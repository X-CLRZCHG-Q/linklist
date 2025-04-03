#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Headers\data_io.h"
#include "..\Headers\sort.h"

//Ϊ����ʹ�ã�������ʹ�������н��в���������win+R��cmd���ڽ���ʹ�� 

// ��ӡ������ʹ��˵��
void print_usage() 
{
    printf("Usage:\n");
    printf("sort generate <file> <size>  -- ���ɲ������ݣ�<�ļ�����.txt>,<��������С>\n");
    printf("sort sort <algorithm> <input> <output>  -- �����ļ����ݣ�<ʹ�õ������㷨>,<�����ļ���.txt>,<����ļ���.txt>\n");
    printf("sort perf <size>            -- ���Դ�����������,<��������С>\n");
    printf("sort small                  -- ����С����������\n");
    printf("\n֧�ֵ��㷨: insertion, merge, quick, count, radix\n");
}

int main(int argc, char** argv)//ʹ��argc����¼�����еĲ�����������argv���洢�����е��ַ��� 
{
    if (argc < 2) //����������ַ�������С���������򷵻�1���� 
	{
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "generate") == 0) //����ڶ����ַ���Ϊgenerate 
	{
        if (argc != 4) //���������������ĸ� 
		{
            print_usage();
            return 1;//�򷵻�1���� 
        }
        int size = atoi(argv[3]);//����atoi�������ַ��ϳ����ֶ�ȡ��������С 
        int* arr = generate_random_array(size);//����������������� 
        if (!arr) 
		{
            printf("��������ʧ��!\n");
            return 1;
        }
        write_data(argv[2], arr, size);//�����������д��������ļ��� 
        free(arr);//�ͷ����� 
        printf("������%d�����ݵ�%s\n", size, argv[2]);
    }
    else if (strcmp(argv[1], "sort") == 0)//����ڶ����ַ���Ϊsort����ѡ�����2 
	{
        if (argc != 5) //�������������� 
		{
            print_usage();
            return 1;//�򱨴���1 
        }
        int n;
        int* arr = read_data(argv[3], &n);//��ȡ�����ļ��е����� 
        if (!arr) 
		{
            printf("��ȡ�ļ�ʧ��!\n");
            return 1;
        }

        // �����㷨����ѡ��������
        if (strcmp(argv[2], "insertion") == 0) insertSort(arr, n);
        else if (strcmp(argv[2], "merge") == 0) mergeSort_wrapper(arr, n);
        else if (strcmp(argv[2], "quick") == 0) quickSort_wrapper(arr, n);
        else if (strcmp(argv[2], "count") == 0) countSort(arr, n);
        else if (strcmp(argv[2], "radix") == 0) radix_count_sort(arr, n);
        else 
		{
            printf("δ֪�㷨: %s\n", argv[2]);//�������δ֪�㷨���򱨴���1 
            free(arr);//�ͷ����� 
            print_usage();
            return 1;
        }

        write_data(argv[4], arr, n);//�����д����������� 
        free(arr);//�ͷ����� 
        printf("��������д��%s\n", argv[4]);
    }
    else if (strcmp(argv[1], "perf") == 0) //����ڶ����ַ���Ϊperf 
	{
        if (argc != 3) //��������������� 
		{
            print_usage();
            return 1;//������1 
        }
        test_performance(atoi(argv[2]));//�ò��Դ��������������в��� 
    }
    else if (strcmp(argv[1], "small") == 0) //����ڶ����ַ���Ϊsmall 
	{
        test_small_data();//���ò��������������ĺ������в��� 
    }
    else //���������������1 
	{
        print_usage();
        return 1;
    }

    return 0;
}
