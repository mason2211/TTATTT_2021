#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//xét nguyên tố
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
//đảo ngược số
int daoNguoc(int n){
    int n1 = 0;
    while (n > 0){
        n1 = n1 * 10 + n % 10;
        n /= 10;
    }
    return n1;
}
//GCD
long long int GCD(long long int a, long long int b){
    if(a<b)
        return GCD(b,a);
    if(a%b==0)
        return b;
    return GCD(b,a%b);
}
//BPCL
long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n){
    long long int b = 1, A = a;
    if (k % 2 == 1)
        b = a;
    k/=2;
    while (k > 0){
        A = mod(A,A,n);
        if (k % 2 == 1)
            b = mod(b,A,n);
        k/=2;
    }
    return b;
}
// Số Carmichael
int isCarmichael(long long int n){
    if (isPrime(n) == 1)
        return 0;
    for(int i = 2;i<n;i++)
        if (gcd(i,n) == 1)
            if (nhanBinhPhuongCoLap(i,n-1,n) != 1)
                return 0;
    return 1;
}
// a^-1 mod b
long long int mod1(long long int x1, long long int p) {
    if (x1 >= 0) return x1 % p;
    else return x1 + p;
}
long long int modNghichDao(long long int a, long long int b) {
    long long int u = b, v = a, x, x1 = 1, x2 = 0, q, r;
    while (u != 1) {
        q = v / u;
        r = v - q * u;
        x = x2 - q * x1;
        v = u;  u = r;
        x2 = x1;  x1 = x;
    }
    return mod1(x1, a);
}
//Fermat
/*int n, t, a=2, check=0;
    srand((int)time(0));
    n = rand();
    t = 500+rand()%(1000+1-500);
    printf("Kiem tra so nguyen n=%d trong %d lan:\n",n,t);
    while(t-->0){
        a = 2+rand()%(n+1-4);
        int r = nhanBinhPhuongCoLap(a,n-1,n);
        if(r!=1){
            printf("Co so a=%d: Hop so\n",a);
            break;
        } 
        else {
            printf("Co so a=%d: Nguyen to\n",a);
            check = 1;
        }
    }
    if(check==1)
        printf("%d co the la nguyen to",n);
    else printf("%d la hop so",n);*/

//Miller-Rabin
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
            y = mod(y, y, n);
            if (y == 1) 
                return 0;
            j++;
        }
        if (y != n - 1) 
            return 0;
    }
    return 1;
}
/*long long int n, t, s = 0, r, a=2, check = 0;
    srand((int)time(0));
    n = rand();
    t = 10+rand()%(20+1-10);
    printf("Kiem tra so nguyen n=%lld trong %lld lan:\n",n,t);
    while(t-->0){
        a = 2+rand()%(n+1-4);
        int r = Miller_Rabin(a,n);
        if(r!=1){
            printf("Co so a=%d: Hop so\n",a);
            break;
        } 
        else {
            printf("Co so a=%d: Nguyen to\n",a);
            check = 1;
        }
    }
    if(check==1)
        printf("%d co the la nguyen to",n);
    else printf("%d la hop so",n);*/
    
// Random Search
int testMiller_Rabin(long long int n, long long int t){
    long long int a, check=0;
    while(t-->0){
        a = 2+rand()%(n+1-4);
        int r = Miller_Rabin(a,n);
        if(r!=1)
            return 0;
        else 
            check = 1;
        a++;
    }
    if(check==1)
        return 1;
}

long long int RANDOMSEARCH(long long int k, long long int t){
    long long int n;
    long long int tmp = pow(2,k)-1;
    while(1){      
        n = rand()%(tmp+1);
        long long int B=rand();
        long long int snt = rand()%(B+1);
        while (1){
            snt = rand()%(B+1);
            if(isPrime(snt)!=1)
                snt = rand()%(B+1);
            else break;
        }    
        while (n%snt==0)
            n = rand()%(tmp+1);
        if(testMiller_Rabin(n,t)==1)
            break;    
    }
    return n;
}

