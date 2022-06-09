#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;
    node *prev = NULL;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}
void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;

    delete temp;
}
int length(node* &head){
    int l =0;
    node* temp=head;

    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}
node* kAppend(node* &head,int k){
    node* newtail;
    node* newhead;
    node* tail =head;
    int l = length(head);
    int count = 1;

    while(tail->next!=NULL){
        if(count == l-k){
            newtail = tail;
        }
        if(count==l-k+1){
            newhead = tail;
        }
        tail=tail->next;
        count++;
    }
    tail->next = head;
    newtail->next = NULL;

    return newhead;
}
int main()
{
    node *head = NULL;
    // insertAtTail(head,1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtHead(head, 1);
    display(head);
    // deletion(head, 1);
    // display(head);
    // cout<<length(head);
    node* newhead = kAppend(head, 3);
    display(newhead);

    return 0;
}