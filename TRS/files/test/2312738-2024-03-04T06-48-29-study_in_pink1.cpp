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
double makeround(double &a){
    if((int)a==a) return a;
    else a=(int)a+1;
    return a;
}
double set600(double &a){
    if (a>600) a=600;
    else if(a<0) a=0;
    return a;
}
double set666(double &a){
    if (a>666) a=666;
    else if(a<0) a=0;
    return a;
}
double set3000(double &a){
    if (a>3000) a=3000;
    else if(a<0) a=0;
    return a;
}
double xacsuat(float a){
    int b=sqrt(a);
    double c=pow(b+1,2);
    double d=pow(b,2);
    if(a-d>c-a) return 100.0*(a/c+80.0)/123.0;
    else return 100.0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
        if(e1>=0&&e1<=99){
    double a=exp1;
    double b=exp2;
    set600(a);
    set600(b);
    if(e1>=0&&e1<=3){
    if(e1==0) {
        b=b+29.0;
        set600(b);
    }
    else if(e1==1) {
        b=b+45.0;
        set600(b);
    }
    else if(e1==2) {
        b=b+75.0;
        set600(b);
    }
    else {
        b=b+29.0+45.0+75.0;
        set600(b);
    }
    if((int(e1*3.0+a*7.0))%2==0){
        a=a+(e1*3.0+a*7.0)/200;
        makeround(a);
        set600(a);
    }
    else {
        a=a-(e1*3.0+a*7.0)/100;
        makeround(a);
        set600(a);
    }
    }
    else if(e1>=4&&e1<=99) {
    if(e1>=4&&e1<=19){
        b=b+(e1/4.0)+19.0;
        makeround(b);
        set600(b);
    }
    else if(e1>=20&&e1<=49){
        b=b+(e1/9.0)+21.0;
        makeround(b);
        set600(b);
    }
    else if(e1>=50&&e1<=65){
        b=b+(e1/16.0)+17.0;
        makeround(b);
        set600(b);
    }
    else if(e1>=66&&e1<=79){
        b=b+(e1/4.0)+19.0;
        makeround(b);
        set600(b);
    if(b>200){
        b=b+(e1/9.0)+21.0;
        makeround(b);
        set600(b);
    }
    }
    else if(e1>=80&&e1<=99){
        b=b+(e1/4.0)+19.0;
        makeround(b);
        set600(b);
        b=b+(e1/9.0)+21.0;
        makeround(b);
        set600(b);
    if(b>400){
        b=b+(e1/16.0)+17.0;
        makeround(b);
        set600(b);
        b=b*1.15;
        makeround(b);
        set600(b);
    }
    }
    a=a-e1;
    makeround(a);
    set600(a);
}
exp1=a;
exp2=b;
return exp1 + exp2;
}
    else return -99;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 > 99 || E2 < 0) return -99;
    else{
    double p,p1,p2,p3;
    double a=HP1;
    double b=EXP1;
    double c=M1;
    p1=xacsuat(b);
    if(E2%2==0){
        if (c==0) goto here;
        if(a<200){
            a=a*1.3;
            makeround(a);
            set666(a);
            c=c-150;
            set3000(c);
        }
        else{
            a=a*11.0/10;
            makeround(a);
            set666(a);
            c=c-70;
            set3000(c);
        }
        if (c==0) goto here;
        if(b<400){
            c=c-200;
            set3000(c);
            b=b*1.13;
            makeround(b);
            set600(b);
        }
        else{
            c=c-120;
            set3000(c);
            b=b*1.13;
            makeround(b);
            set600(b);
        }
        if (c==0) goto here;
        if(b<300){
            c=c-100;
            set3000(c);
            b=b*0.9;
            makeround(b);
            set600(b);
        }
        else{
            c=c-120;
            set3000(c);
            b=b*0.9;
            makeround(b);
            set600(b);
        }
    here: ;
    a=a*0.83;
    makeround(a);
    set666(a);
    b=b*1.17;
    makeround(b);
    set600(b);
}
    else{
        double e=c/2;
        while(c>e){
        if(a<200){
            a=a*1.3;
            makeround(a);
            set666(a);
            c=c-150;
            set3000(c);
        }
        else{
            a=a*11.0/10;
            makeround(a);
            set666(a);
            c=c-70;
            set3000(c);
        }
        if(c<e) break;
        if(b<400){
            c=c-200;
            set3000(c);
            b=b*1.13;
            makeround(b);
            set600(b);
        }
        else{
            c=c-120;
            set3000(c);
            b=b*1.13;
            makeround(b);
            set600(b);
        }
        if(c<e) break;
        if(b<300){
            c=c-100;
            set3000(c);
            b=b*0.9;
            makeround(b);
            set600(b);
        }
        else{
            c=c-120;
            set3000(c);
            b=b*0.9;
            makeround(b);
            set600(b);
        }
    }
    a=a*0.83;
    makeround(a);
    set666(a);
    b=b*1.17;
    makeround(b);
    set600(b);
}
p2=xacsuat(b);
int g[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
if(E2<10) p3=g[E2];
else {
    int f=(E2/10+E2%10)%10;
    p3=g[f];
}
if(p1==100.0&&p2==100.0&&p3==100.0){
    b=b*0.75;
    makeround(b);
    set600(b);
}
else{
p=(p1+p2+p3)/3.0;
if(p<50){
    a=a*0.85;
    makeround(a);
    set666(a);
    b=b*1.15;
    makeround(b);
    set600(b);
}
else{
    a=a*0.9;
    makeround(a);
    set666(a);
    b=b*1.2;
    makeround(b);
    set600(b);
}
}
HP1=a;
EXP1=b;
M1=c;
return HP1+EXP1+M1;
}
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
        if(E3>=0&&E3<=99){
    double a=HP1;
    double b=EXP1;
    double c=HP2;
    double d=EXP2;
        int z[10][10];
    int k1=0,k2=0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            z[i][j]=((E3*j)+(i*2))*(i-j);
            if(z[i][j]>(E3*2)) k1++;
            if(z[i][j]<(-E3)) k2++;
        }
    }
    while(((k1/10)>0)||((k2/10)>0)){
        k1=(k1/10)+(k1%10);
        k2=(k2/10)+(k2%10);
    }
    int taxi=z[k1][k2];
    int chase=taxi;
    int m1=k1+1,m2=k2+1;
    while(m1<=9&&m2<=9){
        if(z[m1][m2]>chase) chase=z[m1][m2];
        m1++;
        m2++;
    }
    m1=k1-1;
    m2=k2-1;
    while(m1>=0&&m2>=0){
        if(z[m1][m2]>chase) chase=z[m1][m2];
        m1--;
        m2--;
    }
    m1=k1+1;
    m2=k2-1;
    while(m1<=9&&m2>=0){
        if(z[m1][m2]>chase) chase=z[m1][m2];
        m1++;
        m2--;
    }
    m1=k1-1;
    m2=k2+1;
    while(m1>=0&&m2<=9){
        if(z[m1][m2]>chase) chase=z[m1][m2];
        m1--;
        m2++;
    }
    chase=abs(chase);
    int l;
    if(chase>=abs(taxi)){
        a=11.0*a/10;
        makeround(a);
        set666(a);
        c=11.0*c/10;
        makeround(c);
        set666(c);
        b=11.2*b/10;
        makeround(b);
        set600(b);
        d=11.2*d/10;
        makeround(d);
        set600(d);
        l=chase;
    }
    else{
        a=0.9*a;
        makeround(a);
        set666(a);
        c=0.9*c;
        makeround(c);
        set666(c);
        b=0.88*b;
        makeround(b);
        set600(b);
        d=0.88*d;
        makeround(d);
        set600(d);
        l=taxi;
    }
    HP1=a;
    EXP1=b;
    HP2=c;
    EXP2=d;
    return l;
    }
    else return -99;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    char se[200];
for (int i=0;i<200;i++){
    se[i]='\0';
}
    int a=0;
    while(email[a]!='@'){
        se[a]=email[a];
        a++;
    }
    int b=0;
    for(int i=0;s[i]!='\0';i++){
        b++;
    }
    int c=0;
    for (int i=0;se[i]!='\0';i++){
        c++;
    }
    char se1[c];
    for (int i=0;i<c;i++){
        se1[i]=se[i];
    }
    int l=-10;
    if(b<8) l=-1;
    else if (b>20) l=-2;
    else{
        for(int i=0;i<b;i++){
            int d=0;
            for(int j=0;j<c;j++){
                if (s[i+j]==se1[j]) d++;
            }
            if(d==c){
                l=-(300+i);
                break;
            }
        }
        if(l==-10){
            for(int i=0;i<b-2;i++){
                if(s[i]==s[i+1]&&s[i+1]==s[i+2]) {
                    l=-(400+i);
                    break;
                }
            }
        }
        int e=0;
        if(l==-10){
            for(int i=0;i<b;i++){
                if(s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%') e++;
            }
            if(e==0) l=-5;
        }
        if(l==-10){
            for(int i=0;i<b;i++){
                if(((s[i]<48)||(s[i]>57&&s[i]<64)||(s[i]>90&&s[i]<97)||(s[i]>122))&&(s[i]!='!')&&(s[i]!='#')&&(s[i]!='$')&&(s[i]!='%')){
                    l=i;
                    break;
                }
            }
        }
    }
    return l;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
        int l=0;
    int Freq[num_pwds];
    int Num[num_pwds];
    int a=0;
    for (int i=0;i<num_pwds;i++){
        Freq[i]=0;
        Num[i]=0;
    }
    for (int i=0;i<num_pwds;i++){
        for(int j=i;j<num_pwds;j++){
            if(strcmp(arr_pwds[j],arr_pwds[i])==0) Freq[i]++;
        }
    }
    int maxFreq=0;
    for (int i=0;i<num_pwds;i++){
        if(maxFreq<Freq[i]) maxFreq=Freq[i];
    }
    for (int i=0;i<num_pwds;i++){
        if(maxFreq==Freq[i]) a++;
    }
    int Freqmax[a];
    int b=0;
    for (int i=0;i<num_pwds;i++){
        if(maxFreq==Freq[i]) {Freqmax[b]=i;
        b++;}
    }
    for (int i=0;i<num_pwds;i++){
        for(int j=0;arr_pwds[i][j]!='\0';j++){
            Num[i]++;
        }
    }
    int maxNum=0;
    for (int i=0;i<a;i++){
        if(maxNum<Num[Freqmax[i]]){
            maxNum=Num[Freqmax[i]];
            l=Freqmax[i];
        }
    }
    return l;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////