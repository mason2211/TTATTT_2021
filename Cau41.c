/*Câu 41. Cho các số nguyên dương a,k,n, nhập từ bàn phím (0<a,k<n<1000), Viết chương trình xác định xem 
a^k mod n có phải là một số nguyên tố hay không (sử dụng thuật toán bình phương và nhân có lặp)?*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n){
    long long int b = 1, A = a;
    if (k % 2 == 1)
        b = a;
    k/=2;
    while (k > 0){
        A = (A*A)%n;
        if (k % 2 == 1)
            b = (b*A)%n;
        k/=2;
    }
    return b;
}
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
    srand((int)time(0));
    // long long int a = rand()%(1000+1);
    // long long int k = rand()%(1000+1);
    // long long int n = rand()%(1000+1);
    long long int a,k,n;
    scanf("%lld%lld%lld",&a,&k,&n);
    while (a>=n || a<=0 || a>=1000){
        //a = rand()%(1000+1);
        printf("Nhap lai a thoa man 0<a,k<n<1000: ");
        scanf("%lld",&a);
    }
    while (k>=n || k<=0 || k>=1000){
        //k = rand()%(1000+1);
        printf("Nhap lai a thoa man 0<a,k<n<1000: ");
        scanf("%lld",&k);
    }
    printf("a = %lld, k = %lld, n = %lld\n",a,k,n);
    long long int x = nhanBinhPhuongCoLap(a,k,n);
    if(isPrime(x)==1)
        printf("%lld^%lld mod %lld = %lld la SNT",a,k,n,x);
    else printf("%lld^%lld mod %lld = %lld khong la SNT",a,k,n,x);
}
