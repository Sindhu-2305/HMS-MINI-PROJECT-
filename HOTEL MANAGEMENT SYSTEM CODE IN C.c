/*
			HOTEL MANAGEMENT SYSTEM IN C 
			SINDHU CHOKKARAPU    1602-19-737-174
			NEHA BANDARU         1602-19-737-144
			
*/
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
int Time() 								//to print current system time
{
  time_t currentTime;
  time(&currentTime);
  printf("Time: %s\n",ctime(&currentTime));
}
int book;
struct booking
{
    char r_number[5];
    char name[50];
    char occupation[100];
    char age[5];
    char phone_number[10];
    char period[2];
    char in_date[12];
    char out_date[12];
	
}s;

void login();
void logo();
void r_booking();
void main_menu();
void search_room_number();
void food_services();
void items();
int display();
int order();
void view();
void check_out();
void notify();
void check_date(int d,int m,int y,struct booking r);
int main()
{
    system("cls");    //to clear the screen
    Time();
    printf("\n\n\n\n\t\t=========================================================================\n\n\n\t\t\t\t\tTAJ HOTEL\n\n\n\t\t\t\t\t1602-19-737-174/144\n\n\n\t\t\t\t\tHotel Management System\n\n\n\t\t==========================================================================\n");
    printf("\nPress Enter to continue...");
	getch();
    login();
}

void login(){
       char u_name[20],c=' ';
       char password[10];
	   int a=0,i=0;
	   do
	   {

		   system("cls");
		   logo();
		   printf("\t\t\t\t\t\t\tLOGIN FORM\n\n");
		   printf("\n\t\t\t\t\t\t  Enter User Name:   ");
		   scanf("%s",&u_name);
		   printf("\n\t\t\t\t\t\t  Enter Password:   ");
		   while(i<10)
		   {
			   password[i] = getch();
			   c = password[i];
			   if(c==13) break;
			   else printf("*");
			   i++;
		   }
		   password[i] = '\0';
		   i=0;
		   if(strcmp(u_name,"sindhu")==0 && strcmp(password,"2305")==0)
		   {
			    printf("\n\n\t\t\t\t\t\t\tWelcome!\n\n\t\t\t\t\t   You have successfully logged In!!!\n\n\t\t\t\t\t\t\tHave a nice day...");
				printf("\n\n\t\t\t\t\t\tEnter any key for services....");
			    getch();
				main_menu();
				break;

		   }
		   else
		  {
				   printf("\n\n\t\t\t\t\tWrong Password!!!");
				   a++;
				   getch();
		  }
	   }while(a<=2);
	   if (a>2)
	   {
			printf("\nSorry you have entered the wrong username and password for 3 times!!!");

			getch();

	   }
		system("cls");

}
void logo()
{
   printf("\n\t\t\t\t\t         ******************************************************************************\n\n");
	printf("\t\t\t\t\t         ******************************************************************************\n\n");
	printf("\t\t\t\t\t                    			WELCOME TO TAJ HOTEL 						       \n\n");
	printf("\t\t\t\t\t                                	SINDHU_NEHA                                    \n\n");
	printf("\t\t\t\t\t         ******************************************************************************\n\n");
	printf("\n\t\t\t\t\t         ******************************************************************************\n\n");
}
void main_menu(){
    system("cls");
    Time();
    getch();
    int ch;
    logo();
    printf("\t\t\t\t\t\t1.Book a room\n\n");
	printf("\t\t\t\t\t\t2.View Room records\n\n");
	printf("\t\t\t\t\t\t3.Search Customer record\n\n");
	printf("\t\t\t\t\t\t4.Check-Out a room\n\n");
	printf("\t\t\t\t\t\t5.Food Services\n\n");
	printf("\t\t\t\t\t\t6.Reminder\n\n");
	printf("\t\t\t\t\t\t7.Exit");
    printf("\n\n\t\t\t\t\t\t\tEnter Your Choice:");
    scanf("%d",&ch);
 switch(ch){
     case 1:r_booking();
	 break;
     case 2:view();
     break;
     case 3:search_room_number();
     break;
     case 4:check_out();
     break;
     case 5:food_services();
     break;
     case 6:system("cls");
			notify();
			break;
	case 7:
				system("cls");
				printf("\n\n\t\t\t\t\t **************  THANK YOU  *************\n");
				printf("\n\n\t\t\t\t\t   ****          VISIT AGAIN       ****\t");
				printf("\n\n\n");
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to go to main menu");
				getch();
				main_menu();
               }
}

void food_services()											//FOOD SERVICE
{
    system("cls" );
    Time();
    getch();
    logo();
	int ser_choice;
	printf("\n\n\t\t\t\t\t\t 1. Order\n\n");
	printf("\t\t\t\t\t\t 2.Display\n\n");
	printf("\t\t\t\t\t\t 3 to Exit");
	printf("\n\n\t\t\t\t\t\t Enter Your Choice:");
	scanf("%d",&ser_choice);
	switch(ser_choice)
	{

		case 1:order();
			   break;
		case 2:display();
			   break;
	    case 3:main_menu();
			   break;
	}
}
struct order{
    char name[50];
    int number_of_food;
    int cost;
}p[10000];

void items ()
{
    printf("\n\t\t\t\t\t\t\t*****************MENU*******************\n");

    printf("Item Code#\t\t Description\t\t\t\t\t\t   Size \t\t\t\t\t   Price(Rs)\n");
	for(int h=0;h<145;h++)
		printf("*");

    printf("\n[21]\t\t\t  Burger \t\t\t\t\t\t   200/300gm\t\t\t\t\t  130/180\n");
    printf("\n[22]\t\t\t  Pizza  \t\t\t\t\t\t   2/14/16inch\t\t\t\t	750/975/1250\n");
    printf("\n[23]\t\t\t  Fried Chicken \t\t\t\t\t   1/4/10 pcs\t\t\t\t	85/320/790\n");
    printf("\n[24]\t\t\t  Grilled Chicken \t\t\t\t\t   quarter/half/full\t\t\t\t 70/140/250\n");
    printf("\n[25]\t\t\t  Noodles \t\t\t\t\t\t   Half/Full	\t\t\t\t  130/250\n");
    printf("\n[26]\t\t\t  Pasta	\t\t\t\t\t\t   Half/Full \t\t\t\t\t  120/240\n");
    printf("\n[27]\t\t\t  Oreo Shake \t\t\t\t\t\t    250mg \t\t\t\t	   180\n");
    printf("\n[28]\t\t\t  Cold Coffee \t\t\t\t\t\t    250mg \t\t\t\t\t   65\n");
    printf("\n[29]\t\t\t  Cappuccino \t\t\t\t\t\t    250mg	\t\t\t     	   70\n");
    printf("\n[30]\t\t\t  Coke	\t\t\t\t\t \t   250/500mg \t\t\t\t        20/30\n\n");

}

int order_count = 0;

int order ()
{
    int n, in, qu;
	char t;
    printf ("please enter your name: ");
	scanf("%c",&t);     // statement to clear buffer
    scanf("%[^\n]",p[order_count].name);
    items();
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;

    level:
    printf ("How many items you want to order? ");
    scanf ("%d", &n);

    getchar ();
    while(n--){
        printf ("\nEnter chosen item code\n");
        scanf ("%d", &in);
        getchar();
        switch(in){
			case 21 : {
				printf ("Enter the size of burger: 1. 200gm  2. 300gm\n");
				int i;
				scanf ("%d", &i);
				getchar();

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;

				if (i==1) p[order_count].cost += (130*qu);

				else p[order_count].cost += (180*qu);
				break;
			}
			case 22 :{
				printf ("Enter the size of Chicken Pizza: 1. 12inch  2. 14inch  3. 16inch\n");
				int i;
				scanf ("%d", &i);
				getchar();

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;

				if (i==1) p[order_count].cost += (750*qu);

				else if (i==2) p[order_count].cost += (975*qu);

				else  p[order_count].cost += (1250*qu);

				break;
			}
			case 23 :{
				printf ("Enter the amount of chicken: 1. 2 pcs  2. 4 pcs  3. 10 pcs\n");
				int i;
				scanf ("%d", &i);
				getchar();

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;

				if (i==1) p[order_count].cost += (85*qu);

				else if (i==2) p[order_count].cost += (320*qu);

				else  p[order_count].cost += (790*qu);

				break;
			}
			case 24 :{
				printf ("Enter the size of grilled chicken: 1. quarter  2. half  3. full\n");
				int i;
				scanf ("%d", &i);
				getchar();

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;

				if (i==1) p[order_count].cost += (70*qu);

				else if (i==2) p[order_count].cost += (140*qu);

				else  p[order_count].cost += (250*qu);

				break;
			}
			case 25 :{
				printf ("Enter the size(bowl) of Noodles: 1. half  2. full\n");
				int i;
				scanf ("%d", &i);
				getchar();

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;

				if (i==1) p[order_count].cost += (130*qu);

				else p[order_count].cost += (250*qu);

				break;
			}
			case 26 :{
				printf ("Enter the size(bowl) of pasta: 1. half  2. full\n");
				int i;
				scanf ("%d", &i);
				getchar();

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;

				if (i==1) p[order_count].cost += (120*qu);

				else p[order_count].cost += (240*qu);

				break;
			}
			case 27 : {
				printf ("250 mg of Oreo Shake\n");

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;
				p[order_count].cost += (180*qu);
				break;
			}
			case 28 : {
				printf ("250 mg of Cold Coffee\n");

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;
				p[order_count].cost += (65*qu);
				break;
			}
			case 29 : {
				printf ("250 mg of Cappuccino\n");

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;
				p[order_count].cost += (70*qu);
				break;
			}
			case 30 :{
				printf ("Enter the size of Coke: 1. 250mg  2. 500mg\n");
				int i;
				scanf ("%d", &i);
				getchar();

				printf ("Please enter the quantity: ");
				scanf ("%d", &qu);
				getchar();

				p[order_count].number_of_food +=qu;

				if (i==1) p[order_count].cost += (20*qu);

				else p[order_count].cost += (30*qu);
				break;
			}
			default : {
				printf ("Invalid selection try again\n");
				n++;
			}
        }
    }
    char temp;
    printf ("Do you want to order anything else?(y/n)\n ");
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        goto level;
	if(temp=='n' || temp=='N')
	{
		printf ("\nNumber of food ordered %d\n", p[order_count].number_of_food);
		printf ("\nThank you %s. Your bill is %dRs.\nPlease wait while we prepare the food.\n\n", p[order_count].name, p[order_count].cost);
		order_count ++;
	}
	getch();
	food_services();
}


int display ()
{
    printf ("Total order taken: %d\n", (order_count));
	getch();
	food_services();
}

void r_booking()	//ROOM BOOKING
{

	 system("cls" );
	 Time();
		//getch();
	 logo();
    printf("\n\t\t\t\t\t\t\tOur Hotel Rooms\n\n");
    printf("\n\n\tRoom No\t\tCategory\t\tAvailable\t\tPeriod(x days)\t  Arrival Date\t Exit Date\n\n");//Checking available or not
    FILE *fp;
    char day[5];
    char avail[10];
    char in_date[12],out_date[12];
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"101")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t101\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"102")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t102\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"103")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t103\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"104")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t104\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"105")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t105\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"106")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t106\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"107")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t107\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"108")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t108\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"109")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t109\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    fp=fopen("detail.txt","r");
    strcpy(day,"N/A");
    strcpy(in_date,"N/A");
    strcpy(out_date,"N/A");
    strcpy(avail,"Yes");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.r_number,"110")==0)
        {
            strcpy(avail,"No");
            strcpy(day,s.period);
            strcpy(in_date,s.in_date);
            strcpy(out_date,s.out_date);
        }
    }
    fclose(fp);
    printf("\n\t110\t\tDouble(1B)\t\t%s\t\t\t%s Days\t\t%s\t%s\n",avail,day,in_date,out_date);
    printf("\n\n\t\t\t\t\t\tWhich room you want to book:");
    scanf("%d",&book);
	if(book>=101 && book<=110)
	{
		 system("cls" );
		Time();
		getch();
		logo();
		time_t t;
		t = time(NULL);
		struct tm tm = *localtime(&t);
		int d = tm.tm_mday;
		int m = tm.tm_mon+1;
		int y = tm.tm_year+1900;
		char date[10];
		char temp;
		 printf("\n\t\t\t\t\t\tFill the form\n\n");
		 printf("\t\t\t\t");
		 for(int l=0;l<60;l++)
			 printf("*");
		 fp=fopen("detail.txt","a");
		 struct booking s;
		 printf("\n\n\t\t\t\t\t\tReenter Room Number:  ");
		 scanf("%s",&s.r_number);
		 printf("\n\t\t\t\t\t\tEnter Name:  ");
		 scanf("%c",&temp); // temp statement to clear buffer
		 scanf("%[^\n]",s.name);
		 printf("\n\t\t\t\t\t\tEnter Age:  ");
		 scanf("%s",&s.age);
		 printf("\n\t\t\t\t\t\tEnter Phone Number: ");
		 scanf("%s",&s.phone_number);
		 printf("\n\t\t\t\t\t\tEnter Occupation:  ");
		 scanf("%s",&s.occupation);
		 printf("\n\t\t\t\t\t\tEnter Period(\'x\'days):  ");
		 scanf("%s",&s.period);
		 printf("\n\t\t\t\t\t\tEnter Arrival Date(DD-MM-YY):  ");
		 scanf("%s",&s.in_date);
		 check_date(d,m,y,s);
		 printf("\n\t\t\t\t\t\tEnter Exit Date(DD-MM-YY):  ");
		 scanf("%s",&s.out_date);
		 printf("\n\n\n\t\t\t\t\t\t This room has been booked for %s days",s.period);
		 fwrite(&s,sizeof(s),1,fp);
		 getch();
		 fclose(fp);
		main_menu();
	}
	else
	{
		printf("\n\t\t\t\t\tInvalid room no...");
		getch();
		main_menu();
	}
 
}
void check_date(int d,int m,int y,struct booking r)
{
	char da[12],mo[12],ye[12],res[12];
	strcpy(da,strtok(r.in_date,"-"));
	strcpy(mo,strtok(NULL,"-"));
	strcpy(ye,strtok(NULL,"-"));
	int a = atoi(da);
	int b = atoi(mo);
	int c = atoi(ye); 
	if(c>y)
	{
		printf("");
			
	}
	else if(c==y)
	{
		if(b>m)
		
			printf("");
		else if(b==m)
		{
			if(a>=d)
				printf("");
			else
			{
				printf("\n\n\t\t\t\t\t\t\t\tEnter valid date!!!");
				getch();
				r_booking();
			}
		}
		else
		{
			printf("\n\n\t\t\t\t\t\t\t\tEnter valid date!!!");
			getch();
			r_booking();
		}
	}
	else
	{
		printf("\n\n\t\t\t\t\t\t\t\tEnter valid date!!!");
		getch();
		r_booking();
	}
 	
}
void view()
{
    system("cls");
    Time();
    getch();
    logo();
    printf("\t\t\t\t\t\tCustomer Details\n\n");
    FILE *fp;
    fp=fopen("detail.txt","r");
    struct booking s;
    printf("Room No\t Name\t\tAge\t Phone Number \t Occupation\t Period(days)\t   Arrival Date\t   Exit Date\n");
    getch();
    while (fread(&s,sizeof(s),1,fp))
    {
    printf("\n%s\t %s\t\t%s\t %s\t %s\t  %s\t\t   %s\t  %s\n",s.r_number,s.name,s.age,s.phone_number,s.occupation,s.period,s.in_date,s.out_date);
    }
    fclose(fp);
    getch();
    main_menu();
}
void search_room_number()
{
    system("cls");
   printf("\t\t\t\t\t\tCustomer Search Option\n\n");
   printf("\t\t\t\t");
   for(int k=0;k<60;k++)
	   printf("*");
   FILE *fp;
   int flag=1;
   fp=fopen("detail.txt","r+");
   struct booking s;
   char se_room[20];
   if(fp==0)
		exit(0);
	fflush(stdin);
   printf("\n\n\t\t\t\t\t\t Enter Room Number:");
   scanf("%s",se_room);
   while(fread(&s,sizeof(s),1,fp))
    {
        if (strcmp(se_room,s.r_number) == 0)
        {
		   flag=0;
		   printf("\n\n\n\tRoom Number\tName\tAge\tPhone Number\tOccupation\tPeriod(days)\t   Arrival Date\t   Exit date\n");
		   printf("\t");
		   for(int j=0;j<110;j++)
			   printf("*");
		   printf("\n\t%s\t\t%s\t%s\t%s\t%s\t\t%s\t\t %s\t %s\n",s.r_number,s.name,s.age,s.phone_number,s.occupation,s.period,s.in_date,s.out_date);
		   break;
		   getch();
       }
   }
   if(flag==1)
   {
		printf("\n\tRequested Room number is not booked!!!");
   }
    getch();
	fclose(fp);
	main_menu();
}

void check_out()
{
	int r,p,z,bill;
	system("cls");
	Time();
	getch();
	struct booking s;
	logo();
	FILE *fpo;
	FILE *fpt;
	printf("Enter the room no u want to check-out: ");
	scanf("%d",&r);
	fpo = fopen("detail.txt","r+");
	fpt = fopen("Tempfile","w");
	while(fread(&s,sizeof(s),1,fpo))
	{
		p = atoi(s.r_number);
		z=atoi(s.period);
		bill = 1500*z;
		if(p!=r)
			fwrite(&s,sizeof(s),1,fpt);

	}
	fclose(fpo);
	fclose(fpt);
	fpo= fopen("Detail.txt","w");
	fpt = fopen("Tempfile","r");
	while(fread(&s,sizeof(s),1,fpt))
		fwrite(&s,sizeof(s),1,fpo);
	printf("\n\t\tCheckout done...");
	printf("\n\t\tRoom no %s bill is %d.\n",s.r_number,bill);
	printf("\n\t\tThe room %s is available again....",s.r_number);
	fclose(fpo);
	fclose(fpt);
	getch();
	main_menu();
}

void notify()									//Remainder function-shows notifications for check-out of rooms if any...
{
    logo();
    char today_date[12];
    printf("\n\n\n\t\t\t\tEnter Date(DD-MM-YYYY):");
    fflush(stdin);
    scanf("%s",today_date);
    int count=0;
    FILE *fp;
    fp=fopen("detail.txt","r");
    struct booking s;
    while(fread(&s,sizeof(s),1,fp))
    {
        if (strcmp(s.out_date,today_date)==0)
        {
            printf("\n\t\t Room No:%s \tDate:%s\t Last Date Today",s.r_number,s.out_date);
            count++;
        }
    }
    fclose(fp);
    if(count==0)
    {
        printf("\n\t\t\t\tNo Notification for today");
    }
    getch();
    main_menu();

}
// END OF PROGRAM
// THANK YOU...
