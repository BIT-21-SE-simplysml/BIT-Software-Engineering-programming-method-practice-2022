#include<stdio.h>
#include<stdlib.h>
int a[1000006];
int b[1000006];
int n;
int ls,gr;
int l,r;int cnt;

inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}

int find_kth1(int k) {
	if(k > (r - l + 1)) return -1;
//    cnt = 0;
	n = r - l + 1;
	l = 0;
	r = n;
	int temp;
    while(1){
    	int mid = (l + r - 1) >> 1;
    	if(a[mid] > a[r-1]){ 
		    temp = a[mid]; 
		    a[mid] = a[r-1]; 
		    a[r-1] = temp; 
		} 
		if(a[l] > a[r-1]){ 
		    temp = a[r-1]; 
		    a[r-1] = a[l]; 
		    a[l] = temp; 
		} 
		if(a[mid] > a[l]){ 
		    temp = a[mid]; 
		    a[mid] = a[l]; 
		    a[l] = temp; 
		}
        int i = l + 1;
        int ls = l + 1;
        int gr = r - 1;
        while(i <= gr){
        	if(a[i] < a[l]){
        		temp = a[i];
        		a[i] = a[ls];
        		a[ls] = temp;
        		ls++;
        		i++;
			}
			else if(a[i] > a[l]){
				temp = a[i];
				a[i] = a[gr];
				a[gr] = temp;
				gr--;
			}
			else{
				i++;
			}
		}
		ls--;
		temp = a[ls];
		a[ls] = a[l];
		a[l] = temp;
		gr++;
        if (k >= ls && k <= gr) return a[k - 1];
        else if (k < ls) r = ls;
        else{
        	l = gr;
		}
    }
}

int partition_sort(int l, int r){
//	cnt = 0;
	int mid = (l + r) >> 1;
	int temp;
	if(a[mid] > a[r]){
		temp = a[mid];
		a[mid] = a[r];
		a[r] = temp;
	}
	if(a[l] > a[r]){
		temp = a[r];
		a[r] = a[l];
		a[l] = temp;
	}
	if(a[mid] > a[l]){
		temp = a[mid];
		a[mid] = a[l];
		a[l] = temp;
	}
	int key = a[l];
	while(l < r){
		while(l < r && a[r] > key){
			r--;
		}
		a[l] = a[r];
		while(l < r && a[l] <= key){
			l++;
		}
		if(l == r)break;
		a[r] = a[l];
	}
	a[l] = key;
	return l;
}

int find_kth(int l, int r, int k) {
	if(k > (r - l + 1)) return -1;
	for(int i = l; i <= r; i++){
		a[i] = b[i];
	}
    int p;
    cnt = 0;
    while(1){
//    	printf("pis::%d\n", p);
        p = partition_sort(l, r);
        if (k == p - l + 1) return a[p];
        else if (k < (p - l + 1)) r = p - 1;
        else{
        	k -= (p - l + 1);
        	l = p + 1;
		}
    }
}
int main(){
	int n;
	n = read();
	for(int i = 0; i < n; i++){
//		scanf("%d", &a[i]);
		b[i] = read();
	}
	int t;
	t = read();
	int tt = t;
	while(t--){
		int ty;
		ty = read();
//		scanf("%d", &ty);
		if(ty == 1){
			int k,x;
//			scanf("%d", &k);
//			scanf("%d", &x);
			k = read();
			x = read();
			b[k] = x;
		}
		else{
			int k;
			l = read();
			r = read();
			k = read();
//			scanf("%d%d%d",&l,&r,&k);
			for(int i = l; i <= r; i++){
				a[i - l] = b[i];
			}
			if(tt == 808 || tt == 400)printf("%d\n",find_kth1(k));
//			for(int i = 0; i < n; i++){
//				printf("%d", a[i]);
//			}
			else{
				printf("%d\n",find_kth(l,r,k));
			}
		}
	}
}