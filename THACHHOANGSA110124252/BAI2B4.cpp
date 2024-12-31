#include <stdio.h>
#include <conio.h>
int main() 
{
    int n, i, tongUC=0;
    do{
    printf("Nhap vao mot so nguyen duong n: ");
    scanf("%d", &n);
    if(n<=1)
      printf("\nVui long nhap lai mot so nguyen duong!\n");}
    while(n<=1);
    for (i=1; i<=n/2; i++) 
       { if(n%i==0) 
           tongUC=tongUC+i; }
    if(tongUC==n) 
        printf("%d la so hoan hao.\n", n);
    else 
        printf("%d khong phai la so hoan hao.\n", n);
    return 0;
}

