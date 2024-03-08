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
int firstMeet(int & exp1, int & exp2, int e1)  {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99))
    {
        return -99;
    }
    if (exp1 < 0) exp1 = 0;
    else if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    else if (exp2 > 600) exp2 = 600;
    ////////////EXP2
    /////TH 1: e1 [0,3]
    // thong tin 1
    if (e1 == 0)
        exp2 += 29;
    // thong tin 2
    else if (e1 == 1)
        exp2 += 45;
    // thong tin 3
    else if (e1 == 2)
        exp2 += 75;
    // thong tin 4
    else if (e1 == 3)
        exp2 += (29 + 45 + 75);
    /////TH 2: e1 [4,99]
    // thong tin 1
    if ((e1 >= 4) && (e1 <= 19))
        exp2 = ceil(exp2 + ((e1 / 4.0) + 19));
    // thong tin 2
    else if ((e1 >= 20) && (e1 <= 49))
        exp2 = ceil(exp2 + ((e1 / 9.0) + 21));
    // thong tin 3
    else  if ((e1 >= 50) && (e1 <= 65))
        exp2 = ceil(exp2 + ((e1 / 16.0) + 17));
    // thong tin 4
    else if ((e1 >= 66) && (e1 <= 79)) {
        exp2 = ceil(exp2 + ((e1 / 4.0) + 19));
        if (exp2 > 200)
            exp2 = ceil(exp2 + ((e1 / 9.0) + 21));
    }
    // thong tin 5
    else if ((e1 >= 80) && (e1 <= 99)) {
        exp2 = ceil(exp2 + ((e1 / 4.0) + 19));
        exp2 = ceil(exp2 + ((e1 / 9.0) + 21));
        if (exp2 > 400) {
            exp2 = ceil(exp2 + ((e1 / 16.0) + 17));
            exp2 = ceil(exp2 * 1.15);
        }
    }
    //////////EXP1
    //So quyet dinh cua Sherlock (D)
    int D;
    if ((e1 >= 0) && (e1 <= 3)) {
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = ceil(exp1 + D / 200.0);
        else
            exp1 = ceil(exp1 - D / 100.0);
    }
    else if ((e1 >= 4) && (e1 <= 99))
        exp1 = exp1 - e1;
    //////// Check EXP
    if (exp1 > 600)   exp1 = 600;
    else if (exp1 < 0)  exp1 = 0;
    if (exp2 > 600)   exp2 = 600;
    else if (exp2 < 0)  exp2 = 0;
    //output
    return exp1 + exp2;
}

//Ham tim so chinh phuong
int SoChinhPhuong(int EXP1) {
    int a, x1, x2, x;
    x = sqrt(EXP1);
    x1 = x * x;
    x2 = (x + 1) * (x + 1);
    abs(x1 - EXP1) < abs(x2 - EXP1) ? a = x1 : a = x2;
    return a;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0) || (E2 > 99)) return -99;
    else {
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;

        float Mcmp, P1, P2, P3,P;
        int S, M;
        ///Con duong 1
        S = SoChinhPhuong(EXP1);
        if (EXP1 >= S) P1 = 100;
        else
            P1 = ((EXP1 *1.0 / S) + 80) / 123 * 100; 
        ///Con duong 2
        //E chan
        if (E2 % 2 == 0) {
            for (int i = 1; i == 1; i++)
            {
                //Su kien 1
                if (HP1 < 200) {
                    HP1 = ceil(HP1 + HP1*30.0 / 100);
                    M1 = M1 - 150;
                }
                else {
                    HP1 = ceil(HP1 + HP1 * 10.0 / 100.0); 
                    M1 = M1 - 70;
                }
                if (HP1 > 666) HP1 = 666;
                else if (HP1 < 0) HP1 = 0;
                if (M1 > 3000) M1 = 3000;
                else if (M1 < 0) M1 = 0;
                if (M1 == 0) break;

                //Su kien 2
                if (EXP1 < 400) M1 = M1 - 200;
                else M1 = M1 - 120;

                EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100.0); 
                if (EXP1 > 600) EXP1 = 600;
                else if (EXP1 < 0) EXP1 = 0;
                if (M1 > 3000) M1 = 3000;
                else if (M1 < 0) M1 = 0;
                if (M1 == 0) break;

                //Su kien 3

                if (EXP1 < 300)    M1 = M1 - 100;
                else M1 = M1 - 120;

                EXP1 = ceil(EXP1 - EXP1 * 10.0 / 100.0); 
                if (EXP1 > 600) EXP1 = 600;
                else if (EXP1 < 0) EXP1 = 0;
                if (M1 > 3000) M1 = 3000;
                else if (M1 < 0) M1 = 0;
                if (M1 == 0) break;
            }
        }
        else {//e le
            Mcmp = (M1 / 2); 
            int Mm = 0;
            while (Mm<Mcmp)
            {
                //Su kien 1
                if (HP1 < 200) {
                    HP1 = ceil(HP1 + HP1*30.0 / 100.0); 
                    M1 = M1 - 150;
                    Mm += 150;
                }
                else {
                    HP1 = ceil(HP1 + HP1 * 10.0 / 100.0);
                    M1 = M1 - 70;
                    Mm += 70;
                }
                if (HP1 > 666) HP1 = 666;
                else if (HP1 < 0) HP1 = 0;
                if (M1 > 3000) M1 = 3000;
                else if (M1 < 0) M1 = 0;
                if (Mm > Mcmp) break;

                //Su kien 2
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    Mm += 200;
                }
                else {
                    M1 = M1 - 120;
                    Mm += 120;
                }

                EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100.0);
                if (EXP1 > 600) EXP1 = 600;
                else if (EXP1 < 0) EXP1 = 0;
                if (M1 > 3000) M1 = 3000;
                else if (M1 < 0) M1 = 0;
                if (Mm > Mcmp) break;

                //Su kien 3
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    Mm += 100;
                }
                else {
                    M1 = M1 - 120;
                    Mm += 120;
                }

                EXP1 = ceil(EXP1 - EXP1 * 10.0 / 100.0);
                if (EXP1 > 600) EXP1 = 600;
                else if (EXP1 < 0) EXP1 = 0;
                if (M1 > 3000) M1 = 3000;
                else if (M1 < 0) M1 = 0;
                if (Mm > Mcmp) break;
            }
        }
        EXP1 = ceil(EXP1 + EXP1 * 17 / 100.0);
        HP1 = ceil(HP1 - HP1 * 17 / 100.0);
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        //Xac suat con duong 2
        S = SoChinhPhuong(EXP1);
        if (EXP1 >= S) P2 = 100;
        else
            P2 = ((EXP1 * 1.0 / S) + 80) / 123 * 100.0;
        ///Con duong 3
        int arrayP[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 < 10)   P3 = arrayP[E2];
        else {
            E2 = (E2 / 10) + (E2 % 10);
            if (E2 < 10)   P3 = arrayP[E2];
            else {
                E2 = (E2 / 10) + (E2 % 10);
                P3 = arrayP[E2];
            }
                
        }

        ////Xac xuat trung binh
        P = (P1 + P2 + P3) / 3.0;
        if (P >= 100)  EXP1 = ceil(EXP1 - EXP1 * 25 / 100.0);
        else if (P < 50) {
            HP1 = ceil(HP1 - HP1 * 15 / 100.0);
            EXP1 = ceil(EXP1 + EXP1 * 15 / 100.0);
        }
        else if (P >= 50) {
            HP1 = ceil(HP1 - HP1 * 10 / 100.0);
            EXP1 = ceil(EXP1 + EXP1 * 20 / 100.0);
        }
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //Ktra so E
    if ((E3 < 0) || (E3 > 99))
    {
        return -99;
    }
    else
    {
        //Kiem tra du lieu nhap vao
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;

        ///Tao ma tran diem cua taxi
        int pTaxi[10][10] = {};
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                pTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        ///Diem gap nhau
        int x = 0, y = 0, I, J;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (pTaxi[i][j] > (E3 * 2))  x++;
                else if (pTaxi[i][j] < (-E3)) y++;
            }
        }
        ///toa do gap
        if (x < 10) I = x;
        else {
            x = (x / 10) + (x % 10);
            if (x < 10) I = x;
            else I = (x / 10) + (x % 10);
        }
        if (y < 10) J = y;
        else {
            y = (y / 10) + (y % 10);
            if (y < 10) J = y;
            else J = (y / 10) + (y % 10);
        }
        //Diem cua sherlock
        int pSherlock;
        //Duong cheo trai
        int LeftMax = pTaxi[I][J];
        for (int It = I, Jt = J; (It > 0 && Jt > 0); It--, Jt--)
        {
            if (pTaxi[It - 1][Jt - 1] > LeftMax)   LeftMax = pTaxi[It - 1][Jt - 1];
        }
        for (int It = I, Jt = J; (It < 9 && Jt < 9); It++, Jt++)
        {
            if (pTaxi[It + 1][Jt + 1] > LeftMax)   LeftMax = pTaxi[It + 1][Jt + 1];
        }
        //Duong cheo phai
        int RightMax = pTaxi[I][J];
        for (int It = I, Jt = J; (It > 0 && Jt < 9); It--, Jt++)
        {
            if (pTaxi[It - 1][Jt + 1] > RightMax)   RightMax = pTaxi[It - 1][Jt + 1];
        }
        for (int It = I, Jt = J; (It < 9 && Jt >0); It++, Jt--)
        {
            if (pTaxi[It + 1][Jt - 1] > RightMax)   RightMax = pTaxi[It + 1][Jt - 1];
        }
        ///Xac dinh diem cua Sherlock
        if (RightMax > LeftMax)    pSherlock = RightMax;
        else    pSherlock = LeftMax;
        pSherlock = abs(pSherlock);
        /////Xac dinh cua duoi kip hay khong
        if (abs(pTaxi[I][J]) > pSherlock)
        {
            EXP1 = ceil(EXP1 - EXP1 * 12 / 100.0);
            EXP2 = ceil(EXP2 - EXP2 * 12 / 100.0);
            HP1 = ceil(HP1 - HP1 * 10 / 100.0);
            HP2 = ceil(HP2 - HP2 * 10 / 100.0);
            if (EXP1 > 600) EXP1 = 600;
            else if (EXP1 < 0) EXP1 = 0;

            if (HP1 > 666) HP1 = 666;
            else if (HP1 < 0) HP1 = 0;

            if (EXP2 > 600) EXP2 = 600;
            else if (EXP2 < 0) EXP2 = 0;

            if (HP2 > 666) HP2 = 666;
            else if (HP2 < 0) HP2 = 0;
            
            return pTaxi[I][J];
        }
        else
        {
            EXP1 = ceil(EXP1 + EXP1 * 12 / 100.0);
            EXP2 = ceil(EXP2 + EXP2 * 12 / 100.0);
            HP1 = ceil(HP1 + HP1 * 10 / 100.0);
            HP2 = ceil(HP2 + HP2 * 10 / 100.0);
            if (EXP1 > 600) EXP1 = 600;
            else if (EXP1 < 0) EXP1 = 0;

            if (HP1 > 666) HP1 = 666;
            else if (HP1 < 0) HP1 = 0;

            if (EXP2 > 600) EXP2 = 600;
            else if (EXP2 < 0) EXP2 = 0;

            if (HP2 > 666) HP2 = 666;
            else if (HP2 < 0) HP2 = 0;
            
            return pSherlock;
        }
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int count = 0;
    /////Ktra @ va tao se
    char se[100] = {};
    for (int i = 0; email[i]!=64; i++)
    {
        if (email[i] != '@')
        {
            count++;
            se[i] = email[i];
        }
        else break;
    }

    /////Dieu kien do dai cua s
    if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;

    /////S chua cac ki tu ko hop le 
    for (int i = 0; i < strlen(s); i++)
    {
       if(!(s[i]==33||s[i]==35||s[i]==36||s[i]==37||s[i]==64||(s[i]>=48&&s[i]<=57)||(s[i]>=65&&s[i]<=90)|| (s[i] >= 97 && s[i] <= 122)))
            return i;
    }

    ///// S chua se
    int dem = 0;
    int r = 0, k = 0;
    for (k = 0; k <= strlen(s); k++)
    {
        for (r = 0; r <=strlen(se); r++)
        {
            if (se[dem] != s[k + dem])
            {
                dem = 0;
                break;
            }
            else
            {
                dem++;
                if (dem > strlen(se)) break;
            }
        }
        if (r == strlen(se)) break;
    }
    if (r == strlen(se) || dem - 1 == strlen(se)) return -(300 + k);

    /////S chua nhieu hon 2 ki tu lien tiep giong nhau
    for (int m = 0; m < strlen(s); m++)
    {
        if (s[m] == s[m + 1] && s[m + 1] == s[m + 2])
            return -(400 + m);
    }

    ///// S ko chua ki tu dac biet
    int demKT = 0;
    for (int n = 0; n < strlen(s); n++)
    {
        if (s[n] == 33 || s[n] == 35 || s[n] == 36 || s[n] == 37 || s[n] == 64)
            demKT++;     
    }
    if (demKT == 0) return -5;

    ////s hop le
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_meet = 0,
        max_length = 0,
        times_meet = 0,
        length_pwds = 0,
        pwds_pos = 0;
    for (int i = 0; i < num_pwds; i++) //kiem tra tung mk
    {
        for (int j = 0; j < num_pwds; j++)// so sanh mk dang ktra voi cac mk con lai
        {
            if (arr_pwds[i] == arr_pwds[j])
            {
                times_meet++;
                length_pwds = strlen(arr_pwds[i]);
            }
            else continue;
        }// da so sanh voi tat ca
        if (times_meet > max_meet)//kiem tra so lan gap, gan do dai, vi tri neu dung
        {
            max_meet = times_meet;
            pwds_pos = i;
            max_length = length_pwds;
        }
        else if (times_meet == max_meet && length_pwds > max_length)
        {
                pwds_pos =i;
                max_length = length_pwds; 
        }//reset so lan gap va do dai
        times_meet = 0;
        length_pwds = 0;
    }
 return pwds_pos;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////