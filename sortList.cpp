#include <iostream>

using namespace std;

// Problem: given the head of a linked list node, sort the linked list in ascending order
// follow up: can you do it in O(nlogn) time complexity and O(1) space complexity
// Solution: use quicksort

struct ListNode {
    int val;
    ListNode* next = nullptr;
};

ListNode* quicksort(ListNode* head, int size) {
    if (size <= 1) {
        return head;
    }

    ListNode* pivot = head; 
    ListNode* start = pivot;

    int sizeLeft = 0;
    ListNode* prev = pivot;
    ListNode* current = start;
    while (current != nullptr) {
        if (current->val < pivot->val) {
            if (pivot == start) {
                ListNode* tmp = current->next;
                current->next = start;
                start = current;
                prev->next = tmp;
                current = tmp;
            } else {
                ListNode* tmp = current->next;
                current->next = start;
                start = current;
                prev->next = tmp;
                current = tmp;
            }
            sizeLeft++;
            continue;
        }
        prev = current;
        current = current->next;
    }

    start = quicksort(start, sizeLeft);
    pivot->next = quicksort(pivot->next, size-sizeLeft-1);
    return start;
}

ListNode* sortList(ListNode* head) {
    ListNode* current = head;
    int size = 0;

    while (current != nullptr) {
        current = current->next;
        size++;
    }

    return quicksort(head, size);
}

