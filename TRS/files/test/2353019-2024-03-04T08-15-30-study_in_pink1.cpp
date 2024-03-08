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

//Utility

bool Odd_or_Even(int & D){
    if (D%2==0){
        return 1;
    }
    else {return 0;}
}

int Absolute_val(int & x, int & y){
    int hieu=x-y;
    if (hieu<0){
        hieu=0-hieu;
    }
    return hieu;
}

bool Check_int(float & X){
    if (X-int(X)!=0){
        return 1;
    }
    else {return 0;}
}

int Check_hp(int & Hp){
    if (Hp<0){
        Hp=0;
    }
    else if (Hp>666){
        Hp=666;
    }
    return Hp;
}

int Check_exp(int & Exp){
    if (Exp<0){
        Exp=0;
    }
    else if (Exp>600){
        Exp=600;
    }
    return Exp;
}

int Check_money(int & Money){
    if (Money<0){
        Money=0;
    }
    else if (Money>3000){
        Money=3000;
    }
    return Money;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

// Task 1

int Task1_1(int & A, int & B){
    int D;
    float C;
    D=B*3+A*7;
    if (Odd_or_Even(D)==1){
        C=float(D)/200;
        if (Check_int(C)==1){
            A=A+C+1;
        }
        else {A=A+C;}
    }
    else {
        C=D/100;
        if (Check_int(C)==1){
            A=A-C+1;
        }
        else {A=A-C;}
    }
    return A;
}

int Task1_2(int & E, int & F){
    float temp;
    if (F>=4 && F<=19){
        temp=float(F)/4+19;
        if (Check_int(temp)==1){
            E=E+temp+1;
        }
        else {E=E+temp;}
    }
    else if (F>=20 && F<=49){
        temp=float(F)/9+21;
        if (Check_int(temp)==1){
            E=E+temp+1;
        }
        else {E=E+temp;}
    }
    else if (F>=50 && F<=65){
        temp=float(F)/16+17;
        if (Check_int(temp)==1){
            E=E+temp+1;
        }
        else {E=E+temp;}
    }
    else if (F>=66 && F<=79){
        temp=float(F)/4+19;
        if (Check_int(temp)==1){
            E=E+temp+1;
        }
        else {E=E+temp;}
        if (E>200){
            temp=float(F)/9+21;
            if (Check_int(temp)==1){
                E=E+temp+1;
            }
            else {E=E+temp;}
        }
    }
    else if (F>=80 && F<=99){
        temp=float(F)/4+19;
        if (Check_int(temp)==1){
            E=E+temp+1;
        }
        else {E=E+temp;}
        temp=float(F)/9+21;
        if (Check_int(temp)==1){
            E=E+temp+1;
        }
        else {E=E+temp;}
        if (E>400){
            temp=float(F)/16+17;
            if (Check_int(temp)==1){
                E=E+temp+1;
            }
            else {E=E+temp;}
            E=E*1.15;
            E=int(E)+1;
        }
    }
    return E;
}

int firstMeet(int & exp1, int & exp2, int e1) {
        switch (e1){
        case 0: exp2+=29;Task1_1(exp1,e1);break;
        case 1: exp2+=45;Task1_1(exp1,e1);break;
        case 2: exp2+=75;Task1_1(exp1,e1);break;
        case 3: exp2=exp2+29+45+75;Task1_1(exp1,e1);break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
        case 98:
        case 99:Task1_2(exp2,e1);exp1-=e1;break;
        default:cout<<"Invalid";break;
    }
    Check_exp(exp1);
    Check_exp(exp2);
    
    return exp1 + exp2;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

// Task 2

float street_1(int & eXp){
    int S,s,i=1;
    S=i*i;
    s=(i-1)*(i-1);
    while (Absolute_val(eXp,S)<=Absolute_val(eXp,s))
    {i++;
        S=i*i;
    s=(i-1)*(i-1);
    }
    float P1;
    if (eXp<=s){
        P1=(eXp/float(s)+80)/123;
    }
    else {P1=1;}
    return P1;
}

float street_2(int & M, int & exP, int & e2, int &hp){
    if (Odd_or_Even(e2)==0){
        float halve;
        halve=M*0.5;
        float temp;
        while(M>halve){
            if (hp<200){
                M-=150;
                temp=float(hp)*1.3;
                if (Check_int(temp)==1){hp=temp+1;}
                else {hp=temp;}
                Check_hp(hp);
            }
            else {
                M-=70;
                temp=float(hp)*1.1;
                if (Check_int(temp)==1){hp=temp+1;}
                else {hp=temp;}
                Check_hp(hp);
            }
            if (M<halve){break;}
            if (exP<400){M-=200;
            temp=float(exP)*1.13;
                if (Check_int(temp)==1){exP=temp+1;}
                else {exP=temp;}
                Check_exp(exP);
            }
            else {M-=120;
                temp=float(exP)*1.13;
                if (Check_int(temp)==1){exP=temp+1;}
                else {exP=temp;}
                Check_exp(exP);
            }
            if (M<halve){break;}
            if (exP<300){M-=100;
            temp=float(exP)*0.9;
                if (Check_int(temp)==1){exP=temp+1;}
                else {exP=temp;}
                Check_exp(exP);
            }
            else {M-=120;
                temp=float(exP)*0.9;
                if (Check_int(temp)==1){exP=temp+1;}
                else {exP=temp;}
                Check_exp(exP);
            }
        }
        float phu1,phu2;
        phu1=float(exP)*1.17;
        phu2=float(hp)*0.83;
        if (Check_int(phu1)==1){exP=phu1+1;}
        else {exP=phu1;}
        Check_exp(exP);
        if (Check_int(phu2)==1){hp=phu2+1;}
        else {hp=phu2;}
        Check_hp(hp);
    }
    else {
        float temp;
        if (M>0){
            if (hp<200){
                M-=150;
                temp=float(hp)*1.3;
                if (Check_int(temp)==1){hp=temp+1;}
                else {hp=temp;}
                Check_hp(hp);
            }
            else {
                M-=70;
                temp=float(hp)*1.1;
                if (Check_int(temp)==1){hp=temp+1;}
                else {hp=temp;}
                Check_hp(hp);
            }
        }
        if (M>0){
            if (exP<400){M-=200;
            temp=float(exP)*1.13;
                if (Check_int(temp)==1){exP=temp+1;}
                else {exP=temp;}
                Check_exp(exP);
            }
            else {M-=120;
                temp=float(exP)*1.13;
                if (Check_int(temp)==1){exP=temp+1;}
                else {exP=temp;}
                Check_exp(exP);
            }
        }
        if (M>0){
            if (exP<300){M-=100;
            temp=float(exP)*0.9;
                if (Check_int(temp)==1){exP=temp+1;}
                else {exP=temp;}
                Check_exp(exP);
            }
            else {M-=120;
                temp=float(exP)*0.9;
                if (Check_int(temp)==1){exP=temp+1;}
                else {exP=temp;}
                Check_exp(exP);
            }
        }
        float phu1,phu2;
        phu1=float(exP)*1.17;
        phu2=float(hp)*0.83;
        if (Check_int(phu1)==1){exP=phu1+1;}
        else {exP=phu1;}
        Check_exp(exP);
        if (Check_int(phu2)==1){hp=phu2+1;}
        else {hp=phu2;}
        Check_hp(hp);
    }
    float P2;
    P2=street_1(exP);
    return P2;
}

float street_3 (int & e_2){
    int a[10]={32,47,28,79,100,50,22,83,64,11};
    int i;
    if (e_2<10){i=e_2;}
    else {
        int donvi;
        int chuc;
        donvi=e_2%10;
        chuc=e_2/10;
        i=(donvi+chuc)%10;
    }
    float P3;
    P3=float(a[i])/100;
    return P3;
}
    
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    float P,p1,p2,p3;
    float a,b;
    p1=street_1(EXP1);
    p2=street_2(M1,EXP1,E2,HP1);
    p3=street_3(E2);
    if (p1==1 && p2==1 && p3==1){
        a=float(EXP1)*0.75;
        if (Check_int(a)==1){ EXP1=a+1;}
        else {EXP1=a;}
       }
    else {
        P=(p1+p2+p3)/3;
        if (P<0.5){
            a=float(HP1)*0.85;
            b=float(EXP1)*1.15;
            if (Check_int(a)==1){HP1=a+1;}
            else {HP1=a;}
            if (Check_int(b)==1){EXP1=b+1;}
            else {EXP1=b;}
        }
        else {
            a=float(HP1)*0.9;
            b=float(EXP1)*1.2;
            if (Check_int(a)==1){HP1=a+1;}
            else {HP1=a;}
            if (Check_int(b)==1){EXP1=b+1;}
            else {EXP1=b;}
        }
    }
    Check_exp(EXP1);
    Check_hp(HP1);
    Check_money(M1);
    
    return HP1 + EXP1 + M1;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

// Task 3

int meet(int a[10][10],int e3,int & Hang,int & Cot){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            a[i][j]=(e3*j+i*2)*(i-j);
            if (a[i][j]>e3*2){Hang++;}
            if (a[i][j]<-e3){Cot++;}
        }
    }
    while (Hang>9){
        Hang=Hang/10+Hang%10;
    }
    while (Cot>9){
        Cot=Cot/10+Cot%10;
    }
    return a[Hang][Cot];
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int hang=0,cot=0;
    int a[10][10];
    int max;
    max=meet(a,E3,hang,cot);
    for (int i=0;hang-i>=0;i++){
        if (cot-i<0){break;}
        if (a[hang-i][cot-i]>max){max=a[hang-i][cot-i];}
    }
    for (int i=0;cot+i<10;i++){
        if (hang+i>9){break;}
        if (a[hang+i][cot+i]>max){max=a[hang+i][cot+i];}
    }
    for (int i=0;hang+i<10;i++){
        if (cot-i<0){break;}
        if (a[hang+i][cot-i]>max){max=a[hang+i][cot-i];}
    }
    for (int i=0;cot+i<10;i++){
        if (hang-i<0){break;}
        if (a[hang-i][cot+1]>max){max=a[hang-i][cot+i];}
    }
    int j=0;
    if (Absolute_val(a[hang][cot],j)>Absolute_val(max,j)){
        float A,b,c,d;
        A=EXP1*0.88;
        b=HP1*0.9;
        c=EXP2*0.88;
        d=HP2*0.9;
        if(Check_int(A)==1){EXP1=A+1;}
        else {EXP1=A;}
        if(Check_int(b)==1){HP1=b+1;}
        else {HP1=b;}
        if(Check_int(c)==1){EXP2=c+1;}
        else {EXP2=c;}
        if(Check_int(d)==1){HP2=d+1;}
        else {HP2=d;}
        max=a[hang][cot];
    }
    else {
        float a,b,c,d;
        a=EXP1*1.12;
        b=HP1*1.1;
        c=EXP2*1.12;
        d=HP2*1.1;
        if(Check_int(a)==1){EXP1=a+1;}
        else {EXP1=a;}
        if(Check_int(b)==1){HP1=b+1;}
        else {HP1=b;}
        if(Check_int(c)==1){EXP2=c+1;}
        else {EXP2=c;}
        if(Check_int(d)==1){HP2=d+1;}
        else {HP2=d;}
    }
    Check_exp(EXP1);
    Check_exp(EXP2);
    Check_hp(HP1);
    Check_hp(HP2);
    
    return max;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

// Task 4
int se_length(const string & mail){
    int pos;
    pos=mail.find("@")-1;
    return pos;
}

int Check_se(const string & a,const string & b){
    int i;
    i=a.find(b);
    return i;
}

int Continue(const string & S){
    for (int i=0; i<S.length(); i++){
        if (S[i]==S[i+1]&&S[i+1]==S[i+2]){return i;}
    }
    return 0;
}

int Char(const string & s){
    int spec=0,inval=0;
    for (int i=0; i<s.length();i++){
        if (!(s[i]>='a'&&s[i<='z'])&&!(s[i]>='A'&&s[i]<='Z')&&!(s[i]>='0'&&s[i]<='9')){
            if (s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
                spec=1;
            }
            else {inval=1;}
        }
    }
    if (spec==0){return -5;}
    else {
        if (inval==1){
            for (int i=0; i<s.length();i++){
            if (!(s[i]>='a'&&s[i<='z'])&&!(s[i]>='A'&&s[i]<='Z')&&!(s[i]>='0'&&s[i]<='9')){
            if (s[i]!='@'||s[i]!='#'||s[i]!='%'||s[i]!='$'||s[i]!='!'){
                return i;
            }
            }
        }
    }
}
return 100;
}

    int checkPassword(const char * s, const char * email) {
    string S = s;
    string Email = email;
    int i = se_length(email);
    if (i==0){i=1;}
    string se = Email.substr(0, i);

    if (8 > S.length()){return -1;}                               
    else if (S.length() > 20){return -2;}                         
    else if(Check_se(S, se) != -1){return -(300 + Check_se(S, se));}                                                                           
    else if (Continue(S) != 0){return -(400 + Continue(S));} 
    else if (Char(S) == -5){return Char(S);}                
    else if (Char(S) != 100){return Char(S);}               
    else{return -10;}
    }

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max=0;
    int a[num_pwds];
    int d=0;
    for (int i=0; i<num_pwds; i++){
        int count =1;
        for (int j=i+1; j<num_pwds; j++){
            if (arr_pwds[i]==arr_pwds[j])
            count++;
        }
        a[i]=count;
    }
    for (int i=0;i<num_pwds;i++){
        if (a[i]>max){max=a[i];}
    }

    for (int i=0;i<num_pwds;i++){
        if (a[i]==max){
            d++;
        }
    }
    int c[d];
    for (int i=0;i<d;i++){
        for (int j=0;j<num_pwds;j++){
            if (a[j]==max){
                c[i]=j;
                a[j]=0;
                break;
            }
        }
    }
    if(d==1){return c[0];}
    else {for (int i=0;i<d;i++){
        for (int j=i+1;j<d;j++){
            if (strlen(arr_pwds[c[j]])>strlen(arr_pwds[c[i]])){
                int temp;
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
        }
    }
}
return c[0];
    }
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////