/*Câu 5. Viết chương trình tính tổng của các số nguyên tố nằm trong khoảng [A, B] với A, B nhập 
vào từ bàn phím.*/
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
    long long int a,b,d=0;
    scanf("%lld%lld",&a,&b);
    while (a==b || a>b || a<0 || b<0){
        printf("Nhap lai A, B thoa man 0 < A < B: ");
        scanf("%lld%lld",&a,&b);
    }
    for(long long int i=a;i<=b;i++)
        if(isPrime(i)==1)
            d+=i;
    printf("Tong cac snt trong khoang [%lld,%lld] la: %lld",a,b,d);
    return 0;
}