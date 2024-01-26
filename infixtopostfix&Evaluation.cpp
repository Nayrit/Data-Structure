#include <bits/stdc++.h>
using namespace std;
int priority(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
string infixToPostfix(string infix) // String!!
{
    int len = infix.size();
    stack<char> s;
    string postfix;
    for (int i = 0; i < len; i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9')
        {
            postfix = postfix + infix[i]; // rule1
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]); // rule2
        }
        else if (infix[i] == ')')
        {
            while (s.top() != '(')
            {
                postfix = postfix + s.top(); // rule4
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && priority(infix[i]) <= priority(s.top()))
            {
                postfix = postfix + s.top(); // rule3
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty())
    {
        postfix = postfix + s.top(); // rule5(unwritten)
        s.pop();
    }
    return postfix;
}
int evaluatePostfix(string postfix)
{
    stack<int> s;
    int len = postfix.length();
    for (int i = 0; i < len; i++)
    {
        if (postfix[i] == ' ')
        {
            continue;
        }
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            s.push(postfix[i] - '0');
        }
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (postfix[i])
            {
            case '^':
                s.push(pow(b, a));
                {
                    break;
                }
            case '*':
                s.push(b * a);
                {
                    break;
                }
            case '/':
                s.push(b / a);
                {
                    break;
                }
            case '+':
                s.push(b + a);
                {
                    break;
                }
            case '-':
                s.push(b - a);
                {
                    break;
                }
            }
        }
    }
    return s.top();
}
int main()
{
    // string infix, postfix;
    // cout << "Provide the infix function: ";
    // getline(cin, infix);
    // postfix = infixToPostfix(infix);
    // cout << "Postfix function: " << postfix << endl;
    string postfix;
    getline(cin, postfix);
    cout << "Postfix Evolution: " << evaluatePostfix(postfix) << endl;
    return 0;
}