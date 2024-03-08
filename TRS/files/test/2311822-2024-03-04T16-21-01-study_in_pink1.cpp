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

void CheckHP1(int &HP1){
    if (HP1>666) HP1=666;
    else if (HP1<0) HP1=0;}
void CheckHP2(int &HP2){
    if (HP2>666) HP2=666;
    else if (HP2<0) HP2=0;}
void CheckEXP1(int & EXP1){
    if (EXP1>600) EXP1=600;
    else if (EXP1<0) EXP1=0;}
void CheckEXP2(int & EXP2){
    if (EXP2>600) EXP2=600;
    else if (EXP2<0) EXP2=0;}
void CheckM1(int & M1) {
    if (M1>3000) M1=3000;
    else if (M1<0) M1=0;}
void CheckM2(int & M2) {
    if (M2>3000) M2=3000;
    else if (M2<0) M2=0;}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if (E1<0) return -99;
    else if (E1>99) return -99;
    CheckEXP1(EXP1);
    CheckEXP2(EXP2);
    int D;
    if (E1<=3){
        switch(E1) {
            case 0:
                EXP2 += 29;
                break;
            case 1:
                EXP2 += 45;
                break;
            case 2:
                EXP2 += 75;
                break;
            case 3:
                EXP2 += 149;
                break;
    }
        D = E1*3 + EXP1*7;
        if (D%2==0) EXP1 = ceil((float)EXP1 + (float)D/200);
        else EXP1 = ceil((float)EXP1 - (float)D/100);
    }
    else if (E1<=19) {
        EXP2 =ceil(static_cast<float>(EXP2) + E1/4.0 + 19.0);
        EXP1 -= E1;
    }
    else if (E1<=49) {
        EXP2 =ceil(static_cast<float>(EXP2) + E1/9.0 + 21.0);
        EXP1 -= E1;
    }
    else if (E1<=65) {
        EXP2 =ceil(static_cast<float>(EXP2) + E1/16.0 + 17.0);
        EXP1 -= E1;
    }
    else if (E1<=79) {
        EXP2 =ceil(static_cast<float>(EXP2) + E1/4.0 + 19.0);
        if (EXP2 > 200) {
            EXP2 =ceil(static_cast<float>(EXP2) + E1/9.0 + 21.0);
        }
        EXP1 -= E1;
    }
    else if (E1<=99) {
        EXP2 =ceil(static_cast<float>(EXP2) + E1/4.0 + 19.0);
        EXP2 =ceil(static_cast<float>(EXP2) + E1/9.0 + 21.0);
        if (EXP2 > 400) {
            EXP2 =ceil(static_cast<float>(EXP2) + E1/16.0 + 17.0);
            EXP2 =ceil((float) EXP2*1.15);
        }
        EXP1 -= E1;
    }
    CheckEXP1(EXP1);
    CheckEXP2(EXP2);
    return EXP1 + EXP2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Way 1
    if (E2<0) return -99;
    else if (E2>99) return -99;
    // Tim so chinh phuong
    CheckHP1(HP1);
    CheckEXP1(EXP1);
    CheckM1(M1);
    double A1;
    A1 = sqrt(EXP1);
    int S1;
    S1 = static_cast<int>(round(A1));
    S1*=S1;
    // Tinh toan
    double P1;
    if (EXP1>=S1) P1 = 1;
        else P1 = ((double)(EXP1/S1) + 80 ) / 123;
    //Way 2
    if (E2%2==1) {
        float C = 0, D;
        D=M1*0.5;
        while (true) {
            if (M1==0) break;
            if (HP1 < 200) {HP1 =ceil(static_cast<float>(HP1) + HP1 * 0.3); M1-=150; C+=150;}
            else {HP1 =ceil(static_cast<float>(HP1)+HP1*0.1); M1-=70; C+=70;}
            CheckHP1(HP1);
            if (C>D) break;
            if (M1==0) break;
            if (EXP1 < 400) {M1-=200; EXP1 =ceil(static_cast<float>(EXP1) + EXP1*0.13); C+=200;}
            else{M1-=120; EXP1 =ceil(static_cast<float>(EXP1) + EXP1*0.13); C+=120;}
            CheckEXP1(EXP1);
            if (C>D) break;
            if (M1==0) break;
            if (EXP1 < 300) {M1-=100; EXP1 =ceil(static_cast<float>(EXP1) - EXP1*0.1); C+=100;}
            else{M1-=120; EXP1 =ceil(static_cast<float>(EXP1) - EXP1*0.1); C+=120;}
            CheckEXP1(EXP1);
            if (C>D) break;
            if (M1==0) break;
        }
        HP1 = ceil ((float) HP1 - HP1*0.17);
        EXP1 =ceil ((float) EXP1 +  EXP1*0.17);
        CheckHP1(HP1);
        CheckEXP1(EXP1);
    }
    else {
        for (int i=0; i<1 ;i++) {
            CheckM1(M1);
            if (M1==0) break;
            if (HP1 < 200) {HP1 =ceil ((float)HP1 + HP1*0.3); M1-=150;}
            else {HP1 =ceil ((float)HP1 + HP1*0.1); M1-=70;}
            CheckHP1(HP1);
            CheckM1(M1);
            if (M1==0) break;
            if (EXP1 < 400) {M1-=200; EXP1 =ceil ((float) EXP1 + EXP1*0.13);}
            else{M1-=120; EXP1 =ceil ((float) EXP1 + EXP1*0.13);}
            CheckEXP1(EXP1);
            CheckM1(M1);
            if (M1==0) break;
            if (EXP1 < 300) {M1-=100; EXP1 =ceil ((float)EXP1 - EXP1*0.1);}
            else{M1-=120; EXP1 =ceil ((float)EXP1 - EXP1*0.1);}
            CheckEXP1(EXP1);
            CheckM1(M1);
            if (M1==0) break;
        }

        HP1 = ceil ((float) HP1 - HP1*0.17);
        EXP1 =ceil ((float) EXP1 + EXP1*0.17);
        CheckHP1(HP1);
        CheckEXP1(EXP1);
    }
    double A2;
    A2 = sqrt(EXP1);
    int S2;
    S2 = static_cast<int>(round(A2));
    S2*=S2;
    // Tinh toan
    double P2;
    if (EXP1>=S2) P2 = 1;
        else P2 = ((double)(EXP1/S2) + 80 ) / 123;
    
    //Way 3
    int Pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = 0;
    if (E2<=9) P3=Pi[E2]/100.0;
        else P3=Pi[(E2%10+E2/10)%10]/100.0;
    //Tinh toan
    
    if (P1==1 & P2==1 & P3==1 ) EXP1 = ceil( (float)EXP1 - EXP1*0.25);
    else if ((P1+P2+P3)/3<0.5) {HP1 = ceil((float)HP1 - HP1*0.15); EXP1 = ceil((float)EXP1 + EXP1*0.15);}
        else {HP1 = ceil((float) HP1 - (HP1*0.1)); EXP1 = ceil((float) EXP1 + EXP1*0.2);}
    CheckHP1(HP1);
    CheckEXP1(EXP1);
    CheckM1(M1);
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0) return -99;
    else if (E3>99) return -99;
    CheckHP1(HP1);
    CheckEXP1(EXP1);
    CheckHP2(HP2);
    CheckEXP2(EXP2);
    int arr[10][10] = {0};
    int a=0,b=0,c,d=0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            arr[i][j] = ((E3 *j)+(i*2))*(i-j);
            }
        }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(arr[i][j]>E3*2) a++;
            else if (arr[i][j]<-E3) b++;
            }
        }
    while (a>=10) {a = a%10 + a/10;}
    while (b>=10) {b = b%10 + b/10;}
    c=arr[a][b];
    int i,j;
    i=a;
    j=b;
    while(true) {
        if (arr[i][j]>d) d=arr[i][j];
            ++i;
            ++j;
        if (i>=10 || i<=0) break;
        if (j>=10 || j<=0) break;
        }
    i=a;
    j=b;
    while(true) {
        if (arr[i][j]>d) d=arr[i][j];
            ++i;
            --j;
        if (i>=10 || i<=0) break;
        if (j>=10 || j<=0) break;
        }
    i=a;
    j=b;
    while(true) {
        if (arr[i][j]>d) d=arr[i][j];
            --i;
            ++j;
        if (i>=10 || i<=0) break;
        if (j>=10 || j<=0) break;
        }
    i=a;
    j=b;
    while(true) {
        if (arr[i][j]>d) d=arr[i][j];
            --i;
            --j;
        if (i>=10 || i<=0) break;
        if (j>=10 || j<=0) break;
        }
    if (d<0) d=-d;
    if (abs(c)>abs(d)) {
        EXP1 = ceil( (float) EXP1 - EXP1*0.12);
        HP1 = ceil( (float) HP1 - HP1*0.1);
        EXP2 = ceil( (float) EXP2 - EXP2*0.12);
        HP2 = ceil( (float) HP2 - HP2*0.1);
    }
    else {
        EXP1 = ceil( (float) EXP1 + EXP1*0.12);
        HP1 = ceil( (float) HP1 + HP1*0.1);
        EXP2 = ceil( (float) EXP2 + EXP2*0.12);
        HP2 = ceil( (float) HP2 + HP2*0.1);
    }
    CheckHP1(HP1);
    CheckEXP1(EXP1);
    CheckHP2(HP2);
    CheckEXP2(EXP2);
    if (abs(c)>abs(d)) {return c;}
    else return d;
    return -1;
}
// Task 4
bool Special(const string& s) {
    const string specialChars = "@#%$!";
    for (char c : s) {
        for (char sc : specialChars) {
            if (c == sc) {
                return true;
            }
        }
    }
    return false;
}
string Name(const string& email) {
    int a = email.find('@');
    return email.substr(0, a);
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
       
    if (strlen(s) < 8)
           return -1;

    if (strlen(s) > 20)
           return -2;

        string se = Name(email);
        
        string ss;
        ss = s;
        string eemail;
        eemail = email;
    
    if (ss.find(se) != string::npos) {
        int sei = ss.find(se);
        return -(300 + sei);
    }
    
    for (int i = 0; i < strlen(s) - 2; ++i) {
        if (ss[i] == ss[i+1] & ss[i+1] == ss[i+2])
            return -(400 + i);
    }
    
    if (Special(s)==false) return -5;
    
    for (int i = 0; i < strlen(s); i++) {
        if (!(((s[i] >= 48) && (s[i] <= 57)) || ((s[i] >= 64) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122)) || (s[i] == 33) || ((s[i] >= 35) && (s[i] <= 37)))) {
            return i;
            break;
        }
    }
    
    return -10;
    
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int a = 0, b = 1, max = 0;
    string arr[30];
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                a++;
            }
        }
        if (a > max) {
            max = a;
            arr[0] = arr_pwds[i];
        }
        a = 0;
    }
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                a++;
            }
        }
        if (a == max) {
            arr[b] = arr_pwds[i];
            ++b;
        }
        a = 0;
    }
    for (int i = 0; i < b; i++) {
        if (strlen(arr[i].c_str()) > strlen(arr[0].c_str())) {
            arr[0] = arr[i];
        }
    }
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], arr[0].c_str()) == 0) {
            return i;
        }
    }
    return -1;
}
