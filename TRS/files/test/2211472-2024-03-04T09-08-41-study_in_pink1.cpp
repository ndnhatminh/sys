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


struct Algorithm{
    struct update {
        static void exp(int & exp) {if(exp > 600) exp = 600; else if(exp < 0) exp = 0;}

        static void hp(int & hp)   {if(hp > 666) hp = 666; else if(hp < 0) hp = 0;}

        static void m(int & m)     {if(m > 3000) m = 3000; else if(m < 0)  m = 0;}
    };

    struct road_2_event {
        static void food(int & HP1, int & M1, int & money) {
            if(M1 == 0) return;
            if(HP1 < 200) {
                HP1 = ceilf(float(HP1)*130/100);
                M1    -= 150;
                money += 150;
            }
            else {
                HP1 = ceilf(float(HP1)*110/100);
                M1    -= 70;
                money += 70;
            }

            Algorithm::update::hp(HP1);
            Algorithm::update::m(M1);
        }

        static void taxi(int & EXP1, int & M1, int & money) {
            if(M1 == 0) return;
            if(EXP1 < 400) {
                M1    -= 200;
                money += 200;
            }
            else {
                M1    -= 120;
                money += 120;
            }
            EXP1 = ceilf(float(EXP1)*113/100);

            Algorithm::update::exp(EXP1);
            Algorithm::update::m(M1);
        }

        static void homeless(int & EXP1, int & M1, int & money) {
            if(M1 == 0) return;
            if(EXP1 < 300) {
                M1    -= 100;
                money += 100;
            }
            else {
                M1     -= 120;
                money  += 120;
            }
            EXP1 = ceilf(float(EXP1)*90/100);

            Algorithm::update::exp(EXP1);
            Algorithm::update::m(M1);
        }
    };

    static float chinh_phuong(const int & EXP) {
        float P;
        if(int(sqrt(EXP)) == float(sqrt(EXP))) P = 100;
        else {
            float t1 = int(sqrt(EXP)), t2 = t1+1, t;
            if(((EXP-t1*t1) > (t2*t2-EXP))) t = t2*t2;
            else                            t = t1*t1;
            if(EXP >= t) P = 100;
            else P = ceilf((float(EXP)/t+80)/1.23);
        }

        return P;
    }

    static int length(const char* & s) {
        int count = 0;
        while(s[++count]!='\0');
        return count; 
    }

    static string se(const char * & email) {
        string output = "";
        for(int i=0; email[i] != '@'; i++) output += email[i];
        return output;
    }

    static int sherlock_and_waston_score(int a[10][10], const int & row, const int & col) {
        int target = a[row][col];
        int b1 = col - row;
        int b2 = row + col;

        for(int i=0; i < 10; i++)  {
            if(i-b1 > 0 && i-b1 < 10) {target = max(target, a[i][i-b1]);}
        }
        for(int j=0; j < 10;j++)  {
            if(-j+b2 < 10 && -j+b2 > 0) {target = max(target, a[-j+b2][j]);} 
        }
        
        return target;
    }
};


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1 < 0 || e1 > 99) return -99;

    // TODO: Complete this function
    if(e1 < 4) {
        switch (e1) {
            case 0: exp2+=29; break;
            case 1: exp2+=45; break;
            case 2: exp2+=75; break;
            case 3: exp2+=149; 
        }

        int D = e1*3 + exp1*7;
        if(D % 2 == 0) {
            exp1 = ceilf(exp1 + float(D)/200); 
        }
        else {
            exp1 = ceilf(exp1 - float(D)/100);
        }
        Algorithm::update::exp(exp1); 
        Algorithm::update::exp(exp2); 
    }
    else {
        if(e1<=19)      exp2 = ceilf(exp2 + float(e1)/4 + 19);  
        else if(e1<=49) exp2 = ceilf(exp2 + float(e1)/9 + 21);
        else if(e1<=65) exp2 = ceilf(exp2 + float(e1)/16 + 17);
        else if(e1<=79) {
            exp2 = ceilf(exp2 + float(e1)/4 + 19);

            if(exp2 > 200) exp2 = ceilf(exp2 + float(e1)/9 + 21);
        }
        else {
            exp2 = ceilf(exp2 + float(e1)/4 + 19);
            exp2 = ceilf(exp2 + float(e1)/9 + 21);

            if(exp2 > 400) {
                exp2 = ceilf(exp2 + float(e1)/16 + 17);
                exp2 = ceilf(float(exp2)*115/100);
            }
        }

        exp1 -= e1;
        Algorithm::update::exp(exp1); 
        Algorithm::update::exp(exp2); 
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2 < 0 || E2 > 99) return -99;

    // TODO: Complete this function
    float P1, P2, P3, p;

    P1 = Algorithm::chinh_phuong(EXP1);
 
    const int half = M1/2;
    int money = 0;
    if(E2 % 2 == 0) {
        Algorithm::road_2_event::food(HP1, M1, money);
        Algorithm::road_2_event::taxi(EXP1, M1, money);
        Algorithm::road_2_event::homeless(EXP1, M1, money);
    }
    else {
        while(1) {
            if(money <= half && M1 != 0) Algorithm::road_2_event::food(HP1, M1, money);
            else break;
            if(money <= half && M1 != 0) Algorithm::road_2_event::taxi(EXP1, M1, money);
            else break;
            if(money <= half && M1 != 0) Algorithm::road_2_event::homeless(EXP1, M1, money);
            else break;
        }
    }
    HP1  = ceilf(float(HP1)*83/100);
    EXP1 = ceilf(float(EXP1)*117/100);
    Algorithm::update::exp(EXP1);

    P2 = Algorithm::chinh_phuong(EXP1);

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2 < 10) P3 = P[E2];
    else {
        int t = E2;
        t = t%10 + t/10;
        P3 = P[t%10];
    }

    if(P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ceilf(float(EXP1)*75/100);
        return HP1 + EXP1 + M1;
    }
    p = (P1 + P2 + P3) / 3;

    if(p < 50) {
        HP1  = ceilf(float(HP1)*85/100);
        EXP1 = ceilf(float(EXP1)*115/100);
    }
    else {
        HP1  = ceilf(float(HP1)*90/100);
        EXP1 = ceilf(float(EXP1)*120/100);
    }

    Algorithm::update::hp(HP1);
    Algorithm::update::exp(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int & E3) {
    if(E3 < 0 || E3 > 99) return -99;

    // TODO: Complete this function
    int a[10][10];
    
    int t1 = 0;
    int t2 = 0;
    int result = 0;

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            a[i][j] = ((E3*j)+(i*2))*(i-j);
            if(a[i][j] > E3*2) t1++;
            if(a[i][j] < -E3)  t2++;
        }
    }
    
    while(t1 >= 10) t1 = t1%10 + t1/10;
    while(t2 >= 10) t2 = t2%10 + t2/10;

    int sherlock_and_waston_score = Algorithm::sherlock_and_waston_score(a,t1,t2);
    int taxi_score = abs(a[t1][t2]);

    if(taxi_score > sherlock_and_waston_score) {
        HP1 = ceilf(float(HP1)*90/100);
        HP2 = ceilf(float(HP2)*90/100);
        EXP1 = ceilf(float(EXP1)*88/100);
        EXP2 = ceilf(float(EXP2)*88/100);
        Algorithm::update::hp(HP1);
        Algorithm::update::hp(HP2);
        Algorithm::update::exp(EXP1);
        Algorithm::update::exp(EXP2);
        return a[t1][t2];
    }
    else {
        HP1 = ceilf(float(HP1)*110/100);
        HP2 = ceilf(float(HP2)*110/100);
        EXP1 = ceilf(float(EXP1)*112/100);
        EXP2 = ceilf(float(EXP2)*112/100);
        Algorithm::update::hp(HP1);
        Algorithm::update::hp(HP2);
        Algorithm::update::exp(EXP1);
        Algorithm::update::exp(EXP2);
        return sherlock_and_waston_score;
    }

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const int pass_length = Algorithm::length(s);
    if(pass_length < 8)  return -1;
    if(pass_length > 20) return -2;
    if(email[0] == '@' ) return -300;

    string se = Algorithm::se(email);
    bool spec = 0;
    int thu_tu = -1;
    for(int i=0; i<pass_length; i++) {
        if(se[0]==s[i]) {
            int index = i;
            while(index-i < se.length() && se[index-i] == s[index]) index++;
            if(index-i == se.length()) return -(300+i);
        }
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') spec = 1; 
        else {
            if(thu_tu == -1) {
                if(!(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9'))) thu_tu = i;
            }
        }
    }

    for(int i=0; i<pass_length; i++) {
        int j=i+1;
        while(j<pass_length && s[j] == s[i]) j++;
        if(j-i > 2) return -(400+i);
    }

    if(!spec) return -5;
    return thu_tu != -1 ? thu_tu : -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count = 0;
    pair<string, int>* Arr = new pair<string, int>[num_pwds];

    for(int i=0; i<num_pwds; i++) {
        bool found = 0;
        for(int j=0; j<=count; j++) {
            if(Arr[j].first==arr_pwds[i]) {Arr[j].second++; found = 1; break;}
        }
        if(!found) Arr[count++] = make_pair(arr_pwds[i], 1);
    }

    for(int i=1; i<count; i++) {
        for(int j=i; j>0; j--) {
            if(Arr[j].second > Arr[j-1].second) swap(Arr[j], Arr[j-1]);
            else break;
        }
    }

    string target = Arr[0].first;
    for(int i=1; i<count; i++) {
        if(Arr[i].second != Arr[0].second) break;
        if(Arr[i].first.length() > int(target.length())) target = Arr[i].first;
    }

    for(int i=0; i<num_pwds; i++) {
        if(arr_pwds[i] == target) return i;
    }
    delete[] Arr;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////