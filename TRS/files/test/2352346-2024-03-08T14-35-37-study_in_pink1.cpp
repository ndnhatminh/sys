#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
int check(int EXP){
    if(EXP < 0){
        EXP = 0;
    }
    else if(EXP > 600){
        EXP = 600;
    }
    return EXP;
}
int checkHP(int HP){
    if(HP > 666){
        HP = 666;
    }
    else if(HP < 0){
        HP = 0;
    }
    return HP;
}
int checkM(int M){
    if(M > 3000){
        M = 3000;
    }
    else if (M < 0){
        M = 0;
    }
    return M;
}
int firstMeet(int & EXP1, int & EXP2, int E1) 
{

    if (E1 >= 0 && E1<=3){
        switch (E1){
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
            EXP2 = EXP2 + 29 + 45 + 75;
            break;
        }
        int D = E1*3 + EXP1*7;
        if(D % 2==0){
            EXP1 = ceil(EXP1 + D/200.0);

        }
        else {
            EXP1 = ceil(EXP1 - D/100.0);

        }
    }
    else if(E1 >= 4 && E1 <= 99){
        if(E1 <= 19){
            EXP2 = ceil(EXP2 + E1/4.0 + 19);    
        }
        else if(E1 <= 49){
            EXP2 = ceil(EXP2 + E1/9.0 + 21);
        }
        else if(E1 <= 65){
            EXP2 = ceil(EXP2 + E1/16.0 + 17);
        }
        else if(E1 <= 79){
            EXP2 = ceil(EXP2 + E1/4.0 + 19);
            if(EXP2 > 200){
                EXP2 = ceil(EXP2 + E1/9.0 + 21);
            }
        }
        else if(E1 <= 99){
            EXP2 = ceil(EXP2 + E1/4.0 + 19);
            EXP2 = ceil(EXP2 + E1/9.0 + 21);
            if(EXP2 > 400){
                EXP2 = ceil(EXP2 + E1/16.0 +17);
                EXP2 = ceil(EXP2 + 0.15*EXP2);

            }
        }
        EXP1 = ceil(EXP1 - E1);
    }
    else if (E1 < 0 || E1 > 99){ 
        return -99;
    }
    EXP1 = check(EXP1);
    EXP2 = check(EXP2);
    return EXP1 + EXP2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
if (E2 > 99 || E2 < 0)
        return -99;
    //Route 1
    int S1, S2;
    float P1, P2, P3;
    S1 = static_cast<int>(sqrt(static_cast<float>(EXP1)) + 0.5);
    int pSquare = S1*S1;
    if(EXP1 >= pSquare){
        P1 = 1.0;
    }
    else{
        P1 = (EXP1*1.0/pSquare + 80)/123.0; 
    }
    //////////////////////////////////////////
    //Route 2
    int paid1 = 0 , paid2 = 0, paid3 = 0;
    int paid = 0;
    float half = M1/2.0;

    if(E2 % 2 != 0){
        while (paid < half){
        //Event 1
            if(HP1 < 200){
                M1 = M1 - 150;
                M1 = checkM(M1);
                paid1 = 150;
                paid += paid1;
                HP1 = ceil(HP1*130.0/100);
                HP1 = checkHP(HP1);
                if(paid > half){
                    break;
                }
        }
            else{
                
                M1 = M1 - 70;
                M1 = checkM(M1);
                paid1 = 70;
                paid += paid1;
                HP1 = ceil(HP1*110.0/100);
                HP1 = checkHP(HP1);
                if(paid > half){
                    break;
                }
                
        }
        //Event 2
            if(EXP1 < 400){
                M1 = M1 - 200;
                M1 = checkM(M1);
                paid2 = 200;
                paid += paid2;
                EXP1 = ceil(EXP1*113.0/100);
                EXP1 = check(EXP1);
                if(paid > half){
                    break;
                }
        }
            else{
                M1 = M1 - 120;
                M1 = checkM(M1);
                paid2 = 120;
                paid += paid2;
                EXP1 = ceil(EXP1*113.0/100);
                EXP1 = check(EXP1);
                if(paid > half){
                    break;
                }
        }
        //Event 3
            if(EXP1 < 300){
                M1 = M1 - 100;
                M1 = checkM(M1);
                paid3 = 100;
                paid += paid3;
                EXP1 = ceil(EXP1*90.0/100);
                EXP1 = check(EXP1);
                if(paid > half){
                    break;
                }
        }
            else{
                M1 = M1 - 120;
                M1 = checkM(M1);
                paid3 = 120;
                paid += paid3;
                EXP1 = ceil(EXP1*90.0/100);
                EXP1 = check(EXP1);
                if(paid > half){
                    break;
                }
        }
            
        }
        
        HP1 = ceil(HP1*83.0/100);
        EXP1 = ceil(EXP1*117.0/100);
        HP1 = checkHP(HP1);
        EXP1 = check(EXP1);
    }
    else{
        //Event 1
        if(M1 == 0){
            goto update;
        }
        if(HP1 < 200){
                M1 = M1 - 150;
                M1 = checkM(M1);
                HP1 = ceil(HP1*130.0/100);
                HP1 = checkHP(HP1);
                if(M1 == 0){
                    goto update;
                }
                
        }
            else{
                M1 = ceil(M1 - 70);
                M1 = checkM(M1);
                HP1 = ceil(HP1*110.0/100);
                HP1 = checkHP(HP1);
                if(M1 == 0){
                    goto update;
                }
                
        }
        //Event 2
            if(EXP1 < 400){
                M1 = M1 - 200;
                M1 = checkM(M1);
                EXP1 = ceil(EXP1*113.0/100);
                if(M1 == 0){
                    goto update;
                }
                
        }
            else{
                M1 = M1 - 120;
                M1 = checkM(M1);
                EXP1 = ceil(EXP1*113.0/100);
                if(M1 == 0){
                    goto update;
                }
                
        } 
        //Event 3
            if(EXP1 < 300){
                M1 = M1 - 100;
                M1 = checkM(M1);
                EXP1 = ceil(EXP1*90.0/100);
                if(M1 == 0){
                    goto update;
                }
                
        }
            else{
                M1 = M1 - 120;
                M1 = checkM(M1);
                EXP1 = ceil(EXP1*90.0/100);
                if(M1 == 0){
                    goto update;
                }
                
        }
            
        //Walk to the end
        update:
            HP1 = ceil(HP1*83.0/100);
            EXP1 = ceil(EXP1*117.0/100);
    }
    S2 = static_cast<int>(sqrt(static_cast<float>(EXP1)) + 0.5);
    int pSquare2 = S2*S2;
    if(EXP1 >= pSquare2){
        P2 = 1.0;
    }
    else{
        P2 = (EXP1*1.0/pSquare2 + 80)/123; 
    }
    //////////////////////////////////////////////////////////////
    //Route 3
    float P[] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11};
    int i;
    if(E2 >= 0 && E2 < 10){
        i = E2;
    }
    else{
        int sum = 0, remain, unit,temp = E2;
        remain = temp % 10;
        sum = sum + remain;
        temp = temp/10;
        remain = temp % 10;
        sum = sum + remain;
        unit = sum % 10;
        i = unit;
        
    }
    P3 = P[i];

    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0){
        EXP1 = ceil(EXP1*75.0/100);
        EXP1 = check(EXP1);
    }
    else{
        float Pave = (P1 + P2 + P3)/3.0;
        
        if(Pave < 0.5){
            HP1 = ceil(HP1*85.0/100);
            EXP1 = ceil(EXP1*115.0/100);
            HP1 = checkHP(HP1);
            EXP1 = check(EXP1);
        }
        else{
            HP1 = ceil(HP1*90.0/100);
            EXP1 = ceil(EXP1*120.0/100);
            HP1 = checkHP(HP1);
            EXP1 = check(EXP1);
        }
    }
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
if(E3 < 0 || E3 >= 100){
    return -99;
}
int map[10][10];
int rows = 0;
int cols = 0;
int taxi_point;
int chase;
int tenth, unit;
    
for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
        map[i][j] = ((E3*j)+(i*2))*(i-j);
        if(map[i][j] > E3*2){
            rows++;
        } 
        if(map[i][j] < -(E3)){
            cols++;
        }
            
    }
        
}
if(rows >= 10){
    tenth = rows/10;
    unit = rows%10;
    rows = tenth + unit;
    if(rows >= 10){
        tenth = rows/10;
        unit = rows%10;
        rows = tenth + unit;
    }
       
    if(cols >= 10){
        tenth = cols/10;
        unit = cols%10;
        cols = tenth + unit;
        if(rows >= 10){
            tenth = rows/10;
            unit = rows%10;
            rows = tenth + unit;
            }
        
        }
    }
    taxi_point = map[rows][cols];
    
    int changed = 0;
    chase = taxi_point;

    while((rows - changed >= 0 && rows + changed < 10) || (cols - changed >= 0 && cols + changed < 10)){
        if(rows - changed >= 0){
            if(cols - changed >= 0){
                if(chase < map[rows - changed][cols - changed]){
                    chase = map[rows - changed][cols - changed];
                }
            }
            if(cols + changed < 10){
                if((chase) < map[rows - changed][cols + changed]){
                    chase = map[rows - changed][cols + changed];
                }
            }
        }
        if(rows + changed < 10){
            if(cols - changed >= 0){
                if(chase < map[rows + changed][cols - changed]){
                    chase = map[rows + changed][cols - changed];
                }
            }
            if(cols + changed < 10){
                if(chase < map[rows + changed][cols + changed]){
                    chase = map[rows + changed][cols + changed];
                }
            }
        }
        changed++;
    }
    if(chase >= abs(taxi_point)){
        EXP1 = ceil(EXP1*112.0/100);
        EXP1 = check(EXP1);

        EXP2 = ceil(EXP2*112.0/100);
        EXP2 = check(EXP2);

        HP1 = ceil(HP1*110.0/100);
        HP1 = checkHP(HP1);

        HP2 = ceil(HP2*110.0/100);
        HP2 = checkHP(HP2);

        return chase;
    } 
    else{
        EXP1 = ceil(EXP1*88.0/100);
        EXP1 = check(EXP1);

        EXP2 = ceil(EXP2*88.0/100);
        EXP2 = check(EXP2);

        HP1 = ceil(HP1*90.0/100);
        HP1 = checkHP(HP1);

        HP2 = ceil(HP2*90.0/100);
        HP2 = checkHP(HP2);

        return taxi_point;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) 
{
    // find se in email
    int i = 0;
    string email1 = email; //char to string
    string s1 = s;
    for(i = 0;i < email1.length(); ++i){
        if(email1[i] == '@'){
            break;
        }
    }
    string se = email1.substr(0, i);
    
    //check  <8 >20
    if(s1.length() < 8){
        return -1;
    }
    else if(s1.length() > 20){
        return -2;
    }
    //first occurence of se
    i = s1.find(se);

    if(i != string::npos){
        return -(300 + i);
    }
    else{

    }
    //3 consecutive chararcters
    for(i = 0; i < s1.length()-2; i++){
        if(s1[i] == s1[i+1] && s1[i] == s1[i+2]){
            return -(400 + i);
        }
    }
    //special char
    int special = 0;
    for(int i = 0; i < s1.length(); i++){
        char c = s1[i];
        if(c == '@' || c == '#' || c == '%' || c == '$' || c == '!'){
            special = 1;
            break;
        }
    }
    if(special == 0){
        return -5;
    }
    for(int i = 0; i < s1.length(); i++){ 
        char a = s1[i];
        //fucntion to check alphanumberic characters
        if(!isalnum(a) && a != '@' && a != '#' && a != '%' && a != '$' && a != '!'){
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{

int freq[100] = {0}; 
int length[100] = {0};
char unique[100][150]; // Max length 150 characters
int flag[100] = {0};
int result = -1;
int maxfreq = 0;
int maxlen = 0;

for(int i = 0; i < num_pwds; i++){
    int len = strlen(arr_pwds[i]);
    for(int j = 0; j < len; j++){
        unique[i][j] = arr_pwds[i][j]; //copy each char to unique
    }
    unique[i][len] = '\0'; 

    for(int l = 0; l < i; l++){
        if(strcmp(unique[i], unique[l]) == 0){ //check if dup
            freq[l]++; //increase freq
            flag[l] = 1; //mark as counted
            break;
        }
    }
    if(flag[i] == 0){
        freq[i]++;
        flag[i] = 1; //if no dup then add 1 freq and set as counted
    }
    length[i] = len;
    }

    // Find max freq and max len to return index
    for(int k = 0; k < num_pwds; k++){
        if(freq[k] > maxfreq || (freq[k] == maxfreq && length[k] > maxlen)){
            maxfreq = freq[k];
            maxlen = length[k];
            result = k;
        }
    }
    return result;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////