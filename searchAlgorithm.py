#Linear search
def linear_search(lis,target):
	"""
	Returns index position of the target if target found else none.
	"""
	for i in range(0,len(list)):
		if list[i]==target:
			return i
	return None