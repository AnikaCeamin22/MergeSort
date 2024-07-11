#include<bits/stdc++.h>
using namespace std;

const int N=1e6+9;
vector<int>a(N);

void Merge(int b, int mid, int e) // O(n)
{
    vector<int>temp;
    int l=b,r=mid+1;
    while(l<=mid && r<=e)
    {
        if(a[l]<=a[r])
        {
            temp.push_back(a[l]);
             l++;
        }
        else
        {
            temp.push_back(a[r]);
            r++;
        }
    }
    while(l<=mid)
    {
        temp.push_back(a[l]);
        l++;
    }
    while(r<=e)
    {
        temp.push_back(a[r]);
        r++;
    }
    for(int i=b; i<=e; i++)
        a[i]=temp[i-b];
}

void MergeSort(int b, int e) // O(logn)
{
    if(b==e) return;
    int mid=(b+e)/2;
    MergeSort(b,mid);
    MergeSort(mid+1,e);
    Merge(b,mid,e);
}

void Solve()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    MergeSort(0,n-1);
    for(int i=0; i<n; i++) cout<<a[i]<<"  ";
    cout<<endl;
}

int main()
{
    int T=1;
    cin>>T;
    while(T--)
    {
        Solve();
    }
}
