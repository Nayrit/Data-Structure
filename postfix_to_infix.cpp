#include<bits/stdc++.h>
using namespace std;
string postfixtoInfix (string postfix)
{
    int l = postfix.size();
    stack <string> s;
    for (int i=0; i<l;i++)
    {
        if((postfix[i]>= 'A' && postfix[i]<='Z') || (postfix[i]>= 'a' && postfix[i]<='z') || (postfix[i]>= '0' && postfix[i]<='9')){
            string op(1,postfix[i]);
            s.push(op);
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] +op1 + ")");
        }
    }
    return s.top();
}
int main(){
    string postfix;
    getline(cin,postfix);
    string infix =  postfixtoInfix (postfix);
    cout << infix << endl;
}
