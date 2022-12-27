/*Câu 19. Viết chương trình in ra các số nguyên dương x nằm trong khoảng [m,l] sao cho giá trị
của biểu thức 𝐴𝑥^2 + 𝐵𝑥 + 𝐶 là một số nguyên tố. Với A,B,C, m,l là các số nguyên nhập từ bàn phím (m<l).*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int isPrime(long int n){
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
int main()
{
    long int m, l, r = 100,check=0;
    scanf("%ld%ld", &m, &l);
    while (m >= l || m < 0 || l <= 0)
    {
        printf("Nhap 0 <= m < l!\n");
        scanf("%ld%ld", &m, &l);
    }
    srand((int)time(0));
    long int A =(rand() % r + 1);
    long int B =(rand() % r + 1);
    long int C =(rand() % r + 1);
    printf("A = %ld; B = %ld; C = %ld\n", A, B, C);
    for (long int x = m; x < l; x++){
        if (isPrime(A * x * x + B * x + C) == 1){
            printf("x = %ld\n", x); 
            check=1;
        }             
    }
    if (check==0)
        printf("Khong co x thoa man!");
    return 0;
}
