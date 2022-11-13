#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct student 
{
    int rollno;
    char name[50];
    double per;
};
int main()
{

    struct student *ptr;
    int n;
    scanf("%d",&n);
    ptr=(struct student*)malloc(n*sizeof(struct student));

    for(int i=0;i<n;i++)
    {
    scanf("%d%s%lf",(&(ptr+i)->rollno),((ptr+i)->name),(&(ptr+i)->per));
    }
    for(int i=0;i<n;i++)
    {

    printf("%d%s%lf",((ptr+i)->rollno),((ptr+i)->name),((ptr+i)->per));
    }
    
    return 0;
}
