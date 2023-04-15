/*
   두 개의 정수 a와 b의 유클리드 최대 공약수(GCD)를 구하는 알고리즘
*/
#include "euclid.h"

int euclidRecursive(int a, int b)  //a와 b의 최대공약수를 재귀적으로 계산
{
    if (b == 0)                    //b가 0이면 a가 최대공약수이므로 
    {
        return a;                  //a를 반환
    }
    else
    {
        return euclidRecursive(b, a % b);  //b와 a%b를 인자로 하여 함수를 다시 호출
    }                                      //b가 0이 될 때까지 반복해서 최대공약수를 계산
}

int euclidRepeative(int a, int b) //a와 b의 최대공약수를 반복적으로 계산 
{
    while (b != 0)     //함수가 호출될 때, b가 0이 될 때까지 while 루프를 반복
    {                  //루프 내에서는 temp에 b를 저장하고, b에는 a%b를 대입하고, a에는 temp를 대입 
        int temp = b;  
        b = a % b;
        a = temp;
    }
    return a;  //b가 0이 되면 a가 최대공약수이므로 a를 반환
}
