/* created 
    by: abhijithvijayan
    on: 06-Jul-18
    at: 20:07
*/

#include<stdio.h>
void add(int, int);
void gen();
void store(int, int, int);
int maxVal(int A[][4]);

int Ar[6][6],i,j,max;
int A[4][4];

void main() {
int sum=0;

    for(i=0;i<6;i++) {
        for(j=0;j<6;j++) {
            scanf("%d",&Ar[i][j]);
        }
    }

    for(i=0;i<6;i++) {
        for(j=0;j<6;j++) {
            printf("%d ",Ar[i][j]);
        }
        printf("\n");
    }   
    gen();
    max=maxVal(A);
    printf("\nThe max value is %d\n",max);
}

void add(int init, int fin) {

  int i, j, sum=0, row=0, col=0; 
  
    for(i=init;i<init+3;i=i+2) {

        for(j=fin;j<fin+3;j++) {          
            sum+=Ar[i][j];
        }

        row+=i;
        j--;
        col+=j;
    }
    col-=2;

    sum+=Ar[row/2][col/2];  //middle element

    printf("%d ",sum);

    store(init,fin,sum);

}

void gen() {
    printf("The hour glass values are\n");
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            add(i,j);
            
        }
    }
}

void store(int n, int m, int val) {
    A[n][m]=val;
}

int maxVal(int A[][4]) {
    max=A[0][0];
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            if(A[i][j]>max) {
                max=A[i][j];
            } 
          }
    }
    return max;
}

/* 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 3 4 5 6 */


