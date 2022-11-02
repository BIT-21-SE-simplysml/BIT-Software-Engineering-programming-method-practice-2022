#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define heapsize 100005

typedef struct{
	long long elem[heapsize];
	int size;
} minheap,*m;

void siftdown(minheap* H, int st, int m){
	int index = st;
	ll temp = H->elem[index];
	for(int i = 2 * index + 1; i <= m; i = 2 * i + 1){
		if(i < m && H->elem[i] > H->elem[i + 1]) i++;
		if(temp <= H->elem[i])break;
		else{
			H->elem[index] = H->elem[i];
			index = i;
		}
	}
	H->elem[index] = temp;
}
void siftup(minheap* H, int st){
	ll temp = H->elem[st];
	int j = st;
	int i = (j - 1) / 2;
	while(j){
		if(H->elem[i] <= temp) break;
		else{
			H->elem[j] = H->elem[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	H->elem[j] = temp;
}
void insert(minheap* H, ll x){
	H->elem[H->size] = x;
	siftup(H,H->size);
	H->size++;
}
void remo(minheap* H){
//	x = H.elem[0];
	H->elem[0] = H->elem[H->size - 1];
	H->size--;
	siftdown(H,0,H->size - 1);
}

ll a[100005];
minheap H;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);	
		insert(&H,a[i]);
	}
//	int t = n - 1;
	ll ans = 0;
	for(int i = 0; i < n - 1; i++){
		long long x1 = H.elem[0];
		remo(&H);
		long long x2 = H.elem[0];
		remo(&H);
		insert(&H,x1 + x2);
		ans += x1 + x2;
	}
	printf("%lld\n", ans);
}