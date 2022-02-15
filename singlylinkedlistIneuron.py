#singly linkedlist
""""
Declare the node class
1.Value
2.Next pointer
"""
class Node:
    def __init__(self,value):
        self.value=value
        self.next=None
        

"""
Declare the linkedlist class:
1.constructor method
2.Insert method
3.Append method
4.Display/print method

"""
"""
Start declaring the values for a sample linkedlist
eg Head-->10 -->15--> 16--> 2-->4-->89-->tail
"""
class Linkedlist:
    def __init__(self):
        self.head=None
        self.tail=None
    #inserting at the beginning    
    def insertion(self,data):
        newNode=Node(data)
        if self.head is None:
            self.head=newNode
            return
        else:
            newNode.next=self.head
            self.head=newNode
    
    #insertion at the end(append)
    def insertion_end(self,data):
        """
         1.without tail pointer
         2.with tail pointer
        """
        #without tail pointer
        newNode=Node(data)
        lastNodeBlock=self.head
        while(lastNodeBlock.next):
            lastNodeBlock=lastNodeBlock.next
        lastNodeBlock.next=newNode
   
    
    #Displaying the linked list
    def displayLinkedlist(self):
        dummyblock=self.head
        while(dummyblock.next):
            print(dummyhead.data)
            dummyblock=dummyblock.next
    
    if __name__=="__main__":
        """
        1.Declare linkedlist
        2.values=[10,15,16,2,4,89]
        3.start looping in the array and add values to linkedlist one by one
        """
        linkedlist=Linkedlist()
        values=[10,15,16,2,4,89]
        for idx in range(len(values)):
            linkedlist.insertion(values[idx])
        linkedlist.display()