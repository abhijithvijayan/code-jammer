/*
 	Solution by: Abhijith V
 	Programming Language: C

*/

#include<stdio.h>
#include<string.h>

void read();
int swap(char str[],int n);
int count(char str[]);

int n,countCharge=1;
char str[50];

void main() {
	int t,swpCount,shoot,k;

	printf("Enter the number of test cases: ");
	scanf("%d",&t);
	0
	for(k=1;k<=t;k++) {
		printf("\nTest case #%d\n",k);
		read();

		if((shoot=count(str))>n) {

			if(!countCharge) {		/* FOR NOT SWAPPING ALGORITHM WHICH HAS NO C (i.e. Charge) in it. eg: SSSSS */
				printf("No hacks Possible!! The Universe is DOOMED!!!\n");
				countCharge=1;		/* RESET */
				continue;
			}

			swpCount=swap(str,n);
			printf("Swapped algorithm is %s\n",str);
			if(swpCount)
				printf("The minimum number of hacks required is %d\n",swpCount);
			else 
				printf("Still no luck after hacks!! The Universe is DOOMED!!!\n");
		}

		else 
			printf("No hacks needed. Alien Robot is stupid\n");
	}
}

void read() {
	int i,FLAG=0;
	printf("Enter the robot's program (C for Charge and S for Shoot): ");
	scanf("%s", str);
	// printf("Entered algorithm is %s\n",str);
/*	for(i=0;str[i]!='\0';i++) {	
		if(str[i]!='C') //  || str[i]!='S') 
		{
			FLAG=1;
			printf("Invalid! Use correct letters!\n");
			break;
		}
	}
	if(FLAG)
		read();    */

	printf("Enter the maximum total damage shield can withstand: ");
	scanf("%d",&n);
}

int count(char str[]) {
	int c=1,s=0,i;
	for(i=0;str[i]!='\0';i++) {
		if(str[i]=='C') {
			c*=2;
		}
		else if(str[i]=='S') {
			s+=c;
		}
	}
	if(c==1)	/* FLAG FOR MANAGING ALGORITHM WHICH HAS NO 'C' (i.e. Charge) in it. eg: SSSSS */
		countCharge=0;	
	return s;
}

int swap(char str[], int n) {
	char temp;
	int len=strlen(str);
	int i,j,swpCount=0,s;
	for(j=0;j<len-1;j++) {
		for(i=0;i<len-1-j;i++) {
			if(str[i]<str[i+1]) {		/* swap when C is to the left of S. eg: CS -> SC*/
				swpCount++;
				temp=str[i];
				str[i]=str[i+1];
				str[i+1]=temp;
			}
			if((s=count(str))<=n) {
				return swpCount;
			}
		}
	}
	if((s=count(str))>n) {	/* when no hacks can help */
		return 0;
	}
}
