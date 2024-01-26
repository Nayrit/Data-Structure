#include<bits/stdc++.h>
using namespace std;
vector<int>Node_Vec[100];
int level[100];
int parent [100];
void BFS (int src)
{
    queue <int> q;
    for (int i =0; i<100; i++)
    {
        level [i] = -1;
        parent [i] = i;
    }
    level [src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int u;
        u = q.front();
        q.pop();
        for (int j = 0; j < Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if (level[v] == -1)
            {
                level[v] = level[u]+1;
                q.push(v);
                parent[v]=u;
            }
        }
    }
}
//Code for find the shortest path of a NODE
/*void find_path(int des)
{
    if(parent[des] != des)
    {
        find_path(parent[des]);
    }
    cout<<des;
}*/

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
    BFS(1);
    cout<<level[5]<<endl;
    //find_path(5);
}
