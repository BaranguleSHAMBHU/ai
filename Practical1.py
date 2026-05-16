''' Practical 1:-
Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected
graph and develop a recursive algorithm for searching all the vertices of a graph or tree data
structure. '''

from collections import deque

# Create graph
graph = {}

# Input number of vertices
vertices = int(input("Enter number of vertices: "))

# Initialize graph
for i in range(vertices):
    vertex = input(f"Enter vertex {i + 1}: ")
    graph[vertex] = []

# Input number of edges
edges = int(input("Enter number of edges: "))

print("\nEnter edges (vertex1 vertex2):")

# Input edges for undirected graph
for i in range(edges):
    v1, v2 = input().split()

    graph[v1].append(v2)
    graph[v2].append(v1)

# ---------------- DFS ----------------
visited_dfs = set()

def dfs(node):
    if node not in visited_dfs:
        print(node, end=" ")
        visited_dfs.add(node)

        for neighbour in graph[node]:
            dfs(neighbour)

# ---------------- BFS ----------------
def bfs(start):
    visited_bfs = set()
    queue = deque()

    visited_bfs.add(start)
    queue.append(start)

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbour in graph[node]:
            if neighbour not in visited_bfs:
                visited_bfs.add(neighbour)
                queue.append(neighbour)

# Starting node
start_node = input("\nEnter starting vertex: ")

# DFS Traversal
print("\nDepth First Search Traversal:")
dfs(start_node)

# BFS Traversal
print("\nBreadth First Search Traversal:")
bfs(start_node)



'''
Input
Enter number of vertices: 6
Enter vertex 1: A
Enter vertex 2: B
Enter vertex 3: C
Enter vertex 4: D
Enter vertex 5: E
Enter vertex 6: F

Enter number of edges: 6

Enter edges (vertex1 vertex2):
A B
A C
B D
B E
C F
E F

Enter starting vertex: A



Output
Depth First Search Traversal:
A B D E F C

Breadth First Search Traversal:
A B C D E F
'''
