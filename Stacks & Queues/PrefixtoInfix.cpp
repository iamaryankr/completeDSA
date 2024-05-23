#include<bits/stdc++.h>
using namespace std;
string prefixToInfixConversion(string &s){
	// Write your code here.
	stack<string> st;
	string res;
	reverse(s.begin(), s.end());
	for(int i=0; i<s.size(); i++){
		char c = s[i];
		if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
			st.push(string(1, c));
		}
		else{
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();
			st.push("(" + op1 + c + op2 + ")");
		}
	}
	return st.top();
}
