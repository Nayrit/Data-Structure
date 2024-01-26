#include<bits/stdc++.h>
using namespace std;
string PostfixtoPrefix(string postfix)
{
    stack<string> s;
    for(int i=0;i<postfix.length();i++){
        if((postfix[i]>= 'A' && postfix[i]<='Z') || (postfix[i]>= 'a' && postfix[i]<='z') || (postfix[i]>= '0' && postfix[i]<='9')){
            string op(1, postfix[i]);
            s.push(op);
        }
        else{
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string exp= postfix[i]+op2+op1;
            s.push(exp);
        }
    }
    return s.top();
}
int main(){
    string s,str;
    getline(cin,s);
    str = PostfixtoPrefix(s);
    cout<<str;

}
