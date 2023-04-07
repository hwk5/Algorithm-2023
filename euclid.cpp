#include "euclid.h"

//재귀적 최대공약수 알고리즘
int euclidRecursive(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return euclidRecursive(b, a % b);
    }
}

//반복적 최대공약수 알고리즘
int euclidRepeative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

