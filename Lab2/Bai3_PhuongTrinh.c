#include <stdio.h>

int main() {
    // 1. Khai báo các biến hệ số và nghiệm (sử dụng kiểu float để chứa số thực)
    float a, b;
    float x;

    printf("--- GIAI PHUONG TRINH BAC NHAT AX + B = 0 ---\n");

    // 2. Nhập các hệ số từ bàn phím
    printf("Nhap he so a (a != 0): ");
    scanf("%f", &a);

    printf("Nhap he so b: ");
    scanf("%f", &b);

    // 3. Tính nghiệm theo công thức x = -b / a
    x = -b / a;

    // 4. Hiển thị kết quả ra màn hình làm tròn đúng 2 chữ số thập phân
    printf("\n--------------------------------------------\n");
    printf("Nghiem cua phuong trinh %.2fx + (%.2f) = 0 la: x = %.2f\n", a, b, x);

    return 0;
}