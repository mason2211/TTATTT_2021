/*Câu 37. Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Knutt-Morris-Patt. Trong trường
hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm vét cạn?*/
#include<stdio.h>
#include<string.h>

int soSanhChuoi(char p[], int j, int i){
    int check = 0;
    for(int k = 0; k < i; k++) // kiem tra chuoi tien to voi chuoi tien to
        if(p[k] == p[j - i + k])   // kiem tra tung ki tu cua chuoi tien to voi ki tu cua chuoi tien to
            check++;  
    if(check == i)
        return 1;
    return 0;
}
int kiemTra(char p[], int j){
    for(int i = j-1; i >= 1; i--)
        if(soSanhChuoi(p, j, i) == 1)
            return i;
    return 0;
}
void failureFunction(char p[], int f[]){
    f[0]=-1;
    f[1]=0;
    for(int j = 2; j < strlen(p); j++){
        f[j] = kiemTra(p, j);
    }
}
int xuLy(char t[], char p[], int f[]){
    int i = 0, j = 0, check = 0, sopheptinhlap = 0;
    while(i < strlen(t) - strlen(p) ){
        int checkp = j, k = i+j;
        while(checkp != strlen(p)){
            if(t[k] == p[j]){
                k++;
                j++;
                checkp++;
                sopheptinhlap++;
            } else {
                i = i + j - f[j];
                j = f[j] == -1 ? 0 : f[j];
                sopheptinhlap++;
                break;
            }
        }
        if(checkp == strlen(p)){
            printf("P co trong T, tai vi tri %d", i);
            check = 1;
            j=0;
            i=i+strlen(p);
        }
    }
    if(check == 0){
        printf("P khong co trong T!");
    }
    return sopheptinhlap;
}
int main(){
    char t[1000],p[1000];
    gets(t); gets(p);
    int f[strlen(p)];
    failureFunction(p, f);
    int sopheptinhlap = xuLy(t, p, f);
    printf("\nSo phep tinh lap la: %d", sopheptinhlap);
    return 0;
}