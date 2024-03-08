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

void check_EXP(int &exp){
    if(exp > 600) exp = 600;
    if(exp < 0) exp = 0;
}
void check_HP(int &hp){
    if(hp > 666) hp = 666;
    if(hp < 0 ) hp = 0;
}
void check_M(int &m){
    if(m > 3000) m = 3000;
    if(m < 0) m = 0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1>=0 && e1<=99) {
        check_EXP(exp1);
        check_EXP(exp2);
        if(e1<4) {
            switch(e1) {
                case 0: exp2 += 29; break; 
                case 1: exp2 += 45; break;
                case 2: exp2 += 75; break;
                case 3: exp2 += 149; break;
            }
        int D; 
        D = e1*3 + exp1*7;
        if(D%2 == 0) {
            exp1 = exp1 + (double)D/200 + 0.999;
        }
        else { 
            exp1 = exp1 - (double)D/100 + 0.999;
        }
        check_EXP(exp1);
        check_EXP(exp2);
    }
    else {
        if((e1 >= 4 && e1 <= 19) || (e1 >= 66 && e1 <= 79) || (e1 >= 80 && e1 <= 99)){
            exp2 = exp2 + (double)e1/4 + 19 + 0.999 ;
        }
        if((e1 >= 20 && e1 <= 49) || (e1 >= 66 && e1 <= 79 && exp2 > 200) || (e1 >= 80 && e1 <= 99)){
            exp2 = exp2 + (double)e1/9 + 21 + 0.999;
        }
        if((e1 >= 50 && e1 <= 65) || (e1 >= 80 && e1 <= 99 && exp2 > 400)){
            exp2 = exp2 + (double)e1/16 + 17 + 0.999;
        }
        if(e1 >= 80 && e1 <= 99 && exp2 > 400) {
            exp2 = (double)exp2*1.15 + 0.999;
        }
    //EXP cua Sherlock giam xuong 
            exp1 -= e1; 
        check_EXP(exp1);
        check_EXP(exp2);
    }
        return exp1 + exp2;
    }
    return -99;
}
double prob(int &EXP){
    int S = pow(round(sqrt(EXP)), 2);
    double P; 
    if(EXP >= S) P = 1;  
    else 
    { 
        double div = (double)EXP/S;
        P = (double)(div+80)/123;
    } 
    return P;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2>=0 && E2<=99)
    {
        check_EXP(EXP1);
        check_HP(HP1);
        check_M(M1);
        double half_m = M1*0.5;
///////////////////////CON DUONG 01////////////////////////
        double P1 = prob(EXP1);  
///////////////////////CON DUONG 02//////////////////////
    while(E2%2==0) 
    {
        if(M1<=0)
        {
            HP1 = HP1*0.83 + 0.999; 
            EXP1 = EXP1*1.17 + 0.999;
            break;
        }
        if(HP1 < 200) 
        {
            HP1 = HP1*1.3 + 0.999; M1 -= 150; 
        }
        else 
        {
            HP1 = HP1*1.1 + 0.999; M1 -= 70;    
        }
        check_HP(HP1); 
        //check so tien con lai
        if(M1 <= 0) 
        {
            HP1 = HP1*0.83 + 0.999; 
            EXP1 = EXP1*1.17 + 0.999;
            break;
        }   
        //phuong tien di chuyen
        if(EXP1 < 400)  M1 -= 200;
        else            M1 -= 120;
        EXP1 = EXP1*1.13 + 0.999;    
        //check so tien con lai  
        if(M1 <= 0) 
        {
            HP1 = HP1*0.83 + 0.999; 
            EXP1 = EXP1*1.17 + 0.999;
            break;
        }
        //nguoi vo gia cu
        if(EXP1 < 300)    M1 -= 100; 
        else              M1 -= 120;
        EXP1 = EXP1*0.9 + 0.999;  
        //check so tien con lai
        if(M1 <= 0) 
        {
            HP1 = HP1*0.83 + 0.999; 
            EXP1 = EXP1*1.17 + 0.999;
            break;
        } 
        //cap nhat EXP va HP tuong tu E2 le
        HP1 = HP1*0.83+ 0.999; 
        EXP1 = EXP1*1.17 + 0.999;
        break;
    }

    while(E2%2!=0)
    { 
        if(M1<=0)
        {
            HP1 = HP1*0.83 + 0.999; 
            EXP1 = EXP1*1.17 + 0.999;
            break;
        }
        if(HP1 < 200) 
        {
            HP1 = HP1*1.3 + 0.999; M1 -= 150; 
        }
        else 
        {
            HP1 = HP1*1.1 + 0.999; M1 -= 70;
        }
        check_HP(HP1);
        //check so tien con lai
        if(M1<half_m || M1<=0) 
        {
            HP1 = HP1*0.83 + 0.999; 
            EXP1 = EXP1*1.17 + 0.999;
            break;
        }
        //phuong tien di chuyen
        if(EXP1<400)  M1 -= 200;
        else          M1 -= 120;
        EXP1 = EXP1*1.13 +0.999;
        check_EXP(EXP1);
        //check so tien con lai
        if((double)M1<half_m || M1<=0) 
        {
            HP1 = HP1*0.83 + 0.999; 
            EXP1 = EXP1*1.17 +0.999;
            break;
        }
        //NGUOI VO GIA CU
        if(EXP1 < 300)    M1 -= 100;
        else              M1 -= 120;
        EXP1 = EXP1*0.9 + 0.999;
        check_EXP(EXP1);
        //KIEM TRA SO TIEN CON LAI
        if(M1<half_m || M1<=0) 
        {
            HP1 = HP1*0.83 + 0.999; 
            EXP1 = EXP1*1.17 + 0.999;
            break;
        } 
    }
        check_EXP(EXP1);
        check_HP(HP1);
        check_M(M1);
        double P2 = prob(EXP1);   
///////////////////////CON DUONG 03///////////////////////////
        int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        double P3;
        if(E2/10 == 0) P3 = (double)P[E2]/100; 
        else 
        {
            int n = E2/10 + E2%10;  
            if(n/10==0)  P3 = (double)P[n]/100;   
            else         P3 = (double)P[n%10]/100;
        
        }
        if(P1==1 && P2==1 && P3==1) EXP1 = EXP1*0.75 + 0.999;
        else 
        {
            double Ptb = (double)(P1+P2+P3)/3;  
            if(Ptb<0.5) 
            {
                HP1 = HP1*0.85 + 0.999;
                EXP1 = EXP1*1.15 + 0.999;
            }
            else 
            {
                HP1 = HP1*0.9 + 0.999;
                EXP1 = EXP1*1.2 + 0.999;
            }
        }
        check_EXP(EXP1);
        check_HP(HP1);
        check_M(M1);
        return HP1 + EXP1 + M1;
    }
    return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3>=0 && E3<=99) 
    {
        check_EXP(EXP1);
        check_EXP(EXP2);
        check_HP(HP1);
        check_HP(HP2);
        //tao mang
        int ar[10][10];
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                ar[i][j] = (E3*j + i*2)*(i-j);
            }
        }
        //xac dinh vi tri gap nhau cua xe va sherlock
        int x = 0; int y = 0;
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(ar[i][j] > E3*2) x++;
                if(ar[i][j] < 0-E3) y++;
            }
        }
        do{
            x = x/10 + x%10;
            y = y/10 + y%10;
        }while(x/10 != 0 || y/10 !=0);
   
        //so diem cua xe taxi tai vi tri (x,y)
        int diem_taxi = ar[x][y]; int diem_SW = ar[x][y];
        int i = x; int j = y;
        while(i>0 && j!=9)
        {
            i--; j++; 
            if(abs(ar[i][j]) > diem_SW) diem_SW = ar[i][j];
        }
        i = x; j = y;
        while(j>0 && i!=9)
        { 
            i++; j--; 
            if(ar[i][j] > diem_SW) diem_SW = ar[i][j];
        }
        i = x; j = y;
        while(j>0 && i>0)
        {
            i--; j--; 
            if(ar[i][j] > diem_SW) diem_SW = ar[i][j];
        }
        while(j!=9 && i!=9)
        {
            i++; j++;  
            if(ar[i][j] > diem_SW) diem_SW = ar[i][j];
        }
//Sherlock va Watson co duoi kip taxi khong???
        int result;
        if(abs(diem_taxi) <= abs(diem_SW)) 
        {
            EXP1 = EXP1*1.12 + 0.999;
            HP1 = HP1*1.1 + 0.999;
            EXP2 = EXP2*1.12 + 0.999;
            HP2 = HP2*1.1 + 0.999;
            result = diem_SW;
        }
        else 
        { 
            EXP1 = EXP1*0.88 + 0.999;
            HP1 = HP1*0.9 + 0.999;
            EXP2 = EXP2*0.88 + 0.999;
            HP2 = HP2*0.9 + 0.999; 
            result = diem_taxi;
        }
        check_EXP(EXP1);
        check_EXP(EXP2);
        check_HP(HP1);
        check_HP(HP2); 

        return result;
    }
     return -99;
}
bool checkSymbol(string s_) {
    const string sym = "!@#$%"; 
    for(char str1 : s_)
    {
        for(char str2 : sym) 
        {
            if(str1 == str2) return 1;
        }
    }
    return 0;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s_(s);
    string email_(email);
    //tao chuoi se tu email
    int found = email_.find('@');     
    string se = email_.substr(0,found);
    //kiem tra do dai password
    if(s_.size() < 8) return -1;
    if(s_.size() > 20) return -2;
    //kiem tra password co chua chuoi se khong
    int sei = s_.find(se);
    if(sei != -1) return -(300 + sei);
    //kiem tra so lan xuat hien cua ki tu
    for(int i=0; i<=s_.size()-3; i++) 
    {
        if(s_[i] == s_[i+1] && s_[i] == s_[i+2]) 
        {
            return -(400 + i);
        }
    }
    //kiem tra password co chua ki tu dac biet khong
    if(!checkSymbol(s_)) return -5;
    //kiem tra password co chua ki tu khong hop le khong
    for(int i=0; i<s_.size(); i++)
    {
        if(s_[i] == '@' ||s_[i] == '!' || s_[i] == '#' || s_[i] == '$' || s_[i] == '%' || isalnum(s_[i])) 
        {
            continue;
        }
        else return i;
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string arr[num_pwds];
    string p[30];
     for(int i=0; i<num_pwds; i++)
    {
        arr[i] = arr_pwds[i];
    }
    int max = 0, count, x=1, y = 0;
    for(int i=0; i < num_pwds; i++)
    {
        count = 1;
        for(int j=i+1; j < num_pwds; j++)
        {
            if(arr[i] == arr[j])  count++;
        }
        if(count > max)  
        {
            p[0] = arr[i];      
            max = count; y = i; 
            if(x!=1) x = 1;
        }
        else if(count == max) 
        {
            p[x] = arr[i];
            ++x;
        }
    }
    if(x!=1) {
    for(int i=0; i<x; i++) 
        {
        if(p[0].size() < p[i].size()) p[0] = p[i];
        }
    }
    for(int i=0; i<num_pwds; i++)
    {
        if(arr[i] == p[0]) 
        { 
            y = i;
            break;
        }
    }
    return y;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////