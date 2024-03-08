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


int findOtherChar(string s) {
    for (char c : s) {
        if (!(isdigit(c) || islower(c) || isupper(c) ||
              c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return s.find(c);
            break; // Nếu có ký tự không thuộc các loại đã nêu
        }
    }
    return -1; // Nếu tất cả các ký tự đều thuộc các loại đã nêu
}

int findRepeatedString(string s){
    for (int i = 0; i<(s.length() - 2); i++){
        if ((s[i]==s[i+1]) && (s[i]==s[i+2])){
            return s.find(s.substr(i,3));
        }
    }
    return -1;
}

bool findSpecialChar (string s){
    for (char i : s){
        if ((i=='@') || (i=='#') || (i=='%') || (i=='$') || (i=='!')){
            return 1;
            break;
        }
    }
    return 0;
}
int sumofDigits(int n){
    int sum = 0;
    while (n>0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}
void update1HP(int &HP){
    if (HP > 666) HP = 666;
    else if (HP < 0) HP = 0;
}
void update1EXP(int &EXP){
    if (EXP > 600) EXP = 600;
    else if (EXP < 0) EXP = 0;
}
void update1M(int &M){
    if (M > 3000) M = 3000;
    else if (M < 0) M = 0;
}
void updateHP(int &HP1, int &HP2){
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (HP2 > 666) HP2 = 666;
    else if (HP2 < 0) HP2 = 0;
}
void updateEXP(int &EXP1, int &EXP2){
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    else if (EXP2 < 0) EXP2 = 0;
}
void updateM(int &M1, int &M2){
    if (M1 > 3000) M1 = 3000;
    else if (M1 < 0) M1 = 0;
    if (M2 > 3000) M2 = 3000;
    else if (M2 < 0) M2 = 0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    if ((e1<0) || (e1>99)) return -99;
    else{
        int D = 0;
        if (e1==0) {
            exp2 += 29;
            D += (e1 * 3 + exp1 * 7);
            if (D%2 == 0) exp1 += ceil(D/200.0);
            else exp1 = ceil(exp1 - (D/100.0));
        }
        else if (e1==1){
            exp2 +=45;
            D += (e1 * 3 + exp1 * 7);
            if (D%2 == 0) exp1 += ceil(D/200.0);
            else exp1 = ceil(exp1 - (D/100.0));
        }
        else if (e1==2) {
            exp2 +=75;
            D += (e1 * 3 + exp1 * 7);
            if (D%2 == 0) exp1 += ceil(D/200.0);
            else exp1 = ceil(exp1 - (D/100.0));
        }
        else if (e1==3) {
            exp2 +=149;
            D += (e1 * 3 + exp1 * 7);
            if (D%2 == 0) exp1 += ceil(D/200.0);
            else exp1 = ceil(exp1 - (D/100.0));
        }
        else if ((e1>=4) && (e1<=19)) {
            exp2 += ceil((e1/4.0) + 19);
            exp1 -= e1;
        }
        else if ((e1>=20) && (e1<=49)) {
            exp2 += ceil((e1/9.0) + 21);
            exp1 -= e1;
        }
        else if ((e1>=50) && (e1<=65)) {
            exp2 += ceil((e1/16.0) + 17);
            exp1 -= e1;
        }
        else if ((e1>=66) && (e1<=79)){
            exp2 += ceil((e1/4.0) + 19);
            if (exp2 > 200) exp2 += ceil((e1/9.0) + 21);
            exp1 -= e1;
        }
        else if ((e1>=80) && (e1<=99)) {
            exp2 += ceil((e1/4.0) + 19);
            exp2 += ceil((e1/9.0) + 21);
            if (exp2 >400) {
                exp2 += ceil((e1/16.0) + 17);
                exp2 += ceil(exp2*0.15);
            }
            exp1 -= e1;
        }
        updateEXP(exp1, exp2);
        return exp1 + exp2;
    }
    //TODO: implement task
}

// Task 2
int traceLuggage(int & hp1, int & exp1, int & m1, int e2){
    if ((e2<0) || (e2>99)) return -99;
    else{
        int s1, s2;
        s1 = pow(round(sqrt(exp1)), 2);  //Con đường 1
        double p1, p2, p3;
        if (exp1 >= s1) p1 = 1;
        else p1 = ((double(exp1)/s1) + 80)/123.0;


        int sum = 0; float mroot = m1 *0.5;  //Con đường 2
        if (e2%2 != 0){
            while(sum <= mroot){
                if(hp1 < 200){
                    hp1 += int(0.999+hp1*0.3/1.00);
                    m1 -= 150; sum += 150;
                }
                else{
                    hp1 += int(0.999+hp1*0.1/1.00);
                    m1 -= 70; sum += 70;
                }
                update1HP(hp1); update1M(m1);
                if(sum > mroot) break;

                if (exp1 < 400){
                    exp1 += int(0.999+exp1*0.13/1.00);
                    m1 -= 200; sum += 200;
                }
                else{
                    exp1 += int(0.999 + exp1*0.13/1.00);
                    m1 -= 120; sum += 120;
                }
                update1EXP(exp1); update1M(m1);
                if(sum > mroot) break;

                if (exp1 <300){
                    exp1 = int(0.999+ exp1*0.9/1.00);
                    m1 -= 100; sum += 100;
                }
                else{
                    exp1 = int(0.999+ exp1*0.9/1.00);
                    m1 -= 120; sum += 120;
                }
                update1M(m1);
            }
            hp1 = int(0.999+hp1*0.83/1.00); exp1 += int(0.999+ exp1*0.17/1.00);
            update1EXP(exp1);
        }
        else{
            if (m1 > 0){
                if(hp1 < 200){
                    hp1 += int(0.999+hp1*0.3/1.00);
                    m1 -= 150;
                }
                else{
                    hp1 += int(0.999+ hp1*0.1/1.00);
                    m1 -= 70;
                }
                update1HP(hp1);
            }
            else{
                goto here;
            }


            if (m1 > 0){
                if (exp1 < 400){
                    exp1 += int(0.999+exp1*0.13/1.00);
                    m1 -= 200;
                }
                else{
                    exp1 += int(0.999+exp1*0.13/1.00);
                    m1 -= 120;
                }
                update1EXP(exp1);
            }
            else{
                goto here;
            }


            if (m1 > 0){
                if (exp1 < 300){
                    exp1 = int(0.999+ exp1*0.9/1.00);
                    m1 -= 100;
                }
                else{
                    exp1 = int(0.999+ exp1*0.9/1.00);
                    m1 -= 120;
                }
            }
            else{
                goto here;
            }
            here: 
            hp1 = int(0.999+ hp1*0.83/1.00); exp1 += int(0.999+ exp1*0.17/1.00);
            update1EXP(exp1); update1M(m1);
        }
        update1EXP(exp1); update1HP(hp1); update1M(m1);
        s2 = pow(round(sqrt(exp1)), 2);
        if (exp1 >= s2) p2 = 1;
        else p2 = ((double(exp1)/s2) + 80)/123.0;

        double p[10]={0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};  //Con đường 3
        p3 = p[sumofDigits(e2)%10];
        if ((p1==1) && (p2==1) && (p3==1)) {
            exp1 = int(0.999+ exp1*0.75/1.00);
        }
        else {
            double finalp = (p1 + p2 + p3)/3.0;
            if (finalp < 0.5){
                hp1 = int(0.999+ hp1*0.85/1.00); exp1 += int(0.999+ exp1*0.15/1.00);
                update1EXP(exp1);
            }
            else{
                hp1 = int(0.999+ hp1*0.9/1.00); exp1 += int(0.999+ exp1*0.2/1.00);
                update1EXP(exp1);
            }
        }
        return hp1 + exp1 + m1;
    }
}

// Task 3
int chaseTaxi(int & hp1, int & exp1, int & hp2, int & exp2, int e3)
{
    if ((e3<0) || (e3>99)) return -99;
    else{
        int sumOfi = 0; int sumOfj = 0;
        signed int a[10][10] = {};
        for (int i = 0; i<10; i++){
            for (int j =0; j<10; j++){
                a[i][j] = ((e3 * j) + (i*2))*(i-j);
                if(a[i][j] > (e3*2)) sumOfi++;
                else if(a[i][j] < (-e3)) sumOfj++;
            }
        }
        while(sumOfi>=10) sumOfi = sumofDigits(sumOfi);
        while(sumOfj>=10) sumOfj = sumofDigits(sumOfj);

        int SWPoint = 0;
        int taxiPoint = a[sumOfi][sumOfj];

        if (sumOfi<sumOfj){
            while((sumOfi<=9) && (sumOfj>=0)){
                if (a[sumOfi][sumOfj]> SWPoint) SWPoint = a[sumOfi][sumOfj];
                sumOfi++; sumOfj--;
            }
        }
        else{
            SWPoint = a[9][9-(sumOfi-sumOfj)];
            while((sumOfi<9) && (sumOfj>0)){
                sumOfi++; sumOfj--;
            }
            while(sumOfi>sumOfj){
                if (a[sumOfi][sumOfj]> SWPoint) SWPoint = a[sumOfi][sumOfj];
                sumOfi--; sumOfj++;
            }
        }

        if (abs(SWPoint) < abs(taxiPoint)){
            exp1 = ceil(exp1*0.88); exp2 = ceil(exp2*0.88);
            hp1 = ceil(hp1*0.9); hp2 = ceil(hp2*0.9);
            return taxiPoint;
        }
        else{
            exp1 += ceil(exp1*0.12); exp2 += ceil(exp2*0.12);
            hp1 += ceil(hp1*0.1); hp2 += ceil(hp2*0.1);
            updateEXP(exp1,exp2); updateHP(hp1,hp2);
            return SWPoint;
        }
    }
    //TODO: implement task
}

// Task 4
int checkPassword(const char * s, const char * email){
    string se;
    string sStr(s);
    int k = 0;
    while(*(email+k) != '@'){
        se.push_back(*(email+k));
        k++;
    }
    if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;
    else if (sStr.find(se) != string::npos) return -(300 + sStr.find(se));
    else if (findRepeatedString(sStr) != -1) return -(400 + findRepeatedString(sStr));
    else if (findSpecialChar(sStr) == 0) return -5;
    else if (findOtherChar(sStr) != -1) return findOtherChar(sStr);
    else return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
    int countMax = 0; int vitri=0;
    for (int i = 0; i<num_pwds; i++){
        int count1 = 1;
        for (int j = i+1; j<num_pwds; j++){
            if (strcmp(arr_pwds[i],arr_pwds[j]) == 0){
                count1++;
            }
        }
        if (count1>countMax) {
            vitri = i;
            countMax = count1;
        }
        else if (count1== countMax){
            if(strlen(arr_pwds[i])>strlen(arr_pwds[vitri])){
                vitri = i;
            }
        }
    }
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////