/*Câu 2. Viết chương trình tìm các số nguyên tố có N chữ số với N nhập từ bàn phím và 2 ≤ N ≤ 10.*/
#include <stdio.h>
#include <math.h>
int isPrime(long long int n){
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long int i = 5; i <= sqrt(n); i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
int main(){
    long long int n;
    scanf("%lld",&n);
    while (n<2 || n>10){
        printf("Nhap lai N thoa man 2 <= N <= 10: ");
        scanf("%lld",&n);
    }
    for(long long int i=pow(10,n-1);i<=pow(10,n)-1;i++)
        if(isPrime(i)==1)
            printf("%lld ",i);
    return 0;
}
