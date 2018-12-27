#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <stdint.h>

#define len(fn) (sizeof(fn) / sizeof(*fn))  // 求数组长度
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
void swap(int *a, int *b);
void printIntArray(int *array, int num);
void reverseArray(int *array, int num);
int k01main();
#endif