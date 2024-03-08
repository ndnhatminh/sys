#include "study_in_pink1.h"

using namespace std;

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

bool isValid (int E){
    if (E < 0) return false;
    else if (E <= 99) return true;
    else return false;
}

bool isSquare (int n){
    int i = 0;
    while (i*i <= n){
        if ( i*i == n ) return true;
        i++;      
    }
    return false;
}

int Find_S (int EXP1){
    int S_larger, S_smaller;
    for (int i = EXP1; i >= 0; i--){
        if (isSquare (i)){
            S_smaller = i;
            break;
        }
    }
    
    for (int i = EXP1; ;i++){
        if (isSquare (i)){
            S_larger = i;
            break;
        }
    }

    if (abs(EXP1 - S_smaller) <= abs(EXP1 - S_larger)) return S_smaller;
    else return S_larger;
}

void RoundUp (float &a){
   int b;
   b = round(a);
   if (a > b) a = b + 1;
   else a = b;
}

void healthRules (int &HP){
    if (HP < 0) HP = 0;
    else if (HP > 666) HP = 666;
}

void expRule (int &EXP){
    if (EXP < 0) EXP = 0;
    if (EXP > 600) EXP = 600;
}

void moneyRule (int &M){
    if (M < 0) M = 0;
    if ( M > 3000) M = 3000;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    float mem1, mem2;
    if (E1 <= 3)
    {
        int D;
        D = E1 * 3 + EXP1 * 7;
        switch (E1)
        {
            case 0:
                EXP2 += 29;
                if(D % 2 == 0)
                    mem1 = EXP1 + (double)D/200;
                else mem1 = EXP1 - (double)D/100;
                RoundUp (mem1);
                EXP1 = mem1;
                break;
            case 1:
                EXP2 += 45;
                if(D % 2 == 0)
                    mem1 = EXP1 + (double)D/200;
                else mem1 = EXP1 - (double)D/100;
                RoundUp (mem1);
                EXP1 = mem1;
                break;
            case 2:
                EXP2 += 75;
                if(D % 2 == 0)
                    mem1 = EXP1 + (double)D/200;
                else mem1 = EXP1 - (double)D/100;
                RoundUp (mem1);
                EXP1 = mem1;
                break;
            case 3:
                EXP2 += 29 + 45 + 75;
                if(D % 2 == 0)
                    mem1 = EXP1 + (double)D/200;
                else mem1 = EXP1 - (double)D/100;
                RoundUp (mem1);
                EXP1 = mem1;
                break;
            default:
            break;
        }
    }

    else if (E1 <= 19){
        mem2 = EXP2 + (double)E1/4 + 19;
        RoundUp (mem2);
        EXP2 = mem2;
        EXP1 -= E1;
    }
    else if (E1 <= 49){
        mem2 = EXP2 + (double)E1/9 + 21;
        RoundUp (mem2);
        EXP2 = mem2;
        EXP1 -= E1;
    }
    else if (E1 <= 65){
        mem2 = EXP2 + (double)E1/16 + 17;
        RoundUp (mem2);
        EXP2 = mem2;
        EXP1 -= E1;
    }
    else if (E1 <= 79){
        mem2 = EXP2 + (double)E1/4 + 19;
        RoundUp (mem2);
        if (mem2 > 200) mem2 = mem2 + (double)E1/9 + 21;
        RoundUp (mem2);
        EXP2 = mem2;
        EXP1 -= E1;
    }
    else if (E1 <= 99){
        mem2 = EXP2 + (double)E1/4 + 19;
        RoundUp (mem2);
        mem2 = mem2 + (double)E1/9 + 21;
        RoundUp (mem2);
        if (mem2 > 400) {
            mem2 = mem2 + (double)E1/16 + 17;
            RoundUp (mem2);
            mem2 = mem2 * 1.15;
            RoundUp (mem2);
        }
        EXP2 = mem2;
        EXP1 -= E1;
    }

    expRule(EXP1);
    expRule(EXP2);
    return EXP1 + EXP2;
}

// Task 2

void path_01 (int &EXP1, double &P1){
    int S;
    S = Find_S (EXP1);
    if (EXP1 >= S){
        P1 = 1;
    }
    else P1 = (EXP1 / (double)S + 80) / 123;
}

void feeding (int &HP1, int &M1){
    float mem_HP;
    if (HP1 < 200){
        mem_HP = HP1 * 1.3;
        RoundUp (mem_HP);
        HP1 = mem_HP;
        M1 -= 150;
    }
    else {
        mem_HP = HP1 * 1.1;
        RoundUp (mem_HP);
        HP1 = mem_HP;
        M1 -= 70;
    }
    moneyRule (M1);
    healthRules (HP1);
}

void get_vehicle (int &EXP1, int &M1){
    float mem_EXP;
    if (EXP1 < 400) M1 -= 200;
    else M1 -= 120;
    mem_EXP = EXP1 * 1.13;
    RoundUp (mem_EXP);
    EXP1 = mem_EXP;
    moneyRule (M1);
    expRule (EXP1);
}

void meet_homeless (int &EXP1, int &M1){
    float mem_EXP;
    if (EXP1 < 300) M1 -= 100;
    else M1 -= 120;
    mem_EXP = EXP1 * 0.9;
    RoundUp (mem_EXP);
    EXP1 = mem_EXP;
    moneyRule (M1);
    expRule (EXP1);
}

void path_02_1 (int &M1, int &EXP1, int &HP1, int &break_point, double &P2){
    while (M1 >= break_point){
        if (M1 > break_point) feeding(HP1, M1);
        if (M1 > break_point) get_vehicle (EXP1, M1);
        if (M1 > break_point) meet_homeless (EXP1, M1);
    }
    float mem_HP, mem_EXP;
    mem_HP = HP1 * 0.83;
    RoundUp (mem_HP);
    HP1 = mem_HP;
    healthRules (HP1);
    mem_EXP = EXP1 * 1.17;
    RoundUp (mem_EXP);
    EXP1 = mem_EXP;
    expRule (EXP1);
    int S;
    S = Find_S (EXP1);
    if (EXP1 >= S) P2 = 1;
    else P2 = (EXP1 / (double)S + 80) / 123; 
}

void path_02_2 (int &M1, int &EXP1, int &HP1, double &P2){
    float mem_HP, mem_EXP;
    feeding (HP1, M1);
    if (M1 <= 0){
        moneyRule (M1);
        P2 = 0;
        mem_HP = HP1 * 0.83;
        RoundUp (mem_HP);
        HP1 = mem_HP;
        healthRules (HP1);
        mem_EXP = EXP1 * 1.17;
        RoundUp (mem_EXP);
        EXP1 = mem_EXP;
        expRule (EXP1);
    }
    else{
        get_vehicle (EXP1, M1);
        if (M1 <= 0){
            moneyRule (M1);
            P2 = 0;
            mem_HP = HP1 * 0.83;
            RoundUp (mem_HP);
            HP1 = mem_HP;
            healthRules (HP1);
            mem_EXP = EXP1 * 1.17;
            RoundUp (mem_EXP);
            EXP1 = mem_EXP;
            expRule (EXP1);
        }
        else{
            meet_homeless (EXP1, M1);
            if (M1 < 0){
                moneyRule (M1);
                P2 = 0;
                mem_HP = HP1 * 0.83;
                RoundUp (mem_HP);
                HP1 = mem_HP;
                healthRules (HP1);
                mem_EXP = EXP1 * 1.17;
                RoundUp (mem_EXP);
                EXP1 = mem_EXP;
                expRule (EXP1);
            }
            else {
                mem_HP = HP1 * 0.83;
                RoundUp (mem_HP);
                HP1 = mem_HP;
                healthRules (HP1);
                mem_EXP = EXP1 * 1.17;
                RoundUp (mem_EXP);
                EXP1 = mem_EXP;
                expRule (EXP1);
                int S;
                S = Find_S (EXP1);
                if (EXP1 >= S){
                    P2 = 1;
                }
                else P2 = (EXP1 / (double)S + 80) / 123;
            }
        }
    }
}

void path_03 (int E2, double &P3){
    double P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    if (E2 >=0 && E2 <=9){
        P3 = P[E2];
    }
    else {
        while (E2 >= 10){
            E2 = E2 % 10 + E2 / 10;
        }
        P3 = P[E2];
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int break_point;
    break_point = M1 / 2;

    double P1;
    double P2;
    double P3;
    
    float mem_EXP, mem_HP;

    path_01 (EXP1, P1);
    if (E2 % 2 != 0) path_02_1 (M1, EXP1, HP1, break_point, P2);
    else path_02_2 (M1, EXP1, HP1, P2);
    path_03 (E2, P3);
    double P;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        mem_EXP = EXP1 * 0.75;
        RoundUp (mem_EXP);
        EXP1 = mem_EXP;
        expRule (EXP1);
    }
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            mem_HP = HP1 * 0.85;
            RoundUp (mem_HP);
            HP1 = mem_HP;
            healthRules (HP1);
            mem_EXP = EXP1 * 1.15;
            RoundUp (mem_EXP);
            EXP1 = mem_EXP;
            expRule (EXP1);

        }
        else {
            mem_HP = HP1 * 0.9;
            RoundUp (mem_HP);
            HP1 = mem_HP;
            healthRules (HP1);
            mem_EXP = EXP1 * 1.2;
            RoundUp (mem_EXP);
            EXP1 = mem_EXP;
            expRule (EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3

void bien_thanh_1_chu_so (int &n){
    if (n >= 0 && n <= 9) n = n;
    else {
        while( n >= 10){
            n = n%10 + n/10;
        }
    }
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int count_i(0), count_j(0);
    int taxi[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(taxi[i][j] > E3 * 2) count_i++;
            if(taxi[i][j] < -E3) count_j++;
        }
    }
    bien_thanh_1_chu_so(count_i);
    bien_thanh_1_chu_so(count_j);

    //duong cheo trai
    int max_trai = taxi[count_i][count_j];
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            if (i + j == count_i + count_j){
                if (taxi[i][j] > max_trai) max_trai = taxi[i][j]; 
            }
        }
    }

    //duong cheo phai;
    int max_phai = taxi[count_i][count_j];
    for (int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            if (i - j == count_i - count_j){
                if (taxi[i][j] > max_phai) max_phai = taxi[i][j];
            }
        }
    }

    //tim diem cua S va W tai vi tri gap nhau
    int Sherlock_Watson_Point;
    if (max_phai > max_trai) Sherlock_Watson_Point = max_phai;
    else Sherlock_Watson_Point = max_trai;

    //Final action
    int taxi_point;
    taxi_point = taxi[count_i][count_j];
    if (abs(taxi_point) > Sherlock_Watson_Point){
        float mem_HP1, mem_EXP1, mem_HP2, mem_EXP2;
        //HP1
        mem_HP1 = HP1 * 0.9;
        RoundUp (mem_HP1);
        HP1 = mem_HP1;
        healthRules (HP1);

        //HP2
        mem_HP2 = HP2 * 0.9;
        RoundUp (mem_HP2);
        HP2 = mem_HP2;
        healthRules (HP2);

        //EXP1
        mem_EXP1 = EXP1 * 0.88;
        RoundUp (mem_EXP1);
        EXP1 = mem_EXP1;
        expRule (EXP1);
        
        //EXP2
        mem_EXP2 = EXP2 * 0.88;
        RoundUp (mem_EXP2);
        EXP2 = mem_EXP2;
        expRule (EXP2);

        return taxi_point;
    }
    else {
        float mem_HP1, mem_EXP1, mem_HP2, mem_EXP2;
        //HP1
        mem_HP1 = HP1 * 1.1;
        RoundUp (mem_HP1);
        HP1 = mem_HP1;
        healthRules (HP1);

        //HP2
        mem_HP2 = HP2 * 1.1;
        RoundUp (mem_HP2);
        HP2 = mem_HP2;
        healthRules (HP2);

        //EXP1
        mem_EXP1 = EXP1 * 1.12;
        RoundUp (mem_EXP1);
        EXP1 = mem_EXP1;
        expRule (EXP1);

        //EXP2
        mem_EXP2 = EXP2 * 1.12;
        RoundUp (mem_EXP2);
        EXP2 = mem_EXP2;
        expRule (EXP2);

        return Sherlock_Watson_Point;
    }

}

// Task 4

bool La_so (char ki_tu){
    if (ki_tu >= '0' && ki_tu <= '9') return true;
    return false;
}

bool La_chu (char ki_tu){
    if((ki_tu >= 'A' && ki_tu <= 'Z') || (ki_tu >= 'a' && ki_tu <= 'z')){
        return true;
    }
    return false;
}

bool La_ki_tu_dac_biet (char ki_tu){
    if(ki_tu == '@' || ki_tu == '#' || ki_tu == '$' || ki_tu == '!' || ki_tu == '%'){
        return true;
    }
    return false;
}

bool la_ki_tu_khac (char ki_tu){
    if (La_chu(ki_tu) || La_ki_tu_dac_biet(ki_tu) || La_so(ki_tu)) return false;
    return true;
}

bool Khong_co_ki_tu_dac_biet (string s){
    for (int i = 0; i < s.length(); i++){
        if (La_ki_tu_dac_biet(s[i]))
        {
            return false;
            break;
        }
        
    }
    return true;
}

int min (int a, int b, int c){
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    return min;
}

bool Check_2_ky_tu_lien_tiep (string s){
    for (int i = 0; i < s.length(); i++){
        if (s[i] == s[i+1] && s[i+1] == s[i+2]){
            return true;
            break;
        }
    }
    return false;
}

void tim_sci (string s, int &sci){
    for (int i = 0; i < s.length(); i++){
        if (s[i] == s[i+1] && s[i+1] == s[i+2]){
            sci = i;
            break;
        }
    }
}

bool Co_chua_se (string s, string se){
    string temp;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == se[0]){
            temp = s.substr(i, se.length());
            if (temp == se){
                return true;
                break;
            }

        }
    }
    return false;
}

void tim_sei (string s, string se, int &sei){
    string temp;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == se[0]){
            temp = s.substr(i, se.length());
            if (temp == se){
                sei = i;
                break;
            }

        }
    }
}

bool Check_ki_tu_khac (string s){
    for (int i = 0; i < s.length(); i++){
        if(la_ki_tu_khac(s[i])){
            return true;
            break;
        }
    }
    return false;
}

void tim_vi_tri_ki_tu_khac (string s, int & mem){

    for (int i = 0; i < s.length(); i++){
        if(la_ki_tu_khac(s[i])){
            mem = i;
            break;
        }
    }
}

int checkPassword (const char * s, const char * email){
    string mem_s, mem_email;
    mem_s = (string)s;
    mem_email = (string)email;
    int sei(21), sci(21), mem(21);
    int m;
    // tim se
    string se;
    int count = 0;
    for (int i = 0; i < mem_email.length(); i++){
        if (mem_email[i] == '@') break;
        count++;
    }
    se = mem_email.substr(0, count);
    tim_sei(mem_s, se, sei);
    tim_sci(mem_s, sci);
    tim_vi_tri_ki_tu_khac(mem_s, mem);
    m = min(sei, sci, mem);

    if (mem_s.length() < 8) return -1;
    if (mem_s.length() > 20) return -2;
    if (Co_chua_se(mem_s, se)) return -(300 + sei);
    if (Check_2_ky_tu_lien_tiep (mem_s)) return -(400 + sci);
    if (Check_ki_tu_khac (mem_s)) return mem;
    if (Khong_co_ki_tu_dac_biet (mem_s)) return -5;

    return -10;
    
}


// Task 5

int dem_so_lan_xuat_hien (string mem_arr_pwds[], int num_pwds, string gia_tri)
{
    int dem = 0;
    for (int i = 0; i < num_pwds; i++){
        if (mem_arr_pwds[i] == gia_tri) dem++;
    }
    return dem;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max = 0;
    int vi_tri;
    string mem_arr_pwds[num_pwds];
    string longest;
    for (int i = 0; i < num_pwds; i++){
        mem_arr_pwds[i] = (string)arr_pwds[i];
    }
    for (int i = 0; i < num_pwds; i++){
        if (dem_so_lan_xuat_hien (mem_arr_pwds, num_pwds, mem_arr_pwds[i]) > max) {
            max = dem_so_lan_xuat_hien (mem_arr_pwds, num_pwds, mem_arr_pwds[i]);
            longest = mem_arr_pwds [i];
        }
    }
    for (int i = 0; i < num_pwds; i++){
        if (dem_so_lan_xuat_hien (mem_arr_pwds, num_pwds, mem_arr_pwds[i]) == max){
            if (mem_arr_pwds [i].length() > longest.length()) longest = mem_arr_pwds[i];
        }
    }
    for (int i = 0; i < num_pwds; i++){
        if (mem_arr_pwds[i] == longest){
            vi_tri = i;
            break;
        }
    }
    return vi_tri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////