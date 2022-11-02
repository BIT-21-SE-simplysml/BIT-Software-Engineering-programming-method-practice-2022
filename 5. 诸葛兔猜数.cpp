void guessnumber(int n){ 
	 int l = 1; int r = n + 1;
//	 int cnt = 0;
	 while(l < r){
	 	int mid = (l + r) >> 1;
//	 	cout << mid << ' ';
	 	if(guess(mid) == 0){
	 		r = mid;
		 }
		 else{
		 	l = mid + 1;
		 }
//	 	cnt++;
	 }
	 cout << l - 1 << endl;
//	 cout << cnt << endl;
}