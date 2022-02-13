#Tree
class TreeNode:
	def __init__(self,data):
		self.data=data
		self.left=None
		self.right=None


#Recursive preorder traversal
def preorder(root):
	#recursive
	if not root:
		return
	print(root.data)
	preorder(root.left)
	preorder(root.right)

#iterative preorder
def preorder(root):
	stack=[root]
	while stack:
		currentNode=stack[-1]
		stack.pop()
		print(currentNode.data)
		if currentNode.right:
			stack.append(currentNode.right)
		if currentNode.left:
			stack.append(currentNode.left)