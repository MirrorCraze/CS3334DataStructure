#include<iostream>
#include<vector>
using namespace std;
class node{
public:
    int parent;
    int sized;
};
int findparent(vector<node> &V,int index)
{

    if(V[index].parent == index)
        return index;
    else
    {
        V[index].parent = findparent(V,V[index].parent);
        return V[index].parent;
    }
}
void merged(vector<node> &V,int a,int b)
{
    int parentA = findparent(V,a);
    int parentB = findparent(V,b);
    if(parentA == parentB)
        return;
    if(V[parentA].sized > V[parentB].sized)
    {
        V[parentB].parent = parentA;
        V[parentA].sized +=V[parentB].sized;
    }
    else
    {
        V[parentA].parent = parentB;
        V[parentB].sized +=V[parentA].sized;
    }
}
main()
{
    int t;
    cin >> t;
    int n,q;
    int a,b;
    int max_size = 0;
    vector <node> V; //Parent
    while(t--)
    {
        V.clear();
        cin >> n >> q;
        for(int i=0;i<=n;i++)
        {
            node temp;
            temp.parent = i;
            temp.sized = 1;
            V.push_back(temp);
        }
        for(int i=0;i<q;i++)
        {
            cin >> a >> b;
            merged(V,a,b);
        }
        for(int i=0;i<=n;i++)
        {
            if(V[i].sized > max_size)
                max_size = V[i].sized;
        }
        cout << max_size << endl;
    }
}
