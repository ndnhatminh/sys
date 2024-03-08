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

int checkExp (int & exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
    return exp;
}

int checkHp (int & hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
    return hp;
}

int checkM (int & m) {
    if (m > 3000) m = 3000;
    if (m < 0) m = 0;
    return m;
}

int checkCeil(int & a, double b) {
    a = (int)b;
    if (a - b == 0) a = a;
    else a = ceil(b);
    return a;
}

// Task 1
int miss1 (int & exp2, int e1) {
    int a = 0;
    checkCeil(a, e1/4.0);
    exp2 += a + 19;
    checkExp(exp2);
    return exp2;
}

int miss2 (int & exp2, int e1) {
    int a = 0;
    checkCeil(a, e1/9.0);
    exp2 += a + 21;
    checkExp(exp2);
    return exp2;
}

int miss3 (int & exp2, int e1) {
    int a = 0;
    checkCeil(a, e1/16.0);
    exp2 += a + 17;
    checkExp(exp2);
    return exp2;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99) return -99;
    checkExp(exp1);
    checkExp(exp2);
    //e1 từ 0-3
    if(e1 >= 0 && e1 <= 3)
    {
        switch(e1) {
            case 0: exp2 += 29; break;
            case 1: exp2 += 45; break;
            case 2: exp2 += 75; break;
            case 3: exp2 += 29 + 45 + 75; break;
        };
        checkExp(exp2);
        int x = (e1*3) + (exp1*7);
        x%2 == 0 ? checkCeil(exp1,exp1 + x/200.0) : checkCeil(exp1,exp1 - x/100.0);
        checkExp(exp1);
    }
    //e1 từ 4-99
    else if (e1 >= 4 && e1 <= 99)
    {
        if(e1 <= 19) miss1(exp2, e1);
        else if (e1 <= 49) miss2(exp2, e1);
        else if (e1 <= 65) miss3(exp2, e1);
        else if (e1 <= 79) {
            miss1(exp2, e1);
            if(exp2 > 200) miss2(exp2, e1);
        }
        else if (e1 <= 99) {
            miss1(exp2, e1);
            miss2(exp2, e1);
            if(exp2 > 400) {
                miss3(exp2, e1);
                checkCeil(exp2, exp2*115/100.0);
                checkExp(exp2);
            }
        }
        exp1 -= e1;
        checkExp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
double caclP (int EXP1, double & p) {
    double s = round(sqrt(EXP1));
    if (EXP1 >= s*s) p = 100;
    else p = ((EXP1/(s*s))+80)*100/123;
    return p;
}

int event1 (int & HP1, int & M1) {
    if (HP1 < 200)
    {
        M1 -= 150;
        checkCeil(HP1, HP1*130/100.0);
        checkHp(HP1);
    } else 
    {
        M1 -= 70;
        checkCeil(HP1, HP1*110/100.0);
        checkHp(HP1);
    }
    checkM(M1);
    return HP1 && M1;
}

int event2 (int & EXP1, int & M1) {
    if (EXP1 < 400)
    {
        M1 -= 200;
    }
    else 
    {
        M1 -= 120;
    }
    checkCeil(EXP1, EXP1*113/100.0);
    checkExp(EXP1);
    checkM(M1);
    return EXP1 && M1;
}

int event3 (int & EXP1, int & M1) {
    if (EXP1 < 300)
    {
        M1 -= 100;
    } 
    else
    {
        M1 -= 120;
    }
    checkCeil(EXP1, EXP1*90/100.0);
    checkExp(EXP1);
    checkM(M1);
    return EXP1 && M1;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    checkHp(HP1);
    checkExp(EXP1);
    checkM(M1);
    // TODO: Complete this function
    double p1 = 0, p2 = 0, p3 = 0;
    //con đường 1
    caclP(EXP1, p1);
    //con đường 2
    if (E2%2 != 0)
    {
        int f = M1;
        float m = M1/2;
        int d = 0;
        while(1)
        {
            if (d <= m && M1 > 0) {
                event1(HP1, M1);
                d += f - M1;
                f = M1;
            }
            if (d <= m && M1 > 0)
            {
                event2(EXP1, M1);
                d += f - M1;
                f = M1;
            }
            if (d <= m && M1 > 0) 
            {
                event3(EXP1, M1);
                d += f - M1;
                f = M1;
            } 
            else
            {
                checkCeil(HP1, HP1*83/100.0);
                checkCeil(EXP1, EXP1*117/100.0);
                break;
            }
        }
    } 
    else 
    {
        if (M1 > 0) event1(HP1, M1);
        if (M1 > 0) event2(EXP1, M1);
        if (M1 > 0) event3(EXP1, M1);
        checkCeil(HP1, HP1*83/100.0);
        checkCeil(EXP1, EXP1*117/100.0);
    }
    checkExp(EXP1);
    checkHp(HP1);
    caclP(EXP1, p2);
    //con đường 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2/10 == 0) {
        p3 = P[E2];
    } else {
        int first = E2/10;
        int last = E2 - first*10;
        int sum = last + first;
        first = sum/10;
        last = sum - first*10;
        p3 = P[last];
    }
    if (p1 == 100 && p2 == 100 && p3 == 100) EXP1 = checkCeil(EXP1, EXP1*75/100.0);
    else {
        if (((p1 + p2 + p3)/3) < 50) {
            checkCeil(HP1, HP1*85/100.0);
            checkCeil(EXP1, EXP1*115/100.0);
        } else {
            checkCeil(HP1, HP1*90/100.0);
            checkCeil(EXP1, EXP1*120/100.0);
        }
    }
    checkExp(EXP1);
    checkHp(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int checkOne (int & a) {
    while (a >= 10) {
        int b = a/10;
        a -= b*10;
        a += b;
    }
    return a;
}

int checkPos(int a) {
    if(a < 0) a = abs(a);
    return a;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    checkHp(HP1);
    checkExp(EXP1);
    checkHp(HP2);
    checkExp(EXP2);
    int table[10][10];
    int ci = 0, cj = 0;
    //ma trận điểm Taxi và tìm tổng số lớn hơn E3x2 và nhỏ hơn -E3
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            table[i][j] = ((E3*j) + (i*2))*(i-j);
            int a = table[i][j];
            if (a > E3*2) ci++;
            if (a < -E3) cj++;
        }
    }
    checkOne(ci);
    checkOne(cj);
    int pointTaxi = table[ci][cj];
    //điểm sher và was
    int point = 0;
    //đường chéo trái lên
    for(int i = ci, j = cj; i != 0 && j != 0; i--, j--) {
        if(point < table[i][j]) point = table[i][j];
    }
    // //đường chéo trái xuống
    for(int i = ci, j = cj; i != 10 && j != 10; i++, j++) {
        if(point < table[i][j]) point = table[i][j];
    }
    // //đường chéo phải lên
    for(int i = ci, j = cj; i != 0 && j != 10; i--, j++) {
        if(point < table[i][j]) point = table[i][j];
    }
    // //đường chéo phải xuống
    for(int i = ci, j = cj; i != 10 && j != 0; i++, j--) {
        if(point < table[i][j]) point = table[i][j];
    }
    point = checkPos(point);
    if (point >= checkPos(pointTaxi)) {
        checkCeil(HP1, HP1*110/100.0);
        checkHp(HP1);
        checkCeil(HP2, HP2*110/100.0);
        checkHp(HP2);
        checkCeil(EXP1, EXP1*112/100.0);
        checkExp(EXP1);
        checkCeil(EXP2, EXP2*112/100.0);
        checkExp(EXP2);
        return point;
    }
    else
    {
        checkCeil(HP1, HP1*90/100.0);
        checkHp(HP1);
        checkCeil(HP2, HP2*90/100.0);
        checkHp(HP2);
        checkCeil(EXP1, EXP1*88/100.0);
        checkExp(EXP1);
        checkCeil(EXP2, EXP2*88/100.0);
        checkExp(EXP2);
        return pointTaxi;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    //lấy giá trị cho chuỗi se
    string e = email;
    string se = "";
    for(int i = 0; i < e.length(); i++) {
        if(email[i] == '@') break;
        else se += email[i];
    }
    //kiểm tra mk 8-20 ký tự
    string pw = s;
    if (pw.length() < 8) return -1;
    if (pw.length() > 20) return -2;
    //kiểm tra mk có chứa chuỗi se không
    if(pw.find(se) != string::npos) return -(300 + pw.find(se));

    //kiểm tra mk có chứa chuỗi có 2 ký tự trở lên giống nhau liên tục
    for (int i = 0; i < pw.length()-2; i++) {
        if(pw[i] == pw[i+1] && pw[i] == pw[i+2]) return -(400+i);
    }

    //kiểm tra mk có ký tự đặc biệt không
    bool checkSym = false;
    for (int i = 0; i< pw.length(); i++) {
        bool specSym = pw[i] == 33 || (pw[i] >= 35 && pw[i] <= 37) || pw[i] == 64;
        if(specSym) checkSym = true;
    }
    if (!checkSym) return -5;

    //kiểm tra mk có ký tự khác ngoài chữ thường, chữ hoa, số và "! @ # $ %"
    for (int i = 0; i< pw.length(); i++) {
        bool upLowNumber =  (pw[i] >= 65 && pw[i] <= 90) || (pw[i] >= 97 && pw[i] <= 122) || (pw[i] >= 48 && pw[i] <= 57);
        bool specSym = pw[i] == 33 || (pw[i] >= 35 && pw[i] <= 37) || pw[i] == 64;
        if(!upLowNumber && !specSym) return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int count = 0, length = 0, index = 0;
    for (int i = 0; i < num_pwds; ++i) {
        int tempLength = strlen(arr_pwds[i]), tempCount = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) tempCount++;
        }
    //kiểm tra xem tại điểm đang lặp có số lần lặp và độ dài lớn hơn cái max hiện tại hoặc có số lần suất hiện cao nhất hay không
        if (tempCount > count || (count == tempCount && length < tempLength)) {
            length = tempLength;
            count = tempCount;
            index = i;
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////