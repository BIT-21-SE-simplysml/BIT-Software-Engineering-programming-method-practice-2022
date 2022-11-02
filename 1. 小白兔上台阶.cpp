#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(41,1);
	for(int i = 2; i < 41; i++){
		a[i] = a[i-1] + a[i - 2];
	}
	cout << a[n] << endl;
}