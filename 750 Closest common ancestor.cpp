#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class node{
public:
    int parent;
    int index;
    vector <int> children;
};
pair<node,int> findDepth(node M[], int head,int depth, int val)
{
    if(head == val)
        return make_pair(M[head],depth);
    else
    {
        pair <node,int> ans;
        for(int i=0;i<M[head].children.size();i++)
        {
            ans = findDepth(M,M[head].children[i],depth+1,val);
            if(ans.second !=-1)
                return ans;
        }
        ans.second = -1;
        return ans;
    }
}
main()
{
    int t;
    cin >> t;
    int n,root,child,par,a,b;
    while(t--)
    {
        cin >> root >> n;
        node M[n+5];
        for(int i=1;i<=n;i++)
        {
            M[i].index = i;
        }
        for(int i=0;i<n-1;i++)
        {
            cin >> child >> par;
            M[par].children.push_back(child);
            M[child].parent = par;
        }
        cin >> a >> b;
        pair <node,int> pA, pB;
        pA = findDepth(M,root,0,a);
        pB = findDepth(M,root,0,b);
        node A = pA.first;
        node B = pB.first;
        int Adepth = pA.second;
        int Bdepth = pB.second;
        while(Adepth < Bdepth)
        {
            Bdepth--;
            B = M[B.parent];
        }
        while(Bdepth < Adepth)
        {
            Adepth--;
            A = M[A.parent];
        }
        while(A.index != B.index)
        {
            B = M[B.parent];
            A = M[A.parent];
        }
        cout << A.index << endl;
    }
}
