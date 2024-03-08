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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0||e1>99) return -99;

    if (exp1>=600) exp1=600; if (exp1<=0) exp1=0;
    if (exp2>=600) exp2=600; if (exp2<=0) exp2=0;

    if (0 <= e1 && e1 <= 4) {
        if (e1==0) exp2 += 29;
        else if (e1==1) exp2 += 45;
        else if (e1==2) exp2 += 75;
        else if (e1==3) exp2 += (29+45+75);

        int D = e1*3 + exp1*7;
        if (D%2==0) exp1 = ceil((float)exp1 + ((float)D/200)); else exp1 = ceil((float)exp1 - ((float)D/100));

    } else {
        if (4 <= e1 && e1 <= 19) exp2 += ceil((float)e1/4+19);
        else if (e1 <= 49) exp2 += ceil((float)e1/9+21);
        else if (e1 <= 65) exp2 += ceil((float)e1/16+17);
        else if (e1 <= 79) {
            exp2 += ceil((float)e1/4+19);
            if (exp2 > 200) exp2 += ceil((float)e1/9+21);
        }
        else if (e1 <= 99) {
            exp2 += ceil((float)e1/4+19) + ceil((float)e1/9+21);
            if (exp2 > 400) {
                exp2 += ceil((float)e1/9+21);
                exp2 = ceil(exp2*1.15);
            }
        }
        exp1 -= e1;
    }
    if (exp1>=600) exp1=600; if (exp1<=0) exp1=0;
    if (exp2>=600) exp2=600; if (exp2<=0) exp2=0;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
        // CON DUONG 1
        if (E2<0||E2>99) return -99;
        if (M1>=3000) M1=3000; if (M1<=0) M1=0;
        if (HP1>=666) HP1=666; if (HP1<=0) HP1=0;
        if (EXP1>=600) EXP1=600; if (EXP1<=0) EXP1=0;

        float S = 0;
        float P1;
        while (S * S <= EXP1) {S++;} S = (S-1) * (S-1);
        if (abs(EXP1 - S) < abs((sqrt(S) + 1) * (sqrt(S) + 1) - EXP1)) P1 = 1;
        else if (S == EXP1) P1 = 1;
        else {
            S = (sqrt(S) + 1) * (sqrt(S) + 1);
            P1 = ((float)EXP1 / S + 80) / 123;
        }

        // CON DUONG 2
    if (M1>=3000) M1=3000; if (M1<=0) M1=0;
    if (HP1>=666) HP1=666; if (HP1<=0) HP1=0;
    if (EXP1>=600) EXP1=600; if (EXP1<=0) EXP1=0;
        float temp = M1*0.5;
    if (M1>0) {
        if (E2 % 2 == 1) {
            while(true) {
                //SU KIEN 1
                if (HP1 < 200) {
                    HP1 = ceil((float)(HP1 * 1.3));
                    M1 -= 150;
                } else {
                    HP1 = ceil((float)(HP1 * 1.1));
                    M1 -= 70;
                }
                if (M1 >= 3000) M1 = 3000; if (M1 <= 0) M1 = 0;
                if (HP1 >= 666) HP1 = 666; if (HP1 <= 0) HP1 = 0;

                if (M1 <= temp) break;

                //SU KIEN 2
                if (EXP1 < 400) M1 -= 200; else M1 -= 120;
                EXP1 = ceil((float)(EXP1 * 1.13));

                if (EXP1 >= 600) EXP1 = 600; if (EXP1 <= 0) EXP1 = 0;

                if (M1 <= temp) break;

                //SU KIEN 3
                if (EXP1 < 300) M1 -= 100; else M1 -= 120;
                EXP1 = ceil((float)(EXP1 * 0.9));

                if (M1 >= 3000) M1 = 3000; if (M1 <= 0) M1 = 0;
                if (EXP1 >= 600) EXP1 = 600; if (EXP1 <= 0) EXP1 = 0;

                if (M1 <= temp) break;
            }
        } else {
            for (int i = 0; i<1; i++) {
                //SU KIEN 1
                if (HP1 < 200) {
                    HP1 = ceil((float)(HP1 * 1.3));
                    M1 -= 150;
                } else {
                    HP1 = ceil((float)(HP1 * 1.1));
                    M1 -= 70;
                }
                if (HP1 >= 666) HP1 = 666;
                if (HP1 <= 0) HP1 = 0;
                if (M1 <= 0) break;

                //SU KIEN 2
                if (EXP1 < 400) M1 -= 200; else M1 -= 120;
                EXP1 = ceil((float)(EXP1 * 1.13));

                if (EXP1 >= 600) EXP1 = 600;
                if (EXP1 <= 0) EXP1 = 0;
                if (M1 <= 0) break;

                //SU KIEN 3
                if (EXP1 < 300) M1 -= 100; else M1 -= 120;
                EXP1 = ceil((float)(EXP1 * 0.9));

                if (EXP1 >= 600) EXP1 = 600;
                if (EXP1 <= 0) EXP1 = 0;
                if (M1 <= 0) break;
            }
        }
    }
        HP1 = ceil((float)(HP1 * 0.83));
        EXP1 = ceil((float)(EXP1 * 1.17));
        if (HP1>=666) HP1=666; if (HP1<=0) HP1=0;
        if (EXP1>=600) EXP1=600; if (EXP1<=0) EXP1=0;

        S = 0;
        float P2;
        while (S * S <= EXP1) {S++;}
        S = (S-1) * (S-1);
        if (abs(EXP1 - S) < abs((sqrt(S) + 1) * (sqrt(S) + 1) - EXP1)) P2 = 1;
        else if (S == EXP1) P2 = 1;
        else {
            S = (sqrt(S) + 1) * (sqrt(S) + 1);
            P2 = ((float)EXP1 / S + 80) / 123;
        }

        //CON DUONG 3
    if (M1>=3000) M1=3000; if (M1<=0) M1=0;
    if (HP1>=666) HP1=666; if (HP1<=0) HP1=0;
    if (EXP1>=600) EXP1=600; if (EXP1<=0) EXP1=0;
        float arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        float P3;

        if (E2 < 10) {P3 = arr[E2] * 0.01;
        } else {P3 = arr[(E2/10 + E2%10)%10] * 0.01;}

        //TINH XAC SUAT
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = ceil((float)(EXP1 * 0.75));
        } else {
            float P = (P1 + P2 + P3) / 3;
            if (P < 0.5) {
                HP1 = ceil((float)(HP1 * 0.85));
                EXP1 = ceil((float)(EXP1 * 1.15));
            } else {
                HP1 = ceil((float)(HP1 * 0.9));
                EXP1 = ceil((float)(EXP1 * 1.2));
            }
        }
        if (M1>=3000) M1=3000; if (M1<=0) M1=0;
        if (HP1>=666) HP1=666; if (HP1<=0) HP1=0;
        if (EXP1>=600) EXP1=600; if (EXP1<=0) EXP1=0;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0||E3>99) return -99;
    if (EXP1>=600) EXP1=600; if (EXP1<=0) EXP1=0;
    if (EXP2>=600) EXP2=600; if (EXP2<=0) EXP2=0;
    if (HP1>=666) HP1=666; if (HP1<=0) HP1=0;
    if (HP2>=666) HP2=666; if (HP2<=0) HP2=0;

    int a[10][10];
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9;j++){
            a[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    int b[10][10];
    for(int i=0; i<=9; i++) {
        for (int j = 0; j <= 9; j++) {
            b[i][j] = a[i][j];
        }
    }
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9;j++){
            for(int temp=0; temp<=9; temp++) {
                if (a[i + temp][j + temp] > b[i][j])
                    b[i][j] = a[i + temp][j + temp];
                if ((i+temp)==9 || (j+temp==9)) break;
            }
            for(int temp=0; temp<=9; temp++) {
                if (a[i - temp][j - temp] > b[i][j])
                    b[i][j] = a[i - temp][j - temp];
                if ((i-temp)==0 || (j-temp==0)) break;
            }
            for(int temp=0; temp<=9; temp++) {
                if (a[i + temp][j - temp] > b[i][j])
                    b[i][j] = a[i + temp][j - temp];
                if ((i+temp)==9 || (j-temp==0)) break;
            }
            for(int temp=0; temp<=9; temp++) {
                if (a[i - temp][j + temp] > b[i][j])
                    b[i][j] = a[i - temp][j + temp];
                if ((i-temp)==0 || (j+temp==9)) break;
            }
            b[i][j] = abs(b[i][j]);
        }
    }
    int count1 = 0;
    int count2 = 0;
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9;j++){
            if(a[i][j]>(2*E3)) count1++;
            if(a[i][j]<(0-E3)) count2++;
        }
    }
    if (count1>=10) count1 = (count1/10 + count1%10);
    if (count1>=10) count1 = (count1/10 + count1%10);
    if (count2>=10) count2 = (count2/10 + count2%10);
    if (count2>=10) count2 = (count2/10 + count2%10);

    if (abs(a[count1][count2]) > b[count1][count2]){
        EXP1 = ceil((float)(EXP1*0.88));
        EXP2 = ceil((float)(EXP2*0.88));
        HP1 = ceil((float)(HP1*0.9));
        HP2 = ceil((float)(HP2*0.9));
        if (EXP1>=600) EXP1=600; if (EXP1<=0) EXP1=0;
        if (EXP2>=600) EXP2=600; if (EXP2<=0) EXP2=0;
        if (HP1>=666) HP1=666; if (HP1<=0) HP1=0;
        if (HP2>=666) HP2=666; if (HP2<=0) HP2=0;
        return a[count1][count2];
    } else {
        EXP1 = ceil((float)(EXP1*1.12));
        EXP2 = ceil((float)(EXP2*1.12));
        HP1 = ceil((float)(HP1*1.1));
        HP2 = ceil((float)(HP2*1.1));
        if (EXP1>=600) EXP1=600; if (EXP1<=0) EXP1=0;
        if (EXP2>=600) EXP2=600; if (EXP2<=0) EXP2=0;
        if (HP1>=666) HP1=666; if (HP1<=0) HP1=0;
        if (HP2>=666) HP2=666; if (HP2<=0) HP2=0;
        return b[count1][count2];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string e = email;
    string se = e.erase(strlen(email)-10, strlen(email)-1);

    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;

    int temp = 0;

    for (int i=0; i<strlen(s); i++){
        if(s[i] == se[0]){
            string s_ = s;
            string tam = s_.substr(i,se.length());
            if(tam == se) {
                temp = -(300+i);
            }
        }
        if (temp !=0) {break; return temp;}
    }
    if (temp != 0) return temp;

    for (int i=0; i<strlen(s)-2; i++){
        if(s[i] == s[i+1] && s[i+1] == s[i+2]) {
            temp = -(400+i);
            break;
        }
    }
    if (temp != 0) return temp;

    for (int i=0; i<strlen(s); i++){
        if(s[i] == '@'||s[i] == '#'||s[i] == '%'||s[i] == '$'||s[i] == '!') {
            temp++;
            break;
        }
    }
    if (temp == 0) return -5;

    temp = 0;
    for (int i=0; i<strlen(s); i++){
        if(s[i] != '@'&& s[i] != '#'&& s[i] != '%'&& s[i] != '$'&& s[i] != '!'
          && (s[i]<48 || s[i]>122 || (s[i]>57 && s[i]<65) || (s[i]>90 && s[i]<97))) {
            temp += i;
            break;
        }
    }
    if (temp != 0) return temp;

    return -10;
}

int count(string c, string arr[], int length){
    int count = 0;
    for (int i = 0; i < length; i++){
        if (arr[i] == c) count++;
    }
    return count;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string temp[num_pwds];
    for (int i = 0; i < num_pwds; i++){temp[i] = (string)arr_pwds[i];}

    string ans; int max = 1;

    for (int i = 0; i < num_pwds; i++){
        if(count(temp[i], temp, num_pwds) > max) {
            max = count(temp[i], temp, num_pwds);
        }
    }
    for (int i = 0; i < num_pwds; i++){
        if(count(temp[i], temp, num_pwds) == max && temp[i].length() > ans.length())
            ans = temp[i];
    }
    int sol = 0;
    for (int i = 0; i < num_pwds; i++){
        if(temp[i] == ans) {
            sol = i;
            break;
        }
    }
    return sol;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////