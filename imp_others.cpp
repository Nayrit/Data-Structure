//Standard template library search it



#include<bits/stdc++.h>
using namespace std;
void fun()
{
    cout<<"Amar global world"<<endl;
}
namespace ami
{
    void fun()
    {
        cout<<"amar world"<<endl;
    }
}
namespace parallel_ami
{
    void fun()
    {
        cout<<"amar parallel world"<<endl;
    }
}
int main()
{
    //glassdoor website -> enosis questions
    //template search in google
    /*
    priority_queue<int> Q;      //Heap_sort
    for(int i = 0; i <5; i++)
    {
        int y;
        cin >> y;
        Q.push(y*-1);
    }
    while(!Q.empty())
    {
        cout<<Q.top() * -1<<endl;
        Q.pop();
    }


    //SET
    set <int> Q;      //Heap_sort
    for(int i = 0; i <8; i++)
    {
        int y;
        cin >> y;
        Q.insert(y);
    }
    cout<<Q.size()<<endl;
    cout<<8-Q.size()<<endl;
    for(auto z : Q)
        cout<<z<<" ";

    string s = "cza";
    sort(s.begin(), s.end());
    cout<<s<<endl;
    do
    {
        cout<<s<<endl;
    }
    while(next_permutation(s.begin(),s.end()));
    */
    fun();
    ami :: fun();
    parallel_ami :: fun();





}

