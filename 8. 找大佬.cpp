void guessdalao(int n) 
{ 
// finish this 
	queue<int> q;
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	while(q.size() >= 2){
		int t1 = q.front();
		q.pop();
		int t2 = q.front();
		q.pop();
		if(better(t1,t2)){
			q.push(t1);
		}
		else q.push(t2);
	}
	int ans = q.front();
	bool p = true;
	for(int i = 1; i <= n; i++){
		if(ans == i){
			continue;
		}
		if(better(ans,i) && better(i,ans) == 0){
			continue;
		}
		else{
			p = false;
			break;
		}
	}
	if(p){
		cout << ans << endl;
	}
	else{
		cout << -1 << endl;
	}
}