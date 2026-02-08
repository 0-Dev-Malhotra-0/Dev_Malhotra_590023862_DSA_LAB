// 7.	Write a menu-driven C program using structure and dynamic memory allocation to add, display, delete records and free memory before exit.

#include <stdio.h>
#include <stdlib.h>

struct Record
{
    int id;
    char name[50];
};

int main()
{
    struct Record *arr = NULL;
    int count = 0;
    int choice, i, id, found;
    char o;

    while(1)
    {
        printf("Menu\n");
        printf("1. Add record\n");
        printf("2. Display records\n");
        printf("3. Delete record by ID\n");
        printf("4. Exit\n");

        printf("\nEnter choice : ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            o = 'y';
            while(o == 'y' || o == 'Y')
            {
                struct Record *temp = realloc(arr,(count+1)*sizeof(struct Record));

                if(temp == NULL)
                {
                    printf("Allocation failed\n");
                    free(arr);
                    return 1;
                }

                arr = temp;

                printf("\nEnter ID : ");
                scanf("%d",&arr[count].id);
                printf("Enter name : ");
                scanf("%s",arr[count].name);

                count++;

                printf("\nDo you want to add more (y/n) : ");
                scanf(" %c",&o);
            }
            
            printf("\n");
        }

        else if(choice == 2)
        {
            if(count == 0)
                printf("\nNo records to display.\n\n");
            
			else
            {
                printf("\nRecords :\n\n");
                for(i = 0; i < count; i++)
                    printf("ID : %d\nName : %s\n\n",arr[i].id,arr[i].name);
            }
        }

        else if(choice == 3)
        {
            if(count == 0)
            {
                printf("\nNo records to delete.\n\n");
                continue;
            }

            printf("\nEnter ID to delete : ");
            scanf("%d",&id);

            found = -1;

            for(i = 0; i < count; i++)
            {
                if(arr[i].id == id)
                {
                    found = i;
                    break;
                }
            }

            if(found == -1)
                printf("\nID not found.\n\n");
                
            else
            {
                for(i = found; i < count-1; i++)
                    arr[i] = arr[i+1];

                count--;
                arr = realloc(arr,count*sizeof(struct Record));
                printf("\nRecord deleted.\n\n");
            }
        }

        else if(choice == 4)
        {
            free(arr);
            printf("\nExiting.");
            break;
        }

        else
            printf("\nInvalid choice. Try again.\n\n");
    }

    return 0;
}

