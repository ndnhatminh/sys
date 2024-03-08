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
void limit(int& gt, int minn, int maxx) {
    if (gt < minn) {
        gt = minn;
    };
    if (gt > maxx) {
        gt = maxx;
    };
}


// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    if ((E1<0)||(E1>99)){return -99;}
    //1.
    switch (E1) {
    case 0:
        EXP2 = EXP2 + 29;
        limit(EXP2, 0, 600);
        break;
    case 1:
        EXP2 = EXP2 + 45;
        limit(EXP2, 0, 600);
        break;
    case 2:
        EXP2 = EXP2 + 75;
        limit(EXP2, 0, 600);
        break;
    case 3:
        EXP2 = EXP2 + 149;
        limit(EXP2, 0, 600);
        break;
    }
    int D = E1 * 3 + EXP1 * 7;
    int o = D / 200;
    int b = D / 100;
    if (E1 >= 0 && E1 <= 4) {
        if (D % 2 == 0) 
        {
            EXP1 = EXP1 + o;
            limit(EXP1, 0, 600); 
        }
        else 
        {
            EXP1 = EXP1 - b;
            limit(EXP1, 0, 600); 
        };
    }
    //2.
    if (E1 >= 4 && E1 <= 19)
    { 
        EXP2 = EXP2 + ceil(E1 * 1.0001 / 4) + 19;
        limit(EXP2, 0, 600); 
    }
    else if ((E1 >= 20) && (E1 <= 49)) 
    {
        EXP2 = EXP2 + ceil(E1 * 1.0001 / 9) + 21;
        limit(EXP2, 0, 600);
    }
    else if (E1 >= 50 && E1 <= 65) 
    {
        EXP2 = EXP2 + ceil(E1 * 1.0001 / 16) + 17;
        limit(EXP2, 0, 600);
    }
    else if (E1 >= 66 && E1 <= 79) {
        EXP2 = EXP2 + ceil(E1 * 1.0001 / 4) + 19;
        limit(EXP2, 0, 600);
        if (EXP2 > 200) 
        {
            EXP2 = EXP2 + ceil(E1 * 1.0001 / 9) + 21;
            limit(EXP2, 0, 600);
        }
        else EXP2 = ceil(EXP2);
    }
    else if (E1 >= 80 && E1 <= 99) 
    {
        EXP2 = EXP2 + ceil(E1 * 1.0001 / 9) + 40 + ceil(E1 * 1.0001 / 4);
        limit(EXP2, 0, 600);
        if (EXP2 > 400) {
            EXP2 = EXP2 + ceil(E1 * 1.0001 / 16) + 17;limit(EXP2, 0, 600);
            EXP2 = ceil(EXP2 * 1.15);limit(EXP2, 0, 600);
        }
        else EXP2 = ceil(EXP2);
    }
    if (E1 >= 4 && E1 <= 99) 
    {
        EXP1 = EXP1 - E1;
        limit(EXP1, 0, 600); 
    }
    return EXP1 + EXP2;
   
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if ((E2<0)||(E2>99)){return -99;}
 //CON DUONG 1:
    double prob1;
    int midn = sqrt(EXP1);
    int leftorg = midn + 1;
    int left1 = EXP1 - (midn * midn);
    int right1 = (leftorg * leftorg) - EXP1;
    double scp = leftorg * leftorg;
    if (left1 < right1) { prob1 = 1; }
    else  prob1 = (EXP1*1.000 / scp + 80) / 123;
    //CON DUONG 2:
    int num = M1 / 2;
if (E2 % 2 == 0) {
        if (HP1 < 200) 
        {
            HP1 = ceil(HP1 * 1.3);
            M1 = M1 - 150;
            limit(HP1, 0, 666);
            limit(M1, 0, 3000);
        }
        else 
        {
            HP1 = ceil(HP1 * 1.1);
            M1 = M1 - 70;
            limit(HP1, 0, 666);
            limit(M1, 0, 3000);
        };
        
        if (M1 > 0) {
            if (EXP1 < 400) 
            {
                M1 = M1 - 200;
                limit(M1, 0, 3000);
            }
            else 
            {
                M1 = M1 - 120;
                limit(M1, 0, 3000);
            };
            EXP1 = ceil(EXP1 * 1.13);limit(EXP1, 0, 600);
        }
        else M1 = 0;
        //.
        if (M1 > 0) {
            if (EXP1 < 300) { M1 = M1 - 100; }
            else { M1 = M1 - 120; };
            limit(M1, 0, 3000);
            EXP1 = ceil(EXP1 * 0.9);
            limit(EXP1, 0, 600);
        }
        else M1 = 0;
    }
    else 
        while (M1 > num) {
            if (M1 > num) {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    M1 = M1 - 150;
                    limit(HP1, 0, 666);
                    limit(M1, 0, 3000);
                }
                else {
                    HP1 = ceil(HP1 * 1.1);
                    M1 = M1 - 70;
                    limit(HP1, 0, 666);
                    limit(M1, 0, 3000);
                };
            }
            else {
                HP1 = ceil(HP1 * 0.83);
                EXP1 = ceil(EXP1 * 1.17);
                limit(EXP1, 0, 600);
                limit(HP1, 0, 666);
                break;
            };
            //.
            if (M1 > num) {
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    limit(M1, 0, 3000);
                    EXP1 = ceil(EXP1 * 1.13);
                    limit(EXP1, 0, 600);
                }
                else {
                    M1 = M1 - 120;
                    limit(M1, 0, 3000);
                    EXP1 = ceil(EXP1 * 1.13);
                    limit(EXP1, 0, 600);
                };

            }
            else 
            { 
                HP1 = ceil(HP1 * 0.83);
                EXP1 = ceil(EXP1 * 1.17);
                limit(EXP1, 0, 600);
                limit(HP1, 0, 666); 
                break; };
            //.
            if (M1 > num) {
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    limit(M1, 0, 3000);
                }
                else {
                    M1 = M1 - 120;
                    limit(M1, 0, 3000);
                };
                EXP1 = ceil(EXP1 * 0.9);
                limit(EXP1, 0, 600);
            }
            else { HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            limit(EXP1, 0, 600);
            limit(HP1, 0, 666);
             break; };
        }
    double prob2;
    int mid = sqrt(EXP1);
    int r1 = mid + 1;
    int left = EXP1 - (mid * mid);
    int right = (r1 * r1) - EXP1;
    double s2 = r1 * r1;
    if (left < right) { prob2 = 1; }
    else { prob2 = (EXP1 * 1.0001 / s2 + 80) / 123; };
    //CON DUONG 3:
    int Prob[] = { 32,47,28,79,100,50,22,83,64,11 };
    int a, b;
    float prob3;
    a = E2 / 10 + E2 % 10;
    b = a % 10;
    if (a / 10 == 0) { prob3 = Prob[a]; }
    else   prob3 = Prob[b];
    //kq
    float floatprob3 = prob3 / 100;
    float finalprob = (prob1 + prob2 + floatprob3)/3;
    if (finalprob == 1) {
        EXP1 = ceil(EXP1 * 0.75);limit(EXP1, 0, 600);
    }
    else
    {
        if (finalprob < 0.5) { HP1 = ceil(HP1 * 0.85); EXP1 = ceil(EXP1 * 1.15); }
        else {
    HP1 = ceil(HP1 * 0.9);limit(HP1, 0, 666);EXP1 = ceil(EXP1 * 1.2); limit(EXP1, 0, 600);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int scp(int a) {
    while (a > 9) { a = a / 10 + a % 10; }
    return a;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    //
    if ((E3<0)||(E3>99)){return -99;}
    int m[10][10];
    int count1 = 0; int count2 = 0;
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            m[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            if (m[i][j] > (2 * E3)) { count1++; }
            if (m[i][j] < (-E3)) {  count2++; }
        }
    }
    int i = scp(count1);
    int j = scp(count2);
    int taxi = m[i][j];
    int max = m[i][j];
    //
    int a = 0, b = 0;
    while ((i + a >= 0) && (j + b >= 0) && (a + i < 10) && (b + j < 10)) {
        if (m[i + a][j + b] > max) { max = m[i + a][j + b]; }
        a++; b++;
    }
    a = 0;b = 0;
    while ((i + a >= 0) && (j + b >= 0) && (a + i < 10) && (b + j < 10)) {
        if (m[i + a][j + b] > max) { max = m[i + a][j + b]; }
        a--; b--;
    }
    a = 0;b = 0;
    while ((i + a >= 0) && (j + b >= 0) && (a + i < 10) && (b + j < 10)) {
        if (m[i + a][j + b] > max) { max = m[i + a][j + b]; }
        a++; b--;
    }
    a = 0;b = 0;
    while ((i + a >= 0) && (j + b >= 0) && (a + i < 10) && (b + j < 10)) {
        if (m[i + a][j + b] > max) { max = m[i + a][j + b]; }
        a--; b++;
    }
    if (abs(taxi) > max) {
        EXP1 = ceil(EXP1 * 0.88);EXP2 = ceil(EXP2 * 0.88); HP1 = ceil(HP1 * 0.9);HP2 = ceil(HP2 * 0.9);limit(EXP1, 0, 600);limit(EXP2, 0, 600);limit(HP1, 0, 666);limit(HP2, 0, 666);
        return taxi;
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);EXP2 = ceil(EXP2 * 1.12); HP1 = ceil(HP1 * 1.1);HP2 = ceil(HP2 * 1.1);limit(EXP1, 0, 600);limit(EXP2, 0, 600);limit(HP1, 0, 666);limit(HP2, 0, 666);
        return max;
    };
}

// Task 4
int checkPassword(const char* scp, const char* email) {
    // TODO: Complete this function
    string se;
    string email1 = email;
    string s1 = scp;
    for (int i = 0;i < email1.length() ;i++) { if (email1[i] == '@') { se = email1.substr(0, i); } }
    //kt length
    if (s1.length() < 8) { return -1; }
    //
    if (s1.length() > 20) { return -2; }
    //kt sei
    for (int i = 0;i < s1.length() ;i++) {
        if (s1[i] == se[0]) { if (se == s1.substr(i,se.length())) { return -(300 + i); } }
    }
    //kt sci
    for (int i = 0;i < s1.length() - 1;i++) {
        if (s1[i] == s1[i + 1]) { return -(400 + i); }
    };
    // kt ktdb
    int dem = 0;
    for (int i = 0;i < s1.length();i++) {
        if ((s1[i] == '@') || (s1[i] == '!') || (s1[i] == '#') || (s1[i] == '$') || (s1[i] == '%')) { dem = dem++; }
    }
    if (dem == 0) { return -5; }
    for (int i = 0;i < s1.length() ;i++) {
if ((s1[i] < 33) || (s1[i] == 34) || ((s1[i] > 37) && (s1[i] < 48)) || ((s1[i] > 57) && (s1[i] < 64)) || ((s1[i] > 90) && (s1[i] < 97)) || (s1[i] > 122)) { return i; };
    };

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int m[num_pwds+1];
    int mx1, mx2, final;
    for (int i = 0;i < num_pwds;i++) { m[i] = 0; }
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0;j < num_pwds;j++) {
            if (arr_pwds[i] == arr_pwds[j]) { m[i]++; }
        }
    }
    mx1 = strlen(arr_pwds[0]); mx2 = m[0];final=0;
    for (int i = 1;i < num_pwds;i++) {
        if (m[i] > mx2) {  mx1 = strlen(arr_pwds[i]); mx2=m[i]; final=i;}
    }
    for (int i = 0;i < num_pwds;i++) {
        if (m[i] == mx2) {
            if (strlen(arr_pwds[i]) > mx1) { final = i; mx1= strlen(arr_pwds[i]);  }
        }
    }

   return final;


}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////