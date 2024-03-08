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
int firstMeet_TH1(int &exp1, int &exp2, int e1){

    if (e1 > 99 || e1 < 0) return -99;
    int D;

    
    if (e1 == 0) exp2 += 29;
    else if (e1 == 1) exp2 += 45;
    else if (e1 == 2) exp2 += 75;
    if (e1 == 3) exp2+=(29+45+75);

    D = e1*3 + exp1*7;
    if (D % 2 != 0){
        exp1 = ceil(exp1 -((double)D/100));
    }
    else  exp1 = ceil(exp1 +((double)D/200));

    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    if (exp2 < 0) exp2 = 0;

    return (exp1 + exp2);

}

int firstMeet_TH2(int &exp1, int &exp2, int e1){
    if (e1 >= 4 && e1 <= 19){
       exp2 = ceil(exp2 + (double)e1/4 + 19);
    }
    else if (e1 >= 20 && e1 <=49){
        exp2 = ceil(exp2 + (double)e1/9 + 21);
    }
    else if (e1 >= 50 && e1 <= 65){
        exp2 = ceil(exp2 + (double)e1/16 + 17);
    }
    else if (e1 >= 66 && e1 <= 79){
       exp2 = ceil(exp2 + (double)e1/4 + 19);
       if (exp2 > 200){
          exp2 = ceil(exp2 + (double)e1/9 + 21);
       }
    }
    else if (e1 >= 80 && e1 <= 99){
        exp2 = ceil(exp2 + (double)e1/4 + 19);
        exp2 = ceil(exp2 + (double)e1/9 + 21);
        if (exp2 > 400){
            exp2 = ceil(exp2 + (double)e1/16 + 17);
            exp2 = ceil(exp2 * 1.15);
        }
    }
    else return -99 ;

    exp1 = exp1 - e1;
    if (exp2 > 600) exp2 = 600;
    if (exp2 < 0) exp2 = 0;

    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    
    return (exp1 + exp2);
}

int firstMeet(int &exp1, int &exp2, int e1){
   if (e1 >= 0 && e1 <= 3){
    return firstMeet_TH1(exp1, exp2, e1);
   }
   else if (e1 >= 4 && e1 <= 99){
    return firstMeet_TH2(exp1, exp2, e1);
   }
   else return -99 ;

}
// Task 2
//Tìm số chính phương
int timSoChinhPhuongGannhat(int & EXP1){
    if (EXP1 > 600) EXP1 = 600;
    int k = sqrt(EXP1);
    int soChinhphuong;
    bool ok = false;
    int i = 0;
    while (i*i <= EXP1){
        if (i*i == EXP1) {
            ok = true;
        }
         ++i;
    }
    if (ok){
        soChinhphuong = EXP1;
    }
    else {
    int sotruoc = k+1;
    int hieutruoc = abs(EXP1 - k*k);
    int hieusau = abs(EXP1 - sotruoc*sotruoc);
    if (hieutruoc < hieusau){
        soChinhphuong = k*k;
    }
    else soChinhphuong = sotruoc*sotruoc;
    }
    return soChinhphuong;
}
//Task 2 - Con đường 1
double traceLuggage_road1 (int & EXP1){
    double p1;
    double rounded_p1;
    int s = timSoChinhPhuongGannhat(EXP1);
    if (EXP1 >= s){
       p1 = 1;
    }
    else {
        p1 = ((double)EXP1/s + 80)/123;
        //rounded_p1 = round(p1 * 100) / 100;
    }
    return p1;

}

void exitFunction(){
    return;
}
//Task 2 - Con đường 2
double traceLuggage_road2 (int & HP1, int & EXP1, int & M1, int E2){
    int m1_before = M1;
    int m1_used = 0;
    double p2, rounded_p2;
    bool m1_out = false;
    //E2 là số lẻ
    if (E2 % 2 != 0){
        while (m1_used <= (m1_before * 0.5)){
            //Dừng chân
            if (HP1 < 200){
                HP1 = ceil((double)HP1 * 1.3 - 0.00000001);
                if (HP1 > 666) HP1 = 666;
                if (HP1 < 0) HP1 = 0;
                M1 = M1 - 150;
                m1_used += 150;
                if (m1_used > (m1_before * 0.5)) break;
            }
            else if (HP1 >= 200) {
                HP1 = ceil((double)HP1 * 1.1 - 0.00000001);
                if (HP1 > 666) HP1 = 666;
                if (HP1 < 0) HP1 = 0;
                M1 = M1 - 70;
                m1_used += 70;
                if (m1_used > (m1_before * 0.5)) break;
            }
            //Thuê taxi hoặc xe ngựa
            if (EXP1 < 400){
                EXP1 = ceil((double)EXP1 * 1.13 - 0.00000001);
                M1 = M1 - 200;
                m1_used += 200;
                if (m1_used > (m1_before * 0.5)) break;
            }
            else if (EXP1 >= 400) {
                EXP1 = ceil((double)EXP1 * 1.13 - 0.00000001);
                M1 = M1 - 120;
                m1_used += 120;
                if (m1_used > (m1_before * 0.5)) break;
            }
            
            //Gặp người vgc và tiết lộ manh mối
            if (EXP1 < 300){
                M1 = M1 - 100;
                m1_used += 100;
                EXP1 = ceil((double)EXP1 * 0.9 - 0.00000001);
                if (m1_used > (m1_before * 0.5)) break;
            }
            else if (EXP1 >= 300) {
                M1 = M1 - 120;
                m1_used += 120;
                EXP1 = ceil((double)EXP1 * 0.9 - 0.00000001);
                if (m1_used > (m1_before * 0.5)) break;
            }

            
        }
        if (M1 <= 0) M1 = 0;
        HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);

        int s = timSoChinhPhuongGannhat(EXP1);
        if (EXP1 >= s){
        p2 = 1;
        }
        else {
        p2 = ((double)EXP1/s + 80)/123;
        //rounded_p2 = round(p2 * 100) / 100;
        }
        return p2;
        
    }
    
    //E2 là số chẵn
    else {
        if (M1 <= 0){
            M1 = 0;
            HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);
            int s = timSoChinhPhuongGannhat(EXP1);
            if (EXP1 >= s){
            p2 = 1;
            }
            else {
            p2 = ((double)EXP1/s + 80)/123;
            //rounded_p2 = round(p2 * 100) / 100;
            }
            return p2;
        }
        //Dừng chân
            if (HP1 < 200){
                HP1 = ceil((double)HP1 * 1.3 - 0.00000001);
                if (HP1 > 666) HP1 = 666;
                M1 = M1 - 150;
                m1_used += 150;
                if (M1 <= 0){
                    M1 = 0;
            HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
            if (HP1 > 666) HP1 = 666;
            EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);
            int s = timSoChinhPhuongGannhat(EXP1);
            if (EXP1 >= s){
            p2 = 1;
            }
            else {
            p2 = ((double)EXP1/s + 80)/123;
            //rounded_p2 = round(p2 * 100) / 100;
            }
            return p2;
        }
                
            }
            else if (HP1 >= 200) {
                HP1 = ceil((double)HP1 * 1.1 - 0.00000001);
                if (HP1 > 666) HP1 = 666;
                M1 = M1 - 70;
                m1_used += 70;
                if (M1 <= 0){
                    M1 = 0;
            HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);
            int s = timSoChinhPhuongGannhat(EXP1);
            if (EXP1 >= s){
            p2 = 1;
            }
            else {
            p2 = ((double)EXP1/s + 80)/123;
            //rounded_p2 = round(p2 * 100) / 100;
            }
            return p2;
        }
               
            }
            //Thuê taxi hoặc xe ngựa
            if (EXP1 < 400){
                EXP1 = ceil((double)EXP1 * 1.13 - 0.00000001);
                
                M1 = M1 - 200;
                m1_used += 200;
                if (M1 <= 0){
                    M1 = 0;
            HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);
            int s = timSoChinhPhuongGannhat(EXP1);
            if (EXP1 >= s){
            p2 = 1;
            }
            else {
            p2 = ((double)EXP1/s + 80)/123;
            //rounded_p2 = round(p2 * 100) / 100;
            }
            return p2;
        }
                
            }
            else if (EXP1 >= 400) {
                EXP1 = ceil((double)EXP1 * 1.13 - 0.00000001);
                M1 = M1 - 120;
                m1_used += 120;
                if (M1 <= 0){
                    M1 = 0;
            HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);
            int s = timSoChinhPhuongGannhat(EXP1);
            if (EXP1 >= s){
            p2 = 1;
            }
            else {
            p2 = ((double)EXP1/s + 80)/123;
            //rounded_p2 = round(p2 * 100) / 100;
            }
            return p2;
        }
                
            }
            
            //Gặp người vgc và tiết lộ manh mối
            if (EXP1 < 300){
                M1 = M1 - 100;
                m1_used += 100;
                EXP1 = ceil((double)EXP1 * 0.9 - 0.00000001);
                if (M1 <= 0){
                    M1 = 0;
            HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);
            int s = timSoChinhPhuongGannhat(EXP1);
            if (EXP1 >= s){
            p2 = 1;
            }
            else {
            p2 = ((double)EXP1/s + 80)/123;
            //rounded_p2 = round(p2 * 100) / 100;
            }
            return p2;
        }
               
            }
            else if (EXP1 >= 300) {
                M1 = M1 - 120;
                m1_used += 120;
                EXP1 = ceil((double)EXP1 * 0.9);
                if (M1 <= 0){
                    M1 = 0;
            HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
            if (HP1 > 666) HP1 = 666;
            EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);
            int s = timSoChinhPhuongGannhat(EXP1);
            if (EXP1 >= s){
            p2 = 1;
            }
            else {
            p2 = ((double)EXP1/s + 80)/123;
            //rounded_p2 = round(p2 * 100) / 100;
            }
            return p2;
        }
            }
            
            
            if (M1 <= 0) M1 = 0;

            HP1 = ceil((double)HP1 * 0.83 - 0.00000001);
            if (HP1 > 666) HP1 = 666;
            EXP1 = ceil((double)EXP1 * 1.17 - 0.00000001);

            int s = timSoChinhPhuongGannhat(EXP1);
            if (EXP1 >= s){
            p2 = 1;
            }
            else {
            p2 = ((double)EXP1/s + 80)/123;
            //rounded_p2 = round(p2 * 100) / 100;
            }
            return p2;
            
    }
}


//Task 2 - Con đường 3
double traceLuggage_road3(int E2){
    double p3;
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    // i từ 0 đến 9
    int i = 0, soDuoctach = 0, tong = 0;
    string s = to_string(E2);
    int soChuso = s.length();
    if (soChuso == 1){
       i = E2;
       p3 = p[i];
    }
    else {
    for (int i = 0; i < soChuso; i++){
        tong += (s[i] - '0'); //chuyển kí tự thành số 
    }
    string chuoiTong = to_string(tong);
    int k = chuoiTong[chuoiTong.length() - 1] - '0';

    i = k;
    p3 = p[i];

    
    }

    return (p3/100);

}



int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 > 99 || E2 < 0) return -99;
   double p1 = traceLuggage_road1(EXP1);
   double p2 = traceLuggage_road2(HP1, EXP1, M1, E2);
   double p3 = traceLuggage_road3(E2);
   double p = (p1 + p2 + p3)/3;
   

   if (p == 1.0){
      EXP1 = ceil((double)EXP1 * 0.75 - 0.00000001);
       if (EXP1 > 600) EXP1 = 600;
        if (EXP1 <= 0) EXP1 = 0;
        if (HP1 > 666) HP1 = 666;
        if (HP1 <= 0) HP1 = 0;
        if (M1 > 3000) M1 = 3000;
        if (M1 < 0) M1 = 0;
      return EXP1 + HP1 + M1;
   }
   if (p < 0.5){
        HP1 = ceil((double)HP1 * 0.85 - 0.00000001);
        EXP1 = ceil((double)EXP1 * 1.15 - 0.00000001);
        
      }
      else {
        HP1 = ceil((double)HP1 * 0.9 - 0.00000001);
        EXP1 = ceil((double)EXP1 * 1.2 - 0.00000001);
    
      }
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 <= 0) EXP1 = 0;
        if (HP1 > 666) HP1 = 666;
        if (HP1 <= 0) HP1 = 0;
        if (M1 > 3000) M1 = 3000;
        if (M1 < 0) M1 = 0;
   
    return EXP1 + HP1 + M1;
}




// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 > 99 || E3 < 0) return -99;
    //Khởi tạo mảng
    int a[10][10] = {{0}};
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int cntDuong = 0, cntAm = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (a[i][j] > 0 && a[i][j] > (E3 * 2))
            ++cntDuong;
            if (a[i][j] < 0 && a[i][j] < -E3)
            ++cntAm;
        }
    } 
    
    //Tinh i
    int i = 0;
    string cntDuong_string = to_string(cntDuong);
    int IntDuong = 0;
    for (int i = 0; i < cntDuong_string.length(); i++){
       IntDuong += (cntDuong_string[i] - '0');
    }
    
    string IntDuong_string = to_string(IntDuong);
    int IntDuong2 = 0;
    if (IntDuong_string.length() > 1){
        for (int i = 0; i < IntDuong_string.length(); i++){
        IntDuong2 += (IntDuong_string[i] - '0');
        }
        i = IntDuong2;
    }
    else {
        i = IntDuong;
    }

    //Tinh j
    int j = 0;
    string cntAm_string = to_string(cntAm);
    int IntAm = 0;
    for (int i = 0; i < cntAm_string.length(); i++){
        IntAm += (cntAm_string[i] - '0');
    }

    string IntAm_string = to_string(IntAm);
    int IntAm2 = 0;
    if (IntAm_string.length() > 1){
        for (int i = 0; i < IntAm_string.length(); i++){
            IntAm2 += (IntAm_string[i] - '0');
        }
        j = IntAm2;
    }
    else {
        j = IntAm;
    }
    
    //Luu toa do taxi
    int iTaxi = i;
    int jTaxi = j;

    //Tinh diem so
    //Duong cheo phai - duoi
    int MaxCheoPhaiDuoi = a[iTaxi][jTaxi];
    for (int i = iTaxi; i < 10; i++){
         if (MaxCheoPhaiDuoi < a[i][jTaxi - (i - iTaxi)]) MaxCheoPhaiDuoi = a[i][jTaxi - (i - iTaxi)];
    }
    //Duong cheo phai - tren
    int MaxCheoPhaiTren = a[iTaxi][jTaxi];
    for (int i = iTaxi; i > 0; i--){
        if (MaxCheoPhaiTren < a[i][abs(i - iTaxi) + jTaxi]) MaxCheoPhaiTren = a[i][abs(i - iTaxi) + jTaxi];
        if (abs(i - iTaxi) + jTaxi == 9) break;
       
    }
    
    int MaxCheoPhai = max(MaxCheoPhaiDuoi, MaxCheoPhaiTren);
    

    //Duong cheo trai - duoi
    int MaxCheoTraiDuoi = a[iTaxi][jTaxi];
    for (int i = iTaxi; i < 10; i++){
        if (MaxCheoPhaiDuoi < a[i][abs(i - iTaxi) + jTaxi]) MaxCheoTraiDuoi = a[i][10 - i + 1];
    }

    //Duong cheo trai - tren
    int MaxCheoTraiTren = a[iTaxi][jTaxi];

    for (int i = iTaxi; i >= 0; i--){
        if (MaxCheoTraiTren < a[i][i + abs(iTaxi - jTaxi)]) MaxCheoTraiTren = a[i][i + abs(iTaxi - jTaxi)];
    }
    
    int MaxCheoTrai = max(MaxCheoTraiDuoi, MaxCheoTraiTren);

    int diemSo = max(MaxCheoPhai, MaxCheoTrai);
    int taxiLocate = a[iTaxi][jTaxi];

    if (diemSo > abs(a[iTaxi][jTaxi])){
        EXP1 = ceil(EXP1 * 1.12 - 0.00000001);
        if (EXP1 > 600) EXP1 = 600;
        EXP2 = ceil(EXP2 * 1.12 - 0.00000001);
        if (EXP2 > 600) EXP2 = 600;

        HP1 = ceil(HP1 * 1.1 - 0.00000001);
        if (HP1 > 666) HP1 = 666;
        HP2 = ceil(HP2 * 1.1 - 0.00000001);
        if (HP2 > 666) HP2 = 666;

        return diemSo;
    }
    else{
        EXP1 = ceil(EXP1 * 0.88 - 0.00000001);
        if (EXP1 > 600) EXP1 = 600;
        EXP2 = ceil(EXP2 * 0.88 - 0.00000001);
        if (EXP2 > 600) EXP2 = 600;

        HP1 = ceil(HP1 * 0.9 - 0.00000001);
        if (HP1 > 666) HP1 = 666;
        HP2 = ceil(HP2 * 0.9 - 0.00000001);
        if (HP2 > 666) HP2 = 666;

        return taxiLocate;
    }
   
    


}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se = "";
    int cntLetter = 0;
    for (int i = 0; email[i] != '@'; i++){
        se += email[i];
        ++cntLetter;
    }
    
    int sizeS = 0;
    bool validLength = false, validno_se = false, validnoNextsame = false, valid_al1special = false;
    while (s[sizeS] != '\0') ++sizeS;
    if (sizeS < 8) return -1;
    if (sizeS > 20) return -2;
    if (sizeS >= 8 && sizeS <= 20) validLength = true;

    //Kiểm tra s có chứa se
    for (int i = 0; i < sizeS; i++) {
        if (se.empty()) return -300;
        if (s[i] == se[0]) {
            int count = 0;

            for (int j = 0; j < se.length(); j++) {
                if (s[j + i] == se[j])
                count += 1;
                else
                break;
            }

            if (count == se.length()){
               return -(300 + i);
            }
    }
    }
    validno_se = true;
    
   //Kiểm tra s có chứa nhiều hơn 2 kí tự liên tiếp giống nhau
    int firstIndex = 0, len = 0;
    for (int i = 0, j = 1; s[i] && s[j - 1]; ++j) {
        if (s[i] == s[j]) continue;
        if (len < j - i) {
            len = j - i;
            firstIndex = i;
        }
        i = j;
    }
    if (len > 2) return -(400 + firstIndex);
    else validnoNextsame = true;

    //Kiểm tra s không chứa kí tự đặc biệt
    int cntSpecial = 0;
    for (int i = 0; i < sizeS; i++){
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') ++cntSpecial;
    }
    if (cntSpecial == 0) return -5;
    else {
      valid_al1special = true;
    }
    
    if (valid_al1special){
        for (int i = 0; i < sizeS; i++){
        if (!isdigit(s[i]) && !isalpha(s[i]) && (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')) return i; 
        }  
    }
    
    
    //Kiểm tra s đạt tiêu chuẩn
    if (validLength && validno_se && validnoNextsame && valid_al1special) return -10;
    
    
    
   return -99;
   }

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string arr[num_pwds];
    for (int i = 0; i < num_pwds; i++){
        arr[i] = arr_pwds[i];
    }
    
    
    bool hasVisited[num_pwds] = {false};
    int maxCnt = 0;
    int maxLength = 0;
    string mostFrequence = "";
    
    for (int i = 0; i < num_pwds; i++){
        if (hasVisited[i]) continue;
        int cnt = 1;

        for (int j = i + 1; j < num_pwds; j++){
            if (arr[i] == arr[j]){
                ++cnt;
                hasVisited[j] = true;
            }
        }
        
        int cntLength = 0;
        while (arr[i][cntLength] != '\0') ++cntLength;
        
        if (cnt > maxCnt || (cnt == maxCnt && cntLength > maxLength)){
            maxCnt = cnt;
            mostFrequence = arr[i];
            maxLength = cntLength;
        }

    }
    for (int i = 0; i < num_pwds; i++){
        if (arr[i] == mostFrequence){
            return i;
        } 
        
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////