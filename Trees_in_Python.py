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


###################################################################################
class Student:
    def __init__(self,name,rollno):
        self.name=name
        self.rollno=rollno
        self.laptop=self.Laptop()
        
    def show(self):
        print(self.name+" "+self.rollno)
        self.laptop.show()
        
    class Laptop:
        def __init__(self):
            self.brand="Hp"
            self.cpu='i5'
            self.ram=64
            
        def show(self):
            print(self.brand+" "+self.cpu,self.ram)
        
s1=Student("William","20")
s2=Student("Wambua","39")

s1.show()

#########################################################################################
#inheritance
#A is super class and B is sub-Class 
class A:
    def feature1(self):
        print("Parent class")
        
    def feature2(self):
        print("Another parent class")
        
class B(A):
        def feature3(self):
            print("child class")
        def feature4(self):
            print("Another child class")
    

        
        
a1=A()
a1.feature1()

a2=B()
a2.feature3()

#inheritrance
a2.feature1()

#############################################################################################