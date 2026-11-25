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


void main()
{
	int choice;
	clrscr();
	while(1)
	{
		printf("\n1---ScanEmployeeDetails");
		printf("\n2---DisplayEmployeeDetails");
		printf("\n3---Exit");

		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:scanEmployee();
				break;
			case 2:displayEmployee();
				break;
			case 3:exit(0);
				break;
			default:printf("\nInvalid Choice!!");

		}

	}

	getch();







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