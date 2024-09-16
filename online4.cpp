/*
5 6
0 1 1
1 2 2
2 4 5
4 3 -4
3 2 -3
3 0 -1
0
*/

#include <bits/stdc++.h>
using namespace std;

void initialize_single_source(int d[], int pi[], int v, int s)
{
    for (int i = 1; i <= v; i++)
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

void path(int pi[], int s, int des)
{
    int cost = 0;
    stack<int> path;
    int temp = des;
    while (pi[temp] != -1)
    {
        path.push(temp);
        temp = pi[temp];
    }

    cout << s;
    while (!path.empty())
    {
        int x = path.top();
        path.pop();
        cout << "->" << x;
    }
}
void bellman(vector<pair<int, int>> g[], int s, int n)
{
    int pi[n + 1];
    int d[n + 1];
    int visit[n + 1] = {0};
    int ct[n + 1] = {0};
    int u, v, w;

    initialize_single_source(d, pi, n, s);

    for (int i = 1; i <= n; i++)
    {
        bool relaxed = false; // Track if any relaxation occurs in the current iteration

        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < g[j].size(); k++)
            {
                u = j;
                v = g[j][k].first;
                w = g[j][k].second;

                if (relax(d, pi, u, v, w))
                {
                    relaxed = true;
                    if (i == n) // Node relaxed in the nth iteration
                        visit[v] = 1;
                    ct[v] += 1;
                }
            }
        }

        // If no relaxation occurred in the current iteration, terminate the loop
        if (!relaxed)
            break;
    }

    bool hasNegativeCycle = false;
    int negativeCycleNode = -1;
    int negativeCycleCost = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visit[i])
        {
            hasNegativeCycle = true;
            negativeCycleNode = i;
            negativeCycleCost = d[i];
            break;
        }
    }

    if (hasNegativeCycle)
    {
        cout << "Negative cycle detected!" << endl;
        cout << "Nodes in the negative cycle: ";

        // Perform backtracking to print the negative cycle
        vector<int> cyclePath;
        int temp = negativeCycleNode;
        while (find(cyclePath.begin(), cyclePath.end(), temp) == cyclePath.end())
        {
            cyclePath.push_back(temp);
            temp = pi[temp];
        }
        cyclePath.push_back(temp);

        reverse(cyclePath.begin(), cyclePath.end());

        for (int i = 0; i < cyclePath.size(); i++)
        {
            cout << cyclePath[i];
            if (i != cyclePath.size() - 1)
                cout << " -> ";
        }
        cout << endl;

        cout << "Total weight (cost) of the negative cycle: " << negativeCycleCost << endl;
    }
    else
    {
        cout << "No negative cycle detected." << endl;
    }

    cout << endl;
    cout << "Number of updates done to nodes: ";

    for (int i = 1; i <= n; i++)
    {
        cout << ct[i] << "\t";
    }

    cout << endl;
    cout << "Path and cost for each node:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ".\t";
        path(pi, s, i);
        cout << "\tCost= " << d[i] << endl;
    }
}

int main()
{
    int n, e, s;

    cout << "How many nodes are there: ";
    cin >> n;
    cout << "How many edges are there: ";
    cin >> e;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(make_pair(b, c));
    }

    cout << "What's the source node: ";
    cin >> s;

    bellman(adj, s, n);

    return 0;
}

