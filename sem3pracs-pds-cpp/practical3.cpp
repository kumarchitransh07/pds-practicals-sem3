#include <bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    string name;
    node *next;
    node *previous;
};

node *head;
node *tail;

void insert()
{
    node *newnode = new node();
    node *temp;
    int roll;
    char name[20];
    cout << "Enter roll number : ";
    cin >> roll;
    cout << "Enter name : ";
    cin.ignore();
    cin.getline(name, 20);
    newnode->roll = roll;
    newnode->name = name;
    newnode->next = NULL;
    newnode->previous = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->previous = temp;
        temp = newnode;
        tail = newnode;
    }
}
void print()
{
    node *temp = head;
    if(temp==nullptr)
    {
        cout << "No student data available.";
    }
    else
    {
        cout << "Starting from head, student data is : \n";
        while (temp!=NULL)
        {
            cout << "Roll no. : " <<temp->roll << "    " << "Name : " << temp->name << endl;
            temp = temp->previous;
        }
    }
}

void printreverse()
{
    node *temp = tail;
    if(temp==nullptr)
    {
        cout << "No student data available.";
    }
    else
    {
        cout << "Starting from tail, student data is : \n";
        while (temp!=NULL)
        {
            cout << "Roll no. : " <<temp->roll << "    " << "Name : " << temp->name << endl;
            temp = temp->previous;
        }
    }
}

int main()
{
    head = NULL;
    int n; 
    cout << "How many elements : ";
    cin >> n;
    while(n--)
    {
        insert();
    }
    print();
    cout << endl;
    printreverse();
}