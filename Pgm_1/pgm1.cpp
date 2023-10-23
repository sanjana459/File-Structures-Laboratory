#include<fstream>
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

class name
{
    public:char name[10];
};

void read_write() //from std i/o
{
int i,n,no;
name f[20];
cout<<"enter the no of names\n";
cin>>no;
for(i=0;i<no;i++)
	{
	cout<<"\nEnter name\n";
	cin>>f[i].name;
	}
cout<<"the name spelled in reverse are\n"; 
for(int j=0;j<no;j++)
	{
	cout<<strrev(f[j].name)<<endl;
	}
}

void read_name(ofstream& a,ofstream& b)//file i/o
{
int i,n;
name f;
cout<<"\nEnter name\n";
cin>>f.name;
a<<f.name;
b<<strrev(f.name)<<"|";
}

void write_name(ifstream& a)
{
char d[25];
a.getline(d,25,'|');
cout<<endl;
cout<<d<<endl;
}

int main(void)
{
int i=1,n,ch;
char ifname[20],ofname[25];
cout<<"Read Names/ Write Reversed names Program"<<endl;
cout<<"1: Using stdin/stdout\n";
cout<<"2: Using files\n";
cin>>ch;
switch(ch)
	{
	case 1:read_write();
	       break;
	case 2:cout<<"Enter the name of the file where data is to be stored\n";
	       cin>>ifname;
	       cout<<"Enter the name of the file where result is to be stored in reverse order\n";
	       cin>>ofname;
	       ofstream a,b;
	       a.open(ifname,ios::out);
	       b.open(ofname,ios::out);
	       cout<<"enter the number of names\n";
	       cin>>n;
	       while(i<=n)
		       {
		       read_name(a,b);
		       i++;
		       }
	       a.close();
	       b.close();
	       ifstream c;
	       c.open(ofname,ios::in);
	       i=1;
	       cout<<"The reversed names from the file "<<ofname<<"\n";
	       while(i<=n)
	       {
	       write_name(c);
	       i++;
	       }
	       break;
	 }
getch();
}
