#include<stdio.h>
#include<stdlib.h>
#define MX 500005
int a[MX];
int temp[MX];
long long ans;
void merge(int l, int mid, int r){
	int i = l;
	int j = mid + 1;
	int k = l;
	while(i <= mid && j <= r){
		if(a[j] < a[i]){
			temp[k++] = a[j++];
			ans += 1ll * mid - i + 1;
		}
		else{
			temp[k++] = a[i++];
		}
	}
	while(i <= mid) temp[k++] = a[i++];
	while(j <= r) temp[k++] = a[j++];
	for(int i = l; i <= r; i++){
		a[i] = temp[i];
	}
}
void merge_sort(int l, int r){
	if(l < r){
		int mid = (l + r) >> 1;
		merge_sort(l,mid);
		merge_sort(mid + 1, r);
		merge(l,mid,r);
	}
}
int main(){
	int n;
	
	while(scanf("%d", &n)!=EOF){
		ans = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		merge_sort(0,n - 1);
		printf("%lld\n",ans);
	}
	
}