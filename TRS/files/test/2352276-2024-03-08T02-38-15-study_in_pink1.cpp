#include "study_in_pink1.h"
using namespace std;
#include <cmath>
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

int check(int n, int firstpoint, int lastpoint) {
    n = (n < firstpoint) ? firstpoint : (n > lastpoint) ? lastpoint : n;
    return n;
}
int check2(int m, int firstpoint2, int lastpoint2) {
    m = (m < firstpoint2) ? firstpoint2 : (m > lastpoint2) ? lastpoint2 : m;
    return m;
}
int check3(int l, int firstpoint3, int lastpoint3) {
    l = (l < firstpoint3) ? firstpoint3 : (l > lastpoint3) ? lastpoint3 : l;
    return l;
}
int firstMeet(int &EXP1, int &EXP2, const int E1){

    int firstpoint = 0, lastpoint = 600;            
    if (E1 < 0 || E1 > 99) return -99;
    EXP1 = check(EXP1, firstpoint, lastpoint);
    EXP2 = check(EXP2, firstpoint, lastpoint);
if(E1==0){
    EXP2 += 29;
    int D=E1*3+EXP1*7;
    if (D%2==0){
    EXP1 += ceil(D/200);
}
else{
    EXP1 -= ceil(D/100);
}
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}
else if(E1==1){
    EXP2 += 45;
    int D=E1*3+EXP1*7;
if (D%2==0){
    EXP1 += ceil(D/200);
}
else{
    EXP1 -= ceil(D/100);
}
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}
else if(E1==2){
    EXP2 += 75;
    int D=E1*3+EXP1*7;
if (D%2==0){
    EXP1 += ceil(D/200);
}
else{
    EXP1 -= ceil(D/100);
}
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}
else if(E1==3){
    EXP2 += 29+45+75;
    int D=E1*3+EXP1*7;
    if (D%2==0){
    EXP1 += ceil(D/200);
}
else{
    EXP1 -= ceil(D/100);
}
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}
else if(E1>=4 && E1<=19){
    EXP2 += ((float)E1/4 + 0.999) + 19;
    EXP1 -= E1;
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}
else if(E1>=20 && E1<=49){
    EXP2 += ((float)E1/9 + 0.999)  + 21;
    
    EXP1 -=  E1;
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}
else if(E1>=50 && E1<=65){
    EXP2 += ((float)E1/16 + 0.999) +17;
    EXP1 -= E1;
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}
else if(E1>=66 && E1<=79){
    EXP2 += ((float)E1/4 + 0.999) + 19;
    if (EXP2 >200){
        EXP2 += ((float)E1/9 + 0.999)  + 21;
    }
    EXP1 -= E1;
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}
else if(E1>=80 && E1<=99){
    EXP2 += ((float)E1/4 + 0.999) + 19;
    EXP2 += ((float)E1/9 + 0.999)  + 21;
    if (EXP2 >400){
        EXP2 += ((float)E1/16 + 0.999) +17;
        EXP2 += EXP2*0.15 + 0.999;
    }
    EXP1 -= E1;
EXP1 = check(EXP1, firstpoint, lastpoint);
EXP2 = check(EXP2, firstpoint, lastpoint);
}

return EXP1+EXP2;
}
// Task 2
bool isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return (sqrtNum * sqrtNum == num);
}

// Hàm tìm số chính phương gần nhất với một số bất kỳ
int findNearestPerfectSquare(int num) {
    int smallerSquare = 0;
    int largerSquare = 0;

    // Tìm số chính phương nhỏ nhất
    for (int i = num; i >= 0; --i) {
        if (isPerfectSquare(i)) {
            smallerSquare = i;
            break;
        }
    }

    // Tìm số chính phương lớn nhất
    for (int i = num; ; ++i) {
        if (isPerfectSquare(i)) {
            largerSquare = i;
            break;
        }
    }

    // So sánh khoảng cách và trả về số chính phương gần nhất
    if (num - smallerSquare <= largerSquare - num) {
        return smallerSquare;
    } else {
        return largerSquare;
    }
}


// Xu ly hanh ly o Street2 dua tren cac gia tri HP1, EXP1, M1 va e2. Cac su kien khac nhau se thay doi gia tri cua HP1, EXP1 va M1. Cu the, su kien 1 tang HP1 va giam M1, su kien 2 giam M1 va tang EXP1, va su kien 3 giam M1 va giam EXP1. Neu M1 giam xuong duoi mot muc nhat dinh hoac M1 het, thi tang EXP1 va giam HP1. Cuoi cung, kiem tra gia tri cua EXP1 va HP1, va tra ve gia tri tu ham traceLuggage_Street1.
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    //con duong 1
    
    float P1;
if (findNearestPerfectSquare(EXP1)<EXP1){
           P1=100;
}
else {
           P1=((float)EXP1/findNearestPerfectSquare(EXP1) +80)/123;
           P1=P1*100;    
}
    int firstpoint = 0, lastpoint = 666;
    int firstpoint2 = 0, lastpoint2 = 3000;
    int firstpoint3 = 0, lastpoint3 = 600;
    HP1 = check(HP1, firstpoint, lastpoint);
    
    M1 = check2(M1, firstpoint2, lastpoint2);
    
    float M1_test = M1; 
    
    
    float M1_pay;
    //con duong 2
if (E2%2 != 0 ){
    
    while(  M1_pay <= (0.5*M1_test) ){
    
  
        if(HP1 < 200){
    HP1=ceil(HP1 + 0.3*HP1);
    //HP1=ceil(HP1_test);
    M1=M1- 150;
    M1_pay += 150;
    
    HP1 = check(HP1, firstpoint, lastpoint);
    M1 = check2(M1, firstpoint2, lastpoint2);
    
    //HP1_test=HP1;    
   
}
        else{
    HP1=ceil(HP1 + 0.1*HP1);
    //HP1=ceil(HP1_test);
    M1=M1- 70;
    M1_pay += 70;
    
        HP1 = check(HP1, firstpoint, lastpoint);
        M1= check2(M1, firstpoint2, lastpoint2);
        
        //HP1_test=HP1;
    }
      if (M1_pay > M1_test*0.5) break;

        if(EXP1<400){
    M1=M1-200;
    M1_pay += 200;
    
    
    M1 = check2(M1, firstpoint2, lastpoint2);
    
    
}
        else{
    M1=M1-120;
    M1_pay += 120;
    EXP1=ceil(EXP1+EXP1*0.13);
    //EXP1=ceil(EXP1_test);
    //EXP1_test=EXP1;
    
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);
    M1 = check2(M1, firstpoint2, lastpoint2);
    
    
}
if (M1_pay > M1_test*0.5) break;
   

        if(EXP1<300){
    M1=M1-100;
    M1_pay += 100;
    EXP1=ceil(EXP1-EXP1*0.1);
    //EXP1=ceil(EXP1_test);
    //EXP1_test=EXP1;
    
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);
    M1 = check2(M1, firstpoint2, lastpoint2);
  
    
}
        else{
    M1=M1-120;
    M1_pay += 120;
    EXP1=ceil(EXP1-EXP1*0.1);
    //EXP1=ceil(EXP1_test);
    //EXP1_test=EXP1;
    
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);
    M1 = check2(M1, firstpoint2, lastpoint2);
  
    
}
if (M1_pay > M1_test*0.5) break;
    }

    
    HP1 = ceil(HP1 - HP1*0.17);
    //HP1 = ceil(HP1_test);
    HP1 = check(HP1, firstpoint, lastpoint);
    //HP1_test = HP1;
    EXP1 = ceil(EXP1 + EXP1*0.17);
    //EXP1 = ceil(EXP1_test);
    //EXP1_test = EXP1;
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);

}
else if(E2%2==0){
    if(M1>0 && HP1 < 200){
    HP1=ceil(HP1 + 0.3*HP1);
    //HP1=ceil(HP1_test);
    M1=M1- 150;
    M1_pay += 150;
    
    M1= check2(M1, firstpoint2, lastpoint2);
    HP1 = check(HP1, firstpoint, lastpoint);
    //HP1_test=HP1;    
   
}
     
    else if(M1>0 && HP1 >=200){
    HP1=ceil(HP1 + 0.1*HP1);
    //HP1=ceil(HP1_test);
    M1=M1 - 70;
    M1_pay += 70;
    
        HP1 = check(HP1, firstpoint, lastpoint);
        M1 = check2(M1, firstpoint2, lastpoint2);
      
        //HP1_test=HP1;
    }
    
   

        if(M1>0 && EXP1<400){
    M1=M1-200;
    M1_pay += 200;
    
  
    M1 = check2(M1, firstpoint2, lastpoint2);
   
    
}
        else if(M1>0 && EXP1 >=400){
    M1=M1-120;
    M1_pay += 120;
    EXP1=ceil(EXP1+EXP1*0.13);
    //EXP1=ceil(EXP1_test);
    //EXP1_test=EXP1;
    
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);
    M1 = check2(M1, firstpoint2, lastpoint2);
   
    
}
   

        if(M1>0 && EXP1<300){
    M1=M1-100;
    M1_pay += 100;
    EXP1 = ceil(EXP1-EXP1*0.1);
    //EXP1=ceil(EXP1_test);
    //EXP1_test=EXP1;
    
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);
    M1 = check2(M1, firstpoint2, lastpoint2);
  
    
}
        else if(M1>0 && EXP1 >=300){
    M1=M1-120;
    M1_pay += 120;
    EXP1=ceil(EXP1-EXP1*0.1);
   
    
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);
    M1= check2(M1, firstpoint2, lastpoint2);
   
    
}
    
    HP1 = ceil(HP1 - HP1*0.17);
    //HP1 = ceil(HP1_test);
    HP1 = check(HP1, firstpoint, lastpoint);
    //HP1_test = HP1;
    EXP1 = ceil( EXP1 + EXP1*0.17);
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);
 }

float P2;
if (findNearestPerfectSquare(EXP1)<EXP1){
           P2=100;
}
else {
           P2=((float)EXP1/findNearestPerfectSquare(EXP1) +80)/123;
           P2=P2*100;    
}
//con duong 3 
int P3[]={32,47,28,79,100,50,22,83,64,11};
int k;
int hangchuc = E2/10;
int hangdonvi = E2%10;
int tong = hangchuc + hangdonvi;

if (E2<10) {
    k=E2;
    }
else{
    if(tong>9){
    k = tong%10;
    }
    else{
    k=tong;
    }
   }

if (P1==100 && P2==100 && P3[k]==100){
    EXP1 -= EXP1*0.25;
    EXP1 = check3(EXP1, firstpoint3, lastpoint3);
}
else if(P1 !=100 || P2 != 100 || P3[k] !=100){
    float P = (P1+P2+P3[k])/3;
     if (P < 50){
        HP1 -= ceil(HP1*0.15);
        EXP1 += ceil(EXP1*0.15);
        EXP1 = check3(EXP1, firstpoint3, lastpoint3);
        HP1 = check(HP1, firstpoint, lastpoint);
     }
     else{
        HP1 = ceil(HP1 - HP1*0.1);
        EXP1 += ceil(EXP1*0.2);
        EXP1 = check3(EXP1, firstpoint3, lastpoint3);
        HP1 = check(HP1, firstpoint, lastpoint);
     }
}
return HP1+EXP1+M1;
}

// Task 3
int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum >= 10 ? sumDigits(sum) : sum;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    
int map[10][10] = {0};
int maxDiem[10][10] = {0};
// Tạo map điểm số taxi
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }
}
// Tính điểm số tuyệt đối lớn nhất từ đường chéo cho Sherlock và Watson
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        int maxDiemDuongcheo = INT_MIN;
        // Đường chéo trái
        for (int k = 0; k < 10; k++) {
            if (i + k < 10 && j + k < 10)
                maxDiemDuongcheo = max(maxDiemDuongcheo, map[i + k][j + k]);
            if (i - k >= 0 && j - k >= 0)
                maxDiemDuongcheo = max(maxDiemDuongcheo, map[i - k][j - k]);
        }
        // Đường chéo phải
        for (int k = 0; k < 10; k++) {
            if (i + k < 10 && j - k >= 0)
                maxDiemDuongcheo = max(maxDiemDuongcheo, map[i + k][j - k]);
            if (i - k >= 0 && j + k < 10)
                maxDiemDuongcheo = max(maxDiemDuongcheo, map[i - k][j + k]);
        }
        maxDiem[i][j] = abs(maxDiemDuongcheo);
    }
}
// Tìm điểm gặp nhau
int gaptaiI = 0, gaptaiJ = 0, DuongE3 = 0, AmE3 = 0;
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        if (map[i][j] > E3 * 2) DuongE3++;
        if (map[i][j] < -E3) AmE3++;
    }
}
gaptaiI = sumDigits(DuongE3);
gaptaiJ = sumDigits(AmE3);

// Bắt được hay không
int DiemTaxi = map[gaptaiI][gaptaiJ];
int DiemSvaW = maxDiem[gaptaiI][gaptaiJ];
bool batDuoc = abs(DiemTaxi) <= DiemSvaW;

// Tăng giảm HP và EXP
if (batDuoc) {
    HP1 = min(666, int(HP1 * 1.10));
    HP2 = min(666, int(HP2 * 1.10));
    EXP1 = min(600, int(EXP1 * 1.12));
    EXP2 = min(600, int(EXP2 * 1.12));
} else {
    HP1 = max(0, int(HP1 * 0.90));
    HP2 = max(0, int(HP2 * 0.90));
    EXP1 = max(0, int(EXP1 * 0.88));
    EXP2 = max(0, int(EXP2 * 0.88));
}
    return (abs(DiemTaxi) > DiemSvaW ? DiemTaxi : DiemSvaW);
}

// Task 4
int checkPassword(const string& s, const string& email) {
    // Tìm chuỗi se
    string se = email.substr(0, email.find('@'));

    // Kiểm tra độ dài của s
    if (s.length() < 8) return -1;
    if (s.length() > 20) return -2;

    // Kiểm tra s không chứa se
    if (s.find(se) != string::npos) return -(300 + s.find(se));

    // Kiểm tra ký tự đặc biệt và không quá 2 ký tự liên tiếp giống nhau
    bool hasSpecialChar = false;
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        
        // Kiểm tra ký tự đặc biệt
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') hasSpecialChar = true;

        // Kiểm tra ký tự hợp lệ
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') return i;

        // Kiểm tra không quá 2 ký tự liên tiếp giống nhau
        if (i >= 2 && c == s[i - 1] && c == s[i - 2]) return -(400 + i - 2);
    }

    // Kiểm tra ký tự đặc biệt
    if (!hasSpecialChar) return -5;

    // Nếu không có lỗi, trả về -10
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int maxCount = 0;
    size_t maxLength = 0;
    const char *correctPassword = nullptr;  // Sử dụng const char* thay cho string
    int position = -1;

    // Duyệt qua mảng để đếm số lần xuất hiện
    for (int i = 0; i < num_pwds; ++i) {
        int count = 0; // Biến để lưu số lần xuất hiện của mật khẩu hiện tại

        // Kiểm tra số lần xuất hiện của mật khẩu hiện tại trong toàn bộ mảng
        for (int j = 0; j < num_pwds; ++j) {
            if (std::strcmp(arr_pwds[j], arr_pwds[i]) == 0) {
                count++;
            }
        }

        size_t length = std::strlen(arr_pwds[i]);

        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            correctPassword = arr_pwds[i];
            position = i; // Cập nhật vị trí mới khi tìm thấy mật khẩu thích hợp hơn
        }
    }

    return position; // Trả về vị trí đầu tiên của mật khẩu đúng
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////