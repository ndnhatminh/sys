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
int updateexp2(int& exp2, int e1) {
    switch (e1) {
    case 0:
       
        exp2 += 29;
        if (exp2 > 600) exp2 = 600;
        if (exp2 < 0) exp2 = 0;
        break;
    case 1:
        
        exp2 += 45;
        if (exp2 > 600) exp2 = 600;
        if (exp2 < 0) exp2 = 0;

        break;
    case 2:
        
        exp2 += 75;
        if (exp2 > 600) exp2 = 600;
        if (exp2 < 0) exp2 = 0;
        break;
    case 3:
       
        exp2 += 29 + 45 + 75;
        if (exp2 > 600) exp2 = 600;
        if (exp2 < 0) exp2 = 0;

        break;
    default:
        if (e1 >= 4 && e1 <= 19) {
            exp2 += ceil(static_cast<double>(e1) / 4) + 19;
            if (exp2 > 600) exp2 = 600;
            if (exp2 < 0) exp2 = 0;
            exp2 = ceil(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceil(static_cast<double>(e1) / 9) + 21;
            if (exp2 > 600) exp2 = 600;
            if (exp2 < 0) exp2 = 0;
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceil(static_cast<double>(e1) / 16) + 17;
            if (exp2 > 600) exp2 = 600;
            if (exp2 < 0) exp2 = 0;
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(static_cast<double>(e1) / 4) + 19;
            if (exp2 > 200) {
                exp2 += ceil(static_cast<double>(e1) / 9) + 21;
            }
            if (exp2 > 600) exp2 = 600;
            if (exp2 < 0) exp2 = 0;
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil(static_cast<double>(e1) / 4) + 19;
            

                exp2 += ceil(static_cast<double>(e1) / 9) + 21;

                if (exp2 > 400) {
                    exp2 += ceil(static_cast<double>(e1) / 16) + 17;
                    
                    exp2 = ceil(static_cast<double>(exp2) * 1.15);
                }
            
            if (exp2 > 600) exp2 = 600;
            if (exp2 < 0) exp2 = 0;
        }
    }
    return exp2;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 3) {
        
        updateexp2(exp2, e1); 
        if (exp1 > 600) exp1 = 600;
        if (exp1 < 0) exp1 = 0;
       
        int D = e1 * 3 + exp1 * 7;
        
        if (D % 2 == 0) {
            exp1 = ceil(exp1+static_cast<double>(D) / 200.0);
        }
        else {
            exp1 = ceil(exp1-static_cast<double>(D) / 100.0);   
        }
        if (exp1 > 600) exp1 = 600;
        if (exp1 < 0) exp1 = 0;
       
        return exp1 + exp2;
    }
   
    else if (e1 >= 4 && e1 <= 99) {
        
        updateexp2(exp2, e1);
        if (exp1 > 600) exp1 = 600;
        if (exp1 < 0) exp1 = 0;
        
        exp1 -= e1;
        if (exp1 > 600) exp1 = 600;
        if (exp1 < 0) exp1 = 0;
        return exp1 + exp2;
    }
    return -99;
    
}
void check_condition(int& EXP1, int& HP1, int& M1) {
    if (EXP1 < 0) { EXP1 = 0; }
    else if (EXP1 > 600) { EXP1 = 600; };
    if (HP1 < 0) { HP1 = 0; }
    else if (HP1 > 666) { HP1 = 666; };
    if (M1 < 0) { M1 = 0; }
    else if (HP1 > 3000) { M1 = 3000; };
};
float path_01(int HP1, int EXP1) {
    int S1 = round(sqrt(static_cast<float>(EXP1)));
    float P1;
    if (EXP1 >= (S1 * S1)) { P1 = 1.0; }
    else { P1 = ((static_cast<float>(EXP1) / (S1 * S1)) + 80) / 123; }

    return P1;
}
float path_02(int& HP1, int& EXP1, int& M1, int E2) {
    float milestone_money = M1 * 0.5;
    float M_cost = 0.0;
    if (E2 < 0 || E2>99) { return 0; }
    if (E2 % 2 == 1) {

        while (M_cost <= milestone_money) {
            if (HP1 < 200) {
                HP1 = ceil(static_cast<float>(HP1) * 0.3 + HP1);
                M_cost += 150;
                check_condition(EXP1, HP1, M1);
            }
            else {
                HP1 = ceil(static_cast<float>(HP1) * 0.1 + HP1);
                M_cost += 70;

                check_condition(EXP1, HP1, M1);
            }
            if (M_cost > milestone_money) { break; }
            if (EXP1 < 400) {
                M_cost += 200;
                EXP1 = ceil(static_cast<float>(EXP1) * 1.13);
                check_condition(EXP1, HP1, M1);
            }
            else {
                M_cost += 120;
                EXP1 = ceil(static_cast<float>(EXP1) * 1.13);
                check_condition(EXP1, HP1, M1);

            }
            if (M_cost > milestone_money) { break; }
            if (EXP1 < 300) {
                M_cost += 100;
                EXP1 = ceil(EXP1 - static_cast<float>(EXP1) * 0.1);
                check_condition(EXP1, HP1, M1);
            }
            else {
                M_cost += 120;
                EXP1 = ceil(EXP1 - static_cast<float>(EXP1) * 0.1);
                check_condition(EXP1, HP1, M1);
            }

        }


        M1 -= M_cost;

        HP1 = ceil(static_cast<float>(HP1) * 0.83);

        EXP1 = ceil(static_cast<float>(EXP1) * 1.17);
        check_condition(EXP1, HP1, M1);
    }
    else if (E2 % 2 == 0) {
        while (M_cost < M1) {

            if (HP1 < 200) {
                HP1 = ceil(static_cast<float>(HP1) * 0.3 + HP1);
                M_cost += 150;
                check_condition(EXP1, HP1, M1);
            }
            else {
                HP1 = ceil(static_cast<float>(HP1) * 0.1 + HP1);
                M_cost += 70;
                check_condition(EXP1, HP1, M1);
            }
            if (M_cost >= M1)
                break;
            if (EXP1 < 400) {
                M_cost += 200;
                EXP1 = ceil(static_cast<float>(EXP1) * 1.13);

                check_condition(EXP1, HP1, M1);
            }
            else {
                M_cost += 120;
                EXP1 = ceil(static_cast<float>(EXP1) * 1.13);
                check_condition(EXP1, HP1, M1);
            }
            if (M_cost >= M1)
                break;
            if (EXP1 < 300) {
                M_cost += 100;
                EXP1 = ceil(EXP1 - static_cast<float>(EXP1) * 0.1);
            }
            else {
                M_cost += 120;
                EXP1 = ceil(EXP1 - static_cast<float>(EXP1) * 0.1);
                check_condition(EXP1, HP1, M1);
            }
            break;

        }
        M1 -= M_cost;
        HP1 = ceil(static_cast<float>(HP1) * 0.83);
        EXP1 = ceil(static_cast<float>(EXP1) * 1.17);
        check_condition(EXP1, HP1, M1);
    }

    int S2 = round(sqrt(static_cast<float>(EXP1)));
    float P2;
    if (EXP1 >= (S2 * S2)) { P2 = 1.0; }
    else { P2 = ((static_cast<float>(EXP1 / (S2 * S2))) + 80) / 123; }

    return P2;
}
int path_03(int EXP1, int HP1, int E2) {
    int P3[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i = 0;
    if (E2 < 10) { i = E2; }
    else if (E2 >= 10) {
        i = (E2 / 10 + E2 % 10) % 10;

    }

    return P3[i];
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    float P = 0;
    float P1 = path_01(HP1, EXP1);
    float P2 = path_02(HP1, EXP1, M1, E2);
    float P3 = path_03(EXP1, HP1, E2);
    if (E2 < 0 || E2>99) { return -99; }
    if ((P1 == 1) && (P2 == 1) && (P3 == 100)) {

        EXP1 = ceil(EXP1 - static_cast<float>(EXP1) * 0.25);
    }
    else {
        P = (P1 + P2 + (P3 / 100)) / 3;

        if (P < 0.5) {
            
            HP1 = ceil(HP1 - static_cast<float>(HP1) * 0.15);
            EXP1 = ceil(static_cast<float>(EXP1 * 0.15) + EXP1);
            
            check_condition(EXP1, HP1, M1);
        }
        else {
            
            HP1 = ceil(HP1 - static_cast<float>(HP1) * 0.1);
            EXP1 = ceil(static_cast<float>(EXP1 * 0.2) + EXP1);
            
            check_condition(EXP1, HP1, M1);
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
void check_condition3(int& EXP1, int& HP1, int& EXP2, int& HP2) {
    if (EXP1 < 0) { EXP1 = 0; }
    else if (EXP1 > 600) { EXP1 = 600; };
    if (HP1 < 0) { HP1 = 0; }
    else if (HP1 > 666) { HP1 = 666; };
    if (EXP2 < 0) { EXP2 = 0; }
    else if (EXP2 > 600) { EXP2 = 600; };
    if (HP2 < 0) { HP2 = 0; }
    else if (HP2 > 666) { HP2 = 666; };
}
void tim_diem_giao(int ma_tran_taxi[10][10], int E3, int& i, int& j) {
    int so_gia_tri_duong = 0;
    int so_gia_tri_am = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (ma_tran_taxi[i][j] > E3 * 2) {
                so_gia_tri_duong++;
            }
            else if (ma_tran_taxi[i][j] < -E3) {
                so_gia_tri_am++;
            }
        }
    }
    if (so_gia_tri_duong >= 10) {
        i = so_gia_tri_duong % 10 + so_gia_tri_duong / 10;
        if (i >= 10) { i = i / 10 + i % 10; }

    }
    if (so_gia_tri_am >= 10) {
        j = so_gia_tri_am % 10 + so_gia_tri_am / 10;
        if (j >= 10) { j = j / 10 + j % 10; }

    }
}

int tim_max_duong_cheo_trai(int ma_tran_taxi[10][10], int i, int j) {
    int maxScore = ma_tran_taxi[i][j];
    while (++i < 10 && ++j < 10) {
        maxScore = max(maxScore, ma_tran_taxi[i][j]);
    }
    return maxScore;
}
int tim_max_duong_cheo_phai(int ma_tran_taxi[10][10], int i, int j) {
    int maxScore = ma_tran_taxi[i][j];
    while (++i < 10 && --j < 10) {
        maxScore = max(maxScore, ma_tran_taxi[i][j]);
    }
    return maxScore;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int i, j;
    if (E3 < 0) { return -99; }
    else if (E3 > 99) { return -99; }
    int ma_tran_taxi[10][10] = { 0 };
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ma_tran_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    tim_diem_giao(ma_tran_taxi, E3, i, j);
    int a = tim_max_duong_cheo_trai(ma_tran_taxi, i, j);
    int b = tim_max_duong_cheo_phai(ma_tran_taxi, i, j);
    int diem_SherlockandWatson;
    if (a > b) {
        diem_SherlockandWatson = a;
    }
    else {
        diem_SherlockandWatson = b;
    }

    int result;
    if (abs(ma_tran_taxi[i][j]) > abs(diem_SherlockandWatson)) {
        EXP1 = ceil(EXP1 - static_cast<float>(EXP1) * 0.12);
        HP1 = ceil(HP1 - static_cast<float>(HP1) * 0.1);
        EXP2 = ceil(EXP2 - static_cast<float>(EXP2) * 0.12);
        HP2 = ceil(HP2 - static_cast<float>(HP2) * 0.1);
        check_condition3(EXP1, HP1, EXP2, HP2);
        return result = ma_tran_taxi[i][j];
    }
    else {
        EXP1 = ceil(static_cast<float>(EXP1) * 0.12 + EXP1);
        HP1 = ceil(static_cast<float>(HP1) * 0.1 + HP1);
        EXP2 = ceil(static_cast<float>(EXP2) * 0.12 + EXP2);
        HP2 = ceil(static_cast<float>(HP2) * 0.1 + HP2);
        check_condition3(EXP1, HP1, EXP2, HP2);
        return result = diem_SherlockandWatson;
    }

}


// Task 4

int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    char se[101];
    int i;

    for (i = 0; i < 100 && email[i] != '@'; ++i) {
        se[i] = email[i];
    }
    se[i] = '\0';
    int len = strlen(s);
    if (len < 8) {
        return -1;
    }
    else if (len > 20) {
        return -2;
    }
    if (strstr(s, se) != NULL) {
        return -(300 + (int)(strstr(s, se) - s));
    }
    for (i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);

        }
    }
    int hasspecialChar = 0;
    int hasinvalidChar = 0;
    int position = 0;


    for (i = 0; i < len; ++i) {
        char currentChar = s[i];

        if (!isalnum(currentChar)) {
            if (currentChar == '#') {
                hasspecialChar++;
            }
            else if (currentChar == '@') {
                hasspecialChar++;
            }
            else if (currentChar == '%') {
                hasspecialChar++;
            }
            else if (currentChar == '$') {
                hasspecialChar++;
            }
            else if (currentChar == '!') {
                hasspecialChar++;
            }
            else {
                hasinvalidChar++;
                position = i;
            }

        }

    }

    if (hasspecialChar == 0 && hasinvalidChar >= 0) {
        return -5;
    }
    else if (hasspecialChar > 0 && hasinvalidChar == 1) {
        return position;
    }
    else if (hasspecialChar > 0&&hasinvalidChar > 1) {
        for (int j = 0; j < len; ++j) {
            char currentChar = s[j];
            if (currentChar != '#' && currentChar != '@' && currentChar != '!' && currentChar != '$' && currentChar != '#' && currentChar != '%' && !isalnum(currentChar))
            {
                return j;
                break;
            }
        }

    }
     return -10; 
}

    

// Task 5
struct con_tro_password {
    const char* password;
    int count;
};

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    con_tro_password password_nhieu_nhat;
    password_nhieu_nhat.password = nullptr;
    password_nhieu_nhat.count = 0;

    for (int i = 0; i < num_pwds; ++i) {
        const char* password_hien_tai = arr_pwds[i];
        int password_hien_tai_Length = strlen(password_hien_tai);
        int currentCount = 1;

        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(password_hien_tai, arr_pwds[j]) == 0) {
                currentCount++;
            }
        }

        if (currentCount > password_nhieu_nhat.count ||
            (currentCount == password_nhieu_nhat.count && password_hien_tai_Length > strlen(password_nhieu_nhat.password))) {
            password_nhieu_nhat.password = password_hien_tai;
            password_nhieu_nhat.count = currentCount;
        }
    }
    int result = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], password_nhieu_nhat.password) == 0) {
            result = i;
            break;
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////