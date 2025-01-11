#include <iostream>
#include <stack>

using namespace std;

// problem: given an array of size n where arr[i] represents the speed of the car, if, two cars moving in opposite directions collide,
// the car with higher abs value will continue with its speed and the other car will get destroyed. find the speed of the last remaining
// car.

// Solution: we can use a stack to store the numbers, then, for each int, if the sign of top and of current are same, we push onto the
// stack. If the signs are opposite, we compare absolute values. if the abs of current is less than abs, we skip and move onto the next
// if it is more than abs, we keep on popping till we find a value whos abs is either >= current or stack is empty

// example: 10 2 -5
// stk = 10 

int** findRemainingCars(int* speeds, int n) {
    stack<int> stk;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if (stk.empty()) {
            stk.push(speeds[i]);
            count++;
        } else if ((stk.top() * speeds[i]) <  0) {
            if (stk.top() < 0 && speeds[i] > 0) {
                stk.push(speeds[i]);
                count++;
            } else if (abs(stk.top()) < abs(speeds[i])) {
                while (!stk.empty() && (abs(stk.top()) < abs(speeds[i])) && (stk.top() * speeds[i] < 0)) {
                    stk.pop();
                    count--;
                }

                if (stk.empty()) {
                    stk.push(speeds[i]);
                    count++;
                } else if (abs(stk.top()) == abs(speeds[i])) {
                    if (stk.top() * speeds[i] < 0) {
                        stk.pop();
                        count--;
                    } else {
                        stk.push(speeds[i]);
                        count++;
                    } 
                } else if (stk.top() * speeds[i] > 0) {
                    stk.push(speeds[i]);
                    count++;
                }
            }  else if (abs(stk.top()) == abs(speeds[i])) {
                stk.pop();
                count--;
            } 
        } else {
            stk.push(speeds[i]);
            count++;
        }
    }

    int* returnArray = (int*)malloc(count*sizeof(int));

    for(int i = 0; i < count; i++) {
        returnArray[count-i-1] = stk.top();
        stk.pop();
    }
    
    int** returnValues = (int**)malloc(2*sizeof(int*));
    returnValues[0] = &count;
    returnValues[1] = returnArray;

    return returnValues;
}

int main(void) {
    int arr[] = {10, 2, -5};

    int** remaining = findRemainingCars(arr, 3);
    int n = *(remaining[0]);
    
    for(int i = 0; i<n; i++) {
        cout << remaining[1][i] << endl;
    }

    return 0;
}