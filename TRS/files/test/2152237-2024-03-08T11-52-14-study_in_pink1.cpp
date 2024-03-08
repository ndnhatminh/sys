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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(exp1 < 0) exp1 = 0;
else if(exp1 > 600) exp1 = 600;
if(exp2 < 0) exp2 = 0;
else if(exp2 > 600) exp2 = 600;
    if(e1 < 0 || e1 > 99) return -99;
    float ex1,ex2;
    if(e1>=0 && e1 <=3){
        int d = e1 * 3 + exp1 * 7;
    
    if(d%2==0){
            ex1 = exp1 + float(d)/200;
            exp1 = ceil(ex1);
            if(exp1<0) exp1 = 0;
             else if(exp1 > 600) exp1 = 600;
    }
    else if(d%2!=0){
            ex1 = exp1 - float(d)/100;
            exp1 = ceil(ex1);
            if(exp1<0) exp1 = 0;
            else if(exp1 > 600) exp1 = 600;
    }
         if(e1==0){
            exp2 += 29;
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
    }
    else if(e1==1){
            exp2 += 45;
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
    }
    else if(e1==2){
            exp2 += 75;
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
    }
    else if(e1==3){
            exp2 += 29 + 45 + 75;
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
    }
    }
    else if(e1>=4 && e1<=99){
        if(e1>=4 && e1 <= 19){
            ex2 = exp2 + float(e1)/4 + 19;
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
    }
    else if(e1>=20 && e1<=49){
            ex2 = exp2 + float(e1)/9 + 21;
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
    }
    else if(e1>=50 && e1 <= 65){
            ex2 = exp2 + float(e1)/16 + 17;
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
    }
    else if(e1>=66 && e1<=79){
            ex2 = exp2 + float(e1)/4 + 19;
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
        if(exp2 > 200){
            ex2 = exp2 + float(e1)/9 + 21;
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
        }
    }
    else if(e1>=80 && e1<=99){
            ex2 = exp2 + float(e1)/4 + 19;
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
             else if(exp2 > 600) exp2 = 600;
            ex2 = exp2 + float(e1)/9 + 21;
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
        if(exp2 > 400){
            ex2 = exp2 + float(e1)/16 + 17;
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
            else if(exp2 > 600) exp2 = 600;
            ex2 = exp2 + 0.15*float(exp2);
            exp2 = ceil(ex2);
             if(exp2 < 0) exp2 = 0;
             else if(exp2 > 600) exp2 = 600;
        }
        
    }
    exp1 -= e1;
    if(exp1<0) exp1 = 0;
     else if(exp1 > 600) exp1 = 600;
    }
     
    return exp1 + exp2;
}

// Task 2
int sochinhphuong(int n){
    int S;
    double x = sqrt(n);
    int low = floor(x);
    int high = ceil(x);
    int lowdis = n - (low * low);
    int highdis = (high * high) - n;
    if (lowdis < highdis) {
        S = low * low;
    } else {
        S = high * high;
    }
    return S;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
    float P1,hp1,exp1,m1,e2,p1,P2,p2;
    int hp11,exp11,m11,choose,count=0;
    int S,m=0,MM1 = M1,S1;
    if(EXP1 < 0) EXP1 = 0;
    else if(EXP1 > 600) EXP1 = 600;
    if(HP1 < 0) HP1 = 0;
    else if(HP1 > 666) HP1 = 666;
    //con duong 1
    S = sochinhphuong(EXP1);
    if(EXP1 >= S){
        P1 = 1;
    }
    else{
        p1 = float(EXP1)/S + 80;
        P1 = p1/123;
         P1 = round(P1*100)/100;
    }
    //con duong 2
    //E2 la mot so le
     while(E2%2!=0 && m <= float(MM1)*0.5){
        choose = 1;
        //hanh dong 1
         if(HP1 < 200){
        hp1 = HP1 + float(HP1)*0.3;
        HP1 = ceil(hp1);
        if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
        m += 150;
        M1 -= 150;
        if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        if(m > float(MM1)*0.5) {
            hp11 = HP1;
            exp11 = EXP1;
            m11 = M1;
            break;
        }
    }
    else if(HP1 >= 200){
        hp1 = HP1 + float(HP1)*0.1;
        HP1 = ceil(hp1);
        if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
        m += 70;
        M1 -= 70;
        if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        if(m > float(MM1)*0.5) {
            hp11 = HP1;
            exp11 = EXP1;
            m11 = M1;
            break;
        }
    }
    //hanh dong 2
     if(EXP1 < 400){
        if(EXP1 < 0) EXP1 = 0;
        M1 -= 200;
        m += 200;
        
        exp1 = EXP1 + float(EXP1)*0.13;
        EXP1 = ceil(exp1);
        if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
        if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        if(m > float(MM1)*0.5) {
            hp11 = HP1;
            exp11 = EXP1;
            m11 = M1;
            break;
        }
        if(EXP1 < 300){
            M1 -= 100;
            m += 100;
            exp1 = EXP1 - 0.1*float(EXP1);
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
            if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
            if(m > float(MM1)*0.5) {
            hp11 = HP1;
            exp11 = EXP1;
            m11 = M1;
            break;
        }
        }
        //hanh dong 3
        else if(EXP1 >= 300){
            m += 120;
            M1 -= 120;
            exp1 = EXP1 - 0.1*float(EXP1);
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
            if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
            if(m > float(MM1)*0.5) {
            hp11 = HP1;
            exp11 = EXP1;
            m11 = M1;
            break;
        }
        }
    }
    // hanh dong 2
    else if(EXP1 >= 400) {
        if(EXP1 > 600) EXP1 = 600;
        m += 120;
        M1 -= 120;
        exp1 = EXP1 + float(EXP1)*0.13;
        EXP1 = ceil(exp1);
        if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
        if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        if(m > float(MM1)*0.5) {
            hp11 = HP1;
            exp11 = EXP1;
            m11 = M1;
            break;
        }
        // hanh dong 3
        if(EXP1 < 300){
            M1 -= 100;
            m += 100;
            exp1 = EXP1 - 0.1*float(EXP1);
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
            if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
            if(m > float(MM1)*0.5) {
            hp11 = HP1;
            exp11 = EXP1;
            m11 = M1;
            break;
        }
        }
        else if(EXP1 >= 300){
            m += 120;
            M1 -= 120;
            exp1 = EXP1 - 0.1*float(EXP1);
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
            if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
            if(m > float(MM1)*0.5) {
            hp11 = HP1;
            exp11 = EXP1;
            m11 = M1;
            break;
        }
        }
    }
    }
    // E2 la mot so chan
    while(E2%2==0 && count == 0){
        choose = 2;
        // hanh dong 1
             if(HP1 < 200){
        hp1 = HP1 + float(HP1)*0.3;
        HP1 = ceil(hp1);
        if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
        m += 150;
        M1 -= 150;
        if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
    }
    else if(HP1 >= 200){
        hp1 = HP1 + float(HP1)*0.1;
        HP1 = ceil(hp1);
        if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
        m += 70;
        M1 -= 70;
        if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
    }
    // hanh dong 2
    if(EXP1 < 400){
        if(EXP1 < 0) EXP1 = 0;
        m += 200;
        M1 -= 200;
        exp1 = EXP1 + float(EXP1)*0.13;
        EXP1 = ceil(exp1);
        if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
        if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        // hanh dong 3
        if(EXP1 < 300){
            m += 100;
            M1 -= 100;
            exp1 = EXP1 - 0.1*float(EXP1);
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
            if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        }
        else if(EXP1 >= 300){
            m += 120;
            M1 -= 120;
            exp1 = EXP1 - 0.1*float(EXP1);
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
            if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        }
    }
    // hanh dong 2
    else if(EXP1 >= 400) {
        if(EXP1 > 600) EXP1 = 600;
        m += 120;
        M1 -= 120;
        exp1 = EXP1 + float(EXP1)*0.13;
        EXP1 = ceil(exp1);
        if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
        if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        if(EXP1 < 300){
            m += 100;
            M1 -= 100;
            exp1 = EXP1 - 0.1*float(EXP1);
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
            if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        }
        else if(EXP1 >= 300){
            m += 120;
            M1 -= 120;
            exp1 = EXP1 - 0.1*float(EXP1);
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
            if(M1 <= 0){
            M1 = 0;
            exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
            break;
        }
        }
    }
      exp1 = (float)EXP1*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)HP1*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
    count++;
    }
    
   if(choose == 1 && M1 != 0){
       exp1 = (float)exp11*1.17;
       EXP1 = ceil(exp1);
       if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
       hp1 = (float)hp11*0.83;
       HP1 = ceil(hp1);
       if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 = 666;
   }
   
   S1 = sochinhphuong(EXP1);
    if(EXP1 >= S1){
        P2 = 1;
    }
    else{
        p2 = float(EXP1)/S1 + 80;
        P2 = p2/123;
         P2 = round(P2*100)/100;
    }
    // con duong 3
    int arr[10] = {32,47,28,79,100,50,22,83,64,11};
    int a,b,sum,mod;    
    float P3,P;
    if(E2%10 == E2){
        P3 = float(arr[E2])/100;
    }
    else if(E2%100 == E2){
        a = E2/10;
        b = E2%10;
        sum = a + b;
        mod = sum%10;
        P3 = float(arr[mod])/100;
    }
    if(P1 == 1 && P2 == 1 && P3 == 1) {
        exp1 = float(EXP1)*0.75;
        EXP1 = ceil(exp1);
        if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
    }
    else if(P1 != 1 || P2 != 1 || P3 != 1){
        P = (P1 + P2 + P3)/3;
        if(P < 0.5){
            hp1 = float(HP1)*0.85;
            HP1 = ceil(hp1);
            if(HP1 < 0) HP1 = 0;
            else if(HP1 > 666) HP1 = 666;
            exp1 = float(EXP1)*1.15;
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
        }
        else if(P >= 0.5){
            hp1 = float(HP1)*0.9;
            HP1 = ceil(hp1);
            if(HP1 < 0) HP1 = 0;
            else if(HP1 > 666) HP1 = 666;
            exp1 = float(EXP1)*1.2;
            EXP1 = ceil(exp1);
            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;
     float hp1,hp2,exp1,exp2;
    int arr[10][10];
    int x,y,count1 = 0,count2 = 0,row,col;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            arr[i][j] = ((E3*j) + (i*2)) * (i - j);
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j] > 0 && arr[i][j] > (E3 * 2) ) count1++;
            else if(arr[i][j] < 0 && arr[i][j] < (-E3)) count2++;
        }
    }
    x = count1;
    while(x%10 != x){
        x = x%10 + x/10;
        
    }
    row = x;
    y = count2;
     while(y%10 != y){
        y = y%10 + y/10;
        
    }
    col = y;
    int max = arr[row][col];
        
            int leftRow = row;
    int leftCol = col;
    while (leftRow >= 0 && leftCol >= 0) {
        if (arr[leftRow][leftCol] > max) {
            max = arr[leftRow][leftCol];
        }
        leftRow--;
        leftCol--;
    }
        
        int   rightRow = row + 1;
        int   rightCol = col + 1;
    while (rightRow < 10 && rightCol < 10) {
        if (arr[rightRow][rightCol] > max) {
            max = arr[rightRow][rightCol];
        }
        rightRow++;
        rightCol++;
    }
    int tempRow = row;
    int tempCol = col;
    while(tempRow >=0 && tempCol < 10){
        if(arr[tempRow][tempCol] > max) max = arr[tempRow][tempCol];
        tempRow--;
        tempCol++;
    }
     tempRow = row;
     tempCol = col;
    while(tempRow < 10 && tempCol >= 0){
        if(max < arr[tempRow][tempCol]) max = arr[tempRow][tempCol];
        tempRow++;
        tempCol--;
    }

    if( arr[row][col] > max || -arr[row][col] > max){
        exp1 = float(EXP1)*0.88;
        EXP1 = ceil(exp1);
        if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
        exp2 = float(EXP2)*0.88;
        EXP2 = ceil(exp2);
        if(EXP2 < 0) EXP2 = 0;
        else if(EXP2 > 600) EXP2 = 600;
        hp1 = float(HP1)*0.9;
        HP1 = ceil(hp1);
        if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 =666;
        hp2 = float(HP2)*0.9;
        HP2 = ceil(hp2);
        if(HP2 < 0) HP2 = 0;
        else if(HP2 > 666) HP2 =666;
        
    }
    else if(arr[row][col] <= max || -arr[row][col] <= max ){
         exp1 = float(EXP1)*1.12;
        EXP1 = ceil(exp1);
        if(EXP1 < 0) EXP1 = 0;
        else if(EXP1 > 600) EXP1 = 600;
        exp2 = float(EXP2)*1.12;
        EXP2 = ceil(exp2);
        if(EXP2 < 0) EXP2 = 0;
        else if(EXP2 > 600) EXP2 = 600;
        hp1 = float(HP1)*1.1;
        HP1 = ceil(hp1);
        if(HP1 < 0) HP1 = 0;
        else if(HP1 > 666) HP1 =666;
        hp2 = float(HP2)*1.1;
        HP2 = ceil(hp2);
        if(HP2 < 0) HP2 = 0;
        else if(HP2 > 666) HP2 =666;
        
    }
   if(abs(arr[row][col]) > abs(max)) return arr[row][col];
   else return max;
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
     //bien de kiem soat mat khau hop len
    int ok = 0;
    // Tạo chuỗi se
    int len = 0;
    while(email[len] != '\0'){
        len++;
    }
    int pos = -1;
    for(int i = 0; i < len; i++){
        if(email[i] == '@') pos = i;
    }
        char* se = new char[pos +1];
        strncpy(se, email, pos);
        se[pos] = '\0';
      
     // Độ dài tối thiểu và tối đa của mật khẩu
    const int minLength = 8;
    const int maxLength = 20;

    // Kiểm tra độ dài của mật khẩu
    int length = 0;
    while (s[length] != '\0') {
        ++length;
    }

    if (length < minLength) {
        ok = 1;
        return -1;  // Độ dài ngắn hơn độ dài tối thiểu
    } else if (length > maxLength) {
        ok = 2;
        return -2;  // Độ dài dài hơn độ dài tối đa
    }

    // Kiểm tra mật khẩu có chứa chuỗi se hay không
    const char* temp = strstr(s,se);
    if(temp != NULL){
        ok = 3;
        return -(300 + (temp - s));
    }
    // Kiểm tra mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp hay không
    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            ok = 4;
            return -(400 + i);  // Chứa nhiều hơn 2 ký tự liên tiếp
        }
    }

    // Kiểm tra mật khẩu có chứa ít nhất 1 ký tự đặc biệt
    const char specialChars[] = "@#%$!";
    bool hasSpecialChar = false;

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < sizeof(specialChars) - 1; ++j) {
            if (s[i] == specialChars[j]) {
                hasSpecialChar = true;
                break;
            }
        }
    }

    if (!hasSpecialChar) {
        ok = 5;
        return -5;  // Không chứa ký tự đặc biệt
    }

    
    //Dieu kien khac

    for(int i = 0; i < length; i++){
        if(!('0' <= s[i] && s[i] <= '9') && !('a' <= s[i] && s[i] <= 'z') && !('A' <= s[i] && s[i] <= 'Z') && !(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
        {   
            ok = 7;
            return i;
        }
    }
  
    // Mật khẩu hợp lệ
    if(ok == 0) return -10;
 
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
     int maxHappen = 0;
    int maxLength = 0;
    int correct = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char *currentPassword = arr_pwds[i];
        int happen = 0;
        int length = strlen(currentPassword);

        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(currentPassword, arr_pwds[j]) == 0) {
                happen++;
            }
        }

        if (happen > maxHappen || (happen == maxHappen && length > maxLength)) {
            // Update maximum occurrences and length, and set correctPasswordIndex
            maxHappen = happen;
            maxLength = length;
            correct = i;
        }
    }

    return correct;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////