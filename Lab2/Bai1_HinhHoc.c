#include <stdio.h>

#define PI 3.14159

int main() {
    // 1. Hình chữ nhật
    float chieuDai, chieuRong, chuViCN, dienTichCN;
    
    printf("--- HINH CHU NHAT ---\n");
    printf("Nhap chieu dai: ");
    scanf("%f", &chieuDai);
    printf("Nhap chieu rong: ");
    scanf("%f", &chieuRong);

    chuViCN = (chieuDai + chieuRong) * 2;
    dienTichCN = chieuDai * chieuRong;

    printf("Chu vi HCN: %.2f\n", chuViCN);
    printf("Dien tich HCN: %.2f\n\n", dienTichCN);

    // 2. Hình tròn
    float banKinh, chuViTron, dienTichTron;

    printf("--- HINH TRON ---\n");
    printf("Nhap ban kinh: ");
    scanf("%f", &banKinh);

    chuViTron = 2 * PI * banKinh;
    dienTichTron = PI * banKinh * banKinh;

    printf("Chu vi hinh tron: %.2f\n", chuViTron);
    printf("Dien tich hinh tron: %.2f\n", dienTichTron);

    return 0;
}