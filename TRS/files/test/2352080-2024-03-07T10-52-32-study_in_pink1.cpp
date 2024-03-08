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
void check_exp(int & exp1, int & exp2){
    if (exp1 > 600)
    {
        exp1 = 600;}
        else if (exp1 < 0)
        {
            exp1 = 0;
        }
    if (exp2 > 600)
    {
        exp2 = 600;}
        else if (exp2 < 0)
        {
            exp2 = 0;
        }   
}

void check_m(int & m1, int & m2){
    if (m1 > 3000)
    {
        m1 = 3000;}
        else if (m1 < 0)
        {
            m1 = 0;
        }
    if (m2 > 3000)
    {
        m2 = 3000;}
        else if (m2 < 0)
        {
            m2 = 0;
        }
}

void check_hp(int & hp1, int & hp2){
    if (hp1 > 666)
    {
        hp1 = 666;}
        else if (hp1 < 0)
        {
            hp1 = 0;
        }
    if (hp2 > 666)
    {
        hp2 = 666;}
        else if (hp2 < 0)
        {
            hp1 = 0;
        }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Case 1
    if (e1 < 0 || e1 > 99) return -99;
    switch (e1)
    {
    case 0:
        exp2 += 29;
        break;
    case 1:
        exp2 += 45;
        break;
    case 2:
        exp2 += 75;
        break;
    case 3: 
        exp2 += 149;
        break;
    } 
    int d = e1 * 3 + exp1 * 7;
    if (e1 >= 0 and e1 <= 3)
    {
        if (d % 2 == 0)
    {
        float k = exp1*1.0 + d*1.0/200;
        exp1 = ceil (k);}
        else
        {float k = exp1*1.0 - d*1.0/100;
        exp1 = ceil (k);}
    }
    // Case 2
    float a;
    if (e1 >= 4 and e1 <= 19)
    {
        a = exp2 + e1*1.0/4 + 19;
        exp2 = ceil(a);}
        else if (e1 >= 20 and e1 <= 49)
        {
            a = exp2 + e1*1.0/9 + 21;
            exp2 = ceil(a);
        }
        else if (e1 >= 50 and e1 <= 65)
        {
            a = exp2 + e1*1.0/16 +17;
            exp2 = ceil(a);
        }
        else if (e1 >= 66 and e1 <= 79)
        {
            a = exp2 + e1*1.0/4 + 19;
            exp2 = ceil(a);
            if (exp2 > 200)
            {
                a = exp2 + e1*1.0/9 + 21;
                exp2 = ceil(a);
            } 
        }
        else if(e1 >= 80 and e1 <= 99)
        {
            float aa = exp2 + e1/4.0 + 19;
            exp2 = ceil(aa);
            float ab;
            ab = exp2 + e1/9.0 + 21;
            exp2 = ceil(ab);
            if (exp2 > 400)
            {
        	    float ac, ad;
                ac = exp2 + e1/16.0 + 17;
                exp2 = ceil(ac);
                ad = exp2 + 0.15*exp2;
                exp2 = ceil(ad);
            }}
    if (e1 >= 4 and e1 <= 99)
    {
        exp1 -= e1;
    }
    // Check EXP
    check_exp(exp1,exp2);
    return exp1 + exp2;
    }  

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Road 1
    if (E2 < 0 || E2 > 99) return -99;
    double p1;
    double c = sqrt (EXP1);
    int s = c;
    if (s*s == EXP1)
        {s = EXP1;}
        else if (EXP1 - s*s > (s+1)*(s+1) - EXP1)
            {s = (s+1)*(s+1);}
            else 
                {s = s*s;}
    if (EXP1 >= s)
    {
        p1 = 100;
    }
    else {p1 = ((EXP1*1.0/s)+80)*100/123;}
    // Road 2
    // ...
    int med, M01 = M1, EXP2, M2, M11 = 0, HP2;
    int i = 1; 
    if ((E2 % 2) != 0){       
    // Event 1
        do { if (HP1 < 200){
                float a = 1.3*HP1;
                HP1 = ceil (a);
                M1 -= 150;
                M11 += 150;
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            else {
                float a = 1.1*HP1;
                HP1 = ceil (a);
                M1 -= 70;
                M11 += 70;
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            if (M11 > (M01/2)) break;
    // Event 2
            if (EXP1 < 400){
                M1 -= 200;
                M11 += 200;
                double b = 1.13*EXP1*1.0;
                EXP1 = ceil (b);
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            else {M1 -= 120;
                M11 += 120;
                double b = 1.13*EXP1*1.0;
                EXP1 = ceil (b);
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            if (M11 > (M01/2)) break;
    //Event 3
            if (EXP1 < 300){
                M1 -= 100;
                M11 += 100;
                float b = 0.9*EXP1;
                EXP1 = ceil(b);
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            else{
                M1 -= 120;
                M11 += 120;
                float b = 0.9*EXP1;
                EXP1 = ceil(b);
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            if (M11 > (M01/2)) break;}
            while (M11 < (M01/2));
            }
        if (E2 % 2 == 0){   
            do {i++;
                if (HP1 < 200){
                float a = 1.3*HP1;
                HP1 = ceil (a);
                M1 -= 150;
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            else {
                float a = 1.1*HP1;
                HP1 = ceil (a);
                M1 -= 70;
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
                if (M1 <=0)
                {
                    break;
                }               
    // Event 2
            if (EXP1 < 400){
                M1 -= 200;
                float b = 1.13*EXP1;
                EXP1 = ceil (b);
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            else {M1 -= 120;
                float b = 1.13*EXP1;
                EXP1 = ceil (b);
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            if (M1 <=0)
                {
                    break;
                }
    //Event 3
            if (EXP1 < 300){
                M1 -= 100;
                float b = 0.9*EXP1;
                EXP1 = ceil (b);
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            else{
                M1 -= 120;
                float b = 0.9*EXP1;
                EXP1 = ceil (b);
                check_exp (EXP1, EXP2);
                check_hp (HP1, HP2);
                check_m (M1, M2);}
            if (M1 <=0)
                {
                    break;
                }}
                while (i < 0);
                }
    
    float a = 0.83*HP1;
    HP1 = ceil (a);
    float b = 1.17*EXP1;
    EXP1 = ceil (b);
    check_exp (EXP1, EXP2);
    check_hp (HP1, HP2);
    check_m (M1, M2);
    float p2;
    double g = sqrt (EXP1);
    int h = floor (g);
    if (h*h == EXP1)
        {h = EXP1;}
        else if (EXP1 - h*h > (h+1)*(h+1) - EXP1)
            {h = (h+1)*(h+1);}
            else 
                {h = h*h;}
    if (EXP1 >= h)
    {
        p2 = 100;
    }
    else {p2 = ((EXP1*1.0/h)+80)*100/123;}
    // Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;
    if (E2 >= 0 and E2 < 10)
    {
        P3 = P[E2]; 
    }
        else if (E2 >= 10)
        {
            int a;
            a = (E2/10 + E2%10)%10;
            P3 = P[a];
        }
    float ap = (p1+p2+P3)/3;
    if (p1 == 100 and p2 == 100 and P3 == 100)
    {
        float a = 0.75*EXP1;
        EXP1 = ceil (a);
        check_exp (EXP1, EXP2);
        check_hp (HP1, HP2);
        check_m (M1, M2);
    }
        else if (ap < 50)
        {
            float a = 0.85*HP1;
            HP1 = ceil (a);
            float b = 1.15*EXP1;
            EXP1 = ceil (b);
            check_exp (EXP1, EXP2);
            check_hp (HP1, HP2);
            check_m (M1, M2);
        }
            else{
                float a = HP1*0.9;
                HP1 = ceil (a);
                float b = EXP1*1.2;
                EXP1 = ceil (b);
            check_exp (EXP1, EXP2);
            check_hp (HP1, HP2);
            check_m (M1, M2);
            }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 or E3 > 99) return -99;
    check_exp(EXP1,EXP2);
    check_hp(HP1,HP2);
    int a[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int o = 0; o < 10; o++)
        {
            a[i][o] = ((E3 * o) + (i * 2)) * (i - o);
        }  
    }
    int b = 0 ,c = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int o = 0; o < 10; o++)
        {
            if (a[i][o] > (E3*2))
            {
                b++;
            }
            if (a[i][o] < -E3)
            {
                c++;
            }
        }
    }
    int b_, c_, taxi, sher;
    b_ = (b/10)+(b%10);
    if (b_ >= 10)
    {
        b_ = (b_/10)+(b_%10);
    }
    c_ = (c/10)+(c%10);
    if (c_ >= 10)
    {
        c_ = (c_/10)+(c_%10);
    }
    taxi = a[b_][c_];
    sher = taxi;
    for (int i = 0; i < 10; i++)
    {
        if ((c_ - b_ + i) < 0 or (c_ - b_ + i) >= 10)
        {
            break;
        }
        if (a[i][c_ - b_ + i] > sher)
        {
            sher = a[i][c_ - b_ + i];
        }  
    }
    for (int i = 0; i < 10; i++)
    {
        if ((c_ + b_ - i) < 0 or (c_ + b_ - i) >= 10)
        {
            continue;
        }
        if (a[i][c_ + b_ - i] > sher)
        {
            sher = a[i][c_ + b_ - i];
        }  
    }
    int result;
    if (abs(taxi) > sher)
    {
        result = taxi;
        EXP1 = ceil(EXP1*88.0/100);
        EXP2 = ceil(EXP2*88.0/100);
        HP1 = ceil(HP1*90.0/100);
        HP2 = ceil(HP2*90.0/100);
    }
    if (abs(taxi) <= sher)
    {
        result = sher;
        EXP1 = ceil(EXP1*112.0/100);
        EXP2 = ceil(EXP2*112.0/100);
        HP1 = ceil(HP1*110.0/100);
        HP2 = ceil(HP2*110.0/100);
    }
    check_exp(EXP1,EXP2);
    check_hp(HP1,HP2);
    return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se, email_, s_;
    email_ = email;
    s_ = s;
    int a = s_.length();
    if (a < 8) return -1;
    if (a > 20) return -2;
    int b = email_.find("@");
    se = email_.substr(0,b);
    int c = s_.find(se);
    if (c >= 0) return -(300 + c);
    for (int i = 0; i < a; i++){
        if (s_[i] == s_[i + 1] and s_[i + 1] == s_[i + 2]){
            return -(400+i);}}
    int d = 0;
    for (int i = 0; i < a; i++)
    {
        if (s_[i]=='@' or s_[i]=='#' or s_[i]=='%' or s_[i]=='$' or s_[i]=='!') {
            d++;}}
    if (d == 0) return -5;
    char c1 {92};
    char c2 {39};
    for (int i = 0; i < a; i++){
        if (s_[i]=='^' or s_[i]=='&' or s_[i]=='*' or s_[i]=='(' or s_[i]==')' or s_[i]=='-' or s_[i]=='_' or s_[i]=='+' or s_[i]=='=' or s_[i]=='~' or s_[i]=='`' or s_[i]=='[' or s_[i]==']' or s_[i]=='{' or s_[i]=='}' or s_[i]=='|' or s_[i]==';' or s_[i]==':' or s_[i]=='"' or s_[i]== ',' or s_[i]=='<' or s_[i]=='.' or s_[i]=='>' or s_[i]=='/' or s_[i]=='?' or s_[i]==c1 or s_[i]==c2)
            return i;}
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int b = 0, i_;
    for (int i = 0; i < num_pwds; i++)
    {
        int a = 1;
        for (int o = i + 1; o < num_pwds; o++)
        {
            if (strcmp (arr_pwds[i],arr_pwds[o]) == 0)
            {
                ++a;}}
        if (a > b)
        {
            b = a;
            i_ = i;
        }
        else if ( a == b)
        {
            string c = arr_pwds[i_];
            string d = arr_pwds[i];
            int c1 = c.length();
            int d1 = d.length();
            if (c1 < d1)
            {
                i_ = i;
            }
        }
    } 
    return i_;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////