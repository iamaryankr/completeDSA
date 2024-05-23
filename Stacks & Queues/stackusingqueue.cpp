class MyStack {
public:
    queue<int> q;
    MyStack() {   
    } 
    void push(int x) {
        if(q.empty()) q.push(x);
        else{
            int size = q.size();
            q.push(x);
            while(size > 0){
                q.push(q.front());
                q.pop();
                size--;
            }
        }
    }
    int pop() {
        int temp= q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
