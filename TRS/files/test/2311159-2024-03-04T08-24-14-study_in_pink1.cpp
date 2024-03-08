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
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (exp1 < 0) exp1 = 0;
    if (exp2 < 0) exp2 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 > 600) exp2 = 600;
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 = exp2 + 29;
            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }

        else if (e1 == 1) {
            exp2 = exp2 + 45;
            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 == 2) {
            exp2 = exp2 + 75;
            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 == 3) {
            exp2 = exp2 + 29 + 45 + 75;
            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) {
            exp1 = ceil(exp1 + d / 200.0);
            
            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }
        else {
            exp1 = ceil(exp1 - d / 100.0);
            
            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);

            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2 + e1 / 9.0 + 21);

            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2 + e1 / 16.0 + 17);

            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);

            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
            if (exp2 > 200) {
                exp2 = ceil(exp2 + e1 / 9.0 + 21);

                if (exp1 < 0) exp1 = 0;
                if (exp2 < 0) exp2 = 0;
                if (exp1 > 600) exp1 = 600;
                if (exp2 > 600) exp2 = 600;
            }

        }
        else if (e1 >= 80) {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);

            exp2 = ceil(exp2 + e1 / 9.0 + 21);

            if (exp1 < 0) exp1 = 0;
            if (exp2 < 0) exp2 = 0;
            if (exp1 > 600) exp1 = 600;
            if (exp2 > 600) exp2 = 600;
            if (exp2 > 400) {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);

                if (exp1 < 0) exp1 = 0;
                if (exp2 < 0) exp2 = 0;
                if (exp1 > 600) exp1 = 600;
                if (exp2 > 600) exp2 = 600;
                exp2 = ceil(exp2 * 1.15);

                if (exp1 < 0) exp1 = 0;
                if (exp2 < 0) exp2 = 0;
                if (exp1 > 600) exp1 = 600;
                if (exp2 > 600) exp2 = 600;
            }

        }
        exp1 = exp1 - e1;
        if (exp1 < 0) exp1 = 0;
        if (exp2 < 0) exp1 = 0;
        if (exp1 > 600) exp1 = 600;
        if (exp2 > 600) exp2 = 600;
    }
        
    
    if (e1 < 0 || e1 >99){
        return -99;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (E2 >= 0 && E2 <= 99) {
        int s;
        float P1;
        s = round(sqrt(EXP1)) * round(sqrt(EXP1));
        if (EXP1 >= s) {
            P1 = 1.0;
        }
        else {
            P1 = (EXP1 / s + 80) / 123.0;
        }
        float m1 = M1 / 2.0;
        int m2 = 0;
        if (E2 % 2 != 0) {
            while (m2 <= m1) {
                if (HP1 < 200) {
                    HP1 = ceil(round(HP1 * 1.3*10)/10);
                    M1 = M1 - 150;
                    m2 = m2 + 150;
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                    if (m2 >= m1) break;
                }
                else if (HP1 >= 200) {
                 
                    HP1 = ceil(round(HP1 * 1.1*10)/10);
                    M1 = M1 - 70;
                    m2 = m2 + 70;
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                    if (m2 >= m1) break;
                }
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    EXP1 = ceil(EXP1 * 1.13);
                    m2 = m2 + 200;
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                    if (m2 >= m1) break;
                }
                else {
                    M1 = M1 - 120;
                    EXP1 = ceil(EXP1 * 1.13);
                    m2 = m2 + 120;
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                    if (m2 >= m1) break;

                }
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    EXP1 =ceil(double(EXP1) * 0.9);
                    m2 = m2 + 100;
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                    if (m2 >= m1) break;
                }
                else {
                    M1 = M1 - 120;
                    EXP1 = ceil(double(EXP1) * 0.900);
                    m2 = m2 + 120;
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                    if (m2 >= m1) break;
                }
            }
            HP1 = ceil(round(HP1 * 0.830*100)/100);
            EXP1 = ceil(double(EXP1) * 1.170);
            if (M1 < 0) M1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
        }
        else {
            if (HP1 < 200 && M1>0) {
                HP1 = ceil(round(HP1 * 1.30*100)/100);
                M1 = M1 - 150;
                if (M1 < 0) M1 = 0;
                if (M1 > 3000) M1 = 3000;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
            else if (HP1 >= 200 && M1>0) {
                HP1 = ceil(round(HP1 * 1.10*100)/100);
                M1 = M1 - 70;
                if (M1 < 0) M1 = 0;
                if (M1 > 3000) M1 = 3000;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
            if (EXP1 < 400 ) {
                if (M1 > 0) {
                    M1 = M1 - 200;
                    EXP1 = ceil(double(EXP1) * 1.130);
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                }
            }
            else if(EXP1>=400){
                if (M1 > 0) {
                    M1 = M1 - 120;
                    EXP1 = ceil(double(EXP1) * 1.130);
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                }

            }
            if (EXP1 < 300) {
                if (M1 > 0) {
                    M1 = M1 - 100;
                    EXP1 = ceil(double(EXP1) * 0.90);
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                }
            }
            else if(EXP1>=300) {
                if (M1 > 0) {
                    M1 = M1 - 120;
                    EXP1 = ceil(double(EXP1) * 0.90);
                    if (M1 < 0) M1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    if (HP1 < 0) HP1 = 0;
                    if (HP1 > 666) HP1 = 666;
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                }
            }
            HP1 = ceil(double(HP1) * 0.830);
            EXP1 =ceil(double(EXP1) * 1.170);
            if (M1 < 0) M1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
        }
        float P2;
        s = round(sqrt(EXP1)) * round(sqrt(EXP1));
        if (EXP1 >= s) {
            P2 = 1.0;
        }
        else {
            P2 = (EXP1 / s + 80) / 123.0;
        }
        float P3[10] = { 0.32,0.47,0.28,0.79,1.0,0.50,0.22,0.83,0.64,0.11 };
        
        int a;
        int i = 0;
        a = E2 / 10;
        if (a == 0) {
            
            i = E2;
        }
        else {
            
            int b = E2 % 10;
            i = (a + b)%10;
        }
        if (P1 == 1.0 && P2 == 1.0 && P3[i] == 1.0) {
            EXP1 = ceil(EXP1 * 0.75);
            if (M1 < 0) M1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;

        }
        else {
            float P = (P1 + P2 + P3[i]) / 3;
            if (P < 0.5) {
                HP1 = ceil(HP1 * 0.85);
                EXP1 = ceil(EXP1 * 1.15);
                if (M1 < 0) M1 = 0;
                if (M1 > 3000) M1 = 3000;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
            else if (P>=0.5) {
                HP1 = ceil(HP1 * 0.9);
                EXP1 = ceil(EXP1 * 1.2);
                if (M1 < 0) M1 = 0;
                if (M1 > 3000) M1 = 3000;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
            }
        }
        return HP1 + EXP1 + M1;
        
       
        
    }
    else return -99;
}


// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3 >= 0 && E3 <= 99) {
        if (HP1 < 0) HP1 = 0;
        if (HP1 > 666) HP1 = 666;
        if (HP2 < 0) HP2 = 0;
        if (HP2 > 666) HP2 = 666;
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
        int diemtaxi[10][10];
        for (int i = 0;i < 10;i++) {
            for (int j = 0;j < 10;j++) {
                diemtaxi[i][j] = ((E3 * j) + (i *2)) * (i - j);
            }
        }
        
        int count1 = 0;
        int count2 = 0;
        for (int i = 0;i < 10;i++) {
            for (int j = 0;j < 10;j++) {
                if (diemtaxi[i][j] > E3 * 2) count1 = count1 + 1;
                if (diemtaxi[i][j] < E3 * (-1)) count2 = count2 + 1;
            }
        }
        int i = count1;
        int j = count2;
        while (i >= 10) i = i % 10 + i / 10;
        while (j >= 10) j = j % 10 + j / 10;
        int c= i;
        int b = j;
        int diemSherlock = diemtaxi[c][b];
        while (i >= 0 && i <10 && j >= 0 && j <10) {
            if (diemtaxi[i][j] >=diemSherlock) diemSherlock = diemtaxi[i][j];
            i += 1;
            j += 1;
        }
        i = c;
        j = b;
        while (i >= 0 && i <10 && j >= 0 && j <10){
            if (diemtaxi[i][j] >=diemSherlock) diemSherlock = diemtaxi[i][j];
            i += 1;
            j -= 1;
        }
        i = c;
        j = b;
        while (i >= 0 && i <10 && j >= 0 && j <10){
            if (diemtaxi[i][j] >=diemSherlock) diemSherlock = diemtaxi[i][j];
            i -= 1;
            j -= 1;
        }
        i = c;
        j = b;
        while (i >= 0 && i <=10 && j >= 0 && j <10){
            if (diemtaxi[i][j] >=diemSherlock) diemSherlock = diemtaxi[i][j];
            i -= 1;
            j += 1;
        }
       
        if (abs(diemtaxi[c][b])>diemSherlock) {
            EXP1 = ceil(EXP1 * 88.0 / 100);
            EXP2 = ceil(EXP2 * 88.0 / 100);
            HP1 = ceil(HP1 * 90.0 / 100);
            HP2 = ceil(HP2 * 90.0 / 100);
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (HP2 < 0) HP2 = 0;
            if (HP2 > 666) HP2 = 666;
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (EXP2 < 0) EXP2 = 0;
            if (EXP2 > 600) EXP2 = 600;
            return diemtaxi[c][b];
        }
        else {
            EXP1 = ceil(EXP1 * 112.0 / 100);
            EXP2 = ceil(EXP2 * 112.0 / 100);
            HP1 = ceil(HP1 * 110.0 / 100);
            HP2 = ceil(HP2 * 110.0 / 100);
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (HP2 < 0) HP2 = 0;
            if (HP2 > 666) HP2 = 666;
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (EXP2 < 0) EXP2 = 0;
            if (EXP2 > 600) EXP2 = 600;
            return diemSherlock;
        }
       

    }

    else
    return -99;
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char* se = new char[strlen(email) + 1];
    int a;
    for (int i = 0;i <strlen(email);i++) {
        se[i]=email[i];
        a = i + 1;
        if (email[i + 1] == '@') break;
    }
    se[a] = '\0';
    const char* pos = strstr(s, se);
    if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;
    else if (pos != nullptr) {
        int a = -(300 + pos - s );
        return a;
    }
    for (int i = 0;i <strlen(s);i++) {
        if (s[i] == s[i + 1] && s[i]==s[i+2]) {
            int b =-(400 + i);
            return b;
        }
    }
    int count = 0;
    int count2 = 0;
    for (int i = 0;i <strlen(s);i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '#' || s[i] == '!') {
            count = count + 1;
            
        }

    }
    if (count == 0) return -5;
    for (int i = 0;i < strlen(s);i++) {
        if (s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '(' || s[i] == ')' || s[i] == '-' || s[i] == '_' || s[i] == '=' || s[i] == '+' || s[i] == ',' || s[i] == '<' || s[i] == '.' || s[i] == '>') {
            count2 = i;

        }
    }
    if (count2 != 0) return count2;
    return -10;
    
        
    
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    struct password {
        int count = 0;
        int length;
        int temp = 0;
    };
    struct password pass[num_pwds];
    for (int i = 0; i < num_pwds;i++) {
        for (int j = 0;j < num_pwds;j++) {
            if (arr_pwds[i] == arr_pwds[j]) pass[i].count = pass[i].count + 1;
        }
        pass[i].length = strlen(arr_pwds[i]);
    }
    int max = 0;
    int max1 = 0;
    for (int i = 0; i < num_pwds;i++) {
        if (pass[i].count >= max) max = pass[i].count;
    }
    for (int i = 0; i < num_pwds;i++) {
        if (pass[i].count == max) pass[i].temp = 1;

    }
    for (int i = 0; i < num_pwds;i++) {
        if (pass[i].temp == 1 && pass[i].length >= max1) max1 = pass[i].length;
    }
    int a = 0;
    for (int i = 0; i < num_pwds;i++) {
        if (pass[i].temp == 1 && pass[i].length == max1) {
            a = i;
            break;
        }
    }
    return a;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////