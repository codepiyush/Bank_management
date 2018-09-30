
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include<conio.h>
#define MAX 3

void Login_Logs();
void menu();
void create();
void update();
void transact();
void view_det();
void del();
void all_list();
void close();
void choose();
void delay(int);
int i,j;
char mex;
struct date{
    int mm,dd,yy;
    };
struct acct{

    char name[60];
    int acc_no,age;
    char address[60];
    char addhar[15];
    double mobile;
    char acc_type[10];
    float amt;
    char password[8];
    struct date dob,track;
    
    }user,chng,check,rem,tran,transfer1,transfer2;


    char user_log[MAX][10], data[10];
    int top=-1;
    int push(char user_log[MAX][10], int *top, char data[10])
{
    if(*top == MAX -1)
        return(-1);
    else
    {
        *top = *top + 1;
        strcpy(user_log[*top], data);
        return(1);
    }
}

int main()
{system("color F2");
    char empnmae[10];
    char pass[10],password[10]="12345";
    int i=0;
    login:
    printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n\n\n");
    printf("\t\t\t\t                       | OWNERS |\n\n");
    printf("\t\t\t\t |-------------|    |---------------|    |-------------|\n");
    printf("\t\t\t\t |   PIYUSH    |    |     LALIT     |    |     AVI     |\n");
    printf("\t\t\t\t |-------------|    |---------------|    |-------------|\n");

	printf("\n\n\n\t\tEnter Username: ");
    scanf("%s",empnmae);
    if(strcmpi(empnmae,"lalit")==0 || strcmpi(empnmae,"avi")==0 || strcmpi(empnmae,"piyush")==0)
    {
        push(user_log,  &top, empnmae);
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t");
        char a=177,b=178;
        printf("Loading.....");
        printf("\n\n");
        printf("\t\t\t\t\t");
        for(i=0;i<30;i++)
        {
            printf("%c",a);
        }
        printf("\r");
        printf("\t\t\t\t\t");
        for(i=0;i<30;i++)
        {
            delay(39999977);
            printf("%c",b);

        }

                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&mex);
            if (mex==1)
                    {

                        system("cls");
                        main();
                    }

            else if (mex==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid Choice!");
                    delay(1000000000);
                    system("cls");
                    goto login_try;}

        }
    }
    else
    {
    	printf("\t\t\t\tInvalid Username\a\a\a");
    	delay(1000000000);
		system("cls");
    	goto login;
	}
        return 0;
}
void Login_Logs()
{printf("\n\n\t\t\t\t\tPeople who logined are:\n");
    int j;
    for(j=0;j<=top;j++)
    {
        printf("\n\t\t\t\t\t%d. %s",j+1,user_log[j]);
    }
    printf("\npress 1 to go to main menu, 0 to exit");
    char ch=getche();
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
	}

}

void delay(int j)
{   int i;
    for(i=0;i<j;i++)
    {
    	
	}
         
}

void create()

{
    int choice;
    FILE *ptr;
    ptr=fopen("record.dat","a+");
    start:
    system("cls");
     printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n");

    printf("\n\n\n\t\t\t\t\t\t      ADD RECORD  \n\n\n");
   time_t now = time(NULL);
   struct tm *t = localtime(&now);
   user.track.mm=t->tm_mon+1;
   user.track.dd=t->tm_mday;
   user.track.yy=t->tm_year+1900;
   printf("\ntoday's date: %d-%d-%d",t->tm_mday,t->tm_mon+1,t->tm_year+1900);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
    {
        if (check.acc_no==user.acc_no)
            {
		printf("\n\nAccount no. already in use!\n\n");
            	delay(1000000000);
                goto start;
            }
    }
    user.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",user.name);
    printf("\nEnter the date of birth(dd-mm-yyyy):");
    scanf("%d-%d-%d",&user.dob.dd,&user.dob.mm,&user.dob.yy);
    user.age=(user.track.yy)-(user.dob.yy);
    printf("\nYour age is: %d",user.age);
    printf("\nEnter the CITY:");
    scanf("%s",user.address);
    printf("\nEnter the addhar number:");
    scanf("%s",user.addhar);
    printf("\nEnter the mobile number: ");
    scanf("%lf",&user.mobile);
    printf("\nEnter the amount to deposit:Rs. ");
    scanf("%f",&user.amt);
    printf("\nType of account:\n\t->Saving\n\t->Current\n\t->Fixed1(for 1 year)\n\t->Fixed2(for 2 years)\n\t->Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",user.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);


    fclose(ptr);
    printf("\nAccount created successfully!");
    create_error:
   printf("\npress 1 to go to main menu, 0 to exit");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
    default : goto create_error;
    break;
	}

}
void all_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int flag=0;
    system("cls");
    printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n\n");

    printf("\nACC. NO.\t\tNAME\t\t\tADDRESS\t\t\tMOBILE\t\t\tBALANCE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
       {
           printf("\n%6d\t\t %10s\t\t    %10s\t\t\t%.0lf\t\t\t%.2f",user.acc_no,user.name,user.address,user.mobile,user.amt);
           flag++;
       }

    fclose(view);
    if (flag==0)
        {   system("cls");
            printf("\nNO DETAIL FOUND. CREATE ACCOUNT FIRST!!\n");}

    all_list_invalid:
     printf("\nPress 1 to go to main menu, 0 to exit");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
    default : goto all_list_invalid;
    break;
	}
}


void update(void)
{ printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n\n\n");

    int choice,flag=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer:  ");
    scanf("%d",&chng.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
    {
        if (user.acc_no==chng.acc_no)
        {   flag=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Mobile\n\nEnter your choice(1 for address and 2 for mobile):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",chng.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,chng.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
                system("cls");
                printf("Address Saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new mobile number:");
                scanf("%lf",&chng.mobile);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,chng.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
                system("cls");
                printf("Mobile number saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(flag!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            update_invalid:
              printf("\npress 1 to go to main menu, 0 to exit, 2 to try again");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
          break;
    case '0':
    	system("cls");
	    close();
        break;
    case '2':
        	update();
        	break;
    default : goto update_invalid;
    break;
	}
        }
    else
    {startss:
		printf("\npress 1 to go to main menu, 0 to exit");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
    default : goto startss;
    break;
	}
        }
}

void txn(void)
{   printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n\n\n");

	int choice,test=0;
    FILE *old,*newrec,*tra;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    int choice1,count=0;
    printf("What do you prefer:\n\n1.Cash transaction\n2.Account transfer\n\nEnter your choice: ");
    scanf("%d",&choice1);
    if(choice1==1)
    {printf("Enter the account no. of the customer:");
    scanf("%d",&tran.acc_no);
       while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
       {

            if(user.acc_no==tran.acc_no)
            {   test=1;
                if(strcmpi(user.acc_type,"fixed1")==0||strcmpi(user.acc_type,"fixed2")==0||strcmpi(user.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT TRANSACT CASH IN FIXED TYPE ACCOUNTS!!!!!");
                   printf("Press any key");
				   getch();
                   system("cls");
                    menu();
                }
					printf("\n\nDo you want to\n1.Deposit\n2.Withdraw\n\nEnter choice:");
    	            scanf("%d",&choice);
        	        if (choice==1)
            	    {
                	    printf("Enter the amount to deposit:Rs ");
                    	scanf("%f",&tran.amt);
	                    user.amt+=tran.amt;
    	                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
        	            printf("\n\nsuccess!");
            	    }
                	else if(choice==2)
                	{
                    	printf("Enter the amount to withdraw:Rs ");
	                    scanf("%f",&tran.amt);
    	                if(user.amt>tran.amt)
        	            {
							user.amt-=tran.amt;
                	    	fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
                    		printf("\n\n success!");
						}
						else
						{
							system("cls");
							printf("\n\n\n\t\t\t\t\t    WARNING!\a\aCannot Withdraw amount more than Balance\n");
							printf("press any key to try again");
							getch();
							system("cls");
							txn();
						}
                	}
			}
        
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
            }
       }
   }
	else if(choice1==2)
    {
    	test=1;
    	if(strcmpi(user.acc_type,"fixed1")==0||strcmpi(user.acc_type,"fixed2")==0||strcmpi(user.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT TRANSACT CASH IN FIXED TYPE ACCOUNTS!!!!!");
                   printf("Press any key");
				   getch();
                   system("cls");
                    menu();
                }
    	firse:
   	    printf("Enter your account number:");
   	    scanf("%d",&transfer1.acc_no);
   	    printf("Enter recepient account number:");
   	    scanf("%d",&transfer2.acc_no);
   	    
   	    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
   	    {
   	    	if(user.acc_no==transfer1.acc_no || user.acc_no==transfer2.acc_no)
   	    	{
   	    		count++;
			}
		}
		if(count==2)
		{
			fclose(old);
			old=fopen("record.dat","r");
			printf("Enter the amount you want to transfer:");
   	    	scanf("%f",&transfer1.amt);
			while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
			{
				if(user.acc_no==transfer1.acc_no)
				{//printf("fsfgs");
					user.amt=user.amt - transfer1.amt;
					fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
				}
				else if(user.acc_no==transfer2.acc_no)
				{//printf("fsfgs");
					user.amt=user.amt + transfer1.amt;
					printf("\n\t\t\tTransfer successful.\n\n");
					fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
				}
				else
				{
					fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);
				}
			}
			
		}
		else
		{
			printf("\n\nEnter valid account numbers.\nPress any key to try again:");
			getch();
			system("cls");
			goto firse;
		}
    }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nNO RECORD!!");
       transact_invalid:
      printf("\npress 1 to go to main menu, 0 to exit, 2 to try again");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
    case '2': txn();
    break;
    default : goto transact_invalid;
    break;
	}

   }
   else
   {
      startsss:
		printf("\npress 1 to go to main menu, 0 to exit");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
    default : goto startsss;
    break;
	}
   }

}
void del(void)
{
    printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n");

    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\n\n\n\n\n\n\n \t\t\tEnter the account no. of the account you want to delete: ");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
   {
        if(user.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,user.acc_type,user.amt,user.track.mm,user.track.dd,user.track.yy);

        else
            {test++;
            system("cls");
            system("color FC");

            printf("\n\n\n\n\n\n\t\t\t\t  Account deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nNo account by that number!!\a\a\a");
            del_invalid:
		printf("\npress 1 to go to main menu, 0 to exit, 2 to try again");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
    case '2':del();
    break;
    default : goto del_invalid;
    break;
	}
        }
    else
        {startssss:
		printf("\npress 1 to go to main menu, 0 to exit");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	    close();
        break;
    default : goto startssss;
    break;
	}

}}

void view_det(void)
{ printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n\n\n");

    FILE *ptr;
    int test=0,rate;
    int choice;
    float period;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
        {
            if(user.acc_no==check.acc_no)
            {   system("cls");
                test=1;
                 printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n");

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d-%d-%d \nAge:%d \nAddress:%s \naddhar No:%s \nmobile number:%.0lf \nType Of Account:%s \nAmount deposited:Rs %.2f \nDate Of Deposit:%d-%d-%d\n",user.acc_no,user.name,user.dob.mm,user.dob.dd,user.dob.yy,user.age,user.address,user.addhar,user.mobile,
                user.acc_type,user.amt,user.track.dd,user.track.mm,user.track.yy);
                if(strcmpi(user.acc_type,"fixed1")==0)
                    {
                       intrst=(9*1*user.amt)/100.0;
                        printf("\n\ncostemer will be given Rs.%.2f  interest on date  %d-%d-%d\nHappy banking",intrst,user.track.mm,user.track.dd,user.track.yy+1);
                    }
                else if(strcmpi(user.acc_type,"fixed2")==0)
                    {
                        intrst=(11*2*user.amt)/100.0;
                        printf("\n\ncostemer will be given Rs.%.2f  interest on date  %d-%d-%d\nHappy banking",intrst,user.track.mm,user.track.dd,user.track.yy+2);

                    }
                else if(strcmpi(user.acc_type,"fixed3")==0)
                    {
                        intrst=(13*3*user.amt)/100.0;
                        printf("\n\ncostemer will be given Rs.%.2f  interest on date  %d-%d-%d\nHappy banking",intrst,user.track.mm,user.track.dd,user.track.yy+3);

                    }
                 else if(strcmpi(user.acc_type,"saving")==0)
                    {
                        intrst=((8*1)/100.0*user.amt)/12;
                        printf("\n\ncostemer will be given Rs.%.2f  interest on date %d every month\nHappy banking",intrst,user.track.dd);

                     }
                 else if(strcmpi(user.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&user.acc_no,user.name,&user.dob.mm,&user.dob.dd,&user.dob.yy,&user.age,user.address,user.addhar,&user.mobile,user.acc_type,&user.amt,&user.track.mm,&user.track.dd,&user.track.yy)!=EOF)
        {
            if(strcmpi(user.name,check.name)==0)
            {   system("cls");
             printf("\t\t\t\t|=========================================================|\n");
             printf("\t\t\t\t|                                                         |\n");
             printf("\t\t\t\t|                       PAL BANK                          |\n");
             printf("\t\t\t\t|                                                         |\n");
             printf("\t\t\t\t|=========================================================|\n");

                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \naddhar No:%s \nmobile number:%.0lf \nType Of Account:%s \nAmount deposited:Rs%.2f \nDate Of Deposit:%d/%d/%d\n\n",user.acc_no,user.name,user.dob.dd,user.dob.mm,user.dob.yy,user.age,user.address,user.addhar,user.mobile,
                user.acc_type,user.amt,user.track.dd,user.track.mm,user.track.yy);
                if(strcmpi(user.acc_type,"fixed1")==0)
                    {
                        intrst=(9*1*user.amt)/100.0;
                        printf("\n\ncostemer will be given Rs.%.2f  interest on date  %d-%d-%d\nHappy banking",intrst,user.track.dd,user.track.mm,user.track.yy+1);
                    }
                else if(strcmpi(user.acc_type,"fixed2")==0)
                    {
                        intrst=(11*3*user.amt)/100.0;
                        printf("\n\ncostumer will be given Rs.%.2f  interest on date  %d-%d-%d\nHappy banking",intrst,user.track.dd,user.track.mm,user.track.yy+2);

                    }
                else if(strcmpi(user.acc_type,"fixed3")==0)
                    {
                        intrst=(13*3*user.amt)/100.0;
                        printf("\n\ncostumer will be given Rs.%.2f  interest on date  %d-%d-%d\nHappy banking",intrst,user.track.dd,user.track.mm,user.track.yy+3);

                    }
                 else if(strcmpi(user.acc_type,"saving")==0)
                    {
                        intrst=(8*(1/12)*user.amt)/100.0;
                        printf("\n\ncostumer will recieve Rs.%.2f  interest on %dth every month\nHappy banking",intrst,user.track.dd);

                     }
                 else if(strcmpi(user.acc_type,"current")==0)
                    {

                        printf("\n\nNO interest for a current account\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
    printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n");

            printf("\nRecord not found!!\a\a\a");
            view_det_invalid:
		printf("\npress 1 to go to main menu, 0 to exit,2 to try again");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
    case '2':
         view_det();
          break;
    default : goto view_det_invalid;
    break;
	}
        }
    else
        {startsks:
		printf("\npress 1 to go to main menu, 0 to exit");
    char ch=getche();
    system("cls");
    switch(ch)
    {
    case '1': menu();
    break;
    case '0':
    	system("cls");
	close();
    break;
    default : goto startsks;
    break;
	}
}
}

void close(void)
 {
// system("color 5");
    printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n");

    printf("\n\n\n\n\n\n\t\t\t\t\t\t|This Project is developed  by|\n\n");
    printf("\t\t|===========================|   |===========================|    |===========================|\n");
    printf("\t\t|        AVI MITTAL         |   |        LALIT KUMAR        |    |      PIYUSH BHARGAV       |\n");
    printf("\t\t|===========================|   |===========================|    |===========================|\n\n\n");
    printf("\t\t\t\t\t\t|===========================|\n");
    printf("\t\t\t\t\t\t|        THANK YOU!         |\n" );
    printf("\t\t\t\t\t\t|===========================|\n");

    }


void menu(void)
{   int choice;
    system("cls");
    system("color F2");
    //system("color 9");
    printf("\t\t\t\t|=========================================================|\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|                       PAL BANK                          |\n");
    printf("\t\t\t\t|                                                         |\n");
    printf("\t\t\t\t|=========================================================|\n");
    printf("\n\n\n\t\t\t\t\t\t WELCOME TO THE MAIN MENU ");
    printf("\n\n\n\n\n\t\t\t\t1.Create new Account account\n\t\t\t\t2.Update account information\n\t\t\t\t3.Deleate Account\n\t\t\t\t4.Check account Details\n\t\t\t\t5.Transaction\n\t\t\t\t6.View Account list\n\t\t\t\t7.Logout\n\t\t\t\t8.Login logs\n\t\t\t\t9.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:create();
        break;
        case 2:update();
        break;
        case 3:del();
        break;
        case 4:view_det();
        break;
        case 5:txn();
        break;
        case 6:all_list();
        break;
        case 7:main();
        break;
        case 8:Login_Logs();
        break;
        case 9:close();
        break;

    }
}

