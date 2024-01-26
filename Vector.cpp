//Name: A.R. Raffiuzzaman Nayrit
//ID: 20210104120



#include<bits/stdc++.h>
using namespace std;
int bin_search(vector<int>A, int k)
{
    int left = 0,right,mid;
    right = A.size()-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(A[mid]==k)
            return 1;
        else if (A[mid]<k)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int main()
{
    vector<int> v;
    int x;
    for(int i=0; i<5; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    int k;
    cin>>k;
    int ans = bin_search(v,k);
    if (ans==1)
        cout<<"paisi"<<endl;
    else
        cout<<"paini"<<endl;
    return 0;
}
