#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
void solve(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll y = 1;
	int cnt = 0;
	while(b * y < c * d){
		if((a * c * y) % (c*d-b*y) == 0){
			++cnt;
		}
		++y;
	}
	cout << cnt << endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t;
	cin >> t;
//	t = 1;
	while(t--){
		solve();
	}
	return 0;
}