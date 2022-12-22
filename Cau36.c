/*Câu 36. Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Boyer-Moore, in giá trị của bảng.
Trong trường hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm vét cạn.*/
#include<stdio.h>
#include<string.h>
int LastOccurrence(char *P,char x){
    for(int i= strlen(P)-1; i>=0; i--)
        if(P[i]==x)
            return i;
    return -1;
}
int main(){
    char T[1000],P[1000];
    gets(P); gets(T);
    int m = strlen(P)-1;
    int i = m, j = m, check = 0;
    while( i < strlen(T)){
        if(T[i] == P[j]){
            i--; j--;
            if(j == 0){
                printf("P co trong T, vi tri bat dau la %d",i);
                check = 1;
                break;
            }
        }
        else{
            int min = j < (1 + LastOccurrence(P,T[i])) ? j : (1 + LastOccurrence(P,T[i]));
            i = i+m-min;
            j = m-1;
        }
    }
    if(check == 0)
        printf("P khong co trong T"); 
}