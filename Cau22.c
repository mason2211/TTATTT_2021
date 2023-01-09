/*Câu 22. Với một số nguyên dương N thoả mãn 0<N<10000, đặt:
F ( N ) = N nếu N là một số nguyên tố
F ( N ) = 0 nếu là hợp số
Cho L và R nhập vào từ bàn phím, với mọi cặp i , j trong khoảng [ L , R ] hãy viết chương trình in ra màn hình 
giá trị tổng của F ( i ) * F ( j ) với j > i. */
#include <stdio.h>
#include <math.h>
int isPrime(long long int n){
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long long int i = 5; i <= sqrt(n); i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
long long int tinh(long long int i, long long int j){
    if(isPrime(i)==0 || isPrime(j)==0)
        return 0;
    else return i*j;
}
int main(){
    long long int l, r, d=0;
    scanf("%lld%lld", &l, &r);
    while (l >= r || l < 0 || r <= 0){
        printf("Nhap 0 <= L < R!\n");
        scanf("%lld%lld", &l, &r);
    }
    for (long long int i = l; i <= r-1; i++)
        for (long long int j = i+1; j <= r; j++)
            printf("\nF ( %lld ) * F ( %lld ) = %lld",i,j,tinh(i,j));
    return 0;
}
