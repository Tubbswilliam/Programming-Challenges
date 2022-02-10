#Linear search
def linear_search(lis,target):
	"""
	Returns index position of the target if target found else none.
	"""
	for i in range(0,len(list)):
		if list[i]==target:
			return i
	return None

#Binary search
def inary_search(list,target):
	l=0
	r=len(list)-1
	while(l<=r):
		m=(r+l)//2
		if list[m]==target:
			return m
		elif list[m]<target:
			l=m+1
		else:
			r=mid-1
	return None



