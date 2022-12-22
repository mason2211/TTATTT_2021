/*Câu 31. Áp dụng theo các thuật toán đã được học trong phần lí thuyết em hãy cài đặt chương
trình:
- Tìm số nguyên tố k gần nhất với phần số của mã số sinh viên của mình (trong trường hợp khoảng 
cách bằng nhau thì lấy số nhỏ hơn).
- Từ số k tìm được tính a^k mod n với a = SBD, n = 123456*/
#include <stdio.h>
#include <math.h>
int isPrime(long long int n){
    if(n<=1)   
        return 0;
    if(n%2==0 || n%3==0)
        return 0;
    if(n==2 || n==3)
        return 1;
    for(long long int i=5;i<=sqrt(n);i+=6)
        if(n%i==0 || n%(i+2)==0)
            return 0;
    return 1;
}
long long int mod(long long int a, long long int b, long long int c){
    return ((a%c)*(b%c))%c;
}
int main(){
    long long int X = 170443, x1, x2, k, n = 123456, a=170443;
    for(long long int i=X;i>1;i--)
        if(isPrime(i)==1){
            x1=i;
            break;
        }
    for(long long int i=X;i<2*X;i++)
        if(isPrime(i)==1){
            x2=i;
            break;
        }
    k = (X-x1)<(x2-X)?x1:x2;
    printf("SNT gan voi %lld nhat la: %lld",X,k);

    //a = SBD (170443), tính a^k mod n
    long long int b = 1, A = a, k1=k;
    if (k1 % 2 == 1)
        b = a;
    k1/=2;
    while (k1 > 0){
        A = mod(A,A,n);
        if (k1 % 2 == 1)
            b = mod(b,A,n);
        k1/=2;
    }
    printf("\nGia tri cua %lld^%lld mod %lld la: %lld",a,k,n,b);
}
