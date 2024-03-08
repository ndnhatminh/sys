#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
void roundhp(int &a) {
    if (a > 666) a = 666;
    else if (a < 0) a = 0;
}
void roundexp(int &b) {
    if (b > 600) b = 600;
    else if (b < 0) b = 0;
}
void roundm(int &c) {
    if (c > 3000) c = 3000;
    else if (c < 0) c = 0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //Case1
    if (e1 >= 0 && e1 <= 3) {
        int d;
        //exp2
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 += (75 + 45 + 29);
        roundexp(exp2);
        //exp1
        d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) exp1 += d / 200;
        else exp1 = ceil(double(exp1) - double(d) / 100);
        roundexp(exp1);
        return exp1 + exp2;
    }
    //Case2
    //4-19
    else if (e1 >= 4 && e1 <= 19) {
        exp2 = ceil(exp2 + double(e1) / 4 + 19);
        roundexp(exp2);
        exp1 -= e1;
        roundexp(exp1);
        return exp1 + exp2;
    }
    //20-49
    else if (e1 >= 20 && e1 <= 49) {
        exp2 = exp2 + ceil(double(e1) / 9 + 21);
        roundexp(exp2);
        exp1 -= e1;
        roundexp(exp1);
        return exp1 + exp2;
    }
    //50-65
    else if (e1 >= 50 && e1 <= 65) {
        exp2 = exp2 + ceil(double(e1) / 16 + 17);
        roundexp(exp2);
        exp1 -= e1;
        roundexp(exp1);
        return exp1 + exp2;
    }
    //66-79
    else if (e1 >= 66 && e1 <= 79) {
        exp2 = ceil(exp2 + double(e1) / 4 + 19);
        roundexp(exp2);
        if (exp2 > 200) exp2 = exp2 + ceil(double(e1) / 9 + 21);
        roundexp(exp2);
        exp1 -= e1;
        roundexp(exp1);
        return exp1 + exp2;
    }
    //80-99
    else if (e1 >= 80 && e1 <= 99) {
        exp2 = ceil(exp2 + double(e1) / 4 + 19);
        roundexp(exp2);
        exp2 = exp2 + ceil(double(e1) / 9 + 21);
        roundexp(exp2);
        if (exp2 > 400) {
            exp2 = exp2 + ceil(double(e1) / 16 + 17);
            roundexp(exp2);
            exp2 = ceil(double(exp2) * 1.15);
            roundexp(exp2);
            exp1 -= e1;
            roundexp(exp1);
        }
        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
int csp(int d) {
    d = round(sqrt(d)) * round(sqrt(d));
    return d;
}
//
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //Road1
    double p1, p2;
    if (csp(EXP1) > EXP1) p1 = (double(EXP1) / double(csp(EXP1)) + 80) / 123;
    else if (csp(EXP1) <= EXP1) p1 = 1;
    //
    int m = 0;
    if (E2 >= 0 && E2 <=99) {
        if (E2 % 2 == 1) {
            const double h = double(M1) / 2;
            while (1) { //while(true)
                //event1
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    roundhp(HP1);
                    M1 -= 150;
                    roundm(M1);
                    m += 150;
                }
                else if (HP1 >= 200) {
                    HP1 = ceil(HP1 * 1.1);
                    roundhp(HP1);
                    M1 -= 70;
                    roundm(M1);
                    m += 70;
                }
                if (m > h) break; //condition
                //event2
                if (EXP1 < 400) {
                    M1 -= 200;
                    roundm(M1);
                    EXP1 = ceil(EXP1 * 1.13);
                    roundexp(EXP1);
                    m += 200;
                }
                else if (EXP1 >= 400) {
                    M1 -= 120;
                    roundm(M1);
                    EXP1 = ceil(EXP1 * 1.13);
                    roundexp(EXP1);
                    m += 120;
                }
                if (m > h) break; //condition
                //event3
                if (EXP1 < 300) {
                    M1 -= 100;
                    roundm(M1);
                    EXP1 = ceil(EXP1 * 0.9);
                    roundexp(EXP1);
                    m += 100;
                }
                else if (EXP1 >= 300) {
                    M1 -= 120;
                    roundm(M1);
                    EXP1 = ceil(EXP1 * 0.9);
                    roundexp(EXP1);
                    m += 120;
                }
                if (m > h) break; //condition
            }
            HP1 = ceil(HP1 * 0.83);
            roundhp(HP1);
            EXP1 = ceil(EXP1 * 1.17);
            //roundexp(EXP1);
        }
        //E2 Even
        else if (E2 % 2 == 0) {
            while (1) {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    roundhp(HP1);
                    M1 -= 150;
                    roundm(M1);
                }
                else if (HP1 >= 200) {
                    HP1 = ceil(HP1 * 1.1);
                    roundhp(HP1);
                    M1 -= 70;
                    roundm(M1);
                }
                if (M1 == 0) break;
                if (EXP1 < 400) {
                    M1 -= 200;
                    roundm(M1);
                    EXP1 = ceil(HP1 * 1.13);
                    roundexp(EXP1);
                }
                else if (EXP1 >= 400) {
                    M1 -= 120;
                    roundm(M1);
                    EXP1 = ceil(HP1 * 1.13);
                    roundexp(EXP1);
                }
                if (M1 == 0) break;
                if (EXP1 < 300) {
                    M1 -= 100;
                    roundm(M1);
                    EXP1 = ceil(HP1 * 0.9);
                    roundexp(EXP1);
                }
                else if (EXP1 >= 300) {
                    M1 -= 120;
                    roundm(M1);
                    EXP1 = ceil(HP1 * 0.9);
                    roundexp(EXP1);
                }
                break;
            }
        }
        if (csp(EXP1) > EXP1) p2 = (double(EXP1) / double(csp(EXP1)) + 80) / 123;
        else if (csp(EXP1) <= EXP1) p2 = 1;
        //Road3
        double P[] = { 32,47,28,79,100,50,22,83,64,11 };
        int i;
        if (E2 - E2 % 10 == 0) i = E2;
        else i = ((E2 % 10) + (E2 - E2 % 10) / 10) % 10;
        if (p1 == p2 && p1 == (P[i] / 100) && p1 == 1) {
            EXP1 = ceil(EXP1 * 0.75);
            roundexp(EXP1);
        }
        else if ((p1 + p2 + P[i] / 100) / 3 < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            roundhp(HP1);
            EXP1 = ceil(EXP1 * 1.15);
            roundexp(EXP1);
        }
        else if ((p1 + p2 + P[i] / 100) / 3 >= 0.5 && (p1 + p2 + P[i] / 100) / 3 < 1) {
            HP1 = ceil(HP1 * 0.9);
            roundhp(HP1);
            EXP1 = ceil(EXP1 * 1.2);
            roundexp(EXP1);
        }
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int mx[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            mx[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            mx[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int x=0;
    int y=0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (mx[i][j] > (E3 * 2)) x += 1;
            else if (mx[i][j] < -E3) y += 1;
        }
    }
    //tim vi tri gap nhau
    while (x > 9) {
        x = (x - x % 10) / 10 + x % 10;
    }
    while (y > 9) {
        y = (y - y % 10) / 10 + y % 10;
    }
    //duong cheo trai   
    int a = x;
    int b = y;
    int c = x;
    int d = y;
    int max = mx[x][y];
    while (a > 0 && b > 0) {
        a -= 1;
        b -= 1;
    }
    while (c < 9 && d < 9) {
        c += 1;
        d += 1;
    }
    while (a <= c && b <= d) {
        if (mx[a][b] >= max) max = mx[a][b];
        else max = max;
        a += 1;
        b += 1;
    }
    //duong cheo phai
    a = x;
    b = y;
    c = x;
    d = y;
    while (a > 0 && b < 9) {
        a -= 1;
        b += 1;
    }
    while (c < 9 && d > 0) {
        c += 1;
        d -= 1;
    }
    while (a <= c && b >= d) {
        if (mx[a][b] >= max) max = mx[a][b];
        else max = max;
        a += 1;
        b -= 1;
    }
    if (abs(mx[x][y]) > max) {
        EXP1 = ceil(double(EXP1)*0.88);
        HP1 = ceil(double(HP1)*0.9);
        EXP2 = ceil(double(EXP2)*0.88);
        HP2 = ceil(double(HP2)*0.9);
        return mx[x][y];
    }
    else {
        EXP1 = ceil(double(EXP1)*1.12);
        HP1 = ceil(double(HP1)*1.1);
        EXP2 = ceil(double(EXP2)*1.12);
        HP2 = ceil(double(HP2)*1.1);
        return max;
    }        
    return -1;
}


//check for task 4(//4)
int check(string s1, string s2){
    if (s2.find(s1) != string::npos){
        return s2.find(s1);
    }
    else return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se(""); 
    for (int i = 0; i <= strlen(email); i++) {
        se += email[i];
        if (email[i + 1] == '@') break;
    }
 //password
    //special character
    bool sch = false;
    for (int i = 0; i <= strlen(s); i++) {
        if (s[i] == '!') {
            sch = true;
        }
        else if (s[i] == '@') {
            sch = true;
        }
        else if (s[i] == '#') {
            sch = true;
        }
        else if (s[i] == '$') {
            sch = true;
        }
        else if (s[i] == '%') {
            sch = true;
        }
    }
    //repeat
    bool repeat = false;
    int j = 0;
    for (j; j < strlen(s); j++) {
        if (s[j] == s[j + 1] && s[j] == s[j + 2]) {
            repeat = true;
            break;
        }
    }
//conditions
    if (strlen(s) >= 8 && strlen(s) <= 20 && check(se, s) == -1 && sch == true && repeat == false) return -10;
    else if (strlen(s) < 8) return -1;     //2
    else if (strlen(s) > 20) return -2;  //3
    else if (check(se, s) != -1) return -(300 + check(se, s));//4
    else if (repeat == true) return -(400 + j); //5
    else if (sch == false) return -5;  //6
    return -99;
}
// Task 5
//find the most frequent element
const char* findmost(const char* arr[], int n) {
    int max = 0;
    const char* most=NULL;

    for (int i = 0; i < n; ++i) {
        int freq = 1;
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                freq++;
            }
        }

        if (freq > max) {
            max = freq;
            most = arr[i];
        }
        else if (freq == max) {
            if (strlen(arr[i]) > strlen(most)) most = arr[i];
            else most = most;
        }
    }
    return most;
}

//find the first position
int first(const char* arr[], int n,const char* target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
//
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const char* mostFrequent = findmost(arr_pwds, num_pwds);
    int f = first(arr_pwds, num_pwds, mostFrequent);
    return f;  
    return -1;  
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////