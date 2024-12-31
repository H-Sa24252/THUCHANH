#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SINHVIEN 100

typedef struct {
    char masv[20];
    char hotensv[100];
    char phai[10];
    float diemtoan;
    float diemvan;
    float diemav;
    float kqht;
    char xeploai[20];
} SinhVien;

float tinhKQHT(SinhVien sv) {
    return (sv.diemtoan * 2 + sv.diemvan * 2 + sv.diemav) / 5;
}

void xepLoai(SinhVien* sv) {
    if (sv->kqht < 1.5) {
        strcpy(sv->xeploai, "Yeu");
    } else if (sv->kqht < 2.5) {
        strcpy(sv->xeploai, "Trung binh");
    } else if (sv->kqht < 3.5) {
        strcpy(sv->xeploai, "Kha");
    } else if (sv->kqht < 3.7) {
        strcpy(sv->xeploai, "Gioi");
    } else {
        strcpy(sv->xeploai, "Xuat sac");
    }
}

int compareKQHT(const void* a, const void* b) {
    SinhVien* svA = (SinhVien*)a;
    SinhVien* svB = (SinhVien*)b;
    if (svA->kqht > svB->kqht) return 1;
    if (svA->kqht < svB->kqht) return -1;
    return 0;
}

void nhapSinhVien(SinhVien *sv) {
    printf("Nhap ma sinh vien: ");
    fflush(stdin);
    fgets(sv->masv, 20, stdin);
    sv->masv[strcspn(sv->masv, "\n")] = 0; 

    printf("Nhap ho ten sinh vien: ");
    fgets(sv->hotensv, 100, stdin);
    sv->hotensv[strcspn(sv->hotensv, "\n")] = 0; 

    printf("Nhap phai (Nam/Nu): ");
    fgets(sv->phai, 10, stdin);
    sv->phai[strcspn(sv->phai, "\n")] = 0;  

    printf("Nhap diem Toan: ");
    scanf("%f", &sv->diemtoan);

    printf("Nhap diem Van: ");
    scanf("%f", &sv->diemvan);

    printf("Nhap diem Anh Van: ");
    scanf("%f", &sv->diemav);

    sv->kqht = tinhKQHT(*sv);
    xepLoai(sv);
}

void inDanhSachSinhVien(SinhVien* sinhvien, int n) {
    printf("\nDanh sach sinh vien:\n");
    printf("MaSV\tHoTen\t\t\tPhai\tToan\tVan\tAnhVan\tKQHT\t\tXepLoai\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", sinhvien[i].masv, sinhvien[i].hotensv, sinhvien[i].phai,
                sinhvien[i].diemtoan, sinhvien[i].diemvan, sinhvien[i].diemav, sinhvien[i].kqht, sinhvien[i].xeploai);
    }
}

int main() {
    int n;
    SinhVien sinhvien[MAX_SINHVIEN];
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. In danh sach sinh vien theo KQHT tang dan\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
                    nhapSinhVien(&sinhvien[i]);
                }
                break;
            case 2:
                if (n == 0) {
                    printf("Chua nhap danh sach sinh vien!\n");
                } else {
                    qsort(sinhvien, n, sizeof(SinhVien), compareKQHT);
                    inDanhSachSinhVien(sinhvien, n);
                }
                break;
            case 0:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

