//
// Created by penper on 2018/12/27.
//

#include "../include.h"
#include <string.h>
static int way1(int n);
static int way2(int n);
static int way3(int n);
static int way4(int n);
// 012345678
// 567801234

/*
 * way1: new arry=01234, << table = [5678], cp arry in table，O(n), 多了空间
 * way2: 左移n次， O(n*n)
 * way3: 01234 5678 -> 56784 0123 -> 5678 01234 = change 4+4, O(n)
 *       0123 45678 -> 4567 01238 ->4567 80123
 * way4: 01234 5678 -> 43210 8765 -> reverse -> 5678 01234, O(n)
 */
const int table_G[] = {0, 1, 2, 3, 4,  5, 6, 7, 8};
int k01main()
{
    way3(4);
}

// 方法1
static int way1(int n)
{
    int table[len(table_G)];
    int temp[n];  // C99 支持变长度数组，但不能初始化
    int len_table = len(table);
    memcpy(table, table_G, sizeof(table_G));
    memcpy(temp, table, sizeof(temp));
    printf("way1: ");
    for (int i = n; i < len_table; i++) {
        table[i-n] = table[i];
    }
    memcpy(table+len_table-n, temp, sizeof(*temp) * n);  //  存在陷阱，下标容易错
    printIntArray(table, len_table);

    return 0;
}
//01234 5678 -> 56784 0123 -> 5678 01234 = change 4+4, O(n) mid 后移
//0123 45678 -> 4567 01238 ->4567 80123
//              5678 40123  mid 前移

// 01 2345678 -> 23 01345678  2345678 01
static int way3(int n) // too 复杂
{
    int table[len(table_G)];
    memcpy(table, table_G, sizeof(table_G));
    int len_table = len(table);
    int changeTimes = min(n, len_table-n);
    printf("%d\n", changeTimes);
}
// 方法4
// way4: 01234 5678 -> 43210 8765 -> reverse -> 5678 01234, O(n)
static int way4(int n)
{
    int table[len(table_G)];
    memcpy(table, table_G, sizeof(table_G));
    printf("way4: ");
    reverseArray(table, n);
    reverseArray(table+n, len(table)-n);

    reverseArray(table, len(table));
    printIntArray(table, len(table));
}