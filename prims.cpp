#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>G[10];
int N,E;
int weight[10];
int p[10];
vector<pair<int,int>>vec;
int low_cost = INT_MAX;
void initialize()
{
    for(int i=1;i<=N;i++)
    {
        weight[i] = INT_MAX;
        p[i] = NULL;
    }
}
void prim(int root)
{
    initialize();
    priority_queue<pair<int,pair<int,int>>>Q;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            Q.push(make_pair(-i,make_pair(G[i][j].first,G[i][j].second)));
        }
    }
    weight[root] = 0;
    while(!Q.empty())
    {
        int u = (-1)*Q.top().first;
        int v = Q.top().second.first;
        int w = Q.top().second.second;
        Q.pop();
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<G[i].size();j++)
            {
                if(w < weight[v])
                {
                    p[v] = u;
                    weight[v] = w;
                }
            }
        }
    }
    int cost = 0;
    cout<<"T={ ";
    for(int i=1;i<=N;i++)
    {
        if(p[i]!=0)
        {
            cout<<"(" <<p[i]<<", "<<i<<")";
        }
        cost += weight[i];
    }
    cout<<" } ";
    cout<<"cost: "<<cost<<"\n";
    if(cost<low_cost)
    {
        vec.clear();
        low_cost = cost;
        for(int i=1;i<=N;i++)
        {
            if(p[i]!=0)
            {
                vec.push_back(make_pair(p[i],i));
            }
        }
    }
}
void lowest_cost()
{
    cout<<"lowest cost: \n";
    cout<<"{ ";
    for(auto ele: vec)
    {
        cout<<"("<<ele.first<<", "<<ele.second<<")";
    }
    cout<<" } ";
    cout<<"cost: "<<low_cost<<"\n";
}
void input()
{
    cout<<"Enter number of nodes: ";
    cin>>N;
    cout<<"Enter number of edgtes: ";
    cin>>E;
    cout<<"Enter source : dest : weight: \n";
    for(int i=0;i<E;i++)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        G[src].push_back(make_pair(dest,weight));
    }
    cout<<"Graph: \n";
    for(int i=1;i<=N;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<G[i].size();j++)
        {
            cout<<"("<<G[i][j].first<<", "<<G[i][j].second<<"),";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main()
{
    input();
    for(int i=1;i<=N;i++)
    {
        prim(i);
    }
    lowest_cost();
    return 0;
}
/*
5
6
1 2 7
2 3 4
3 1 7
3 4 9
4 5 2
5 1 7
*/
