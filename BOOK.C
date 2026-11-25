/*
      Name:Nikhil Shee
      DOC:3 Nov 2026
      Obj:Book Details Using Structure
*/

#include<stdio.h>
#include<conio.h>
#define SIZE 5

struct Book
{
	int bId;
	char bName[30];
	float price;
	int flag;

}b[SIZE];

void scanBook();
void displayBook();
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
	printf("\n1---scan Book Details");
	printf("\n2---display Book Details");
	printf("\n3---Search Book Details");
	printf("\n4---Update Book Details");
	printf("\n5---Delete Book Details");
	printf("\n6---Exit");

	printf("\nEnter your choice: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:scanBook();
		       break;

		case 2:displayBook();
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

void scanBook()
{
	int i;
	float temp;

	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter Book ID=");
		scanf("%d",&b[i].bId);

		printf("\nEnter Book Name=");
		scanf("%s",b[i].bName);

		printf("\nEnter Price=");
		scanf("%f",&temp);
		b[i].price=temp;

		b[i].flag=1;


	}


}

void displayBook()
{
	int i;


	printf("\nB_ID\tB_NAME\t\tB_PRICE");


	for(i=0;i<SIZE;i++)
	{
		if(b[i].flag!=-1)
		{
			printf("\n%d\t%s\t\t%.2f",b[i].bId,b[i].bName,b[i].price);
		}

	}


  }

int search(id)
{
	int i;

	for(i=0;i<SIZE;i++)
	{
		if(b[i].bId==id && b[i].flag!=-1)
		{
			return i;

		}

	}
	return -1;

}

void particular(int i)
{
	if(b[i].flag!=-1)
	{
	printf("\nB_ID\tB_NAME\tB_PRICE");
	printf("\n%d\t%s\t%.2f",b[i].bId,b[i].bName,b[i].price);

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
		       scanf("%d",&b[i].bId);
		       printf("\nThe New Details are--->\n");
		       particular(i);
		       break;

		case 2:printf("\nThe Previous Details are--->\n");
		       particular(i);
		       printf("\nEnter New Name:");
		       scanf("%s",b[i].bName);
		       printf("\nThe New Details are--->\n");
		       particular(i);
		       break;

		case 3:printf("\nThe Previous Details are--->\n");
		       particular(i);
		       printf("\nEnter New Price:");
		       scanf("%f",&temp);
		       b[i].price=temp;
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
		b[index].flag=-1;
		printf("\nRecord Deleted Successfully");

	}



}