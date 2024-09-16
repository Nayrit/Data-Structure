#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> graph[10];
int vis[10];
vector<int> res;
pair<int,int>cost[10];
int mx=INT_MAX;
void DFS(int node){
    vis[node] = 1;
    for (auto child: graph[node]){
        if (vis[child.first] == 0){
            DFS(child.first);
        }
    }
    res.push_back(node);
}
void relax(int u, int v, int w){
    if (cost[v].second > cost[u].second + w){
        cost[v].second = cost[u].second + w;
        cost[v].first = u;
    }
}
void ShortPathANDTopSort(int node,int n){
    for (int i =0; i< n; i++){
        if (vis[i]==0)
            DFS(i);
    }
    for (int i=0; i<n; i++){
        if (i==node){
            cost[i].first = 0;
            cost[i].second=0;
        }
        else{
            cost[i].first = 0;
            cost[i].second=mx;
        }
    }
    for(int j=0; j<n; j++){
        for(auto v:graph[j])
            relax(j, v.first, v.second);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    while (m--){
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
    }
    int src;
    cout << "Enter Source: ";
    cin >> src;
    ShortPathANDTopSort(src, n);
    reverse(res.begin(),res.end());
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<"->";
    cout<<endl;
    cout <<"cost: ";
    for (int i = 0; i < n; i++)
        cout <<cost[i].second << " ";
    cout<<endl;
}
