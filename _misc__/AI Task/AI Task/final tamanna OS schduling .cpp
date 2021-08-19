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
int s, t;
schedule temp;

bool comp(const schedule &x, const schedule &y){
	return x.priority > y.priority;

}

int main(){

	int Time_slice;
	int max_burst = 0;

	printf("Enter number of processes:");
	scanf("%d", &process_count);

	printf("Enter process name    | priority     | cpu_burst:   \n\n");
	for (int a = 0; a < process_count; a++){

		scanf("%s", construct[a].name);

		scanf("%d", &construct[a].priority);

		scanf("%d", &construct[a].cpu_burst);
	}

	// start of Round robin
	

	printf("Enter Time_slice:   ");
	scanf("%d", &Time_slice);

	printf("\n------RR--------\n");

	for (a = 0; a < process_count; a++){
		if (max_burst < construct[a].cpu_burst)
			max_burst = construct[a].cpu_burst;
	}

	printf("\n max cpu burst : %d\n\n\n", max_burst);

	for (int loop = 0; loop <= max_burst / Time_slice; loop++)  //<= because 5/2 =2 but it may need 3 times to loop
	{

		for (s = 0; s < process_count; s++){
			t = 0;
			while (construct[s].cpu_burst > 0 && t < Time_slice)
			{
				printf("%s-", construct[s].name);
				--construct[s].cpu_burst;
				t++;
			}
		}
	}

	// start of priority scheduling

	printf("\n\n------priority scheduling--------\n\n");

	sort(construct, construct + process_count - 1, comp);

	for (a = 0; a < process_count; a++){

		printf("  %s  ", construct[a].name);
	}

	return 0;
}










