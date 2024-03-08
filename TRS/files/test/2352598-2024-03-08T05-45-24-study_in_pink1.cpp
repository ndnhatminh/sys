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


   int task1(int & exp1, int & exp2, int & e1)
    {

    exp1 = max(0, min(exp1, 600));
    exp2 = max(0, min(exp2, 600));

    if (e1 > 99 || e1 < 0){
    return e1 = -99;
    
    }
    return exp1, exp2, e1;
    }   

    int task2 (int & HP1, int & EXP1, int & M1, int & E2)
    {
    HP1 = max(0, min(HP1, 666));    

    EXP1 = max(0, min(EXP1, 600));    

    M1 = max(0, min(M1, 3000));
   
    if (E2 < 0 || E2 > 99) E2 = -99;   

    return HP1, EXP1, M1, E2;
    }

    int task3 (int & HP1, int & EXP1, int & HP2, int & EXP2, int & E3)
    {    
    HP1 = max(0, min(HP1, 666));
    HP2 = max(0, min(HP2, 666));

    EXP1 = max(0, min(EXP1, 600));
    EXP2 = max(0, min(EXP2, 600));

    if (E3 < 0 || E3 > 99) E3 = -99;

    return HP1, HP2, EXP1, EXP2, E3;
    }
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    task1 (exp1, exp2, e1);
    if (e1 > 99 || e1 < 0){
    return e1 = -99;
    }
    int D = e1 * 3 + exp1 * 7;
        if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
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
                exp2 += 29 + 45 + 75;
                break;
            default:
                return -99;
        }

        if (D % 2 == 0) {
            exp1 += std::ceil(D / 200.0);
        } else {
            exp1 = std::ceil(exp1 - (D / 100.0));
        }
        task1 (exp1, exp2, e1);
    } 
        else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 += std::ceil((e1 / 4.0) + 19);
            task1 (exp1, exp2, e1);
        } else if (e1 >= 20 && e1 <= 49) {
            exp2 += std::ceil((e1 / 9.0) + 21);
            task1 (exp1, exp2, e1);
        } else if (e1 >= 50 && e1 <= 65) {
            exp2 += std::ceil((e1 / 16.0) + 17);
            task1 (exp1, exp2, e1);
        } else if (e1 >= 66 && e1 <= 79) {
            exp2 += std::ceil((e1 / 4.0) + 19);
task1 (exp1, exp2, e1);
            if (exp2 > 200) {
                exp2 += std::ceil((e1 / 9.0) + 21);
                task1 (exp1, exp2, e1);
            }
        } else if (e1 >= 80 && e1 <= 99) {
            exp2 += std::ceil((e1 / 4.0) + 19);
            exp2 += std::ceil((e1 / 9.0) + 21);
            task1 (exp1, exp2, e1);
            if (exp2 > 400) {
              
                exp2 += std::ceil((e1 / 16.0) + 17);
                exp2 += std::ceil(exp2 * 0.15);
                task1 (exp1, exp2, e1);
            }
        }
       

        exp1 -= e1;
        task1 (exp1, exp2, e1);
    }

    return exp1 + exp2;
}


// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {    
    // **Conduong1
    
    task2(HP1, EXP1, M1, E2);
    int S;
    double P1, P2;
    double squareroot = static_cast<int>(sqrt(EXP1));
    int uppersquare = squareroot * squareroot;
    int lowersquare = (squareroot + 1) * (squareroot + 1);
    if (abs((uppersquare - EXP1)) > abs((EXP1 - lowersquare))) {
        S = lowersquare;
    } else {
        S = uppersquare;
    }
    if (EXP1 >= S) {
        P1 = 1.0;
    } else {
        P1 = (((EXP1 * 1.0) / S) + 80) / 123;
    }
      // **Conduong2
    int money = 0; 
    if (E2 % 2 != 0) {
        while (true) {
            // muadoan+nuocuong
            if (HP1 < 200) {
                HP1 = std::ceil(HP1 + HP1 * 0.3);               
                money += 150;
            } else {
                HP1 = std::ceil(HP1 + HP1 * 0.1);                
                money += 70;
            }  
            task2(HP1, EXP1, M1, E2);
          
             if (money > (M1 * 0.5))                 
                break; 
            
            
            // dichuyen
            if (EXP1 < 400) {
                money += 200;
                EXP1 = std::ceil(EXP1 + EXP1 * 0.13);                
            } else {
                money += 120;
                EXP1 = std::ceil(EXP1 + EXP1 * 0.13);
            }
            task2(HP1, EXP1, M1, E2);
             if (money > (M1 * 0.5)) {
                break; 
            }
            // gapnguoivogiacu
            if (EXP1 < 300) {
                money += 100;
            } else {
                money += 120;
            }
            EXP1 = std::ceil(EXP1 - EXP1 * 0.1);
            task2(HP1, EXP1, M1, E2);
            if (money > (M1 * 0.5)) {                
                break; 
            }
        
            if (E2 % 2 == 0) {
            break;
            }
        }
    }
    HP1 = std::ceil(HP1 - HP1 * 0.17);
    EXP1 = std::ceil(EXP1 + EXP1 * 0.17);
    task2(HP1, EXP1, M1, E2);
    // *Conduong3
    if (EXP1 >= S) {
        P2 = 1.0;
    } else {
        P2 = (((EXP1 * 1.0) / S) + 80) / 123;
    }
    M1 = M1 - money;
    int i;
    if (E2 < 10) {
        i = E2;
    }
    if (E2 >= 10) {
        i = ((E2 / 10) + (E2 % 10)) % 10;
    }
    int xacsuat[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3 = xacsuat[i];
double avgxs = ceil((P1 + P2 + P3) / 3.0);
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 -= EXP1 * 0.25;
    } else {
        if (avgxs < 0.5) {
            HP1 = std::ceil(HP1 - HP1 * 0.15);
            EXP1 = std::ceil(EXP1 + EXP1 * 0.15);           
        } else {
            HP1 = std::ceil(HP1 - HP1 * 0.1);
            EXP1 = std::ceil(EXP1 + EXP1 * 0.2);           
        }
    }
    task2(HP1, EXP1, M1, E2);
       return HP1 + EXP1 + M1;
    
}


// Task 3
    int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int map[10][10];
    int count1 = 0;
    int count2 = 0;
    task3(HP1, EXP1, HP2, EXP2, E3);
   
    //**Ma tran diem so
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > (E3 * 2)) {
                count1++;
            }
            if (map[i][j] < (-E3)) {
                count2++;
            }
        }
    }
    //**Timvitrigapnhau
    int hoanh = ((count1 / 10) + (count1 % 10)) / 10 + ((count1 / 10) + (count1 % 10)) % 10;
    int tung = ((count2 / 10) + (count2 % 10)) / 10 + ((count2 / 10) + (count2 % 10)) % 10;
    int taxipoint = map[hoanh][tung];
    //**TinhdiemSherWat
    int a = hoanh, b = tung;
    for (int i = 0; i <= 9; i++) {
        if (taxipoint < map[hoanh][tung]) {
taxipoint = map[hoanh][tung];
            
        }hoanh--;
         tung--;
        if (hoanh < 0 || tung < 0) {
            break;
        }
    }
    int maxcheotraitren = taxipoint;//maxcheotraitren
    hoanh = a; tung = b;
    taxipoint = map[hoanh][tung];
    for (int i = 0; i <= 9; i++) {
        if (taxipoint < map[hoanh][tung]) {
            taxipoint = map[hoanh][tung];
            
        }
        hoanh--;
        tung++;
        if (hoanh < 0 || tung > 9) {
            break;
        }
    }

    int maxcheotraiduoi = taxipoint;//maxcheotraiduoi
    hoanh = a; tung = b;
    taxipoint = map[hoanh][tung];
    for (int i = 0; i <= 9; i++) {
        if (taxipoint < map[hoanh][tung]) {
            taxipoint = map[hoanh][tung];
           
        } 
        hoanh++;
        tung--;
        if (hoanh > 9 || tung < 0) {
            break;
        }
    }
    int maxcheophaitren = taxipoint;//maxcheophaitren
    hoanh = a; tung = b;
    taxipoint = map[hoanh][tung];
    for (int i = 0; i <= 9; i++) {
        if (taxipoint < map[hoanh][tung]) {
            taxipoint = map[hoanh][tung];
            
        }
        hoanh++;
        tung++;
        if (hoanh > 9 || tung > 9) {
            break;
        }
       
    }
    int maxcheophaiduoi = taxipoint;//maxcheophaiduoi
    hoanh = a; tung = b;
    taxipoint = map[hoanh][tung];

    int SherWatpoint = maxcheotraitren;
    if (maxcheotraiduoi > SherWatpoint) {
        SherWatpoint = maxcheotraiduoi;
    }
    if (maxcheophaitren > SherWatpoint) {
        SherWatpoint = maxcheophaitren;
    }
    if (maxcheophaiduoi > SherWatpoint) {
SherWatpoint = maxcheophaiduoi;
    }

    if ((abs(taxipoint)) > SherWatpoint) {
EXP1 = std::ceil(EXP1 - EXP1 * 0.12);
        HP1 = std::ceil(HP1 - HP1 * 0.1);
        EXP2 = std::ceil(EXP2 - EXP2 * 0.12);
        HP2 = std::ceil(HP2 - HP2 * 0.1);

    }
    else {
        EXP1 = std::ceil(EXP1 + EXP1 * 0.12);
        HP1 = std::ceil(HP1 + HP1 * 0.1);
        EXP2 = std::ceil(EXP2 + EXP2 * 0.12);
        HP2 = std::ceil(HP2 + HP2 * 0.1);
    }
    if (HP1 > 666) {
        HP1 = 666;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP2 > 666) {
        HP2 = 666;
    }
    if (HP2 < 0) {
        HP2 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP2 > 600) {
        EXP2 = 600;
    }
    if (EXP2 < 0) {
        EXP2 = 0;
    }
    int result;
    if (abs(taxipoint) > SherWatpoint) {
        result = taxipoint;
    }
    else {
        result = SherWatpoint;
    }

    return result;
}

    
   // Task 4
    int checkPassword(const char * s, const char * email) {
    string password(s);
    string se(email);
    se = se.substr(0, se.find('@'));
    string special_chars = "@#%$!";
    
    
    if (password.length() < 8){
        return -1;
    }
    if (password.length() > 20){

        return -2;    
    }

    size_t sei = password.find(se);
if (sei != std::string::npos) return -(300 + sei);

    for (size_t sci = 0; sci < password.length() - 2; sci++) {
        if (s[sci] == s[sci + 1] && s[sci + 1] == s[sci + 2]) {
            return -(400 + sci);
        }
    }

    bool checkktdb = false;
    for (char c : password) {
    if (special_chars.find(c) != std::string::npos) {
        checkktdb = true;
        break;
    }
}
if (!checkktdb){
    return -5;
    }

for (size_t i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (!isalnum(c) && special_chars.find(c) == string::npos) return i;        
    }

    return -10;
}
            

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int maxcount = 0;
    const char *phantuxhnhieunhat = nullptr;
    int vitridautien = -1;

    for (int i = 0; i < num_pwds; i++) {
        int counting = 1;

        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                counting++;
            }
        }

        if (counting > maxcount || (counting == maxcount && strlen(arr_pwds[i]) > strlen(phantuxhnhieunhat))) {
            maxcount = counting;
            phantuxhnhieunhat = arr_pwds[i];
            vitridautien = i;
        }
    }

    return vitridautien;
}






////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
