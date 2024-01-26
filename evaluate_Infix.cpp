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
string infixToPostfix(string infix){
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
int evaluatePostfix (string postfix){
    stack <int> s;
    int len = postfix.size();
    for (int i=0; i<len; i++){
        if (postfix[i]==' ')
            continue;
        else if (postfix[i]>= '0' && postfix[i]<= '9')
            s.push(postfix[i]-'0');
        else{
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch(postfix[i])
            {
            case '^' :
                s.push(pow(b,a));
                break;
            case '*' :
                s.push(b*a);
                break;
            case '/' :
                s.push(b/a);
                break;
            case '+' :
                s.push(b+a);
                break;
            case '-' :
                s.push(b-a);
                break;

            }
        }
    }
    return s.top();
}
int main(){
    string infix;
    getline(cin,infix);
    string postfix = infixToPostfix (infix);
    int result = evaluatePostfix(postfix);
    cout<< result;
}
