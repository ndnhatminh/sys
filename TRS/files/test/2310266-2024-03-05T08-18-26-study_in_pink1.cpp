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
    if (E1<0 || E1>99)
        return -99;
    if (EXP1<0){
        EXP1 = 0;
    }
    if (EXP2<0){
        EXP2 = 0;
    }
    if (EXP1>600){
        EXP1 = 600;
    }
    if (EXP2>600){
        EXP2 = 600;
    }
    if (E1>=0 && E1<=3){
        switch(E1){
            case 0:
                EXP2 += 29;
                break;
            case 1:
                EXP2 += 45;
                break;
            case 2:
                EXP2 += 75;
                break;
            case 3:
                EXP2 = EXP2 + 29 + 45 + 75;
                break;
        }
        int D = E1*3 + EXP1*7;
        if (D%2==0){
            EXP1 = ceil(EXP1 + D/200.0);
        }
        else{
            EXP1 = ceil (EXP1 - D/100.0);
        }
    }
    if (E1>=4 && E1<=19){
        EXP2 = ceil(EXP2 + (E1/4.0 + 19));
        EXP1 -= E1;
    }
    else if (E1>=20 && E1<=49){
        EXP2 = ceil(EXP2 + (E1/9.0 + 21));
        EXP1 -= E1;
    }
    else if (E1>=50 && E1<=65){
        EXP2 = ceil(EXP2 + (E1/16.0 + 17));
        EXP1 -= E1;
    }
    else if (E1>=66 && E1<=79){
        EXP2 = ceil(EXP2 + (E1/4.0 + 19));
        if (EXP2 > 200){
            EXP2 = ceil(EXP2 + (E1/9.0 + 21));

        }
        EXP1 -= E1;
    }
    else if (E1>=80 && E1<=99){
        EXP2 = ceil(EXP2 + (E1/4.0 + 19));
        EXP2 = ceil(EXP2 + (E1/9.0 + 21));
        if (EXP2 > 400){
            EXP2 = ceil(EXP2 + (E1/16.0 + 17));
            EXP2 = ceil(EXP2 + 0.15*EXP2);
        }
        EXP1 -= E1;
    }

    if (EXP1<0){
        EXP1 = 0;
    }
    if (EXP2<0){
        EXP2 = 0;
    }
    if (EXP1>600){
        EXP1 = 600;
    }
    if (EXP2>600){
        EXP2 = 600;
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP1 > 666) {
        HP1 = 666;
    }
    if(M1<0){
        M1 = 0;
    }
    if(M1 >3000){
        M1 = 3000;
    }
    double P1, P2, P3, P;
    const int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int m = M1;
    int n = 0;
    int S;
    int a = abs(pow(ceil(sqrt(EXP1)), 2) - EXP1);
    int b = abs(pow(int(sqrt(EXP1)), 2) - EXP1);

    if (a < b) {
        S = pow(ceil(sqrt(EXP1)), 2);
    } else {
        S = pow(int(sqrt(EXP1)), 2);
    }

    if (EXP1 >= S) {
        P1 = 100.0;
    } else {
        P1 = (((double)(EXP1/S) + 80) / 123)*100;
    }

    if (E2 % 2 == 1) {
        for (int i = 0; i < 10; i++){
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            if (HP1 < 200) {
                HP1 += ceil((double) HP1 * 30 / 100);
                M1 -= 150;
                n += 150;
            } else {
                HP1 += ceil((double) HP1 * 10 / 100);
                M1 -= 70;
                n+=70;
            }
            if(HP1>666){
                HP1 = 666;
            }
            if(n > (m*0.5)){
                break;
            }
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
                n += 200;
            } else {
                M1 -= 120;
                n += 120;
            }
            EXP1 += ceil((double) EXP1 * 13 / 100);
            if(EXP1 > 600){
                EXP1=600;
            }
            if(n  > (m*0.5)){
                break;
            }
            if (M1 <= 0) {
                M1 = 0;
                break;
            }

            if (EXP1 < 300) {
                M1 -= 100;
                n += 100;
            } else {
                M1 -= 120;
                n += 120;
            }
            EXP1 -= floor((double) EXP1 * 10 / 100);
            if( n > (m*0.5)){
                break;
            }
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
        }
    }
    else if(E2%2 == 0) {
        for (int i = 0; i < 1;i++){
            if (M1 <= 0) {
                M1 = 0;
                break;
            }
            if (HP1 < 200) {
                HP1 += ceil((double) HP1 * 30 / 100);
                M1 -= 150;
            }
            else {
                HP1 += ceil((double) HP1 * 10 / 100);
                M1 -= 70;
            }
            if(HP1 > 666){
                HP1 = 666;
            }
            if (M1 <= 0){
                M1 = 0;
                break;
            }
            if (EXP1 < 400) {
                M1 -= 200;
            } else {
                M1 -= 120;
            }
            EXP1 += ceil((double) EXP1 * 13 / 100);
            if(EXP1 > 600){
                EXP1 = 600;
            }
            if (M1 <= 0){
                M1 = 0;
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
            } else {
                M1 -= 120;
            }
            EXP1 -= floor((double) EXP1 * 10 / 100);
            if (M1 <= 0){
                M1 = 0;
                break;
            }

        }
    }
    HP1 -= floor((double) HP1 * 17 / 100);
    EXP1 += ceil((double) EXP1 * 17 / 100);
    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP1 > 666) {
        HP1 = 666;
    }
    if(M1<0){
        M1 = 0;
    }
    if(M1 >3000){
        M1 = 3000;
    }

    a = abs(pow(ceil(sqrt(EXP1)), 2) - EXP1);
    b = abs(pow(int(sqrt(EXP1)), 2) - EXP1);

    if (a < b) {
        S = pow(ceil(sqrt(EXP1)), 2);
    } else {
        S = pow(int(sqrt(EXP1)), 2);
    }

    if (EXP1 >= S) {
        P2 = 100.0;
    } else {
        P2 = (((double)(EXP1/S) + 80) / 123)*100.0;
    }

    if( E2>=0 && E2<=9){
        P3 = p[E2]*1.0;
    }
    else if( E2 >=10 &&E2<=99){
        int d = ( E2/10 + E2%10 )%10;
        P3 = p[d]*1.0;
    }

    P = (P1 + P2 + P3) / 3.0;
    if (P1 == 100.0 && P2 == 100.0 && P3 == 100.0 ) {
        EXP1 -= floor((double) EXP1 * 25 / 100);
    } else if (P < 50.0) {
        HP1 -= floor((double) HP1 * 15 / 100);
        EXP1 += ceil((double) EXP1 * 15 / 100);
    } else if (P >= 50.0) {
        HP1 -= floor((double) HP1 * 10 / 100);
        EXP1 += ceil((double) EXP1 * 20 / 100);
    }

    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP1 > 666) {
        HP1 = 666;
    }
    if(M1<0){
        M1 = 0;
    }
    if(M1 >3000){
        M1 = 3000;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP1 > 666) {
        HP1 = 666;
    }    if (EXP2 < 0) {
        EXP2 = 0;
    }
    if (EXP2 > 600) {
        EXP2 = 600;
    }
    if (HP2 < 0) {
        HP2 = 0;
    }
    if (HP2 > 666) {
        HP2 = 666;
    }
    int i = 0, j = 0;
    int a [10][10];
    for (int m = 0; m<10; m++ ){
        for( int n = 0; n<10; n++){
            a[m][n] = ((E3*n)+(2*m))*(m-n);
        }
    }
    for (int m = 0; m<10; m++ ){
        for( int n = 0; n<10; n++){
            if( a [m][n] > (E3*2)){
                i+=1;
            }
            else if( a [m][n] < (-1*E3)){
                j+=1;
            }
        }
    }
    for (int k = 0; k < 10; k++){
        if(i/10 == 0){
            break;
        }
        int s1 = i/10;
        int s2 = i%10;
        i = s1 + s2;
    }
    for (int k = 0; k < 10; k++){
        if(j/10 == 0){
            break;
        }
        int s1 = j/10;
        int s2 = j%10;
        j = s1 + s2;
    }
    int m = i;
    int n = j;
    int taxi = abs(a[i][j]);
    int r;
    int max = a[m][n];

    while(m < 9 && n<9){
        m += 1;
        n += 1;
        if(a[m][n] > max){
            max = a[m][n];
        }
    }
    m = i;
    n = j;
    while(m > 0 && n>0){
        m -= 1;
        n -= 1;
        if(a[m][n] > max){
            max = a[m][n];
        }
    }
    m=i;
    n=j;
    while(m > 0 && n<9){
        m -= 1;
        n += 1;
        if(a[m][n] > max){
            max = a[m][n];
        }
    }
    m = i;
    n = j;
    while(m < 9 && n>0){
        m += 1;
        n -= 1;
        if(a[m][n] > max){
            max = a[m][n];
        }
    }
    if(taxi > max){
        EXP1 -= floor((double)EXP1*12/100);
        HP1 -= floor((double)HP1*10/100);
        EXP2 -= floor((double)EXP2*12/100);
        HP2 -= floor((double)HP2*10/100);
        r = a[i][j];
        return r;
    }
    else if (taxi <= max){
        EXP1 += ceil((double)EXP1*12/100);
        HP1 += ceil((double)HP1*10/100);
        EXP2 += ceil((double)EXP2*12/100);
        HP2 += ceil((double)HP2*10/100);
        r = max;
        if (EXP1 < 0) {
            EXP1 = 0;
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        }
        if (HP1 < 0) {
            HP1 = 0;
        }
        if (HP1 > 666) {
            HP1 = 666;
        }    if (EXP2 < 0) {
            EXP2 = 0;
        }
        if (EXP2 > 600) {
            EXP2 = 600;
        }
        if (HP2 < 0) {
            HP2 = 0;
        }
        if (HP2 > 666) {
            HP2 = 666;
        }
        return r;
    }


    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string mk(s);
    string e(email);
    int m = e.length();
    int n = mk.length();
    string se, sc;
    for (int i =0; i < m;i++){
        if(email[i]=='@'){
            se = e.substr(0,i);
            break;
        }
    }
    if (n > 20)
        return -2;
    if (n < 8)
        return -1;
    if (mk.find(se) != string::npos){
        int sei = mk.find(se);
        return -(300+sei);
    }
    for (int sci = 0; sci < n; sci++){
        if(mk[sci] == mk[sci+1] && mk[sci] == mk[sci+2])
            return -(400+sci);
    }
    bool ktdt = false;
    int k = 0;
    for ( int i = 0; i < n; i++){
        if(mk[i] != '\0'){
            if ( (mk[i] != '!') && (mk[i] != '@') && (mk[i] != '#') && (mk[i] != '$') && (mk[i] != '%') ){
                k += 1;
            }
        }
    }
    if ( k == n ) return -5;
    for (int i = 0; i < n; i++){
        if(isalnum(mk[i])){
            continue;
        }
        else if ((mk[i] == '!') || (mk[i] == '@') || (mk[i] == '#') || (mk[i] == '$') || (mk[i] == '%')){
            ktdt = true;
        }
        else return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int a = 0;
    int b = 0;
    const char * c;
    for (int i = 0; i < num_pwds; i++) {
        int n = strlen(arr_pwds[i]);
        int m =1;
        for (int j = 0; j < (num_pwds-1); j++){
            if(strcmp(arr_pwds[i],arr_pwds[num_pwds-1-j])==0){
                m+=1;
            }
        }
        if( m > a || ( m == a && n > b)){
            a = m;
            b = n;
            c = arr_pwds[i];
        }
    }
    for (int i = 0; i < num_pwds; i++){
        if ( strcmp(arr_pwds[i],c)==0) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
