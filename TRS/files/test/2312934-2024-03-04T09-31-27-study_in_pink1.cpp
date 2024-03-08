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




//check Money
int checkmoney(int &money) {
    if (money > 3000) {
        money = 3000;
    }
    else if (money <0){
        money = 0;
    }
    return money;
}

//Check HP
int checkhp(int &HP){
    if(HP<0){
        HP = 0;
    }
    else if(HP>666){
        HP = 666;
    }
    return HP;
}
//check EXP
int checkexp(int &EXP){
    if(EXP >600){
        EXP = 600;
    }
    else if(EXP < 0){
        EXP = 0;
    }
        return EXP;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Kiem tra exp1 va exp2
    if(e1<0 || e1>99){
        return -99;
    }
    checkexp(exp1);
    checkexp(exp2);
    int D;// Khai bao gia tri D 
    //Truong hop 1
    if(e1 >= 0 && e1<=3){
        if(e1==0){
            exp2 = exp2 + 29;
            checkexp(exp2);
        }
        else { if(e1==1){
            exp2 = exp2 + 45;
            checkexp(exp2);
                    }
                    else {if(e1==2){
                        exp2 = exp2 + 75;
                        checkexp(exp2);
                    }
                        else{ if(e1==3){
                            exp2 = exp2 + 29 ;checkexp(exp2);
                            exp2 = exp2 + 45 ;checkexp(exp2);
                            exp2 = exp2 + 75;checkexp(exp2);
                            
                            
                    }}
    }}// Tinh gia tri so nguyen D
        D = e1*3 + exp1*7;
        // Neu D chan 
        if((D%2)==0){
            exp1 = exp1 + (float)D/200 + 0.999;
            checkexp(exp1);
        }
        //Neu D le 
        else exp1 = exp1 - (float)D/100 + 0.999;
        checkexp(exp1);
        // Kiem tra lai gia tri cua exp1 va exp2
        if(exp1 >600){
        exp1 = 600;
    }
    else if(exp1 < 0){
        exp1 = 0;
    }
    if(exp2 >600){
        exp2 = 600;
    }
    else if(exp2 < 0){
        exp2 = 0;
    }
    }// Truong hop 2
    else if(e1>=4 && e1<=99){
        if(e1>=4 && e1<=19){
            exp2 = exp2 + (float)e1/4 + 19 + 0.999;
            checkexp(exp2);
            exp1 = exp1 - e1;
            checkexp(exp1);
        }
        else{ if(e1>=20 && e1<=49){
            exp2 = exp2 + (float)e1/9 + 21 + 0.999;
            checkexp(exp2);
            exp1 = exp1 - e1;
            checkexp(exp1);
        }
            else{ if(e1>=50 && e1<=65){
                exp2 = exp2 + (float)e1/16 +17 + 0.999;
                checkexp(exp2);
                exp1 = exp1 - e1;
            checkexp(exp1);
            }
                else{ if(e1>=66 && e1<=79){
                    exp2 = exp2 + (float)e1/4 +19 + 0.999;
                    checkexp(exp2);
                    exp1 = exp1 - e1;
                    checkexp(exp1);
                    if(exp2 > 200){
                        exp2 = exp2 + (float)e1/9 + 21 + 0.999;
                        checkexp(exp2);
                    }}
                    else{ if(e1>=80 && e1<=99){
                        exp1 = exp1 - e1;
                        checkexp(exp1);
                        exp2 = exp2 + (float)e1/4 + 19 + 0.999;
                        checkexp(exp2);
                        exp2 = exp2 + (float)e1/9 + 21 + 0.999;
                        checkexp(exp2);
                        if(exp2 > 400){
                            exp2 = exp2 + (float)e1/16 + 17 + 0.999;
                            checkexp(exp2);
                            exp2 = (float)1.15*exp2 + 0.999;
                            checkexp(exp2);
                        }
                    }
                }
            }
        }
    }
    }
    return exp1 + exp2;
}



//Ham xac dinh so chinh phuong gan nhat:
double sochinhphuonggannhat(int EXP1){
    double canhai = (double)sqrt(EXP1);
    double songuyenbe = floor(canhai);
    double songuyenlon = ceil(canhai);
    return (EXP1 - songuyenbe * songuyenbe < songuyenlon * songuyenlon - EXP1) ? songuyenbe*songuyenbe : songuyenlon*songuyenlon;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2){
    // TODO: Complete this function
    if(E2<0 || E2>99){
        return -99;
    }
    checkhp(HP1);
    checkexp(EXP1);
    checkmoney(M1);
    
    double P1, P2, P3, P4;
int S = sochinhphuonggannhat(EXP1);
//Way1
if(EXP1 >=S){
P1 = 1.0; //100%
}
else P1 = ((double)EXP1/S + 80)/123 ;
//Way2
//E la so le
if((E2%2) == 1){
    double motnua = (double)M1*0.5;
    while ((E2%2) == 1){
        if(M1 == 0){
        break;
    }
    
if(HP1 < 200){
HP1 = HP1 + (float)HP1*0.3 + 0.999; checkhp(HP1);
M1 = M1 - 150 ; checkmoney(M1);
if(M1 < motnua){
    break;
}
}
else {
    HP1 = HP1 + (float)HP1*0.1 + 0.999; checkhp(HP1);
    M1 = M1 - 70 ; checkmoney(M1); 
    if(M1 < motnua){
    break;
}
}
if(EXP1 < 400){
    //di taxi
    M1 = M1 - 200; checkmoney(M1);
    EXP1 = EXP1 + (float)EXP1*0.13 + 0.999; checkexp(EXP1);
    if(M1 < motnua){
    break;
}
}
//di xe ngua
else{
    M1 = M1 - 120; checkmoney(M1);
    EXP1 = EXP1 + (float)EXP1*0.13 + 0.999; checkexp(EXP1);
    if(M1 < motnua){
    break;
}
}
// vo gia cu
if(EXP1 < 300){
    M1 = M1 - 100; checkmoney(M1);
    EXP1 = EXP1 - (float)EXP1*0.1 + 0.999; checkexp(EXP1);
    if(M1 < motnua){
    break;
}
}
else {
    M1 = M1 - 120; checkmoney(M1);
    EXP1 = EXP1 - (float)EXP1*0.1 + 0.999; checkexp(EXP1);
    if(M1 < motnua){
    break;
}
}
}
HP1 = HP1 - (float)HP1*0.17 + 0.999; checkhp(HP1);
EXP1 = EXP1 + (float)EXP1*0.17 + 0.999; checkexp(EXP1);}
// E LA SO CHAN
else if((E2%2) == 0){
     for(int i=1; i <= 1; i++){
if(HP1 < 200){   
HP1 = HP1 + (float)HP1*0.3 + 0.999; checkhp(HP1);
M1 = M1 - 150 ; checkmoney(M1);
if(M1 == 0){
    break;
}}

else {
    HP1 = HP1 + (float)HP1*0.1 + 0.999; checkhp(HP1);
    M1 = M1 - 70 ; checkmoney(M1); 
    if(M1 == 0){
    break;
}
}
if(EXP1 < 400){
    //di taxi
    M1 = M1 - 200; checkmoney(M1);
    EXP1 = EXP1 + (float)EXP1*0.13 + 0.999; checkexp(EXP1);
    if(M1 == 0 ){
    break;
}
}
//di xe ngua
else{
    M1 = M1 - 120; checkmoney(M1);
    EXP1 = EXP1 + (float)EXP1*0.13 + 0.999; checkexp(EXP1);
    if(M1 == 0){
    break;
}
}
// vo gia cu
if(EXP1 < 300){
    M1 = M1 - 100; checkmoney(M1);
    EXP1 = EXP1 - (float)EXP1*0.1 + 0.999; checkexp(EXP1);
    if(M1 == 0){
    break;
}
}
else {
    M1 = M1 - 120; checkmoney(M1);
    EXP1 = EXP1 - (float)EXP1*0.1 + 0.999; checkexp(EXP1);
    if(M1 == 0){
    break;
}}}
HP1 = HP1 - (float)HP1*0.17 + 0.999; checkhp(HP1);
EXP1 = EXP1 + (float)EXP1*0.17 + 0.999; checkexp(EXP1);}
 S = sochinhphuonggannhat(EXP1);
if(EXP1 >= S){
P2 = 1.0; //100%
}
else P2 = ((double)EXP1/S + 80)/123 ;
//Way3
int P[10]={32,47,28,79,100,50,22,83,64,11};
int i;
    if (E2>=0 && E2< 10) {
        i = E2;
    } else if(E2 >= 10 && E2<=99) {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    }
     P3 = (double)P[i]/100;
    // Tinh toan lai xac xuat
    if((P1==1.0) && (P2==1.0) && (P3==1.0)){
        EXP1 = (double)EXP1*0.75 + 0.999;
        checkexp(EXP1);
    }
    else{
        P4 = (P1+P2+P3)/3;
        if(P4 < 0.5){
            HP1 = HP1 - (double)HP1*0.15 + 0.999; checkhp(HP1);
            EXP1 = (double)EXP1*1.15 + 0.999;
            checkexp(EXP1);
        }
        else if(P4 >= 0.5){
            HP1 = HP1 - (double)HP1*0.1 + 0.999; checkhp(HP1);
            EXP1 = (double)EXP1*1.2 + 0.999;
            checkexp(EXP1);
    }}
    
    return HP1 + EXP1 + M1;
}





// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99){
        return -99;
    }
    checkhp(HP1);
    checkexp(EXP1);
    checkhp(HP2);
    checkexp(EXP2);
    
    int taxi[10][10] = {0};// Mang luu tru cho taxi
    int scorefinal;
    int scoresherlock;
    int soduong, soam, sherlockpoint;
    soduong =0;
    soam=0;
    int x,y; 
    // Tinh toan diem cho mang 
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // tim so gia tri duong va gia tri am thoa man
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
           if (taxi[i][j] > E3*2){
            soduong += 1; 
           }
           else if (taxi[i][j]< (-E3)){
            soam += 1;
           }
        }
    }
    // toa do hang
    if(soduong >=0 && soduong<=9){
        x= soduong;
    }
    else if(soduong>=10  && soduong<=99){
        
        x = soduong/10 + soduong%10;
        if(x>=10 && x<=99){
           x = x/10 + x%10;
        }
        }
        // toa do cot
        if(soam >=0 && soam<=9){
        y= soam;
    }
    else if(soam>=10  && soam<=99){
        
        y = soam/10 + soam%10;
        if(y>=10 && y<=99){
           y = y/10 + y%10;
        }
        }
        // Diem gap nhau
       int diemtaxi = taxi[x][y];
       int max_left1 = taxi[x][y];
       int max_left2 = taxi[x][y];
       int max_right1 = taxi[x][y];
       int max_right2 = taxi[x][y];
       int heso1 = x, heso2 =y, heso3=x, heso4=y, heso5=x, heso6=y, heso7=x, heso8=y;
       //maxleft1
    for(int a = 0; a <10; a++){
        if(x == 0 || y == 0)
            break;
        
        --heso1 ;
        --heso2 ;
        max_left1 = max(max_left1, taxi[heso1][heso2]);
        if (heso1 == 0 || heso2 == 0 )
            break;
        
    }
    //maxleft2
    for(int a = 0; a <10; a++){
        if(x == 9 || y == 9)
            break;
        
        ++heso3 ;
        ++heso4 ;
        max_left2 = max(max_left2, taxi[heso3][heso4]);
        if (heso3 == 9 || heso4 == 9 )
            break;
        

    }
    //maxrigth1
    for(int a = 0; a <10; a++){
        if(x == 0 || y == 9)
            break;
        
        --heso5  ;
        ++heso6  ;
        max_right1 = max(max_right1, taxi[heso5][heso6]);
        if (heso5 == 0 || heso6 == 9 )
            break;
        }
        //maxright2
        for(int a = 0; a < 10; a++){
            if(x == 9 || y == 0)
                break;
            
            ++heso7  ;
            --heso8  ;
            max_right2 = max(max_right2, taxi[heso7][heso8]);
            if (heso7 == 9 || heso8 == 0 )
                break;
            
        }
        sherlockpoint = abs(max(max_left1, max(max_right1, max(max_left2, max_right2))));
        scoresherlock = max(max_left1, max(max_right1, max(max_left2, max_right2)));
        // duoi bat taxi
    if(sherlockpoint < abs(taxi[x][y])){
        EXP1 = (double)EXP1*0.88 + 0.999; checkexp(EXP1);
        EXP2 = (double)EXP2*0.88 + 0.999; checkexp(EXP2);
        HP1 = (double)HP1*0.9 + 0.999; checkhp(HP1);
        HP2 = (double)HP2*0.9 + 0.999; checkhp(HP2);
        scorefinal = taxi[x][y];
    }
    else if (sherlockpoint >= abs(taxi[x][y])){
        EXP1 = (double)EXP1*1.12 + 0.999; checkexp(EXP1);
        EXP2 = (double)EXP2*1.12 + 0.999; checkexp(EXP2);
        HP1 = (double)HP1*1.1 + 0.999; checkhp(HP1);
        HP2 = (double)HP2*1.1 + 0.999; checkhp(HP2);
         scorefinal = scoresherlock;
    }
    
    
    return scorefinal;
}

// Task 4
bool kiemtrakitu(char n) {
    return (n == '@' || n == '#' || n == '%' || n == '$' || n == '!');
}
bool kiemtrachuvaso(char t) {
    return ( t>= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9');
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
char se[100];  // khoi tao mang se 
    strncpy(se, email, strchr(email, '@') - email);  // Sao chep chuoi  email vào se từ vị trí đầu tien đến vi tri co @
    se[strchr(email, '@') - email] = '\0';  // Đat ky tu ket thuc chuoi ('\0') vao vi tri co @ trong email
    // check do dai mat khau
    int dodais = strlen(s);
    if (dodais < 8){
        return -1; 
    }
    if (dodais > 20){
        return -2;
    }
        // check s có se khong
    if (strstr(s, se) != NULL) return -(300 + (strstr(s, se) - s ));
         // check mk co 3 ky tu lien tiep va giong nhau khong
    for (int i = 0; i <= dodais - 2; i++) {
        if (s[i] == s[i + 1] && s[i+1] == s[i + 2])
            return -(400 + i); 
    }
    // check ki tu dac biet
    bool kiemtra = false;
    for (int i = 0; i < dodais; i++) {
        if (kiemtrakitu(s[i])) {
            kiemtra = true;
            break;
        }
    }
    if (kiemtra == false){
        return -5;}
    // check truong hop khac khong hop le
    for (int i = 0; i < dodais; i++) {
        if (!(kiemtrachuvaso(s[i]) || kiemtrakitu(s[i]))) // check chu va so va ki tu dac biet
            return i; // tra ve vi tri khong hop le
    }
    // Mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

  int maxtansuat = 0; //lưu trữ số lần xuất hiện nhiều nhất của 1 mk
  int maxdodai = 0;// Lưu trữ độ dài của mk xuất hiện nhiều nhất
  int vitridautien = -1;// Biến giá trị tả về vị trí đầu tiên
for (int i = 0; i < num_pwds; i++) {
        const char* password = arr_pwds[i];
        int dodai = strlen(password);

        // Đếm số lần xuất hiện của mật khẩu
        int tansuat = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(password, arr_pwds[j]) == 0)//so sánh hai chuỗi 
            {
                ++tansuat;
            }
        }
        // Kiểm tra xem có phải mật khẩu đúng không
        if (tansuat > maxtansuat || (tansuat == maxtansuat && dodai > maxdodai)) {
            maxtansuat = tansuat;
            maxdodai = dodai;
            vitridautien = i;
        }
    }
  return vitridautien;
}

 

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////