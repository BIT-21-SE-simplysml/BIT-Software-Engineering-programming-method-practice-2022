#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
void solve(){
	ll n;
	cin >>n;
	vector<ll> a(n);
	for(int i = 0; i < n ;i++){
		cin >> a[i];
	}
	ll w;
	cin >> w;
	sort(a.begin(),a.end());
	ll good = 0;
	for(int i = 0; i < n; i++){
		if(a[i] <= w){
			good = a[i];
		}
		else{
			break;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(good >= a[i]){
			good -= a[i];
			ans++;
		}
		else break;
	}
	cout << ans << endl;
	
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