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
node *merge(node *&head1, node *head2)
{
    node *pt1 = head1;
    node *pt2 = head2;
    node *dummy = new node(-1);
    node *pt3 = dummy;

    while (pt1 != NULL && pt2 != NULL)
    {
        if (pt1->data < pt2->data)
        {
            pt3->next = pt1;
            pt1 = pt1->next;
        }
        else
        {
            pt3->next = pt2;
            pt2 = pt2->next;
        }
        pt3 = pt3->next;
    }
    while (pt1 != NULL)
    {
        pt3->next = pt1;
        pt1 = pt1->next;
        pt3 = pt3->next;
    }
    while (pt2 != NULL)
    {
        pt3->next = pt2;
        pt2 = pt2->next;
        pt3 = pt3->next;
    }
    return dummy->next;
}
node *mergeRecursive(node *&head1, node *&head2)
{
    node *result;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);
    display(head1);
    display(head2);

    // node *newHead = merge(head1, head2);
    node *newHead = mergeRecursive(head1, head2);
    display(newHead);
    return 0;
}