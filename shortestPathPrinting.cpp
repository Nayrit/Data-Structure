#include <bits/stdc++.h>
using namespace std;
vector<int> Node_Vec[10];
int level[10];      //for BFS
int parent[10];     //for path
void BFS(int source)
{
    queue <int> Q;
    for(int i=0; i<10; i++)
        level[i] = -1;
    level[source] = 0;
    Q.push(source);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int j=0; j<Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if (level[v] == -1)
            {
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
}
void Path(int source)
{
    queue <int> Q;
    for(int i=0; i<8; i++)      //i<8 for nodes
    {
        level[i] = -1;
        parent[i] = i;
    }
    level[source] = 0;
    Q.push(source);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int j=0; j<Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if (level[v] == -1)
            {
                level[v] = level[u] + 1;
                Q.push(v);
                parent[v] = u;              //parent declaring
            }
        }
    }
}
void pathPrinting(int dest)                 //recursion for printing path
{
    if(parent[dest] != dest)
    {
        pathPrinting(parent[dest]);

    }
    cout<<dest<<endl;
}

int main()
{
    int node_no, edge_no;
    cout<<"Enter the number of nodes: ";
    cin>>node_no;
    cout<<"Enter the number of edges: ";
    cin>>edge_no;
    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        cin>>nodeA;
        cin>>nodeB;
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }
    for (int i = 1; i <= node_no; i++)
    {
        cout<<i<<"->";
        for (int j = 0; j < Node_Vec[i].size(); j++)
        {
            cout<<Node_Vec[i][j]<< " ";
        }
        cout<<endl;
    }
    //BFS(1);
    //cout<<"level: "<<level[6]<<endl;
    Path(1);
    pathPrinting(5);
}

