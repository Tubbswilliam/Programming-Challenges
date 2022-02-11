class Node:
	"""An obj for storing a single node for a linked list.
	Models two attriutes - data and the link to the next node."""
	data=None
	nexTNode=None

	def __init__(self,data):
		self.data=data

	def __repr__(self):
		return "Node data : %s"%self.data

class LinkedList:
	"""Singly linked list"""
	def __init__(self):
		self.head=None

	def is_Empty(self):
		return self.head==None

	def size(self):
		"""Returns length of a list"""
		current=self.head
		count=0

		while current:
			count+=1
			current=current.nexTNode
		return count 

	def add(self,data):
		'''Adds a new node containing data at the head of the list
		takes constant time'''
		newNode=Node(data)
		newNode.nexTNode=self.head
		self.head=newNode

	def __repr__(self):
		nodes=[]
		current=self.head

		while current:
			if current is self.head:
				nodes.append("[Head: %s]"%current.data)
			elif current.nexTNode is None:
				nodes.append("[Tail: %s]"%current.data)
			else:
				nodes.append("[%s]"%current.data)

			current=current.nexTNode
		return "->".join(nodes)


