/*
	Name:Nikhil Shee
	Doc:15 oct 2026
	Obj:Employee management system
*/
#include<stdio.h>
#include<conio.h>
#define SIZE 5

struct Employee
{
	int eId;
	char eName[30];
	float gSalary;
	float tAllowances;
	float nSalary;
	float tax;


}a[SIZE];

void scanEmployee(void);
void displayEmployee(void);
void nSalary(int i);
void search(int id);


void main()
{
	int choice,id;
	clrscr();
	while(1)
	{
		printf("\n1---Scan Employee Details");
		printf("\n2---Display Employee Details");
		printf("\n3---Search Employee Details");
		printf("\n4---Exit");

		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:scanEmployee();
				break;
			case 2:displayEmployee();
				break;
			case 3:printf("\nEnter the Employee ID to Search:");
			       scanf("%d",&id);
			       search(id);
			       break;
			case 4:exit(0);
				break;
			default:printf("\nInvalid Choice!!");

		}

	}

	getch();
}

void search(int id)
{
	int success=-1,i;
	for(i=0;i<SIZE;i++)
	{
		if(id==a[i].eId)
		{
			success=i;
			break;
		}


	}

	if(success>=0)
	{
		printf("\nEID\tENAME\tGSALARY\tTALLOWANCES\tNETSALARY\tTAX");
		printf("\n%d\t%s\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",a[i].eId,a[i].eName,a[i].gSalary,a[i].tAllowances,a[i].nSalary,a[i].tax);

	}
	else
		printf("\nEmployee Not Found!!");



}

void scanEmployee()
{
	int i;
	float temp;

	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter Employee ID=");
		scanf("%d",&a[i].eId);

		printf("\nEnter Employee Name:");
		scanf("%s",a[i].eName);

		printf("\nEnter gross Salary=");
		scanf("%f",&temp);
		a[i].gSalary=temp;

		printf("\nEnter travel allowances=");
		scanf("%f",&temp);
		a[i].tAllowances=temp;

		printf("\nEnter tax=");
		scanf("%f",&temp);
		a[i].tax=temp;

		nSalary(i);


	}

}

void nSalary(int i)
{
	a[i].nSalary=a[i].gSalary-(a[i].tax+a[i].tAllowances);
}

void displayEmployee()
{
	int i;
	printf("\n==============================Employee Details=============================\n");
	printf("\nEID\tENAME\tGSALARY\tTALLOWANCES\tNETSALARY\tTAX");
	for(i=0;i<SIZE;i++)
	{
	    printf("\n%d\t%s\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",a[i].eId,a[i].eName,a[i].gSalary,a[i].tAllowances,a[i].nSalary,a[i].tax);


	}

}