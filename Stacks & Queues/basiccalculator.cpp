//basic calculator 
class Solution {
public:
    int calculate(string s) {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int,int>> st;

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                long long int num = 0;
                while(i<s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if(s[i] == '('){
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                sum = st.top().first + (st.top().second * sum);
                st.pop();

            }
            else if(s[i] == '-'){
                sign = -1 * sign;
            }
        }
        return sum;
    }
};

//basic calculator - II
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char sign = '+';
        int curr = 0;
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                curr = curr*10 + (s[i]-'0');
            }
            if(!isdigit(s[i]) && s[i]!=' ' || i==s.size()-1){
                if(sign == '+') stk.push(curr);
                else if(sign == '-') stk.push(-1*curr);
                else{
                    int num;
                    if(sign == '*') num = stk.top()*curr;
                    else num = stk.top()/curr;
                    stk.pop();
                    stk.push(num);
                }  
                sign = s[i];
                curr = 0; 
            }
           
        }
        int sum = 0;
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};