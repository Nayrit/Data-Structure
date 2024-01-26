#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void insertion_sort()
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = v[i];
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}
void enter_value(int k)
{
    int j = v.size() - 1;
    while (j >= 0 && v[j] > k)
    {
        v[j + 1] = v[j];
        --j;
    }
    v[j + 1] = k;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    insertion_sort();
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
        cout<<endl;
    int value;
    cin >> value;
    enter_value(value);
    for(int i=0; i<=n; i++)
        cout<<v[i]<<" ";
    return 0;
}
