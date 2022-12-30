/*Câu 36. Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Boyer-Moore, in giá trị của bảng.
Trong trường hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm vét cạn.*/
#include<stdio.h>
#include<string.h>
# define CHARS 256
// int lastOccurrence(char P[],char x){
//     for(int i= strlen(P)-1; i>=0; i--)
//         if(P[i]==x)
//             return i;
//     return -1;
// }
void LastOccurrence( char P[], int size, int badchar[CHARS])
{
    int i;
    int check[1000];
    for (i = 0; i < CHARS; i++){
        badchar[i] = -1;
        check[i]=-1;
    }
         
    for (i = size-1; i >=0 ; i--){
        badchar[(int) P[i]] = i;
        if(check[(int) P[i]]==-1){
            printf("%c: %d\n",P[i],i);
            check[(int) P[i]]=1;
        }    
    } 
}
int main(){
    char T[1000],P[1000];
    gets(T); gets(P); 
    int m= strlen(P);
    int i= m-1, j=m-1, min, check=0;
    int badchar[CHARS];
    LastOccurrence(P, m, badchar);
    while( i < strlen(T)){
        if(T[i]==P[j]){
            if(j==0){
                printf("P co xuat hien trong T, co vi tri bat dau la %d",i);
                check=1;
                break;
            }
            i--; j--;
        }
        else{
            //min = j < (1 + lastOccurrence(P,T[i])) ? j : (1 + lastOccurrence(P,T[i])) ;
            min = j < (1 + badchar[T[i]]) ? j : (1 + badchar[T[i]]) ;
            i = i+m-min;
            j = m-1;
        }
    }
    if(check==0) printf("P khong xuat hien trong T!");
}
