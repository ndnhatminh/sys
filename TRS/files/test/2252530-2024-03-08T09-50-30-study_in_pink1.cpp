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
void checkandRoundM(int& M)
{
     if (M > 3000)
        M = 3000;
    else if (M < 0)
        M = 0;

    // Làm tròn HP
    M = round(M);
}
   void checkAndRoundHP(int& HP) {
    // Kiểm tra và làm tròn HP
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;

    // Làm tròn HP
    HP = round(HP);
}
void checkAndRoundEXP(int& EXP) {
    // Kiểm tra và làm tròn EXP
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
        EXP = 0;

    // Làm tròn EXP
    EXP = round(EXP);
}
// Hàm tính xác suất P1 trên con đường 01
double calculateProbabilityOnPath1(int EXP1) {
    int S = round(sqrt(EXP1))*round(sqrt(EXP1)); // S là số chính phương gần với EXP1 nhất
    // cout<< "S: "<< S << endl;
    if (EXP1 >= S) {
        return 1.0; // Xác suất 100%
    } else {
        return (EXP1 * 1.0 / S + 80) / 123;
    }
}

// Hàm thực hiện các hành động trên con đường 02
double performActionsOnPath2(int& HP1, int& EXP1, int& M1, int E2) {
    double halfInitialMoney = M1 * 0.5; // 50% số tiền ban đầu
    // cout << "50 % so tien ban dau" << halfInitialMoney << endl;
    double currentMoneySpent = 0; // Số tiền đã chi
    bool continueEvents = true; // Biến kiểm tra liệu có tiếp tục sự kiện hay không
    bool odd = E2 % 2 != 0; // Kiểm tra xem E2 có phải là số lẻ không
    bool pathTaken = false; // Biến đánh dấu đã thực hiện đường đi ít nhất một lần
        
    // if (odd) 
    // {
    //     // cout <<" E2 la so le";
    //     // cout << endl;
    // }
    // else {
    //     // cout <<"E2 la so chan";
    //     // cout <;< endl
    // }
    // cout<<"HP1 " <<HP1 << endl;
    // cout<<"EXP1 "<<EXP1 << endl;
    
    while (halfInitialMoney > currentMoneySpent )
    {
        // Nếu HP1 < 200, mua thức ăn và nước uống
        if (HP1 < 200) {
            M1 -= 150;
            currentMoneySpent += 150;
            HP1 = ceilf(HP1 * 1.3); // Cộng 30% HP hiện có
        } else {
            M1 -= 70;
            currentMoneySpent += 70;
            HP1 = ceilf(HP1 * 1.1); // Cộng 10% HP hiện có
        }
        checkandRoundM(M1);
        checkAndRoundEXP(EXP1);
        checkAndRoundHP(HP1);
        // cout<<"HP1 mua thuc an nuoc uong " <<HP1 << endl;
        // cout<<"EXP1 mua thuc an nuoc uong "<<EXP1 << endl;
        // cout << "tien mua thuc an nuoc uong " << M1 << endl;
        // cout <<"so tien chi tra: " << currentMoneySpent << endl;
        // cout << endl;
        if ((currentMoneySpent > halfInitialMoney && odd) || (M1 == 0) ) break;
        // cout<<"HP1 mua thuc an nuoc uong " <<HP1 << endl;
        // cout<<"EXP1 mua thuc an nuoc uong "<<EXP1 << endl;
        
        // Thuê taxi hoặc xe ngựa
        // if (M1 > 200) { break; }
        // else 
        // {
        if (EXP1 < 400) {
            M1 -= 200;
            currentMoneySpent += 200;
            EXP1 = ceilf(EXP1 * 1.13); // Tăng 13% EXP
        } else {
            M1 -= 120;
            currentMoneySpent += 120;
            EXP1 = ceilf(EXP1 * 1.13);
        }
        checkandRoundM(M1);
        checkAndRoundEXP(EXP1);
        checkAndRoundHP(HP1);
        
        // cout<<"HP1 thue taxi hoac xe ngua " <<HP1 << endl;
        // cout<<"EXP1 thua taxi hoac xe ngua "<<EXP1 << endl;
        // cout << "tien gap nguoi thue taxi hoac xe ngua " << M1 << endl;
        // cout <<"so tien chi tra: " << currentMoneySpent << endl;
        // cout<< endl;
        if ((currentMoneySpent > halfInitialMoney && odd) || (M1 == 0) ) break;
        
         // Gặp người vô gia cư
        if (EXP1 < 300) {
            M1 -= 100;
            currentMoneySpent += 100;
            EXP1 = ceilf(EXP1 * 0.9); // Giảm 10% EXP
        } else {
            M1 -= 120;
            currentMoneySpent += 120;
            EXP1 = ceilf(EXP1*0.9); // Giảm 10% EXP
        }
        checkandRoundM(M1);
        checkAndRoundEXP(EXP1);
        checkAndRoundHP(HP1);
        // cout<<"HP1 gap nguoi vo gia cu " <<HP1 << endl;
        // cout<<"EXP1 gap nguoi vo gia cu "<<EXP1 << endl;
        // cout << "tien gap nguoi vo gia cu " << M1 << endl;
        // cout <<"so tien chi tra: " << currentMoneySpent << endl;
        // cout << endl;
        if ( (currentMoneySpent > halfInitialMoney && odd) || (M1 == 0) ) break;
        
        
        
        if (!odd)
        {
            break;
        }
    }
    
    
        // if (odd)
        // {
        //     while (halfInitialMoney > currentMoneySpent)
        //     {
        //         cout <<"vong lap so sanh so tien chi tra va 50% " << endl;
        //         // Nếu HP1 < 200, mua thức ăn và nước uống
        // if (HP1 < 200) {
        //     M1 -= 150;
        //     currentMoneySpent += 150;
        //     HP1 = ceilf(HP1 * 1.3); // Cộng 30% HP hiện có
        // } else {
        //     M1 -= 70;
        //     currentMoneySpent += 70;
        //     HP1 = ceilf(HP1 * 1.1); // Cộng 10% HP hiện có
        // }
        // checkAndRoundEXP(EXP1);
        // checkAndRoundHP(HP1);
        // cout<<"HP1 mua thuc an nuoc uong " <<HP1 << endl;
        // cout<<"EXP1 mua thuc an nuoc uong "<<EXP1 << endl;
        // cout << "tien mua thuc an nuoc uong " << M1 << endl;
        // cout <<"so tien chi tra: " << currentMoneySpent << endl;
        // cout << endl;
        //  if (currentMoneySpent > halfInitialMoney) break;
        // // if (currentMoneySpent > halfInitialMoney) break;
        // // cout<<"HP1 mua thuc an nuoc uong " <<HP1 << endl;
        // // cout<<"EXP1 mua thuc an nuoc uong "<<EXP1 << endl;
    
        // // Thuê taxi hoặc xe ngựa
        // if (EXP1 < 400) {
        //     M1 -= 200;
        //     currentMoneySpent += 200;
        //     EXP1 = ceilf(EXP1 * 1.13); // Tăng 13% EXP
        // } else {
        //     M1 -= 120;
        //     currentMoneySpent += 120;
        //     EXP1 = ceilf(EXP1 * 1.13);
        // }
        // checkAndRoundEXP(EXP1);
        // checkAndRoundHP(HP1);
        //  if (currentMoneySpent > halfInitialMoney) break;
        // cout<<"HP1 thue taxi hoac xe ngua " <<HP1 << endl;
        // cout<<"EXP1 thua taxi hoac xe ngua "<<EXP1 << endl;
        // cout << "tien gap nguoi thue taxi hoac xe ngua " << M1 << endl;
        // cout <<"so tien chi tra: " << currentMoneySpent << endl;
        // cout<< endl; 
        
        
        //  // Gặp người vô gia cư
        // if (EXP1 < 300) {
        //     M1 -= 100;
        //     currentMoneySpent += 100;
        //     EXP1 = ceilf(EXP1 * 0.9); // Giảm 10% EXP
        // } else {
        //     M1 -= 120;
        //     currentMoneySpent += 120;
        //     EXP1 = ceilf(EXP1*0.9); // Giảm 10% EXP
        // }
        //     checkAndRoundEXP(EXP1);
        // checkAndRoundHP(HP1);
        //  cout<<"HP1 gap nguoi vo gia cu " <<HP1 << endl;
        // cout<<"EXP1 gap nguoi vo gia cu "<<EXP1 << endl;
        // cout << "tien gap nguoi vo gia cu " << M1 << endl;
        // cout <<"so tien chi tra: " << currentMoneySpent << endl;
        // cout << endl;
        //  if (currentMoneySpent > halfInitialMoney) break;
        
        //     }
        // }
        
        // if (!odd)
        // {
        //     continueEvents = false;
        // }
        // cout <<"so le " <<odd <<"continueEvents" << continueEvents<< endl;
    HP1 = ceilf(HP1 * 0.83); // Giảm 17% HP hiện có
    EXP1 = ceilf(EXP1 * 1.17); // tang 17%
        checkAndRoundEXP(EXP1);
        checkAndRoundHP(HP1);
    // cout << "HP1 sau chuoi su kien " << HP1 << endl;
    // cout << "EXP1 sau chuoi su kien " << EXP1 << endl;
    // cout <<"So tien sau chuoi su kien" <<M1 <<endl;
    int S = round(sqrt(EXP1))*round(sqrt(EXP1)); // S là số chính phương gần với EXP1 nhất
    // cout<< "S: "<< S << endl;
    
    // cout <<"HP1 sau khi ket thuc "<< HP1<< endl;
    // cout <<"EXP1 sau khi ket thuc "<< EXP1<< endl;
    // Nếu E2 là số chẵn hoặc tiền không đủ để tiếp tục các sự kiện
    // if (!odd || M1 < 70) {
    //     HP1 = ceil(HP1 * 0.83); // Giảm 17% HP hiện có
    //     EXP1 = ceil(EXP1 * 1.17); // Tăng 17% EXP
    // }
    // cout<< "EXP1: su kien 2 = " <<EXP1 << endl;
    return EXP1;
    
}
double calculateProbabilityOnPath2(int EXP1) {
    // cout <<"EXP1 cua P2 " <<EXP1 <<endl;
    int S = round(sqrt(EXP1))*round(sqrt(EXP1)); // S là số chính phương gần với EXP1 nhất
    // cout<< "S cua P2: "<< S << endl;
    if (EXP1 >= S) {
        return 1.0; // Xác suất 100%
    } else {
        return (EXP1 * 1.0 / S + 80) / 123;
    }
}
double calculateProbabilityOnPath3(int E2) {
    const int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // Mảng các giá trị phần trăm
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        int sum = E2 / 10 + E2 % 10;
        i = sum % 10;
        // cout <<"tong hai chu so: " << i << endl;
    }
    // cout <<"P[I] = "<<P[i] <<" " <<" P3 = " << P[i] * 1.0 / 100 << endl;
    return P[i] * 1.0 / 100; // Chuyển về dạng phần trăm
}

// Hàm tính xác suất cuối cùng và cập nhật EXP1 và HP1
double calculateFinalProbabilityAndUpdateStats(double P1, double P2, double P3, int& EXP1, int& HP1) {
    // double finalProbability = (P1 + P2 + P3) / 3;
     double finalProbability = round((P1 + P2 + P3) / 3.0 * 100) / 100;
    //  cout << " xac suat trung binh khi round " << finalProbability << endl;
     if (finalProbability == 1)
     {
         EXP1 = ceilf(EXP1 - (EXP1*25.0)/100.0);
         
        checkAndRoundEXP(EXP1);
        checkAndRoundHP(HP1);
        //  cout <<"EXP1: " << EXP1;
     }
     else
     {
     {
    if (finalProbability < 0.5) {
        HP1 = ceilf(HP1 * 0.85); // Giảm 15% HP1
        EXP1 = ceilf(EXP1 * 1.15); // Tăng 15% EXP1
        
        checkAndRoundEXP(EXP1);
        checkAndRoundHP(HP1);
    } else {
        HP1 = ceilf(HP1 * 0.9); // Giảm 10% HP1
        // cout << "HP1: " << HP1 << endl;
        EXP1 = ceilf(EXP1 * 1.2); // Tăng 20% EXP1
        
        checkAndRoundEXP(EXP1);
        checkAndRoundHP(HP1);
        // cout << "EXP1: " << EXP1 << endl;
    }
     }
     }
    // if (EXP1 > 600)
    // {
    //     EXP1 = 600;
    // }
   checkAndRoundHP(HP1);
   checkAndRoundEXP(EXP1);
     return finalProbability;
}

// Hàm traceLuggage

int TongHaiChuSo(int a)
{
    long long PhanDonVi;
    long long PhanChuc;
    PhanDonVi =  a % 10;
    PhanChuc = a / 10;
    if (PhanDonVi + PhanChuc >= 10)
    {
        return TongHaiChuSo(PhanDonVi + PhanChuc);
    }
    else return PhanDonVi + PhanChuc;
}
// ham task 4

bool has_invalid_character(const string& s) {
    for (char c : s) {
        if ( c != '@' || c != '#' || c != '%' || c != '$' || c != '!' || !isalnum(c) ) {
            return true; // Trả về true nếu có ký tự không hợp lệ
        }
    }
    return false; // Trả về false nếu không có ký tự không hợp lệ
}
int find_invalid_character_position(const string& s) {
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (!(isalnum(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i; // Trả về vị trí của ký tự không hợp lệ
        }
    }
    return -1; // Trả về -1 nếu không có ký tự không hợp lệ
}

bool ChuoiKyTuDacBiet(const string& s) {
    for (char c : s) {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            return true;
        }
    }
    return false;
}

int GiaTriKyTuDacBiet(const string& s) {
    for (char c : s) {
        if (!(isalnum(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return -5; // Trả về -5 nếu có ký tự đặc biệt
        }
    }
    return 0; // Trả về 0 nếu không có ký tự đặc biệt
}
bool ChuaHaiChuoiLienTiep(const string& s) {
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i + 2]) {
            return true;
        }
    }
    return false;
}

int ViTriHaiChuoiLienTiep(const string& s) {
    int sci = -1; 
    for (int i = 0; i < s.length() - 2; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) {
            sci = i;
            break; 
        }
    }
    if (sci != -1) {
        return -(400 + sci);
    } else {
        return sci;
    }
}

bool NganHonDoDaiToiThieu(const string& s)
{
    if (s.length() < 8)
    {
        return true;
    }
    return false;
}
bool DaiHonDoDaiToiThieu(const string& s)
{
    if (s.length() > 20)
    {
        return true;
    }
    return false;
}

// kiem tra do dai toi thieu
bool DoDaiToiThieu(const string& s)
{
    if (s.length() >= 8 && s.length() <= 20)
    {
        return true;
    }
    else return false;
}
// tach ky tu truoc @
string KyTuTruoc(const string &s)
{
      string tach = s.substr(0, s.find ("@"));
      return tach;
}
// kiem tra trong mat khau co chua se 
bool KiemTraSe(const string &s, const string email)
{
    string tach = KyTuTruoc(email);
    if (s.find(tach) == string::npos)
    {
        return false;
    }
    return true;
}
// kiem tra 2 ky tu lien tiep giong nhau
int KyTuLienTiep(const string& s) {
    int sci = -1; 
    for (int i = 0; i < s.length() - 2; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) {
            sci = i;
            break; 
        }
    }
    if (sci != -1) {
        return -(400 + sci);
    } else {
        return sci;
    }
}
// kiem tra mat khau hop le
bool checkPasswordHopLe(const string& s, const string email)
{
    if (DoDaiToiThieu(s) ==  true && KiemTraSe(s, email) ==  false && ChuaHaiChuoiLienTiep(s) == false 
    && ChuoiKyTuDacBiet(s) == true && find_invalid_character_position(s) == -1 )
    {
        return true;
    }
    return false;
}



// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    double d;
    exp2 = double(exp2);
     if (e1 > 99 || e1 < 0)
    {
        return -99;
    }
// truong hop 1
    if ( e1>= 0 && e1 <= 3)
    {
        // cout<<"truong hop 1 \n";
        if (e1 == 0)
        {
            // thong tin 1
            exp2 = exp2 + 29;  
            d = e1 * 3 + exp1 * 7;
        }
        else
        if (e1 == 1)
        {
            // thong tin 2
            exp2 = exp2 + 45;
            d = e1 * 3 + exp1 * 7;
        }
        else
        if (e1 == 2)
        {
            // thong tin 3
            exp2 = exp2 + 75;
            d = e1 * 3 + exp1 * 7;
        }
        else
        if (e1 == 3)
        { 
            // thong tin 4
            exp2 = exp2 + 149;
            d = e1 * 3 + exp1 * 7;
        
        // if (int(d) % 2 == 0)
        // {
        //     exp1 = exp1 + ceilf(d/200);
        // }
        // else
        // {
        //     exp1 = ceilf(exp1 - d/100);
        // }
      
        }

        if (int(d) % 2 == 0)
        {
            exp1 = exp1 + ceilf(d/200);
        }
        else
        {
            exp1 = ceilf(exp1 - d/100);
        }
    }

// truong hop 2
    if ( e1>= 4 && e1 <= 99)
    {
        double newexp2;
        // cout<<"truong hop 2 \n";
        if ( e1>= 4 && e1 <= 19)
        {
            // cout<<"thong tin 1 \n";
            newexp2 = double(exp2) + double((e1/4.0 + 19));
            exp2 = ceil(newexp2);
        }
        else
        if ( e1>= 20 && e1 <= 49)
        {
            // cout<<"thong tin 2 \n";
            newexp2 = double(exp2) + double((e1/9.0 + 21)); // thong tin 2
            // cout << ceil(double((e1/9.0 + 21))) << " \n";
            // cout << ceil(e1/9.0) << " \n"; 
            // cout<<" newexp2: "  <<ceil (double(newexp2)) << " " <<" exp2: " << ceil(exp2) << " \n";
            exp2 = ceil(newexp2);
        }
        else 
        if ( e1>= 50 && e1 <= 65)
        {
            // cout<<"thong tin 3 \n";
            newexp2 = double(exp2) + double((e1/16.0 + 17));
            exp2 = ceil(newexp2);
        }
//thong tin 4
        else if (e1 >= 66 && e1 <=79)
        {
            // cout<<"thong tin 4 \n";
                newexp2 = ceil(double(exp2) + double((e1/4.0 + 19)));
                cout << newexp2 << " \n";
                if (newexp2 > 200)
                {
                   newexp2 = ceil(double(newexp2) + double((e1/9.0 + 21)));
                //    cout <<newexp2 << " \n ";
                } 
        exp2 = newexp2;
        }
//thong tin 5
        else if (e1>= 80 && e1 <= 99 )
        {
            // cout<<"thong tin 5 \n";
            // thong tin 5
            // cout<< exp2 + e1/4.0 + 19<< " \n";
            newexp2 = ceil( ceil(double(exp2) + double(e1/4.0 + 19)) + (e1 / 9.0 + 21));
            // cout<<"exp2: " <<newexp2 << " \n";
            if (newexp2 > 400)
            {
                newexp2 = ceil(newexp2+ double(e1/16.0 + 17));
                // cout<<"exp2: " <<newexp2 << " \n";
                newexp2  = ceil(newexp2*1.15);
                // cout<<"exp2: " <<newexp2 << " \n";
            }
            exp2 = newexp2;
            
        if (exp1 > 600)
        {
            exp1 = 600;
        }
        if (exp2 > 600)
        {
            exp2 = 600;
        }
        // cout<<"exp2: " <<exp2 <<"exp1: " <<exp1 << " \n";
        }
        exp1 = exp1 - e1;
        
    }
    // cout << " exp1: "<< exp1 << " "<< "exp2: "<< exp2 << " \n";
     checkAndRoundEXP(exp1);
     checkAndRoundEXP(exp2);
    return exp1 + exp2;

}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 > 99 || E2 < 0)
    {
        return -99;
    }
    double P1 = calculateProbabilityOnPath1(EXP1);
    // cout<<"P1 = " <<P1 << endl;
    performActionsOnPath2(HP1, EXP1, M1, E2);
    double P2 = calculateProbabilityOnPath2(EXP1); // Giả sử xác suất tìm được vali trên con đường 02 là 100%
    // cout <<"P2 = " << P2 << endl;
    double P3 = calculateProbabilityOnPath3(E2);

    double finalProbability = calculateFinalProbabilityAndUpdateStats(P1, P2, P3, EXP1, HP1);
    // Trả về kết quả HP1 + EXP1 + M1
    // cout << "HP1: "<< HP1 << " EXP1: " << EXP1 << " M1: " << M1 << endl;
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // Khởi tạo ma trận 10x10 và ma trận điểm của Sherlock và Watson
      if (E3 > 99 || E3 < 0)
    {
        return -99;
    }
    int taxiMap[10][10] = {0};
    int SWMap[10][10] = {0};
    long long sum_duong = 0 ;
    long long sum_dam = 0;
    
    // Tính điểm cho mỗi vị trí của taxi
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            // cout << taxiMap[i][j] << " \t "; 
        }
        // cout<<endl;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j =0; j < 10; ++j)
        {
            if (taxiMap[i][j] > E3*2 )
            {
                sum_duong++;
            }
            else 
            if (taxiMap[i][j] < -(E3*2))
            {
                sum_dam++;
            }
        }
    }
    if (sum_duong > 10) {
        sum_duong = TongHaiChuSo(sum_duong);
    }
    // else cout<< "vi tri i:  " << sum_duong;
    if (sum_dam > 10) {
        sum_dam = TongHaiChuSo(sum_dam);
    }
    // else cout<< "vi tri j:  " << sum_dam;
    // cout<< "so gia tri duong: " << sum_duong << "so gia tri am: "<< sum_dam << endl;
    // cout<<"gia tri cua taxi tai toa do" <<"["<<sum_duong<<"]" <<"["<<sum_dam<<"]" <<taxiMap[sum_duong][sum_dam]<<"\n";
    
    long long a = sum_duong;
    long long b = sum_dam;
    long long dif = a - b;
    long long sum = a + b;
    string lbag = "";
    string rbag = "";
    int giatrimax = 0;
    // cout <<" cac diem tren duong cheo phai: ";
    for (int i =0 ; i<10; i++)
    {
        for (int j =0; j < 10; j++)
        {
            if (dif == i - j)
            {
                if (taxiMap[i][j] > giatrimax)
                {
                    giatrimax = taxiMap[i][j];
                }
                // cout<< taxiMap[i][j] << " ";
            }
        }
    }
    // cout<< endl;
    // cout <<" cac diem tren duong cheo trai: ";
    for (int i =0; i < 10; i++)
    {
        for (int j = 0; j < 10; j ++)
        {
            if (sum == i + j)
            {
                if (taxiMap[i][j] > giatrimax)
                {
                    giatrimax = taxiMap[i][j];
                }
                // cout << taxiMap[i][j] << " " ;
            }
          
        }
    }
    // cout << endl;
    // cout << "gia tri lon nhat: " << giatrimax << " ";
    if (abs(taxiMap[sum_duong][sum_dam]) > giatrimax)
    {        
        EXP1 = ceilf(EXP1*0.88);
        EXP2 =ceilf(EXP2*0.88);
        HP1 = ceilf(HP1*0.9);
        HP2 = ceilf(HP2*0.9);
        checkAndRoundEXP(EXP1);
       checkAndRoundEXP(EXP2);
       checkAndRoundHP(HP1);
       checkAndRoundHP(HP2);
            return taxiMap[sum_duong][sum_dam];
    }
    else 
    {
       EXP1 = ceilf(EXP1*1.12);
       EXP2 = ceilf(EXP2*1.12);
       HP1 = ceilf(HP1*1.1);
       HP2 = ceilf(HP2*1.1);
       checkAndRoundEXP(EXP1);
       checkAndRoundEXP(EXP2);
       checkAndRoundHP(HP1);
       checkAndRoundHP(HP2);
       return giatrimax;
    }
    return 0;
}

// Task 4
int checkPassword(const char * s, const char * email) {
// Tìm chuỗi se
    // testcase
    
// chuyen char thanh string de xu ly
    const char *charEmail = email;
    string subEmail = string (charEmail);

    const char *charS = s;
    string subS = string (charS);
    
    //
     int invalid_pos = find_invalid_character_position(subS);


    if (checkPasswordHopLe(subS, email) == true) { 
        return -10; 
    }
    
    if (NganHonDoDaiToiThieu(subS) == true ) { return -1; }
    
    
    if (DaiHonDoDaiToiThieu(subS) == true ) { return -2; } 
    
    // ky tu truoc se
    string tach = KyTuTruoc(subEmail);
    
    size_t pos = subS.find(tach);
    int int_pos = static_cast<int>(pos);
    // cout<< - (300 + int_pos )<< " \n";
    
    
    if (KiemTraSe(s, email) == true ) {  return -(300 + int_pos); }
    
    if (ChuaHaiChuoiLienTiep(subS) == true) {
        return ViTriHaiChuoiLienTiep(subS);
    }
    
    if (ChuoiKyTuDacBiet(subS) == false) {  return -5;}

    if (has_invalid_character(subS) == true )
    {
        return find_invalid_character_position(subS);
    }
    return -99;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // Khởi tạo mảng đếm số lần xuất hiện của mỗi mật khẩu
    int *passwordCount = new int[num_pwds]();
    // Khởi tạo biến đếm số lần xuất hiện nhiều nhất của mật khẩu và độ dài lớn nhất của mật khẩu
    int maxCount = 0;
    int maxLength = 0;
    // Khởi tạo biến lưu vị trí đầu tiên của mật khẩu đúng trong arr_pwds
    int correctIndex = -1;

    // Đếm số lần xuất hiện của mỗi mật khẩu và tìm mật khẩu có số lần xuất hiện nhiều nhất
    for (int i = 0; i < num_pwds; ++i) {
        // Mặc định số lần xuất hiện của một mật khẩu là 1
        passwordCount[i] = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                // Tăng số lần xuất hiện của mật khẩu
                passwordCount[i]++;
            }
        }
        if (passwordCount[i] > maxCount || (passwordCount[i] == maxCount && strlen(arr_pwds[i]) > maxLength)) {
            // Cập nhật số lần xuất hiện nhiều nhất và độ dài lớn nhất của mật khẩu
            maxCount = passwordCount[i];
            maxLength = strlen(arr_pwds[i]);
            // Cập nhật vị trí đầu tiên của mật khẩu đúng
            correctIndex = i;
        }
    }

    // Giải phóng bộ nhớ cho mảng đếm số lần xuất hiện của mật khẩu
    delete[] passwordCount;
    
    return correctIndex;
}
// int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
//     long long passwordCount[30] = {0}; // Mảng đếm số lần xuất hiện của mỗi mật khẩu
//     long long maxCount = 0; // Số lần xuất hiện nhiều nhất của một mật khẩu
//     long long maxLength = 0; // Độ dài lớn nhất của mật khẩu xuất hiện nhiều nhất
//     long long correctIndex = -1; // Vị trí đầu tiên của mật khẩu đúng trong arr_pwds

//     // Đếm số lần xuất hiện của mỗi mật khẩu và tìm mật khẩu có số lần xuất hiện nhiều nhất
//     for (long long i = 0; i < num_pwds; ++i) {
//         passwordCount[i] = 1; // Mặc định số lần xuất hiện của một mật khẩu là 1
//         for (long long j = i + 1; j < num_pwds; ++j) {
//             if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
//                 passwordCount[i]++; // Tăng số lần xuất hiện của mật khẩu
//             }
//         }
//         if (passwordCount[i] > maxCount || (passwordCount[i] == maxCount && strlen(arr_pwds[i]) > maxLength)) {
//             maxCount = passwordCount[i];
//             maxLength = strlen(arr_pwds[i]);
//             correctIndex = i;
//         }
//     }

//     return correctIndex;
// }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////