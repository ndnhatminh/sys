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

void resethp(float & hp)
{
    if (hp > 666) {
        hp = 666;
    }
    else if (hp < 0) {
        hp = 0;
    }
}

void resetexp(float & exp)
{
    if (exp > 600) {
        exp = 600;
    }
    else if (exp < 0) {
        exp = 0;
    }
}

void resetmoney(float & m)
{
    if (m > 3000) {
        m = 3000;
    }
    else if (m < 0) {
        m = 0;
    }
}

int sum(int n)
{
    if (n/10 == 0) {
        return n;
    }
    else {
        while (n/10 != 0) {
            n = n/10+n%10;
        }
        return n;
    }
}

bool lengthcheck1(string s)
{
    if (s.length() < 8) {
        return true;
    }
    return false;
}

bool lengthcheck2(string s)
{
    if (s.length() > 20) {
        return true;
    }
    return false;
}

bool secheck(string s, string se, size_t & sei)
{
    if (s.find(se) != string::npos) {
        sei = s.find(se);
        return true;
    }
    return false;
}

bool ltcheck(string s, size_t & sci)
{
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i-1] && s[i] == s[i+1]) {
            sci = i-1;
            return true;
        }
    }
    return false;
}

char specialcheck(string s, size_t & n)
{
    char res;
    bool c = false, d = false, e = false;
    int a[s.length()], t = 0;
    //n = s.length()+100;
    for (int i = 0; i < s.length(); ++i) {
        if ((s[i] >= 32 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 64) || (s[i] >= 91 && s[i] <= 96) || 
            (s[i] >= 123 && s[i] <= 126)) {
            d = true;
            if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%') {
                c = true;
            }
            else {
                e = true;
                a[t] = i;
                ++t;
            }
        }
    }

    n = a[0];
    if (d == false || (e == true && c == false)) {
        res = 'a';
    }
    if (c == true && e == true) {
        res = 'b';
    }
    return res;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    float tmp1=exp1, tmp2 = exp2;
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    else {
        resetexp(tmp1);
        resetexp(tmp2);
        if (e1 >= 0 && e1 <= 3) {
            switch(e1) 
            {
                case 0: 
                    tmp2 += 29;
                    resetexp(tmp2);
                    break;
                case 1: 
                    tmp2 += 45;
                    resetexp(tmp2);
                    break;
                case 2: 
                    tmp2 += 75;
                    resetexp(tmp2);
                    break;
                case 3: 
                    tmp2 += 29+45+75;
                    resetexp(tmp2);
                    break;
            }
        
            int d = e1*3+tmp1*7;
            float tmpd = d;
            if (d%2 == 0) {
                tmp1 += tmpd/200;
                resetexp(tmp1);
               
            }
            else {
                tmp1 -= tmpd/100;
                resetexp(tmp1);
                
            }
            tmp1 = ceil(tmp1);
            resetexp(tmp1);
        }
        else if (e1 >= 4 && e1 <= 99) {

            if (e1 >= 4 && e1 <= 19) {
                tmp2 += ceil(e1/4.0+19);
                resetexp(tmp2);
            }
            else if (e1 >= 20 && e1 <= 49) {
                tmp2 += ceil(e1/9.0+21);
                resetexp(tmp2);
            }
            else if (e1 >= 50 && e1 <= 65) {
                tmp2 += ceil(e1/16.0+17);
                resetexp(tmp2);
            }
            if (e1 >= 66 && e1 <= 79) {
                tmp2 += ceil(e1/4.0+19);
                resetexp(tmp2);
                if (tmp2 > 200) {
                    tmp2 += ceil(e1/9.0+21);
                    resetexp(tmp2);
                }
            }
            if (e1 >= 80 && e1 <= 99) {
                tmp2 += ceil(e1/4.0+19);
                resetexp(tmp2);
                tmp2 += ceil(e1/9.0+21);
                resetexp(tmp2);
                if (tmp2 > 400) {
                    tmp2 += ceil(e1/16.0+17);
                    resetexp(tmp2);
                    tmp2 += ceil(tmp2*15.0/100);
                    resetexp(tmp2);
                }
            }
            tmp1 -= e1;
            resetexp(tmp1);
        }
    }
    exp1=tmp1;
    exp2=tmp2;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    else {
        float tmp1 = EXP1, tmphp=HP1, tmpm1=M1, p1, p2, p3;
        resethp(tmphp);
        resetexp(tmp1);
        resetmoney(tmpm1);
        int s = pow(round(sqrt(tmp1)),2);
        if (tmp1 >= s) {
            p1 = 1;
        }   
        else {
            p1 = (tmp1/s+80)/123;
        }

        if (E2%2 == 1) {
            while (1) {
                
                if (tmphp < 200) {
                    tmphp += ceil(tmphp*30.0/100);
                    resethp(tmphp);
                    tmpm1 -= 150;
                    resetmoney(tmpm1);
                    if (tmpm1 < M1/2) {
                        break;
                    }
                }
                else if (tmphp >= 200) {
                    tmphp += ceil(tmphp*10.0/100);
                    resethp(tmphp);
                    tmpm1 -= 70;
                    resetmoney(tmpm1);   
                    if (tmpm1 < M1/2) {
                        break;
                    }
                }
                
                if (tmp1 < 400) {
                    tmpm1 -= 200;
                    resetmoney(tmpm1);
                    tmp1 += ceil(tmp1*13.0/100);
                    resetexp(tmp1);
                    if (tmpm1 < M1/2) {
                        break;
                    }
                }
                else if (tmp1 >= 400) {
                    tmpm1 -= 120;
                    resetmoney(tmpm1);
                    tmp1 += ceil(tmp1*13.0/100);
                    resetexp(tmp1);
                    if (tmpm1 < M1/2) {
                        break;
                    }
                }
                

                if (tmp1 < 300) {
                    tmpm1 -= 100;
                    resetmoney(tmpm1);
                    tmp1 -= floor(tmp1*10.0/100);
                    resetexp(tmp1);
                    if (tmpm1 < M1/2) {
                        break;
                    }
                }
                else if (tmp1 >= 300) {
                    tmpm1 -= 120;
                    resetmoney(tmpm1);
                    tmp1 -= floor(tmp1*10.0/100);
                    resetexp(tmp1);
                    if (tmpm1 < M1/2) {
                        break;
                    }
                }
            } 
           
        }
        else {
            int k=1;
            while(k == 1) {
                if (tmphp < 200) {
                    tmphp += ceil(tmphp*30.0/100);
                    resethp(tmphp);
                    tmpm1 -= 150;
                    resetmoney(tmpm1);
                   if (tmpm1 <= 0) {
                        break;
                    }
                }
                else if (tmphp >= 200) {
                    tmphp += ceil(tmphp*10.0/100);
                    resethp(tmphp);
                    tmpm1 -= 70;
                    resetmoney(tmpm1);
                    if (tmpm1 <= 0) {
                        break;
                    }
                }

                if (tmp1 < 400) {
                    tmpm1 -= 200;
                    resetmoney(tmpm1);
                    tmp1 += ceil(tmp1*13.0/100);
                    resetexp(tmp1);
                    if (tmpm1 <= 0) {
                        break;
                    }
                }
                else if (tmp1 >= 400) {
                    tmpm1 -= 120;
                    resetmoney(tmpm1);
                    tmp1 += ceil(tmp1*13.0/100);
                    resetexp(tmp1);
                    if (tmpm1 <= 0) {
                        break;
                    }
                }

                if (tmp1 < 300) {
                    tmpm1 -= 100;
                    resetmoney(tmpm1);
                    tmp1 -= floor(tmp1*10.0/100);
                    resetexp(tmp1);
                }
                else if (tmp1 >= 300) {
                    tmpm1 -= 120;
                    resetmoney(tmpm1);
                    tmp1 -= floor(tmp1*10.0/100);
                    resetexp(tmp1);
                }
                ++k;
            }
        }
        tmphp -= floor(tmphp*17.0/100);
        resethp(tmphp);
        tmp1 += ceil(tmp1*17.0/100);
        resetexp(tmp1);
        s = pow(round(sqrt(tmp1)),2);
        if (tmp1 >= s) {
            p2 = 1;
        }   
        else {
            p2 = (tmp1/s+80)/123;
        }

        int ps5[10] = {32,47,28,79,100,50,22,83,64,11};
        if (E2 <= 9) {
            p3 = ps5[E2];
        }
        else {
            int tam = E2/10 + E2%10;
            p3 = ps5[tam%10];
        }
        if (p1 == 1 && p2 == 1 && p3 == 100) {
            tmp1 -= floor(tmp1*25.0/100);
            resetexp(tmp1);
        }
        else {
            if ((p1+p2+p3/100)/3 < 0.5) {
                tmphp -= floor(tmphp*15.0/100);
                resethp(tmphp);
                tmp1 += ceil(tmp1*15.0/100);
                resetexp(tmp1);
            }
            else {
                tmphp -= floor(tmphp*10.0/100);
                resethp(tmphp);
                tmp1 += ceil(tmp1*20.0/100);
                resetexp(tmp1);
            }
        }
        //cout << tmp1 << " " << tmphp << " " << tmpm1 << endl;
        HP1 = tmphp; EXP1 = tmp1; M1 = tmpm1;
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    else {
        int a[10][10];
        int u = 0, v = 0;
        float tmphp1=HP1, tmphp2=HP2, tmp1=EXP1, tmp2=EXP2;
        resethp(tmphp1);
        resethp(tmphp2);
        resetexp(tmp1);
        resetexp(tmp2);
        for(int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                a[i][j]=0;
            }
        }
        for(int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                a[i][j] = ((E3*j)+(i*2))*(i-j);
                if (a[i][j] > E3*2) {
                    ++u;
                }
                if (a[i][j] < -E3) {
                    ++v;
                }
            }
        }
        int t1=sum(u), t2=sum(v), t3=sum(u), t4=sum(v), t5=sum(u), t6=sum(v),t7=sum(u), t8=sum(v), maz=a[t1][t2];
        while (t3 >= 0 && t4 >= 0) {
            if (a[t3][t4] > maz) {
                maz = a[t3][t4];
            }
            --t3;
            --t4;
        }
        while (t5 >= 0 && t6 <= 9) {
            if (a[t5][t6] > maz) {
                maz = a[t5][t6];
            }
            --t5;
            ++t6;
        }
        while (t7 <= 9 && t8 >= 0) {
            if (a[t7][t8] > maz) {
                maz = a[t7][t8];
            }
            ++t7;
            --t8;
        }
        while (t1 <= 9 && t2 <= 9) {
            if (a[t1][t2] > maz) {
                maz = a[t1][t2];
            }
            ++t1;
            ++t2;
        }
        if (abs(a[sum(u)][sum(v)]) > maz) {
            tmp1 -= floor(tmp1*12.0/100);
            resetexp(tmp1);
            tmphp1 -= floor(tmphp1*10.0/100);
            resethp(tmphp1);
            tmp2 -= floor(tmp2*12.0/100);
            resetexp(tmp2);
            tmphp2 -= floor(tmphp2*10.0/100);
            resethp(tmphp2);
            EXP1 = tmp1;
            HP1 = tmphp1;
            EXP2 = tmp2;
            HP2 = tmphp2;
            return a[sum(u)][sum(v)];
        }
        else {
            tmp1 += ceil(tmp1*12.0/100);
            resetexp(tmp1);
            tmphp1 += ceil(tmphp1*10.0/100);
            resethp(tmphp1);
            tmp2 += ceil(tmp2*12.0/100);
            resetexp(tmp2);
            tmphp2 += ceil(tmphp2*10.0/100);
            resethp(tmphp2);
            EXP1 = tmp1;
            HP1 = tmphp1;
            EXP2 = tmp2;
            HP2 = tmphp2;
            return maz;
        }

    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string emails = "", pass = "", se = "";
    size_t n = strlen(email), m = strlen(s), sei, sci, z;
    for (int i = 0; i < n; ++i) {
        emails += email[i];
    }
    for (int i = 0; i < m; ++i) {
        pass += s[i];
    }
    
    int t = 0;
    while (emails[t] != '@') {
        se += emails[t];
        ++t;
    }

    if (lengthcheck1(pass)) {
        return -1;
    }
    else if (lengthcheck2(pass)) {
        return -2;
    }
    else if (secheck(pass,se,sei)) {
        return -(300+sei);
    }
    else if (ltcheck(pass,sci)) {
        return -(400+sci);
    }
    else if (specialcheck(pass,z) == 'a') {
        return -5;
    }
    else if (specialcheck(pass,z) == 'b') {
        return z;
    }
    else {
        return -10;
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int d[num_pwds], t = 0, ma = 0, res;
    size_t ml = 0;
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i],arr_pwds[j]) == 0) {
                ++t;
            }
        }
        d[i] = t;
        if (t > ma) {
            ma = t;
        }
        t = 0;
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (d[i] == ma) {
            if (strlen(arr_pwds[i]) > ml) {
                ml = strlen(arr_pwds[i]);
                res = i;
            }
        }
    }
    return res;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////