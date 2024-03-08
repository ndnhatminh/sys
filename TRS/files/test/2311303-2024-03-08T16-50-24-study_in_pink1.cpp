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
    if (e1 >=0 && e1 <=3) {
        if (e1 == 0) {
            exp2 = exp2 + 29;
        } else if (e1 == 1) {
            exp2 = exp2 + 45;
        } else if (e1 == 2) {
            exp2 = exp2 + 75;
        } else if (e1 == 3) {
            exp2 = exp2 + 29 + 45 + 75;
        }
        int D = e1*3 + exp1*7;
        if (D%2 == 0) {
            exp1 = exp1 + D/200;
        } else {
            exp1 = exp1 - D/100;
        }
    }
    if (e1 >= 4 && e1 <= 99) {
        if (e1>=4 && e1<=19) {
            exp2 = exp2 +  e1/4 + 19+1;
        } else if (e1>=20 && e1<=49) {
            exp2 = exp2 + e1/9 + 22;
        } else if (e1>=50 && e1<=65) {
            exp2 = exp2 + e1/16 + 18;
        } else if (e1>=66 && e1<=79) {
            exp2 = exp2 + e1/4 + 19+1;
            if (exp2 > 200) {
                exp2 = exp2 + e1/9 + 21+1;
            }
        } else if (e1>=80 && e1<=99) {
            exp2 = exp2 +  e1/4 + 19+1;
            exp2 = exp2 + e1/9 + 22;
            if (exp2 > 400) {
                exp2 = exp2 + e1/16 + 17+1;
                exp2 = exp2*1.15;
            }
        }
        if (exp1 > 600) {
            exp1=600;
        }
        if (exp1 < 0) {
            exp1=0;
        }
        if (exp2 > 600) {
            exp2=600;
        }
        if (exp2 < 0) {
            exp2=0;
        }
        exp1 = exp1 - e1;
    }
    return exp1 + exp2;
}

// Task 2
int road02_ev1(int & HP1, int & M1) {
	if (HP1 < 200) {
        HP1 = (HP1*1.3)+1;
        M1-=150;
    } else {
        HP1 = (HP1*1.1)+1;
        M1-=70;
    }
    return M1;
}
int road02_ev2(int & HP1, int & M1, int & EXP1) {
    if (EXP1 < 400) {
        M1-=200;
    } else {
        M1-=120;
    }
    EXP1 = (EXP1*1.13)+1;
    return M1;
}
int road02_ev3(int & HP1, int & M1, int & EXP1) {
    if (EXP1 < 300) {
        M1-=100;
    } else {
        M1-=120;
    }
    EXP1 = (EXP1*0.9)+1;
    return M1;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double P1, P2; 
    int P3[10] = {32,47,28,79,100,50,22,83,64,11}, P;
    double S1 ;
    double s1 ;
    for (int i=0;i*i<=EXP1;i++) {
        S1 = i*i;
        s1 =(i+1)*(i+1);
    }
    if(s1 - double(EXP1) < double(EXP1) - S1) {
        P1 = ((EXP1/s1)+80)/123;
    } else {
        P1=100;
    }
    int iniM = M1;
    if (E2%2==0) {
        road02_ev1(HP1, M1);
        if (M1>0) {
            road02_ev2(HP1, M1, EXP1);
            if (M1>0) {
                road02_ev3(HP1, M1, EXP1);
                if (M1<0) {
                    M1=0;
                    HP1 = (HP1*0.83)+1;
                    EXP1 = (EXP1*1.17)+1;
                }
            } else {
                M1=0;
                HP1 = (HP1*0.83)+1;
                EXP1 = (EXP1*1.17)+1;
            }
        } else {
            M1=0;
            HP1 = (HP1*0.83)+1;
            EXP1 = (EXP1*1.17)+1;
        }
    } else {
        while (M1 >= iniM/2) {
            road02_ev1(HP1, M1);
            if (M1 < iniM/2) {
                break;
            }
            road02_ev2(HP1, M1, EXP1);
            if (M1 < iniM/2) {
                break;
            } 
            road02_ev3(HP1, M1, EXP1);
            if (M1 < iniM/2) {
                break;
            }      
        }
        HP1 = (HP1*0.83)+1;
        EXP1 = (EXP1*1.17)+1;
    }
    double S2 ;
    double s2 ;
    for (int i=0;i*i<=EXP1;i++) {
        S2 = i*i;
        s2 =(i+1)*(i+1);
    }
    if(s2 - double(EXP1) < double(EXP1) - S2) {
        P2 = ((EXP1/s2)+80)/123;
    } else {
        P2=100;
    }
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        i = E2/10 + E2%10;
        i = i%10;
    }
    P = (P1*100 + P2 + P3[i])/3;
    if (P==100) {
        EXP1 = EXP1*0.75+1;
        return traceLuggage(HP1, EXP1, M1, E2);
    } else if (P < 50) {
        HP1 = (HP1*0.85)+1;
        EXP1 = EXP1*1.15+1;
    } else if (P >= 50) {
        HP1 = (HP1*0.9)+1;
        EXP1 = (EXP1*1.2)+1;
    }
    if (EXP1 > 600) {
            EXP1=600;
    } else if(EXP1 < 0){
        EXP1=0;
    }
    if (HP1 > 666) {
        HP1=666;
    } else if (HP1 < 0) {
        HP1 = 0;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int maxValue(int arr[10][10], int m, int n,int & maxval) {
    int max[100], temp1, temp2, i;
    for (i=0;i<100;i++) {
        temp1 = m;
        temp2 = n;
        temp1++;
        temp2++;
        max[i]=arr[temp1][temp2];
        if (temp1==9 || temp2==9) {
            break;
        }
    }
    for (i;i<100;i++) {
        temp1 = m;
        temp2 = n;
        temp1--;
        temp2++;
        max[i]=arr[temp1][temp2];
        if (temp1==0 || temp2==9) {
            break;
        }
    }
    for (i;i<100;i++) {
        temp1 = m;
        temp2 = n;
        temp1++;
        temp2--;
        max[i]=arr[temp1][temp2];
        if (temp1==9 || temp2==0) {
            break;
        }
    }
    for (i;i<100;i++) {
        temp1 = m;
        temp2 = n;
        temp1--;
        temp2--;
        max[i]=arr[temp1][temp2];
        if (temp1==0 || temp2==0) {
            break;
        }
    }
    maxval=max[0];
    for (int a=0; a<=i; a++) {
        if (max[a]>maxval) {
            maxval=max[a];
        }
    }
    return maxval;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int arr[10][10], m=0, n=0, maxval = 0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            arr[i][j] = ((E3*j)+(i*2))*(i-j);   
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (arr[i][j] > E3*2) {
                m++;
            } else if (arr[i][j] < 0) {
                if (abs(arr[i][j]) > E3) {
                    n++;
                }
            }
        }
    }
    while (m>=10) {
        m = m/10 + m%10;
    }
    while (n>=10) {
        n = n/10 + n%10;
    }
    maxValue(arr, m, n, maxval);
    if(maxval>=abs(arr[m][n])) {
        HP1=HP1*1.1;
        EXP1=EXP1*1.12;
        HP2=HP2*1.1;
        EXP2=EXP2*1.12;
        return arr[m][n]; 
    } else {
        HP1=HP1*0.9;
        EXP1=EXP1*0.88;
        HP2=HP2*0.9;
        EXP2=EXP2*0.88;
        return arr[m][n];
    }
    return -1;
}

// Task 4
int e_name(const char * email, int & num, char* se) {
    for (int i=0; email[i]!= '@';i++) {
        num=i;
    }
    for (int i=0; email[i]!= '@';i++) {
        se[i]=email[i];
    }
    return num;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int length_s = std::strlen(s);
    if (length_s < 8) {
        return -1;
    }
    if (length_s > 20) {
        return -2;
    }
    int symbol;
    int num=0;
    char se[100];
    num =e_name(email,num,se);
    for (int i = 0; i < length_s; i++){
        if (s[i] == se[0]) {
            for (int j=1; j<num; j++) {
                if (s[i+j] != se[j]) {
                    break;
                }
                if(j==num-1) {
                    return -(300 + i);
                }
            }
        }
        if (s[i]==s[i+1]) {
            return -(400 + i);
        }
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            symbol++;
        }
    }
    if (symbol==0) {
            return -5;
    }
    for (int i = 0; i < length_s; i++){
        if (s[i] < 'A') {
            return i;
        }
        if (s[i] > 'Z' && s[i] < 'a') {
            return i;
        }
        if (s[i] > 'z') {
            return i;
        }
    }
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    int crt_pwd = -1;
    for (int i = 0; i < num_pwds; i++) {
        const char* password = arr_pwds[i];
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (std::strcmp(password, arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > maxCount || (count == maxCount && std::strlen(password) > maxLength)) {
            maxCount = count;
            maxLength = std::strlen(password);
            crt_pwd = i;
        }
    }
    return crt_pwd;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////