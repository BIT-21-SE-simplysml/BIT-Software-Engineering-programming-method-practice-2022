#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 505
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'

void solve(){
	int n,m;
	cin >> n >> m;
	if(m == 0){
		cout << 1 << endl;
		return;
	}
	if(n == 1){	
		cout << 2 << endl;
		return;
	}
	if(n == 2){
		if(m == 1){
			cout << 3 << endl;
			return;
		}
		cout << 4 << endl;
		return;
	}
	if(m == 1){
		cout << 4 << endl;
		return;
	}
	if(m == 2)cout << 7 << endl;
	else cout << 8 << endl;
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