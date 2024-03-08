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

// Hàm làm tròn và kiểm tra điều kiện cuối cùng
int lamtronAndCheck(double value, int firstpoint, int lastpoint) {
    int result = ceil(value);
    result = (result < firstpoint) ? firstpoint : (result > lastpoint) ? lastpoint : result;
    return result;
}
//Hàm kiểm tra số chính phương cho task 2
bool lasochinhphuong(int n) {
    if (n <= 0) return false;
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    //hàm tăng EXP Watson theo thông tin
    // check input
    if (E1 < 0 || E1 > 99) return -99;
    EXP1 = lamtronAndCheck(EXP1, 0, 600);
    EXP2 = lamtronAndCheck(EXP2, 0, 600);
    
    //Trường hợp 1
    if (0<=E1 && E1<=3){
        if (E1 == 0) {
            EXP2 += 29;
        } else if (E1 == 1) {
            EXP2 += 45;
        } else if (E1 == 2) {
            EXP2 += 75;
        } else if (E1 == 3) {
            EXP2 += 29 + 45 + 75;
        } 
    //tính EXP tăng giảm của Sherlock
        double EXP1_TEST=EXP1;
        double E1_TEST=E1;
        double D=double(E1_TEST*3+EXP1_TEST*7);
        int E=lamtronAndCheck(D,0,99999);
        if (E%2==0) EXP1_TEST+=D/200;
        else EXP1_TEST-=D/100;
        EXP1=lamtronAndCheck(EXP1_TEST,0,600);
    }
    //Trường hợp 2
    
    else{    
        double E1_TEST=E1;
        double EXP2_TEST=EXP2;
        if (4<=E1 && E1<=19){
            EXP2_TEST += double(E1_TEST/4+19);
            EXP2_TEST =lamtronAndCheck(EXP2_TEST,0,600);
        }
        if (20<=E1 && E1<=49){
            EXP2_TEST += double(E1_TEST/9+21);
            EXP2_TEST =lamtronAndCheck(EXP2_TEST,0,600);
        }
        if (50<=E1 && E1<=65){
            EXP2_TEST += double(E1_TEST/16+17);
            EXP2_TEST =lamtronAndCheck(EXP2_TEST,0,600);
        }
        if (66<=E1 && E1<=79){
            EXP2_TEST += double(E1_TEST/4+19);
            EXP2_TEST = lamtronAndCheck(EXP2_TEST,0,600);
            if(EXP2_TEST>200){
                EXP2_TEST += double(E1_TEST/9+21);
                EXP2_TEST = lamtronAndCheck(EXP2_TEST,0,600);
            }
        }
        if(80<=E1 && E1<=99){
            EXP2_TEST += double(E1_TEST/4+19);
            EXP2_TEST = lamtronAndCheck(EXP2_TEST,0,600);
            EXP2_TEST += double(E1_TEST/9+21);
            EXP2_TEST = lamtronAndCheck(EXP2_TEST,0,600);
            if (EXP2_TEST>400){
                EXP2_TEST += double((E1_TEST/16)+17);
                EXP2_TEST = lamtronAndCheck(EXP2_TEST,0,600);    
                EXP2_TEST*=1.150000;
            }
        }
        EXP1-=E1;
        EXP2=lamtronAndCheck(EXP2_TEST,0,600);
    }
    EXP1=lamtronAndCheck(EXP1,0,600);
    EXP2=lamtronAndCheck(EXP2,0,600);
    return EXP1 + EXP2;
}


//Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
// TODO: Complete this function
//hàm tăng EXP Watson theo thông tin
// check input
    if (E2 < 0 || E2 > 99) return -99;
    HP1=lamtronAndCheck(HP1,0,666);
    EXP1=lamtronAndCheck(EXP1,0,600);
    M1=lamtronAndCheck(M1,0,3000);
    // TODO: Complete this function
//Tìm số chính phương S gần nhất với EXP1
    double P, P1, P2, P3;
    int S;
    int sqrt_EXP1 = sqrt(EXP1);
    int lower_cp = sqrt_EXP1 * sqrt_EXP1;
    int higher_cp = (sqrt_EXP1 + 1) * (sqrt_EXP1 + 1);

    // Tìm số chính phương gần nhất
    if (EXP1 - lower_cp < higher_cp - EXP1) {
        S = lower_cp;
    }
    else {
        S = higher_cp;
    }

//Con đường 1
    if (EXP1 >= S) {
        P1 = 1;
    }
    else {
        P1 = (double(EXP1) / S + 80) / 123;
    }


double HP1_TEST = HP1;
double EXP1_TEST=EXP1;
//Con đường 2
    int moneyNeed = 0;
    // Nếu E2 là số lẻ, lặp lại các sự kiện cho đến khi tiền cần chi lớn hơn 50% số tiền ban đầu
    double half_M1=0.5*M1;
    switch (E2%2) {
        case 1:
            while (moneyNeed <= half_M1) {
                    //Kiểm tra điều kiện 
                if (moneyNeed >= half_M1) break;
                // Sự kiện 1: Mua thức ăn và nước uống
                if (HP1 < 200) {
                    HP1_TEST *= 1.3;
                    M1-=150;
                }
                else {
                    HP1_TEST *= 1.1;
                    M1-=70;
                }
                moneyNeed += (HP1 < 200) ? 150 : 70;
                HP1=lamtronAndCheck(HP1_TEST,0,666);
                    // Kiểm tra điều kiện
                if (moneyNeed >= half_M1) break;

                // Sự kiện 2: Thuê taxi hoặc xe ngựa
                if (EXP1 < 400) { // Đi taxi
                    EXP1_TEST=EXP1;
                    EXP1_TEST *= 1.13;
                    M1-=200;
                }
                else { // Đi xe ngựa
                    EXP1_TEST=EXP1;
                    EXP1_TEST *= 1.13;
                    M1-=120;
                }
                moneyNeed += (EXP1 < 400) ? 200 : 120;
                EXP1=lamtronAndCheck(EXP1_TEST,0,600);
                    // Kiểm tra điều kiện
                if (moneyNeed >= half_M1) break;

                // Sự kiện 3: Gặp người vô gia cư
                if (EXP1 < 300) {
                    M1-=100;
                    EXP1_TEST*= 0.9; // Giảm EXP khi nhầm vali
                }
                else {
                    M1-=120;
                    EXP1_TEST*= 0.9;
                }
                moneyNeed += (EXP1 < 300) ? 100 : 120;
                EXP1=lamtronAndCheck(EXP1_TEST,0,600);
                    // Kiểm tra điều kiện
                if (moneyNeed >= half_M1) break;
            }
            break;
    // Nếu E2 là số chẵn tiếp tục với một lần thực hiện đến khi M1=0 sau sk nào đó
        case 0:
            int M1_TEST=M1;
            // Sự kiện 1: Mua thức ăn và nước uống
                moneyNeed += (HP1 < 200) ? 150 : 70;
                if (HP1 < 200) {
                    HP1_TEST *=1.3;
                }
                else {
                    HP1_TEST *=1.1;
                }
                HP1=lamtronAndCheck(HP1_TEST,0,666);
                if (moneyNeed>=M1_TEST) {
                    M1=0;
                    break;}
            // Sự kiện 2: Thuê taxi hoặc xe ngựa
                moneyNeed += (EXP1 < 400) ? 200 : 120;
                if (EXP1 < 400) { // Đi taxi
                    EXP1_TEST *= 1.13;
                }
                else { // Đi xe ngựa
                    EXP1_TEST *= 1.13;
                }
                EXP1=lamtronAndCheck(EXP1_TEST,0,600);
                if (moneyNeed>=M1_TEST) {
                    M1=0;
                    break;}
            // Sự kiện 3: Gặp người vô gia cư
                moneyNeed += (EXP1 < 300) ? 100 : 120;
                if (EXP1 < 300) {
                    EXP1_TEST *= 0.9; // Giảm EXP khi nhầm vali
                    EXP1=lamtronAndCheck(EXP1_TEST,0,600);
                }
                else {
                    EXP1_TEST *= 0.9; // Giảm EXP do nhầm vali
                    EXP1=lamtronAndCheck(EXP1_TEST,0,600);
                }
            M1-=moneyNeed;
            break;
    }
    HP1_TEST = HP1;
    HP1_TEST *= 0.83;
    HP1=lamtronAndCheck(HP1_TEST,0,666);
    EXP1_TEST = EXP1;
    EXP1_TEST *= 1.17;
    EXP1 = lamtronAndCheck(EXP1_TEST,0,600);
//Xác suất P2
    if (EXP1 >= S) {
        P2 = 1;
    }
    else {
        P2 = (double(EXP1) / S + 80) / 123;
    }
//Con đường 3
    double A[10] = {0.32,0.47,0.28,0.79,100,0.50,0.22,0.83,0.64,0.11};
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        i = E2 / 10 + E2 % 10;
        i = i % 10;
    }
    P3 = A[i];
//Tổng kết
    if (P1 == 1 && P2 == 1 && P3 == 1) { //SH đã nhầm lẫn gì đó
        EXP1_TEST = EXP1;
        EXP1_TEST *=0.75;
        EXP1 = lamtronAndCheck(EXP1_TEST,0,600);
    }
    P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1_TEST = HP1;
            HP1_TEST *= 0.85;
            HP1=lamtronAndCheck(HP1_TEST,0,666);
            EXP1_TEST = EXP1;
            EXP1_TEST *= 1.15;
            EXP1 = lamtronAndCheck(EXP1_TEST,0,600);
        }
        else if (P >= 0.5) {
            HP1_TEST = HP1;
            HP1_TEST *= 0.9;
            HP1=lamtronAndCheck(HP1_TEST,0,666);
            EXP1_TEST = EXP1;
            EXP1_TEST *= 1.2;
            EXP1 = lamtronAndCheck(EXP1_TEST,0,600);
        }
    HP1=lamtronAndCheck(HP1,0,666);
    EXP1=lamtronAndCheck(EXP1,0,600);
    M1=lamtronAndCheck(M1,0,3000);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    //khởi tạo ma trận 10x10
    E3 = lamtronAndCheck(E3, 0, 99);
    int map[10][10];

    // Duyệt qua các vị trí trên bản đồ của taxi
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    //tính giá trị âm dương trong map
    int slduong = 0;
    int slam = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (map[i][j] > (E3 * 2)) {
                slduong++;
            }
            else if (map[i][j] < (-E3)) {
                slam++;
            }
        }
    }
    //vị trí gặp nhau
    while (slduong >= 10) {
        slduong = slduong / 10 + slduong % 10;
    }
    while (slam >= 10)
    {
        slam = slam / 10 + slam % 10;
    }
    int meeting_point = map[slduong][slam];
    // Tính điểm số của Sherlock và Watson

    //tính chéo trái 
    int cheomax = meeting_point;
    int cheotrai = 0;
    int cheophai = 0;
    int x = slduong;
    int y = slam;
    while (true)
    {
        x--;
        y--;
        cheotrai = map[x][y];
        cheomax = max(cheomax, cheotrai);
        if (x == 0 || y == 0) break;
    }
    x = slduong;
    y = slam;
    while (true)
    {
        x++;
        y++;
        cheotrai = map[x][y];
        cheomax = max(cheomax, cheotrai);
        if (x == 9 || y == 9) break;

    }

    //tính chéo phải
    x = slduong;
    y = slam;
    while (true)
    {
        x--;
        y++;
        cheophai = map[x][y];
        cheomax = max(cheomax, cheophai);
        if (x == 0 || y == 9) break;
    }
    x = slduong;
    y = slam;
    while (true)
    {
        x++;
        y--;
        cheophai = map[x][y];
        cheomax = max(cheomax, cheophai);
        if (x == 9 || y == 0) break;
    }


    int SH_WS_SCORE = cheomax;

    //so sánh và cập nhật HP, EXP
    if (abs(meeting_point) > SH_WS_SCORE) {
        EXP1 *= 0.88;
        EXP2 *= 0.88;
        HP1 *= 0.9;
        HP2 *= 0.9;
    }
    else {
        EXP1 *= 1.12;
        EXP2 *= 1.12;
        HP1 *= 1.1;
        HP2 *= 1.1;
        meeting_point = SH_WS_SCORE;
    }
    EXP1 = lamtronAndCheck(EXP1, 0, 600);
    EXP2 = lamtronAndCheck(EXP2, 0, 600);
    HP1 = lamtronAndCheck(HP1, 0, 660);
    HP2 = lamtronAndCheck(HP2, 0, 660);
    return meeting_point;
}

// Task 4
bool containsSpecialChar(const string& str) {
    for (char c : str) {
        if (!isalnum(c) && c != ' ') { // Kiểm tra xem ký tự có phải là chữ hoặc số không
            return true; // Nếu không phải chữ hoặc số, coi như chứa ký tự đặc biệt
        }
    }
    return false; // Không chứa ký tự đặc biệt nếu không tìm thấy trong chuỗi
}
void getse(const char* email, char* username) {
    int i = 0;
    // Sao chép ký tự từ email sang username cho đến khi gặp ký tự '@' hoặc ký tự kết thúc chuỗi '\0'
    while (email[i] != '@' && email[i] != '\0') {
        username[i] = email[i];
        i++;
    }
    // Kết thúc chuỗi username bằng ký tự kết thúc chuỗi '\0'
    username[i] = '\0';
}
int checkPassword(const char* s, const char* email) {
    // Lấy phần se từ địa chỉ email
    char se[100];
    getse(email,se);

    // Yêu cầu hợp lệ về độ dài của mật khẩu
    int sLength = strlen(s);
    if (sLength < 8) return -1;
    if (sLength > 20) return -2;

    // Yêu cầu mật khẩu không chứa chuỗi se
    const char* sei = strstr(s, se);
    if (sei != nullptr)
    {
        return -(300 + (sei-s));
    }

    // Yêu cầu mật khẩu không chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (int i = 0; i < sLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i);
        }
    }

    // Yêu cầu mật khẩu chứa ít nhất 1 ký tự đặc biệt
    if (containsSpecialChar(s)) {//nếu có
    }
    else {
        return -5;
    }// Không chứa ký tự đặc biệt

    // Nếu mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int count[30] = { 0 };
    int length[30] = { 0 };

    // Đếm số lần xuất hiện của mỗi mật khẩu và lưu độ dài của từng mật khẩu
    for (int i = 0; i < num_pwds; i++) {
        count[i]++;
        length[i] = strlen(arr_pwds[i]);
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count[i]++;
            }
        }
    }

    // Tìm mật khẩu có số lần xuất hiện lớn nhất và độ dài lớn nhất
    int max_count = -1;
    int max_length = -1;
    int correct_password_index = -1;

    for (int i = 0; i < num_pwds; i++) {
        if (count[i] > max_count || (count[i] == max_count && length[i] > max_length)) {
            max_count = count[i];
            max_length = length[i];
            correct_password_index = i;
        }
    }

    // Trả về chỉ số của mật khẩu đúng
    return correct_password_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////