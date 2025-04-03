#include "..\Headers\sort.h"
#include "..\Headers\data_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef void (*sort_func)(int[], int);

/**
 * ���������㷨��С��������Ƶ�����µ�����
 * ���Է�����100������ * 100,000������
 */
void test_small_data() 
{
    const int DATA_SIZE = 100;      // ��������������
    const int ITERATIONS = 100000;  // �ظ��������

    // ���ɹ̶���С���ݼ�������������Ӱ��ʱ�䣩
    int* base_data = generate_random_array(DATA_SIZE);
    if (!base_data) {
        fprintf(stderr, "�����޷����ɻ�������\n");
        return;
    }

    // �������������㷨��������
    sort_func sorts[] =
	{
        insertSort,
        mergeSort_wrapper,
        quickSort_wrapper,
        countSort,
        radix_count_sort
    };
    
    const char* sort_names[] = {
        "��������(Insertion)",
        "�鲢����(Merge)",
        "��������(Quick)",
        "��������(Count)",
        "��������(Radix)"
    };

    printf("���ڲ���С��������Ƶ���ܣ�%d�� x %d����\n", ITERATIONS, DATA_SIZE);
    printf("----------------------------------------\n");

	int i;
    for (i = 0; i < 5; i++)
	{
        // Ԥ�����ڴ�����ظ����俪��
        int* temp_buffer = malloc(DATA_SIZE * sizeof(int));
        if (!temp_buffer) {
            fprintf(stderr, "������ʱ�ڴ����ʧ��\n");
            continue;//�����ڴ����ʧ��ʱ��������ǰ���򣬽�����һ����
        }

        // ��ʱ��ʼ
        int j;
        clock_t start = clock();//��ʱ��ʼ 
        for (j = 0; j < ITERATIONS; j++) //�ظ����� 
		{
            // ÿ�θ���ԭʼ�����Ա�֤����һ����
            memcpy(temp_buffer, base_data, DATA_SIZE * sizeof(int));
            sorts[i](temp_buffer, DATA_SIZE);  // ִ������
        }
        clock_t end = clock();//��ʱ���� 

        // �����ܺ�ʱ���룩
        double time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%-20s: %.6f ��\n", sort_names[i], time_used);

        free(temp_buffer);//�ͷű������ݵ��ڴ� 
    }

    free(base_data);  // �ͷŻ��������ڴ�
    printf("\n");
}
