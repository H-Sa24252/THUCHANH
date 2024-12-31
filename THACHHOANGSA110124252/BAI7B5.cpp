#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>

void nhap1c(int a[50],int &n);
void xuat1c(int a[50],int n);
void timmaxmin(int a[50],int n);
void chenXvaoK(int a[50],int &n,int x,int k);

int main()
{ int a[50],n,x,k, key;
 while(true)
   {
   	  system("cls");
   	  printf("******************************************************\n");
   	  printf("**         CAC THAO TAC TREN MANG 1 CHIEU           **\n");
   	  printf("**         1. Nhap mang 1 chieu                     **\n");
   	  printf("**         2. Xuat mang 1 chieu                     **\n");
   	  printf("**         3. Tim so NT Max, Min                    **\n");
   	  printf("**         4. Chen x vao vi tri k                   **\n");
   	  printf("**         5. Nhap a xoa phan bang a                **\n");
   	  printf("**         0. Thoat                                 **\n");
   	  printf("******************************************************\n");
   	  printf("\n    \t\t    AN PHIM CHON: ");
   	  scanf("%d",&key);
   	  switch(key)
   	    {
   	     case 1:
   	     	 fflush(stdin);
   	     	 nhap1c(a,n);
   	     	 printf("\n Bam phim bat ky de tiep tuc!");
   	     	 getch();
   	     	 break;
   	     case 2:
   	     	 xuat1c(a,n);
   	     	 printf("\n Bam phim bat ky de tiep tuc!");
   	     	 getch();
   	     	 break;
   	     case 3:
   	     	 timmaxmin(a,n);
   	     	 printf("\n Bam phim bat ky de tiep tuc!");
   	     	 getch();
   	     	 break;
   	     case 4:
   	     	 chenXvaoK(a,n,x,k);
   	     	 printf("\n Bam phim bat ky de tiep tuc!");
   	     	 getch();
   	     	 break;
   	     case 0:
   	     	 exit(1);
   	       default:
   	       	  printf("\n Khong co chuc nang nay!");
   	       	  printf("\n Bam phim bat ky de tiep tuc!");
   	       	  getch();
   	       	  break;
   	    }
   }
}
void nhap1c(int a[50],int &n)
{
	 printf("\n Nhap so phan tu mang: ");
	 scanf("%d",&n);
	for(int i=0;i<n;i++)
	  {
	  	printf("\n Nhap phan tu thu %d ",i);
	  	scanf("%d",&a[i]);
	  }
}


void xuat1c(int a[50],int n)
{
	printf("\n CAC PHAN TU MANG LA : ");
	   for(int i=0;i<n;i++)
	   printf("\t %d",a[i]);
}

void timmaxmin(int a[50],int n)
{ int max, min;
     for(int i=0;i<n;i++)
     {
      if (max<a[i])
     	max=a[i];
    else
         max=max;
      if(min>a[i])
         min=a[i];
    else
         min=min;
     }
printf("\n Phan tu lon nhat trong mang la %d",max);
printf("\n Phan tu nho nhat la %d",min);
}
void chenXvaoK(int a[50], int &n, int x, int k) 
{     printf("Nhap gia tri x can chen: ");
      scanf("%d", &x);
      printf("Nhap vi tri k: ");
      scanf("%d", &k);
    if (k < 0 || k > n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    (n)++;
    printf("Da chen %d vao vi tri %d.\n", x, k);
}

