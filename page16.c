#include<stdio.h>

int main(){
    int coin[3] = {500,100,10};
    int change,i,count[3];

    printf("잔돈입력: ");
    scanf("%d", &change);

    for(i=0;i<3;i++){
        count[i]= change/coin[i]; //동전갯수 저장
        change = change%coin[i]; //잔돈 저장
        printf("%d원 =%d개\n", coin[i], count[i]);
    }
}