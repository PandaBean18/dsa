#include <iostream>

using namespace std;

// Problem: given a sorted array of n integers, where some integers are repeating, find the first and last occurance of target element t

// Solution: Use binary search to first find the integer. This index could be at the start, end or middle of the repetitions, so
// we move i to the left initially to find the first occurance and then to the right to find the last;

int binarySearch(int* arr, int n, int t) {
    int s = 0, e = n-1;
    int i = (s+e)/2;

    while (s != e) {
        if (arr[i] == t) {
            return i;
        } else if (arr[i] > t) {
            e = i-1;
            if (e<0) {
                break;
            }
        } else {
            s = i+1;
            if (s >= n) {
                break;
            }
        }
        i = (s+e)/2;
    }

    if (arr[s] == t) {
        return s;
    }
    return -1;
}

int* findFirstAndLastOccurance(int* arr, int n, int t) {
    int* indicies = (int*)malloc(2*sizeof(int));
    indicies[0] = -1;
    indicies[1] = -1;
    
    int i = binarySearch(arr, n, t);

    if (i == -1) {
        return indicies;
    }

    indicies[0] = indicies[1] = i;

    while (arr[indicies[0]-1] == t && indicies[0] > 0) {
        indicies[0] = indicies[0]-1;
    }

    while (arr[indicies[1] + 1] == t && indicies[1] < (n-1)) {
        indicies[1] = indicies[1]+1;
    }

    return indicies;

}

int main() {
    int arr[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int* i = findFirstAndLastOccurance(arr, 10, 7);
    cout << i[0] << " " << i[1] << endl; 

    return 0;
}