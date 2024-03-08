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


int limitHP(int HP)
{
    if (HP < 0) HP = 0;
    else if (HP > 666) HP = 666;
    return HP;
}
// Limit the EXP
int limitEXP(int EXP)
{
    if (EXP < 0) EXP = 0;
    else if (EXP > 600) EXP = 600;
    return EXP;
}
// Limit the Money
int limitM(int M)
{
    if (M < 0) M = 0;
    else if (M > 3000) M = 3000;
    return M;      
}
bool limitE (int E)
{
    if ( E>=0 && E<=99) return false;
    return true;

} // Limit EXP, M, HP is these value exceed their limit
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Trường Hợp 1: e1 từ 0-3
   
    if (limitE(e1)) return -99;
    else {
    limitEXP(exp1); // giới hạn lúc nhập 
    limitEXP(exp2);    
    float Exp1, Exp2;
    if ((0 <= e1) && (e1 <= 3)) {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else exp2 += 149;
        exp2=limitEXP(exp2);
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) Exp1 = ceil(exp1*1.00 + D / 200.00);
        else Exp1 = ceil(exp1*1.00- (D / 100.00));
        exp1 = limitEXP(Exp1);

    }// Trường hợp 2 e1 từ 4-99
    else {
        if ((4 <= e1) && (e1 <= 19)) {
            Exp2 = exp2 +  (e1 / 4.00 + 19.00);
            exp2 = limitEXP(ceil(Exp2));
            
        }
        else if ((20 <= e1) && (e1 <= 49)) {
            Exp2 = exp2 + (e1 / 9.00 + 21.00);
            exp2 = limitEXP(ceil(Exp2));
        }
        else if ((50 <= e1) && (e1 <= 65)) {
            Exp2 = exp2 +  (e1 / 16.00 + 17.00);
            exp2 = limitEXP(ceil(Exp2));
        }
        else if ((66 <= e1) && (e1 <= 79)) {
            Exp2 = exp2 +  (e1 / 4.00 + 19.00);
            exp2 = limitEXP(ceil(Exp2));
            if (exp2 > 200) {
                Exp2 = exp2 +  (e1 / 9.00 + 21.00);
                exp2 = limitEXP(ceil(Exp2));
            }
        }
        else if ((80 <= e1) && (e1 <= 99)) {
            Exp2 = exp2 + (e1 / 4.00 + 19.00);
            exp2 = limitEXP(ceil(Exp2));
            if (exp2 > 200){
            Exp2 = exp2 + (e1 / 9.00 + 21.00);
             exp2 = limitEXP(ceil(Exp2));
            if (exp2 > 400) {
                Exp2 = exp2 +  (e1 / 16.00 + 17.00);
                exp2 = limitEXP(ceil(Exp2));
                Exp2 = exp2 +  exp2 * 0.15;
                exp2 = limitEXP(ceil(Exp2));
            }
            }
       
          
        
        }

        exp1 = limitEXP(exp1 - e1); 
    }
    }

    return exp1 + exp2;

}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

if (limitE(E2)) return -99;
    else {
limitEXP(EXP1);
limitM(M1);
limitHP(HP1);
 float p1, p2, p3;
 float hp1, exp1 , m1;
 int M = M1, S;
 int bill = 0;
 
 int A = ceil(sqrt(EXP1));// Tìm só chính phương gần nhất 
 int B = floor(sqrt(EXP1));

 if (abs((A * A - EXP1)) < abs((B * B - EXP1)))
 {
     S = (A * A);
 }
 else {
     S = (B * B);
 }

 if (EXP1 >= S) p1 = 100; // tính tỉ lệ sherlocks tìm thấy vali trên đường này P1
 else p1 = (((EXP1 / S) + 80.0) / 123.0) * 100;
 //Road 2
 if (E2 % 2 == 1) {    //Trường hợp E2 lẻ
     do {
         // Mua đồ ăn
         HP1 = limitHP(HP1);
         if (HP1 < 200) {
             HP1 = (HP1 * 1.3) + 0.99999;
             M1 -= 150; bill += 150;
         }
         else {
             HP1 = (HP1 * 1.1) + 0.99999;
             M1 -= 70; bill += 70;
         }
         HP1 = limitHP(HP1);
         M1 = limitM(M1);
         if (bill > 0.5 * M) // kiểm tra tiền đã tiêu có lớn hơn tiền ban đầu
             break;
         //Đi xe
         if (EXP1 < 400) {
             M1 -= 200; bill += 200;
         }
         else {
             M1 -= 120; bill += 120;
         }
         exp1  = ceil(EXP1 * 1.13);
         EXP1 = limitEXP(exp1);
         M1 = limitM(M1);
         if (bill > 0.5 * M)
             break;
         // Người vô gia cư
         if (EXP1 < 300) {
             M1 -= 100; bill += 100;
         }
         else {
             M1 -= 120; bill += 120;
         }
         exp1  = ceil(EXP1 * 0.9);
         M1 = limitM(M1);
         EXP1 = limitEXP( exp1 );
         if (bill > 0.5 * M)
             break;
     } while (bill < 0.5 * M);
 }
 else { // Trường hợp e2 chẵn và ngắt khi m1 = 0
     // Mua đồ ăn
    while(M>0){
    if (HP1 < 200) {
        HP1 = (HP1 * 1.3) + 0.99999;
        M1 -= 150;
    }
     else {
        HP1 = (HP1 * 1.1) + 0.99999;
        M1 -= 70;
    }
    HP1 = limitHP(HP1);
    M1 = limitM(M1);
    if (M1 == 0)
        break;
     //Đi xe
    if (EXP1 < 400) {
        M1 -= 200;
     }
     else {
        M1 -= 120;
     }
    exp1  = ceil(EXP1 * 1.13);
    EXP1 = limitEXP( exp1 );
    M1 = limitM(M1);
    if (M1 == 0)
        break;
     // Người vô gia cư
    if (EXP1 < 300) {
         M1 -= 100;
    }
    else {
         M1 -= 120;
    }
    exp1  = ceil(EXP1 * 0.9);
    M1 = limitM(M1);
    EXP1 = limitEXP(exp1 );
    break;
 }
 }
HP1 = (HP1 * 0.83) + 0.99999;
exp1 = (ceil(EXP1  * 1.17));
HP1 = limitHP (HP1);
EXP1 = limitEXP(exp1);

float C = ceil(sqrt(EXP1)); // Tìm só chính phương gần nhất 
float D = floor(sqrt(EXP1));
if (abs((C * C - EXP1)) < abs((D * D - EXP1)))
    {
        S = (C * C);
    }
else {
        S = (D * D);
}
if (EXP1 >= S) p2 = 100; // tính tỉ lệ sherlocks tìm thấy vali trên đường này P2
else p2 = (((EXP1 / S) + 80.0) / 123.0) * 100;

 //Road 3
int i = 0;
int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
if (E2 < 10) {
     i = E2;
 }
 else {
     int hangchuc = E2 / 10;
     int hangdonvi = E2 % 10;
     i = (hangchuc + hangdonvi) % 10;
 }
 p3 = P[i];
 // Tính tỉ lệ của 3 con đường 

 if (p1 ==100 && p2 == 100 && p3 == 100) {
     exp1  = ceil(EXP1 * 0.75);
     EXP1 = limitEXP(exp1 );

 }
 else {
     double  avgP = (p1 + p2 + p3) / 3.00;
     if (avgP < 50) {
         HP1 = limitHP((HP1 * 0.85) + 0.99999);
         EXP1 = limitEXP(ceil(EXP1 * 1.15));
     }
     else {
         HP1 = limitHP((HP1 * 0.90) + 0.99999);
         EXP1 = limitEXP(ceil(EXP1 * 1.20));
     }

 }
    }
 return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
if (limitE(E3)) return -99;
    else {
EXP1 = limitEXP(EXP1);
EXP2 = limitEXP(EXP2);
HP1 = limitHP(HP1);
HP2 = limitHP(HP2);

int matrix[10][10]={0}; 
for (int i=0; i<10; i++) {
for (int j=0; j<10; j++) {
    matrix[i][j]=(( E3*j)+(i*2))*(i-j);
    }
}
    
    int a=0, b=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if((matrix[i][j] > 0)&&(matrix[i][j]>( E3 * 2))) a+=1; // kiểm tra số lượng a số lớn hơn 0
            if(((matrix[i][j]) < 0)&&(matrix[i][j]<(- E3))) b+=1;// kiểm tra số lượng b số bé hơn 0
            
        }
    }
    a=a/10 + a%10;
    a=a/10 + a%10; // tính tổng của hàng đơn vị và hàng chục của số số dương
    b=b/10 + b%10;
    b=b/10 + b%10;// tính tổng hàng đơn vị và hàng chục của số số dương
   
    int Maxmatrix= matrix[a][b];
    
    int z=b, x=b, c=b, v=b;
 
    for(int i=(a + 1); i < 10; i++){ 
    if(z > 0) {
    z--;        
    if (matrix[i][z] > Maxmatrix)  {
    Maxmatrix = matrix[i][z];     
    }
        }
        if(x < 9) {
            x++;
            if (matrix[i][x] > Maxmatrix)  {
                Maxmatrix = matrix[i][x];                
            }
        }        
    } 
    for(int i=(a - 1); i > (-1); i--){ 
        if(c>0) {
            c--;
            
            if (matrix[i][c] > Maxmatrix)  {
                Maxmatrix = matrix[i][c];                
            }            
        }
        if(v<9) {
            v++;            
            if (matrix[i][v] > Maxmatrix)  {
                Maxmatrix = matrix[i][v];                
            }            
        }
        
    }
    if( abs(matrix[a][b]) > Maxmatrix) {
         EXP1 = 0.88* EXP1 + 0.99999;
         EXP2= 0.88* EXP2 + 0.99999;
         HP1= 0.9* HP1 + 0.99999;
         HP2= 0.9* HP2 + 0.99999;
        EXP1 = limitEXP(EXP1);
        HP1 = limitHP(HP1);
        EXP2 = limitEXP(EXP2);
        HP2 = limitHP(HP2);
        return matrix[a][b];
    }
    
    else {
         EXP1 = 1.12* EXP1 + 0.99999;
         EXP2= 1.12* EXP2 + 0.99999;
         HP1= 1.1* HP1 + 0.99999;
         HP2= 1.1* HP2 + 0.99999;
        EXP1 = limitEXP(EXP1);
        HP1 = limitHP(HP1);
        EXP2 = limitEXP(EXP2);
        HP2 = limitHP(HP2);
        return Maxmatrix;
    }
    


    
    return -1;
    }
}
   
  

// Task 4
// Task 4
int checkPassword(const char* s, const char* email) {
    int n, a;
    string EMAIL(email);
    n = strlen(s);
    string se = EMAIL.substr(0, EMAIL.find('@'));
    //Kiểm tra nếu vượt quá độ dài cho phép 
    if (n < 8) return -1;
    if (n > 20) return -2;
    //Gán chuỗi đằng trước kí tự @ trong email cho biến se


    //Kiểm tra nếu có chuỗi se trong s
    if (strstr(s, se.c_str()) != NULL) {
        const char* p = strstr(s, se.c_str()); //Lấy vị trí đầu tiên nếu bị trùng
        int i = p - s;
        return -(300 + i);
    }

    //Kiểm tra có lớn hơn 2 kí tự liên tiếp có giống nhau ko
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);

        }
    }
    //Kiểm tra nếu có kí tự @ # % ! $ ko
    bool b = false;
    for (int i = 0; i < n; i++) {
        char j = s[i];
        if (j == '@' || j == '#' || j == '%' || j == '!' || j == '$') b = true;
    }
    if (!b) return -5;

    //Kiểm tra nếu có ký tự không hợp lệ
    for (int i = 0; i < n; i++) {
        char j = s[i];
        if (j != '@' && j != '#' && j != '%' && j != '!' && j != '$' && (j < '0' || j > '9') && (j < 'a' || j > 'z') && (j < 'A' || j > 'Z'))
            return i;
    }

    //Các hàm kiểm tra đều sai thì MK hợp lệ 
    return -10;
}




// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // Kiểm tra trường hợp đặc biệt
    if (num_pwds <= 0 || arr_pwds == nullptr) {
        return -1; // Trả về giá trị không hợp lệ nếu không có mật khẩu nào
    }

    int max_count = 0;
    int max_length = 0;
    int result_index = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* current_pwd = arr_pwds[i];
        int current_length = std::strlen(current_pwd);
        int current_count = 0;

        for (int j = 0; j < num_pwds; ++j) {
            if (i != j && std::strcmp(current_pwd, arr_pwds[j]) == 0) {
                current_count++;
            }
        }

        if (current_count > max_count || (current_count == max_count && current_length > max_length)) {
            max_count = current_count;
            max_length = current_length;
            result_index = i;
        }
    }

    return result_index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////