#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 1027
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
int a[MX][MX];
int b[MX][MX];
bool vis[MX][MX];
int cnt = 1;
void trie(int n, int x, int y, int stx, int sty){
	if(n == 1){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				if(stx + i != x || sty + j != y){
					a[stx + i][sty + j] = cnt;
				}
			}
		}
		cnt++;
		return;
	}
	int row = 1 << n;
	int mid = row >> 1;
	vector<pair<int, int> > pt(4);
	pt[0] = make_pair(stx + mid - 1, sty + mid - 1);
	pt[1] = make_pair(stx + mid - 1, sty + mid);
	pt[2] = make_pair(stx + mid, sty + mid - 1);
	pt[3] = make_pair(stx + mid, sty + mid);
	vector<pair<int, int> > st(4);
	st[0] = make_pair(stx,sty);
	st[1] = make_pair(stx,sty + mid);
	st[2] = make_pair(stx + mid,sty);
	st[3] = make_pair(stx + mid, sty + mid);
	int ty;
	if(x < stx + mid && y < sty + mid){
		ty = 0;
	}
	if(x < stx + mid && y >= sty + mid){
		ty = 1;
	}
	if(x >= stx + mid && y < sty + mid){
		ty = 2;
	}
	if(x >= stx + mid && y >= sty + mid){
		ty = 3;
	}
//	cout << "try(" << n << ' ' << x << ' ' << y << ' ' << stx << ' ' << sty <<" ty:" << ty << ")\n";
	for(int i = 0; i < 4; i++){
		if(i == ty) continue;
		a[pt[i].first][pt[i].second] = cnt; 
	}
	cnt++;
	for(int i = 0; i < 4; i++){
		if(i == ty){
			trie(n - 1,x,y,st[i].first,st[i].second);
			continue;
		}
		trie(n - 1,pt[i].first,pt[i].second,st[i].first,st[i].second);
	}
	return;
}

void solve(){
	int n,x,y;
	cin >> n >> x >> y;
	trie(n,x,y,1,1);
	int row = (1 << n);
	cnt = 1;
	for(int i = 1; i < row; i++){
		for(int j = 1; j <= row; j++){
			int bas = a[i][j];
			if(vis[i][j] || a[i][j] == 0)continue;
			for(int k = -1; k <= 1; k++){
				for(int q = 0; q <= 1; q++){
					if(a[i+q][j+k] == bas){
						vis[i+q][j+k] = true;
						b[i+q][j+k] = cnt;
					}
				}
			}
			++cnt;
		}
	}
	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= row; j++){
			cout << b[i][j] << ' ';
		}
		cout << endl;
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