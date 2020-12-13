#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void beginning(struct Node **head, int new_data)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void insertAfter(int key, int value)
{
    struct Node *myNode = head;
    int flag = 0;
    while (myNode != NULL)
    {
        if (myNode->data == key)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = myNode->next;
            myNode->next = newNode;
            flag = 1;
            break;
        }
        else
            myNode = myNode->next;
    }
    if (flag == 0)
        printf("Key not found!\n");
}

void insert(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
void deleteNode(struct Node **head1, int key)
{
    struct Node *temp = *head1, *prev;
    if (temp != NULL && temp->data != key)
    {
        *head1 = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int main()
{
    int n, choice, m, k, d;
    char ch, sh;
    do
    {
        printf("Enter the number:\n");
        scanf("%d", &n);
        insert(&head, n);
        printf("Do you wish to continue(y/n)?");
        scanf("%s", &ch);
    } while (ch == 'y' || ch != 'n');
    printList(head);
    do
    {
        printf("\nEnter you choice: 1.Insert at the beginning\t 2.Insert After\t 3.Delete node \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the new data:\n");
            scanf("%d", &m);
            beginning(&head, m);
            printList(head);
            break;
        case 2:
            printf("Enter the new data:\n");
            scanf("%d", &m);
            printf("After which you want to enter:\n");
            scanf("%d", &k);
            insertAfter(k, m);
            printList(head);
            break;
        case 3:
            printf("Enter the data to be deleted:\n");
            scanf("%d", &d);
            deleteNode(&head, d);
            printList(head);
            break;
        default:
            printf("Incorrect input");
        }
        printf("Do you wish to continue(y/n)?");
        scanf("%s", &sh);
    } while (sh == 'y' || sh != 'n');
    return 0;
}