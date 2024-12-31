#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void tongcacchuso(int n, int donvi, int chuc, int tram, int tong, int tich);
void sohoanhao(int n, int i, int tongUC);
void thutrongtuan(int n);
void xettamgiac(double a, double b, double c, double p, double S, double ha, double hb, double hc);
void thuasoNT(int n);

int main()
{ int n, tram, chuc, donvi, tong, tich, i, tongUC=0,a, b, c, p, S, ha, hb, hc,key;
  while(true)
    {
    	system("cls");
    	printf("*************************************************\n");
    	printf("**             AN PHIM CHON DE THUC HIEN       **\n");
    	printf("**         1. Tinh tong cac chu so             **\n");
    	printf("**         2. So hoan hao                      **\n");
    	printf("**         3. Thu trong tuan                   **\n");
    	printf("**         4. Xet tam giac                     **\n");
    	printf("**         5. Thua so nguyen to                **\n");
    	printf("**         0. Thoat                            **\n");
    	printf("*************************************************\n");
    	printf("\n   \t\t    AN PHIM CHON: ");
    	scanf("%d",&key);
    	switch(key)
    	    {
    	    case 1:
			    fflush(stdin);
			    tongcacchuso(n,donvi,chuc,tram,tong,tich);
			    printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                sohoanhao(n,i,tongUC);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                thutrongtuan(n);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                xettamgiac(a,b,c,p,S,ha,hb,hc);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
                thuasoNT(n);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 0:
                exit(1);
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
void tongcacchuso(int n, int donvi, int chuc, int tram, int tong, int tich)
{
    do {
        printf("Nhap vao mot so nguyen duong co 3 chu so: ");
        scanf("%d", &n);
        if (n < 100 || n > 999) 
            printf("Vui long nhap mot so nguyen duong co 3 chu so!\n");
       }
	    while (n < 100 || n > 999); 
              tram = n / 100;          
    		  chuc = (n/10)% 10;   
   			  donvi= n % 10;         
              tong = tram + chuc + donvi;
			  tich = tram * chuc * donvi; 
    printf("Tong cac chu so = %d\n", tong);
    printf("Tich cac chu so = %d\n", tich);
}
void sohoanhao(int n, int i,int tongUC)
{
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
}

void thutrongtuan(int n)
{
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
}

void xettamgiac(double a, double b, double c, double p, double S, double ha, double hb, double hc)
{   
    do
    { printf("Nhap ba canh cua tam giac (a, b, c): ");
      scanf("%lf %lf %lf", &a, &b, &c);
      if(a+b<c||a+c<b||b+c<a)
        printf("Ba canh khong tao thanh mot tam giac.\n");
    }while(a+b<c||a+c<b||b+c<a);
    { if (a == b && b == c)  
	   {
		printf("Day la tam giac deu.\n");
	   }
        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) 
		{
            printf("Day la tam giac vuong.\n");
        }
        else if (a == b || a == c || b == c)
		 {
            printf("Day la tam giac can.\n");
        }
        else {
            printf("Day la tam giac thuong.\n");
        }
    }
    p = (a + b + c) / 2.0;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    ha = (2 * S) / a;
    hb = (2 * S) / b;
    hc = (2 * S) / c;
    printf("Dien tich tam giac: %.0f\n", S);
    printf("Chieu dai duong cao ha: %.0f\n", ha);
    printf("Chieu dai duong cao hb: %.0f\n", hb);
    printf("Chieu dai duong cao hc: %.0f\n", hc);
}
    
void thuasoNT(int n) 
{  do
  { printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    if (n <= 0) 
    printf("Vui long nhap mot so nguyen duong.\n");} 
	while(n<=0); 
 int i = 2;
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

