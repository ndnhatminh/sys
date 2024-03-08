#include "study_in_pink1.h"

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
void rsvl(int& gt, int minn, int maxx) {
    if (gt < minn) {
        gt = minn;
    };
    if (gt > maxx) {
        gt = maxx;
    };
}


// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    if ((E1 < 0) || (E1 > 99)) { return -99; }
    //1.
     switch (E1) {
    case 0:
        EXP2 = EXP2 + 29;rsvl(EXP2, 0, 600);
        break;
    case 1:
        EXP2 = EXP2 + 45;rsvl(EXP2, 0, 600);
        break;
    case 2:
        EXP2 = EXP2 + 75;rsvl(EXP2, 0, 600);
        break;
    case 3:
        EXP2 = EXP2 + 149;rsvl(EXP2, 0, 600);
        break;
    }
    if ((E1 >= 0) && (E1 < 4)) {
         int D = E1 * 3 + EXP1 * 7; int o = ceil(D *1.0/ 200);double y = D/ 100;
        if (D % 2 == 0) { EXP1 = EXP1 + o;rsvl(EXP1, 0, 600); }
        else { EXP1 = ceil(EXP1 - y);rsvl(EXP1, 0, 600); };
    }
    //2.
    if (E1 >= 4 && E1 <= 19) { EXP2 = EXP2 + ceil(E1 * 1.000 / 4) + 19;rsvl(EXP2, 0, 600); }
    else if ((E1 >= 20) && (E1 <= 49)) {
        EXP2 = EXP2 + ceil(E1 * 1.000 / 9) + 21;rsvl(EXP2, 0, 600);
    }
    else if (E1 >= 50 && E1 <= 65) {
        EXP2 = EXP2 + ceil(E1 * 1.000 / 16) + 17;rsvl(EXP2, 0, 600);
    }
    else if (E1 >= 66 && E1 <= 79) {
        EXP2 = EXP2 + ceil(E1 * 1.000 / 4) + 19;rsvl(EXP2, 0, 600);
        if (EXP2 > 200) {
            EXP2 = EXP2 + ceil(E1 * 1.000 / 9) + 21;rsvl(EXP2, 0, 600);
        }
        else EXP2 = ceil(EXP2);
    }
    else if (E1 >= 80 && E1 <= 99) {
        EXP2 = EXP2 + ceil(E1 * 1.000 / 9) + 40 + ceil(E1 * 1.000 / 4);rsvl(EXP2, 0, 600);
        if (EXP2 > 400) {
            EXP2 = EXP2 + ceil(E1 * 1.000 / 16) + 17;rsvl(EXP2, 0, 600);EXP2 = ceil(EXP2 * 1.15);rsvl(EXP2, 0, 600);
        }
        else EXP2 = ceil(EXP2);
    }
    if (E1 >= 4 && E1 <= 99) { EXP1 = EXP1 - E1;rsvl(EXP1, 0, 600); }
    return EXP1 + EXP2;

}

// Task 2
double xs(int EXP1){
    double p;
    int nh = sqrt(EXP1);
    int lh = nh + 1;
    int kc1 = EXP1 - (nh * nh);
    int kc2 = (lh * lh) - EXP1;
    double s = lh * lh;
if (kc1 < kc2) { p = 1; }
    else  p = (EXP1 * 1.0 / s + 80) / 123;
    return p;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
if ((E2 < 0) || (E2 > 99)) { return -99; }
    //CON DUONG 1:
    double p1,p2,p3;
    int temp1,temp2,temp3;
    temp2=HP1;temp3=M1;
 do {
     temp1=EXP1;
     //CON DUONG 1:
    p1=xs(EXP1);
    //CON DUONG 2:
    int u=M1/2;
    if (E2%2 !=0){
        while (M1>u){
            if (M1>u){
                if (HP1<200){HP1=ceil(HP1*1.3);rsvl(HP1,0,666); M1=M1-150;}
                else {HP1=ceil(HP1*1.1);rsvl(HP1,0,666); M1=M1-70;}
            } else break;
            if (M1>u){if (EXP1<400){M1=M1-200;} else {M1=M1-120;} EXP1=ceil(EXP1*1.13); rsvl(EXP1,0,600);} else break;
            if (M1>u){if (EXP1<300){M1=M1-100;} else {M1=M1-120;} EXP1=ceil(EXP1*0.9); rsvl(EXP1,0,600);} else break;
        }
        HP1=ceil(HP1*0.83); EXP1=ceil(EXP1*1.17);rsvl(EXP1,0,600);
    } else {
        for (int i=0;i<1;i++){
        if (M1>0){
                if (HP1<200){HP1=ceil(HP1*1.3);rsvl(HP1,0,666); M1=M1-150;rsvl(M1,0,3000);}
                else {HP1=ceil(HP1*1.1);rsvl(HP1,0,666); M1=M1-70;rsvl(M1,0,3000);}
            } else {M1=0;break;}
        if (M1>0){if (EXP1<400){M1=M1-200;rsvl(M1,0,3000);} else {M1=M1-120;rsvl(M1,0,3000);} EXP1=ceil(EXP1*1.13); rsvl(EXP1,0,600);} else {M1=0;break;}
        if (M1>0){if (EXP1<300){M1=M1-100;rsvl(M1,0,3000);} else {M1=M1-120;rsvl(M1,0,3000);} EXP1=ceil(EXP1*0.9); rsvl(EXP1,0,600);} else {M1=0;break;}
        }
          HP1=ceil(HP1*0.83); EXP1=ceil(EXP1*1.17);rsvl(EXP1,0,600);
    }
  p2=xs(EXP1);
  //CON DUONG 03
  double P[10]={0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
  if ((E2<10)&&(E2>=0)){p3=P[E2];} else {
      int a= (int(E2/10)+E2%10)%10;
      p3=P[a];
  }
  if ((p1+p2+p3)==3){EXP1=ceil(temp1*0.75);HP1=temp2;M1=temp3;}
   } while ((p1+p2+p3)==3);
  double p=(p1+p2+p3)/3; 
  if (p<0.5){HP1=ceil(HP1*0.85); EXP1=ceil(EXP1*1.15); rsvl(EXP1,0,600);}
  else {HP1=ceil(HP1*0.9); EXP1=ceil(EXP1*1.2); rsvl(EXP1,0,600);}
    return HP1 + EXP1 + M1;
}

// Task 3
int s(int n) {
    while (n > 9) { n = n / 10 + n % 10; }
    return n;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    //
    if ((E3 < 0) || (E3 > 99)) { return -99; }
    int m[10][10];
    int dem1 = 0; int dem2 = 0;
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            m[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            if (m[i][j] > (2 * E3)) { dem1++; }
            if (m[i][j] < (-E3)) { dem2++; }
        }
    }
    int i = s(dem1);
    int j = s(dem2);
    int taxi = m[i][j];
    int max = m[i][j];
    //
    int x = 0, y = 0;
    while ((i + x >= 0) && (j + y >= 0) && (x + i < 10) && (y + j < 10)) {
        if (m[i + x][j + y] > max) { max = m[i + x][j + y]; }
        x++; y++;
    }
    x = 0;y = 0;
    while ((i + x >= 0) && (j + y >= 0) && (x + i < 10) && (y + j < 10)) {
        if (m[i + x][j + y] > max) { max = m[i + x][j + y]; }
        x--; y--;
    }
    x = 0;y = 0;
    while ((i + x >= 0) && (j + y >= 0) && (x + i < 10) && (y + j < 10)) {
        if (m[i + x][j + y] > max) { max = m[i + x][j + y]; }
        x++; y--;
    }
    x = 0;y = 0;
    while ((i + x >= 0) && (j + y >= 0) && (x + i < 10) && (y + j < 10)) {
        if (m[i + x][j + y] > max) { max = m[i + x][j + y]; }
x--; y++;
    }
    if (abs(taxi) > max) {
        EXP1 = ceil(EXP1 * 0.88);EXP2 = ceil(EXP2 * 0.88); HP1 = ceil(HP1 * 0.9);HP2 = ceil(HP2 * 0.9);rsvl(EXP1, 0, 600);rsvl(EXP2, 0, 600);rsvl(HP1, 0, 666);rsvl(HP2, 0, 666);
        return taxi;
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);EXP2 = ceil(EXP2 * 1.12); HP1 = ceil(HP1 * 1.1);HP2 = ceil(HP2 * 1.1);rsvl(EXP1, 0, 600);rsvl(EXP2, 0, 600);rsvl(HP1, 0, 666);rsvl(HP2, 0, 666);
        return max;
    };
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string se;
    string email1 = email;
    string s1 = s;
    for (int i = 0;i < email1.length();i++) { if (email1[i] == '@') { se = email1.substr(0, i); } }
    //check chieu dai
    if (s1.length() < 8) { return -1; }
    //
    if (s1.length() > 20) { return -2; }
    //check sei
    for (int i = 0;i < s1.length();i++) {
        if (s1[i] == se[0]) { if (se == s1.substr(i, se.length())) { return -(300 + i); } }
    }
    //check sci
    for (int i = 0;i < s1.length() - 2;i++) {
        if ((s1[i] == s1[i + 1])&&(s1[i]==s1[i+2])) { return -(400 + i); }
    };
    // check ktdb
    int dem = 0;
    for (int i = 0;i < s1.length();i++) {
        if ((s1[i] == '@') || (s1[i] == '!') || (s1[i] == '#') || (s1[i] == '$') || (s1[i] == '%')) {  dem++; }
    }
    if (dem == 0) { return -5; }
//th con lai
    for (int i = 0;i < s1.length();i++) {
        if ((s1[i] < 33) || (s1[i] == 34) || ((s1[i] > 37) && (s1[i] < 48)) || ((s1[i] > 57) && (s1[i] < 64)) || ((s1[i] > 90) && (s1[i] < 97)) || (s1[i] > 122)) { return i; };
    };

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int m[num_pwds + 1];
    int max1, max2, idx;
    for (int i = 0;i < num_pwds;i++) { m[i] = 0; }
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0;j < num_pwds;j++) {
            if (arr_pwds[i] == arr_pwds[j]) { m[i]++; }
        }
    }
    max1 = strlen(arr_pwds[0]); max2 = m[0];idx = 0;
    for (int i = 1;i < num_pwds;i++) {
        if (m[i] > max2) { max1 = strlen(arr_pwds[i]); max2 = m[i]; idx = i; }
    }
    for (int i = 0;i < num_pwds;i++) {
        if (m[i] == max2) {
            if (strlen(arr_pwds[i]) > max1) { idx = i; max1 = strlen(arr_pwds[i]); }
        }
    }

    return idx;


}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////