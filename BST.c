#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;

};

struct node* createNode(int value){
struct node* newNode=(struct node*)malloc(sizeof(struct node));
newNode->data=value;
newNode->left=NULL;
newNode->right=NULL;
return newNode;

}

struct node* insert(struct node* root,int value){
    if (root==NULL){
        return createNode(value);
    }
   else if(value<root->data){
        root->left=insert(root->left,value);
    }
    else{
        root->right=insert(root->right,value);
    }
    return root;
}

int search(struct node* root,int value){
    while(root!=NULL){
        if(value==root->data){
            return 1;
        }
        else if(value<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return 0;

}

struct node* findMin(struct node* root){
    while (root->left!=NULL)
    {
        root=root->left;

    }
return root;
}

struct node* delete(struct node* root,int value)
{
    if(root==NULL){
        return root;
    }
    if(value<root->data){
        root->left=delete(root->left,value);
    }
    else if(value>root->data){
        root->right=delete(root->right,value);
    }
    else{
        if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;

        }
        else if(root->right==NULL){
             struct node* temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);

    }
    return root;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);

    }
}


int main(){
    struct node* root=NULL;
    int choice,value;
    while (1)
    {
        printf("------BST--------");
        printf("1.insert\t2.delete\t3.search\t4.display\t5.exit\t");
        printf("enter your choice\t");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter value:\n");
            scanf("%d",&value);
            root=insert(root,value);
            break;
        case 2:
          printf("enter value:\n");
            scanf("%d",&value);
            root=delete(root,value);
            break;
 case 3:
          printf("enter value:\n");
            scanf("%d",&value);
            if(search(root,value))
            printf("found\n");
            else
            printf("not found\n");

            break;

             case 4:
          printf("tree\n");
            inorder(root);
            printf("\n");
            break;
            case 5:
            exit(0);

        
        default:
        printf("invalid");
            break;
        }
    }
    
}

