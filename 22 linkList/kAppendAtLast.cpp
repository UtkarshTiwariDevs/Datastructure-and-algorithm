#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
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
    for(int i =1;i<=10;i++){
        insertAtTail(head,i);
    }
    display(head);

    node* newhead = kAppend(head, 3);
    display(newhead);

    return 0;
}