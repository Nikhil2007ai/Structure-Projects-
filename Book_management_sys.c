#include<stdio.h>
#define SIZE 2
#include<stdlib.h>

struct Book
{
  int bookId;
  char title[30];
  char author[30];
  int availableCopies;
  int flag;
                
}b[SIZE];


void create();
void display();
int search(int bid);
void del(int bid);
void update(int i);
int isBookAvailable(int rnum);
void displayParticular(int i);


void main()
{
    int choice,bid,index,result;
    
    
    while(1)
    {
    printf("\n----------------------------------------------------\n");
    printf("\t BOOK MANAGEMENT SYSTEM\t");
    printf("\n----------------------------------------------------\n");
    
    printf("\n1---To Scan Book Details");
    printf("\n2---To Display Book Details");
    printf("\n3---To Search Book Details");
    printf("\n4---To Delete Book Details");
    printf("\n5---To Update Book Details");
    printf("\n6---To Know the availability of Book");
    printf("\n7---Exit");
    
    printf("\nEnter any number (1-7) to Perform the required operation::");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:create();
               break;
               
        case 2:display();
               break;
               
        case 3:printf("\nEnter the Book id to search::");
               scanf("%d",&bid);
               
               index=search(bid);
               
               if(index==-1)
               {
               
                  printf("\n No Record Found!!!");
               }
               
               else
               {
                      displayParticular(index);          
               }
               break;
               
        case 4:printf("\nEnter the Book id to Delete::");
               scanf("%d",&bid);
               
               del(bid);
               break;
               
        case 5:printf("\nEnter the Book id to Update::");
               scanf("%d",&bid);
               
               index=search(bid);
               
               if(index==-1)
               {
               
                  printf("\n No Record Found!!!");
               }
               
               else
               {
                      update(index);          
               }
               break;
               
        case 6:printf("\nEnter the Book id to Know the Availability:: ");
               scanf("%d",&bid);
        
               result=isBookAvailable(bid);
               
               if(result==-1)
               {
                    printf("%d Book Id is not Available!!",bid);
               
               }
               
               else
               {
                  printf("%d Book Id is Available!!!",bid);
               }
               
               break;
               
        case 7:exit(0);
        
        default:printf("\nInvalid Input(Please Enter between 1 to 7)");
        
               
    }


  }

}

void create()
{
  int i;
  for(i=0;i<SIZE;i++)
  {
    printf("\n============Book %d Details===============\n",i+1);
    
    printf("\nEnter the Book Id:");
    scanf("%d",&b[i].bookId);
    
    printf("\nEnter the Book Title:");
    scanf("%s",b[i].title);
    
    printf("\nEnter the Book Author:");
    scanf("%s",b[i].author);
    
    printf("\nEnter the Book Available Copies:");
    scanf("%d",&b[i].availableCopies);
    
    b[i].flag=1;
  
  
  
  }


}


void display()
{
    int i;
    
    printf("\n---------------------------------------------------------------\n");
    
    printf("\n Book Id \tBook Title \tBook Author \tAvailable Copies\n");
    
     printf("\n---------------------------------------------------------------\n");
    
    
    
    for(i=0;i<SIZE;i++)
    {
        if(b[i].flag!=-1)
        {
        printf("\n%d \t\t%s \t\t%s \t\t%d",b[i].bookId,b[i].title,b[i].author,b[i].availableCopies);
        
        }
    
    }

}

void displayParticular(int i)
{

     if(b[i].flag!=-1)
     {
     
         
         printf("\n---------------------------------------------------------------\n");
    
           printf("\n Book Id \tBook Title \tBook Author \tAvailable Copies\n");
    
         printf("\n---------------------------------------------------------------\n");
         
         printf("\n%d \t\t%s \t\t%s \t\t%d",b[i].bookId,b[i].title,b[i].author,b[i].availableCopies);
    

        
     
    
     }
      
     else
     {
        printf("\nNo Record Found!!!");
     
     }

}

int search(int bid)
{
    int i;
    
    for(i=0;i<SIZE;i++)
    {
      if(b[i].bookId==bid && b[i].flag!=-1)
      {
          return i;
      
      }
    
    }
    
    return -1;


}

void update(int i)
{
  int choice;
  
  printf("\n===========Update Menu============\n");
  printf("\n1---Book Id");
  printf("\n2---Book Title");
  printf("\n3---Book Author");
  printf("\n4---Available Copies");
  
  printf("\nEnter the Number(1-4) for update:");
  scanf("%d",&choice);
  
  switch(choice)
  { 
      case 1:printf("\nThe Previous Details---->\n");
            displayParticular(i);
            
            printf("\nEnter the New Book Id:");
            scanf("%d",&b[i].bookId);
            
            printf("\nThe Updated Details---->\n");
            displayParticular(i);
            
            printf("\nSuccessfully Updated!!");
            break;
            
      case 2:printf("\nThe Previous Details---->\n");
            displayParticular(i);
            
            printf("\nEnter the New Book Title:");
            scanf("%s",b[i].title);
            
            printf("\nThe Updated Details---->\n");
            displayParticular(i);
            
            printf("\nSuccessfully Updated!!");
            break;
            
      case 3:printf("\nThe Previous Details---->\n");
            displayParticular(i);
            
            printf("\nEnter the New Book Author:");
            scanf("%s",b[i].author);
            
            printf("\nThe Updated Details---->\n");
            displayParticular(i);
            
            printf("\nSuccessfully Updated!!");
            break;
            
      case 4:printf("\nThe Previous Details---->\n");
            displayParticular(i);
            
            printf("\nEnter the New Available Copies:");
            scanf("%d",&b[i].availableCopies);
            
            printf("\nThe Updated Details---->\n");
            displayParticular(i);
            
            printf("\nSuccessfully Updated!!");
            break;
            
            
  
  
  
  }



}

void del(int bid)
{
  int ind;
  
  ind=search(bid);
  
  if(ind!=-1)
  {
  
      b[ind].flag=-1;
      
      printf("\nSuccessfully Deleted!!!");
  
  }
  
  else
  {
      printf("\nNo Record Found to be Deleted!!!");
  }



}


int isBookAvailable(int bid)
{

    int ind;
    
    ind=search(bid);
    
    if(ind!=-1)
    {
    
        if(b[ind].availableCopies!=0)
        {
            return 1;
        }
        
        else
        {
          return -1;
        }
    
    
    }
    
    {
    
        printf("\nNo such Book Id exists!!");
    
    }

}




