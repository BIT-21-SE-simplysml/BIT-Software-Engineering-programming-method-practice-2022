#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
vector<ll> ans(100);
char get_ans(int ce, int n){
	if(ce == 0){
		if(n == 1){
			return 'h';
		}
		else return 's';
	}
	if(ans[ce - 1] >= n){
		return get_ans(ce - 1, n);
	}
	else if(n == ans[ce - 1] + 1){
		return 'h';
	}
	else if(n > ans[ce - 1] + 1 && n <= ans[ce - 1] + (ce + 3)){
		return 's';
	}
	else{
		return get_ans(ce - 1 , n - ans[ce - 1] - ce - 3);
	}
}
void solve(){
	ll n;
	cin >> n;
	ans[0] = 3;
	int ce = 0;
	for(int i = 1; i < 100; i++){
		if(ans[i - 1] >= n){
			break;
		}
		else{
			ans[i] = ans[i - 1] * 2 + 1 + (i + 2);
			ce++;
		}
	}
	cout << get_ans(ce,n) << endl;
	cout << ce << endl;
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