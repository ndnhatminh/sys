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
// tra hp ve dung trang thai
int tradunghp(int hp){
    if (hp > 666) return 666;
    else if (hp < 0) return 0;
    return hp;
}
// tra exp ve dung trang thai
int traexp(int i){
    if (i > 600) return 600;
    else if (i < 0) return 0;
    return i;
}
// tra M ve dung trang thai
int tram(int i){
    if (i> 3000) return 3000;
    else if ( i < 0) return 0;
    return i;
}
int lamtron(double e){
    int a = round(e);
    double hieu = e - a;
    if (hieu >= 0.00000001 && hieu <= 0.99999999){
        return a + 1;
    }
    else{
        return a;
    }
}
///////////////////////////////////////////////////////////////
//nhiem vu 1
int firstMeet(int &EXP1, int &EXP2, int E1){
    if (E1 < 0 || E1 > 99){
        return -99;
    }
    else if (E1 >= 0 && E1 <= 3){
        EXP1 = traexp(EXP1);
        EXP2 = traexp(EXP2);
        if (E1 == 0){
            EXP2 += 29;
        }
        else if (E1 == 1){
            EXP2 += 45;
        }
        else if (E1 == 2){
            EXP2 += 75;
        }
        else if (E1 == 3){
            EXP2 += 29 + 45 + 75;
        }
        EXP2 = traexp(EXP2);

        int D = E1 * 3 + EXP1*7;
        if (D % 2 == 0){
            //EXP1 = ceil(ceil((EXP1 + (double)D/200)*100)/100);
            EXP1 += lamtron( (double)D/200);
        }
        else{
            //EXP1 = ceil(ceil((EXP1 - (double)D/100)*100)/100);
            EXP1 = lamtron( EXP1 - (double)D/100);
        }
        EXP1 = traexp(EXP1);
    }
    else{
        EXP1 = traexp(EXP1);
        EXP2 = traexp(EXP2);
        if (E1 >= 4 && E1 <= 19){
            //EXP2 += ceil(ceil(((double)E1/4 + 19)*100)/100);
            EXP2 += lamtron((double)E1/4 + 19);
        }
        else if (E1 >= 20 && E1<= 49){
            //EXP2 += ceil(ceil(((double)E1/9 + 21)*100)/100);
            EXP2 += lamtron((double)E1/9 + 21);
        }
        else if (E1 >= 50 && E1 <= 65){
            //EXP2 += ceil(ceil(((double)E1/16 + 17)*100)/100);
            EXP2 += lamtron((double)E1/16 + 17);
        }
        else if (E1 >= 66 && E1 <= 79){
            //EXP2 += ceil(ceil(((double)E1/4 + 19)*100)/100);
            EXP2 += lamtron((double)E1/4 + 19);
            if (EXP2 > 200){
                //EXP2 += ceil(ceil(((double)E1/9 + 21)*100)/100);
                EXP2 += lamtron((double)E1/9 + 21);
            }
        }
        else{
            //EXP2 += ceil(ceil(((double)E1/4 + 19)*100)/100);
            //EXP2 += ceil(ceil(((double)E1/9 + 21)*100)/100);
            EXP2 += lamtron((double)E1/4 + 19);
            EXP2 += lamtron((double)E1/9 + 21);
            if (EXP2 > 400){
                //EXP2 += ceil(ceil(((double)E1/16 + 17)*100)/100);
                //EXP2 = ceil(ceil(((double)EXP2*1.15)*100)/100);
                EXP2 += lamtron((double)E1/16 + 17);
                EXP2 = lamtron((double)EXP2*1.15);
            }
        }
        EXP2 = traexp(EXP2);
        EXP1 -= E1;
    }
    EXP2 = traexp(EXP2);
    EXP1 = traexp(EXP1);
    return EXP1 + EXP2;
}

///////////////////////////////////////////////////////////////////
// nhiem vu 2
double tinhxacsuat(int &EXP1){
    double giatri = sqrt(EXP1);
    int S;
    double P1;
    int a = pow(ceil(ceil(giatri*100)/100),2) - EXP1;
    int b = -pow(floor(floor(giatri*100)/100),2) + EXP1;
    if (a < b) S = pow(ceil(ceil(giatri*100)/100),2);
    else S = pow(floor(giatri),2);
    if ( S <= EXP1){
        P1 = 100;
    }
    else{
        P1 = ((double)EXP1/S + 80)/ 123 * 100;
    }
    return P1;
}
int traceLuggage(int&HP1, int&EXP1, int&M1, int E2){
    if (E2 < 0 || E2 > 99){
        return -99;
    }
    M1 = tram(M1);
    HP1 = tradunghp(HP1);
    EXP1 = traexp(EXP1);
    // duong thu 1
    double P1 = tinhxacsuat(EXP1);
    // duong thu 2
    int tienbd = (double)M1*0.5 + 0.5;
    while(E2 % 2 != 0 && E2 != 0) {
        if (M1 > tienbd ||(M1 == tienbd && M1 !=0)) {
            if (HP1 < 200) {
                //HP1 = ceil(ceil((double) HP1 * 1.3*100)/100);
                HP1 = lamtron((double) HP1 * 1.3);
                M1 -= 150;
            } else {
                double giu = HP1 * 1.1;
                //HP1 = ceil(ceil((double) HP1 * 1.1*100)/100);
                HP1 = lamtron((double) HP1 * 1.1);
                M1 -= 70;
            }
            M1 = tram(M1);
            HP1 = tradunghp(HP1);
            if (M1 > tienbd ||(M1 == tienbd && M1 !=0)) {
                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                //EXP1 = ceil(ceil((double) EXP1 * 1.13*100)/100);
                EXP1 = lamtron((double) EXP1 * 1.13);
                M1 = tram(M1);
                EXP1 = traexp(EXP1);
                if (M1 > tienbd||(M1 == tienbd && M1 !=0)) {
                    if (EXP1 < 300) {
                        M1 -= 100;
                    } else {
                        M1 -= 120;
                    }
                    //EXP1 = ceil(ceil((double) EXP1 * 0.9*100)/100);
                    EXP1 = lamtron((double) EXP1 * 0.9);
                    M1 = tram(M1);
                    EXP1 = traexp(EXP1);
                    if (M1 < tienbd ||(M1 == tienbd && M1 ==0)) {
                        //HP1 = ceil(ceil(HP1*0.83*100)/100);
                        //EXP1 = ceil(ceil(EXP1*1.17*100)/100);
                        HP1 = lamtron((double) HP1 * 0.83);
                        EXP1 = lamtron((double) EXP1 * 1.17);
                        EXP1 = traexp(EXP1);
                        HP1 = tradunghp(HP1);
                        break;
                    }
                } else {
                    //HP1 = ceil(ceil(HP1*0.83*100)/100);
                    //EXP1 = ceil(ceil(EXP1*1.17*100)/100);
                    HP1 = lamtron((double) HP1 * 0.83);
                    EXP1 = lamtron((double) EXP1 * 1.17);
                    EXP1 = traexp(EXP1);
                    HP1 = tradunghp(HP1);
                    break;
                }
            } else {
                //HP1 = ceil(ceil(HP1*0.83*100)/100);
                //EXP1 = ceil(ceil(EXP1*1.17*100)/100);
                HP1 = lamtron((double) HP1 * 0.83);
                EXP1 = lamtron((double) EXP1 * 1.17);
                EXP1 = traexp(EXP1);
                HP1 = tradunghp(HP1);
                break;
            }
        }
        else{
            HP1 = lamtron((double) HP1 * 0.83);
            EXP1 = lamtron((double) EXP1 * 1.17);
            EXP1 = traexp(EXP1);
            HP1 = tradunghp(HP1);
            break;
        }
    }
    if (E2 % 2 == 0){
        if (M1 != 0) {
            if (HP1 < 200) {
                //HP1 = ceil(ceil((double) HP1 * 1.3*100)/100);
                HP1 = lamtron((double) HP1 * 1.3);
                M1 -= 150;
            } else {
                //HP1 = ceil(ceil((double) HP1 * 1.1*100)/100);
                HP1 = lamtron((double) HP1 * 1.1);
                M1 -= 70;
            }
            M1 = tram(M1);
            HP1 = tradunghp(HP1);

            if (M1 != 0) {
                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                // EXP1 = ceil(ceil((double) EXP1 * 1.13*100)/100);
                EXP1 = lamtron((double) EXP1 * 1.13);
                M1 = tram(M1);
                EXP1 = traexp(EXP1);

                if (M1 != 0) {
                    if (EXP1 < 300) {
                        M1 -= 100;
                    } else {
                        M1 -= 120;
                    }
                    //EXP1 = ceil(ceil((double) EXP1 * 0.9*100)/100);
                    EXP1 = lamtron((double) EXP1 * 0.9);
                    M1 = tram(M1);
                    EXP1 = traexp(EXP1);
                }
            }
        }
        //HP1 = ceil(ceil(HP1*0.83*100)/100);
        //EXP1 = ceil(ceil(EXP1*1.17*100)/100);
        HP1 = lamtron((double) HP1*0.83);
        EXP1 = lamtron((double) EXP1*1.17);
        EXP1 = traexp(EXP1);
        HP1 = tradunghp(HP1);
    }
    double P2 = tinhxacsuat(EXP1);
    //con duong 3
    int P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 0 && E2 <= 9){
        P3 = P[E2];
    }
    else {
        P3 = P[(E2%10 + E2/10)%10];
    }
    if (P1 == 100 && P2 == 100 && P3 == 100){
        //EXP1 = ceil(ceil((double)EXP1*0.75*100)/100);
        EXP1 = lamtron((double) EXP1*0.75);
        EXP1 = traexp(EXP1);
        HP1 = tradunghp(HP1);
        M1 = tram(M1);
    }
    else{
        double P = (P1 + P2 + P3)/3;
        if (P < 50){
            //HP1 = ceil(ceil((double)HP1*0.85*100)/100);
            //EXP1 = ceil(ceil((double)EXP1*1.15*100)/100);
            HP1 = lamtron((double) HP1*0.85);
            EXP1 = lamtron((double) EXP1*1.15);

        }
        else{
            //HP1 = ceil(ceil((double)HP1*0.9*100)/100);
            //EXP1 = ceil(ceil((double)EXP1*1.2*100)/100);
            HP1 = lamtron((double) HP1*0.9);
            EXP1 = lamtron((double) EXP1*1.2);
        }
        EXP1 = traexp(EXP1);
        HP1 = tradunghp(HP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
//////////////////////////////////////////////////////////////////
// nhiem vu 3
int tinhgiatri(int E3, int i, int j){
    return ((E3*j) + (i*2))*(i-j);
}
int chaseTaxi(int &HP1 , int & EXP1, int &HP2, int &EXP2, int E3){
    if (E3 < 0 || E3 > 99){
        return -99;
    }
    HP1 = tradunghp(HP1);
    EXP1 = traexp(EXP1);
    HP2 = tradunghp(HP2);
    EXP2 = traexp(EXP2);
    int P[10][10];
    memset(P, 0, sizeof(P));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            P[i][j]=tinhgiatri(E3, i, j);
        }
    }
    int giatridiemduong = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <= i; j++){
            if (P[i][j] > (E3*2)){
                giatridiemduong+=1;
            }
        }
    }
    if (giatridiemduong >= 10){
        giatridiemduong = (giatridiemduong%10) + (giatridiemduong/10);
        if (giatridiemduong >= 10){
            giatridiemduong = (giatridiemduong%10) + (giatridiemduong/10);
        }
    }
    int giatridiemam = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 9; j >= i; j--){
            if (P[i][j] < (-E3)){
                giatridiemam+=1;
            }
        }
    }
    if (giatridiemam >= 10){
        giatridiemam = (giatridiemam%10) + (giatridiemam/10);
        if (giatridiemam >= 10){
            giatridiemam = (giatridiemam%10) + (giatridiemam/10);
        }
    }
    int diemgap = P[giatridiemduong][giatridiemam];
    int gtlonnhat = diemgap;
    int i = giatridiemduong;
    int j = giatridiemam;
    //if (giatridiemduong == 0 || giatridiemam == 0 || giatridiemduong == 9 || giatridiemam == 9)
    while(i != -1 && j != -1 && i != 10 && j != 10){
        if (gtlonnhat < P[i][j]){
            gtlonnhat = P[i][j];
        }
        i--;
        j--;
    }
    i = giatridiemduong;
    j = giatridiemam;
    while(i != -1 && j != -1 && i != 10 && j != 10){
        if (gtlonnhat < P[i][j]){
            gtlonnhat = P[i][j];
        }
        i--;
        j++;
    }
    i = giatridiemduong;
    j = giatridiemam;
    while(i != -1 && j != -1 && i != 10 && j != 10){
        if (gtlonnhat < P[i][j]){
            gtlonnhat = P[i][j];
        }
        i++;
        j--;
    }
    i = giatridiemduong;
    j = giatridiemam;
    while(i != -1 && j != -1 && i != 10 && j != 10){
        if (gtlonnhat < P[i][j]){
            gtlonnhat = P[i][j];
        }
        i++;
        j++;
    }
    i = giatridiemduong;
    j = giatridiemam;
    if(abs(diemgap) > gtlonnhat){
//        EXP1=ceil(ceil((double)EXP1*0.88*100)/100);
//        EXP2=ceil(ceil((double)EXP2*0.88*100)/100);
//        HP1=ceil(ceil((double)HP1*0.9*100)/100);
//        HP2=ceil(ceil((double)HP2*0.9*100)/100);
        EXP1 = lamtron((double)EXP1*0.88);
        EXP2 = lamtron((double)EXP2*0.88);
        HP1 = lamtron((double)HP1*0.9);
        HP2 = lamtron((double)HP2*0.9);
    }
    else{
//        EXP1=ceil(ceil((double)EXP1*1.12*100)/100);
//        EXP2=ceil(ceil((double)EXP2*1.12*100)/100);
//        HP1=ceil(ceil((float)HP1*1.1*100)/100);
//        HP2=ceil(ceil((double)HP2*1.1*100)/100);
        EXP1 = lamtron((double)EXP1*1.12);
        EXP2 = lamtron((double)EXP2*1.12);
        HP1 = lamtron((double)HP1*1.1);
        HP2 = lamtron((double)HP2*1.1);
    }
    EXP1=traexp(EXP1);
    EXP2=traexp(EXP2);
    HP1= tradunghp(HP1);
    HP2 = tradunghp(HP2);
    int ketqua;
    if(abs(diemgap) > gtlonnhat){
        ketqua = diemgap;
    }
    else{
        ketqua = gtlonnhat;
    }
    return ketqua;
}
//////////////////////////////////////////////////////////////////
// nhiem vu 4
int sokytu(string s){
    int dodai = s.size();
    int temp = 0;
    for(int i = 0; i < dodai; i++){
        if (s[i] == '@'){
            temp++;
        }
    }
    return temp;
}
int vitrivipham(string s){
    int dodai = s.size();
    int temp = 0;
    if (dodai > 100) return 100;
    for(int i = 0; i < dodai; i++){
        if (temp == 2) return i;
        if (s[i] == '@'){
            temp++;
        }
    }
    return 0;
}
int demlientiep(string c){
    int dodai = c.size();
    int dem = 0;
    for(int i = 0; i < dodai - 1; i++){
        if (c[i] == c[i+1] && c[i] == c[i+2]){
            return i;
        }
    }
    return -1;
}
bool kytudb(string c){
    int dodai = c.size();
    for(int i = 0; i < dodai ; i++){
        int day = c[i];
        if (day == '@' || day == '#' || day == '%'|| day =='$' || day == '!'){
            return false;
        }
    }
    return true;
}
int checkPassword(const char* s,const char* email){
    string e(email);
    string S(s);
    int dodai = e.size();
    if (dodai > 100 || sokytu(email) != 1) return vitrivipham(e);
    int vitria = e.find('@');
    string se;
    if (vitria == 0) se = "";
    else se = e.substr(0,vitria);
    int ddmatkhau = S.size();
    if (ddmatkhau < 8) return -1;
    else if (ddmatkhau > 20) return -2;
    if (S.find(se) != string::npos){
        return -(300+S.find(se));
    }
    if (demlientiep(s) != -1){
        return -(400+demlientiep(s));
    }
    if (kytudb(s) == true) return -5;
    for(int i = 0; i < ddmatkhau; i++){
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' ||s[i] == '$' || s[i] == '!'
            ||(s[i] >= 48 && s[i] <= 57) ||(s[i] >= 65 && s[i] <= 90) ||(s[i] >= 97 && s[i] <= 122)){}
        else return i;
    }
    return -10;
}

//////////////////////////////////////////////////////////////////////
// nhiem vu 5
int demtrung(string arr_pwds[], int vitri,int num_pwds){
    string vitrixet = arr_pwds[vitri];
    int count = 0;
    for(int i = 0; i < num_pwds; i++){
        if (arr_pwds[i] == vitrixet){
            count++;
        }
    }
    return count;
}
int findCorrectPassword(const char* arr[], int num_pwds){
    string arr_pwds[num_pwds];
    for(int i =0; i < num_pwds; i++){
        arr_pwds[i] = arr[i];
    }
    int vitritra = 0;
    for(int i = 1; i < num_pwds;i++){
        int a = demtrung(arr_pwds, i, num_pwds);
        int b =demtrung(arr_pwds, vitritra, num_pwds);
        if (a > b){
            vitritra = i;
        }
        else if (a == b){
            if (arr_pwds[i].size() == arr_pwds[vitritra].size()){
                if (i < vitritra){
                    vitritra = i;
                }
            }
            else if (arr_pwds[i].size() > arr_pwds[vitritra].size()){
                vitritra = i;
            }
        }
    }
    return vitritra;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////