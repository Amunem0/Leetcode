class MyCircularDeque {
public:
    vector<int> deque; // deque to store elements
    int front;         // index to the front element
    int rear;          // index to the rear element
    int currCount;     // current number of elements in the deque
    int n;             // maximum size of the deque

    // Constructor to initialize the deque with size k
    MyCircularDeque(int k) {
        n = k;
        deque = vector<int>(n, 0);
        front = 0;
        rear = n - 1;
        currCount = 0;
    }
    
    // Insert an element at the front of the deque
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + n) % n;
        deque[front] = value;
        currCount++;
        return true;
    }
    
    // Insert an element at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % n;
        deque[rear] = value;
        currCount++;
        return true;
    }
    
    // Delete an element from the front of the deque
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % n;
        currCount--;
        return true;
    }
    
    // Delete an element from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + n) % n;
        currCount--;
        return true;
    }
    
    // Get the front element of the deque
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }
    
    // Get the rear element of the deque
    int getRear() {
        if (isEmpty()) return -1;
        return deque[rear];
    }
    
    // Check if the deque is empty
    bool isEmpty() {
        return currCount == 0;
    }
    
    // Check if the deque is full
    bool isFull() {
        return currCount == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
