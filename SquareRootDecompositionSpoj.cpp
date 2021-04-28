//SQRT Decomposition is an algorithm used
//to answer range query problems where Fenwick Tree and segment trees fail


//SQRT Dcompstn implementation

/*
int getMin(int l,int r){
	int LB=l/BLK;
	int RB=r/BLK;
	int mn= INT_MAX;

	if(LB==RB){
		for(int i=l;i<r;i++){
			mn=min(mn,arr[i])
		}
	else{
		for(int i=l;i<BLK*(LB+1);i++)
			mn=min(mn,ar[i]);
		for(int i=LB+1;i<RB;i++)
			mn=min(mn,F[i]);
		for(int i=BLK*RB;i<=r;i++)
			mn=min(mn,ar[i]);
	}

	return min;
}

*/



/*
Problem

Given an array of integers and queries of the form L,R,
how many elements exist in the given range?
*/

//Basic template of the Mo's Algorithm

for (int i = 0; i < q; i++) {
	int L = Q[i]; //l
	int R = Q[i]; //r
	int idx = Q[i]; //i

	//extending the range
	while (MR < R)MR++, add(MR);
	while (ML > L)ML--, add(ML);

	//reducing the range
	while (MR > R)remove(MR), MR--;
	while (ML < L)remove(ML), ML++;

	ans[idx] = count;
}