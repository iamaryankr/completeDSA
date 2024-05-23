#include <iostream>
#include<cstring>
#include <stack>

using namespace std;
//for program to convert infix to postfix
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}
 
int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}
 
int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}
 
char* convert(char* infix){
    char* postfix = new char [strlen(infix) + 1];
 
    stack<char> stk;
 
    int i = 0;
    int j = 0;
 
    while (infix[i] != '\0'){
        if (isOperand(infix[i])){
            postfix[j++] = infix[i++];
        } else {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top())){
                stk.push(infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(stk.top())){
                stk.pop();
            }
            else {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }
 
    while (! stk.empty() && stk.top() != ')'){
        postfix[j++] = stk.top();
        stk.pop();
    }
 
    postfix[j] = '\0';
 
    return postfix;
 
}

//for program to evaluate postfix
int isOperand2(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}
int operation(char op,int x,int y){
    if(op=='x') return x+y;
    else if(op=='-') return x-y;
    else if(op=='*') return x*y;
    else if(op=='/') return x/y;
}
int PostfixEvaluate(char *postfix){
    stack <int> st;
    int x,y;
    int result;
    for(int i=0; postfix[i]!='\0';i++){
        if(isOperand2(postfix[i])){
            //int typecast wont work, so subtract
            st.push(postfix[i]-'0');
        }
        else{
            y=st.top();
            st.pop();
            x=st.top();
            st.pop();
            result = operation(postfix[i],x,y);
            st.push(result);
        }
    }
    result = st.top();
    st.pop();
    return result;
}
 
 
int main() {
 
    char infix[] = "((a+b)*c)-d^e^f";
    cout << convert(infix) << endl;

    char postfix[] = "35*62/+4-";
    cout << PostfixEvaluate(postfix) << endl;
 
}