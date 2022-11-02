#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
void solve(){
	ll a,b,k;
	cin >> a >> b  >> k;
	a %= 10;
	b %= 10;
	for(int i = 0; i < k; i++){
		int c = a * b;
		a = b;
		b = c % 10;
	}
	cout << b << endl;
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