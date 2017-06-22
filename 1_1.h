#include<iostream>
#include<stdlib.h>
#include<set>
void mergeTwoArray(int array[], int low_index, int mid_index, int high_index);
void printMessage(int array[]);
void campareTwoArrayForMerge(int *temp_array, int array[], int &index_of_front_array, int &index_of_later_array, int &mid_index, int &high_index, int &index_of_temp_array);
void addRemainingtoArray(int *temp_array, int array[], int &index_of_front_array, int &index_of_later_array, int &mid_index, int &high_index, int &index_of_temp_array, int &low_index);