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

//checking
void checkHp1 (int & HP1 ){
    if ( HP1 < 0 ){
        HP1 = 0;
    }else if ( HP1 >666){
        HP1 = 666;
    }
}
void checkHp2 (int & HP2 ){
    if ( HP2 < 0 ){
        HP2 = 0;
    }else if ( HP2 >666){
        HP2 = 666;
    }
} 
void checkM1 (int & M1 ){
    if ( M1 < 0 ){
        M1 = 0;
    }else if ( M1 >3000){
        M1 = 3000;
    }
}
void checkM2 (int & M2 ){
    if ( M2 < 0 ){
        M2 = 0;
    }else if ( M2 >3000){
        M2 = 3000;
    }
}
void checkEXP1 (int & EXP1 ){
    if ( EXP1 < 0 ){
        EXP1 = 0;
    }else if ( EXP1 >600){
        EXP1 = 600;
    }
}
void checkEXP2 (int & EXP2 ){
    if ( EXP2 < 0 ){
        EXP2 = 0;
    }else if ( EXP2 >600){
        EXP2 = 600;
    }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
   
    if ( e1 < 0 || e1 > 99){
        return -99;
    }
    // Truong hop 1
    checkEXP1(exp1);
    checkEXP2(exp2);
    if (e1 >= 0   && e1 <=3 ){
        if (e1==0){
            exp2 = exp2 + 29;
        }
        else if (e1==1){
            exp2 = exp2 + 45;
        }
        else if (e1==2){
            exp2 = exp2 + 75;
        }
        else if (e1==3){
            exp2 = exp2 + 29 + 45 +75;
        }
        checkEXP2(exp2);
        int D;
        D= e1*3 + exp1*7;
            if (D%2==0){
                exp1 = ceil(exp1+(double)D/200);
                checkEXP1 (exp1);
            }else {
                exp1 =ceil(exp1 -(double)D/100);
                checkEXP1 (exp1);
                }
        checkEXP2(exp2); 
    }// Truong hop 2   
    else if (e1 >= 4 && e1<=99){
        // Thong tin 1
        checkEXP2(exp2);
        if (e1>=4 && e1<=19){
            exp2 = ceil((double)exp2 + ((double)e1/4 + 19));
            checkEXP2(exp2);
        }
        // Thong tin 2
        else if (e1>=20 && e1 <= 49){
            exp2 = ceil((double)exp2 + ( (double)e1/9 + 21));
            checkEXP2(exp2);
        }
        // Thong tin 3
        else if (e1>=50 && e1 <= 65){
            exp2 = ceil((double)exp2 + ( (double)e1/16 + 17));
            checkEXP2(exp2);
        }
        // Thong tin 4
        else if (e1>=66 && e1 <= 79){
            exp2 = ceil((double)exp2 + ( (double)e1/4 + 19));
            checkEXP2(exp2);
            // Giai thich thong tin 2 
            if (exp2 > 200){
                exp2 = ceil((double)exp2 + ((double)e1/9+21));
                checkEXP2(exp2);
            }
        }
        // Thong tin 5
        else if (e1>=80 && e1 <= 99){
            exp2 = ceil((double)exp2 + ((double)e1/4 + 19));
            checkEXP2(exp2);
            exp2 = ceil((double)exp2 + ((double)e1/9 +21));
            checkEXP2(exp2);
            // Giai thich thong tin 3
            if (exp2 > 400){
                exp2 = ceil((double)exp2 + ((double)e1/16 + 17));
                checkEXP2(exp2);
                exp2 = ceil((double)exp2*1.15);
                checkEXP2(exp2);
            } 
        }
        // sherlock bi sai lam  
        exp1= exp1-e1;
        checkEXP1(exp1); 
    }
    return exp1 + exp2; 
} 
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function  
   if ( E2 < 0 || E2 > 99){
        return -99;
    }
    checkEXP1(EXP1);
    checkHp1(HP1);
    checkM1(M1);
    double P;// P : xac xuat cua ca  tuyen duong
    checkHp1(HP1); checkM1(M1); checkEXP1(EXP1);
    if (E2>0 || E2==0 && E2<99 || E2==99){  
        // Way 1
        checkEXP1(EXP1);
        float  P1, P2;
        int S1, S2;;
        double root1 = round(sqrt(EXP1));
        S1 = root1* root1;
        if (EXP1> S1|| EXP1 ==S1){
            P1 =1;
        }else {
            P1 = ((double)EXP1/S1 +80)/123 ;

        }
        //----------------------------------------------------------------
        //Way 2
        // TH e2 la so le
        if (E2%2==1){
            int pt = 0, bd = M1/2;
            //pt: so tien da tieu
            //bd: so tien ban dau
            while (true){
             // hanh dong 1 : mua thuc an
                if(pt>bd) break;
                if(M1==0) break;
                if(HP1 < 200){
                HP1=ceil((double)HP1*130/100);
                checkHp1(HP1);
                M1= M1-150;
                pt= pt + 150;
                checkM1(M1);
            }else {
                HP1 = ceil((double)HP1*110/100);
                checkHp1(HP1);
                M1= M1-70;
                pt= pt + 70;
                checkM1(M1);
            }
                if(pt>bd) break;
                if(M1==0) break;
            // hanh dong 2: di duong
            if (EXP1<400 ){
                M1 = M1-200;
                pt = pt + 200;
                EXP1 = ceil((double)EXP1*113/100);
                checkEXP1(EXP1);
                checkM1(M1);
            }else   {
                M1 = M1-120;
                pt= pt + 120;
                EXP1 = ceil((double)EXP1*113/100);
                checkEXP1(EXP1);
                checkM1(M1);
            }
                if(pt>bd) break;
                if(M1==0) break;
            checkEXP1(EXP1);
            //hanh dong 3: giup do
            if(EXP1<300 ){
                M1 = M1 - 100;
                pt = pt + 100;
                EXP1 = ceil((double)EXP1*90/100);
                checkEXP1(EXP1);
                checkM1(M1);
            }else {
                M1 = M1 -120;
                pt= pt + 120;
                EXP1 = ceil((double)EXP1*90/100);
                checkEXP1(EXP1);
                checkM1(M1);
            }
                if(pt>bd) break;
                if(M1==0) break;
            } 
            HP1 = ceil((double)HP1*83/100);
            checkHp1(HP1);
            EXP1 = ceil((double)EXP1*117/100);
            checkEXP1(EXP1);
        // truong hop E2 la so chan      
        }
        else if (E2%2==0){
            checkM1(M1);
            // nNeu M1 lon hon 0 thuc hien hanh dong 1
            if (M1 > 0){
               if(HP1 < 200){
                HP1=ceil((double)HP1*130/100);
                checkHp1(HP1);
                M1= M1-150;
                checkM1(M1);
            }else {
                HP1 = ceil((double)HP1*110/100);
                checkHp1(HP1);
                M1= M1-70;
                checkM1(M1);
            }
            checkM1(M1);
            }
            // Neu M1 van lon hon 0 thuc hien hanh dong 2
            if (M1 > 0){
                if (EXP1<400){
                M1 = M1-200;
                EXP1 = ceil((double)EXP1*113/100);
                checkEXP1(EXP1);
                checkM1(M1);
            }else {
                M1 = M1-120;
                EXP1 = ceil((double)EXP1*113/100);
                checkEXP1(EXP1);
                checkM1(M1);
            }
            }
            checkM1(M1);
            // Neu M1 van lon hon 0 thuc hien  hanh dong 3
            if (M1 > 0){
                if(EXP1<300){
                M1 = M1 - 100;
                EXP1 = ceil((double)EXP1*90/100);
                checkEXP1(EXP1);
                checkM1(M1);
            }else {
                M1 = M1 -120;
                EXP1 = ceil((double)EXP1*90/100);
                checkEXP1(EXP1);
                checkM1(M1);
            }
            }
            HP1 = ceil((double)HP1*83/100);
            checkHp1(HP1);
            EXP1 = ceil((double)EXP1*117/100);
            checkEXP1(EXP1);
        }
        // con duong 2 da hoan thanh 
    // tinh P2
    int root2 = round(sqrt(EXP1));
    S2 = root2* root2;
    if (EXP1> S2|| EXP1 ==S2){
        P2 =1;
    }else {
        P2 = ((double)EXP1/S2 +80)/123 ;
    }
    //----------------------------------------------------------------
    // Way 3
    int Pi[10] ={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    if (E2/10==0){
        P3 = ((double)Pi[E2])/100;
    }else{
        int sum;
        sum = E2/10 +E2%10;
        // sum : tong cua 2 chu so
        if (sum>0 && sum < 10){
            P3 = (double)Pi[sum]/100;
        }else{
            int sc = sum%10;
            // sc: gia tri don vi cua sum
            P3 = (double)Pi[sc]/100;
        }
    }
    P = P1 + P2 + P3; // tong cua 3 xac xuat
    if (P == 3){
        EXP1 = ceil((double)EXP1*75/100);
        checkEXP1(EXP1);
    }else{
         // truong hop tim vali kho khan
    P =P/3;
    if (P <0.5){
            checkHp1(HP1);
            HP1 = ceil((double)HP1*85/100);
            EXP1 =ceil((double)EXP1*115/100);
            checkHp1(HP1);
            checkEXP1(EXP1);
        }
        // truong hop tim vali de dang
        else {
            checkHp1(HP1);
            HP1=ceil((double)HP1*90/100);
            EXP1 = ceil((double)EXP1*120/100);
            checkEXP1(EXP1);
            checkHp1(HP1);
        }
    }  
    // con duong 3 da hoan thanh
//----------------------------------------------------------------
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
     if ( E3 < 0 || E3 > 99){
        return -99;
    }
    checkEXP1(EXP1);
    checkEXP1(EXP2);
    checkHp1(HP1);
    checkHp2(HP2);
    if (E3>0 || E3 == 0 && E3<99 || E3 == 99){
        int matrix[10][10];
        // nhap gia tri cua ma tran
        // i la so hang
        // j la so cot
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = ((E3*j)+(i*2))*(i-j);
            }
        }
        int SlDuong =0;// bien dem so phan tu duong lon hon "E3 * 2"

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++){
                if ( matrix[i][j] > (E3 * 2)){
                    SlDuong = SlDuong + 1;
                }
            }
        } // ket thuc vong lap

        int SlAm = 0;// bien dem so phan tu am nho hon "-E3"

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++){
                if ( matrix[i][j] < (-E3)){
                    SlAm = SlAm + 1;
                }
            }
        } // ket thuc vong lap

        int diem_gap_i, diem_gap_j;

        while (SlDuong > 9)
        {
            diem_gap_i = SlDuong/10 + SlDuong%10;
            SlDuong = diem_gap_i;
        }
        while (SlAm > 9)
        {
            diem_gap_j = SlAm/10 + SlAm%10;
            SlAm = diem_gap_j;
        }
        int diem_giao = matrix[diem_gap_i][diem_gap_j]; // diem taxi
        int traceDiemDao = diem_giao;
        // Tim diem lon nhat cua duong cheo trai
        int leftColPos, leftRowPos;
        if (diem_gap_i > diem_gap_j){
            leftRowPos = diem_gap_i - diem_gap_j;
            leftColPos = 0;
        }else {
            leftRowPos = 0;
            leftColPos = diem_gap_j - diem_gap_i;
        }
        int bien_cong_cot = leftColPos;
        for ( int i = leftRowPos; i < 10; i++){
             if(matrix[i][bien_cong_cot] > diem_giao){
                diem_giao = matrix[i][bien_cong_cot];
             }
             bien_cong_cot = bien_cong_cot +1;
             if( i > 9 ||bien_cong_cot > 9){
                 break;
             }
        }
        int maxLeftDioagonal = diem_giao;
        diem_giao = traceDiemDao;
        //----------------------------------------------------------------
        // Tim diem lon nhat cua duong cheo phai
        int rightColPos,rightRowPos;
        if (diem_gap_i < diem_gap_j || diem_gap_i == diem_gap_j){
            if(diem_gap_j +diem_gap_i < 9){
                rightRowPos = 0;
                rightColPos = diem_gap_i + diem_gap_j;
            }
            rightRowPos =abs(9 - (diem_gap_j +diem_gap_i));
            rightColPos = 9;
        } else {
            if(diem_gap_i + diem_gap_j < 9){
                rightRowPos = 0;
                rightColPos = diem_gap_i + diem_gap_j;
            }
            rightColPos = 9;
            rightRowPos = abs(9 - (diem_gap_i + diem_gap_j));
           
        }
        int bien_tru_cot = rightColPos;
        for (int i = rightRowPos; i < 10; i++){
            if (matrix[i][bien_tru_cot]> diem_giao){
                diem_giao = matrix[i][bien_tru_cot];
            }
            bien_tru_cot = bien_tru_cot -1;
            if (bien_tru_cot < 0 || i > 9){
                break;
            }
        }
        int maxRightDioagonal = diem_giao;
        diem_giao = traceDiemDao;
        //----------------------------------------------------------------
        // Tim gia tri lon nhat cua 2 duong cheo
        int maxDioagonal; // diem cua sherlock
        if (maxRightDioagonal > maxLeftDioagonal){
            maxDioagonal = maxRightDioagonal;
        }else {
            maxDioagonal = maxLeftDioagonal;
        }
        // truong hop khonng duoi kip
        if (abs(diem_giao) > abs(maxDioagonal)){
            EXP1 = ceil((double)EXP1*88/100 );
            EXP2 = ceil((double)EXP2*88/100 );
            HP1 = ceil((double)HP1*90/100 );
            HP2 = ceil((double)HP2*90/100 );
        }
        // truong hop duoi kip
        else{
            EXP1 = ceil((double)EXP1*112/100 );
            EXP2 = ceil((double)EXP2*112/100 );
            HP1 = ceil((double)HP1*110/100 );
            HP2 = ceil((double)HP2*110/100 );
        }
        checkEXP1(EXP1);
        checkEXP2(EXP2);
        checkHp1(HP1);
        checkHp2(HP2);
        //----------------------------------------------------------------
        // Tra ve ket qua
      if (abs(diem_giao) > abs(maxDioagonal)) {
            return diem_giao;
        } else return maxDioagonal;
    }else {
        return -99;
    }    
}
// Task 4
int checkPassword(const char *s, const char *email) {
    // chuyen sang string
    string password(s);
    string emailStr(email);
    // lay chuoi "se" tu email
    int Pos = emailStr.find('@'); // bien su dung de luu vi tri cua ky tu "@"
    string se = emailStr.substr(0, Pos);// sao chep chuoi sang bien "se" tu ki tu thu 0 den vi tri "@"              
    // kiem tra do dai cua mat khau
    int Len = password.length();
    // kiem tra so ki tu lien tiep giong nhau
    bool check = false;
    int  backUp;
    for (int i =  0; i < Len -  2; i++) {
        if (password[i] == password[i +  1] && password[i] == password[i +  2]) {
           check = true;
           backUp = i;
           break;
        }
    }
    // Kiểm tra có chứa  ít nhất  1 ký tự  đặc biệt
    bool hasSpecialChar = false;
    for (int i=0;i<(int)password.size();i++) {
        if (password[i]=='@'||password[i]=='#'||password[i]=='%'||password[i]=='$'||password[i]=='!') {
            hasSpecialChar = true;
            break;
        }
    }
    // truong hop hop le
    if (Len <  8) {
        return -1;// ky tu nho hon 8
    }if (Len >  20) {
        return -2;
    }if (password.find(se) != string::npos) {
        int sei = password.find(se);
        return  -(300 + sei);
    }if (check == true)  {
        return -(400+ backUp);
    }
    if (hasSpecialChar == false) {
         return -5 ; // kiem tra neu khong chua ky tu dac biet
    }
        for (int i = 0; i < Len; i++){
            
         if (int(s[i])<33 || int(s[i])==34||(int(s[i]) >= 38  && int(s[i]) < 48) || (int(s[i]) >= 58 && int(s[i]) <= 63   ) || (int(s[i]) >= 91  && int(s[i]) <= 96 ) || int(s[i]) >= 123){
            return i;// kiem tra cach dieu kien con lai
            break;
        }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // frepw la tan so xuat hien cua moi mat khau
    int frepw, ltn;    
    // ltn vi tri cua chuoi mat khau
    frepw  = 0;
    ltn = 0;
    const char* maxPwds = "";// maxPwds : lua chuoi co tan so xuat hien lon nhat
    for (int i = 0; i < num_pwds; i++) {
         if (arr_pwds[i] != nullptr && strcmp(arr_pwds[i], "") !=  0)// dieu kien chuoi có phai rong hay 0 ?
          {
            int AlwFre =  1;
            for (int j =  0; j < num_pwds; j++) // dem so lan xuat hien cua mat khau
            {
                if (j != i && strcmp(arr_pwds[i], arr_pwds[j]) ==  0) {
                    AlwFre++;
                }
            }
            if (AlwFre > frepw) // tim ra mat khau dai nhat
            {
                frepw = AlwFre;
                maxPwds = arr_pwds[i];
                ltn = i;
            }else if (AlwFre == frepw){
                if (strlen(arr_pwds[i]) > strlen(maxPwds)){
                    maxPwds = arr_pwds[i];
                    frepw = AlwFre;
                    ltn = i;
                }
            }
            AlwFre = 1;
        }
    }
    return ltn;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////