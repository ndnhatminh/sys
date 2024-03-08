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
int limit(int value,int lowest,int highest){
    if(value<lowest) {
        value=lowest;
    }
    else if(value>highest) {
        value=highest;
    }
    return value;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int kq;
    exp1 = limit(exp1,0,600);
    exp2 = limit(exp2,0,600);
    if (e1>99 || e1<0){
       kq = -99 ;
    }
    if (e1<=99 || e1 >=0){
        if (e1 >=0 && e1 <=3 ){
            if (e1==0){
                exp2=exp2 + 29;
                exp2 = limit(exp2,0,600);
            }
            if (e1==1){
                exp2 = exp2 +45;
                exp2 = limit(exp2,0,600);
            }
            if (e1==2){
                exp2 = exp2 + 75;
                exp2 = limit(exp2,0,600);
            }
            if (e1==3){
                exp2 = exp2 + 45+75+29;
                exp2 = limit(exp2,0,600);
            }
            int D=0;
                D = (e1 * 3)+ (exp1*7)+0.999;
            if (D %2 ==0){
                exp1 = exp1 + (D/200);
                exp1 = limit(exp1,0,600);
            }
            else{
        		exp1 = exp1 - (D/100);
        		exp1 = limit(exp1,0,600);
    		}
        }
    //
    //
    //
        if (e1 >=4 && e1<=90){
            if (e1>=4 && e1 <=19){
                exp2 = exp2 + ((float)e1/4 + 19)+0.999;
                exp2 = limit(exp2,0,600);
            }
            if (e1 >= 20 && e1 <= 49){
                exp2 = (exp2 + (float)e1/9 +21)+0.999;
                exp2 = limit(exp2,0,600);
            }
            if (e1 >=50 && e1<=65){
                exp2 = exp2 + ((float)e1/16 +17)+0.999;
                exp2 = limit(exp2,0,600);
            }
            if (e1 >=66 && e1 <=79){
                exp2 = exp2 + ((float)e1/4 + 19)+0.999;
                exp2 = limit(exp2,0,600);
            if (exp2 >=200){
                exp2 = exp2 + ((float)e1/9 +21)+0.999;
                exp2 = limit(exp2,0,600);
                }
            }
            if (e1 >=80 && e1 <=99){
                exp2 = exp2 + ((float)e1/4 + 19)+0.999;
                exp2 = exp2 + ((float)e1/9 +21)+0.999;
                exp2 = limit(exp2,0,600);
                if (exp2 >=400){
                    exp2 = exp2 + ((float)e1/16 +17)+0.999;
                    exp2 =  (exp2 * 1.15 +0.999);
                    exp2 = limit(exp2,0,600);
                }
            }
        exp1 = exp1 - e1;
        exp1 = limit(exp1,0,600);
        }
        kq = exp1 + exp2 ;
    }
    return kq;
}
    //
    //
    //

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int kq;
    HP1 = limit(HP1,0,666);
    EXP1 = limit(EXP1,0,600);
    M1 = limit(M1,0,3000);
    if (E2 >99 || E2 <0){
       kq = -99;
    }
    if (E2>=0 || E2 <=99){
        float P1;
        int S ;
        S = pow(round(sqrt(EXP1)),2);
        if (EXP1 >=S){
            P1 = 100;
        }
        else{
            P1 = (((float)EXP1/S +80)/123.00)*100 ;
        }
        //
        //
        if (E2%2==1){
            float x = M1/2;
            while (M1>x){
                if (HP1 <200){
                    HP1 = HP1 * 1.3 +0.999;
                    HP1 = limit(HP1,0,666);
                    M1 = M1 - 150 ;
                    M1 = limit(M1,0,3000);
                }
                if (HP1>=200){
                    HP1 = HP1 * 1.1 + 0.999;
                    HP1 = limit(HP1,0,666);
                    M1 =M1-70;
                    M1 = limit(M1,0,3000);
                }
                if (M1<=x){
                    break;
                }
                if (EXP1 < 400){
                    M1 = M1 - 200;
                    M1 = limit(M1,0,3000);
                    EXP1 = EXP1 *1.13 + 0.999;
                    EXP1 = limit(EXP1,0,600);
                }
                if (EXP1 >=400){
                    M1 = M1-120;
                    M1 = limit(M1,0,3000);
                    EXP1 = EXP1 * 1.13 +0.999;
                    EXP1 = limit(EXP1,0,600);
                }
                if (M1<=x){
                    break;
                }
                if (EXP1 <300){
                    M1 = M1 -100;
                    M1 = limit(M1,0,3000);
                    EXP1 = EXP1 * 0.9 +0.999;
                    EXP1 = limit(EXP1,0,600);
                }
                if (EXP1 >=300){
                    M1 = M1 -120;
                    M1 = limit(M1,0,3000);
                    EXP1 = EXP1 * 0.9 + 0.999;
                    EXP1 = limit(EXP1,0,600);
                }
                if (M1<=x){
                    break;
                }
            }
            HP1 = HP1*0.83 + 0.999;
            HP1 = limit(HP1,0,666);
            EXP1 = EXP1 *1.17 +0.999;
            EXP1 = limit(EXP1,0,600);
        }
        if(E2%2==0){
            do{
                if (HP1 <200){
                    HP1 = HP1 * 1.3 +0.999;
                    HP1 = limit(HP1,0,666);
                    M1 = M1 - 150 ;
                    M1 = limit(M1,0,3000);
                }
                if (HP1>=200){
                    HP1 = HP1 * 1.1 + 0.999;
                    HP1 = limit(HP1,0,666);
                    M1 =M1-70;
                    M1 = limit(M1,0,3000);
                }
                if (M1<0){
                    break;
                }
                if (EXP1 < 400){
                    M1 = M1 - 200;
                    M1 = limit(M1,0,3000);
                    EXP1 = EXP1 *1.13 + 0.999;
                    EXP1 = limit(EXP1,0,600);
                }
                if (EXP1 >=400){
                    M1 = M1-120;
                    M1 = limit(M1,0,3000);
                    EXP1 = EXP1 * 1.13 +0.999;
                    EXP1 = limit(EXP1,0,600);
                }
                if (M1<0){
                    break;
                }
                if (EXP1 <300){
                    M1 = M1 -100;
                    M1 = limit(M1,0,3000);
                    EXP1 = EXP1 * 0.9 +0.999;
                    EXP1 = limit(EXP1,0,600);
                }
                if (EXP1 >=300){
                    M1 = M1 -120;
                    M1 = limit(M1,0,3000);
                    EXP1 = EXP1 * 0.9 + 0.999;
                    EXP1 = limit(EXP1,0,600);
                }
                if (M1<0){
                    break;
                }
            }
            while(1<0);
            HP1 = HP1*0.83 + 0.999;
            HP1 = limit(HP1,0,666);
            EXP1 = EXP1 *1.17 +0.999;
            EXP1 = limit(EXP1,0,600);
            M1 = limit(M1,0,600);
        }
        float P2;
        S = pow(round(sqrt(EXP1)),2);
        if (EXP1 >=S){
            P2 = 100;
        }
        else{
            P2 = (((float)EXP1/S +80)/123.00)*100;
        }
        //
        //
        //
        int P[10]={32 ,47 ,28,79,100,50,22,83,64,11};
        int i;
        float Ptb;
        if (E2>=0 && E2<=9){
            i = E2;
        }
        if ( E2 >=10 && E2 <=99){
            int a = E2/10;
            int b = E2&10;
            i=(a+b)%10;
        }
        if(P1==100 && P2==100 && P[i]==100){
            EXP1 = EXP1 * 0.75;
            EXP1 = limit(EXP1,0,600);
        }
        else{
            Ptb = (P1+P2+P[i])/3.00;
            if (Ptb < 50){
                EXP1 = EXP1 * 1.15 +0.999;
                EXP1 = limit(EXP1,0,600);
                HP1 = HP1 * 0.85 + 0.999;
                HP1 = limit(HP1,0,666);
            }
            else {
                HP1 = HP1 * 0.9 + 0.999;
                HP1 = limit(HP1,0,666);
                EXP1 = EXP1 * 1.2 +0.999;
                EXP1 = limit(EXP1,0,600);
            }
        }
        HP1 = limit(HP1,0,666);
        EXP1 = limit(EXP1,0,600);
        M1 = limit(M1,0,3000);
        kq = HP1 + EXP1 + M1;
    }
    return kq;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int kq;
    if (E3 >99 || E3 <0){
       kq = -99;
    }
    int S1[10][10];
    int i;
    int j ;
    for (i=0;i<10;i++){
        for(j=0;j<10;j++){
            S1[i][j]= ((E3*j)+(i*2))*(i-j);
        }
    }
    int a=0;
    int b=0;
    for (i=0;i<10;i++){
        for(j=0;j<10;j++){
            if (S1[i][j]>(E3*2)){
                a = a+1;
            }
            if (S1[i][j]<(E3*(-1))){
                b = b+1;
            }
        }
    }
    if (a>=0&&a<=9){
        i=a;
    }
    if (a>=10&&a<=99){
        while(a>=10&&a<=99){
            a = (a/10) + (a%10);
        }
        i=a;
    }
    if (b>=0&&b<=9){
        j=b;
    }
    if (b>=10&&b<=99){
        while(b>=10&&b<=99){
            b = (b/10) + (b%10);
        }
        j=b;
    }
    int m = S1[i][j];
    while ( i<=8 && j<=8){
        if(m < S1[i+1][j+1]){
            m=S1[i+1][j+1];
        }
        i++;
        j++;
    }
    while (i>=1 && j>=1){
        if(m < S1[i-1][j-1]){
            m=S1[i-1][j-1];
        }
        i--;
        j--;
    }
    i=a;
    j=b;
    while (i>=1 && j<=8){
        if(m < S1[i-1][j+1]){
            m=S1[i-1][j+1];
        }
        i--;
        j++;
    }
    while (i<=8 && j>=1){
        if(m < S1[i+1][j-1]){
            m=S1[i+1][j-1];
        }
        i++;
        j--;
    }
    i=a;
    j=b;
    if(abs(S1[i][j]) > abs(m)){
        EXP1 = EXP1 * 0.88 + 0.999;
        EXP1 = limit(EXP1,0,600);
        EXP2 = EXP2 * 0.88 + 0.999;
        EXP2 = limit(EXP2,0,600);
        HP1 = HP1 * 0.9 +0.999;
        HP1 = limit(HP1,0,666);
        HP2 = HP2 * 0.9 +0.999;
        HP2 = limit(HP2,0,666);
        kq = S1[i][j];
    }
    else{
        EXP1 = EXP1 * 1.12 + 0.999;
        EXP1 = limit(EXP1,0,600);
        EXP2 = EXP2 * 1.12 + 0.999;
        EXP2 = limit(EXP2,0,600);
        HP1 = HP1 * 1.1 +0.999;
        HP1 = limit(HP1,0,666);
        HP2 = HP2 * 1.1 +0.999;
        HP2 = limit(HP2,0,666);
        kq = m;
    }
    return kq ;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int kq;
    int i;
    int j;
    int sei;
    int sci = -1;
    int b=-1;
    char a;
    for(i=0 ; i< strlen(email) ;i++){
        a = email[i];
        if(a == '@'){
            j = i;
            break;
        }
    }
    string se;
    string m = email;
    string n = s;
    se = m.substr(0,(j));
    for(i=0 ; i<n.length() ; i++){
        if ( (n[i]>='a'&&n[i]<='z') || (n[i]>='A'&&n[i]<='Z') || (n[i]>='0'&&n[i]<='9') || n[i]=='!' || n[i]=='@' || n[i]=='#' || n[i]=='$' || n[i]=='%' ){
            b=-1;
        }
        else {
            b = i;
            break ;
        }
    }
    for (int k=1 ; k < (n.length()-1); k++){
        if (n[k]== n[k-1] && n[k] == n[k+1]){
            sci = (k-1);
            break;
        }
    }
    if ( n.length() <8) {
        kq = -1;
    }
    else if ( n.length() >20){
        kq = -2;
    }
    else if (n.find(se) != string::npos){
        sei = n.find(se);
        kq = -(300 + sei);
    }
    else if(sci != -1){
        kq = sci;
    }
    else if ( (n.find("@") == string::npos) || (n.find("#")==string::npos) || (n.find("$")==string::npos) || (n.find("%")==string::npos) || (n.find("!"))){
        kq = -5;
    }
    else if (b != -1){
        kq = b;
    }
    else {
        kq =10;
    }

    return kq ;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int i;
    int j;
    int a=1;
    int slxh=0;//so lan xuat hien
    int maxxh=0;//xuat hien nhieu nhat
    int vt=1;//vi tri can tim
    for (i=0 ; i< num_pwds ; i++){
        const char * mkht = arr_pwds[i];
        for (j=0 ; j < num_pwds ; j++){
            if(strcmp(mkht , arr_pwds[j])==0){
                slxh = slxh + 1 ;
            }
        }
        if (slxh > maxxh || (slxh == maxxh && ( strlen(mkht))> a )) {
            maxxh = slxh;
            a  = strlen(mkht);
            vt = i;
        }
        slxh=0;
    }
    return vt;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
