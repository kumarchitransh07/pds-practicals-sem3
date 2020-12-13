#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head;

void insertnode(int value)
{
    node*temp = new node(); 
    temp->data = value;
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        node *temp2 = head;
        while(temp2->next!=NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->next = NULL;
    }
}
void print()
{
    node *temp = head;
    if(temp==nullptr)
    {
        cout << "No element in list!!";
    }
    else
    {
        cout << "The given linked list : ";
        while(temp!=NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
    }
}
void deletenode(int n)
{
    node *temp1 = head;
    if (n==1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }
    
    for(int i=0; i<n-2; i++)
    {
        temp1 = temp1->next;
    }
    node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;

}
int main()
{
    head = NULL;
    int n;
    cout << "How many elements : ";
    cin >> n;
    int value1;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the number : ";
        cin >> value1;
        insertnode(value1);
    }
    print();
    cout << "\nLast node will be deleted.\n";
    deletenode(n);
    print();
}