#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 50005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
int dp[MX]; //get_money per 1'000 dollars
void solve(){
	ll s,n,d;
	cin >> s >> n >> d;
	vector<pair<int, int> > a(d);
	for(int i = 0; i < d; i++){
		cin >> a[i].first >> a[i].second;
		a[i].first /= 1000;
	}
	while(n--){
		ll have_money = s / 1000;
		for(int i = 0; i < MX; i++){
			dp[i] = 0;
		}
		for(int i = 0; i < d; i++){
			for(int j = have_money; j >= 0; j--){
				if(j + a[i].first <= have_money){
					dp[j] = max(dp[j], dp[j + a[i].first] + a[i].second);
				}
			}
		}
		s += dp[0];
	}
	cout << s << endl;
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