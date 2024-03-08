
#include "main.h"


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


//Help
#define ll long long
#define info1 (e1/4.0 +19)
#define info2 (e1/9.0 + 21)
#define info3 (e1/16.0 + 17)

void checkExp(int &n){
    if (n > 600) n = 600;
    else if ( n < 0) n = 0;
    
}

void checkHp(int &n){
    if (n > 666) n = 666;
    else if ( n < 0) n = 0;
    
}

void checkM(int &n){
    if (n > 3000) n = 3000;
    else if ( n < 0) n = 0;
    
}

ll findS (int exp1){
    int n = sqrt(exp1);
    int d1 = -n*n + exp1, d2 = (n+1)*(n+1) -exp1;
    if (d1 > d2) return (n+1)*(n+1);
    else return n*n;
}

int checkE(int &e)
{
    if (e < 0 || e >= 100) return -99;
    return e;
}

double findXS(int EXP1){
    ll S = findS(EXP1); double P;
    if (S <= EXP1){
        P = 1;
    } else {
        P = static_cast<double>((1.0*EXP1/S + 80)/123.0);    
    }
    return P;
}

ll findE2(int E2){
    int num = 0;
    while (E2 != 0){
        num += E2%10;
        E2 /= 10;
    } 
    return num%10;
}

ll findPoint(int n){
    calculate : n = n/10 + n%10;
    if (n/10 != 0) goto calculate;
    return n;
}

int findSPo(int a[10][10], int ii, int jj){
    
    int _max = 0;
    //check left-down
        for(int i = 0; i < 10; i++){
                int i1 = ii + i, j1 = jj - i;
                if( i1 <0 || j1 < 0 || i1 > 9 || j1 > 9) break; 
                if (a[i1][j1] > _max)
                _max = a[i1][j1];
        }
    //check left up
    for(int i = 0; i < 10; i++){
                int i1 = ii - i, j1 = jj + i;
                if(  i1 <0 || j1 < 0 || i1 > 9 || j1 > 9) break;
                if (a[i1][j1] > _max)
                _max = a[i1][j1];
        }
    //check right down
     for(int i = 0; i < 10; i++){
                int i1 = ii + i, j1 = jj + i;
                if(  i1 <0 || j1 < 0 || i1 > 9 || j1 > 9) break; 
                if (a[i1][j1] > _max)
                _max = a[i1][j1];
        }
    //check right up 
    for(int i = 0; i < 10; i++){
                int i1 = ii - i, j1 = jj - i;
                if(  i1 <0 || j1 < 0 || i1 > 9 || j1 > 9) break; 
                if (a[i1][j1] > _max)
                _max = a[i1][j1];
        }
        return _max;
}




// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 >= 100) return -99;
     
    checkExp(exp1); checkExp(exp2);
    if ( e1 < 4){
        if (e1 == 0){
        exp2 += 29;
    }
        else if (e1 == 1){
        exp2 += 45;
    }
        else if (e1 == 2){
        exp2 += 75;
    }
        else if (e1 == 3){
        exp2 += (29 + 45 + 75);
    }
    ll D = e1*3 + exp1*7;
     
    if (D%2 == 0){
        exp1 = ceil(static_cast<double>(exp1 + ((double)D/200)));
    }
    else {
       exp1 = ceil(static_cast<double>(exp1 - ((double)D/100)));
    }
    checkExp(exp1);
    checkExp(exp2);
    }
    else 
    {
        if ( e1 >= 4 && e1 <= 19){
            exp2 = ceil(static_cast<double>(exp2 + (double)(info1)));
            checkExp(exp2);
        } 
        else if ( e1 >=10 && e1 <=49){
            exp2 = ceil(static_cast<double>(exp2 + (double)(info2)));
            checkExp(exp2);
        }
        else if ( e1 >= 50 && e1 <= 65){
            exp2 = ceil(static_cast<double>(exp2 + (double)(info3)));
            checkExp(exp2);
        }
        else if ( e1 >= 66 && e1 <= 79){
            exp2 = ceil(static_cast<double>(exp2 + (double)(info1))); checkExp(exp2);
            if (exp2 > 200) exp2 = ceil(static_cast<double>(exp2 + (info2)));
            checkExp(exp2);
        }
        else if ( e1 >= 80 && e1 <= 99){
            exp2 = ceil(static_cast<double>(exp2 + (double)(info1))); checkExp(exp2); 
            exp2 = ceil(static_cast<double>(exp2 + (double)(info2))); checkExp(exp2);
            if ( exp2 > 400) {
               exp2 = ceil(static_cast<double>(exp2 + (double)(info3))); checkExp(exp2);
               exp2 = ceil(static_cast<double> (1.15*exp2-0.0000001)); checkExp(exp2);
            }
             
        }
        exp1 = exp1 - e1;
        checkExp(exp1); checkExp(exp2);
    }
   return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 >= 100) return -99;
    checkHp(HP1); checkExp(EXP1); checkM(M1);
    //First Road
    double P1 = findXS(EXP1);
    //Second Road
    double halfM = 0.5*M1; 
    
    if (E2 % 2 == 1){
    while(true){
    //Drink
    if (M1 == 0) break;
    if (HP1 < 200){
        HP1  = ceil(static_cast<double>(1.3*HP1-0.000001));
        M1 -= 150;
        
    } else {
        HP1  = ceil(static_cast<double>(1.1*HP1-0.000001));
        M1 -= 70;
    }
    checkM(M1); checkHp(HP1);
    
    if (M1 < halfM) break;
    if (M1 == 0) break;
    //Move 
    if (EXP1 < 400){
        M1 -= 200;
    } else {
        M1 -= 120;
    }
    checkM(M1);
    EXP1 = ceil(static_cast<double>(1.13*EXP1-0.0000001));
    checkExp(EXP1);
    if (M1 < halfM) break;
    if (M1 == 0) break;

    //Help the homeless
    if ( EXP1 < 300){
        M1 -= 100;
    } else {
        M1 -= 120;
    }
    checkM(M1);
    EXP1 = ceil(static_cast<double>(0.9*EXP1-0.0000001));
    checkExp(EXP1);
    if (M1 < halfM) break;
    if (M1 == 0) break;
    }
    }
    else if (E2%2 == 0) {
    if (M1 == 0) goto haha;
    //Drink
    if (HP1 < 200){
        HP1 = ceil(static_cast<double>(1.3*HP1-0.0000001));
        M1 -= 150;
    } else {
        HP1 = ceil(static_cast<double>(1.1*HP1-0.0000001));
        M1 -= 70;
    }
    checkHp(HP1);
    checkM(M1);
    if (M1 == 0) goto haha;

    //Move 
    if (EXP1 < 400){
        M1 -= 200;
    } else {
        M1 -= 120;
    }
    checkM(M1);
    EXP1 = ceil(static_cast<double>(1.13*EXP1-0.0000001));
    checkExp(EXP1);
    if (M1 == 0) goto haha;

    //Help the homeless
    if ( EXP1 < 300){
        M1 -= 100;
    } else {
        M1 -= 120;
    }
    checkM(M1);
    EXP1 = ceil(static_cast<double>(0.9*EXP1-0.0000001));
    checkExp(EXP1);
    if (M1 == 0) goto haha;
    }
    haha:
    HP1 = ceil(static_cast<double>(0.83*HP1-0.0000001));
    EXP1 = ceil(static_cast<double>(1.17*EXP1-0.0000001));
    checkHp(HP1);
    checkExp(EXP1);

    double P2 = findXS(EXP1);

    //Third Road
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = findE2(E2); 
    double P3 = static_cast<double>(P[i])/100;
    
    //End of 3 road 
    double Ptb = (P1 + P2 + P3)/3;
    
    if (Ptb == 1){
        EXP1 = ceil(static_cast<double>(0.75*EXP1-0.0000001));
    } 
    else if (Ptb < 0.5) {
        EXP1 = ceil(static_cast<double>(1.15*EXP1-0.0000001));
        HP1 = ceil(static_cast<double>(0.85*HP1-0.0000001));
    } else if ( Ptb >= 0.5) {
        HP1 = ceil(static_cast<double>(0.9*HP1-0.0000001));
        EXP1 = ceil(static_cast<double>(1.2*EXP1-0.0000001));
    }
    checkHp(HP1);
    checkExp(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 >= 100) return -99;
    checkHp(HP1); checkExp(EXP1); checkHp(HP2); checkExp(EXP2); 
    int Point[10][10] = {0}; int ii = 0, jj = 0;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            Point[0][0] = 0;
            Point[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (Point[i][j] > E3*2) ii++;
            if (Point[i][j] < -E3) jj++;
        }
    }
    int k = 0;
    ii = findPoint(ii);
    jj = findPoint(jj);
    int carPo = Point[ii][jj];
    int chasePo = findSPo(Point, ii, jj);
    
    if (abs(chasePo) < abs(carPo)) {
        EXP1 = ceil(static_cast<double>(EXP1*0.88-0.000001));
        HP1  = ceil(static_cast<double>(HP1*0.9-0.000001));
        EXP2 = ceil(static_cast<double>(EXP2*0.88-0.000001));
        HP2 = ceil(static_cast<double>(HP2*0.9-0.000001));
        checkExp(EXP1); checkExp(EXP2);
        checkHp(HP1); checkHp(HP2);
        return carPo;
    } else {
        //1.12 1
        EXP1 = ceil(static_cast<double>(EXP1*1.12-0.000001));
        HP1  = ceil(static_cast<double>(HP1*1.1-0.000001));
        EXP2 = ceil(static_cast<double>(EXP2*1.12-0.000001));
        HP2 = ceil(static_cast<double>(HP2*1.1-0.000001));
        checkExp(EXP1); checkExp(EXP2);
        checkHp(HP1); checkHp(HP2);
        return chasePo;
    }
    return -1;
}

//Task4

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //check lenght of s
    string pd(s);
    string e(email);
    int sLenght = pd.size();
    if (sLenght < 8) return -1;
    else if (sLenght > 20) return -2;
    //findse
    string se ="";
    for (int i = 0; i < e.size(); i++){
        if (e[i] == '@') break;
        se += e[i];
    }
    //Add more variables
        int sei, cnt1 = 0; bool ok1 = false;
        int sci, cnt2 = 0;

    //find se 
    if (pd.find(se) != string::npos){
        return -(300 +pd.find(se));
    }

    //check dieu kien chua hai ky tu lien tiep
    for(int i = 1; i < sLenght; i++) {
        if (pd[i-1] == pd[i] && pd[i] == pd[i+1]){
            cnt2++;
            if (cnt2 == 1) sci = i - 1;
        }
    }
    if (cnt2 != 0) return -(400+ sci);

    //check thoa dieu kien ky tu dac biet
    for (int i = 0; i < sLenght; i++){
        if (pd[i] ==  '@'||pd[i] == '#' ||pd[i] == '%' ||pd[i] == '$' ||pd[i] == '!')
        {
            ok1 = true; 
            break;
        }
    }
    if (ok1 == false) return -5;
    
    for (int i = 0; i < sLenght; i++){
        //check thoa dieu kien ky tu 
        if ((pd[i] >= '0' && pd[i] <= '9') || (pd[i] >= 'a' && pd[i] <= 'z') || (pd[i] >= 'A' && pd[i] <= 'Z') || pd[i] ==  '@'||pd[i] == '#' ||pd[i] == '%' ||pd[i] == '$' ||pd[i] == '!' )
        {
           continue;
        }
        else return i;
    }
    

    //valid password
    return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr_p[num_pwds];
    for(int i = 0; i < num_pwds; i++){
        arr_p[i] = arr_pwds[i];
    }
    int fre_pd = 0, pos = 0; 
    for(int i = 0; i < num_pwds; i++){
        int total = 0;
        for (int j = i ; j < num_pwds ; j++){
            if (arr_p[i] == arr_p[j]){
                total++;
            }
        }
        
        if (total > fre_pd ){
            pos = i; 
            fre_pd = total;
        }
        else if (total == fre_pd){
            if (arr_p[i].size() > arr_p[pos].size())
            pos = i;
            else if (arr_p[i].size() == arr_p[pos].size()){
                if ( i < pos) pos = i;
            }
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////