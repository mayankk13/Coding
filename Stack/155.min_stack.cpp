/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    // vector of pairs and their correcponding min value seen so far
    vector<pair<int, int>> st;
    // constructor for MinStack
    MinStack() {
        
    }
    // insert new element
    void push(int val) {
        if (st.empty()) {
            // if stack is empty, create a pair with val as both element and min
            pair<int, int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else {
            // if stack is not empty, create a pair with val as element
            // and min of cal and curr min value in stack as second element
            pair<int, int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }              
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */