#include<bits/stdc++.h>
using namespace std;
string prefixtoInfix (string prefix){
    int l = prefix.size();
    stack <string> s;
    for (int i=l-1; i>=0;i--){
        if(prefix[i]=='+'|| prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/' || prefix[i]=='^'){
            string operator1 = s.top();
            s.pop();
            string operator2 = s.top();
            s.pop();
            string lala = "(" + operator1 + prefix[i] + operator2 + ")";
            s.push (lala);
        }
        else {
            s.push(string (1,prefix[i]));
        }
    }
    return s.top();
}
int main(){
    string prefix;
    getline(cin,prefix);
    string infix = prefixtoInfix (prefix);
    cout << infix << endl;
}
