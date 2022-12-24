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
    long long int n,j;
    scanf("%lld",&n);
    for(long long int i=1;i<=n;i++){
        j = tongUoc(i);
        if(tongUoc(j)==i && j>i)  //(điều kiện a>i đề loại trường hợp đảo vị trí của j với i)
            printf("%lld %lld\n",i,j);
    }
    return 0;
}
