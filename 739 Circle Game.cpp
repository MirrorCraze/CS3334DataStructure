#include<iostream>
#include<stdio.h>

class Node{
public:
    int data;
    Node* next;
    Node(int dataa){
        data = dataa;
    }
};
class CLL{ //Circular Linked list
public:
    Node* refer=NULL;
    Node* head = NULL;
    int length = 0;
    CLL()
    {
        refer = NULL;
    }
    CLL(int data)
    {
        Node *temp = new Node(data);
        temp->next = temp;
        refer = temp;
        head = temp;
        length++;
    }
    void insertNode(int data,int shift)
    {
        if(length !=0)
            shift = shift%length;
        length++;
        if(refer==NULL)
        {
            Node *temp = new Node(data);
            temp->next = temp;
            refer = temp;
            head = temp;
            //printf("YAY");
        }
        else
        {
            while(shift >=1)
            {
                refer = refer->next;
                shift--;
            }
            //Node temp(data);
            Node* temp = new Node(data);
            temp->next = refer->next;
            refer->next = temp;
            refer = refer->next;
            //printf("\nNEXT : %d\nTHIS : %d\n", temp->next->data,temp->data);
            //printf("\nREF : %d\n",refer->data);

        }
    }
    void printAll()
    {
        int first = refer->data;
        while(true)
        {
            printf("%d ",refer->data);
            refer = refer->next;
            if(refer->data ==first)
            {
                printf("\n");
                break;
            }
        }
    }
    void deleteNode(int shift)
    {
        if(length !=0)
            shift = shift%length;
        if(shift == 0)
            shift = length;
        while(shift >1) //Go to the one before node that needed to be removed.
        {
            refer = refer->next;
            shift--;
        }
        Node* temp = refer->next ->next;
        delete refer->next;
        length--;
        if(length == 0)
            refer = NULL;
        else
        {
            refer->next = temp;
            refer = refer->next;
        }
    }
    void printNode(int shift)
    {
        if(length !=0)
            shift = shift%length;
        while(shift >0)
        {
            refer = refer->next;
            shift--;
        }
        printf("%d\n",refer->data);
    }
};

main()
{

    CLL circular_list;
    int n;
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        circular_list.insertNode(temp,0);
        //printf("I %d\n",i);
    }
    circular_list.refer = circular_list.refer->next;
    int t;
    //circular_list.printAll();
    scanf("%d",&t);
    int case_no;
    int shift;
    int val;
    while(t--)
    {
        scanf("%d",&case_no);
        if(case_no == 1)
        {
            scanf("%d %d",&shift, &val);
            circular_list.insertNode(val,shift-1);
        }
        else if(case_no == 2)
        {
            scanf("%d",&shift);
            circular_list.deleteNode(shift-1);
        }
        else
        {
            scanf("%d",&shift);
            circular_list.printNode(shift-1);
        }
        //circular_list.printAll();
    }

}
