#ifndef DATA_IO_H
#define DATA_IO_H

/**
  *@brief 生成随机数组 
  *@param n 数组长度 
  *@return 返回int数组指针 
  */ 
int* generate_random_array(int n);


/**
  *@brief 从文件中读取数据 
  *@param filename文件名   n输出参数，返回读取到的数据个数 
  *@return 数据数组指针 
  */ 
int* read_data(const char* filename, int* n);


/**
  *@brief 将数组写入文件 
  *@param filename文件名  arr待写入函数  n数组长度 
  *@return 无 
  */ 
void write_data(const char* filename, int arr[], int n);//写入文件数据

#endif
