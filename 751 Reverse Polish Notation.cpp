#include<iostream>
#include<stack>
#include<string>
using namespace std;
main()
{
    string st;
    stack <int> S;
    while(getline(cin,st))
    {
        for(int i=0;i<st.length();i=i+2)
        {
            if(st[i] >='0' && st[i] <='9')
                S.push(st[i]-'0');
            else
            {
                int right= S.top();
                S.pop();
                int left = S.top();
                S.pop();
                if(st[i] == '+')
                {
                    S.push(right+left);
                }
                else if(st[i] == '-')
                {
                    S.push(left-right);
                }
                else if(st[i] == '*')
                {
                    S.push(left*right);
                }

            }
        }
        cout << S.top()<<endl;
        S.pop();
    }
}
