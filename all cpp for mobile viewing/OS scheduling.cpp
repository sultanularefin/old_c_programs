#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

void RR(void);
void priority(void);

typedef struct {

	char name[20];
	int priority;
	int cpu_burst;

}schedule;
schedule construct[20];
int a, b;
int process_count;
int s,t;
schedule temp;

bool comp(const schedule &x ,const schedule &y){
	return x.priority > y.priority;
	
}

int main(){

	int choice;
	printf("Enter number of processes:");
	scanf("%d", &process_count);

	printf("Enter process name    | priority     | cpu_burst:   \n\n");
	for (int a = 0; a<process_count; a++){

		scanf("%s", construct[a].name);

		scanf("%d", &construct[a].priority);

		scanf("%d", &construct[a].cpu_burst);
	}

	do{
		printf("\n\n choice \n\n");

		puts("1. RR   \n");
		puts("2. Priority \n");
		puts("\n anything else to Quit.\n");

		puts("\n");
		scanf("%d", &choice);
		switch (choice){

		case 1:RR();
			break;
		case 2:priority();
			break;
		default:exit(1);
		}
	} while (choice != 'q');

	return 0;
}

void RR(void)
{
	int Time_slice;
	int max_burst = 0;
	
	printf("Enter Time_slice:   ");
	scanf("%d\n", &Time_slice);

	printf("\n------RR--------\n");

	for (a = 0; a<process_count; a++){
		if (max_burst<construct[a].cpu_burst)
			max_burst = construct[a].cpu_burst;
	}
	
	for (int loop = 0; loop <= max_burst / Time_slice; loop++)  //<= because 5/2 =2 but it may need 3 times to loop
	{

		for (s = 0; s<process_count; s++){
			t = 0;
			while (construct[s].cpu_burst > 0 && t <Time_slice)
			{
				printf("%s-", construct[s].name);
				--construct[s].cpu_burst;
				t++;
			}
		}
	}
	return;
}

void priority(void){
	
	printf("------priority scheduling--------\n");

	sort(construct, construct + process_count - 1, comp);

	for (a = 0; a<process_count; a++){
	
			printf("  %s  ", construct[a].name);
	}
	return;
}




