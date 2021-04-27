#include "Library.h"
#include <string.h>

void addLib();
void workTime();
void addBook();
void isExist();
void borrowBook();
void returnBook();
void printBooks();
void printAuthorBook();

Library lib("", "", 0, 0, 0, 0);
int main()
{
	printf("1: Add library\n");
	printf("2: Working time of library\n");
	printf("3: Add book to specific library\n");
	printf("4: Is exist a specific book?\n");
	printf("5: Borrow book\n");
	printf("6: Return book\n");
	printf("7: print books information\n");
	printf("8: Print all author books\n");
	printf("9: exit\n\n");
	int i = -1;
	while (i != 0)
	{
		scanf("%d", &i);
		getchar();
		switch (i)
		{
		case 1:
			addLib();
			break;
		case 2:
			workTime();
			break;
		case 3:
			addBook();
			break;
		case 4:
			isExist();
			break;
		case 5:
			borrowBook();
			break;
		case 6:
			returnBook();
			break;
		case 7:
			printBooks();
			break;
		case 8:
			printAuthorBook();
			break;
		case 9:
			exit(0);
		}
	}
}

void addLib()
{
	char libName[30], address[150];
	int start, end, found, staff;
	printf("Lib name: ");
	scanf("%[^\n]s", libName);
	getchar();
	printf("Lib address: ");
	scanf("%[^\n]s", address);
	getchar();
	printf("Lib start time: ");
	scanf("%d", &start);
	printf("Lib end time: ");
	scanf("%d", &end);
	printf("Lib found year: ");
	scanf("%d", &found);
	printf("Lib staff num: ");
	scanf("%d", &staff);
	Library *temp = new Library(libName, address, start, end, found, staff);
	lib = *temp;
	printf("Library added successfully\n\n");
}

void workTime()
{
	int t;
	printf("Input your time that you want to go there: ");
	scanf("%d", &t);
	lib.isOpen(t) ? printf("%s is open now\n", lib.getName()) : printf("%s is close now\n", lib.getName());
}

void addBook()
{
	char nameBook[30], Aname[40], Aemail[50];
	int publish, num, Agender;
	printf("Name of book: ");
	scanf("%[^\n]s", nameBook);
	getchar();
	printf("Publish year: ");
	scanf("%d", &publish);
	getchar();
	printf("Name of author: ");
	scanf("%[^\n]s", Aname);
	getchar();
	printf("Gender of author (1:Mail)(0:Femail): ");
	scanf("%d", &Agender);
	getchar();
	printf("Email of author: ");
	scanf("%[^\n]s", Aemail);
	getchar();
	printf("Number of new books: ");
	scanf("%d", &num);
	getchar();
	Book *a = new Book(nameBook, publish, Author(Aname, Agender, Aemail), num);
	lib.addBook(a);
	printf("%s added successfully\n", nameBook);
}

void isExist()
{
	char str[50];
	printf("Input your name book: ");
	scanf("%[^\n]s", str);
	getchar();
	lib.isExistBook(str) ? printf("%s is exist now\n", str) : printf("%s is not exist now\n", str);
}

void borrowBook()
{
	char str[50];
	printf("Input your name book: ");
	scanf("%[^\n]s", str);
	getchar();
	lib.lendBook(str) ? printf("%s lend you successfully\n", str) : printf("%s is not exist now\n", str);
}

void returnBook()
{
	char str[50];
	printf("Input your name book: ");
	scanf("%[^\n]s", str);
	getchar();
	lib.returnBook(str) ? printf("%s returned successfully\n", str) : printf("%s does not belonging to this library\n", str);
}

void printBooks()
{
	lib.printBooks();
}

void printAuthorBook()
{
	char str[50];
	printf("Input author: ");
	scanf("%[^\n]s", str);
	getchar();
	lib.printAuthorsBook(str);
}
