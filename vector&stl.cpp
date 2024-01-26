#include<bits/stdc++.h>
using namespace std;
//cplusplus.com
/*
int main()
{
    /*vector<int> arr;
    vector<int> arr1 = {1,2,3,4,5};//vector dynamic memory allocation
    cout<<arr1.size()<<endl;//gives size
    arr1.push_back(5);//last e ekta index nibe
    cout<<arr1.size()<<endl;
    arr1.pop_back();//last index ber kore dibe
    arr1.begin();//provides the first number of the array
    arr1.end();//gives last number
    arr1.erase(3);
    reverse(arr1);
    */



/*int n;        cin>>n;
int arr[n];
for(int i=0; i<n; i++){
    cin>>arr[i];
}
int sv;         cin>>sv;
for(int i=0; i<n; i++){
    if(arr[i]==sv)
        cout<<"found"<<endl;
        return 0;
}
cout<<"not found"<<endl
return 0;
*/

/*
    vector<int>arr;
    int n;          cin>>n;
    for(int i=0; i<n; i++)
    {
        int v;      cin>>v;
        arr.push_back(v);
    }
    int sv;         cin>>sv;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]==sv)
            cout<<"found"<<endl;
            return 0;
    }
    cout<<"not found"<<endl;
    return 0;
}
*/

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


