#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 200005
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
void solve(){
	int n;
	cin >> n;
	vector<pair<ll, ll> > a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j <n; j++){
			if(a[i].first == a[j].first &&  a[j].second == a[i].second){
				a[j].first = -10000;
				a[j].second = -10000;
			}
		}
	}
//	去重
	double ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i].first == -10000)continue;
		for(int j = i + 1; j < n; j++){
			if(a[j].first == -10000)continue;
			ll aa = a[j].second - a[i].second;
			ll bb = a[i].first - a[j].first;
			ll cc = a[i].first * a[j].second - a[i].second * a[j].first;
			int ty = 0;
			bool p = false;
			for(int k = 0; k < n; k++){
				if(a[k].first == -10000)continue;
//				bool p = false;
				if(k == i || k == j){
					continue;
				}
				if(ty == 0){
					if(aa*a[k].first + bb * a[k].second > cc){
						ty = -1;
					}
					if(aa*a[k].first + bb * a[k].second == cc){
						ty = 0;
					}
					if(aa*a[k].first + bb * a[k].second < cc){
						ty = 1;
					}
				}
				else{
					int temp = 0;
					if(aa*a[k].first + bb * a[k].second > cc){
						temp = -1;
					}
					else{
						temp = 1;
					}
					if(aa*a[k].first + bb * a[k].second == cc)
						continue;
					if(temp == ty){
						continue;
					}
					else{
						p = true;
					}
				}
			}
//			找到凸包位置
			if(!p){ 	
				bool pp = true;
				for(int k = 0; k < n; k++){
					if(k == i || k == j || a[k].first == -10000) continue;
					if(1ll * a[i].first * (a[j].second - a[k].second) + 1ll * a[j].first * (a[k].second - a[i].second) + 1ll * a[k].first * (a[i].second - a[j].second) == 0){
						int mxx = max(a[i].first,max(a[j].first,a[k].first));
						int mnx = min(a[i].first,min(a[j].first,a[k].first));
						int mxy = max(a[i].second,max(a[j].second,a[k].second));
						int mny = min(a[i].second,min(a[j].second,a[k].second));
						if((a[k].first == mnx || a[k].first == mxx) && (a[k].second == mxy || a[k].second == mny)){
							pp = false;
							break;
						}
					}
				}
				if(pp){
//					cout << "hereis::"<<a[i].first << ' ' << a[j].first << endl;
					ans += sqrt(pow(double(a[j].first - a[i].first),2) + pow(double(a[i].second - a[j].second),2));
				}
			}
		}
	}
	printf("%lf\n",ans);
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