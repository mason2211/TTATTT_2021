/*Viết chương trình tính tổng của các số nguyên tố nhỏ hơn hoặc bằng N với N được nhập từ bàn phím.*/
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
    long long int n, d=0;
    scanf("%lld",&n);
    for(long long int i=1;i<=n;i++)
        if(isPrime(i)==1)
            d+=i;
    printf("Tong cac so nguyen to nho hon bang N la: %lld",d);        
    return 0;
}