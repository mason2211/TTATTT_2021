/*Câu 13. Viết chương trình tìm hai số nguyên tố nhỏ hơn hoặc bằng N với N nhập vào từ bàn
phím, sao cho tổng và hiệu của chúng đều là số nguyên tố.*/
#include <stdio.h>
#include <math.h>
int isPrime(long long int n){
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long int i = 5; i <= sqrt(n); i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
int main(){
    long  int n, i, j,check=0;;
    scanf("%ld",&n);
    while(n<=0){
        printf("Nhap n thoa man de bai: ");
        scanf("%lld",&n);
    }
    for(i=2;i<=n;i++){
        if(isPrime(i)==1)
            for(j=i+1;j<=n;j++)
                if(isPrime(j)==1)
                    if(isPrime(i+j)==1 && isPrime(j-i)==1){
                        printf("2 SNT can tim la %d va %d",i,j);
                        check=1;
                    }    
                break;
        break;
    }
    if(!check) printf("Khong co cap so nao thoa man");
    return 0;
}
