/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <iostream>
#include <stack>
using namespace std;

int priority(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

int main(){
    string s;
    cin>>s;
    stack<char> st;
    string ans="";

    for(char c:s){
        if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
            ans+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty()&&st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while (!st.empty()&&st.top()!= '('&&priority(st.top()) >= priority(c)) {
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans+=st.top();
        st.pop();
    }

    cout<<ans;
    return 0;
}