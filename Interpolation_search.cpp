#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }

        
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);
        if (arr[pos] == key) return pos;

  
        if (arr[pos] < key)
            low = pos + 1;
        else 
            high = pos - 1;
    }
    return -1; 
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;

    int index = interpolationSearch(arr, n, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

/* output :
Element found at index: 3
*/





