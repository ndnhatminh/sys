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
int firstMeet(int & exp1, int & exp2, int e1)
{
    // TODO: Complete this function
    if (e1<0 || e1>99) return -99;
    checkExp(exp1, exp2);
    //case 1
    if (0<=e1 && e1<=3)
    {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 += 29 + 45 + 75;

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 += ceil((double)D / 200);
        if (D % 2 != 0) exp1 -= ceil(D / 100);
    }
    //case2
    else if (4<=e1 && e1<=99)
    {
        if (4<=e1 && e1<=19) exp2 += ceil((double)e1/4 + 19);
        else if (20<=e1 && e1<=49) exp2 += ceil((double)e1/9 + 21);
        else if (50<=e1 && e1<= 65) exp2 += ceil((double)e1/16 + 17);
        else if (66<=e1 && e1<=79)
        {
            exp2 += ceil((double)e1/4 + 19);
            if (exp2>200) exp2 += ceil((double)e1/9 + 21);
        }
        else if (80<=e1 && e1<=99)
        {
            exp2 += ceil((double)e1/4 + 19) + ceil((double)e1/9 + 21);
            if (exp2>400){
                exp2 += ceil((double)e1/16 + 17);
                exp2 = ceil (exp2 * 1.15);
            }

        }
        exp1 -= e1 ;
    }
    checkExp(exp1, exp2);
    return exp1 + exp2;
}


// Task 2
int nearestPerfectSquare(int x)
{
    int root = sqrt(x);
    int lowerSquare = root * root;
    int upperSquare = (root + 1) * (root + 1);
    if (x - lowerSquare <= upperSquare - x)
        return lowerSquare;
    else
        return upperSquare;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0 || E2>99) return -99;
    //checkInput
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if(HP1>666) HP1 = 666;
    if(HP1<0) HP1 = 0;
    if(M1>3000) M1 = 3000;
    if(M1<0) M1 = 0;
    //way1
    int S = nearestPerfectSquare(EXP1);
    double P1;
    if (EXP1>=S) P1=1.0;
    else P1=((double)EXP1/S + 80.0)/123.0;
    //way2
    if (E2 % 2 !=0)
    {
        double Spent = (double)M1/2;
        while(M1>=(Spent) && M1>0)
        {
            if (HP1<200)
            {
                HP1 += ceil((double)HP1 * 30/100.0);
                M1 -= 150;
                if(HP1>666) HP1 = 666;
                if(HP1<0) HP1 = 0;
            }
            else
            {
                HP1 += ceil((double)HP1 * 10/100.0);
                M1 -= 70;
                if(HP1>666) HP1 = 666;
                if(HP1<0) HP1 = 0;
            }
            if (M1<Spent) break;
            if (EXP1<400)
            {
                M1 -= 200;
                EXP1 += ceil((double)EXP1 * 13/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
            else
            {
                M1 -=120;
                EXP1 += ceil((double)EXP1 * 13/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
            if (M1<Spent) break;
            if (EXP1<300)
            {
                M1 -= 100;
                EXP1 -= floor((double)EXP1 * 10/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
            else
            {
                M1 -=120;
                EXP1 -= floor((double)EXP1 * 10/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
            if (M1<Spent) break;

        }
    }
    if ((E2 % 2) ==0) {
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 += ceil((double) HP1 * 30/100.0);
                M1 -= 150;
                if(HP1>666) HP1 = 666;
                if(HP1<0) HP1 = 0;
            } else {
                HP1 += ceil((double) HP1 * 10/100.0);
                M1 -= 70;
                if(HP1>666) HP1 = 666;
                if(HP1<0) HP1 = 0;
            }
        }
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 -= 200;
                EXP1 += ceil((double) EXP1 * 13/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            } else {
                M1 -= 120;
                EXP1 += ceil((double) EXP1 * 13/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
        }
        if (M1 > 0) {
            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 -= floor((double) EXP1 * 10/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            } else {
                M1 -= 120;
                EXP1 -= floor((double) EXP1 * 10/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
        }
        if (M1 < 0) M1 = 0;
    }

    HP1 -= floor((double)HP1 * 17/100.0);
    EXP1 += ceil((double)EXP1 * 17/100.0);
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if(HP1>666) HP1 = 666;
    if(HP1<0) HP1 = 0;
    int S2 = nearestPerfectSquare(EXP1);
    double P2;
    if (EXP1>=S2) P2=1.0;
    else P2=((double)EXP1/S2 + 80.0)/123.0;
    //way3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2<10) i = E2;
    else
    {
        int T = E2/10 + E2%10;
        i = T % 10;
    }
    double P3 = (double)P[i]/100.0;
    //final
    double H;
    H = (P1+P2+P3)/3.0;
    if(H==1.0) EXP1 -= floor(EXP1 * 25/100.0);
    else if (H < 0.5)
    {
            HP1 -= floor((double) HP1 * 15/100.0);
            EXP1 += ceil((double) EXP1 * 15/100.0);
    }
    else
    {
            HP1 -= floor((double) HP1 * 10/100.0);
            EXP1 += ceil((double) EXP1 * 20/100.0);
    }
    //checkOutput
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if(HP1>666) HP1 = 666;
    if(HP1<0) HP1 = 0;
    if(M1>3000) M1 = 3000;
    if(M1<0) M1 = 0;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
    // TODO: Complete this function
    if (E3<0 || E3>99) return -99;
    //checkInput
    checkEXP(EXP1, EXP2);
    checkHP(HP1, HP2);
    //start matrix
    int map [10][10];
    int x=0;
    int y=0;
    //score for each position
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int score = ((E3 * j) + (i * 2)) * (i - j);
            map[i][j] = score;

        }


    }
//    for (int i=0;i<10;i++)
//    {
//        for(int j=0;j<10;j++)
//        {
//            cout << map[i][j] << " ";
//        }
//        cout <<endl;
//    }
    //meeting point
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] > (E3 * 2)) ++x;
            if (map[i][j] < (E3 * -1)) ++y;
        }
    }
    while(x>=10)
    {
        x = x%10 + x/10;
    }
    while(y>=10)
    {
        y = y%10 + y/10;
    }
    //Sherlock & Watson score
    int MP = map[x][y];
    int xmax = x;
    int ymax = y;
    while ((xmax>-1) && (ymax>-1))
    {
        if (map[xmax][ymax] > MP) MP = map[xmax][ymax];
        --xmax;
        --ymax;
    }
    xmax = x;
    ymax = y;
    while ((xmax<10) && (ymax>-1))
    {
        if (map[xmax][ymax] > MP) MP = map[xmax][ymax];
        ++xmax;
        --ymax;
    }
    xmax = x;
    ymax = y;
    while ((xmax<10) && (ymax<10))
    {
        if (map[xmax][ymax] > MP) MP = map[xmax][ymax];
        ++xmax;
        ++ymax;
    }
    xmax = x;
    ymax = y;
    while ((xmax>-1) && (ymax<10))
    {
        if (map[xmax][ymax] > MP) MP = map[xmax][ymax];
        --xmax;
        ++ymax;
    }
    //comparison
    if (abs(map[x][y]) > abs(MP))
    {
        EXP1 -= floor((double)EXP1 * 12/100.0);
        EXP2 -= floor((double)EXP2 * 12/100.0);
        HP1 -= floor((double)HP1 * 10/100.0);
        HP2 -= floor((double)HP2 * 10/100.0);
        checkEXP(EXP1, EXP2);
        checkHP(HP1, HP2);
        return map[x][y];
    }
    else
    {
        EXP1 += ceil((double)EXP1 * 12/100.0);
        EXP2 += ceil((double)EXP2 * 12/100.0);
        HP1 += ceil((double)HP1 * 10/100.0);
        HP2 += ceil((double)HP2 * 10/100.0);
        checkEXP(EXP1, EXP2);
        checkHP(HP1, HP2);
        return MP;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // cout << "\n" << "S = " << s << "\n"<< "Email = " << email;
    //ReDefining
    string alt_s(s);
    string alt_email(email);
    string se = alt_email.substr(0, alt_email.find('@'));
    //checkLength
    if (alt_s.length() <= 7)        return -1;
    else if (alt_s.length() >= 21)  return -2;
    //checkLegitChar
    const string legit_char = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%";
    for (int i = 0; i < alt_s.length(); ++i) {
        if (legit_char.find(alt_s[i]) == string::npos) {
            return i;
        }
    }
    //checkSe
    if (alt_s.find(se) != string::npos) {
        return (300 + (alt_s.find(se))) * -1;
    }
    //checkDoubleChar
    for (int i = 0; i < alt_s.length() - 2; ++i) {
        if (alt_s[i] == alt_s[i + 1] && alt_s[i] == alt_s[i+2]) {
            return (400 + i) * -1;
        }
    }
    //checkSpecialChar
    const string special_Char = "@#%$!";
    bool checkSC = false;
    for (int i = 0; i < alt_s.length(); ++i) {
        if (special_Char.find(alt_s[i]) != string::npos) checkSC = true;
    }
    if(checkSC == false) return -5;
    else                return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int *count = new int[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        count[i] = 0;
    }

    // Count each pwd appears time
    for (int i = 0; i < num_pwds; i++) {
        for (int j = i; j < num_pwds; j++) {
            if (string(arr_pwds[i]) == string(arr_pwds[j])) {
                count[i]++;
            }
        }
    }

    // find most frequent pwd
    int maxCount = 0;
    int mostFrequentPwd = -1;
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequentPwd = i;
        }
    }

    // find longest pwd
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] == maxCount && std::string(arr_pwds[i]).length() > std::string(arr_pwds[mostFrequentPwd]).length()) {
            mostFrequentPwd = i;
        }
    }

    delete[] count;

    return mostFrequentPwd; // Return -1 if no correct password found
}

void checkExp(int & exp1, int & exp2)
{
    if (exp1 > 600) exp1 = 600;
    if (exp2 > 600) exp2 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 < 0) exp2  = 0;
}
void checkEXP(int & EXP1, int & EXP2)
{
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 < 0) EXP2 = 0;
}
void checkHP(int & HP1, int & HP2)
{
    if(HP1>666) HP1 = 666;
    if(HP1<0) HP1 = 0;
    if(HP2>666) HP2 = 666;
    if(HP2<0) HP2 = 0;
}
void checkM (int & M1, int & M2)
{
    if(M1>3000) M1 = 3000;
    if(M1<0) M1 = 0;
    if(M2>3000) M2 = 3000;
    if(M2<0) M2 = 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////