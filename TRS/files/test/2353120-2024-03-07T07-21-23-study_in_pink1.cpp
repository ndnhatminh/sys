#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int lam_tron(double num) {
    double thap_phan = num - floor(num);
    if (thap_phan == 0) {
        return num;
    }
    else {
        return ceil(num - 0.000001);
    }
}
int check(int input, int a, int b) {
    input = (input < a) ? a : (input > b) ? b : input;
    return input;
}
int firstMeet(int & exp1, int & exp2, int e1){
    //TODO: implement task
    //Checking valid value
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    exp1 = check(exp1, 0, 600);
    exp2 = check(exp2, 0, 600);
    // Determine case 1 and case2
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0){
            exp2 += 29;
            exp2 = check(exp2, 0, 600);
        }
        else if (e1 == 1) {
            exp2 += 45;
            exp2 = check(exp2, 0, 600);
        } 
        else if (e1 == 2) {
            exp2 += 75;
            exp2 = check(exp2, 0, 600);
        }
        else if (e1 == 3) {
            exp2 += 149;
            exp2 = check(exp2, 0, 600);
        }
    int D = e1 * 3 + exp1 * 7;
    if (D % 2 == 0) {
        double exp1_dbl = ceil((double) exp1 + ((double) D) / 200);
        exp1 = ceil(exp1_dbl);
        exp1 = check(exp1, 0, 600);
    }
    else {
        double exp1_dbl = ceil((double) exp1 - ((double) D) / 100);
        exp1 = ceil(exp1_dbl);
        exp1 = check(exp1, 0, 600);
    }
    }
    else if (e1 >= 4 && e1 <= 99) {
        float info_1 = ((double)e1) / 4 + 19.0;
        float info_2 = ((double)e1) / 9 + 21.0;
        float info_3 = ((double)e1) / 16 + 17.0;
        double exp2_dbl = (double) exp2;
        if (e1 >= 4 && e1 <= 19) {
            exp2_dbl += info_1;
            exp2 = ceil (exp2_dbl);
            exp2 = check(exp2, 0, 600);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2_dbl += info_2;
            exp2 = ceil (exp2_dbl);
            exp2 = check(exp2, 0, 600);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2_dbl += info_3;
            exp2 = ceil (exp2_dbl);
            exp2 = check(exp2, 0, 600);
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2_dbl += info_1;
            exp2 = ceil (exp2_dbl);
            exp2 = check(exp2, 0, 600);
            exp2_dbl = (double) exp2;
            if (exp2 > 200) {
                exp2_dbl += info_2;
                exp2 = ceil (exp2_dbl);
                exp2 = check(exp2, 0, 600);
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2_dbl += info_1;
            exp2 = ceil (exp2_dbl);
            exp2 = check(exp2, 0, 600);
            exp2_dbl = (double) exp2;
            exp2_dbl += info_2;
            exp2 = ceil (exp2_dbl);
            exp2 = check(exp2, 0, 600);
            exp2_dbl = (double) exp2;
        if(exp2 > 400) {
            exp2_dbl += info_3;
            exp2 = ceil (exp2_dbl);
            exp2 = check(exp2, 0, 600);
            exp2_dbl = (double) exp2;
            exp2_dbl = exp2_dbl * 1.15;
            exp2 = ceil(exp2_dbl);
            exp2 = check(exp2, 0, 600);
        }
        }
        exp1 -= e1;
        exp1 = check(exp1, 0, 600);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //TODO: implement task
    // Kiểm tra mã sự kiện 
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    // Kiểm tra các thông số của Sherlock
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);
    // Khởi tạo biến số thực để tính toán
    double HP1_dbl = HP1;
    double EXP1_dbl = EXP1;
    double M1_dbl = M1;
    // Con đường 01
    // Tìm xác xuất P1 dựa theo số chính phương S
    double P_1 = 0;
    int S_1 = 0;
    int so_can_b2 = (int)sqrt(EXP1_dbl);
    int so_can_b2_nho = so_can_b2 * so_can_b2;
    int so_can_b2_lon = (so_can_b2 + 1) * (so_can_b2 + 1);
    // Tìm khoảng cách ngắn nhất giữa 2 số chính phương so với EXP1
    if (abs(EXP1 - so_can_b2_nho) < abs(EXP1 - so_can_b2_lon)) {
        S_1 = so_can_b2_nho; 
    } else {
        S_1 = so_can_b2_lon;
    }
    // Trường hợp EXP1 >= S
    if (EXP1 >= S_1) {
        P_1 = 100.0; // Xác xuất tìm thấy vali là 100%
    } else { // Trường hợp khác
        P_1 = (((EXP1_dbl / (double)S_1) + 80.0)/ 123.0) * 100.0; // Công thức tính xác xuất tìm thấy vali
    }
    // Con đường 02
    // Xác định cách trải qua 3 sự kiện theo E2
    const double so_tien_quy_dinh = (double) M1 * 0.5; // Thiết lập 1 hằng số chỉ 50% số tiền lúc bắt đầu
    if ((E2 % 2) != 0) { // E2 lẻ
        while(true) { // Lặp vô hạn qua các sự kiện
            // Sự kiện 1
            if (HP1 < 200) {
                HP1_dbl = HP1_dbl * 1.30; // Thức ăn + nước uống
                HP1 = lam_tron(HP1_dbl);  // Làm tròn số
                HP1 = check (HP1, 0, 666); // Kiểm tra điều kiện HP1
                HP1_dbl = (double) HP1; // Ép kiểu và trả giá trị về double để tiếp tục tính toán
                M1_dbl = M1_dbl - 150; // Chi 150
                M1 = lam_tron (M1_dbl); //...   
                M1 = check(M1, 0, 3000);//...
                M1_dbl = (double) M1;//...
                if (M1_dbl < so_tien_quy_dinh) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            } else {
                HP1_dbl = HP1_dbl * 1.10; // Nước uống
                HP1 = lam_tron(HP1_dbl);  // Làm tròn số
                HP1 = check (HP1, 0, 666); // Kiểm tra điều kiện HP1
                HP1_dbl = (double) HP1; // Ép kiểu và trả giá trị về double để tiếp tục tính toán
                M1_dbl = M1_dbl - 70; // Chi 70
                M1 = lam_tron (M1_dbl); //...
                M1 = check(M1, 0, 3000);//...
                M1_dbl = (double) M1;//...
                if (M1_dbl < so_tien_quy_dinh) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            }
            // Sự kiện 2
            if (EXP1 < 400) { // Đi Taxi
                EXP1_dbl = EXP1_dbl * 1.13; //...
                EXP1 = lam_tron(EXP1_dbl);  //...
                EXP1 = check(EXP1, 0, 600); //...
                EXP1_dbl = (double)EXP1; //...
                M1_dbl = M1_dbl - 200; //...
                M1 = lam_tron(M1_dbl); //...
                M1 = check (M1, 0, 3000); //...
                M1_dbl = (double) M1;
                if (M1_dbl < so_tien_quy_dinh) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            } else { // Đi xe ngựa
                EXP1_dbl = EXP1_dbl * 1.13; //...
                EXP1 = lam_tron(EXP1_dbl);  //...
                EXP1 = check(EXP1, 0, 600); //...
                EXP1_dbl = (double)EXP1; //...
                M1_dbl = M1_dbl - 120; //...
                M1 = lam_tron(M1_dbl); //...
                M1 = check (M1, 0, 3000); //...
                M1_dbl = (double) M1; //...
                if (M1_dbl < so_tien_quy_dinh) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            }
            // Sự kiện 3
            if (EXP1 < 300) { // Nghe hướng dẫn
                EXP1_dbl = EXP1_dbl * 0.90; //...
                EXP1 = lam_tron(EXP1_dbl);  //...
                EXP1 = check(EXP1, 0, 600); //...
                EXP1_dbl = (double)EXP1; //...
                M1_dbl = M1_dbl - 100; //...
                M1 = lam_tron(M1_dbl); //...
                M1 = check (M1, 0, 3000); //...
                M1_dbl = (double) M1; //...
                if (M1_dbl < so_tien_quy_dinh) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            } else { // Nhờ dẫn đi
                EXP1_dbl = EXP1_dbl * 0.90; //...
                EXP1 = lam_tron(EXP1_dbl);  //...
                EXP1 = check(EXP1, 0, 600); //...
                EXP1_dbl = (double)EXP1; //...
                M1_dbl = M1_dbl - 120; //...
                M1 = lam_tron(M1_dbl); //...
                M1 = check (M1, 0, 3000); //...
                M1_dbl = (double) M1; //...
                if (M1_dbl < so_tien_quy_dinh) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            }
        }  
        // Cập nhập số liệu theo bài toán
        // HP1
        HP1_dbl = HP1_dbl * 0.83; 
        HP1 = lam_tron(HP1_dbl);  
        HP1 = check (HP1, 0, 666); 
        HP1_dbl = (double) HP1; 
        // EXP1
        EXP1_dbl = EXP1_dbl * 1.17; 
        EXP1 = lam_tron(EXP1_dbl);  
        EXP1 = check(EXP1, 0, 600); 
        EXP1_dbl = (double)EXP1; 
    } else { //E2 là số chẵn
        int m = 0; // Tạo biến lặp
        while(m < 1) { // Đảm bảo vòng lặp chỉ đi qua 1 lần duy nhất
            // Sự kiện 1
            if (HP1 < 200) {
                HP1_dbl = HP1_dbl * 1.30; // Thức ăn + nước uống
                HP1 = lam_tron(HP1_dbl);  // Làm tròn số
                HP1 = check (HP1, 0, 666); // Kiểm tra điều kiện HP1
                HP1_dbl = (double) HP1; // Ép kiểu và trả giá trị về double để tiếp tục tính toán
                M1_dbl = M1_dbl - 150; // Chi 150
                M1 = lam_tron (M1_dbl); //...
                M1 = check(M1, 0, 3000);//...
                M1_dbl = (double) M1;//...
                if (M1_dbl == 0) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            } else {
                HP1_dbl = HP1_dbl * 1.10; // Nước uống
                HP1 = lam_tron(HP1_dbl);  // Làm tròn số
                HP1 = check (HP1, 0, 666); // Kiểm tra điều kiện HP1
                HP1_dbl = (double) HP1; // Ép kiểu và trả giá trị về double để tiếp tục tính toán
                M1_dbl = M1_dbl - 70; // Chi 70
                M1 = lam_tron (M1_dbl); //...
                M1 = check(M1, 0, 3000);//...
                M1_dbl = (double) M1;//...
                if (M1_dbl == 0) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            }
            // Sự kiện 2
            if (EXP1 < 400) { // Đi Taxi
                EXP1_dbl = EXP1_dbl * 1.13; //...
                EXP1 = lam_tron(EXP1_dbl);  //...
                EXP1 = check(EXP1, 0, 600); //...
                EXP1_dbl = (double)EXP1; //...
                M1_dbl = M1_dbl - 200; //...
                M1 = lam_tron(M1_dbl); //...
                M1 = check (M1, 0, 3000); //...
                M1_dbl = (double) M1;
                if (M1_dbl == 0) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            } else { // Đi xe ngựa
                EXP1_dbl = EXP1_dbl * 1.13; //...
                EXP1 = lam_tron(EXP1_dbl);  //...
                EXP1 = check(EXP1, 0, 600); //...
                EXP1_dbl = (double)EXP1; //...
                M1_dbl = M1_dbl - 120; //...
                M1 = lam_tron(M1_dbl); //...
                M1 = check (M1, 0, 3000); //...
                M1_dbl = (double) M1; //...
                if (M1_dbl == 0) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            }
            // Sự kiện 3
            if (EXP1 < 300) { // Nghe hướng dẫn
                EXP1_dbl = EXP1_dbl * 0.90; //...
                EXP1 = lam_tron(EXP1_dbl);  //...
                EXP1 = check(EXP1, 0, 600); //...
                EXP1_dbl = (double)EXP1; //...
                M1_dbl = M1_dbl - 100; //...
                M1 = lam_tron(M1_dbl); //...
                M1 = check (M1, 0, 3000); //...
                M1_dbl = (double) M1; //...
                if (M1_dbl == 0) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            } else { // Nhờ dẫn đi
                EXP1_dbl = EXP1_dbl * 0.90; //...
                EXP1 = lam_tron(EXP1_dbl);  //...
                EXP1 = check(EXP1, 0, 600); //...
                EXP1_dbl = (double)EXP1; //...
                M1_dbl = M1_dbl - 120; //...
                M1 = lam_tron(M1_dbl); //...
                M1 = check (M1, 0, 3000); //...
                M1_dbl = (double) M1; //...
                if (M1_dbl == 0) { // kiểm tra hạn mức tiêu xài
                    break;
                }
            }
            m++; // Nếu đi qua hết 3 sự kiện như chưa hết tiền thì sẽ thoát khỏi vòng lặp
        }
        // Cập nhập số liệu theo bài toán
        // HP1
        HP1_dbl = HP1_dbl * 0.83; 
        HP1 = lam_tron(HP1_dbl);  
        HP1 = check (HP1, 0, 666); 
        HP1_dbl = (double) HP1; 
        // EXP1
        EXP1_dbl = EXP1_dbl * 1.17; 
        EXP1 = lam_tron(EXP1_dbl);  
        EXP1 = check(EXP1, 0, 600); 
        EXP1_dbl = (double)EXP1; 
    }
    // Xác định P2 sau bài toán
    double P_2 = 0;
    int S_2 = 0;
    int so_can_b2_cpy = sqrt(EXP1_dbl);
    int so_can_b2_nho_1 = so_can_b2_cpy * so_can_b2_cpy;
    int so_can_b2_lon_1 = (so_can_b2_cpy + 1) * (so_can_b2_cpy + 1);
    // Tìm khoảng cách ngắn nhất giữa 2 số chính phương so với EXP1
    if (abs(EXP1 - so_can_b2_nho_1) < abs(EXP1 - so_can_b2_lon_1)) {
        S_2 = so_can_b2_nho_1; 
    } else {
        S_2 = so_can_b2_lon_1;
    }
    // Trường hợp EXP1 >= S
    if (EXP1 >= S_2) {
        P_2 = 100; // Xác xuất tìm thấy vali là 100%
    } else { // Trường hợp khác
        P_2 = (((EXP1_dbl / (double)S_2) + 80.0)/ 123.0) * 100.0; // Công thức tính xác xuất tìm thấy vali
    }
    // Xác định P3 theo mảng
    // Khởi tạo biến xác xuất P3
    double P_3 = 0;
    // Tạo 1 mảng 10 phần tử cố định
    int P [10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    // Khởi tạo biến chỉ số mảng
    int i = 0;
    if (E2 >= 0 && E2 <=9) { //Trường hợp 1: số có 1 chữ số
        i = E2;
    }
    if (E2 >= 10 && E2 <= 99) { //Trường hợp 2: Số có 2 chữ số
        int a = E2 / 10; // Trích số hàng chục 
        int b = E2 % 10; // trích số hàng đơn vị
        i = a + b; // Cộng 2 số
        if (i >= 10) { // Trường hợp cộng 2 nhưng vẫn ra số có 2 chữ số 
            int c = i % 10;
            i = c;
        }
    }
    // Xác xuất P_3 trích từ mảng P theo chỉ số i
    P_3 = (double) P[i]; 
    // Tìm vali dựa trên xác xuất
    // Trường hợp cả 3 tuyến đường đều có xs 100%
    if ((P_1 == 100.0) && (P_2 == 100.0) && (P_3 == 100.0)) { // Sherlock bị nhầm lẫn
        // Giảm điểm EXP
        EXP1_dbl = EXP1_dbl * 0.75;
        EXP1 = lam_tron(EXP1_dbl);  
        EXP1 = check(EXP1, 0, 600);
        EXP1_dbl = (double) EXP1;   
    } else { // Sherlock không bị nhầm
        // Bình quân xác xuất trên 3 con đường
        double P_avr = (P_1 + P_2 + P_3) / 3.0;
        if (P_avr < 50) { // Rất vất vả 
            // Giảm HP1 15%
            HP1_dbl = HP1_dbl * 0.85; 
            HP1 = lam_tron(HP1_dbl);  
            HP1 = check (HP1, 0, 666); 
            HP1_dbl = (double) HP1; 
            // Tăng EXP 15%
            EXP1_dbl = EXP1_dbl * 1.15;
            EXP1 = lam_tron(EXP1_dbl);  
            EXP1 = check(EXP1, 0, 600);
            EXP1_dbl = (double) EXP1;
        } else { // Rất nhanh chóng 
            // Giảm HP1 10%
            HP1_dbl = HP1_dbl * 0.90; 
            HP1 = lam_tron(HP1_dbl);  
            HP1 = check (HP1, 0, 666); 
            // Tăng EXP 20%
            EXP1_dbl = EXP1_dbl * 1.20;
            EXP1 = lam_tron(EXP1_dbl);  
            EXP1 = check(EXP1, 0, 600);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    //TODO: implement task
    // Kiểm tra giá trị E3 có phù hợp không
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    // Kiểm tra và điều chỉnh các giá trị đầu vào
    HP1 = check(HP1, 0, 666); 
    HP2 = check(HP2, 0, 666); 
    EXP1 = check(EXP1, 0, 600);
    EXP2 = check(EXP2, 0, 600);
    // Gán công thức để tính toán trên ma trận 
    // Khởi tạo mảng 2 chiều rỗng để giả lập một ma trận
    int toa_do[10][10] = {0};
    // Quét qua tất cả phần tử trong mảng 2 chiều
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            toa_do[i][j] = (((E3 * j) + (i * 2)) * (i - j)); // Gán công thức để tính toán
        }
    }
    // Khởi tạo biến đếm
    int m = 0, n = 0, p = 0, q = 0;
    // Quét qua các phần tử trong mảng để tìm giá trị biến đếm theo điều kiện
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Điều kiện biến đếm
            if (toa_do[i][j] > (E3 * 2)) {
                m++;
            }
            if (toa_do[i][j] < -E3) {
                n++;
            }
        }
    }
    // Tọa độ trục Ox của điểm gặp chiếc Taxi
    if (m >= 10) {
        int a = m / 10;
        int b = m % 10;
        p = a + b;
    }
    // Trường hợp tọa độ vẫn là số có 2 chữ số
    if (p >= 10) {
        int c = p / 10;
        int d = p % 10;
        p = c + d;
    }
    // Tọa độ trục Oy của điểm gặp chiếc Taxi
    if (n >= 10) {
        int a = n / 10;
        int b = n % 10;
        q = a + b;
    }
    // Trường hợp tọa độ vẫn là số có 2 chữ số
    if (q >= 10) {
        int c = n / 10;
        int d = n % 10;
        q = c + d;
    }
    // Gán giá tri vào tọa độ điểm gặp Taxi
    int toa_do_Taxi = toa_do[p][q];
    // Gán giá trị vào 1 biến để so sánh lấy giá trị lớn nhất
    int toa_do_trai_tren_max = toa_do_Taxi; // Chéo trái trên
    int toa_do_trai_duoi_max = toa_do_Taxi; // Chéo trái dưới
    int toa_do_phai_tren_max = toa_do_Taxi; // Chéo phải trên
    int toa_do_phai_duoi_max = toa_do_Taxi; // Chéo phải dưới
    int toa_do_trai_max = 0;
    int toa_do_phai_max = 0;
    int toa_do_max = 0;
    // Quét qua các phần tử để so sánh trên đường chéo
    for (int i = 0; i < 10; i++) {
        // Điều kiện đảm bảo kết quả so sánh không bị tràn ra khỏi mảng 
        if (p - i >= 0 && q - i >= 0) { // Đối với chéo trái trên
            if (toa_do_trai_tren_max < toa_do[p - i][q - i]) {
                toa_do_trai_tren_max = toa_do[p - i][q - i];
            }
        }
        // Điều kiện đảm bảo kết quả so sánh không bị tràn ra khỏi mảng 
        if (p + i < 10 && q - i >= 0) { // Đối với chéo trái dưới 
            if (toa_do_trai_duoi_max < toa_do[p + i][q - i]) {
                toa_do_trai_duoi_max = toa_do[p + i][q - i];
            }
        }
        // Tìm giá trị lớn nhất của tọa độ trên đường chéo trái
        toa_do_trai_max = (toa_do_trai_tren_max > toa_do_trai_duoi_max) ? toa_do_trai_tren_max : toa_do_trai_duoi_max;
        // Điều kiện đảm bảo kết quả so sánh không bị tràn ra khỏi mảng 
        if (p - i >= 0 && q + i < 10) { // Đối với chéo phải trên
            if (toa_do_phai_tren_max < toa_do[p - i][q + i]) {
                toa_do_phai_tren_max = toa_do[p - i][q + i];
            }
        }
        // Điều kiện đảm bảo kết quả so sánh không bị tràn ra khỏi mảng 
        if (p + i < 10 && q + i < 10) { // Đối với chéo phải dưới 
            if (toa_do_phai_duoi_max < toa_do[p + i][q + i]) {
                toa_do_phai_duoi_max = toa_do[p + i][q + i];
            }
        }
        // Tìm giá trị lớn nhất của tọa độ trên đường chéo phải
        toa_do_phai_max = (toa_do_phai_tren_max > toa_do_phai_duoi_max) ? toa_do_phai_tren_max : toa_do_phai_duoi_max;
        // Tìm giá trị lớn nhất của tọa độ trên 2 đường chéo
        toa_do_max = (toa_do_trai_max > toa_do_phai_max) ? toa_do_trai_max : toa_do_phai_max;
    }
    // Tính toán số liệu dựa trên kết quả
    if (abs(toa_do_max) >= abs(toa_do_Taxi)) { // Đuổi kịp
        double EXP1_dbl = EXP1 * 1.12;
        double EXP2_dbl = EXP2 * 1.12;
        double HP1_dbl = HP1 * 1.10;
        double HP2_dbl = HP2 * 1.10;
        EXP1 = lam_tron (EXP1_dbl);
        EXP2 = lam_tron (EXP2_dbl);
        HP1 = lam_tron (HP1_dbl);
        HP2 = lam_tron (HP2_dbl); 
    }
    else { // Không đuổi kịp
        double EXP1_dbl = EXP1 * 0.88;
        double EXP2_dbl = EXP2 * 0.88;
        double HP1_dbl = HP1 * 0.90;
        double HP2_dbl = HP2 * 0.90;
        EXP1 = lam_tron (EXP1_dbl);
        EXP2 = lam_tron (EXP2_dbl);
        HP1 = lam_tron (HP1_dbl);
        HP2 = lam_tron (HP2_dbl); 
    }
    // Đảm bảo số liệu nằm trong khoảng quy định
    EXP1 = check(EXP1, 0, 600);
    EXP2 = check(EXP2, 0, 600);
    HP1 = check(HP1, 0, 666);
    HP2 = check(HP2, 0, 666);
    // Trả về giá trị thực 
    return (abs(toa_do_max) < abs(toa_do_Taxi)) ? toa_do_Taxi : toa_do_max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    //TODO: implement task
    // Trích chuỗi "se" trước '@' trong chuỗi "email"
    string EMAIL = email;
    string SE = EMAIL.substr(0, EMAIL.find('@'));
    // Điều kiện độ dài ký tự
    string S = s;
    if (S.length() < 8) return -1; // Ít hơn 8 ký tự
    if (S.length() > 20) return -2; // Nhiều hơn 20 ký tự
    // Điều kiện có chứa chuỗi trích "se"
    size_t vi_tri_SE = S.find(SE); // Tìm vị trí của "se" trong s
    if (vi_tri_SE != string::npos) return -(300 + vi_tri_SE); // Khác với vị trí 'không có trong chuỗi' (npos), tức là có tồn tại chuỗi SE
    // Điều kiện chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    if (S.length() >= 3) { // Cần ít nhất 3 ký tự trong 1 mật khẩu 
        for (int i = 0; i < S.length() - 2; i++) { // So sánh 2 ký tự liên tiếp nên phải bỏ đi 2 ký tự để tránh bị tràn khi so sánh tới cuối chuỗi
            if (S[i] == S[i + 1] && S[i] == S[i + 2]) {
                return -(400 + i);
            }
        }    
    }
    // Điều kiện ký tự đặc biệt
    bool co_ky_tu_db = false;
    for (int i = 0; i < S.length(); i++) { 
        if (S[i] == '@' || S[i] == '#' || S[i] == '$' || S[i] == '%' || S[i] == '!') { // Không chứa bất kỳ ký tự nào ở trên
            co_ky_tu_db = true;
            break;  // Nếu có ký tự thì thoát vòng lặp
        }
    }
    if (!co_ky_tu_db) return -5;
    // Điều kiện các ký tự không hợp lệ nhưng không thuộc các điều kiện nêu trên
    for (int i = 0; i < S.length(); i++) { //isalnum vừa không là int vừa không char, nói chung là thứ nào đó khác 2 cái trên
        if (!isalnum(S[i]) && S[i] != '@' && S[i] != '#' && S[i] != '$' && S[i] != '%' && S[i] != '!') {
            return i;
        }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //TODO: implement task
    // Tạo biến số lần đếm cao nhất
    int max_so_dem = 0;
    // Tạo biến có độ dài ký tự cao nhất
    int max_ky_tu = 0;
    // Tạo biến có số lần & độ dài ký tự cao nhất
    int max_ca_hai = -1;
    // Tìm chuỗi có số lần đếm cao nhất
    for (int i = 0; i < num_pwds; i++) {    // Lấy 1 chuỗi ký tự từ mảng 
        int so_dang_dem = 0;                // Số lần giống nhau đếm được (trước khí gán lại)
        int so_ky_tu = strlen(arr_pwds[i]); // Đếm số ký tự trong chuỗi không bao gồm NULL
        for (int j = 0; j < num_pwds; j++) {    // lấy 1 chuỗi ký tự từ mảng 1
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) { // So sánh mỗi chuỗi với 1 hàng chuỗi ký tự thứ 2 xem coi có cái nào giống nhau không
                so_dang_dem++;              // Tăng 1 lần xuất hiện của chuỗi trong mảng 
            }
        } // Có trường hợp giống nhau // Không có trường hợp giống nhau VÀ lấy giá trị của số lượng ký tự chuỗi thứ i
        if (so_dang_dem > max_so_dem || (so_dang_dem == max_so_dem && so_ky_tu > max_ky_tu)) {
            // Đặt lại giá trị max lần xuất hiện cao nhất để tiếp tục lần so sánh thứ i + 1
            max_so_dem = so_dang_dem;
            // Đặt lại giá trị max số lượng ký tự cao nhất để tiếp tục lần so sánh thứ i + 1
            max_ky_tu = so_ky_tu;
            // Trả về vị trí thứ i sau mỗi lần kiểm tra của vòng lặp
            max_ca_hai = i;
        }
    }
    return max_ca_hai;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////