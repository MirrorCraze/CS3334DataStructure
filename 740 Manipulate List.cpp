#include<iostream>
#include<stack>
using namespace std;
class node
{
public:
    int val;
    node* right;
    node* left;
    node(int val)
    {
        this->val = val;
        right = NULL;
        left = NULL;
    }
};
class dlist //doubly linked list
{
public:
    node* head;
    node* tail;
    int len = 0;
    dlist()
    {
        head = NULL;
        tail = NULL;
    }
    void append_back(node* n)
    {

        len++;
        if(len == 1)
        {
            head = n;
            tail = n;
            return;
        }
        n->left = tail;
        tail->right = n;
        tail = n;
    }
    void append_pos(int pos,node* n)
    {
        if(pos == 0)
        {
            n->right = head;
            head->left = n;
            head = n;
            len++;
        }
        else if(len == 0 ||pos%len == 0)
            append_back(n);
        else
        {
            len++;
            pos--;
            node* refer = head;
            while(pos >0)
            {
                refer = refer->right;
                pos--;
            }
            node* right_node = refer->right;
            node* left_node  = refer;
            right_node->left = n;
            left_node->right = n;
            n->left = left_node;
            n->right = right_node;
        }
    }
    void delete_pos(int pos)
    {

        if(len == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            len = 0;
        }
        else
        {
            len--;
            pos--;
            node* refer = head;
            while(pos >0)
            {

                refer = refer->right;
                pos--;
            }

            if(refer == head)
            {
                head = refer->right;
                delete refer;
                head ->left = NULL;

            }
            else if(refer == tail)
            {
                tail = refer->left;
                delete refer;
                tail ->right = NULL;
            }
            else
            {
                node* left_node = refer->left;
                node* right_node = refer->right;
                left_node->right = right_node;
                right_node->left = left_node;
                delete refer;
            }

        }
    }
    void reverse_portion(int left, int right)
    {
        int counter = 1;
        node* refer = head;

        while(counter < left)
        {
            refer = refer ->right;
            counter++;
        }
        node* left_node = refer;
        while(counter < right)
        {
            refer = refer->right;
            counter++;
        }
        node* right_node = refer;
        bool lefthead = false, righttail = false;
        refer = left_node;
        stack <int> S;
        node* del;
        counter = left;
        while(counter<=right)
        {
            S.push(refer->val);
            refer = refer->right;
            delete_pos(left);
            counter++;
            /*printAll();
            printBackAll();*/

        }

        /*if(!lefthead)
            left_node->left->right = right_node->right;
        if(!righttail)
            right_node->right->left = left_node->left;*/

        int val;
        for(int i=left;i<=right;i++)
        {
            val = S.top();
            S.pop();
            node* n = new node(val);
            append_pos(i-1,n);
        }
    }
    void printPos(int n)
    {
        node* refer = head;
        while(n>1)
        {
            refer = refer -> right;
            n--;
        }
        cout << refer->val << endl;
    }
    void printAll()
    {
        for(node* i = head;i!=NULL;i = i->right)
            cout << i->val << " ";
        cout << endl;
    }
    void printBackAll()
    {
        for(node* i = tail;i!=NULL;i = i->left)
            cout << i->val << " ";
        cout << endl;
    }
};

main()
{
    int n;
    int temp;
    dlist DQ;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        DQ.append_back(new node(temp));
    }
    int q;
    bool front = true;
    int com;
    int pos;
    int left, right;
    int val;
    cin >> q;
    while(q--)
    {
        cin >> com;
        if(com == 1)
        {
            cin >> pos >> val;
            node* n = new node(val);
            DQ.append_pos(pos,n);
        }
        if(com == 2)
        {
            cin >> pos;
            DQ.delete_pos(pos);
        }
        if(com == 3)
        {
            cin >> left>>right;
            //cout << left << right;
            DQ.reverse_portion(left,right);
        }
        if(com == 4)
        {
            cin >>pos;
            DQ.printPos(pos);
        }
        /*DQ.printAll();
        DQ.printBackAll();*/
    }
}
