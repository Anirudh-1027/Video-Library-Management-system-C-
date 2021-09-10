#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream.h>
#include <process.h>
#include <dos.h>


void check_username();
void get_pw();

class user
{public:
char name[50],username[20],pw[10];
long phno;
int age;
}u1,u2;

void getdata()
{
gotoxy(20,8);
cout<<"enter name:";
gotoxy(20,10);
cout<<"enter age:";
gotoxy(20,12);
cout<<"enter phone no.:";
gotoxy(20,14);
cout<<"enter username:";
gotoxy(20,16);
cout<<"enter password:";
gotoxy(40,8);
gets(u1.name);
gotoxy(40,10);
cin>>u1.age;
gotoxy(40,12);
cin>>u1.phno;
gotoxy(40,14);
gets(u1.username);
gotoxy(40,16);
get_pw();
check_username();
}
void get_pw()
{
int i=0;
do{
u1.pw[i++]=getch();
cout<<'*';
}
while(u1.pw[i-1]!='\r');

u1.pw[i]='\0';
}
class cart
{
public:
char mname[20],genre[20],lang[20];
int qty;
float tot;
}c;

struct movie
{
char name[20],genre[20], language[20],cbfc[3];
int stock;
float price;
}m1,m2;

void check_username()
{//int x=0;
USERNAME:
	 ofstream fout("user.dat", ios::out|ios::app|ios::binary);
	 fstream fin("user.dat",ios::in|ios::binary);
		while(!fin.eof())
		{
	fin.read((char*)&u2, sizeof(u2));
	if (fin.eof()) break;
			 if(strcmpi(u1.username,u2.username)==0)
			 {
		 //x=1;
		 cout<<"\nusername alredy exists.Enter new username:";
		 delay(1000);
		 gets(u1.username);
		 fin.close();
		 goto USERNAME;
			 }
		}
	fout.write((char*)&u1,sizeof(u1));
		fin.close();
		fout.close();
		getch();
}
void main()
{
char passw[50],title[40],end[100],uname[30],adpass[12],ps[30];
int ch,z=0,x=5,tmp=0,choice;
fstream fin ("user.dat", ios::binary| ios::in| ios::app);
MENU:
clrscr();
for(int k=0;k<160;k++)
	{
	cout<<"*";
	//delay(10);
	}
  cout<<endl;
  gotoxy(25,6);
  strcpy(title,"WELCOME TO ONLINE VIDEO LIBRARY");
  for(int i=0;title[i]!='\0';i++)
  {
  cout<<title[i];
 // delay(100);
	}

	cout<<"\n HOME\n\n 1.register\n 2.login\n 3.Admin\n 4.Exit";
	cout<<"\n\n\n\n\n\n\n\n";
	 for( k=0;k<160;k++)
	{
	cout<<"*";
	//delay(10);
	}
	cout<<"\n Enter your choice:";
	cin>>ch;
	switch(ch)
	{
	case 1:
	{
	clrscr();
	getdata();
	clrscr();
	gotoxy(33,11);
	cout<<"ACCOUNT SUCCESSFULLY CREATED!!!";
	delay(1000);
	goto MENU;
	}
	case 2:
	{
	   LOGIN:
			//  int prev_pos=-1,cur_pos=0;
				clrscr();
				gotoxy(20,12);
				cout<<"Enter your registered username:";
				gotoxy(52,12);
				gets(uname);
				fstream fin("user.dat",ios::in|ios::binary|ios::app);
				while(!fin.eof())
				{
				fin.read((char*)&u2,sizeof(u2));
				if (strcmpi(uname,u2.username)==0)
			    {
			 tmp=1;
			 strcpy( ps,u2.pw);
			 fin.close();
				break;

			 }
			 }
			if(tmp==1)
				{ int i=0;
				 gotoxy(20,15);
		 cout<<"PASSWORD:";
		 do{
				 passw[i++]=getch();
				 cout<<'*';
				 }while(passw[i-1]!='\r');
				 passw[i]='\0';
		if (strcmp(passw, ps)==0)
		{
		clrscr();
		gotoxy (25,14);
		cout<<"YOU HAVE SUCCESSFULLY LOGGED IN!!!";
		delay(1000);
	USERHOME:
		clrscr();
		 gotoxy(33,11);
		 cout<<"LOADING.....";
		 delay(1000);
		 clrscr();
		 gotoxy(33,11);
		 cout<<"GATHERING DATA.....";
		 delay(1000);
		 clrscr();
		 gotoxy(33,11);
		 cout<<"LOADED SUCCESSFULLY.....";
		 delay(1000);
		 clrscr();
		 for( k=0;k<160;k++)
		{
		cout<<"*";
		delay(10);
		}
		 gotoxy(25,6);
		 cout<<"\n WELCOME USER\n";
		 cout<<"\n 1.Buy movie\n 2.View cart\n 3.Return movie\n 4.Log out\n";
		 cout<<"\n\n\n\n\n\n";
		 cout<<"ENTER YOUR CHOICE:";
		 cin>>choice;
		 switch(choice)
		 {
		 case 1:
		 {
		 int k=1;
		 char uname[20];
		 clrscr();
		 gotoxy(25,6);
		 cout<<"MOVIES AVAILABLE ARE";
		 cout<<"\n\n";
		 cout<<"S.NO\tNAME\t\tGENRE\t\tLANG\t\tSTOCK\tRATING\t\PRICE\n";
		 ifstream fin("hanuman.dat",ios::in|ios::binary);
		 while(!fin.eof())
		 {
		 fin.read((char*)&m1,sizeof(m1));
		 if(fin.eof())
		 break;
		 cout<<k++<<"\t"<<m1.name<<"\t\t"<<m1.genre<<"\t\t"<<m1.language<<"\t\t"<<m1. stock<<"\t"<<m1.cbfc<<"\t"<<m1.price<<"\n";
		 }
		     cout<<"\n";
		     char u;
		 ofstream cartout("cart.dat",ios::out|ios::binary);
		 do
		{
		  fstream fout("hanuman.dat",ios::in|ios::out|ios::binary);
		  movie m;
		   cout<<"enter movie name you want to purchase:";
		 gets(uname);
		 int k;
		 fout.seekg(0,ios::beg);
		 while(!fout.eof())
		 {
		 fout.read((char*)&m1,sizeof(m1));
		 if(fout.eof())
		 break;
		 k=0;
		 if(strcmpi(uname,m1.name)==0)
		 {
		 k=1;
		 cout<<"\nenter the stock:";
		 cin>>c.qty;
		 while(c.qty>m1.stock)
		 {
		 cout<<"\nsorry,only "<<m1.stock<<" are available";
		 cout<<"\nEnter the stock again:";
		 cin>>c.qty;
		 }
		 strcpy(c.mname,m1.name);
		 strcpy(c.lang,m1.language);
		 strcpy(c.genre,m1.genre);
		 c.tot+=m1.price*c.qty;
		 cartout.write((char*)&c,sizeof(c));
		 m1.stock-=c.qty;
		 fout.seekp(fout.tellp()-sizeof(m1));
		 fout.write((char*)&m1,sizeof(m1));
		 break;
		 }
		 }
		 if(k==0)
		 {
		 cout<<"\n the entered movie does not exist ";
		 }
		 cout<<"\ndo you want to purchase more?";
		 cin>>u;
		 }
		 while(u=='y');
		 cout<<"\nSUCCESSFUL";
		 cartout.close();
		 delay(1000);
		 goto USERHOME;
		 }

	      case 2:
	      {
	      int k=0;
	      char a;
	      clrscr();
	      gotoxy(25,6);
	      cout<<"CART";
	      cout<<"\n\n";
	      cout<<"S.NO\tNAME\t\tGENRE\t\tLANG\t\tSTOCK\tRATING\n";
	      ifstream cartin("cart.dat",ios::binary);
	      while(!cartin.eof())
	      {
	      cartin.read((char*)&c,sizeof(c));
	      if(cartin.eof())
	      break;
	      cout<<++k<<"\t"<<c.mname<<"\t\t"<<c.genre<<"\t\t"<<c.lang<<"\t\t"<<c.qty<<"\t"<<m1.cbfc<<"\n";
	       }
	       cout<<"\n\nTOTAL PRICE:"<<c.tot<<endl;
	       cartin.close();
	       cout<<"confirm purchase? ";
	       cin>>a;
	       if(a=='n'||a=='n')
	       {
	       goto USERHOME;
	       }
	       else
	       {
	       clrscr();
	       gotoxy(30,11);
	       cout<<"PURCHASE HAS BEEN CONFIRMED!";
	       gotoxy(30,12);
	       cout<<"THANK YOU!";
	      delay(1000);
	      goto MENU;
	      }
	      break;
	       }
	       case 3:
	       {
	       clrscr();
		int stk;
		 tmp=0;
		 char name[30];
		 clrscr();
		 gotoxy(10,11);
		 cout<<"ENTER THE MOVIE NAME:";
		 gets(name);
		fstream movin("hanuman.dat", ios::in| ios::out|ios::binary);
	       ofstream movout("hanuman.dat", ios::app| ios::binary);
		 while(!movin.eof())
		 {
		 movin.read((char*)&m1,sizeof(m1));
		 if(movin.eof())
		 break;
		 if(strcmpi(name,m1.name)==0)
		 {
		 gotoxy(10,12);
		 cout<<"ENTER THE NO. OF MOVIES YOU ARE RETURNING:" ;
		 cin>>stk;
		 movin.seekp(movin.tellp()-sizeof(m1));
		 m1.stock+=stk;
		 movin.write((char*)&m1,sizeof(m1));
		 tmp=1;
		 gotoxy(25,14);
		 cout<<"SUCCESSFUL";
		 delay(1000);
		 break;
		 }
		 }
		 if(tmp==0)
		 {
		 clrscr();
		 gotoxy(25,12);
		 cout<<"SUCH A MOVIE DOESNT EXIST!!";
		 delay(1000);
		 }
		 goto USERHOME;
		 break;
		 }
	      case 4:
	      {
	      goto MENU;
	      }
		 }
		  }
				 else
				 {
				 cout<<"\n\t\t"<<"THE PASSWORD IS WRONG";
				 delay(1000);
				 goto MENU;
				 }
				 }
			else if (tmp==0)
			{
			cout<<"\n\t\tUSERNAME DOESNT EXIST";
			delay(1000);
			goto MENU;
			}
			break;
			}
	 case 3:
			{
			while(x!=0)
			{
			clrscr();
			gotoxy(28,12);
			cout<<"ENTER ADMIN PASSWORD:";

	while(z<10)
	 {
	 adpass[z]=getch();
		if(adpass[z]=='\r')
		 {
		 adpass[z]='\0';break;
		 }
		cout<<"*";
		z++;
	 }
	 if(strcmp(adpass,"password")==0)
	 goto ADMIN;
	 else
	 {
	 gotoxy(20,13);
	 cout<<"Wrong password,Access denied!!"<<" You have "<<--x<<" chances left";z=0;
	 getch();
	 if(x==0)
	 goto MENU;
	 }
		}
		 ADMIN: clrscr();
		 gotoxy(33,11);
		 cout<<"LOADING.....";
		 delay(1000);
		 clrscr();
		 gotoxy(33,11);
		 cout<<"GATHERING DATA.....";
		 delay(1000);
		 clrscr();
		 gotoxy(33,11);
		 cout<<"LOADED SUCCESSFULLY.....";
		 delay(1000);
		 clrscr();
		 for( k=0;k<160;k++)
		{
		cout<<"*";
		delay(10);
		}
		 gotoxy(25,6);
		 cout<<"\n WELCOME ADMIN\n";
		 cout<<"\n 1.Add a Movie profile\n 2.Search for a Movie profile\n 3.delete movie profile\n 4.Log out\n";
		 cout<<"\n\n\n\n\n\n";
		 cout<<"ENTER YOUR CHOICE:";
		 cin>>choice;
		 switch(choice)
		 {
		 case 1:
		 {
		 int stk;
		 tmp=0;
		 char name[30];
		 clrscr();
		 gotoxy(24,10);
		 cout<<"ENTER THE MOVIE NAME:";
		 gets(name);
		fstream movin("hanuman.dat", ios::in| ios::out|ios::binary);
	       ofstream movout("hanuman.dat", ios::app| ios::binary);
		 while(!movin.eof())
		 {
		 movin.read((char*)&m1,sizeof(m1));
		 if(movin.eof())
		 break;
		 if(strcmpi(name,m1.name)==0)
		 {
		 gotoxy(24,14);
		 cout<<"THE MOVIE ALREADY EXISTS";
		 gotoxy(24,15);
		 cout<<"STOCK AVAILABLE: "<<m1.stock;
		 gotoxy(24,16);
		 cout<<"ENTER THE STOCK TO BE UPDATED:" ;

		 cin>>stk;
		 movin.seekp(movin.tellp()-sizeof(m1));
		 m1.stock+=stk;
		 movin.write((char*)&m1,sizeof(m1));
		 tmp=1;
		 gotoxy(24,18);
		 cout<<"SUCCESSFUL";
		 delay(1000);
	       break;
		 }
		 }
		movin.close();
		 if(tmp!=1)
		{
		 strcpy(m2.name,name);
		 gotoxy(24,12);
		 cout<<"ENTER THE GENRE:  ";
		 gets(m2.genre);
		 gotoxy(24,14);
		 cout<<"ENTER LANGUAGE:  ";
		 gets(m2.language);
		 gotoxy(24,16);
		 cout<<"ENTER STOCK:  ";
		 cin>>m2.stock;
		 gotoxy(24,18);
		 cout<<"ENTER CBFC RATING:";
		 gets(m2.cbfc);
		 gotoxy(24,20);
		 cout<<"ENTER PRICE:";
		 cin>>m2.price;
		movout.seekp(movin.tellp()-sizeof(m1));
	       movout.write((char*)&m2,sizeof(m2));
		clrscr();
		 gotoxy(24,15);
		 cout<<"THE MOVIE HAS BEEN SUCCESFULLY ADDED";
		 delay(1000);
		 }
		movin.close();
		goto ADMIN;
		 }
		 case 2:
		 {
		 char mname[30];

		 tmp=0;
		 clrscr();
		 gotoxy(25,14);
		 cout<<"ENTER THE MOVIE TO BE SEARCHED :";
		 gets(mname);
			fstream movin("hanuman.dat", ios::in| ios::binary| ios::out);
		 while(!movin.eof())
		 {
		 movin.read((char*)&m2,sizeof(m2));
		 if(strcmpi(mname,m2.name)==0)
		 {
		 tmp=1;
		 break;
		 }
		 }
		 if(tmp==0)
		 {
		 clrscr();
		 gotoxy(24,15);
		 cout<<"THE ENTERED MOVIE NAME DOES NOT EXIST";
		 delay(1000);
		 break;
		 }
		 else if(tmp==1)
		 {
		 clrscr();
		 gotoxy(24,10);
		 cout<<"MOVIE NAME:  ";
		 puts(m2.name);
		 gotoxy(24,12);
		 cout<<"GENRE:  ";
		 puts(m2.genre);
		 gotoxy(24,14);
		 cout<<"LANGUAGE:  ";
		 puts(m2.language);
		 gotoxy(24,16);
		 cout<<"STOCK:  ";
		 cout<<m2.stock;
		 gotoxy(24,18);
		 cout<<"CBFC RATING:  ";
		 puts(m2.cbfc);
		 gotoxy(24,20);
		 cout<<"PRICE: ";
		 cout<<m2.price;
		 getch();
		 }
		  movin.close();
		 goto ADMIN;
		 }
		case 3:
		{
		char w[20];
		clrscr();
		gotoxy(25,14);
		cout<<"ENTER THE MOVIE NAME TO BE DELETED :";
		ifstream fin("hanuman.dat", ios::binary);
		ofstream fout("tmp.dat", ios::binary);
		gets(w);
		while(!fin.eof())
		{
		fin.read((char*)&m1,sizeof(m1));
		if(fin.eof())
		break;
		if(strcmpi(m1.name,w)!=0)
		fout.write((char*)&m1,sizeof(m1));
		}
		fin.close();
		fout.close();
		remove("hanuman.dat");
		rename("tmp.dat","hanuman.dat");
		clrscr();
		gotoxy(25,15);
		cout<<"DELETE SUCCESSFUL";
		delay(1000);
		goto ADMIN;
		}
		case 4:
		{
		goto MENU;
		}
		 }
		 }
		 getch();
		 }
		 }
























