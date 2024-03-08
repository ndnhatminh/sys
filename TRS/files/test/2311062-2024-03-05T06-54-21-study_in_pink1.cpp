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
        int &E3
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
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
void chp1(int & HP1){
    if(HP1<0) HP1=0;
    else if(HP1>666) HP1=666;
}

void chp2(int & HP2){
    if(HP2<0) HP2=0;
    else if(HP2>666) HP2=666;
}

void cexp1(int & EXP1){
    if(EXP1<0) EXP1=0;
    else if(EXP1>600) EXP1=600;
}

void cexp2(int & EXP2){
    if(EXP2<0) EXP2=0;
    else if(EXP2>600) EXP2=600;
}

void cm1(int & M1){
    if(M1<0) M1=0;
    else if(M1>3000) M1=3000;
}

void cm2(int & M2){
    if(M2<0) M2=0;
    else if(M2>3000) M2=3000;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1<0||E1>99) return -99;
    else{
        int d;
        cexp1(EXP1);
        cexp2(EXP2);
        if(E1<=3){
            if(E1==0){
                EXP2+=29;
                cexp2(EXP2);
            }
            else if(E1==1){
                EXP2+=45;
                cexp2(EXP2);
            }
            else if(E1==2){
                EXP2+=75;
                cexp2(EXP2);
            }
            else if(E1==3){
                EXP2+=149;
                cexp2(EXP2);
            }
            d=E1*3+EXP1*7;
            if(d%2==0){
                EXP1=ceil((float)EXP1+(float)d/200);
                cexp1(EXP1);
            }
            else{
                EXP1=ceil((float)EXP1-(float)d/100);
                cexp1(EXP1);
            }
        }
        else{
            if(E1>=4&&E1<=19){
                EXP2=ceil((float)EXP2+(float)E1/4+19);
                cexp2(EXP2);
            }
            else if(E1>=20&&E1<=49){
                EXP2=ceil((float)EXP2+(float)E1/9+21);
                cexp2(EXP2);
            }
            else if(E1>=50&&E1<=65){
                EXP2=ceil((float)EXP2+(float)E1/16+17);
                cexp2(EXP2);
            }
            else if(E1>=66&&E1<=79){
                EXP2=ceil((float)EXP2+(float)E1/4+19);
                cexp2(EXP2);
                if(EXP2>200){
                    EXP2=ceil((float)EXP2+(float)E1/9+21);
                    cexp2(EXP2);
                }
            }
            else if(E1>=80&&E1<=99){
                EXP2=ceil((float)EXP2+(float)E1/4+19);
                cexp2(EXP2);
                EXP2=ceil((float)EXP2+(float)E1/9+21);
                cexp2(EXP2);
                if(EXP2>400){
                EXP2 = ceil((double)EXP2 + ((double)E1/16 + 17));
                cexp2(EXP2);
                EXP2 = ceil((double)EXP2*1.15);
                cexp2(EXP2);
                }
            }
            EXP1=EXP1-E1;
            cexp1(EXP1);
    }
    return EXP1 + EXP2;
}
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0||E2>99) return -99;
    else{
    float p1,p2,p3;
    chp1(HP1);
    cexp1(EXP1);
    cm1(M1);
    int s=sqrt(EXP1);
    if(abs(EXP1-s*s)>abs(EXP1-(s+1)*(s+1))) s++;
    if(s*s<=EXP1) p1=1;
    else p1=(float)((EXP1/(s*s))+80)/123+0.01;
    //cout<<s*s<<endl<<"P1: "<<setprecision(3)<<fixed<<p1<<endl;
    //WAY2
    if(E2%2==1){
        int ct=0,bd=M1;
        while(M1>0){
            if(HP1<200){
                ct+=150;
                M1=M1-150;
                cm1(M1);
                //cout<<"CT: "<<ct<<endl;
                HP1=ceil((float)HP1*130/100);
                chp1(HP1);
                //cout<<"HP1: "<<HP1<<endl;
            }
            else{
                ct+=70;
                M1=M1-70;
                cm1(M1);
                //cout<<"CT: "<<ct<<endl;
                HP1=ceil((float)HP1*110/100);
                chp1(HP1);
                //cout<<"HP1: "<<HP1<<endl;
            }
            if (ct>bd/2) break;
            if(EXP1<400){
                ct+=200;
                M1=M1-200;
                cm1(M1);
                //cout<<"CT: "<<ct<<endl;
                EXP1=ceil((float)EXP1*113/100);
                cexp1(EXP1);
                //cout<<"EXP1: "<<EXP1<<endl;
            }
            else{
                ct+=120;
                M1=M1-120;
                cm1(M1);
                //cout<<"CT: "<<ct<<endl;
                EXP1=ceil((float)EXP1*113/100);
                cexp1(EXP1);
                //cout<<"EXP1: "<<EXP1<<endl;
            }
            if (ct>bd/2) break;
            if(EXP1<300){
                ct+=100;
                M1=M1-100;
                cm1(M1);
                //cout<<"CT: "<<ct<<endl;
                EXP1=ceil((float)EXP1*90/100);
                cexp1(EXP1);
                //cout<<"EXP1: "<<EXP1<<endl;
            }
            else{
                ct+=120;
                M1=M1-120;
                cm1(M1);
                //cout<<"CT: "<<ct<<endl;
                EXP1=ceil((float)EXP1*90/100);
                cexp1(EXP1);
                //cout<<"EXP1: "<<EXP1<<endl;
            }
            if (ct>bd/2) break;
        }
        HP1=ceil((float)HP1*83/100);
        EXP1=ceil((float)EXP1*117/100);
        chp1(HP1);
        cexp1(EXP1);
    }
    else{
        if(M1>0){
            if(HP1<200){
                M1=M1-150;
                cm1(M1);
                HP1=ceil((float)HP1*130/100);
                chp1(HP1);
                //cout<<"HP1: "<<HP1<<endl;
            }
            else{
                M1=M1-70;
                cm1(M1);
                HP1=ceil((float)HP1*110/100);
                chp1(HP1);
                //cout<<"HP1: "<<HP1<<endl;
            }
        }
        if(M1>0){
            if(EXP1<400){
                M1=M1-200;
                cm1(M1);
                EXP1=ceil((float)EXP1*113/100);
                cexp1(EXP1);
                //cout<<"EXP1: "<<EXP1<<endl;
            }
            else{
                M1=M1-120;
                cm1(M1);
                EXP1=ceil((float)EXP1*113/100);
                cexp1(EXP1);
                //cout<<"EXP1: "<<EXP1<<endl;
            }
        }
        if(M1>0){
            if(EXP1<300){
                M1=M1-100;
                cm1(M1);
                EXP1=ceil((float)EXP1*90/100);
                cexp1(EXP1);
                //cout<<"EXP1: "<<EXP1<<endl;
            }
            else{
                M1=M1-120;
                cm1(M1);
                EXP1=ceil((float)EXP1*90/100);
                cexp1(EXP1);
                //cout<<"EXP1: "<<EXP1<<endl;
            }
        }
        HP1=ceil((float)HP1*83/100);
        EXP1=ceil((float)EXP1*117/100);
        chp1(HP1);
        cexp1(EXP1);
    }
    s=sqrt(EXP1);
    if(abs(EXP1-s*s)>abs(EXP1-(s+1)*(s+1))) s++;
    if(s*s<=EXP1) p2=1;
    else p2=(float)((EXP1/(s*s))+80)/123+0.01;
    //cout<<endl<<"HP1: "<<HP1<<endl;
    //cout<<"EXP1: "<<EXP1<<endl;
    //cout<<"P2: "<<setprecision(2)<<fixed<<p2<<endl;
    //WAY3
    int i, P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2/10==0) i=E2;
    else{
            int baydihoipen=(int)(E2/10)+(int)(E2%10);
            i=(int)(baydihoipen%10);
    }
    p3=(float)P[i]/100;
    //cout<<"i: "<<i<<endl;
    //cout<<"P3: "<<setprecision(2)<<fixed<<p3<<endl;
    cexp1(EXP1);
    //cout<<"EXP1: "<<EXP1<<endl;
    if(p1==1&&p2==1&&p3==1){
        EXP1=ceil((float)EXP1*75/100);
        //cout<<"EXP1: "<<EXP1<<endl;
    }
    else{
        float pfinal=(p1+p2+p3)/3;
        //cout<<"Pfinal: "<<setprecision(2)<<fixed<<pfinal<<endl;
        if(pfinal<0.5){
            HP1=ceil((float)HP1*85/100);
            EXP1=ceil((float)EXP1*115/100);
            chp1(HP1);
            cexp1(EXP1);
        }
        else{
            HP1=ceil((float)HP1*90/100);
            EXP1=ceil((float)EXP1*120/100);
            chp1(HP1);
            cexp1(EXP1);
        }
    }
    chp1(HP1);
    cexp1(EXP1);
    return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int reS=0;
    if(E3<0||E3>99) reS=-99;
    else{
        int Ta[20][20], maxC[20], maxR[20], L[20][20], R[20][20], SnW[20][20], Po=0, Ne=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            Ta[i][j]=((E3*j)+(i*2))*(i-j);
            if(Ta[i][j]>(E3*2)) Po++;
            else if(Ta[i][j]<(-E3)) Ne++;
            //cout<<Ta[i][j]<<" ";
        }
        //cout<<endl;
    }
    //Max trong duong cheo trai
    //Duoi duong cheo chinh
    for(int a=0;a<10;a++){
        //cout<<endl;
        maxC[a]=-1000000;
        int i=a, j=0;
        while(i<10){
            maxC[a]=max(maxC[a],Ta[i][j]);
            i++;
            j++;
            //cout<<maxC[a]<<" ";
        }
    }
    for(int a=0;a<10;a++){
        int i=a, j=0;
        while(i<10){
            L[i][j]=maxC[a];
            i++;
            j++;
        }
    }
    //Tren duong cheo chinh
    for(int a=0;a<10;a++){
        //cout<<endl;
        maxR[a]=-1000000;
        int i=a, j=0;
        while(i<10){
            maxR[a]=max(maxR[a],Ta[j][i]);
            i++;
            j++;
            //cout<<maxR[a]<<" ";
        }
    }
    for(int a=0;a<10;a++){
        int i=a, j=0;
        while(i<10){
            L[j][i]=maxR[a];
            i++;
            j++;
        }
    }
    //Max trong duong cheo phai
    //Duoi duong cheo chinh
    for(int a=0;a<10;a++){
        //cout<<endl;
        maxC[a]=-1000000;
        int i=a, j=9;
        while(i<10){
            maxC[a]=max(maxC[a],Ta[i][j]);
            i++;
            j--;
            //cout<<maxC[a]<<" ";
        }
    }
    for(int a=0;a<10;a++){
        int i=a, j=9;
        while(i<10){
            R[i][j]=maxC[a];
            i++;
            j--;
        }
    }
    //Tren duong cheo chinh
    for(int a=0;a<10;a++){
        //cout<<endl;
        maxR[a]=-1000000;
        int i=0, j=a;
        while(j>=0){
            maxR[a]=max(maxR[a],Ta[i][j]);
            i++;
            j--;
            //cout<<maxR[a]<<" ";
        }
    }
    for(int a=0;a<10;a++){
        int i=0, j=a;
        while(j>=0){
            R[i][j]=maxR[a];
            i++;
            j--;
        }
    }
    //Diem cua Sherlock va Watson
    for(int i=0;i<10;i++){
        //cout<<endl;
        for(int j=0;j<10;j++){
            SnW[i][j]=max(L[i][j], R[i][j]);
            //cout<<SnW[i][j]<<" ";
        }
    }
    //Diem gap nhau
    int PoT=0, NeT=0;
    if(Po/10==0) PoT=Po;
    else{
        int PoTT=(Po%10)+((int)Po/10);
        if(PoTT/10==0) PoT=PoTT;
        else PoT=(PoTT%10)+((int)PoTT/10);
    }
    if(Ne/10==0) NeT=Ne;
    else{
        int NeTT=(Ne%10)+((int)Ne/10);
        if(NeTT/10==0) NeT=NeTT;
        else NeT=(NeTT%10)+((int)NeTT/10);
    }
    //cout<<PoT<<" "<<NeT;
    //So sanh
    cexp1(EXP1);
    cexp2(EXP2);
    chp1(HP1);
    chp2(HP2);
    if(abs(Ta[PoT][NeT])<=abs(SnW[PoT][NeT])){
        EXP1=ceil((float)EXP1*112/100);
        EXP2=ceil((float)EXP2*112/100);
        HP1=ceil((float)HP1*110/100);
        HP2=ceil((float)HP2*110/100);
        reS=SnW[PoT][NeT];
    }
    else{
        EXP1=ceil((float)EXP1*88/100);
        EXP2=ceil((float)EXP2*88/100);
        HP1=ceil((float)HP1*90/100);
        HP2=ceil((float)HP2*90/100);
        reS=Ta[PoT][NeT];
    }
    cexp1(EXP1);
    cexp2(EXP2);
    chp1(HP1);
    chp2(HP2);
    //cout<<"EXP1: "<<EXP1<<endl;
    //cout<<"HP1: "<<HP1<<endl;
    //cout<<"EXP2: "<<EXP2<<endl;
    //cout<<"HP2: "<<HP2<<endl;
    //cout<<reS;
    }
    return reS;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pass(s);
    string emaill(email);
    int ap=emaill.find('@');
    //cout<<"Vi tri @: "<<ap<<endl;
    string se=emaill.substr(0, ap);
    //cout<<"se: "<<se<<endl;
    //Check lap lai
    bool rcheck=0;
    int rpois;
    for(int i=0;i<(int)pass.size()-2;i++){
        if(pass[i]==pass[i+1]&&pass[i]==pass[i+2]&&pass[i+1]==pass[i+2]){
            rcheck=1;
            rpois=i;
            break;
        }
    }
    //Check ky tu dac biet
    bool specialcheck=0;
    for(int i=0;i<(int)pass.size();i++){
        if(pass[i]=='@'||pass[i]=='#'||pass[i]=='%'||pass[i]=='$'||pass[i]=='!'){
            specialcheck=1;
            break;
        }
    }
    //Check dap so
    int ans=-10;
    if((int)pass.size()<8) ans=-1;
    else if((int)pass.size()>20) ans=-2;
    else if(pass.find(se)!=string::npos) ans=-(300+(int)pass.find(se));
    else if(rcheck==1) ans=-(400+rpois);
    else if(specialcheck==0) ans=-5;
    else{
        for(int i=0;i<(int)pass.size();i++){
            if(int(pass[i])<33||int(pass[i])==34||(int(pass[i])>37&&int(pass[i])<48)||(int(pass[i])>57&&int(pass[i])<64)||(int(pass[i])>90&&int(pass[i])<97)||int(pass[i])>122){
                ans=i;
                break;
            }
        }
    }
    return ans;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
    int mfs=0, ans=0;
    const char* maxp="";
    for(int i=0;i<num_pwds;i++){
        if(arr_pwds[i]!=nullptr&&strcmp(arr_pwds[i],"")!=0){
            int satihoicup=1;
            for(int j=0;j<num_pwds;j++){
                if(j!=i&&strcmp(arr_pwds[i],arr_pwds[j])==0) satihoicup++;
            }
            if(satihoicup>mfs){
                mfs=satihoicup;
                maxp=arr_pwds[i];
                ans=i;
            }
            else if(satihoicup==mfs){
                if (strlen(arr_pwds[i])>strlen(maxp)){
                    maxp=arr_pwds[i];
                    mfs=satihoicup;
                    ans=i;
                }
            }
            satihoicup=1;
        }
    }
    return ans;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////