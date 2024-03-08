#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int check_exp(int &exp)
{
    if (exp > 600)
        exp = 600;
    else if (exp < 0)
        exp = 0;
    return 0;
}
int check_hp(int &hp)
{
    if (hp > 666)
        hp = 666;
    else if (hp < 0)
        hp = 0;
    return 0;
}
int check_money(int &money)
{
    if (money > 3000)
        money = 3000;
    else if (money < 0)
        money = 0;
    return 0;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if(e1 < 0 || e1 > 99) return -99;
    check_exp(exp1); check_exp(exp2);
    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            check_exp(exp2);
            break;
        case 1:
            exp2 += 45;
            check_exp(exp2);
            break;
        case 2:
            exp2 += 75;
            check_exp(exp2);
            break;
        case 3:
            exp2 += 149;
            check_exp(exp2);
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        exp1 = (D % 2 == 0) ? ceil(exp1 + D/200.0) : ceil(exp1 - D/100.0);
        check_exp(exp1);
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += ceil(e1/ 4.0 + 19);
            check_exp(exp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 += ceil(e1 / 9.0 + 21);
            check_exp(exp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 += ceil(e1/ 16.0 + 17);
            check_exp(exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += ceil(e1 / 4.0 + 19);
            check_exp(exp2);
            if (exp2 > 200){
                exp2 += ceil(e1 / 9.0 + 21);
                check_exp(exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 += ceil(ceil(e1 / 4.0 + 19) + (e1 / 9.0 + 21));
            check_exp(exp2);
            if (exp2 > 400)
                exp2 = ceil(1.15 * (exp2 + ceil(e1 / 16.0 + 17)));
            check_exp(exp2);
        }
        exp1 -= e1;
        check_exp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if(E2 < 0 || E2 > 99) return -99;
    check_exp(EXP1); check_hp(HP1); check_money(M1);
    // Con duong 1
    float P1;
    int S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S) P1 = 1;
    else P1 = (float(EXP1) / float(S) + 80) / 123;
    // Con duong 2
    float P2;
    float M = M1;
    while (E2 % 2 != 0){
        if (M1 < (0.5 * M) || M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
        }
        if (HP1 < 200){
            HP1 = ceil(float(HP1)*1.3);
            check_hp(HP1);
            M1 -= 150;
            check_money(M1);
            if (M1 < (0.5 * M) || M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        else{
            HP1 = ceil(float(HP1)*110/100);
            check_hp(HP1);
            M1 -= 70;
            check_money(M1);
            if (M1 < (0.5 * M) || M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        if (EXP1 < 400){
            M1 -= 200;
            check_money(M1);
            EXP1 = ceil(float(EXP1)*113/100);
            check_exp(EXP1);
            if (M1 < (0.5 * M) || M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        else{
            M1 -= 120;
            check_money(M1);
            EXP1 = ceil(float(EXP1) * 113/100);
            check_exp(EXP1);
            if (M1 < ceil(0.5 * M) || M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        if (EXP1 < 300){
            M1 -= 100;
            check_money(M1);
            EXP1 = ceil(float(EXP1) * 0.9);
            if (M1 < (0.5 * M) || M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        else{
            M1 -= 120;
            check_money(M1);
            EXP1 = ceil(EXP1 * 0.9);
            if (M1 < (0.5 * M) || M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
    }
    while (E2 % 2 == 0){
        if (M1 == 0){
            HP1 = ceil(float(HP1) * 0.83);
            check_hp(HP1);
            EXP1 = ceil(float(EXP1) * 117/100);
            check_exp(EXP1);
            break;
        }
        if (HP1 < 200){
            HP1 = ceil(float(HP1)*1.3);
            check_hp(HP1);
            M1 -= 150;
            check_money(M1);
            if (M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        else{
            HP1 = ceil(float(HP1)*110/100);
            check_hp(HP1);
            M1 -= 70;
            check_money(M1);
            if (M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        if (EXP1 < 400){
            M1 -= 200;
            check_money(M1);
            EXP1 = ceil(float(EXP1)*113/100);
            check_exp(EXP1);
            if (M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        else{
            M1 -= 120;
            check_money(M1);
            EXP1 = ceil(float(EXP1)*113/100);
            check_exp(EXP1);
            if (M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        if (EXP1 < 300){
            M1 -= 100;
            check_money(M1);
            EXP1 = ceil(float(EXP1) * 0.9);
            if (M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        else{
            M1 -= 120;
            check_money(M1);
            EXP1 = ceil(float(EXP1) * 0.9);
            if (M1 == 0){
                HP1 = ceil(float(HP1) * 0.83);
                check_hp(HP1);
                EXP1 = ceil(float(EXP1) * 117/100);
                check_exp(EXP1);
                break;
            }
        }
        HP1 = ceil(float(HP1) * 0.83);
        check_hp(HP1);
        EXP1 = ceil(float(EXP1) * 117/100);
        check_exp(EXP1);
        break;
    }
    int S1 = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S1) P2 = 1;
    else P2 = (float(EXP1)/float(S1) + 80) / 123;
    // Con duong 3
    const float P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    float P3 = P[(E2 / 10 + E2 % 10) % 10];
    float P_case;
    if (P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = ceil(float(EXP1) * 0.75);
        check_exp(EXP1);
        return HP1 + EXP1 + M1;
    }
    else P_case = (P1 + P2 + P3) / 3;
    if (P_case < 0.5){
        HP1 = ceil(float(HP1) * 0.85);
        EXP1 = ceil(float(EXP1) * 115/100);
        check_exp(EXP1);
    }
    else{
        HP1 = ceil(float(HP1) * 0.9);
        EXP1 = ceil(float(EXP1) * 1.2);
        check_exp(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if(E3 < 0 || E3 > 99) return -99;
    check_hp(HP1); check_hp(HP2); check_exp(EXP1); check_exp(EXP2);
    int maze[10][10];
    int SWscore;
    int count_i = 0, count_j = 0;
    //Khoi tao diem so cua taxi trong me cung
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            maze[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            count_i = (maze[i][j] > E3 * 2) ? (count_i + 1) / 10 + (count_i + 1) % 10 : count_i;
            count_j = (maze[i][j] < -E3) ? (count_j + 1) / 10 + (count_j + 1) % 10 : count_j;
        }
    }
    //Tim gia tri lon nhat tren duong cheo
    int blMaxscore = maze[count_i][count_j], alMaxscore = maze[count_i][count_j], brMaxscore = maze[count_i][count_j], arMaxscore = maze[count_i][count_j];
    int i, j;
    for (int step = 0; step <= 9;++step){
        i = count_i + step;
        j = count_j - step;
        if(i >= 0 && i <= 9 && j >= 0 && j <= 9) blMaxscore = (blMaxscore < maze[i][j])?maze[i][j]:blMaxscore;
        else{
            i = 0, j = 0;
            break;
        }
    }
    for (int step = 0; step <= 9;++step){
        i = count_i - step;
        j = count_j - step;
        if(i >= 0 && i <= 9 && j >= 0 && j <= 9) alMaxscore = (alMaxscore < maze[i][j])?maze[i][j]:alMaxscore;
        else{
            i = 0, j = 0;
            break;
        }
    }
    for (int step = 0; step <= 9;++step){
        i = count_i + step;
        j = count_j + step;
        if(i >= 0 && i <= 9 && j >= 0 && j <= 9) brMaxscore = (brMaxscore < maze[i][j])?maze[i][j]:brMaxscore;
        else{
            i = 0, j = 0;
            break;
        }
    }
    for (int step = 0; step <= 9;++step){
        i = count_i - step;
        j = count_j + step;
        if(i >= 0 && i <= 9 && j >= 0 && j <= 9) arMaxscore = (arMaxscore < maze[i][j])?maze[i][j]:arMaxscore;
        else{
            i = 0, j = 0;
            break;
        }
    }
    SWscore = max(max(blMaxscore,alMaxscore),max(brMaxscore,arMaxscore));
    //Khong duoi kip xe
    if(abs(maze[count_i][count_j]) > SWscore){
        EXP1 = ceil(float(EXP1)*88/100);
        EXP2 = ceil(float(EXP2)*88/100);
        HP1 = ceil(float(HP1)*90/100);
        HP2 = ceil(float(HP2)*90/100);
        return maze[count_i][count_j];
    }
    //Duoi kip xe
    else{
        EXP1 = ceil(float(EXP1)*112/100);
        check_exp(EXP1); 
        EXP2 = ceil(float(EXP2)*112/100);
        check_exp(EXP2);
        HP1 = ceil(float(HP1)*110/100);
        check_hp(HP1);
        HP2 = ceil(float(HP2)*110/100);
        check_hp(HP2);
        return SWscore;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    //Khoi tao mang gom cac ky tu hop le
    int valid_char[90];
    int invalid_char[23] = {34,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,91,92,93,94,95,96};
    for(int i = 0; i < 90; i++){
        valid_char[i] = i + 33;
        for(int j = 0; j < 23; j++){
            if(valid_char[i] == invalid_char[j]) valid_char[i] = '\0';
        }
    }
    string t_email = email;
    string t_s = s;
    char se[100];
    se[t_email.copy(se, t_email.find_first_of('@'), 0)] = '\0';//Lenh trong ngoac vuong tra ve do dai cua chuoi vua copy
    string t_se = se;
    bool checkSerialchar = false, checkSpecialchar = true, checkValidchar = false;
    int idxSerialchar, idxInvalidchar;
    for(int i = 0; i < t_s.length() - 2;i++){
        if(s[i] == s[i+1] && s[i] == s[i+2]){ 
            checkSerialchar = true;
            idxSerialchar = i;
            break;
        }
    }
    for(int i = 0; i < t_s.length(); i++){
        if(s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
            checkSpecialchar = false;
            break;
        }
    }
    for(int i = 0; i < t_s.length(); i++){
        for(int j = 0; j < 90; j++){
            if(s[i] == valid_char[j]){
                checkValidchar = true;
                break;
            }
        }
        if(checkValidchar) checkValidchar = false;
        else{
            checkValidchar = true;
            idxInvalidchar = i;
            break;
        }
    }
    if(t_s.length() < 8) return -1;
    else if(t_s.length() > 20) return -2;
    else if(t_s.find(t_se) < t_s.length()) return -(300 + int(t_s.find(t_se)));
    else if(checkSerialchar) return -(400 + idxSerialchar);
    else if(checkSpecialchar) return -5;
    else if(checkValidchar) return idxInvalidchar;
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxAppear = 0, maxLen = 0, idxCorrectPassword, idxMaxAppear;
    string t_arr_pwds[num_pwds];
    for(int i = 0; i < num_pwds; i++){
        t_arr_pwds[i] = arr_pwds[i];
    }
    //Xuat hien nhieu nhat
    for(int i = 0; i < num_pwds; i++){
        int countAppear = 0;
        for(int j = 0; j < num_pwds; j++){
            if(t_arr_pwds[j] == t_arr_pwds[i]) countAppear+=1;
        }
        if(maxAppear < countAppear) maxAppear = countAppear;
    }
    //Do dai lon nhat
    for(int i = 0; i < num_pwds; i++){
        int countAppear = 0;
        for(int j = 0; j < num_pwds; j++){
            if(t_arr_pwds[j] == t_arr_pwds[i]) countAppear+=1;
        }
        if(countAppear == maxAppear){
            if(maxLen < t_arr_pwds[i].length()) maxLen = t_arr_pwds[i].length();
            }
    }
    //Mat khau chinh xac
    for(int i = 0; i < num_pwds; i++){
        int countAppear = 0;
        for(int j = 0; j < num_pwds; j++){
            if(t_arr_pwds[j] == t_arr_pwds[i]) countAppear+=1;
        }
        if(countAppear == maxAppear && t_arr_pwds[i].length() == maxLen) return i;
    }
    return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////