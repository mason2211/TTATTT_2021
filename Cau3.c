/*Câu 3. Cho một số nguyên dương N, gọi:
- k là số ước nguyên tố của N;
- q là tổng của các ước nguyên tố của N;
- p là tổng của các ước số của N;
- s là số ước của N;
Hãy viết chương trình tính giá trị của: N+p+s-q-k với N cho trước nhập từ bàn phím.
Ví dụ: N=24, có các ước là {1,2,3,4,6,8,12,24} do đó:
p=1+2+3+4+6+8+12+24=60 và s=8 trong đó có 2 ước nguyên tố là {2,3} do đó: q=2+3=5 và k=2
Và từ đó: N+p+s-q-k = 24+60+8-5-2=85;*/
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
    long long int n, k = 0, q = 0, p = 0, s = 0;
    scanf("%lld", &n);
    for (long long int i = 1; i <= n; i++){
        if (n % i == 0){
            s += 1;
            p += i;
            if (isPrime(i) == 1){
                k += 1;
                q += i;
            }
        }
    }
    printf("N+p+s-q-k = %lld",n+p+s-q-k);
    return 0;
}