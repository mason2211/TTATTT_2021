/*Câu 17. Viết chương trình tìm số nguyên dương x nhỏ nhất và nhỏ hơn N nhập từ bàn phím sao cho giá trị 
của biểu thức 𝐴𝑥^2 + 𝐵𝑥 + 𝐶 là một số nguyên tố với A,B,C là các số nguyên nhập vào từ bàn phím*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
    long int n, r=100,check=0;;
    scanf("%ld",&n);
    srand((int)time(0));
    long int A = (rand()%r+1);
    long int B = (rand()%r+1);
    long int C = (rand()%r+1);
    printf("A = %ld; B = %ld; C = %ld\n",A, B, C);
    for(long int x=0;x<n;x++){
        if(isPrime(A*x*x + B*x + C)==1){
            printf("x = %ld",x);
            check=1;
            break;
        }     
    }
    if(!check) printf("Khong co x thoa man!!!");
    return 0;
}
