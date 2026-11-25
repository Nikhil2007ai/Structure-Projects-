#include<stdio.h>
#include<conio.h>
#define SIZE 2

struct Fruit
{
	int fruitid;
	char fruitname[30];
	float price;
	float weight;

}f[SIZE];

void scanFruitDetails();
void displayFruitDetails();

void main()
{
	int choice;
	clrscr();

	while(1)
	{
	printf("\n=========Fruit Details===========\n");
	printf("\n1---ScanFruitDetails");
	printf("\n2---DisplayFruitDetails");
	printf("\n3---Exit");

	printf("\nEnter your Choice:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:scanFruitDetails();
			break;
		case 2:displayFruitDetails();
			break;

		case 3:exit(0);
			break;
		default:printf("\nInvalid Choice!!!");

	}

    }
	getch();
}

void scanFruitDetails()
{
	int i;
	float temp;

	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter FruitId:");
		scanf("%d",&f[i].fruitid);

		printf("\nEnter FruitName:");
		scanf("%s",f[i].fruitname);

		printf("\nEnter Fruit Price:");
		scanf("%f",&temp);
		f[i].price=temp;

		printf("\nEnter Fruit Weight:");
		scanf("%f",&temp);
		f[i].weight=temp;

	}

}

void displayFruitDetails()
{
	int i;
	printf("\nFruit_ID\tFruit_Name\tPrice\t\tWeight");

	for(i=0;i<SIZE;i++)
	{
		printf("\n%d\t\t%s\t\t%.2f\t\t%.2f",f[i].fruitid,f[i].fruitname,f[i].price,f[i].weight);

	}



}