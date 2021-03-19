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
	//Binary indexed tree
};
