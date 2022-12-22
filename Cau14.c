/*Câu 14. Viết chương trình tìm số nguyên tố có ba chữ số, biết rằng nếu viết số đó theo thứ tự
ngược lại thì ta được một số là lập phương của một số tự nhiên.*/
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
int daoNguoc(int n){
    int n1 = 0;
    while (n > 0){
        n1 = n1 * 10 + n % 10;
        n /= 10;
    }
    return n1;
}
int isCubeNumber(int n){
    for (int i = 5; i < 10; i++){
        if (i*i*i-n==0)
            return 1;
    }   
    return 0;
}
int main(){
    for (int i = 101; i <= 1000; i++){
        if (isPrime(i) == 1)
            if(isCubeNumber(daoNguoc(i))==1)
                printf("So do la: %d ", i);
            }
    return 0;
}