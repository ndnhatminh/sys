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



void update_Stats_Task1(int &EXP1, int &EXP2){
    EXP1 = min(max(EXP1, 0), 600);
    EXP2 = min(max(EXP2, 0), 600);
}
void update_Stats_Task2(int &HP1, int &EXP1, int &M1){
    HP1 = min(max(HP1, 0), 666);
    EXP1 = min(max(EXP1, 0), 600);
    M1 = min(max(M1, 0), 3000);
}

void update_Stats_Task3(int &HP1, int &HP2, int &EXP1, int &EXP2){
    HP1 = min(max(HP1, 0), 666);
    HP2 = min(max(HP2, 0), 666);
    EXP1 = min(max(EXP1, 0), 600);
    EXP2 = min(max(EXP2, 0), 600);
}

int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1 < 0 || E1 > 99){
        return -99;
    }
    update_Stats_Task1(EXP1, EXP2);
    if(E1 >= 0 && E1 <= 3){ //Condition if the Even 1 (E1) in range [0;3]
        int D = E1*3 + EXP1*7;
    if(D%2==0){
        EXP1 = EXP1 + D/200;
    }
    else {
        EXP1 = EXP1 - D/100;
    }
        switch(E1){
            case 0: //Watson’s hairstyle and manner of speech are like those of the military
                EXP2 = EXP2 + 29;
                break;
            case 1: //His face is tanned but not tanned under the wrist, proving that Watson has returned from abroad
                EXP2 = EXP2 + 45;
                break;
            case 2: //Watson limped, but when they met, he chose to stand without asking for a chair, so he had psychological problems after being injured. This could be an injury caused by action on the battlefield
                EXP2 = EXP2 + 75; 
                break;
            case 3: //Sherlock explained all the 3 information
                EXP2 = EXP2 + 29 + 45 + 75;
                break;
            default:
                break;
        }
    }
    else if(E1 >=4 && E1 <=19){ //Case 4, 5, ..., 18, 19
        EXP2 += (ceil(static_cast<float>(E1)/4) + 19); // Watson has an expensive phone but he is looking for a roommate to share the rent, the phone must have been given to Watson by someone else
        EXP1 = EXP1 - E1;
    }
    else if(E1 >=20 && E1 <=49){ //Case 20, 21, ..., 48, 49
        EXP2 += (ceil(static_cast<float>(E1)/9) + 21); // The phone has many scratches indicating that it has been placed with many other items such as keys, coins. Watson wouldn’t do that to a luxury item. This is caused by the previous owner with the phone
        EXP1 = EXP1 - E1;
    }
    else if(E1 >=50 && E1 <=65){ //Case 49, 50, ..., 64, 65
        EXP2 += (ceil(static_cast<float>(E1)/16) + 17); // On the phone is engraved the name: Harry Watson, showing that this was given to him by an old family member
        EXP1 = EXP1 - E1;
    }
    else if(E1 >=66 && E1 <=79){ //Case 66, 67, ..., 78, 79
        EXP2 += (ceil(static_cast<float>(E1)/4) + 19); // Sherlock explains information 1; after Watson finished listening and EXP2 was updated, if EXP2 > 200, Sherlock continued to interpret the information 2 and Watson was updated with EXP2 respectively.
        if(EXP2 > 200){ // If EXP2 > 200, Sherlock continued to interpret the information 2 and Watson was updated with EXP2 respectively.
            EXP2 += (ceil(static_cast<float>(E1)/9) + 21);
        }
        EXP1 = EXP1 - E1;
    }
    else if(E1 >=80 && E1 <=99){ //Case 80, 81, ..., 98, 99
        EXP2 += (ceil(static_cast<float>(E1)/4) + 19); // Sherlock explains information 1; after Watson finished listening and EXP2 was updated, if EXP2 > 200, Sherlock continued to interpret the information 2 and Watson was updated with EXP2 respectively.
        EXP2 += (ceil(static_cast<float>(E1)/9) + 21);
        if(EXP2 > 400){ //if EXP2 > 400, Sherlock continued to interpret the information 3 and Watson was updated with EXP2 respectively
            EXP2 += (ceil(static_cast<float>(E1)/16) + 10);
            EXP2 = ceil(EXP2*1.15);
        }
        EXP1 = EXP1 - E1;
    }
    update_Stats_Task1(EXP1, EXP2);
    return EXP1 + EXP2;
}

// Task 2




int PerfectSquare(int &EXP1){
    int S = static_cast<int>(sqrt(EXP1));
    int lower = S*S;
    int upper = (S+1)*(S+1);
    if(abs(EXP1-lower) <= abs(EXP1-upper)){
        S = lower;
    }
    else{
        S = upper;
    }
    return S;
}

bool Evencheck(float & CurrentM, int E){
    if (E%2 == 1) {return true;}
    if (CurrentM < 0) {
        return false;
    }
    return true;
}

bool Oddcheck(float & CurrentM, int E, float EstimatedM){
    if (E%2 == 0) {return true;}
    if (CurrentM < EstimatedM) {
        return false;
    }
    return true;
}

void RoudOn(float & EXP1, float & HP1, float &M1){
    HP1 = ceil(HP1);
    EXP1 = ceil(EXP1);
    M1 = ceil(M1);
}

void Road2(float & EXP1, float & HP1, float & M1, int E, float EstimatedM){
    if (HP1 < 200) {
        HP1 *= 1.3;
        M1 -= 150;
    } else {
        HP1 *= 1.1;
        M1 -= 70;
    }
    RoudOn(EXP1, HP1, M1);
    if(Evencheck(M1, E) == false){
        return;
    }
    if (Oddcheck(M1, E, EstimatedM) ==false){
        return;
    }
    if (EXP1 < 400) {
        M1 -= 200;
    } else {
        M1 -= 120;
    }
    EXP1 *= 1.13;
    RoudOn(EXP1, HP1, M1);
    if(Evencheck(M1, E) == false){
        return;
    }
    if (Oddcheck(M1, E, EstimatedM) ==false){
        return;
    }
     if (EXP1 < 300) {
        M1 -= 100;
    } else {
        M1 -= 120;
    }
    EXP1 *= 0.9;
    RoudOn(EXP1, HP1, M1);
    if(Evencheck(M1, E) == false){
        return;
    }
    RoudOn(EXP1, HP1, M1);
    if (Oddcheck(M1, E, EstimatedM) ==false){
        return;
    }
    else{
        if(E%2 == 1){
            return Road2(EXP1, HP1, M1, E, EstimatedM);
        }
    }
    
}


int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    float SEXP1 = PerfectSquare(EXP1);
    float EXP1_Road2 = static_cast<float>(EXP1);
    float HP1_Road2 = static_cast<float>(HP1);
    float M1_Road2 = static_cast<float>(M1);

    //Road 1 begin
    float P1 = ((EXP1_Road2/SEXP1) + 80 )/ 123;
    if(EXP1_Road2 >= SEXP1){
        P1 = 1;
    }

    //Road 2 begin

    Road2(EXP1_Road2, HP1_Road2, M1_Road2, E2, M1_Road2/2);
    HP1_Road2 *= (1-0.17);
    EXP1_Road2 *= (1+0.17);
    RoudOn(EXP1_Road2, HP1_Road2, M1_Road2);
    float P2 = ((EXP1_Road2/SEXP1)+80)/123;
    if(EXP1_Road2 >= SEXP1){
        P2 = 1;
    }

    //Road_3

    float P[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int P3X = 0;
    if(E2< 10){
        P3X = E2;
    }
    else if(E2 >= 10 && E2 <=99){
        int sum = (E2/10) + (E2%10);
        P3X = sum%10;
    }
    float P3 = P[P3X];

    if(P1 == 1 && P2 == 1 && P3 == 1){
        EXP1_Road2 *= 0.75;
    }
    else{
        float P_Avg = (P1 + P2 + P3)/3;
        if(P_Avg < 0.5){
            HP1_Road2 *= 0.85;
            EXP1_Road2 *= 1.2;
        }
        else{
            HP1_Road2 *=0.9;
            EXP1_Road2 *=1.2;
        }
    }
    EXP1 = static_cast<int>(ceil(EXP1_Road2));
    HP1 = static_cast<int>(ceil(HP1_Road2));
    M1 = static_cast<int>(ceil(M1_Road2));
    update_Stats_Task2(HP1, EXP1, M1);


        return HP1 + EXP1 + M1;
 
}   



// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    update_Stats_Task3(HP1, HP2, EXP1, EXP2);
    if(E3 < 0 || E3 > 99){
        return -1;
    }   
    else{
        int countpos = 0;
        int countneg = 0;
        const int rows = 10;
        const int cols = 10;
        int taximap[rows][cols]={0};
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                taximap[i][j] = ((E3*j)+(i*2))*(i-j);
                if(taximap[i][j] > 2*E3){
                    countpos +=1;
                }
                if(taximap[i][j] < -E3){
                    countneg +=1;
                }
            }
        }
        int a = countpos;
        do{
            if(a < 10){
                break;
            }
            int tempone = a % 10;
            int tempten = a / 10;
            a = tempone + tempten;
        }
        while(a >= 10);
        
        int b = countneg;
        do{
            if(b < 10){
                break;
            }
            int tempone = b % 10;
            int tempten = b / 10;
            b = tempone + tempten;
        }
        while(b >= 10);
    
    
        int detectivemap[rows][cols] = {0};
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                int lt[10] = {0}, rt[10] = {0};
                int k = 0;
                int r = i, c = j;
                while(r < 10 && c < 10){
                    lt[k] = taximap[r][c];
                    ++r;
                    ++c;
                    ++k;
                }
                k = 0;
                r = i, c = j;
                while(r >= 0 && c < 10){
                    rt[k] = taximap[r][c];
                    --r;
                    ++c;
                    ++k;
                }
                int max_lt = lt[0], max_rt = rt[0];
                for(k = 0; k < 10; ++k){
                    if(lt[k] > max_lt){
                        max_lt = lt[k];
                    }
                }
                for(k = 0; k < 10; ++k){
                    if(rt[k] > max_rt){
                        max_rt = rt[k];
                    }
                }
            
                detectivemap[i][j]=abs(max(max_lt, max_rt));
            }
        }
    
        if(abs(taximap[a][b]) > detectivemap[a][b]){
            EXP1 -= static_cast<int>(EXP1 * 0.12);
            HP1 -= static_cast<int>(HP1 * 0.10);
            EXP2 -= static_cast<int>(EXP2 * 0.12);
            HP2 -= static_cast<int>(HP2 * 0.10);
            return taximap[a][b];
        }
        else{
            EXP1 += static_cast<int>(EXP1 * 0.12);
            HP1 += static_cast<int>(HP1 * 0.10);
            EXP2 += static_cast<int>(EXP2 * 0.12);
            HP2 += static_cast<int>(HP2 * 0.10);
            return detectivemap[a][b];
        }
    }
}
    

    


    

// Task 4
int checkPassword(const char *s, const char *email) {
    string str_s(s);
    string str_email(email);
    string se = str_email.substr(0, str_email.find('@'));

    if (str_s.length() < 8) {
        return -1;
    }

    if (str_s.length() > 20) {
        return -2;
    }

    const string allowed_chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%";
    for (size_t i = 0; i < str_s.length(); ++i) {
        if (allowed_chars.find(str_s[i]) == string::npos) {
            return static_cast<int>(i);
        }
    }

    if (str_s.find(se) != string::npos) {
        return -300 - static_cast<int>(str_s.find(se));
    }

    for (size_t i = 0; i < str_s.length() - 2; ++i) {
        if (str_s[i] == str_s[i + 1] && str_s[i] == str_s[i + 2]) {
            return -400 - static_cast<int>(i);
        }
    }

    bool has_special_char = false;
    for (char c : str_s) {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            has_special_char = true;
            break;
        }
    }

    if (!has_special_char) {
        return -5;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int MAX_NUM_PWDS = 30;
    char pwds[MAX_NUM_PWDS][101];
    int counts[MAX_NUM_PWDS] = {0};

    // Copy passwords into array
    for (int i = 0; i < num_pwds; ++i) {
        strcpy(pwds[i], arr_pwds[i]);
    }

    // Count the occurrence of each password
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = i+1; j < num_pwds; ++j) {
            if (strcmp(pwds[i], pwds[j]) == 0) {
                counts[i]++;
            }
        }
    }

    // Find the correct password
    int idx = -1;
    int max_count = -1;
    int max_length = -1;
    for (int i = 0; i < num_pwds; ++i) {
        int length = strlen(pwds[i]);
        if (counts[i] > max_count || (counts[i] == max_count && length > max_length)) {
            idx = i;
            max_count = counts[i];
            max_length = length;
        }
    }

    return idx;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////