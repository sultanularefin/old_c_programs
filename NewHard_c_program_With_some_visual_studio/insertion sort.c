/* insertion sort ascending order */

#include<stdio.h>
void insertion_sort(int array[],int size);
main()
{
   int array[100], n, c, d, swap, k;

   printf("Enter number of elements\n");
   scanf("%d", &n);

   printf("Enter %d integers\n", n);

   for ( c = 0 ; c < n ; c++ )
       scanf("%d", &array[c]);
       
   printf("Unsorted array :\n");
   for(c=0;c<n;c++) printf(" %d ",array[c]);
   
   
   insertion_sort(array,n);
   
   printf("\n\n\nSorted array : ");
   for(c=0;c<n;c++) printf(" %d ",array[c]);
   
 	printf("\n\n\n"); 
   return 0;
}


void insertion_sort(int array[],int size) 

{
	
	int insert; // temporary variable to hold element to insert 
	
	int i;	//  int used in for loop
	
	//loop over size-1 element 
	for(i=1;i<size;i++) {
		
		int moveItem=i; // initialize location to place element 
		
		insert=array[i];
		
		/* search for place to put current element */
		
		while(moveItem>0 && array [moveItem-1]>insert)
		
		{
			//shift element right on slot 
			array[moveItem]=array[moveItem-1];
			--moveItem;
		
		} // end while
		
		array[moveItem]=insert; /* place inserted element */
	
		
	} // end for loop

} // end function insertion sort
	
