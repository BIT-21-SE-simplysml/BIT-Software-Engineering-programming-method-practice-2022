#include<stdio.h>
#include<stdlib.h>
int a[8];
int cnt = 0;
int ans[50000];
int cmp(const void* a, const void* b){
	return *(int*) a - *(int*) b;
}
void permutation(int *a, int m, int n){
	if(m == n){
		for(int i = 0; i < n; i++){
			ans[cnt] *= 10;
			ans[cnt] += a[i];
		}
		cnt++; 
	}
	for(int i = m; i < n; i++){
		int t = a[m];
		a[m] = a[i];
		a[i] = t;
		permutation(a,m+1,n);
		t = a[m];
		a[m] = a[i];
		a[i] = t;
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		a[i] = i + 1;
	}
	permutation(a,0,n);
	qsort(ans,cnt,sizeof(int),cmp);
	int temp[8];
	for(int i = 0; i < cnt; i++){
		for(int j = n - 1; j >= 0; j--){
			temp[j] = ans[i] % 10;
			ans[i] /= 10;
		}
		for(int j = 0; j < n; j++){
			printf("%d%c", temp[j],(j == n - 1)?'\n':' ');
		}
//		printf("\n");
	}
}

int main(){
	int t;
//	cin >> t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}