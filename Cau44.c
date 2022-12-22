/*Câu 44. Cho mảng A gồm các số nguyên thuộc 𝐹𝑝 nhập vào từ bàn phím, hãy viết chương trình in
ra mảng B có các phần tử là nghịch đảo của các phần tử tương ứng trong A. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
long long int mod(long long int x1, long long int p) {
    if (x1 >= 0) return x1 % p;
    else return x1 + p;
}
long long int gcd(long long int a, long long int b) {
    if (a == b)
        return 1;
    else if (b == 0)
        return a;
    else return gcd(b, a % b);
}
long long int modNgichDao(long long int a, long long int p){
    long long int x1 = 1, x2 = 0, m = p, n = a, q, r, x;
    while (n != 1) {
        q = m / n;
        r = m % n;
        x = x2 - q * x1;
        m = n; n = r; x2 = x1; x1 = x;
    }
    return mod(x1, p);
}
int main() {
    srand((int)time(0));
    long long int p = rand();
    long long int n = 1+ rand()%(20+1);
    printf("p = %lld, n = %lld\n",p,n);
    long long int A[n], B[n];
    printf("A = [");
    for(long long int i=0;i<n;i++){
        A[i] = rand()%(p+1);
        printf("%6lld|",A[i]);
        if(gcd(A[i],p)==1) 
            B[i]= modNgichDao(A[i],p);
        else B[i]=0;
    }
    printf("]\n");
    printf("B = [");
    for(long long int i=0;i<n;i++)
        printf("%6lld|",B[i]);   
    printf("]\n");
}