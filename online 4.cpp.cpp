#include <bits/stdc++.h>
using namespace std;
vector<int> Node_Vec[10];
int level[10];      //for BFS
int parent[10];     //for path
int node_no, edge_no;
int Path(int source)
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

int main()
{

    cout<<"Enter the number of nodes and edges: ";
    cin>>node_no;
    cin>>edge_no;
    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        cin>>nodeA;
        cin>>nodeB;
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }
    for(int i=1; i<=node_no; i++)
    {
        if(i==1){
            Path(i);
            cout<<1<<" ";}
        else
        {
            if(parent[i] == i){
                Path(i);
                cout<<1<<" ";
            }
            else
                cout<<2<<" ";
        }
    }
    //pathPrinting(5);
}



