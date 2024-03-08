#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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

//check
int checkHP(int & HP){
if (HP<0){
    HP=0;
}
else if (HP>666){
HP=666;
}
return HP;
} 

int checkM(int& M){
    if (M<0){
M=0;
    }
    else if (M>3000){
        M=3000;
    }

   
    return M;
}


int checkEXP(int& EXP){
    if (EXP<0){EXP=0;
    }
    else if (EXP>600){
        EXP=600;
}

    return EXP;
}


// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
if (0>e1 || e1>99){
return -99;
    }

     int D; 
     checkEXP(exp1);
     checkEXP(exp2);

    switch(e1){
    case 0:
        exp2 += 29;
        D = e1 * 3 + exp1 * 7;
        if ((D % 2) == 0) {
            exp1 += (D / 200.0)+0.9999;
        }
        else {
            exp1 -= floor(D / 100.0);
        }
       
checkEXP(exp1);
checkEXP(exp2);

        break;

    case 1:
        exp2 += 45;
        D = e1 * 3 + exp1 * 7;
        if ((D % 2) == 0) {
            exp1 += (D / 200.0)+0.999;
        }
        else {
            exp1 -= floor(D / 100.0);
        }
        checkEXP(exp1);
checkEXP(exp2);

        break;
    case 2:
        exp2 += 75;
        D = e1 * 3 + exp1 * 7;
        if ((D % 2) == 0) {
            exp1 += (D / 200.0)+0.999;
        }
        else {
            exp1 -= floor(D / 100.0);
        }
        checkEXP(exp1);
checkEXP(exp2);

        break;
    case 3:
        exp2 += (29 + 45 + 75);
        
        D = e1 * 3 + exp1 * 7;
   
        if ((D % 2) == 0) {
           exp1 += D / 200.0+0.999;
           
        }
        else {
           exp1 -= floor( D / 100.0);
           
        }
     
        checkEXP(exp1);
checkEXP(exp2);


        break;

    default:
        if (e1 >= 4 && e1 <= 19) {
            exp2 += (e1 / 4.0 +0.9999 + 19);
            
            
          
            checkEXP(exp2);
            exp1 -= e1;
            checkEXP(exp1);
            
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += (e1 / 9.0 +0.9999+ 21);
       
            checkEXP(exp2);
 
           
            exp1 -= e1;
            checkEXP(exp1);
           
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += (e1 / 16.0 + 0.999 + 17);
            
           
            
            checkEXP(exp2);
            exp1 -= e1;
            checkEXP(exp1);
            
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += (e1 / 4.0 + 0.999 + 19);
             
             
              checkEXP(exp2);
            if (exp2 > 200){
                exp2 += (e1 / 9.0 +0.999 + 21);
                 
              
              checkEXP(exp2);
            } 
            exp1 -= e1;
            checkEXP(exp1);
           


        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += (e1 / 4.0) +0.999 + 19;
          
            checkEXP(exp2);
           
            exp2 += (e1 / 9.0) +0.999 + 21;
           
            checkEXP(exp2);
       
            if (exp2 > 400) {
                exp2 += (e1 / 16.0)+0.9999 + 17;
                
                checkEXP(exp2);
                exp2 += 0.15 * exp2 +0.999;
               
                checkEXP(exp2);
            } 
            exp1 -= e1;
            checkEXP(exp1);
            
        }
        checkEXP(exp1);
checkEXP(exp2);
    }


    return exp1 + exp2;
}
// TODO: Complete this function

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
if (0>E2 || E2>99){
return -99;
    }

 // đường 1
    double x1{}, S1{}, P1{};
    x1 = round(sqrt(EXP1));
    S1 = x1 * x1;
    if (EXP1 >= S1) {
        P1 = 1;
    }
    else {
        //ép kiểu để tính toán chính xác
        P1 = (EXP1 /(S1) + 80) / 123.0;
    }
   

    //đường 2
   

if (M1>0 && E2 % 2 == 0){
    
        if (HP1 < 200) {
            HP1 += 0.3 * HP1 + 0.9999;
            checkHP(HP1);
            M1 -= 150;
            checkM(M1);
             switch (M1){
        case 0:
        break;
    }
        
        }
        else {
            HP1 += 0.1 * HP1 + 0.9999;
            checkHP(HP1);
            M1 -= 70;
            checkM(M1);
             switch (M1){
        case 0:
        break;
    }

        }

        if (EXP1 < 400) {
            EXP1 += 0.13 * EXP1 +0.9999;
            checkEXP(EXP1);
            M1 -= 200;
            checkM(M1);
             switch (M1){
        case 0:
        break;
        }}
        else {
            EXP1 += 0.13 * EXP1+0.9999;
            checkEXP(EXP1);
            M1 -= 120;
            checkM(M1);
             switch (M1){
        case 0:
        break;
        }}

        if (EXP1 < 300) {
           
            EXP1 = 0.9 * EXP1+ 0.9999;
            checkEXP(EXP1);
             M1 -= 100;
            checkM(M1);
             switch (M1){
        case 0:
        break;
        }}
        else {
            
            EXP1 =0.9 * EXP1+0.9999;
            checkEXP(EXP1);
            M1 -= 120;
            checkM(M1);
             switch (M1){
        case 0:
        break;}
        }
        //break;
} 

else if (E2%2!=0 || (M1==0&&E2%2==0)){
   checkM(M1);
             switch (M1){
        case 0:
        break;}
        
        int sum=0;
        int M0 = M1;
        do {
            
            if (HP1 < 200) {
                HP1 += 0.3 * HP1 + 0.9999;
                checkHP(HP1);
                sum += 150;
                 M1 -= 150;
                checkM(M1);
               
            }
            else {
                HP1 += 0.1 * HP1 +0.9999;
                checkHP(HP1);
                sum += 70;
                M1 -= 70;
                checkM(M1);
                 
            }

            if (sum > M0 *0.5){
                break;
            }

            if (EXP1 < 400) {
                EXP1 += 0.13 * EXP1 +0.9999;
                checkEXP(EXP1);
                sum += 200;
                M1 -= 200;
                checkM(M1);
               
            }
            else {
                EXP1 += 0.13 * EXP1 +0.9999;
                checkEXP(EXP1);
                sum += 120;
                 M1 -= 120;
                 checkM(M1);
                  
            }

            if (sum > M0 *0.5){
                break;
            }

            if (EXP1 < 300) {
                
                EXP1 = 0.1 * EXP1;
                 checkEXP(EXP1);
                M1 -= 100;
                sum += 100;
                checkM(M1);
                 
            }
            else {
                M1 -= 120;
                checkM(M1);
                sum += 120;
                EXP1 = 0.9 * EXP1 + 0.9999;
                 checkEXP(EXP1);
                                  

            }
            if (sum > M0 *0.5){
                break;
            }

        } while (sum <= M0 * 0.5);
        

    
}


    EXP1 += 0.17*EXP1 +0.999;
 checkEXP(EXP1);
    HP1 = 0.83*HP1 + 0.999;
 checkHP(HP1);
                



    double x2{}, S2{}, P2{};
    x2 = round(sqrt(EXP1));
    S2 = x2 * x2;
    if (EXP1 >= S2) {
        P2 = 1;
    }
    else {
        P2 = (EXP1 /  (S2) + 80) / 123.0;
    }

    

    //đường 3

    int P3[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i{};
    if (E2 < 10) {
        i = E2;
    }
    else {
        int sum1{};
        sum1 = (int)(E2 / 10) + (E2 % 10);
        i = sum1 % 10;
    }
    double P3a = P3[i] / 100.0;
    double Pfinal{};

    if (P1 == P2 == P3a == 1)
    {
        EXP1 = 0.75 * EXP1+0.999;
         checkEXP(EXP1);

        Pfinal = 1;
       
    }
    else {
        Pfinal = (P1 + P2 + P3a) / 3.0;
       
        if (Pfinal <= 0.5) {
            HP1 = HP1 * 0.85 +0.999;
             checkHP(HP1);


            EXP1 += EXP1 * 0.15+0.9999;
             checkEXP(EXP1);
        }
        else {
            HP1 = HP1 * 0.9 + 0.9999;
             checkHP(HP1);
            EXP1 += EXP1 * 0.2+0.99999;
             checkEXP(EXP1);
        }
    }

    return HP1 + EXP1 + M1;

}


   int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // Kiểm tra giá trị của E3
    if (E3 < 0 || E3 > 99) {
        return -99;
    }

    // Khởi tạo và tính toán mảng điểm taxi
    long long taxiPkt[10][10] = {0};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxiPkt[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
 // Khởi tạo và tính toán mảng maxTaxi
    long long maxTaxi[10][10] = {0};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            long long maxCheoTrai = taxiPkt[i][j];
            long long maxCheoPhai = taxiPkt[i][j];

            // Tính max trái
            for (int a = 0; (i + a < 9) && (j + a < 9) && (i+a >=0) && (j+a >=0); ++a) {
                maxCheoTrai = std::max(maxCheoTrai, taxiPkt[i + a][j + a]);
            }
            for (int a = 1; (i - a >= 0) && (j - a >= 0) && (i - a < 9) && (j - a <9); ++a) {
                maxCheoTrai = std::max(maxCheoTrai, taxiPkt[i - a][j - a]);
            }

            // Tính max phải
            for (int a = 0; (i + a >= 0) && (j - a >= 0) && (i + a < 9) && (j - a <9); ++a) {
                maxCheoPhai = std::max(maxCheoPhai, taxiPkt[i + a][j - a]);
            }
            for (int a = 1; (i - a >= 0) && (j + a >= 0) && (i - a < 9) && (j + a <9); ++a) {
                maxCheoPhai = std::max(maxCheoPhai, taxiPkt[i - a][j + a]);
            }

            maxTaxi[i][j] = std::max(maxCheoTrai, maxCheoPhai);
        }
    } 

   

    // Tính các điểm số và cập nhật HP, EXP
   int soDuong = 0, soAm = 0;
for (int a = 0; a < 10; ++a) {
    for (int b = 0; b < 10; ++b) {
        if (taxiPkt[a][b] > E3 * 2) {
            soDuong++;
        }
        if (taxiPkt[a][b] < -E3) {
            soAm++;
        }
    }
}


   

   // std::cout << "soDuong: " <<soDuong << " soAm: " <<soAm <<'\n';

    int gap_i = 0, gap_j = 0;
    if (soDuong < 10 && soAm < 10) {
        gap_i = soDuong;
        gap_j = soAm;
    } else if (soDuong > 10 && soAm < 10) {
        gap_i = soDuong % 10 + soDuong / 10;
        gap_j = soAm;
         if (gap_i>=10){
        gap_i=gap_i/10+gap_i/10;
     }
    } else if (soDuong < 10 && soAm > 10) {
        gap_j = soAm % 10 + soAm / 10;
        gap_i = soDuong;
         if (gap_j>=10){
        gap_j=gap_j/10+gap_j/10;
     }
    } else if (soDuong > 10 && soAm > 10) {
        gap_i = soDuong % 10 + soDuong / 10;
        gap_j = soAm % 10 + soAm / 10;
     if (gap_i>=10){
        gap_i=gap_i/10+gap_i%10;
     }
     if (gap_j>=10){
        gap_j=gap_j/10+gap_j%10;
     }
    }

   // std::cout << "gap I " << gap_i << " gap j " << gap_j<<'\n';

    long long diemTaxitaiij = taxiPkt[gap_i][gap_j];
   // std::cout << "diemtaxitaiij la: " << diemTaxitaiij<<std::endl;
    long long diemSherlocktaiij = maxTaxi[gap_i][gap_j];
   // std::cout << "diemSherlocktaiij la: " << diemSherlocktaiij<<std::endl;

  if (abs(diemTaxitaiij) > diemSherlocktaiij) {
        HP1 = 0.9 * HP1 + 0.9999;
        HP2 = 0.9 * HP2 + 0.9999;
        EXP1 = 0.88 * EXP1 + 0.999;
        EXP2 = 0.88 * EXP2 + 0.9999;

        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);

        return diemTaxitaiij;
    } else {
        HP1 = HP1 + 0.1 * HP1 + 0.9999;
        HP2 =  HP2 + 0.1 * HP2 + 0.9999;
        EXP1 = EXP1+ 0.12 * EXP1 + 0.9999;
        EXP2 = EXP2 + 0.12 * EXP2 + 0.999;

       
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return diemSherlocktaiij;
    }

    return diemTaxitaiij;
}

// Task 4
int checkPassword(char const* s, char const* email) {
    // Lấy chuỗi trước ký tự '@' trong email

     std::string password(s);
    std::string userEmail(email);

    std::string se = userEmail.substr(0, userEmail.find('@'));

    // Kiểm tra độ dài của mật khẩu
    if (password.length() < 8) {
        return -1; // Độ dài ngắn hơn độ dài tối thiểu
    } else if (password.length() > 20) {
        return -2; // Độ dài dài hơn độ dài tối đa
    }

    // Kiểm tra xem mật khẩu có chứa chuỗi se hay không
    size_t sei = password.find(se);
    if (sei != std::string::npos) {
        return -(300 + sei); // Chứa chuỗi se
    }

    // Kiểm tra xem mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau hay không
    for (size_t i = 0; i < password.length() - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
        }
    }

    // Kiểm tra xem mật khẩu có chứa ít nhất 1 ký tự đặc biệt hay không
    bool containsSpecialChar = false;
    for (char c : password) {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            containsSpecialChar = true;
            break;
        }
    }
    if (!containsSpecialChar) {
        return -5; // Không chứa ký tự đặc biệt
    }

    // Kiểm tra từng ký tự trong mật khẩu
    for (size_t i = 0; i < password.length(); ++i) {
        char c = s[i];

        // Kiểm tra xem ký tự có phải là chữ số, chữ cái hoa, chữ cái thường hoặc ký tự đặc biệt không
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i; // Ký tự không hợp lệ
        }

        // Kiểm tra xem ký tự có là ký tự thứ 3 giống liên tiếp không
        if (i >= 2 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]) {
            return -(400 + i - 2); // Chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
        }
    }

    return -10; // Mật khẩu hợp lệ
}





  
struct PasswordInfo {
    int count;
    int length;
};

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // mảng lưu số lần xuất hiện và độ dài của từng mật khẩu
    PasswordInfo info[201];

    //số lần xuất hiện và độ dài của mỗi mật khẩu
    for (int i = 0; i < num_pwds; ++i) {
        // Đặt số lần xuất hiện và độ dài ban đầu là 0
        info[i].count = 0;
        info[i].length = strlen(arr_pwds[i]);

        // Tính số lần xuất hiện của mật khẩu
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                info[i].count++;
            }
        }
    }

    // Tìm mật khẩu xuất hiện nhiều nhất và có độ dài lớn nhất
    int max_count = 0;
    int max_length = 0;
    int max_index = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (info[i].count > max_count || (info[i].count == max_count && info[i].length > max_length)) {
            max_count = info[i].count;
            max_length = info[i].length;
            max_index = i;
        }
    }

    // Trả về vị trí đầu tiên của mật khẩu đúng
    return max_index;
}







////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
