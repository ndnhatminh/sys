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
void checkMax(int &a, int b) {
    if (a > b) 
        a = b;
}
void checkMin (int &c, int d) {
    if (c < d)
        c = d;
}
int maxHP = 666;
int minHP = 0;
int maxEXP = 600;
int minEXP = 0;
int maxM = 3000;
int minM = 0;
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
if (e1 > 99)
    return -99;
if (e1 < 0)
    return -99;
    // TH1

checkMax (exp2, maxEXP);
checkMin (exp2, minEXP);
checkMax (exp1, maxEXP);
checkMin (exp1, minEXP);

if (e1 >= 0 && e1 <= 3) 
{
if (e1 == 0)
    exp2 = exp2 + 29;
else if (e1 == 1)
    exp2 = exp2 + 45;
else if (e1 == 2)
    exp2 = exp2 + 75;
else if (e1 == 3)
    exp2 = exp2 + 29 + 45 + 75;
int D;
D = ((double)e1 * 3 + (double)exp1 * 7) + 0.9999;
    if (D % 2 == 0)
        exp1 = ((double)exp1 + D / 200) + 0.9999;
    else exp1 = ((double)exp1 - D / 100) + 0.9999; 
}

checkMax (exp2, maxEXP);
checkMin (exp2, minEXP);
checkMax (exp1, maxEXP);
checkMin (exp1, minEXP);

// TH2
if (e1 >= 4 && e1 <= 99) 
{
    if (e1 >= 4 && e1 <=19)
        exp2 = (double)exp2 + ((double)e1/4 +19) + 0.9999;
    else if (e1 >=20 && e1 <= 49)
        exp2 = (double)exp2 + ((double)e1/9 +21) + 0.9999;
    else if (e1 >= 50 && e1 <= 65)
        exp2 = (double)exp2 + ((double)e1/16 + 17) + 0.9999;
    else if (e1 >= 66 && e1 <= 79)
{
        exp2 = (double)exp2 + ((double)e1/4 +19) + 0.9999;
    if (exp2 > 200) 
        {
            exp2 = (double)exp2 + ((double)e1/9 + 21) + 0.9999;
        }
}   
    else if (e1 >= 80 && e1 <= 99)
{
        exp2 = ((double)exp2 + (double)(e1/4 + 19) + (double)(e1/9 + 21)) + 0.9999;
    if (exp2 > 400) 
        {
            exp2 = ((double)exp2 + ((double)e1/16 + 17)) + 0.9999;
            exp2 = ((double)exp2 * 1.15) + 0.9999;
        }
}
checkMax(exp2, maxEXP);
checkMin(exp2, minEXP);

                exp1 = exp1 - e1;

checkMin(exp1, minEXP);
}

 // Trả về result           
    return (exp1 + (double)exp2) + 0.99999;
} 

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
// TODO: Complete this function
if (E2 > 99) 
    return -99;
else if (E2 < 0)
    return -99;
    // CON DUONG 1
    
    // Xác định số chính phương gần nhất EXP1
int S;
double T;
T = round(sqrt(EXP1));
S = T * T;
double P1;
if (EXP1 >= S) 
    P1 = 100;
else 
    P1 = ((double)EXP1/(double)S + 80)/123;
    
    // CON DUONG 2
int halfmoney;
halfmoney = M1/2;
// E2 lẻ
if (E2 % 2 != 0) {
    do {

checkMax(HP1, maxHP);
checkMin(HP1, minHP);
checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(EXP1, maxEXP);
checkMin(EXP1, minEXP);

      // Chấm số 1  
        if (HP1 < 200) 
            {
                HP1 = ((double)HP1 * 1.3) + 0.9999;
                M1 = M1 - 150;
            } 
        else if (HP1 >= 200) 
            {
                HP1 = ((double)HP1 * 1.1) + 0.9999;
                M1 = M1 - 70;
            } 
                        if (M1 < halfmoney) {
                            break;
                        }
        
checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(HP1, maxHP);
checkMin(HP1, minHP);

      // Chấm số 2  
        if (EXP1 < 400) 
            {
                M1 = M1 - 200;
            } 
        else if (EXP1 >= 400) 
            {
                M1 = M1 - 120;
            } 
    EXP1 = (1.13 * (double)EXP1) + 0.9999; 
                        
                        if (M1 < halfmoney) {
                            break;
                        }
    
checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(EXP1, maxEXP);
checkMin(EXP1, minEXP);

      // Chấm số 3  
        if (EXP1 < 300) 
            {
                M1 = M1 - 100;
            } 
        else if (EXP1 >= 300) 
            {
                M1 = M1 - 120;
            } 
    EXP1 = ((double)EXP1 * 0.9) + 0.9999;  
                        
                        if (M1 < halfmoney) {
                            break;
                        }

checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(EXP1, maxEXP);
checkMin(EXP1, minEXP);
     
} while (M1 >= halfmoney); 
}   
// E2 chẵn
if (M1 != 0) {
    if (E2 % 2 == 0) 
        {

checkMax(HP1, maxHP);
checkMin(HP1, minHP);
checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(EXP1, maxEXP);
checkMin(EXP1, minEXP);

        // chấm 1
            if (HP1 < 200) 
                {
                    HP1 = ((double)HP1 * 1.3) + 0.9999;
                    M1 = M1 - 150;
                } 
            else if (HP1 >= 200) 
                {
                    HP1 = ((double)HP1 * 1.1) + 0.9999;
                    M1 = M1 - 70;
                } 

checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(HP1, maxHP);
checkMin(HP1, minHP);

        //chấm 2                
            if (EXP1 < 400) 
                {
                    M1 = M1 - 200;
                } 
            else if (EXP1 >= 400) 
                {
                    M1 = M1 - 120;
                } 
    EXP1 = (1.13 * (double)EXP1) + 0.9999;

checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(EXP1, maxEXP);
checkMin(EXP1, minEXP);
            
        // chấm 3
            if (EXP1 < 300) 
                {
                    M1 = M1 - 100;
                } 
            else if (EXP1 >= 300) 
                {
                    M1 = M1 - 120;
                } 
    EXP1 = ((double)EXP1 * 0.9) + 0.9999;

checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(EXP1, maxEXP);
checkMin(EXP1, minEXP);

    }
  }
// Trả về EXP1 & HP1 final con đường 2
EXP1 = ((double)EXP1 * 1.17) + 0.9999;
HP1 = ((double)HP1 * 0.83) + 0.9999;

checkMax(EXP1, maxEXP);
checkMin(EXP1, minEXP);
checkMax(HP1, maxHP);
checkMin(HP1, minHP);

// Xác xuất của con đường 2
double P2;
S = pow(round(sqrt(EXP1)), 2);
if (EXP1 >= S) 
    P2 = 100;
else 
    P2 = ((double)EXP1/(double)S + 80)/123;
// CON DUONG 3
int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int i;
    if (E2 < 10) {
        i = E2;
    } else {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    } 

// Xác suất của con đường 3
double P3;
    P3 = P[i];

// Xac suat cua 3 duong
double Pt;
if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ((double)EXP1 * 0.75) + 0.9999;
} else if (P1 != 100 || P2 != 100 || P3 != 100) {
        Pt = (P1 + P2 + P3)/3;
}
if (Pt < 50) {
        EXP1 = ((double)EXP1 * 1.15) + 0.9999;
        HP1 = (HP1 - HP1 * 0.1) + 0.9999;
} else if (Pt > 50) {
        EXP1 = ((double)EXP1 * 1.2) + 0.9999;
        HP1 = ((double)HP1 * 0.9) + 0.9999;
}

{
checkMax(HP1, maxHP);
checkMin(HP1, minHP);
checkMax(M1, maxM);
checkMin(M1, minM);
checkMax(EXP1, maxEXP);
checkMin(EXP1, minEXP);
}

    return HP1 + EXP1 + M1;
     
} 

// Task 3
int cn(int a) {
    int b = 0;

while (a > 0) {
    b += a%10;
    a = a/10;
}

    if (b > 9) {
        return cn(b);
    }
    else return b;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // Điều kiện cho EXP1,2 & HP1,2 & E3
    

    checkMax(EXP2, maxEXP);
    checkMin(EXP2, minEXP);
    checkMax(EXP1, maxEXP);
    checkMin(EXP1, minEXP);
    checkMax(HP1, maxHP);
    checkMin(HP1, minHP);
    checkMax(HP2, maxHP);
    checkMin(HP2, minHP);

    if (E3 > 99) {
        return -99; }
    else if (E3 < 0) {
        return -99;
    }
    // Start
    
    // Tạo ma trận 10x10 
    int diemtaxi[10][10];

    // Tính giá trị cho từng phần tử của mảng

    int a = 0; int h = 0; int max = 0;
    
    

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            diemtaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (diemtaxi[i][j] > E3 * 2) 
                   a++; 
                    else if (diemtaxi[i][j] < (E3 * -1))
                        h++;
                }
        }
    
    a = cn(a);
    h = cn(h);
    int maxXe = diemtaxi[a][h];

    if ( a <= h) {
        int j = h;
            for (int i = a; i < 10; i++) {
                if (diemtaxi[i][j] > max) {
                    max = diemtaxi[i][j];
                        j--;
                }
                    if (j < 0)
                        break;
            }
    } else {
    // cheotrai 
    int d = a - h;   
        for (int j = 0; d < 10; j++) {
            if (diemtaxi[d][j] > max) 
                max = diemtaxi[d][j];
                d++;
        }
    //cheophai
    int tong = a + h;
            if (tong <= 9) {
                int j = 0;
                    for (int i = tong; i >= 0; i--) {
                        if (diemtaxi[i][j] > max) 
                            max = diemtaxi[i][j];
                            j++;
                        }
                    }
             
       else {
            int j = tong - 9;
            for (int i = 9; j < 10; i--) {
                if (diemtaxi[i][j] > max) {
                    max = diemtaxi[i][j];
                    j++;
                }
            } 
        }
    }

if (abs(maxXe) > max) {
    EXP1 = (double)EXP1 * 0.88 + (EXP1%25!=0);
    EXP2 = (double)EXP2 * 0.88 + (EXP2%25!=0);
    HP1 = (double)HP1 * 0.9 + (HP1%10!=0);
    HP2 = (double)HP2 * 0.9 + (HP2%10!=0);

checkMax (EXP1, maxEXP);
checkMax (EXP2, maxEXP);
checkMax (HP1, maxHP);
checkMax (HP2, maxHP);
    
    return maxXe;
}
    else {
        EXP1 = (double)EXP1 * 1.12 + (EXP1%25!=0);
        EXP2 = (double)EXP2 * 1.12 + (EXP2%25!=0);
        HP1 = (double)HP1 * 1.1 + (HP1%10!=0);
        HP2 = (double)HP2 * 1.1 + (HP2%10!=0);

    checkMax (EXP1, maxEXP);
    checkMax (EXP2, maxEXP);
    checkMax (HP1, maxHP);
    checkMax (HP2, maxHP);

        return max;
    }
}    


// Task 4

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
string str = s;
string str1 = email;
string se = str1.substr(0, str1.find('@'));
// Check độ dài 
    if (str.length() < 8) {
        return -1;
    }   if (str.length() > 20) {
            return -2;
        }  
// Check s chứa se
    size_t sei = str.find(se);

        if (sei != std::string::npos)
            return -(300 + sei);

// Check 2 kí tự giống nhau liên tiếp trong s
int k = str.length();
int sci = -1;

    for (int i = 0; i < k; i++) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2])
            sci = i;
                break;
        return -(400 + i);
    }

// Check 5 kí tự đặc biệt
bool ktdb = false;
    for (char c : str) {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
            return ktdb = true;
                break;
    }
    if (!ktdb)
        return -5;

// Check các th còn lại
for (int i = 0; i < str.length(); i++) {
    char c = str[i];
        if (!((c >= 'a' && c <= 'z') || (c >='0' && c <= '9') || (c >= 'A' && c <= 'Z')) || (c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))
            return i;
    }
return -10;
return -99;
}

// Task 5
#include <unordered_map>
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    int firstCorrectPasswordIndex = 0;
    std::unordered_map <std::string, int> passcount;

    // Đếm số lần xuất hiện của pw
    for (int i = 0; i < num_pwds; i++) {
        const std::string& pw = arr_pwds[i];
        passcount[pw]++;
    }

    // Tìm pw xuất hiện nhiều nhất và có độ dài lớn nhất
    for (int i = 0; i < num_pwds; i++) {
        const std::string& password = arr_pwds[i];
        int count = passcount[password];
        int length = password.length();

        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            firstCorrectPasswordIndex = i;
        }
    }
    return firstCorrectPasswordIndex;
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

