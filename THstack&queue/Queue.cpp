//queue, circularqueue and DEqueue
#include<bits/stdc++.h>
using namespace std;
class Queue{
    private: 
        int size,front,rear;
        int *Q;
    public:
        Queue(int size);
        ~Queue();
        bool isFull();
        bool isEmpty();
        void enqueue(int x);
        int dequeue();
        void Display();
};
Queue:: Queue(int size){
    this->size= size;
    front = -1;
    rear = -1;
    Q= new int[size];
}
Queue:: ~Queue(){
    delete []Q;
}
bool Queue:: isEmpty(){
    if(front == rear) return true;
    return false;
}
bool Queue:: isFull(){
    if(rear== size-1) return true;
    return false;
}

void Queue:: enqueue(int x){
    if(isFull()) cout<<"queue overflow! "<<endl;
    else{
        rear++;
        Q[rear]=x;
    }
}

int Queue:: dequeue(){
    int x=-1;
    if(isEmpty())  cout<<"queue underflow! "<<endl;
    else{
        front ++;
        x=Q[front];
    }
    return x; 
}
void Queue::Display() {
    for (int i=front+1; i<=rear; i++){
        cout << Q[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 

//circular queue
class CircularQueue{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        CircularQueue(int size);
        ~CircularQueue();
        bool isFull();
        bool isEmpty();
        void enqueue(int x);
        int dequeue();
        void display();
};

CircularQueue:: CircularQueue(int size){
     this->size=size;
     front = 0;
     rear = 0;
     Q = new int [size];
}
CircularQueue:: ~CircularQueue(){
    delete []Q;
}
bool CircularQueue:: isEmpty(){
    if(front== rear){
        return true;
    }
    return false;
}
bool CircularQueue:: isFull(){
    if((rear+1)%size == front){
        return true;
    }
    return false;
}
int CircularQueue:: dequeue(){
    int x=-1;
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        front= (front+1)%size;
        x=Q[front];
    }
    return x;
}
void CircularQueue:: enqueue(int x){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        rear = (rear+1)%size;
        Q[rear]=x;
    }
}
void CircularQueue:: display(){
    int i= front +1;
    do{
        cout<<Q[i]<<flush;
        if(i<rear){
            cout<<" <- "<<flush;
        }
        i=(i+1)%size;
    }
    while(i!=(rear+1)%size);
}

//double ended queue which allows us to add elements both the side
class DEQueue{
private:
    int front;
    int rear;
    int size;
    int* Q;
 
public:
    DEQueue(int size);
    ~DEQueue();
    void display();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty();
    bool isFull();
};
 
DEQueue::DEQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}
 
DEQueue::~DEQueue() {
    delete [] Q;
}
 
bool DEQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool DEQueue::isFull() {
    if (rear == size - 1){
        return true;
    }
    return false;
}
 
void DEQueue::enqueueFront(int x) {
    if (front == -1){
        cout << "DEQueue Overflow" << endl;
    } else {
        Q[front] = x;
        front--;
    }
}
 
void DEQueue::enqueueRear(int x) {
    if (isFull()){
        cout << "DEQueue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
int DEQueue::dequeueFront() {
    int x = -1;
    if (isEmpty()){
        cout << "DEQueue Underflow" << endl;
    } else {
        x = Q[front];
        front++;
    }
    return x;
}
 
int DEQueue::dequeueRear() {
    int x = -1;
    if (rear == -1){
        cout << "DEQueue Underflow" << endl;
    } else {
        x = Q[rear];
        rear--;
    }
    return x;
}
 
void DEQueue::display() {
    for (int i=front+1; i<=rear; i++) {
        cout << Q[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main(){
    int A[] = {1, 3, 5, 7, 9}; 
    Queue q(sizeof(A)/sizeof(A[0]));
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
    // Display
    q.Display();
    // Overflow
    q.enqueue(10);
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
    // Underflow
    q.dequeue();
    
    return 0;

    
    int A[] = {1, 3, 5, 7, 9};
 
    CircularQueue cq(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]);
    }
 
    // Display
    cq.display();
    cout << endl;
 
    // Overflow
    cq.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.dequeue();
    }
 
    // Underflow
    cq.dequeue();
}
