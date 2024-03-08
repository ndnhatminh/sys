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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<4 && e1>=0){
    switch(e1)
    {
        case 0: exp2 += 29; break;
        case 1: exp2 += 45; break;
        case 2: exp2 += 75; break;
        case 3: exp2 += 149; break;
    }
    int D = e1*3+ exp1*7;
    if (D % 2 == 0) {
        float fexp1 = exp1 + D /200.0;
        exp1 = ceil(fexp1);
    } else {
        float fexp1 = exp1 - D /100.0;
        exp1 = ceil(fexp1);
    }}
    else{
        if (e1 >= 4 && e1 <= 19) {
        exp2 += ceil((e1 / 4.0) + 19);
        exp1 = exp1 - e1;
        } else if (e1 >= 20 && e1 <= 49) {
        exp2 += ceil((e1 / 9.0) + 21);
        exp1 = exp1 - e1;
        } else if (e1 >= 50 && e1 <= 65) {
        exp2 += ceil((e1 / 16.0) + 17);
        exp1 = exp1 - e1;
        } else if (e1 >= 66 && e1 <= 79) {
        exp2 += ceil((e1 / 4.0) + 19);
        exp1 = exp1 - e1;
        if (exp2 > 200) {
            exp2 += ceil((e1 / 9.0) + 21);
                        }
        } else if (e1 >= 80 && e1 <= 99) {
        exp2 += ceil((e1 / 4.0) + 19);
        exp2 += ceil((e1 / 9.0) + 21);
        exp1 = exp1 - e1;
        if (exp2 > 400) {
            exp2 += ceil((e1 / 16.0) + 17);
            exp2 += ceil(exp2*0.15);
                        }
        } else{
            return -99;
        }
    }
    exp1 = std::min(std::max(exp1, 0), 600);
    exp2 = std::min(std::max(exp2, 0), 600);
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 >= 0 && E2 <100){
   double P1;
   int S1 = round(sqrt(EXP1))*round(sqrt(EXP1));
   if(EXP1>=S1){
    P1 = 1.0;
   } else {
    P1 = (double(EXP1)/S1+80.0)/123.0;
   }
double P2;
int money = M1*0.5;
if(M1>0){
if(E2%2==0){
    if(HP1<200){
        HP1 = 1.3*HP1+0.999;
        EXP1 = std::min(std::max(EXP1, 0), 600);
        HP1 = std::min(std::max(HP1, 0), 666);
        M1 -= 150;
    }else {
        HP1 = 1.1*HP1+0.999;
        EXP1 = std::min(std::max(EXP1, 0), 600);
        HP1 = std::min(std::max(HP1, 0), 666);
        M1 -= 70;
    }
    if(M1>0){
    if(EXP1>400){
        M1 -=120;
    } else{
        M1 -= 200;
    }
    EXP1 = 1.13*EXP1+0.999;
    EXP1 = std::min(std::max(EXP1, 0), 600);
    HP1 = std::min(std::max(HP1, 0), 666);  
    }
    if(M1>0){
    if(EXP1<300){
        M1 -= 100;
    } else{
        M1 -= 120;
    }
    EXP1 = 0.9*EXP1+0.999;
    }
}else{
    while(M1>money)
    {
       if(HP1<200){
        HP1 = 1.3*HP1+0.999;
        EXP1 = std::min(std::max(EXP1, 0), 600);
        HP1 = std::min(std::max(HP1, 0), 666);
        M1 -= 150;
    }else {
        HP1 = 1.1*HP1+0.999;
        EXP1 = std::min(std::max(EXP1, 0), 600);
        HP1 = std::min(std::max(HP1, 0), 666);
        M1 -= 70;
    }
    if(M1<money){break;}
    if(EXP1>400){
        M1 -=120;
    } else{
        M1 -= 200;
    }
    EXP1 = 1.13*EXP1+0.999;
    EXP1 = std::min(std::max(EXP1, 0), 600);
    HP1 = std::min(std::max(HP1, 0), 666); 
    if(M1<money){break;}
    if(EXP1<300){
        M1 -= 100;
    } else{
        M1 -= 120;
    }
    EXP1 = 0.9*EXP1+0.999; 
    if(M1<1){break;}
    } 
} 
}  
M1 = std::min(std::max(M1, 0), 3000);
EXP1 = 1.17*EXP1+0.999;
HP1 = 0.83*HP1+0.999;
EXP1 = std::min(std::max(EXP1, 0), 600);
HP1 = std::min(std::max(HP1, 0), 666);
int S2 = round(sqrt(EXP1))*round(sqrt(EXP1));
   if(EXP1>=S2){
    P2 = 1.0;
   } else {
    P2 = (double(EXP1)/S2+80.0)/123.0;
   }
int P[10]={32,47,28,79,100,50,22,83,64,11};
double P3;
if(E2/10 < 1){
    P3 = P[E2]/100.0;
} else {
    int sum = E2/10 + E2%10;
    if(sum/10 < 1){
        P3 = P[sum]/100.0;
    }else{
        P3 = P[sum%10]/100.0;
    }
}
if(P1==P2&&P2==P3&&P3==1.0)
{
    EXP1 = EXP1*0.75+0.999;
    return HP1 + EXP1 + M1;
}

if((P1+P2+P3)/3>=0.5){
   EXP1 = 1.2*EXP1+0.999;
   HP1 = 0.9*HP1 + 0.999; 
} else {
   EXP1 = 1.15*EXP1+0.999;
   HP1 = 0.85*HP1+0.999; 
}
EXP1 = std::min(std::max(EXP1, 0), 600);
HP1 = std::min(std::max(HP1, 0), 666);
    return HP1 + EXP1 + M1;
    } else {
    return -99;
  }
}


// Task 3
int calculateTaxiSkill(int i, int j, int E3) {
    return ((E3 * j) + (i * 2)) * (i - j);
}
int findMax(int arr[], int size) {
    int max = arr[0]; // Giả sử phần tử đầu tiên là số lớn nhất

    for (int i = 1; i < size; ++i) {
        // So sánh từng phần tử với số lớn nhất hiện tại
        if (arr[i] > max) {
            max = arr[i]; // Cập nhật số lớn nhất nếu phần tử mới lớn hơn
        }
    }

    return max;
}
int findMaxnum(int a, int b, int c) {
    int maxnum = a; // Giả sử số đầu tiên là số lớn nhất

    // So sánh số đầu tiên với số thứ hai
    if (b > maxnum) {
        maxnum = b; // Cập nhật số lớn nhất nếu số thứ hai lớn hơn
    }

    // So sánh số lớn nhất với số thứ ba
    if (c > maxnum) {
        maxnum = c; // Cập nhật số lớn nhất nếu số thứ ba lớn hơn
    }

    return maxnum;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 >= 0 && E3 < 100){
     const int ROWS = 10;
     const int COLS = 10;

    // Khởi tạo ma trận taxi và ma trận điểm của Sherlock và Watson
    int taxiMatrix[ROWS][COLS] = {0};
    // Tính điểm số cho mỗi ô trong ma trận taxi
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            taxiMatrix[i][j] = calculateTaxiSkill(i, j, E3);
        }
    }
    int count_i =0;
    int count_j = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if(taxiMatrix[i][j] > E3*2)
            count_i ++;
            if(taxiMatrix[i][j] < -E3)
            count_j ++;
        }
    }
    while(count_i>9){
      count_i = count_i/10+ count_i%10;
    }
    while(count_j>9){
      count_j = count_j/10+ count_j%10;
    }
    int max[10]= {0};
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if(i+j==count_i+count_j){
                  max[i] = taxiMatrix[i][j];    
                  }
            }
        }
int max2[10]= {0};
for (int i = count_i, j = count_j; i < ROWS && j < COLS; ++i,++j) {
                  max2[i] = taxiMatrix[i][j];    
                  }
int max3[10]= {0};
for (int i = count_i,j = count_j; i >=0 && j >=0; --i,--j) {
                  max3[i] = taxiMatrix[i][j];    
                  }     
int ans1 = findMax(max,10);
int ans2 = findMax(max2,10);
int ans3 = findMax(max3,10);
int rs = findMaxnum(ans1, ans2, ans3);
if(abs(taxiMatrix[count_i][count_j])> rs)
{
   EXP1 = EXP1*0.88 + 0.999;
   EXP2 = EXP2*0.88+0.999;
   HP1 = HP1*0.9+0.999;
   HP2 = HP2*0.9+0.999;
   EXP1 = std::min(std::max(EXP1, 0), 600);
   HP1 = std::min(std::max(HP1, 0), 666);
   EXP2 = std::min(std::max(EXP2, 0), 600);
   HP2 = std::min(std::max(HP2, 0), 666);
   return taxiMatrix[count_i][count_j];
} else {
   EXP1 = EXP1*1.12+0.999;
   EXP2 = EXP2*1.12+0.999;
   HP1 = HP1*1.1+0.999;
   HP2 = HP2*1.1+0.999;
   EXP1 = std::min(std::max(EXP1, 0), 600);
   HP1 = std::min(std::max(HP1, 0), 666);
   EXP2 = std::min(std::max(EXP2, 0), 600);
   HP2 = std::min(std::max(HP2, 0), 666);
   return rs;
}
} else {
     return -99;
    }
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
     // Kiểm tra độ dài mật khẩu
    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;
    // Tách phần se từ email
    std::string se = "";
    int i = 0;
    while (email[i] != '@') {
        se += email[i];
        i++;
    }
    // Kiểm tra chuỗi "se"
    const char* SE = se.c_str();
    const char *search = strstr(s, SE);
    if (search != nullptr) {
        return -(300 + (search - s));
    }
    // Kiểm tra nhiều hơn 2 ký tự liên tiếp và giống nhau
   for (int i = 0; i < len - 1; ++i) {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2])) {
            // Có nhiều hơn 2 ký tự giống nhau
            return -(400 + i);
        }
    }
    // Kiểm tra ký tự đặc biệt
    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            // Ký tự là chữ cái hoặc chữ số
            continue;
        } else if (s[i] == '@' || s[i] == '#' || s[i] == '%' ||
                   s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;
        } 
    }
    if (!hasSpecialChar) return -5;
    for (int i = 0; i < len; ++i) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            // Ký tự là chữ cái hoặc chữ số
            continue;
        } else if (s[i] == '@' || s[i] == '#' || s[i] == '%' ||
                   s[i] == '$' || s[i] == '!') {
                    continue; 
        }else{
            return i;
        } 
    }

    return -10; // Mật khẩu hợp lệ
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
  int passwordCount[num_pwds];
    for (int i = 0; i < num_pwds; ++i) {
        passwordCount[i] = 0;
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (passwordCount[i] == -1) {
            continue;
        }
        passwordCount[i] = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (std::strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                passwordCount[i]++;
                passwordCount[j] = -1;
            }
        }
    }

    int maxCount = 0;
    int maxLength = 0;
    int correctPasswordIndex = -1;
    for (int i = 0; i < num_pwds; ++i) {
        if (passwordCount[i] > maxCount || (passwordCount[i] == maxCount && std::strlen(arr_pwds[i]) > maxLength)) {
            maxCount = passwordCount[i];
            maxLength = std::strlen(arr_pwds[i]);
            correctPasswordIndex = i;
        }
    }

    return correctPasswordIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////