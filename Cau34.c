/*Câu 34. Cài đặt thuật toán kiểm tra số nguyên tố Fermat. Trong trường hợp số nào thì thuật toán
cho kết quả kiểm tra sai.*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int nhanBinhPhuongCoLap(int a, int k, int n){
    int b=1, A=a;
    if(k%2==1)
        b=a;
    k/=2;
    while(k%2==0){
        A = (A*A)%n;
        if(k%2==1)
            b = (A*b)%n;
        k/=2;
    }
    return b;
}
int main(){
    //a^(n-1) mod n
    int n, t, a=2, check=0;
    srand((int)time(0));
    n = rand();
    t = 500+rand()%(1000+1-500);
    printf("Kiem tra so nguyen n=%d trong %d lan:\n",n,t);
    while(t-->0){
        a = 2+rand()%(n+1-4);
        int r = nhanBinhPhuongCoLap(a,n-1,n);
        if(r!=1){
            //printf("Co so a=%d: Hop so\n",a);
            break;
        } 
        else {
            //printf("Co so a=%d: Nguyen to\n",a);
            check = 1;
        }
    }
    if(check==1)
        printf("%d co the la nguyen to",n);
    else printf("%d la hop so",n);
    return 0;
}
