/*Câu 1. Một số gọi là Q-prime khi nó có đúng 4 ước số nguyên dương. Hãy viết chương trình in ra
các số Q-Prime nhỏ hơn hoặc bằng một số N cho trước nhập từ bàn phím.*/
#include <stdio.h>
long long int demUoc(long long int n){
    int d=2; //ước là 1 và n
    for(long long int i=2;i<=n/2;i++)
        if(n%i==0)
            d+=1;
    return d;
}
int main(){
    long long int n;
    scanf("%lld",&n);
    for(long long int i=2;i<=n;i++)
        if(demUoc(i)==4)
            printf("%lld ",i);
    return 0;
}
