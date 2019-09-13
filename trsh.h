#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<strings.h>
#include <term.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <crypt.h>
#include <ncurses.h>
//  FIXME: #include <python3.7/python.h>
#include <stdlib.h>
#include <err.h>
#include <strings.h>
#include <sys/socket.h>
#define me 0.1 //version header
size_t *ofint;
FILE *fip;
fpos_t sav;
typedef int trsh_A;
struct mode {
	char name[100];
	long int flo;
};
struct mode trk;
static char callmeT; 
char *(trustful);
/*
 * FIXME: let find array
 * /
 */
int arr[10] = {13,4,56,78,90,57,1,23,12,71};
char arrayz[100];

double *(number1);
int *(number2);
volatile int hmm;

/*
 * FIXME: for factorial number
 */
int fac(int i){
	int a,b,c=1;
	printf("Enter some digit");
	scanf("%d",&b);

	for(a=1;a<=b;a++){
		c = c * b;
	}
	
}

int factorial(){
	int a,b,c=1,z;
	printf("Enter the factorial number or digit:");
	scanf("%d", &z);
	if(z==0)
		printf("catch error occur\n");
	        exit(0);
	for(b=1;b<=z;b++){
		c = c * b;
	}	
printf("\nFactorial number of %d\n is = %d\n",z,c);
/*	do{
		printf("\n%d\n",z);
		--z;
	}while(0<z);
	*/
}
int job(){
	int time,work,empl;
	printf("Enter the worker time:");
	scanf("%d",&time);
	work = 1;
	while(time<=40){
		work = work * 12;
		empl++;
	}
	printf("the amount of worker is %d",work);

}
int ascii(){
	int ijk;
}
