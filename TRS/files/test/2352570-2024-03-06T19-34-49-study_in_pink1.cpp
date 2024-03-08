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

inline int checkEXP(int exp_func) {
    if (exp_func <= 0) {
        return 0;
    }
    if (exp_func >= 600) {
        return 600;
    }
    else {
        return exp_func;
    }
}
inline int checkHP(int hp_func) {
    if (hp_func <= 0) {
        return 0;
    }
    if (hp_func >= 666) {
        return 666;
    }
    else {
        return hp_func;
    }
}
inline int checkM(int M_func) {
    if (M_func <= 0) {
        return 0;
    }
    if (M_func >= 3000) {
        return 3000;
    }
    else {
        return M_func;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    // TODO: Complete this function
    double exp1_c1 = exp1, exp2_c2 = exp2, e2 = e1;
    if (e1 < 0 || e1 >99) {
        return -99;
    }
    else if (e1 >= 0 && e1 <=3) {
        //Watson sau khi nghe giảng
        if (e1 == 0) {
            exp2 += 29;
        }
        else if (e1 == 1) {
            exp2 += 45;
        }
        else if (e1 == 2) {
            exp2 += 75;
        }
        else if (e1 == 3) {
            exp2 += (29 + 45 + 75);
        }
        int D = e1*3 + exp1*7;
        if (D % 2 == 0) {
            exp1_c1 += (double) D/200; //Holmes nếu đúng
            exp1 = ceil (exp1_c1);
            exp1 = checkEXP(exp1);
        }
        else if (D %2 != 0) {
            exp1_c1 -= (double) D/100; //Holmes nếu sai
            exp1 = ceil (exp1_c1);
            exp1 = checkEXP(exp1);
        }
    }
    else if (e1 >= 4 && e1<=99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2_c2 +=(double) (e2/4 + 19); //Holmes giảng thông tin 1
            exp2 = ceil (exp2_c2);
            exp2 = checkEXP(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2_c2 += (double) (e2/9 +21); //Holmes giảng thông tin 2
            exp2 = ceil (exp2_c2);
            exp2 = checkEXP(exp2);
        }
        else if (e1 >= 50 && e1 <=65) {
            exp2_c2 += (double) (e2/16 +17);
            exp2 = ceil (exp2_c2);
            exp2 = checkEXP(exp2);
        }
        else if (e1 >= 66 && e1 <=79) {
            exp2_c2 += (double) (e2/4 +19); //Holmes giảng thông tin 1
            exp2 = ceil (exp2_c2);
            exp2 = checkEXP(exp2);
            if (exp2 > 200) {
                exp2_c2 = exp2;
                exp2_c2 += (double) (e2/9 +21);
                exp2 = ceil (exp2);
                exp2 = checkEXP(exp2);
            }
        }
        else if (e1 >= 80 && e1 <=99) {
            exp2_c2 += (double) (e2/4 +19); //Holmes giảng thông tin 1&2
            exp2 = ceil (exp2_c2);
            exp2_c2 = exp2;
            exp2 = checkEXP(exp2);
            exp2_c2 += (double) (e2/9 +21);
            exp2 = ceil (exp2_c2);
            exp2 = checkEXP(exp2);
            if (exp2 > 400) {
                exp2_c2 = exp2;
                exp2_c2 += (double) (e2/16 + 17);
                exp2 = ceil (exp2_c2);
                exp2 = checkEXP(exp2);
                exp2_c2 = exp2;
                exp2_c2 *= (double) (1.15);
                exp2 = ceil (exp2_c2);
                exp2 = checkEXP(exp2);
                
            }
        }
        exp1 -= e1; //Holmes bị trừ 
        exp1 = checkEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double P1, P2, P3;
    double so_mu =  round(sqrt (EXP1));
    int S = pow (so_mu, 2); //Khởi chạy số chính phương gần EXP1 nhất
    //con đường 1
    double HP1_C1 = HP1, M1_C1 = M1, EXP1_C1 = EXP1;
    if (EXP1 >= S) { 
        P1 = 1; //P1=100%
    }
    else if (EXP1 < S) {
        double EXP1_C2 = EXP1;
        P1 = ((EXP1_C2/S+80)/(123));
    }
    //con đường 2
    if (E2 % 2 != 0 && M1 >0) {
        int budget = M1;
        while (true) {
            if (HP1 < 200) { 
                HP1_C1 = HP1;
                HP1_C1 *= (double) 1.3;  //HP Holmes được cộng 30%
                HP1 = ceil (HP1_C1);
                HP1 = checkHP(HP1);
                M1_C1 = M1;
                M1_C1 -= 150; //Tiền bị trừ 150
                M1 = ceil (M1_C1);
                M1 = checkM(M1);
            }
            else if (HP1 >= 200) {
                HP1_C1 = HP1;
                HP1_C1 *= (double) 1.1;
                HP1 = ceil (HP1_C1);
                HP1 = checkHP(HP1);
                M1_C1 = M1;
                M1_C1 -= 70;
                M1 = ceil (M1_C1);
                M1 = checkM(M1);
            }
            if (M1 < (0.5 * budget)) {
                break;
            }
            if (EXP1 < 400) {
                M1_C1 = M1;
                M1_C1-=200; //Đi taxi
                M1 = ceil (M1_C1);
                M1 = checkM(M1);
                EXP1_C1 = EXP1;
                EXP1_C1 *= (double) (1.13);
                EXP1 = ceil (EXP1_C1);
                EXP1 = checkEXP (EXP1);
            }
            else if (EXP1 >= 400) {
                M1_C1 = M1;
                M1_C1 -= 120; //Đi xe ngựa
                M1 = ceil (M1_C1);
                M1 = checkM(M1);
                EXP1_C1 = EXP1;
                EXP1_C1 *= (double) (1.13);
                EXP1 = ceil (EXP1_C1);
                EXP1 = checkEXP (EXP1);
            }
            if (M1 < (0.5 * budget)) {
                break;
            }
            if (EXP1 < 300) {
                M1_C1 = M1;
                M1_C1 -= 100;
                M1 = ceil (M1_C1);
                M1 = checkM (M1);
                EXP1_C1 = EXP1;
                EXP1_C1 *= (double) 0.9; //Nhầm vali, giảm 10%
                EXP1 = ceil (EXP1_C1);
                EXP1 = checkEXP (EXP1);
            }
            else if (EXP1 >= 300) {
                M1_C1 = M1;
                M1_C1 -= 120;
                M1 = ceil (M1_C1);
                M1 = checkM (M1);
                EXP1_C1 = EXP1;
                EXP1_C1 *= (double) 0.9; //Nhầm vali, giảm 10%
                EXP1 = ceil (EXP1_C1);
                EXP1 = checkEXP (EXP1);
            }
            if (M1 < (0.5 * budget)) {
                break;
            }
        }
        HP1_C1 = HP1;
        HP1_C1 *= (double) (0.83);
        HP1 = ceil (HP1_C1);
        HP1 = checkHP (HP1);
        EXP1_C1 = EXP1;
        EXP1_C1 *= (double) (1.17);
        EXP1 = ceil (EXP1_C1);
        EXP1 = checkEXP (EXP1);
    }
    else if (E2 %2 == 0) {
        if (M1 > 0) {
            if (HP1 < 200) { 
                HP1_C1 *= (double) 1.3;  //HP Holmes được cộng 30%
                HP1 = ceil (HP1_C1);
                HP1 = checkHP (HP1);
                M1_C1 -= 150; //Tiền bị trừ 150
                M1 = ceil (M1_C1);
                M1 = checkM (M1);
            }
            else if (HP1 >= 200) {
                HP1_C1 *= (double) 1.1;
                HP1 = ceil (HP1_C1);
                HP1 = checkHP (HP1);
                M1_C1 -= 70;
                M1 = ceil (M1_C1);
                M1 = checkM (M1_C1);
            }
            if (M1 > 0) {
                if (EXP1 < 400) {
                    M1_C1 = M1;
                    M1_C1 -=200; //Đi taxi
                    M1 = ceil (M1_C1);
                    M1 = checkM (M1);
                    EXP1_C1 = EXP1;
                    EXP1_C1 *= (double) (1.13);
                    EXP1 = ceil (EXP1_C1);
                    EXP1 = checkEXP (EXP1);
                }
                else if (EXP1 >= 400) {
                    M1_C1 = M1;
                    M1_C1 -= 120; //Đi xe ngựa
                    M1 = ceil (M1_C1);
                    M1 = checkM (M1);
                    EXP1_C1 = EXP1;
                    EXP1_C1 *= (double) (1.13);
                    EXP1 = ceil (EXP1_C1);
                    EXP1 = checkEXP (EXP1);
                }
            }
            if (M1 > 0) {
                if (EXP1 < 300) {
                    M1_C1 = M1;
                    M1_C1 -= 100;
                    M1 = ceil (M1_C1);
                    M1 = checkM (M1);
                    EXP1_C1 = EXP1;
                    EXP1_C1 *= (double) 0.9; //Nhầm vali, giảm 10%
                    EXP1 = ceil (EXP1_C1);
                    EXP1 = checkEXP (EXP1);
                }
                else if (EXP1 >= 300) {
                    M1_C1 -= 120;
                    M1 = ceil (M1_C1);
                    M1 = checkM (M1);
                    EXP1_C1 *= (double) 0.9; //Nhầm vali, giảm 10%
                    EXP1 = ceil (EXP1_C1);
                    EXP1 = checkEXP (EXP1);
                }
            }
            if (M1 <= 0) {
                M1 = 0;
            }
        }
        HP1_C1 = HP1;
        HP1_C1 *= (double) (0.83);
        HP1 = ceil (HP1_C1);
        HP1 = checkHP (HP1_C1);
        EXP1_C1 = EXP1;
        EXP1_C1 *= (double) (1.17);
        EXP1 = ceil (EXP1_C1);
        EXP1 = checkEXP (EXP1);
    }
    double mu =  round(sqrt (EXP1));
    int S2 = pow (mu, 2); //Khởi chạy số chính phương gần EXP1 nhất
    if (EXP1 >= S2) { 
        P2 = 1; //P1=100%
    }
    else if (EXP1 < S2) {
        double EXP1_C2 = EXP1;
        P2 = ((EXP1_C2/S2+80)/(123));
    }
    //con đường 3
    double P[10]= {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 <=9 && E2 >=0) {
        P3 = P[E2];
        P3 /= 100;
    }
    else if (E2 >= 10) {
        int i = ((((E2/10)%10) + (E2%10))%10);
        P3 = P[i];
        P3 /= 100;
    }
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)) {
        EXP1_C1 = EXP1;
        EXP1_C1 *= (double) (0.75);
        EXP1 = ceil (EXP1_C1);
        EXP1 = checkEXP (EXP1);
    }
    else if ((P1 != 1) || (P2 != 1) || (P3 != 1)) {
        double average = ((P1 + P2 + P3)/3);
        if (average < 0.5) {
            HP1_C1 = HP1;
            HP1_C1 *= (double) (0.85);
            HP1 = ceil (HP1_C1);
            HP1 = checkHP (HP1);
            EXP1_C1 = EXP1;
            EXP1_C1 *= (double) (1.15);
            EXP1 = ceil (EXP1_C1);
            EXP1 = checkEXP (EXP1);
        }
        else if (average >= 0.5) {
            HP1_C1 = HP1;
            HP1_C1 *= (double) (0.9);
            HP1 = ceil (HP1_C1);
            HP1 = checkHP (HP1);
            EXP1_C1 = EXP1;
            EXP1_C1 *= (double) (1.2);
            EXP1 = ceil (EXP1_C1);
            EXP1 = checkEXP (EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //TODO: implement task
    int taxi_score[10][10] = {0};
    int s_w_score[10][10] = {0};
    int hang, cot;
    int positive_count = 0, negative_count = 0;
    int max_score;
    double EXP2_C2 = EXP2, EXP1_C1 = EXP1;
    double HP2_C2 = HP2, HP1_C1 = HP1;
    int last_value;
    if (E3 <0 || E3 > 99) {
        return -99;
    }
    
    //tạo ma trận lưu điểm số của taxi
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxi_score[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // dem so phan tu duong va am trong mang
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (taxi_score[i][j] > (2 * E3)) {
                positive_count ++;
            }
            if (taxi_score[i][j] < (-E3)) {
                negative_count ++;
            }
        }
    }
    if (positive_count > 10) {
        positive_count = (positive_count % 10) + ((positive_count - (positive_count % 10))/10);
        if (positive_count > 10) {
            positive_count = (positive_count % 10) + ((positive_count - (positive_count % 10))/10);
        }
        else if (positive_count == 10) {
            positive_count = 1;
        }
    }
    if (negative_count > 10) {
        negative_count = (negative_count % 10) + ((negative_count - (negative_count % 10))/10);
        if (negative_count > 10) {
            negative_count = (negative_count % 10) + ((negative_count - (negative_count % 10))/10);
        }
        else if (negative_count == 10) {
            negative_count = 1;
        }
    }
    // duong cheo trai va phai so sanh gia tri
    max_score = taxi_score [positive_count][negative_count];
    hang = positive_count - 1;
    cot = negative_count - 1;
    while ((hang >= 0 && hang <= 10) &&  (cot >= 0 && cot <= 10)) {
        if (taxi_score[hang][cot] > max_score) {
            max_score = taxi_score[hang][cot];
        }
        hang --;
        cot --;
    }
    hang = positive_count - 1;
    cot = negative_count + 1;
    while ((hang >= 0 && hang <= 10) &&  (cot >= 0 && cot <= 10)) {
        if (taxi_score[hang][cot] > max_score) {
            max_score = taxi_score[hang][cot];
        }
        hang --;
        cot ++;
    }
    hang = positive_count + 1;
    cot = negative_count - 1;
    while ((hang >= 0 && hang <= 10) &&  (cot >= 0 && cot <= 10)) {
        if (taxi_score[hang][cot] > max_score) {
            max_score = taxi_score[hang][cot];
        }
        hang ++;
        cot --;
    }
    hang = positive_count + 1;
    cot = negative_count + 1;
    while ((hang >= 0 && hang <= 10) &&  (cot >= 0 && cot <= 10)) {
        if (taxi_score[hang][cot] > max_score) {
            max_score = taxi_score[hang][cot];
        }
        hang ++;
        cot ++;
    }
    int present_value = taxi_score [positive_count][negative_count];
    // khong duoi kip taxi
    if (abs(present_value) > max_score) {
        EXP1_C1 = EXP1;
        EXP1_C1 *= (double) (0.88);
        EXP1 = ceil (EXP1_C1);
        EXP1 = checkEXP (EXP1);
        EXP2_C2 = EXP2;
        EXP2_C2 *= (double) (0.88);
        EXP2 = ceil (EXP2_C2);
        EXP2 = checkEXP (EXP2);
        HP1_C1 = HP1;
        HP1_C1 *= (double) (0.9);
        HP1 = ceil (HP1_C1);
        HP1 = checkHP (HP1);
        HP2_C2 = HP2;
        HP2_C2 *= (double) (0.9);
        HP2 = ceil (HP2_C2);
        HP2 = checkHP (HP2);
        last_value = present_value;
    }
    // duoi kip taxi
    if (abs(present_value) <= max_score) {
        EXP1_C1 = EXP1;
        EXP1_C1 *= (double) (1.12);
        EXP1 = ceil (EXP1_C1);
        EXP1 = checkEXP (EXP1);
        EXP2_C2 = EXP2;
        EXP2_C2 *= (double) (1.12);
        EXP2 = ceil (EXP2_C2);
        EXP2 = checkEXP (EXP2);
        HP1_C1 = HP1;
        HP1_C1 *= (double) (1.1);
        HP1 = ceil (HP1_C1);
        HP1 = checkHP (HP1);
        HP2_C2 = HP2;
        HP2_C2 *= (double) (1.1);
        HP2 = ceil (HP2_C2);
        HP2 = checkHP (HP2);
        last_value = max_score;
    }
    return last_value;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = email;
    string matkhau = s;
    int len = strlen (s);
    int n = se.find ("@"); //tìm vị trí của chuỗi chỗ @
    se = se.substr(0, n);

    
    bool special_case = false;
    bool continued_case = false;
    //quy định về độ dài của mật khẩu
    if ((len) > 20) { 
        return -2;
    }
    else if (len < 8) {
        return -1;
    }

    //check xem liệu mk có chứa ký tự đặc biệt
    for (int i = 0; i < len;i ++) {
        if ((matkhau [i] == '@') || (matkhau [i] == '#') || (matkhau [i] == '%') || (matkhau [i] == '$') || (matkhau [i] == '!')) {  
            special_case = true;
        }
        if (matkhau[i] == '\0') {
            continued_case = true;
        }
    }

    //check xem mk có chứa chuỗi se
    int sei = matkhau.find (se); 
    if ((sei > 0)) {
        return -(300 + sei);
    }
    else if ((sei == -1) || (sei == string::npos) || (sei == 0)) {
        return -300;
    }

    if (!special_case) {
        return -5;
    }
    //check xem liệu có nhiều hơn 2 ký tự trùng nhau trong mật khẩu và trả về vị trí của chuỗi đầu tiên bị trùng
    if (continued_case) {
        for (int i = 1; i < (len);i ++) {
            if (matkhau[i] == matkhau[i - 1] && matkhau[i] == matkhau[i + 1]) {
                int sci = i - 1;
                return -(400 + sci);
            }
        }
    }
    
    return -10;   
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int dem_max = 0, len_max = 0, i_max = 0, dem, len;
    if (num_pwds == 1) { //1 thif k trunfg
        return 0;
    }
    else {
        for (int i = 0; i < num_pwds; i ++) {
            string tamthoi1 = arr_pwds [i]; //gán 1 biến tạm thời cho con trỏ hằng
            dem = 0;
            len = strlen (arr_pwds[i]);
            for (int j = 0; j < num_pwds; j++) { //2 vòng lặp cho các số chạy tuần tự 
                string tamthoi2 = arr_pwds[j];
                if (tamthoi1 == tamthoi2) {
                    dem ++;
                }
                //nếu trùng số biến đếm thì so sánh số lượng ký tự
                if (dem > dem_max || (dem == dem_max && (len > len_max) )) {
                    i_max = i;
                    len_max = len;
                    dem_max = dem;
                }
            }
        }
    return i_max;
    }
    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////