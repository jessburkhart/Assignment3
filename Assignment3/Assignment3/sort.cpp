#include "sort.h"

//insertion sort using a linked list

void insertion_sort(ListNode*& head) {
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode* sorted = nullptr;

    while (head != nullptr) {
        ListNode* current = head;
        head = head->next;

        if (sorted == nullptr || current->val < sorted->val) {
            current->next = sorted;
            sorted = current;
        }
        else {
            ListNode* temp = sorted;
            while (temp->next != nullptr && temp->next->val < current->val) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
}

//prints out list to user

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}