'''Practical 2:-
Implement A star Algorithm for any game search problem. '''

graph = {
    'A': [('B', 1), ('C', 3)],
    'B': [('D', 3), ('E', 6)],
    'C': [('F', 5)],
    'D': [('G', 2)],
    'E': [('G', 1)],
    'F': [('G', 2)],
    'G': []
}

# Heuristic values
heuristic = {
    'A': 7,
    'B': 6,
    'C': 4,
    'D': 2,
    'E': 1,
    'F': 2,
    'G': 0
}

def a_star(start, goal):

    open_list = [start]
    closed_list = []

    g = {}
    g[start] = 0

    parent = {}
    parent[start] = start

    while open_list:

        # Find node with lowest f(n)
        current = open_list[0]

        for node in open_list:
            if g[node] + heuristic[node] < g[current] + heuristic[current]:
                current = node

        # Goal reached
        if current == goal:
            path = []

            while parent[current] != current:
                path.append(current)
                current = parent[current]

            path.append(start)
            path.reverse()

            print("\nShortest Path:")
            print(" -> ".join(path))

            return

        # Move current node from open to closed
        open_list.remove(current)
        closed_list.append(current)

        # Check neighbors
        for neighbor, cost in graph[current]:

            if neighbor not in open_list and neighbor not in closed_list:
                open_list.append(neighbor)
                parent[neighbor] = current
                g[neighbor] = g[current] + cost

            else:
                if g[neighbor] > g[current] + cost:
                    g[neighbor] = g[current] + cost
                    parent[neighbor] = current

                    if neighbor in closed_list:
                        closed_list.remove(neighbor)
                        open_list.append(neighbor)

    print("Path does not exist!")

# User Input
start = input("Enter start node: ")
goal = input("Enter goal node: ")

a_star(start, goal)


'''
Input
Enter start node: A
Enter goal node: G

Output
Shortest Path:
A -> B -> D -> G

'''
