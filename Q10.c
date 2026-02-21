/* 10.	Write a C program to maintain Student Records using a Linked List. 
Each node should store student details such as roll number, name, and marks. 
Implement operations to insert, delete, search, and display records. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    int roll;
    char name[50];
    float marks;
    struct student *next;
};

void insert(struct student **start)
{
    struct student *newnode = malloc(sizeof(struct student));

    printf("Enter Roll Number: ");
    scanf("%d",&newnode->roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", newnode->name);

    printf("Enter Marks: ");
    scanf("%f",&newnode->marks);

    newnode->next = NULL;

    if(*start == NULL)
    {
        *start = newnode;
    }
    else
    {
        struct student *ptr = *start;
        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = newnode;
    }

    printf("Record Inserted Successfully.\n");
}

void deleteStudent(struct student **start)
{
    if(*start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d",&roll);

    struct student *ptr = *start;
    struct student *prev = NULL;

    if(ptr->roll == roll)
    {
        *start = ptr->next;
        free(ptr);
        printf("Record Deleted.\n");
        return;
    }

    while(ptr != NULL && ptr->roll != roll)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("Record not found.\n");
        return;
    }

    prev->next = ptr->next;
    free(ptr);

    printf("Record Deleted.\n");
}

void searchStudent(struct student *start)
{
    if(start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d",&roll);

    while(start != NULL)
    {
        if(start->roll == roll)
        {
            printf("\nRecord Found:\n");
            printf("Roll: %d\n", start->roll);
            printf("Name: %s\n", start->name);
            printf("Marks: %.2f\n", start->marks);
            return;
        }
        start = start->next;
    }

    printf("Record not found.\n");
}

void display(struct student *start)
{
    if(start == NULL)
    {
        printf("No records available.\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while(start != NULL)
    {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               start->roll,
               start->name,
               start->marks);
        start = start->next;
    }
}

int main()
{
    struct student *start = NULL;
    int choice = 0;

    while(choice != 5)
    {
        printf("------ Student Record Menu ------\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
				insert(&start);
				break;
            case 2: 
				deleteStudent(&start); 
				break;
            case 3: 
				searchStudent(start); 
				break;
            case 4: 
				display(start); 
				break;
            case 5: 
				break;
            default: 
				printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}
