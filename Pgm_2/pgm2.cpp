#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std; 

class student
{
public:
char name[15],usn[15],age[5],sem[5],branch[15],buffer[45];
};

void writeRecord() //Function to add record to file
{
fstream stdinput;
student s;
stdinput.open("student.txt",ios::app|ios::out); //Open file in append mode
if(!stdinput)
{
cout<<"cannot open the file in append mode";
exit(1);
}
cout<<"\nEnter the student name = ";
cin>>s.name;
cout<<"\nEnter the usn = ";
cin>>s.usn;
cout<<"\nEnter the age = ";
cin>>s.age;
cout<<"\nEnter the sem = ";
cin>>s.sem;
cout<<"\nEnter the branch = ";
cin>>s.branch;

//packing the information
strcpy(s.buffer,s.name);
strcat(s.buffer,"|");
strcat(s.buffer,s.usn);
strcat(s.buffer,"|");
strcat(s.buffer,s.age);
strcat(s.buffer,"|");
strcat(s.buffer,s.sem);
strcat(s.buffer,"|");
strcat(s.buffer,s.branch);

int count=strlen(s.buffer);
for(int k=0;k<45-count;k++)
strcat(s.buffer,"!");
strcat(s.buffer,"\n");
stdinput<<s.buffer; //writing the packed information to buffer
stdinput.close();
}

void search()
{
fstream find;
char usn[15],extra[45];
student s;
find.open("student.txt",ios::in);
if(!find)
{
cout<<"\nUnable to open the file in read mode";
exit(0);
}
cout<<"\nEnter the record's usn you want to search = ";
cin>>usn;

//Unpacking the record

while(!find.eof())
{
find.getline(s.name,15,'|');
find.getline(s.usn,15,'|');
find.getline(s.age,5,'|');
find.getline(s.sem,5,'|');
find.getline(s.branch,15,'!');
find.getline(extra,45,'\n');

if(strcmp(s.usn,usn)==0)
{
cout<<"\nRecord found";
cout<<"\n"<<s.name<<"\t"<<s.usn<<"\t"<<s.age<<"\t"<<s.sem<<"\t"<<s.branch;
find.close();
return;
}
}
cout<<"\nRecord not found";
find.close();
return;
}

void displayFile()
{
student s;
int c,i;
char extra[45];
fstream show;
show.open("student.txt",ios::in);

if(!show)
{
cout<<"\ncannot open the file in read mode";
exit(1);
}
i=0;
printf("\n\nNAME\t\tUSN\t\tAGE\t\tSEM\t\tBRANCH \n");
printf("----\t\t---\t\t---\t\t---\t\t------\n");
while(!show.eof())
{
show.getline(s.name,15,'|');
show.getline(s.usn,15,'|');
show.getline(s.age,5,'|');
show.getline(s.sem,5,'|');
show.getline(s.branch,15,'!');
show.getline(extra,45,'\n');
printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s",s.name,s.usn,s.age,s.sem,s.branch);
i++;
}
show.close();
}

void modify()
{
fstream change;
char usn[15],buffer[45],extra[45];
int i,j;
student s1[20];

change.open("student.txt",ios::in);

if(!change)
{
cout<<"\nUnable to open the file in input mode";
exit(1);
}

cout<<"\nEnter the usn of the record to be modified ";
cin>>usn;

i=0;

//Loading the file to Main memory

while(!change.eof())
{
change.getline(s1[i].name,15,'|');
change.getline(s1[i].usn,15,'|');
change.getline(s1[i].age,5,'|');
change.getline(s1[i].sem,5,'|');
change.getline(s1[i].branch,15,'!');
change.getline(extra,45,'\n');
i++;
}
i--;

for(j=0;j<i;j++)
{
if(strcmp(usn,s1[j].usn)==0)
{
cout<<"\nThe old values of the record with usn "<<usn<<" are ";
cout<<"\nname = "<<s1[j].name;
cout<<"\nusn = "<<s1[j].usn;
cout<<"\nage = "<<s1[j].age;
cout<<"\nsem = "<<s1[j].sem;
cout<<"\nbranch = "<<s1[j].branch;

cout<<"\nEnter the new values \n";
cout<<"\nname = "; cin>>s1[j].name;
cout<<"\nusn = "; cin>>s1[j].usn;
cout<<"\nage = "; cin>>s1[j].age;
cout<<"\nsem = "; cin>>s1[j].sem;
cout<<"\nbranch = "; cin>>s1[j].branch;
break;
}
}

if(j==i)
{
cout<<"\nThe record with usn "<<usn<<" is not present";
return;
}
change.close();
fstream out1;
out1.open("student.txt",ios::out);
if(!out1)
{
cout<<"\nUnable to open the file in output mode";
return;
}

for(j=0;j<i;j++)
{
strcpy(buffer,s1[j].name);
strcat(buffer,"|");
strcat(buffer,s1[j].usn);
strcat(buffer,"|");
strcat(buffer,s1[j].age);
strcat(buffer,"|");
strcat(buffer,s1[j].sem);
strcat(buffer,"|");
strcat(buffer,s1[j].branch);

int count=strlen(buffer);
for(int k=0;k<45-count;k++)
strcat(buffer,"!");

strcat(buffer,"\n");

out1 << buffer;
}
out1.close();
}

int main()
{

int choice;
for(;;)
{
cout<<"\n  0 : exit";
cout<<"\n  1 : write to file";
cout<<"\n  2 : display the file";
cout<<"\n  3 : modify the file";
cout<<"\n  4 : search";
cout<<"\n\n Enter the choice :  ";
cin>>choice;

switch(choice)

{
case 1:writeRecord();break;
case 2:displayFile();break;
case 3:modify();break;
case 4:search();break;
case 0:exit(0);
default:cout<<"\nInvalid input....";break;
}
}
return 0;
}
