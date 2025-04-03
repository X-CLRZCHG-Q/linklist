#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Headers\data_io.h"
#include "..\Headers\sort.h"

//为方便使用，本程序使用命令行进行操作，请用win+R打开cmd窗口进行使用 

// 打印命令行使用说明
void print_usage() 
{
    printf("Usage:\n");
    printf("sort generate <file> <size>  -- 生成测试数据，<文件名称.txt>,<数据量大小>\n");
    printf("sort sort <algorithm> <input> <output>  -- 排序文件数据，<使用的排序算法>,<输入文件名.txt>,<输出文件名.txt>\n");
    printf("sort perf <size>            -- 测试大数据量性能,<数据量大小>\n");
    printf("sort small                  -- 测试小数据量性能\n");
    printf("\n支持的算法: insertion, merge, quick, count, radix\n");
}

int main(int argc, char** argv)//使用argc来记录命令行的参数个数，用argv来存储命令行的字符串 
{
    if (argc < 2) //如果命令行字符串个数小于两个，则返回1报错 
	{
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "generate") == 0) //如果第二个字符串为generate 
	{
        if (argc != 4) //如果输入参数不足四个 
		{
            print_usage();
            return 1;//则返回1报错 
        }
        int size = atoi(argv[3]);//利用atoi函数将字符合成数字读取数据量大小 
        int* arr = generate_random_array(size);//生成随机数存入数组 
        if (!arr) 
		{
            printf("生成数据失败!\n");
            return 1;
        }
        write_data(argv[2], arr, size);//将数组的数据写入给定的文件中 
        free(arr);//释放数组 
        printf("已生成%d个数据到%s\n", size, argv[2]);
    }
    else if (strcmp(argv[1], "sort") == 0)//如果第二个字符串为sort，则选择操作2 
	{
        if (argc != 5) //如果输入参数不够 
		{
            print_usage();
            return 1;//则报错返回1 
        }
        int n;
        int* arr = read_data(argv[3], &n);//读取输入文件中的数据 
        if (!arr) 
		{
            printf("读取文件失败!\n");
            return 1;
        }

        // 根据算法名称选择排序函数
        if (strcmp(argv[2], "insertion") == 0) insertSort(arr, n);
        else if (strcmp(argv[2], "merge") == 0) mergeSort_wrapper(arr, n);
        else if (strcmp(argv[2], "quick") == 0) quickSort_wrapper(arr, n);
        else if (strcmp(argv[2], "count") == 0) countSort(arr, n);
        else if (strcmp(argv[2], "radix") == 0) radix_count_sort(arr, n);
        else 
		{
            printf("未知算法: %s\n", argv[2]);//如果遇到未知算法，则报错返回1 
            free(arr);//释放数组 
            print_usage();
            return 1;
        }

        write_data(argv[4], arr, n);//排序后写入输出数组中 
        free(arr);//释放数组 
        printf("排序结果已写入%s\n", argv[4]);
    }
    else if (strcmp(argv[1], "perf") == 0) //如果第二个字符串为perf 
	{
        if (argc != 3) //如果参数个数不足 
		{
            print_usage();
            return 1;//报错返回1 
        }
        test_performance(atoi(argv[2]));//用测试大数据量函数进行测试 
    }
    else if (strcmp(argv[1], "small") == 0) //如果第二个字符串为small 
	{
        test_small_data();//则用测数据量多次排序的函数进行测试 
    }
    else //其他情况均报错返回1 
	{
        print_usage();
        return 1;
    }

    return 0;
}
