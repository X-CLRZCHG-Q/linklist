#ifndef __SORT_H_
#define __SORT_H_


//插入排序 
void insertSort(int arr[],int n);

//归并排序
void mergeSort_wrapper(int arr[],int n);

//快速排序
void quickSort_wrapper(int arr[],int n);

//计数排序 
void countSort(int arr[], int n);

//基数排序
void radix_count_sort(int arr[], int n);

#endif
