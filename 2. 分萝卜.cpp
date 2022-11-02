#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
void solve(){
	ll n,l,r;
	cin >> n >> l >> r;
	if(r - l >= n){
		cout << n - 1 << endl;
		return;
	}
	l %= n;
	r %= n;
	if(r < l){
		cout << n - 1 << endl;
	}
	else cout << r << endl;
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