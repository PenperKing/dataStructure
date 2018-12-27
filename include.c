//
// Created by penper on 2018/12/27.
//

#include "include.h"

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void printIntArray(int *array, int num)
{
    for (int i = 0; i < num; i++) {
        printf("%d, ", array[i]);
    }
    puts("");
}
void reverseArray(int *array, int num)
{
    int *left  = array;
    int *right = array+num-1;
    while(left < right) {
        swap(left++, right--);
    }
}