/*Câu 8. Một số gọi là số Т-prime nếu có có đúng 3 ước nguyên dương. Viết chương trình tìm các
số Т-prime nhỏ hơn hoặc bằng N với N cho trước nhập từ bàn phím*/
#include <stdio.h>
long long int demUoc(long long int n){
    int d=2; //ước là 1 và n
    for(long long int i=2;i<=n/2;i++)
        if(n%i==0)
            d+=1;
    return d;
}
int main(){
    long long int n,check=0;
    scanf("%lld",&n);
    while(n<=0){
        printf("Nhap n thoa man de bai: ");
        scanf("%lld",&n);
    }
    for(long long int i=2;i<=n;i++)
        if(demUoc(i)==3){
            check=1;
            printf("%lld ",i);
        }
    if(!check) printf("Khong co so T-prime < %lld",n);
    return 0;
}
