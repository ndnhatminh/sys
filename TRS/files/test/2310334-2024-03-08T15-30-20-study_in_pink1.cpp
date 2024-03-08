#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
/*int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    return HP1 + EXP1 + M1;
}
*/
//Gioi han HP
void limitHP(double& HP)
{
    if (HP < 0) HP = 0;
    else if (HP > 666) HP = 666;
}
// Gioi han EXP
void  limitEXP(double& EXP)
{
    if (EXP < 0) EXP = 0;
    else { if (EXP > 600) EXP = 600; }
}
// Gioi han so tien M
void limitM(double& M)
{
    if (M < 0) M = 0;
    else if (M > 3000) M = 3000;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if ((0 > e1) || (99 < e1)) {
        return -99;
    }
    else {
        //tao bien sao chep cho cac tham so exp1 exp2
        double cexp1 = exp1 * 1.0, cexp2 = exp2 * 1.0;
        limitEXP(cexp1);
        limitEXP(cexp2);
        /*truong hop 1*/
        if ((e1 >= 0) && (e1 <= 3)) {
            if (e1 == 0) {
                cexp2 += 29;
                limitEXP(cexp2);
            }
            else {
                if (e1 == 1) {
                    cexp2 += 45;
                    limitEXP(cexp2);
                }
                else {
                    if (e1 == 2) {
                        cexp2 += 75;
                        limitEXP(cexp2);
                    }
                    else {
                        cexp2 += 149;
                        limitEXP(cexp2);
                    }
                }
            }
            int D = e1 * 3 + cexp1 * 7;
            if ((D % 2) == 0) {
                cexp1 += (D / 200.0);
                limitEXP(cexp1);
            }
            else {
                cexp1 -= (D / 100.0);
                limitEXP(cexp1);
            }
            cexp1 = ceil(cexp1);
            limitEXP(cexp1);
        }
        else { /*truong hop 2*/
            if ((e1 >= 4) && (e1 <= 19)) {
                cexp2 += (e1 / 4.0 + 19);
                cexp2 = ceil(cexp2);
                limitEXP(cexp2);
            }
            else {
                if ((e1 >= 20) && (e1 <= 49)) {
                    cexp2 += ((e1 / 9.0) + 21);
                    cexp2 = ceil(cexp2);
                    limitEXP(cexp2);
                }
                else {
                    if ((e1 >= 50) && (e1 <= 65)) {
                        cexp2 += (e1 / 16.0 + 17);
                        cexp2 = ceil(cexp2);
                        limitEXP(cexp2);
                    }
                    else {
                        if ((e1 >= 66) && (e1 <= 79)) {
                            cexp2 += (e1 / 4.0 + 19);
                            cexp2 = ceil(cexp2);
                            limitEXP(cexp2);
                            if (cexp2 > 200) {
                                cexp2 += (e1 / 9.0 + 21);
                                cexp2 = ceil(cexp2);
                            }
                            limitEXP(cexp2);
                        }
                        else {
                            cexp2 += (e1 / 4.0 + 19);
                            cexp2 = ceil(cexp2);
                            limitEXP(cexp2);
                            cexp2 += (e1 / 9.0 + 21);
                            cexp2 = ceil(cexp2);
                            limitEXP(cexp2);
                            if (cexp2 > 400) {
                                cexp2 += (e1 / 16.0 + 17);
                                cexp2 = ceil(cexp2);
                                limitEXP(cexp2);
                                cexp2 += (cexp2 * 0.15);
                                cexp2 = ceil(cexp2);
                                limitEXP(cexp2);
                            }
                            limitEXP(cexp2);
                        }
                    }
                }

            }
            cexp1 -= e1;
            cexp1 = ceil(cexp1);
            limitEXP(cexp1);
        }
        exp1 = cexp1;
        exp2 = cexp2;
    }
    return exp1 + exp2;
}
//task 2
int sqrnum(int n) {
    int b = round(sqrt(n));
    return b * b;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if ((0 > E2) || (99 < E2)) {
        return -99;
    }
    else {
        double cexp1 = EXP1, chp1 = HP1, cm1 = M1, p1 = 0;
        limitEXP(cexp1);
        limitHP(chp1);
        limitM(cm1);
        int money = cm1, bill = 0;
        //con duong 1, tinh p1
        int s1 = sqrnum(cexp1);
        if (cexp1 >= s1) {
            p1 = 1;
        }
        else {
            p1 = (cexp1 / s1 + 80) / 123.0;
        }
        //con duong 2
        if ((E2 % 2) == 1) {
            while (bill <= (0.5 * money)) {
                if (cm1 == 0) {
                    break;
                }
                //food
                if (chp1 < 200) {
                    chp1 += (chp1 * 0.3);
                    chp1 = ceil(chp1);
                    limitHP(chp1);
                    cm1 -= 150;
                    bill += 150;
                    limitM(cm1);
                }
                else {
                    chp1 += (0.1 * chp1);
                    chp1 = ceil(chp1);
                    limitHP(chp1);
                    cm1 -= 70;
                    limitM(cm1);
                    bill += 70;
                }
                if (bill > (0.5 * money)) {
                    break;
                }
                //taxi,ngua
                if (cexp1 < 400) {
                    cm1 -= 200;
                    limitM(cm1);
                    bill += 200;
                    cexp1 += (cexp1 * 0.13);
                    cexp1 = ceil(cexp1);
                    limitEXP(cexp1);
                }
                else {
                    cm1 -= 120;
                    limitM(cm1);
                    bill += 120;
                    cexp1 += (cexp1 * 0.13);
                    cexp1 = ceil(cexp1);
                    limitEXP(cexp1);
                }
                if (bill > (0.5 * money)) {
                    break;
                }
                //nguoi vo gia cu
                if (cexp1 < 300) {
                    cm1 -= 100;
                    limitM(cm1);
                    bill += 100;
                    cexp1 -= (cexp1 * 0.1);
                    cexp1 = ceil(cexp1);
                    limitEXP(cexp1);
                }
                else {
                    cm1 -= 120;
                    limitM(cm1);
                    bill += 120;
                    cexp1 -= (cexp1 * 0.1);
                    cexp1 = ceil(cexp1);
                    limitEXP(cexp1);
                }
            }
        }
        else {
            //food
            if ((chp1 < 200) && (cm1 > 0)) {
                chp1 += (chp1 * 0.3);
                chp1 = ceil(chp1);
                limitHP(chp1);
                cm1 -= 150;
                limitM(cm1);
            }
            else {
                if ((chp1 >= 200) && (cm1 > 0)) {
                    chp1 += (0.1 * chp1);
                    chp1 = ceil(chp1);
                    limitHP(chp1);
                    cm1 -= 70;
                    limitM(cm1);
                }
            }
            //taxi,ngua
            if ((cexp1 < 400) && (cm1 > 0)) {
                cm1 -= 200;
                limitM(cm1);
                cexp1 += (cexp1 * 0.13);
                cexp1 = ceil(cexp1);
                limitEXP(cexp1);
            }
            else {
                if ((cexp1 >= 400) && (cm1 > 0)) {
                    cm1 -= 120;
                    limitM(cm1);
                    cexp1 += (cexp1 * 0.13);
                    cexp1 = ceil(cexp1);
                    limitEXP(cexp1);
                }
            }
            //nguoi vo gia cu
            if ((cexp1 < 300) && (cm1 > 0)) {
                cm1 -= 100;
                limitM(cm1);
                cexp1 -= (cexp1 * 0.1);
                cexp1 = ceil(cexp1);
                limitEXP(cexp1);
            }
            else {
                if ((cexp1 >= 300) && (cm1 > 0)) {
                    cm1 -= 120;
                    limitM(cm1);
                    cexp1 -= (cexp1 * 0.1);
                    cexp1 = ceil(cexp1);
                    limitEXP(cexp1);
                }
            }
        }
        chp1 -= chp1 * (0.17);
        chp1 = ceil(chp1);
        limitHP(chp1);
        cexp1 += (0.17 * cexp1);
        cexp1 = ceil(cexp1);
        limitEXP(cexp1);
        //tinh p2
        double p2 = 0;
        int s2 = sqrnum(cexp1);
        if (cexp1 >= s2) {
            p2 = 1;
        }
        else {
            p2 = (cexp1 / s2 + 80) / 123.0;
        }
        //con duong 3
        //khoi tao mang gia tri xac suat P
        int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
        //tao chi so gia tri xac suat i
        int i = 0;
        if (E2 < 10) {
            i = E2;
        }
        else {
            int donvi = (E2 % 10);
            int chuc = (E2 / 10);
            i = (donvi + chuc) % 10;
        }
        if (p1 == p2 == (P[i] / 100.0) == 1) {
            cexp1 -= (0.25 * cexp1);
            cexp1 = ceil(cexp1);
            limitEXP(cexp1);
        }
        else {
            double lastP = (p1 + p2 + P[i] / 100.0) / 3;
            if (lastP < 0.5) {
                chp1 -= (0.15 * chp1);
                chp1 = ceil(chp1);
                limitHP(chp1);
                cexp1 += (0.15 * cexp1);
                cexp1 = ceil(cexp1);
                limitEXP(cexp1);
            }
            else {
                chp1 -= (0.1 * chp1);
                chp1 = ceil(chp1);
                limitHP(chp1);
                cexp1 += (0.2 * cexp1);
                cexp1 = ceil(cexp1);
                limitEXP(cexp1);
            }
        }
        HP1 = chp1;
        EXP1 = cexp1;
        M1 = cm1;
    }
    return HP1 + EXP1 + M1;
}
//task 3
int cong2cs(int n) {
    while (n >= 10) {
        int donvi = n % 10;
        int chuc = n / 10;
        n = donvi + chuc;
    }
    return n;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if ((E3 < 0) || (E3 > 99)) {
        return -99;
    }
    else {
        double chp1 = HP1, cexp1 = EXP1, chp2 = HP2, cexp2 = EXP2;
        limitHP(chp1);
        limitHP(chp2);
        limitEXP(cexp1);
        limitEXP(cexp2);
        int matrix[10][10] = { 0 };
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        //tim numi, numj ( toa do gap nhau)
        int numi = 0, numj = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (matrix[i][j] > (2 * E3)) {
                    numi += 1;
                }
                if (matrix[i][j] < (0 - E3)) {
                    numj += 1;
                }
            }
        }
        numi = cong2cs(numi);
        numj = cong2cs(numj);
        //duong cheo trai
        int ii = numi;
        int jj = numj;
        while ((ii != 0) && (jj != 0)) {
            ii -= 1;
            jj -= 1;
        }
        int stt[20] = { };
        int i = 0;
        while ((ii != 10) && (jj != 10)) {
            stt[i] = matrix[ii][jj];
            i += 1;
            ii += 1;
            jj += 1;
        }
        //duong cheo phai
        ii = numi;
        jj = numj;
        while ((ii != 0) && (jj != 9)) {
            ii -= 1;
            jj += 1;
        }
        while ((ii != 10) && (jj != -1)) {
            stt[i] = matrix[ii][jj];
            i += 1;
            ii += 1;
            jj -= 1;
        }
        //tim max tren duong cheo trai phai
        int max = stt[0];
        for (int y = 0; y < 20; y++) {
            if (stt[y] >= max) {
                max = stt[y];
            }
        }
        int taxipts = 0;
        taxipts = abs(matrix[numi][numj]);
        if (taxipts > max) {
            cexp1 -= (0.12 * cexp1);
            cexp1 = ceil(cexp1);
            limitEXP(cexp1);
            cexp2 -= (0.12 * cexp2);
            cexp2 = ceil(cexp2);
            limitEXP(cexp2);
            chp1 -= (0.1 * chp1);
            chp1 = ceil(chp1);
            limitHP(chp1);
            chp2 -= (0.1 * chp2);
            chp2 = ceil(chp2);
            limitHP(chp2);
        }
        else {
            cexp1 += (0.12 * cexp1);
            cexp1 = ceil(cexp1);
            limitEXP(cexp1);
            cexp2 += (0.12 * cexp2);
            cexp2 = ceil(cexp2);
            limitEXP(cexp2);
            chp1 += (0.1 * chp1);
            chp1 = ceil(chp1);
            limitHP(chp1);
            chp2 += (0.1 * chp2);
            chp2 = ceil(chp2);
            limitHP(chp2);
        }
        HP1 = chp1;
        EXP1 = cexp1;
        HP2 = chp2;
        EXP2 = cexp2;
        if (taxipts > max) { return matrix[numi][numj]; }
        else return max;
    }
}

// Task 4
/*int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function

    return -99;
}*/
int checkPassword(const char* s, const char* email) {
    // kiem tra do dai
    int lengths = strlen(s);
    int lengthemail = strlen(email);
    if (lengths < 8) {
        return -1; // mat khau ngan hon do dai toi thieu
    }
    if (lengths > 20) {
        return -2; // mat khau dai hon do dai toi da
    }
    //lay chuoi se
    //tao bien string clone cho email va s de khong bi loi kieu du lieu
    string cemail(email);
    string cs(s);
    string se = cemail.substr(0, cemail.find('@'));
    int sei = 0;
    bool checkse = (cs.find(se) != string::npos);
    if (checkse) {
        sei = cs.find(se);
        return (0 - (300 + sei));
    }
    //kiem tra co nhieu hon 2 ky tu giong nhau
    for (int i = 0; i < lengths - 2; i++) {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2])) {
            return (0 - (400 + i));
        }
    }
    //kiem tra co chua it nhat 1 ky tu dac biet khong
    bool checkspecial = false;
    for (int i = 0; i < lengths; i++) {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!')) {
            checkspecial = true;//neu true thi co it nhat 1 ky tu dac biet
        }
    }
    if (checkspecial == false) {
        return -5;
    }
    //kiem tra cac dieu kien khac
    bool othercondition = false;
    int kytudautien = 0;
    for (int i = 0; i < lengths; i++) {
        if (!(((s[i] >= '0') && (s[i] <= '9')) || ((s[i] >= '@') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z')) || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!'))) {
            othercondition = true;//neu true thi tuc la co 1 ky tu khac dieu kien yeu cau ham
            kytudautien = i;
            break;
        }
    }
    if (othercondition == true) {
        return kytudautien;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    if (num_pwds <= 0 || arr_pwds == nullptr) {
        return -1; // tra ve gia tri ko hop le neu so mat khau <=0
    }

    int count[99] = { 0 }; 

    for (int i = 0; i < num_pwds; i++) {
        const char* currentpwd = arr_pwds[i];
        int tempcount = 0;

        for (int j = 0; j < num_pwds; j++) {
            if (j != i && strcmp(currentpwd, arr_pwds[j]) == 0) {
                tempcount++;
            }
        }
        count[i] = tempcount;
    }

    int maxcount = count[0];
    int maxindex = 0;

    for (int k = 1; k < num_pwds; k++) {
        if (count[k] > maxcount) {
            maxcount = count[k];
            maxindex = k;
        }
        else if (count[k] == maxcount) {
            if (strlen(arr_pwds[k]) > strlen(arr_pwds[maxindex])) {
                maxindex = k;
            }
        }
    }

    return maxindex;
}




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////