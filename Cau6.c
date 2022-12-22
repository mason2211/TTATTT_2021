/*Câu 6. Hai số tạo thành một cặp số thân thiết khi chúng tuân theo quy luật: Số này bằng tổng tất
cả các ước của số kia (trừ chính số đó) và ngược lại. Viết chương trình tìm hai số dạng này nhỏ
hơn N (với N nhập vào từ bàn phím).*/
#include <stdio.h>
int thanThiet(long long int a,long long int b){
    long long int d1=0, d2=0;
    for(long long int i=1,j=1;i<=a/2,j<=b/2;i++,j++){
        if(a%i==0)
            d1+=i;
        if(b%j==0)
            d2+=j;
    }    
    if(d1==b && d2==a)
            return 1;
    return 0;
}
int main(){
    long long int n, d=0;
    scanf("%lld",&n);
    for(long long int i=1;i<n;i++){
        for(long long int j=i+1;j<(2*i<n?2*i:n);j++)
            if(thanThiet(i,j)==1)
                printf("%lld va %lld thoa man\n",i,j);   
        if(i==n-1)
            printf("Ket thuc");
    }

    return 0;
}
