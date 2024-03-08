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

void limitEXP(int &EXP1) {
    if (EXP1 < 0) { EXP1 = 0;}
    if (EXP1 >600) {EXP1 = 600;}
    }
void limithp(int &HP1) {
    if (HP1 < 0) { HP1 = 0;}
    if (HP1 >666) {HP1 = 666;}
    }
void limitm(int &M1 ) {
    if (M1 < 0) { M1 = 0;}
    if (M1 >3000) {M1 = 3000;}}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    int D;
    if (E1<0||E1>99){
        return -99;
    }    limitEXP(EXP1);
    limitEXP(EXP2);


    if (E1 <= 3 && E1 >= 0) {
        D = E1 * 3 + EXP1 * 7;
        if (int(D) % 2 == 0) {
            EXP1 = ceil(EXP1+float(D/200.0)  );
        } else {
            EXP1 = ceil( EXP1-float(D/100.0)  );
        }
        if (E1 == 0) {
            EXP2 += 29;
        } else if (E1 == 1) {
            EXP2 += 45;
        } else if (E1 == 2) {
            EXP2 += 75;
        } else {
            EXP2 += 149;
        }
    }else if (E1<=99 && E1>=4){
            EXP1 -= E1;
            if (E1<=19 ){
                EXP2 = ceil(EXP2 + float(E1/4.0) + 19);

            }else if (E1<= 49){
                EXP2 = ceil(EXP2 + float(E1/9.0)  + 21 );
                
            }else if (E1<=65){
                EXP2 = ceil(EXP2 + float(E1/16.0)  + 17  );
                
            }else if (E1<=79){
                EXP2 = ceil(EXP2 + float(E1/4.0) + 19);
                
                if (EXP2>200){
                    EXP2 = ceil(EXP2 + float(E1/9.0)  + 21 );
                    
                }
            }else if (E1<=99){
                EXP2 = ceil(EXP2 + float(E1/4.0) + 19);

                EXP2 = ceil(EXP2 + float(E1/9.0)  + 21 );
                
                if (EXP2>400){
                    EXP2 = ceil(EXP2 + float(E1/16.0)  + 17  );
                    
                    EXP2 = ceil(EXP2 * 1.15);
                }
            }
        }limitEXP(EXP1);
        limitEXP(EXP2);
        return EXP1 + EXP2;}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0||E2>99){
        return -99;
    }
    limithp(HP1);
    limitEXP(EXP1);
    limitm(M1);
    
    // Route 01 
    int i1=0 ; int i2 = 0;float P1; int S; 
     
     int moneyog = M1;
    int moneyspent = 0;
    for (int i=0 ; i<=24;i ++){
        i1 = i2;
        i2 = abs(EXP1 - i*i);
        if (i2 > i1){
            continue;
        }else{
            S = i*i;
            if (EXP1 >= S){
                P1= 1;
            }else {
                P1 = ((float(EXP1)/S)+80)/123;
            }
        }
    }
        if (E2 % 2 == 1) {
        while (M1>0) { 
            if (HP1 < 200) {
                HP1 = HP1 * 1.3 + 0.999;
                M1 -= 150;
                moneyspent += 150;
            } else {
                HP1 = HP1 * 1.1+0.999;
                M1 -= 70;
                moneyspent += 70;
            }limithp(HP1);
            if (moneyspent > moneyog / 2) {
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
                moneyspent += 200;
                EXP1 = ceil(EXP1 * 1.13);
            } else {
                M1 -= 120;
                moneyspent += 120;
                EXP1 = ceil(EXP1 * 1.13);
            }limitEXP(EXP1);
            if (moneyspent > moneyog / 2) {
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
                moneyspent += 100;
                EXP1 = ceil(EXP1 * 0.9);
            } else {
                M1 -= 120;
                moneyspent += 120;
                EXP1 = ceil(EXP1 * 0.9);
            }
            if (moneyspent > moneyog / 2) {
                break;
            }
        }

    }else {
        while (M1 > 0 ) { // Fix the loop condition
            if (HP1 < 200) {
                HP1 = HP1 * 1.3 + 0.999;
                M1 -= 150;
            } else {
                HP1 = HP1 * 1.1 + 0.999;
                M1 -= 70;
            }limithp(HP1);
            if (M1<=0){
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
                EXP1 = ceil(EXP1 * 1.13);
            } else {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 1.13);
            }limitEXP(EXP1);
            if (M1<=0){
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = ceil(EXP1 * 0.9);
            } else {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 0.9);
                
            }break;
        }limitm(M1);
    }
    HP1 = HP1 * 0.83 + 0.999;
    EXP1 = ceil(EXP1 * 1.17);
    limitEXP(EXP1);
    int i3 = 0;
    int i4 = 0;
    float P2;
    int S2;
    for (int i = 0; i <= 24; i++) {
        i3 = i4;
        i4 = abs(EXP1 - i * i);
        if (i4 > i3) {
            continue;
        } else {
            S2 = i * i;
            if (EXP1 >= S2) {
                P2 = 1;
            } else {
                P2 = ((float(EXP1) / S2) + 80) / 123;
            }
        }
    }
    double P3;
    double arr3[10] = { 0.32, 0.47, 0.28, 0.79, 1.0, 0.50, 0.22, 0.83, 0.64, 0.11 };
    if (E2<10){
        P3 = arr3[E2];
    }else{
        
            P3 =  (arr3[(E2/10 + E2 %10)%10]);
        }
    
    if(P1 ==1 && P2 == 1 && P3 ==1){
        EXP1 = ceil(EXP1*0.75);
        
    }else{
        float Pavg = (P1+P2+P3)/3.0;
        if (Pavg <0.5){
            HP1 = HP1*0.85 + 0.999;
            EXP1 = ceil(EXP1*1.15);
        }else{
            HP1 = HP1*0.9 + 0.999;
            EXP1 = ceil(EXP1*1.2);
        }
    }
    limitEXP(EXP1);
    limithp(HP1);
    limitm(M1);
    return HP1 + EXP1 + M1;
}



// Task 3
int calc(int number){
        if (number>=10){
            number = number/10 + number % 10;
            if (number >=0){
                number = number/10 + number % 10;
            }
        }return number;
    }
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
        if (E3<0||E3>99){
        return -99;
    } 
    limitEXP(EXP1);
    limitEXP(EXP2);
    limithp(HP1);
    limithp(HP2);
    int poscount =0, negcount = 0;
    int taxipos[10][10]={};
    for (int x=0 ; x<=9; x++){
        for (int y = 0 ; y <= 9 ; y ++){
            taxipos[x][y]= ((E3*y)+(x*2))*(x-y);
            if (taxipos[x][y] > (E3*2)){
                poscount++;
            }else if (taxipos[x][y]<(-E3)){
                negcount++;
            }
        }
    }


    int i = calc(poscount);
    int j = calc(negcount);
    int largest = -9999;


    for (int x = 0; x <= 9; x++) {
        if (taxipos[i + x][j - x] > largest) {
            largest = taxipos[i + x][j - x];
        }
        if (i + x == 9 or j - x == 0) {
            break;
        }
    }



    for (int x = 0; x <= 9; x++) {
        if (taxipos[i - x][j - x] > largest) {
            largest = taxipos[i - x][j - x];
        }
        if (i - x == 0 or j - x == 0) {
            break;
        }
    }

    for (int x = 0; x <= 9; x++) {
        if (taxipos[i - x][j + x] > largest) {
            largest = taxipos[i - x][j + x];
        }
        if (i - x == 0 or j + x == 9) {
            break;
        }
    }

    for (int x = 0; x <= 9; x++) {
        if (taxipos[i + x][j + x] > largest) {
            largest = taxipos[i + x][j + x];
        }
        if (i + x == 9 or j + x == 9) {
            break;
        }
    }
    if (abs(taxipos[i][j])<=largest){
        EXP1 = EXP1 *1.12+0.9999;
        EXP2 = EXP2 *1.12+0.9999;
        HP1 = HP1 *1.1 + 0.9999;
        HP2 = HP2 *1.1 + 0.9999;
        
    }else{
        EXP1 = EXP1 *0.88+0.9999;
        EXP2 = EXP2 *0.88+0.9999;
        HP1 = HP1 *0.9 + 0.9999;
        HP2 = HP2 *0.9 + 0.9999;
    }limitEXP(EXP1);
    limitEXP(EXP2);
    limithp(HP1);
    limithp(HP2);
    if (abs(taxipos[i][j])<=largest){
        return largest;
        }else {
            return taxipos[i][j];
        }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int check = 0;
    string charcheck = "@#%$!abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string stemail =  email ;
    string sts = s ;
    string se = stemail.substr(0, stemail.find('@'));
    if (sts.length()<8 ){
        return -1;
    }if (sts.length() >20){
        return -2;
    }
    if (sts == se){
        return -300;
    }
    int lendiff = sts.length() - se.length() +1 ;
    for (int i = 0; i < lendiff; i++) {
        bool found1 = true;
        for (int j = 0; j < se.length(); j++) {
            if (se[j] != sts[i + j]) {
                found1 = false;
                break;
            }
        }
        if (found1) {
            return -(300 + i);
        }
    }
    
    
    
    
    
    for (int i =0 ; i<=sts.length()-2; i ++){
        if (sts[i]==sts[i+1] && sts[i]== sts[i+2]){
            return -(400+ i);
        }
    }for (int i=0 ; i <sts.length();i++){
        for (int j =0 ; j <5 ; j++){
            if (sts[i]==charcheck[j]){
                check++;
            }
        }
    }
    if (check ==0){
        return -5;
    }
for (int i = 0; i < sts.length(); i++) {
    bool found2 = false;
    for (char c : charcheck) {
        if (c == sts[i]) {
            found2 = true;
            break;
        }
    }
    if (!found2) {
        return i; 
    }
}

    return -10; 
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max_count = 0; 
    int max_length = 0; 
    string correct_password; 

    for (int i = 0; i < num_pwds; i++) {
        string pwd = arr_pwds[i];
        int count = 0; 
        int length = pwd.length(); 
        
        
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[j] == pwd) {
                count++;
            }
        }
        
        if (count > max_count || (count == max_count && length > max_length)) {
            max_count = count;
            max_length = length;
            correct_password = pwd;
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == correct_password) {
            return i;
        }
    }

    return -1; 
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////