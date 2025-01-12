#include <iostream>
#include <queue>

using namespace std;

// problem: given n points in 2d space, find K points closest to 0,0

// solution 1: store K elements lineraly with a reference to the max value stored in the object. For all values less than this max, 
// we insert the value into the object. If the count of elements in object exceeds k, we remove the Max element in the array, we also
// find the next greatest element to store its value. This approach is O(n^2) time complexity

// solution 2: using a max heap to store the elements. This approach has O(nlogk) time complexity

int sumOfSq(vector<int>& arr) {
    return (arr[0]*arr[0]) + (arr[1]*arr[1]);
}

class Compare {
    public:
    bool operator()(vector<int>& a, vector<int>& b) {
        return (sumOfSq(a) > sumOfSq(b));
    } 
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq; 
    int counter = 0;
    int maxSum = 0;
    for(int i = 0; i < points.size(); i++) {
        int currentSum = sumOfSq(points[i]); 

        if (counter == 0) {
            pq.push(points[i]);
            counter++;
            maxSum = currentSum;
        } else {
            if (counter < k) {
                pq.push(points[i]);
                counter++;

                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            } else {
                if (currentSum < maxSum) {
                    pq.pop();
                    pq.push(points[i]);

                    vector<int> a;
                    a.push_back(pq.top()[0]);
                    a.push_back(pq.top()[1]);

                    maxSum = sumOfSq(a);
                }
            }
        }
    }

    vector<vector<int>> returnArray;

    while (!pq.empty()) {
        returnArray.push_back(pq.top());
        pq.pop();
    }

    return returnArray;
}


