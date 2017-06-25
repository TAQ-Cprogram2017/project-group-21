#include<stdio.h>
#include<string.h>
#include<math.h>

void main()
{
    printf("draw the chemical structure below\n");
    matrix();
    return 0;
}

int matrix()
{
int i=0,j=0;
int n=carboncount();
char a[n][n];
for (i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        a[i][j]='0';
    }
}
for (i=0;i<n;i++)
{
    a[i][i]='x';
    a[i+1][i]='1';
    a[i][i+1]='1';
}
printf("the secular determinant of the chemical is:\n\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if(i==j+1 || i==j-1)
        printf("-%c       ",a[i][j]);
        else
        printf(" %c       ",a[i][j]);
    }
 printf("\n");
}
printf("\n");
printf("the solutions of X are:\n\n");

    float t1,t2,t3;
    double x[n];
    for(i=0;i<n;i++)
    {
        t1=(i+1)*3.1415926;
        //printf("t1=%f\n",t1);
        t2=n+1;
        //printf("t2=%f\n",t2);
        t3=t1/t2;
        //printf("t3=%f\n",t3);
        x[i]=2*cos(t3);
        printf("X[%d]=%f     ",i+1,x[i]);
    }
    printf("\n\n");
    printf("the energy levels are:\n\n");
for(i=n-1;i>=0;i--)
{
    if(x[i]>=0)
    printf("____  E[%d] = a + %f b\n\n",i+1,x[i]);
    else
    printf("____  E[%d] = a - %f b\n\n",i+1,-x[i]);
}
double c[n];
double sum=1;
printf("the molecular orbitals are: \n\n");
c[n-1]=1;
//printf("c[%d]=%f",n-1,c[n-1]);
for(i=0;i<n;i++)
{
    c[n-2]=x[i];
    //printf("c[%d]=%f",n-2,x[i]);}
    for(j=n-1;j>=0;j--)
    {
        c[j-2]=x[i]*c[j-1]-c[j];
        //printf("c[%d]=%f\n     ",j,c[j]);

    }//above is correct
   for(j=1;j<n;j++)
    {
        //sum=sum+c[j]*c[j];

    }
    //sum=sqrt(sum);
    //printf("sum=%f",sum);}
    //sum=1;

    /*for(j=0;j<n;j++)
    {
        c[j]=c[j]/sqrt(sum);
        printf("c[%d]=%f     ",j,c[j]);
    }
    sum=1;*/

    printf("¦×[%d] = %f ¦Õ[1]",i+1,c[0]);
    for(j=1;j<n;j++)
    printf(" + %f ¦Õ[%d] ",c[j],j+1);
    printf("\n");
}
printf("the charge density of each atom is:\n\n");
for(i=n-1;i>=0;i--)
{
    if (i==0)
    printf("C  ");
    else
        if (i%2==0)
        printf("C     -    ");
        else
        printf("C     =     ");
}
printf("\n");
for(i=n-1;i>=0;i--)
{
    printf("%f  ",c[i]*c[i]);
}
printf("\n");
}

int carboncount()
{
 char a[1000];
 gets(a);
 char x='C';
 int i,k=0;
 for(i=0;i<strlen(a);i++)
 {
     if(a[i]==x)
     {
         k++;
     }
 }
return k;
}
