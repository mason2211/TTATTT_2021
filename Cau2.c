/*Câu 2. Viết chương trình tìm các số nguyên tố có N chữ số với N nhập từ bàn phím và 2 ≤ N ≤ 10.*/
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    while (n<2 || n>10){
        printf("Nhap lai N thoa man 2 <= N <= 10: ");
        scanf("%lld",&n);
    }
    int k2 = pow(10,n), k1 = pow(10,n-1);
    int check[k2+1]; //Sàng NT
    for(int i = 2 ; i < k2 ; i++)
        check[i]=1;
    for(int i = 2 ; i < k2 ; i++) 
        if(check[i]==1)
            for(int j = 2*i; j<k2; j+=i)
                check[j]=0;
    for(int i = k1; i < k2; i++)
        if(check[i]==1)
            printf("%d ",i);  
    return 0;
}
