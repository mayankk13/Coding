// implement queue from scratch 

#include<bits/stdc++.h>
using namespace std;
#define maxSize 1000

class Solution {
private:
	int arr[maxSize];
	int front = 0;
	int rear = 0;
public:
	void queueEnqueue(int x) {
		if (rear == maxSize) {
			cout<<"queue is full" <<endl;
		}
		arr[rear++] = x;
	}

	int queueDequeue() {
		if (front == rear) {
			cout<<"queue is empty" <<endl;
			return INT_MIN;
		}
		if (rear > 0) {
			int temp = arr[front];
			front++;
		}
	}
};

int main() {
	Solution queue;
    queue.queueEnqueue(10);
    queue.queueEnqueue(20);
    queue.queueEnqueue(30);
    cout << "Dequeued element: " << queue.queueDequeue() << endl;
    cout << "Dequeued element: " << queue.queueDequeue() << endl;
    cout << "Dequeued element: " << queue.queueDequeue() << endl;
    cout << "Dequeued element: " << queue.queueDequeue() << endl; // Trying to dequeue from an empty queue
    return 0;
}

