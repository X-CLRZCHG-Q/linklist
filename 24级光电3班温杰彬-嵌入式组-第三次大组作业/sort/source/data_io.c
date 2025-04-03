#include "..\Headers\data_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_random_array(int n) 
{
    int* arr = malloc(n * sizeof(int));//malloc���ڴ治��ʱ�᷵��NULL 
    if (!arr) return NULL;//�ж��ڴ�����Ƿ�ʧ�ܣ�ʧ���򷵻�NULL���������������Ч�ڴ� 

    srand(time(NULL)); // ����������ӣ���ʱ�䲥������α����� 
    int i;
    for (i = 0; i < n; i++) 
	{
        arr[i] = rand() % 1000000; // ����0-999999�������
    }
    return arr;//���������ַ 
}

int* read_data(const char* filename, int* n)
{
    FILE* fp = fopen(filename, "r");//��ֻ���ķ�ʽ��һ���ı��ļ� 
    if (!fp) return NULL;

    int capacity = 1024;//�������� 
    int* arr = malloc(capacity * sizeof(int));
    int num, count = 0;

    while (fscanf(fp, "%d", &num) == 1) //���ļ���fp��ѭ����ȡ����%d�����洢������num�У�ֱ���ļ��������ȡʧ�� 
	{
        if (count >= capacity)  // ��̬����
		{
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));//��չ���鳤�� 
        }
        arr[count++] = num;//��num��ֵһ������������ 
    }

    *n = count;//��ָ��n�����������ݸ�����count�� 
    fclose(fp);//�ر��ļ� 
    return arr;//���ش������ݵ�����ĵ�ַ 
}

void write_data(const char* filename, int arr[], int n) {
    FILE* fp = fopen(filename, "w");//��ֻд�ķ�ʽ��һ���ı��ļ���û���ļ����½�һ�� 
    if (!fp) return;//��ʧ��ʱ���� 
	
	int i;
    for (i = 0; i < n; i++) 
	{
        fprintf(fp, "%d\n", arr[i]);//�������е���һ����д���ļ�fp 
    }
    fclose(fp);
}
