// tanvir.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "header.h"

void RR(void);
void priority(void);
void SJF(void);

using namespace std;

typedef struct {

	char name[20];
	int priority;
	int cpu_burst;

}schedule;

int process_count;
int a, b;

int s;

int main(){

	//vector <schedule> job;
	int choice;


	printf("Enter your choice of Scheduling Algorithm: ");

	puts("1. RR   ");
	puts("2. Priority ");
	puts("3. SJF ");
	puts("anything else to Quit.");

	
	do{
		puts("\n");
		scanf("%d", &choice);
		switch (choice){


		case 1:RR();
			break;
		case 2:priority();
			break;
		case 3:SJF();
			break;
		default:exit(1);
		}
	} while (choice != 'q');


	getch();
	return 0;

}



