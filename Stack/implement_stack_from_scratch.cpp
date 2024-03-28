#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int arr[1000];
    int top = -1;
public:
    void push(int x) {
        top++;
        arr[top] = x;
    }
};