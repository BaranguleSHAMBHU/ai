''' Practical 3:-
Prim's Minimum Spanning Tree Algorithm '''

INF = 9999999

# Number of vertices
n = int(input("Enter number of vertices: "))

# Vertex names
vertices = []

print("Enter vertex names:")

for i in range(n):
    vertex = input()
    vertices.append(vertex)

# Adjacency matrix
graph = []

print("\nEnter adjacency matrix:")

for i in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

selected = [False] * n

# Start from first vertex
selected[0] = True

edge_count = 0
total_cost = 0

print("\nEdges in Minimum Spanning Tree:\n")

while edge_count < n - 1:

    minimum = INF
    x = 0
    y = 0

    for i in range(n):
        if selected[i]:

            for j in range(n):

                if (not selected[j]) and graph[i][j]:

                    if minimum > graph[i][j]:
                        minimum = graph[i][j]
                        x = i
                        y = j

    print(vertices[x], "-", vertices[y], ":", graph[x][y])

    total_cost += graph[x][y]
    selected[y] = True
    edge_count += 1

print("\nTotal Cost of MST:", total_cost)

'''
Input
Enter number of vertices: 5

Enter vertex names:
A
B
C
D
E

Enter adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Output
Edges in Minimum Spanning Tree:

A - B : 2
B - C : 3
B - E : 5
A - D : 6

Total Cost of MST: 16
'''
