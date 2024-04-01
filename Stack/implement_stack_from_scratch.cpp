// implement stack from scratch

#include<bits/stdc++.h>
using namespace std;
#define max_size 100

class Solution {
private:
    int arr[max_size]; // array to store stack element
    int top = -1;      // top of the stack

public:
    void push(int x) {
        if (isFull()) {
            cout<<"Stack is Full" <<endl;
        }
        arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) {
            cout<<"Stack is empty" <<endl;
            return -1;
        }
        return arr[top--];  
    }

    int middleElement() {
        if (isEmpty()) {
            cout<<"Stack is empty" <<endl;
        }

        int size = top + 1;
        int mid = size / 2;

        int temp[max_size]; // array to store stack elements;
        int middleElement = -1; // initialize to a default value

        for (int i = 0; i < mid; i++) {
            int element = pop();
            temp[i] = element;
        }

        middleElement = pop();

        for (int i = mid - 1; i >= 0; i--) {
            push(temp[i]);
        }

        return middleElement;
    }

    bool isEmpty() {
        return top < 0;
    }

    int peek() {
        return arr[top];
    }

    bool isFull() {
        return top == max_size - 1;
    }
};

int main() {
    Solution ob;
    ob.push(10);
    ob.push(2);
    ob.push(23);
    ob.push(0);
    ob.push(99);
    cout<<ob.pop() <<endl;
    cout<<ob.isEmpty() <<endl;
    cout<<ob.peek() <<endl;
    cout<<ob.middleElement() <<endl;

    return 0;
}