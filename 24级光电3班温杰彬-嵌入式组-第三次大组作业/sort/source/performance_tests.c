#include "..\Headers\sort.h"
#include "..\Headers\data_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef void (*sort_func)(int[], int);//定义sort_func为函数指针类型的别名 

/**
 * 测试排序算法在大数据量下的性能
 * @param size 测试数据量大小（如10000、50000、200000）
 */
void test_performance(int size) 
{
    // 生成随机测试数据
    int* arr = generate_random_array(size);
    if (!arr) 
	{
        fprintf(stderr, "错误：内存分配失败\n");//用stderr处理错误输出流 
        return;
    }

    // 定义所有排序算法及其名称
    sort_func sorts[] =
	{
        insertSort,
        mergeSort_wrapper,
        quickSort_wrapper,
        countSort,
        radix_count_sort
    };
    
    const char* sort_names[] = {
        "插入排序(Insertion)",
        "归并排序(Merge)",
        "快速排序(Quick)",
        "计数排序(Count)",
        "基数排序(Radix)"
    };

    printf("正在测试数据量: %d\n", size);
    printf("----------------------------------------\n");

    // 遍历所有排序算法进行测试
    int i;
    for (i = 0; i < 5; i++) {
        // 复制原始数据以保证测试公平性
        int* arr_copy = malloc(size * sizeof(int));
        if (!arr_copy) 
		{
            fprintf(stderr, "错误：无法复制数组\n");
            continue;//遇到内存分配失败时，跳过当前排序，进入下一排序 
        }
        memcpy(arr_copy, arr, size * sizeof(int));//备份数据，把arr数组中的数据复制到arr_cpy数组中 

        // 计时开始
        clock_t start = clock();//记录开始时间 
        sorts[i](arr_copy, size);  // 执行排序
        clock_t end = clock();//记录结束时间 

        // 计算耗时（秒）
        double time_used = ((double)(end - start)) / CLOCKS_PER_SEC;//用消耗的CPU时钟周期数/每秒对应的时钟周期数 
        printf("%-20s: %.6f 秒\n", sort_names[i], time_used);//输出排序算法的名称和所用的时间 

        free(arr_copy);  // 释放副本内存
    }

    free(arr);  // 释放原始数据内存
    printf("\n");
}
