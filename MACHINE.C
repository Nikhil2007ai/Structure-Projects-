/*
      Name:Nikhil Shee
      DOC:3 Nov 2026
      Obj:Machine Details Using Structure
*/

#include<stdio.h>
#include<conio.h>
#define SIZE 5

struct Machine
{
	int mId;
	char mName[30];
	float price;
	int flag;

}m[SIZE];

void scanMachine();
void displayMachine();
int search(int id);
void particular(int i);
void update(int i);
void del(int id);

void main()
{
	int choice,id,index;
	clrscr();

	while(1)
	{

	printf("\n=========Machine Details===========\n");
	printf("\n1---scan Machine Details");
	printf("\n2---display Machine Details");
	printf("\n3---Search Machine Details");
	printf("\n4---Update Machine Details");
	printf("\n5---Delete Machine Details");
	printf("\n6---Exit");

	printf("\nEnter your choice: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:scanMachine();
		       break;

		case 2:displayMachine();
		       break;

		case 3:printf("\nEnter the id to search:");
		       scanf("%d",&id);
		       index=search(id);
		       if(index==-1)
		       {
				printf("\nNo Record Found!!");
		       }
		       else
		       {
				particular(index);
		       }
		       break;

		case 4:printf("\nEnter the id to update:");
		       scanf("%d",&id);
		       index=search(id);
		       if(index==-1)
		       {
				printf("\nNo Record Found!!");
		       }
		       else
		       {
				update(index);
		       }
		       break;

		case 5:printf("\nEnter the id to delete:");
		       scanf("%d",&id);
		       del(id);
		       break;

		case 6:exit(0);

		default:printf("\nInvalid Choice!!!");

	}


	}

	getch();
}

void scanMachine()
{
	int i;
	float temp;

	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter Machine ID=");
		scanf("%d",&m[i].mId);

		printf("\nEnter Machine Name=");
		scanf("%s",m[i].mName);

		printf("\nEnter Price=");
		scanf("%f",&temp);
		m[i].price=temp;

		m[i].flag=1;


	}


}

void displayMachine()
{
	int i;


	printf("\nM_ID\tM_NAME\t\tM_PRICE");


	for(i=0;i<SIZE;i++)
	{
		if(m[i].flag!=-1)
		{
			printf("\n%d\t%s\t\t%.2f",m[i].mId,m[i].mName,m[i].price);
		}

	}


  }

int search(id)
{
	int i;

	for(i=0;i<SIZE;i++)
	{
		if(m[i].mId==id && m[i].flag!=-1)
		{
			return i;

		}

	}
	return -1;

}

void particular(int i)
{
	if(m[i].flag!=-1)
	{
	printf("\nM_ID\tM_NAME\tM_PRICE");
	printf("\n%d\t%s\t%.2f",m[i].mId,m[i].mName,m[i].price);

	}

	else
	{
		printf("\nNo Record Found!!");
	}

}

void update(int i)
{
	int choice;
	float temp;

	printf("\n========Update Menu=========");
	printf("\n1---Id");
	printf("\n2---Name");
	printf("\n3---Price");

	printf("\nEnter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:printf("\nThe Previous Details are--->\n");
		       particular(i);
		       printf("\nEnter New ID:");
		       scanf("%d",&m[i].mId);
		       printf("\nThe New Details are--->\n");
		       particular(i);
		       break;

		case 2:printf("\nThe Previous Details are--->\n");
		       particular(i);
		       printf("\nEnter New Name:");
		       scanf("%s",m[i].mName);
		       printf("\nThe New Details are--->\n");
		       particular(i);
		       break;

		case 3:printf("\nThe Previous Details are--->\n");
		       particular(i);
		       printf("\nEnter New Price:");
		       scanf("%f",&temp);
		       m[i].price=temp;
		       printf("\nThe New Details are--->\n");
		       particular(i);
		       break;

		case 4:printf("\nInvalid Choice!!!");
		       break;



	}




}

void del(int id)
{
	int index;

	index=search(id);

	if(index==-1)
	{
		printf("\nRecord Not Found!!!");

	}

	else
	{
		m[index].flag=-1;
		printf("\nRecord Deleted Successfully");

	}



}