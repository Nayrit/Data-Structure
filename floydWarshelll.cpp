#include <bits/stdc++.h>
using namespace std;

int d[100][100];
int pi[100][100];

void ini(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = 9999;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            pi[i][j] = (int)NULL;
        }
    }
}

void floys_warshall(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }
}

void path(int u, int v)
{
    if (u == v)
    {
        cout << u << " ";
    }
    else if (pi[u][v] == (int)NULL)
    {
        cout << "No path found from  " << u << " to " << v << endl;
    }
    else
    {
        path(u, pi[u][v]);
        cout << v << " ";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    n++;

    ini(n);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        d[u][v] = w;
        pi[u][v] = u;
    }

    floys_warshall(n);

    cout << "\nStarting index is 0 :" << endl;

    cout<<"\nCost :"<<endl;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << setw(4) << d[i][j] << "\t";
        cout << endl;
    }

    cout << endl;

    cout<<"\nPredecessor :"<<endl;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << setw(4) << pi[i][j] << "\t";
        cout << endl;
    }

    return 0;
}