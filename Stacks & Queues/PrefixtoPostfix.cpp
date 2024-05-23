#include<bits/stdc++.h>
using namespace std;
string preToPost(string s) {
    // Write Your Code Here
    stack<string> st;
    string ans;
    for(int i=s.size()-1; i>=0; i--){
        char c= s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            string temp ;
            temp.push_back(c);
            st.push(temp);
        }
        else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string temp = s1 + s2 + c;
            st.push(temp);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}