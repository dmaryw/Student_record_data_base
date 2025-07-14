#include"header.h"
int main() {
	struct st *hptr = 0;
	int n;
	char op,ch;
	while(1){
		printf("---------------------------------\n");
		printf("|     STUDENT  RECORD  MENU     |\n");
		printf("---------------------------------\n");
		printf("|    a/A: Add new record        |\n");
		printf("|    d/D: Delete a record       |\n");
		printf("|    p/P: Display the record    |\n");
		printf("|    m/M: Sort the record       |\n");
		printf("|    f/F: Save the record       |\n");
		printf("|    e/E: Exit                  |\n");
		printf("|    s/S: Modify the record     |\n");
		printf("|    t/T: Delete all records    |\n");
		printf("|    r/R: Reverse all records   |\n");
		printf("---------------------------------\n");

		printf("Enter your choice : ");
		scanf(" %c",&ch);
		switch (ch) {
			case 'a':
			case 'A':
				do {
					add_begin(&hptr);
					printf("Do you want to add another record (Y/N)? ");
					scanf(" %c", &op);
				} while (op == 'Y' || op == 'y');
				break;

			case 'd':
			case 'D':{
					 int choice;
					 printf("Delete by:\n");
					 printf("1. Roll Number\n");
					 printf("2. Name\n");
					 printf("3. Marks\n");
					 printf("Enter your choice: ");
					 scanf("%d", &choice);

					 if (choice == 1) {
						 int roll_num;
						 printf("Enter roll number to delete: ");
						 scanf("%d", &roll_num);
						 del_by_roll(&hptr, roll_num);
					 }
					 else if (choice == 2) {
						 char name[20];
						 printf("Enter name to delete: ");
						 scanf("%s", name);
						 del_by_name(&hptr, name);
					 }
					 else if (choice == 3) {
						 float marks;
						 printf("Enter marks to delete: ");
						 scanf("%f", &marks);
						 del_by_marks(&hptr, marks);
					 }
					 else {
						 printf("Invalid choice.\n");
					 }
					 break;
				 }

			case 'p':
			case 'P':
				 print(hptr);
				 break;

			case 'm':
			case 'M':
				 {
					 printf("Sort by: 1) Roll Number  2) Marks 3) Name\n");
					 int s_choice;
					 scanf("%d", &s_choice);

					 // Copy the list
					 struct st* copy = copy_list(hptr);

					 // Sort the copy
					 if (s_choice == 1)
						 copy = sort_roll(copy);
					 else if (s_choice == 2)
						 copy = sort_mark(copy);
					 else if (s_choice == 3)
						 copy = sort_name(copy);
					 else {
						 printf("Invalid sort choice.\n");
						 free_list(copy);
						 break;
					 }

					 // Print the sorted copy
					 print(copy);

					 // Free the copy
					 free_list(copy);
					 break;
				 }

			case 'f':
			case 'F':
				 save(hptr);
				 printf("Records saved to file.\n");
				 break;

			case 'e':
			case 'E':{
					 char d;
					 printf("do you want to save the file and then exit (Y/N): \n");
					 scanf(" %c",&d);
					 if(d=='Y'| d=='y'){
						 save(hptr);
						 printf("You are exiting the menu,after saving into the file.\n");
						 exit(0);
					 }
					 if(d=='N'| d== 'n'){
						 printf("You are exiting the menu.\n");
						 exit(0);
					 }
				 }

			case 's':
			case 'S':
				 modify(hptr);
				 break;

			case 't':
			case 'T':
				 del_all(&hptr);
				 printf("All records deleted.\n");
				 break;

			case 'r':
			case 'R':
				 rev_print(hptr);
				 printf("Records reversed.\n");
				 break;

			default:
				 printf("You have entered a wrong choice.\n");
		}

		int c = count(hptr);
		printf("The number of records is: %d\n", c);
	}

	return 0;
}

