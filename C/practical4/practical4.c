#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int t[100], n,i;
void get_array()
{
FILE *InputFile;
InputFile= fopen("input.txt","r");
for (i=0;i<100;i++)
{
fscanf(InputFile,"%d ",&t[i]);
}
fclose(InputFile);
}
struct BST
{
int data;
struct BST *left;
struct BST *right;
};
struct BST *createnode(int t)
{
struct BST* newnode;
newnode= (struct BST*)malloc(sizeof(struct BST));
newnode->data=t;
newnode->left=newnode->right=NULL;
return newnode;
}
struct BST* insert(struct BST* root, int t)
{
if (root==NULL)
{
root=createnode(t);
}
else if (t<=root->data)
{
root->left=insert(root->left,t);
}
else
{
root->right=insert(root->right,t);
}
return root;
}
void inorder(struct BST* root)
{
printf("Inorder transversal:\n");
if (root==NULL)
return;
inorder(root->left);
printf("%d",root->data);
inorder(root->right);
}
void preorder(struct BST* root)
{
printf("Preorder transversal:\n");
if (root==NULL)
return;
printf("%d",root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct BST* root)
{
printf("Postorder transversal:\n");
if (root==NULL);
return;
postorder(root->left);
postorder(root->right);
printf("%d", root->data);
}
int main()
{
get_array();
struct BST *root = NULL;
root=insert(root,*t);
inorder(root);
preorder(root);
postorder(root);
return 0;
}