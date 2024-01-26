#include<bits/stdc++.h>
using namespace std;
string PrefixToPostfix(string prefix){
    stack<string> s;
    for(int i = prefix.length()-1;i>=0;i--){
        if((prefix[i]>= 'A' && prefix[i]<='Z')  (prefix[i]>= 'a' && prefix[i]<='z')  (prefix[i]>= '0' && prefix[i]<='9')){
            string op(1, prefix[i]);
            s.push(op);
        }
        else{
            string op1=s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string exp = op1+op2+prefix[i];
            s.push(exp);
        }
    }
    return s.top();
}
int main(){
    string s, str;
    getline(cin,s);
    str = PrefixToPostfix(s);
    cout<<str;
}
