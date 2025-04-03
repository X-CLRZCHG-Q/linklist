#ifndef DATA_IO_H
#define DATA_IO_H

/**
  *@brief ����������� 
  *@param n ���鳤�� 
  *@return ����int����ָ�� 
  */ 
int* generate_random_array(int n);


/**
  *@brief ���ļ��ж�ȡ���� 
  *@param filename�ļ���   n������������ض�ȡ�������ݸ��� 
  *@return ��������ָ�� 
  */ 
int* read_data(const char* filename, int* n);


/**
  *@brief ������д���ļ� 
  *@param filename�ļ���  arr��д�뺯��  n���鳤�� 
  *@return �� 
  */ 
void write_data(const char* filename, int arr[], int n);//д���ļ�����

#endif
