#include<stdio.h>
int a[50],i,j,ind=1,p,c,t,max=50,l,r,temp;
int main()
{
    int c,f;
    do
    {
    printf("-----MENU------\n1.Insertion  2.Deletion  3.Display  4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:insertion();
            break;
        case 2:deletion();
            break;
        case 3:display();
            break;
        case 4:exit(0);
            break;
        default:printf("\nInvalid choice : \n");
    }
    }
    while(c!=4);
}
int insertion()
{
    if(ind>max)
    {
        printf("\nArray is Full!\n");
        return 0;
    }
    printf("Enter the element : ");
    scanf("%d",&a[ind]);
    p=ind/2;
    c=ind;
    while(a[p]>a[c] && p!=0)
    {
        t=a[p];
        a[p]=a[c];
        a[c]=t;
        c=p;
        p=p/2;
    }
    ind=ind+1;
}
int deletion()
{
    if(ind==1)
    {
        printf("\nIt's Empty!\n");
        return 0;
    }
    if(ind==2)
    {
        ind=1;
        printf("\nDeleted successfully.\n");
        return 0;
    }
    a[1]=a[ind-1];
    ind=ind-1;
    p=1;
    l=p*2;
    r=(p*2)+1;
    while((a[p]>a[l] || a[p]>a[r]) && (l<ind))
    {
        if(r>=ind)
        {
            t=l;
        }
        else if(a[l]>a[r])
        {
            t=r;
        }
        else if(a[r]>a[l])
        {
            t=l;
        }
        temp=a[t];
        a[t]=a[p];
        a[p]=temp;
        p=t;
        l=p*2;
        r=(p*2)+1;
    }
    printf("\nDeleted successfully.\n");
}
int display()
{
    if(ind==1)
    {
        printf("\nEmpty!\n");
        return 0;
    }
    printf("Elements :");
    for(i=1;i<ind;i++)
    {
        printf("\n%d\n",a[i],i);
    }
}
