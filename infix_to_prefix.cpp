#include<bits/stdc++.h>
using namespace std;
int priority( char symbol){
    if(symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}
string infixToPostfix(string infix)
{
    int len = infix.size();
    stack<char> ch;
    string postfix;
    for ( int i=0; i<len; i++){
        if(infix[i]>='a' && infix[i] <='z' || infix[i]>='A' && infix[i]<='Z' || infix[i]>= '0' && infix[i]<='9')
            postfix = postfix + infix[i];
        else if (infix[i]=='(')
            ch.push(infix[i]);
        else if (infix[i]==')'){
            while (ch.top() != '('){
                postfix+= ch.top();
                ch.pop();
            }
            ch.pop();
        }
        else{
                while(! ch.empty()&& priority(infix[i])<= priority(ch.top())){
                    postfix += ch.top();
                    ch.pop();
                }
                ch.push(infix[i]);
        }
    }
    while (!ch.empty()){
        postfix += ch.top();
        ch.pop();
    }
    return postfix;
}
string infixtoPrefix(string infix){
    int l = infix.size();
    reverse(infix.begin(),infix.end());
    for (int i=0; i<l;i++){
        if (infix[i] == '(') {
            infix[i] = ')';
        }else if (infix[i] == ')')
            infix[i] = '(';
    }
    string prefix =infixToPostfix(infix);
    reverse(prefix.begin(),prefix.end());
    return prefix;
}
int main(){
    string infix;
    getline(cin,infix);
    string prefix = infixtoPrefix (infix);
    cout <<prefix << endl;
}
