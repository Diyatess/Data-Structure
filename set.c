#include<stdint.h>
#include<stdlib.h>

int set_union();
int set_inter();
int set_diff();
int set_equal();
int main()
{
    int choice;
    while(1)
    {
        printf("\n \n ----Menu---- \n");
        printf("1.Union 2.Intersection \n 3.Difference 4.Equality");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            set_union();
            break;
            case 2:
            set_inter();
            break;
            case 3:
            set_diff();
            break;
            case 4:
            set_equal();
            break;
            default: printf("OOPS!! You Selected wrong option");
        }
    }

}

int set_union()
{
    int s[50],s1[20],s2[20],i,n,m;
    printf(" Enter the size of first set elements:");
    scanf("%d",&n);
    printf(" enter the set elements(0's or 1's):");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the size of second set elements:");
    scanf("%d",&m);
    printf("enter the set elements(0's or 1's):");
    for(i=0;i<m;i++)
    {
        scanf("%d",&s2[i]);
    }
    if(n!=m)
    {
        printf("We cannot find union");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            s[i]=s1[i]||s2[i];
        }
        printf("union is:");
        for(i=0;i<n;i++)
        {
          printf("%d",s[i]);
        }
    }
}
int set_inter()
{
    int s[50],s1[20],s2[20],i,n,m;
    printf("Enter the size:");
    scanf("%d",&n);
    printf("enter the set elements(0's or 1's):");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the size:");
    scanf("%d",&m);
    printf("enter the set elements(0's or 1's):");
    for(i=0;i<m;i++)
    {
        scanf("%d",&s2[i]);
    }
    if(n!=m)
    {
        printf("We cannot find intersection");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            s[i]=s1[i] && s2[i];
        }
        printf("intersection is:");
        for(i=0;i<n;i++)
        {
          printf("%d",s[i]);
        }
    }
}

int set_diff()
{
    int s[50],s1[20],s2[20],i,n,m;
    printf("Enter the size :");
    scanf("%d",&n);
    printf("enter the set elements(0's or 1's):");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the size :");
    scanf("%d",&m);
    printf("enter the set elements(0's or 1's):");
    for(i=0;i<m;i++)
    {
        scanf("%d",&s2[i]);
    }
    if(n!=m)
    {
        printf("We cannot find Difference");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            s2[i]=!s2[i];
        }
        for(i=0;i<n;i++)
        {
            s[i]=s1[i] && s2[i];
        }
        printf("Difference is:");
        for(i=0;i<n;i++)
        {
          printf("%d",s[i]);
        }
    }
}
int set_equal()
{
    int s[50],s1[20],s2[20],i,n,m;
    printf("Enter the size :");
    scanf("%d",&n);
    printf("enter the set elements(0's or 1's):");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the size :");
    scanf("%d",&m);
    printf("enter the set elements(0's or 1's):");
    for(i=0;i<m;i++)
    {
        scanf("%d",&s2[i]);
    }
    if(n!=m)
    {
        printf("We cannot find Equality");
    }
    else
    {
        int count=0;
        for(i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                count=1;
            }
        }
        if(count==1)
            printf("These two sets are not equal");
        else
            printf("Two sets are equal");
    }
}

