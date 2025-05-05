#include<bits/stdc++.h>
using namespace std;

void printarr(int a[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int a[], int n)
{
    for(int i = 2; i <= n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while(j > 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main()
{
    int a[] = {0, 9, 2, 3, 5, 4};
    int n = (sizeof(a) / sizeof(a[0])) - 1;
    printarr(a, n);
    insertion_sort(a, n);
    printarr(a, n);
    return 0;
}
