#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
pair<double, double> p[MX / 2];
int n;
bool check(double mid){
	double mn = -MX;
	double mx = MX;
	double& r = mid;
	for(int i = 0; i < n; i++){
		if(abs(p[i].second) > mid) return true;
		double temp = pow(pow(r,2) - pow(p[i].second,2), 0.5);
		mn = max(mn,p[i].first - temp);
		mx = min(mx,p[i].first + temp);
		if(mx + 1e-8 < mn){
			return true;
		}
	}
	return false;
}

void solve(){
//	int n;
	cin >> n;
	for(int i = 0 ; i < n;i ++){
		cin >> p[i].first >> p[i].second;
	}
	double l = 0;
	double r = 30000;
	while(r - l > 1e-6){
		double mid = (l + r) / 2;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	printf("%.4f\n", l);
}

int main(){
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(0);
	int t;
//	cin >> t;
	t = 1;
	while(t--){
		solve();
	}
	return 0;
}