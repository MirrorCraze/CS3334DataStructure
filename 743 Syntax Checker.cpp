#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Node{
public:
    char data;
    int order;
    Node(char da, int ord);
};
Node::Node(char da,int ord)
{
    data = da;
    order = ord;
}

main()
{
    string S;
    stack<Node> st;
    bool found = false;
    while(getline(cin,S))
    {
        found = false;
        while(!st.empty())
            st.pop();
        int Slen = S.length();
        for(int i=0;i<Slen;i++)
        {
            if(S[i]!='[' &&S[i]!='{' &&S[i]!='(' &&S[i]!='}' &&S[i]!=']' &&S[i]!=')')
                continue;
            Node temp(S[i],i+1);
            if((S[i]=='[' ||S[i]=='{' ||S[i]=='('))
            {
                st.push(temp);
                continue;
            }
            if(S[i] ==')')
            {
                if(!st.empty() && st.top().data == '(')
                    st.pop();
                else
                {
                    cout << i+1 << endl;
                    found = true;
                    break;

                }
            }
            if(S[i] ==']')
            {
                if(!st.empty() &&st.top().data == '[')
                    st.pop();
                else
                {
                    cout << i+1 << endl;
                    found = true;
                    break;
                }
            }
            if(S[i] =='}')
            {
                if(!st.empty() && st.top().data == '{')
                    st.pop();
                else
                {
                    cout << i+1 << endl;
                    found = true;
                    break;
                }
            }

        }
        if(found)
            continue;
        if(st.empty())
            cout << "Success" << endl;
        else
        {
            while(st.size() >1)
                st.pop();
            cout << st.top().order<<endl;
            st.pop();
        }
    }
}
