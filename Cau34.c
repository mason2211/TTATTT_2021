/*Câu 34. Cài đặt thuật toán kiểm tra số nguyên tố Fermat. Trong trường hợp số nào thì thuật toán
cho kết quả kiểm tra sai.*/
#include <stdio.h>
#include <math.h>
long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n) {
    long long int b = 1, A = a;
    if (k % 2 == 1)
        b = a;
    k /= 2;
    while (k > 0) {
        A = (A*A)%n;
        if (k % 2 == 1)
            b = (b*A)%n;
        k /= 2;
    }
    return b;
}
int Fermat(long long int a,long long int n) {
    long long int r = nhanBinhPhuongCoLap(a, n - 1, n);
    if (r!=1)
        return 0;
    return 1;
}
int main() {
    long long int n, t, a=2, check = 1;
    scanf("%lld%lld", &n, &t);
    while (t-->0) {
        if (Fermat(a, n)!= 1){
            printf("Co so a=%d: Hop so\n",a);
            check = 0;
            break;
        }
        else
            printf("Co so a=%d: Nguyen to\n",a);  
        a++;
    }
    if (check == 1)
        printf("%lld co the la nguyen to", n);
    else printf("%lld la hop so", n);
    return 0;
}
