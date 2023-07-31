//LIBRARY MODULE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book
{
	char booknam[1000];
	int bkid,bb;
}b[1000];					//"bkid"=>BOOK_ID(BOOK), "bb"=>

struct account		//to store users(STUDENTS)...
{
	char username[1000],password[1000],bookname[1000];
	int bk,bid;			//"bk"=>	"bid"=>BOOK_ID(ACCOUNT)...
}acc[1000];

int i=0,bookcount=4;	//i-user/STUDENT count
void view()	// to view the list of books
{
	int j,f=0;
	printf("Available Books :\n ");
	//if book is available the "bb" is 0 else 1
	for(j=0;j<=bookcount;j++)
	{
		if(b[j].bb==0)
		{
			f=1;
			printf("	%d . %s\n",j+1,b[j].booknam);
		}
	}
	if(f==0)
		printf("T-T-T-T-T-T-T-T!!!NO BOOKS AVAILABLE!!!T-T-T-T-T-T-T");
}
void issued()	//to check the list of issued
{
	int j,f=0;
	printf("\nIssued Books :\t");
	for(j=0;j<=bookcount;j++)
	{
		if(b[j].bb==1)
		{
			f=1;
			printf("	%d . %s\n",j+1,b[j].booknam);
		}
	}
	if(f==0)
		printf("\n!!!!!!!!!!!!NO BOOKS AVAILABLE!!!!!!!!!!!!!!\nT-T");
}
void Account()	//to create OR add "ACCOUNT" user(STUDENT)...
{
	printf("\nEnter Your UserName:");
	scanf("	%[^\n]",acc[i].username);
	printf("\nEnter Your Password:");
	scanf("	%[^\n]",acc[i].password);
	strcpy(acc[i].bookname," ");
	acc[i].bk=0;
	printf("\nT__T !!!!!!!!ACCOUNT CREATED SUCCESSFULLY!!!!!!! ");
	i++;
}
void adds()	//to add the book in the "struct book"
{
	printf("\nEnter Book Name:\t");
	bookcount++;
	scanf(" %[^\n]",b[bookcount].booknam);
	b[bookcount].bb=0;
	b[bookcount].bkid=1001+bookcount;
}
void issue(int s)	//to check the book is available
{
	int nn;
	for(;1;)
	{
		view();
		printf("Enter number what book you want:	");
		scanf("%d",&nn);
		if(acc[s].bk==0)
		{
			if((nn-1<=bookcount&&nn>=0) && b[nn-1].bb==0)
			{
				acc[s].bid=nn-1;
				acc[s].bk=1;
				b[nn-1].bb=1;
				printf("Take Your %s Book\n",b[acc[s].bid].booknam);
				break;
			}
			else
				printf("Enter valid Book Number:\n");
		}
		else
		{
			printf("You already have a book");
			break;
		}
	}
}
void ret(int s)//to RETURN the book 
{
	if(acc[s].bk)
	{
		printf("Thanks for RETURNING Your %s book\n",acc[s].bookname);
		strcpy(acc[s].bookname," ");	//by giving (" ") means to remove it form the list...
		acc[s].bk=0;
		b[acc[s].bid].bb=0;
	}
	else
	printf("You don't get book! '~'");
}
void Login()	//to access the library menu(ACCOUNT CREATION, ISSUE BOOK, RETURN BOOK)
{
	int f=1,l=0,sc=0;
	char na[1000],pas[1000];
	for(;f;)
	{
		f=0;
		printf("\nAccount Name:\t");
		scanf("	%[^\n]",na);		//"na"==>ACCOUNT NAME...
		printf("\nAccount Password:\t");
		scanf("	%[^\n]",pas);	//"pas"==>PASSWORD(STUDENT)....
		for(l=0;l<i;l++)
		{
			if(!strcmp(acc[l].username,na)&&!strcmp(acc[l].password,pas))	//checking "ACCOUNT" login
			{
				f=1;	
				break;
			}
		}
		if(f)							//TO BREAKS/CANCELS  THE ACCOUNT LOGIN....
			break;
		else   							//FOR INVALID ACCOUNT LOGIN and re-asks the user to login in account...
		{
			printf("Invalid Login\n");
			break;
		}
	}
	for(;f;)				//AFTER BREAK(i.e.=>f=1) it goes for the ACCOUNT(STUDENT)PURPOSES...
	{
		printf("1 for get book \t 2 for return book \t 3 for Exit\n");
		scanf("%d",&sc);
		if(sc==1)
		{
			issue(l);		//"issue()"==>separate function for "ISSUE" a book at student site...
		}
		else if(sc==2)
		{
			ret(l);			//"ret()"==>separate function for "RETURNING" a book at student site...
			
		}
		else if(sc==3)
		{
			f=0;		//"EXIT" the above for loop...
			
		}
	}
}
int main()
{
	int choice=0,c=0,ac;
	char s[1000];
	strcpy(b[0].booknam,"Tale of Uzumaki Naruto");
	strcpy(b[1].booknam,"Tale of Jiraya The GALLANT");
	strcpy(b[2].booknam,"Highschool D X D");
	strcpy(b[3].booknam,"Your Lie in April");
	strcpy(b[4].booknam,"I want to eat YOUR PANCREAS");
	b[0].bb=0;
	b[1].bb=0;
	b[2].bb=0;
	b[3].bb=0;
	b[4].bb=0;
	b[0].bkid=1001;
	b[1].bkid=1002;
	b[2].bkid=1003;
	b[3].bkid=1004;
	b[4].bkid=1005;
	printf("********************\n*Welcome to Library*\n********************");
	while(1)
	{
	//CHOICE MAINLY FOR USER SELECTION...
	printf("\n1 FOR STUDENTS \t 2 FOR ADMIN \t 3 FOR EXIT:\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		while(1)
		{
			printf("\n1 FOR LOGIN \t 2 FOR CREATE ACCOUNT \t 3 FOR EXIT\n");
				scanf("%d",&c);//"c"==>FOR PURPOSE OF THE STUDENTS... 
				if(c==1)
				{
					Login();	//"login()"==> FOR ACCOUNT LOGIN
				}
				else if(c==2)
				{
					Account();	//"account()"==> FOR ACCOUNT CREATION
					i++;
				}
				else if(c==3)
				{
					printf("--------THANK YOU!!!!!!!!!!\n");	//EXIT THE "while(1)" loop
					break;
				}
		}
	}
	else if(choice==2)
	{
		for(;1;)
		{
			printf("\nEnter ADMIN password:\t");
			scanf(" %[^\n]",s);
			if(!strcmp("T4TEQ",s))	//strcmp()==>compares the password,if its true it displays ("0") , so we take (!strcmp==>i.e.=>for getting ("1"))
			{
				for(;1;)
				{
					printf("\n1	FOR ADD BOOK \t2FOR VIEW BOOK \t3FOR ISSUED BOOK \t4FOR EXIT\n");
					scanf("%d",&ac);	//"ac"==>FOR "ADMIN'S" CHOICE OF ADDING, VIEWING, ISSUING AND EXITING FORM THE ADMIN SESSION...
					if(ac==1)
					{
						adds();			//"adds()"==>for adding a book(ADMIN)
					}
					else if(ac==2)
					{
						view();			//"view()"==>for viewing a book(ADMIN)
					}
					else if(ac==3)
					{
						issued();		//"issued()"==>for issue a book(ADMIN)
					}
					else if(ac==4)
					{
						printf("\n!!!!!!THE ADMIN SESSION IS EXITED!!!!!");
						break;
					}
				}
				break;
			}
			else
				printf("\n!!!!!You have entered a INVALID PASSWORD!!!!!!!");
		}
	}
			else if(choice==3)
			{
				printf("\n!!!!!!THE LIBRARY MODULE ENDED!!!!!!!\n:)");	//"choice=3"==>FOR EXIT TOTAL MODULE...
				break;
			}
	}
return 0;
}

