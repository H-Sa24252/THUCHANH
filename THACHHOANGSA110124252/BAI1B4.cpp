#include <stdio.h>
#include <conio.h>
int main() 
{
    int n, tram, chuc, donvi, tong, tich;
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

    return 0;
}

