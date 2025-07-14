#include "header.h"
void modify(struct st *hptr)
{
	int choice;
	printf("Modify by:\n");
	printf("1. Roll Number\n");
	printf("2. Name\n");
	printf("3. Marks\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	int roll_no;
	struct st* ptr; 
	char name[20];
	float mark;
	int found = 0;

	switch (choice)
	{
		case 1:
			printf("Enter Roll Number to modify: ");
			scanf("%d", &roll_no);

			ptr = hptr;
			while (ptr)
			{
				if (ptr->roll_num == roll_no)
				{
					printf("Enter new name and marks: ");
					scanf("%s %f", ptr->name, &ptr->marks);
					printf("Record updated successfully!\n");
					print(hptr);
					return;
				}
				ptr = ptr->nxt;
			}
			printf("No record found with roll number %d\n", roll_no);
			break;

		case 2:
			printf("Enter name to modify: ");
			scanf("%s", name);

			ptr = hptr;
			found = 0;
			printf("\nMatching records with name \"%s\":\n", name);
			printf("---------------------------------------------------\n");
			printf("Roll No\tName\t\tMarks\n");
			printf("---------------------------------------------------\n");

			while (ptr)
			{
				if (strcmp(ptr->name, name) == 0)
				{
					printf("%d\t%s\t\t%.2f\n", ptr->roll_num, ptr->name, ptr->marks);
					found = 1;
				}
				ptr = ptr->nxt;
			}

			if (!found)
			{
				printf("No student found with name %s\n", name);
				return;
			}

			printf("\nEnter the roll number of the record you want to modify: ");
			scanf("%d", &roll_no);

			ptr = hptr;
			while (ptr)
			{
				if (ptr->roll_num == roll_no && strcmp(ptr->name, name) == 0)
				{
					printf("Enter new name and marks: ");
					scanf("%s %f", ptr->name, &ptr->marks);
					printf("Record updated successfully!\n");
					print(hptr);
					return;
				}
				ptr = ptr->nxt;
			}
			printf("No matching roll number found for name %s.\n", name);
			break;

		case 3:
			printf("Enter marks to modify: ");
			scanf("%f", &mark);

			ptr = hptr;
			found = 0;
			printf("\nMatching records with marks %.2f:\n", mark);
			printf("---------------------------------------------------\n");
			printf("Roll No\tName\t\tMarks\n");
			printf("---------------------------------------------------\n");

			while (ptr)
			{
				if (ptr->marks == mark)
				{
					printf("%d\t%s\t\t%.2f\n", ptr->roll_num, ptr->name, ptr->marks);
					found = 1;
				}
				ptr = ptr->nxt;
			}

			if (!found)
			{
				printf("No student found with marks %.2f\n", mark);
				return;
			}

			printf("\nEnter the roll number of the record you want to modify: ");
			scanf("%d", &roll_no);

			ptr = hptr;
			while (ptr)
			{
				if (ptr->roll_num == roll_no && ptr->marks == mark)
				{
					printf("Enter new name and marks: ");
					scanf("%s %f", ptr->name, &ptr->marks);
					printf("Record updated successfully!\n");
					print(hptr);
					return;
				}
				ptr = ptr->nxt;
			}
			printf("No matching roll number found with marks %.2f.\n", mark);
			break;

		default:
			printf("Invalid option.\n");
	}
}

