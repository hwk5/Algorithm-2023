#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h" //프로젝트 안의 헤더

#define N 1000
#define MAX_VALUE 1000000

int testEuclid()
{
    int result = 0;
    int a = 0, b = 0;
    int i;

    clock_t start, end;
    double recursiveTime, repeativeTime;

    start = clock();
    for (i = 0; i < N; i++)
    {
        a = rand() % MAX_VALUE + 1;
        b = rand() % MAX_VALUE + 1;

        int gcdRecursive = euclidRecursive(a, b);
        int gcdRepeative = euclidRepeative(a, b);

        if (gcdRecursive != gcdRepeative)
        {
            result = 1;
            break;
        }
    }
    end = clock();

    recursiveTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    for (i = 0; i < N; i++)
    {
        a = rand() % MAX_VALUE + 1;
        b = rand() % MAX_VALUE + 1;

        int gcdRecursive = euclidRecursive(a, b);
        int gcdRepeative = euclidRepeative(a, b);

        if (gcdRecursive != gcdRepeative)
        {
            result = 1;
            break;
        }
    }
    end = clock();

    repeativeTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (result == 0)
    {
        printf(" Match.\n");
        printf(" Recursive time: %.1f s\n", recursiveTime);
        printf(" Repeative time: %.1f s\n", repeativeTime);
    }
    else
    {
        printf("Not Match.\n");
    }

    return result;
}