/*Câu 20. Viết chương trình in ra các cặp số (A,B) nằm trong khoảng (M,N) sao cho ước số chung
lớn nhất của A và B có giá trị là một số D cho trước. Với M,N,D nhập vào từ bàn phím. (0<M,N,D < 1000).*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int gcd(int a, int b){
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    while (m>=n || m < 0 || n<=0 || m >= 1000 || n>=1000){
        printf("Nhap 0 <= m < n < 1000\n");
        scanf("%ld%ld", &m, &n);
    }
    srand((int)time(0));
    int D = (rand()%100+1);
    printf("Random UCLN = %d",D); 
    if(n<D || n/2<D)
            printf("\n==> Khong co cap so nao!");
    else
        for(int i=m;i<n;i++){
            for(int j = i*2;j<n;j++)
                if(gcd(i,j)==D)
                    printf("\n%d va %d\n%d va %d",i,j,j,i);
            if(i==n-1)
                printf("\nHet!"); 
    }       
}