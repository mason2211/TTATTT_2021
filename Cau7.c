/*Câu 7. Một số emirp là một số nguyên tố mà khi đảo ngược vị trí các chữ số của nó, ta cũng được
một số nguyên tố. Viết chương trình liệt kê các số emirp nhỏ hơn N với N nhập vào từ bàn phím.*/
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
long long int daoNguoc(long long int n){
    long long int n1=0;
    while (n>0){
        n1 = n1*10 + n%10;
        n/=10;
    }
    return n1;    
}
int main(){
    long long int n, check=0;;
    scanf("%lld",&n);
    while(n<=0){
        printf("Nhap n thoa man de bai: ");
        scanf("%lld",&n);
    }
    for(long long int i=0;i<n;i++)
        if(isPrime(i)==1 && isPrime(daoNguoc(i))==1){
            check=1;
            printf("%lld ",i);
        }
    if(!check) printf("Khong co so emirp < %lld",n);   
    return 0;
}
