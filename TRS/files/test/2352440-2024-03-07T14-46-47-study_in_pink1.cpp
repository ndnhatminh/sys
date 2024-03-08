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

int check_condition (int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3){
  
    HP1 = max(0, min(HP1, 666));
    HP2 = max(0, min(HP2, 666));

    EXP1 = max(0, min(EXP1, 600));
    EXP2 = max(0, min(EXP2, 600));

    M1 = max(0, min(M1, 3000));
    M2 = max(0, min(M2, 3000));

    if (E1 < 0 || E1 > 99) E1 = -99;
    if (E2 < 0 || E2 > 99) E2 = -99;
    if (E3 < 0 || E3 > 99) E3 = -99;

    return HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);
    
    if (e1 >= 0 && e1 <=3){
        if (e1 == 0) exp2 = exp2 + 29;
        else if (e1 == 1) exp2 = exp2 + 45;       
        else if (e1 == 2) exp2 = exp2 + 75;
        else exp2 = exp2 + 29 + 45 + 75;
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1 + D/200.0);
        else exp1 = ceil(exp1 - D/100.0);        
        }

     else if (e1 >= 4 && e1 <=99) {
        if ( e1 >= 4 && e1<= 19) exp2 = ceil(exp2 + e1/4.0 + 19);
        if ( e1 >= 20 && e1 <= 49) exp2 = ceil(exp2 + e1/9.0 + 21);
        if ( e1 >= 50 && e1 <= 65) exp2 = ceil(exp2 + e1/16.0 + 17);
        if ( e1 >= 66 && e1 <= 79) {
          exp2 = ceil (exp2 + (e1/4.0 + 19));
          if (exp2 > 200) exp2 = ceil(exp2 + (e1/9.0 + 21));
        }
        if (  e1 >= 80 && e1<= 99) {
            exp2 = ceil (exp2 + (e1/4.0 + 19));
            exp2 = ceil(exp2 + (e1/9.0 + 21));
          
          if (exp2 > 400) {
            exp2 = ceil(exp2 + e1/16.0 + 17);
            exp2 = ceil(exp2*1.15);      
          }           
        }  
        exp1 = exp1 - e1;                      
    }
    else return e1 = -99; 

    check_condition (HP1,  HP2,  exp1, exp2, M1,  M2,  e1, E2,  E3);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int HP2, EXP2, M2, E1, E3;
    int s1, s2; // s la so chinh phuong gan voi EXP1
    float p1, p2, p3, m1, s_exp1, s_s1, s_s2;

    check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);
    if (E2 < 0 || E2 > 99) return E2 = -99;

    
    s1 = pow(round(sqrt(EXP1)),2);
    s_s1 = s1;
    s_exp1 = EXP1;
    if (s_exp1 >= s_s1) p1 = 1;
    else p1 = (s_exp1/s_s1 + 80.0)/123.0;
    m1 = M1*0.5;
   
    if(M1 > m1){
        while (M1 > m1){
            if (HP1 < 200) {
                HP1 = ceil(HP1*1.3);
                M1 = M1 - 150;
            } else {
                HP1 += ceil(HP1*0.1);
                M1 = M1 - 70;            
            }
            check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);
            if(M1 < m1 && E2%2 != 0|| M1 <= 0 ) break;
        
            if(EXP1 < 400) M1 = M1 - 200;               
            else M1 = M1 - 120;          
            EXP1 += ceil(EXP1*0.13);
            check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);
            if(M1 < m1 && E2%2 != 0 || M1 <= 0 ) break;

            
            if(EXP1 <300) M1 = M1 - 100; 
            else M1 = M1 - 120;
            EXP1 = ceil(EXP1*0.9);
            check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);
             if(M1 < m1 && E2%2 != 0 || M1 <= 0 ) break;
             
            if(E2 % 2 == 0) break;       
        }
    } 

    check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);

    HP1 = ceil(HP1*0.83);
    EXP1 = ceil(EXP1*1.17);  
    check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);
       
    s2 = pow(round(sqrt(EXP1)),2);
    s_s2 = s2;
    s_exp1 = EXP1; 
    if (s_exp1 >= s_s2) p2 = 1; 
    else p2 = (s_exp1/s_s2 + 80.0)/123.0;
    
    float P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 10){
        int i = (E2/10 + E2%10);
        if (i >= 10) {
            i = i%10;
            p3 = P[i]/100.0;
        }
        else p3 = P[i]/100.0;
    }
    else p3 = P[E2]/100.0;
    
    float p = (p1 + p2 + p3)/3.0;
     if (p == 1.0) EXP1 = ceil(EXP1*0.75);
    else{
        if(p < 0.5) {
            HP1 = ceil(HP1 - HP1*.15);
            EXP1 = ceil(EXP1*1.15);
        }
        else {
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*1.2);
        }
    }
    check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
     int M1, M2, E1, E2;
    int taxi_vitri[10][10];
    int SherWat_vitri[10][10];
    int diemgapI = 0;
    int diemgapJ = 0; 
 check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);
 if (E3 < 0 || E3 > 99) return E3 = -99;

    // Tinh diem taxi  
    for (int i = 0; i < 10; ++i) 
        for (int j = 0; j < 10; ++j) 
            taxi_vitri[i][j] = (((E3*j) + i*2) * (i - j));            
               
    // Tinh diem Sherlock va Watson
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int max_d_chtrai = taxi_vitri[i][j];
            int max_d_chphai = taxi_vitri[j][i];
            for (int k = 0; k < 10; k++) {
                if (i + k < 10 && j + k < 10) 
                    max_d_chtrai = max(max_d_chtrai, taxi_vitri[i + k][j + k]);
                
                if (i + k < 10 && j - k >= 0) 
                    max_d_chphai = max(max_d_chphai, taxi_vitri[i + k][j - k]);                
            }
            SherWat_vitri[i][j] = max(max_d_chtrai, max_d_chphai);
            if (SherWat_vitri[i][j] < 0) SherWat_vitri[i][j] = 0;
        }
    }

// Tinh diem gap cua Taxi va Sherlock va Watson 
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {           
        if (taxi_vitri[i][j] > E3*2) diemgapI++;            
        if (taxi_vitri[i][j] < -E3) diemgapJ++; 
    }           
}

int K, L = 0 ;
K = diemgapI;
L = diemgapJ;
while (K > 9) K = K/10 + K%10;

while (L > 9) L = L/10 + L%10;
    
// So sanh diem gap cua Taxi va Sherlock va Watson
int taxi_diem = taxi_vitri[K][L];
int SherWat_diem = SherWat_vitri[K][L];
int MN; 
if (abs(taxi_diem) > SherWat_diem) MN = taxi_diem;
else MN = SherWat_diem;

// Khong duoi kiep taxi
if (abs(taxi_diem) > SherWat_diem) {
    HP1 = ceil(HP1 * 0.9);
    EXP1 = ceil(EXP1 * 0.88);
    HP2 = ceil(HP2 * 0.9);
    EXP2 = ceil(EXP2 * 0.88);
} 
// Duoi kiep taxi
else {   
    HP1 += ceil(HP1 * 0.1);
    EXP1 += ceil(EXP1 * 0.12);
    HP2 += ceil(HP2 * 0.1);
    EXP2 += ceil(EXP2 * 0.12);
}
check_condition (HP1,  HP2,  EXP1, EXP2, M1,  M2,  E1, E2,  E3);  
    return MN;
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string password(s);
    string se(email);
    se = se.substr(0, se.find('@'));
    string ktdb_string = "@#%$!";
    
    // Check chieu dai password 
    if (password.length() < 8)  return -1;
    if (password.length() > 20) return -2;    

    // Check password co chua se 
    size_t se_con = password.find(se);
    if (se_con != string::npos) return -(300 + se_con);
    

    // Check co 2 ky tu giong nhau lien tiep 
    for (size_t i = 0; i < password.length() - 2; ++i) {
        if (password[i] == password[i+1] && password[i+1] == password[i+2]) return -(400 + i);
        
    } 

    // Check co it nhat 1 ky tu dac biet
    bool co_ktdacbiet = false;
    for (char c : password) {
        if (ktdb_string.find(c) != string::npos) {
            co_ktdacbiet = true;
            break;
        }
    }
    if (!co_ktdacbiet) return -5;    

    // Check ky tu hop le 
    for (size_t i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (!isalnum(c) && ktdb_string.find(c) == string::npos) return i;        
    }
     // Neu mat khau hop le return -10
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_ginhau = 0;
    int max_chdai = 0;
    int fist_vitri = -1;

  for (int i = 0; i < num_pwds; ++i) {
     int ginhau = 0;
     int chieudai = strlen(arr_pwds[i]);
    //check mat khau trung nhau 
    for (int j = 0; j < num_pwds; ++j) 
        if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) ginhau++;            
    
    //check mat khau trung nhau nhieu nhat va dai nhat
    if (ginhau > max_ginhau || (ginhau == max_ginhau && chieudai > max_chdai)) {
      max_ginhau = ginhau;
      max_chdai = chieudai;
      fist_vitri = i;
    }
        
}
    return fist_vitri;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////