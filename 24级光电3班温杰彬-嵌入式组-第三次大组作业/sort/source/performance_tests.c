#include "..\Headers\sort.h"
#include "..\Headers\data_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef void (*sort_func)(int[], int);//����sort_funcΪ����ָ�����͵ı��� 

/**
 * ���������㷨�ڴ��������µ�����
 * @param size ������������С����10000��50000��200000��
 */
void test_performance(int size) 
{
    // ���������������
    int* arr = generate_random_array(size);
    if (!arr) 
	{
        fprintf(stderr, "�����ڴ����ʧ��\n");//��stderr������������ 
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

    printf("���ڲ���������: %d\n", size);
    printf("----------------------------------------\n");

    // �������������㷨���в���
    int i;
    for (i = 0; i < 5; i++) {
        // ����ԭʼ�����Ա�֤���Թ�ƽ��
        int* arr_copy = malloc(size * sizeof(int));
        if (!arr_copy) 
		{
            fprintf(stderr, "�����޷���������\n");
            continue;//�����ڴ����ʧ��ʱ��������ǰ���򣬽�����һ���� 
        }
        memcpy(arr_copy, arr, size * sizeof(int));//�������ݣ���arr�����е����ݸ��Ƶ�arr_cpy������ 

        // ��ʱ��ʼ
        clock_t start = clock();//��¼��ʼʱ�� 
        sorts[i](arr_copy, size);  // ִ������
        clock_t end = clock();//��¼����ʱ�� 

        // �����ʱ���룩
        double time_used = ((double)(end - start)) / CLOCKS_PER_SEC;//�����ĵ�CPUʱ��������/ÿ���Ӧ��ʱ�������� 
        printf("%-20s: %.6f ��\n", sort_names[i], time_used);//��������㷨�����ƺ����õ�ʱ�� 

        free(arr_copy);  // �ͷŸ����ڴ�
    }

    free(arr);  // �ͷ�ԭʼ�����ڴ�
    printf("\n");
}
