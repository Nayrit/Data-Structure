#include<bits/stdc++.h>
using namespace std;
int A[10];
int partition(int low,int high)
{
    int pivot = A[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(A[i]<=pivot)
            i=i+1;
        while(A[j]>pivot)
            j=j-1;
        if(i<j)
            swap(A[i],A[j]);
    }
    swap(A[low],A[j]);
    return j;
}
void quicksort(int low, int high)
{
    if(low<high)
    {
        int pos =partition(low,high);
        quicksort(low,pos);
        quicksort(pos+1,high);
    }
}
int main()
{
    for(int i=0; i<10; i++)
        cin>>A[i];
    A[10]=999999;
    for(int i=0; i<10; i++)
        cout<<A[i]<<" "<<endl;
    quicksort(0,10);
    for(int i=0; i<10; i++)
        cout<<A[i]<<" ";
    return 0;
}
