#include <iostream>
using namespace std;
struct node
{
    int roll;
    string name;
    node *next;
};
struct node *head;
void insert()
{
    node*temp = new node(); 
    int roll;
    char name[20];
    cout << "Enter roll number : ";
    cin >> roll;
    cout << "Enter name : ";
    cin.ignore();
    cin.getline(name, 20);
    temp->roll = roll;
    temp->name = name;
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
        cout << "No data present.";
    }
    else
    {
        cout << "The given student data is : " << endl;
        while(temp!=NULL)
        {
            cout << "Roll no. : " << temp->roll << "   Name : " << temp->name << endl;
            temp = temp->next;
        }
    }
}
int main()
{
    head = NULL;
    cout << "How many students : ";
    int n;
    cin >> n;
    while(n--)
    {
        insert();
    }
    print();   
}