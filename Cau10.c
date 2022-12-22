/*Câu 10. Viết chương trình đếm số ước và số ước nguyên tố của một số N nhập vào từ bàn phím*/
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
    long long int n, d1=0, d2=0;
    scanf("%lld",&n);
    for(long long int i=1;i<=n;i++)
        if(n%i==0){
            d1+=1;
            if(isPrime(i)==1)
                d2+=1;
        }
    printf("So uoc cua N la: %lld\nSo uoc nguyen to cua N la: %lld",d1,d2);        
    return 0;
}