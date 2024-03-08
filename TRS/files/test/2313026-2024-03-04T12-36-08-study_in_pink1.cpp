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


//General functions


//value clamp
int HPCtrl(int HP){
    HP = HP < 0 ? 0 : HP;
    HP = HP > 666 ? 666 : HP;
    return HP;
}
int EXPCtrl(int EXP){
    EXP = (EXP < 0) ? 0 : EXP;
    EXP = (EXP > 600) ? 600 : EXP;
    return EXP;
}
int MCtrl(int M){
    M = M < 0 ? 0 : M;
    M = M > 3000 ? 3000 :M;
    return M;
}
//Event exception

/*int Echecker(int e){
    if(e <0 || e > 99){
        return -99;}
}
*/
//Stats change

void HPChange(int &HP, double increment){
    HP = HPCtrl(ceil(HP + HP*increment));
    //cout << "HP: " << HP << endl;
}
void EXPChange(int &EXP, double increment){
    EXP = EXPCtrl(ceil(EXP + EXP*increment));
    //cout << "EXP: " << EXP << endl;
}

//4.2 Road 1 functions

//find nearest square number
int nearestSqrNum(int & exp1){
    exp1 = EXPCtrl(exp1);
    double root = sqrt(exp1);

    int lower_root = floor(root);
    int higher_root = ceil(root);

    double lower_square = pow(lower_root,2);
    double higher_square = pow(higher_root,2);
    double distanceLow = abs(exp1 - lower_square);
    double distanceHigh = abs(exp1 - higher_square);

    int closest;
    if (distanceLow <= distanceHigh){
        closest = lower_square;
    }
    else{
        closest = higher_square;
    }
    return closest;
}



//4.2 Road 2 functions

//First event func (Hp restore money lost)
void eventHPRestore(int &HP1, int &M1){
    if (HP1 < 200){
        HPChange(HP1,0.3);
        M1 = MCtrl( M1 -= 150 );
    } else if(HP1 >= 200){
        HPChange(HP1,0.10);
        M1 = MCtrl( M1 -= 70 );
    }
    //cout <<"HP1: "<<HP1 << ", M1: "<<M1<<endl;
}

//Second event func (taxi or horse)

void eventTorH(int &EXP1, int &M1){
    if(EXP1 < 400){
        M1 = MCtrl( M1 -= 200);//taxi
    }else{
        M1 = MCtrl( M1 -= 120);//horse
        
    }
    EXPChange(EXP1,0.13);
    //cout <<"EXP1: "<<EXP1 << ", M1: "<<M1<<endl;
}

//Third event func (homeless)

void eventHomeless(int &EXP1, int &M1){
    if(EXP1 < 300){
        M1 = MCtrl( M1 -= 100);
    }else{
        M1 = MCtrl( M1 -= 120);
    }
    EXPChange(EXP1,-0.1);
    //cout <<"EXP1: "<<EXP1 << ", M1: "<<M1<<endl;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    exp1 = EXPCtrl(exp1);
    exp2 = EXPCtrl(exp2);
    if (e1 < 0 || e1 > 99) {
        return -99;
    }else {
        // Truong hop 1
        if (e1 >= 0 && e1 < 4) {
            if (e1 == 0) {
                exp2 += 29;
            }
            if (e1 == 1) {
                exp2 += 45;
            }
            if (e1 == 2) {
                exp2 += 75;
            }
            if (e1 == 3) {
                exp2 += 149;
            }
            exp1 = EXPCtrl(exp1);
            double D = e1 * 3 + exp1 * 7; 
            if (fmod(D, 2) == 0) { 
                exp1 = ceil(exp1 + (D/200));
            } else {
                exp1 = ceil(exp1 - (D/100));
            }
            exp1 = EXPCtrl(exp1);
        }

        // Truong hop 2
        double de1 = e1;
        if (de1 >= 4 && de1 <= 19) { // info 1
            exp2 += ceil(de1 / 4 + 19); 
            exp1 -= e1;
        }
        if (de1 >= 20 && de1 <= 49) { // info 2
            exp2 += ceil(de1 / 9 + 21); 
            exp1 -= e1;
        }
        if (de1 >= 50 && de1 <= 65) { // info 3
            exp2 += ceil(de1 / 16 + 17); 
            exp1 -= e1;
        }
        if (de1 >= 66 && de1 <= 79) {
            exp2 += ceil(de1 / 4 + 19); // explain info 1
            exp2 = (exp2 > 200) ? (exp2 + ceil(de1 / 9 + 21)) : exp2; // if new exp > 200 then info 2
            exp1 -= e1;
        }
        if (de1 >= 80 && de1 <= 99) {
            exp2 += ceil(de1 / 4 + 19); // info 1
            exp2 += ceil(de1 / 9 + 21); // info 2
            exp2 = (exp2 > 400) ? (exp2 + ceil(de1 / 16 + 17)) * 1.15 : exp2; // if exp > 400 then info 3
            exp1 -= e1;
        }
    }

    
    exp1 = EXPCtrl(exp1);
    exp2 = EXPCtrl(exp2);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    HP1 = HPCtrl(HP1);
    EXP1 = EXPCtrl(EXP1);
    M1 = MCtrl(M1);
    int S1 = nearestSqrNum(EXP1);
    
    double p1, p2;

    // road 1
    if (S1 <= EXP1) {
        p1 = 1;
    } else {
        p1 = (static_cast<double>(EXP1) / static_cast<double>(S1) + 80) / 123;
    }
    
    // road 2
    if (E2 % 2 != 0) {
        int halfM = M1 * 0.5;
        int tempM = M1;
        int totalUsedM = 0;
        while (totalUsedM <= halfM) {
            for (int i = 0; i < 3 && totalUsedM <= halfM; i++) {
                switch (i) {
                    case 0:
                        eventHPRestore(HP1, M1);
                        totalUsedM += (tempM - M1);
                        tempM = M1;
                        break;
                    case 1:
                        eventTorH(EXP1, M1);
                        totalUsedM += (tempM - M1);
                        tempM = M1;
                        break;
                    case 2:
                        eventHomeless(EXP1, M1);
                        totalUsedM += (tempM - M1);
                        tempM = M1;
                        break;
                }
            }
        }
        HPChange(HP1, -.17);
        EXPChange(EXP1, .17);
    } else {
        for (int i = 0; i < 1; i++) {
            if (M1 < 0) break;
            eventHPRestore(HP1, M1);
            if (M1 < 0) break;
            eventTorH(EXP1, M1);
            if (M1 < 0) break;
            eventHomeless(EXP1, M1);
            
            
        }
        HPChange(HP1, -.17);
        EXPChange(EXP1, .17);
    }

    

    int S2 = nearestSqrNum(EXP1);
    if (S2 <= EXP1) {
        p2 = 1;
    } else {
        p2 = (static_cast<float>(EXP1) / static_cast<float>(S2) + 80) / 123;
    }
    

    double p3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        int temp1 = static_cast<int>(floor(static_cast<double>(E2) / 10));
        int temp2 = E2 % 10;
        i = (temp1 + temp2) % 10;
    }
    double Pavg = (p1 + p2 + (p3[i] / 100)) / 3;

    if (Pavg == 1) {
        EXPChange(EXP1, -.25);
    } else if (Pavg < 0.5) {
        HPChange(HP1, -.15);
        EXPChange(EXP1, .15);
    } else {
        HPChange(HP1, -.1);
        EXPChange(EXP1, .20);
    }

    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this functiona
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    int mapTaxi[10][10];
    for(int i = 0; i< 10; i++){
        for(int j = 0; j < 10; j++){
            mapTaxi[i][j] = ((E3 * j) + (i * 2))*(i-j);
            //cout <<mapTaxi[i][j] <<" \t";
        }
        //cout<< endl;
    }
    int mapSherlock[10][10];
    int crossLeft = 0,crossRight = 0;
    for(int i = 0 ; i< 10; i++){//asign value to sherlock map
        for(int j = 0; j < 10; j++){
            crossLeft = 0,crossRight = 0;
            for(int t = 0; t < 10 - abs(i - j); t++){
                crossLeft = (max((mapTaxi[t][abs(i-j)+t]), crossLeft));
            }
            for(int t = 0; t < (10 - abs(i - (9-j)));t++){
                crossRight = (max((mapTaxi[abs(i - (9-j)) + t][9-t]), crossRight));
                //cout<<  (mapTaxi[abs(i - (9-j)) + t][9-t]) <<endl;
            }
            mapSherlock[i][j] = max(crossLeft,crossRight);
            
        }
        
    }

    
    //where sherlock meets taxi
    int meeti = 0, meetj = 0;
    int countP = 0, countN = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(mapTaxi[i][j] > E3 * 2){
                countP++;
            }else if(mapTaxi[i][j] < (-E3)){
                countN++;
            }
        }
    }
    
    while (countP >= 10){
        meeti = countP/10 + countP%10;
        countP = meeti;
    }
    while (countN >= 10){
        meetj = countN/10 + countN%10;
        countN = meetj;
    };
    if(abs(mapTaxi[meeti][meetj]) > mapSherlock[meeti][meetj]){
        EXPChange(EXP1,-.12);
        EXPChange(EXP2,-.12);
        HPChange(HP1,-.1);
        HPChange(HP2,-.1);
    }else{
        EXPChange(EXP1,.12);
        EXPChange(EXP2,.12);
        HPChange(HP1,.1);
        HPChange(HP2,.1);
    }
    return abs(mapTaxi[meeti][meetj]) > mapSherlock[meeti][meetj] ? mapTaxi[meeti][meetj] : mapSherlock[meeti][meetj];
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string mail = email;
    string pass = s;
    string se = mail.substr(0, mail.find('@'));

    //check length
    int n = pass.length();
    if (n < 8) {
        return -1; 
    }
    if (n > 20) {
        return -2; 
    }

    //check se
    if (pass.find(se) != string::npos) {
        return -(300 + pass.find(se)); 
    }

    //check repeat
    for (int i = 0; i < n - 2; ++i) {
        if (pass[i] == pass[i + 1] && pass[i + 1] == pass[i + 2]) {
        return -(400 + i); 
        }
    }

    //check special
    bool hasSpecial = false;
    for (char c : pass) {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
        hasSpecial = true;
        break;
        }
    }
    if (!hasSpecial) {
        return -5;
    }

    //check other
    for (int i = 0; i < n; ++i) {
        if (!isalnum(pass[i]) && pass[i] != '@' && pass[i] != '#' && pass[i] != '%' && pass[i] != '$' && pass[i] != '!') {
        return i;
        }
    }

    //correct pass
    return -10;
    }

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    int countPasswords[30] = { 0 };// holds the number of times a string is repeated
    
    int indexPasswords = 0;
    
    string arr[num_pwds];
    
    for(int i = 0; i < num_pwds; i++){
        arr[i] = arr_pwds[i];
    }
    
    
    // loop through entire array and check if element has existed already
    for (int i = 0; i < num_pwds; i++) {
        bool found = false;
        for (int j = 0; j < indexPasswords; j++) {// if the element has existed be 4 then add to the count (countPasswords)
            if (arr[i].compare(arr[j]) == 0) { 
                countPasswords[j] += 1;
                found = true;
                break;
            }
        }
        
        if (!found) {
        countPasswords[indexPasswords]++;
        indexPasswords++;
        }
    }
    
    
    
    int max_count = 0;
    int max_password_index = -1;
    for (int i = 0; i < indexPasswords ; i++) {
        if (countPasswords[i] > max_count) {
            max_count = countPasswords[i];
            max_password_index = i;
            
            
        } else if (countPasswords[i] == max_count && strlen(arr_pwds[i]) > strlen((arr_pwds[max_password_index])) > 0) {
           max_password_index = i;
        }
        
    }
    for (int i = 0; i < num_pwds; i++) {
        if (arr[i].compare(arr[max_password_index]) == 0) {
            
            return i;
        }
        
    }
    
    
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
