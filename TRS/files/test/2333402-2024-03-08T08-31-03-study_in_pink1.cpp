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

void e19(float & t2, int & e1)
    {
        t2 = t2 + (float(e1)/4 + 19);
    }

    void e49(float & t2, int & e1)
    {
       t2 = t2 + (float(e1)/9 + 21);
    }

    void e65(float & t2, int & e1)
    {
        t2 = t2 + (float(e1)/16 + 17);
    }

int checkexp1(float & exp1){
    if(exp1 < 0){
        return exp1 = 0;
    }
    if(exp1 >= 600){
        return exp1 = 600;
    }
    else{
        return exp1;
    }
}

int checkexp2(float & exp2){
    if(exp2 < 0){
        return exp2 = 0;
    }
    if(exp2 >= 600){
        return exp2 = 600;
    }
    else{
        return exp2;
    }
}

int checkhp1(float & hp1){
    if(hp1 < 0){
        return hp1 = 0;
    }
    if(hp1 >= 666){
        return hp1 = 666;
    }
    else{
        return hp1;
    }
}

int checkhp2(float & hp2){
    if(hp2 < 0){
        return hp2 = 0;
    }
    if(hp2 >= 666){
        return hp2 = 666;
    }
    else{
        return hp2;
    }
}

int checkm1(float & m1){
    if(m1 < 0){
        return m1 = 0;
    }
    if(m1 >= 3000){
        return m1 = 3000;
    }
    else{
        return m1;
    }
}

int checkm2(float & m2){
    if(m2 < 0){
        return m2 = 0;
    }
    if(m2 >= 3000){
        return m2 = 3000;
    }
    else{
        return m2;
    }
}

int checkexp1int(int & exp1){
    if(exp1 < 0){
        return exp1 = 0;
    }
    if(exp1 >= 600){
        return exp1 = 600;
    }
    else{
        return exp1;
    }
}

int checkexp2int(int & exp2){
    if(exp2 < 0){
        return exp2 = 0;
    }
    if(exp2 >= 600){
        return exp2 = 600;
    }
    else{
        return exp2;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1){
    checkexp1int(exp1);
    checkexp2int(exp2);

    float t1  = exp1;
    float t2  = exp2;


    if(e1 >= 0 && e1 <=3){  //TH1
        switch(e1){
            case 0:
                t2 += 29;
                break;
            case 1:
                t2 += 45;
                break;
            case 2:
                t2 += 75;
                break;
            case 3:
                t2 += 29 + 45 + 75;
                break;
        };
        int d = e1 * 3 + t1 * 7;
        if (d % 2 == 0){
            t1 = ceilf(t1 + (float(d) / 200));
        }
        else{
            t1 = ceilf(t1 - (float(d) / 100));
        }
    }

    else if(e1>=4 && e1 <=99){  //TH2
        if(e1 <= 19) e19(t2, e1);
        else if(e1 <= 49) e49(t2, e1);
        else if(e1 <= 65) e65(t2, e1);
        else if(e1 <= 79){
            e19(t2, e1);
            if(t2 > 200){
                e49(t2, e1);
            }
        }

        else if(e1 <= 99){
            e19(t2, e1);
            e49(t2, e1);
            if(t2 > 400){
                e65(t2, e1);
                t2 = t2 + (t2*0.15);
            }
        }
        t1 -= e1;
    }

    checkexp1(t1);
    checkexp2(t2);

    exp1 = ceilf(t1);
    exp2 = ceilf(t2);
    return exp1 + exp2;
}

// Task 2
float traces1(float & exp1){
    int S = round(sqrt(exp1)) * round(sqrt(exp1));
    float P1;
    if(exp1 >= S){
        P1 = 1;
    }
    else{
        P1 = ((exp1/S) + 80)/123;
    }
    return P1;
}

float traces2(float & hp1, float & exp1, float & m1, int e2){
    float m50 = m1 * 0.5;
    float P2;
    checkhp1(hp1);
    checkexp1(exp1);
    checkm1(m1);
    if(e2 % 2 != 0){
        while(m1 > m50){
            if(hp1 < 200){
                hp1 = ceilf(hp1 * 1.3);
                m1 = m1 - 150;
            }
            else{
                hp1 = ceilf(hp1 * 1.1);
                m1 = m1 - 70;
            }
            if(m1 < m50){
                break;
            }

            if(exp1 < 400){
                m1 = m1 - 200;
                exp1 = ceilf(exp1 * 1.13);
            }
            else{
                m1 = m1 - 120;
                exp1 = ceilf(exp1 * 1.13);
            }
            if(m1 < m50){
                break;
            }

            if(exp1 < 300){
                m1 = m1 -100;
                exp1 = ceilf(exp1 * 0.9);
            }
            else{
                m1 = m1 -120;
                exp1 = ceilf(exp1 * 0.9);
            }
            if(m1 < m50){
                break;
            }
        }
        hp1 = ceilf(hp1 * 0.83);
        exp1 = ceilf(exp1 * 1.17);
    }
    else{
        while(m1>0){
            if(hp1 < 200){
                hp1 = ceilf(hp1 * 1.3);
                m1 = m1 - 150;
            }
            else{
                hp1 = ceilf(hp1 * 1.1);
                m1 = m1 - 70;
            }
            if(m1 <= 0){
                break;
            }
            if(exp1 < 400){
                m1 = m1 - 200;
                exp1 =  ceilf(exp1 * 1.13);
            }
            else{
                m1 = m1 - 120;
                exp1 = ceilf(exp1 * 1.13);
            }
            if(m1 <= 0){
                break;
            }
            if(exp1 < 300){
                m1 = m1 -100;
                exp1 = ceilf(exp1 * 0.9);
            }
            else{
                m1 = m1 - 120;
                exp1 = ceilf(exp1 * 0.9);
            }
            if(m1 <= 0){
                break;
            }
            break;
        }
        hp1 = ceilf(hp1 * 0.83);
        exp1 = ceilf(exp1 * 1.17);
    }
    float S = round(sqrt(exp1)) * round(sqrt(exp1));
    if(exp1 >= S){
        P2 = 1;
    }
    else{
        P2 = ((exp1/S) + 80)/123;
    }
    return P2;
}

float traces3(int e2){
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    int i;
        if (to_string(e2).length() == 1){
            i = e2;
        }
        else{
            int sum = 0;
            float a = e2/10;
            float b = e2 % 10;
            sum = a + b;
            i = sum % 10;
        }
    P3 = (P[i]);
    P3 = P3/100;
    return P3;

}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    float h1 = HP1;
    float t1 = EXP1;
    float m1 = M1;

    float P = ((traces1(t1) + traces2(h1, t1, m1, E2) + traces3(E2))/3)*100;
    if(P == 100){
        t1 = ceilf(t1 * 0.9);
    }
    else if(P >= 50){
        h1 = ceilf(h1 * 0.9);
        t1 = ceilf(t1 * 1.2);

    }
    else{
        h1 = ceilf(h1 * 0.85);
        t1 = ceilf(t1 * 1.15);
    }
    checkexp1(t1);
    checkhp1(h1);
    checkm1(m1);

    EXP1 = t1;
    HP1 = h1;
    M1 = m1;

    return HP1 + EXP1 + M1;
}


//Task3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
    
}

// Task 4
int checkPassword(const char * s, const char * email){
    string se = "";
    size_t n = strlen(s), m = strlen(email);

    for(int i=0; i < n; i++){
        se += s[i];
    }
    string emails = "";
    for(int i=0; i < m; i++){
        emails += email[i];
    }
    string sem = emails.substr(0, emails.find('@'));

    // kt độ dài mật khẩu
    if (se.length() < 8) return -1;
    if (se.length() > 20) return -2;

    // kt chuỗi se
    int posse = se.find(sem);
    if (posse != string::npos) return -(300 + posse);

    // kt ký tự đặc biệt
    bool hasspecialchar = false;
    for (int i = 0; i < se.length(); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
        hasspecialchar = true;
        break;
        }
    }
    if (!hasspecialchar) return -5;

    // kt 2 ký tự liên tiếp
    for (int i = 0; i < se.length() - 2; i++){
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]){
        return -(400 + i);
        }
    }

    // kt ký tự hợp lệ
    for (int i = 0; i < se.length(); i++){
        if (!isalnum(s[i]) && !ispunct(s[i])){
            return -6;
        }
    }
    // valid pass
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
    int count_pwds[30] = {0};

    string se[num_pwds];
    for(int i=0; i < num_pwds; i++){
        se[i] = arr_pwds[i];
    }

    for (int i = 0; i < num_pwds; i++){
        count_pwds[i] = 1;
        for (int j = i + 1; j < num_pwds; j++){
            if (arr_pwds[i] == arr_pwds[j]){
                count_pwds[i]++;
                count_pwds[j] = -1; // đánh dấu nnk trùng
            }
        }
    }

    // tìm max_count
    int max_count = 0;
    int pos_max_pwd = -1;
    for (int i = 0; i < num_pwds; i++){
        if (count_pwds[i] > max_count){
            max_count = count_pwds[i];
            pos_max_pwd = i;
            }
    }

    // tìm mk đúng theo độ dài
    int max_len = se[pos_max_pwd].length();
    for (int i = 0; i < num_pwds; i++){
        if (count_pwds[i] == max_count && se[i].length() > max_len){
        max_len = se[i].length();
        pos_max_pwd = i;
        }
    }

    return pos_max_pwd;
    return -1;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

//g++ -o main main.cpp study_in_pink1.cpp -I . -std=c++11
// ./main sa_tc_01_input
