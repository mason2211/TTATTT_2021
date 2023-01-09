/*Câu 24. Đặt S1, S2 là các mảng chứa giá trị bình phương của các số nguyên. Hãy viết chương trình in ra số lượng tất cả 
các số nguyên tố nằm trong khoảng [a,b] sao cho số này cũng là tổng của hai số x và y với x thuộc S1 và y thuộc S2. 
Trong đó, a,b là các số được nhập từ bàn phím
Ví dụ: với a=10, b =15, in ra giá trị là 1 vì trong khoảng [10,15] chỉ có 2 số nguyên tố 11 và 13, nhưng chỉ có 13 = 2^2 + 3^2=4+9.*/
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
    long long int a, b, d=0;
    scanf("%lld%lld", &a, &b);
    while (a >= b || a < 0 || b <= 0){
        printf("Nhap 0 <= A < B!\n");
        scanf("%lld%lld", &a, &b);
    }
    long long int n1=sqrt(a+b);
    long long int S1[n1+1], S2[n1+1];
    for(long long int i = 1; i<=n1;i++){
        S1[i] = pow(i,2);
        S2[i] = pow(i,2);
    }   
    for(long long int i=1;i<n1;i++)
        for(long long int j=i+1;j<n1;j++)
            if(isPrime(S1[i]+S2[j])==1 && (S1[i]+S2[j])>=a && (S1[i]+S2[j])<=b){
                d+=1;
                printf("%lld + %lld = %lld\n", S1[i], S2[j], S1[i]+S2[j]);
            }
    printf("%lld", d);
    return 0;
}
