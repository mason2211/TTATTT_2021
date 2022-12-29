/*Câu 39. Cho mảng A nhập từ bàn phím gồm các số nguyên dương. Hãy viết chương trình tìm các
cặp số (i,j) trong mảng A sao cho ước chung lớn nhất của chúng là một số nguyên tố.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int isPrime(long long int n){
    if(n<2)
        return 0;
    if(n==2 || n==3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    for(long long int i=5;i<=sqrt(n);i+=6)
        if(n%i==0 || n%(i+2)==0)
            return 0;
    return 1;
}
long long int GCD(long long int a, long long int b){
    if(a<b)
        return GCD(b,a);
    if(a%b==0)
        return b;
    return GCD(b,a%b);
}
int main(){
    long long int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%lld",&n);
    long long int a[n];
    srand((int)time(0));
    for(long long int i=0;i<n;i++){
        a[i] = rand();
        printf("%lld ",a[i]);
    }   
    printf("\n");  
    for(long long int i=0;i<n-1;i++)
        for(long long int j=i+1;j<n;j++){
            long long int gcd = GCD(a[i],a[j]);
            if(isPrime(gcd)==1)
                printf("a[%lld], a[%lld] , GCD(a[%lld],a[%lld]) = %lld\n",i,j,i,j,gcd);
        }
}
