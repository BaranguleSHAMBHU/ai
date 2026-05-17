/*
Practical 1:
Implement Depth First Search algorithm and Breadth First Search algorithm.
Use an undirected graph and develop a recursive algorithm for searching
all the vertices of a graph or tree data structure.
*/
/*
Sample Input:

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

Sample Output:

Depth First Search Traversal:
A B D E F C

Breadth First Search Traversal:
A B C D E F
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Graph declaration
unordered_map<string, vector<string>> graph;

// Set to store visited nodes for DFS
set<string> visited_dfs;

// ---------------- DFS Function ----------------
void dfs(string node)
{
    if (visited_dfs.find(node) == visited_dfs.end())
    {
        cout << node << " ";
        visited_dfs.insert(node);

        for (string neighbour : graph[node])
        {
            dfs(neighbour);
        }
    }
}

// ---------------- BFS Function ----------------
void bfs(string start)
{
    set<string> visited_bfs;
    queue<string> q;

    visited_bfs.insert(start);
    q.push(start);

    while (!q.empty())
    {
        string node = q.front();
        q.pop();

        cout << node << " ";

        for (string neighbour : graph[node])
        {
            if (visited_bfs.find(neighbour) == visited_bfs.end())
            {
                visited_bfs.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
}

// ---------------- Main Function ----------------
int main()
{
    int vertices, edges;
    string vertex, v1, v2, start_node;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Input vertices
    for (int i = 0; i < vertices; i++)
    {
        cout << "Enter vertex " << i + 1 << ": ";
        cin >> vertex;
        graph[vertex] = {};
    }

    cout << "\nEnter number of edges: ";
    cin >> edges;

    cout << "\nEnter edges (vertex1 vertex2):\n";

    // Input edges for undirected graph
    for (int i = 0; i < edges; i++)
    {
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << "\nEnter starting vertex: ";
    cin >> start_node;

    cout << "\nDepth First Search Traversal:\n";
    dfs(start_node);

    cout << "\n\nBreadth First Search Traversal:\n";
    bfs(start_node);

    return 0;
}