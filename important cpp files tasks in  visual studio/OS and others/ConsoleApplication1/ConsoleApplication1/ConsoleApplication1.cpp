// ConsoleApplication1.cpp : Defines the entry point for the console application.

#include "stdafx.h"

//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int s;
#define boot_sector_code 62
#define sector_location 11.12

int Decimal(char *string);
//  #define JOIN(a,b) a ## b
//  #difine decrement(s) i ## s

FILE *fp;


int main(void){

	int offset;
	char str[1000];
	char boot[20];


	int scan;
	char newch;
	int G;


	int a, b;   // sector location

	char ch1[4], ch2[4];
	int i;
	char ch[20];

	int f; // number of sectors per fat
	int nf; // number of file allocation tables
	int rs; //number of reserved sectors

	int rc; //root directory entry count
	int rcb; // root directory count in bytes
	int sib; //sector size in bytes

	int srd; // sectors in root directory
	int sbr; //sectors before root directory



	//if ((fp = fopen("myfile", "w+b")) == NULL){
	//	printf("cannot create file.\n");
	//	exit(1);

	//}

	if ((fp = fopen("myfile", "rb")) == NULL){
		printf("Cannot open file.\n");
		exit(1);
	}
	while (!feof(fp)){
		putchar(getc(fp));
		if (ferror(fp)){
			puts("File Error Occured");
		}
	}
	puts("______boot code:_____\n");
	printf("    Enter boot code address:  ");
	scanf("%d", &a);
	//scan = 62;
	offset = (a+1) * 3 + 7 * 4;
	//offset = 54;
	
	 fseek(fp, offset, SEEK_SET);
	//printf(" %d ", ftell(fp));

	//fread(&ch, sizeof(char), 2, fp
	fscanf(fp, "%s", boot);

	//puts("\n");
	//printf(" %d ",ftell(fp));

	puts(boot);

	/*
		putchar(*ch);
		putchar(*(ch + 1));*/

	//G = Decimal(boot);
	//	printf("%d", G);

		puts("\n");
//	 sector size begins here.
	
	puts("\n__________SECTOR SIZE____________\n ");
	puts("      Enter  location to scan for sector size (11 12):");
	scanf("%d %d", &a,&b);
	
	offset = 7 + 3 * (a);
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);

	offset = 7 + 3 * (b);
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch2);


	//printf("%d", ftell(fp));


	

		*(ch+0) = ch2[0];
		*(ch + 1) = ch2[1];
	
		*(ch+2) = ch1[0];
		*(ch+3)=ch1[1];
		*(ch + 4) = '\0';
	
	
	puts("\n");

	puts(ch);

	puts("\n");


	printf("Boot sector size : %d\n\n",Decimal(ch));

	puts("_________Cluster size in sectors_________");
	puts("      Enter  location to scan for cluster size in sector (13):");
	scanf("%d", &a);
	//(boot_sector_code + 1) * 3 + 7 * 4
	offset = (7 + 3 * (a + 1));
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);

	printf("sector size per cluster: %d\n\n",Decimal(ch1));

	puts("_________puts number of entries in the root directory_________\n\n");


	
	puts("Enter  location to scan for root direcotory (17 18):\n\n");
	scanf("%d %d", &a, &b);

	offset = (6 * 2 + 3 * (a + 1));
	
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);

	offset = (6 * 2 + 3 * (b  + 1));
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch2);


	//printf("%d", ftell(fp));




	*(ch + 0) = ch2[0];
	*(ch + 1) = ch2[1];

	*(ch + 2) = ch1[0];
	*(ch + 3) = ch1[1];
	*(ch + 4) = '\0';


	puts("\n");

	puts(ch);

	puts("\n");
	printf("number of entries in the root directory: %d\n\n",Decimal(ch));


		puts("\n_________number of sectors per file allocation table_________\n");



		puts("Enter  location to scan for the number of sectors per file allocation table :(22 23)\n\n");
		scanf("%d %d", &a, &b);

		offset = (6 * 2 + 3 * (a + 1));

		fseek(fp, offset, SEEK_SET);
		fscanf(fp, "%s", ch1);

		offset = (6 * 2 + 3 * (b + 1));
		fseek(fp, offset, SEEK_SET);
		fscanf(fp, "%s", ch2);


		//printf("%d", ftell(fp));




		*(ch + 0) = ch2[0];
		*(ch + 1) = ch2[1];

		*(ch + 2) = ch1[0];
		*(ch + 3) = ch1[1];
		*(ch + 4) = '\0';


		puts("\n");

		puts(ch);

		puts("\n");


	printf("number of sectors per file allocation table: %d", Decimal(ch));
	puts("\n");

	puts("number of rererved sectors on the disk:");


	puts("Enter  location to scan for (14 15) :");
	scanf("%d %d", &a, &b);

	offset = (7  + 3 * (a ));

	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);

	offset = (7 + 3 * (b ));
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch2);


	printf("%d", ftell(fp));

	*(ch + 0) = ch2[0];
	*(ch + 1) = ch2[1];

	*(ch + 2) = ch1[0];
	*(ch + 3) = ch1[1];
	*(ch + 4) = '\0';


	puts("\n");

	puts(ch);

	puts("\n");
	printf("number of reserved sectors on the disk: %d\n\n", Decimal(ch));
	puts("\n");

	puts("\n");
	puts("_________total number of sectors:_______________");


	puts("Enter  location to scan for (19 20) :");
	scanf("%d %d", &a, &b);

	offset = (6 * 2 + 3 * (a + 1));

	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);

	offset = (6 * 2 + 3 * (b + 1));
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch2);


	printf("%d", ftell(fp));

	*(ch + 0) = ch2[0];
	*(ch + 1) = ch2[1];

	*(ch + 2) = ch1[0];
	*(ch + 3) = ch1[1];
	*(ch + 4) = '\0';


	puts("\n");

	puts(ch);

	puts("\n");
	printf("total number of sectors: %d\n\n", Decimal(ch));


	puts("\n");
	puts("_________number of hidden sectors on the disk:_______________");


	puts("Enter  location to scan for (28, 29) :");
	scanf("%d %d", &a, &b);

	offset = (6 * 2 + 3 * (a + 1));

	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);

	offset = (6 * 2 + 3 * (b + 1));
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch2);


	//printf("%d", ftell(fp));

	*(ch + 0) = ch2[0];
	*(ch + 1) = ch2[1];

	*(ch + 2) = ch1[0];
	*(ch + 3) = ch1[1];
	*(ch + 4) = '\0';


	puts("\n");

	puts(ch);

	puts("\n");
	printf("number of hidden sectors on the disk: %d\n\n", Decimal(ch));


	

	
	puts("\n\n_________sector number of the first copy of the file allocation table:__________");
	
	
	puts("Enter  location to scan for reserved sector : (14 15 )");
	scanf("%d %d", &a, &b);
	
	offset = (7 + 3 * (a));
	
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);
	
	offset = (7 + 3 * (b));
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch2);
	
	
	printf("%d", ftell(fp));
	
	*(ch + 0) = ch2[0];
	*(ch + 1) = ch2[1];
	
	*(ch + 2) = ch1[0];
	*(ch + 3) = ch1[1];
	*(ch + 4) = '\0';
	
	
	puts("\n");
	
	puts(ch);
	
	puts("\n");
	printf("sector number of the first copy of the "
		"\n file allocation table:: %d\n\n", Decimal(ch));

	/* since reserved sector =1 (boot sector) then first copy of the file allocation table start after that so sector (0=bootsector ) +1  = first copy of file
	allocation table*/
	
	
	puts("\n\n_________sector number of the first sector of the root directory:__________\n\n");
	
	
	puts("\nEnter  location to scan for number of sectors per file allocation table : (22 23)");
	scanf("%d %d", &a, &b);
	
	offset = (6*2 + 3 * (a+1));
	
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);
	
	offset = (6*2 + 3 * (b+1));
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch2);
	
	
	//printf("%d", ftell(fp));
	
	*(ch + 0) = ch2[0];
	*(ch + 1) = ch2[1];
	
	*(ch + 2) = ch1[0];
	*(ch + 3) = ch1[1];
	*(ch + 4) = '\0';
	
	
	
	
	puts("\n");
	
	
	puts(ch);
	f=Decimal(ch);
	
	puts("___Enter location to scan for number of fat copies:___ (16) ");
	scanf(" %d", &a);
	
	offset = (6 * 2 + 3 * (a + 1));
	
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);
	
	nf=Decimal(ch1);
	puts("Enter  location to scan for reserved sectors : ( 14 15 )");
	scanf("%d %d", &a, &b);
	
	offset = (7 + 3 * (a));
	
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch1);
	
	offset = (7 + 3 * (b));
	fseek(fp, offset, SEEK_SET);
	fscanf(fp, "%s", ch2);
	
	
	//printf("%d", ftell(fp));
	
	*(ch + 0) = ch2[0];
	*(ch + 1) = ch2[1];
	
	*(ch + 2) = ch1[0];
	*(ch + 3) = ch1[1];
	*(ch + 4) = '\0';
	
	
	puts("\n");
	
	puts(ch);
	rs = Decimal(ch);
	puts("\n");
	
	puts("\n");
	printf("ssector number of the first sector of the root directory: %d\n", nf*f+rs);


puts("\n\n______sector number of the first sector of the first usable data cluster/area______");



puts("\nEnter  location to scan for number of root directory entries : (17 18)");
scanf("%d %d", &a, &b);

offset = (6*2 + 3 * (a+1));

fseek(fp, offset, SEEK_SET);
fscanf(fp, "%s", ch1);

offset = (6*2 + 3 * (b+1));
fseek(fp, offset, SEEK_SET);
fscanf(fp, "%s", ch2);


//printf("%d", ftell(fp));

*(ch + 0) = ch2[0];
*(ch + 1) = ch2[1];

*(ch + 2) = ch1[0];
*(ch + 3) = ch1[1];
*(ch + 4) = '\0';




puts("\n");


puts(ch);
rc=Decimal(ch);
rcb = rc * 32;  // rc =number of root directory entry ,and since every root directory entry is 32 bytes long . rcb = sector size in bytes


 puts("\n___Enter location to scan Sector size in bytes___( 11 12 )\n");



 scanf("%d %d", &a, &b);

 offset = (7 + 3 * (a ));

 fseek(fp, offset, SEEK_SET);
 fscanf(fp, "%s", ch1);

 offset = (7 + 3 * (b ));
 fseek(fp, offset, SEEK_SET);
 fscanf(fp, "%s", ch2);


 //printf("%d", ftell(fp));

 *(ch + 0) = ch2[0];
 *(ch + 1) = ch2[1];

 *(ch + 2) = ch1[0];
 *(ch + 3) = ch1[1];
 *(ch + 4) = '\0';




 puts("\n");


 puts(ch);
 sib = Decimal(ch); //sector size in bytes;

 srd=rcb / sib;    // number of sectors in the root directory



printf("\n\nSo each sector is %d bytes long\n", srd);

printf("\nEnter location to scan for number of fat directories:  (16 )");
scanf(" %d", &a);

offset = (6 * 2 + 3 * (a + 1));

fseek(fp, offset, SEEK_SET);
fscanf(fp, "%s", ch1);

nf=Decimal(ch1);

puts("Enter  location to scan for reserved sectors : (14 15)");
scanf("%d %d", &a, &b);

offset = (7 + 3 * (a));

fseek(fp, offset, SEEK_SET);
fscanf(fp, "%s", ch1);

offset = (7 + 3 * (b));
fseek(fp, offset, SEEK_SET);
fscanf(fp, "%s", ch2);


//printf("%d", ftell(fp));

*(ch + 0) = ch2[0];
*(ch + 1) = ch2[1];

*(ch + 2) = ch1[0];
*(ch + 3) = ch1[1];
*(ch + 4) = '\0';


puts("\n");

puts(ch);
rs = Decimal(ch);
puts("\n");
puts("\nEnter  location to scan for number of sectors per file allocation table : (22 23 )\n\n");
scanf("%d %d", &a, &b);

offset = (6*2 + 3 * (a+1));

fseek(fp, offset, SEEK_SET);
fscanf(fp, "%s", ch1);

offset = (6*2 + 3 * (b+1));
fseek(fp, offset, SEEK_SET);
fscanf(fp, "%s", ch2);


//printf("%d", ftell(fp));

*(ch + 0) = ch2[0];
*(ch + 1) = ch2[1];

*(ch + 2) = ch1[0];
*(ch + 3) = ch1[1];
*(ch + 4) = '\0';




puts("\n");


puts(ch);
f=Decimal(ch);



puts("\n");
sbr = nf * f + rs; // sectors before root directory



printf("\n\nsector number of the first sector of the root directory: %d\n", sbr);
printf("number of sectors before data area:%d\n\n\n", srd + sbr);






	fclose(fp);


	//	getch();
	return 0;



}

int Decimal(char hex[])   /* Function to convert hexadecimal to decimal. */
{
	int i, length, sum = 0;
	for (length = 0; hex[length] != '\0'; ++length);
	for (i = 0; hex[i] != '\0'; ++i, --length)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			sum += ((hex[i] - '0')*pow(16, length - 1));
		if (hex[i] >= 'A' && hex[i] <= 'F')
			sum += ((hex[i] - 55)*pow(16, length - 1));
		if (hex[i] >= 'a' && hex[i] <= 'f')
			sum += ((hex[i] - 87)*pow(16, length - 1));
	}
	return sum;
}










