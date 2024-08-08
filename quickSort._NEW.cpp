#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
#define en  "\n"

int correctPlace(vector<int> &v, int low, int high) {
    int pivot = v[low],i = low,j = high;

    while (i < j)
    {
        while (v[i] <= pivot && i < high) i++;
        while (v[j] > pivot && j >low) j--;
        if (i < j) swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}

void quickSort(vector<int> &v, int low, int high) {
    if (low < high) {
        int pIndex = correctPlace(v, low, high);
        quickSort(v, low, pIndex - 1);
        quickSort(v, pIndex + 1, high);
    }
}

void Solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    quickSort(v,0,n-1);

    for(int i=0; i<n; i++) cout<<v[i]<<" ";
    cout<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T=1,t=0;
    //cin>>T;
    while(T--){
            t++;
   // cout<<"Case "<<t<<": ";
        Solve();
    }

    return 0;
}
