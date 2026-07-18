#include <stdio.h>
#include <math.h>

int main() {
    int luaChon;

    // Hiển thị giao diện cấu trúc Menu chương trình
    printf("++---------------------------------------------------++\n");
    printf("|            MENU CHUC NANG - LAB 3                   |\n");
    printf("++---------------------------------------------------++\n");
    printf("| 1. Tinh hoc luc sinh vien                          |\n");
    printf("| 2. Giai phuong trinh bac hai                       |\n");
    printf("| 3. Tinh tien dien tieu thu hang thang              |\n");
    printf("| 4. Thoat chuong trinh                              |\n");
    printf("++---------------------------------------------------++\n");
    printf("Moi ban chon chuc nang (1-4): ");
    scanf("%d", &luaChon);

    switch (luaChon) {
        case 1: {
            printf("\n--- CHUC NANG 1: TINH HOC LUC SINH VIEN ---\n");
            float diem;
            printf("Nhap vao diem so cua sinh vien (0.0 - 10.0): ");
            scanf("%f", &diem);

            // Bắt lỗi dữ liệu đầu vào ngoài phạm vi cho phép
            if (diem < 0.0 || diem > 10.0) {
                printf("Diem so nhap vao khong hop le!\n");
            } else {
                // Phân loại học lực theo cấu trúc if-else bậc thang
                if (diem >= 9.0) {
                    printf("Hoc luc: Xuan sac\n");
                } else if (diem >= 8.0) {
                    printf("Hoc luc: Gioi\n");
                } else if (diem >= 6.5) {
                    printf("Hoc luc: Kha\n");
                } else if (diem >= 5.0) {
                    printf("Hoc luc: Trung binh\n");
                } else if (diem >= 3.5) {
                    printf("Hoc luc: Yeu\n");
                } else {
                    printf("Hoc luc: Kem\n");
                }
            }
            break;
        }

        case 2: {
            printf("\n--- CHUC NANG 2: GIAI PHUONG TRINH BAC HAI ---\n");
            float a, b, c;
            printf("Nhap he so a: ");
            scanf("%f", &a);
            printf("Nhap he so b: ");
            scanf("%f", &b);
            printf("Nhap he so c: ");
            scanf("%f", &c);

            // Biện luận trường hợp hệ số a == 0 (Trở thành PT bậc nhất)
            if (a == 0) {
                if (b == 0) {
                    if (c == 0) {
                        printf("Phuong trinh co vo so nghiem.\n");
                    } else {
                        printf("Phuong trinh vo nghiem.\n");
                    }
                } else {
                    float x = -c / b;
                    printf("Phuong trinh co nghiem duy nhat: x = %.2f\n", x);
                }
            } else {
                // Biện luận trường hợp hệ số a != 0 sử dụng biệt thức Delta
                float delta = (b * b) - (4 * a * c);
                if (delta < 0) {
                    printf("Phuong trinh vo nghiem.\n");
                } else if (delta == 0) {
                    float xKep = -b / (2 * a);
                    printf("Phuong trinh co nghiem kep: x = %.2f\n", xKep);
                } else {
                    float x1 = (-b + sqrt(delta)) / (2 * a);
                    float x2 = (-b - sqrt(delta)) / (2 * a);
                    printf("Phuong trinh co 2 nghiem rieng biet:\n");
                    printf("x1 = %.2f\n", x1);
                    printf("x2 = %.2f\n", x2);
                }
            }
            break;
        }

        case 3: {
            printf("\n--- CHUC NANG 3: TINH TIEN DIEN LUY TIEN ---\n");
            float kwh;
            double tongTien = 0;

            printf("Nhap vao tong so kWh dien tieu thu: ");
            scanf("%f", &kwh);

            if (kwh < 0) {
                printf("So kWh tieu thu khong the am!\n");
            } else {
                // Thuật toán tính tiền điện lũy tiến theo từng khoảng bậc thang riêng biệt
                if (kwh <= 50) {
                    tongTien = kwh * 1.678;
                } else if (kwh <= 100) {
                    tongTien = (50 * 1.678) + ((kwh - 50) * 1.734);
                } else if (kwh <= 200) {
                    tongTien = (50 * 1.678) + (50 * 1.734) + ((kwh - 100) * 2.014);
                } else if (kwh <= 300) {
                    tongTien = (50 * 1.678) + (50 * 1.734) + (100 * 2.014) + ((kwh - 200) * 2.536);
                } else if (kwh <= 400) {
                    tongTien = (50 * 1.678) + (50 * 1.734) + (100 * 2.014) + (100 * 2.536) + ((kwh - 300) * 2.834);
                } else {
                    tongTien = (50 * 1.678) + (50 * 1.734) + (100 * 2.014) + (100 * 2.536) + (100 * 2.834) + ((kwh - 400) * 2.927);
                }
                
                // Hiển thị kết quả tường minh, nhân với 1000 nếu hệ số tính toán để dạng dấu phẩy (1.678 -> 1678đ)
                // Do đề bài biểu diễn dạng 1.678 đồng/kWh (hiểu theo nghĩa hệ nghìn Việt Nam), ta nhân trực tiếp ra số tiền thực:
                printf("Tong so tien dien can thanh toan: %.0f dong\n", tongTien * 1000);
            }
            break;
        }

        case 4:
            printf("Da thoat chuong trinh thành công. Tam biet!\n");
            break;

        default:
            printf("Chuc nang ban chon khong ton tai! Vui long chay lai.\n");
            break;
    }

    return 0;
}