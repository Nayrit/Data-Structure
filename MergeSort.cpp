#include <iostream>
using namespace std;
int arr[8] = {6,5,7,9,34,54,65,23};
void Merge(int low, int mid, int hi) {
    int m = mid - low + 1;
    int n = hi -mid;
    int L[m+1];
    int R[n+1];
    for(int i = 0 ; i < m ; i++)
        L[i] = arr[low + i];
    for(int j = 0 ; j < n ; j++)
        R[j] = arr[mid + j + 1];
    int i = 0 , j = 0 , k = low;
    while(i<m and j<n) {
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
            k++;
        }
        else {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while(i < m) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int low, int hi) {
    if(low < hi) {
        int mid = (low + hi) /2;
        MergeSort(low, mid);
        MergeSort(mid + 1 , hi);
        Merge(low, mid, hi);
    }
}
int main() {
    cout<<"Before sorting: \n";
    for(int i = 0 ; i < 8 ; i++)
        cout<<arr[i]<<'\t';
    cout<<'\n';
    MergeSort(0,7);
    cout<<"After sorting: \n";
    for(int i = 0 ; i < 8 ; i++)
        cout<<arr[i]<<'\t';
    cout<<'\n';
}
