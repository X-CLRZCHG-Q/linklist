#include "..\Headers\data_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_random_array(int n) 
{
    int* arr = malloc(n * sizeof(int));//malloc在内存不足时会返回NULL 
    if (!arr) return NULL;//判断内存分配是否失败，失败则返回NULL，避免后续操作无效内存 

    srand(time(NULL)); // 设置随机种子，用时间播种生成伪随机数 
    int i;
    for (i = 0; i < n; i++) 
	{
        arr[i] = rand() % 1000000; // 生成0-999999的随机数
    }
    return arr;//返回数组地址 
}

int* read_data(const char* filename, int* n)
{
    FILE* fp = fopen(filename, "r");//以只读的方式打开一个文本文件 
    if (!fp) return NULL;

    int capacity = 1024;//数组容量 
    int* arr = malloc(capacity * sizeof(int));
    int num, count = 0;

    while (fscanf(fp, "%d", &num) == 1) //从文件发fp中循环读取整数%d，并存储到变量num中，直到文件结束或读取失败 
	{
        if (count >= capacity)  // 动态扩容
		{
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));//扩展数组长度 
        }
        arr[count++] = num;//把num的值一个个传入数组 
    }

    *n = count;//由指针n返回数组数据个数（count） 
    fclose(fp);//关闭文件 
    return arr;//返回储存数据的数组的地址 
}

void write_data(const char* filename, int arr[], int n) {
    FILE* fp = fopen(filename, "w");//以只写的方式打开一个文本文件，没有文件则新建一个 
    if (!fp) return;//打开失败时返回 
	
	int i;
    for (i = 0; i < n; i++) 
	{
        fprintf(fp, "%d\n", arr[i]);//将数组中的数一个个写入文件fp 
    }
    fclose(fp);
}
