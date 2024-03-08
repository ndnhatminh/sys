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

int returnHP(int &HP) {
    if (HP<0) {
        HP = 0;
    }
    else if (HP>666) {
        HP = 666;
    }
    else {}
    return HP;
}
int returnEXP(int &EXP) {
    if (EXP<0) {
        EXP = 0;
    }
    else if (EXP>600) {
        EXP = 600;
    }
    else {}
    return EXP;
}
int returnM(int &M) {
    if (M<0) {
        M = 0;
    }
    else if (M>3000) {
        M = 3000;
    }
    else {}
    return M;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    returnEXP(exp1);
    returnEXP(exp2);
    if ((e1<0)&&(e1>100)) {return -99;}
    if ((e1 >= 0) && (e1 <= 3)){
        switch (e1){
            case 0:
                exp2+=29;
                returnEXP(exp2);
                break;
            case 1:
                exp2+=45;
                returnEXP(exp2);
                break;
            case 2:
                exp2+=75;
                returnEXP(exp2);
                break;
            default:
                exp2+=29+45+75;
                returnEXP(exp2);
                break;
        }
        int D = e1*3 + exp1*7;
        if (D%2 == 0){
            exp1=exp1+D/200.0 +0.999;
            returnEXP(exp1);
        }
        else {
            exp1=exp1-D/100.0 +0.999;
            returnEXP(exp1);
        }
    }
    else {
        if ((e1 >= 4) && (e1 <= 19)) {
            exp2=ceil(exp2 + (e1/4.0) + 19); //thong tin 1
            returnEXP(exp2);
        }
        else if ((e1 >= 20) && (e1 <= 49)) {
            exp2=ceil(exp2 + (e1/9.0) + 21); //thong tin 2
            returnEXP(exp2);
        }
        else if ((e1 >= 50) && (e1 <= 65)) {
            exp2=ceil(exp2 + (e1/16.0) + 17); // thong tin 3
            returnEXP(exp2);
        }
        else if ((e1 >= 66) && (e1 <= 79)) {
            exp2=ceil(exp2 + (e1/4.0) + 19);
            returnEXP(exp2);
            if (exp2 > 200) {
                exp2=ceil(exp2 + (e1/9.0) + 21);//thong tin 1+2
                returnEXP(exp2);
            }
        }
        else if ((e1 >= 80) && (e1 <= 99)) {
            exp2=ceil(exp2 + (e1/4.0) + 19);
            exp2=ceil(exp2 + (e1/9.0) + 21);
            returnEXP(exp2);
            if (exp2 > 400) {
                exp2=ceil(exp2 + (e1/16.0) + 17);//thong tin 1+2+3
                exp2=ceil(exp2*1.15);//exp extra khi co ca 3 tt
                returnEXP(exp2);
            }
        }
        exp1-=e1; //sai lam cua Sherlock
        returnEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    returnHP(HP1);
    returnEXP(EXP1);
    returnM(M1);
    if ((E2<0)&&(E2>100)) {return -99;}
    //Bat dau con duong 01
    int sqNUMmax, sqNUMmin, S;
    float P1;
    sqNUMmin = sqrt(EXP1);
    sqNUMmax = sqNUMmin + 1;
    if (EXP1 - sqNUMmin*sqNUMmin < sqNUMmax*sqNUMmax - EXP1) {
        P1=1.0;
    } // EXP1 >= S
    else {
        S = sqNUMmax*sqNUMmax;
        P1 = ((EXP1*1.0/S) + 80.0)/123.0;
    } // EXP1 < S
    //Ket thuc con duong 01
    //Bat dau con duong 02
    float m_half = M1*0.5;
    int m_pay = 0;
    if (M1 == 0) {
        goto calculateP2;
    }
    if (E2%2 == 1) {
        while (M1 > 0){
            //Hanh dong 1
            if (HP1 < 200){
                HP1= HP1 * 1.3 + 0.999;
                M1= M1 - 150;
                returnHP(HP1);
                returnM(M1);
                m_pay += 150;
                if (m_half < m_pay) {goto walk;}
            }
            else {
                HP1 = HP1 * 1.1 + 0.999;
                M1 = M1 - 70;
                returnHP(HP1);
                returnM(M1);
                m_pay += 70;
                if (m_half < m_pay) {goto walk;}
            }
            //Hanh dong 2
            if (EXP1 < 400) {
                M1 = M1 - 200;
                m_pay += 200;
                EXP1 = EXP1*1.13 + 0.999;
                returnM(M1);
                returnEXP(EXP1);
                if (m_half < m_pay) {goto walk;}
            }
            else {
                M1 = M1 - 120;
                m_pay += 120;
                EXP1 = EXP1*1.13 + 0.999;
                returnM(M1);
                returnEXP(EXP1);
                if (m_half < m_pay) {goto walk;}
            }
            //Hanh dong 3
            if (EXP1 < 300) {
                M1 = M1 - 100;
                m_pay += 100;
                EXP1 = EXP1*0.9 +0.999;
                returnM(M1);
                returnEXP(EXP1);
                if (m_half < m_pay) {goto walk;}
            }
            else {
                M1 = M1 - 120;
                m_pay += 120;
                EXP1 = EXP1*0.9 +0.999;
                returnM(M1);
                returnEXP(EXP1);
                if (m_half < m_pay) {goto walk;}
            }
        }
        
    }//KET THUC E2 LE
    else {
        //Hanh dong 1
        if (HP1 < 200){
            HP1= HP1 * 1.3 + 0.999;
            M1= M1 - 150;
            returnHP(HP1);
            returnM(M1);
            if (M1 <= 0) {goto walk;}
        }
        else {
            HP1 = HP1 * 1.1 + 0.999;
            M1 = M1 - 70;
            returnHP(HP1);
            returnM(M1);
            if (M1 <= 0) {goto walk;}
        }
        //Hanh dong 2
        if (EXP1 < 400) {
            M1 = M1 - 200;
            EXP1 = EXP1*1.13 + 0.999;
            returnEXP(EXP1);
            returnM(M1);
            if (M1 <= 0) {goto walk;}
        }
        else {
            M1 = M1 - 120;
            EXP1 = EXP1*1.13 + 0.999;
            returnEXP(EXP1);
            returnM(M1);
            if (M1 <= 0) {goto walk;}
        }
        //Hanh dong 3
        if (EXP1 < 300) {
            M1 = M1 - 100;
            EXP1 = EXP1*0.9 +0.999;
            returnEXP(EXP1);
            returnM(M1);
            if (M1 <= 0) {goto walk;}
        }
        else {
            M1 = M1 - 120;
            EXP1 = EXP1*0.9 +0.999;
            returnEXP(EXP1);
            returnM(M1);
            if (M1 <= 0) {goto walk;}
        }
    }//KET THUC E2 CHAN
walk:
    HP1 = HP1*0.83 + 0.999;
    EXP1 = EXP1*1.17 + 0.999;
    returnEXP(EXP1);
    returnHP(HP1);
calculateP2:
    float P2;
    sqNUMmin = sqrt(EXP1);
    sqNUMmax = sqNUMmin + 1;
    if (EXP1 - sqNUMmin*sqNUMmin < sqNUMmax*sqNUMmax - EXP1) {
        P2=1.0;
    } // EXP1 >= S
    else {
        S = sqNUMmax*sqNUMmax;
        P2 = ((EXP1*1.0/S) + 80.0)/123.0;
    }//Ket thuc con duong 2
    //Bat dau con duong 3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    int i;
    float P3;
    if (E2 < 10) {
        P3 = P[E2];
    }
    else {
        i = E2/10 + E2%10;
        if (i >= 10) {
            i = E2%10;
        }
        P3 = P[i];
    }//Ket thuc con duong 3
    if ((P1==P2)&&(P2==P3)&&(P1=100.0)) {
        EXP1 = EXP1 * 0.75 + 0.999;
        returnEXP(EXP1);
    }
    else {
        float P_average=(P1+P2+P3)/3.0;
        if (P_average < 0.5) {
            HP1 = HP1*0.85 + 0.999;
            EXP1 = EXP1*1.15 + 0.999;
            returnEXP(EXP1);
            returnHP(HP1);
        }
        else {
            HP1 = HP1*0.9 + 0.999;
            EXP1 = EXP1*1.2 + 0.999;
            returnEXP(EXP1);
            returnHP(HP1);
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    returnHP(HP1);
    returnHP(HP2);
    returnEXP(EXP1);
    returnEXP(EXP2);
    if ((E3<0)&&(E3>100)) {return -99;}
    int arrayTaxi[10][10];
    int c_i=0, c_j=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            arrayTaxi[i][j] = ((E3*j) + (i*2)) * (i-j);
            if (arrayTaxi[i][j] > (E3*2)) {
                c_i++;
            }
            if (arrayTaxi[i][j] < (-E3)) {
                c_j++;
            }
        }
    }//Nhap gia tri diem Taxi
    for (int loop=0; loop<2; loop++) {
        c_i=c_i/10 + c_i%10;
        c_j=c_j/10 + c_j%10;
    }//Tim diem gap nhau
    int max = arrayTaxi[c_i][c_j];
    for (int a=0; a<10; a++) {
        if (((c_i+a)<10) && ((c_j+a)<10)) {
            if (arrayTaxi[c_i+a][c_j+a] > max) {
                max=arrayTaxi[c_i+a][c_j+a];
            }
        }
        if (((c_i-a)>-1) && ((c_j-a)>-1)) {
            if (arrayTaxi[c_i-a][c_j-a] > max) {
                max=arrayTaxi[c_i-a][c_j-a] ;
            }
        }
        if (((c_i+a)<10) && ((c_j-a)>-1)) {
            if (arrayTaxi[c_i+a][c_j-a] > max) {
                max=arrayTaxi[c_i+a][c_j-a] ;
            }
        }
        if (((c_i-a)>-1) && ((c_j+a)<10)) {
            if (arrayTaxi[c_i-a][c_j+a] > max) {
                max=arrayTaxi[c_i-a][c_j+a] ;
            }
        }
    }//Tim diem cho Sherlock va Watson
    int point;
    if (abs(max) >= abs(arrayTaxi[c_i][c_j])) {
        EXP1 = EXP1*1.12 + 0.999;
        EXP2 = EXP2*1.12 + 0.999;
        HP1 = HP1*1.1 + 0.999;
        HP2 = HP2*1.1 + 0.999;
        returnEXP(EXP1);
        returnEXP(EXP2);
        returnHP(HP1);
        returnHP(HP2);
        point = max;
    }
    else {
        EXP1 = EXP1*0.88 + 0.999;
        EXP2 = EXP2*0.88 + 0.999;
        HP1 = HP1*0.9 + 0.999;
        HP2 = HP2*0.9 + 0.999;
        returnEXP(EXP1);
        returnEXP(EXP2);
        returnHP(HP1);
        returnHP(HP2);
        point = arrayTaxi[c_i][c_j];
    }
    return point;
}

// Task 4

int checkPassword(const char * s, const char * email) {
        // TODO: Complete this function
#define max_char 100
        char se[max_char];
        int ema=0;
        while (email[ema]!='@') {
            se[ema]=email[ema];
            ema++;
        }//gan se
        int mk=0;
        while (s[mk]!='\0') {
            mk++;
        }//tinh do dai mat khau
        int sei=0;
        for (int idx=0; idx<mk; idx++) {
            int count_pass=0;
            for (int idx_2=0; idx_2 < ema; idx_2++) {
                if (se[idx_2] == s[idx_2+idx]) {
                    count_pass++;
                    if (count_pass == ema) {
                        sei=idx;
                        goto check2char;
                    }
                }
            }
        }//Kiem tra s co trung se?
check2char:
        int sci=0;
        for (int idx_3=0; idx_3<mk; idx_3++) {
            if ((s[idx_3] == s[idx_3+1])&&(s[idx_3+1] == s[idx_3+2])) {
                sci = idx_3;
                goto checkspecialchar;
            }
        }
checkspecialchar:
        int count_specialchar=0;
        char specialchar[5] = {'@', '#', '%', '$', '!'};
        for (int idx_4=0; idx_4<mk; idx_4++) {
            for (int idx_5=0; idx_5 <5; idx_5++) {
                if (specialchar[idx_5] == s[idx_4]) {
                    count_specialchar++;
                }
            }
        }
        int trave;
        if (mk < 8) {
            trave = -1;
            goto done;
        }
        else if (mk > 20) {
            trave = -2;
            goto done;
        }
        else if (sei!=0) {
            trave = -(300+sei);
            goto done;
        }
        else if (sci!=0) {
            trave = -(400+sci);
            goto done;
        }
        else if (count_specialchar!=0) {
            trave = -5;
            goto done;
        }
        else {trave = -10;}
done:
    return trave;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    const char * arr_password[num_pwds];
    
    arr_password[0] = arr_pwds[0];
    //dem so phan tu
    
    for (int idx_6=1; idx_6<num_pwds; idx_6++) {
        for (int idx_7=1; idx_7<num_pwds; idx_7++) {
            for (int idx_8=0; idx_8<num_pwds; idx_8++) {
                if (arr_pwds[idx_7] == arr_password[idx_8]) {
                    goto passbitrung;
                }
            }
            arr_password[idx_6] = arr_pwds[idx_7];
            break;
            passbitrung:
            continue;
        }
    }//gan mang
    int count_appear[num_pwds];
    int max_appear = 0;
    for (int idx_9=0; idx_9<num_pwds;idx_9++) {
        int count_app=0;
        for (int idx_10=0; idx_10<num_pwds; idx_10++) {
            if (arr_password[idx_9] == arr_pwds[idx_10]) {
                count_app++;
            }
        }
        count_appear[idx_9]=count_app;
        if (count_appear[idx_9]>max_appear) {
            max_appear = count_appear[idx_9];
        }
    }//dem so lan xuat hien va tim so lan xuat hien lon nhat
    unsigned long max_lengthofpw = 0;
    int index=0;
    for (int idx_11=num_pwds-1; idx_11>=0; idx_11--) {
        if (count_appear[idx_11] == max_appear) {
            string str=arr_password[idx_11];
            if (max_lengthofpw <= str.length()) {
                max_lengthofpw = str.length();
                index = idx_11;
            }
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
