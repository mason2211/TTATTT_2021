#include <stdio.h>
#include <math.h>

int m, n, flag=0;
int prime[10001];
int result[101]; // mảng chứa snt đã chọn

void Eratosthenes(int n) {
    for(int i = 2 ; i <= n ; i++)
        prime[i]=1;
	for(int i = 2; i <= n; i++)
        if(prime[i]==1)
            for(int j = 2*i; j<=n; j+=i)
                prime[j]=0;
}

// In kết quả
void printResult() { 
	printf("[ ");
	for (int i =1; i<m; i++) 
		printf("%5d, ", result[i]);
    printf("%5d ]\n", result[m]);
}

// backtracking
void tryWith(int check, int start, int sum) {
	// check: Vị trí xét
	// start: Xét từ SNT "start"
	// sum: Tổng các SNT đã chọn
	if (check > m) 
		return;
	else {
		for (int select=start; select < n; select++) {
			if (prime[select]==1) {
				sum += select; 
				result[check] = select;
				// Dùng branch and bound(Nhánh và cận) => Loại bớt các vòng for thừa
				if (check != m && sum + select*(m-check) >= n) 
					return;
				if (sum == n) 
					if (check == m){
						printResult();
						flag=1;
					} 
					else return;
				else // Nếu cận đúng thì tiếp tục tìm
					tryWith(check+1, select+1, sum);
				sum -= select;
			}
		}
	}
}
int main() {
    printf("Nhap lan luot N va M: ");
	scanf("%d%d",&n,&m);
	Eratosthenes(n);
	tryWith(1, 2, 0);
	if(flag==0)
		printf("Khong the phan tich N = %d thanh tong cua M = %d SNT!!",n,m);
	return 0;
}
