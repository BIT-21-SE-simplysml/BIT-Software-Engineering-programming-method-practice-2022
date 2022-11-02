#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 1000005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
//bool st[MX];
//int dp[MX]; //get_money per 1'000 dollars
bool p = false;
int a[80];
bool vis[80];
int n;
inline bool cmp(int a, int b){
	return a > b;
}

void dfs(int num, int las, int res, int piece, int nn){
//	cout << nn << endl;
	if(num == nn){
		p = true;
	}
	if(res == 0){
		int pl = n;
		for(int i = 0; i < n;i ++){
			if(vis[i] == 0){
				pl = i;
				break;
			}
		}
		vis[pl] = 1;
		if(pl == n){
			return;
		}
		dfs(num + 1,pl,piece - a[pl],piece,nn);
		vis[pl] = 0;
	}
	for(int i = las + 1; i < n; i++){
		if(vis[i] == 0 && a[i] <= res){
			vis[i] = 1;
			dfs(num,i,res - a[i],piece,nn);
			vis[i] = 0;
			if(p == true)
				return;
			while(a[i] == a[i + 1] && i < n)i++;
		}
	}
}

void solve(){
//	int n;
	cin >> n;
	int sum = 0;
	int mx = 0;
	forn(i,n){
		cin >> a[i];
	}
	forn(i,n){
		mx = max(mx,a[i]);
		sum += a[i];
	}
	vector<int> possible;
	sort(a,a+n,cmp);
	for(int i = mx; i <= sum; i++){
		if(sum % i == 0){
			for(int i = 0; i < 80; i++){
				vis[i] = false;
			}
			vis[0] = true;
			dfs(1,0,i - a[0],i,sum / i);
//			vis[0] = true; 
			if(p){
				cout << i << endl;
				return;
			}
		}
	}
	
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t;
//	cin >> t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}