#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
void solve(){
	int n,x;
	cin >> n >> x;
	map<int, int> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		m[a[i]] = 1;
	}
	for(int i = 0; i < n; i++){
		if(m.count(x - a[i])){
			cout << "true\n";
			return;
		}
	}
	cout << "false\n";
	return;
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