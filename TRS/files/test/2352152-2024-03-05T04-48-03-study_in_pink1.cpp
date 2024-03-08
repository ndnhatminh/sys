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
void hp(int &hp){
    if(hp<0){
       hp=0; 
    }
    if(hp>666){
        hp=666;
    }
}
void money(int &money){
    if(money<0){
        money=0; 
    }
    if(money>3000){
        money=3000;
    }
}
void exp(int &exp){
    if(exp<0){
       exp=0; 
    }
    if(exp>600){
        exp=600;
    }
}
int lam_tron(float chi_so){
    int a=chi_so+0.9999;
    return a;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    exp(exp1);
    exp(exp2);
    if(e1<=3&&e1>=0){
        if(e1==0){
            exp2+=29;
            exp(exp2);
        } else if(e1==1){
            exp2+=45;
            exp(exp2);
        } else if(e1==2){
            exp2+=75;
            exp(exp2);
        } else{
            exp2+=(29+45+75);
            exp(exp2);
        }
        int D=e1*3+exp1*7;
        if(D%2==0){
            exp1=ceil(exp1+D*1.0/200);
            exp(exp1);
        } else{
            exp1=ceil(exp1-D*1.0/100);
        }
    } else if(e1>=4&&e1<=99){
        if(e1<=19){
            exp2=ceil(exp2+e1*1.0/4+19);
            exp(exp2);
        } else if(e1<=49){
            exp2=ceil(exp2+e1*1.0/9+21);
            exp(exp2);
        } else if(e1<=65){
            exp2=ceil(exp2+e1*1.0/16+17);
            exp(exp2);
        } else if(e1<=79){
            exp2=ceil(exp2+e1*1.0/4+19);
            if(exp2>200){
                exp2=ceil(exp2+e1*1.0/9+21);
                exp(exp2);
            }
        } else{
            exp2=ceil(exp2+e1*1.0/4+19);
            exp2=ceil(exp2+e1*1.0/9+21);
            if(exp2>400){
                exp2=ceil(exp2+e1*1.0/16+17);
                exp2=ceil(exp2*1.15);
                exp(exp2);
            }
        }
        exp1-=e1;
    } else{
        return -99;
    }
    exp(exp1);
    exp(exp2);
    return exp1 + exp2;
}

// Task 2:
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //Dieu kien
    if(E2<0||E2>99){
        return -99;
    }
    hp(HP1);
    exp(EXP1);
    money(M1);
    //Xac suat
    float P1, P2, P3, Pt;
    //Tinh xac suat P1
    int S;
    int b=round(sqrt(EXP1));
    int c=sqrt(EXP1)+1;
    if((EXP1-b*b)<(c*c-EXP1)){
        S=b*b;
    } else{
        S=c*c;
    }
    if(EXP1>=S){
        P1=100;
    } else{
        P1=(EXP1*1.0/(S)+80)/1.23;
    }
    //Tinh xac suat P2
    float Nua=(M1*0.5);
    int Tieu=0;
    if(M1==0){
        /*HP1=lam_tron(HP1*0.83);
        EXP1=lam_tron(EXP1*1.17);
        exp(EXP1);*/
    } else if(E2%2!=0){//E le
        while(1){
            if(HP1<200){
                //Su kien 1:
                HP1=lam_tron(HP1*1.3);
                hp(HP1);
                M1-=150;
                money(M1);
                Tieu+=150;
            } else{
                HP1=lam_tron(HP1*1.1);
                hp(HP1);
                M1-=70;
                money(M1);
                Tieu+=70;
            }
            if(Tieu>Nua){
                /*HP1=lam_tron(HP1*0.83);
                EXP1=lam_tron(EXP1*1.17);
                exp(EXP1);*/
                break;
            }
                //Su kien 2:
            if(EXP1<400){
                EXP1=lam_tron(EXP1*1.13);
                exp(EXP1);
                M1-=200;
                money(M1);
                Tieu+=200;
            } else{
                EXP1=lam_tron(EXP1*1.13);
                exp(EXP1);
                M1-=120;
                money(M1);
                Tieu+=120;
            }
            if(Tieu>Nua){
                /*HP1=lam_tron(HP1*0.83);
                EXP1=lam_tron(EXP1*1.17);
                exp(EXP1);*/
                break;
            }
            //Su kien 3:
            if(EXP1<300){
                EXP1=lam_tron(EXP1*0.9);
                M1-=100;
                money(M1);
                Tieu+=100;
            } else{
                EXP1=lam_tron(EXP1*0.9);
                M1-=120;
                money(M1);
                Tieu+=120;
            }
            if(Tieu>Nua){
                /*HP1=lam_tron(HP1*0.83);
                EXP1=lam_tron(EXP1*1.17);
                exp(EXP1);*/
                break;
            }
        }
    } else{//E chan
        //Su kien 1:
        if(HP1<200){
                HP1=lam_tron(HP1*1.3);
                hp(HP1);
                M1-=150;
                money(M1);
            } else{
                HP1=lam_tron(HP1*1.1);
                hp(HP1);
                M1-=70;
                money(M1);
            }
            if(M1==0){
                M1=0;
            } else if(EXP1<400){//Su kien 2:
                EXP1=lam_tron(EXP1*1.13);
                exp(EXP1);
                M1-=200;
                money(M1);
            } else{
                EXP1=lam_tron(EXP1*1.13);
                exp(EXP1);
                M1-=120;
                money(M1);
            } 
            if(M1==0){
                M1=0;
            } else if(EXP1<300){//Su kien 3:
                EXP1=lam_tron(EXP1*0.9);
                M1-=100;
                money(M1);
            } else{
                EXP1=lam_tron(EXP1*0.9);
                M1-=120;
                money(M1);
            }
            /*HP1=lam_tron(HP1*0.83);
            EXP1=lam_tron(EXP1*1.17);
            exp(EXP1);*/
    }
    HP1=lam_tron(HP1*0.83);
    EXP1=lam_tron(EXP1*1.17);
    exp(EXP1);
    int R;
    int d=round(sqrt(EXP1));
    int e=sqrt(EXP1)+1;
    if((EXP1-d*d)<(e*e-EXP1)){
        R=d*d;
    } else{
        R=e*e;
    }
    if(EXP1>=R){
        P2=100;
    } else{
        P2=(EXP1*1.0/(R)+80)/1.23;
    }
    //Tinh xac suat P3
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2<10){
        P3=P[E2];
    } else{
        int a=0;
        while(E2!=0){
            a+=E2%10;
            E2=E2/10;
        }
        P3=P[a%10];
    }
    //Trung binh cong cac xac suat
    Pt=(P1+P2+P3)/3.0;
    if(Pt==100){
        EXP1=lam_tron(EXP1*0.75);
    } else if(Pt<50){
        HP1=lam_tron(HP1*0.85);
        EXP1=lam_tron(EXP1*1.15);
        exp(EXP1);
    } else{
        HP1=lam_tron(HP1*0.9);
        EXP1=lam_tron(EXP1*1.2);
        exp(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3:
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99){
        return -99;
    }
    hp(HP1);
    hp(HP2);
    exp(EXP1);
    exp(EXP2);
    int mang[10][10];
    int count1=0;
    int count2=0;
    int diem_taxi=0;
    int diem_sherlock=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            mang[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(mang[i][j]>(E3*2)){
                ++count1;
            }
        }
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(mang[i][j]<(-E3)){
                ++count2;
            }
        }
    }
    while(count1>=10){
        int tong=0;
        while(count1!=0){
            tong+=count1%10;
            count1=count1/10;
        }
        count1=tong;
    }
    while(count2>=10){
        int tong=0;
        while(count2!=0){
            tong+=count2%10;
            count2=count2/10;
        }
        count2=tong;
    }
    diem_taxi=mang[count1][count2];
    diem_sherlock=mang[count1][count2];
    int a=count2;
    for(int i=count1; i<10; i++){
            if(mang[i][a]>diem_sherlock){
                diem_sherlock=mang[i][a];
            }
            if(a==9){
                break;
                }
            ++a;
        }
        int b=count2;
    for(int i=count1; i>=0; i--){
            if(mang[i][b]>diem_sherlock){
                diem_sherlock=mang[i][b];
            }
            if(b==0){
                    break;
                }
                --b;
        }
        int c=count2;
    for(int i=count1; i<10; i++){
            if(mang[i][c]>diem_sherlock){
                diem_sherlock=mang[i][c];
            }
            if(c==0){
                    break;
                }
                --c;
        }
        int d=count2;
    for(int i=count1; i>=0; i--){
            if(mang[i][d]>diem_sherlock){
                diem_sherlock=mang[i][d];
            }
            if(d==9){
                    break;
                }
                ++d;
        }
    if(abs(diem_taxi)<=diem_sherlock){
        EXP1=lam_tron(EXP1*1.12);
        HP1=lam_tron(HP1*1.1);
        EXP2=lam_tron(EXP2*1.12);
        HP2=lam_tron(HP2*1.1);
        hp(HP1);
        hp(HP2);
        exp(EXP1);
        exp(EXP2);
        return diem_sherlock;
    } else{
        EXP1=lam_tron(EXP1*0.88);
        HP1=lam_tron(HP1*0.9);
        EXP2=lam_tron(EXP2*0.88);
        HP2=lam_tron(HP2*0.9);
        return diem_taxi;
    }
}

// Task 4
int f;
int func(string s){
    for(int i=0; i<s.size()-2;i++){
        if(s[i]==s[i+1]&&s[i+1]==s[i+2]){
            f=i;
            return 1;
        }
    }
    return 0;
}
int g;
int func1(string s){
    for(int i=0; i<s.size();i++){
        if(!((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')||(s[i]=='@')||(s[i]=='#')||(s[i]=='%')||(s[i]=='$')||(s[i]=='!'))){
            g=i;
            return 1;
        }
    }
    return 0;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S=s;
    string EMAIL=email;
    string se=EMAIL.erase(EMAIL.find("@"));
    if(S.size()<8){
        return -1;
    } else if(S.size()>20){
        return -2;
    } else if(S.find(se)!=string::npos){
        return-(300+S.find(se));
    }else if(func(S)){
        return -(400+f);
    }else if((S.find("@")==string::npos)&&(S.find("#")==string::npos)&&(S.find("%")==string::npos)&&(S.find("$")==string::npos)&&(S.find("!")==string::npos)){
        return -5;
    }else if(func1(S)){
        return g;
    }else{
        return -10;
    }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int first_index=0;
    int max_length=0;
    int max_count=0;
    int count=0;
    //max_length=arr_pwds[0].size();
    /*int ARR_PWDS[num_pwds];
    for(int i=0; i<num_pwds; i++){
        ARR_PWDS[i]=arr_pwds[i];
    }*/
    for(int i=0; i<num_pwds; i++){
        count=1;
        if(arr_pwds[i]!=""){
            for(int j=i+1; j<num_pwds; j++){
                if(strcmp(arr_pwds[i],arr_pwds[j])==0){
                    arr_pwds[j]="";
                    count+=1;
                }
            }
            if(count>max_count||((count==max_count)&&(max_length<strlen(arr_pwds[i])))){
                max_length=strlen(arr_pwds[i]);
                max_count=count;
                first_index=i;
            }
        }
    }

    return first_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////