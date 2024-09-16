#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    vector<int>v1;
    vector<char>v2;
    for(int i=0;i<5; i++){
        v1.push_back(i);
        v2.push_back('A'+i);
    }
    for(int i=0; i<v1.size();i++){
        cout<<v1[i]<< " ";
    }
    cout<<endl;
    v1.insert(v1.begin()+3,9);
    sort(v1.begin(),v1.end());
    for(int i=0; i<v1.size();i++){
        cout<<v2[i]<< " ";
    }
    cout<<endl;
    vector<char>::iterator ptr;
    cout<<"Using Iterator: ";
    for(ptr=v2.begin(); ptr<v2.end(); ptr++){
        cout<<*ptr<< " ";
    }
    cout<<endl;
    */



    vector<int>graph[100];
    vector<int>weights[100];
    int N,adjN,name,t,w;
    cout<<"Enter total number of Nodes: ";
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cout<<endl<<"Enter Node Name/No.: ";
        cin>>name;
        cout<<endl<<"Enter total number of adjacent Nodes of Node "<<name<<" :";
        cin>>adjN;
        cout<<endl<<"Enter Adjacent nodes and weights of node "<<name<<" :";
        for(int j=0;j<adjN;j++)
        {
            cin>>t;
            cin>>w;
            graph[name].push_back(t);
            weights[name].push_back(w);
        }

    }
    cout<<endl<<"Adjacency List:";
    for(int i=0;i<100;i++)
    {
        if(graph[i].size()>0)
        {
            cout<<endl<<i<<"--> ";
            for(int j=0;j<graph[i].size();j++)
            {
                cout<<graph[i][j]<<" ";
            }
        }

    }
    cout<<endl<<"Weight List:";
    for(int i=0;i<100;i++)
    {
        if(weights[i].size()>0)
        {
            cout<<endl<<i<<"--> ";
            for(int j=0;j<weights[i].size();j++)
            {
                cout<<weights[i][j]<<" ";
            }
        }

    }
}
