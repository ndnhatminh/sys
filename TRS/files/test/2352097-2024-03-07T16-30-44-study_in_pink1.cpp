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

//Change the right value of variables
void hp1Change (int & HP1){
    if (HP1>666) HP1=666;
    if (HP1<0) HP1=0;
}
void hp2Change (int & HP2){
    if (HP2>666) HP2=666;
    if (HP2<0) HP2=0;
}
void exp1Change (int & EXP1){
    if (EXP1>600) EXP1=600;
    if (EXP1<0) EXP1=0;
}
void exp2Change (int & EXP2){
    if (EXP2>600) EXP2=600;
    if (EXP2<0) EXP2=0;
}
void m1Change (int & M1){
    if (M1>3000) M1=3000;
    if (M1<0) M1=0;
}
void m2Change (int & M2){
    if (M2>3000) M2=3000;
    if (M2<0) M2=0;
}
void eChange (int & E1, int & E2, int & E3){
    if (E1<0 || E1 >99) E1=-99;
    if (E2<0 || E2 >99) E2=-99;
    if (E3<0 || E3 >99) E3=-99;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    int D;
    if (E1<0 || E1 >99) return -99;
    else{
        if (E1>=0 && E1<=3){
            if (E1 == 0) EXP2 += 29;
            else if (E1 == 1) EXP2 += 45;
            else if (E1 == 2) EXP2 += 75;
            else if (E1 == 3) EXP2 += (29 + 45 + 75);

            D = E1 * 3 + EXP1 * 7;
            float tee = D;
            if (D % 2 == 0) EXP1 = ceil((EXP1*1.0f) + (tee/200.0f));
            else EXP1 = ceil((EXP1*1.0f) - (tee/100.0f));
        }else{
            float E11 = E1;
            if (E11>=4 && E11<=19) EXP2 += (ceil(E11/4)+19);
            else if (E11>=20 && E11<=49) EXP2 += (ceil(E11/9)+21);
            else if (E11>=50 && E11<=65) EXP2 += (ceil(E11/16)+17);
            else if (E11>=66 && E11<=79) {
                EXP2 += (ceil(E11/4)+19);
                if (EXP2 > 200) EXP2 += (ceil(E11/9)+21);
            } else if (E11>=80 && E11<=99) {
                EXP2 += ceil(E11/4)+19;
                EXP2 += ceil(E11/9)+21;
                if (EXP2 > 400){
                    EXP2 += ceil(E11/16)+17;
                    EXP2 =  ceil((float)EXP2*115/100);
                }
            }
            EXP1 -= E1;
        }
    
    exp1Change(EXP1);
    exp2Change(EXP2);
    return (EXP1 + EXP2);
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0 || E2 >99) return -99;
    else{
        float P1, P2, P3;
        //duong 1
        int S1 = round ((float) (sqrt(EXP1)));
        S1*=S1;
        if (EXP1 >= S1) P1=100;
        else P1 = ((((float)EXP1/(float)S1)+80)/123)*100;

        //duong 2
        int mdau = ceil((float)M1 * 0.5);
        int mchi=0;
        if (E2 % 2 == 0){   //E2 chan
            if (HP1<200){   //y 1
            HP1 = HP1*1.3+0.999;
            M1 -= 150;
            hp1Change(HP1);
        }else{
            HP1 = HP1*1.1+0.999;
            M1 -= 70;
            hp1Change(HP1);
        }
            if (M1>0){
                if (EXP1 < 400){    //y 2
                    M1 -= 200;
                } else{
                    M1 -= 120;
                }
                EXP1 = EXP1*1.13+0.999;
                exp1Change(EXP1); 
            } 

            if (M1>0){
                if (EXP1 < 300){    //y 3
                    M1 -= 100;
                } else{
                    M1 -= 120;
                }
                EXP1 = EXP1*0.9+0.999; 
                exp1Change(EXP1);    
            }
        HP1 = HP1*0.83+0.999;
        EXP1 = EXP1*1.17+0.999;  
        hp1Change(HP1); 
        exp1Change(EXP1); 
        }else{  //E2 so le
            while (mchi<=mdau){
                if (HP1<200){   //y 1
                    HP1 = HP1*1.3+0.999;
                    mchi += 150;
                    hp1Change(HP1);
                }else{
                    HP1 = HP1*1.1+0.999;
                    mchi += 70;
                    hp1Change(HP1);
                }
                if (mchi>mdau) break;
                if (EXP1 < 400){    //y 2
                    mchi += 200;
                } else{
                    mchi += 120;
                }
                EXP1 = EXP1*1.13+0.999;
                exp1Change(EXP1); 
                if (mchi>mdau) break;
                if (EXP1 < 300){    //y 3
                    mchi += 100;
                } else{
                    mchi += 120;
                }
                EXP1 = EXP1 = EXP1*0.9+0.999;
                exp1Change(EXP1); 
                if (mchi>mdau) break;
            }
            M1 -= mchi;
            HP1 = HP1*0.83+0.999;
            EXP1 = EXP1*1.17+0.999; 
            hp1Change(HP1); 
            exp1Change(EXP1); 
        }
        int S2 = round ((float) (sqrt(EXP1)));
        S2*=S2;
        if (EXP1 >= S2) P2=100;
        else P2 = ((((float)EXP1/(float)S2)+80)/123)*100;

        int a[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; //duong 3
        if (E2>=0 && E2<=9) P3= a[E2];
        else {
            int temp = E2;
            int sum=0;
            sum += (temp%10);
            temp /= 10;
            sum += temp;
            P3 = a[sum%10];
        }


        //sau khi di ca 3 duong
        if (P1 == 100 && P2 == 100 && P3 == 100) EXP1 = EXP1*0.75+0.999;
        else{
            float P = (P1+P2+P3)/3;
            if (P<50){
                HP1 = HP1*0.85+0.999;
                EXP1 = EXP1*1.15+0.999;
            }else{
                HP1 = HP1*0.9+0.999;
                EXP1 = EXP1*1.2+0.999;
            }
        }

    hp1Change(HP1);
    exp1Change(EXP1);
    m1Change(M1);

    return HP1+EXP1+M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int a[10][10];
    if (E3<0 || E3 >99) return -99;
    else{
    for (int i=0; i<=9;i++){    //gan ca gia tri = 0
        for (int j=0;j<=9;j++){
            a[i][j]=0;
        }
    }
    int countduong=0, countam=0;
    int xgap,ygap,temp,sum;

    for (int i=0; i<=9;i++){    //khoi tao ma tran taxi
        for (int j=0;j<=9;j++){
            a[i][j]= ((E3*j)+(i*2)) * (i-j);
            if (a[i][j]>(E3*2)) countduong++;
            if (a[i][j]<(0-E3)) countam++;
        }
    }

    if (countduong<=9) xgap = countduong;
    else {
        temp = countduong;
        sum=0;
        sum += (temp%10);
        temp /= 10;
        sum += temp;
        if (sum>9){
            temp = sum;
            sum=0;
            sum += (temp%10);
            temp /= 10;
            sum += temp;
        }
        xgap = sum;   
    }
    if (countam<=9) ygap = countam;
    else {  
        temp = countam;
        sum=0;
        sum += (temp%10);
        temp /= 10;
        sum += temp;
        if (sum>9){
            temp = sum;
            sum=0;
            sum += (temp%10);
            temp /= 10;
            sum += temp;
        }
        ygap = sum;   
    }


    int eMax = a[xgap][ygap];
    int u,v;
    if ((xgap+ygap)<=9){//check duong cheo phai
        u=0;
        v= ygap + xgap;
        while (v>=0){   
        if (a[u][v] > eMax) eMax = a[u][v];
        u++;
        v--;
    }
    }else{
        u= (xgap + ygap)-9;
        v= 9;
        while (u<=9){
        if (a[u][v] > eMax) eMax = a[u][v];
        u++;
        v--;
    }
    }

    if (xgap<=ygap){//check duong cheo trai
        u=0;
        v= ygap - xgap;
        while (v<=9){   
        if (a[u][v] > eMax) eMax = a[u][v];
        u++;
        v++;
    }
    }else{
        u= xgap - ygap;
        v= 0;
        while (u<=9){
        if (a[u][v] > eMax) eMax = a[u][v];
        u++;
        v++;
        }
    }


    if (abs(a[xgap][ygap])>eMax){
                HP1 = HP1*0.9+0.999;
                EXP1 = EXP1*0.88+0.999;
                HP2 = HP2*0.9+0.999;
                EXP2 = EXP2*0.88+0.999;
                hp1Change(HP1);
                hp2Change(HP2);
                exp1Change(EXP1);
                exp2Change(EXP2); 
                return a[xgap][ygap];   
    }else{
                HP1 = HP1*1.1+0.999;
                EXP1 = EXP1*1.12+0.999; 
                HP2 = HP2*1.1+0.999;
                EXP2 = EXP2*1.12+0.999; 
                hp1Change(HP1);
                hp2Change(HP2);
                exp1Change(EXP1);
                exp2Change(EXP2);
                return eMax;
    }

    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int checkvalue=0;
    string pw = s;
    string se = email;
    int n = se.length()-1;
    for (int i=n; i>=0; i--){
        if (se[i]=='@') break;
        se.pop_back();
    }
    se.pop_back();
    //dieu kien 2
    if (pw.length()<8) return -1;
    
    //dieu kien 3
    if (pw.length()>20) return -2;
    
    //dieu kien 4
    if (se.length()==0) return 0-(300+0);
    else{
    size_t found = pw.find(se);
    if(found != string::npos) {
        return 0-(300+found);
    }
    }
    
    //dieu kien 5
    for (int i=0; i<pw.length()-2;i++){
        if ((pw[i]==pw[i+1]) && (pw[i]==pw[i+2])){
            return 0-(400+i);
        }
    }

    //dieu kien 6
    bool checkdk6 = false;
    for (int i=0;i<pw.length();i++){
        if (pw[i]=='@' || pw[i]=='#' ||pw[i]=='%' ||pw[i]=='$' ||pw[i]=='!') checkdk6 = true;
    }
    if (checkdk6 == false) return -5;

    //dieu kien [
    for (int i=0; i<pw.length();i++){
        if (pw[i]=='[') return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string a[num_pwds];
    for (int i=0;i<num_pwds;i++){
        a[i]=arr_pwds[i];
    }
    
    int vitri=0;
    string s1,s2;
    s1=a[0];
    int eCount=1;
    for (int j=1;j<num_pwds;j++){ //dem pw dau
        if (a[0]==a[j]) eCount++;
    }
    int eCountmax=eCount;

    for (int i=1;i<num_pwds;i++){ //dem nhung pw sau
        eCount=1;
        for (int j=i+1;j<num_pwds;j++){
            if (a[i]==a[j]) eCount++;
        }
        s2=a[i];
        if (eCount > eCountmax){
            vitri = i;
            s1=a[i];
            eCountmax=eCount;
        }

        if (eCount == eCountmax){
            if (s2.length()>s1.length()){
                s1=s2;
                vitri=i;
            }
        }
    }
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////