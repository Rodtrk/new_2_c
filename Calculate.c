#include <trsh.h>
#include <string.h>
#include <stdio.h>
#define size 1000
/* 
 * This will calucalte 
 */
int main(){
	char op;
	printf("chose ([+],[*],[-],[/])\t:");
	scanf("%c",&op) ;
	double no,num,t ;
	printf("operands : \t");
	scanf("%lf  %lf", &no, &num) ;

	switch(op){
		case '+':
      		        printf("%.1lf + %.1lf = %.1lf \n",no,num,no+num) ;
		        break ;
		case '*':
			t = (no * num);
			printf("%lf\n:%f",no*num,t) ;
			break;
		case '-':
			
			printf("%lf\n",no-num);
			break;
		case '/':
			
			printf("%lf\n",no/num);
			break;

		default:
			printf("i,m new programmer ,so make no change \n");
	}


}
