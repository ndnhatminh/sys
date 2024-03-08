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

// Helper functions
int roundNumber(double num){
    int roundnum = (int)num;
    if(num - roundnum > 0) return roundnum+1;
    return roundnum;
}
int findNearest_square(int exp1){
    double tmp_double = sqrt(exp1);
    if(tmp_double - (int)tmp_double == 0) return exp1;
    int tmp = (int)tmp_double;
    int lower = tmp*tmp;
    int higher = (tmp+1)*(tmp+1);
    if((higher - exp1) > (exp1 - lower)) return lower;
    else return higher;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0 || e1>99) return -99;
    else if(e1>=0 && e1<=3){// Case 1
        if(e1==0) exp2 = (exp2+29 > 600) ? 600 : (exp2+29);
        else if(e1==1) exp2 = (exp2+45 > 600) ? 600 : (exp2+45);
        else if(e1==2) exp2 = (exp2+75 > 600) ? 600 : (exp2+75);
        else if(e1==3) exp2 = (exp2+149 > 600) ? 600 : (exp2+149);

        int d = e1*3 + exp1*7;
        if(d%2 == 0){
            exp1 = roundNumber(exp1 + (d/200.00));
            exp1 = (exp1 > 600) ? 600 : exp1;
        }
        else{
            exp1 = roundNumber(exp1 - (d/100.00));
            exp1 = (exp1 < 0) ? 0 : exp1;
        }
    }
    else if(e1>=4 && e1<=99){// Case 2
        if(e1>=4 && e1<=19){// Information 1
            exp2 = roundNumber(exp2 + e1/4.00 + 19);
            exp2 = (exp2 > 600) ? 600 : exp2;
        }
        else if(e1>=20 && e1<=49){// Information 2
            exp2 = roundNumber(exp2 + e1/9.00 + 21);
            exp2 = (exp2 > 600) ? 600 : exp2;
        }
        else if(e1>=50 && e1<=65){// Information 3
            exp2 = roundNumber(exp2 + e1/16.00 + 17);
            exp2 = (exp2 > 600) ? 600 : exp2;
        }
        else if(e1>=66 && e1<=79){// Information 4
            // Information 1
            exp2 = roundNumber(exp2 + e1/4.00 + 19);
            exp2 = (exp2 > 600) ? 600 : exp2;
            if(exp2 > 200){
                // Information 2
                exp2 = roundNumber(exp2 + e1/9.00 + 21);
                exp2 = (exp2 > 600) ? 600 : exp2;
            }
        }
        else if(e1>=80 && e1<=99){// Information 5
            // Information 1
            exp2 = roundNumber(exp2 + e1/4.00 + 19);
            exp2 = (exp2 > 600) ? 600 : exp2;
            // Information 2
            exp2 = roundNumber(exp2 + e1/9.00 + 21);
            exp2 = (exp2 > 600) ? 600 : exp2;
            if(exp2 > 400){
                // Information 3
                exp2 = roundNumber(exp2 + e1/16.00 + 17);
                exp2 = (exp2 > 600) ? 600 : exp2;
                // When heard all 3 Information, bonus 15% exp2
                exp2 = roundNumber(exp2 + 0.15*exp2);
                exp2 = (exp2 > 600) ? 600 : exp2;
            }
        }
        exp1 = (exp1 - e1 < 0) ? 0 : (exp1 - e1);

    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99) return -99;
    HP1 = HP1>666 ? 666 : HP1;
    HP1 = HP1<0? 0 : HP1;
    EXP1 = EXP1>600 ? 600 : EXP1;
    EXP1 = EXP1<0? 0 : EXP1;
    M1 = M1>3000 ? 3000 : M1;
    M1 = HP1<0? 0 : M1;
    // ROAD 1 ///////////////////////////////////
    int S1 = findNearest_square(EXP1);
    double P1 = 0;

    if(EXP1>=S1) P1 = 1.00;
    else{
        P1 = (EXP1/S1 + 80.00)/123.00;
    }
    // ROAD 2 ///////////////////////////////////
    if(E3%2 != 0 && M1!=0){
        int prev_M1 = M1;
        while((prev_M1 - M1) <= (0.5*prev_M1)){
            if(HP1<200){
                HP1 = roundNumber(HP1 + 0.3*HP1);
                HP1 = (HP1>666) ? 666 : HP1;
                M1 -= 150;
                M1 = M1<0 ? 0 : M1;
            }
            else{
                HP1 = roundNumber(HP1 + 0.1*HP1);
                HP1 = (HP1>666) ? 666 : HP1;
                M1 -= 70;
                M1 = M1<0 ? 0 : M1;
            }
            if((prev_M1 - M1) > (0.5*prev_M1)) break;

            if(EXP1<400) M1 -= 200;
            else M1-= 120;
            M1 = M1<0 ? 0 : M1;
            EXP1 = roundNumber(EXP1 + 0.13*EXP1);
            EXP1 = (EXP1>600) ? 600 : EXP1;
            if((prev_M1 - M1) > (0.5*prev_M1)) break;

            if(EXP1<300) M1-= 100;
            else M1 -= 120;
            M1 = M1<0 ? 0 : M1;
            EXP1 = roundNumber(EXP1 - 0.1*EXP1);
            EXP1 = (EXP1<0) ? 0 : EXP1;
            if((prev_M1 - M1) > (0.5*prev_M1)) break;
        }
        HP1 = roundNumber(HP1 - 0.17*HP1);
        HP1 = (HP1<0) ? 0 : HP1;
        EXP1 = roundNumber(EXP1 + 0.17*EXP1);
        EXP1 = (EXP1>600) ? 600 : EXP1;
    }
    else if(E3%2 == 0 && M1!=0){
        if(HP1<200){
                HP1 = roundNumber(HP1 + 0.3*HP1);
                HP1 = (HP1>666) ? 666 : HP1;
                M1 -= 150;
                M1 = M1<0 ? 0 : M1;
            }
        else{
            HP1 = roundNumber(HP1 + 0.1*HP1);
            HP1 = (HP1>666) ? 666 : HP1;
            M1 -= 70;
            M1 = M1<0 ? 0 : M1;
        }
        if(M1!=0){
            if(EXP1<400) M1 -= 200;
            else M1-= 120;
            M1 = M1<0 ? 0 : M1;
            EXP1 = roundNumber(EXP1 + 0.13*EXP1);
            EXP1 = (EXP1>600) ? 600 : EXP1;
            
            if(M1!=0){
                if(EXP1<300) M1-= 100;
                else M1 -= 120;
                M1 = M1<0 ? 0 : M1;
                EXP1 = roundNumber(EXP1 - 0.1*EXP1);
                EXP1 = (EXP1<0) ? 0 : EXP1;
            }
        }
        HP1 = roundNumber(HP1 - 0.17*HP1);
        HP1 = (HP1<0) ? 0 : HP1;
        EXP1 = roundNumber(EXP1 + 0.17*EXP1);
        EXP1 = (EXP1>600) ? 600 : EXP1;
    }
    else if(M1==0){
        HP1 = roundNumber(HP1 - 0.17*HP1);
        HP1 = (HP1<0) ? 0 : HP1;
        EXP1 = roundNumber(EXP1 + 0.17*EXP1);
        EXP1 = (EXP1>600) ? 600 : EXP1;
    }
    int S2 = findNearest_square(EXP1);
    double P2 = 0;
    if(EXP1>=S2) P2 = 1.00;
    else{
        P2 = (((double)EXP1/(double)S2) + 80.00)/123.00;
    }
    // ROAD 3 ///////////////////////////////////
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3=0;
    if(E3<=9) P3 = P[E3]/100.00;
    else{
        int index = ((E3/10) + (E3%10)) % 10;
        P3 = P[index]/100.00;
    }
    // END OF 3 ROADS ///////////////////////////////////
    if(P1 == 1.00 && P2 == 1.00 && P3 == 1.00){
        EXP1 = roundNumber(EXP1 - 0.25*EXP1);
        EXP1 = (EXP1<0) ? 0 : EXP1;
    }
    else{
        double P_average = (P1+P2+P3)/3.00;
        if(P_average < 0.5){
            HP1 = roundNumber(HP1 - 0.15*HP1);
            HP1 = (HP1<0) ? 0 : HP1;
            EXP1 = roundNumber(EXP1 + 0.15*EXP1);
            EXP1 = (EXP1>600) ? 600 : EXP1;
        }
        else{
            HP1 = roundNumber(HP1 - 0.1*HP1);
            HP1 = (HP1<0) ? 0 : HP1;
            EXP1 = roundNumber(EXP1 + 0.2*EXP1);
            EXP1 = (EXP1>600) ? 600 : EXP1;
        }
    }
    //
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99) return -99;
    HP1 = HP1>666 ? 666 : HP1;
    HP1 = HP1<0? 0 : HP1;
    HP2 = HP2>666 ? 666 : HP2;
    HP2 = HP2<0? 0 : HP2;
    EXP1 = EXP1>600 ? 600 : EXP1;
    EXP1 = EXP1<0? 0 : EXP1;
    EXP2 = EXP2>600 ? 600 : EXP2;
    EXP2 = EXP2<0? 0 : EXP2;
    int matrix[10][10] = {};
    int index_i = 0;
    int index_j = 0;
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            matrix[i][j] = ((E3*j)+(i*2))*(i-j);
            if(matrix[i][j] > E3*2) ++index_i;
            else if(matrix[i][j] < (-E3)) ++index_j;
        }
    }
    while(index_i >= 10){
        index_i = (index_i/10) + (index_i%10);
    }
    while(index_j >= 10){
        index_j = (index_j/10) + (index_j%10);
    }
    int chaser_point = matrix[index_i][index_j];
    int i = index_i;
    int j = index_j;
    while(i>=0 && j<10){
        chaser_point = (matrix[i][j]>chaser_point) ? matrix[i][j] : chaser_point;
        --i;
        ++j;
    }
    i = index_i;
    j = index_j;
    while(i<10 && j>=0){
        chaser_point = (matrix[i][j]>chaser_point) ? matrix[i][j] : chaser_point;
        ++i;
        --j;
    }
    i = index_i;
    j = index_j;
    while(i>=0 && j>=0){
        chaser_point = (matrix[i][j]>chaser_point) ? matrix[i][j] : chaser_point;
        --i;
        --j;
    }
    i = index_i;
    j = index_j;
    while(i<10 && j<10){
        chaser_point = (matrix[i][j]>chaser_point) ? matrix[i][j] : chaser_point;
        ++i;
        ++j;
    }
    chaser_point = (chaser_point < 0) ? (-chaser_point) : chaser_point;
    if(abs(matrix[index_i][index_j]) > chaser_point){
        HP1 = roundNumber(HP1 - 0.1*HP1);
        HP1 = (HP1<0) ? 0 : HP1;
        HP2 = roundNumber(HP2 - 0.1*HP2);
        HP2 = (HP2<0) ? 0 : HP2;
        EXP1 = roundNumber(EXP1 - 0.12*EXP1);
        EXP1 = (EXP1<0) ? 0 : EXP1;
        EXP2 = roundNumber(EXP2 - 0.12*EXP2);
        EXP2 = (EXP2<0) ? 0 : EXP2;
        return matrix[index_i][index_j];
    }
    else{
        HP1 = roundNumber(HP1 + 0.1*HP1);
        HP1 = (HP1>666) ? 666 : HP1;
        HP2 = roundNumber(HP2 + 0.1*HP2);
        HP2 = (HP2>666) ? 666 : HP2;
        EXP1 = roundNumber(EXP1 + 0.12*EXP1);
        EXP1 = (EXP1>600) ? 600 : EXP1;
        EXP2 = roundNumber(EXP2 + 0.12*EXP2);
        EXP2 = (EXP2>600) ? 600 : EXP2;
        return chaser_point;
    }

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int size_s = strlen(s);
    int size_email = strlen(email);
    // Check length criteria
    if(size_s<8) return -1;
    else if(size_s>20) return -2;
    // Check if s contains se
    int size_se=0;
    for(int i=0;i<size_email;++i){
        if(email[i]=='@') break;
        ++size_se;
    }
    char se[100];
    strncpy(se,email,size_se);
    se[size_se] = '\0';
    const char* p_se = nullptr;
    p_se = strstr(s,se);
    if(p_se!=nullptr){// s including se
        int sei = p_se - s;
        return -(300 + sei);
    }
    // Check if s contains more than 2 continuous and same characters
        // Note: Apply sliding window method with size = 3
    for(int i=0;i<size_s-2;++i){
        if(s[i] == s[i+1] && s[i+1] == s[i+2]){
            return -(400+i);
        }
    }
    // Check if s contains any special characters
    bool sp_char = false;
    for(int i=0;i<size_s;++i){
        if(s[i] == '@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!'){
            sp_char = true;
            break;
        }
    }
    if(sp_char==false) return -5;
    // Check if s contains unvalid characters
    for(int i=0;i<size_s;++i){
        if(s[i]>='0' && s[i]<='9'){}
        else if(s[i]>='a' && s[i]<='z'){}
        else if(s[i]>='A' && s[i]<='Z'){}
        else if(s[i] == '@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!'){}
        else return i; 
    }
    // Valid Password
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int* ds_pwds = new int[50];// store index of distinct password in arr_pwds[]
    ds_pwds[0]=0;
    int num_ds_pwd = 1;
    bool repeat = false;
    int* freq = new int[50];
    freq[0] = 1;
    for(int i=1;i<num_pwds;++i){
        repeat = false;
        for(int j=0;j<num_ds_pwd;++j){
            if(strcmp(arr_pwds[ds_pwds[j]],arr_pwds[i])==0){
                freq[j] += 1;
                repeat = true;
                break;
            }
        }
        if(repeat == false){
            ds_pwds[num_ds_pwd] = i;
            freq[num_ds_pwd] = 1;
            ++num_ds_pwd;
        }
    } 
    // Find maximum frequency
    int max_freq = freq[0];
    for(int i=0;i<num_ds_pwd;++i){
        max_freq = max(freq[i],max_freq);
    }
    // Find maxmium length among the most repeated passwords
    int max_length = 0;
    for(int i=0;i<num_ds_pwd;++i){
        if(freq[i]==max_freq){
            int tmp_length = strlen(arr_pwds[ds_pwds[i]]);
            max_length = max(max_length, tmp_length);
        }
    }
    // Find the most freqent and longest password (right password) and return its index
    int return_value = 0;
    for(int i=0;i<num_ds_pwd;++i){
        if(freq[i] == max_freq && strlen(arr_pwds[ds_pwds[i]]) == max_length){
            return_value = ds_pwds[i];
            break;
        } 
    }
    delete[] ds_pwds;
    delete[] freq;
    return return_value;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////