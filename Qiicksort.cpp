#include<bits/stdc++.h>
using namespace std;

void scana(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printa(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int a[], int l, int r){
    int pivot = a[r];
    int idx = l - 1;
    for(int i = l; i < r; i++){
        if(a[i] < pivot){
            idx++;
            swap(a[i], a[idx]);
        }
    }
    idx++;
    swap(a[idx], a[r]);
    return idx;
}

void quick_sort(int a[], int l, int r){
    if(l < r){
        int pivot_idx = partition(a, l, r);
        quick_sort(a, l, pivot_idx - 1);
        quick_sort(a, pivot_idx + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    scana(a, n);
    quick_sort(a, 0, n - 1);
    printa(a, n);
    return 0;
}
