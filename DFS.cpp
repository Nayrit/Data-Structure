#include<bits/stdc++.h>
using namespace std;
vector<int>Node_Vec[100];
int color[100];
int parent [100];
void DFS (int src)
{
    stack <int> S;
    int white =0, gray =1, black=2;
    for (int i =0; i<100; i++)
    {
        color [i] = white;
        parent [i] = i;
    }
    color [src] = gray;
    S.push(src);
    while (!S.empty())
    {
        int u;
        u = S.top();
        S.pop();
        for (int j = 0; j < Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if (color[v] == white)
            {
                color[v] = gray;
                S.push(v);
                parent[v]=u;
            }
            color[src] = black;
            //cout<<
        }
    }
}
int main()
{
    int node_no, edge_no;
    printf("Enter the number of nodes: ");
    scanf("%d", &node_no);
    printf("Enter the number of edges: ");
    scanf("%d", &edge_no);
    for(int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        scanf("%d %d", &nodeA, &nodeB);
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }
//Print Node Adjacency List by traversing the list
    for(int i = 1; i <= node_no; i++)
    {
        printf("%d -> ", i);
        for(int j = 0; j < Node_Vec[i].size(); j++)
        {
            printf("%d ", Node_Vec[i][j]);
        }
        printf("\n");
    }
    DFS(1);
    cout<<color[5]<<endl;
    //find_path(5);
}
