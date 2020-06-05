#include<iostream>
#include<stack>
using namespace std;
class node{
public:
    int val;
    node* left;
    node* right;
    node()
    {
        val = -1;
        left = NULL;
        right = NULL;
    }
    void construct_tree(int PR[],int PO[], int leftPR, int leftPO, int len)
    {
        this->val = PR[leftPR];
        if(len == 1)
            return;
        int sep = -1;
        for(int i=leftPO;i<leftPO+len;i++)
        {
            if(this->val == PO[i])
            {
                sep = i;
                //cout << "Sep" << sep << endl;
                break;
            }
        }
        int leftlen = sep-leftPO;
        int rightlen = leftPO +len - sep-1;
        if(sep == -1)
        {
            //cout << "Error" << "LeftPO" << leftPO << "Len" << len << endl;
            return;
        }
        if(leftlen != 0)
        {
            this->left = new node();
            //cout << "left under" << this->val << endl;
            this->left->construct_tree(PR,PO,leftPR+1, leftPO,leftlen);
        }
        if(rightlen != 0)
        {
            this->right = new node();
            //cout << "right under" << this->val << endl;
            this->right->construct_tree(PR,PO,leftPR+leftlen+1,sep+1,rightlen);
        }
    }
};
void postorder(node n,bool first)
    {
        if(n.left == NULL && n.right == NULL)
        {
            cout << n.val;
            if(!first)
                cout << " ";
        }
        else
        {
            if(n.left !=NULL)
                postorder((*n.left),false);
            if(n.right !=NULL)
                postorder((*n.right),false);
            cout << n.val;
            if(!first)
                cout << " ";
        }
    }
main()
{
    int t;
    int n;
    cin >>t;
    while(t--)
    {
        cin >> n;
        int PR[n+5]; //Preorder
        int PO[n+5]; //Postorder
        for(int i=0;i<n;i++)
            cin >> PR[i];
        for(int i=0;i<n;i++)
            cin >> PO[i];
        node root;
        root.construct_tree(PR,PO,0,0,n);
        postorder(root,true);
        cout << endl;
    }
}
