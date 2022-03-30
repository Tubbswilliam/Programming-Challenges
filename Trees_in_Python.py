#Trees
class Node:
    def __init__(self,val):
        self.left=None
        self.data=val
        self.right=None
        
"""
class Tree:
    #create a node
    #insert another node
    #display node
    #search an element
    #delete a node

"""
class Tree:
    def createNode(self,data):
        return Node(data)
    
    def insert(self,node,data):
        if(node is None):
            return self.createNode(data)
        if data<node.data:
            node.left=self.insert(node.left,data)
        else:
            node.right=self.insert(node.right,data)
        return node 
    def traverse_Inorder(self,root):
        if(root is not None):
            self.traverse_Inorder(root.left)
            print(root.data)
            self.traverse_Inorder(root.right)
            

############################################################################################
#Instance variable and class variable

class Student:
    school="Technical University"
    def __init__(self):
        self.name="William"
        self.age=21
        
        
s1=Student()
s2=Student()
Student.school="MIT" #Changing class variable
s2.name="Wambua" #changing instance variable
print(s1.name+" "+s1.school)
print(s2.name+" "+s2.school)