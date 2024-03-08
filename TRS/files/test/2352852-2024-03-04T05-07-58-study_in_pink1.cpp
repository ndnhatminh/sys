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
int checkmax(int a, int b) {
    return (a > b) ? a : b;
}

// Task 1


int resetHP(int HP){
    if(HP>666){
        HP=666;
    }
    else if(HP<0){
        HP=0;
    }
    else{
        HP=HP;
    }
    return HP;
}
int resetEXP(int EXP){
    if(EXP<0)
    EXP=0;
    else if(EXP>600)
    EXP=600;
    else{
        EXP=EXP;
    }
    return EXP;
}
int resetM(int M){
    if(M>3000){
        M=3000;
    }
    else if(M<0){
        M=0;
    }
    else{
        M=M;
    }
    return M;
}

int firstMeet(int & exp1, int & exp2, int e1) 
{
    if (e1 < 0 || e1 > 99) 
    {
        return -99;
    }
    if (e1 >= 0 && e1 <= 3)
     {  exp1=resetEXP(exp1);
        exp2=resetEXP(exp2);
        switch (e1) {
            case 0:
                exp2 += 29;
                exp2 = resetEXP(exp2);
                break;
            case 1:
                exp2 += 45;
                exp2 = resetEXP(exp2);
                break;
            case 2:
                exp2 += 75;
                exp2 = resetEXP(exp2);
                break;
            case 3:
                exp2 += 29 + 45 + 75;
                exp2 = resetEXP(exp2);
                break;
            default:
                break;
        }
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + static_cast<double>(D) / 200);
            exp1 = resetEXP(exp1);
        }
        else 
        {
            exp1 = ceil(exp1 - static_cast<double>(D) / 100);
            exp1 = resetEXP(exp1);
        }
    }
    else if (e1 >= 4 && e1 <= 99) 
    {   exp1=resetEXP(exp1);
        exp2=resetEXP(exp2);
        if (e1 >= 4 && e1 <= 19) 
        {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19) - 1e-10);
            exp2 = resetEXP(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) 
        {
            exp2 = ceil(exp2 + (e1 / 9.0 + 21) - 1e-10);
            exp2 = resetEXP(exp2);
        }
        else if (e1 >= 50 && e1 <= 65) 
        {
            exp2 = ceil(exp2 + (e1 / 16.0 + 17) - 1e-10);
            exp2 = resetEXP(exp2);
        }
        else if (e1 >= 66 && e1 <= 79) 
        {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19) - 1e-10);
            exp2 = resetEXP(exp2);
            if (exp2 > 200) 
            {
                exp2 = ceil(exp2 + (e1 / 9.0 + 21) - 1e-10);
                exp2 = resetEXP(exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99) 
        {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19) - 1e-10);
            exp2 = resetEXP(exp2);
            exp2 = ceil(exp2 + (e1 / 9.0 + 21) - 1e-10);
            exp2 = resetEXP(exp2);
            if (exp2 > 400) 
            {
                exp2 = ceil(exp2 + (e1 / 16.0 + 17) - 1e-10);
                exp2 = resetEXP(exp2);
                exp2 = ceil(exp2 + 0.15 * exp2 - 1e-10);
                exp2 = resetEXP(exp2);
            }
        }
        exp1 = exp1 - e1;
        exp1 = resetEXP(exp1);
    }
    return exp1 + exp2;
}

//Task 2


bool onedigit(int n ){
    if(n>=0&&n<10)
    return true;
    else return false;
}
int tong2chuso(int n){
    int chuc=n/10;
    int donvi=n%10;
    return (chuc+donvi)%10;
}
int tong2chusomoi(int n) {
    int chuc = n / 10;
    int donvi = n % 10;
    return chuc + donvi;
}

int hamcheck(int n) {
    if (onedigit(n)) {
        return n;
    }
    else {
        n = tong2chusomoi(n);
        if (onedigit(n)) {
            return n;
        }
        else {
            n = tong2chusomoi(n);
            return n;
        }
    }
}
bool ischinhphuong(int n){
   if(n<0){
    return false;
   }
   int num=sqrt(n);
    return num*num==n;
}
float chinhphuong(int n ){
    if(ischinhphuong(n))
    return n;
    int lower=sqrt(n);
    int upper=sqrt(n)+1;
    int thap=lower*lower;
    int cao=upper*upper;
    if(abs(cao-n)<=abs(thap-n)) return cao;
    else
    return thap;
}
double conduong1(int & HP1, int & EXP1, int & M1, int E){
     EXP1=resetEXP(EXP1);
       
    float s;
    s=chinhphuong(EXP1);
    double p1;
    if(EXP1>=s) 
    p1=1.0;
    else 
    p1=double((EXP1/s+80))/123;
   return p1;
}
double conduong2(int &HP1, int &EXP1, int &M1, int E2){
    EXP1=resetEXP(EXP1);
    HP1=resetHP(HP1);
    float tientieu = 0;
    int taxi = 200;
    int ngua = 120;
    int food = 150;
    int drink = 70;
    M1=resetM(M1);
    double half_M1 = double(M1) / 2; // 1/2 g
    

    if(E2 % 2 != 0){
        while(tientieu <= half_M1&&M1>0){
            if(HP1 < 200){
                HP1 = ceil(1.3 * HP1- 1e-10);
                HP1 = resetHP(HP1);
                tientieu += food;
            }
            else{
                HP1 = ceil(1.1 * HP1- 1e-10);
                tientieu += drink;
                HP1 = resetHP(HP1);
            }
            if(tientieu>half_M1){
            break;
        }
            
            if(EXP1 < 400){
                tientieu += taxi;
                EXP1 = ceil(1.13 * EXP1- 1e-10);
                EXP1 = resetEXP(EXP1);
            }
            else{
                tientieu += ngua;
                EXP1 = ceil(1.13 * EXP1- 1e-10);
                EXP1 = resetEXP(EXP1);
            }
            if(tientieu>half_M1){
            break;
        }
            
            if(EXP1 < 300){
                tientieu += 100;
                EXP1 = ceil(0.9 * EXP1- 1e-10);
                EXP1 = resetEXP(EXP1);
            }
            else{
                tientieu += 120;
                EXP1 = ceil(0.9 * EXP1- 1e-10);
                EXP1 = resetEXP(EXP1);
            }
            if(tientieu>half_M1){
            break;
        }
        }
        HP1=ceil(0.83*HP1- 1e-10);
        HP1=resetHP(HP1);
        EXP1=ceil(1.17*EXP1- 1e-10);
        EXP1=resetEXP(EXP1);
        M1=M1-tientieu;
        M1=resetM(M1);
    }
    else{
         while(M1!=0){
            if(HP1 < 200){
                HP1 = ceil(1.3 * HP1- 1e-10);
                HP1 = resetHP(HP1);
                M1=M1-150;
                M1=resetM(M1);
            }
            else{
                HP1 = ceil(1.1 * HP1- 1e-10);
                HP1 = resetHP(HP1);
                M1=M1-70;
                M1=resetM(M1);
                
            }
            if(M1==0){
            break;
        }
            
            if(EXP1 < 400){
                M1=M1-taxi;
                M1=resetM(M1);
                EXP1 = ceil(1.13 * EXP1- 1e-10);
                EXP1 = resetEXP(EXP1);
            }
            else{
                M1=M1-120;
                M1=resetM(M1);
                EXP1 = ceil(1.13 * EXP1- 1e-10);
                EXP1 = resetEXP(EXP1);
            }
            if(M1==0){
            break;
        }
            
            if(EXP1 < 300){
                M1=M1-100;
                M1=resetM(M1);
                EXP1 = ceil(0.9 * EXP1- 1e-10);
                EXP1 = resetEXP(EXP1);
            }
            else{
                M1=M1-120;
                M1=resetM(M1);
                EXP1 = ceil(0.9 * EXP1- 1e-10);
                EXP1 = resetEXP(EXP1);
            }
            if(M1==0){
            break;
        }
        break;
        }
         HP1=ceil(0.83*HP1- 1e-10);
        HP1=resetHP(HP1);
        EXP1=ceil(1.17*EXP1- 1e-10);
        EXP1=resetEXP(EXP1);
        M1=resetM(M1);
        
    }

    float s;
    s=chinhphuong(EXP1);
    double p2;
    if(EXP1>=s) 
    p2=1.0;
    else 
     p2=double((EXP1/s+80))/123;
    return p2;
}
double conduong3(int & HP1, int & EXP1, int & M1, int E2){
     EXP1=resetEXP(EXP1);
    double p3;
    int pos;
    double arr[10]={0.32, 0.47, 0.28, 0.79, 1.0, 0.50, 0.22, 0.83, 0.64, 0.11};
    if(onedigit(E2)){
        p3=arr[E2];
    }
    else{
        pos=tong2chuso(E2);
        p3=(arr[pos]);
    }
    return p3;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
     if(E2<0||E2>99){
        return -99;
    }
    double p1=conduong1(HP1,EXP1,M1,E2);
    double p2= conduong2(HP1,EXP1,M1,E2);
    double p3=conduong3(HP1,EXP1,M1,E2);
    double pav;
    pav = double((p1 + p2 + p3)) / 3;

    if (pav == 1) {
        EXP1 = ceil(0.75 * EXP1 - 1e-10);
        EXP1 = resetEXP(EXP1);
    } else if (pav < 0.5) {
        HP1 = ceil(0.85 * HP1 - 1e-10);
        HP1 = resetHP(HP1);

        EXP1 = ceil(1.15 * EXP1 - 1e-9);
        EXP1 = resetEXP(EXP1);
        
    } else if (pav >= 0.5) {
        HP1 = ceil(0.9 * HP1 - 1e-10);
        HP1 = resetHP(HP1);

        EXP1 = ceil(1.2 * EXP1 - 1e-10);
        EXP1 = resetEXP(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
     if(E3<0||E3>99){
        return -99;
    }
    EXP1=resetEXP(EXP1);
    HP1=resetHP(HP1);
    EXP2=resetEXP(EXP2);
    HP2=resetHP(HP2);
    int duongdi[10][10];
    int diemi;
    int diemj;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            duongdi[i][j] = (((E3 * j) + (i * 2)) * (i - j));
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (duongdi[i][j] > (E3 * 2)) {
                count1++;
            }
            if (duongdi[i][j] < (-E3)) {
                count2++;
            }
        }
    }

    diemi = hamcheck(count1);
    diemj = hamcheck(count2);

    int maxcheophai = duongdi[diemi][diemj];
    int maxcheotrai = duongdi[diemi][diemj];
    int diemxechay=duongdi[diemi][diemj];
    int hieucheotrai = diemi - diemj;
    int tongcheophai = diemi + diemj;
    int poswaston=0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i - j == hieucheotrai) {
                maxcheotrai = checkmax(maxcheotrai, duongdi[i][j]);
            }
            if (i + j == tongcheophai) {
                maxcheophai = checkmax(maxcheophai, duongdi[i][j]);
            }
        }
    }
    poswaston = checkmax(maxcheotrai, maxcheophai);
    poswaston=abs(poswaston);
    if (abs(diemxechay)>poswaston){
        EXP1=ceil(double(EXP1)*0.88- 1e-10);
        EXP1=resetEXP(EXP1);
        HP1=ceil(double(HP1)*0.9- 1e-10);
        HP1=resetHP(HP1);
        EXP2=ceil(double(EXP2)*0.88- 1e-10);
        EXP2=resetEXP(EXP2);
        HP2=ceil(double(HP2)*0.9- 1e-10);
        HP2=resetHP(HP2);
    }
    else{
         EXP1=ceil(double(EXP1)*1.12- 1e-10);
         EXP1=resetEXP(EXP1);
       HP1=ceil(double(HP1)*1.1- 1e-10);
       HP1=resetHP(HP1);
       EXP2=ceil(double(EXP2)*1.12- 1e-10);
         EXP2=resetEXP(EXP2);
       HP2=ceil(double(HP2)*1.1- 1e-10);
       HP2=resetHP(HP2);
    }
   if(abs(diemxechay)>poswaston){
    return diemxechay;
   }
   else return poswaston;
}

// Task 4
int hamfound(string a, string b) {
    int c = b.find(a);
    return c;
}
bool kytucdacbiet(char c) {
    return (c == '$' || c == '%' || c == '@' || c == '!' || c == '#');
}
int foundkytu(const char*s){
        int count=0;
        for (int i = 0; i <= strlen(s) - 1; ++i) {
         if (kytucdacbiet(s[i]))
         count++;
        }
        return count;
}

int checkPassword(const char* s, const char* email) {
string stringemail(email);
int found=stringemail.find('@');
    string se=stringemail.substr(0, found);
    int sdai=strlen(s);
    if(sdai<8){
        return -1;}
    else if(sdai>20){
        return -2;
 }
 if(hamfound(se,s)!=-1){
    return -(300+hamfound(se,s));
 }
 for (int i = 0; i < sdai; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400+i);
        }
    }
 if(foundkytu(s)==0){
    return -5;
 }
    for (int j = 0; j < sdai; j++) {
        if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))) {
            if (!kytucdacbiet(s[j]))
                return j;
        }
    }
 return -10;
}

// Task 5


int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int xuathiennhieunhat = 0;
    int vitri = 0;
    string c; 

    for(int i = 0; i < num_pwds; i++) { 
        int dem = 0;
        for(int j = i; j < num_pwds; j++) {                           
            if (string(arr_pwds[i]) == string(arr_pwds[j])){ 
                dem++;
            }        
        }
        if(dem > xuathiennhieunhat) {
            xuathiennhieunhat = dem;
            c = string(arr_pwds[i]);
            vitri = i;
        }
        else if(dem == xuathiennhieunhat && strlen(arr_pwds[i]) > c.length()) {
            c = string(arr_pwds[i]);
            vitri = i;
        }
    }
    return vitri;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////