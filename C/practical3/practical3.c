#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
char batch[20], name[20], dept[10];
long int phno,id;
struct node *rlink;
struct node *llink;
};
typedef struct node* NODE;
NODE first=NULL;
int count=0;
NODE createStudentNode()
{
NODE student;
student=(NODE)malloc(sizeof(struct node));
if(student==NULL)
{
printf("Out of Memory\n");
exit(0);
}
student->rlink=NULL;
student->llink=NULL;
char batch[20], name[20], dept[10] ;
long int phno,id;
printf("Enter Batch:\t");
scanf("%s", batch);
printf("Enter Name:\t");
scanf("%s", name);
printf("Enter Department:\t");
scanf("%s", dept);
printf("Enter Phone Number:\t");
scanf("%ld", &phno);
printf("Enter ID No.\t");
scanf("%ld", &id);
strcpy(student->batch, batch);
strcpy(student->name, name);
strcpy(student->dept, dept);
student->phno=phno;
student->id=id;
count++;
return student;
}
void display()
{
NODE cur;
cur=first;
if(cur==NULL)
{
printf("The list is empty\n");
}
else
{
printf("The contents of the list are\n");
while(cur!=NULL)
{
printf("\nBatch: %s\nName: %s\nDepartment: %s\nPhone: %ld \nID No: %ld",cur->batch, cur->name, cur->dept, cur->phno,cur->id);
cur=cur->rlink;
}
printf("\nThe number of students: %d",count);
}
}
NODE insert_end()
{
NODE cur, temp;
temp=createStudentNode();
if(first==NULL)
{
return temp;
}
cur=first;
while(cur->rlink!=NULL)
{
cur=cur->rlink;
}
cur->rlink=temp;
temp->llink=cur;
temp->rlink=NULL;
return first;
}
int main()
{
int n,i;
printf("Enter the number of students\n");
scanf("%d",&n);
for(i=0; i<n; i++)
first=insert_end();
display();
return 0;
}