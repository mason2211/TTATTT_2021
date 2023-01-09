/*Câu 43. Cho N nhập vào từ bàn phím (0<N<1000), sinh một số nguyên tố p<100. Hãy viết chương trình tìm tất
 cả các số nguyên a<N sao cho a^p mod N là số nguyên tố.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
int Miller_Rabin(long long int a, long long int n) {
    long long int x = n - 1, s=0, r;
    while (x % 2 == 0) {
        s += 1;
        x /= 2;
    }
    r = x;
    long long int y = nhanBinhPhuongCoLap(a, r, n);
    if (y != 1 && y != n - 1) {
        long long int j = 1;
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
int testMiller_Rabin(long long int n, long long int t){
    long long int a, check=0;
    while(t-->0){
        a = 2+rand()%(n+1-4);
        int r = Miller_Rabin(a,n);
        if(r!=1)
            return 0;
        else 
            check = 1;
    }
    if(check==1)
        return 1;
}
long long int RANDOMSEARCH(long long int k, long long int t){
    long long int n, snt, B, tmp = pow(2,k)-1;
    b1:     
    n = rand()%(tmp+1);
    B=rand();
    while (1){
        snt = rand()%(B+1);
        if(isPrime(snt)!=1)
             snt = rand()%(B+1);
        else break;
    }    
    if(n%snt==0) goto b1;
    if(testMiller_Rabin(n,t)==1)
        return n;
    else goto b1;      
}
int main() {
    srand((int)time(0)); 
    long long int n,kq=0;
    scanf("%lld",&n);
    while (n<=0 || n>=1000){
        printf("Nhap N thoa man dieu kien 0<N<1000: ");
        scanf("%lld",&n);
    }
    long long int k = rand()%(6+1);
    long long int t = rand()%(20+1);
    long long int p= RANDOMSEARCH(k,t);
    printf("p = %lld, n = %lld ",p,n);
    long long int a=2, check=0;
    long long int checkP[n+1]; //Sàng NT
    for(long long int i = 2 ; i < n ; i++)
        checkP[i]=1;
    for(long long int i = 2 ; i < n ; i++) 
        if(checkP[i]==1)
            for(long long int j = 2*i; j<n; j+=i)
                checkP[j]=0;
    while (a<n){
        kq=nhanBinhPhuongCoLap(a,p,n); 
        if(checkP[kq]==1){
            printf("\nkq = %3lld, a = %3lld ",kq,a);
        }
        a++;   
    }     
    if(kq==0) printf("Khong co so a thoa man!");        
    return 0;
}
