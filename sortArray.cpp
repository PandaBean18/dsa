#include <iostream>
#include <vector>

using namespace std;

// problem: sort an array in nlogn time
// solution: use in place merge sort

void merge(vector<int>& arr, int s1, int e1, int s2, int e2) {
    int i = s1;
    int j = s2;
    vector<int> merged;

    while (i <= e1 && j <= e2) {
        if (arr[i] > arr[j]) {
            merged.push_back(arr[j]);
            j++;
        } else {
            merged.push_back(arr[i]);
            i++;
        }
    }

    if (i <= e1) {
        while (i <= e1) {
            merged.push_back(arr[i]);
            i++;
        }
    } else if (j <= e2) {
        while (j <= e2) {
            merged.push_back(arr[j]);
            j++;
        }
    }

    for (int k = s1; k <= e2; k++) {
        arr[k] = merged[k-s1];
    }

    return;
}

void sort(vector<int>& arr, int s, int e) {
    if (s == e) {
        return;
    } else if (e == s+1) {
        if (arr[s] > arr[e]) {
            swap(arr[s], arr[e]);
        }
        return;
    } else if (s > e) {
        return;
    }
    int mid = (s+e)/2;
    sort(arr, s, mid);
    sort(arr, mid+1, e);
    merge(arr, s, mid, mid+1, e);

    return;
}
