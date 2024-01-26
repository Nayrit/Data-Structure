#include <bits/stdc++.h>
using namespace std;
int priority(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}
string postToPre(string post_exp)
{
    stack<string> s;
    int length = post_exp.size();
    for (int i = 0; i < length; i++)
    {
        if (isOperator(post_exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = post_exp[i] + op2 + op1;
            s.push(temp);
        }
        else
            s.push(string(1, post_exp[i]));
    }
    string ans = "";
    while (!s.empty())
    {
        ans = ans + s.top();
        s.pop();
    }
    return ans;
}

// Driver Code
int main()
{
    string post_exp = "ABC/-AK/L-*";

    // Function call
    cout << "Prefix : " << postToPre(post_exp);
    return 0;
}

