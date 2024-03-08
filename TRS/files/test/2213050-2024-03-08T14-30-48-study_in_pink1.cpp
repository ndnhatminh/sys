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
int find_neareat_Square(int n){
    int i = sqrt(n);
    if(i*i == n) return i*i;
    else{
        if(abs(n - i*i) < abs(n - (i+1)*(i+1))) return i*i;
        else return (i+1)*(i+1);
    }
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99) return -99;

    if(exp1 > 600) exp1 = 600; if(exp1 < 0) exp1 = 0;
    if(exp2 > 600) exp2 = 600; if(exp2 < 0) exp2 = 0;

    if((e1 >= 0 ) && (e1 <= 3)){
        switch(e1){
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

        if(exp2 > 600) exp2 = 600;

        int D = e1*3 + exp1*7;
        if( D%2 != 0){
            int sub = D/100.0;
            exp1 = exp1 - sub;
            if(exp1 < 0) exp1 = 0;
        }
        else{
            float plus = D/200.0;
            exp1 = exp1 + plus + 0.9999;
            if(exp1 > 600) exp1 = 600;
        }
    }
    else if((e1 >= 4) && (e1 <= 99)){
        //tt1
        if((e1 >= 4) && (e1 <= 19)){
            float plus = 19 + e1/4.0;
            exp2 = exp2 + plus + 0.9999;
            if(exp2 > 600) exp2 = 600;
        }
        //tt2
        else if((e1 >= 20) && (e1 <= 49)){
            float plus = 21 + e1/9.0;
            exp2 = exp2 + plus + 0.9999;
            if(exp2 > 600) exp2 = 600;
        }
        //tt3
        else if((e1 >= 50) && (e1 <= 65)){
             float plus = 17 + e1/16.0;
            exp2 = exp2 + plus + 0.9999;
            if(exp2 > 600) exp2 = 600;
        }
        //tt4
        else if((e1 >= 66) && (e1 <= 79)){
            float plus = 19 + e1/4.0;
            exp2 = exp2 + plus + 0.9999;
            if(exp2 > 600) exp2 = 600;

            if(exp2 > 200){
                float plus = 21 + e1/9.0;
            exp2 = exp2 + plus + 0.9999;
            if(exp2 > 600) exp2 = 600;
            }
        }
        //tt5
        else if((e1 >= 80) && (e1 <= 99)){
             float plus = 19 + e1/4.0;
            exp2 = exp2 + plus + 0.9999;
            if(exp2 > 600) exp2 = 600;

             float pluss = 21 + e1/9.0;
            exp2 = exp2 + pluss + 0.9999;
            if(exp2 > 600) exp2 = 600;

            bool check = false;
            if(exp2 > 400){
                check = true;
                float plus = 17 + e1/16.0;
                exp2 = exp2 + plus + 0.9999;
             if(exp2 > 600) exp2 = 600;
            }

            if(check == true){
                float plus = 0.15*exp2;
                exp2 = exp2 + plus + 0.9999;
                if(exp2 > 600) exp2 = 600;
            }
        }

        exp1 -= e1;
        if(exp1 < 0) exp1 = 0;
    }
    else return exp1 + exp2;

    return exp1 + exp2;
}

// Task 2   
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;

    if(EXP1 > 600) EXP1 = 600; if(EXP1 < 0) EXP1 = 0;
    if(HP1 > 666) HP1 = 666; if(HP1 < 0) HP1 = 0;
    if(M1 < 0) M1 = 0; if(M1 > 3000) M1 = 3000;

    float probality_1 = 1.0;
    int S = find_neareat_Square(EXP1);
    if(S > EXP1) probality_1 = (EXP1/(S*1.0) + 80)/123.0;

    if(E2%2 == 0){
        if(M1 != 0){
            if(HP1 >= 200){// event 1
                //float plus = 0.1*HP1;
                HP1 = HP1 + 0.1*HP1 + 0.9999;
                if(HP1 > 666) HP1 = 666;

                M1 -= 70;
                if(M1 < 0) M1 = 0;
            }
            else{
                //float plus = 0.3*HP1;
                HP1 = HP1 + 0.3*HP1 + 0.9999;   
                if(HP1 > 666) HP1 = 666;
            
                M1 -= 150;
                if(M1 < 0) M1 = 0;
            }
            //event 2  
            if(M1 != 0){
                if(EXP1 < 400){
                    M1 -= 200;
                    if(M1 < 0) M1 = 0;
                }
                else{
                    M1 -= 120;
                    if(M1 < 0) M1 = 0;
                }

                //float plus = 0.13*EXP1;
                EXP1 = EXP1 + 0.13*EXP1 + 0.9999;
                // event 3
                if(M1 != 0){
                    if(EXP1 < 300){
                        M1 -= 100;
                        if(M1 < 0) M1 = 0;
                    }
                    else{
                        M1 -= 120;
                        if(M1 < 0) M1 = 0;
                    }
                    float subs = int(0.1*EXP1);
                    EXP1 -= subs; 
                    if(EXP1 < 0) EXP1 = 0;

                }
            }

        }
        ///go along the road
    }
    else{ //E2 is odd
        int m_50percent = 0.5*M1;
        int tax = 0;
        while(tax < m_50percent && M1 != 0){

            if(HP1 >= 200){// event 1
                HP1 = HP1 + 0.1*HP1 + 0.9999;
                if(HP1 > 666) HP1 = 666;

                M1 -= 70; tax += 70;
                if(M1 < 0) M1 = 0;
            }
            else{
                HP1 = HP1 + 0.3*HP1 + 0.9999;
                if(HP1 > 666) HP1 = 666;

                M1 -= 150; tax += 150;
                if(M1 < 0) M1 = 0;
            }

            if(M1 == 0 || tax > m_50percent) break;

            if(EXP1 < 400){
                M1 -= 200; tax += 200;
                if(M1 < 0) M1 = 0;
            }
            else{
                M1 -= 120; tax += 120;
                if(M1 < 0) M1 = 0;
            }

            EXP1 = EXP1 + 0.13*EXP1 + 0.9999;

            if(M1 == 0 || tax > m_50percent) break;

            if(M1 != 0){
                    if(EXP1 < 300){
                        M1 -= 100; tax += 100;
                        if(M1 < 0) M1 = 0;
                    }
                    else{
                        M1 -= 120; tax += 120;
                        if(M1 < 0) M1 = 0;
                    }
                    float subs = int(0.1*EXP1);
                    EXP1 -= subs; 
                    if(EXP1 < 0) EXP1 = 0;
            }
        }
    }
    int sub = int(0.17*HP1);
    HP1 -= sub;
    if(HP1 < 0) HP1 = 0;
    EXP1 = EXP1 + 0.17*EXP1 + 0.9999;
    if(EXP1 > 600) EXP1 = 600;

    float probality_2 = 1.0;
    int S_2 = find_neareat_Square(EXP1);
    if(S_2 > EXP1) probality_2 = (EXP1/(S*1.0) + 80)/123.0;

    int arr[10] = {32,47,28,79,100,50,22,83,64,11};
    int index = 0;
    if(int(E2/10) == 0) index = E2;
    else{
        index = (int(E2/10) + E2%10)%10;
    }
    int probality_3 = arr[index];

    if((probality_1 == 1) && (probality_2 == 1) && (probality_3 == 100)){
        int subb = 0.25*EXP1;
        EXP1 -= subb;
        if(EXP1 < 0) EXP1 = 0;
    }
    else{
        float pro_aver = (probality_1 + probality_2 + float(probality_3/100.0))/3;
        if(pro_aver < 0.5){
            int subb = 0.15*HP1;
            HP1 -= subb;
            if(HP1 < 0) HP1 = 0;
            EXP1 = EXP1 + 0.15*EXP1 + 0.9999;
            if(EXP1 > 600) EXP1 = 600;
        }
        else{
            int subb = 0.1*HP1;
            HP1 -= subb;
            if(HP1 < 0) HP1 = 0;
            EXP1 = EXP1 + 0.2*EXP1 + 0.9999;
            if(EXP1 > 600) EXP1 = 600;
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int findMax_in_X_line(int** arr,int i, int j){
    int max = INT_MIN;

    for(int x = i,y = j;(x >= 0)&&(y >= 0)&&(x < 10)&&(y < 10);--x,++y ){
        if(arr[x][y] > max) max = arr[x][y];
    }

    for(int x = i,y = j;(x >= 0)&&(y >= 0)&&(x < 10)&&(y < 10);++x,--y ){
        if(arr[x][y] > max) max = arr[x][y];
    }

    for(int x = i,y = j;(x >= 0)&&(y >= 0)&&(x < 10)&&(y < 10);--x,--y ){
        if(arr[x][y] > max) max = arr[x][y];
    }

    for(int x = i,y = j;(x >= 0)&&(y >= 0)&&(x < 10)&&(y < 10);++x,++y ){
        if(arr[x][y] > max) max = arr[x][y];
    }

    return max >= 0 ? max : (-1)*max;
}
int higher_than_2E2(int** arr,int E3){
    int num = 0;
    for(int row = 0; row < 10;++row){
        for(int col = 0; col < 10; ++col){
            if(arr[row][col] > 2*E3) ++num;
        }
    }
    return num;
}
int lower_than__E1(int** arr,int E3){
    int num = 0;
    for(int row = 0; row < 10;++row){
        for(int col = 0; col < 10; ++col){
            if(arr[row][col] < (-1)*E3) ++num;
        }
    }
    return num;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;

    if(EXP1 > 600) EXP1 = 600; if(EXP1 < 0) EXP1 = 0;
    if(HP1 > 666) HP1 = 666; if(HP1 < 0) HP1 = 0;

    if(EXP2 > 600) EXP2 = 600; if(EXP2 < 0) EXP2 = 0;
    if(HP2 > 666) HP2 = 666; if(HP2 < 0) HP2 = 0;


    int** matrix = new int*[10];
    for(int i = 0; i < 10;++i) matrix[i] = new int[10];

    for(int row = 0; row < 10;++row){
        for(int col = 0; col < 10; ++col){
            matrix[row][col] = ((E3*col) + (row*2))*(row - col);
        }
    }
    int i = higher_than_2E2(matrix,E3);
    int j = lower_than__E1(matrix,E3);
    while((i/10) != 0){
        i = i/10 + i%10;
    }
    while((j/10) != 0){
        j = j/10 + j%10;
    }
    int main_point = findMax_in_X_line(matrix,i,j);
    int car_point = matrix[i][j];
    if(abs(car_point) > main_point){
        EXP1 = EXP1 - int(0.12*EXP1);
        HP1 = HP1 - int(0.1*HP1);
        EXP2 = EXP2 - int(0.12*EXP2);
        HP2 = HP2 - int(0.1*HP2);

        if(EXP1 > 600) EXP1 = 600; if(EXP1 < 0) EXP1 = 0;
        if(HP1 > 666) HP1 = 666; if(HP1 < 0) HP1 = 0;

        if(EXP2 > 600) EXP2 = 600; if(EXP2 < 0) EXP2 = 0;
        if(HP2 > 666) HP2 = 666; if(HP2 < 0) HP2 = 0;
        return car_point;
    }
    else{
        EXP1 = EXP1 + (0.12*EXP1) + 0.9999;
        HP1 = HP1 + (0.1*HP1) + 0.9999;
        EXP2 = EXP2 + (0.12*EXP2) + 0.9999;
        HP2 = HP2 + (0.1*HP2) + 0.9999;

        if(EXP1 > 600) EXP1 = 600; if(EXP1 < 0) EXP1 = 0;
        if(HP1 > 666) HP1 = 666; if(HP1 < 0) HP1 = 0;

        if(EXP2 > 600) EXP2 = 600; if(EXP2 < 0) EXP2 = 0;
        if(HP2 > 666) HP2 = 666; if(HP2 < 0) HP2 = 0;
        return main_point;
    }

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S = s;
    string Email = email;
    int index_of_se = 0;
    for(int i = 0; i < Email.length();++i){
        if(Email[i] == '@'){
            index_of_se = i;
            break;
        }
    }
    string se = Email.substr(0,index_of_se);
    bool check_special_char = false;
    int invalid_char = -1;
    bool has_invalid = false;
    if(S.length() < 8) return -1;
    if(S.length() > 20) return -2;
    if(S.find(se) != string::npos) return (-1)*(300 + S.find(se));
    for(int i = 0;i < S.length();++i){
        if(((i+2) < S.length()) && ((i+1) < S.length()) && (S[i] == S[i+1]) && (S[i] == S[i+2])){
            return (-1)*(400 + i);
        }
        if((S[i] == '@')||(S[i] == '#')||(S[i] == '%')||(S[i] == '!')||(S[i] == '$')) check_special_char = true;

        if((S[i] != '@')&&(S[i] != '#')&&(S[i] != '!')&&(S[i] != '%')&&(S[i] != '$')&& !((S[i] <= '9')&&(S[i] >= '0')) && !((S[i] <= 'z')&&(S[i] >= 'a'))&& !((S[i] <= 'Z')&&(S[i] >= 'A'))  && has_invalid == false) {
            invalid_char = i;
            has_invalid = true;
        }
    }
    if(check_special_char == false) return -5;
    if(invalid_char != -1) return invalid_char;
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_times = 0, max_length = 0, first_index = 0;
    for(int i = 0; i < num_pwds;++i){
        const char* tmp = arr_pwds[i];
        int times = 1;
        for(int j = i+1; j < num_pwds;++j){
            if(arr_pwds[j] == tmp) ++times;
        }

        if(times > max_times){
            max_times = times; max_length = strlen(tmp); first_index = i;
        }
        else if(times == max_times){
            if(strlen(tmp) > max_length){
                max_times = times; max_length = strlen(tmp); first_index = i;
            }
        }
    }
    return first_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////