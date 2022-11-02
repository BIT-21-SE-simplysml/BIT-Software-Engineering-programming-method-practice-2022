#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
ll a[405][405];
ll solve(int n, int m){
	if(a[n][m] > 0){
		return a[n][m];
	}
	if(n == 1 || m == 1) return a[n][m] = 1;
	if(n < m) return a[n][m] = solve(n,n);
	if(n == m) return a[n][m] = solve(n,n - 1) + 1;
	return a[n][m] = solve(n, m - 1) + solve(n - m,m);	
}
void solve1(){
	int n;
	cin >> n;
	for(int i = 0; i < 405; i++){
		for(int j = 0; j < 405; j++){
			a[i][j] = -1;
		}
	}
	cout << solve(n,n) << endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t;
//	cin >> t;
	t = 1;
	while(t--){
		solve1();
	}
	return 0;
}