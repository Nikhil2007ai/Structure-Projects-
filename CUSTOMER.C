#include<stdio.h>
#include<conio.h>

void scan(int custid,char custName[],float fees);

void display(int custid,char custName[],float fees);


void main()
{
	int cid;
	float fees;
	char custName[30];
	clrscr();


	printf("\nEnter cid:");
	scanf("%d",&cid);

	printf("\nEnter fees:");
	scanf("%f",&fees);

	printf("\nEnter customer Name: ");
	scanf("%s",custName);

	display(cid,custName,fees);




   getch();


}

void display(int custid,char custName[],float fees)
{

	printf("\n========Customer Details=========\n");
	printf("\nCustomer ID=%d",custid);
	printf("\nCustomer Name=%s",custName);
	printf("\nCustomer fees=%.2f",fees);




}


void scan(int custid,char custName[],float fees)
{

	return;


}