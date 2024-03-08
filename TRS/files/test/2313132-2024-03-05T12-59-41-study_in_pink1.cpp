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
void resetHP(int & HP){
    if(HP > 666) HP = 666;
        else {if(HP < 0) HP = 0;}
}
void resetEXP(int & EXP){
    if(EXP > 600) EXP = 600;
        else {if(EXP < 0) EXP = 0;}
}
void resetM(int & M){
    if(M > 3000) M = 3000;
        else {if(M < 0) M = 0;}
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 >= 0 && e1 <= 3){
        double Exp1, Exp2;
        resetEXP(exp2);
        switch (e1) {
            case 0 : exp2 += 29; break;
            case 1 : exp2 += 45; break;
            case 2 : exp2 += 75; break;
            case 3 : exp2 += 149; break;
        }
        resetEXP(exp2);
        resetEXP(exp1);
        if ((e1*3 + exp1*7) % 2 == 0 ) {
            Exp1 = exp1 + ((e1*3 + exp1*7)/200.0);
        }   else Exp1 = exp1 - ((e1*3 + exp1*7)/100.0);

        exp1 = ceil(Exp1);
        resetEXP(exp1);
    }
    if (e1 >= 4 && e1 <= 99){
        double Exp1, Exp2;
        resetEXP(exp1);
        resetEXP(exp2);
        if (e1 <= 19) Exp2 = exp2 + (e1/4.0 + 19);
            else if (e1 <= 49) Exp2 = exp2 + (e1/9.0 + 21);
                else if (e1 <= 65) Exp2 = exp2 + (e1/16.0 + 17);
                    else if (e1 <= 79) {
                        Exp2 = exp2 + (e1/4.0 + 19);
                        exp2 = ceil(Exp2);
                            if(exp2 > 200) {
                                Exp2 = exp2 + (e1/9.0 + 21);
                            }
                    }
                        else {
                            Exp2 = exp2 + (e1/4.0 + 19);
                            exp2 = ceil(Exp2);
                            Exp2 = exp2 + (e1/9.0 + 21);
                            exp2 = ceil(Exp2);
                            if (exp2 > 400) {
                                Exp2 = exp2 + (e1/16.0 + 17);
                                exp2 = ceil(Exp2);
                                Exp2 = exp2*1.15;
                            }
                        }
        exp2 = ceil(Exp2);
        exp1 -= e1;
        resetEXP(exp1);
        resetEXP(exp2);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //Road 1
        resetEXP(EXP1);
        float P1;
        float a = round(sqrt(EXP1));
        float S = pow(a,2);
        if (EXP1 >= S) P1 = 100;
            else P1 = ((float)(EXP1/S)+80)/1.23;
    // End Road 1
    // Road 2
    int firstM1 = M1;
    float hp1,exp1;
    if (E2 % 2 != 0){
        tryAgain :
        resetHP(HP1);
        resetM(M1);
        if (HP1 < 200){
            hp1 = 1.3*HP1;
            HP1 = ceil(hp1);
            M1 -= 150;
        } else if (HP1 >= 200){
            hp1 = 1.1*HP1;
            HP1 = ceil(hp1);
            M1 -= 70;
        }
        resetHP(HP1);
        resetM(M1);
        if ((float)M1 < (float)(firstM1/2)) goto endRoad2;

        resetEXP(EXP1);
        if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
        exp1 = 1.13*EXP1;
        EXP1 = ceil(exp1);
        resetEXP(EXP1);
        resetM(M1);
        if ((float)M1 < (float)(firstM1/2)) goto endRoad2;

        if (EXP1 < 300) M1-= 100;
            else M1 -= 120;
        exp1 = 0.9*EXP1;
        EXP1 = ceil(exp1);
        resetEXP(EXP1);
        resetM(M1);
        if ((float)M1 < (float)(firstM1/2)) goto endRoad2;
            else goto tryAgain;
    }
        else {  resetHP(HP1);
                resetM(M1);
                double hp1,exp1;
                if (HP1 < 200){
                    hp1 = 1.3*HP1;
                    HP1 = ceil(hp1);
                    M1 -= 150;
                } else {
                    hp1 = 1.1*HP1;
                    HP1 = ceil(hp1);
                    M1 -= 70;
                }
                resetHP(HP1);
                resetM(M1);
                if (M1 == 0) goto endRoad2;

                resetEXP(EXP1);
                if (EXP1 < 400) M1 -= 200;
                    else M1 -= 120;
                exp1 = 1.13*EXP1;
                EXP1 = ceil(exp1);
                resetEXP(EXP1);
                resetM(M1);
                if (M1 == 0) goto endRoad2;
                if (EXP1 < 300) M1-= 100;
                    else M1 -= 120;
                exp1 = 0.9*EXP1;
                EXP1 = ceil(exp1);
                resetEXP(EXP1);
                resetM(M1);
            }
            endRoad2 :
                hp1 = 0.83*HP1;
                HP1 = ceil(hp1);
                exp1 = 1.17*EXP1;
                EXP1 = ceil(exp1);
                resetHP(HP1);
                resetEXP(EXP1);
        float P2;
        a = round(sqrt(EXP1));
        S = pow(a,2);
        if (EXP1 >= S) P2 = 100;
            else P2 = ((float)(EXP1/S)+80)/123;
    //End Road 2
    // Road 3
    float P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 0 && E2 <= 9) P3 = P[E2];
    if (E2 >= 10 && E2 <= 99) P3 = P[((E2/10)+(E2%10))%10];
    // End Road 3
    if(P1 == 100 && P2 == 100 && P3 == 100) {
            exp1 = 0.75*EXP1;
            EXP1 = ceil(exp1);
            resetEXP(EXP1);
    } else {
        float p = (P1 + P2 + P3)/3;
        if (p < 50){
                hp1 = 0.85*HP1;
                HP1 = ceil(hp1);
                exp1 = 1.15*EXP1;
                EXP1 = ceil(exp1);
                resetEXP(EXP1);
                resetHP(HP1);
        }   else if (p >= 50){
                hp1 = 0.9*HP1;
                HP1 = ceil(hp1);
                exp1 = 1.2*EXP1;
                EXP1 = ceil(exp1);
                resetEXP(EXP1);
                resetHP(HP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    //Tao ma tran
        float hp1,hp2,exp1,exp2;
        int matrix[10][10];
        for(int i = 0 ; i <= 9; i++){
            for(int j = 0 ; j <=9 ; j++){
                matrix[i][j] = ((E3*j) + (i*2))*(i-j);
            }
        }
    //Tim diem gap nhau
        int I = 0 , J = 0;
        for(int i = 0 ; i <= 9; i++){
            for(int j = 0 ; j <=9 ; j++){
                if(matrix[i][j] > E3*2) I++;
                if(matrix[i][j] < -E3) J++;
            }
        }
        while(I > 9) I = (I/10) + (I%10);
        while(J > 9) J = (J/10) + (J%10);
    //Tim diem cua taxi
        int pointTaxi = matrix[I][J];
    //Tim diem cua SL
        int maxPoint = matrix[I][J];
        //Tim hai diem bat dau cua hai duong cheo
            int i1,i2,j1,j2;
            if(I == J) {i1 = 0; j1 =0;}
                else {
                    i1 = I - min(I,J);
                    j1 = J - min(I,J);
                }
            if(I + J == 9 ) {i2 = 9; j2 =0;}
                else {
                    j2 = I - min(I,9-J);
                    i2 = J + min(I,9-J);
                }

        int m = i1 , n = j1;
        while (m != 9 && n != 9) {
            if(matrix[m][n] > maxPoint) maxPoint = matrix[m][n];
            m++;
            n++;
        }
         m = i2, n = j2;
        while (m != 0 && n != 9 ) {
            if(matrix[m][n] > maxPoint) maxPoint = matrix[m][n];
            m--;
            n++;
        }
        if(abs(pointTaxi) > abs(maxPoint)){
            exp1 = 0.88*EXP1;
            EXP1 = ceil(exp1);
            exp2 = 0.88*EXP2;
            EXP2 = ceil(exp2);
            hp1 = 0.9*HP1;
            HP1 = ceil(hp1);
            hp2 = 0.9*HP2;
            HP2 = ceil(hp2);
            resetEXP(EXP1);resetEXP(EXP2);
            resetHP(HP1);resetHP(HP2);
            return pointTaxi;
        } else {
            exp1 = 1.12*EXP1;
            EXP1 = ceil(exp1);
            exp2 = 1.12*EXP2;
            EXP2 = ceil(exp2);
            hp1 = 1.1*HP1;
            HP1 = ceil(hp1);
            hp2 = 1.1*HP2;
            HP2 = ceil(hp2);
            resetEXP(EXP1);resetEXP(EXP2);
            resetHP(HP1);resetHP(HP2);
            return maxPoint;
        }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string pass = s;
    string mail = email;
    // Tim se
    int i = 0;
    string se = "";
    while (mail[i] != '@'){
        se.push_back(mail[i]);
        i++;
    }
    // Kiem tra pass
    if (pass.length() < 8) return -1;
    if (pass.length() > 20) return -2;

    for (int i = 0 ; i <= pass.length() - ((se.length() > 3) ? 3 : se.length()); i++){
        if(se == pass.substr(i,se.length())) return -(300+i);
        if(pass[i] == pass[i+1] && pass[i+1] == pass[i+2]) return -(400+i);
    }
    for (int n = 0; n< pass.length();n++){
        if(pass[n] == '@' || pass[n] == '#' || pass[n] == '$' || pass[n] == '%' || pass[n] == '!' ){
            goto qualified;
        }
    }
    return -5;
    qualified :
        return -10;
}

// Task 5
int countRepeat(const char * arr_pwds[], int num_pwds, string s){
            int numberRepeat = 0;
            for (int i = 0 ; i< num_pwds;i++){
                if(arr_pwds[i] == s) numberRepeat++;
            }
            return numberRepeat;
        }
int string_length(const char *str) {
    int length;
    for (length = 0; str[length] != '\0'; length++);
    return length;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //Max Count Repeat
            string final[30];
            string s_final;
            int result;
            int number_final = 0;
            int maxCount = countRepeat(arr_pwds,num_pwds,arr_pwds[0]);
            for(int i = 0 ; i < num_pwds; i++){
                if(countRepeat(arr_pwds,num_pwds,arr_pwds[i]) > maxCount) maxCount = countRepeat(arr_pwds,num_pwds,arr_pwds[i]);
            }
             for(int i = 0 ; i < num_pwds; i++){
                if(countRepeat(arr_pwds,num_pwds,arr_pwds[i]) == maxCount){
                    final[number_final] = arr_pwds[i];
                    number_final++;
                }
            }
            int maxLength = final[0].length();
            for(int i = 0 ; i < number_final;i++){
                if(final[i].length() > maxLength) maxLength = final[i].length();
            }
            for(int i = 0 ; i < number_final;i++){
                if(final[i].length() == maxLength)  s_final = final[i];
            }
            for(int i = 0 ; i < num_pwds; i++){
                if(arr_pwds[i] == s_final) {result = i; break;}
            }
            return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
