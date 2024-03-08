#include "study_in_pink1.h"
//ab
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
int check_HP(int HP1) {
    if(HP1 > 666) return 666;
    if (HP1 < 0) return 0;
    return HP1;
}
int check_EXP(int EXP) {
    if (EXP > 600) return 600;
    if (EXP < 0) return 0;
    return EXP;
}
int check_M (int M) {
    if (M < 0) return 0;
    if (M > 3000) return 3000;
    return M;
}
int Scale_Up(float a) {
    if((a - int(a)) > 0) a++;
    return a;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    exp1 = check_EXP(exp1);
    exp2 = check_EXP(exp2);
    // case 1
    if (e1 >=0 && e1 <=3) {
       if (e1 == 0) exp2 += 29;
       if (e1 == 1) exp2 += 45;
       if (e1 == 2) exp2 += 75;
       if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;
       exp2 = check_EXP(exp2);
       int d = e1 * 3 + exp1 * 7;
       if (d & 1) exp1 = Scale_Up(exp1 - (d/100.0f));
       else exp1 += Scale_Up(d/200.0f); 
       exp1 = check_EXP(exp1);
    }
    // case 2
    if (e1 >= 4 && e1 <=99) {
        if (e1 >= 4 && e1 <= 19) exp2 += (Scale_Up(e1/4.0f) + 19);
        if (e1 >= 20 && e1 <= 49) exp2 += (Scale_Up(e1/9.0f) + 21);
        if (e1 >= 50 && e1 <= 65) exp2 += (Scale_Up(e1/16.0f) + 17);
        if (e1 >= 66 && e1 <= 79) {
            exp2 += (Scale_Up(e1/4.0f) + 19);
            exp2 = check_EXP(exp2);
            if (exp2 > 200) exp2 += (Scale_Up(e1/9.0f) + 21);
            exp2 = check_EXP(exp2);
        }
        if (e1 >= 80 && e1 <=99) {
            exp2 = exp2 + (Scale_Up(e1/4.0f) + 19) + (Scale_Up(e1/9.0f) + 21);
            exp2 = check_EXP(exp2);
            if (exp2 > 400) {
                exp2 += (Scale_Up(e1/16.0f) + 17);
                exp2 = Scale_Up(exp2 * 1.15f);
            }
        }
        exp2 = check_EXP(exp2);
        exp1 -= e1;
        exp1 = check_EXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
// Ham check so co 1 chu so va so co 2 chu so 
bool check_number (int n) {
    int count = 0;
    while (n > 0) {
        n = n / 10;
        count ++;
    }
    if (count == 1) return true;
    return false;
}
// Ham tinh tong so chu so trong 1 so
int Sum_of_number (int n) {
    int sum = 0;
    while (n > 0) {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}
// Ham tinh P1, P2
double Find_P1_P2(int EXP1) {
    double P1;
    int S1 = sqrt(EXP1);
    double ratio1;
    if ((EXP1 - S1 * S1) <= ((S1 + 1)*(S1 + 1) - EXP1)) {
        P1 = 1;
    }
    else {
        S1++;
        ratio1 = static_cast<double>(EXP1) / (S1 * S1);
        P1 = (ratio1 + 80)/123.0;
    }
    return P1;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // ROAD 1
    if (E2 < 0 || E2 > 99) return -99;
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);
    M1 = check_M(M1);
    int S1 = sqrt(EXP1);
    double P1 = Find_P1_P2(EXP1); // Ham tim P1, P2 dung 
    //ROAD 2
    if (M1 != 0) {
        int spend = 0;
        double money = M1 / 2;
        if (E2 % 2 == 1) {
            while (1) {
            //EVENT 1
                if(HP1 < 200) {
                    HP1 = Scale_Up(HP1*1.3f);
                    M1 -= 150;
                    spend += 150;
                }
                else {
                    HP1 = Scale_Up(HP1*1.1);
                    M1 -= 70;
                    spend += 70;
                }
                M1 = check_M(M1);
                HP1 = check_HP(HP1);
                if (spend > money) break;
                //EVENT 2
                if (EXP1 < 400) {
                    M1 -= 200;
                    spend += 200;
                }
                else {
                    M1 -= 120;
                    spend += 120;
                }
                EXP1 = Scale_Up(EXP1 * 1.13f);
                M1 = check_M(M1);
                EXP1 = check_EXP(EXP1);
                if (spend > money) break;
                // EVENT 3
                if (EXP1 < 300) {
                    M1 -= 100;
                    spend += 100;
                }
                else {
                    M1 -= 120;
                    spend += 120;
                }
                EXP1 = Scale_Up(EXP1 * 0.9f);
                EXP1 = check_EXP(EXP1);
                M1 = check_M(M1);
                if (spend > money) break;
            }
        }
        else {
            //EVENT 1
            for (int i = 1; i <= 1; i++) {
                if (HP1 < 200) {
                    HP1 = Scale_Up(HP1*1.3f); // HP1 = 30
                    M1 -= 150; // m1 = 2089
                }
                else{
                    HP1 = Scale_Up(HP1*1.1f);
                    M1 -= 70;
                }
                M1 = check_M(M1);
                HP1 = check_HP(HP1);
                if (M1 == 0) break;
                //EVENT 2
                if (EXP1 < 400) {
                    M1 -= 200;  // m1 = 1889
                }
                else {
                    M1 -= 120;
                }
                M1 = check_M(M1);
                EXP1 = Scale_Up(EXP1 * 1.13f); //exp1 = 424
                EXP1 = check_EXP(EXP1);
                if (M1 == 0) break;
                if (EXP1 < 300) {
                    M1 -= 100;
                }
                else {
                    M1 -= 120; //m1 - 1769
                }
                EXP1 = Scale_Up(EXP1 * 0.9f); //exp1 = 382
                EXP1 = check_EXP(EXP1);
                M1 = check_M(M1); // m1 = 1769
                if (M1 == 0) break;
            }
        }
    }
    HP1 = Scale_Up(HP1 * 0.83f); // hp1 = 25
    EXP1 = Scale_Up(EXP1 * 1.17f); // exp1 = 447
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);
    // Calculate P2
    double P2 = Find_P1_P2(EXP1); 
    // ROAD 3
    double P3;
    double average;
    double P[] = {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
    if(check_number(E2) == true) {
        P3 = P[E2];
    }
    else {
        P3 = P[Sum_of_number(E2)%10]; 
    } 
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = Scale_Up(EXP1 * 0.75f);
    else {
        average = (P1 + P2 + P3)/3;
        if (average < 0.5) {
            HP1 = Scale_Up(HP1 * 0.85f);
            EXP1 = Scale_Up(EXP1 * 1.15f);
        }
        if (average >= 0.5) {
            HP1 = Scale_Up(HP1 * 0.9f);
            EXP1 = Scale_Up(EXP1 * 1.2);
        }
    }    
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0) return -99;
    HP1 = check_HP(HP1);
    HP2 = check_HP(HP2);
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    int map[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int positive = 0;
    int negative = 0;
    // Calculate map[i][j], coutn positive and negative number
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3*j) + (i*2))*(i-j);
            if (map[i][j] > 0 && map[i][j] > (E3*2)) positive ++;
            else {
                if (map[i][j] < 0 && map[i][j] < (-E3)) negative ++;
            }
        }
    }
    //Calculate Max_Right[i][j] = max of duong cheo phai cua diem map[i][j];
   int Max_Right[10][10];
    Max_Right[0][0] = map[0][0];
    Max_Right[9][9] = map[9][9];
    for (int i = 1; i < 10; i++) {
        int j = 0;
        int index_1 = i;
        int max_1 = map[index_1][j];
        while (index_1 >= 0) {
            if (max_1 < map[index_1][j]) max_1 = map[index_1][j];
            index_1--;
            j++;
        }
        index_1 = i;
        j = 0;
        while (index_1 >= 0) {
            Max_Right[index_1][j] = max_1;
            index_1--;
            j++;
        }
    }
    for (int j = 1; j < 9; j++) {
        int i = 9;
        int coordinate_1 = j;
        int max_2 = map[i][coordinate_1];
        while (coordinate_1 <= 9) {
            if (max_2 < map[i][coordinate_1]) max_2 = map[i][coordinate_1];
            i--;
            coordinate_1++;
        }
        i = 9;
        coordinate_1 = j;
        while (coordinate_1 <= 9) {
            Max_Right[i][coordinate_1] = max_2;
            i--;
            coordinate_1++;
        }
    }
    // Calculate Max_Left[i][j]
    int Max_Left[10][10];
    Max_Left[0][9] = map[0][9];
    Max_Left[9][0] = map[9][0];
   for (int i = 1; i < 10; i++) {
    int j = 9;
    int index_2 = i;
    int max_3 =map[index_2][j];
    while (index_2 >= 0) {
        if (max_3 < map[index_2][j]) max_3 = map[index_2][j];
        index_2--;
        j--;
        }
    j = 9;
    index_2 = i;
    while (index_2 >= 0) {
        Max_Left[index_2][j] = max_3;
        index_2--;
        j--;
    }
   }
    
    for (int j = 8; j >= 1; j--) {
        int i = 9;
        int coordinate_2 = j;
        int max_4 = map[i][coordinate_2];
        while (coordinate_2 >= 0) {
            if (max_4 < map[i][coordinate_2]) max_4 = map[i][coordinate_2];
            i--;
            coordinate_2--;
        }
        i = 9;
        coordinate_2 = j;
        while (coordinate_2 >= 0) {
            Max_Left[i][coordinate_2] = max_4;
            i--;
            coordinate_2--;
        }
    }
    // Calculate MAP[10][10] to store the point max(Max_Right[i][j], Max_Left[i][j])
    int Map_Sherlock[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Map_Sherlock[i][j] = abs(max(Max_Left[i][j], Max_Right[i][j]));
        }
    }
    // Calculate the coordinate of the meeting of taxi, Sherlock and Watson
    int Sum_of_number_i;
    int Sum_of_number_j;
    if (check_number(positive) == true) Sum_of_number_i = positive; 
    if (check_number(positive) ==  false) {
        while(1) {
            positive = Sum_of_number(positive);
            if(check_number(positive) ==  true) break;
        }
        Sum_of_number_i = positive;
    }
    if (check_number(negative) == true) Sum_of_number_j = negative;
    if (check_number(negative) == false) {
        while(1) {
            negative = Sum_of_number(negative);
            if(check_number(negative) ==  true) break;
        }
        Sum_of_number_j = negative;
    }
    // Calculate EXP and HP after meeting
    if (abs(map[Sum_of_number_i][Sum_of_number_j]) > Map_Sherlock[Sum_of_number_i][Sum_of_number_j]) {
        EXP1 = Scale_Up(EXP1 * 0.88f);
        EXP2 = Scale_Up(EXP2 * 0.88f);
        HP1 = Scale_Up(HP1 * 0.9f);
        HP2 = Scale_Up(HP2 * 0.9f);
    }
    if(abs(map[Sum_of_number_i][Sum_of_number_j]) <= Map_Sherlock[Sum_of_number_i][Sum_of_number_j]) {
        EXP1 = Scale_Up(EXP1 * 1.12f);
        EXP2 = Scale_Up(EXP2 * 1.12f);
        HP1 = Scale_Up(HP1 * 1.1);
        HP2 = Scale_Up(HP2 * 1.1);
    }
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    HP1 = check_HP(HP1);
    HP2 = check_HP(HP2);
    // Print out the answer of task 3
    if (abs(map[Sum_of_number_i][Sum_of_number_j]) > Map_Sherlock[Sum_of_number_i][Sum_of_number_j]) {
        return map[Sum_of_number_i][Sum_of_number_j];
    }  
    else return Map_Sherlock[Sum_of_number_i][Sum_of_number_j];
}

// Task 4
bool check_length1 (string s) {
    if (s.length() < 8) return false;
    return true;
}
// Check xem do dai co > 20 hay ko. Neu co thi false, neu ko thi true
bool check_length2 (string s) {
    if (s.length() > 20) return false;
    return true;
}
// Check xem ki tu co toa hay ko. Neu co thi true, neu sai thi false
bool check_Character (string s) {
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')|| (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))   continue;
        else return false;          
    }
    return true;
}
//Xuat ra vi tri cua ki tu dac biet neu s bi sai ve character
int Result_Character(string s) {
    int locate = -1;
    for (int i = 0; i < s.length(); i++) {
       if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')|| (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))   continue;
       else {
          locate = i;
          break;
       }
    }
    return locate;
} 
// Check so ki tu dac biet. Neu dung la true, neu sai la false
bool check_NumberofSpecials (string s) {
    int count = 0 ;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') count ++;
    }
    if (count == 0) return false;
    return true;
}
// Check xem co 2 ki tu lien ke giong nhau hay ko. Neu ko thi true, neu co thi false 
bool check_SequentCharacter (string s) {
    for (int i = 0; i < s.length() - 2; i++) {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) return false;
    }
    return true;
}
// Tim location cua sequen character 
int Result_SequentCharacter (string s) {
    int res = -1;
    for (int i = 0; i < s.length() - 2; i++) {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
            res = i;
            break;
        }
    }
    return res;
}
// Check string se co trong s hay ko. Neu co thi true, neu khong thi false
bool check_SeinS (string s,string se) {
    if (se.length() > s.length()) return false;
    size_t index = s.find(se);
    if (index != string::npos) return true;
    return false;
}
// Neu se trong s, tim vi tri cua ki tu dau cua se trong s
int Result_SeinS (string s, string se) {
    int res = -1;
    string a;
    int LENGTH_S = s.length();
    int LENGTH_SE = se.length(); 
    for (int i = 0; i < (LENGTH_S - LENGTH_SE + 1); i++) {
        a = "";
        for (int j = i; j < ( LENGTH_SE +i); j++) {
            a.push_back(s[j]);
        }
        if (a == se) {
            res = i;
            break;
        }
    }
    return res;
}

int checkPassword(const char * s, const char * email) {     
    // TODO: Complete this function
    // Find string se
    string se ;
    int i = 0;
    while (email[i]!='@') {
        se.push_back(email[i]);
        i++;
    }
    int res = 0;
    // check if s is a valid password
    for (int i = 0; i < 1; i++) {
        if(check_length1(s) == true && check_length2(s) == true && check_Character(s) == true && check_SeinS(s,se) == false && check_SequentCharacter(s) == true && check_NumberofSpecials(s) == true) {
            res = -10;
            break;
        }
        else {
            //Neu s co do dai < 8, tra ve -1
            if (check_length1(s) == false) {
                res = -1;
                break;
            }
            //Neu s co do dai > 20, tra ve -2
            if (check_length2(s) == false) {
                res = -2;
                break;
            } 
            //Neu S co chua SE;
            if (check_SeinS(s,se) == true) {
                res = -(300 + Result_SeinS(s,se));
                break;
            }
            //NEU S Co cac ki tu giong nhau lien ke
            if (check_SequentCharacter(s) == false) {
                res =  -(400 + Result_SequentCharacter(s));
                break;
            }
            //Neu s ko co ki tu dac biet
            if (check_NumberofSpecials(s) == false) {
                res = -5;
                break;
            }
            // Cac truong hop tra ve gtri location
            if (check_Character(s) == false) {
                res = Result_Character(s);
                break;
            }
      }
    }
    return res;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int *count = new int[num_pwds];
    int *length = new int[num_pwds];
    for (int i = 0; i < num_pwds; i++){
        count[i] = 0;
        length[i] = 0;
    }
    // tinh so lan xuat hien cua tung xau
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i],arr_pwds[j]) == 0) count[i]++;
       }
    }
    // Tinh do dai tung xau 
    for (int i = 0; i < num_pwds; i++) {
        length[i] = strlen(arr_pwds[i]);
    }
    // tim so lan xuat hien nhieu nhat
    int max_count = -1;
    for (int i = 0; i < num_pwds; i++) {
        if (max_count < count[i]) max_count = count[i];
    }
    //uihuhaduishdi
    int len = -1;
    for (int i = 0; i < num_pwds - 1; i++) {
        if (count[i] == max_count) {
            for (int j = i + 1; j < num_pwds; j++) {
                //cout << len << " ";
                if (count[j] == max_count) {
                    //cout << len << " ";
                    if (length[i] == length[j]) continue;
                    if (length[i] > length[j]) len = max(len,length[i]);
                    if (length[i] < length[j]) len = max(len,length[j]);
                    //cout << len << " ";
                }
            }
        }
    }
    //cout << endl;
    //cout << len << endl;
    // Neu locate = -1 => co 2 truong hop
    // truong hop 1: nhung sau xuat hien nhieu lan nhat la cung 1 xau => xuat ra vi tri dau tien xuat hien sau
    // truong hop 2; nhung sau xuat hien nhieu lan nhat nhung lai la 2 sau khac nhau => xuat ra vi tri dau tien xat hien xau
    if (len == -1) {
        for (int i = 0; i < num_pwds; i++) {
            if (count[i] == max_count) {
                delete[] count;
                delete[] length;
                return i;
            };
        }   
    }
    else {
        for (int i = 0; i < num_pwds; i++) {
            if (count[i] == max_count && length[i] == len) {
                delete[] count;
                delete[] length;
                return i;
            }
        }
    }
    delete[] count;
    delete[] length;
    return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////