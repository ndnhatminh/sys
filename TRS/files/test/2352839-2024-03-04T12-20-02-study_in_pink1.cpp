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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1 < 0 || E1 > 99) return -99;
    //situation 1
    else if (E1 >= 0 && E1 <= 3){
        int incrementExp[] = {29, 45 , 75, 29 + 45 + 75};
        EXP2 += incrementExp[E1];
        int D = E1*3 + EXP1*7;
        if(D%2==0){
            EXP1 = ceil(EXP1 + D/200.0);
        }
        else{
            EXP1 = ceil(EXP1 - D/100.0);
        }
    }
    //situation 2
    else{
        if(E1<=19) EXP2 = ceil(EXP2 + E1/4.0 + 19);
        else if(E1 <= 49) EXP2 = ceil(EXP2 + E1/9.0 + 21);
        else if(E1 <= 65) EXP2 = ceil(EXP2 + E1/16.0 + 17);
        else if(E1 <= 79){
            EXP2 = ceil(EXP2 + E1/4.0+19);
            if(EXP2 > 200){
                EXP2 = ceil(EXP2 + E1/ 9.0 + 21);
        }
        }
        else{
            EXP2 = ceil(EXP2 + E1/4.0 + 19);
            EXP2 = ceil(EXP2 + E1/9.0 + 21);
            if(EXP2 > 400){
                EXP2 = ceil(EXP2 + E1/16.0 + 17);
                EXP2 = ceil(EXP2 + EXP2 * 0.15);
            }
        }
        EXP1 -= E1;
        
       
    }
    if(EXP1 > 600) EXP1  = 600;
    else if(EXP1 < 0) EXP1 =0;
    if(EXP2 > 600) EXP2 = 600;
    else if(EXP2<0) EXP2=0; 
    return EXP1 + EXP2;
}   
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    int S;
    bool looponce = true;
    double P1, P2, P3, P4; 

    int S1 = round(ceil(sqrt(EXP1)));
    int S2 = round(floor(sqrt(EXP1)));

    if (abs(S1 * S1 - EXP1) > abs(S2 * S2 - EXP1)) {
        S = S2 * S2;
    }
    else {
        S = S1 * S1;
    }

    if (EXP1 < S) {
        P1 = (static_cast<double>(EXP1) / S + 80) / 123;
    }
    else {
        P1 = 1;
    }

    double useM1 = 0; 
    // road 02
    if (E2 % 2 != 0) {
        while (useM1 <= M1 * 50.0 / 100) {
            
            if (HP1 < 200) {
                HP1 = ceil(HP1 + HP1 * 30.0 / 100);
                useM1 += 150;
            }
            else {
                HP1 = ceil(HP1 + HP1 * 10.0 / 100);
                useM1 += 70;
            }
            // Simplify conditions
            EXP1 = min(600, max(0, EXP1)); 
            HP1 = min(666, max(0, HP1));   
            M1 = min(3000, max(0, M1));   

            if (useM1 > M1 * 50.0 / 100) {
                break;
            }

            if (EXP1 < 400) {
                useM1 += 200;
                EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100);
            }
            else {
                useM1 += 120;
                EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100);
            }
            EXP1 = min(600, max(0, EXP1)); 
            HP1 = min(666, max(0, HP1));   
            M1 = min(3000, max(0, M1));    

            if (useM1 > M1 * 50.0 / 100) {
                break;
            }

            if (EXP1 < 300) {
                useM1 += 100;
                EXP1 = ceil(EXP1 - EXP1 * 10.0 / 100);
            }
            else {
                useM1 += 120;
                EXP1 = ceil(EXP1 - EXP1 * 10.0 / 100);
            }
            EXP1 = min(600, max(0, EXP1)); 
            HP1 = min(666, max(0, HP1));   
            M1 = min(3000, max(0, M1));    

            if (useM1 > M1 * 50.0 / 100) {
                break;
            }
        }
    }
    // Straight road without loops
    else {
        while (useM1 - M1 <= 0 && looponce) {
          
            if (HP1 < 200) {
                HP1 = ceil(HP1 + HP1 * 30.0 / 100);
                useM1 += 150;
            }
            else {
                HP1 = ceil(HP1 + HP1 * 10.0 / 100);
                useM1 += 70;
            }
            // Simplify conditions
            EXP1 = min(600, max(0, EXP1)); 
            HP1 = min(666, max(0, HP1));   
            M1 = min(3000, max(0, M1));    
            if (useM1 - M1 > 0) break;

            if (EXP1 < 400) {
                useM1 += 200;
                EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100);
            }
            else {
                useM1 += 120;
                EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100);
            }
            EXP1 = min(600, max(0, EXP1)); 
            HP1 = min(666, max(0, HP1));  
            M1 = min(3000, max(0, M1));    
            if (useM1 - M1 > 0) break;

            if (EXP1 < 300) {
                useM1 += 100;
                EXP1 = ceil(EXP1 - EXP1 * 10.0 / 100);
            }
            else {
                useM1 += 120;
                EXP1 = ceil(EXP1 - EXP1 * 10.0 / 100);
            }
            EXP1 = min(600, max(0, EXP1)); 
            HP1 = min(666, max(0, HP1));   
            M1 = min(3000, max(0, M1));    
            if (useM1 - M1 > 0) break;
            looponce = false;
        }
    }
    HP1 = ceil(HP1 - HP1 * 17.0 / 100);
    EXP1 = ceil(EXP1 + EXP1 * 17.0 / 100);

    int N;
    int N1 = round(ceil(sqrt(EXP1)));
    int N2 = round(floor(sqrt(EXP1)));

    if (abs(N1 * N1 - EXP1) > abs(N2 * N2 - EXP1)) {
        N = N2 * N2;
    }
    else {
        N = N1 * N1;
    }
    if (EXP1 >= N) {
        P2 = 1;
    }
    else {
        P2 = (static_cast<double>(EXP1) / S + 80) / 123;
    }

    double P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (0 <= E2 && E2 <= 9) {
        P3 = P[E2];
    }
    else if (10 <= E2 && E2 <= 99) {
        int n1 = E2 / 10;
        int n2 = E2 % 10;
        int n3 = n2 + n1;
        int i = n3 % 10;
        P3 = (1.0 / 100) * P[i];
    }

    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 - EXP1 * 25.0 / 100);
    }
    else {
        P4 = (P1 + P2 + P3) / 3;
        if (P4 < 0.5) {
            HP1 = ceil(HP1 - HP1 * 15.0 / 100);
            EXP1 = ceil(EXP1 + EXP1 * 15.0 / 100);
        }
        else {
            HP1 = ceil(HP1 - HP1 * 10.0 / 100);
            EXP1 = ceil(EXP1 + EXP1 * 20.0 / 100);
        }
    }
    // Simplify conditions
    M1 -= useM1;
    EXP1 = min(600, max(0, EXP1)); 
    HP1 = min(666, max(0, HP1));   
    M1 = min(3000, max(0, M1));    
    
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    // TODO: Complete this function
    int result;
    int a;
    int b;
    int diemSherlock = 0;
    int bigger = 0;
    int diemtaxi =0;
    int smaller = 0; 
    int last_bigger;
    int last_smaller;
    int biggest;
    int arr[10][10] = {0};
    for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        if (arr[i][j] > 2 * E3) {
            ++bigger;
        }
        if (arr[i][j] < -E3) {
            ++smaller;
        }
    }
}

while (bigger > 0) {
    int n = bigger / 10;
    int m = bigger % 10;
    last_bigger = n + m;

    bigger = last_bigger;
    if (bigger < 10) break;
}

while (smaller > 0) {
    int k = smaller / 10;
    int l = smaller % 10;
    last_smaller = k + l;

    smaller = last_smaller;
    if (smaller < 10) break;
}



diemtaxi = ((E3 * smaller) + (bigger * 2)) * (bigger - smaller);

int max_value = arr[bigger][smaller];
for (int i = 1; i <= bigger; ++i) {
    if (bigger - i >= 0 && smaller - i >= 0 && arr[bigger - i][smaller - i] > max_value) // Upper-left diagonal
        max_value = arr[bigger - i][smaller - i];
    if (bigger - i >= 0 && smaller + i < 10 && arr[bigger - i][smaller + i] > max_value) // Upper-right diagonal
        max_value = arr[bigger - i][smaller + i];
    if (bigger + i < 10 && smaller - i >= 0 && arr[bigger + i][smaller - i] > max_value) // Lower-left diagonal
        max_value = arr[bigger + i][smaller - i];
    if (bigger + i < 10 && smaller + i < 10 && arr[bigger + i][smaller + i] > max_value) // Lower-right diagonal
        max_value = arr[bigger + i][smaller + i];
}
diemSherlock = max_value;
a = abs(diemSherlock);
b = abs(diemtaxi);
if (b > a) {
    result = diemtaxi;
    EXP1 = ceil(EXP1 * 88.0 / 100);
    HP1 = ceil(HP1 * 90.0 / 100);
    EXP2 = ceil(EXP2 * 88.0 / 100);
    HP2 = ceil(HP2 * 90.0 / 100);
}
else {
    result = diemSherlock;
    EXP1 = ceil(EXP1 + EXP1 * 12.0 / 100);
    HP1 = ceil(HP1 + HP1 * 10.0 / 100);
    EXP2 = ceil(EXP2 + EXP2 * 12.0 / 100);
    HP2 = ceil(HP2 + HP2 * 10.0 / 100);
}


EXP1 = min(600, std::max(0, EXP1));
HP1 = min(666, std::max(0, HP1));
EXP2 = min(600, std::max(0, EXP2));
HP2 = min(666, std::max(0, HP2));

    return result;
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
size_t length = strlen(s);
    if (length < 8) {
        return -1; 
    }
    if (length > 20) {
        return -2; 
    }
    string password(s);
    string e=email;
    string se=e.substr(0,e.find("@"));
    size_t sePos = password.find(se);
    if (sePos != string::npos) {
        return -(300 + static_cast<int>(sePos)); 
    }

    for (size_t i = 0; i < length - 1; ++i) {
        if (s[i] == s[i + 1]&& s[i]==s[i+2]) {
            return -(400 + static_cast<int>(i)); 
        }
    }
    bool specialcharacter = false;
    const char specialChars[] = {'@', '#','$', '%', '!'};
    for (size_t i = 0; i < length; ++i) {
        if (strchr(specialChars, s[i]) != nullptr) {
            specialcharacter = true;
            break;
        }
    }
    if (!specialcharacter) {
        return -5; 
    }
    for (int j = 0; j < length; ++j) {
    if(isalpha(s[j])==0 && isdigit(s[j])==0 && s[j]!='@'&& s[j]!='#' && s[j]!='$'&& s[j]!='%' && s[j]!='!')
        return j;}
    return -10; 

    return -99;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int do_dai = 0;
    int so_lan_xuat_hien = 0;
    int index = -1;

    for (int i = 0; i < num_pwds; i++) {
        int length = strlen(arr_pwds[i]);
        int count = 0;

        // tinh so lan xuat hien cua mat khau
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        // mat khau xuat hien nhieu nhat va co do dai dai nhat
        if (count > so_lan_xuat_hien || (count == so_lan_xuat_hien && length > do_dai)) {
            do_dai = length;
            so_lan_xuat_hien = count;
            index = i;
        }
    }

    return index;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////