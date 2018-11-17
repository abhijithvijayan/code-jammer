#include<stdio.h>

void main() {
    int Ar[10], i,j,k;
    int n, size,tmp;

    scanf("%d",&size);
    scanf("%d",&n);

    for(i=0;i<size;i++) {
        scanf("%d", &Ar[i]);
    }

    for(k=0;k<n;k++){
        for(j=0;j<size-1;j++) {
            tmp=Ar[j];
            Ar[j]=Ar[j+1];
            Ar[j+1]=tmp;
        }
    }

    for(i=0;i<size;i++) {
        printf("%d ",Ar[i]);
    }
}