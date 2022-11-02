#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'

ll m;
//ll m = 1e9 + 7;
vector<ll> quick_matrix_pow(int j){
	vector<ll> temp;
	if(j == 1){
//		temp[0] = 0;
		temp.push_back(0);
		for(int i = 1; i < 4; i++){
			temp.push_back(1);
		}
		return temp;
	}
	vector<ll> temp2;
	if(j % 2 == 0){
		temp = quick_matrix_pow(j / 2);
		temp2.push_back((1ll * temp[0] * temp[0] + temp[1] * temp[2]) % m);
		temp2.push_back((1ll * temp[0] * temp[1] + temp[1] * temp[3]) % m);
		temp2.push_back((1ll * temp[2] * temp[0] + temp[3] * temp[2]) % m);
		temp2.push_back((1ll * temp[2] * temp[1] + temp[3] * temp[3]) % m);
		return temp2;
	}
	else{
		temp = quick_matrix_pow(j - 1);
		temp2.push_back((1ll * temp[0] * 0 + temp[1] * 1) % m);
		temp2.push_back((1ll * temp[0] * 1 + temp[1] * 1) % m);
		temp2.push_back((1ll * temp[2] * 0 + temp[3] * 1) % m);
		temp2.push_back(1ll * (temp[2] * 1 + temp[3] * 1) % m);
		return temp2;
	}
}

void solve(){
	ll i,j;
	cin >> i >> j >> m;
	ll a1 = (1ll * i - 1 + (ll)(1.0 * i * double(1 + sqrt(1.0 * 5)) / 2));
	ll a2 = (1ll * a1 * 2 - i + 1);
//	cin >> j;
//	ll a1 = 1;
//	ll a2 = 1;
	a1 %= m;
	a2 %= m;
	if(j == 1){
		cout << a1 << endl;
		return;
	}
	if(j == 2){
		cout << a2 << endl;
		return;
	}
	vector<ll> ans = quick_matrix_pow(j - 1);
	cout << (1ll * ans[0] * a1 + ans[1] * a2) % m << endl;
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