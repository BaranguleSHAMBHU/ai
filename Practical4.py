''' Practical 4:-
Graph Coloring Problem using Backtracking and Branch & Bound '''

# Check whether color can be assigned
def is_safe(node, graph, colors, color, n):

    for k in range(n):

        if graph[node][k] == 1 and colors[k] == color:
            return False

    return True

# Backtracking function
def solve_graph_coloring(graph, m, colors, node, n):

    # All vertices colored
    if node == n:
        return True

    # Try different colors
    for color in range(1, m + 1):

        if is_safe(node, graph, colors, color, n):

            colors[node] = color

            if solve_graph_coloring(graph, m, colors, node + 1, n):
                return True

            # Backtrack
            colors[node] = 0

    return False

# Main Program
n = int(input("Enter number of vertices: "))

print("\nEnter adjacency matrix:")

graph = []

for i in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

m = int(input("\nEnter number of colors: "))

colors = [0] * n

if solve_graph_coloring(graph, m, colors, 0, n):

    print("\nSolution Exists!")

    for i in range(n):
        print("Vertex", i, "-> Color", colors[i])

else:
    print("\nNo solution exists!")


'''
Input

Enter number of vertices: 4

Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

Enter number of colors: 3

Output
Solution Exists!

Vertex 0 -> Color 1
Vertex 1 -> Color 2
Vertex 2 -> Color 3
Vertex 3 -> Color 2
'''
