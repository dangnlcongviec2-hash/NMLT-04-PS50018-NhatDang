#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// ==========================================
// KHAI BÁO CÁC HÀM HỖ TRỢ & HÀM CHỨC NĂNG
// ==========================================
void menu();
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();
void chucNang8();
void chucNang9();
void chucNang10();

// Hàm hỗ trợ tìm UCLN
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Cấu trúc Sinh viên cho Chức năng 8
typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;

// Cấu trúc Phân số cho Chức năng 10
typedef struct {
    int tu;
    int mau;
} PhanSo;

void rutGonPhanSo(PhanSo *ps) {
    int ucln = timUCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
    if (ps->mau < 0) { // Chuyển dấu âm lên tử số
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}

void inPhanSo(PhanSo ps) {
    rutGonPhanSo(&ps);
    if (ps.mau == 1) {
        printf("%d", ps.tu);
    } else {
        printf("%d/%d", ps.tu, ps.mau);
    }
}

// ==========================================
// HÀM CHÍNH (MAIN) & MENU
// ==========================================
int main() {
    int luaChon;
    srand(time(NULL)); // Khởi tạo hạt giống ngẫu nhiên cho game Lott

    do {
        menu();
        printf("Moi ban chon chuc nang (0-10): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:  chucNang1(); break;
            case 2:  chucNang2(); break;
            case 3:  chucNang3(); break;
            case 4:  chucNang4(); break;
            case 5:  chucNang5(); break;
            case 6:  chucNang6(); break;
            case 7:  chucNang7(); break;
            case 8:  chucNang8(); break;
            case 9:  chucNang9(); break;
            case 10: chucNang10(); break;
            case 0:
                printf("\n=========================================\n");
                printf("  CAM ON BAN DA SU DUNG CHUONG TRINH!\n");
                printf("=========================================\n");
                break;
            default:
                printf("\n[Loi] Chuc nang khong hop le! Vui long chon tu 0 den 10.\n");
                break;
        }

        if (luaChon != 0) {
            printf("\nNhan Enter de tiep tuc...");
            getchar(); getchar(); // Dừng màn hình chờ người dùng
        }

    } while (luaChon != 0);

    return 0;
}

void menu() {
    printf("\n+-------------------------------------------------------------+\n");
    printf("|                NHAP MON LAP TRINH - MENU                    |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("| 1. Kiem tra so nguyen                                       |\n");
    printf("| 2. Tim UCLN va BCNN cua 2 so                                |\n");
    printf("| 3. Tinh tien Karaoke                                        |\n");
    printf("| 4. Tinh tien dien                                           |\n");
    printf("| 5. Chuc nang doi tien                                       |\n");
    printf("| 6. Tinh lai suat vay ngân hang (Tra gop 12 thang)           |\n");
    printf("| 7. Vay tien mua xe                                          |\n");
    printf("| 8. Sap xep thong tin sinh vien                              |\n");
    printf("| 9. Game FPOLY-LOTT (2/15)                                   |\n");
    printf("| 10. Tinh toan phan so                                       |\n");
    printf("| 0. Thoat chuong trinh                                       |\n");
    printf("+-------------------------------------------------------------+\n");
}

// ==========================================
// CHI TIẾT 10 CHỨC NĂNG (Y2)
// ==========================================

// --- CHỨC NĂNG 1: KIỂM TRA SỐ NGUYÊN ---
void chucNang1() {
    printf("\n--- CHUC NANG 1: KIEM TRA SO NGUYEN ---\n");
    float x;
    printf("Nhap vao so x: ");
    scanf("%f", &x);

    // Kiểm tra có phải số nguyên
    if (x == (int)x) {
        int n = (int)x;
        printf("+ So %.0f LA so nguyen.\n", x);

        // Kiểm tra số nguyên tố
        int isPrime = 1;
        if (n < 2) isPrime = 0;
        else {
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) { isPrime = 0; break; }
            }
        }
        if (isPrime) printf("+ So %d LA so nguyen to.\n", n);
        else printf("+ So %d KHONG PHAI la so nguyen to.\n", n);

        // Kiểm tra số chính phương
        int sq = sqrt(n);
        if (n >= 0 && sq * sq == n) printf("+ So %d LA so chinh phuong.\n", n);
        else printf("+ So %d KHONG PHAI la so chinh phuong.\n", n);

    } else {
        printf("+ So %.2f KHONG PHAI la so nguyen.\n", x);
        printf("+ Vi khong la so nguyen nen khong xet So nguyen to va So chinh phuong.\n");
    }
}

// --- CHỨC NĂNG 2: TÌM UCLN VÀ BCNN ---
void chucNang2() {
    printf("\n--- CHUC NANG 2: TIM UCLN VA BCNN ---\n");
    int x, y;
    printf("Nhap so nguyen x: "); scanf("%d", &x);
    printf("Nhap so nguyen y: "); scanf("%d", &y);

    int ucln = timUCLN(x, y);
    long long bcnn = (x == 0 || y == 0) ? 0 : (abs((long long)x * y) / ucln);

    printf("-> Uoc so chung lon nhat (UCLN) cua %d va %d la: %d\n", x, y, ucln);
    printf("-> Boi so chung nho nhat (BCNN) cua %d va %d la: %lld\n", x, y, bcnn);
}

// --- CHỨC NĂNG 3: TÍNH TIỀN KARAOKE ---
void chucNang3() {
    printf("\n--- CHUC NANG 3: TINH TIEN KARAOKE ---\n");
    int gioBD, gioKT;
    printf("Nhap gio bat dau (12h - 23h): "); scanf("%d", &gioBD);
    printf("Nhap gio ket thuc (12h - 23h): "); scanf("%d", &gioKT);

    if (gioBD < 12 || gioKT > 23 || gioBD >= gioKT) {
        printf("[Loi] Gio khong hop le! Quan chi hoat dong tu 12h den 23h va Gio BD < Gio KT.\n");
        return;
    }

    int soGio = gioKT - gioBD;
    double tongTien = 0;

    if (soGio <= 3) {
        tongTien = soGio * 150000;
    } else {
        tongTien = (3 * 150000) + ((soGio - 3) * 150000 * 0.7);
    }

    // Khuyến mãi giảm 10% nếu bắt đầu trong khoảng 14h - 17h
    if (gioBD >= 14 && gioBD <= 17) {
        tongTien *= 0.9;
        printf("-> Ban duoc giam gia 10%% vi khong gio bat dau trong khoang 14h-17h!\n");
    }

    printf("-> Tong so tien Karaoke can thanh toan: %.0f VNĐ\n", tongTien);
}

// --- CHỨC NĂNG 4: TÍNH TIỀN ĐIỆN ---
void chucNang4() {
    printf("\n--- CHUC NANG 4: TINH TIEN DIEN ---\n");
    float kwh;
    printf("Nhap so kWh dien su dung: "); scanf("%f", &kwh);

    if (kwh < 0) {
        printf("[Loi] So kWh khong the la so am!\n");
        return;
    }

    double tongTien = 0;
    if (kwh <= 50) {
        tongTien = kwh * 1678;
    } else if (kwh <= 100) {
        tongTien = (50 * 1678) + ((kwh - 50) * 1734);
    } else if (kwh <= 200) {
        tongTien = (50 * 1678) + (50 * 1734) + ((kwh - 100) * 2014);
    } else if (kwh <= 300) {
        tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + ((kwh - 200) * 2536);
    } else if (kwh <= 400) {
        tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + (100 * 2536) + ((kwh - 300) * 2834);
    } else {
        tongTien = (50 * 1678) + (50 * 1734) + (100 * 2014) + (100 * 2536) + (100 * 2834) + ((kwh - 400) * 2927);
    }

    printf("-> So tien dien phai trả: %.0f VNĐ\n", tongTien);
}

// --- CHỨC NĂNG 5: ĐỔI TIỀN ---
void chucNang5() {
    printf("\n--- CHUC NANG 5: CHUC NANG DOI TIEN ---\n");
    int soTien;
    printf("Nhap so tien can doi: "); scanf("%d", &soTien);

    if (soTien <= 0) {
        printf("[Loi] So tien nhap vao phai lon hon 0!\n");
        return;
    }

    int menGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soTo[9] = {0};
    int temp = soTien;

    // Nếu nhập đúng tờ mệnh giá (ví dụ 500) và muốn đổi ra tiền lẻ, ta bắt đầu đổi từ mệnh giá nhỏ hơn
    int startIdx = 0;
    if (soTien == 500) startIdx = 1; // Bắt đầu đổi từ tờ 200 để ra 2 tờ 200 + 1 tờ 100

    for (int i = startIdx; i < 9; i++) {
        if (temp >= menGia[i]) {
            soTo[i] = temp / menGia[i];
            temp %= menGia[i];
        }
    }

    printf("-> Ket qua doi %d thanh cac to tien:\n", soTien);
    for (int i = 0; i < 9; i++) {
        if (soTo[i] > 0) {
            printf("   + %d to men gia %d\n", soTo[i], menGia[i]);
        }
    }
}

// --- CHỨC NĂNG 6: TÍNH LÃI SUẤT VAY NGÂN HÀNG (TRẢ GÓP) ---
void chucNang6() {
    printf("\n--- CHUC NANG 6: TAINH LAI SUAT VAY TRẢ GOP (12 THANG) ---\n");
    double tienVay;
    printf("Nhap so tien muon vay (VNĐ): "); scanf("%lf", &tienVay);

    if (tienVay <= 0) {
        printf("[Loi] So tien vay phai lon hon 0!\n");
        return;
    }

    double gocHangThang = tienVay / 12.0;
    double duNo = tienVay;
    double laiSuatThang = 0.05; // 5%/tháng

    printf("\n%-8s | %-15s | %-15s | %-15s | %-15s\n", "Ky han", "Lai phai tra", "Goc phai tra", "Tong phai tra", "Du no con lai");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 1; i <= 12; i++) {
        double lai = duNo * laiSuatThang;
        double tongPhaiTra = gocHangThang + lai;
        duNo -= gocHangThang;
        if (duNo < 0) duNo = 0;

        printf("%-8d | %-15.0f | %-15.0f | %-15.0f | %-15.0f\n", i, lai, gocHangThang, tongPhaiTra, duNo);
    }
}

// --- CHỨC NĂNG 7: VAY TIỀN MUA XE ---
void chucNang7() {
    printf("\n--- CHUC NANG 7: CHUONG TRINH VAY TIEN MUA XE ---\n");
    float pctVay;
    printf("Nhap phan tram vay toi da (Vi du 80 nghia la vay 80%%, tra truoc 20%%): ");
    scanf("%f", &pctVay);

    if (pctVay <= 0 || pctVay > 100) {
        printf("[Loi] Phan tram vay khong hop le (1 - 100)!\n");
        return;
    }

    double giaTriXe = 500000000.0; // 500 triệu
    double tienVay = giaTriXe * (pctVay / 100.0);
    double tienTraTruoc = giaTriXe - tienVay;

    int thoiHanThang = 24 * 12; // 24 năm = 288 tháng
    double laiSuatNam = 0.072;  // 7.2%/năm
    double laiSuatThang = laiSuatNam / 12.0;

    double gocThang = tienVay / thoiHanThang;
    double laiThangDau = tienVay * laiSuatThang;

    printf("\n+ Gia tri xe: %.0f VNĐ\n", giaTriXe);
    printf("+ So tien phai tra lan dau (Tra truoc): %.0f VNĐ\n", tienTraTruoc);
    printf("+ So tien vay ngân hang: %.0f VNĐ\n", tienVay);
    printf("+ Thoi han vay: 24 nam (%d thang)\n", thoiHanThang);
    printf("+ So tien goc phai tra hang thang: %.0f VNĐ\n", gocThang);
    printf("+ So tien phai tra thang dau tien (Goc + Lai): %.0f VNĐ\n", gocThang + laiThangDau);
}

// --- CHỨC NĂNG 8: SẮP XẾP THÔNG TIN SINH VIÊN ---
void chucNang8() {
    printf("\n--- CHUC NANG 8: SAP XEP THONG TIN SINH VIEN ---\n");
    int n;
    printf("Nhap so luong sinh vien: "); scanf("%d", &n);

    if (n <= 0) {
        printf("[Loi] So luong sinh vien phai lon hon 0!\n");
        return;
    }

    SinhVien ds[100];
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf(" + Ho va ten: ");
        fflush(stdin); // Xóa bộ nhớ đệm
        getchar(); // Nhận ký tự thừa nếu có
        gets(ds[i].hoTen);
        printf(" + Diem: ");
        scanf("%f", &ds[i].diem);

        // Xếp loại học lực
        if (ds[i].diem >= 9.0) strcpy(ds[i].hocLuc, "Xuat sac");
        else if (ds[i].diem >= 8.0) strcpy(ds[i].hocLuc, "Gioi");
        else if (ds[i].diem >= 6.5) strcpy(ds[i].hocLuc, "Kha");
        else if (ds[i].diem >= 5.0) strcpy(ds[i].hocLuc, "Trung binh");
        else strcpy(ds[i].hocLuc, "Yeu");
    }

    // Sắp xếp điểm giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    printf("\n=== DANH SACH SINH VIEN SAU KHI SAP XEP (DIEM GIAM DAN) ===\n");
    printf("%-5s | %-25s | %-8s | %-12s\n", "STT", "Ho va Ten", "Diem", "Hoc Luc");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d | %-25s | %-8.1f | %-12s\n", i + 1, ds[i].hoTen, ds[i].diem, ds[i].hocLuc);
    }
}

// --- CHỨC NĂNG 9: GAME FPOLY-LOTT ---
void chucNang9() {
    printf("\n--- CHUC NANG 9: GAME FPOLY-LOTT (2/15) ---\n");
    int so1, so2;
    printf("Nhap vao so thu nhat (01 - 15): "); scanf("%d", &so1);
    printf("Nhap vao so thu hai (01 - 15): "); scanf("%d", &so2);

    if (so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15) {
        printf("[Loi] So nhap vao phai nam trong khoang tu 01 den 15!\n");
        return;
    }

    int kq1 = rand() % 15 + 1;
    int kq2 = rand() % 15 + 1;

    printf("\n-> Ket qua xo so cua He thong: %02d - %02d\n", kq1, kq2);

    int demTrung = 0;
    if (so1 == kq1 || so1 == kq2) demTrung++;
    if (so2 == kq1 || so2 == kq2) demTrung++;

    if (demTrung == 2) {
        printf("=> CHUC MUNG BAN DA TRUNG GIAI NHAT!\n");
    } else if (demTrung == 1) {
        printf("=> CHUC MUNG BAN DA TRUNG GIAI NHI!\n");
    } else {
        printf("=> CHUC BAN MAY MAN LAN SAU!\n");
    }
}

// --- CHỨC NĂNG 10: TÍNH TOÁN PHÂN SỐ ---
void chucNang10() {
    printf("\n--- CHUC NANG 10: TINH TOAN PHAN SO ---\n");
    PhanSo ps1, ps2;

    printf("Nhap Phan so 1 (Tu va Mau): ");
    scanf("%d %d", &ps1.tu, &ps1.mau);
    printf("Nhap Phan so 2 (Tu va Mau): ");
    scanf("%d %d", &ps2.tu, &ps2.mau);

    if (ps1.mau == 0 || ps2.mau == 0) {
        printf("[Loi] Mau so phai khac 0!\n");
        return;
    }

    // TỔNG
    PhanSo tong = {ps1.tu * ps2.mau + ps2.tu * ps1.mau, ps1.mau * ps2.mau};
    printf("\n+ Tong: "); inPhanSo(ps1); printf(" + "); inPhanSo(ps2); printf(" = "); inPhanSo(tong); printf("\n");

    // HIỆU
    PhanSo hieu = {ps1.tu * ps2.mau - ps2.tu * ps1.mau, ps1.mau * ps2.mau};
    printf("+ Hieu: "); inPhanSo(ps1); printf(" - "); inPhanSo(ps2); printf(" = "); inPhanSo(hieu); printf("\n");

    // TÍCH
    PhanSo tich = {ps1.tu * ps2.tu, ps1.mau * ps2.mau};
    printf("+ Tich: "); inPhanSo(ps1); printf(" * "); inPhanSo(ps2); printf(" = "); inPhanSo(tich); printf("\n");

    // THƯƠNG
    if (ps2.tu == 0) {
        printf("+ Thuong: Khong the chia cho 0!\n");
    } else {
        PhanSo thuong = {ps1.tu * ps2.mau, ps1.mau * ps2.tu};
        printf("+ Thuong: "); inPhanSo(ps1); printf(" / "); inPhanSo(ps2); printf(" = "); inPhanSo(thuong); printf("\n");
    }
}