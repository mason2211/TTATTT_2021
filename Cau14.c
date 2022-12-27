/*Câu 14. Viết chương trình tìm số nguyên tố có ba chữ số, biết rằng nếu viết số đó theo thứ tự
ngược lại thì ta được một số là lập phương của một số tự nhiên.*/
#include <stdio.h>
#include <math.h>
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
    int check[1000+1]; //Sàng NT
    for(int i = 2 ; i <= 1000 ; i++)
        check[i]=1;
    for(int i = 2 ; i <= 1000 ; i++) 
        if(check[i]==1)
            for(int j = 2*i; j<=1000; j+=i)
                check[j]=0;
    for (int i = 101; i < 1000; i++)
        if (check[i] == 1)
            if(isCubeNumber(daoNguoc(i))==1)
                printf("So do la: %d ", i);
    return 0;
}
