#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 105
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
const double eps = 1e-6;
double a[MX][MX];

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		double mx = -1;
		int pl = 0;
		for(int j = i; j < n; j++){
			if(abs(a[j][i]) > mx){
				pl = j;
				mx = a[j][i];
			}
		}
		if(pl != i){
			double temp;
			for(int k = 0; k <= n; k++){
				temp = a[i][k];
				a[i][k] = a[pl][k];
				a[pl][k] = temp;
			}
		}
		double temp = a[i][i];
		if(abs(a[i][i]) < eps){
			cout << "No Solution\n";
			return;
		}
		for(int k = i; k <= n; k++){
			a[i][k] /= temp;
		}
		for(int j = i + 1; j < n; j++){
			for(int k = n; k >= i; k--){
				a[j][k] -= a[j][i] * a[i][k];
			}
		}
	}
	vector<double> ans(n,0);
	for(int i = n - 1; i >= 0; i--){
		for(int j = i + 1; j < n; j++){
			a[i][n] -= ans[j] * a[i][j];
		}
		ans[i] = a[i][n];
	}
	cout.setf(ios::fixed);
	for(int i = 0; i < n; i++){
		cout << fixed << setprecision(2) << ans[i] << endl;
	}
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