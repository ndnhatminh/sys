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
void update(int &n, float newN, int maxN)
{
    if (newN > maxN)
        n = maxN;
    else if (newN < 0)
        n = 0;
    else
        n = ceil(newN);
}
#define MAX_EXP 600
#define MAX_HP 666
#define MAX_M 3000

int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 >= 0 && e1 <= 3)
    { // case1
        int E1[4] = {29, 45, 75, 149};
        exp2 += E1[e1];
        exp2 = exp2 > 600 ? 600 : exp2;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            update(exp1, exp1 + D / 200.0f, MAX_EXP);
        else
            update(exp1, exp1 - D / 100.0f, MAX_EXP);
    }
    else if (e1 > 3 && e1 < 100)
    { //case2
        if (e1 < 20)
            update(exp2, exp2 + e1 / 4.0f + 19, MAX_EXP);
        else if (e1 < 50)
            update(exp2, exp2 + e1 / 9.0f + 21, MAX_EXP);
        else if (e1 < 66)
            update(exp2, exp2 + e1 / 16.0f + 17, MAX_EXP);
        else if (e1 < 80)
        {

            update(exp2, exp2 + e1 / 4.0f + 19, MAX_EXP);
            if (exp2 > 200)
                update(exp2, exp2 + e1 / 9.0f + 21, MAX_EXP);
        }
        else
        {
            update(exp2, exp2 + e1 / 4.0f + 19, MAX_EXP);
            update(exp2, exp2 + e1 / 9.0f + 21, MAX_EXP);
            if (exp2 > 400)
            {
                update(exp2, exp2 + e1 / 16.0f + 17, MAX_EXP);
                update(exp2, exp2 * 1.15f, MAX_EXP);
            }
        }
        exp1 -= e1;
        exp1 = exp1 < 0 ? 0 : exp1;
    }
    else
        return -99; 
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
// TODO: Complete this function
    if (E2 > 99 || E2 < 0)
        return -99;
    double P1,P2,P3; 
    //road 1
    int S,c,d,e;
    c = round(sqrt(double(EXP1)));
    d = EXP1 - c*c; e = (c+1)*(c+1) - EXP1;

    if(d<e) S = c*c;
    else S = (c+1)*(c+1);

    if (EXP1 >= S) P1 = 100;
    else P1 = (double(EXP1)/S + 80)/1.23;

    //road 2
    if( E2%2 != 0){
        int a = M1;
        int m =0; 
        while(true){
           
            if(HP1 < 200) 
            {
                if(M1 > 150) {M1 -=150; HP1 = ceil(double(HP1)*13/10); m += 150;}
                else {M1 = 0; HP1 = ceil(double(HP1)*13/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            else 
            {
                if(M1>70) {M1 -= 70; HP1 = ceil(double(HP1)*11/10); m+= 70;}
                else {M1 = 0; HP1 = ceil(double(HP1)*11/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
            if(m>ceil(double(a)/2)) break;
            
            if(EXP1 < 400)
            {
                if(M1 > 200){M1 -= 200; EXP1 = ceil(double(EXP1)*11.3/10); m += 200;}
                else {M1 = 0; EXP1 = ceil(double(EXP1)*11.3/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            else 
            {
                if(M1 >120) {M1 -= 120; EXP1 = ceil(double(EXP1)*11.3/10); m+=120;}
                else {M1=0; EXP1 = ceil(double(EXP1)*11.3/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
            if(m>ceil(double(a)/2)) break;
            

            if(EXP1 <300)
            {
                if(M1 > 100){M1 -= 100; EXP1 = ceil(double(EXP1)*9/10); m+=100; }
                else {M1 = 0; EXP1 = ceil(double(EXP1)*9/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            else
            {
                if(M1>120){M1 -= 120; EXP1 = ceil(double(EXP1)*9/10); m+= 120;}
                else {M1=0; EXP1 = ceil(double(EXP1)*9/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
            if(m>ceil(double(a)/2)) break;
        }
        HP1 = ceil(double(HP1)*8.3/10); EXP1 = ceil(double(EXP1)*11.7/10);
    }
    else
    {
        for(int i = 0; i < 1; i++){
            if(HP1 < 200) 
            {
                if(M1 > 150) {M1 -=150; HP1 = ceil(double(HP1)*13/10);}
                else {M1 = 0; HP1 = ceil(double(HP1)*13/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            else 
            {
                if(M1>70) {M1 -= 70; HP1 = ceil(double(HP1)*11/10); }
                else {M1 = 0; HP1 = ceil(double(HP1)*11/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
            if(EXP1 < 400)
            {
                if(M1 > 200){M1 -= 200;  EXP1 = ceil(double(EXP1)*11.3/10);}
                else {M1 = 0; EXP1 = ceil(double(EXP1)*11.3/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            else 
            {
                if(M1 >120) {M1 -= 120; EXP1 = ceil(double(EXP1)*11.3/10);}
                else {M1=0; EXP1 = ceil(double(EXP1)*11.3/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;

            if(EXP1 <300)
            {
                if(M1 > 100){M1 -= 100; EXP1 = ceil(double(EXP1)*9/10); }
                else {M1 = 0; EXP1 = ceil(double(EXP1)*9/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            else
            {
                if(M1>120){M1 -= 120; EXP1 = ceil(double(EXP1)*9/10);}
                else {M1=0; EXP1 = ceil(double(EXP1)*9/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
        }
        HP1 = ceil(double(HP1)*8.3/10); EXP1 = ceil(double(EXP1)*11.7/10);
    }
    if(EXP1 > 600) EXP1 = 600;
    if(EXP1 < 0) EXP1 = 0; 
    if(HP1 > 666) HP1 = 666;
    if(HP1 < 0) HP1 = 0;
    if(M1 > 3000) M1 = 0;
    if(M1 < 0) M1 = 0;

    int c2,d2,e2,S2;
    c2 = round(sqrt(double(EXP1)));
    d2 = EXP1 - c2*c2; e2 = (c2+1)*(c2+1) - EXP1;
    if(d2<e2) S2 = c2*c2;
    else S2 = (c2+1)*(c2+1);

    if (EXP1 >= S2) P2 = 100;
    else P2 = (double(EXP1)/S2 + 80)/1.23;

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if(E2 < 10) { i = E2;}
    else { i = (E2/10 + E2%10)%10; }
    P3 = P[i];

    if(P1 == 100 && P2 == 100 && P3 == 100) { EXP1 = ceil(double(EXP1)*7.5/10);}
    else
    {
        double Pave = (P1 + P2 + P3)/3;
        if(Pave < 50) { HP1 = ceil(double(HP1)*8.5/10); EXP1 = ceil(double(EXP1)*11.5/10); }
        else { HP1 = ceil(double(HP1)*9/10); EXP1 = ceil(double(EXP1)*12/10); }
    }
    if(EXP1 > 600) EXP1 = 600;
    if(EXP1 < 0) EXP1 = 0; 
    if(HP1 > 666) HP1 = 666;
    if(HP1 < 0) HP1 = 0;
    if(M1 > 3000) M1 = 0;
    if(M1 < 0) M1 = 0;
    return HP1 + EXP1 + M1;
}

// Task 3 
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if (E3 < 0 || E3 > 99) {
        return -99;
    }

    //TODO: implement task
    int Map[10][10] = {0};

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            Map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            
        }
        
    }

    int i_count = 0, j_count = 0;
    int location[2] = {0, 0};
    int grade = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (Map[i][j] > E3 * 2)
                i_count++;
            if (Map[i][j] < -E3)
                j_count++;
        }
    }

    while (i_count >= 10) {
        i_count = i_count / 10 + i_count % 10;
    }
    while (j_count >= 10) {
        j_count = j_count / 10 + j_count % 10;
    }
    location[0] = i_count;
    location[1] = j_count;

    grade = Map[location[0]][location[1]];

     int sherwatson_scores[10][10] = {0};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int left_diag_value = 0, right_diag_value = 0;
            int r = i, c = j;
            while (r < 10 && c >= 0) {
                left_diag_value = max(left_diag_value, Map[r][c]);
                r++;
                c--;
            }
            r = i, c = j;
            while (r < 10 && c < 10) {
                right_diag_value = max(right_diag_value, Map[r][c]);
                r++;
                c++;
            }
            sherwatson_scores[i][j] = max(left_diag_value, right_diag_value);
            if (sherwatson_scores[i][j] < 0)
                sherwatson_scores[i][j] = abs(sherwatson_scores[i][j]);
                
        }
        
    }

    int sherwatson_grade = sherwatson_scores[location[0]][location[1]];
    
    if (abs(grade) > sherwatson_grade) {
         EXP1 -= floor((double)EXP1 * 0.12); 
       HP1 -= floor((double)HP1 * 0.1); 
       EXP2 -= floor((double)EXP2 * 0.12); 
        HP2 -= floor((double)HP2 * 0.1); 
    } else {
        EXP1 += ceil((double)EXP1 * 0.12); 
       HP1 += ceil((double)HP1 * 0.1); 
       EXP2 += ceil((double)EXP2 * 0.12); 
        HP2 += ceil((double)HP2 * 0.1); 
    }
 if (EXP1 < 0) EXP1 = 0;
            else if (EXP1 > 600) EXP1 = 600;
            if (EXP2 < 0) EXP2 = 0;
            else if (EXP2 > 600) EXP2 = 600;
    if (abs(grade) > sherwatson_grade)
    
        return grade;
    else
        return sherwatson_grade;

    
}

// Task 4
bool containsSpecialCharacter(char ch) {
    const char specialChars[] = "@#$!";
    for (char specialChar : specialChars) {
        if (ch == specialChar) {
            return true;
        }
    }
    return false;
}

int checkPassword(const char* s, const char* email) {
    const char* se = strstr(email, "@");
    if (!se) {
        return -1; 
    }

    int passwordLength = strlen(s);
    if (passwordLength < 8) {
        return -1; 
    }
    if (passwordLength > 20) {
        return -2; 
    }

    for (int i = 0; i < passwordLength; ++i) {
        char ch = s[i];
        if (!isalnum(ch) && !containsSpecialCharacter(ch) && ch != ' ') {
            return -5;
        }
    }

    if (strstr(s, "se")) {
        return -(300 + (int)(strstr(s, "se") - s));
    }

    for (int i = 0; i < passwordLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); 
        }
    }

    bool hasSpecialChar = false;
    for (int i = 0; i < passwordLength; ++i) {
        if (containsSpecialCharacter(s[i])) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        return -5;
    }

    return -10; 
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
     const int max_password = 30;
    std::string passwords[max_password];
    int f[max_password] = {0};

    for (int i = 0; i < num_pwds; ++i) {
        int j;
        for (j = 0; j < max_password; ++j) {
            if (arr_pwds[i] == passwords[j]) {
                f[j]++;
                break;
            } else if (passwords[j].empty()) {
                passwords[j] = arr_pwds[i];
                f[j]++;
                break;
            }
        }
    }

    int maxFreq = 0;
    std::string mostFrequentpassword;
    for (int i = 0; i < max_password; ++i) {
        if (!passwords[i].empty() && f[i] > maxFreq) {
            maxFreq = f[i];
            mostFrequentpassword = passwords[i];
        } else if (!passwords[i].empty() && f[i] == maxFreq && passwords[i].length() > mostFrequentpassword.length()) {
            mostFrequentpassword = passwords[i];
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == mostFrequentpassword) {
            return i; 
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////