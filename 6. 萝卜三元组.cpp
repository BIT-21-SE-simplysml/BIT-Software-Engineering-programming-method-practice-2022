int findMinDiffWeight(int n) 
{ 
	int x = 0;
	int y = 0;
	int z = 0;
	int mn = 2 * 1e9;
	for(int i = 0; i < 3 * n; i++){
		mn = min(mn, DiffWeight(x,y,z));
		int index = xls_min(x,y,z);
		if(index == 1){
			++x;
			if(x == n){
				break;
			}
		}
		if(index == 2){
			++y;
			if(y == n){
				break;
			}
		}
		if(index == 3){
			++z;
			if(z == n){
				break;
			}
		}
	}
//	cout << mn << endl;
	return mn;
}