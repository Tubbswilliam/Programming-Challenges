//Notes
//Fenecik tree/Binary indexed tree is a
//data structure that helps in performing operations/functions within a certain range.
//It also helps in updating the elements.
//It has a time complexity of O(log n).
//It takes O(n log n) to create and O(n) in space.

//As mentioned above, it is efficient in operations and updating.
//Pseudo code of sum operation and an update.
/*
def sum(int r):
    res = 0
    while (r >= 0):
        res += t[r]
        r = g(r) - 1
    return res

def increase(int i, int delta):
    for all j with g(j) <= i <= j:
        t[j] += delta

 */


//Implementation of the fenwick tree using the sum operation
//and single updating.

//You can create a Fenwick tree initialized with zeros,
//or you can convert an existing array into the Fenwick form.
struct FenwickTree {
	vector<int>bit;//Binary indexed tree
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}
	FenwickTree(vector<int>a): FenwickTree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	//Then we need to implement the sum operation
	int sum(int r) {
		int ret = 0;
		for (; r > 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}
	//Sum operation within a certain range for example L to R
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	//Afterwards then the update operation

};
