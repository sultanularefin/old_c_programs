#include<iostream>
#include<stdio.h>
#include<conio.h>
//#include<string.h>
#include<stdlib.h>
using namespace std;
char *strchr( char *str,char ch);
char *getyear(char *s);
class Employee {

    int EmpID;
    char *EmpName;
    char *DOB;
    double salary;
    public:
    Employee(int ID,char *Name,char *Date,double s)

        {
                EmpID=ID;
                EmpName=Name;
                DOB=Date;
                salary=s;

        }
    int getEmpID() {return EmpID;}
    char * getEmpName() { return EmpName;}
    void  getDOB()
                    {
                     char *y;

                     y=getyear(DOB);
                     int a;
                     a=atoi(DOB);
                     char *b=strchr(DOB,'/');
                     int c;
                     int i=0;
                     char str[10];
                     while(*b!=0){
                     str[i]=*b;
                     i++;
                     b++;
                     }

                     str[i]='\0';

                     c=atoi(str);
                     if(c==1) printf("%s","January");
                     if(c==2) printf("%s","February");
                     if(c==3) printf("%s","March");
                     if(c==4) printf("%s","April");
                     if(c==5) printf("%s","May");
                     if(c==6) printf("%s","June");
                     if(c==7) printf("%s","July");
                     if(c==8) printf("%s","August");
                     if(c==9) printf("%s","September");
                     if(c==10) printf("%s","Octeber");
                     if(c==11) printf("%s","November");
                     if(c==12) printf("%s","December");
                     printf(" %d ,",a);


                         printf(y);



                    return   ;
                    }

    double getsalary() { return salary;}
    };

int main(void){

    Employee ob(123456,"Karim","10/01/1980",30000.00);

 puts("ID       Name                 Date of Birth        Salary");
 printf("__________________________________________________________________\n");

  Employee oc(345687,"Rahim","05/12/1985",2500.00);
  Employee od(457956,"Anyone","01/04/1990",5000.00);

  cout<<ob.getEmpID()<<"        "<<ob.getEmpName()<<"       ";
  ob.getDOB();
  printf("    TK %.2f\n",ob.getsalary()) ;

 cout<<oc.getEmpID()<<"        "<<oc.getEmpName()<<"       ";
  oc.getDOB();
  printf("    TK %.2f\n",oc.getsalary()) ;

  cout<<od.getEmpID()<<"        "<<od.getEmpName()<<"       ";
  od.getDOB();
  printf("    TK %.2f\n",od.getsalary()) ;


 getch();
 return 0;


   }
char *strchr( char *str,char ch)

{


    int i=-1;
    do{ i++;
        if(*(str+i)==ch){

            return (str+(i+1));
        }
    }while (*(str+i)!='ch' && *(str+i)!='\0');    /*here && ==> short circuit and
                                                it means that only if one condition is
                                                satisfied then do loop will exit */

 return NULL;

 }

 char *getyear(char *s)

 {
     return (s+6);
 }
