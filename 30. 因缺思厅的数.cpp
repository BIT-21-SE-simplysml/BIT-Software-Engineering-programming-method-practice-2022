#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
void solve(){
	ll m,k;
	cin >> m >> k;
	ll tot = 0;
	ll dig_num = 0;
	ll m1 = m;
	while(m1){
		dig_num++;
		m1 /= 10;
	}
	m1 = m;
	ll bas = 1;
	for(int i = 1; i < dig_num; i++){
		bas *= 10;
	}
	while(m1){
		tot += m1 - bas + 1;
		m1 /= 10;
		bas /= 10;
	}
	if(tot > k){
		cout << 0 << endl;
		return;
	}
	if(tot == k){
		cout << m << endl;
		return;
	}
	bas = 1;
	for(int i = 0; i < dig_num; i++){
		bas *= 10;
	}
	m1 = m * 10;
	while(tot < k){
		tot += m1 - bas;
		m1 *= 10;
		bas *= 10;
	}
	cout << m1 / 10 - tot + k - 1 << endl; 
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