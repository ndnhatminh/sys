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
int exp_check(int &a){
    if (a>=600) a=600;
    else if (a<=0) a=0;
    return a;
}
int hp_check(int &a){
    if (a>=666) a=666;
    else if (a<=0) a=0;
    return a;
}
int m_check(int &a){
    if (a>=3000) a=3000;
    else if (a<=0) a=0;
    return a;
}
int e_check(int &e){
    if (e<0) return -99;
    else if (e>99) return -99;
    return 0;
}
int integer_test(float a){
    int b = a;
    if (b<a) return b+1;
    else if (b>a) return 0;
    else return a;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (0>e1 || e1>99) return -99;
    exp_check(exp1);
    exp_check(exp2);
    if (0<=e1 && e1<=3){
        if (e1==0) exp2+=29;
        else if (e1==1) exp2+=45;
        else if (e1==2) exp2+=75;
        else if (e1==3) exp2=exp2+29+45+75;
        int d = e1*3+exp1*7;
        if (d%2==0) {
        float t = 1.0*d/200;
        exp1=integer_test(exp1+t);
        }
        else {
            float t = 1.0*d/100;
            exp1=integer_test(exp1-t);
        }
    }
    else if (e1>3 && e1<=99){
        if (4<=e1 && e1<=19) exp2+=integer_test(1.0*e1/4+19);
        else if (20<=e1 && e1<=49) exp2+=integer_test(1.0*e1/9+21);
        else if (50<=e1 && e1<=65) exp2+=integer_test(1.0*e1/16+17);
        else if (66<=e1 && e1<=79) {
            exp2+=integer_test(1.0*e1/4+19);
            if (exp2>200) exp2+=integer_test(1.0*e1/9+21);
        }
        else if (80<=e1 && e1<=99){
            exp2+=integer_test(1.0*e1/4+19);
            exp2+=integer_test(1.0*e1/9+21);
            if (exp2>400) {
                exp2+=integer_test(1.0*e1/16+17);
                exp2=exp2+integer_test(exp2*0.15);
            }
        }
        exp1-=e1;
    }
    else return -99;
    exp1=integer_test(exp1);
    exp2=integer_test(exp2);
    exp_check(exp1);
    exp_check(exp2);
    return exp1+exp2;
}
//Task 2
int closest_square_number(int a){
    int s = round(sqrt(a));
    return s*s;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (0>E2 || E2>99) return -99;
    hp_check(HP1);
    exp_check(EXP1);
    m_check(M1);
    double P1, P2, P3;
    if (EXP1>=closest_square_number(EXP1)) P1=1;
    else P1=(1.0*EXP1/closest_square_number(EXP1)+80)/123;
    if (E2%2!=0){
        int temp=M1;
        while (true){
        if (M1==0) break;
        if (HP1<200){
        HP1=integer_test(HP1*1.3);
        M1-=150;
        }   
        else{
        HP1=integer_test(HP1*1.1);
        M1-=70;
        }
        hp_check(HP1);
        m_check(M1);
        if (temp-M1>0.5*temp) break;
        if (EXP1<400) M1-=200;
        else M1-=120;
        m_check(M1);
        EXP1=integer_test(EXP1*1.13);
        exp_check(EXP1);
        if (temp-M1>0.5*temp) break;
        if (EXP1<300) M1-=100;
        else M1-=120;
        m_check(M1);
        EXP1=integer_test(EXP1*0.9);
        exp_check(EXP1);
        if (temp-M1>0.5*temp) break;
        }
        HP1=integer_test(HP1*0.83);
        EXP1=integer_test(EXP1*1.17);
        hp_check(HP1);
        exp_check(EXP1);
    }
    else {
        while (true){
        if (M1==0) break;
        if (HP1 < 200){
        HP1=integer_test(HP1*1.3);
        M1-=150;
        }   
        else{
        HP1=integer_test(HP1*1.1);
        M1-=70;
        }
        hp_check(HP1);
        m_check(M1);
        if (M1==0) break;
        if (EXP1<400) M1-=200;
        else M1-=120;
        m_check(M1);
        EXP1=integer_test(EXP1*1.13);
        exp_check(EXP1);
        if (M1==0) break;
        if (EXP1<300) M1-=100;
        else M1-=120;
        EXP1=integer_test(EXP1*0.9);
        m_check(M1);
        break;
        }
        HP1=integer_test(HP1*0.83);
        EXP1=integer_test(EXP1*1.17);
        hp_check(HP1);
        exp_check(EXP1);
    }
    if (EXP1>=closest_square_number(EXP1)) P2=1;
    else P2=(1.0*EXP1/closest_square_number(EXP1)+80)/123;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2/10==0) P3=0.01*P[E2];
    else if (E2/10<=9) {
        int tmp=E2;
        int sum=0;
        while (tmp!=0){
            sum+=tmp%10;
            tmp=tmp/10;
        }
        int i = sum%10;
        P3=0.01*P[i];
    }
    else return -99;
    if (P1==P2 && P2==P3 && P1==1) EXP1=integer_test(EXP1*0.75);
    else {
        double p=(P1+P2+P3)/3;
        if (p<0.5){
            HP1=integer_test(HP1*0.85);
            EXP1=integer_test(EXP1*1.15);
        }
        else if (p>=0.5){
            HP1=integer_test(HP1*0.9);
            EXP1=integer_test(EXP1*1.2);
        }
    }
    hp_check(HP1);
    exp_check(EXP1);
    return HP1 + EXP1 + M1;
}
// Task 3
int s_w_point(int a, int b, int array[10][10]){
    int c=a, d=b;
    while (!((a==0)||(b==0))){
        a--; b--;
    }
    int max=array[a][b];
    while(!(a==10 || b==10)){
        if (array[a][b]>=max) max=array[a][b];
        a++; b++;
    }
    while(!(c==0||d==9)){
        c--;d++;
    }
    while(!(c==10||d==0)){
        if (array[c][d]>=max) max=array[c][d];
        c++;d--;
    }
    return max;
}
int abs(int a){
    if (a>=0) return a;
    else return -a;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (0>E3 || E3 >99) return -99;
    exp_check(EXP1);
    exp_check(EXP2);
    hp_check(HP1);
    hp_check(HP2);
    int taxi_path[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) taxi_path[i][j]=((E3*j)+(i*2))*(i-j);
    }
    int s_w_path[10][10];
    for ( int j = 0; j < 10; j++){
        for ( int i = 0; i < 10; i++) s_w_path[i][j]=abs(s_w_point(i, j, taxi_path));
    }
    int i=0, j=0;
    for (int a = 0; a < 10; a++){
        for (int b = 0; b < 10; b++){
            if (taxi_path[a][b]>E3*2) i++;
            else if (taxi_path[a][b]<(-E3)) j++;
        }
    }
    int sum=0;
    while(i!=0){
        sum+=i%10;
        i/=10;
    }
    int sum1=0;
    while(sum!=0){
        sum1+=sum%10;
        sum/=10;
    }
    i=sum1;
    int sum2=0;
    while(j!=0){
        sum2+=j%10;
        j/=10;
    }
    int sum3=0;
    while(sum2!=0){
        sum3+=sum2%10;
        sum2/=10;
    }
    j=sum3;
    if (abs(taxi_path[i][j])>s_w_path[i][j]) {
        HP1=integer_test(HP1*0.9);
        HP2=integer_test(HP2*0.9);
        EXP1=integer_test(EXP1*0.88);
        EXP2=integer_test(EXP2*0.88);
        hp_check(HP1);
        hp_check(HP2);
        exp_check(EXP1);
        exp_check(EXP2);
        return taxi_path[i][j];
    }
    else {
        HP1=integer_test(HP1*1.1);
        HP2=integer_test(HP2*1.1);
        EXP1=integer_test(EXP1*1.12);
        EXP2=integer_test(EXP2*1.12);
        hp_check(HP1);
        hp_check(HP2);
        exp_check(EXP1);
        exp_check(EXP2);
        return s_w_path[i][j];
    }
    return -1;
}

// Task 4
int checkerror(const char * si){
    string s(si);
    for (int i = 0; i < s.length(); i++){
        bool is_al = isalpha(s[i]);
        bool is_num = isdigit(s[i]);
        bool is_sp_ch = (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$'|| s[i]=='!'); 
        bool error = is_al || is_num || is_sp_ch;
        if (!error) return i;
    }
    return -1;
}
int character_check(const char *s){
    string si(s);
    for (int i = 0; i < si.length(); i++){
        if (s[i]=='@' || s[i]=='%' || s[i]=='$'||s[i]=='!'||s[i]=='#') return 1;
    }
    return 0;
}
int doublecharacter_check(string s){
    for ( int i = 0; i < s.length(); i++){
        if (s[i]==s[i+1] && s[i]==s[i+2]) return i;
    }
    return -1;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string si(s);
    string emaili(email);
    string se;
    stringstream ss(emaili);
    int double_character = doublecharacter_check(si);
    getline(ss, se, '@');
    int find_se = si.find(se);
    if (si.length()<8) return -1;
    else if (si.length()>20) return -2;
    else if (find_se!=-1) return -(300+find_se);
    else if (double_character!=-1) return -(400+double_character);
    else if (!character_check(s)) return -5;
    else if (checkerror(s)!=-1) return checkerror(s);
    else return -10;
    return -99;
}

// Task 5
/*int string_length(const char *s){
    int i = 0;
    while (s[i]!='\0') i++;
    return i;
}*/
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int n=num_pwds;
    int cnt[num_pwds];
    for (int i = 0; i < num_pwds; i++) cnt[i]=0;
    for (int i = 0; i < num_pwds; i++){
        for (int j = i+1; j < num_pwds; j++ ){
            if (strcmp(arr_pwds[i],arr_pwds[j])==0) cnt[i]++;//arr_pwds[i]==arr_pwds[j]
        }
    }
    int max=0;
    for ( int i = 0; i < num_pwds; i++){
        if (cnt[i]>=max) max=cnt[i];
    }
    int index;
    int max_length=0;
    for (int i = 0; i < num_pwds; i++){
        if (cnt[i]==max){
            if (strlen(arr_pwds[i])>max_length){
                max_length=strlen(arr_pwds[i]);
                index=i;
            }
        }
        if (i==num_pwds-1) return index;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////