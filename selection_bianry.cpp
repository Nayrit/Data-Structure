#include<bits/stdc++.h>
using namespace std;
vector<int> A;
void selectionSort()
{
    int n=A.size();
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
            if(A[j] < A[min])
                min = j;
        swap(A[i],A[min]);
    }
}
int bin_search(int k)
{
    int left = 0,right,mid;
    right = A.size()-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(A[mid]==k)
            right = mid-1;
        else if (A[mid]<k)
            left=mid+1;
        else
            right=mid-1;
    }
    return 0;
}
int main()
{
    for(int i=0; i<5; i++)
    {
        int y;
        cin>>y;
        A.push_back(y);
    }
    selectionSort();
    int k;
    cin>>k;
    int ans = bin_search(k);
    if (ans)
        cout<<ans<<endl;
    return 0;
}
