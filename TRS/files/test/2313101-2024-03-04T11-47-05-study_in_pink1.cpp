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



//Kiểm tra giới hạn đầu cuối cho nhiệm vụ 1
void minmax1(int &exp1, int &exp2) {
        if (exp1 > 600) exp1 = 600;
        if (exp1 < 0) exp1 = 0;
        if (exp2 > 600) exp2 = 600;
        if (exp2 < 0) exp2 = 0;
    }

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //------------------

if (e1>=0&&e1<=99){
    if (e1>=0&&e1<=3){
        //1 đến 3
        if (e1==0) exp2 = ceil(exp2 + 29);
        else if (e1==1) exp2 = ceil(exp2 + 45);
        else if (e1==2) exp2 = ceil(exp2 + 75);
        else if (e1==3) exp2 = ceil(exp2 + 29 + 45 + 75);
        minmax1(exp1,exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D%2==0) exp1 = ceil(exp1 + D/200.00);
        else exp1 = ceil(exp1 - D/100.00);
        minmax1(exp1,exp2);
    }
    if (e1>=4&&e1<=99){
        //4 đến 99
        if (e1>=4&&e1<=19) exp2 = ceil(exp2 + e1/4.00 + 19);
        else if (e1>=20&&e1<=49) exp2 = ceil(exp2 + e1/9.00 + 21);
        else if (e1>=50&&e1<=65) exp2 = ceil(exp2 + e1/16.00 + 17);
        else if (e1>=66&&e1<=79) {
            exp2 = ceil(exp2 + e1/4.00 + 19);
            minmax1(exp1,exp2);
            if (exp2>200) exp2 = ceil(exp2 + e1/9.00 + 21);
            minmax1(exp1,exp2);
        }
        else if (e1>=80&&e1<=99) {
            exp2 = ceil(exp2 + e1/4.00 + 19);
            minmax1(exp1,exp2);
            exp2 = ceil(exp2 + e1/9.00 + 21);
            minmax1(exp1,exp2);
            if (exp2>400) {
                exp2 = ceil(exp2 + e1/16.00 + 17);
                minmax1(exp1,exp2);
                exp2 = ceil(exp2 + exp2*15.00/100.00);
                minmax1(exp1,exp2);
            }
        }
        exp1 = ceil(exp1 - e1);
        minmax1(exp1,exp2);
    }
    //------------------
    return exp1 + exp2;}
    else return -99;
}

// Task 2

//Kiểm tra giới hạn đầu cuối cho nhiệm vụ 2
void minmax2(int &HP1, int &EXP1, int &M1){
    if (HP1>666) HP1 = 666;
    if (HP1<0) HP1 = 0;
    if (EXP1>600) EXP1 = 600;
    if (EXP1<0) EXP1 = 0;
    if (M1>3000) M1 = 3000;
    if (M1<0) M1 = 0;
}

float XacSuat(int EXP1){
    float p;
    int sqr = sqrt(EXP1);
    int kc1 = EXP1 - sqr*sqr;
    int kc2 = (sqr+1)*(sqr+1) - EXP1;
    if (kc1<kc2) p = 100;
    else p = (EXP1/((sqr+1)*(sqr+1))+80)/123.00;
    return p;
}


int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2>=0&&E2<=99){

        //Con đường 1
        float P1 = XacSuat(EXP1);

        //Con đường 2
        float sotienbandau = M1;
        int sotiendatieu = 0;
        while (true){
            if (E2%2==1){
                //E2 là số lẻ

                //Sự kiện 1
                if (HP1 < 200){
                    HP1 = HP1*1.3 + 0.9999;
                    M1 = M1 - 150;
                    sotiendatieu = sotiendatieu + 150;
                } else {
                    HP1 = HP1*1.1 + 0.9999;
                    M1 = M1 - 70;
                    sotiendatieu = sotiendatieu + 70;
                }
                minmax2(HP1,EXP1,M1);

                //Kiểm tra điều kiện sau khi xảy ra sự kiện 1
                if (sotiendatieu>sotienbandau/2){
                    HP1 = HP1*0.83 + 0.9999;
                    EXP1 = EXP1*1.17 + 0.9999;
                    minmax2(HP1,EXP1,M1);
                    break;
                }

                //Sự kiện 2
                if (EXP1 < 400){
                    M1 = M1 - 200;
                    EXP1 = EXP1*1.13 + 0.9999;
                    sotiendatieu = sotiendatieu + 200;
                } else {
                    M1 = M1 - 120;
                    EXP1 = EXP1*1.13 + 0.9999;
                    sotiendatieu = sotiendatieu + 120;
                }
                minmax2(HP1,EXP1,M1);

                //Kiểm tra điều kiện sau khi xảy ra sự kiện 2
                if (sotiendatieu>sotienbandau/2){
                    HP1 = HP1*0.83 + 0.9999;
                    EXP1 = EXP1*1.17 + 0.9999;
                    minmax2(HP1,EXP1,M1);
                    break;
                }

                //Sự kiện 3
                if (EXP1 < 300){
                    M1 = M1 - 100;
                    EXP1 = EXP1*0.9 + 0.9999;
                    sotiendatieu = sotiendatieu + 100;
                } else {
                    M1 = M1 - 120;
                    EXP1 = EXP1*0.9 + 0.9999;
                    sotiendatieu = sotiendatieu + 120;
                }
                minmax2(HP1,EXP1,M1);

                //Kiểm tra điều kiện sau khi xảy ra sự kiện 3
                if (sotiendatieu>sotienbandau/2){
                    HP1 = HP1*0.83 + 0.9999;
                    EXP1 = EXP1*1.17 + 0.9999;
                    minmax2(HP1,EXP1,M1);
                    break;
                }
            } else {
                //E2 là số chẵn
                //Sự kiện 1
                if (HP1 < 200){
                    HP1 = HP1*1.3 + 0.9999;
                    M1 = M1 - 150;
                } else {
                    HP1 = HP1*1.1 + 0.9999;
                    M1 = M1 - 70;
                }
                minmax2(HP1,EXP1,M1);

                //Kiểm tra điều kiện sau khi xảy ra sự kiện 1
                if (M1 == 0){
                    HP1 = HP1*0.83 + 0.9999;
                    EXP1 = EXP1*1.17 + 0.9999;
                    minmax2(HP1,EXP1,M1);
                    break;
                }

                //Sự kiện 2
                if (EXP1 < 400){
                    M1 = M1 - 200;
                    EXP1 = EXP1*1.13 + 0.9999;
                } else {
                    M1 = M1 - 120;
                    EXP1 = EXP1*1.13 + 0.9999;
                }
                minmax2(HP1,EXP1,M1);

                //Kiểm tra điều kiện sau khi xảy ra sự kiện 2
                if (M1 == 0){
                    HP1 = HP1*0.83 + 0.9999;
                    EXP1 = EXP1*1.17 + 0.9999;
                    minmax2(HP1,EXP1,M1);
                    break;
                }

                //Sự kiện 3
                if (EXP1 < 300){
                    M1 = M1 - 100;
                    EXP1 = EXP1*0.9 + 0.9999;
                } else {
                    M1 = M1 - 120;
                    EXP1 = EXP1*0.9 + 0.9999;
                }
                minmax2(HP1,EXP1,M1);

                //Kết thúc vòng lặp
                HP1 = HP1*0.83 + 0.9999;
                EXP1 = EXP1*1.17 + 0.9999;
                minmax2(HP1,EXP1,M1);
                break;
            }
            
        }
        float P2 = XacSuat(EXP1);

        //Con đường 3
        int p[10] = {32,47,28,79,100,50,22,83,64,11};
        float P3; 
        int chiso;
        while (E2/10>0) E2 = E2/10 + (E2 - (E2/10)*10);
        P3 = p[E2];
        float FinalP;
        if (P1 == P2 == P3 == 100){
            EXP1 = EXP1*0.75 + 0.9999;
            minmax2(HP1,EXP1,M1);
        } else {
            FinalP = (P1 + P2 + P3)/3;
            if (FinalP<50){
                HP1 = HP1*0.85 + 0.9999;
                EXP1 = EXP1*1.15 + 0.9999;
                minmax2(HP1,EXP1,M1);
            } else {
                HP1 = HP1*0.9 + 0.9999;
                EXP1 = EXP1*1.2 + 0.9999;
                minmax2(HP1,EXP1,M1);
            }
        }
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3

//Kiểm tra giới hạn đầu cuối của các giá trị trong nhiệm vụ 3
void minmax3(int &EXP1, int &HP1, int &EXP2, int &HP2){
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (HP1>666) HP1 = 666;
    if (HP1<0) HP1 = 0;
    if (HP2>666) HP2 = 666;
    if (HP2<0) HP2 = 0;
}

void TimDiemKhoiDauDuongCheoTrai (int &i,int &j){
    while (i>0&&j>0){
        i = i - 1;
        j = j - 1;
    }
}

void TimDiemKhoiDauDuongCheoPhai (int &i,int &j){
    while (i<9&&j>0){
        i = i + 1;
        j = j - 1;
    }
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if (E3>=0&&E3<=99){
    //Tạo 1 ma trận 10x10 lưu số điểm của taxi
    int taxi[10][10] = {0};
    for (int i = 0;i<10;i=i+1){
        for (int j = 0;j<10;j=j+1){
            taxi[i][j] = ((E3*j+i*2)*(i-j));
        }
    }

    //Tìm điểm hai người gặp taxi
    int chisoi = 0, chisoj = 0;
    for (int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            if (taxi[i][j] > (E3*2)) chisoi = chisoi + 1;
            if (taxi[i][j] <-E3) chisoj = chisoj + 1;
        }
    }

    //Fix chi so i va j
    while (chisoi/10>0) chisoi = chisoi/10 + (chisoi - (chisoi/10)*10);
    while (chisoj/10>0) chisoj = chisoj/10 + (chisoj - (chisoj/10)*10);

    int tempi = chisoi;
    int tempj = chisoj;
    int temp2i = chisoi;
    int temp2j = chisoj;
    TimDiemKhoiDauDuongCheoTrai(chisoi,chisoj);
    TimDiemKhoiDauDuongCheoPhai(tempi,tempj);

    int DiemNguoi[100];
    DiemNguoi[0] = taxi[chisoi][chisoj]; 
    DiemNguoi[1] = taxi[tempi][tempj];
    int count = 2;

    //Gán giá trị của 2 đường chéo lưu điểm của taxi vào mảng
    while (chisoi<9&&chisoj<9){
        chisoi = chisoi + 1;
        chisoj = chisoj + 1;
        DiemNguoi[count] = taxi[chisoi][chisoj];
        count = count + 1;
    }
    while (tempi>0&&tempj<9){
        tempi = tempi - 1;
        tempj = tempj + 1;
        DiemNguoi[count] = taxi[tempi][tempj];
        count = count + 1;
    }
    //Mảng sẽ được cin giá trị từ chỉ số 0 đến chỉ số count - 1

    //Tìm giá trị lớn nhất trong mảng chứa điểm của hai người
    int max = DiemNguoi[0];
    for (int i = 1; i<=count - 1; i ++){
        if (DiemNguoi[i]>max) max = DiemNguoi [i];
    }

    int trave;
    if (abs(taxi[temp2i][temp2j])>max){
        trave = taxi[temp2i][temp2j];
        EXP1 = ceil(EXP1-EXP1/100.00*12.00);
        minmax3 (EXP1,HP1,EXP2,HP2);
        HP1 = ceil(HP1-HP1/100.00*10.00);
        minmax3 (EXP1,HP1,EXP2,HP2);
        EXP2 = ceil(EXP2-EXP2/100.00*12.00);
        minmax3 (EXP1,HP1,EXP2,HP2);
        HP2 = ceil(HP2-HP2/100.00*10.00); 
        minmax3 (EXP1,HP1,EXP2,HP2);
    } else {
        trave = max;
        EXP1 = ceil(EXP1+EXP1/100.00*12.00);
        minmax3 (EXP1,HP1,EXP2,HP2);
        HP1 = ceil(HP1+HP1/100.00*10.00);
        minmax3 (EXP1,HP1,EXP2,HP2);
        EXP2 = ceil(EXP2+EXP2/100.00*12.00);
        minmax3 (EXP1,HP1,EXP2,HP2);
        HP2 = ceil(HP2+HP2/100.00*10.00); 
        minmax3 (EXP1,HP1,EXP2,HP2);
    }

    return trave;}
else return -99;
}

// Task 4

//Hàm tính độ dài chuỗi
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Hàm kiểm tra mật khẩu
int checkpass(const char* s, const char* se) {
    int len = stringLength(s);
    
    // Kiểm tra độ dài của mật khẩu
    if (len < 8) return -1; // Mật khẩu quá ngắn
    if (len > 20) return -2; // Mật khẩu quá dài

    // Kiểm tra xem mật khẩu có chứa chuỗi se không
    int seLen = stringLength(se);
    for (int i = 0; i <= len - seLen; ++i) {
        bool trung = true;
        for (int j = 0; j < seLen; ++j) {
            if (s[i + j] != se[j]) {
                trung = false;
                break;
            }
        }
        if (trung) return -(300 + i); // Mật khẩu chứa chuỗi se
    }

    // Kiểm tra các ký tự liên tiếp và giống nhau
    for (int i = 0; i < len - 2; ++i) { //Chạy từ chỉ số 0, loại trừ hai ký tự cuối
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Mật khẩu chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
        }
    }

    // Kiểm tra xem mật khẩu có chứa ít nhất một ký tự đặc biệt không
    bool KyTuDacBiet = false;
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            KyTuDacBiet = true;
            break;
        }
    }
    if (!KyTuDacBiet) return -5; // Mật khẩu không chứa ký tự đặc biệt

    // Kiểm tra xem mật khẩu có chứa các ký tự không hợp lệ
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (!((c >= '0' && c <= '9') || // Chữ số
              (c >= 'a' && c <= 'z') || // Chữ cái thường
              (c >= 'A' && c <= 'Z') || // Chữ cái in hoa
              (c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))) { // Ký tự đặc biệt
            return i; // Trả về vị trí của ký tự không hợp lệ
        }
    }

    //Nếu tất cả điều kiện đều không vi phạm
    // Mật khẩu hợp lệ
    return -10;
}


int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    char se[100];

    //Copy ký tự từ email sang se cho tới khi gặp ký tự @ thì dừng lại
    int count = 0;
    while (email[count]!='@'){
        se[count] = email[count];
        count = count + 1;
    }
    se[count] = '\0';

    int returnn = checkpass(s,se);

    return returnn;
}

// Task 5

//Struct để lưu thông tin về mật khẩu và số lần xuất hiện của nó
struct ThongTinPass {
    string password;
    int count;
};

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // Khởi tạo mảng để lưu thông tin về mật khẩu và số lần xuất hiện
    ThongTinPass passwords[num_pwds];
    int SoPassDuocTimThay = 0;

    // Duyệt qua mảng arr_pwds, đếm số lần xuất hiện của mỗi mật khẩu
    for (int i = 0; i < num_pwds; ++i) {
        bool found = false;
        // Kiểm tra xem mật khẩu đã xuất hiện trước đó chưa
        for (int j = 0; j < SoPassDuocTimThay; ++j) {
            if (passwords[j].password == arr_pwds[i]) {
                passwords[j].count++;
                found = true;
                break;
            }
        }
        // Nếu mật khẩu chưa xuất hiện trước đó, thêm vào mảng
        if (!found) {
            passwords[SoPassDuocTimThay].password = arr_pwds[i];
            passwords[SoPassDuocTimThay].count = 1;
         SoPassDuocTimThay++;
        }
    }

    // Tìm mật khẩu xuất hiện nhiều nhất và có độ dài lớn nhất
    string FinalPass;
    int max_count = 0;
    int max_length = 0;
    for (int i = 0; i < SoPassDuocTimThay; ++i) {
        if (passwords[i].count > max_count || (passwords[i].count == max_count && passwords[i].password.size() > max_length)) {
            FinalPass = passwords[i].password;
            max_count = passwords[i].count;
            max_length = passwords[i].password.size();
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu đúng trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == FinalPass) {
            return i;
        }
    }

    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////