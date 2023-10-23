

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
public:char rrn[10],usn[10],name[10],sem[10],dept[10],buffer[45];
};
int count=0;
void pack()
{
student s;
cout<<"enter usn name sem dept\n";
cin>>s.usn>>s.name>>s.sem>>s.dept;
ofstream ofile;
ofile.open("anb.txt",ios::app);
char str[10];

sprintf(str,"%d",count);
strcpy(s.buffer,str);strcat(s.buffer,"|");
strcat(s.buffer,s.usn);strcat(s.buffer,"|");
strcat(s.buffer,s.name);strcat(s.buffer,"|");
strcat(s.buffer,s.sem);strcat(s.buffer,"|");
strcat(s.buffer,s.dept);strcat(s.buffer,"\n");
count++;
ofile<<s.buffer;
ofile.close();
}

void unpack()
{
student s;
ifstream a;
a.open("anb.txt",ios::in);
cout<<"rrn\tusn\tname\tsem\tdept\n";
while(!a.eof())
{
a.getline(s.rrn,10,'|');
a.getline(s.usn,10,'|');
a.getline(s.name,10,'|');
a.getline(s.sem,10,'|');
a.getline(s.dept,10,'\n');
cout<<s.rrn<<"\t"<<s.usn<<"\t"<<s.name<<"\t"<<s.sem<<"\t"<<s.dept<<"\n";
}
a.close();
}

void srch()
{
char rrn[10];
student s;
ifstream a;
a.open("anb.txt",ios::in);
cout<<"enter the rrn to be searched\n";
cin>>rrn;
while(!a.eof())
{
a.getline(s.rrn,10,'|');
a.getline(s.usn,10,'|');
a.getline(s.name,10,'|');
a.getline(s.sem,10,'|');
a.getline(s.dept,10,'\n');
if(strcmp(rrn,s.rrn)==0)
{
cout<<"record found\n";
cout<<s.rrn<<" "<<s.usn<<" "<<s.name<<" "<<s.sem<<" "<<s.dept<<"\n";
a.close();
return;
}

}
cout<<"incorrect rrn\n";
a.close();
return;
}

int main()
{
int ch;
for(;;)
{
cout<<"1.add,2.display,3.search,4.exit\n";
cin>>ch;
switch(ch)
{
case 1:pack();break;
case 2:unpack();break;
case 3:srch();break;
case 4:exit(0);break;
default:cout<<"invallid choice\n";
	
}
}
return 0;
}
