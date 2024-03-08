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
    if ((e1>=0) && (e1<=99)) {
    if (e1>=0 && e1<=3)
    {
        if (e1==0) exp2+=29;
        if (e1==1) exp2+=45;
        if (e1==2) exp2+=75;
        if (e1==3) exp2+=29+45+75;
        int d=e1*3+exp1*7;
        if (d%2==0) exp1+=ceil(d/200.0);
        else exp1=ceil(exp1-(d/100.0));
        if (exp1<0) exp1=0;
        if (exp2<0) exp2=0;
        if (exp1>600) exp1=600;
        if (exp2>600) exp2=600;
    }
    if (e1>=4 && e1<=99)
    {
        if (e1>=4 && e1<=19) exp2+=ceil(e1/4.0+19);
        if (e1>=20 && e1<=49) exp2+=ceil(e1/9.0+21);
        if (e1>=50 && e1<=65) exp2+=ceil(e1/16.0+17);
        if (exp1<0) exp1=0;
        if (exp2<0) exp2=0;
        if (exp1>600) exp1=600;
        if (exp2>600) exp2=600;
        if (e1>=66 && e1<=79) {
            exp2+=ceil(e1/4.0+19);
            if (exp1<0) exp1=0;
            if (exp2<0) exp2=0;
            if (exp1>600) exp1=600;
            if (exp2>600) exp2=600;
            if (exp2>200) exp2+=ceil(e1/9.0+21);
        }
        if (e1>=80 && e1<=99) {
            exp2+=ceil(e1/4.0+19);
            exp2+=ceil(e1/9.0+21);
            if (exp1<0) exp1=0;
            if (exp2<0) exp2=0;
            if (exp1>600) exp1=600;
            if (exp2>600) exp2=600;
            if (exp2>400) {exp2+=ceil(e1/16.0+17);
                    exp2+=ceil(exp2*0.15+ 1.1920929e-07);}
        }
        exp1=exp1-e1;
    }
    if (exp1<0) exp1=0;
    if (exp2<0) exp2=0;
    if (exp1>600) exp1=600;
    if (exp2>600) exp2=600;
    return exp1 + exp2;}
    else return -99;}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2>=0) and (E2<=99)) {
    if (M1<0) M1=0; if (M1>3000) M1=3000;
    if (HP1<0) HP1=0; if (HP1>666) HP1=666;
    if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;
    int S1;
    S1=pow(round(sqrt(EXP1*1.0)),2);
    const double m11=M1/2.0;
    double P1;
    if (EXP1>=S1) P1=1.0;
    else P1=(EXP1*1.0/S1+80)/123.0;
    if (E2%2==0) {
        if (M1>0){if (HP1<200) {HP1+=ceil(HP1*0.3 - 1e-15);
                    M1-=150;}
        else {HP1+=ceil(HP1*0.1 - 1e-15);
            M1-=70;}
        if (M1<0) M1=0; if (M1>3000) M1=3000;
        if (HP1<0) HP1=0; if (HP1>666) HP1=666;
        if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
        if (M1>0) {
        if (EXP1<400) M1-=200;
        else M1-=120;
        EXP1+=ceil(EXP1*0.13 - 1e-15);
        if (M1<0) M1=0; if (M1>3000) M1=3000;
        if (HP1<0) HP1=0; if (HP1>666) HP1=666;
        if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
        if (M1>0) {
        if (EXP1<300) M1-=100; 
        else M1-=120; 
        EXP1=ceil(EXP1*0.9 + 1e-15);
        if (M1<0) M1=0; if (M1>3000) M1=3000;
        if (HP1<0) HP1=0; if (HP1>666) HP1=666;
        if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
        HP1=ceil(HP1*0.83 + 1e-15);
        EXP1+=ceil(EXP1*0.17 - 1e-15);
        if (M1<0) M1=0; if (M1>3000) M1=3000;
        if (HP1<0) HP1=0; if (HP1>666) HP1=666;
        if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
    if (E2%2==1)
    {
        while (M1>=m11)
        {
            if (M1>=m11) {if (HP1<200) {HP1+=ceil(HP1*0.3 - 1e-15);
                  M1-=150;}
            else {HP1+=ceil(HP1*0.1 - 1e-15);
                  M1-=70;}
            if (M1<0) M1=0; if (M1>3000) M1=3000;
            if (HP1<0) HP1=0; if (HP1>666) HP1=666;
            if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
            if (M1>=m11){
                if (EXP1<400) M1-=200;
                else M1-=120; 
                EXP1+=ceil(EXP1*0.13 - 1e-15);
            if (M1<0) M1=0; if (M1>3000) M1=3000;
            if (HP1<0) HP1=0; if (HP1>666) HP1=666;
            if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
            if (M1>=m11){
                if (EXP1<300) M1-=100; 
                else M1-=120; 
                EXP1=ceil(EXP1*0.9 + 1e-15);
            if (M1<0) M1=0; if (M1>3000) M1=3000;
            if (HP1<0) HP1=0; if (HP1>666) HP1=666;
            if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
        }
        HP1=ceil(HP1*0.83 + 1e-15);
        EXP1+=ceil(EXP1*0.17 - 1e-15);
        if (M1<0) M1=0; if (M1>3000) M1=3000;
        if (HP1<0) HP1=0; if (HP1>666) HP1=666;
        if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;
    }
    int S2=pow(round(sqrt(EXP1*1.0)),2);
    double P2,P3,Pall;
    if (EXP1>=S2) P2=1.0;
    else P2=(EXP1*1.0/S2+80)/123.0;
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    if ((E2>=0) && (E2<=9)) P3=P[E2]/100.0;
    if ((E2>=10) && (E2<=99)) {int i=(E2/10+E2%10)%10;
    P3=P[i]/100.0;}
    if ((P1==1) && (P2==1) && (P3==1)) {EXP1=ceil(EXP1*0.75 + 1e-15);
    if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
    else {Pall=(P1+P2+P3)/3.0;
    if (Pall<0.5) {HP1=ceil(HP1*0.85 + 1e-15); EXP1+=ceil(EXP1*0.15 - 1e-15);}
    else {HP1=ceil(HP1*0.9 + 1e-15); EXP1+=ceil(EXP1*0.2 - 1e-15);}
    if (M1<0) M1=0; if (M1>3000) M1=3000;
    if (HP1<0) HP1=0; if (HP1>666) HP1=666;
    if (EXP1<0) EXP1=0; if (EXP1>600) EXP1=600;}
    return HP1 + EXP1 + M1;
}
else return -99;}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3>=0) && (E3<=99)){
    if (EXP1 < 0) EXP1 = 0; if (EXP1 > 600) EXP1 = 600;
    if (HP1 < 0) HP1 = 0;   if (HP1 > 666) HP1 = 666;
    if (EXP2 < 0) EXP2 = 0;   if (EXP2 > 600) EXP2 = 600;
    if (HP2 < 0) HP2 = 0;    if (HP2 > 666) HP2 = 666;
    int map[10][10];
    int score,score_taxi;
    for (int i=0; i<10; i++) 
        for (int j=0; j<10; j++)
            map[i][j]=((E3*j)+(i*2))*(i-j);
    int counti=0,countj=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (map[i][j]>(E3*2)) counti++;
            if (map[i][j]<(-E3)) countj++;
        }
    }
    if (counti<=9) counti=counti;
    else if (counti<=99) counti=((counti/10+counti%10)/10)+((counti/10+counti%10)%10);
    if (countj<=9) countj=countj;
    else if (countj<=99) countj=((countj/10+countj%10)/10)+((countj/10+countj%10)%10);
    score_taxi=map[counti][countj];
    score=map[counti][countj];
    int i=counti, j=countj;
    while (i > 0 && j > 0)
        if (map[--i][--j] > score) score = map[i][j];
    i = counti; j = countj;
    while (i < 9 && j < 9)
        if (map[++i][++j] > score) score = map[i][j];
    i = counti; j = countj;
    while (i < 9 && j > 0)
        if (map[++i][--j] > score) score = map[i][j];
    i = counti; j = countj;
    while (i > 0 && j < 9)
        if (map[--i][++j] > score) score = map[i][j];
    if (abs(score_taxi) > abs(score)) {
        EXP1=ceil(EXP1*0.88 + 1e-15);
        EXP2=ceil(EXP2*0.88 + 1e-15);
        HP1=ceil(HP1*0.9 + 1e-15);
        HP2=ceil(HP2*0.9 + 1e-15);
        if (EXP1 < 0) EXP1 = 0; if (EXP1 > 600) EXP1 = 600;
        if (HP1 < 0) HP1 = 0;   if (HP1 > 666) HP1 = 666;
        if (EXP2 < 0) EXP2 = 0;   if (EXP2 > 600) EXP2 = 600;
        if (HP2 < 0) HP2 = 0;    if (HP2 > 666) HP2 = 666;
    } 
    else {
        EXP1+=ceil(EXP1*0.12- 1e-15);
        EXP2+=ceil(EXP2*0.12- 1e-15);
        HP1+=ceil(HP1*0.1- 1e-15);
        HP2+=ceil(HP2*0.1- 1e-15);
        if (EXP1 < 0) EXP1 = 0; if (EXP1 > 600) EXP1 = 600;
        if (HP1 < 0) HP1 = 0;   if (HP1 > 666) HP1 = 666;
        if (EXP2 < 0) EXP2 = 0;   if (EXP2 > 600) EXP2 = 600;
        if (HP2 < 0) HP2 = 0;    if (HP2 > 666) HP2 = 666;
    }
    if (abs(score_taxi)>abs(score)) return score_taxi;
    else return score;
}
else return -99;}
bool checkSpecial(string s) {
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '$' || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '!') 
        return true;
    }
    return false;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
     string se, e = email, str = s;
    if (str.size() < 8) return -1; 
    else if (str.size() > 20) return -2;
    else {
        int location = e.find("@");
        se = e.substr(0,location);
        int sei = str.find(se);
        if ((sei >= 0) && (sei < str.size())) return -(300 + sei);
        else {
            for (int i = 0; i < str.size() - 2; i++) {
                if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2])) {
                    return -(400 + i);  
                }
            }
            if (!checkSpecial(str)) return -5;
            else {bool flag = false;
            int i = 0;
            for (i=0; i < str.size(); i++) {
                if (!isdigit(str[i]) && !isalpha(str[i]) && (str[i] != '!') && (str[i] != '@') && (str[i] != '#') && (str[i] != '$') && (str[i] != '%')) 
                    {flag = true; 
                    return i;}
            }
            if (flag==false) return -10;  
        }
    }
}
return 0;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    /*int max=1, mostapp_in; 
    string mostapp;
    for (int i = 0; i < num_pwds; i++) { 
        int count = 1; 
        for (int j = i+1; j < num_pwds; j++) { 
            if (arr_pwds[i]==arr_pwds[j]) 
                count++; 
        } 
        if (count>max) 
        { 
            max=count; 
            mostapp_in=i; 
            mostapp=arr_pwds[i];
        } 
        else if (count==max) {
            string mostapp_2=arr_pwds[i];
            if (mostapp_2.size() > mostapp.size()) {
                mostapp=arr_pwds[i];
                mostapp_in=i;
        }
    }}
    return mostapp_in;}*/
    int count[num_pwds];
    int most_index=-1;
    string arr[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        arr[i]=arr_pwds[i];
    }
    for (int i = 0; i < num_pwds; i++) {  
        for (int j = i+1; j < num_pwds; j++) { 
            if (arr[i]==arr[j]) 
                count[i]++; 
        }
    }
    string mostapp;
    int max_app=0;
    int max_length=0;
    for (int i=0; i<num_pwds; i++) {
        count[i]++;
        if ((count[i]>max_app) || ((count[i]==max_app)&& (arr[i].size()>max_length)))
        {
            max_app=count[i];
            max_length=arr[i].size();
            mostapp=arr[i];
            most_index=i;
        }
    }
    for (int i=0; i<num_pwds; i++) {
        if (arr[i]==mostapp)
            {most_index=i;
             break;}
    }
    return most_index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
