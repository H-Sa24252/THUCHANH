#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool laSoNguyenTo(int so) 
{
    if (so < 2) return false;
    for (int i = 2; i * i <= so; i++)
	{
        if (so % i == 0) return false;
    }
    return true;
}

int tongChuSo(int so)
 {
    int tong = 0;
    while (so > 0)
    {
        tong += so % 10;
        so /= 10;
     }
    return tong;
 }

void nhapMaTran(int a[MAX][MAX], int m, int n) 
{
    for (int i = 0; i < m; i++)
	{
        for (int j = 0; j < n; j++) 
	    {
            do
			{
                printf("Nhap phan tu tai a[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            } while (!laSoNguyenTo(a[i][j]) || a[i][j] <= 0 || a[i][j] >= 97);
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int m, int n)
{
    printf("Ma tran:\n");
    for (int i = 0; i < m; i++)
	{
        for (int j = 0; j < n; j++) 
		{
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void xuatPhanTuChiaHetCho2(int a[MAX][MAX], int m, int n) 
{
    printf("Cac phan tu có tong chu so chia het cho 2:\n");
    for (int i = 0; i < m; i++)
	{
        for (int j = 0; j < n; j++)
		{
            if (tongChuSo(a[i][j]) % 2 == 0) 
			{
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

int tongPhanTuKhongChiaHetCho2(int a[MAX][MAX], int m, int n)
{
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (tongChuSo(a[i][j]) % 2 != 0) 
			{
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int timMinTrenDongK(int a[MAX][MAX], int n, int k) 
{
    int min = a[k][0];
    for (int j = 1; j < n; j++) 
	{
        if (a[k][j] < min) 
		{
            min = a[k][j];
        }
    }
    return min;
}

int tichCacPhanTuTrenCotK(int a[MAX][MAX], int m, int k) 
{
    int tich = 1;
    for (int i = 0; i < m; i++) {
        tich *= a[i][k];
    }
    return tich;
}

void sapXepMaTran(int a[MAX][MAX], int m, int n)
 {
    int temp[MAX * MAX];
    int idx = 0;

    for (int i = 0; i < m; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            temp[idx++] = a[i][j];
        }
    }

    for (int i = 0; i < idx - 1; i++) 
    {
        for (int j = i + 1; j < idx; j++) 
		{
            if (temp[i] > temp[j]) 
			{
                int tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }

    idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = temp[idx++];
        }
    }
}

void timMaxMinDuongCheoChinh(int a[MAX][MAX], int m) 
{
    int max = a[0][0], min = a[0][0];
    for (int i = 0; i < m; i++) 
	{
        if (a[i][i] > max) max = a[i][i];
        if (a[i][i] < min) min = a[i][i];
    }
    printf("Phan tu lon nhat tren duong cheo chinh: %d\n", max);
    printf("Phan tu nho nhat tren duong cheo chinh: %d\n", min);
}

int main() {
    int a[MAX][MAX], m, n, luaChon, k;

    do {
        printf("\nMenu:\n");
        printf("1. Nhap ma tran \n");
        printf("2. Xuat ma tran \n");
        printf("3. Xuat cac phan tu co tong chu so chia het cho 2\n");
        printf("4. Tinh tong phan tu co tong chu so khong chia het cho 2\n");
        printf("5. Tim phan tu nho nhat tren dong k\n");
        printf("6. Tinh tich cac phan tu tren cot k\n");
        printf("7. Sap xep ma tran tang dan\n");
        printf("8. Nhap ma tran vuong và tim max, min tren duong cheo chinh\n");
        printf("0. Thoat \n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so dong (m): ");
                scanf("%d", &m);
                printf("Nhap so cot (n): ");
                scanf("%d", &n);
                nhapMaTran(a, m, n);
                break;
            case 2:
                xuatMaTran(a, m, n);
                break;
            case 3:
                xuatPhanTuChiaHetCho2(a, m, n);
                break;
            case 4:
                printf("Tong cac phan tu khong chia het cho 2: %d\n", tongPhanTuKhongChiaHetCho2(a, m, n));
                break;
            case 5:
                printf("Nhap dong k: ");
                scanf("%d", &k);
                if (k >= 0 && k < m) {
                    printf("Phan tu nho nhat tren dong %d: %d\n", k, timMinTrenDongK(a, n, k));
                } else {
                    printf("Dong k khong hop le !\n");
                }
                break;
            case 6:
                printf("Nhap cot k: ");
                scanf("%d", &k);
                if (k >= 0 && k < n) {
                    printf("Tich cac phan tu tren cot %d: %d\n", k, tichCacPhanTuTrenCotK(a, m, k));
                } else {
                    printf("Cot k khong hop le !\n");
                }
                break;
            case 7:
                sapXepMaTran(a, m, n);
                printf("Ma tran sau khi sap xep: \n");
                xuatMaTran(a, m, n);
                break;
            case 8:
                printf("Nhap kich thuoc ma tran vuong (m=n): ");
                scanf("%d", &m);
                nhapMaTran(a, m, m);
                timMaxMinDuongCheoChinh(a, m);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (luaChon != 0);

    return 0;
}
