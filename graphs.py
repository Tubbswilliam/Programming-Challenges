#Adjacency matrix
adjMatrix=[[float('-inf')for i in range(5)] for j in range(5)]

for i in range(10):#Number of inputs in u,v,w =10
	u,v,w=map(int,input().split())
	adjMatrix[u][v]=w #directed graph
	adjMatrix[v][u]=w #undirected graph

#Ajacency list
#Adjacency list in terms of a dictionary
adjlist={}
for i in range(10):
	u,v,w=map(int,input().split())

	#In case of directed graph
	if u in adjlist:
		adjlist[u].append((v,w))
	else:
		adjlist[u]=[]
		adjlist[u].append((v,w))

	#In case of undirected graph
	if v in adjlist:
		adjlist[v].append((u,w))
	else:
		adjlist[v]=[]
		adjlist[v].append((v,w))



