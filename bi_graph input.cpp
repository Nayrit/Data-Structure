#include <bits/stdc++.h>
using namespace std;
vector<int> Node_Vec[100];
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
    }
    for (int i = 1; i <= node_no; i++)
    {
        cout<<i<<"->";
        for (int j = 0; j < Node_Vec[i].size(); j++)
        {
            cout<<Node_Vec[i][j];
        }
        cout<<endl;
    }
}
