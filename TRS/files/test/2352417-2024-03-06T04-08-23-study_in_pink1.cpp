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

void EXPlimit(int & exp1, int & exp2) {
    exp1 = (exp1 > 600) ? 600 : exp1;
    exp1 = (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : exp2;
    exp2 = (exp2 < 0) ? 0 : exp2;
}

void HPlimit(int & HP1, int & HP2) {
    HP1 = (HP1 > 666) ? 666 : HP1;
    HP1 = (HP1 < 0) ? 0 : HP1;
    HP2 = (HP2 > 666) ? 666 : HP2;
    HP2 = (HP2 < 0) ? 0 : HP2;
}

void Mlimit(int & M1, int & M2) {
    M1 = (M1 > 3000) ? 3000 : M1;
    M1 = (M1 < 0) ? 0 : M1;
    M2 = (M2 > 3000) ? 3000 : M2;
    M2 = (M2 < 0) ? 0 : M2;
}

int FindS(int num) {
    if ((pow(ceil(float(sqrt(num))), 2) - num) > (num - pow(floor(float(sqrt(num))), 2)))
        return pow(floor(float(sqrt(num))), 2);
    else return pow(ceil(float(sqrt(num))), 2);
}
float FindP(int exp1, int s) {
    float P = (s <= exp1) ? 1.0 : (((float(exp1)) / float(s) + float(80) )/ float(123));
    return P;
}

// void checkintask2(int & EXP1, int & HP1, int & M1, int InitialMoney) {
//     if (M1<0) {
//             M1 = 0;
//             HP1 = ceil(HP1*0.83);
//             EXP1 = ceil(EXP1*1.17);
//         }
//         Mlimit(M1,M1);
//         HPlimit(HP1,HP1);
//         EXPlimit(EXP1,EXP1);

//     if ((InitialMoney/2)>M1) {
//                 HP1 = ceil(HP1*0.83);
//                 EXP1 = ceil(EXP1*1.17);
//                 break;
//         }
//         Mlimit(M1,M1);
//         HPlimit(HP1,HP1);
//         EXPlimit(EXP1,EXP1);
// }

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    EXPlimit(exp1, exp2);
// 4.1.1 Trường hợp 1 (0.5 điểm)
    if (e1<=3 && e1>=0) {
        switch(e1) {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 = exp2 + 29 + 45 + 75;
                break;
        }
        EXPlimit(exp1, exp2);
        int D = e1*3 +exp1*7;
        if (D%2==0) {
            exp1 = ceil(exp1 + float(D)/200.0);
        } else exp1 = ceil(exp1 - float(D)/100.0);
        // cout << D << " " << e1;

// 4.1.2 Trường hợp 2 (1.0 điểm)
    } else if (e1<=99 && e1>=4) {
        if (e1<=19 && e1>=4) {
            exp2 = ceil(exp2 + float(e1)/float(4)+19);
        } else if (e1<=49 && e1>=20) {
            exp2 = ceil(exp2 + float(e1)/float(9)+21);
        } else if (e1<=65 && e1>=50) {
            exp2 = ceil(exp2 + float(e1)/float(16)+17);
        } else if (e1<=79 && e1>=66) {
            exp2 = ceil(exp2 + float(e1)/float(4)+19);
            EXPlimit(exp1, exp2);
            exp2 = (exp2 > 200) ? ceil(exp2 + float(e1)/float(9)+21) : exp2;
        } else if (e1<=99 && e1>=80) {
            exp2 = ceil(ceil(exp2 + float(e1)/float(4)+19) + float(e1)/float(9)+21);
            EXPlimit(exp1, exp2);
            exp2 = (exp2>400) ? ceil(ceil((exp2 + float(e1)/float(16)+17))*1.15) : exp2;
        }
        exp1-=e1;
    } else return -99;
    EXPlimit(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0 || E2>99) return -99;
// 4.2.1 Con đường 01
    EXPlimit(EXP1, EXP1);
    HPlimit(HP1, HP1);
    Mlimit(M1, M1);
    int S1 = FindS(EXP1);
    float P1 = FindP(EXP1, S1);
    
// 4.2.2 Con đường 02
    const int InitialMoney = M1;
    
    do {
        if (HP1<200) {
            HP1 = ceil(HP1*1.3F);
            M1-=150;
        } else {
            HP1 = ceil(HP1*1.1F);
            M1-=70;
        }
        Mlimit(M1,M1);
        HPlimit(HP1,HP1);
        EXPlimit(EXP1,EXP1);

        if (M1<=0) {
            Mlimit(M1,M1);
            break;
        }

        if ((M1*2)<InitialMoney && (E2%2)!=0) {
            break;
        }
        Mlimit(M1,M1);
        HPlimit(HP1,HP1);
        EXPlimit(EXP1,EXP1);

        if (EXP1<400) {
            M1-=200;
        } else if (EXP1>=400) {
            M1-=120;
        }
        EXP1 = ceil(EXP1*1.13F);

        if (M1<=0) {
            Mlimit(M1,M1);
            break;
        }
        if ((M1*2)<InitialMoney && (E2%2)!=0) {
            break;
        }
        Mlimit(M1,M1);
        HPlimit(HP1,HP1);
        EXPlimit(EXP1,EXP1);

        
        Mlimit(M1,M1);
        HPlimit(HP1,HP1);
        EXPlimit(EXP1,EXP1);

        if (EXP1<300) {
            M1-=100;
        } else M1-=120;
        EXP1 = ceil(EXP1*0.9F);
        Mlimit(M1,M1);
        HPlimit(HP1,HP1);
        EXPlimit(EXP1,EXP1);

        if (M1<=0) {
            Mlimit(M1,M1);
            break;
        }

        if ((M1*2)<InitialMoney && (E2%2)!=0) {
            break;
        }
        Mlimit(M1,M1);
        HPlimit(HP1,HP1);
        EXPlimit(EXP1,EXP1);
    } while ((E2%2)!=0);

    HP1 = ceil(HP1*0.83);
    EXP1 = ceil(EXP1*1.17);
    Mlimit(M1,M1);
    HPlimit(HP1,HP1);
    EXPlimit(EXP1,EXP1);

    int S2 = FindS(EXP1);
    float P2 = FindP(EXP1, S2);

// 4.2.3 Con đường 03
    float P[10] = {0.32F, 0.47F, 0.28F, 0.79F, 1.0F, 0.50F, 0.22F, 0.83F, 0.64F, 0.11F};
    int i;
    if (E2 >=0 && E2<=9) {
        i = E2;
    } else if (E2>=10 && E2 <=99) {
        i = (E2%10) + (E2-(E2%10))/10;
        i=i%10;
    } else {
        // E2 = i;
        return -99;
    }
    float P3 = P[i];
    float Ptotal = (P1+P2+P3)/3.0F;
    if (P1 == P2 && P2 == P3 && P3 == float(1)) {
        EXP1=ceil(EXP1*0.75);
    } else if (Ptotal < 0.5) {
        HP1 = ceil(HP1*0.85F);
        EXP1 = ceil(EXP1*1.15);
    } else {
        HP1 = ceil(HP1*0.9F);
        EXP1 = ceil(EXP1*1.2);
    }

    // EXP1 = P1;
    
    Mlimit(M1,M1);
    HPlimit(HP1,HP1);
    EXPlimit(EXP1,EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int a = 0;
    int b = 0;
    int Array[10][10];
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            Array[i][j] = ((E3*j)+(i*2))*(i-j);
            if (Array[i][j]>(E3*2)) {
                a++;
            } else if (Array[i][j]<(-E3)) {
                b++;
            }
        }
    }
    while (a>9) {
        a=(a%10) + ((a-(a%10))/10);
    }
    while (b>9) {
        b=(b%10) + ((b-(b%10))/10);
    }

    int Max = 0;
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            if ((abs(i-a) == abs(j-b)) && (Array[i][j]>Max) && ((i-a)>=0)) {
                Max = Array[i][j];
            }
        }
    }
    if (abs(Array[a][b])>abs(Max)) {
        EXP1 = ceil(EXP1*0.88F);
        EXP2 = ceil(EXP2*0.88F);
        HP1 = ceil(HP1*0.9F);
        HP2 = ceil(HP2*0.9F);
        EXPlimit(EXP1, EXP2);
        HPlimit(HP1, HP2);
        return Array[a][b];
    } else {
        EXP1 = ceil(EXP1*1.12F);
        EXP2 = ceil(EXP2*1.12F);
        HP1 = ceil(HP1*1.1F);
        HP2 = ceil(HP2*1.1F);
        EXPlimit(EXP1, EXP2);
        HPlimit(HP1, HP2);
        return Max;
    }
    EXPlimit(EXP1, EXP2);
    HPlimit(HP1, HP2);

    // return Max;
}



int SeCheck(const char * s, const char * se, int length, int SeLength) {
    // bool exist = false;
    for (int i = 0;i<=(length-SeLength);i++) {
        bool exist = true;
        for (int j = 0;j<SeLength;j++) {
            if (s[i+j] != se[j]) {
                exist = false;
                
            }
            
        }
        if (exist) return i; // return error
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // int sei, sci;
    
    char * se = (char *)malloc(101);
    int SeLength = 0;
    while (email[SeLength] != '@') {
        se[SeLength] = email[SeLength];
        SeLength++;
    }
    // Add an end for se
    se[SeLength+1] = '\0';

    // Find length of password
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    const char Alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','@','#','%','$','!','0','1','2','3','4','5','6','7','8','9'};
    // char LightAlphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    // char SpecialKey[] = {'@','#','%','$','!'};

    if (length<8) {
        return -1;
    } else if (length>20) {
        return -2;
    }
    
    if (SeLength == 0) return -300;

    int sei = SeCheck(s, se, length, SeLength);
    if (sei != -1) {
        return -(300 + sei);
    }

    for (int sci =0;sci<length;sci++) {
        if ((s[sci] == s[sci+1]) && (s[sci+1] == s[sci+2])) {
            return -(400+sci);
        }
    }
    bool Special = false;
    for (int i=0;i<length;i++) {
        if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') {
            Special = true;
            break;
        }
    }
    if (!Special) return -5;

    bool exist = false;
    for (int i=0;i<length;i++) {
        for (int j=0;j<67;j++) {
            if (s[i] == Alphabet[j]) {
                exist = true;
            }
        }
        if (!exist) {
            return i;
        }
        exist = false;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string sndArray[num_pwds];
    for (int i=0;i<num_pwds;i++) {
        sndArray[i] = arr_pwds[i];
    }

    int CountFreq[31] = {0};
    int LengthFreq[31] = {0};

    for (int i=0; i<num_pwds;i++) {
        int index = -1;
        for (int j = 0; j < i;j++) {
            if (sndArray[i] == sndArray[j]) {
                index = j;
                break;
            }
        }
        if (index != -1) {
            CountFreq[index]++;
        } else {
            CountFreq[i]++;
        }
    }

    int maxCount = 0;
    int Max = 0;
    for (int i=0;i<num_pwds;i++) {
        if (CountFreq[i] > maxCount && (i>Max)) {
            maxCount = CountFreq[i];
            Max = i;
        }
    }

    return Max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////