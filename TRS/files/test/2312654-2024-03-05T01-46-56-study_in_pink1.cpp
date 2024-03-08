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

int HPc(int HP){
    if (HP>666) return 666;
    else if (HP<0) return 0;
    else return HP;
}
int EXPc(int EXP){
    if (EXP>600) return 600;
    else if (EXP<0) return 0;
    else return EXP;
}
int Mc(int M){
    if (M>3000) return 3000;
    else if (M<0) return 0;
    else return M;
}
int Ec(int E){
    if (E>99) return 0;
    else if (E<0) return 0;
    else return 1;}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(Ec(e1)==0) return -99;
    else
    {exp2 = EXPc(exp2);
    if (e1>=0&&e1<=3)
      {switch (e1)
    {
       case 0:
        {exp2+=29;
        exp2 = EXPc(exp2);
        break;}
       case 1:
        {exp2+=45;
        exp2 = EXPc(exp2);
        break;}
       case 2:
        {exp2+=75;
        exp2 = EXPc(exp2);
        break;}    
       default:
        {exp2 = exp2 + 29 + 45 + 75;
        exp2 = EXPc(exp2);
        }
    }
      int D = e1*3 + exp1*7;
      if(D%2==0)
      {exp1 += ceilf((double)D/200);
      exp1 = EXPc(exp1);}
      else 
      {exp1 = ceilf(exp1 - (double)D/100);
      exp1 = EXPc(exp1);}}
    else if (e1<=99)
    {
        if(e1<=19)
       {exp2 = exp2 + ceilf((double)e1/4)  +19;
       exp2 = EXPc(exp2);}
        else if(e1<=49)
       {exp2 = exp2 + ceilf((double)e1/9)  +21;
       exp2 = EXPc(exp2);}
        else if(e1<=65)
       {exp2 = exp2 + ceilf((double)e1/16) +17;
       exp2 = EXPc(exp2);}
        else if(e1<=79) 
      {exp2 = exp2 + ceilf((double)e1/4)  +19;
      exp2 = EXPc(exp2);
       if(exp2>200) {exp2 = exp2 + ceilf((double)e1/9)  +21;
       exp2 = EXPc(exp2);}}
        else if(e1<=99) 
       {exp2 = exp2 + ceilf((double)e1/4)  +19;
       exp2 = exp2 + ceilf((double)e1/9)  +21;
       exp2 = EXPc(exp2);
       if(exp2>400) 
        {exp2 = exp2 + ceilf((double)e1/16) +17;
         exp2 = ceilf((double)exp2*1.15);
         exp2 = EXPc(exp2);
         }
       } 
    exp1 -= e1; 
    exp1 = EXPc(exp1);   
    }
    return exp1 + exp2;
}}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(Ec(E2)==0) return -99;
    else{
    HP1=HPc(HP1);EXP1=EXPc(EXP1);M1=Mc(M1);    
    double P1=0;
    int S1=0;
    for (int i=1;i<sqrt(EXP1);i++){
        if((i+1)>sqrt(EXP1)){
         if((EXP1-i*i)>((i+1)*(i+1)-EXP1)) S1=(i+1)*(i+1);
         else S1=i*i;
        }
    }
    if (EXP1>=S1) P1=1;
    else P1= ((((double)EXP1/S1)+80)/123);
    if(E2%2!=0){
    int pM = 0;
    double hM=M1/2;   
    while(((double)pM<=hM)&&(M1!=0))
    {
    if((double)pM<=hM)
    if(M1!=0){
    if(HP1<200) {
        HP1=ceilf((double)HP1*1.3);HP1=HPc(HP1);
        M1-=150;M1=Mc(M1);
        pM+=150;}
    else {
        HP1=ceilf((double)HP1*1.1);HP1=HPc(HP1);
        M1-=70;M1=Mc(M1);
        pM+=70;}}
    if((double)pM<=hM)
    if(M1!=0){    
    if(EXP1<400) {M1-=200;M1=Mc(M1);pM+=200;}
    else {M1-=120;M1=Mc(M1);pM+=120;}
    EXP1=ceilf((double)EXP1*1.13);EXP1=EXPc(EXP1);}
    if((double)pM<=hM)
    if(M1!=0){
    if(EXP1<300) {M1-=100;M1=Mc(M1);pM+=100;}
    else {M1-=120;M1=Mc(M1);pM+=120;}
    EXP1=ceilf((double)EXP1*0.9);EXP1=EXPc(EXP1);}
    }
    
    }
    else{
    if(M1!=0){   
    if(HP1<200) {
        HP1=ceilf((double)HP1*1.3);HP1=HPc(HP1);
        M1-=150;M1=Mc(M1);
        }
    else {
        HP1=ceilf((double)HP1*1.1);HP1=HPc(HP1);
        M1-=70;M1=Mc(M1);
        }}
    if(M1!=0) {   
      if(EXP1<400) {M1-=200;M1=Mc(M1);}
      else {M1-=120;M1=Mc(M1);}
    EXP1=ceilf((double)EXP1*1.13);EXP1=EXPc(EXP1);}
    if(M1!=0){
      if(EXP1<300) {M1-=100;M1=Mc(M1);}
      else {M1-=120;M1=Mc(M1);}
    EXP1=ceilf((double)EXP1*0.9);EXP1=EXPc(EXP1);}}
    HP1=ceilf((double)HP1*0.83);
    EXP1=ceilf((double)EXP1*1.17);EXP1=EXPc(EXP1);
    double P2=0;
    int S2=0;
    for (int i=1;i<sqrt(EXP1);i++){
        if((i+1)>sqrt(EXP1)){
         if((EXP1-i*i)>((i+1)*(i+1)-EXP1)) S2=(i+1)*(i+1);
         else S2=i*i;
        }
    }
    
    if (EXP1>=S2) P2=1;
    else P2= ((((double)EXP1/S2)+80)/123);



    int i=0;
    double P3=0;
    int Pas[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if((E2-10)<0) P3=(double)Pas[E2]/100;
    else {
        int fd=E2/10;
        int iP=E2-fd*10+fd;
        int iPs=iP-(iP/10)*10;
        P3 = (double)Pas[iPs]/100;
        
    }

    double Pt=0;
    Pt=(P1+P2+P3)/3;
    if (Pt==1) EXP1=ceilf((double)EXP1*0.75);
    else if (Pt<0.5){
        HP1=ceilf((double)HP1*0.85);
        EXP1=ceilf((double)EXP1*1.15);}
    else{
        HP1=ceilf((double)HP1*0.90);
        EXP1=ceilf((double)EXP1*1.20);}
    HP1=HPc(HP1);EXP1=EXPc(EXP1);  M1=Mc(M1);  
    return HP1 + EXP1 + M1;
}}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(Ec(E3)==0) return -99;
    else{
        HP1=HPc(HP1);EXP1=EXPc(EXP1);HP2=HPc(HP2);EXP2=EXPc(EXP2);
   int mat[10][10] = {};
   int x=0,y=0,bgg=0,smm=0;
   
   for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j){
            mat[i][j]=(((E3 * j) + (i * 2)) * (i - j));
            if (mat[i][j]>(E3*2)) bgg+=1;
            if (mat[i][j]<-E3) smm+=1;
        }  
    }
    
    if(bgg/10==0) x=bgg;
    else {x=(bgg/10)+(bgg-(bgg/10)*10);
    if(x/10!=0) x=(x/10)+(x-(x/10)*10);}
    if(smm/10==0) y=smm;
    else{ y=(smm/10)+(smm-(smm/10)*10);
    if(y/10!=0) y=(y/10)+(y-(y/10)*10);}
    int taxi = mat[x][y];
    int SW = mat[x][y], chua=0;
    for (int i=0;(x+i<10)&&(y+i<10);i++){
       chua=mat[x+i][i+y];
       if(chua>SW) SW=chua;
    } 
    for (int i=0;(x-i>0)&&(y+i<10);i++){
       chua=mat[x-i][i+y];
       if(chua>SW) SW=chua;
    }
    for (int i=0;(x-i>0)&&(y-i>0);i++){
       chua=mat[x-i][y-i];
       if(chua>SW) SW=chua;
    }
    for (int i=0;(x+i<10)&&(y-i>0);i++){
       chua=mat[x+i][y-i];
       if(chua>SW) SW=chua;
    }
    if(abs(taxi)>SW){
        EXP1=ceilf((double)EXP1*0.88);EXP1=EXPc(EXP1);
        EXP2=ceilf((double)EXP2*0.88);EXP2=EXPc(EXP2);
        HP1=ceilf((double)HP1*0.9);HP1=HPc(HP1);
        HP2=ceilf((double)HP2*0.9);HP2=HPc(HP2);
        return taxi;
    }
    else{
        EXP1=ceilf((double)EXP1*1.12);EXP1=EXPc(EXP1);
        EXP2=ceilf((double)EXP2*1.12);EXP2=EXPc(EXP2);
        HP1=ceilf((double)HP1*1.1);HP1=HPc(HP1);
        HP2=ceilf((double)HP2*1.1);HP2=HPc(HP2);
        return SW;
    }
    }
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string sa=s;
    string emails=email;
    int eL = sa.length();
    int Ba  = emails.find('@');
    string se = emails.substr(0,Ba);
    int sci=-5;
    for (int i=0;i<(eL-1);i++)
     if(sa[i]==sa[i+1])
      if(sa[i+2]==sa[i+1]){
        sci=i;
        break;
     } 
    int sc;
    for (int i=0;i<eL;i++){
        switch(sa[i]){
            case '@':
            case '#':
            case '%':
            case '$':
            case '!':{
                sc=1;
                i=eL;
                break;
            }
            default: sc = 0;
        }
    }int nc;
    int con=0;
    for (int i=0;i<eL;i++){
        switch(sa[i]){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'q':
            case 'Q':
            case 'w':
            case 'W':
            case 'e':
            case 'E':
            case 'r':
            case 'R':
            case 't':
            case 'T':
            case 'Y':
            case 'y':
            case 'u':
            case 'U':
            case 'I':
            case 'i':
            case 'o':
            case 'O':
            case 'p':
            case 'P':
            case 'a':
            case 'A':
            case 's':
            case 'S':
            case 'd':
            case 'D':
            case 'f':
            case 'F':
            case 'g':
            case 'G':
            case 'h':
            case 'H':
            case 'j':
            case 'J':
            case 'k':
            case 'K':
            case 'l':
            case 'L':
            case 'z':
            case 'Z':
            case 'x':
            case 'X':
            case 'C':
            case 'c':
            case 'v':
            case 'V':
            case 'b':
            case 'B':
            case 'n':
            case 'N':
            case 'M':
            case 'm':
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':{
                nc=1;
                break;
            }
            default:{ nc = 0;
            con=i;
            i=eL; 
            break;}
        }
    }
    if(eL<8) return -1;
    else if (eL>20) return -2;
    else if ( sa.find(se) != string::npos){
        int sei  = sa.find(se);
        return -(300 + sei);
    }
    else if (sci!=-5) return -(400 + sci);
    else if (sc==0) return -5;
    else if (nc==0) return con;
    else return -10;
    
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
string arr_pwd[num_pwds];
for (int i=0;i<num_pwds;i++)
arr_pwd[i]=arr_pwds[i];
int test2=0,pos2=0;
int number[num_pwds];
for (int i=0;i<num_pwds;i++)
 number[i]=i;
for (int i=0;i<num_pwds;i++){
   int pos1=i,test1=1;
 if(i==number[i])
for (int j=0;j<num_pwds;j++)
    if(i!=j)
    if(arr_pwd[i]==arr_pwd[j])
       {test1+=1;
       number[j]=-1;
       }
if(test1==test2)
       {if(arr_pwd[pos1].length()>arr_pwd[pos2].length())
         pos2=pos1;}
if(test1>test2){
        test2=test1;
        pos2=pos1;
    }
}
    return pos2;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////