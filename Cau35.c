/*Câu 35. Cài đặt thuật toán kiểm tra số nguyên tố Miller-Rabin in ra kết luận về 1 số nguyên
dương N nhập vào từ bàn phím với xác suất kết luận tương ứng sau thuật toán. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
int Miller_Rabin(long long int a, long long int n) {
    long long int x = n - 1, s=0, r;
    while (x % 2 == 0) {
        s += 1;
        x /= 2;
    }
    r = x;
    long long int y = nhanBinhPhuongCoLap(a, r, n);
    if (y != 1 && y != n - 1) {
        int j = 1;
        while (j <= s - 1 && y != n - 1) {
            y = (y*y)%n;
            if (y == 1) 
                return 0;
            j++;
        }
        if (y != n - 1) 
            return 0;
    }
    return 1;
}
int main() {
    long long int n, t, s = 0, r, a=2, check = 0;
    //srand((int)time(0));
    scanf("%lld%lld",&n,&t);
    //t = 10+rand()%(20+1-10);
    printf("Kiem tra so nguyen n=%lld trong %lld lan:\n",n,t);
    while(t-->0){
        //a = 2+rand()%(n+1-4);
        int r = Miller_Rabin(a,n);
        if(r!=1){
            printf("Co so a=%d: Hop so\n",a);
            break;
        } 
        else {
            printf("Co so a=%d: Nguyen to\n",a);
            check = 1;
        }
        a++;
    }
    if(check==1)
        printf("%d co the la nguyen to",n);
    else printf("%d la hop so",n);
    return 0;
}
