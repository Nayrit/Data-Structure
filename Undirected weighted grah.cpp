#include <bits/stdc++.h>
using namespace std;
vector<int> Node_Vec[100];
vector<int> Node_weight[100];
int main()
{
    int node_no, edge_no;
    cout<<"Enter the number of nodes: ";
    cin>>node_no;
    cout<<"Enter the number of edges: ";
    cin>>edge_no;

    for (int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB,weight;
        cin>>nodeA;
        cin>>nodeB;
        cin>>weight;
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
        Node_weight[nodeA].push_back(weight);
        Node_weight[nodeB].push_back(weight);
    }
    cout<<"Undirected graph output:"<<endl;
    for (int i = 1; i <= node_no; i++)
    {
        cout<<i<<"->";
        for (int j = 0; j < Node_Vec[i].size(); j++)
        {
            cout<<Node_Vec[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<"Weighted Adjacency List:"<<endl;
    for (int i = 1; i <= node_no; i++)
    {
        cout<<i<<"->";
        for (int j = 0; j < Node_weight[i].size(); j++)
        {
            cout<<Node_weight[i][j]<< " ";
        }
        cout<<endl;
    }
}
