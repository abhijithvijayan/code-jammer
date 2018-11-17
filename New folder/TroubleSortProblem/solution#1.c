/*
 	Solution by: Abhijith V
 	Programming Language: C

*/

#include<stdio.h>

int read();
int isSorted(int [],int);
int troubleSort(int [],int);

int Ar[20],res;

void main() {
	int t,i,flag;			// don't use i as a global var
	printf("Enter the number of test cases: ");
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		flag=read();
		printf("\n");
		if(flag<0)
			printf("Case #%d: Successfully Sorted\n",i);
		else 
			printf("Case #%d: First sorting error at index #%d\n",i,flag);
	}

}

int read() {
	int n,i;
	printf("\nHow many numbers: ");
	scanf("%d",&n);
	printf("Enter the numbers: ");
	for(i=0;i<n;i++)
		scanf("%d",&Ar[i]);
	res=troubleSort(Ar,n);
	return res;
}

int troubleSort(int Ar[],int n) {
	int flag=0,i,tmp;
	while(!flag) {
		flag=1;
		for(i=0;i<n-2;i++) {
			if(Ar[i]>Ar[i+2]) {
				flag=0;
				tmp=Ar[i];
				Ar[i]=Ar[i+2];
				Ar[i+2]=tmp;
			}
		}
	}
	printf("Final List\n");
	for(i=0;i<n;i++)
		printf("%d ",Ar[i]);
	res=isSorted(Ar,n);
	return res;
}

int isSorted(int Ar[],int n) {
	int res=0,i;
	for(i=0;i<n-1;i++) {
		if(Ar[i]>Ar[i+1])
			return i;
	}
	return -1;
}	