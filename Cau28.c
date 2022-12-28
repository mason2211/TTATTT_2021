/*Câu 28. Viết chương trình tìm các số Carmichael (là các số giả nguyên tố n thoả mãn điều kiện là
hợp số và thoả mãn 𝑏^(𝑛−10 ≡ 1 (𝑚𝑜𝑑 𝑛) với mọi số nguyên dương b nguyên tố cùng nhau với n)
nhỏ hơn một số N cho trước nhập vào từ bàn phím (với điều kiện 0 ≤ 𝑁 ≤ 10000.*/
#include <stdio.h>
#include <math.h>
long long int gcd(long long int a, long long int b){
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
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
int isCarmichael(long long int n){
    if (isPrime(n) == 1)
        return 0;
    for(int i = 2;i<n;i++)
        if (gcd(i,n) == 1)
            if (nhanBinhPhuongCoLap(i,n-1,n) != 1)
                return 0;
    return 1;
}
int main(){
    long long int n, check=0;
    scanf("%lld", &n);
    while (n < 0 || n >10000){
        printf("Nhap 0 <= N <= 10000!\n");
        scanf("%lld", &n);
    }
    for (long long int i = 2; i <= n; i++)
        if (isCarmichael(i) == 1){
            check=1;
            printf("%lld ", i);
        }
    if(check==0)
        printf("Khong co so Carmichael < %lld",n);
    return 0;          
}
