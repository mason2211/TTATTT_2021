/*Câu 12. Viết chương trình tìm bốn số nguyên tố liên tiếp, sao cho tổng của chúng là số nguyên tố
nhỏ hơn hoặc bằng N (với N được nhập vào từ bàn phím).*/
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
    long int n, t=0, x, i, j;
    scanf("%ld",&n);
    long int pr[n];
    for(i=2;i<=n;i++)
        if(isPrime(i)==1)
            pr[t++]=i;
    for(i=0;i<=t-3;i++){
        x = pr[i] + pr[i+1] + pr[i+2] + pr[i+3];
        if(isPrime(x)==1 && x<=n){
            printf("4 SNT can tim la %ld %ld %ld %ld", pr[i], pr[i+1], pr[i+2], pr[i+3]);
            break;
        }      
        else if (x>n){
            printf("Khong co 4 SNT lien tiep thoa man de bai!");
            break;
        }
    }  
}
