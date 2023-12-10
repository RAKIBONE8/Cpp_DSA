#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void deleteAtPosition(Node* &head,int pos)
{
    Node* tmp = head;
   for(int i=1;i<=pos-1;i++)
   {
     tmp = tmp->next;
   }
   Node* todelete = tmp->next;
   tmp->next = tmp->next->next;
   delete todelete;
}
int size(Node *head) // O(n)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}
void deleteHead(Node* &head)
{
    Node* todelete = head;
    head = head->next;
    delete todelete;
}
void print(Node *head) // O(n)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    int pos;
    cin>>pos;
    if(pos>=size(head))
    {
        cout<<"Invalid index"<<endl;
    }
    else if(pos == 0)
    {
        deleteHead(head);
    }
    else
    {
        deleteAtPosition(head, pos);
    }
    
    print(head);
    return 0;
}