#include<stdio.h>
#include<conio.h>

void square(int a[],int b[],int s)
{
	int i;

	for(i=0;i<s;i++)
	{

		b[i]=a[i]*a[i];

	}


	printf("\nSquare of array-->");

	for(i=0;i<s;i++)
	{
		printf("%d\t",b[i]);

	}


}

void sort(int b[],int s)
{
	int i,j,temp;

	for(i=0;i<s;i++)
	{
		for(j=0;j<s-1;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}

		}



	}

	printf("\nSorted array--->\n");
	for(i=0;i<s;i++)
	{

		printf("%d\t",b[i]);

	}


}

void main()
{
	int a[100],b[100],s,i;
	clrscr();

	printf("\nEnter size:");
	scanf("%d",&s);

	for(i=0;i<s;i++)
	{
		printf("\nEnter a[%d]=",i);
		scanf("%d",&a[i]);




	}

	square(a,b,s);

	sort(b,s);


   getch();


}