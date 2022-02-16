#Min heap

#Sift up operation/function
def siftUp(currentIx,heap):
	#compute the parent idx
	parentIdx=(currentIdx-1)//2
	while(currentIdx>0 and heap[parentIdx]>heap[currentIdx]):
		swap(currentIdx,parentIdx,heap)
		currentIdx=parentIdx
		parentIdx=(currentIdx-1)//2

def swap(idx1,idx2,heap):
	heap[idx1],heap[idx2]=heap[idx2],heap[idx1]

#insert function 
def insertNewValue(heap,value):
	heap.append(value)#Appending a new value at the end of the heap
	siftUp(len(heap)-1,heap) #calling the sift up function

