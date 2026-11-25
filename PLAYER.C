/*
	Name:Nikhil Shee
	Doc:19 Nov 2026
	Obj:Players Details
*/

#include<stdio.h>
#include<conio.h>
#define SIZE 5

struct player
{
	int pId;
	char pName[30];
	int t_score;
	int T_score;
	int total;
	float avg;
	int flag;
}p[SIZE];

void scanPlayers();
void displayPlayers();
void displayParticularPlayer(int i);
void total(int i);
void avg(int i);
int search(int id);
void update(int i);
void del(int id);

void main()
{
	int choice;
	int id,index;
	clrscr();

	while(1)
	{
		printf("\n=========Player Score Details==========\n");
		printf("\n1---Scan Players");
		printf("\n2---Display Players");
		printf("\n3---Search Players");
		printf("\n4---Update Players");
		printf("\n5---Delete Players");
		printf("\n6---Exit");

		printf("\nEnter what you want to do(1-6):");
		scanf("%d",&choice);

		switch(choice)
		{

			case 1:scanPlayers();
			       break;

			case 2:displayPlayers();
			       break;

			case 3:printf("\nEnter the Id to Search:");
			       scanf("%d",&id);
			       index=search(id);

			       if(index==-1)
			       {
					printf("\nNo Record Found!!");
			       }
			       else
			       {
					displayParticularPlayer(index);

			       }
			       break;
			case 4:printf("\nEnter the Id to Update:");
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

			case 5:printf("\nEnter Id to Delete:");
			       scanf("%d",&id);
			       del(id);
			       break;

			case 6:exit(0);

			default:printf("\nInvalid Choice!!!");








		}

	}
	getch();

}

void scanPlayers()
{
	int i;

	for(i=0;i<SIZE;i++)
	{
		if(p[i].flag!=-1)
		{

		printf("\nEnter PlayerID:");
		scanf("%d",&p[i].pId);

		printf("\nEnter Player Name:");
		scanf("%s",p[i].pName);

		printf("\nEnter T20 Score:");
		scanf("%d",&p[i].t_score);

		printf("\nEnter Test Score:");
		scanf("%d",&p[i].T_score);

		total(i);

		avg(i);

		p[i].flag=1;



		}
	}


}


void total(int i)
{
	p[i].total=p[i].t_score+p[i].T_score;



}

void avg(int i)
{
	float temp;

	temp=p[i].total/2;

	p[i].avg=temp;

}

void displayPlayers()
{
	int i;
	printf("\nP_ID\tP_NAME \tT20_SCORE\tTEST_SCORE\tTOTAL\tAVERAGE");
	for(i=0;i<SIZE;i++)
	{
		if(p[i].flag!=-1)
		{

			printf("\n%d\t%s \t%d\t\t%d\t\t%d\t%.2f",p[i].pId,p[i].pName,p[i].t_score,p[i].T_score,p[i].total,p[i].avg);


		}


	}




}

void displayParticularPlayer(int i)
{

	if(p[i].flag!=-1)
	{

		printf("\nP_ID\tP_NAME\tT20_SCORE\tTEST_SCORE\tTOTAL\tAVERAGE");
		printf("\n%d\t%s\t%d\t\t%d\t\t%d\t%.2f",p[i].pId,p[i].pName,p[i].t_score,p[i].T_score,p[i].total,p[i].avg);

	}

}

int search(int id)
{
	int i;
	for(i=0;i<SIZE;i++)
	{

		if(p[i].pId==id&&p[i].flag!=-1)
		{
		    return i;

		}


	}
	return -1;



}

void update(int i)
{
	int choice;

	printf("\n======Update Menu=======\n");
	printf("\n1---ID");
	printf("\n2---Name");
	printf("\n3---T20 Score");
	printf("\n4---Test Score");

	printf("\nEnter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:printf("\nThe Previous Details--->\n");
		       displayParticularPlayer(i);
		       printf("\nEnter the New Id::");
		       scanf("%d",&p[i].pId);
		       printf("\nThe Updated Details--->\n");
		       displayParticularPlayer(i);
		       break;

		case 2:printf("\nThe Previous Details--->\n");
		       displayParticularPlayer(i);
		       printf("\nEnter the New Name::");
		       scanf("%s",p[i].pName);
		       printf("\nThe Updated Details--->\n");
		       displayParticularPlayer(i);
		       break;

		case 3:printf("\nThe Previous Details--->\n");
		       displayParticularPlayer(i);
		       printf("\nEnter the New T20 score::");
		       scanf("%d",&p[i].t_score);
		       printf("\nThe Updated Details--->\n");
		       displayParticularPlayer(i);
		       break;

		case 4:printf("\nThe Previous Details--->\n");
		       displayParticularPlayer(i);
		       printf("\nEnter the New T_score::");
		       scanf("%d",&p[i].T_score);
		       printf("\nThe Updated Details--->\n");
		       displayParticularPlayer(i);
		       break;

	}


}

void del(int id)
{
	int i;
	int index;
	index=search(id);

	if(index!=-1)
	{
			p[index].flag=-1;
			printf("\nData Deleted Successfully!!!");
	}

	else
	{
			printf("\nNo Such Record!!!");
	}


}