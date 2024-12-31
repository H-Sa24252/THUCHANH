#include <stdio.h>
#include <math.h>

int main() 
{
    double a, b, c, p, S, ha, hb, hc;
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
  return 0;
}

