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
        if (e1 >= 0 && e1 <= 3) {
            if (exp2 > 600) {
            exp2 = 600;
        }
        if (exp1 > 600) {
            exp1 = 600;
        }
        if (exp1 < 0) {
            exp1 = 0;
        }
        if (exp2 < 0) {
            exp2 = 0;
        }
        if (e1 == 0) {
            exp2 = exp2 + 29;
            if (exp2 > 600) {
                exp2 = 600;
            }
            if (exp1 > 600) {
                exp1 = 600;
            }
            if (exp1 < 0) {
                exp1 = 0;
            }
            if (exp2 < 0) {
                exp2 = 0;
            }
        }
         else if (e1 == 1) {
             exp2 = exp2 + 45;
             if (exp2 > 600) {
                exp2 = 600;
             }
             if (exp1 > 600) {
                exp1 = 600;
             }
             if (exp1 < 0) {
                exp1 = 0;
             }
             if (exp2 < 0) {
                exp2 = 0;
               }
          }
          else if (e1 == 2) {
               exp2 = exp2 + 75;
               if (exp2 > 600) {
                  exp2 = 600;
               }
               if (exp1 > 600) {
                  exp1 = 600;
                }
               if (exp1 < 0) {
                  exp1 = 0;
               }
               if (exp2 < 0) {
                   exp2 = 0;
               }
          }
          else if (e1 == 3) {
               exp2 = exp2 + 29 + 45 + 75;
               if (exp2 > 600) {
                    exp2 = 600;
                }
               if (exp1 > 600) {
                    exp1 = 600;
                }
               if (exp1 < 0) {
                    exp1 = 0;
                }
               if (exp2 < 0) {
                    exp2 = 0;
                }
            }
            int d;
           d = e1 * 3 + exp1 * 7;
            if (d % 2 == 0) {
                exp1 = ceil(exp1 + d / 200.0);
                if (exp2 > 600) {
                    exp2 = 600;
                }
                if (exp1 > 600) {
                    exp1 = 600;
                }
                if (exp1 < 0) {
                    exp1 = 0;
                }
                if (exp2 < 0) {
                    exp2 = 0;
                }
            }
            if (d % 2 != 0) {
                exp1 = ceil(exp1 - d / 100.0);
                if (exp2 > 600) {
                    exp2 = 600;
                }
                if (exp1 > 600) {
                    exp1 = 600;
                }
                if (exp1 < 0) {
                    exp1 = 0;
                }
                if (exp2 < 0) {
                    exp2 = 0;
                }
            }
        }
    else if (e1 >= 4 && e1 <= 99) {
            if (exp2 > 600) {
            exp2 = 600;
        }
        if (exp1 > 600) {
            exp1 = 600;
        }
        if (exp1 < 0) {
            exp1 = 0;
        }
        if (exp2 < 0) {
            exp2 = 0;
        }
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil(exp2 + e1*1.0 / 4.0 + 19);
            if (exp2 > 600) {
                exp2 = 600;
            }
            if (exp1 > 600) {
                exp1 = 600;
            }
            if (exp1 < 0) {
                exp1 = 0;
            }
            if (exp2 < 0) {
                exp2 = 0;
            }
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2 + e1*1.0 / 9.0 + 21);
            if (exp2 > 600) {
                exp2 = 600;
            }
            if (exp1 > 600) {
                exp1 = 600;
            }
            if (exp1 < 0) {
                exp1 = 0;
            }
            if (exp2 < 0) {
                exp2 = 0;
            }
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2 + e1*1.0 / 16.0 + 17);
            if (exp2 > 600) {
                exp2 = 600;
            }
            if (exp1 > 600) {
                exp1 = 600;
            }
            if (exp1 < 0) {
                exp1 = 0;
            }
            if (exp2 < 0) {
                exp2 = 0;
            }
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + e1*1.0 / 4.0 + 19);
            if (exp2 > 600) {
                exp2 = 600;
            }
            if (exp1 > 600) {
                exp1 = 600;
            }
            if (exp1 < 0) {
                exp1 = 0;
            }
            if (exp2 < 0) {
                exp2 = 0;
            }
            if (exp2 > 200 && exp2 <= 600) {
                exp2 = ceil(exp2 + e1*1.0 / 9.0 + 21);
                if (exp2 > 600) {
                    exp2 = 600;
                }
                if (exp1 > 600) {
                    exp1 = 600;
                }
                if (exp1 < 0) {
                    exp1 = 0;
                }
                if (exp2 < 0) {
                    exp2 = 0;
                }
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(exp2 + e1*1.0 / 4.0 + 19);
            exp2 = ceil(exp2 + e1*1.0 / 9.0 + 21);
            if (exp2 > 600) {
                exp2 = 600;
            }
            if (exp1 > 600) {
                exp1 = 600;
            }
            if (exp1 < 0) {
                exp1 = 0;
            }
            if (exp2 < 0) {
                exp2 = 0;
            }
            if (exp2 > 400 && exp2 <= 600) {
                exp2 = ceil(exp2 + e1*1.0 / 16.0 + 17);
                exp2 = ceil(exp2 * 1.15);
                if (exp2 > 600) {
                    exp2 = 600;
                }
                if (exp1 > 600) {
                    exp1 = 600;
                }
                if (exp1 < 0) {
                    exp1 = 0;
                }
                if (exp2 < 0) {
                    exp2 = 0;
                }
            }
        }
        exp1 = exp1 - e1;
        if (exp1 > 600) {
            exp1 = 600;
        }
        if (exp1 < 0) {
            exp1 = 0;
        }
        if (exp2 < 0) {
            exp2 = 0;
        }
        if (exp2 > 600) {
            exp2 = 600;
        }
    }
    if (e1 > 99 || e1 < 0) {
        return -99;
    }
    return exp1 + exp2;
}
// Task 2
    int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
        if(E2>=0 && E2<=99){
         if (HP1<0){
            HP1=0;
        }
        if (HP1>666){
            HP1=666;
        }
        if (EXP1<0){
            EXP1=0;
        }
        if(EXP1>600){
            EXP1=600;
        }
        if(M1<0){
            M1=0;
        }
        if(M1>3000){
            M1=3000;
        }
        int s;
        double p1;
        s = (round(sqrt(EXP1))) * (round(sqrt(EXP1)));
        if (EXP1 >= s) {
            p1 = 1.0;
        }
        if (EXP1 < s) {
            p1 = (EXP1 / s + 80) / 123.0;
        }
        double a;
        int b=0;
        a = M1 * 0.5;
        if (E2 % 2 != 0) {
            while(b<=a){
                if(M1==0){
                    break;
                }
                if (HP1 >= 200) {
                HP1 = ceil(HP1 * 110.0/100);
                M1 = M1 - 70;
                b = b + 70;
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (b > a) break;
            }
            else if (HP1 < 200) {
                HP1 = ceil(HP1 * 130.0/100);
                M1 = M1 - 150;
                b = b + 150;
                if (HP1<0){
                    HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (b > a) break;
            }
            if (EXP1 >= 400) {
                M1 = M1 - 120;
                b = b + 120;
                EXP1 = ceil(EXP1 * 113.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (b > a) break;
            }
            else if (EXP1 < 400) {
                M1 = M1 - 200;
                b = b + 200;
                EXP1 = ceil(EXP1 * 113.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (b > a) break;
            }
            if (EXP1 >= 300) {
                M1 = M1 - 120;
                b = b + 120;
                EXP1 =ceil(EXP1 * 90.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (b > a) break;
            }
            else if (EXP1 < 300) {
                M1 = M1 - 100;
                b = b + 100;
                EXP1 =ceil(EXP1 * 90.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (b > a) break;
            }  
        }
        }
        if (E2 % 2 == 0) {
            while(M1>0){
                if (HP1 >= 200) {
                HP1 = ceil(HP1 * 110.0/100);
                M1 = M1 - 70;
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (M1 == 0) {
                    break;
                }
            }
            else if (HP1 < 200) {
                HP1 = ceil(HP1 * 130.0/100);
                M1 = M1 - 150;
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (M1 == 0) {
                    break;
                }
            }
            if (EXP1 >= 400) {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 * 113.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (M1 == 0) {
                    break;
                }
            }
            else if (EXP1 < 400) {
                M1 = M1 - 200;
                EXP1 = ceil(EXP1 * 113.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (M1 == 0) {
                    break;
                }
            }
                if (EXP1 >= 300) {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 * 90.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (M1 == 0) {
                    break;
                }
            }
            else if (EXP1 < 300) {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1 *90.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
                if (M1 == 0) {
                    break;
                }
            }
            break;
        }
        }
        HP1 = ceil(HP1 * 83.0/100);
        EXP1 = ceil(EXP1 * 117.0/100);
        if (HP1<0){
            HP1=0;
        }
        if (HP1>666){
            HP1=666;
        }
        if (EXP1<0){
            EXP1=0;
        }
        if(EXP1>600){
            EXP1=600;
        }
        if(M1<0){
            M1=0;
        }
        if(M1>3000){
            M1=3000;
        }
        double p2;
        s = (round(sqrt(EXP1))) * (round(sqrt(EXP1)));
        if (EXP1>=s){
            p2=1.0;
        }
        if(EXP1<s){
        p2 = (EXP1 / s + 80) / 123.0;
        }
        double P[10] = { 0.32,0.47,0.28,0.79,1.0,0.50,0.22,0.83,0.64,0.11 };
        double p3;
        if (E2 >= 0 && E2 <= 9) {
            p3 = P[E2];
        }
        if (E2 >= 10 && E2 <= 99) {
            int c, d;
            c = E2 / 10 + E2 % 10;
            d = c % 10;
            p3 = P[d];
        }
        double p4;
        if (p1 == 1.0 && p2 == 1 && p3 == 1) {
            EXP1 =ceil( EXP1 * 75.0/100);
            if (HP1<0){
                HP1=0;
            }
            if (HP1>666){
                HP1=666;
            }
            if (EXP1<0){
                EXP1=0;
            }
            if(EXP1>600){
                EXP1=600;
            }
            if(M1<0){
                M1=0;
            }
            if(M1>3000){
                M1=3000;
            }
        }
        if (p1 != 1.0 || p2 != 1.0 || p3 != 1.0) {
            p4 = (p1 + p2 + p3) / 3.0;
            if (p4 < 0.5) {
                HP1 = ceil(HP1 * 85.0/100);
                EXP1 = ceil(EXP1 * 115.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
            }
            if (p4 > 0.5) {
                HP1 = ceil(HP1*90.0/100);
                EXP1 = ceil(EXP1 * 120.0/100);
                if (HP1<0){
                HP1=0;
                }
                if (HP1>666){
                    HP1=666;
                }
                if (EXP1<0){
                    EXP1=0;
                }
                if(EXP1>600){
                    EXP1=600;
                }
                if(M1<0){
                    M1=0;
                }
                if(M1>3000){
                    M1=3000;
                }
            }
        }
}
    if (E2<0||E2>99){
        return-99;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if(E3>=0 && E3<=99){
    if (EXP2 > 600) {
        EXP2 = 600;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP2 < 0) {
        EXP2 = 0;
    }
    if (HP1<0){
        HP1=0;
    }
    if (HP1>666){
        HP1=666;
    }
    if (HP2<0){
        HP2=0;
    }
    if (HP2>666){
        HP2=666;
    }
    int taxi[10][10];
    int ver=0;
    int hor=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            taxi[i][j]=(E3*j+i*2)*(i-j);
            if(taxi[i][j]>E3*2){
                ver++;
            } 
            if(taxi[i][j]<E3*(-1)){
                hor++;
            } 
        }
    }
    while(ver >= 10 || hor >= 10 ){
        if(ver >= 10){
            ver = ver / 10 + ver % 10;
        }
        if(hor >= 10){
            hor = hor / 10 + hor % 10;
        }
    }
    int x=ver;
    int y=hor;
    int max=0;
    while(x>=0 && x<10 && y>=0 && y<10){
        if(max<taxi[x][y]) {
            max=taxi[x][y];
        }
        x++;
        y++;
    }
    x=ver; 
    y=hor;
    while(x>=0 && x<10 && y>=0 && y<10){
        if(max<taxi[x][y]) {
            max=taxi[x][y];
        }
        x--;
        y--;
    }
    x=ver; 
    y=hor;
    while(x>=0 && x<10 && y>=0 && y<10){
        if(max<taxi[x][y]) {
            max=taxi[x][y];
        }
        x--;
        y++;
    }
    x=ver; 
    y=hor;
        while(x<10 && x>=0 && y<10 && y>=0){
        if(max<taxi[x][y]) {
            max=taxi[x][y];
        }
        x++;
        y--;
    }
    if(max<abs(taxi[ver][hor])){
        EXP2=ceil(EXP2*88.0/100);
        HP2=ceil(HP2*90.0/100 );
        EXP1=ceil(EXP1*88.0/100 );
        HP1=ceil(HP1*90.0/100);
        if (EXP2 > 600) {
            EXP2 = 600;
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        }
        if (EXP1 < 0) {
            EXP1 = 0;
        }
        if (EXP2 < 0) {
            EXP2 = 0;
        }
        if (HP1<0){
            HP1=0;
        }
        if (HP1>666){
            HP1=666;
        }
        if (HP2<0){
            HP2=0;
        }
        if (HP2>666){
            HP2=666;
        }
        return taxi[ver][hor];
    }
    else{
        EXP2=ceil(EXP2*112.0/100);
        HP2=ceil(HP2*110.0/100);
        EXP1=ceil(EXP1*112.0/100 );
        HP1=ceil(HP1*110.0/100);
        if (EXP2 > 600) {
            EXP2 = 600;
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        }
        if (EXP1 < 0) {
            EXP1 = 0;
        }
        if (EXP2 < 0) {
            EXP2 = 0;
        }
        if (HP1<0){
            HP1=0;
        }
        if (HP1>666){
            HP1=666;
        }
        if (HP2<0){
            HP2=0;
        }
        if (HP2>666){
            HP2=666;
        }
        return max;
    }
}
 return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int se_pos = 0;
    while (email[se_pos] != '@') {
        se_pos++;
    }
    string se(email, 0, se_pos);
    if (strlen(s) < 8){
        return -1;
    }
    if(strlen(s)>20){
        return-2;
    }
    bool has_special_char = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if(!(isalnum(s[i]))){
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                has_special_char = true;
            }
        }
        if (strstr(s, se.c_str()) != NULL) {
            return -(300 + strstr(s, se.c_str()) - s);
        }
    }
    int sci = 0;
    int count = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (i > 0 && s[i] == s[i-1]) {
            count++;
        } 
        else {
            count = 1;
        }
        if (count > 2) {
            return -(400 + i - count + 1);
        }
        sci = i;
    }
    if (has_special_char==false) {
        return -5;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if(!(isalnum(s[i]))){
            if (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
                return i;
            }
        }
    }
    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int pos=0;
    int fre=0;
    int count;
    for (int i=0; i<num_pwds ; i++) {
            count=1;
        for (int j=i+1; j<num_pwds; j++) {
            if (string(arr_pwds[i])==string(arr_pwds[j])) {
                count++;
            }
        }
        if (count>fre ) {
            pos=i;
            fre=count;
        }
        else if(count==fre){
            if(strlen(arr_pwds[pos])<strlen(arr_pwds[i])){
                pos=i;
                fre=count;
            }
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////