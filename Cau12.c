/*Câu 12. Viết chương trình tìm bốn số nguyên tố liên tiếp, sao cho tổng của chúng là số nguyên tố
nhỏ hơn hoặc bằng N (với N được nhập vào từ bàn phím).*/
#include <stdio.h>
#include <math.h>
int main(){
    long long int n, t=0, x, i, j;
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
    long long int pr[n];
    for(i=2;i<=n;i++)
        if(check[i]==1)
            pr[t++]=i;
    if(t<3) printf("Khong co 4 SNT lien tiep thoa man de bai!");
    for(i=0;i<=t-3;i++){
        x = pr[i] + pr[i+1] + pr[i+2] + pr[i+3];
        if (x>n){
            printf("Khong co 4 SNT lien tiep thoa man de bai!");
            break;
        }
        else{
            if(check[x]==1){
                printf("4 SNT can tim la %lld %lld %lld %lld", pr[i], pr[i+1], pr[i+2], pr[i+3]);
                break;
            }         
        }  
    }
}
