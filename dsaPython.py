#Tree
class TreeNode:
	def __init__(self,data):
		self.data=data
		self.left=None
		self.right=None


#preorder traversal
def preorder(root):
	#recursive
	if not root:
		return
	print(root.data)
	preorder(root.left)
	preorder(root.right)