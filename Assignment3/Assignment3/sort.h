#pragma once
#include <iostream>
using namespace std;

//ListNode and insertion sort and print list functions

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void insertion_sort(ListNode*& head);
void printList(ListNode* head);
