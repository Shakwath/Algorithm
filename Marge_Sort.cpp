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

void merge(int a[], int l, int m, int r){
    int ls = m - l + 1;
    int rs = r - m;

    int la[ls], ra[rs];

    for(int i = 0, j = l; i < ls; i++, j++){
        la[i] = a[j];
    }
    for(int i = 0, j = m + 1; i < rs; i++, j++){
        ra[i] = a[j];
    }

    // printa(la, ls);
    // printa(ra, rs);

    int i = 0, j = 0, k = l;
    while(i < ls && j < rs){
        if(la[i] <= ra[j]){
            a[k] = la[i];
            k++, i++;
        }
        else{
            a[k] = ra[j];
            k++, j++;
        }
    }

    while(i < ls){
        a[k] = la[i];
        k++, i++;
    }
    while(j < rs){
        a[k] = ra[j];
        k++, j++;
    }
}

void merge_sort(int a[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    scana(a, n);
    merge_sort(a, 0, n - 1);
    printa(a, n);
    return 0;
}
