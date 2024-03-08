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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1<0 || E1>99){
        return -99;
    }
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) {
            EXP2 = EXP2 + 29;
        }
        else if (E1 == 1) {
            EXP2 = EXP2 + 45;
        }
        else if (E1 == 2) {
            EXP2 =  EXP2 + 75;
        }
        else {
            EXP2 = EXP2 + 29 + 45 + 75;
        }
        int D = E1 * 3 + EXP1 * 7;








        if (D % 2 == 0) {
            EXP1 = ceil(EXP1 + D / 200.0);
        }
        else{
            EXP1 = ceil(EXP1 - D / 100.0);
        }
    }
    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil(E1 / 4.0) + 19;
        }
         else if (E1 >= 20 && E1 <= 49) {
            EXP2 += ceil(E1 / 9.0) + 21;
        }
        else if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil(E1 / 16.0) + 17;
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceil(E1 / 4.0) + 19;
            if (EXP2 > 200)
                EXP2 += ceil(E1 / 9.0) + 21;
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 += ceil(E1 / 4.0) + 19;
            EXP2 += ceil(E1 / 9.0) + 21;
            if (EXP2 > 400)
            {
                EXP2 += ceil(E1 / 16.0) + 17;
                EXP2 = ceil(EXP2 * 115.0/100 );








            }
        }
        EXP1 -= E1;
    }
    if(EXP1>600){
        EXP1=600;
    }
    if(EXP2>600){
        EXP2=600;
    }
    if(EXP1<0){
        EXP1=0;
    }
    if(EXP2<0){
        EXP2=0;
    }








    return EXP1 + EXP2;
}
















// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if(E2<0 || E2>99){
        return -99;
    }
    // TODO: Complete this function
    int n = sqrt(EXP1);
    int S = 0;
    float P1;
    //CONDUONG1
    if (abs(n * n - EXP1) > abs((n + 1)*(n + 1) - EXP1)) {
        S = (n + 1) * (n + 1);
    }
    else {
        S = n * n;
    }
    if (EXP1 >= S) {
        P1 = 100;
    }
    else {
        P1 = ((EXP1 / S) + 80)*100.0 / 123;
    }
   
    //CONDUONG2
    if (E2 % 2 != 0) {
        int halfm = M1;
        while (M1 > halfm*0.5){
            if(M1 < halfm*0.5) break;
           
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 13.0/10);
                    M1 -= 150;
                }else{
                    HP1 = ceil(HP1 * 11.0/10);
                    M1 -= 70;
                }
           
            if(M1 < halfm*0.5) break;
                   
           
                if (EXP1 < 400) {
                    M1 -= 200;
                }else{
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 113.0/100);
           
            if(M1 < halfm*0.5) break;
           
           
                if (EXP1 < 300) {
                    M1 -= 100;
                }else{
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 9.0/10);
           
            }
        }else if (E2 % 2 == 0) {
            if (M1>0){
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 13.0/10);
                    M1 -= 150;
                }else{
                    HP1 = ceil(HP1 * 11.0/10);
                    M1 -= 70;
                }
            }
                       
            if (M1>0){
                if (EXP1 < 400) {
                    M1 -= 200;
                }else{
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 113.0/100);
            }  




            if (M1>0){
                if (EXP1 < 300) {
                    M1 -= 100;
                }else{
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 9.0/10);
            }        
    }




    if(EXP1>600){
        EXP1=600;
    }
    if(HP1>666){
        HP1=666;
    }
    if(EXP1<0){
        EXP1=0;
    }
    if(HP1<0){
        HP1=0;
    }
    if(M1<0){
        M1=0;
    }
    if(M1>3000){
        M1=3000;
    }
   
    HP1 = ceil(HP1 * 83.0/100);
    EXP1 = ceil(EXP1 * 117.0/100);




    if(EXP1>600){
        EXP1=600;
    }
    if(HP1>666){
        HP1=666;
    }
    if(EXP1<0){
        EXP1=0;
    }
    if(HP1<0){
        HP1=0;
    }
    if(M1<0){
        M1=0;
    }
    if(M1>3000){
        M1=3000;
    }  




    float P2 =0;
    int  z = sqrt(EXP1);
    int Y = 0;
    //CONDUONG1
    if (abs(z * z - EXP1) > abs((z + 1)*(z + 1) - EXP1)){
        Y = (z + 1) * (z + 1);
    }
    else{
        Y = z * z;
    }
       
    if (EXP1 >= Y){
        P2 = 100;
    }else{
        P2 = ((EXP1 / Y) + 80)*100.0 / 123;
    }
       




   
       
    //CONDUONG3
    int P[]={32,47,28,79,100,50,22,83,64,11};
    float P3;
    int b = 0;
    int c = 0;
    int d = 0;
    if (E2 <= 9) {
        P3 = P[E2];
    }
    else if (E2 >= 10 && E2 <= 99){
        b = E2 / 10;
        c = E2 % 10;
        int d = (b + c) % 10;
        P3 = P[d];
    }
   
    // Tong
    if ( P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1 = ceil(EXP1 * 75.0/100);
    }
    else {
        int e = (P1 + P2 + P3) / 3;
        if (e < 50) {
            EXP1 = ceil(EXP1 * 115.0/100);
            HP1 = ceil(85.0/100 * HP1);
        }
        else{
            EXP1 = ceil(EXP1 * 120.0/100);
            HP1 = ceil(90.0/100* HP1);
        }
   }
    if(EXP1>600){
        EXP1=600;
    }
    if(HP1>666){
        HP1=666;
    }
    if(EXP1<0){
        EXP1=0;
    }
    if(HP1<0){
        HP1=0;
    }
    if(M1<0){
        M1=0;
    }
    if(M1>3000){
        M1=3000;
    }  




    return HP1 + EXP1 + M1;
}
















// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99){
        return -99;
    }
    long long arr[10][10];
    int a=0, b=0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > (2 * E3) && arr[i][j] > 0){
                a += 1;
            }else if (arr[i][j] < (-E3) && arr[i][j] < 0){
                b += 1;
            }
        }
    }
   
    while ( a >= 10 ) {
        a = (a / 10) + (a % 10);
    }
    while ( b >= 10) {
        b = (b / 10) + (b % 10);
       
    }


    int txp = arr[a][b];
    int slp = 0;


    for(int i = a, j = b; i > -1 && j > -1 && j < 10 && i < 10  ; i++, j++){
        if(arr[i][j]>slp){
            slp=arr[i][j];
        }
    }


    for(int i = a, j = b;  i > -1 && j > -1 && j < 10 && i < 10 ; i--, j--){
    if(arr[i][j]>slp){
            slp=arr[i][j];
        }
    }


    for(int i = a, j = b;  i > -1 && j > -1 && j < 10 && i < 10 ; i++, j--){
    if(arr[i][j]>slp){
            slp=arr[i][j];
        }
    }


    for(int i = a, j = b; i > -1 && j > -1 && j < 10 && i < 10 ; i--, j++){
    if(arr[i][j]>slp){
            slp=arr[i][j];
        }
    }




    if (abs(txp) > abs(slp)) {
        EXP1 = ceil(EXP1 * 88.0/100);
        HP1 = ceil(HP1 * 90.0/100);
        EXP2 = ceil(EXP2 * 88.0/100);
        HP2 =ceil( HP2 * 90.0/100);
        if(EXP1>600){
        EXP1=600;
        }
        if(HP1>666){
            HP1=666;
        }
        if(EXP1<0){
            EXP1=0;
        }
        if(HP1<0){
            HP1=0;
        }
        if(EXP2>600){
            EXP2=600;
        }
        if(HP2>666){
            HP1=666;
        }
        if(EXP2<0){
            EXP1=0;
        }
        if(HP2<0){
            HP2=0;
        }
   
        return txp;
    }
    else {
        EXP1 = ceil(EXP1 * 112.0/100);
        HP1 = ceil(HP1 * 110.0/100);
        EXP2 = ceil(EXP2 * 112.0/100);
        HP2 = ceil(HP2 * 110.0/100);
        if(EXP1>600){
            EXP1=600;
        }
        if(HP1>666){
            HP1=666;
        }
        if(EXP1<0){
            EXP1=0;
        }
        if(HP1<0){
            HP1=0;
        }
        if(EXP2>600){
            EXP2=600;
        }
        if(HP2>666){
            HP1=666;
        }
        if(EXP2<0){
            EXP1=0;
        }
        if(HP2<0){
            HP2=0;
        }
   
        return slp;
    }


}






















// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pw = string(s);
    string se;
    string Email=string(email);
    se = Email.substr(0, Email.find('@'));








    if (pw.size() < 8) {
        return -1;
    }
    else if ( pw.size() > 20){
        return -2;
    }
    if (pw.find(se) != string::npos) {
        return -(300 + pw.find(se));
    }








    for (int i = 0; i < pw.length(); i++) {
        if (pw[i] == pw[i + 1] && pw[i + 1] == pw[i + 2])
            return -(400 + i);
    }








    int n = 0;
    for (int i = 0; i < pw.length(); i++) {
        if (pw[i] == '@' || pw[i] == '#' || pw[i] == '%' || pw[i] == '$' || pw[i] == '!')
            n++;
    }
    if (n == 0)
        return -5;
















    for (int i = 0; i < pw.length(); i++) {
        if (!(pw[i] == '@' || pw[i] == '#' || pw[i] == '%' || pw[i] == '$' || pw[i] == '!' || isalpha(pw[i]) || isdigit(pw[i])))
            return i;
    }
   
    return -10;
}
















// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int g=0,max=0,k=0,length=0,l=0;
   
    for (int i = 0; i < num_pwds ; i++) {
        for (int j = 0; j < num_pwds ; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                g += 1;
            }
        }
        if (g > max || (g == max && strlen(arr_pwds[i]) > length)) {
            max = g;
            l = i;
            length = strlen(arr_pwds[i]);
        }
        g = 0;
    }
    return l;
}
















////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////




























































































