/*Câu 21. Một số gọi là siêu số nguyên tố nếu số lượng các số nguyên tố từ 1 đến X (ngoại trừ X) là
một số nguyên tố. Hãy viết chương trình đếm số lượng các siêu số nguyên tố này trong khoảng
[A,B] cho trước nhập từ bàn phím.*/
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

int countPrime(long long int n){
    int d = 0;
    for(long int i = 2; i<n;i++)
        if(isPrime(i)==1)
            d+=1;
    return d;
}
int main(){
    long long int a, b, d=0;
    scanf("%lld%lld", &a, &b);
    while (a >= b || a < 0 || b <= 0){
        printf("Nhap 0 <= A < B!\n");
        scanf("%lld%lld", &a, &b);
    }
    for (long long int x = a; x < b; x++)
        if(isPrime(countPrime(x))==1){
            d++;
            //printf("\nSo %ld la sieu nguyen to vi co %ld SNT nho hon %ld",x,countPrime(x),x);
        }
    printf("%lld",d);
    return 0;
}
