#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
int xa,ya,xb,yb;
const double pi = 3.1415926;
void solve(){
	int n;
	cin >> n;
	cin >> xa >> ya >> xb >> yb;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		a[i] = i;
	}
	vector<pair<int, int> > pt(n);
	vector<double> r(n);
	double ans = 0;
	double mx = 0;
	for(int i = 0; i < n; i++){
		cin >> pt[i].first >> pt[i].second;
	}
	do{
		ans = 0;
		for(int i = 0; i < n; i++){
			double mn = 10000;
			mn = min(1.0 * abs(pt[a[i]].first - xa),mn);
			mn = min(1.0*abs(pt[a[i]].second - ya),mn);
			mn = min(1.0*abs(pt[a[i]].first - xb),mn);
			mn = min(1.0*abs(pt[a[i]].second - yb),mn);
			for(int j = 0; j < i; j++){
				if(r[a[j]] == 0) continue;
				mn = min(mn, max(1.0*0, sqrt(1.0*(pt[a[i]].first - pt[a[j]].first)*(pt[a[i]].first - pt[a[j]].first) + 1.0*(pt[a[i]].second -pt[a[j]].second)*(pt[a[i]].second -pt[a[j]].second)) - r[a[j]]));
			}
			r[a[i]] = mn;
			ans += pi * mn * mn;
		}
		mx = max(mx,ans);
	}while(next_permutation(a.begin(),a.end()));
	printf("%.lf\n",(abs((xa-xb) * (ya-yb)) - mx));
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