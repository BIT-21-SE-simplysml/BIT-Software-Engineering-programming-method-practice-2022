void findminandmax(int n) 
{ 
// finish this 
	vector<int> large(n);
	vector<int> small(n);
	for(int i = 1; i <= n;i ++){
		if(cmp(2 * i - 1, 2 * i) >= 0){
			large[i - 1] = 2 * i - 1;
			small[i - 1] = 2 * i;
		}
		else{
			large[i - 1] = 2 * i;
			small[i - 1] = 2 * i - 1;
		}
	}
	int index = large[0];
	for(int i = 1; i < n; i++){
		if(cmp(index, large[i]) == -1){
			index = large[i];
		}
	}
	int index2 = small[0];
	for(int i = 1; i < n; i++){
		if(cmp(index2, small[i]) == 1){
			index2 = small[i];
		}
	}
	cout << index2 << ' ' << index << endl;
	return;
}