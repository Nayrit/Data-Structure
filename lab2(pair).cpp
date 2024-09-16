#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*
    pair<int,char> p;
    p.first=1;
    p.second='a';
    cout<<"Pair contains: "<<p.first<<" "<<p.second;

    //***************vector pair****************
    vector<pair<int,char>>vp;
    for(int i=0;i<5;i++)
    {
        vp.push_back(make_pair(i,'A'+i));
    }
    cout<<endl<<"Vector pair contents: "<<endl;
    for(int i=0;i<vp.size();i++)
    {
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }

    //*******vector of pairs of pair**********
    vector<pair<int,pair<char,char>>>vpp;
    for(int i=0;i<5;i++)
    {
        vpp.push_back(make_pair(i,make_pair('A'+i,'A'+i+5)));
    }
    cout<<endl<<"Vector of pairs of pair contents: "<<endl;
    for(int i=0;i<vpp.size();i++)
    {
        cout<<vpp[i].first<<" "<<vpp[i].second.first<<" "<<vpp[i].second.second<<endl;
    }
    */
    //pair<pair<int,int>,int>p;
    vector<pair<pair<char,char>,int>> g;
    //vector<pair<int,int>>g;
    cout<<"Enter no. of edges: ";
    int E,w;
    char s,d;
    cin>>E;
    cout<<endl;
    cout<<"Enter nodes and weights of edges: "<<endl;;
    for(int i=0;i<E;i++)
    {
       cin>>s;
       cin>>d;
       cin>>w;
       //g.push_back(make_pair(s,d));
       g.push_back(make_pair(make_pair(s,d),w));
    }
    for(int i=0;i<E;i++)
    {
        cout<<endl<<g[i].first.first<< "-->"<<g[i].first.second<< " : "<<g[i].second;
    }




}
