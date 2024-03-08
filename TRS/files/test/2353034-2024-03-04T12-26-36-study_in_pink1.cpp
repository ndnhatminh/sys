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
    if (e1 < 0 || e1 > 99){
        return -99;
    }
    if (exp1 < 0){
        exp1 =0;
    }
    if (exp2 < 0){
        exp2 = 0;
    }
    if (exp1 > 600){
        exp1 = 600;
    }
    if (exp2 > 600){
        exp2 = 600;
    }
    // TH1 Sherlock suy doan ve chien truong
       if (e1 >=0 && e1 <= 3){
           // thong tin 1
           if (e1 == 0){
               exp2 += 29;
               if (exp2 > 600){
                   exp2 = 600;
               }
           }
           // thong tin 2
           else if (e1 == 1){
               exp2 += 45;
               if (exp2 > 600){
                   exp2 = 600;
               }
           }
           // thong tin 3
           else if (e1 == 2){
               exp2 += 75;
               if (exp2 > 600){
                   exp2 = 600;
               }
           }
           // ca 3 thong tin
           else {
               exp2 += (75 + 45 + 29 );
               if (exp2 > 600){
                   exp2 = 600;
               }
           }
           // Tinh chi so suy doan cua Sherlock
           int d = e1 * 3 + exp1 * 7;
           // Suy doan dung
           if (d % 2 == 0){
               if ((exp1 * 1.0 + 1.0 * d / 200.0) > (int) (exp1 * 1.0 + 1.0 * d/200.0)){
                   exp1 = (int)(exp1 * 1.0 + 1.0 *d / 200.0) + 1;
               }
               else{
                   exp1 = (int)(exp1 * 1.0 + 1.0 * d / 200.0);
               }
               if (exp1 > 600){
                   exp1 = 600;
               }
           }
           // Suy doan sai
           else {
               if ((exp1 * 1.0 - 1.0 * d/100.0) > (int) (exp1 * 1.0 - 1.0 * d/100.0)){
                   exp1 = (int)(exp1 * 1.0 - 1.0 * d / 100.0) + 1;
               }
               else{
                   exp1 = (int)(exp1 * 1.0 - 1.0 * d / 100.0);
               }
               if (exp1 < 0){
                   exp1 = 0;
               }
           }
       }
       
    // TH2: Sherlock suy doan ve nguoi anh trai
       else if ( e1 >= 4 && e1 <= 99){
           //thong tin 1
           if (e1 >= 4 && e1 <= 19){
               exp2 = ceil(1.0 * exp2 + (1.0 * e1 / 4.0 + 19.0));
               if (exp2 > 600){
                   exp2 = 600;
               }
           }
           //thong tin 2
           else if (e1 <= 49){
               exp2 = ceil(1.0 * exp2 + 1.0 * e1 / 9.0 + 21.0);
               if (exp2 > 600){
                   exp2 = 600;
               }
           }
           //thong tin 3
           else if (e1 <= 65){
               exp2 = ceil (1.0 * exp2 + 1.0 * e1 / 16 + 17.0);
               if (exp2 > 600){
                   exp2 = 600;
               }
           }
           else if (e1 <= 79){
               //cap nhat exp2
               exp2 = ceil(1.0 * exp2 + (1.0 * e1 / 4.0 + 19.0));
               if (exp2 > 600){
                   exp2 = 600;
               }
               //TH lon hon 200, giai thich 2 thong tin
               if (exp2 > 200){
                   exp2 = ceil(1.0 * exp2 + 1.0 * e1 / 9.0 + 21.0);
                   if (exp2 > 600){
                       exp2 = 600;
                   }
               }
           }
           else {
               // cap nhat exp2
               exp2 = ceil(1.0 * exp2 + (1.0 * e1 / 4.0 + 19.0));
               if (exp2 > 600){
                   exp2 = 600;
               }
               exp2 = ceil(1.0 * exp2 + 1.0 * e1 / 9.0 + 21.0);
               if (exp2 > 600){
                   exp2 = 600;
               }
               //TH lon hon 400, giai thich 3 thong tin
               if (exp2 > 400){
                   exp2 = ceil (1.0 * exp2 + 1.0 * e1 / 16 + 17.0);
                   if (exp2 > 600){
                       exp2 = 600;
                   }
                   exp2 = ceil (1.0*exp2*1.15);
                   if (exp2 > 600){
                       exp2 = 600;
                   }
               }
           }
           //Sherlock bi shock
           exp1 -= e1;
           if (exp1 < 0){
               exp1 = 0;
           }
       }
       else{
           return -99;
       }
       return exp1+exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
//kiem tra gia tri dau vao
    if (E2 > 99 || E2 < 0)
        return -99;
    if (HP1 < 0){
        HP1 = 0;
    }
    if (HP1 > 666){
        HP1 = 666;
    }
    if (M1 < 0){
        M1 = 0;
    }
    if (M1 > 3000){
        M1 = 3000;
    }
    if (EXP1 < 0){
        EXP1 = 0;
    }
    if (EXP1 > 600){
        EXP1 = 600;
    }
    double P1, P2, P3;
    // con duong 1
    int Sochinhphuong;
    if (EXP1 - pow((long long)sqrt(EXP1),2) <= pow((long long)sqrt(EXP1) + 1,2) - EXP1){
        Sochinhphuong = pow((long long)sqrt(EXP1),2);
    }
    else{
        Sochinhphuong = pow((long long)sqrt(EXP1) + 1,2);
    }
    if (EXP1 >= Sochinhphuong){
        P1 = 100.0;
    }
    else{
        P1 = (1.0 * EXP1 / (1.0 * Sochinhphuong) + 80.0) / 123.0 * 100.0;
    }
    // con duong 2
    double halfmoney = 0.5 * 1.0 * M1;
    int sotienchitra = 0;
    //E2 la so le
    if (E2 % 2 == 1){
        for (int i = 1; ; i++){
            // Kiem tra M1
            if (M1 == 0){
                break;
            }
            // Su kien 1
            if (HP1 < 200){
                M1 -= 150;
                sotienchitra += 150;
                
                if (M1 < 0){
                    M1 = 0;
                }
                HP1 = ceil(HP1 * 13.0 / 10.0);
                if (HP1 > 666){
                    HP1 = 666;
                }
                
                if (sotienchitra > halfmoney){
                    break;
                }
            }
            else {
                M1 -= 70;
                sotienchitra += 70;
                
                if (M1 < 0){
                    M1 = 0;
                }
                HP1 = ceil(HP1 * 11.0 / 10.0);
                if (HP1 > 666){
                    HP1 = 666;
                }
                if (sotienchitra > halfmoney){
                    break;
                }
            }
            // Su kien 2
            if (EXP1 < 400){
                M1 -= 200;
                sotienchitra += 200;
                if (M1 < 0){
                    M1 = 0;
                }
                EXP1 = ceil (EXP1 * 113.0 / 100);
                if (EXP1 > 600){
                    EXP1 = 600;
                }
                if (sotienchitra > halfmoney){
                    break;
                }
            }
            else {
                M1 -= 120;
                sotienchitra += 120;
                if (M1 < 0){
                    M1 = 0;
                }
                EXP1 = ceil (EXP1 * 113.0 / 100);
                if (EXP1 > 600){
                    EXP1 = 600;
                }
                if (sotienchitra > halfmoney){
                    break;
                }
            }
            // Su kien 3
            if (EXP1 < 300){
                M1 -= 100;
                sotienchitra += 100;
                if (M1 < 0){
                    M1 = 0;
                }
                EXP1 = ceil (EXP1 * 9.0 /10.0);
                if (EXP1 < 0){
                    EXP1 = 0;
                }
                if (sotienchitra > halfmoney){
                    break;
                }
            }
            else {
                M1 -= 120;
                sotienchitra += 120;
                if (M1 < 0){
                    M1 = 0;
                }
                EXP1 = ceil (EXP1 * 9.0 /10.0);
                if (EXP1 < 0){
                    EXP1 = 0;
                }
                if (sotienchitra > halfmoney){
                    break;
                }
            }
            
        }
    }
    else {
        for (int i = 1; i<=1 ; i++){
            // Kiem tra M1
            if (M1 == 0){
                break;
            }
            // Su kien 1
            if (HP1 < 200){
                M1 -= 150;
                
                HP1 = ceil(HP1 * 13.0 / 10);
                if (HP1 > 666){
                    HP1 = 666;
                }
                if (M1 <= 0){
                    M1 = 0;
                    break;
                }
            }
            else {
                M1 -= 70;
                HP1 = ceil(HP1 * 11.0 / 10);
                if (HP1 > 666){
                    HP1 = 666;
                }
                if (M1 <= 0){
                    M1 = 0;
                    break;
                }
            }
            // Su kien 2
            if (EXP1 < 400){
                M1 -= 200;
                EXP1 = ceil (EXP1 * 113.0 / 100.0);
                if (EXP1 > 600){
                    EXP1 = 600;
                }
                if (M1 <= 0){
                    M1 = 0;
                    break;
                }
            }
            else {
                M1 -= 120;
                EXP1 = ceil (EXP1 * 113.0 / 100.0);
                if (EXP1 > 600){
                    EXP1 = 600;
                }
                if (M1 <= 0){
                    M1 = 0;
                    break;
                }
            }
            // Su kien 3
            if (EXP1 < 300){
                M1 -= 100;
                EXP1 = ceil (EXP1 * 9.0 /10.0);
                if (EXP1 < 0){
                    EXP1 = 0;
                }
                if (M1 <= 0){
                    M1 = 0;
                    break;
                }
            }
            else {
                M1 -= 120;
                EXP1 = ceil (EXP1 * 9.0 /10.0);
                if (EXP1 < 0){
                    EXP1 = 0;
                }
                if (M1 <= 0){
                    M1 = 0;
                    break;
                }
            }
        }
    }
    HP1 = ceil(1.0 * HP1 * 83.0 / 100.0);
    EXP1 = ceil (1.0 * EXP1 * 117.0 / 100.0);
    if (EXP1 > 600){
        EXP1 = 600;
    }
    int Sochinhphuong2;
    if (EXP1 - pow((long long)sqrt(EXP1),2) <= pow((long long)sqrt(EXP1) + 1,2) - EXP1){
        Sochinhphuong2 = pow((long long)sqrt(EXP1),2);
    }
    else{
        Sochinhphuong2 = pow((long long)sqrt(EXP1) + 1,2);
    }
    if (EXP1 >= Sochinhphuong2){
        P2 = 100.0;
    }
    else{
        P2 = (1.0 * EXP1 / (1.0 * Sochinhphuong2)+ 80.0) / 123.0 * 100;
    }
    //con duong 3
    double Pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int ordinary = 0;
    if (E2 < 10){
        ordinary += E2;
    }
    else{
        int num = E2;
        while (num != 0){
            ordinary += num % 10;
            num /= 10;
        }
        ordinary = ordinary % 10;
    }
    P3 = Pi[ordinary];
    if (P1 == 100.0 && P2 == 100.0 && P3 == 100.0){
        EXP1 = ceil (0.75 * EXP1);
    }
    else if ( 1.0 * (P1 + P2 + P3) / 3.0 < 50.0){
        HP1 = ceil (1.0 * HP1 * 0.85);
        EXP1 = ceil (1.0 * EXP1 * 115.0/100.0);
        if (EXP1 > 600){
            EXP1 = 600;
        }
    }
    else{
        HP1 = ceil (1.0 * HP1 * 0.9);
        EXP1 = ceil (1.0 * EXP1 * 120.0/100.0);
        if (EXP1 > 600){
            EXP1 = 600;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 >99){
        return -99;
    }
    // Kiem tra thong so dau vao
    if (E3 < 0 || E3 >99){
        return -99;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP1 > 666){
        HP1 = 666;
    }
    if (HP2 < 0){
        HP2 = 0;
    }
    if (HP2 > 666){
        HP2 = 666;
    }
    if (EXP1 < 0){
        EXP1 = 0;
    }
    if (EXP1 > 600){
        EXP1 = 600;
    }
    if (EXP2 < 0){
        EXP2 = 0;
    }
    if (EXP2 > 600){
        EXP2 = 600;
    }
    int wheretaxi [10][10] = {0};
    int wheresherlock [10][10] = {0};
    //Khoi tao mang cho taxi
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            wheretaxi[i][j] = (E3 * j + i * 2) * (i - j);
        }
    }
    //Dem so phan tu lon hon 2*E3 va so phan tu be hon -E3
    int countpos = 0, countneg = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (wheretaxi[i][j] > 2 * E3){
                countpos++;
            }
            if (wheretaxi[i][j] < - E3){
                countneg ++;
            }
        }
    }
    // Tinh toa do gap nhau cua Sherlock va taxi
    int a,b;
    do {
        a = countpos % 10;
        b = countpos/10;
        countpos = a+b;
    } while (countpos>9);
    
    do {
        a = countneg % 10;
        b = countneg/10;
        countneg = a+b;
    } while (countneg>9);
    
    //Xet duong cheo tinh diem cho Sherlock tai diem gap nhau
    int maxpoint = wheretaxi[countpos][countneg];
    int x = countpos, y = countneg;
    while (x != 0 && y != 0){
        x--;
        y--;
        if (wheretaxi[x][y] > maxpoint){
            maxpoint = wheretaxi[x][y];
        }
    }
    int h = countpos, t = countneg;
    while (h != 9 && t != 9){
        h++;
        t++;
        if (wheretaxi[h][t] > maxpoint){
            maxpoint = wheretaxi[h][t];
        }
    }
    int c = countpos, d = countneg;
    while(c != 0 && d != 9){
        c--;
        d++;
        if (wheretaxi[c][d] > maxpoint){
            maxpoint = wheretaxi[c][d];
        }
    }
    int m = countpos, n = countneg;
    while (m != 9 && n != 0){
        m++;
        n--;
        if (wheretaxi[m][n] > maxpoint){
            maxpoint = wheretaxi[m][n];
        }
    }
    wheresherlock[countpos][countneg]= maxpoint;
    
    if (abs(wheretaxi[countpos][countneg]) > abs(wheresherlock[countpos][countneg])){
        EXP1 = ceil(EXP1 * 88.0 / 100.0);
        EXP2 = ceil(EXP2 * 88.0 / 100.0);
        HP1 = ceil (HP1 * 9.0/ 10.0);
        HP2 = ceil(HP2 * 9.0 / 10.0);
        return (int)wheretaxi[countpos][countneg];
    }
    else {
        EXP1 = ceil(EXP1 * 112.0 / 100.0);
        EXP2 = ceil(EXP2 * 112.0 / 100.0);
        HP1 = ceil (HP1 * 110.0/ 100.0);
        HP2 = ceil(HP2 * 110.0 / 100.0);
        if (EXP1 > 600){
            EXP1 = 600;
        }
        if (EXP2 > 600) {
            EXP2 = 600;
        }
        if (HP1 > 666){
            HP1 = 666;
        }
        if (HP2 > 666){
            HP2 = 666;
        }
        return maxpoint;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    //Ep kieu tham so dau vao ve string
    string password = s;
    string superemail = email;
    //Dat ten bien thu tu cho phan tim 3 phan tu, toa do chu cai ko hop le
    int thutu = 0, toado;
    //Kiem tra do dai password
    if (password.length() < 8){
        return -1;
    }
    else if (password.length() > 20){
        return -2;
    }
    //Kiem tra password co chua chuoi truoc @ hay khong
    string beforemail = superemail.substr(0, superemail.find('@'));
    if (password.length()>= beforemail.length()){
            for (int i = 0; i <  password.length() - beforemail.length() + 1; i++){
                int dem = i;
                int kiemtra = 0;
                for (int j = i; beforemail[j-i] != '\0'; j++){
                    if (beforemail[j-i] != password[j]){
                        kiemtra = 1;
                        break;
                    }
                }
                if (kiemtra == 0){
                    return  -(300 + dem);
                }
            }
    }
    //Kiem tra co chua 3 phan tu lien ke nhau
    for (int i = 0; i <= password.length() - 3; i++){
        thutu = i;
        if (password[i] == password [i+1] && password[i+1] == password [i+2]){
            return - (400 + thutu);
        }
    }
    //Kiem tra chua it nhat 1 ki tu dac biet
    int ans = 0;
    for (int i = 0; i < password.length(); i++){
        char r = password [i];
        if (r == '@' || r == '#' || r == '%' || r == '$' || r == '!'){
            ans = 1;
            break;
        }
    }
    if (ans != 1){
        return -5;
    }
    //Kiem tra phan tu hop le
    for (int i = 0; i < password.length(); i++){
        toado = i;
        char r = password [i];
        if ((r < '0' || r > '9') && (r < 'a' || r > 'z') && (r < 'A' || r > 'Z') && r != '@' && r != '#' && r != '%' && r != '$' && r != '!'){
            return toado;
        }
            
    }
    //Password hop le thi ra ve -10
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //Khai bao bien luu tan suat va bien luu tan suat max
    int demtansuat[1000001] = {0};
    int tansuatmax = 0;
    /* Dem tan suat lan luot cac xau trong mang, neu 1 xau xuat hien nhieu thi tan suat se dung o vi tri no xuat hien dau tien */
    for (int i = 0; i < num_pwds; i++){
        demtansuat[i] = 1;
        for (int j = 0; j < i; j++){
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                demtansuat[j] ++;
            }
        }
    }
    /*Do tung vi tri va cap nhat tan suat max va vi tri max, neu co vi tri co tan suat luu trong dem tan suat = tan suat max vi tri truoc, so sanh do dai xau cua 2 vi tri do voi nha, neu vi tri hien tai lon hon thi cap nhat vi tri max*/
    int vitritansuatmax = 0;
    for (int i = 0; i < num_pwds; i++){
        if (demtansuat[i] > tansuatmax){
            tansuatmax = demtansuat[i];
            vitritansuatmax = i;
        }
        else if (demtansuat[i] == tansuatmax){
            
                if (strlen(arr_pwds[i]) > strlen(arr_pwds[vitritansuatmax])){
                    vitritansuatmax = i;
                }
            
        }
    }
    return vitritansuatmax;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
