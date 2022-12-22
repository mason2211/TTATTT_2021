/*Câu 15. Viết chương trình Hai số nguyên tố sinh đôi là hai số nguyên tố hơn kém nhau 2 đơn vị.
Tìm hai số nguyên tố sinh đôi nhỏ hơn hoặc bằng N, với N được nhập vào từ bàn phím.*/
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
    long int n;
    scanf("%ld",&n);
    for(long int i=3;i<=n-2;i++){
        if(isPrime(i)==1 && isPrime(i+2)==1)
            printf("Hai SNT sinh doi la: %ld va %ld\n",i,i+2);
    }
    return 0;
}