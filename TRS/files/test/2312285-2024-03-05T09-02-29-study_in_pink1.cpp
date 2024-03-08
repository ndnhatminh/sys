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
int checkVal(int n, int smallest, int largest) {
    if(n > largest) {n = largest;}
    if(n < smallest) {n = smallest;}
    return n;
}
bool checkE(int n) {
    if(n < 0 || n > 99) return false;
    else{return true;}
}
int firstMeet(int & exp1, int & exp2, int e1) {
    if(checkE(e1)) {
    // TODO: Complete this function
    exp1 = checkVal(exp1, 0, 600);
    exp2 = checkVal(exp2, 0, 600);
    //when e1 in [0,3];
    if(e1 >= 0 && e1 <= 3) {
        switch(e1) {
            case 0: {exp2 += 29;exp2 = checkVal(exp2, 0, 600);} break;
            case 1: {exp2 += 45;exp2 = checkVal(exp2, 0, 600);} break;
            case 2: {exp2 += 75;exp2 = checkVal(exp2, 0, 600);} break;
            case 3: {exp2 += 149;exp2 = checkVal(exp2, 0, 600);} break;
        }
        int D;
        D = e1*3 +  exp1*7;
        if(D %2 == 0) {
            exp1 += ceil(D/200.0);
            exp1 = checkVal(exp1, 0, 600);
        } else{
            exp1 -= ceil(D/100.0) - 1;
            exp1 = checkVal(exp1, 0, 600);
        }
    }
    //When e1 in [4,99]
    if(e1 >= 4 && e1 <= 99)
    {
    if(e1 >= 4 && e1 <= 19) {
        exp2 += ceil(e1/4.0 + 19);
        exp2 = checkVal(exp2, 0, 600);
    }
    if(e1 > 19 && e1 <= 49) {
        exp2 += ceil(e1/9.0 + 21);
        exp2 = checkVal(exp2, 0, 600);
    }
    if(e1 > 49 && e1 <= 65) {
        exp2 += ceil(e1/16.0 + 17);
        exp2 = checkVal(exp2, 0, 600);
    }
    if(e1 > 65 && e1 <= 79) {
        exp2 += ceil(e1/4.0 + 19);
        exp2 = checkVal(exp2, 0, 600);
        if(exp2 > 200) {
            exp2 += ceil(e1/9.0 + 21);
            exp2 = checkVal(exp2, 0, 600);
        }
    }
    if(e1 > 79 && e1 <= 99) {
        exp2 += ceil(e1/4.0 + 19);
        exp2 = checkVal(exp2, 0, 600);
        exp2 += ceil(e1/9.0 + 21);
        exp2 = checkVal(exp2, 0, 600);
        if(exp2 > 400) {
            exp2 += ceil(e1/16.0 + 17);
            exp2 = checkVal(exp2, 0, 600);
            exp2 = ceil(exp2 * 1.15);
            exp2 = checkVal(exp2, 0, 600);
    }
    }
    exp1 -= e1;
    exp1 = checkVal(exp1, 0, 600);
    }
    return exp1 + exp2;
    } 
    return -99; // If e1 out of range
}

// Task 2
float Path1(int EXP) {
    if(EXP!= 0) {
    int n1, n2;
    n1 = sqrt(EXP);
    n2 = sqrt(EXP) +1;
    if(EXP-(n1*n1) < (n2*n2)-EXP) {
        return 1.00;
    } else {
        return (EXP/(n2*n2)+80)/123.0;
    }
    } else return 80/123.00;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(checkE(E2)){
    // TODO: Complete this function
    EXP1 = checkVal(EXP1, 0, 600);
    HP1 = checkVal(HP1, 0, 666);
    M1 = checkVal(M1, 0, 3000);
    float P[10] = {32,47,28,79,100,50,22,83,64,11};
    float P1, P2, P3;//Xac suat tim thay vali tren tung con duong
    int M_use = 0;//So tien da xai
    int M;//So tien gioi han moi truong hop
    if(E2 % 2 == 0) {
        M = M1;
    } else M = M1/2;
    bool x = 1;
    while(x) {
    // PATH 1:
    P1 = Path1(EXP1);
    // PATH 2:
    bool cont = true;
    while(cont){
        if (M_use >= M) {cont = false; break;}
        if(HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                HP1 = checkVal(HP1, 0, 666);
                M_use += 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1);
                HP1 = checkVal(HP1, 0, 666);
                M_use += 70;
            }
        if (M_use >= M) {cont = false; break;}
        if(EXP1 < 400) {
                EXP1 = ceil(EXP1 * 1.13);
                EXP1 = checkVal(EXP1, 0, 600);
                M_use += 200;
            }
            else {
                EXP1 = ceil(EXP1 * 1.13);
                EXP1 = checkVal(EXP1, 0, 600);
                M_use += 120;
            }
        if (M_use >= M) {cont = false; break;}
        if(EXP1 < 300) {
                EXP1 = ceil(EXP1 * 0.9);
                EXP1 = checkVal(EXP1, 0, 600);
                M_use += 100;
            }
            else {
                EXP1 = ceil(EXP1 * 0.9);
                EXP1 = checkVal(EXP1, 0, 600);
                M_use += 120;
            }
        if (M_use >= M) {cont = false; break;}
        if (E2 % 2 == 0) {cont = false; break;}
    }//Vong lap cac truong hop
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    HP1 = checkVal(HP1, 0, 666);
    EXP1 = checkVal(EXP1, 0, 600);
    P2 = Path1(EXP1);
    //PATH 3:
    int n;
    if(E2 >= 10) {
        n = (E2/10 + E2 %10) % 10;
    } else {n = E2;}
    P3 = P[n]*0.01;
    //Ket luan sau khi di het moi con duong:
    if( (P1 + P2 + P3) == 3.00) {
        EXP1 = ceil(EXP1 * 0.75);
        EXP1 = checkVal(EXP1, 0, 600);
    } else{
        if((P1 + P2 + P3) / 3.00 < 0.50) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
            HP1 = checkVal(HP1, 0, 666);
            EXP1 = checkVal(EXP1, 0, 600);
            x = 0;
        } else {
            HP1 = ceil(HP1 * 0.90);
            EXP1 = ceil(EXP1 * 1.20);
            HP1 = checkVal(HP1, 0, 666);
            EXP1 = checkVal(EXP1, 0, 600);
            x = 0;
        }
    }
    }
    M1 = M1 - M_use;
    M1 = checkVal(M1, 0, 3000);
    return HP1 + EXP1 + M1;
    } else return -99;
}
// Task 3
int breakNum(int n) {
    if(n > 9) {
    while(n > 9) {
        n = n/10 + n % 10;
        }
        return n;
    } else return n;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(checkE(E3)){
    EXP1 = checkVal(EXP1, 0, 600);
    EXP2 = checkVal(EXP2, 0, 600);
    HP1 = checkVal(HP1, 0, 666);
    HP2 = checkVal(HP2, 0, 666);
    int res,pos= 0,neg = 0,x,y;
    int Map_point[10][10];
    int Sherlock_point[10][10];
    for(int i = 0 ; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            Map_point[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    } //Lap ma tran diem so tung diem cho Taxi;
    for(int i = 0 ; i < 10; i++) {//Lap ma tran diem cua Sherlock:
        for(int j = 0; j < 10; j++) {
            int Max = Map_point[i][j];
            bool x = true;
            //Khao sat tren duong cheo phu
            if(i + j < 10) {
            int m = 0, n = i + j;
            while(x) {
                if(Map_point[m][n] > Max) {
                    Max = Map_point[m][n];
                }
                if(n == 0) {
                    x = false;
                    break;
                }
                m++;
                n--;
            }
            } else{
                int m = i + j - 9, n = 9;
            while(x) {
                if(Map_point[m][n] > Max) {
                    Max = Map_point[m][n];
                }
                if(n == i + j -9 ) {
                    x = false;
                    break;
                }
                m++;
                n--;
            }
            }
            //Khao sat tren duong cheo chinh
            x = true;
            if(i > j) {
            int m = i - j, n = 0;
            while(x) {
                if(Map_point[m][n] > Max) {
                    Max = Map_point[m][n];
                }
                if(m == 9) {
                    x = false;
                    break;
                }
                m++;
                n++;
            }
            } else{
                int m = 0, n = j - i;
            while(x) {
                if(Map_point[m][n] > Max) {
                    Max = Map_point[m][n];
                }
                if(n == 9) {
                    x = false;
                    break;
                }
                m++;
                n++;
            }
            }
            Sherlock_point[i][j] = Max;
            if(Map_point[i][j] > (E3 * 2)) {//Tim gia tri pos, neg
                pos++;
            }
            if(Map_point[i][j] < -E3) {
                neg++;
            }
        }
    }
    x = breakNum(pos);
    y = breakNum(neg);
    if(abs(Map_point[x][y]) > Sherlock_point[x][y]){
        res = Map_point[x][y];
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.90);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.90);
    EXP1 = checkVal(EXP1, 0, 600);
    EXP2 = checkVal(EXP2, 0, 600);
    HP1 = checkVal(HP1, 0, 666);
    HP2 = checkVal(HP2, 0, 666);
    } else {
        res = Sherlock_point[x][y];
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 * 1.10);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 * 1.10);
    EXP1 = checkVal(EXP1, 0, 600);
    EXP2 = checkVal(EXP2, 0, 600);
    HP1 = checkVal(HP1, 0, 666);
    HP2 = checkVal(HP2, 0, 666);
    }
    return res;
    } else return -99;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s1 = s;
    string email1 = email;
    char se1[100];
    int spe = 0,pos1 = 0, sci = 0,sei = 0;
    int i = 0;
    bool case1 = false, case2 = false, case3 = false, case4 = false, case5 = false,case6 = false;
    while(email1[i] != 64) {
        se1[i] = email1[i];
        i++;
    }
    string se = se1;
    if(s1.size() < 8) {//Ngan hon
        return -1;
    }
    if(s1.size() > 20) {
        return -2;    //Dai hon
    }
    for(int i = 0; i < s1.size(); i++) {
        if((s1[i] != 33) && (s1[i] != 64) && (!(s1[i] >= 35 && s1[i] <= 37)) && (!(s1[i] >= 48 && s1[i] <= 57)) && !(s1[i] >= 65 && s1[i] <= 90)
            && !(s1[i] >= 97 && s1[i] <= 122)) {//Xuat hien ky tu khac da quy uoc
            pos1 = i;
            return i;
        }
    }
    for(int i = 0; i < s1.size(); i++) {
        if((s1[i] == 33) || (s1[i] == 64) || (s1[i] >= 35 && s1[i] <= 37)) {
            spe = 1;
            break;
        }
    }
    if(spe != 1) {return -5;} //Khong co ky tu dac biet
    bool check = false;
    for(int i = 0; i <= s1.size() - 3; i++) {
        if(s1[i] == s1[i+1]) {
            if (s1[i] == s1[i+2]){
            check = true;
            sci = i;
            }
        }
    } //Co nhieu hon 2 ky tu lien tiep trung nhau
    if(check == true) {return -(400+sci);}
    if(se.size() < s1.size()) {
    for(int i = 0; i <= s1.size() - se.size();i++) {
        if(se == s1.substr(i,se.size())){
            return -(300 + i);
        }
    }
    }//Xuat hien se trong chuoi s
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string s[num_pwds];
    int Appear[100];//Luu tru so lan xuat hien;
    int Length[100];//Luu tru do dai xau;
    for(int i = 0; i < num_pwds; i++) {
        s[i] = arr_pwds[i];
        Appear[i] = 1;
        Length[i] = s[i].size();
    }
    for(int i = 0; i < num_pwds - 1; i++) {
        if(s[i] == "#") {
            Appear[i] = -1;
            Length[i] = s[i].size();
        } else {
            for(int j = i + 1; j < num_pwds; j++) {
                if(s[i] == s[j]){
                    s[j] = "#";
                    Appear[i]++;
                }
            }
        }
    }
    if(s[num_pwds - 1] == "#") {
        Appear[num_pwds - 1] = -1;
        Length[num_pwds - 1] = 1;
    }
    int Max = Appear[0];
    int k,res;
    for(int i = 0; i < num_pwds; i++) {
        if(Max < Appear[i]) {
            Max = Appear[i];
            k = Length[i];
            res = i;
        }
    }
    for(int i = 0; i < num_pwds; i++) {
        if(Max == Appear[i]) {
            for(int j = i; j < num_pwds; j++){
                if(Appear[i] == Appear[j]){
                    if(k < Length[j]) {
                        k = Length[j];
                        res = j;
                    }
                }
            }
        }
    }
    return res;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////