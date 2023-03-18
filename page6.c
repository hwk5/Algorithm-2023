#include<stdio.h>

int main(){
    int a[10], max=0; //최대숫자 변수 max로 지정하고 0으로 초기화

for(i=0;i<10;i++){ //
    printf("입력값: ");
    scanf("%d", &a[i]);
    if(a[i] > max) { //인덱스값과 비교
        max = a[i];
}
printf("최댓값: %d\n", max); 
return 0;
}
 }