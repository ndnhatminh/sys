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

    int adjustHP(int & HP1, int & HP2) {
        if (HP1 < 0) HP1 = 0;
        if (HP2 < 0) HP2 = 0;
        if (HP1 > 666) HP1 = 666;
        if (HP2 > 666) HP2 = 666;
        return 0;
}
    int adjustEXP(int & EXP1, int & EXP2) {
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
        return 0;
}
    int adjustM(int & M1, int & M2) {
        if (M1 < 0) M1 = 0;
        if (M2 < 0) M2 = 0;
        if (M1 > 3000) M1 = 3000;
        if (M2 > 3000) M2 = 3000;
        return 0;
    }
    int roundup(float a) {
        if (a == (int)a) return a;
        else return (int)a + 1;
    }

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1 < 0 || e1 > 99) return -99;
    else {
        if (e1 >= 0 && e1 <= 3) {
            switch(e1) {
                case 0:
                    exp2 += 29;
                    adjustEXP(exp1, exp2);
                    break;
                case 1:
                    exp2 += 45;
                    adjustEXP(exp1, exp2);
                    break;
                case 2:
                    exp2 += 75;
                    adjustEXP(exp1, exp2);
                    break;
                case 3:
                    exp2 += (29+45+75);
                    adjustEXP(exp1, exp2);
                    break;
                default:
                    break;
            }
            int D = e1*3 + exp1*7 ;
            if (D%2 == 0) {
                exp1 += D/200;
                adjustEXP(exp1, exp2);
                if (D%200 != 0) exp1++;
                adjustEXP(exp1, exp2);
            }
            else {
                exp1 -= D/100;
                adjustEXP(exp1, exp2);
            }
        }
        else {
            if ( e1 >= 4 && e1 <= 19) {
                exp2 = exp2 + (e1/4 + 19);
                adjustEXP(exp1, exp2);
                if ( e1%4 != 0) exp2++;
                adjustEXP(exp1, exp2);
                exp1=exp1-e1;
                adjustEXP(exp1, exp2);
            }
            else {
                if ( e1 >= 20 && e1 <= 49) {
                    exp2 = exp2 + (e1/9 + 21);
                    adjustEXP(exp1, exp2);
                    if ( e1%9 != 0) exp2++;
                    adjustEXP(exp1, exp2);
                    exp1=exp1-e1;
                    adjustEXP(exp1, exp2);
                }
                else {
                    if ( e1 >= 50 && e1 <= 65) {
                        exp2 = exp2 + (e1/16 + 17);
                        adjustEXP(exp1, exp2);
                        if ( e1%16 != 0) exp2++;
                        adjustEXP(exp1, exp2);
                        exp1=exp1-e1;
                        adjustEXP(exp1, exp2);
                    }
                    else {
                        if ( e1 >= 66 && e1 <= 79) {
                            exp2 = exp2 + (e1/4 + 19);
                            adjustEXP(exp1, exp2);
                            if ( e1%4 != 0) exp2++;
                            adjustEXP(exp1, exp2);
                            if ( exp2 > 200) {
                                exp2 = exp2 + (e1/9 +21 ); 
                                adjustEXP(exp1, exp2);
                                if ( e1%9 != 0) exp2++;
                                adjustEXP(exp1, exp2);
                            }
                            exp1=exp1-e1;
                            adjustEXP(exp1, exp2);
                        }
                        else {
                            exp2 = exp2 + (e1/4 +19);
                            adjustEXP(exp1, exp2);
                            if ( e1%4 != 0) exp2++;
                            adjustEXP(exp1, exp2);
                            exp2 = exp2 + (e1/9 +21);
                            adjustEXP(exp1, exp2);
                            if ( e1%9 != 0) exp2++;
                            adjustEXP(exp1, exp2);
                            if (exp2>400) {
                                exp2 = exp2 + (e1/16 +17);
                                adjustEXP(exp1, exp2);
                                if ( e1%16 != 0) exp2++;
                                adjustEXP(exp1, exp2);
                                exp2 = exp2*1.15;
                                adjustEXP(exp1, exp2);
                                if (exp2%23!=0) exp2++;
                                adjustEXP(exp1, exp2);
                            }
                            exp1=exp1-e1;
                            adjustEXP(exp1, exp2);
                        }
                    }
                }
            }

        }

        return exp1 + exp2;
    }

    
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    bool E2odd = false;
    adjustEXP(EXP1, EXP1);
    adjustHP(HP1, HP1);
    adjustM(M1, M1);
    if (E2 % 2 != 0) E2odd = true;
    if ( E2 < 0 || E2 > 99 ) return -99;
    float p1,p2,p3;
        
    // way1
    int s = sqrt(EXP1);
    if ( abs(s*s - EXP1) <= ((s+1)*(s+1) - EXP1) ) p1=1.0 ;
    else p1=(((EXP1*1.00)/((s+1)*(s+1)))+80)/123.0;
        
    int m = 0, M = M1*0.5;
    if (M1%2!=0) M++;
    // way2
    for ( int i=0; ; i++) {
        if (E2odd) if (m > M) break;
        if (!E2odd) if (M1 < 0 || i==1) break;
        //cua hang
        if ( HP1<200 ) {
            HP1=roundup((HP1+0.00)*1.3);
            adjustHP(HP1, HP1);
            M1-=150;
            m+=150;
            if (!E2odd) if (M1 < 0 || i==1) {
                adjustM(M1, M1);
                break;
            }  
            adjustM(M1, M1);
            }
        else {
            HP1=roundup((HP1+0.00)*1.1);
            adjustHP(HP1, HP1);
            M1-=70;
            m+=70;
            if (!E2odd) if (M1 < 0 || i==1) {
                adjustM(M1, M1);
                break;
            }  
            adjustM(M1, M1);
        }
        if (E2odd) if (m > M) break;
        //thue xe

        if (EXP1 < 400 ) {
            M1-=200;
            m+=200;
            if (!E2odd) if (M1 < 0 || i==1) {

                EXP1=roundup((EXP1+0.00)*1.13);
                adjustEXP(EXP1, EXP1);
                adjustM(M1, M1);
                break;

                }   
            adjustM(M1, M1);
        }
        else {
            M1-=120;
            m+=120;
            if (!E2odd) if (M1 < 0 || i==1) {

                EXP1=roundup((EXP1+0.00)*1.13);
                adjustEXP(EXP1, EXP1);
                adjustM(M1, M1);

                break;
                }
            adjustM(M1, M1);

        }
        
        EXP1=roundup((EXP1+0.00)*1.13);
        adjustEXP(EXP1, EXP1);
        if (E2odd) if (m > M) break;

        //gap vo gia cu
        if (EXP1<300) {
            M1-=100;
            m+=100;
            if (!E2odd) if (M1 < 0 || i==1) {

                EXP1=roundup((EXP1+0.00)*0.9);
                adjustEXP(EXP1, EXP1);
                adjustM(M1, M1);

                break;
            }
            adjustM(M1, M1);
        }
        else {
            M1-=120;
            m+=120;
            if (!E2odd) if (M1 < 0 || i==1) {

                EXP1=roundup((EXP1+0.00)*0.9);
                adjustEXP(EXP1, EXP1);
                adjustM(M1, M1);

                break;
            }
            adjustM(M1, M1);
        }
        EXP1=roundup((EXP1+0.00)*0.9);
        adjustEXP(EXP1, EXP1);
        if (E2odd) if (m > M) break;
    }
    HP1=roundup((HP1+0.00)*0.83);
    adjustHP(HP1, HP1);
    EXP1=roundup((EXP1+0.00)*1.17);
    adjustEXP(EXP1, EXP1);
    
    s = sqrt(EXP1);
    if ( abs(s*s - EXP1) <= ((s+1)*(s+1) - EXP1) ) p2=1.0 ;
    else p2=(((EXP1*1.00)/((s+1)*(s+1)))+80)/123.0;

    // way3
    float P[]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
        
    if (E2<10) p3=P[E2] ;
    else {
        int i = E2%10 + E2/10;
        if ( i<10 ) p3 = P[i];
        else {
            i = i % 10;
            p3 = P[i];
        }
    }

    //end
    if (p1==1.0 && p2==1.0 && p3==1.0) {
        EXP1=roundup((EXP1+0.00)*0.75);
        adjustEXP(EXP1, EXP1);
    }
    else {
        float p = (p1+p2+p3)/3;
        if (p<0.5) {
            HP1=roundup((HP1+0.00)*0.85);
            adjustHP(HP1, HP1);

            EXP1=roundup((EXP1+0.00)*1.15);
            adjustEXP(EXP1, EXP1);
            
        }
        else {
            HP1=roundup((HP1+0.00)*0.9);
            adjustHP(HP1, HP1);

            EXP1=roundup((EXP1+0.00)*1.2);
            adjustEXP(EXP1, EXP1);
        }
    }

     
    return HP1 + EXP1 + M1;
    
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    //adjust
    adjustEXP(EXP1, EXP2);
    adjustHP(HP1, HP2);

    if (E3<0 || E3 > 99) return -99;
    //ma tran taxi
    int a1[10][10], l=0, k=0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a1[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    } 
    //tim vi tri gap nhau
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (a1[i][j] > (E3*2)) l++;
            if (a1[i][j] < (-E3)) k++;
        }
    }
    while (l > 9 ) {l = l % 10 + l / 10; }
    while (k > 9 ) {k = k % 10 + k / 10; }
    //tim ma tran sherlock
        
    int max = a1[l][k];
    int a = l , b = k;

    while ((a>=0 && a < 9) && (b>=0 && b<9)) {
        a++;b++;
        if (max < a1[a][b]) {
            max = a1[a][b];
        }

    }
    a = l; b = k;
    while ((a>0 && a <= 9) && (b>0 && b<=9)) {
        a--;b--;
        if (max < a1[a][b]) {
            max = a1[a][b];
        }
        
    }
    a = l; b = k;
    while ((a>=0 && a < 9) && (b>0 && b<=9)) {
        a++;b--;        
        if (max < a1[a][b]) {
            max = a1[a][b];
        }

        }
    while ((a>0 && a <= 9) && (b>=0 && b<9)) {
        a--;b++;
        if (max < a1[a][b]) {
            max = a1[a][b];
        }
        
    }

    //tim diem cua sherlock tai vi tri gap nhau;

    int sherlock = abs(max);
        
    //khong duoi kip taxi
        
    if (abs(a1[l][k]) > sherlock) {
        EXP1=roundup((EXP1+0.00)*0.88);
        adjustEXP(EXP1, EXP2);
        HP1 = roundup((HP1+0.00)*0.9);
        adjustHP(HP1, HP2);
        EXP2=roundup((EXP2+0.00)*0.88);
        adjustEXP(EXP1, EXP2);
        HP2=roundup((HP2+0.00)*0.9);
        adjustHP(HP1, HP2);
            
        return a1[l][k] ;
    }
        
    //duoi kip taxi

    else {
        EXP1=roundup((EXP1+0.00)*1.12);
        adjustEXP(EXP1, EXP2);
        HP1=roundup((HP1+0.00)*1.1);
        adjustHP(HP1, HP2);
        EXP2=roundup((EXP2+0.00)*1.12);
        adjustEXP(EXP1, EXP2);
        HP2=roundup((HP2+0.00)*1.1);
        adjustHP(HP1, HP2);
            
        return sherlock ;
    }
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // tao chuoi se
    string se= "";
    for (int i = 0; ; i++) {
        se += email[i];
        if (email[i+1] == '@') break;
    }

    // kiem tra do dai
    if (strlen(s) < 8 ) return -1;
    if (strlen(s) > 20 ) return -2;


    

    // kiem tra chuoi se co trong s hay khong
    int count = -10;
    for ( int i=0; i< strlen(s); i++) {
        if (s[i] == se[0]) {
            bool check = true;
            for (int j = 0; se[j] != '\0'; j++) {
                if (s[i+j] != se[j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                count=i;
                break;
            }
        }
    }
        //s co chua chuoi se
        if (count != -10) return -(300+count);

    //kiem tra s co chua nhieu hon 2 ky tu lien tiep giong nhau

    for (int i = 0; i < strlen(s)-2; i++) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) return -(400+i);
        }

    //ki tu dac biet
    bool specialchar = false;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            specialchar = true;
            break;
        }
    }
    if (!specialchar) return -5;


    return -10;
    }


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int* count = new int[num_pwds];
    for (int i=0; i<num_pwds; i++) {

        if (count[i] == -1) continue;

        for (int j=i+1; j<num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count[i]++;
                count[j]=-1;
            }
        }
        
    }

    int maxcount = -1, maxlenght = -1, a=0;
    for (int i=0; i<num_pwds; i++) {
        if (count[i] > maxcount) {
            maxcount = count[i];
            maxlenght = strlen(arr_pwds[i]);
            a=i;
        }
        if (count[i] == maxcount) {
            if (strlen(arr_pwds[i]) > maxlenght) {
                maxlenght = strlen(arr_pwds[i]);
                a=i;
            }
        }
    }
    
    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////