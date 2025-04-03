#include "..\Headers\sort.h"
#include "..\Headers\data_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef void (*sort_func)(int[], int);

/**
 * 测试排序算法在小数据量高频调用下的性能
 * 测试方案：100个数据 * 100,000次排序
 */
void test_small_data() 
{
    const int DATA_SIZE = 100;      // 单次排序数据量
    const int ITERATIONS = 100000;  // 重复排序次数

    // 生成固定的小数据集（避免多次生成影响时间）
    int* base_data = generate_random_array(DATA_SIZE);
    if (!base_data) {
        fprintf(stderr, "错误：无法生成基础数据\n");
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

    printf("正在测试小数据量高频性能：%d次 x %d数据\n", ITERATIONS, DATA_SIZE);
    printf("----------------------------------------\n");

	int i;
    for (i = 0; i < 5; i++)
	{
        // 预分配内存避免重复分配开销
        int* temp_buffer = malloc(DATA_SIZE * sizeof(int));
        if (!temp_buffer) {
            fprintf(stderr, "错误：临时内存分配失败\n");
            continue;//遇到内存分配失败时，跳过当前排序，进入下一排序
        }

        // 计时开始
        int j;
        clock_t start = clock();//计时开始 
        for (j = 0; j < ITERATIONS; j++) //重复排序 
		{
            // 每次复制原始数据以保证测试一致性
            memcpy(temp_buffer, base_data, DATA_SIZE * sizeof(int));
            sorts[i](temp_buffer, DATA_SIZE);  // 执行排序
        }
        clock_t end = clock();//计时结束 

        // 计算总耗时（秒）
        double time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%-20s: %.6f 秒\n", sort_names[i], time_used);

        free(temp_buffer);//释放备份数据的内存 
    }

    free(base_data);  // 释放基础数据内存
    printf("\n");
}
