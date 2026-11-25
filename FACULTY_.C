/*
	Name:Nikhil Shee
	DOC:22 Oct 2026
	Obj:Faculty Management system
*/

#include<stdio.h>
#include<conio.h>
#define SIZE 5

struct faculty
{
	int fId;
	char fName[30];
	float fSalary;
	int flag;

}f[SIZE];

void scanFacultyDetails(void);
void displayFacultyDetails(void);
int search(int id);
void displayParticularFaculty(int index);
void updateFacultyDetails(int index);
void del(int id);


void main()
{
	int choice,id;
	int index;
	clrscr();

	while(1)
	{

	printf("\n===========Faculty Members Management============\n");
	printf("\n1---ScanFacultyDetails");
	printf("\n2---displayFacultyDetails");
	printf("\n3---SearchParticularFaculty");
	printf("\n4---UpdateFacultyDetails");
	printf("\n5---DeleteFacultyDetails");
	printf("\n6---Exit\n");

	printf("\n Enter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:scanFacultyDetails();
			break;

		case 2:displayFacultyDetails();
			break;

		case 3:printf("\nEnter the Faculty ID:");
			scanf("%d",&id);
			index=search(id);

			if(index==-1)
			{
				printf("\nNo Record Found!!");


			}
			else
			{
				displayParticularFaculty(index);
			}
			break;
		case 4:printf("\nEnter the Faculty Id to update:");
		       scanf("%d",&id);
		       index=search(id);

		       if(index==-1)
		       {
				printf("\n No Record Found!!!");

		       }
		       else
		       {

				updateFacultyDetails(index);
		       }
		       break;

		case 5:printf("\nEnter Id to Delete:");
		       scanf("%d",&id);
		       del(id);
		       break;

		case 6:exit(0);

		default:printf("\n Invalid Choice");





	}//end of switch


      }//end of while

 getch();
}

void scanFacultyDetails()
{
	int i;
	float temp;
	for(i=0;i<SIZE;i++)
	{

		printf("\nEnter Faculty ID:");
		scanf("%d",&f[i].fId);

		printf("\nEnter Faculty Name:");
		scanf("%s",f[i].fName);

		printf("\nEnter Faculty Salary:");
		scanf("%f",&temp);

		f[i].fSalary=temp;

	}//end of for



}//scaning Faculty Details

void displayFacultyDetails()
{
	int i;

	printf("\nF_ID\tF_NAME\tF_SALARY\n");

	for(i=0;i<SIZE;i++)
	{
		if(f[i].flag!=-1)
			printf("\n%d\t%s\t%.2f",f[i].fId,f[i].fName,f[i].fSalary);

	} //end of for

}//displaying Faculty Details

int search(int id)
{
	int i;

	for(i=0;i<SIZE;i++)
	{
		if(f[i].fId==id && f[i].flag!=-1)
		{
			return i;

		}// end of if

	} //end of for

	return -1;

}//end of search

void displayParticularFaculty(int i)
{

     if(f[i].flag!=-1)
     {
	 printf("\nF_ID\tF_NAME\tF_SALARY\n");
	 printf("\n%d\t%s\t%.2f",f[i].fId,f[i].fName,f[i].fSalary);
     }
     else
     {
	printf("\nRecord Not Found!!!");
     }

}//end of displaying particular faculty Details

void updateFacultyDetails(int i)
{
	int choice;
	float temp;

	printf("\n=======Update Menu========\n");
	printf("\n1-----Faculty Name");
	printf("\n2-----Faculty Salary");

	printf("\nEnter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:printf("\nThe Previous Details are---->\n");
		       displayParticularFaculty(i);
		       printf("\nEnter the New Name of Faculty:");
		       scanf("%s",f[i].fName);
		       printf("\nThe Updated Details are------>\n");
		       displayParticularFaculty(i);
		       break;

		case 2:printf("\nThe Previous Details are---->\n");
		       displayParticularFaculty(i);
		       printf("\nEnter the New Salary of Faculty:");
		       scanf("%f",&temp);
		       f[i].fSalary=temp;
		       printf("\nThe Updated Details are------>\n");
		       displayParticularFaculty(i);
		       break;

	}

}

void del(int id)
{

	int index;

	index=search(id);

	if(index==-1)
	{
		printf("\nRecord Not Found!!");

	}

	else
	{
		f[index].flag=-1;
		printf("\nRecord Deleted Successfully!!!");
	}

}