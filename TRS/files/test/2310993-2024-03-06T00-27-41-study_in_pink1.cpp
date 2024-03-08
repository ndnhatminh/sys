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
int max(int a, int b){
    if (a > b)
        return a;
    else return b;
}
int min(int a, int b){
    if (a < b)
        return a;
    else return b;
}
void checkHP(int &x){
    x = max(x, 0);
    x = min(x, 666);
}
void checkEXP(int &x){
    x = max(x, 0);
    x = min(x, 600);
}
void checkM(int &x){
    x = max(x, 0);
    x = min(x, 3000);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0 || e1> 99)
        return -99;
    else {
        int d = e1 * 3 + exp1 * 7;
        if (e1 >= 0 && e1 <= 3)
        {
            if (e1 ==0)
                exp2 += 29;
            else if (e1 ==1)
                exp2 += 45;
            else if (e1 ==2)
                exp2 += 75;
            else
                exp2 += 29 + 45 + 75;
            checkEXP(exp2);
            if (d % 2 == 0)
                exp1 = (int)(exp1+(double)d/200+0.999);
            else
                exp1 = (int)(exp1-(double)d/100+0.999);
            checkEXP(exp1);
        }
        else if (e1 >= 4 && e1 <=99)
        {
            if (e1 >= 4 && e1 <=19)
                exp2 = (int)(exp2+ (double)e1 / 4 + 19+0.999);
            if (e1 >= 20 && e1 <=49)
                exp2 = (int)(exp2+ (double)e1 / 9 + 21+0.999);
            if (e1 >= 50 && e1 <=65)
                exp2 = (int)(exp2+ (double)e1 / 16 + 17+0.999);
            if (e1 >= 66 && e1 <=79)
            {
                exp2 = (int)(exp2+ (double)e1/4 + 19+0.999);
                if (exp2 > 200) exp2 = (int)(exp2+ (double)e1/9 + 21+0.999);
            }
            if (e1 >= 80 && e1 <= 99)
            {
                exp2 =  (int)(exp2+ (double)e1/4 + 19+0.999);
                exp2 =  (int)(exp2+ (double)e1/9 + 21+0.999);
                if (exp2 > 400) {
                    exp2 = (int)(exp2+ (double)e1/16 + 17+0.999);
                    exp2 = (int)(exp2+ (double)exp2*0.15+0.999);
                }
            }
            exp1 -= e1;
            checkEXP(exp1);
            checkEXP(exp2);
        }
    checkEXP(exp1);
    checkEXP(exp2);
        return exp1 + exp2;
    }
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Trace 1
if (E2<0 || E2> 99)
    return -99;
else{
    double sqr = sqrt(EXP1),p1,p2,p3;
     if (int(sqr+1)-sqr >= sqr-int(sqr) || int(sqr)*int(sqr) == EXP1)
        p1 = 1;
    else
        p1 = (double(EXP1) /(int(sqr + 1) * int(sqr + 1)) +80)/123;
    // Trace 2
    if (M1 !=0){
        double m1 = M1;
        if (E2 % 2 == 1){
            while (M1 >= (double)m1/2 )
            {
                if (HP1 < 200){
                    HP1 = (double)HP1 * 1.3+0.999;
                    M1 -= 150;
                }
                else {
                    HP1 = (double)HP1 * 1.1+0.999;
                    M1 -= 70;
                }
                checkHP(HP1);
                checkM(M1);
                if (M1 < (double)m1/2)
                    break;
                if (EXP1 < 400)
                    M1 -= 200;
                else
                    M1 -= 120;
                EXP1 = (double)EXP1 * 1.13+0.999;
                checkEXP(EXP1);
                checkM(M1);
                if (M1 < (double)m1/2)
                    break;
                if (EXP1 < 300)
                    M1 -= 100;
                else
                    M1 -= 120;
                EXP1 = (double)EXP1 * 0.9+0.999;
                checkEXP(EXP1);
                checkM(M1);
                if (M1 < (double)m1/2)
                    break;
            }
        }
        else{
            do {
                if (HP1 < 200){
                    HP1 = (double)HP1 * 1.3+0.999;
                    M1 -= 150;
                }
                else {
                    HP1 = (double)HP1 * 1.1+0.999;
                    M1 -= 70;
                }
                checkHP(HP1);
                checkM(M1);
                if (M1 ==0)
                    break;
                if (EXP1 < 400)
                    M1 -= 200;
                else
                    M1 -= 120;
                EXP1 = (double)EXP1 * 1.13+0.999;
                checkEXP(EXP1);
                checkM(M1);
                if (M1 ==0)
                    break;
                if (EXP1 < 300)
                    M1 -= 100;
                else
                    M1 -= 120;
                EXP1 = (double)EXP1 * 0.9+0.999;
                checkEXP(EXP1);
                checkM(M1);
            } while (0);
        }
        HP1 = (double)HP1 * 0.83+0.999;
        EXP1 = (double)EXP1 * 1.17+0.999; 
        checkHP(HP1);
        checkM(M1);
        checkEXP(EXP1);  
    }
     
    sqr = sqrt(EXP1);//Tính p2
    if (int(sqr+1)-sqr >= sqr-int(sqr) || int(sqr)*int(sqr) == EXP1)
        p2 = 1;
    else
        p2 = (double(EXP1) /(int(sqr + 1) * int(sqr + 1)) +80)/123;
    
    //Trace 3
    int i;
    int P[11] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 /10 ==0)
        i = E2;
    else {
        i = E2 / 10+E2 % 10;
        i = i % 10;
    }
        
    p3=P[i]*0.01;
    // sqr = sqrt(EXP1);//Tính p3
    // if (abs(int(sqr+1)-sqr) <= abs(sqr-int(sqr)))
    //     p3 = 1;
    // else
    //     p3 = (double(EXP1) /(int(sqr + 1) * int(sqr + 1)) +80)/123;
    if (p1+p2+p3 >=3)
        EXP1 =(double)EXP1 * 0.75 + 0.999;
    
    else if (p1+p2+p3 <1.5) {
        HP1 = (double)HP1 * 0.85 + 0.999;
        EXP1 = (double)EXP1 * 1.15 + 0.999;
    }
    else {
        HP1 = (double)HP1 * 0.9 + 0.999;
        EXP1 = (double)EXP1 * 1.2 + 0.999;
    }
    checkHP(HP1);
    checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}
}

//Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if (E3<0 || E3> 99)
    return -99;
    int P[10][10],a=0,b=0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            P[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (P[i][j]> E3*2)
                ++a;
            if (P[i][j]< -E3)
                ++b;
        }
    }
    while (a /10 !=0){
        a = a / 10 + a % 10;
    }
    while (b /10 !=0){
        b = b / 10 + b % 10;
    }
    // chéo trái
    int minn = min(a, b), maxx = max(a, b), t=-99999;
    while (minn >= 0){
        t = max(P[minn][minn],t);
        --minn;
    }
    while (maxx < 10){
        t = max(P[maxx][maxx],t);
        ++maxx;
    }
    //chéo phải
    if (a + b == 9){
        for (int i = 9; i >= 0;--i)
            t = max(P[9-i][i], t);
    }
    else if (a + b > 9){
        int j = 0;
        while (b+j <=9){
            t =max(P[a-j][b+j], t);
            ++j;
        }
        j = 0;
        while (a+j<=9){
            t =max(P[a+j][b-j], t);
            ++j;
        }
    }
    else {
        int i = 0;
        while (a-i>=0){
            t = max(P[a - i][b + i], t);
            ++i;
        }
        i = 0;
        while (b-i>=0){
            t = max(P[b - i][a + i], t);
            ++i;
        }
    }
    if (abs(t)>=abs(P[a][b])){
        EXP1 = (double)EXP1*1.12+0.999;
        EXP2 = (double)EXP2*1.12+0.999;
        HP1 = (double)HP1*1.1 + 0.999;
        HP2 = (double)HP2*1.1 + 0.999;
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return abs(t);
    }
    else {
        EXP1 = (double)EXP1 * 0.88+0.999;
        EXP2 = (double)EXP2 * 0.88+0.999;
        HP1 = (double)HP1 * 0.9 + 0.999;
        HP2 = (double)HP2 * 0.9 + 0.999;
        return P[a][b];
    }
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // // cout << "Check Password";
    // if (email =="@gmail.com")
    //     return -300;
    // return -1;
    int size_email = strlen(email);
    int size_s = strlen(s);
        // return -300;
    if (size_s < 8)
    {
        // cout << -1;
        return -1;
    }
    if (size_s > 20){
        return -2;
    }
    char *se, *ptr, *s1;
    int id = 0, length_se, cei, k = 0, check = 0, asi = -1;
    se = new char[100];
    ptr = new char[100];
    s1 = new char[100];
    // s1 = new char[100];
    // string s1[] = s;
    // string email1[] = email;

    // s1 = s;
    
    while (1) {
        if (*(email + id) == '@')
        {
            if (id == 0)
                return -300;
            se[id] = '\0';
            break;
        }
        se[id] = *(email + id);
        ++id;
    }
    // cout << "pre\n";
    strcpy(s1, s);
    ptr = NULL;
    ptr = strstr(s1,se);
    // cout << email<<" "<<s1<<" "<<" "<<se<<" "<<ptr<<'\n';
    // cout << '\n';
    if (ptr != NULL)
    {
        *(ptr+strlen(ptr))  = '\0';
        cei = size_s - strlen(ptr);
        // delete[] se;
        // delete[] ptr;
        // delete[] s1;
        // cout << "NULL";
        return -(300 + cei);
    }
    if (size_s >2){
        for (int i = 0; i < size_s-2;++i){
            if (s[i] == s[i+1] && s[i+1]==s[i+2]){
                // delete[] se;
                // delete[] ptr;
                // cout<< -(400+i);
                // cout << "bg";
                return -(400 + i);
            }
                
        }
    }
    for (int i = 0; i < size_s;++i){
        if ( s[i]=='@' || s[i]=='#' || s[i]=='%'||s[i]=='$'||s[i]=='!' ){
            check++;
        }
    }
    for (int i = 0; i < size_s;++i){
        // cout << asi;
        if ((s[i] > 'z' || s[i] < 'a') && (s[i] > 'Z' || s[i] < 'A') && (s[i] < '0' || s[i] > '9') && (s[i] != '#') && (s[i] != '%') && (s[i] != '$') && (s[i] != '!') && (s[i] != '@'))
        {
                if (asi ==-1) asi = i;
                // cout << asi;
                // cout << asi;
        }
    }
        //  cout << asi;
        if (check == 0)
        {
            return -5;
        }
    if (asi != -1){
        return asi;
    }
    else return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // string arra[30];
    // bool *checked = new bool(num_pwds + 1);

    // for (int i = 0; i < num_pwds; ++i)
    //     *(checked + i) = false;
    int max_occur = 0, max_size = 0, vitri = -1;
    for (int i = 0; i < num_pwds; ++i) {
        // if (*(checked + i))
        //     continue;
        int dem = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]))
                continue;
            ++dem;
            // *(checked + j) = true;
        }

        int k = strlen(arr_pwds[i]);

        if (dem > max_occur) {
            vitri = i;
            max_size = k;
            max_occur = dem;
        } else if (dem == max_occur && k > max_size) {
            vitri = i;
            max_size = k;
        }
    }

    // delete[] checked;
    return vitri;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////