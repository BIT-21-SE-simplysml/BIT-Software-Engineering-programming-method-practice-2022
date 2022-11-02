#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 1000005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
bool st[MX];
int dp[MX]; //get_money per 1'000 dollars
void solve(){
	int l;
	int s,t,m;
	cin >> l >> s >> t >> m;
	int temp;
	for(int i = 0; i < m; i++){
		cin >> temp;
		st[temp] = true;
	}
	for(int i = 0; i < MX; i++){
		dp[i] = 0x3f3f3f3f;
	}
	dp[0] = 0;
	for(int i = 0; i <= l; i++){
		if(st[i]) dp[i]++;
		for(int j = s; j <= t; j++){
			dp[i + j] = min(dp[i + j], dp[i]);
		}
	}
	int mn = 0x3f3f3f3f;
	for(int i = l; i <= l + 10; i++){
		mn = min(mn, dp[i]);
	}
	cout << mn << endl;
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