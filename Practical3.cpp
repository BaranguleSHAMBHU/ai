/*
Practical 3:
Prim's Minimum Spanning Tree Algorithm
*/
/*
Sample Input:

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

Sample Output:

Edges in Minimum Spanning Tree:

A - B : 2
B - C : 3
B - E : 5
A - D : 6

Total Cost of MST: 16
*/

#include <iostream>
#include <vector>
using namespace std;

#define INF 9999999

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<string> vertices(n);

    cout << "\nEnter vertex names:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> vertices[i];
    }

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "\nEnter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<bool> selected(n, false);

    // Start from first vertex
    selected[0] = true;

    int edge_count = 0;
    int total_cost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n\n";

    while (edge_count < n - 1)
    {
        int minimum = INF;
        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (minimum > graph[i][j])
                        {
                            minimum = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << vertices[x] << " - " << vertices[y] << " : " << graph[x][y] << endl;

        total_cost += graph[x][y];
        selected[y] = true;
        edge_count++;
    }

    cout << "\nTotal Cost of MST: " << total_cost << endl;

    return 0;
}