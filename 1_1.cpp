#include<iostream>
#include<stdlib.h>
#include<set>
#define N 10000000
#define BitsPerWord 32
#define Move 5
int a[1 + N / BitsPerWord];
using namespace std;
void mergeTwoArray(int array[], int low_index, int mid_index, int high_index);
void printMessage(int array[]);
void campareTwoArrayForMerge(int *temp_array, int array[], int &index_of_front_array, int &index_of_later_array, int &mid_index, int &high_index, int &index_of_temp_array);
void addRemainingtoArray(int *temp_array, int array[], int &index_of_front_array, int &index_of_later_array, int &mid_index, int &high_index, int &index_of_temp_array, int &low_index);
void sortArray(int array[], int low_index, int high_index)
{
	int mid_index = (low_index + high_index) / 2;
	if (low_index < high_index)
	{
		sortArray(array, low_index, mid_index);
		sortArray(array, mid_index + 1, high_index);
		mergeTwoArray(array, low_index, mid_index, high_index);
		printMessage(array);
	}

}
void mergeTwoArray(int array[], int low_index, int mid_index, int high_index)
{

	int *temp_array = new int[high_index - low_index + 1];
	int index_of_front_array = low_index, index_of_later_array = mid_index + 1, index_of_temp_array = 0;
	campareTwoArrayForMerge(temp_array, array, index_of_front_array, index_of_later_array, mid_index, high_index, index_of_temp_array);
	addRemainingtoArray(temp_array, array, index_of_front_array, index_of_later_array, mid_index, high_index, index_of_temp_array, low_index);
}
void campareTwoArrayForMerge(int *temp_array, int array[], int &index_of_front_array, int &index_of_later_array, int &mid_index, int &high_index, int &index_of_temp_array)
{
	while (index_of_front_array <= mid_index && index_of_later_array <= high_index)
	{
		if (array[index_of_front_array] < array[index_of_later_array])
		{
			temp_array[index_of_temp_array++] = array[index_of_front_array++];
		}
		else
		{
			temp_array[index_of_temp_array++] = array[index_of_later_array++];
		}
	}
}
void addRemainingtoArray(int *temp_array, int array[], int &index_of_front_array, int &index_of_later_array, int &mid_index, int &high_index, int &index_of_temp_array, int &low_index)
{
	while (index_of_front_array <= mid_index)
		temp_array[index_of_temp_array++] = array[index_of_front_array++];
	while (index_of_later_array <= high_index)
		temp_array[index_of_temp_array++] = array[index_of_later_array++];
	for (int i = 0; i < index_of_temp_array; i++)
		array[i + low_index] = temp_array[i];
}
void printMessage(int array[])
{
	for (int i = 0; i < 8; i++)
		cout << array[i] << " ";
	cout << endl;
}
//void set(int i)
//{
//	a[i >> Move] |= 1 << (i & 0x1F);
//}
//void clr(int i)
//{
//	a[i >> Move] & ~(1 << (i & 0x1F));
//}
//int test(int i)
//{
//	return a[i >> Move] & 1 << (i & 0x1F);
//}
//void main()
//{
//	int a[5] = { 23, 11, 34, 52, 323 };
//	std::set<int> set;
//	const int length = sizeof(a) / sizeof(int);
//	for (int i = 0; i < length; i++)
//	{
//		set.insert(a[i]);
//	}
//	std::set<int>::iterator j;
//	for (j = set.begin(); j != set.end(); j++)
//		cout << *j << "  ";
//	getchar();
//}