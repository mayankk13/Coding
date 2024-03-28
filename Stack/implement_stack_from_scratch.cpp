#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int arr[1000];
    int top = -1;
public:
    void push(int x) {
        arr[++top] = x;
    }
    int pop() {
        if (top == -1) {
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top < 0;
    }

    int peek() {
        return arr[top];
    }
};

int main() {
    Solution ob;
    ob.push(10);
    ob.push(2);
    ob.push(23);
    cout<<ob.pop() <<endl;
    cout<<ob.isEmpty() <<endl;
    cout<<ob.peek() <<endl;

    return 0;
}