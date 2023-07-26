// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;

// #include "Solution.h"

#include <iostream>
#include <vector>

class Deque {
private:
    std::vector<int> queue;
    int size;

public:
    Deque(int n) {
        size = n;
    }

    void insertFront(int element) {
        if (queue.size() < size) {
            queue.insert(queue.begin(), element);
        }
        else {
            std::cout << "-1" << std::endl;
        }
    }

    void insertRear(int element) {
        if (queue.size() < size) {
            queue.push_back(element);
        }
        else {
            std::cout << "-1" << std::endl;
        }
    }

    void deleteFront() {
        if (!queue.empty()) {
            queue.erase(queue.begin());
        }
        else {
            std::cout << "-1" << std::endl;
        }
    }

    void deleteRear() {
        if (!queue.empty()) {
            queue.pop_back();
        }
        else {
            std::cout << "-1" << std::endl;
        }
    }

    int getFront() {
        if (!queue.empty()) {
            return queue.front();
        }
        return -1;
    }

    int getRear() {
        if (!queue.empty()) {
            return queue.back();
        }
        return -1;
    }
};


// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}
