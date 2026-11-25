/*


	Name:Nikhil Shee
	DOC:8 oct 2026
	OBJ:Student Grade System using Structure

*/

#include<stdio.h>
#include<conio.h>
#define SIZE 5

struct Student
{
	int sid;
	char name[30];
	float fees;
	float maths,psc,bee;
	float total,per;
	char grade;
}s[SIZE];

void scanStudentDetails();
void displayStudentDetails();
void calculateGrade(int i);

void main()
{
	int choice,id;

	while(1)
	{
		clrscr();

		printf("\n1---Scan Student Details");
		printf("\n2---Display Student Details");
		printf("\n3---Exit");

		printf("\n Enter your Choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:scanStudentDetails();
				break;
			case 2:displayStudentDetails();
				break;
			case 3:exit(0);






		}



	      getch();


	}

}

void scanStudentDetails()
{
	int i;
	float temp;

	for(i=0;i<SIZE;i++)
	{
		printf("\n Enter Student ID: ");
		scanf("%d",&s[i].sid);

		printf("\n Enter Student Name: ");
		scanf("%s",s[i].name);

		printf("\n Enter the Student fees: ");
		scanf("%f",&temp);
		s[i].fees=temp;

		printf("\n Enter the maths mark: ");
		scanf("%f",&temp);
		s[i].maths=temp;

		printf("\n Enter the bee mark: ");
		scanf("%f",&temp);
		s[i].bee=temp;

		printf("\n Enter the psc mark: ");
		scanf("%f",&temp);
		s[i].psc=temp;

		calculateGrade(i);

	}

}

void calculateGrade(int i)
{
	s[i].total=s[i].maths+s[i].bee+s[i].psc;
	s[i].per=s[i].total/3;

	if(s[i].per>=90)
	{
		s[i].grade='A';
	}
	else if(s[i].per>=80)
	{
		s[i].grade='B';
	}
	else if(s[i].per>=70)
	{
		s[i].grade='C';
	}
	else if(s[i].per>=60)
	{
		s[i].grade='D';
	}
	else if(s[i].per>=50)
	{
		s[i].grade='E';
	}
	else
	{
		s[i].grade='F';
	}

}

void displayStudentDetails()
{
	int i;
	printf("\n Stu_ID\tName\tTotal\tPer\tGrade");
	for(i=0;i<SIZE;i++)
	{

		printf("\n %d\t %s\t %.2f\t %.2f\t %c",s[i].sid,s[i].name,s[i].total,s[i].per,s[i].grade);
	}




}