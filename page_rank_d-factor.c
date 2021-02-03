#include<stdio.h>
#include<conio.h>
int main()
{   int m[10],n,a[10],i;
    float d,d2,b,c,pr[10],x[10],s;
    printf("Enter the value of damping factor d between 0 to 1 :-- ");
    scanf("%f",&d);
    d2= 1-d;
    printf("Enter the no. of outgoing pages of the page whose page rank is to be calculated :--\n");
    scanf("%d",&n);
    printf("Enter the pages:--\n");
    for (i=0;i<n;i++)
    {scanf("%d", &a[i]);}
    for (i=0;i<n;i++)
    {printf("Enter the page rank of page %d :-- ", a[i]);
    scanf("%f",&pr[i]);}
    for (i=0;i<n;i++)
    {
    printf("Enter the outlink pages of page %d :-- ", a[i]);
    scanf("%d",&m[i]);}
    for (i=0;i<n;i++)
    {x[i]=pr[i]/m[i];
    s=s+x[i];}
    printf("Summation is :-- %f\n",s);
    b= s*d;
    c=d2+b;
    printf("Page rank is :-- %f",c);
    getch();
    return 0;
    }
