#include <iostream>
#include <stack>
using namespace std;

string PretoIn(string pre)
{
    stack<string> in;
    for (int i = pre.length() - 1; i >= 0; i--)
    {
        if (pre[i] <= '9' && pre[i] >= '0')
        {
            in.push(string(1, pre[i]));
        }
        else
        {
            string s1 = in.top();
            in.pop();
            string s2 = in.top();
            in.pop();
            in.push('(' + s1 + pre[i] + s2 + ')');
        }
    }
    return in.top();
}

int main()
{
    string prefix = "+*235";
    string infix = PretoIn(prefix);
    cout << "Prefix = " << prefix << endl;
    cout << "Infix = " << infix << endl;
    return 0;
}