#include <bits/stdc++.h>
using namespace std;
int evaluatePrefix(string postfix)
{
    stack<char> s;
    for (int i = postfix.length()-1; i >= 0; i--){
        if (postfix[i] == ' ')
            continue;
        else if (postfix[i] >= '0' && postfix[i] <= '9'){
            s.push(postfix[i] - '0');
        }
        else{
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (postfix[i])
            {
            case '^':
                s.push(pow(b, a));
                break;
            case '*':
                s.push(b,a);
                break;
            case '/':
                s.push(b / a);
                break;
            case '+':
                s.push(b + a);
                break;
            case '-':
                s.push(b - a);
                break;
            }
        }
    }
    return s.top();
}
int main()
{
    string prefix;
    getline(cin, prefix);
    int result = evaluatePrefix(prefix);
    cout << result;
    return 0;
}
