/*Viết chương trình sinh một mảng số nguyên tố A gồm N phần tử (N nhập từ bàn phím) sử dụng kiểm tra 
Miller-Rabin. In ra mảng và tính khoảng cách nhỏ nhất giữa 2 số bất kỳ trong mảng. */
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
    long long int n, snt, B;
    long long int tmp = pow(2,k)-1;
    b1:while(1){     
        n = rand()%(tmp+1);
        B=rand();
        while (1){
            snt = rand()%(B+1);
            if(isPrime(snt)!=1)
                snt = rand()%(B+1);
            else break;
        }    
        if(n%snt==0)
            goto b1;
        if(testMiller_Rabin(n,t)==1)
            break;      
    }
    return n;
}
int main() {
    srand((int)time(0)); 
    long long int k = 2+ rand()%(100+1-2);
    long long int t = rand()%(100+1);
    long long int n = 3+ rand()%(20+1-3);
    system("cls");
    printf("n = %lld\n",n);
    long long int A[n];
    long long int i=0;
    printf("A = [");
    while(i<n){ //khởi tạo mảng A
        A[i] = RANDOMSEARCH(k,t);
        printf("%6lld|",A[i]);
        i++;
        if(i==n)
            break;
    }
    printf("]\n");
    for(long long int i=0;i<n-1;i++)
        for(long long int j=i+1;j<n;j++)
            if(A[i]>A[j]){
                long long int tmp=A[i];
                A[i]=A[j];
                A[j]=tmp;
            } 
    printf("A = [");
    for(long long int i=0;i<n;i++)
            printf("%6lld|",A[i]);
    printf("]\n");   
    printf("A = [");
    long long int min;
    for(long long int i=0;i<n-1;i++){
        A[i] = A[i+1] - A[i];
        printf("%6lld|",A[i]);
        min = A[i]<min?A[i]:min;
    }
    printf("]\n");
    printf("Khoang cach nho nhat trong mang A la %lld",min);    
    return 0;
}
