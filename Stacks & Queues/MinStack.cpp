//method 1
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {}
    
    void push(int val) {
        int mini;
        if(st.empty()){
            mini = val; 
        }
        else
            mini = min(val, st.top().second);
        st.push({val, mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

//optimal method
//updating the value and min
class MinStack {
    stack<long long>s;
    long long  mini;
public:
    MinStack() {
        while(!s.empty())s.pop();
        mini=INT_MAX;
    }
    
    void push(int val) {
        long long value=val;
        if(s.empty()){
           s.push(value); 
           mini=value;
        }
        else{
        if(value<mini){
            s.push(2*value*1LL-mini);
            mini=value;
        }
        else s.push(value);
      }
    }
    
    void pop() {


        long long top=s.top();
        s.pop();

        if(top<mini){
            mini=2*mini-top;
        }
    }
    
    int top() {
        if(s.empty())return -1;
        long long top=s.top();

        if(top<mini)return mini;
        else return top;
    }
    
    int getMin() {
        return mini;
    }
};

