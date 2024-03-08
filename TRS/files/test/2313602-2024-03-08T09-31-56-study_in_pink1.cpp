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

// function checking

struct Check {
/*private:
int checkHP1 , checkHP2 , checkEXP1 , checkEXP2 , checkM1 , checkM2 ;
*/
public:
    int checkEXP1 (int & EXP1) {
        if (EXP1 < 0) {
            EXP1 = 0;
        } else if (EXP1 > 600) {
            EXP1 = 600;
        }
        return EXP1;
    }

    int checkEXP2 (int & EXP2) {
        if (EXP2 < 0) {
            EXP2 = 0;
        } else if (EXP2 > 600) {
            EXP2 = 600;
        }
        return EXP2;
    }
    int checkHP1 (int & HP1) {
        if (HP1 < 0) {
            HP1 = 0;
        } else if (HP1 > 666) {
            HP1 = 666;
        }
        return HP1;
    }

    int checkHP2 (int & HP2) {
        if (HP2 < 0) {
            HP2 = 0;
        } else if (HP2 > 666) {
            HP2 = 666;
        }
        return HP2;
    }

    int checkM1 (int & M1) {
        if (M1 < 0) {
            M1 = 0;
        } else if (M1 > 3000) {
            M1 = 3000;
        }
        return M1;
    }

    int checkM2 (int & M2) {
        if (M2 < 0) {
            M2 = 0;
        } else if (M2 > 3000) {
            M2 = 3000;
        }
        return M2;
    }
};
void findP(int & EXP1, double & P) {
    int S1=0;
    double square1 = 0;
    S1 = round(sqrt(EXP1));
    square1 = S1*S1;
    if (EXP1 >= square1)
    {
        P = 1;
    } else {
        P = float(EXP1/square1 +80)/123;
    }
}
void findP2(int & HP1, int & EXP1 , int & M1, int E2, double & P2){
    Check Check;
    if (E2 % 2 == 0) {
        while (M1 > 0){
    // thuc an
        if ( HP1 < 200) {
            HP1 += ceil((double)HP1*0.3);
            M1 -= 150;
        } else if ( HP1 >= 200) {
            HP1 += ceil((double)HP1*0.1);
            M1 -= 70;
        }
        Check.checkHP1(HP1);
        if (M1 <= 0){
            M1 = 0;
            break;
        }
    // thue xe
        if ( EXP1 < 400) {
            M1 -=200;
        } else if ( EXP1 >= 400) {
            M1 -= 120; 
        }
        EXP1 += ceil((double)EXP1*0.13);
        Check.checkEXP1(EXP1);
        if (M1 <= 0) {
            M1 = 0;
            break;
        }
    // nguoi vo gia cu
        if ( EXP1 < 300) {
            M1 -= 100;
        } else if ( EXP1 >= 300) {
            M1 -= 120; 
        }
        EXP1 -= floor((double)EXP1*0.1);
        Check.checkEXP1(EXP1);
        if (M1 <= 0) M1 = 0;
        break;
        }
    }  
    if (E2 %2 == 1){ // luu y
        int TongChiM1 = 0;
        double HalfM1 = ceil(M1/2) ;
        while (TongChiM1 <= HalfM1) {
    // thuc an
        if (M1 == 0 ){ 
            break;
        }
        if ( HP1 < 200) {
                HP1 += ceil((double)HP1*0.3);
                M1 -= 150;
                TongChiM1 += 150;
            } else if ( HP1 >= 200) {
                HP1 += ceil((double)HP1*0.1);
                M1 -= 70;
                TongChiM1 += 70;
            }
            Check.checkHP1(HP1);
            if (TongChiM1 > HalfM1) {
                break;
            }
    // thue xe
            if ( EXP1 < 400) {
                M1 -=200;
                TongChiM1 += 200;
            } else if ( EXP1 >= 400) {
                M1 -= 120;
                TongChiM1 += 120;
            }
            EXP1 += ceil((double)EXP1*0.13);
            Check.checkEXP1(EXP1);
            if (TongChiM1 > HalfM1) {
                break;
            }
    // nguoi vo gia cu
            if ( EXP1 < 300) {
                M1 -= 100;
                TongChiM1 += 100;
            } else if ( EXP1 >= 300) {
                M1 -= 120;
                TongChiM1 += 120;    
            }
            EXP1 -= floor((double)EXP1*0.1);         
            Check.checkEXP1(EXP1);
            if (TongChiM1 > HalfM1) {
                break;
            }
        }
    }    
        if (E2%2 == 1 || M1 == 0){
            HP1 = ceil(HP1 - double(HP1*0.17));
            EXP1 = ceil(EXP1 + double(EXP1*0.17));
        } else if (E2%2 == 0){
            HP1 = ceil(HP1 - double(HP1*0.17));
            EXP1 = ceil(EXP1 + double(EXP1*0.17));
        }
        Check.checkEXP1(EXP1);
        Check.checkHP1(HP1);
        findP(EXP1, P2);
}
void  findP3(int & E2,double & P3){
double Pi3[10]={0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11};
    if (E2>=0 && E2 <=9 ) {
        P3 = Pi3[E2];
    }else {
        P3 = Pi3[(E2/10+E2%10)%10];
    }
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    // kiem tra bien exp 
        

    //    
    if ( E1>=0 && E1<=3) { // TH1
        Check Check;
        Check.checkEXP1(EXP1);
        Check.checkEXP2(EXP2);
        if (E1 == 0){           // TH1 case 0
            EXP2 += 29;
        }else if (E1 == 1){     // TH1 case 1
            EXP2 += 45;
        }else if (E1 == 2){     // TH1 case 2
            EXP2 += 75;
        }else if (E1 == 3){     // TH1 case 3
        EXP2 += (29 + 45 + 75);
        }
        ((E1*3 + EXP1*7)%2==0)? (EXP1 += ceil(((double)(E1*3 + EXP1*7)/200))) : (EXP1 -= floor(((double)(E1*3 + EXP1*7)/100)));
            Check.checkEXP1(EXP1);
            Check.checkEXP2(EXP2);
        return EXP1 + EXP2;
    }else if (E1>=4 && E1<=99) { // TH2
        Check Check;
        Check.checkEXP1(EXP1);
        Check.checkEXP2(EXP2);
        if (E1 >= 4 && E1 <= 19) { //TH2 case 1
            EXP2 += ceil(((double)E1/4 + 19)); 
        }else if (E1 >= 20 && E1 <= 49){ //TH2 case 2
            EXP2 += ceil(((double)E1/9 + 21));
        }else if (E1 >= 50 && E1 <= 65){ //TH2 case 3
            EXP2 += ceil(((double)E1/16 + 17));
        }else if (E1 >= 66 && E1 <= 79){ //TH2 case 4
            EXP2 += ceil(((double)E1/4 + 19));      //tt1
        if (EXP2 > 200) {
                EXP2 += ceil(((double)E1/9 + 21));   //tt2
            }       
        }else if (E1 >= 80 && E1 <= 99){ //TH2 case 5
            EXP2 += ceil(((double)E1/4 + 19));      //tt1
            EXP2 += ceil(((double)E1/9 + 21));       //tt2
            if (EXP2 > 400) {
                EXP2 += ceil(((double)E1/16 + 17));  //tt3
                EXP2 += ceil((double)EXP2*0.15); // cộng 15%
            }   
        }
        Check.checkEXP1(EXP1);
        Check.checkEXP2(EXP2);
        EXP1 -= E1;
        Check.checkEXP1(EXP1);
        return EXP1 + EXP2;
    }else {
        return -99;
    }             
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // case E2 la chan
        //check zone
    Check Check;
    if ( E2>=0 && E2 <=99 ){
    Check.checkHP1(HP1);
    Check.checkEXP1(EXP1);
    Check.checkM1(M1);
    double P1, P2, P3;      
    findP(EXP1,P1);
    findP2(HP1,EXP1,M1,E2,P2);
    findP3(E2,P3);
    if ( P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = ceil(EXP1*0.75);
    }else {
    double avr =(P1+P2+P3)/3;
    if (avr >= 0.5){
        HP1 -= floor(double(HP1*0.1));
        EXP1 += ceil(double(EXP1*0.2));
    } else if ( avr < 0.5 ) {
        HP1 -= floor(double(HP1*0.15)); 
        EXP1 += ceil(double(EXP1*0.15));
    }
    }
        Check.checkEXP1(EXP1);
        Check.checkHP1(HP1);
        Check.checkM1(M1);
    return HP1 + EXP1 + M1;     
    } else  {
        return -99;
    }  
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3>=0 && E3 <= 99){
    Check Check;
    Check.checkHP1(HP1);
    Check.checkEXP1(EXP1);
    Check.checkHP2(HP2);
    Check.checkEXP2(EXP2);
    // check bien
    int valueofLocationTaxi = 0;
    int matrixTaxi[10][10];
    int matrixI = 0;
    int matrixJ = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrixTaxi[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrixTaxi[i][j] > E3*2) matrixI++;
            if (matrixTaxi[i][j] < -E3) matrixJ++;
        }
    }
    int realI = ((matrixI/10 + matrixI %10 )%10 + (matrixI/10 + matrixI %10 )/10)%10;
    int realJ = ((matrixJ/10 + matrixJ %10 )%10 + (matrixJ/10 + matrixJ %10 )/10)%10;
    valueofLocationTaxi = matrixTaxi[realI][realJ];
    int detectiveLocation = matrixTaxi[realI][realJ];
        int j = realJ;
        for (int i = realI ; i < 10 ; i++) {
            if (detectiveLocation < matrixTaxi[i][j]) detectiveLocation = matrixTaxi[i][j];
            if (i == 9 || j == 9) break;
            j++;
        }
        j = realJ;
        for (int i = realI ; i < 10 ; i++) {
            if (detectiveLocation < matrixTaxi[i][j]) detectiveLocation = matrixTaxi[i][j];
            if (i == 9 || j == 0) break;
            j--;
        }
        j = realJ;
        for (int i = realI ; i > 0 ; i--) {
            if (detectiveLocation < matrixTaxi[i][j]) detectiveLocation = matrixTaxi[i][j];
            if (i == 0 || j == 0) break;
            j--;
        }
        j = realJ;
        for (int i = realI ; i > 0 ; i--) {
            
            if (detectiveLocation < matrixTaxi[i][j]) detectiveLocation = matrixTaxi[i][j];
            if (i == 0 || j == 9) break;
            j++;
        }
        if (valueofLocationTaxi < 0 ) {valueofLocationTaxi = abs(valueofLocationTaxi);}
        if (valueofLocationTaxi > detectiveLocation) {
            EXP1 = ceil(EXP1 - double(EXP1*0.12));
            EXP2 = ceil(EXP2 - double(EXP2*0.12));
            HP1 = ceil(HP1 - double(HP1*0.1));
            HP2 = ceil(HP2 - double(HP2*0.1));
        } else {
            EXP1 = ceil(EXP1 + double(EXP1*0.12));
            EXP2 = ceil(EXP2 + double(EXP2*0.12));
            HP1 = ceil(HP1 + double(HP1*0.1));
            HP2 = ceil(HP2 + double(HP2*0.1));
        }
            
            Check.checkHP1(HP1);
            Check.checkEXP1(EXP1);
            Check.checkHP2(HP2);
            Check.checkEXP2(EXP2);  //check again
        if (valueofLocationTaxi > detectiveLocation){return matrixTaxi[realI][realJ]; }
        else{ return detectiveLocation ;}
    }else return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int sizeOfPassword = strlen(s); // do dai mk    
    int sizeOfEmail = strlen(email);// do dai email
    if (sizeOfPassword < 8 ) {return -1;}// kiem tra do dai mk
    else if (sizeOfPassword > 20) {return -2;}// do dai vuot toi da
    
    // tim se ( truoc @)
    int beforeEmail;
    for (int i = 0 ; i < strlen(email) ; i++){
        if (email[i] == '@'){
            beforeEmail = i;
            break;
        }
    }
    
    int sei;

    // tim vi tri sei
    // do dai doan truoc @ trong email 
    for (int i = 0; i <= sizeOfPassword - beforeEmail; i++) {
        bool found = true;
        for (int j = 0; j < beforeEmail; j++) {
            if (s[i + j] != email[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            sei = i;
             
            return -(300 + sei);
        }
    }


    // kiem tra mat khau xem co bi lap khong 
    
    for (int i = 0; i < sizeOfPassword; ++i) {
        if ( s[i] == s[i + 1] && s[i] == s[i + 2]){
            return -(400 + i);
        }
    }

    // kiem tra ki tu dac biet

    bool found = false;
    for (int i = 0; i < sizeOfPassword; ++i) {
            if ( s[i] =='@' || s[i] =='#' || s[i] =='!' || s[i] =='%' || s[i] =='$'){
                found = true;
                break;
            }
    }
    if (found == false) {
        return -5;
    }
    for (int i = 0 ; i < sizeOfPassword; ++i) {
        if ((s[i] <= 122 && s[i] >= 97) || (s[i] >= 64 && s[i] <=90) || (s[i] <=57 && s[i] >= 48)|| s[i] =='#' || s[i] =='!' || s[i] =='%' || s[i] =='$'){
            continue;
        }else {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxcount = 0;
    int place_pwds = 0;
    int count[num_pwds] ={0};
    for (int i = 0 ; i < num_pwds ; i++) {
        for (int j = i + 1 ; j <num_pwds ; j++){
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                count[i]++;
            }
        }
    }
    for (int i = 0 ; i < num_pwds ; i++) {
        if (maxcount < count[i]){
            maxcount = count[i];
            place_pwds = i;
        }else if (maxcount == count[i]){
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[place_pwds])){  
            place_pwds = i;      
            }  
        }
    }
    return place_pwds;
}
// Code made by Tri Nguyen 2313602
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////