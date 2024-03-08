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
    if (exp1>600) exp1=600;
    else if (exp1<0) exp1=0;

    if (exp2>600) exp2=600;
    else if (exp2<0) exp2=0;

    if (e1<0||e1>99) return -99;
    else if (e1>=0&&e1<=3){
        if (e1==0) exp2+=29;
        else if (e1==1) exp2+=45;
        else if (e1==2) exp2+=75;
        else exp2+=(29+45+75);

        int D=e1*3+exp1*7;
        if (D%2==0) exp1=ceil(exp1+(double)D/200);
        else exp1=ceil(exp1-(double)D/100);

        if (exp1>600) exp1=600;
        else if (exp1<0) exp1=0;

        if (exp2>600) exp2=600;
    }
    else{
        if (e1>=4&&e1<=19) exp2+=ceil(19+(double)e1/4);
        else if (e1>=20&&e1<=49) exp2+=ceil(21+(double)e1/9);
        else if (e1>=50&&e1<=65) exp2+=ceil(17+(double)e1/16);
        else if (e1>=66&&e1<=79){
            exp2+=ceil(19+(double)e1/4);
            if (exp2>600) exp2=600;

            if (exp2>200) exp2+=ceil(21+(double)e1/9);
        }
        else{
            exp2+=ceil(19+(double)e1/4);
            if (exp2>600) exp2=600;
            exp2+=ceil(21+(double)e1/9);
            if (exp2>600) exp2=600;

            if (exp2>400){
                exp2+=ceil(17+(double)e1/16);
                if (exp2>600) exp2=600;
                exp2=ceil((double)exp2+(double)exp2*15/100);
            }
        }
        exp1-=e1;
        if (exp1<0) exp1=0;

        if (exp2>600) exp2=600;
    }
    return exp1 + exp2;
}

// Task 2
void road02(int & HP1, int & EXP1, int & M1){
    if (M1!=0){
        double temp=M1/2;
        while (M1>=temp){
            if (HP1<200){
                HP1=ceil((double)HP1+(double)HP1*3/10);
                M1-=150;
            }
            else{
                HP1=ceil((double)HP1+(double)HP1/10);
                M1-=70; 
            }

            if (HP1>666) HP1=666;

            if (M1<0) M1=0;
            if (M1<temp) break;

            if (EXP1<400) M1-=200;
            else M1-=120;
            EXP1=ceil((double)EXP1+(double)EXP1*13/100);

            if (EXP1>600) EXP1=600;

            if (M1<0) M1=0;
            if (M1<temp) break;

            if (EXP1<300) M1-=100;
            else M1-=120;
            EXP1=ceil((double)EXP1-(double)EXP1/10);

            if (M1<0) M1=0;
        }
    }        
}
void road02special(int & HP1, int & EXP1, int & M1){
    while (M1>0){
        if (HP1<200){
            HP1=ceil((double)HP1+(double)HP1*3/10);
            M1-=150;
        }
        else{
            HP1=ceil((double)HP1+(double)HP1/10);
            M1-=70; 
        }

        if (HP1>666) HP1=666;

        if (M1<=0){
            M1=0;
            break;
        }

        if (EXP1<400) M1-=200;
        else M1-=120;
        EXP1=ceil((double)EXP1+(double)EXP1*13/100);

        if (EXP1>600) EXP1=600;

        if (M1<=0){
            M1=0;
            break;
        }

        if (EXP1<300) M1-=100;
        else M1-=120;
        EXP1=ceil((double)EXP1-(double)EXP1/10);

        if (M1<=0) M1=0;
        break;
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (HP1>666) HP1=666;
    else if (HP1<0) HP1=0;

    if (EXP1>600) EXP1=600;
    else if (EXP1<0) EXP1=0;

    if (M1>3000) M1=3000;
    else if (M1<0) M1=0;

    if (E2<0||E2>99) return -99;
    else{
        int temp1=sqrt(EXP1), S;
        double P1, P2, P3;
        if (EXP1==temp1*temp1) S=EXP1;
        else{
            int res1=temp1*temp1, res2=(temp1+1)*(temp1+1);
            if (EXP1-res1<res2-EXP1) S=res1;
            else S=res2;
        }

        if (EXP1>=S) P1=100;
        else P1=(double)100*((double)EXP1/S+80)/123;

        if (E2%2==1){
            road02(HP1,EXP1,M1);
            HP1=ceil((double)HP1-(double)HP1*17/100);
            EXP1=ceil((double)EXP1+(double)EXP1*17/100);
            if (EXP1>600) EXP1=600;
        }
        else{
            road02special(HP1,EXP1,M1);
            HP1=ceil((double)HP1-(double)HP1*17/100);
            EXP1=ceil((double)EXP1+(double)EXP1*17/100);
            if (EXP1>600) EXP1=600;
        }

        int temp2=sqrt(EXP1);
        if (EXP1==temp2*temp2) S=EXP1;
        else{
            int res1=temp2*temp2, res2=(temp2+1)*(temp2+1);
            if (EXP1-res1<res2-EXP1) S=res1;
            else S=res2;
        }

        if (EXP1>=S) P2=100;
        else P2=(double)100*((double)EXP1/S+80)/123;

        int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        if (E2<10) P3=P[E2];
        else{
            int temp=E2/10+E2%10;
            temp%=10;
            P3=(double)P[temp];
        }

        double ave=(double)(P1+P2+P3)/3;
        if (P1==100&&P2==100&&P3==100) EXP1=ceil((double)EXP1-(double)EXP1/4);
        else if (ave<50){
            HP1=ceil((double)HP1-(double)HP1*3/20);
            EXP1=ceil((double)EXP1+(double)EXP1*3/20);
        }
        else{
            HP1=ceil((double)HP1-(double)HP1/10);
            EXP1=ceil((double)EXP1+(double)EXP1/5); 
        }

        if (EXP1>600) EXP1=600;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int gg;
    if (HP1>666) HP1=666;
    else if (HP1<0) HP1=0;

    if (HP2>666) HP2=666;
    else if (HP2<0) HP2=0;

    if (EXP1>600) EXP1=600;
    else if (EXP1<0) EXP1=0;

    if (EXP2>600) EXP2=600;
    else if (EXP2<0) EXP2=0;

    if (E3<0||E3>99) return -99;
    else{
        int a[10][10], cnti=0, cntj=0;
        for (int i=0 ; i<10 ; i++){
            for (int j=0 ; j<10 ; j++) a[i][j]=(E3*j+i*2)*(i-j);
        }
        for (int i=0 ; i<10 ; i++){
            for (int j=0 ; j<10 ; j++){
                if (a[i][j]>E3*2) cnti++;
                if (a[i][j]<-E3) cntj++;
            }
        }
        while (cnti>=10) cnti=cnti/10+cnti%10;
        while (cntj>=10) cntj=cntj/10+cntj%10;
        int sw=a[cnti][cntj], taxi=a[cnti][cntj];
        if (cnti==cntj){
            while (cnti<10&&cntj>=0){
                if (sw<a[cnti][cntj]) sw=a[cnti][cntj];
                cnti++, cntj--;
            }
        }
        else if (cnti>cntj){
            sw=a[9][9+cntj-cnti];
            while (cnti<10&&cntj>=0){
                if (sw<a[cnti][cntj]) sw=a[cnti][cntj];
                cnti++, cntj--;
            }
        }
        else{
            int temp=(cntj-cnti)/2+1;
            cnti+=temp, cntj-=temp;
            while (cnti<10&&cntj>=0){
                if (sw<a[cnti][cntj]) sw=a[cnti][cntj];
                cnti++, cntj--;
            }
        }
        if (abs(taxi)>abs(sw)){
            EXP1=ceil((double)EXP1-(double)EXP1*12/100);
            EXP2=ceil((double)EXP2-(double)EXP2*12/100);
            HP1=ceil((double)HP1-(double)HP1/10);
            HP2=ceil((double)HP2-(double)HP2/10);
            gg=taxi;
        }
        else{
            EXP1=ceil((double)EXP1+(double)EXP1*12/100);
            EXP2=ceil((double)EXP2+(double)EXP2*12/100);
            HP1=ceil((double)HP1+(double)HP1/10);
            HP2=ceil((double)HP2+(double)HP2/10);
            gg=sw; 
        }
        if (HP1>666) HP1=666;

        if (HP2>666) HP2=666;

        if (EXP1>600) EXP1=600;

        if (EXP2>600) EXP2=600;
    }
    return gg;
}

// Task 4
bool checkchar(string s){
    for (int i=0 ; i<s.length()-2 ; i++){
        if (s[i]==s[i+1]&&s[i+1]==s[i+2]) return true;
    }
    return false;
}
int charpos(string s){
    for (int i=0 ; i<s.length()-1 ; i++){
        if (s[i]==s[i+1]&&s[i+1]==s[i+2]) return i;
    }
    return -1;
}
bool checkspecialchar(string s){
    if (s.find('@')>s.length()&&s.find('#')>s.length()&&s.find('%')>s.length()&&s.find('$')>s.length()&&s.find('!')>s.length())
        return true;
    return false;
}
int totalcharpos(string s){
    for (int i=0 ; i<s.length() ; i++){
        if (!(s[i]>='0'&&s[i]<='9')&&!(s[i]>='a'&&s[i]<='z')&&!(s[i]>='A'&&s[i]<='Z')&&s[i]!='@'&&s[i]!='#'&&s[i]!='%'&&s[i]!='$'&&s[i]!='!')
            return i;
    }
    return -1;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se, email1=email, s1=s;
    int x=email1.find('@');
    se=email1.substr(0,x);
    if (s1.length()<8) return -1;
    else if (s1.length()>20) return -2;
    else if (s1.find(se)!=string::npos) return -(300+s1.find(se));
    else if (checkchar(s1)) return -(400+charpos(s1));
    else if (checkspecialchar(s1)) return -5;
    else if (totalcharpos(s1)!=-1) return totalcharpos(s1);
    else return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_val=0, pos=-1, max_len=0;
    for (int i=0 ; i<num_pwds ; i++){
        int dem=0, len=strlen(arr_pwds[i]);
        for (int j=i ; j<num_pwds ; j++){
            if (strcmp(arr_pwds[j],arr_pwds[i])==0) dem++;
        }
        if (dem>max_val){
            max_val=dem;
            max_len=strlen(arr_pwds[i]);
            pos=i;
        }
        else if (dem==max_val&&len>max_len){
            max_len=strlen(arr_pwds[i]);
            pos=i;
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////