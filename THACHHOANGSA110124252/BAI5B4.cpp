#include <stdio.h>
void thuasoNT(int n);
int main() 
{   int n;
   do
  { printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    if (n <= 0) 
    printf("Vui long nhap mot so nguyen duong.\n");} 
	while(n<=0);
	{
       printf("%d = ", n);
       thuasoNT(n);
    }
   return 0;
}

void thuasoNT(int n) 
{ int i = 2;
   while (i * i <= n)
    { while (n % i == 0)
	   {
	     printf("%d", i);
          n /= i;
			{
			printf("*");
			}
       }
        i++;  }
    if (n > 1)
	 {printf("%d", n);  }}


