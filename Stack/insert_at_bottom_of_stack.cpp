// Inserting at the end of stack

#include<bits/stdc++.h>
using namespace std;

stack<int> st;

class Solution {  
public:
    void insert_at_bottom(int x) {
        if (st.empty()) {
            st.push(x);
        }
        else {
            /* All items are held in Function Call Stack until we reach end of the stack. When the stack becomes
            empty, the st.size() becomes 0, the above if part is executed and the item is inserted
            at the bottom */
            int a = st.top();
            st.pop();
            insert_at_bottom(x);

            //push all the items held in Function Call Stack
            //once the item is inserted at the bottom
            st.push(a);
        }
    }
};

int main() {
    Solution ob;
    st.push(10);
    st.push(2);
    st.push(23);
    st.push(0);
    st.push(99);

    int x;
    cin>>x;

    ob.insert_at_bottom(x);
    cout<<st.top();

    return 0;
}