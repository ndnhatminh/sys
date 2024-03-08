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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    int D=0;
    KtraExp(exp1);
    KtraExp(exp2);
    if ((e1 < 0) || (e1 > 99))
        return -99;
    else
    {
        if (e1 <= 3) {
            if (e1 == 0)
                exp2 = exp2 + 29;
            else
                if (e1 == 1)
                    exp2 = exp2 + 45;
                else
                    if (e1 == 2)
                        exp2 = exp2 + 75;
                    else
                        exp2 = exp2 + 149;
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
                exp1 = exp1 + D / 200.0+0.999;
            else
                exp1 = exp1 - D / 100.0+0.999;
        }
        else {
            if (e1 <= 19)
                exp2 = exp2 + e1 / 4.0 + 19+0.999;
            else
                if (e1 <= 49)
                    exp2 = exp2 + e1 / 9.0 + 21+0.999;
                else
                    if (e1 <= 65)
                        exp2 = exp2 + e1 / 16.0 + 17+0.999;
                    else
                        if (e1 <= 79) {
                            exp2 = exp2 + e1 / 4.0 + 19+0.999;
                            if (exp2 > 200)
                                exp2 = exp2 + e1 / 9.0 + 21+0.999;
                        }
                        else
                            if (e1 <= 99) {
                                exp2 = exp2 + e1 / 4.0 + 19+0.999;
                                exp2 = exp2 + e1 / 9.0 + 21+0.999;
                                if (exp2 > 400) {
                                    exp2 = exp2 + e1 / 16.0 + 17+0.999;
                                    exp2 = exp2 * 1.15+0.999;
                                }
                            }
            exp1 = exp1 - e1;
        }
        KtraExp(exp1);
        KtraExp(exp2);
        return exp1 + exp2;
    }
   
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    float P1=0, P2=0, P3=0,S=0;
    int ChiPhi2=0;
    int K = 0;
    KtraExp(EXP1);
    KtraHP(HP1);
    KtraM(M1); 
    if ((E3 >= 100) || (E3 < 0))
        return -99;
    //Con duong 1
    {
        S = round(sqrt(EXP1));
        if (EXP1 >= S*S)
            P1 = 1;
        else
            P1 = (EXP1 / (S*S) + 80) / 123;
    }
    
    //Con duong 2
    {
        while ((E3 % 2 == 1) || (K == 0)) {
            //SuKien1
            {
                
                if (HP1 < 200) {
                    HP1 = HP1 * 1.3+0.999;
                    ChiPhi2 = ChiPhi2 + 150;
                    KtraHP(HP1);
                }

                else {
                    HP1 = HP1 * 1.1+0.999;
                    ChiPhi2 = ChiPhi2 + 70;
                    KtraHP(HP1);
                }
            
            }
           
            Ktra2(ChiPhi2, M1, E3);
            //SuKien2
            {
                if (EXP1 < 400)
                    ChiPhi2 = ChiPhi2 + 200;
                else
                    ChiPhi2 = ChiPhi2 + 120;
                EXP1 = 1.13 * EXP1+0.999;
            }
            Ktra2(ChiPhi2, M1, E3);
            //SuKien3
            {
                if (EXP1 < 300)
                    ChiPhi2 = ChiPhi2 + 100;
                else
                    ChiPhi2 = ChiPhi2 + 120;
                EXP1 = 0.9 * EXP1+0.999;
            }
            Ktra2(ChiPhi2, M1, E3);
            K = K + 1; 
        }
        HP1 = 0.83 * HP1+0.999;
        EXP1 = 1.17 * EXP1+0.999;
        M1 = M1 - ChiPhi2;
        KtraM(M1);
        KtraExp(EXP1);
        KtraHP(HP1);
        S = round(sqrt(EXP1));
        if (EXP1 >= S*S)
            P2 = 1;
        else
            P2 = (EXP1 / (S*S) + 80) / 123;
    }
    //Con Duong 3
    {
        float p[10] = { 32,47,28,79,100,50,22,83,64,11 };
        if ((E3 >= 100) || (E3 < 0))
            return -99;
        else
            if (E3 >= 10) {
                E3 = (E3 % 10 + (E3 / 10) % 10) % 10;
                P3 = p[E3]/100;
            }
            else
                P3 = p[E3]/100;
    }
    //cout << P1 << " " << P2 << " "<<P3<<endl;
    if ((P1 == P2) && (P2 == P3) && (P3 == P1) && (P1==1))
        EXP1 = 0.75 * EXP1+0.999;
    else
    {
        P1 = (P1 + P2 + P3) / 3;
        if (P1 < 0.5) {
            HP1 = 0.85 * HP1+0.999;
            EXP1 = 1.15 * EXP1+0.999;

        }
        else
        {
            HP1 = 0.9 * HP1+0.999;
            EXP1 = 1.2 * EXP1+0.999;
        }
    }


    
    KtraExp(EXP1);
    KtraHP(HP1);
    return(EXP1 + HP1 + M1);
}
// Task 3
void chiso(int& dem)
{
    if (dem < 10)
        return;
    else  {
        dem = dem % 10 + (dem / 10) % 10;
        chiso(dem);
    }
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    KtraHP(HP1);
    KtraHP(HP2);
    KtraExp(EXP1);
    KtraExp(EXP2);
    if ((E3 >= 100) || (E3 < 0))
        return -99;
    int maxx=0, i=0, j=0, e=E3;
    int a[10][10] = {};
    int dem1 = 0, dem2 = 0;
    //TaoMang
    {
        for (i = 0; i <= 9; i++)
            for (j = 0; j <= 9; j++)
            {
                a[i][j] = ((e * j) + (i * 2)) * (i - j);
                if (a[i][j] > e * 2)
                    dem1 = dem1 + 1;
                if (a[i][j] < -e)
                    dem2 = dem2 + 1;
            }
    }
    chiso(dem1);
    chiso(dem2);
    //xetduongcheotrai
    {
        maxx = (a[dem1][dem2]);
        i = dem1 + 1;
        j = dem2 + 1;
        while ((i <= 9) && (j <= 9))
        {
            if (abs(a[i][j]) > abs(maxx))
                maxx = a[i][j];
            i = i + 1;
            j = j + 1;
        }
        i = dem1 - 1;
        j = dem2 - 1;
        while ((i >= 0) && (j >= 0))
        {
            if (abs(a[i][j]) > abs(maxx))
                maxx = a[i][j];
            i = i - 1;
            j = j - 1;
        }
    }
    //xetduongcheophai
    {
        i = dem1;
        j = dem2;
        while ((i >= 0) && (j <= 9))
        {
            if (abs(a[i][j]) > abs(maxx))
                maxx = a[i][j];
            i = i - 1;
            j = j + 1;
        }
        i = dem1;
        j = dem2;
        while ((i <= 9) && (j >= 0))
        {
            if (abs(a[i][j]) > abs(maxx))
                maxx = a[i][j];
            i = i + 1;
            j = j - 1;
        }
    }
    //result
    {
        if (abs(maxx) >= abs(a[dem1][dem2])) {
            EXP1 = EXP1 * 1.12+0.999;
            EXP2 = EXP2 * 1.12+0.999;
            HP1 = HP1 * 1.1+0.999;
            HP2 = HP2 * 1.1+0.999;
            KtraHP(HP1);
            KtraHP(HP2);
            KtraExp(EXP1);
            KtraExp(EXP2);
           
        }
        else {
            EXP1 = EXP1 * 0.88+0.999;
            EXP2 = EXP2 * 0.88+0.999;
            HP1 = HP1 * 0.9+0.999;
            HP2 = HP2 * 0.9+0.999;
            KtraHP(HP1);
            KtraHP(HP2);
            KtraExp(EXP1);
            KtraExp(EXP2);
            //return a[dem1][dem2];
        }
        if ((maxx) >= (a[dem1][dem2]))
            return maxx;
        else
            return a[dem1][dem2];
            
    }
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s1 = s, s2 = email;
    int LengS = s1.length(), LengEmail = s2.length();
    int pos = s2.find('@');
    bool KtraKyTuDB = 0;
    int KtraConLai = -1;
    s2 = s2.substr(0, pos);
    if (LengS < 8)
        return -1;
    else
        if (LengS > 20)
            return -2;
        else {
            pos = s1.find(s2);
            if (pos != -1)
                return -(300 + pos);
            else {
                int i = 0;
                while (i <= LengS - 1)
                {
                    if (i < LengS - 2)
                        if ((s1[i] == s[i + 1]) && (s[i + 1] == s[i + 2]))
                            return -(400 + i);
                    if (!(((s1[i] >= 'a') && (s1[i] <= 'z')) || ((s1[i] >= 'A') && (s1[i] <= 'Z')) || ((s1[i] == '@') || (s1[i] == '#') || (s1[i] == '%') || (s1[i] == '$') || (s1[i] == '!'))||((s1[i]>='0')&&(s1[i]<='9')))) {
                        if (KtraConLai==-1)
                        KtraConLai = i;
                    }
                    if ((s1[i] == '@') || (s1[i] == '#') || (s1[i] == '%') || (s1[i] == '$') || (s1[i] == '!'))
                        KtraKyTuDB = 1;
                    ++i;
                }
                if (KtraKyTuDB == 0)
                    return -5;
                else
                    if (KtraConLai != -1) 
                        return KtraConLai;
              
                    else
                        return -10;
            }

        }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string Smax = arr_pwds[0];
    string s[31];
    int soluong[31] = {}, FirstPlace[31] = {};
    bool KtraLap = 0;
    int soluongkhac = -1, i = 0, j = 0;
    for (i = 0; i <= num_pwds - 1; i++) {
        KtraLap = 0;
        for (j = 0; j <= soluongkhac; j++)
            if (s[j] == arr_pwds[i]) {
                KtraLap = 1;
                break;
            }
        if (KtraLap == 1) {
            ++soluong[j];
        }
        else {
            ++soluongkhac;
            s[soluongkhac] = arr_pwds[i];
            FirstPlace[soluongkhac] = i;
            soluong[soluongkhac] = 1;
        }
    }
    int maxxcount = soluong[0], result = FirstPlace[0];
    for (i = 0; i <= soluongkhac; i++)
    {
        if (maxxcount < soluong[i]) {
            maxxcount = soluong[i];
            result = FirstPlace[i];
            Smax = s[i];

        }
        else
            if ((maxxcount == soluong[i]) && (Smax.length() < s[i].length())) {
                result = FirstPlace[i];
                Smax = s[i];

            }

    }
    return result;
   
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////