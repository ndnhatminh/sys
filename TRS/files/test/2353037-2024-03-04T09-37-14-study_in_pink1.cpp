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
bool eq(double a, double b){
    if(abs(a-b) < 0.000001) return true;
    else return false;
}
int cei(double a){
    int b = a;
    if(eq(a, b)) return b;
    else return b+1;
}
// Task 1
int f(int a, char c){
    if(a < 0) return 0;
    if(a > 666 && c == 'h') return 666;
    if(a > 600 && c == 'e') return 600;
    if(a > 3000 && c == 'm') return 3000;
    return a;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99) return -99;
    //exp2 always increases (addition), exp1 decreases(minus)
    if(e1 <= 3){//Case 1
        switch(e1){
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        default:
            exp2 += 149;
        }
        int D = 3*e1 + 7*exp1;
        if(D%2 == 0) exp1 += cei(D*1.0/200);
        else exp1 -= D/100; //D là số nguyên nên nó tự làm tròn xuống
    }
    else{ //Case 2
        if(e1 >= 4 && e1 <= 19){//info 1
            exp2 += cei(e1*1.0/4) + 19;
        }
        else if(e1 >= 20 && e1 <= 49){//info 2
            exp2 += cei(e1*1.0/9) + 21;
        }
        else if(e1 >= 50 && e1 <= 65){//info 3
            exp2 += cei(e1*1.0/16) + 17;
        }
        else if(e1 >= 66 && e1 <= 79){//inf 4: info 1, then if meet condition, info 2
            exp2 += cei(e1*1.0/4) + 19;
            if(exp2 > 200){
                 exp2 += cei(e1*1.0/9) + 21;
            }
        }
        else{//info 5(remaining range is [80;99]): info 1, then 2, then if meet condition, info 3, then bonus
            exp2 += cei(e1*1.0/4) + 19;
            exp2 += cei(e1*1.0/9) + 21;
            if(exp2 > 400){
                exp2 += cei(e1*1.0/16) + 17;
                exp2 = cei(1.15*exp2); //bonus
            }
        }
        exp1 -= e1;
    }
    exp2 = f(exp2, 'e');
    exp1 = f(exp1, 'e');
    return exp1 + exp2;
}

// Task 2
void event1(int &HP1, int &M1){
    if(HP1 < 200){
        HP1 = cei(HP1*1.3);
        M1 -= 150;
    }
    else{
        HP1 = cei(HP1*1.1);
        M1 -= 70;
    }
    HP1 = f(HP1, 'h');
}

void event2(int &M1, int &EXP1){
    if(EXP1 < 400){
        M1 -= 200;
    }
    else{
        M1 -= 120;
    }
    EXP1 = cei(EXP1*1.13);
    EXP1 = f(EXP1, 'e');
}

void event3(int &M1, int &EXP1){
    if(EXP1 < 300){
        M1 -= 100;
    }
    else{
        M1 -= 120;
    }
    EXP1 = cei(EXP1*0.9);
    EXP1 = f(EXP1, 'e');
}

double prob(int EXP1){//calc probability for road 1 and 2
    int a = sqrt(EXP1);
    if(EXP1 <= a*a + a) return 1;
    else return (EXP1*1.0/((a+1)*(a+1))+80)/123;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
    //cout << "Task1: " << endl << "HP1: " << HP1 << "EXP1: " << EXP1 << "M1: " << M1 << endl;
    double p, p1, p2, p3;
//Road 1
    p1 = prob(EXP1);// cout << "p1 " << p1 << endl;
//Road 2
    if(M1 != 0){
     if(E2%2 != 0){//money always decreases (minus), hp increases (multiply), exp1 either goes up or down (multiply)
        int lim = cei(M1*1.0/2); //cout << "lim: " << lim << endl;
        while(M1 >= lim){ //if the remaining money is still equal or greater than 50% the initial money
            event1(HP1, M1);//hp increases
            //cout << "event1 " << HP1 << " " << M1 << endl;
            if(M1 < lim) break; //stop
            else{ //continue
                event2(M1, EXP1);//exp increases
                EXP1 = f(EXP1, 'e'); //in case exp goes up too much
               // cout << "event2 " << M1 << " " << EXP1 << endl;
                if(M1 < lim) break;//stop
                else{//continue
                    event3(M1, EXP1); //exp decreases
                   // cout << "event3 " << M1 << " " << EXP1 << endl;
                }
            }
        }
    }
     else{
        event1(HP1, M1); //hp increases
        if(M1 < 0) M1 = 0;
        else{
            event2(M1, EXP1);
            EXP1 = f(EXP1, 'e'); //in case exp goes up too much
            if(M1 < 0) M1 = 0;
            else{//continue
                event3(M1, EXP1); //exp decreases
            }
        }
     }
    }
    HP1 = f(HP1, 'h');//in case too much
    M1 = f(M1, 'm');//in case too low
    EXP1 = cei(EXP1*1.17); EXP1 = f(EXP1, 'e');
    HP1 = cei(HP1*0.83);
   // cout << "EXP1: " << EXP1 << endl
     //  << "HP1 " << HP1 << endl
     //   << "M1 " << M1 << endl;
    p2 = prob(EXP1); //cout << "p2 " << p2 << endl;
//Road 3
    int i;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2/10 == 0){
        i = E2;
    }
    else{
        i = (E2/10 + E2%10)%10;
    }
    p3 = P[i]*1.0/100;// cout << "p3 " << p3 << endl;

    if(p1 == 1 && p2 == 1 && p3 == 1){
        EXP1 = cei(EXP1*0.75);
        return HP1 + EXP1 + M1;
    }
    p = (p1 + p2 + p3)/3; //cout << "p " << p << endl;
    if(p >= 0.5){ //hp decreases, exp increases (all by multiplying)
        HP1 = cei(HP1*0.9);
        EXP1 = cei(EXP1*1.2);
    }
    else{
        HP1 = cei(HP1*0.85);
        EXP1 = cei(EXP1*1.15);
    }
    EXP1 = f(EXP1, 'e');
    return HP1 + EXP1 + M1;
}

// Task 3
int meet(int a){
    while(a/10 != 0){
        a = a/10 + a%10;
    }
    return a;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;
    int A[10][10], meet_i = 0, meet_j = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            A[i][j] = (E3*j + i*2)*(i-j);
            if(A[i][j] > 2*E3) meet_i++; //calc where S and W meets the taxi
            if(A[i][j] < -E3) meet_j++;
        }
    }
    meet_i = meet(meet_i); //make them become 1-digit number
    meet_j = meet(meet_j);
    int ileft, jleft, iright, jright; //starting point to search (pure human)
    int maxlef, maxrig;
    if(meet_i >= meet_j){
        maxlef = A[meet_i - meet_j][0];
        jleft = 1;
        ileft = meet_i - meet_j + 1;
    }
    else{
        maxlef = A[0][meet_j - meet_i];
        ileft = 1;
        jleft = meet_j - meet_i + 1;
    }
    if(meet_i - 0 >= 9 - meet_j){
        maxrig = A[meet_i - (9-meet_j)][9];
        iright = meet_i + meet_j - 8;
        jright = 8;
    }
    else{
        maxrig = A[0][meet_j + (meet_i - 0)];
        iright = 1;
        jright = meet_j + meet_i - 1;
    }

    while((ileft <= 9 && ileft >= 0) && (jleft <= 9 && jleft >= 0)){
        if(A[ileft][jleft] > maxlef){
            maxlef = A[ileft][jleft];
        }
        ileft++; jleft++;
    }
    while((iright <= 9 && iright >= 0) && (jright <= 9 && jright >= 0)){
        if(A[iright][jright] > maxrig){
            maxrig = A[iright][jright];
        }
        iright++; jright--;
    }
    int pSaW = abs(max(maxlef, maxrig)), pT = abs(A[meet_i][meet_j]);
    if(pT > pSaW){
        EXP1 = cei(EXP1*0.88);
        EXP2 = cei(EXP2*0.88);
        HP1 = cei(HP1*0.9);
        HP2 = cei(HP2*0.9);
        return A[meet_i][meet_j];
    }
    else{
        EXP1 = cei(EXP1*1.12);
        EXP2 = cei(EXP2*1.12);
        HP1 = cei(HP1*1.1);
        HP2 = cei(HP2*1.1);
        EXP1 = f(EXP1, 'e');
        EXP2 = f(EXP2, 'e');
        HP1 = f(HP1, 'h');
        HP2 = f(HP2, 'h');
        return max(maxlef, maxrig);
    }
    return -1;
}

//Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string a = s, se = "";
    int i = 0, ktdb = 0;
    while(email[i] != '@'){
        se += email[i];
        i++;
    }
    int l_pw = a.length(), l_mai = se.length();
    int sei = a.find(se);


    if(l_pw < 8) return -1;
    else if(l_pw > 20) return -2;
    else if(sei != string::npos) return -(300+sei);
    for(int j = 0; j < l_pw; j++){
        if(a[j] == a[j+1] && a[j+1] == a[j+2]) return -(400+j);
        if(a[j] == '!' || a[j] == '@' || a[j] == '#' || a[j] == '$' || a[j] == '%'){
            ktdb++;
        }
    }
    if(ktdb == 0) return -5;
    for(int j = 0; j < l_pw; j++){
        if(!(a[j] == '!' || a[j] == '@' || a[j] == '#' || a[j] == '$' || a[j] == '%' || (a[j] >= 48 && a[j] <= 57) || (a[j] >= 97 && a[j] <= 122) || (a[j] >= 65 && a[j] <= 90))){
            return j;
        }
    }
    return -10;
    return -99;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int A[10000];
    for(int i = 0; i < num_pwds; i++){
        A[i]++;
        for(int j = i+1; j < num_pwds; j++){
            if(arr_pwds[i] == arr_pwds[j]){
                A[i]++;
            }
        }
    }
    int a = A[0];
    for(int i = 1; i < num_pwds; i++){//find the max frequency
        if(A[i] > a) a = A[i];
    }
    /*cout << a << endl;
    for(int i = 0; i < num_pwds; i++){
        cout << A[i] << " ";
    }*/

    string s; int l = 0;
    for(int i = 0; i < num_pwds; i++){
        if(A[i] == a){
            s = arr_pwds[i];
            if(s.length() > l) l = s.length();
        }
    }
    //cout << endl << l << endl;
    for(int i = 0; i < num_pwds; i++){
        s = arr_pwds[i];
        if(s.length() == l && A[i] == a) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
