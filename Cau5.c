/*Câu 5. Viết chương trình tính tổng của các số nguyên tố nằm trong khoảng [A, B] với A, B nhập 
vào từ bàn phím.*/
#include <stdio.h>
#include <math.h>
int main(){
    long long int a,b,d=0;
    scanf("%lld%lld",&a,&b);
    while (a==b || a>b || a<0 || b<0){
        printf("Nhap lai A, B thoa man 0 <= A < B: ");
        scanf("%lld%lld",&a,&b);
    }
    long long int check[b+1]; //Sàng NT
    for(long long int i = 2 ; i <= b ; i++)
        check[i]=1;
    for(long long int i = 2 ; i <= b ; i++) 
        if(check[i]==1)
            for(long long int j = 2*i; j<=b; j+=i)
                check[j]=0;
    for(long long int i=a;i<=b;i++)
        if(check[i]==1)
            d+=i;
    printf("Tong cac snt trong khoang [%lld,%lld] la: %lld",a,b,d);
    return 0;
}
