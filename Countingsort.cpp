#include <iostream>
using namespace std;

void countingsort(int arr[], int n)
{
    // Find the maximum element
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // Initialize count array
    int* count = new int[max_val + 1];
    for (int i = 0; i <= max_val; i++)
        count[i] = 0;

    // Count frequencies
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Accumulate the counts
    for (int i = 1; i <= max_val; i++)
        count[i] += count[i - 1];

    // Build the output array
    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted output back to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Clean up
    delete[] count;
    delete[] output;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countingsort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
