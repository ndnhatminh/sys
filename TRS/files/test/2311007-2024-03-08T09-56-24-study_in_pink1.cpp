
#include "study_in_pink1.h"
using namespace std;
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

// Task 1
int checkhp(int n) {
    if (n > 666) return 666;
    else  if (n < 0) return 0;
    else if (n >= 0 && n <= 666) return n;
    return 0;
}
int checkexp(int n) {
    if (n > 600) return 600;
    else  if (n < 0) return 0;
    else if (n >= 0 && n <= 600) return n;
    return 0;
}
int checkm(int n) {
    if (n > 3000) return 3000;
    else  if (n < 0) return 0;
    else if (n >= 0 && n <= 3000) return n;
    return 0;
}

int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    if (E1 > 99 || E1 < 0) return -99;
    EXP1 = checkexp(EXP1);
    EXP2 = checkexp(EXP2);

    /////////case1//////
    if (E1 >= 0 && E1 <= 3) {
        //tinh exp2
        switch (E1) {
        case 0: {
            EXP2 += 29;
            break;
        }
        case 1: {
            EXP2 += 45;
            break;
        }case 2: {
            EXP2 += 75;
            break;
        }case 3:{
            EXP2 += 149;
            break;
        }
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            int exp1test = ceilf(EXP1 + D*1.0 / 200);
            EXP1 = exp1test;
        }
        else {
            int exp1test = ceilf(EXP1 - D*1.0 / 100);
            EXP1 = exp1test;
        }
         
    }//======case2======
    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            int exp2test = ceilf(EXP2 + E1*1.0000 / 4 + 19);
            EXP2 = exp2test;
           
        }
        else if (E1 >= 20 && E1 <= 49) {
            int exp2test= ceilf(EXP2 + E1*1.0000 / 9 + 21);
            EXP2 = exp2test;
           
        }
        else if (E1 >= 50 && E1 <= 65) {
            int exp2test = ceilf(EXP2 + E1 * 1.0000 / 16 + 17);
            EXP2 = exp2test;
            
        }
        else if (E1 >= 66 && E1 <= 79) {
            int exp2test = ceilf(EXP2 + E1 * 1.0000 / 4 + 19);
            if (exp2test > 200) {
                exp2test = ceilf(exp2test + E1 * 1.000 / 9 + 21);
                EXP2 = exp2test;
                
            }
            else {
                EXP2 = exp2test;
                
            }
        }
        else if (E1 >= 80 && E1 <= 99) {
            int exp2test = ceilf(EXP2 + ceilf(E1 * 1.0000 / 4 + 19) + ceilf(E1*1.000 / 9 + 21));
            if (exp2test > 400) {
                exp2test = ceilf(exp2test + E1 * 1.0000 / 16 + 17);
                exp2test = ceilf(exp2test * 115.0/100);
                EXP2 = exp2test;
               
            }
            else {
                EXP2 = exp2test;
                
            }
        }
        EXP1 = EXP1 - E1;
        EXP1=checkexp(EXP1);
        EXP2=checkexp(EXP2);
    }
     EXP1=checkexp(EXP1);
     EXP2=checkexp(EXP2);
    return EXP1 + EXP2;
}

// Task 2
//kiem tra so chinh phuong
int chinhphuong(int n) {
    double c = sqrt(n);
    int low = floor(c);
    int high = ceil(c);
    if (pow(high, 2) - n > n - pow(low, 2)) {
        return low*low;
    }
    else if (pow(high, 2) - n < n - pow(low, 2)) {
        return high*high;
    }
    else if (low = c = high) return n;
    return 0;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    M1 = checkm(M1);
    if (E2 > 99 || E2 < 0) return -99;
    float P1;//ti le tim ra vali
    //===way1=====
    int S = chinhphuong(EXP1);
    if (EXP1 >= S) {
        P1 = 100;
    }
    else P1 = (EXP1 * 1.0 / S + 80)*100 / 123;
    //======way2======
    if (E2 % 2 == 1) {
        int chitra=0;
        const float gan = M1*5.0/10;
        while(chitra<gan&&M1>0) {
            
                if (HP1 < 200) {
                    double hp1test = HP1 * 13.0/10;
                    HP1 = ceilf(hp1test);
                    HP1=checkhp(HP1);
                    M1 = M1 - 150;
                    chitra = chitra + 150;
                }
                else {
                    double hp1test = HP1 * 11.0/10;
                    HP1 = ceilf(hp1test);
                    HP1=checkhp(HP1);
                    M1 = M1 - 70;
                    chitra += 70;
                }
                if (chitra > gan||M1<=0) break;
                
            
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    float exp1test = EXP1 * 113.0/100;
                    EXP1 = ceilf(exp1test);
                    EXP1=checkexp(EXP1);
                    chitra += 200;
                }
                else {
                    M1 = M1 - 120;
                    float exp1test = EXP1 * 113.0/100;
                    EXP1 = ceilf(exp1test);
                    EXP1=checkexp(EXP1);
                    chitra += 120;
                }
                if (chitra > gan||M1<0) break;
               
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    float exp1test = EXP1 * 9.0/10;
                    EXP1 = ceilf(exp1test);
                    EXP1=checkexp(EXP1);
                    chitra += 100;
                }
                else {
                    M1 =M1- 120;
                    float exp1test = EXP1 * 9.0/10;
                    EXP1 = ceilf(exp1test);
                    EXP1=checkexp(EXP1);
                    chitra += 120;
                }
                if (chitra < gan||M1<=0) continue;
        } 
       
    }
    else if (E2%2==0) {
    
        if (M1 > 0) {
            if (HP1 < 200) {
                double hp1test = HP1 * 13.0/10;
                HP1 = ceilf(hp1test);
                HP1=checkhp(HP1);
                M1 = M1 - 150;
            }
            else {
                double hp1test = HP1 * 11.0/10;
                HP1 = ceilf(hp1test);
                HP1=checkhp(HP1);
                M1 = M1 - 70;
            }
        }
          
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 = M1 - 200;
                float exp1test = EXP1 * 113.0/100;
                EXP1 = ceilf(exp1test);
                EXP1=checkexp(EXP1);
            }
            else {
                M1 = M1 - 120;
                float exp1test = EXP1 * 113.0/100;
                EXP1 = ceilf(exp1test);
                EXP1=checkexp(EXP1);
            }
        }
        if (M1 > 0) {
            if (EXP1 < 300) {
                M1 = M1 - 100;
                float exp1test = EXP1 * 9.0/10;
                EXP1 = ceilf(exp1test);
                EXP1=checkexp(EXP1);
            }
            else {
                M1 =M1- 120;
                float exp1test = EXP1 * 9.0/10;
                EXP1 = ceilf(exp1test);
                EXP1=checkexp(EXP1);
            }
        }
        
    }
    HP1 = ceilf(HP1 * 83.0/100);
    EXP1 = ceilf(EXP1 * 117.0/100);
    EXP1=checkexp(EXP1);
    HP1=checkhp(HP1);
    float P2;
    int H = chinhphuong(EXP1);
    if (EXP1 >= H) {
        P2 = 100;
    }
    else P2 = (EXP1 * 1.0000 / H + 80)*100 / 123;
    ///=====way3=======
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i;
    if (E2 >= 0 && E2 <= 9) {
            i = E2;
    }
    else if (E2 >= 10 && E2 <= 99) {
        int donvi = E2 % 10;
        int chuc = E2 / 10;
       int so = chuc + donvi;
       i = so % 10;
    }
    int P3 = P[i];
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ceilf(float(EXP1 * 75.0/100));
    }
    else {
       float P = (P1 + P2 + P3) / 3;
       if (P < 50) {
           HP1 = ceilf(float(HP1 * 85.0/100));
           EXP1 = ceilf(float(EXP1 * 115.0/100));
       }
       else {
           HP1 = ceilf(float(HP1 * 9.0/10));
           EXP1 = ceilf(float(EXP1 * 12.0/10));
    }
    }
    HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    M1 = checkm(M1);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    HP2 = checkhp(HP2);
    EXP2 = checkhp(EXP2);
    if(E3>99||E3<0) return -99;
    const int ROWS = 10;
const int COLS = 10;

int taxi[ROWS][COLS] = { 0 }; // khoi tao ma tran 10x10 voi gia tri 0

for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
        // tinh diem tung vi tri
        int skill = ((E3 * j) + (i * 2)) * (i - j);
        taxi[i][j] = skill;
    }
}

   

//bigger
int counti = 0;
for (int a = 0; a < ROWS; ++a) {
    for (int b = 0; b < COLS; b++) {
        if (taxi[a][b] > E3 * 2) {
            ++counti;
        }
    }
}
   
int i;
if (counti >= 0 && counti <= 9) {
    i = counti;
}
else if (counti >= 10 && counti <= 99) {
    int donvi = counti % 10;
    int chuc = counti / 10;
    i = donvi + chuc;
    if (i >= 10) {
        int dv = i % 10;
        int ch = i / 10;
        i = dv + ch;
    }
}

//smaller
int countj = 0;
for (int a = 0; a < ROWS; ++a) {
    for (int b = 0; b < COLS; b++) {
        if (taxi[a][b] < -E3) {
            ++countj;
        }
    }
}
   
int j;
if (countj >= 0 && countj <= 9) {
    j = countj;
}
else if (countj >= 10 && countj <= 99) {
    int donvi = countj % 10;
    int chuc = countj / 10;
    j = donvi + chuc;
    if (i >= 10) {
        int dv = j % 10;
        int ch = j / 10;
        j = dv + ch;
    }
}
   

int diemtaxi = taxi[i][j];
  
int  max_score = diemtaxi;
//huong1
for (int a = i - 1, b = j - 1; a >= 0 && b >= 0; --a, --b) { 
    if (taxi[a][b] > max_score) { 
        max_score = taxi[a][b];
    }
}

// huong2
for (int a = i + 1, b = j - 1; a < 10 && b >= 0; ++a, --b) { 
    if (taxi[a][b] > max_score) { 
        max_score = taxi[a][b];
    }
}

// huong3
for (int a = i + 1, b = j + 1; a < 10 && b < 10; ++a, ++b) { 
    if (taxi[a][b] > max_score) { 
        max_score = taxi[a][b];
    }
}

// huong4
for (int a = i - 1, b = j + 1; a >= 0 && b < 10; --a, ++b) { 
    if (taxi[a][b] > max_score) { 
        max_score = taxi[a][b];
    }
}
//so sanh diem txi va diem sherchlok
int max;
if (abs(diemtaxi)>max_score){
    float testexp1=EXP1*88.0/100;
    EXP1=ceilf(testexp1);
    EXP1=checkexp(EXP1);

    float testhp1=HP1*90.0/100;
    HP1=ceilf(testhp1);
    HP1=checkhp(HP1);

    float testexp2=EXP2*88.0/100;
    EXP2=ceilf(testexp2);
    EXP2=checkexp(EXP2);

    float testhp2=HP2*90.0/100;
    HP2=ceilf(testhp2);
    HP2=checkhp(HP2);

    return diemtaxi;
}else{
    float testexp1=EXP1*112.0/100;
    EXP1=ceilf(testexp1);
    EXP1=checkexp(EXP1);

    float testhp1=HP1*110.0/100;
    HP1=ceilf(testhp1);
    HP1=checkhp(HP1);

    float testexp2=EXP2*112.0/100;
    EXP2=ceilf(testexp2);
    EXP2=checkexp(EXP2);

    float testhp2=HP2*110.0/100;
    HP2=ceilf(testhp2);
    HP2=checkhp(HP2);
    return max_score;
    }

}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    size_t atPos = strchr(email, '@') - email;
    char se[101];
    strncpy(se, email, atPos);
    se[atPos] = '\0';


       if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }
    if (strstr(s, se) != nullptr) {
        return -(300 + static_cast<int>(strstr(s, se) - s));
    }
    for (size_t i = 0; i < strlen(s) - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + static_cast<int>(i));
        }
    }
     if (!(strstr(s, "!") != nullptr) &&
        !(strstr(s, "@") != nullptr) &&
        !(strstr(s, "#") != nullptr) &&
        !(strstr(s, "%") != nullptr) &&
        !(strstr(s, "$") != nullptr)
        )
    {
        return -5;
    }
    for (size_t i = 0; i < strlen(s); ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!' ) {
            return static_cast<int>(i);
        }
    }
   
   
    return -10;


}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    int vitri = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int leng = strlen(pwd);

      //so lan xuat hien cua mat khau
        int count = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(pwd, arr_pwds[j]) == 0) {
                ++count;
            }
        }

        // kiem tra dieu kien
        if (count > maxCount || (count == maxCount && leng > maxLength)) {
            maxCount = count;
            maxLength = leng;
            vitri = i;
        }
    }

    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////