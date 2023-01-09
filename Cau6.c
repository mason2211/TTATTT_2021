/*Câu 6. Hai số tạo thành một cặp số thân thiết khi chúng tuân theo quy luật: Số này bằng tổng tất
cả các ước của số kia (trừ chính số đó) và ngược lại. Viết chương trình tìm hai số dạng này nhỏ
hơn N (với N nhập vào từ bàn phím).*/
#include <stdio.h>
long long int tongUoc(long long int a){
    long long int d=1;
    for(long long int i=2;i<=a/2;i++)
        if(a%i==0)
            d+=i;
    return d;
}
int main(){
    long long int n,j, check=0;
    scanf("%lld",&n);
    while(n<=0){
        printf("Nhap n thoa man de bai: ");
        scanf("%lld",&n);
    }
    for(long long int i=1;i<=n;i++){
        j = tongUoc(i);
        if(tongUoc(j)==i && j>i && j<n){ // (j>i) để loại trường hợp i j đảo vị trí cho nhau
            printf("%lld %lld\n",i,j);
            check=1;
        }
    }
    if(!check) printf("Khong co cap so than thiet < %lld",n);
    return 0;
}
