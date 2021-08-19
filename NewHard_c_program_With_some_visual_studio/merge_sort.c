
#include "stdio.h"
#include "conio.h"
int array[100];

void split(int array[],int low,int high);
void merge(int array[],int left,int middle1,int middle2,int right);

int main()
{

	int count;
	printf("Enter number of inputs : \n\n" );
	scanf("%d",&count);

	int i;
    printf("\n\n");

	for( i=0;i<count;i++) scanf("%d",&array[i]);
	
	printf("\n\n");
	
	printf("UnSorted array holo :  ");
	for( i=0;i<count;i++) printf(" %d",array[i]);
	
	printf("\n\n\n");
	
	split(array,0,count-1);
	printf("Sorted array holo :  ");

	for( i=0;i<count;i++) printf("  %d",array[i]);
	getch();
	return 0;
}

void split(int array[],int low,int high) {

    int middle1,middle2;

    if(high-low>=1) {
    middle1=(low+high)/2;
    middle2=middle1+1;
    
    // split array in half and sort each half recursively
	split(array,low,middle1); // first half
    split(array,middle2,high); //second half

    merge(array,low,middle1,middle2,high); // merge the two sorted arrays
   }

 }

void merge(int array[],int left,int middle1,int middle2,int right)


    {
        int leftindex=left;				// index into left subarray
        int rightindex=middle2;			// index into right subarray
        int combinedindex=left;			// index into temporara array
        int tempArray[100];				// temporary array
        
		int i;
        while(leftindex<=middle1 &&rightindex<=right){

        if(array[leftindex]<=array[rightindex])
            tempArray[combinedindex++]=array[leftindex++];
        else
            tempArray[combinedindex++]=array[rightindex++];
       }

        if(leftindex==middle2) 		// if at end of left subarray....
		{
        while(rightindex<=right)
        tempArray[combinedindex++] = array[rightindex++];

        }

     else			//if at end of right subarray...
     {
         while(leftindex<=middle1)
         tempArray[combinedindex++]=array[leftindex++];
     }

        for(i=left;i<=right;i++)	//copy values back into original array
        array[i]=tempArray[i];

}
