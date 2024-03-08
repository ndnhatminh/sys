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
//Gioi han cac gia tri trong task 2
void limTask2(int & HP1, int & EXP1, int & M1){
    HP1 = min(max(0, HP1), 666);
    EXP1 = min(max(0, EXP1), 600);
    M1 = min(max(0, M1), 3000);
}

//Tim so chinh phuong gan EXP1
float squareNumNearEXP1(int & EXP1){
    float P1 = 0.0;
    int S_small = floor(sqrt(EXP1));
    float i = sqrt(EXP1);
    float S_larger = pow(ceil(i), 2);
    return abs(EXP1 - S_small * S_small) <= abs(EXP1 - S_larger) ? P1 = 1 : P1 = (EXP1 / S_larger + 80) / 123;
}
//Tinh thu tu phan tu trong mang
int index(int & E2){
    int i;  
    if(E2 >= 0 && E2 < 10){
        i = E2;
    }
    else {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    }
    return i;
}
// GIoi han cac gia tri o task 3
void limTask3(int & HP1, int & EXP1, int & HP2, int & EXP2) {
    HP1 = min(max(0, HP1), 666);
    EXP1 = min(max(0, EXP1), 600);
    HP2 = min(max(0, HP2), 666);
    EXP2 = min(max(0, EXP2), 600);
}
//Dem so luong ki tu trong chuoi mk
int countChar(const char *string){
    int count = 0;
    while(*string != '\0'){
        count++;
        string++;
    }
    return count;
}
//Kiem tra chuoi mk co ki tu dac biet hay khong
bool has_special_char(const char *s){
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return true;
        }
    }
    return false;
}
//Kiem tra 2 ki tu lien tiep trong chuoi mk
int twoChar(const char*s){
    int nums = -1;
    int num = countChar(s);
    int count_tc = 0;
    for (int i = 0; i <= num -1; i++) {
        if (s[i] == s[i + 1]) {
            count_tc++;
            if(count_tc == 2){
                nums = i - 1;
                break;
            }
        }
        else count_tc = 0;
    }
    return nums;
}
//Kiem tra cac truong hop khac
int checkChar(const char *s){
    for(int i = 0; s[i] != '\0'; i++){
        if(!((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9') ||
            (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
                return i;
            }

    }
    return -1;
}
    

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    //Situation_1
    if(E1 < 0 || E1 > 99){
        return -99;
    }
    if(E1 >= 0 && E1 <= 3){
        switch(E1){
            case 0:
                EXP2 = EXP2 + 29;
                break;
            case 1:
                EXP2 = EXP2 + 45;
                break;
            case 2:
                EXP2 = EXP2 + 75;
                break;
            case 3:
                EXP2 = EXP2 + 149;
                break;
        }
    //Sherlock' s decision
    int D;
        D = E1*3 + EXP1*7;
        if(D % 2 == 0){
            EXP1 = ceil(EXP1 + ((D*1.0)/200));
        }
        else{EXP1 = ceil(EXP1 - ((D*1.0)/100));}
        if(EXP1 > 600){
            EXP1 = 600;
        }
    }

    //Situation_2
    else if(E1 >= 4 && E1 <= 19){
        EXP2 = ceil(EXP2 +((E1*1.0)/4 + 19));
        if(EXP2 > 600){
            EXP2 = 600;
        }
        EXP1 = EXP1 - E1;
        if(EXP1 < 0){
            EXP1 = 0;
        }
        if(EXP1 > 600){
            EXP1 = 600;
        }
    }
    else if(E1 >= 20 && E1 <= 49){
        EXP2 = ceil(EXP2 +((E1*1.0)/9 + 21));
        if(EXP2 > 600){
            EXP2 = 600;
        }
        EXP1 = EXP1 - E1;
        if(EXP1 < 0){
            EXP1 = 0;
        }
        if(EXP1 > 600){
            EXP1 = 600;
        }
    }
    else if(E1 >= 50 && E1 <= 65){
        EXP2 = ceil(EXP2 +((E1*1.0)/16 + 17));
        if(EXP2 > 600){
            EXP2 = 600;
        }
        EXP1 = EXP1 - E1;
        if(EXP1 < 0){
            EXP1 = 0;
        }
        if(EXP1 > 600){
            EXP1 = 600;
        }
    }
    else if(E1 >= 66 && E1 <= 79){
        if(ceil(EXP2 +((E1*1.0)/4 + 19)) > 200){
            EXP2 = ceil(EXP2 +((E1*1.0)/4 + 19));
            EXP2 = EXP2 + ceil(((E1*1.0)/9 + 21));
            if(EXP2 > 600){
                EXP2 = 600;
            }
        }
        if(ceil(EXP2 +((E1*1.0)/4 + 19)) <= 200){
            EXP2 = ceil(EXP2 +((E1*1.0)/4 + 19));
        }
        EXP1 = EXP1 - E1;
        if(EXP1 < 0){
            EXP1 = 0;
        }
        if(EXP1 > 600){
            EXP1 = 600;
        }
    }
    else if(E1 >= 80 && E1 <= 99){
        if(ceil(EXP2 + ((E1*1.0)/4 + 19)) + ceil(((E1*1.0)/9 + 21)) > 400){
            EXP2 = ceil(ceil(EXP2 +((E1*1.0)/4 + 19)) + ceil(((E1*1.0)/9 + 21)) + ceil(((E1*1.0)/16 + 17)));
            EXP2 = ceil(EXP2 * 115 / 100);
            if(EXP2 > 600){
                EXP2 = 600;
            }
        }
        if(ceil(EXP2 + ((E1*1.0)/4 + 19)) + ceil(((E1*1.0)/9 + 21)) <= 400){
            EXP2 = ceil(EXP2 + ((E1*1.0)/4 + 19)) + ceil(((E1*1.0)/9 + 21));
        }
        EXP1 = EXP1 - E1;
        if(EXP1 < 0){
            EXP1 = 0;
        }
        if(EXP1 > 600){
            EXP1 = 600;
        }
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //FIRST WAY
    float S1 = squareNumNearEXP1(EXP1);

    //SECOND WAY
    if(E2 < 0 || E2 > 99){
        return -99;
    }
    if(E2 % 2 != 0){ //E2 is Odd
        float half_M1 = M1 / 2;
        int tempM1 = ceil(half_M1);
        while(true){
            if(HP1 < 200){
                float newHP1 = HP1 * 1.3;
                HP1 = ceil(newHP1);
                M1 = M1 - 150;
                limTask2(HP1, EXP1, M1);

            }
            else {
                float newHP1 = HP1 * 1.1;
                HP1 = ceil(newHP1);
                M1 = M1 - 70;
                limTask2(HP1, EXP1, M1);
            }
            if(M1 < tempM1){
                break;
            }
            if(EXP1 < 400){
                M1 = M1 - 200;
            }
            else{
                M1 = M1 - 120;
            }
            float newEXP1 = EXP1 * 1.13;
            EXP1 = ceil(newEXP1);
            limTask2(HP1, EXP1, M1);
            if(M1 < tempM1){
                break;
            }
            if(EXP1 < 300){
                M1 = M1 - 100;
            }
            else {
                M1 = M1 - 120;
            }
            float new_EXP1 = EXP1 * 0.9;
            EXP1 = ceil(new_EXP1);
            limTask2(HP1, EXP1, M1);
            if( M1 < tempM1){
                break;
            }
        }
        float newHP = HP1 * 0.83;
        HP1 = ceil(newHP);
        float newExp = EXP1 * 1.17;
        EXP1 = ceil(newExp);
        limTask2(HP1, EXP1, M1);
    }

    else { // E2 is Even
            if(HP1 < 200){
                float newHP1 = HP1 * 1.3;
                HP1 = ceil(newHP1);
                M1 = M1 - 150;
            }
            else{
                float newHP1 = HP1 * 1.1;
                HP1 = ceil(newHP1);
                M1 = M1 - 70;
            }
            limTask2(HP1, EXP1, M1);
            if(M1 > 0){
                if(EXP1 < 400){
                    M1 = M1 - 200;   
                }
                else {
                    M1 = M1 - 120;
                }
                float newEXP1 = EXP1 * 1.13;
                EXP1 = ceil(newEXP1);
                limTask2(HP1, EXP1, M1);
            }
            if(M1 > 0){
                if(EXP1 < 300){
                    M1 = M1 - 100;
                }
                else {
                    M1 = M1 - 120;
                }
                float new_EXP1 = EXP1 * 0.9;
                EXP1 = ceil(new_EXP1);
                limTask2(HP1, EXP1, M1);
            }
        float newHP = HP1 * 0.83;
        HP1 = ceil(newHP);
        float newExp = EXP1 * 1.17;
        EXP1 = ceil(newExp);
        limTask2(HP1, EXP1, M1);
    }
    float S2 = squareNumNearEXP1(EXP1);

    //THIRD WAY
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = index(E2);
    float S3 = P[i] / 100.0;
    if(S1 == 1 && S2 == 1 && S3 == 1){
        float new_EXP1 = EXP1 * 0.75;
        EXP1 = ceil(new_EXP1);
        limTask2(HP1, EXP1, M1);
    }
    else {
        float X; //Xac suat cuoi cung
        X = (S1 + S2 + S3) / 3.0;
        if(X < 0.5){
            float new_EXP1 = EXP1 * 1.15;
            EXP1 = ceil(new_EXP1);
            float newHP1 = HP1 * 0.85;
            HP1 = ceil(newHP1);
            limTask2(HP1, EXP1, M1);
        }
        else {
            float newHP1 = HP1 * 0.9;
            HP1 = ceil(newHP1);
            float new_EXP1 = EXP1 * 1.2;
            EXP1 = ceil(new_EXP1);
            limTask2(HP1, EXP1, M1);
        }
    }
    limTask2(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99){
        return -99;
    }
    limTask3(HP1, EXP1, HP2, EXP2);
    //khoi tao mang diem cua taxi
    int arr[10][10];
    //diem so cua taxi
    int count = 0;
    int count1 = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = ((E3*j)+(i*2))*(i-j);
            if(arr[i][j] > (E3*2)){
                count++;
            }
            if(arr[i][j] < (0-E3)){
                count1++;
            }
        }
    }
    while(count > 9){
        int donvi = count % 10;
        int chuc = count / 10;
        count = chuc + donvi;
    }
    while(count1 > 9){
        int donvi1 = count1 % 10;
        int chuc1 = count1 / 10;
        count1 = chuc1 + donvi1;
    }

    int arr_1[10][10];
    int max = INT_MIN;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int a = i - j;
            int b = i + j;
            for(int i = 0; i < 10; i++){
                for (int j= 0; j < 10; j++){
                    if (i - j ==a || i + j == b){
                        if(arr[i][j] > max){
                            max = arr[i][j];
                        }
                    }
                }
            }
            if(max < 0){
                max = abs(max);
            }
            arr_1[i][j] = max;
            max = INT_MIN;
        }
    }

    if(abs(arr[count][count1]) <= arr_1[count][count1]){
        float iHP1 = HP1 * 1.1;
        HP1 = ceil(iHP1);
        float iEXP1 = EXP1 * 1.12;
        EXP1 = ceil(iEXP1);

        float iHP2 = HP2 * 1.1;
        HP2 = ceil(iHP2);
        float iEXP2 = EXP2 * 1.12;
        EXP2 = ceil(iEXP2);
        limTask3(HP1, EXP1, HP2, EXP2);
        return arr_1[count][count1];
    }
    else {
        float iHP1 = HP1 * 0.9;
        HP1 = ceil(iHP1);
        float iEXP1 = EXP1 * 0.88;
        EXP1 = ceil(iEXP1);

        float iHP2 = HP2 * 0.9;
        HP2 = ceil(iHP2);
        float iEXP2 = EXP2 * 0.88;
        EXP2 = ceil(iEXP2);
        limTask3(HP1, EXP1, HP2, EXP2);
        return arr[count][count1];
    }
    
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char* p = strchr(email, '@');
    int a = p - email;
    char* se = new char[a + 1];//+1 o nho de cho Null
    strncpy(se, email, a);
    se[a] = '\0'; // danh dau la ket thuc chuoi

    int count_S = countChar(s);
    int se_check;
    const char *sse_check = strstr(s, se);
    if(sse_check == NULL) se_check = -99;
    else se_check = sse_check - s;

    int t_char = twoChar(s);
    bool spc = has_special_char(s);
    int c_check = checkChar(s);

    if(count_S < 8) return -1;
    else if(count_S > 20) return -2;
    else if(se_check != -99) return (-300 - se_check);
    else if(t_char != -1) return (-400 - t_char);
     else if(spc == false) return -5;
    else if(c_check != -1) return(c_check);
    else return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int length = 0;
    int max = 0;
    int Pos;
    int length_max = 1;
    for(int i = 0; i < num_pwds; i++){
        int count = 1;
        const char*a = arr_pwds[i];
        length = countChar(a);
        for(int j = 0; j < num_pwds; j++){
            if(i != j) {
                const char*b = arr_pwds[j];
                if(strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                    count++;
                }
            }
        }
        if(count > max || (count == max && length > length_max)){
            max = count;
            length_max = length;
            Pos = i;
        }
    }
    return Pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
