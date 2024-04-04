#include "queue.h"
#include "function.h"
#include "sort.h"
#include <vector>
using namespace std;

int main() {
    //creating a queue and adding elements to it
    Queue<int> myQueue;
    for (int i = 0; i < 10; ++i) {
        myQueue.push(i);
    }

    //printing out the elements in the queue
    cout << "Elements in the queue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << "\n";

    for (int i = 0; i < 10; ++i) {
        myQueue.push(i);
    }

    //moving front to rear and then printing out the new order of the elements in the queue
    myQueue.move_to_rear();

    cout << "Elements in the queue after moving front to rear: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << "\n";

    //creating a vector and adding elements to it
    vector<int> myVector;

    for (int i = 0; i < 10; i++) {
        myVector.push_back(i);
    }
    myVector.push_back(3);
    
    //printing out the elements in the vector
    cout << "\nElements in the vector: ";
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << " ";
    }

    int target = 3;

    //searching for the last occurrence of the target and printing out the value
    int last;
    last = linear_search(myVector, target, myVector.size()-1); 
    cout << "\nThe last occurrence of the target number 3: " << last;
    
    //creating a list and adding elements to it
    ListNode* myList = new ListNode(4);
    myList->next = new ListNode(1);
    myList->next->next = new ListNode(3);
    myList->next->next->next = new ListNode(2);
    myList->next->next->next->next = new ListNode(0);

    //printing out the original list
    cout << "\n\nOriginal List: ";
    printList(myList);

    //sorting the list and printing out the new order of elements in the list
    cout << "Sorted List: ";
    insertion_sort(myList);
    printList(myList);

}