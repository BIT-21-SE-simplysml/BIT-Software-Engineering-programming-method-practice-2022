#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
inline bool cmp(ll x, ll y){
	return x > y;
}
void solve(){
	int n;
	cin >> n;
//	ll md = (1ll << 64);
	vector<ll> num(n);
	vector<ll> cost(n);
	ll temp;
	stack<ll > st;
	forn(i,n){
		cin >> num[i];
	}
	forn(i,n) cin >> cost[i];
	sort(num.begin(),num.end());
	sort(cost.begin(),cost.end());
	vector<ll> needed;
	ll mn = 0;
	ll las = -1;
	forn(i,n){
		if(las == num[i]){
			st.push(num[i]);
			continue;
		}
		while(!st.empty() && las < num[i] - 1){
			las++;
			needed.push_back(las - st.top());
			st.pop();
		}
		las = num[i];
	}
	while(!st.empty()){
		las++;
		needed.push_back(las - st.top());
		st.pop();
	}
	sort(needed.begin(),needed.end(),cmp);
	ll ans = 0;
//	ll md = (1ll << 64);
	for(int i = 0; i < needed.size(); i++){
		if(needed[i] == 0) break;
//		cout << needed[i] << ' ' << cost[i] << endl;
		ans += needed[i] * cost[i];
//		ans %= md; 
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