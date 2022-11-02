#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI pair<int, int>
#define MP map<int, int>
#define MX 105
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
int rank1[MX];
int rank2[MX];
int ty[MX];
bool is_two[MX];

void solve(){
	int n,m;
	cin >> n;
	vector<string> s1(n);
	getline(cin,s1[0]);
	for(int i = 0; i < n; i++)getline(cin,s1[i]);
	cin >> m;
	vector<string> s2(m);
		getline(cin,s2[0]);
	for(int i = 0; i < m; i++)getline(cin,s2[i]);
//	cout << "S1 FROM HERE\n";
//	forn(i,n) cout << s1[i] << endl;
//	cout << "HERE IS S2\n";
//	forn(i,m) cout << s2[i] << endl;
	for(int i = 0; i < MX; i++){
		rank1[i] = -1;
		rank2[i] = -1;
		ty[i] = 0;
		is_two[i] = false;
	}
	int rank = 1;
	for(int i = 0; i < n; i++){
		int temp = 0;
		int peo = 0;
		for(int j = 0; j < s1[i].size(); j++){
			if(s1[i][j] == ' '){
				if(temp){
					peo++;
					rank1[temp] = rank;
				}
				temp = 0;
			}
			if(s1[i][j] >= '0' && s2[i][j] <= '9'){
				temp *= 10;
				temp += s1[i][j] - '0';
			}
		}
		if(temp){
			peo++;
			rank1[temp] = rank;
		}
		temp = 0;
		rank += peo;
	}
	rank = 1;
	for(int i = 0; i < m; i++){
		int temp = 0;
		int peo = 0;
		for(int j = 0; j < s2[i].size(); j++){
			if(s2[i][j] == ' '){
				if(temp){
					peo++;
					rank2[temp] = rank;
				}
				temp = 0;
			}
			if(s2[i][j] >= '0' && s2[i][j] <= '9'){
				temp *= 10;
				temp += s2[i][j] - '0';
			}
		}
		if(temp){
			peo++;
			rank2[temp] = rank;
		}
		temp = 0;
		rank += peo;
	}
//  use_for_Debug
//	for(int i = 0; i < MX; i++){
//		if(rank1[i] != -1){
//			cout << "i is " << i << " : rank1 is : " << rank1[i] <<"\n"; 
//		}
//	}
//	for(int i = 0; i < MX; i++){
//		if(rank2[i] != -1){
//			cout << "i is " << i << " : rank2 is : " << rank2[i] <<"\n"; 
//		}
//	}

	vector<int> only_1;
	vector<int> only_2;
	vector<int> bth;
	for(int i = 0; i < MX; i++){
		if(rank1[i] != -1){
			ty[i] += 1;
		}
	}
	for(int i = 0; i < MX; i++){
		if(rank2[i] != -1){
			ty[i] += 2;
		}
	}
	for(int i = 0; i < MX; i++){
		if(ty[i] == 1){
			only_1.push_back(i);
		}
		if(ty[i] == 2){
			only_2.push_back(i);
		}
		if(ty[i] == 3){
			bth.push_back(i);
			is_two[i] = true;
		}
	}
	// find the rank
	// rule 1;
	for(int i = 0; i < bth.size(); i++){
		int mnp = i;
		for(int j = i + 1; j < bth.size(); j++){
			if(rank1[bth[j] ] + rank2[bth[j]] < rank1[bth[mnp]] + rank2[bth[mnp]]){
				mnp = j;
			}
		}
		swap(bth[mnp],bth[i]);
	}
	vector<vector<int> > final_list;
	vector<int> temp;
	las = -1;
	for(int i = 0; i < bth.size(); i++){
//		las = -1;
		
	}
	
	// rule 2;
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