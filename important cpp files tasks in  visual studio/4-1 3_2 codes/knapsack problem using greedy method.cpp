/*
What actually Problem Says ?

Given a set of items, each with a weight and a value.

Determine the number of each item to include in a collection so that the total weight is less than a given limit and the total value is
as large as possible.

It derives its name from the problem faced by someone who is constrained by a fixed-size knapsack and must fill it with the most 
useful items.

knapsack = A bag carried by a strap on your back or shoulder
Program :

*/

# include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
	float x[20], tp = 0,tw = 0;

	int i, j, u;
	u = capacity;

	for (i = 0; i < n; i++)
		x[i] = 0.0;					// initialize array x[i] to 0's

	for (i = 0; i < n; i++) {
		if (weight[i] > u)		// u is capacity
			break;
		else {
			x[i] = 1.0;					/* 1.0 means quantitiy 1 in the bag. such as i items count is 1, fraction means that 
			item was not taken as a whole but fraction of that items weight to take total capacity(e.g. 15) and profit [i]. */
			tp = tp + profit[i];		//tp = total profit
			tw = tw + weight[i];		// tw = total weight	
			u = u - weight[i];				
		}
	}

	if (i < n)
		x[i] = u / weight[i];		/*x[i]==1.0 MEANS ONE ITEM IF X[I]=FRACTION THNE , IT MEANS NOT 1 WHOLE ITEM 
									WHICH IS NEEDED TO COMPLETE THE GIVEN   capacity     */

	tp = tp + (x[i] * profit[i]);

	printf("\nThe result vector is: ");
	for (i = 0; i < n; i++)
		printf("%f\t", x[i]);

	printf("\nMaximum profit is: %f", tp);

}

int main() {
	float weight[20], profit[20], capacity;
	int num, i, j;
	float ratio[20], temp;

	printf("\nEnter the no. of objects:- ");
	scanf_s("%d", &num);

	printf("\nEnter the wts and profits of each object:- ");
	for (i = 0; i < num; i++) {
		scanf_s("%f %f", &weight[i], &profit[i]);
	}

	printf("\nEnter the capacityacity of knapsack:- ");
	scanf_s("%f", &capacity);

	for (i = 0; i < num; i++) {
		ratio[i] = profit[i] / weight[i];
	}

	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {		//  like bubble sort , bubble sorting occuring here.
											// sorting all of them in descending order , by ratio
			if (ratio[i] < ratio[j]) {
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;

				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;

				temp = profit[j];
				profit[j] = profit[i];		
				profit[i] = temp;		
				/*				whoever 's ratio is greater that is summed with tp, at last where there is no position to
				take integer weight then fraction is added like you have added weigh 13 in the bag(15 is total that you can 
				take ) and the last thing you can take have weight 3 not 2 (13 + 2) = 15 then we take 2 and for that the 
				fraction of profit */		
			}
		}
	}

	knapsack(num, weight, profit, capacity);
	return(0);
}


/*

Enter the no. of objects:- 7

Enter the wts and profits of each object:-
2 10
3 5
5 15
7 7
1 6
4 18
1 3

Enter the capacity of knapsack:- 15

The result vector is:- 1.000000        1.000000        1.000000        1.000000
1.000000        0.666667        0.000000

Maximum profit is:- 55.333332

*/
