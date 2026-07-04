#include <stdio.h>
#include <string.h>

int main() {
    // 1. Khai báo các biến lưu trữ thông tin sinh viên và điểm số
    char mssv[20];
    char hoTen[50];
    float diemToan, diemLy, diemHoa;
    float diemTB;

    // 2. Nhập dữ liệu từ bàn phím
    printf("Nhap ma so sinh vien (MSSV): ");
    scanf("%s", mssv);
    
    // Xóa bộ nhớ đệm trước khi nhập chuỗi có khoảng trắng
    while (getchar() != '\n'); 

    printf("Nhap ho va ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    // Xóa ký tự xuống dòng '\n' do fgets tự động nhận vào
    hoTen[strcspn(hoTen, "\n")] = '\0'; 

    printf("Nhap diem Toan: ");
    scanf("%f", &diemToan);

    printf("Nhap diem Ly: ");
    scanf("%f", &diemLy);

    printf("Nhap diem Hoa: ");
    scanf("%f", &diemHoa);

    // 3. Tính toán điểm trung bình theo công thức (Toán nhân hệ số 2)
    diemTB = (diemToan * 2 + diemLy + diemHoa) / 4;

    // 4. Xuất dữ liệu ra màn hình theo đúng định dạng mẫu yêu cầu
    printf("\n--- KET QUA DIEM SINH VIEN ---\n");
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    printf("Diem Trung Binh: %.2f\n", diemTB); // Làm tròn đến 2 chữ số thập phân

    return 0;
}