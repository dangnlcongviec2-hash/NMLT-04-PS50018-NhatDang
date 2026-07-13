#include <stdio.h>

int main() {
    // 1. Khai báo các biến lưu trữ điểm số 3 môn
    float diemToan, diemLy, diemHoa;
    float diemTB;

    printf("--- QUAN LY DIEM SO (LAB 2 - BAI 2) ---\n");
    
    // 2. Nhập dữ liệu từ bàn phím
    printf("Nhap diem mon Toan: ");
    scanf("%f", &diemToan);

    printf("Nhap diem mon Ly: ");
    scanf("%f", &diemLy);

    printf("Nhap diem mon Hoa: ");
    scanf("%f", &diemHoa);

    // 3. Tính toán điểm trung bình có nhân hệ số và vận dụng kỹ thuật ép kiểu
    // Biến mẫu số (6) được chuyển thành dạng số thực 6.0 hoặc ép kiểu (float) 
    // để kết quả trả về là một số thực chính xác, tránh lỗi chia số nguyên (Integer Division).
    diemTB = (float)(diemToan * 3 + diemLy * 2 + diemHoa) / 6.0;

    // 4. Hiển thị kết quả ra màn hình làm tròn đúng 2 chữ số thập phân
    printf("\n---------------------------------------\n");
    printf("Diem Trung Binh cua sinh vien la: %.2f\n", diemTB);

    return 0;
}