#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define PI pair<int, int>  
#define MP map<int, int>  
#define MX 200005  
#define forn(i, n) for(int i = 0; i < n; i++)  
#define endl '\n'  
void solve(){  
    ll n,k;  
    cin >> n >> k;  
    vector<double> a(n);  
    double sum = 0;  
    for(int i = 0; i<n ;i ++){  
        cin >> a[i];  
        sum += a[i];  
    }  
    double ave = 1.0 * sum / n;  
    double fc = 0;  
    for(int i = 0; i < n; i++){  
        fc += pow(a[i] - ave, 2);  
//      cout << fc << endl;  
    }  
    if(fc <= 0.0001){  
        cout << "No answer!\n";  
        return;  
    }  
    fc /= n;
    int num = int(sqrt(k / fc));  
    if(num == 0){
    	cout << 1 << endl;
    	return;
	}
	if(k - fc * num * num <= fc * (num + 1) * (num + 1) - k){  
        cout << num << endl;  
    }
    else cout << num + 1 << endl;  
}  
  
int main(){  
    std::ios::sync_with_stdio(false);  
    std::cin.tie(0);  
    int t;  
//  cin >> t;  
    t = 1;  
    while(t--){  
        solve();  
    }  
    return 0;  
}