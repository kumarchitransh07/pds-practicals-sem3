#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
struct student_data
{
int rollno;
char studentName[MAX];
float marks;
struct student_data *next;
};
struct student_data *insert(struct student_data *front, int id, char name[], float grades)
{
struct student_data *newnode;
newnode = (struct student_data*)malloc(sizeof(struct student_data));
if (newnode == NULL)
{
printf("\n Allocation failed \n");
exit(2);
}
newnode->rollno = id;
strcpy(newnode->studentName, name);
newnode->marks= grades;
newnode->next = front;
front = newnode;
return(front);
}
void printNode(struct student_data *p)
{
printf("\n Roll No: %d", p->rollno);
printf("\n Name of the student: %s", p->studentName);
printf("\n Grades: %f\n", p->marks);
}
void display(struct student_data *front)
{
struct student_data *ptr;
for (ptr = front; ptr != NULL; ptr = ptr->next)
{
printNode(ptr);
}
}
int main()
{
struct student_data *linkList;
char name[21];
char choice;
int id;
float grades;
linkList = NULL;
do
{
printf("\n Enter the roll no: ");
scanf("%d", &id);
printf("Enter the name of the student: ");
scanf("%s" , &name);
printf("Enter the grades: ");
scanf("%f",&grades);
linkList = insert(linkList, id, name, grades);
printf("Do you wish to continue(y/n)?");
scanf("%s",&choice);
}
while( choice=='y' || choice!='n');
if (linkList == NULL)
{
printf("\n List empty.");
}
display(linkList);
return 0;
}