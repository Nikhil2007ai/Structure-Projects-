#include<stdio.h>
#define SIZE 5
#include<string.h>
#include<stdlib.h>

struct Hotel
{
  int roomNumber;
  char roomType[30];
  float pricePerNight;
  char isBooked[3];
  int flag;
                
}h[SIZE];


void create();
void display();
int search(int rnum);
void del(int rnum);
void update(int i);
int findStatusOfRoom(int rnum);
void displayParticular(int i);


void main()
{
    int choice,rnum,index,result;
    
    
    while(1)
    {
    printf("\n----------------------------------------------------\n");
    printf("\t HOTEL ROOM MANAGEMENT \t");
    printf("\n----------------------------------------------------\n");
    
    printf("\n1---To Scan Hotel Details");
    printf("\n2---To Display Hotel Details");
    printf("\n3---To Search Hotel Details");
    printf("\n4---To Delete Hotel Details");
    printf("\n5---To Update Hotel Details");
    printf("\n6---To Know the availability of Room");
    printf("\n7---Exit");
    
    printf("\nEnter any number (1-7) to Perform the required operation::");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:create();
               break;
               
        case 2:display();
               break;
               
        case 3:printf("\nEnter the Room Number to search::");
               scanf("%d",&rnum);
               
               index=search(rnum);
               
               if(index==-1)
               {
               
                  printf("\n No Record Found!!!");
               }
               
               else
               {
                      displayParticular(index);          
               }
               break;
               
        case 4:printf("\nEnter the Room Number to Delete::");
               scanf("%d",&rnum);
               
               del(rnum);
               break;
               
        case 5:printf("\nEnter the Room Number to Update::");
               scanf("%d",&rnum);
               
               index=search(rnum);
               
               if(index==-1)
               {
               
                  printf("\n No Record Found!!!");
               }
               
               else
               {
                      update(index);          
               }
               break;
               
        case 6:printf("\nEnter the Room Number to Know the Availability:: ");
               scanf("%d",&rnum);
        
               result=findStatusOfRoom(rnum);
               
               if(result==-1)
               {
                    printf("%d Room Number is Booked!!!Sorry",rnum);
               
               }
               
               else
               {
                  printf("%d Room Number is Available for Booking!!!",rnum);
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
    printf("\n============Room %d Details===============\n",i+1);
    
    printf("\nEnter the Room Number:");
    scanf("%d",&h[i].roomNumber);
    
    printf("\nEnter the Room Type:");
    scanf("%s",h[i].roomType);
    
    printf("\nEnter the Price per Night:");
    scanf("%f",&h[i].pricePerNight);
    
    printf("\nEnter the Room Availability(yes or no):");
    scanf("%s",h[i].isBooked);
    
    h[i].flag=1;
  
  
  
  }


}


void display()
{
    int i;
    
    printf("\n---------------------------------------------------------------\n");
    
    printf("\nRoom No.\tRoom Type\tPrice/night\tAvailability\n");
    
     printf("\n---------------------------------------------------------------\n");
    
    
    
    for(i=0;i<SIZE;i++)
    {
        if(h[i].flag!=-1)
        {
        printf("\n%d\t\t%s\t\t%.2f\t\t %s",h[i].roomNumber,h[i].roomType,h[i].pricePerNight,h[i].isBooked);
        
        }
    
    }

}

void displayParticular(int i)
{

     if(h[i].flag!=-1)
     {

         printf("\nRoom No.\tRoom Type\tPrice/night\tAvailability\n");
     
         printf("\n%d\t\t%s\t\t%.2f\t\t %s",h[i].roomNumber,h[i].roomType,h[i].pricePerNight,h[i].isBooked);
     
    
     }
      
     else
     {
        printf("\nNo Record Found!!!");
     
     }

}

int search(int rnum)
{
    int i;
    
    for(i=0;i<SIZE;i++)
    {
      if(h[i].roomNumber==rnum && h[i].flag!=-1)
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
  printf("\n1---Room Number");
  printf("\n2---RoomType");
  printf("\n3---Price Per Night");
  printf("\n4---Availability");
  
  printf("\nEnter the Number(1-4) for update:");
  scanf("%d",&choice);
  
  switch(choice)
  { 
      case 1:printf("\nThe Previous Details---->\n");
            displayParticular(i);
            
            printf("\nEnter the New Room Number:");
            scanf("%d",&h[i].roomNumber);
            
            printf("\nThe Updated Details---->\n");
            displayParticular(i);
            
            printf("\nSuccessfully Updated!!");
            break;
            
      case 2:printf("\nThe Previous Details---->\n");
            displayParticular(i);
            
            printf("\nEnter the New Room Type:");
            scanf("%s",h[i].roomType);
            
            printf("\nThe Updated Details---->\n");
            displayParticular(i);
            
            printf("\nSuccessfully Updated!!");
            break;
            
      case 3:printf("\nThe Previous Details---->\n");
            displayParticular(i);
            
            printf("\nEnter the New Price per Night:");
            scanf("%f",&h[i].pricePerNight);
            
            printf("\nThe Updated Details---->\n");
            displayParticular(i);
            
            printf("\nSuccessfully Updated!!");
            break;
            
      case 4:printf("\nThe Previous Details---->\n");
            displayParticular(i);
            
            printf("\nEnter the New Availability(yes or no):");
            scanf("%s",h[i].isBooked);
            
            printf("\nThe Updated Details---->\n");
            displayParticular(i);
            
            printf("\nSuccessfully Updated!!");
            break;
            
            
  
  
  
  }



}

void del(int rnum)
{
  int ind;
  
  ind=search(rnum);
  
  if(ind!=-1)
  {
  
      h[ind].flag=-1;
      
      printf("\nSuccessfully Deleted!!!");
  
  }
  
  else
  {
      printf("\nNo Record Found to be Deleted!!!");
  }



}


int findStatusOfRoom(int rnum)
{

    int ind;
    
    ind=search(rnum);
    
    if(ind!=-1)
    {
    
        if(strcmp(h[ind].isBooked,"yes")==0)
        {
            return 1;
        }
        
        else
        {
          return -1;
        }
    
    
    }
    
    {
    
        printf("\nNo such Room Number exists!!");
    
    }

}




