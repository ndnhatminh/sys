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

//Ham roundUp
int roundUp(double n){
    n += 0.999;
    return n;
}
//resetHP
int resetHP(int HP){
    if (HP > 666)
        return 666;
    if (HP < 0)
        return 0;
    return HP;
}

//resetEXP
int resetEXP(int EXP){
    if (EXP > 600)
        return 600;
    if (EXP < 0)
        return 0;
    return EXP;
}

//resetMoney
int resetM(int M){
    if (M > 3000)
        return 3000;
    if (M < 0)
        return 0;
    return M;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99)
        return -99;
    
    exp1 = resetEXP(exp1);
    exp2 = resetEXP(exp2);
    
    
    if (e1 >= 0 && e1 < 4){
        if (e1 == 0)
            exp2 += 29;
        if (e1 == 1)
            exp2 += 45;
        if (e1 == 2)
            exp2 += 75;
        if (e1 == 3)
            exp2 += 29 + 45 + 75;
        exp2 = resetEXP(exp2);
        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0)
            exp1 += roundUp((double)D / 200);
        else exp1 = roundUp(exp1 - (double)D / 100);
        exp1 = resetEXP(exp1);
    }

    if (e1 >= 4 && e1 < 100){
        if (e1 >= 4 && e1 <= 19)
            exp2 += roundUp((double)e1 / 4 + 19);
        
        if (e1 >= 20 && e1 <= 49)
            exp2 += roundUp((double)e1 / 9 + 21);
        
        if (e1 >= 50 && e1 <= 65)
            exp2 += roundUp((double)e1 / 16 + 17);
        
        if (e1 >= 66 && e1 <= 79){
            exp2 += roundUp((double)e1 / 4 + 19);
            if (exp2 > 200) exp2 += roundUp((double)e1 / 9 + 21);
        }
        
        if (e1 >= 80 && e1 <= 99){
            exp2 = roundUp(exp2 + (double)e1 / 4 + 19);
            exp2 = resetEXP(exp2);
            exp2 = roundUp(exp2 + (double)e1 / 9 + 21);
            exp2 = resetEXP(exp2);
            
            if (exp2 > 400){
                exp2 = roundUp(exp2 + (double)e1 / 16 + 17);
                resetEXP(exp2);
                exp2 = roundUp((double)exp2 * 1.15); 
            }
        }
        exp2 = resetEXP(exp2);
        exp1 -= e1;
        exp1 = resetEXP(exp1); 
    }
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // chua reset___
    if (E2 < 0 || E2 > 99)
        return -99;
    
    HP1 = resetHP(HP1);
    EXP1 = resetEXP(EXP1);
    M1 = resetM(M1);

    double percentage_1 = 0;

    double percentage_2 = 0;

    double percentage_3 = 0;
    // first path: 
    int check = round(sqrt(EXP1)); 
    
    if (EXP1 >= pow(check,2)){
        percentage_1 = 1;
    }
    else percentage_1 = ((double)EXP1 / pow(check,2) + 80) / 123;
    //second path:
    if (M1 > 0){
        if (E2 % 2 != 0){
            int initialM1 = M1;
            while (!(M1 < 0.5 * initialM1)){
                // first event
                if (HP1 < 200){
                    //cout << HP1 << " "; 
                    HP1 = roundUp((double)HP1 * 1.3);
                    HP1 = resetHP(HP1);
                    M1 -= 150;
                }
                else {
                    HP1 = roundUp((double)HP1 * 1.1);
                    
                    HP1 = resetHP(HP1);
                    M1 -= 70;
                }
                M1 = resetM(M1);
                if (M1 < 0.5 * initialM1) {
                    break;
                }
                
                //second event
                if (EXP1 < 400){
                    M1 -= 200;
                }
                else {
                    M1 -= 120;
                }
                M1 = resetM(M1);
                
                EXP1 = roundUp((double)EXP1 * 1.13);
                EXP1 = resetEXP(EXP1);

                if (M1 < 0.5 * initialM1) {
                    break;
                }
                
                //third event
                if (EXP1 < 300){
                    M1 -= 100;
                }
                else {
                    M1 -= 120;
                }
                M1 = resetM(M1);

                EXP1 = roundUp((double)EXP1 * 0.9);
                EXP1 = resetEXP(EXP1);

                if (M1 < 0.5 * initialM1) {
                    break;
                }               
            }
        }   
        else {
            while (M1 != 0){
            //first event 
            if (HP1 < 200){
                    HP1 = roundUp((double)HP1 * 1.3);
                    M1 -= 150;
                }
            else {
                    HP1 = roundUp((double)HP1 * 1.1);
                    M1 -= 70;
                }
            M1 = resetM(M1);
            HP1 = resetHP(HP1);

            if (M1 == 0) break;
            
            //second event
            if (EXP1 < 400)
                M1 -= 200;
            else M1 -= 120;

            EXP1 = roundUp((double)EXP1 * 1.13);
            M1 = resetM(M1);
            EXP1 = resetEXP(EXP1);
            
            if (M1 == 0) break;
            //third event
            if (EXP1 < 300)
                M1 -= 100;
            else M1 -= 120;

            EXP1 = roundUp((double)EXP1 * 0.9);

            M1 = resetM(M1);
            EXP1 = resetEXP(EXP1);
            break;
            }
        }
    }

    HP1 = roundUp((double)HP1 * 0.83);
    EXP1 = roundUp((double)EXP1 * 1.17);
    HP1 = resetHP(HP1);
    EXP1 = resetEXP(EXP1);
    
    //cout << " "<< HP1 << " " << EXP1; 
    check = round(sqrt(EXP1));
    if (EXP1 >= pow(check,2))
        percentage_2 = 1;
    else percentage_2 = ((double)EXP1 / pow(check,2) + 80) / 123;
    //Third path
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    
    int initialE2 = E2;

    int pos = 0;    
    if (E2 < 10) percentage_3 = (double)p[E2] / 100;
    
    else {
        pos += initialE2 % 10;
        initialE2 /= 10;
        pos += initialE2 % 10;
        if (pos >= 10)
            pos %= 10; 
        
        percentage_3 = (double)(p[pos]) / 100;
    }
    
    double result = (percentage_1 + percentage_2 + percentage_3) / 3;
    //cout << percentage_1 << " " << percentage_2 << " " << percentage_3 << endl;
    //cout << result; 
    if (result == 1) EXP1 = roundUp((double)EXP1 * 0.75);
    if (result < 0.5){
        HP1 = roundUp((double)HP1 * 0.85);  
        EXP1 = roundUp((double)EXP1 * 1.15);
    }
    if (result >= 0.5 && result < 1){
        HP1 = roundUp((double)HP1 * 0.9);
        EXP1 = roundUp((double)EXP1 * 1.2);
    } 
    EXP1 = resetEXP(EXP1);  
    HP1 = resetHP(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // hàm abs() có thể ko đc
    if (E3 < 0 || E3 > 99)
        return -99;
    
    HP1 = resetHP(HP1);
    EXP1 = resetEXP(EXP1);
    HP2 = resetHP(HP2);
    EXP2 = resetEXP(EXP2);


    int taxi[10][10];
    int SvW[10][10];

    int pos_i = 0, pos_j = 0;

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            //cout << taxi[i][j] << " ";
            if (taxi[i][j] > E3 * 2)
                pos_i += 1;
            if (taxi[i][j] < -1 * E3)
                pos_j += 1;
        }
        //cout << endl;
    }
    
    //find position
    while(pos_i >= 10){    
            int tmp = 0;
            while (pos_i > 0){
                tmp += pos_i % 10;
                pos_i /= 10;
            }
            pos_i = tmp;
        }
        while(pos_j >= 10){    
            int tmp = 0;
            while (pos_j > 0){
                tmp += pos_j % 10;
                pos_j /= 10;
            }
            pos_j = tmp;
        }
        //cout << pos_i << pos_j << " ";
            SvW[pos_i][pos_j] = taxi[pos_i][pos_j];
            //UpLeft
            int horizontal = pos_j, vertical = pos_i;
            while(vertical != 0 && horizontal != 0){
                vertical -= 1;
                horizontal -= 1;
                if (SvW[pos_i][pos_j] < taxi[vertical][horizontal]){
                    
                    SvW[pos_i][pos_j] = taxi[vertical][horizontal];
                    // cout << taxi[vertical][horizontal] << " ";
                }
            }
            //UpRight
            horizontal = pos_j; 
            vertical = pos_i;
            while(vertical != 0 && horizontal != 9){vertical -= 1;
                horizontal += 1;
                if (SvW[pos_i][pos_j] < taxi[vertical][horizontal]){
                    
                    SvW[pos_i][pos_j] = taxi[vertical][horizontal];
                    //cout << taxi[vertical][horizontal] << " ";
                }
            }
            //DownLeft
            horizontal = pos_j; 
            vertical = pos_i;
            while(vertical != 9 && horizontal != 0){
                vertical += 1;
                horizontal -= 1;
                
                if (SvW[pos_i][pos_j] < taxi[vertical][horizontal]){
                    
                    SvW[pos_i][pos_j] = taxi[vertical][horizontal];
                    //cout << taxi[vertical][horizontal] << " ";
                    //cout << vertical << " " << horizontal << endl; 
                
                }
            }
            //DownRight
            horizontal = pos_j; 
            vertical = pos_i;
            while(vertical != 9 && horizontal != 9){
                vertical += 1;
                horizontal += 1;
                if (SvW[pos_i][pos_j] < taxi[vertical][horizontal]){
                    
                    SvW[pos_i][pos_j] = taxi[vertical][horizontal];
                    //cout << SvW[pos_i][pos_j] << " ";
                    //cout << vertical << " " << horizontal << endl;
                }
            }
            //cout << SvW[pos_i][pos_j] << " ";
            if (SvW[pos_i][pos_j] < 0) SvW[pos_i][pos_j] *= -1;
            
    if (SvW[pos_i][pos_j] >= abs(taxi[pos_i][pos_j])){
        EXP1 = roundUp((double)EXP1 * 1.12);
        HP1 = roundUp((double)HP1 * 1.1);
        EXP2 = roundUp((double)EXP2 * 1.12);
        HP2 = roundUp((double)HP2 * 1.1);
        
        EXP1 = resetEXP(EXP1); EXP2 = resetEXP(EXP2);
        HP1 = resetHP(HP1); HP2 = resetHP(HP2);
        return SvW[pos_i][pos_j];
    }        
    else {
        EXP1 = roundUp((double)EXP1 * 0.88);
        HP1 = roundUp((double)HP1 * 0.9);
        EXP2 = roundUp((double)EXP2 * 0.88);
        HP2 = roundUp((double)HP2 * 0.9);
        
        EXP1 = resetEXP(EXP1); EXP2 = resetEXP(EXP2);
        HP1 = resetHP(HP1); HP2 = resetHP(HP2);
        return taxi[pos_i][pos_j];
    }
//    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string string_S = s;
    string string_mail = email;
    string se ="";
    for (int i = 0; i < string_mail.size(); i++)
        if (string_mail[i] != '@')
            se += string_mail[i];
        else break;
    
    //check length
    int sizePass = string_S.size();
    if (sizePass < 8 || sizePass > 20){
        if (sizePass < 8) return -1;
        if (sizePass > 20) return -2;
    }
    //check se in pass
    if (se == "")
        return -300;
    for (int i = 0; i < sizePass; i++)
        if (string_S[i] == se[0]){
            bool pass = true;
            int number = 1; 
            for (int j = 1; j < se.size(); j++){
                if (i + number < sizePass){
                    if (string_S[i + number++] != se[j])
                        pass = false;
                }
                else pass = false;
            }
            if (pass == true)
                return -(300 + i);
        }
    //check same word
    for (int i = 0; i < sizePass - 2; i++)
        if (string_S[i] == string_S[i + 1] && string_S[i] == string_S[i + 2])
            return -(400 + i);

    bool checkSymbol = false;
    for (int i = 0; i < sizePass; i++)
        if (string_S[i] == 33 || (string_S[i] >= 35 && string_S[i] <= 37)|| string_S[i] == 64)
            checkSymbol = true;
    if (checkSymbol == false)
        return -5;

    for (int i = 0; i < sizePass; i++)
        if (string_S[i] == 33 || (string_S[i] >= 35 && string_S[i] <= 37) ||(string_S[i] >= 48 && string_S[i] <= 57) ||(string_S[i] >= 64 && string_S[i] <= 90) || (string_S[i] >= 97 && string_S[i] <= 122))
            continue;
        else {
            return i;
        }
    return -10;              
}

// Task 5   
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string pass[num_pwds];
    for (int i = 0; i < num_pwds; i++)
        pass[i] = arr_pwds[i];
    
    int result[num_pwds];
    memset(result, 0, sizeof(result));
    for (int i = 0; i < num_pwds; i++)
        for (int j = i + 1; j < num_pwds; j++)
            if (pass[i] == pass[j])
                result[i] += 1;

    int pos = 0;
    int maxCheck = 0;
    for (int i = 0; i < num_pwds; i++){
        if (maxCheck < result[i]){        
            pos = i;
            maxCheck = result[i];
        }
        if (maxCheck == result[i])
            if (pass[pos].size() < pass[i].size())
                pos = i;
            
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
