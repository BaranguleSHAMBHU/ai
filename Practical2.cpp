/*
Practical 2:
Implement A* Algorithm for any game search problem.
*/
/*
Sample Input:

Enter start node: A
Enter goal node: G

Sample Output:

Start Node: A
Goal Node: G

Shortest Path:
A -> B -> D -> G
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Graph: node -> list of {neighbor, cost}
unordered_map<string, vector<pair<string, int>>> graph;

// Heuristic values
unordered_map<string, int> heuristic;

// Function to implement A* Algorithm
void aStar(string start, string goal)
{
    vector<string> open_list;
    vector<string> closed_list;

    unordered_map<string, int> g;
    unordered_map<string, string> parent;

    open_list.push_back(start);
    g[start] = 0;
    parent[start] = start;

    while (!open_list.empty())
    {
        // Find node with lowest f(n) = g(n) + h(n)
        string current = open_list[0];

        for (string node : open_list)
        {
            if (g[node] + heuristic[node] < g[current] + heuristic[current])
            {
                current = node;
            }
        }

        // Goal reached
        if (current == goal)
        {
            vector<string> path;

            while (parent[current] != current)
            {
                path.push_back(current);
                current = parent[current];
            }

            path.push_back(start);
            reverse(path.begin(), path.end());

            cout << "\nShortest Path:\n";

            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i];
                if (i != path.size() - 1)
                    cout << " -> ";
            }

            cout << endl;
            return;
        }

        // Move current node from open list to closed list
        open_list.erase(remove(open_list.begin(), open_list.end(), current), open_list.end());
        closed_list.push_back(current);

        // Check neighbours
        for (auto neighbour_pair : graph[current])
        {
            string neighbour = neighbour_pair.first;
            int cost = neighbour_pair.second;

            bool inOpen = find(open_list.begin(), open_list.end(), neighbour) != open_list.end();
            bool inClosed = find(closed_list.begin(), closed_list.end(), neighbour) != closed_list.end();

            if (!inOpen && !inClosed)
            {
                open_list.push_back(neighbour);
                parent[neighbour] = current;
                g[neighbour] = g[current] + cost;
            }
            else
            {
                if (g[neighbour] > g[current] + cost)
                {
                    g[neighbour] = g[current] + cost;
                    parent[neighbour] = current;

                    if (inClosed)
                    {
                        closed_list.erase(remove(closed_list.begin(), closed_list.end(), neighbour), closed_list.end());
                        open_list.push_back(neighbour);
                    }
                }
            }
        }
    }

    cout << "Path does not exist!" << endl;
}

int main()
{
    string start, goal;

    // Creating graph
    graph["A"] = {{"B", 1}, {"C", 3}};
    graph["B"] = {{"D", 3}, {"E", 6}};
    graph["C"] = {{"F", 5}};
    graph["D"] = {{"G", 2}};
    graph["E"] = {{"G", 1}};
    graph["F"] = {{"G", 2}};
    graph["G"] = {};

    // Heuristic values
    heuristic["A"] = 7;
    heuristic["B"] = 6;
    heuristic["C"] = 4;
    heuristic["D"] = 2;
    heuristic["E"] = 1;
    heuristic["F"] = 2;
    heuristic["G"] = 0;

    cout << "Enter start node: ";
    cin >> start;

    cout << "Enter goal node: ";
    cin >> goal;

    aStar(start, goal);

    return 0;
}