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

    if (exp1>600) exp1=600;
    if (exp1<0) exp1=0;
    if (exp2>600) exp2=600;
    if (exp2<0) exp2=0;

    switch (e1)
    {
    case 0:
        exp2=exp2+29;
        break;
    case 1:
        exp2=exp2+45;
        break;
    case 2:
        exp2=exp2+75;
        break;
    case 3:
        exp2=exp2+149;
        break;
    case 4 ... 19:
        exp2=ceil(exp2+((e1/4.0)+19));
        break;
    case 20 ... 49:
        exp2=ceil(exp2+((e1/9.0)+21));
        break;
    case 50 ... 65:
        exp2=ceil(exp2+((e1/16.0)+17));
        break;
    case 66 ... 79:
        exp2=exp2+((e1/4)+19);
        if (exp2>200) exp2=exp2+((e1/9.0)+21);
        break;
    case 80 ... 99:
        exp2=ceil(exp2+((e1/4.0)+19));
        exp2=ceil(exp2+((e1/9.0)+21));
        if (exp2>400) exp2=ceil(exp2+((e1/16.0)+17));
        exp2=ceil(exp2*115/100.0);
        break;
    default:
        break;
    }

    switch (e1)
    {
    case 0 ... 3:
        if ((e1*3+exp1*7)%2==0){
            exp1=ceil(exp1+(e1*3+exp1*7)/200.0);
        }
        else exp1=ceil(exp1-(e1*3+exp1*7)/100.0);
        break;
    case 4 ... 99:
        exp1=exp1-e1;
        break;
    default:
        break;
    }

    if (exp1>600) exp1=600;
    if (exp1<0) exp1=0;
    if (exp2>600) exp2=600;
    if (exp2<0) exp2=0;
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (HP1>666) HP1=666;
    if (HP1<0) HP1=0;
    if (EXP1>600) EXP1=600;
    if (EXP1<0) EXP1=0;
    if (M1<0) M1=0;
    if (M1>3000) M1=3000;
    double s;
    int i;
    double p1,p2,p3;
    int ms=0; //money spent
    int ml=ceil(M1*0.5); //money limmit
    s=floor(sqrt(EXP1));
    if (s*s!=EXP1) {
        if (abs((s+1)*(s+1))-EXP1>abs(s*s)-EXP1) {
            s=s*s;
        }
        else s=(s+1)*(s+1);
    }
    if (EXP1>=s) {
        p1=1;
    }
    else p1=((EXP1/s) + 80 )/123;

    //E2 is odd
    while (true) {
        if ((E2%2)!=0){
            if (HP1<200) {
                HP1=ceil(HP1*1.3);
                M1=M1-150;
                ms=ms+150;
                if (HP1>666) HP1=666;
            }
            else {
                HP1=ceil(HP1*1.1);
                M1=M1-70;
                ms=ms+70;
                if (HP1>666) HP1=666;
            }
            if (M1 <= 0 || ms > ml) {
                HP1=ceil(HP1*0.83);
                EXP1=ceil(EXP1*1.17);
                if (EXP1>600) EXP1=600;
                break;
            }

            if (EXP1<400) {
                M1=M1-200;
                ms=ms+200;
                EXP1=ceil(EXP1*1.13);
                if (EXP1>600) EXP1=600;
            }
            else {
                M1=M1-120;
                ms=ms+120;
                EXP1=ceil(EXP1*1.13);
                if (EXP1>600) EXP1=600;
            }
            if (M1 <= 0 || ms > ml) {
                HP1=ceil(HP1*0.83);
                EXP1=ceil(EXP1*1.17);
                if (EXP1>600) EXP1=600;
                break;
            } 

            if (EXP1<300) {
                M1=M1-100;
                ms=ms+100;
                EXP1=ceil(EXP1*0.9);
            }
            else {
                M1=M1-120;
                ms=ms+120;
                EXP1=ceil(EXP1*0.9);
            }
            if (M1 <= 0 || ms > ml) {
                HP1=ceil(HP1*0.83);
                EXP1=ceil(EXP1*1.17);
                if (EXP1>600) EXP1=600;
                break;
            }                 
        }
    }      

    // E2 is even
    while ((E2%2)==0) {
        if (HP1<200){
            HP1=ceil(HP1*1.3);
            M1=M1-150;
            if (HP1>666) HP1=666;
        }
        else {
            HP1=ceil(HP1*1.1);
            M1=M1-70;
            if (HP1>666) HP1=666;
        }
        if (M1 <= 0) {
            HP1=ceil(HP1*0.83);
            EXP1=ceil(EXP1*1.17);
            if (EXP1>600) EXP1=600;
            break;
        }

        if (EXP1<400){
            M1=M1-200;
            EXP1=ceil(EXP1*1.13);
            if (EXP1>600) EXP1=600;
        }
        else {
            M1=M1-120;
            EXP1=ceil(EXP1*1.13);
            if (EXP1>600) EXP1=600;
        }
        if (M1 <= 0) {
            HP1=ceil(HP1*0.83);
            EXP1=ceil(EXP1*1.17);
            if (EXP1>600) EXP1=600;
            break;
        } 

        if (EXP1<300){
            M1=M1-100;
            EXP1=ceil(EXP1*0.9);
        }
        else {
            M1=M1-120;
            EXP1=ceil(EXP1*0.9);
        }
        if (M1 <= 0) {
            HP1=ceil(HP1*0.83);
            EXP1=ceil(EXP1*1.17);
            if (EXP1>600) EXP1=600;
            break;
        }
        HP1=ceil(HP1*0.83);
        EXP1=ceil(EXP1*1.17);
        break;   
    }
    
    if (HP1>666) HP1=666;
    if (HP1<0) HP1=0;
    if (EXP1>600) EXP1=600;
    if (EXP1<0) EXP1=0;
    if (M1<0) M1=0;
    if (M1>3000) M1=3000;


    s=floor(sqrt(EXP1));
    if (s*s!=EXP1){
        if (abs((s+1)*(s+1))-EXP1>abs(s*s)-EXP1){
            s=s*s;
        }
        else s=(s+1)*(s+1);
    }
    if (EXP1>=s){
        p2=1;
    }
    else p2=((EXP1/s) + 80 )/123;

    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) {
        // E2 is a one-digit number
        i = E2;  
    } 
    else {
        // E2 is a two-digit number
        i = ((E2 / 10) + (E2 % 10)) % 10;
    }
    p3=P[i];

    if((p1==p2==p3==1)){
        EXP1=ceil(EXP1*0.75);
    }
    else{
        double pavg=((p1+p2+p3)/3);
        if (pavg<0.5) {
            HP1=ceil(HP1*0.85);
            EXP1=ceil(EXP1*1.15);
        }
        else {
            HP1=ceil(HP1*0.9);
            EXP1=ceil(EXP1*1.2);
        }
    }
    if (EXP1>600) EXP1=600;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int taxi_scores[10][10];
    int sw_scores[10][10];
    int right_dia, left_dia;
    int k,l;
    int verdict;

    if (HP1>666) HP1=666;
    if (HP1<0) HP1=0;
    if (EXP1>600) EXP1=600;
    if (EXP1<0) EXP1=0;
    if (HP2>666) HP2=666;
    if (HP2<0) HP2=0;
    if (EXP2>600) EXP2=600;
    if (EXP2<0) EXP2=0;

    // Calculate taxi score matrix    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxi_scores[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    } 
    //Show taxi score matrix   
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j < 10; ++j) {
    //         cout<< taxi_scores[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    //Calculate sw score matrix    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(i>j){
                k=i-j;
                l=0;
                left_dia=taxi_scores[i-j][0];
                while(k<=9) {
                    if(taxi_scores[k][l]>left_dia) {
                        left_dia=taxi_scores[k][l];
                    }
                    k++;
                    l++;
                }
            }
            else if(i<j){
                k=0;
                l=j-i;
                left_dia=taxi_scores[0][j-i];
                while(l<=9) {
                    if (taxi_scores[k][l]>left_dia) {
                        left_dia=taxi_scores[k][l];
                    }
                    k++;
                    l++;
                }
            }
            else left_dia=0;

            if(i+j>=9) {
                k=i+j-9;
                l=9;
                right_dia=taxi_scores[i+j-9][9];
                while(k<=9) {
                    if(taxi_scores[k][l]>right_dia) {
                        right_dia=taxi_scores[k][l];
                    }
                    k++;
                    l--;
                }
            }
            else {
                k=0;
                l=i+j;
                right_dia=taxi_scores[0][i+j];
                while(k<=i+j) {
                    if (taxi_scores[k][l]>right_dia) {
                        right_dia=taxi_scores[k][l];
                    }
                    k++;
                    l--; 
                }
            }
            if (right_dia>=left_dia) {
                sw_scores[i][j]=right_dia;
            }
            else sw_scores[i][j]=left_dia;
        }
    }
    //Show sw score matrix   
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j < 10; ++j) {
    //         cout<< sw_scores[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // Calculate meeting point index p1
    int i_count = 0, j_count = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (taxi_scores[i][j] > E3 * 2) {
                i_count++;
            }
            if (taxi_scores[i][j] < -E3) {
                j_count++;
            }
        }
    }
    // Calculate meeting point index p2
    while (i_count >= 10) {
        i_count = (i_count / 10) + (i_count % 10);
    }
    while (j_count >= 10) {
        j_count = (j_count / 10) + (j_count % 10);
    }
    
    //cout<<"meet point:("<<i_count<<","<<j_count<<")\n"; // Checking meet point
    if (abs(taxi_scores[i_count][j_count])>abs(sw_scores[i_count][j_count])) {
        HP1=ceil(HP1*0.9);
        EXP1=ceil(EXP1*0.88);
        HP2=ceil(HP2*0.9);
        EXP2=ceil(EXP2*0.88);
        verdict=taxi_scores[i_count][j_count];
    }   
    else {
        HP1=ceil(HP1*1.1);
        EXP1=ceil(EXP1*1.12);
        HP2=ceil(HP2*1.1);
        EXP2=ceil(EXP2*1.12);
        verdict=sw_scores[i_count][j_count];
    }
    if (HP1>666) HP1=666;
    if (HP1<0) HP1=0;
    if (EXP1>600) EXP1=600;
    if (EXP1<0) EXP1=0;
    if (HP2>666) HP2=666;
    if (HP2<0) HP2=0;
    if (EXP2>600) EXP2=600;
    if (EXP2<0) EXP2=0;

    return verdict;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Check length of s
    int len = strlen(s);
    if (len < 8) return -1; // shorter than minimum length
    if (len > 20) return -2; // longer than maximum length

    // Extract the string before '@' from s
    string emailStr(email);
    size_t pos = emailStr.find('@');
    string se = emailStr.substr(0, pos);

    // Check if s contains se
    const char *found = strstr(s, se.c_str());
    if (found != nullptr) {
        return -(300 + (found - s)); // first occurrence of se
    }

    // Check for more than 2 consecutive identical characters
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // pos of first string containing more than 2 consecutive identical characters
        }
    }

    // Check for special character
    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i) {
        char ch = s[i];
        if (!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
              ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!')) {
            return -(i + 1); // position of first character violating validity requirement
        }
        if (ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!') {
            hasSpecialChar = true;
        }
    }
    if (!hasSpecialChar) return -5; // does not contain special characters

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int password_count[num_pwds] = {0};
    int password_length[num_pwds] = {0};

    // Count occurrences and lengths of passwords
    for (int i = 0; i < num_pwds; ++i) {
        const char *password = arr_pwds[i];
        int len = strlen(password);

        // Store length
        password_length[i] = len;

        // Count occurrences
        for (int j = 0; j < num_pwds; ++j) {
            if (j != i && strcmp(password, arr_pwds[j]) == 0) {
                password_count[i]++;
            }
        }
    }

    // Find the correct password
    int max_occurrences = 0;
    int max_length = 0;
    int correct_password_index = -1;

    for (int i = 0; i < num_pwds; ++i) {
        if (password_count[i] > max_occurrences || (password_count[i] == max_occurrences && password_length[i] > max_length)) {
            max_occurrences = password_count[i];
            max_length = password_length[i];
            correct_password_index = i;
        }
    }

    return correct_password_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////