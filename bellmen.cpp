#include <bits/stdc++.h>
using namespace std;
void single_source(int d[], int pi[], int v, int s)
{
    for (int i = 0; i < v; i++)
    {
        d[i] = INT_MAX;
        pi[i] = -1;
    }
    d[s] = 0;
}
bool relax(int d[], int pi[], int u, int v, int w)
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
        return true;
    }
    return false;
}
void printPath(int pi[], int s, int des)
{
    stack<int> path;
    int temp = des;
    while (temp != -1)
    {
        path.push(temp);
        temp = pi[temp];
    }
    cout << "Path: ";
    cout << s;
    while (!path.empty())
    {
        int x = path.top();
        path.pop();
        cout << " -> " << x;
    }
    cout << endl;
}
bool bellman(vector<pair<int, int>> g[], int s, int n)
{
    int pi[n];
    int d[n];
    int ct[n] = {0};
    single_source(d, pi, n, s);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto edge : g[j])
            {
                int u = j;
                int v = edge.first;
                int w = edge.second;

                if (relax(d, pi, u, v, w))
                {
                    ct[v] += 1;
                }
            }
        }
    }
    // negative cycle check korbe
    for (int j = 0; j < n; j++)
    {
        for (auto edge : g[j])
        {
            int u = j;
            int v = edge.first;
            int w = edge.second;

            if (relax(d, pi, u, v, w))
            {
                return true; // negative cycle dekhabe
            }
        }
    }
    cout << "Number of updates done to nodes: ";
    for (int i = 0; i < n; i++)
        cout << ct[i] << " ";
    cout << endl;

    cout << "Shortest paths from source node " << s << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "To node " << i << ": ";
        printPath(pi, s, i);
        cout << "Cost: " << d[i] << endl;
    }

    return false; // negative cycle nai
}

int main()
{
    int n, e, s;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<pair<int, int>> adj[n];
    cout << "Enter the edges (node1 node2 weight):" << endl;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
    cout << "Enter the starting node: ";
    cin >> s;
    bool hasNegativeCycle = bellman(adj, s, n);

    if (hasNegativeCycle)
    {
        cout << "Negative cycle detected." << endl;
    }
    else
    {
        cout << "No negative cycle detected." << endl;
    }

    return 0;
}
