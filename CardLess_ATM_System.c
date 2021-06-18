#include <stdio.h>
#include <conio.h>
#include <graphics.h> // All the Libraries needed for Implementation
#include <stdlib.h>
#include <string.h>
// All the functions to perform the particular operation
void Acdata(); // Function for Data Storage
int Login(); // Function for Login Mechanism
int Deposit(); // Function for mechanism of Cash Deposition
int Withdraw(); // Function for mechanism of Cash Withdraw
int Chkbalance(); // Function for mechanism of Checking Balance
int Accdetails(); // Function for mechanism of displaying Account Details
void Thanks(); // Function for Thank You Screen
typedef struct
{
char Acno[13];
char Acname[15];
float Amt;
char Cdno[13]; // Data of the User is stored in the form of these Structure
int lpin;
int tpin;
} Account;
Account *accs;
int gd = DETECT, gm;
int lpass=0, tpass=0, idx;
void main()
{
int lck, tch;
char ec;
accs = (Account*)calloc(3, sizeof(Account)); /* Dynamic Memory Allocation for
if(accs != NULL) Structure*/
{
Acdata();
}
start:
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
rectangle(10,10,630,450);
setfillstyle(8,8);
floodfill(15,15,15); /* Graphics Code for Home Screen
settextstyle(3,0,4); Layout*/
outtextxy(135,20,"CARDLESS ATM SERVICE");
outtextxy(210,180,"Hello Customer");
outtextxy(245,220,"Welcome :)");
settextstyle(3,0,2);
outtextxy(210,410,"Press Enter To Continue");
ec = getch();
closegraph();
if(ec == '5')
{
exit(0); // Exit mechanism for Administrator

P a g e 22 | 32

}
lck = Login();
if(lck == 0)
{
goto start;
}
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
rectangle(10,10,630,450);
setfillstyle(8,8);
floodfill(15,15,15);
settextstyle(3,0,4);
outtextxy(105,20,"Welcome To Your Account");
settextstyle(3,0,2);
outtextxy(190,180,"Please Choose an Option"); /* Graphics Code for
outtextxy(220,220,"1 >> Deposit Cash"); Transaction Options Screen */
outtextxy(220,240,"2 >> Withdraw Cash");
outtextxy(220,260,"3 >> Check Your Balance");
outtextxy(220,280,"4 >> Account Details");
outtextxy(220,300,"5 >> Quit");
outtextxy(240,410,"Enter Your Choice");
tch = getch();
closegraph();
clrscr();

switch(tch) // Choice mechanism for choosing Transaction
{
case '1':
Deposit();
break;
case '2':
Withdraw();
break;
case '3':
Chkbalance();
break;
case '4':
Accdetails();
break;
case '5':
clrscr();
Thanks();
goto start;
default:
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
rectangle(10,10,630,450);
setfillstyle(8,8);
floodfill(15,15,15); /* Code for resolving if choice
settextstyle(3,0,4); is invalid */
outtextxy(250,200,"Invalid Choice");
getch();
closegraph();
Thanks();
clrscr();

P a g e 23 | 32

break;
}
goto start;
}
void Acdata()
{
strcpy((accs+0)->Acno,"918602501968");
strcpy((accs+0)->Acname,"Jayesh Bansal");
(accs+0)->Amt = 16328.75;
strcpy((accs+0)->Cdno,"973474010816");
(accs+0)->lpin = 3927;
(accs+0)->tpin = 1479;
strcpy((accs+1)->Acno,"919827935115");
strcpy((accs+1)->Acname,"Aakash Jain");
(accs+1)->Amt = 27529.41;
strcpy((accs+1)->Cdno,"983557353733");
(accs+1)->lpin = 5735;
(accs+1)->tpin = 3123;
strcpy((accs+2)->Acno,"916232109001");
strcpy((accs+2)->Acname,"Jitendra Singh");
(accs+2)->Amt = 32920.60;
strcpy((accs+2)->Cdno,"977374856631");
(accs+2)->lpin = 1924;
(accs+2)->tpin = 2437;
}
int Login()
{
int i, j, ch, ac=0, pc=0, count;
char c, *edcn;
clrscr();
printf("\n\n");
printf("\t ************************* LOGIN PAGE **************************");
printf("\n\n\n");
printf("\t\t Enter Your ATM Card Number : ");
card:
count = 0;
scanf("%s",edcn);
for(i=0; i<3; i++)
{
if(strcmp(edcn, (accs+i)->Cdno) == 0)
{
printf("\n\n\t\t Enter Your Login Pin : ");
for( j=0; j<4 ; j++)
{
c = getch();
ch = c - '0';
lpass = lpass*10 + ch;
printf("*");
}
getch();
idx = i;
goto pass;
}

P a g e 24 | 32

else
{
count++;
}
}
if(count == 3)
{
if(ac == 1)
{
printf("\n\n\n");
printf("\t *********************** LOGIN FAILED ***********************");
getch();
Thanks();
clrscr();
return 0;
}
gotoxy(1,6);
delline();
ac++;
printf("\t\t Card Number not exist, Press Enter");
getch();
printf("\r\t\t Enter Your ATM Card Number Again : ");
goto card;
}
pass:
if(lpass == (accs+idx)->lpin)
{
printf("\n\n\n");
printf("\t ********************** LOGIN SUCCESSFUL *********************");
getch();
clrscr();
lpass = 0;
return 1;
}
else
{
if(pc == 1)
{
printf("\n\n\n");
printf("\t ********************* LOGIN FAILED *********************");
getch();
Thanks();
clrscr();
return 0;
}
gotoxy(1,8);
delline();
pc++;
printf("\t\t Incorrect Pin, Press Enter ");
getch();
lpass = 0;
printf("\r\t\t Enter Your Login Pin Again : ");
for( j=0; j<4 ; j++)
{
c = getch();

P a g e 25 | 32

ch = c - '0';
lpass = lpass*10 + ch;
printf("*");
}
getch();
goto pass;
}
}
int Deposit()
{
int i, ch, dac=0, dtc=0, damt;
char c;
clrscr();
printf("\n\n");
printf("\t ************************ DEPOSIT CASH ************************");
printf("\n\n");
printf("\t\t\t Amount should be in multiples of 100");
printf("\n\n");
printf("\t\t Enter Amount to be deposited : ");
deposit:
scanf("%d",&damt);
if( damt%100 == 0 && damt < 5000 )
{
printf("\n\n");
printf("\t\t Enter Your Transaction Pin : ");

for( i=0; i<4 ; i++)

{
c = getch();
ch = c - '0';
tpass = tpass*10 + ch;
printf("*");
}
getch();
goto Transacpin;
}
else
{
if(dac == 1)
{
printf("\n\n\n");
printf("\t ***************** TRANSACTION FAILED *****************");
getch();
Thanks();
clrscr();
return 0;
}
gotoxy(1,7);
delline();
dac++;
printf("\t\t Invalid Amount, Press Enter");
getch();
printf("\r\t\t Enter Amount to be deposited Again : ");
goto deposit;
}
Transacpin:
if(tpass == (accs+idx)->tpin)

P a g e 26 | 32

{
printf("\n\n\n");
printf("\t ****************** TRANSACTION SUCCESSFUL ******************");
(accs+idx)->Amt = (accs+idx)->Amt + (float)damt;
printf("\n\t ********** AMOUNT DEPOSITED SUCCESSFULLY **********");
getch();
Thanks();
clrscr();
tpass = 0;
return 1;
}
else
{
if(dtc == 1)
{
printf("\n\n\n");
printf("\t ****************** TRANSACTION FAILED *****************");
getch();
Thanks();
clrscr();
return 0;
}
gotoxy(1,10);
delline();
dtc++;
printf("\t\t Incorrect Pin, Press Enter");
getch();
tpass = 0;
printf("\r\t\t Enter Your Transaction Pin Again : ");

for( i=0; i<4 ; i++)

{
c = getch();
ch = c - '0';
tpass = tpass*10 + ch;
printf("*");
}
getch();
goto Transacpin;
}
}
int Withdraw()
{
int i, ch, wac=0, wtc=0, wamt;
char c;
clrscr();
printf("\n\n");
printf("\t ************************ WITHDRAW CASH ************************");
printf("\n\n");
printf("\t\t\t Amount should be in multiples of 100");
printf("\n\n");
printf("\t\t Enter Amount to be withdrawn : ");
withdraw:
scanf("%d",&wamt);
if( wamt%100 == 0 && wamt < 5000 )
{
printf("\n\n");
printf("\t\t Enter Your Transaction Pin : ");

for( i=0; i<4 ; i++)

P a g e 27 | 32

{
c = getch();
ch = c - '0';
tpass = tpass*10 + ch;
printf("*");
}
getch();
goto Transacpin;
}
else
{
if(wac == 1)
{
printf("\n\n\n");
printf("\t ***************** TRANSACTION FAILED ******************");
getch();
Thanks();
clrscr();
return 0;
}
gotoxy(1,7);
delline();
wac++;
printf("\t\t Invalid Amount, Press Enter");
getch();
printf("\r\t\t Enter Amount to be withdrawn Again : ");
goto withdraw;
}
Transacpin:
if(tpass == (accs+idx)->tpin)
{
printf("\n\n\n");
printf("\t ***************** TRANSACTION SUCCESSFUL *****************");
(accs+idx)->Amt = (accs+idx)->Amt - (float)wamt;
printf("\n\t ********** AMOUNT WITHDRAWN SUCCESSFULLY **********");
getch();
Thanks();
clrscr();
tpass = 0;
return 1;
}
else
{
if(wtc == 1)
{
printf("\n\n\n");
printf("\t ***************** TRANSACTION FAILED ******************");
getch();
Thanks();
clrscr();
return 0;
}
gotoxy(1,10);
delline();
wtc++;
printf("\t\t Incorrect Pin, Press Enter");
getch();
tpass = 0;
printf("\r\t\t Enter Your Transaction Pin Again : ");
for( i=0; i<4 ; i++)

P a g e 28 | 32

{
c = getch();
ch = c - '0';
tpass = tpass*10 + ch;
printf("*");
}
getch();
goto Transacpin;
}
}
int Chkbalance()
{
int i, ch, ctc=0;
char c, bal[40];
clrscr();
sprintf(bal,"AVAILABLE BALANCE : %.2f ",(accs+idx)->Amt);
printf("\n\n");
printf("\t *************** FOR CHECKING AVAILABLE BALANCE ***************");
printf("\n\n\n");
printf("\t\t Enter Your Transaction Pin : ");
Transacpin:
tpass = 0;
for( i=0; i<4 ; i++)
{
c = getch();
ch = c - '0';
tpass = tpass*10 + ch;
printf("*");
}
getch();
if(tpass == (accs+idx)->tpin)
{
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
rectangle(10,10,630,450);
setfillstyle(8,8);
floodfill(15,15,15);
settextstyle(3,0,4);
outtextxy(210,20,"Account Balance");
settextstyle(3,0,3);
outtextxy(140,200,bal);
getch();
closegraph();
Thanks();
clrscr();
tpass = 0;
return 1;
}
else
{
if(ctc == 1)
{
printf("\n\n\n");
printf("\t ******************** TRANSACTION FAILED *********************");
getch();
Thanks();
clrscr();
return 0;

P a g e 29 | 32

}
gotoxy(1,5);
delline();
ctc++;
printf("\t\t Incorrect Pin, Press Enter");
getch();
printf("\r\t\t Enter Your Transaction Pin Again : ");
goto Transacpin;
}
}
int Accdetails()
{
int i, ch, atc=0;
char c, Ac[40], Cd[30], Aname[40], Balance[30];
clrscr();
sprintf(Ac,"Account Number : %s",(accs+idx)->Acno);
sprintf(Cd,"Card Number : %s",(accs+idx)->Cdno);
sprintf(Aname,"Account Holder Name : %s",(accs+idx)->Acname);
sprintf(Balance,"Available Balance : %.2f",(accs+idx)->Amt);
printf("\n\n");
printf("\t ******************* FOR ACCOUNT DETAILS *******************");
printf("\n\n\n");
printf("\t\t Enter Your Transaction Pin : ");
Transacpin:
tpass = 0;

for( i=0; i<4 ; i++)

{
c = getch();
ch = c - '0';
tpass = tpass*10 + ch;
printf("*");
}
getch();
if(tpass == (accs+idx)->tpin)
{
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
rectangle(10,10,630,450);
setfillstyle(8,8);
floodfill(15,15,15);
settextstyle(3,0,4);
outtextxy(210,20,"Account Details");
settextstyle(3,0,3);
outtextxy(130,200,Ac);
outtextxy(130,230,Cd);
outtextxy(130,260,Aname);
outtextxy(130,290,Balance);
getch();
closegraph();
Thanks();
clrscr();
tpass = 0;
return 1;
}
else
{
if(atc == 1)

P a g e 30 | 32

{
printf("\n\n\n");
printf("\t ***************** TRANSACTION FAILED ******************");
getch();
Thanks();
clrscr();
return 0;
}
gotoxy(1,5);
delline();
atc++;
printf("\t\t Incorrect Pin, Press Enter");
getch();
printf("\r\t\t Enter Your Transaction Pin Again : ");
goto Transacpin;
}
}
void Thanks()
{
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
rectangle(10,10,630,450);
setfillstyle(8,8);
floodfill(15,15,15);
settextstyle(3,0,4);
outtextxy(210,200," THANK YOU! ");
delay(5000);
closegraph();
}
