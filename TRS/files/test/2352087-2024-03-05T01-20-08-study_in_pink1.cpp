#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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

void checkConEXP(int& exp1, int& exp2) {
    if (exp1 <0) exp1=0;
    if (exp2 <0) exp2=0;
    if (exp1 >600) exp1=600;
    if (exp2 >600) exp2=600;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1<0 || e1>99) return -99;
    checkConEXP(exp1, exp2);
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {exp2 += 29; checkConEXP(exp1, exp2);}
        if (e1 == 1) {exp2 += 45; checkConEXP(exp1, exp2);}
        if (e1 == 2) {exp2 += 75; checkConEXP(exp1, exp2);}
        if (e1 == 3) {exp2 += 149; checkConEXP(exp1, exp2);}
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {exp1 = ceil (double(exp1) + double(D / 200.0)); checkConEXP(exp1, exp2);}
        if (D % 2 != 0) {exp1 = ceil (double(exp1)- double(D / 100.0)); checkConEXP(exp1, exp2);}
    }
    if (e1 >= 4 && e1 <= 99) {
        exp1 -= e1; checkConEXP(exp1, exp2);
        if (e1 >= 4 && e1 <= 19) {exp2 = ceil(double(exp2) +double(e1 / 4.0 + 19.0));checkConEXP(exp1, exp2);}
        if (e1 >= 20 && e1 <= 49) {exp2= ceil(double(exp2) + double(e1 / 9.0 + 21.0));checkConEXP(exp1, exp2);}
        if (e1 >= 50 && e1 <= 65) {exp2= ceil(double(exp2) + double(e1 / 16.0 + 17.0));checkConEXP(exp1, exp2);}
        if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(double(exp2) +double(e1 / 4.0 + 19.0));
            checkConEXP(exp1, exp2);
            if (exp2 > 200) {exp2 = ceil(double(exp2) +double(e1 / 9.0 + 21.0)); checkConEXP(exp1, exp2);}
        }
        if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(double(exp2) +double(e1 / 4.0 + 19.0)); 
            checkConEXP(exp1, exp2);
            exp2 = ceil(double(exp2) + double(e1 / 9.0 + 21.0));
            checkConEXP(exp1, exp2);
            if (exp2 > 400) {
                exp2 = ceil(double(exp2) + double(e1 / 16.0 + 17.0));
                checkConEXP(exp1, exp2);
                exp2 = ceil(double(exp2) * 1.15);
                checkConEXP(exp1, exp2);
            }
        }
 }
    return exp1 + exp2;
}

// Task 2
void checkConHPtask2(int& hp1) {
    if (hp1 <0) hp1=0;
    if (hp1 >666) hp1=666;
}
void checkConEXPtask2(int& exp1) {
    if (exp1 <0) exp1=0;
    if (exp1 >600) exp1=600;
}
void checkContask2(int&hp1, int&m1, int&exp1){
    if (hp1 <0) hp1=0;
    if (hp1 >666) hp1=666;
    if (exp1 <0) exp1=0;
    if (exp1 >600) exp1=600;
    if (m1>3000) m1=3000;
    if (m1<0) m1=0;



}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0 ||E2>99) return -99;
    checkContask2(HP1,M1,EXP1);
    int a=round(sqrt(EXP1));
    int S=a*a;
    double P1;
    if (EXP1>=S) P1=1.0;
    else P1= double((EXP1/S +80.0)/123.0);
    //conduong2
    checkContask2(HP1,M1,EXP1);
    double stbd= M1*0.5; 
    checkContask2(HP1,M1,EXP1);
    if (M1==0) {
        HP1 = ceil(double(HP1*0.83));
        EXP1 = ceil (double(EXP1*1.17));
    }
    else if (E2 % 2 != 0) {
        int moneyUse=0;
        while (true){
            if (HP1<200) {
                HP1 = ceil(double(HP1)+ 0.3*double(HP1));
                M1 -= 150;
                moneyUse+=150;
                checkContask2(HP1,M1,EXP1);
                if (moneyUse>stbd) break;
        }
            else {
                HP1 = ceil(double(HP1)+ 0.1*double(HP1)); 
                M1 -= 70;
                moneyUse+=70;
                checkContask2(HP1,M1,EXP1);
                if (moneyUse>stbd) break;
        }
            if (EXP1<400)  {
                M1 -= 200;
                moneyUse+=200;
                EXP1 = ceil(double(EXP1*1.13));
                checkContask2(HP1,M1,EXP1);
                if (moneyUse>stbd) break;
            }
            else {
                M1-= 120;
                moneyUse+=120;
                EXP1 = ceil(double(EXP1*1.13));
                checkContask2(HP1,M1,EXP1);
                if (moneyUse>stbd) break;
            }
            
            if (EXP1<300) {
                M1 -= 100;
                moneyUse+=100;
                EXP1 = ceil(double(EXP1*0.9));
                checkContask2(HP1,M1,EXP1);
                if (moneyUse>stbd) break;
            }
            else {
                M1-= 120;
                moneyUse+=120;
                EXP1 = ceil(double(EXP1*0.9));
                checkContask2(HP1,M1,EXP1);
                if (moneyUse>stbd) break;
            }            
            }
        checkContask2(HP1,M1,EXP1);
        HP1 = ceil(double(HP1*0.83));
        EXP1 = ceil (double(EXP1*1.17));
        checkContask2(HP1,M1,EXP1);
    }    
    else if (E2 % 2 == 0) {  
        while(true){
        if (HP1<200) {
                HP1 = ceil(double(HP1)+ 0.3*double(HP1));
                M1 -= 150; 
        }
        else {
                HP1 = ceil(double(HP1)+ 0.1*double(HP1)); 
                M1 -= 70;  
        }
        checkContask2(HP1,M1,EXP1);
        if (M1==0) break;
        if (EXP1<400)  {
                M1 -= 200;
                EXP1 = ceil(double(EXP1*1.13));
            }
        else {
                M1-= 120;
                EXP1 = ceil(double(EXP1*1.13));
            }  
        checkContask2(HP1,M1,EXP1);
        if (M1==0) break;
        if (EXP1<300) {
                M1 -= 100;
                EXP1 = ceil(double(EXP1*0.9));
            }
        else {
                M1-= 120;
                EXP1 = ceil(double(EXP1*0.9));
            }   
        checkContask2(HP1,M1,EXP1);
        if (M1==0) break;
        break;
        }
    HP1 = ceil(double(HP1*0.83));
    EXP1 = ceil (double(EXP1*1.17));
    }
    //
    checkContask2(HP1,M1,EXP1);
    int b=round(sqrt(EXP1));
    int S2=b*b;
    double P2;
    if (EXP1>=S2) P2=1.0;
    else P2= double((EXP1/S2 +80.0)/123.0);
    //conduong3
    double i;
    double arrP[10]={0.32,0.47,0.28,0.79,1.0,0.5,0.22,0.83,0.64,0.11};
    if (E2>=0 && E2<10) i=arrP[E2];
    if (E2>=11 && E2<=99) {
        E2= (E2%10 + E2/10);
        E2= E2%10;
        i=arrP[E2];
    }
    if (P1==1.0 && P2==1.0 && i==1.0) {
        EXP1 = ceil (double (EXP1*0.75));
        checkContask2(HP1,M1,EXP1);
    }
    else {
        double ave=(P1+P2+i)/3;
        if (ave <0.5) {
            HP1=ceil(double(HP1*0.85));
            EXP1=ceil(double(EXP1*1.15));
            checkContask2(HP1,M1,EXP1);
        }
        else {
            HP1=ceil(double(HP1*0.9));
            EXP1=ceil(double(EXP1*1.2));
            checkContask2(HP1,M1,EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int checkValue(int &tValue, int &SW_Value){
    if (abs(tValue)>SW_Value) return tValue;
    else return SW_Value;
}
void checkContask3(int & HP1, int & EXP1, int & HP2, int & EXP2){
    if (HP1 <0) HP1=0;
    if (HP1 >666) HP1=666;
    if (EXP1 <0) EXP1=0;
    if (EXP1 >600) EXP1=600; 
    if (HP2 <0) HP2=0;
    if (HP2 >666) HP2=666;
    if (EXP2 <0) EXP2=0;
    if (EXP2 >600) EXP2=600; 
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if (E3<0 ||E3>99) return -99;
    checkContask3(HP1,EXP1,HP2,EXP2); //check Condition
    int SW[10][10];
    int T[10][10];
    int i, j;





    for (i = 0; i <= 9; i++){
        for (j = 0; j <= 9; j++){
            T[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }//matrix of taxi



    for (i = 0; i <= 9; i++){
        for (j = 0; j <= 9; j++){
            int maxValue = 0;

            for (int a = i, b = j; (a <=9) && (b <=9); a++, b++) {
                if (T[a][b]>=maxValue) maxValue=T[a][b];
            }
            for (int a = i, b = j; (a<=9) && (b >=0); a++, b-- ) {
                if (T[a][b]>=maxValue) maxValue=T[a][b];
            } 
            for (int a = i, b = j; (a >=0) && (b <=9); a--, b++) {
                if (T[a][b]>=maxValue) maxValue=T[a][b];
            }
            for (int a = i, b = j; (a >=0) && (b >=0); a--, b--) {
                if (T[a][b]>=maxValue) maxValue=T[a][b];
            }
            SW[i][j] = maxValue;
        }
    }
    int coMeet_i = 0;
    int coMeet_j = 0; //khaibaodiemgapnhau



    for (i = 0; i <= 9; i++){
        for (j = 0; j <= 9; j++){
            if (T[i][j] > (E3 * 2)){
                coMeet_i++;
            }
            if (T[i][j] < (-E3)){
                coMeet_j++;
            }
        }
    }
    while (coMeet_i >= 10){
        int x1 = coMeet_i % 10;
        int x2 = coMeet_i /10;
        coMeet_i = x1 + x2;
    }
    while (coMeet_j >= 10){
        int y1 = coMeet_j % 10;
        int y2 = coMeet_j /10;
        coMeet_j = y1 + y2;
    }



    
    int tValue = T[coMeet_i][coMeet_j];
    int SW_Value = SW[coMeet_i][coMeet_j];
    if ((abs(tValue) > SW_Value)){
        EXP1 = ceil(double(EXP1 - EXP1 * 0.12));
        checkContask3(HP1,EXP1,HP2,EXP2);
        EXP2 = ceil(double(EXP2 - EXP2 * 0.12));
        checkContask3(HP1,EXP1,HP2,EXP2);
        HP1 = ceil(double(HP1 - HP1 * 0.1));
        checkContask3(HP1,EXP1,HP2,EXP2);
        HP2 = ceil(double(HP2 - HP2 * 0.1));
        checkContask3(HP1,EXP1,HP2,EXP2);
    } else {
        EXP1 = ceil(double(EXP1 + EXP1 * 0.12));
        checkContask3(HP1,EXP1,HP2,EXP2);
        EXP2 = ceil(double(EXP2 + EXP2 * 0.12));
        checkContask3(HP1,EXP1,HP2,EXP2);
        HP1 = ceil(double(HP1 + HP1 * 0.1));
        checkContask3(HP1,EXP1,HP2,EXP2);
        HP2 = ceil(double(HP2 + HP2 * 0.1));
        checkContask3(HP1,EXP1,HP2,EXP2);
    }
    return checkValue(tValue,SW_Value);
    return -1;
}

// Task 4
int checkInd(const string &se, const string &s){
    int count =0;
    for (int i=0;i < s.length(); i++){
        if (s[i]==se[count]){
            if(count==se.length()-1) return i-se.length();
            else count ++;
        }
        else {
            count =0;
            if (s[i]==se[count]){
                count++;
            }
        }
    }
    return 0;
}
int checkInd1(const string &se, const string &s){
    int count =0;
    for (int i=0;i < s.length(); i++){
        if (s[i]==se[count]){
            if(count==se.length()-1) return i-se.length();
            else count ++;
        }
        else {
            count =0;
            if (s[i]==se[count]){
                count++;
            }
        }
    }
    return 0;
}
int checkPassword(const char * s, const char * email)
{
    char se[99]; //khai bao chuoi se
    int lenArre=strlen(email); //bien do dai cua email
    //do dai cua se
    for (int i=0;i<lenArre;i++){
        if (email[i]=='@'){
            strncpy(se,email,i);
            se[i]='\0';
            break;
        }

    } //ketthuc


    int lenArrs=strlen(s);
    if (strlen(s)>=8 && strlen(s)<=20){
        if (strstr(s,se) == NULL ){
            for (int i = 0; i < lenArrs; ++i){
                if (s[i]==s[i+1] && s[i+2]==s[i+1]) {
                    return -(400+i);
                    break;
                } 
            }
            for (int i=0; i<lenArrs;i++) {
                if (s[i] != '@' && s[i] != '$' && s[i] != '%' && s[i] != '!'&& s[i] != '#') continue;
                else {
                    for (int i=0; i<lenArrs;i++){
                        if (s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '('||s[i] == ')'||s[i]=='-'||s[i] == '_' 
                        || s[i] == '+' || s[i] == '=' || s[i] == '/'||s[i] == '{'||s[i]=='['||s[i] == '}' || s[i] == ']')   return i;
                        if (s[i] == '\\' || s[i] == '|' || s[i] == ':' || s[i] == ';'||s[i]=='"'||s[i] == ',' 
                        || s[i] == '.' || s[i] == '<' || s[i] == '>'||s[i] == '?'||s[i]=='`'||s[i] == '~'||s[i]=='\'')   return i;

                    }
                    return -10;
                }
            }
            return -5;  
            
        }
        else {
            int sei=checkInd1(se, s);
            sei+=1;
            return -(300+sei);
        }




        
    }
    else if (strlen(s)<8) return -1;
    else if (strlen(s)>20) return -2;



return 0;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxRepeat = 0;
    int Index;
    int maxSize = 0;
    for (int i = 0; i < num_pwds; i++) {
        int count = 1;
        for (int j = i+1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > maxRepeat||(count == maxRepeat && strlen(arr_pwds[i]) > maxSize)) {
            maxRepeat = count;
            maxSize = strlen(arr_pwds[i]);
            Index = i;
        }
    }
    return Index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////