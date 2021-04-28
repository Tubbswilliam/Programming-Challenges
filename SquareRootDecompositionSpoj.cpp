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