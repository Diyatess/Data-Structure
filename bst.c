#include<stdio.h>
#include<stdlib.h>

struct node
{
        struct node *lchild;
        int info;
        struct node *rchild;
};

struct node *search(struct node *ptr, int skey);
struct node *insert(struct node *ptr, int ikey);
struct node *del(struct node *ptr, int dkey);
struct node *Min(struct node *ptr);
struct node *Max(struct node *ptr);
int height(struct node *ptr);
void inorder(struct node *ptr);

int main( )
{
        struct node *root=NULL,*ptr;
        int choice,k;

        while(1)
        {
                printf("\n-----Menu-----\n");
                printf(" 1.Insert  2.Search");
                printf("3.Delete  4.Inorder Traversal\n");
                printf(" 7.Quit\n");
                printf("Enter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {

                case 1:
                        printf("Enter the key to be inserted : ");
                        scanf("%d",&k);
                        root = insert(root, k);
                        break;

                case 2:
                        printf("Enter the key to be searched : ");
                        scanf("%d",&k);
                        ptr = search(root, k);
                        if(ptr!=NULL)
                                printf("\nKey found...");
                        break;

                case 3:
                        printf("Enter the key to be deleted : ");
                        scanf("%d",&k);
                        root = del(root,k);
                        break;

                 case 4:
                        inorder(root);
                        break;
                 case 5:
                         printf("Height of tree is %d", height(root));
                         break;

                 case 6:
                        ptr = Min(root);
                        if(ptr!=NULL)
                                printf("\nMinimum key is %d", ptr->info );
                        ptr = Max(root);
                        if(ptr!=NULL)
                                printf("\nMaximum key is %d", ptr->info );
                        break;

                 case 7:exit(1);

                 default:
                        printf("\nWrong choice\n");
                }
        }
        return 0;

}

struct node *search(struct node *ptr, int skey)
{
        if(ptr==NULL)
        {
                printf("key not found\n");
                return NULL;
        }
        else if(skey < ptr->info)
                return search(ptr->lchild, skey);
        else if(skey > ptr->info)
                return search(ptr->rchild, skey);
        else
                return ptr;
}

struct node *insert(struct node *ptr, int ikey )
{
        if(ptr==NULL)
        {
                ptr = (struct node *) malloc(sizeof(struct node));
                ptr->info = ikey;
                ptr->lchild = NULL;
                ptr->rchild = NULL;
        }
        else if(ikey < ptr->info)
                ptr->lchild = insert(ptr->lchild, ikey);
        else if(ikey > ptr->info)
                ptr->rchild = insert(ptr->rchild, ikey);
        else
                printf("Duplicate key");
        return ptr;
}

struct node *del(struct node *ptr, int dkey)
{
        struct node *tmp, *succ;

        if( ptr == NULL)
        {
                printf("Dkey not found");
                return(ptr);
        }
        if( dkey < ptr->info )
                ptr->lchild = del(ptr->lchild, dkey);
        else if( dkey > ptr->info )
                ptr->rchild = del(ptr->rchild, dkey);
        else
        {

                if( ptr->lchild!=NULL  &&  ptr->rchild!=NULL )
                {
                        succ=ptr->rchild;
                        while(succ->lchild)
                                succ=succ->lchild;
                        ptr->info=succ->info;
                        ptr->rchild = del(ptr->rchild, succ->info);
                }
                else
                {
                        tmp = ptr;
                        if( ptr->lchild != NULL )
                                ptr = ptr->lchild;
                        else if( ptr->rchild != NULL)
                                ptr = ptr->rchild;
                        else
                                ptr = NULL;
                        free(tmp);
                }
        }
        return ptr;
}

struct node *Min(struct node *ptr)
{
        if(ptr==NULL)
                return NULL;
        else if(ptr->lchild==NULL)
        return ptr;
        else
                return Min(ptr->lchild);
}

struct node *Max(struct node *ptr)
{
        if(ptr==NULL)
                return NULL;
        else if(ptr->rchild==NULL)
        return ptr;
        else
                return Max(ptr->rchild);
}


void inorder(struct node *ptr)
{
        if(ptr == NULL )
                return;
        inorder(ptr->lchild);
        printf("%d  ",ptr->info);
        inorder(ptr->rchild);
}

int height(struct node *ptr)
{
        int h_left, h_right;

        if (ptr == NULL)
                return 0;

        h_left =  height(ptr->lchild);
        h_right = height(ptr->rchild);

        if (h_left > h_right)
                return 1 + h_left;
        else
                return 1 + h_right;
}
