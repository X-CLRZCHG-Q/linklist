#include <stdio.h>
#include <stdlib.h>

//�������� 
void insertSort(int arr[],int n)
{
	int i=1;
	int j=0;
	int key=0;
	
	for(i=1;i<n;i++)//i��ָ��ڶ����� 
	{
		key=arr[i];//��i��ָ���ֵ��key 
		j=i-1;//jΪiǰһ��ֵ 
		
		while(j>=0&&key<arr[j])//����������һ������ʱ����ѭ��
		{
			arr[j+1]=arr[j];//��j��ֵ�������ĺ�һλ 
			j--;//ͬʱj�Լ���ָ��ǰһλ 
		}	
		arr[j+1]=key;//��key��ֵ����j+1 
	}		
} 

//�鲢����

/***************************�鲢�����ڲ��ṹ*************************************************/ 
static void merge(int arr[],int l,int m,int r)//�鲢����ĺϲ����� 
{
	int n1=m-l+1;//�������鳤��(lΪ����˵��±꣬mΪ�м�ֵ���±꣬rΪ���Ҷ˵��±�)
	int n2=r-m;//�������鳤�� 
	
	int *left=malloc(n1*sizeof(int));//������ʱ���鴢������������
	int *right=malloc(n2*sizeof(int));

	int i,j;
	for(i=0;i<n1;i++) left[i]=arr[l+i]; //�������ݵ���ʱ����
	for(j=0;j<n2;j++) right[j]=arr[m+1+j]; 	
	
	int a,b,c;//�ϲ������������� 
	a=b=0;
	c=l;//cΪ���±� 
	while(a<n1&&b<n2)//ֻҪ��һ�������Ͼ��˳�ѭ�� 
	{
		if(left[a]<=right[b]) arr[c++]=left[a++];//��ֵС�ķ������ 
		else arr[c++]=right[b++];
	}
	
	while(a<n1) arr[c++]=left[a++];//����ʣ��Ԫ�� 
	while(b<n2) arr[c++]=right[b++];
	
	free(left);//�ͷ���ʱ�ڴ�ռ� 
	free(right);
}

static void mergeSort(int arr[],int l,int r)//�ݹ���κ��� 
{
	if(l<r)
	{
		int m=l+(r-l)/2;//�ҵ��м������������ֳ������� 
		mergeSort(arr,l,m);//���õݹ�һֱ�����벿�� 
		mergeSort(arr,m+1,r);//���õݹ�һֱ����Ұ벿�� 
		merge(arr,l,m,r);//�ϲ���� 
	}
}
/***********************************�ⲿ�ӿ�**********************************/


//�ⲿ�ӿ� 
void mergeSort_wrapper(int arr[],int n)//�鲢�����װ������ʹ��ʱ�����Ӧ��������鳤�ȣ�  
{
	mergeSort(arr,0,n-1);
}
/***********************************************END****************************************************/






/*************************************************���������ڲ�*****************************************/ 

static void swap(int* a, int* b)//����ֵ���� 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


static int partition(int arr[],int low,int high)//�����������������ΪС�ںʹ�������������� 
{
	int pivot=arr[high];
	int i=low-1;
	
	int j=low;
	for(j=low;j<high;j++)//ѭ��ִ�� 
	{
		if(arr[j]<pivot) swap(&arr[++i],&arr[j]);//j����С�ڻ�׼���ͷŵ�ǰ�棬���ڻ�׼���Ͳ�����j����������i�����������iָ���λ���������һ��С�ڻ�׼������ 
	} 
	swap(&arr[i+1],&arr[high]);//ѭ�������󽫵�һ�����ڻ�׼�������׼������ 
	return i+1;//���ػ�׼�����±� 
} 

static void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);//piΪ��׼�����±� 
		quickSort(arr,low,pi-1);//�ֳɴ�С���ݷֱ�����һֱ�ݹ� 
		quickSort(arr,pi+1,high);
	}
 } 

/******************************************�ⲿ�ӿ�***************************************************/ 

void quickSort_wrapper(int arr[],int n)//���������װ������ʹ��ʱ�����Ӧ��������鳤�ȣ� 
{
	quickSort(arr,0,n-1);
}

/*********************************************END****************************************************/




/*************************************************���������ڲ�*****************************************/ 
 
void countSort(int arr[], int n)// ȷ�����ݷ�Χ
{
    int max = arr[0], min = arr[0];
    
    int i=1;
    for (i = 1; i < n; i++) //�������� 
	{
        if (arr[i] > max) max = arr[i];//��max���Ϊmax 
        if (arr[i] < min) min = arr[i];//��minС��Ϊmin 
    }
    int range = max - min + 1;//����������Сֵ֮��ķ�Χ 
    
    //�����ڿ��ٵ����鳤��ȡ�������ֵ����Сֵ֮�����ĵ�ֵ����˼���ϴ�����ݾ������ã���Ϊ֮��ÿһ���������Ὺ��һ��λ�ã� 
    int* count = calloc(range, sizeof(int));// �����������飬��calloc���Խ��г�ʼ��Ϊ0 
    int* output = malloc(n * sizeof(int));//����������� 
    
    for (i = 0; i < n; i++) // ͳ��ÿ��Ԫ�صĳ��ִ���
	{	
		count[arr[i] - min]++;//��min�±�Ϊ0��ʼ��ͨ����ֵ���ҵ���Ӧλ��ͳ������ 
	} 
    
    
    for (i = 1; i < range; i++) // �����ۼ�Ƶ�Σ�ȷ��Ԫ������λ�ã�
	{
		count[i] += count[i - 1];
	}	
    
   
    for (i = n - 1; i >= 0; i--)// ������䱣֤�ȶ���
	{
        output[--count[arr[i] - min]] = arr[i];//(�ؼ���countҪ���Լ� 
    }
    
    
    for (i = 0; i < n; i++)// ��������ƻ�ԭ����
	{ 
		arr[i] = output[i];
	}
    
    free(count);
    free(output);
}

/*************************************************END*****************************************/ 


/*************************************************���������ڲ�*****************************************/  

// ������������ȡ�������ֵ
static int get_max(int arr[], int n) 
{
    int max = arr[0];
    
    int i = 1;
    for (i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
        
    return max;
}

// ��ָ��λ�����м�������
static void count_sort_for_radix(int arr[], int n, int exp) 
{
    int* output = malloc(n * sizeof(int));
    int count[10] = {0};  // ʮ�������ַ�Χ0-9
 
 
//��Ƕ��һ����������ʵ�ָ��������ȶ����򣬸�λ����ʱ��λ��˳�򲻻�ı䣩   
    int i = 0; 
    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;// ͳ�Ƶ�ǰλ�ĳ��ִ���
    
    
    for (i = 1; i < 10; i++) count[i] += count[i - 1];// �����ۼ�Ƶ��
    
    
    for (i = n - 1; i >= 0; i--) // ������䱣֤�ȶ���
	{
        output[--count[(arr[i]/exp)%10]] = arr[i];
    }
    
    // ��������ƻ�ԭ����
    for (i = 0; i < n; i++) arr[i] = output[i];
    
    free(output);
}

// ��������������
void radix_count_sort(int arr[], int n)//��װ���� 
 {
    int max = get_max(arr, n);//��ȡ���ֵ 
   
    int exp = 1;   
    for (exp = 1; max/exp > 0; exp *= 10)  // �����λ�����λ��������
	{
        count_sort_for_radix(arr, n, exp);
    }
}
/*************************************************END*****************************************/ 
