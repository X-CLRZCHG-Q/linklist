#include <stdio.h>
#include <stdlib.h>

//插入排序 
void insertSort(int arr[],int n)
{
	int i=1;
	int j=0;
	int key=0;
	
	for(i=1;i<n;i++)//i从指向第二个数 
	{
		key=arr[i];//把i所指向的值给key 
		j=i-1;//j为i前一个值 
		
		while(j>=0&&key<arr[j])//当两者中其一不符合时跳出循环
		{
			arr[j+1]=arr[j];//将j的值赋给他的后一位 
			j--;//同时j自减，指向前一位 
		}	
		arr[j+1]=key;//把key的值赋给j+1 
	}		
} 

//归并排序

/***************************归并函数内部结构*************************************************/ 
static void merge(int arr[],int l,int m,int r)//归并排序的合并函数 
{
	int n1=m-l+1;//左子数组长度(l为最左端的下标，m为中间值的下标，r为最右端的下标)
	int n2=r-m;//右子数组长度 
	
	int *left=malloc(n1*sizeof(int));//创建临时数组储存左右子数组
	int *right=malloc(n2*sizeof(int));

	int i,j;
	for(i=0;i<n1;i++) left[i]=arr[l+i]; //复制数据到临时数组
	for(j=0;j<n2;j++) right[j]=arr[m+1+j]; 	
	
	int a,b,c;//合并两个有序数组 
	a=b=0;
	c=l;//c为左下标 
	while(a<n1&&b<n2)//只要有一方不符合就退出循环 
	{
		if(left[a]<=right[b]) arr[c++]=left[a++];//把值小的放在左边 
		else arr[c++]=right[b++];
	}
	
	while(a<n1) arr[c++]=left[a++];//处理剩余元素 
	while(b<n2) arr[c++]=right[b++];
	
	free(left);//释放临时内存空间 
	free(right);
}

static void mergeSort(int arr[],int l,int r)//递归分治函数 
{
	if(l<r)
	{
		int m=l+(r-l)/2;//找到中间的数，将数组分成两部分 
		mergeSort(arr,l,m);//利用递归一直拆解左半部分 
		mergeSort(arr,m+1,r);//利用递归一直拆解右半部分 
		merge(arr,l,m,r);//合并结果 
	}
}
/***********************************外部接口**********************************/


//外部接口 
void mergeSort_wrapper(int arr[],int n)//归并排序包装函数（使用时传入对应数组和数组长度）  
{
	mergeSort(arr,0,n-1);
}
/***********************************************END****************************************************/






/*************************************************快速排序内部*****************************************/ 

static void swap(int* a, int* b)//交换值函数 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


static int partition(int arr[],int low,int high)//分区函数，将数组分为小于和大于枢轴的两部分 
{
	int pivot=arr[high];
	int i=low-1;
	
	int j=low;
	for(j=low;j<high;j++)//循环执行 
	{
		if(arr[j]<pivot) swap(&arr[++i],&arr[j]);//j的数小于基准数就放到前面，大于基准数就不动，j继续自增，i不动，则最后i指向的位置则是最后一个小于基准数的数 
	} 
	swap(&arr[i+1],&arr[high]);//循环结束后将第一个大于基准的数与基准数交换 
	return i+1;//返回基准数的下标 
} 

static void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);//pi为基准数的下标 
		quickSort(arr,low,pi-1);//分成大小两份分别排序，一直递归 
		quickSort(arr,pi+1,high);
	}
 } 

/******************************************外部接口***************************************************/ 

void quickSort_wrapper(int arr[],int n)//快速排序包装函数（使用时传入对应数组和数组长度） 
{
	quickSort(arr,0,n-1);
}

/*********************************************END****************************************************/




/*************************************************计数排序内部*****************************************/ 
 
void countSort(int arr[], int n)// 确定数据范围
{
    int max = arr[0], min = arr[0];
    
    int i=1;
    for (i = 1; i < n; i++) //遍历数组 
	{
        if (arr[i] > max) max = arr[i];//比max大成为max 
        if (arr[i] < min) min = arr[i];//比min小成为min 
    }
    int range = max - min + 1;//计算出最大最小值之间的范围 
    
    //（由于开辟的数组长度取决于最大值和最小值之间相差的的值，因此极差较大的数据尽量不用，因为之间每一个整数都会开出一个位置） 
    int* count = calloc(range, sizeof(int));// 创建计数数组，用calloc可以进行初始化为0 
    int* output = malloc(n * sizeof(int));//创建输出数组 
    
    for (i = 0; i < n; i++) // 统计每个元素的出现次数
	{	
		count[arr[i] - min]++;//从min下标为0开始，通过差值来找到对应位置统计数据 
	} 
    
    
    for (i = 1; i < range; i++) // 计算累加频次（确定元素最终位置）
	{
		count[i] += count[i - 1];
	}	
    
   
    for (i = n - 1; i >= 0; i--)// 反向填充保证稳定性
	{
        output[--count[arr[i] - min]] = arr[i];//(关键）count要先自减 
    }
    
    
    for (i = 0; i < n; i++)// 将结果复制回原数组
	{ 
		arr[i] = output[i];
	}
    
    free(count);
    free(output);
}

/*************************************************END*****************************************/ 


/*************************************************基数排序内部*****************************************/  

// 辅助函数：获取数组最大值
static int get_max(int arr[], int n) 
{
    int max = arr[0];
    
    int i = 1;
    for (i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
        
    return max;
}

// 按指定位数进行计数排序
static void count_sort_for_radix(int arr[], int n, int exp) 
{
    int* output = malloc(n * sizeof(int));
    int count[10] = {0};  // 十进制数字范围0-9
 
 
//内嵌了一个计数排序（实现根本：是稳定排序，高位排序时低位的顺序不会改变）   
    int i = 0; 
    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;// 统计当前位的出现次数
    
    
    for (i = 1; i < 10; i++) count[i] += count[i - 1];// 计算累加频次
    
    
    for (i = n - 1; i >= 0; i--) // 反向填充保证稳定性
	{
        output[--count[(arr[i]/exp)%10]] = arr[i];
    }
    
    // 将结果复制回原数组
    for (i = 0; i < n; i++) arr[i] = output[i];
    
    free(output);
}

// 基数排序主函数
void radix_count_sort(int arr[], int n)//包装函数 
 {
    int max = get_max(arr, n);//获取最大值 
   
    int exp = 1;   
    for (exp = 1; max/exp > 0; exp *= 10)  // 从最低位到最高位依次排序
	{
        count_sort_for_radix(arr, n, exp);
    }
}
/*************************************************END*****************************************/ 
