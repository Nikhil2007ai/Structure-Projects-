/*
      Name:Nikhil Shee
      DOC:20 Nov 2026
      Obj:Vehicle Details Using Structure
*/

#include <stdio.h>
#define SIZE 5
#include <stdlib.h>

struct Vehicle
{
    int vId;
    char Name[30];
    float mil;
    char ftype[30];
    int flag;

} v[SIZE];

void scanVehicle();
void displayVehicle();
int search(int id);
void particular(int i);
void update(int i);
void del(int id);

void main()
{
    int choice, id, index;

    while (1)
    {

        printf("\n==============Vehicle Details==============\n");
        printf("\n1---Scan Vehicle Details");
        printf("\n2---Display Vehicle Details");
        printf("\n3---Search Vehicle Details");
        printf("\n4---Update Vehicle Details");
        printf("\n5---Delete Vehicle Details");
        printf("\n6---Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanVehicle();
            break;

        case 2:
            displayVehicle();
            break;

        case 3:
            printf("\nEnter the id to search:");
            scanf("%d", &id);
            index = search(id);
            if (index == -1)
            {
                printf("\nNo Record Found!!");
            }
            else
            {
                particular(index);
            }
            break;

        case 4:
            printf("\nEnter the id to update:");
            scanf("%d", &id);
            index = search(id);
            if (index == -1)
            {
                printf("\nNo Record Found!!");
            }
            else
            {
                update(index);
            }
            break;

        case 5:
            printf("\nEnter the id to delete:");
            scanf("%d", &id);
            del(id);
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid Choice!!!");
        }
    }
}

void scanVehicle()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter Vehicle ID=");
        scanf("%d", &v[i].vId);

        printf("\nEnter Vehicle Name=");
        scanf("%s", v[i].Name);

        printf("\nEnter Fuel Type:");
        scanf("%s", v[i].ftype);

        printf("\nEnter Mileage=");
        scanf("%f", &v[i].mil);

        v[i].flag = 1;
    }
}

void displayVehicle()
{
    int i;

    printf("\n----------------------------------------------------");
    printf("\nV_ID\tV_NAME\t\tV_FTYPE\t\tV_MILEAGE");
    printf("\n----------------------------------------------------");

    for (i = 0; i < SIZE; i++)
    {
        if (v[i].flag != -1)
        {
            printf("\n%d\t%s\t\t%s\t\t%.2f", v[i].vId, v[i].Name, v[i].ftype, v[i].mil);
        }
    }
}

int search(int id)
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        if (v[i].vId == id && v[i].flag != -1)
        {
            return i;
        }
    }
    return -1;
}

void particular(int i)
{
    if (v[i].flag != -1)
    {
        printf("\nV_ID\tV_NAME\tV_FTYPE\tV_MILEAGE");
        printf("\n%d\t%s\t%s\t%.2f", v[i].vId, v[i].Name, v[i].ftype, v[i].mil);
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
    printf("\n3---Fuel Type");
    printf("\n4---Mileage");

    printf("\nEnter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nThe Previous Details are--->\n");
        particular(i);
        printf("\nEnter New Vehicle ID:");
        scanf("%d", &v[i].vId);
        printf("\nThe New Details are--->\n");
        particular(i);
        break;

    case 2:
        printf("\nThe Previous Details are--->\n");
        particular(i);
        printf("\nEnter New Vehicle Name:");
        scanf("%s", v[i].Name);
        printf("\nThe New Details are--->\n");
        particular(i);
        break;

    case 3:
        printf("\nThe Previous Details are--->\n");
        particular(i);
        printf("\nEnter New Fuel Type:");
        scanf("%s", v[i].ftype);
        printf("\nThe New Details are--->\n");
        particular(i);
        break;

    case 4:
        printf("\nThe Previous Details are--->\n");
        particular(i);
        printf("\nEnter New Mileage:");
        scanf("%.2f", &v[i].mil);
        printf("\nThe New Details are--->\n");
        particular(i);
        break;

    default:
        printf("\nInvalid Choice!!!");
        break;
    }
}

void del(int id)
{
    int index;

    index = search(id);

    if (index == -1)
    {
        printf("\nRecord Not Found!!!");
    }

    else
    {
        v[index].flag = -1;
        printf("\nRecord Deleted Successfully");
    }
}