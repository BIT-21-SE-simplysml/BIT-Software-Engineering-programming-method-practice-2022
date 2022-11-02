#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
void solve(){
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	forn(i,n){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	ll ans1,ans2;
	ans1 = 0;
	ans2 = 0;
	forn(i,n){
		if(a[i] * i >= ans1){
			ans1 += m;
		}
	}
	forn(i,n){
		int j = n - i - 1;
		if(a[j] * i >= ans2){
			ans2 += m;
		}
	}
//	cout <<ans1 << endl << ans2 << endl;
	cout<<fixed<<setprecision(2)<<(1.0 * max(ans1,ans2) / (1.0*n)) << ' ' << 1.0 * min(ans1,ans2) / n << endl;
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