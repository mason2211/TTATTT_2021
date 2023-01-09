/*Câu 15. Viết chương trình Hai số nguyên tố sinh đôi là hai số nguyên tố hơn kém nhau 2 đơn vị.
Tìm hai số nguyên tố sinh đôi nhỏ hơn hoặc bằng N, với N được nhập vào từ bàn phím.*/
#include <stdio.h>
#include <math.h>
int main(){
    long int n,check=0;
    scanf("%ld",&n);
    while(n<=0){
        printf("Nhap n thoa man de bai: ");
        scanf("%ld",&n);
    }
    long int checkP[n+1]; //Sàng NT
    for(long int i = 2 ; i <= n ; i++)
        checkP[i]=1;
    for(long int i = 2 ; i <= n ; i++) 
        if(checkP[i]==1)
            for(long int j = 2*i; j<=n; j+=i)
                checkP[j]=0;
    for(long int i=3;i<=n-2;i++){
        if(checkP[i]==1 && checkP[i+2]==1){
            check=1;
            printf("Hai SNT sinh doi la: %ld va %ld\n",i,i+2);
        }
    }
    if(!check) printf("Khong co 2 SNT sinh doi nao thoa man de");
    return 0;
}
