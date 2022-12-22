/*Câu 16. Viết chương trình tìm các số nguyên tố từ một mảng sinh ngẫu nhiên có kích thước N,
với N nhập vào từ bàn phím*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
    long int n,r;
    scanf("%ld",&n);
    long int a[n];
    srand((int)time(0));
    for(long int i = 0; i < n; ++i){
        a[i] = (rand()%r+1);
        printf("%ld ",a[i]);
    }
    printf("\n");
    for(long int i = 0; i < n; ++i){
        if(isPrime(a[i])==1)
            printf("%ld ",a[i]);
    }
    return 0;
}