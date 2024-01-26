#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*
    vector<int> v;
    for(int i=0; i<5; i++)
    {
        int y;
        //cin>>y;
        v.push_back(y * -1);    //for reverse in O(1)
    }
    sort(v.begin(), v.end());
    for( auto z:v)
        cout<<z * -1<< " ";
        cout<<endl;
    //reverse(v.begin(), v.end());
   // for(auto z:v)
    //    cout<<z<< " ";




    int arr[10];
    for(int i =0; i<10; i++)
        cin>>arr[i];
    sort(arr, arr+5);
    for(int i =0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    */
    vector<int> v;
    for(int i=0; i<9; i++)
    {
        int y;
        cin>>y;
        v.push_back(y);    //for reverse in O(1)
    }
    sort(v.begin(), v.end());
    int ans = binary_search(v.begin(), v.end(), 100);
    if(ans == 1)
        cout<< "Found" << endl;
    else
        cout<<"Not found"<<endl;
    for( auto z:v)
        cout<<z << " ";
        cout<<endl;
    //upper bound, lower bound search on google
    //sort algorithm search on wekepedia
}
