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

    //invalid e1
    if(e1 < 0 || e1 > 99)
        return -99;

    //valid e1
    exp1 = testEXP(exp1);
    exp2 = testEXP(exp2);

    //Case 1
    if(e1 >= 0 && e1 <= 3) {

        int arr[4] = {29, 45, 75, 149};
        exp2 = testEXP(exp2 + arr[e1]);

        int D = e1*3 + exp1*7;
        if(D%2 == 0) 
            exp1 = testEXP(exp1 + D/200.0);
        else 
            exp1 = testEXP(exp1 - D/100.0);

        return exp1 + exp2;
    } 

    //Case 2
    else {
        if(e1 >= 4 && e1 <= 19) {
            exp2 = testEXP(exp2 + e1/4.0 + 19);
        }
        else if(e1 >= 20 && e1 <= 49) {
            exp2 = testEXP(exp2 + e1/9.0 + 21);
        }
        else if(e1 >= 50 && e1 <= 65) {
            exp2 = testEXP(exp2 + e1/16.0 + 17);
        }
        else if(e1 >= 66 && e1 <= 79) {
            exp2 = testEXP(exp2 + e1/4.0 + 19);
            if(exp2 > 200) {
                exp2 = testEXP(exp2 + e1/9.0 + 21);
            }
        }
        else {
            exp2 = testEXP(exp2 + e1/4.0 + 19);
            exp2 = testEXP(exp2 + e1/9.0 + 21);
            if(exp2 > 400) {
                exp2 = testEXP(exp2 + e1/16.0 + 17);
                exp2 = testEXP(exp2 + exp2*0.15);
            }
        }

        exp1 = testEXP(exp1 - e1);

        return exp1 + exp2;
    }

}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    //invalid E2
    if(E2 < 0 || E2 > 99) 
        return -99;

    //valid E2
    HP1 = testHP(HP1);
    EXP1 = testEXP(EXP1);
    M1 = testM(M1);
    
    //Path1
    double P1;
    if(EXP1 >= squareNum(EXP1)) 
        P1 = 1;
    else 
        P1 = (1.0*EXP1/squareNum(EXP1) + 80)/123.0;

    //Path2
    if(E2 % 2 != 0) {
        
        if(M1 == 0) ;
        else {

            const int m = M1;

            while(true) {

                //Event1
                if(HP1 < 200) {
                    HP1 = testHP(HP1 + 0.3*HP1);
                    M1 = testM(M1 - 150);
                } 
                else {
                    HP1 = testHP(HP1 + 0.1*HP1);
                    M1 = testM(M1 - 70);
                    }
                if((m - M1) > 0.5*m)
                    break;

                //Event2
                if(EXP1 < 400) {
                    M1 = testM(M1 - 200);
                    EXP1 = testEXP(EXP1 + 0.13*EXP1);
                }
                else {
                    M1 = testM(M1 - 120);
                    EXP1 = testEXP(EXP1 + 0.13*EXP1);
                }
                if((m - M1) > 0.5*m)
                    break;

                //Event3
                if(EXP1 < 300) {
                    M1 = testM(M1 - 100);
                    EXP1 = testEXP(EXP1 - 0.1*EXP1);
                }
                else {
                    M1 = testM(M1 - 120);
                    EXP1 = testEXP(EXP1 - 0.1*EXP1);
                }
                if((m - M1) > 0.5*m)
                    break;
            }

        }

    }

    else {
        //Event1
        if(M1 == 0) ;
        else 
            if(HP1 < 200) {
                HP1 = testHP(HP1 + 0.3*HP1);
                M1 = testM(M1 - 150);
            } 
            else {
                HP1 = testHP(HP1 + 0.1*HP1);
                M1 = testM(M1 - 70);
            }

        //Event2
        if(M1 == 0) ;
        else 
            if(EXP1 < 400) {
                M1 = testM(M1 - 200);
                EXP1 = testEXP(EXP1 + 0.13*EXP1);
            }
            else {
                M1 = testM(M1 - 120);
                EXP1 = testEXP(EXP1 + 0.13*EXP1);
            }

        //Event3
        if(M1 == 0) ;
        else 
            if(EXP1 < 300) {
                M1 = testM(M1 - 100);
                EXP1 = testEXP(EXP1 - 0.1*EXP1);
            }
            else {
                M1 = testM(M1 - 120);
                EXP1 = testEXP(EXP1 - 0.1*EXP1);
            }

    }

    HP1 = testHP(HP1 - 0.17*HP1);
    EXP1 = testEXP(EXP1 + 0.17*EXP1);

    double P2;
    if(EXP1 >= squareNum(EXP1)) 
        P2 = 1;
    else 
        P2 = (1.0*EXP1/squareNum(EXP1) + 80)/123.0;

    //Path3
    double P3[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11};
    int i = idex1(E2);

    if(P1 == 1 && P2 == 1 && P3[i] == 1) {
        EXP1 = testEXP(EXP1 - 0.25*EXP1);
    } 
    else if(((P1 + P2 + P3[i])/3.0) < 0.5) {
        EXP1 = testEXP(EXP1 + 0.15*EXP1);
        HP1 = testHP(HP1 - 0.15*HP1);
    } 
    else if(((P1 + P2 + P3[i])/3.0) >= 0.5) {
        EXP1 = testEXP(EXP1 + 0.2*EXP1);
        HP1 = testHP(HP1 - 0.1*HP1);
    }

    return HP1 + EXP1 + M1;

}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    //invalid E3
    if(E3 < 0 || E3 > 99)
        return -99;
    
    //valid E3
    EXP1 = testEXP(EXP1);
    EXP2 = testEXP(EXP2);
    HP1 = testHP(HP1);
    HP2 = testHP(HP2);

    int arr1[10][10]; 
    int arr2[10][10];
    for(int i = 0; i < 10; i++) 
        for(int j = 0; j < 10; j++) 
            arr1[i][j] = (E3*j + i*2)*(i - j);
        
    //Mark of Sherlock and Watson
    for(int i = 0; i < 10; i++) 
        for(int j = 0; j < 10; j++) {

            int maximum = INT_MIN;

            if(j > i) 
                for(int nj = j - i; nj < 10; nj++) {
                    int ni = nj - (j - i);
                    if(arr1[ni][nj] > maximum) {
                        maximum = arr1[ni][nj];
                            arr2[i][j] = maximum;
                    }
                }
            else 
                for(int ni = -(j - i); ni < 10; ni++) {
                    int nj = ni + (j - i);
                    if(arr1[ni][nj] > maximum) {
                        maximum = arr1[ni][nj];
                        arr2[i][j] = maximum;
                    }
                }
                
            if((9 - (j + i)) > 0) 
                for(int ni = i + j; ni >= 0; ni--) {
                    int nj = (i + j) - ni;
                    if(arr1[ni][nj] > maximum) {
                        maximum = arr1[ni][nj];
                        arr2[i][j] = maximum;
                    }
                }
            else 
                for(int nj = i + j - 9; nj < 10; nj++) {
                    int ni = (i + j) - nj;
                    if(arr1[ni][nj] > maximum) {
                        maximum = arr1[ni][nj];
                        arr2[i][j] = maximum;
                    }
                }
                
            if(arr2[i][j] < 0) 
                arr2[i][j] = abs(arr2[i][j]);

        }
            
        //Encounter
        int cnti = 0, cntj = 0;
        for(int i = 0; i < 10; i++) 
            for(int j = 0; j < 10; j++) 
                if(arr1[i][j] > E3*2) 
                    cnti++;
            
        for(int i = 0; i < 10; i++) 
            for(int j = 0; j < 10; j++) 
                if(arr1[i][j] < -1*E3) 
                    cntj++;

        cnti = idex2(cnti);
        cntj = idex2(cntj);
            
        //On time?
        if(abs(arr1[cnti][cntj]) > arr2[cnti][cntj]) {
            EXP1 = testEXP(EXP1 - 0.12*EXP1);
            HP1 = testHP(HP1 - 0.1*HP1);
            EXP2 = testEXP(EXP2 - 0.12*EXP2);
            HP2 = testHP(HP2 - 0.1*HP2);
            return arr1[cnti][cntj];
        }
        else {
            EXP1 = testEXP(EXP1 + 0.12*EXP1);
            HP1 = testHP(HP1 + 0.1*HP1);
            EXP2 = testEXP(EXP2 + 0.12*EXP2);
            HP2 = testHP(HP2 + 0.1*HP2);
            return arr2[cnti][cntj];
        }

}

// Task 4
int checkPassword(const char * s, const char * email) {
    
    //Make se
    string se = "";
    for(int i = 0; i < strlen(email); i++) {
        if(email[i] == '@')
            break;
        se += email[i];
    }
    
    //Check s lenghth
    if(strlen(s) >= 8 && strlen(s) <= 20) ;
    else if(strlen(s) < 8) 
        return -1;
    else 
        return -2;
    
    //Does s contain se?
    if(strlen(s) < se.length()) ;
    else 
        for(int i = 0; i <= (strlen(s) - se.length()); i++) {
            string subs = "";
            for(int j = i; j <= i + (se.length() - 1); j++) 
                subs += s[j];
            if(subs.compare(se) == 0)
                return -(300 + i);
            else ;
        }
    
    //Does s contain any substring of more than 2 characters?
    int arr[256];
    for(int i = 0; i < 256; i++)
        arr[i] = 0;

    char tmp = ' ';
    for(int i = 0; i < strlen(s); i++) {
        arr[(int)(s[i])]++;
        if(s[i] != tmp) {
            arr[(int)(tmp)] = 0;
            tmp = s[i];
        }
        else {
            if(arr[(int)(s[i])] >= 3)
                return -(400 + (i - 2));
            else ;
        }
    }
    
    //Does s contain any special character?
    int cnt = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') 
            cnt++;
        else ;
    }
    if(cnt == 0) 
        return -5;
    else ;
    
    //Other case
    for(int i = 0; i < strlen(s); i++) {
        if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') ;
        else 
            return i;
    }

    return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {

    //Use array to mark idex and time
    int note[100]; 
    int arr[100];

    for(int k = 0; k < 100; k++) {
        arr[k] = 0;
        note[k] = 1; //if an element is checked, mark it 0, if not, 1
    }
    
    //Count
    for(int i = 0; i < num_pwds; i++) {
        if(note[i] == 0) 
            continue;
        int cnt = 0;
        for(int j = 0; j < num_pwds; j++) 
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                cnt++;
                note[i] = 0;
            }
        arr[i] = cnt;
    }

    //Find expecting element
    int mfre = 0, idex = 0;
    for(int i = 0; i < num_pwds; i++) {
        if(arr[i] > mfre || (arr[i] == mfre && (strlen(arr_pwds[i]) > strlen(arr_pwds[idex])))) {
            idex = i;
            mfre = arr[i];
        }
        else ;
    }

    return idex;

}

//Reset EXP to fit condition
int testEXP(float EXP){
    EXP = ceil(EXP);
    if(EXP > 600) 
        return 600;
    else if(EXP < 0)
        return 0;
    else 
        return EXP;
}

//Reset HP to fit condition
int testHP(float HP){
    HP = ceil(HP);
    if(HP > 666) 
        return 666;
    else if(HP < 0)
        return 0;
    else 
        return HP;
}

//Reset M to fit condition
int testM(float M){
    M = ceil(M);
    if(M > 3000) 
        return 3000;
    else if(M < 0)
        return 0;
    else 
        return M;
}

//Find square number
int squareNum(int n){
    int i = sqrt(n);
    if(n > 0.5*((i + 1)*(i + 1) + i*i)) 
        return (i + 1)*(i + 1);
    else 
        return i*i;
}

//Find index in task 2
int idex1(int E2) {
    int sum = 0;
        if(E2 / 10 == 0) 
            return E2;
        else {
            while(E2) {
                sum += E2 % 10;
                E2 /= 10;
            }
            return sum % 10;
        }
}

//Find index in task 3
int idex2(int cnt) {
    int sum = cnt;
    if(cnt / 10 == 0) 
            return cnt;
    else {
        do{
            sum = sum/10 + sum%10;
        } while(sum/10 != 0);
        return sum;
    }
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////