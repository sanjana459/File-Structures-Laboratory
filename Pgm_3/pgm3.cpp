#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;

class student
{
  public:char name[15],usn[15],age[5],sem[5],branch[15],buffer[100];
};

void writeRecord()
{
 fstream stdinput;
 student s;
 stdinput.open("program_3.txt",ios::app|ios::out);
 if(!stdinput)
 {
   cout<<"cannot open the file in output mode";
 
   exit(0);
 }
 cout<<"\nEnter the student name       = ";
 cin>>s.name;
 cout<<"\nEnter the usn                = ";
 cin>>s.usn;
 cout<<"\nEnter the age                = ";
 cin>>s.age;
 cout<<"\nEnter the sem                = ";
 cin>>s.sem;
 cout<<"\nEnter the branch             = ";
 cin>>s.branch;

 strcpy(s.buffer,s.name);
 strcat(s.buffer,"|");
 strcat(s.buffer,s.usn);
 strcat(s.buffer,"|");
 strcat(s.buffer,s.age);
 strcat(s.buffer,"|");
 strcat(s.buffer,s.sem);
 strcat(s.buffer,"|");
 strcat(s.buffer,s.branch);
 strcat(s.buffer,"\n");

 stdinput<<s.buffer;
 stdinput.close();

}

void search()
{
   fstream find;
   char usn[15],extra[45];
   find.open("program_3.txt",ios::in);
  if(!find)
  {
    cout<<"\nUnable to open the file in input mode";
    
    exit(0);
  }
  cout<<"\nEnter the record's usn you want to search = ";
  cin>>usn;

  student s;

  while(!find.eof())
  {
   find.getline(s.name,15,'|');
   find.getline(s.usn,15,'|');
   find.getline(s.age,5,'|');
   find.getline(s.sem,5,'|');
   find.getline(s.branch,15,'\n');

   if(strcmp(s.usn,usn)==0)
   {
    cout<<"\nRecord found";
    cout<<"\nname\tusn\tage\tsem\tbranch";
    cout<<"\n"<<s.name<<"\t"<<s.usn<<"\t"<<s.age<<"\t"<<s.sem<<"\t"<<s.branch;
    find.close();
   
    return;
   }

  }

  cout<<"\nRecord not found";
  
  return;

}

void displayFile()
{
 student s;
 int c,i;
 fstream show;
 show.open("program_3.txt",ios::in);
 if(!show)
 {
   cout<<"\ncannot open the file in output mode";
  
   exit(1);
 }

 i=0;
 printf("Name\t\tUsn\t\tAge\t\tSem\t\tBranch\n");
 while(!show.eof())
 {
  show.getline(s.name,15,'|');
  show.getline(s.usn,15,'|');
  show.getline(s.age,5,'|');
  show.getline(s.sem,5,'|');
  show.getline(s.branch,15,'\n');
  printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s",s.name,s.usn,s.age,s.sem,s.branch);
  i++;
 }

 show.close();
 
}

void modify()
{
  fstream change;
  char usn[15];
  int i,j;
  student s1[100];

  change.open("program_3.txt",ios::in);
  if(!change)
  {
    cout<<"\nUnable to open the file in input mode";
    
    exit(0);
  }

  cout<<"\nEnter the usn";
  cin>>usn;

   i=0;

  while(!change.eof())
  {
  change.getline(s1[i].name,15,'|');
  change.getline(s1[i].usn,15,'|');
  change.getline(s1[i].age,5,'|');
  change.getline(s1[i].sem,5,'|');
  change.getline(s1[i].branch,15,'\n');
  i++;
  }

 i--;
 for(j=0;j<i;j++)
 {
  if(strcmp(usn,s1[j].usn)==0)
  {
    cout<<"\nThe old values of the record with usn "<<usn<<" are ";
    cout<<"\nname   = "<<s1[j].name;
    cout<<"\nusn    = "<<s1[j].usn;
    cout<<"\nage    = "<<s1[j].age;
    cout<<"\nsem    = "<<s1[j].sem;
    cout<<"\nbranch = "<<s1[j].branch;

    cout<<"\nEnter the new values \n";
    cout<<"\nname   = ";  cin>>s1[j].name;
    cout<<"\nusn    = ";  cin>>s1[j].usn;
    cout<<"\nage    = ";  cin>>s1[j].age;
    cout<<"\nsem    = ";  cin>>s1[j].sem;
    cout<<"\nbranch = ";  cin>>s1[j].branch;
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
 out1.open("program_3.txt",ios::out);
 if(!out1)
 {
  cout<<"\nUnable to open the file in output mode";

  return;
 }

 for(j=0;j<i;j++)
 {
   out1<<s1[j].name<<'|'<<s1[j].usn<<'|'
       <<s1[j].age<<'|'<<s1[j].sem<<'|'<<s1[j].branch<<'\n';
 }
  out1.close();
}

int main()
{
int choice;
for(;;)
 {
 
 cout<<"\n0:exit";
 cout<<"\n1:write to file";
 cout<<"\n2:display the file";
 cout<<"\n3:modify the file";
 cout<<"\n4:search";
 cout<<"\n\nEnter the choice";
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
