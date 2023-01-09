/*Câu 9. Viết chương trình đếm số số nguyên tố nhỏ hơn hoặc bằng N với N được nhập vào từ bàn
phím.*/
#include <stdio.h>
#include <math.h>
int main(){
    long long int n,d=0;
    scanf("%lld",&n);
    while(n<=0){
        printf("Nhap n thoa man de bai: ");
        scanf("%lld",&n);
    }
    long long int check[n+1]; //Sàng NT
    for(long long int i = 2 ; i <= n ; i++)
        check[i]=1;
    for(long long int i = 2 ; i <= n ; i++) 
        if(check[i]==1)
            for(long long int j = 2*i; j<=n; j+=i)
                check[j]=0;
    for(long long int i=2;i<=n;i++)
        if(check[i]==1)
            d++;
    if(d!=0)
        printf("Co %lld SNT <= %lld",d,n);
    else printf("Khong co SNT nao <= %lld",n);
    return 0;
}
