#include <stdio.h>
#include <conio.h>
int main() 
{ int n;
    do
    {  printf("Nhap vao mot so nguyen duong n : ");
       scanf("%d", &n);
    if(n < 1 || n > 7)
       printf("Gia tri khong hop le! Vui long nhap lai.\n");
    }
    while (n<1 || n>7); 
    switch(n) 
	{   case 1:
            printf("Sunday\n");
            break;
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
        case 7:
            printf("Saturday\n");
            break;
    }
  return 0;
}

