/*Câu 21. Một số gọi là siêu số nguyên tố nếu số lượng các số nguyên tố từ 1 đến X (ngoại trừ X) là
một số nguyên tố. Hãy viết chương trình đếm số lượng các siêu số nguyên tố này trong khoảng
[A,B] cho trước nhập từ bàn phím.*/
#include <stdio.h>
#include <math.h>
long long int countPrime(long long int n, long long int check[n]){
    int d = 0;
    for(long int i = 2; i<n;i++)
        if(check[i]==1)
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
    long long int check[b+1]; //Sàng NT
    for(long long int i = 2 ; i < b ; i++)
        check[i]=1;
    for(long long int i = 2 ; i < b ; i++) 
        if(check[i]==1)
            for(long long int j = 2*i; j<b; j+=i)
                check[j]=0;
    for (long long int x = a; x < b; x++)
        if(check[countPrime(x,check)]==1){
            d++;
            //printf("\nSo %lld la sieu nguyen to vi co %lld SNT nho hon %lld",x,countPrime(x,check),x);
        }
    printf("So cac so sieu nguyen to trong khoang tren la: %lld",d);
    return 0;
}
