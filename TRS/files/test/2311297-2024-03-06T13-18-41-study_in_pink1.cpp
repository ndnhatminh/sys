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
   
void EXP(int &EXP1, int &EXP2){  
    if (EXP1>600) EXP1=600;
    if (EXP1<0) EXP1=0;
    if (EXP2>600) EXP2=600;
    if (EXP2<0) EXP2=0;
}

void HP(int &HP1, int &HP2){
    if (HP1>666) HP1=666;
    if (HP1<0) HP1=0;
    if (HP2>666) HP2=666;
    if (HP2<0) HP2=0;
}

void M(int &M1, int &M2){
    if (M1>3000) M1=600;
    if (M1<0) M1=0;
    if (M2>3000) M2=3000;
    if (M2<0) M2=0;
}
void E(int E1,int E2,int E3){
    if (E1>=0&&E1<=99) E1=E1;
    else E1=-99;
    if (E2>=0&&E2<=99) E2=E2;
    else E2=-99;
    if (E3>=0&&E3<=99) E3=E3;
    else E3=-99;
}
// Task 1
int firstMeet1(int&EXP1,int&EXP2,int E1)
{
    if (E1=0)
        EXP2+=29;
    else if (E1=1)
        EXP2+=45;
    else if (E1=2)
        EXP2+=75;
    else if (E1=3)
        EXP2+=29+45+75; 

    int D=E1*3+EXP1*7;
    if (D%2==0)
        EXP1=static_cast<int>(ceil(EXP1+(D/200.0)-0.001));
    else
        EXP1=static_cast<int>(ceil(EXP1-(D/100.0)-0.001));

    EXP(EXP1,EXP2);
    return EXP1+EXP2;
}

int firstMeet2(int&EXP1,int&EXP2,int E1)
{
    if (E1>=4&&E1<=19)
        EXP2=static_cast<int>(ceil(EXP2+(E1/4.0+19)-0.001));
    else if (E1>=20&&E1<=49)
        EXP2=static_cast<int>(ceil(EXP2+(E1/9.0+21)-0.001));
    else if (E1>=50&&E1<=65)
        EXP2=static_cast<int>(ceil(EXP2+(E1/16.0+17)-0.001));
    else if (E1>=66&&E1<=79)
    {
        EXP2=static_cast<int>(ceil(EXP2+(E1/4.0+19)-0.001));
        if (EXP2>200)
            EXP2=static_cast<int>(ceil(EXP2+(E1/9.0 + 21) - 0.001));
    }
    else
    {
        EXP2=static_cast<int>(ceil(EXP2+(E1/4.0+19)-0.001));
        EXP2=static_cast<int>(ceil(EXP2+(E1/9.0+21)-0.001));
        if (EXP2>400)
        {
            EXP2=static_cast<int>(ceil(EXP2+(E1/16.0+17)-0.001));
            EXP2=static_cast<int>(ceil(EXP2*1.15-0.001));
        }
    }

    EXP1-=E1;
    EXP(EXP1,EXP2); 
    return EXP1+EXP2;
}

int firstMeet(int&EXP1, int&EXP2, int E1) {
    // TODO: Complete this function
    if (E1<=3&&E1>=0)
        firstMeet1(EXP1,EXP2,E1);
    else if (E1>=4&&E1<=99)
        firstMeet2(EXP1,EXP2,E1);
    else
        return 0;

    return EXP1+EXP2;
}

// Task 2
int closestsquare(int X) 
{
    int sqrtA=static_cast<int>(sqrt(X));
    int sqr1=sqrtA*sqrtA;
    int sqr2=(sqrtA+1)*(sqrtA+1);
    if (X-sqr1<sqr2-X) return sqr1;
    else return sqr2;
}

int traceLuggage1(int EXP1)
{
    int S;
    S = closestsquare(EXP1);
    if (EXP1>=S)
        return 1;
    else
        return (EXP1/S+80)/123;
}

int traceLuggage2(int&HP1,int&EXP1,int&M1,int E2)
{
    float sherM=M1*0.5;
    while (true)
    {
        
        if (HP1<200)
        {
            HP1=static_cast<int>(ceil(HP1*1.3-0.001));
            M1-=150;
        }
        else if (HP1>=200)
        {
            HP1=static_cast<int>(ceil(HP1*1.1-0.001));
            M1-=70;
        }
        HP(HP1,HP1); 
        M(M1,M1);    
        if (E2%2==1&&M1<sherM)
        {
            EXP1=static_cast<int>(ceil(EXP1*1.17-0.001));
            HP1=static_cast<int>(ceil(HP1-HP1*0.17-0.001));
            EXP(EXP1,EXP1); 
            HP(HP1,HP1);    
            break;
        }
        else if (E2%2==0&&M1==0)
        {
            EXP1=static_cast<int>(ceil(EXP1*1.17-0.001));
            HP1=static_cast<int>(ceil(HP1-HP1*0.17-0.001));
            EXP(EXP1,EXP1); 
            HP(HP1,HP1);    
            break;
        }

        
        if (EXP1<400)
            M1-=200;
        else if (EXP1>=400)
            M1-=120;
        EXP1=static_cast<int>(ceil(EXP1*1.13-0.001));
        EXP(EXP1,EXP1); 
        M(M1,M1);       
        if (E2%2==1&&M1<sherM)
        {
            EXP1=static_cast<int>(ceil(EXP1*1.17-0.001));
            HP1=static_cast<int>(ceil(HP1-HP1*0.17-0.001));
            EXP(EXP1,EXP1); 
            HP(HP1,HP1);    
            break;
        }
        else if (E2%2==0&&M1==0)
        {
            EXP1=static_cast<int>(ceil(EXP1*1.17-0.001));
            HP1=static_cast<int>(ceil(HP1-HP1*0.17-0.001));
            EXP(EXP1,EXP1); 
            HP(HP1,HP1);    
            break;
        }

        
        if (EXP1<300)
            M1-=100;
        else if (EXP1>=300)
            M1-=120;
        EXP1=static_cast<int>(ceil(EXP1*0.9-0.001));
        EXP(EXP1,EXP1); 
        M(M1,M1);       
        if (E2%2==1&&M1<=sherM)
        {
            EXP1=static_cast<int>(ceil(EXP1*1.17-0.001));
            HP1=static_cast<int>(ceil(HP1-HP1*0.17-0.001));
            EXP(EXP1, EXP1); 
            HP(HP1,HP1);    
            break;
        }
        else if (E2%2==0)
        {
            EXP1=static_cast<int>(ceil(EXP1*1.17-0.001));
            EXP(EXP1,EXP1); 
            HP1=static_cast<int>(ceil(HP1-HP1*0.17-0.001));
            HP(HP1, HP1);    
            break;
        }
    }

    return traceLuggage1(EXP1);
}

int traceLuggage3(int E2)
{
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    int i;
    if (E2<10)
    {
        i=E2;
    }
    else
    {
        i=(E2/10+E2%10)%10;
    }
    return P[i];
}

int traceLuggage(int&HP1, int&EXP1, int&M1, int E2) {
    // TODO: Complete this function
    float P1=traceLuggage1(EXP1);
    float P2=traceLuggage2(HP1,EXP1,M1,E2);
    float P3=traceLuggage3(E2);

    if (P1==100&&P2==100&&P3==100)
        EXP1=static_cast<int>(ceil(EXP1*0.75-0.001));
    else
    {
        float P=(P1+P2+P3)/3;
        if (P<50)
        {
            HP1=static_cast<int>(ceil(HP1*0.85-0.001));
            EXP1=static_cast<int>(ceil(EXP1*1.15-0.001));
        }
        else
        {
            HP1=static_cast<int>(ceil(HP1*0.9-0.001));
            EXP1=static_cast<int>(ceil(EXP1*1.2-0.001));
        }
    }
    EXP(EXP1, EXP1); 
    HP(HP1, HP1);    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    int matran[10][10]={0};
    int sherandwat[10][10]={0};

    
    for (int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            matran[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            int cheotrai=matran[i][j];
            for (int x=0;x<min(i,j);x++)
            {
               if (cheotrai>matran[i-x][j-x]){
                cheotrai=cheotrai;
               } else  cheotrai=matran[i-x][j-x];
            }
            int cheophai=matran[i][j];
            for (int x=0;x<min(10-i,j);x++)
            {
                if (cheophai>matran[i+x][j-x]){
                    cheophai=cheophai;
                } else cheophai=matran[i+x][j-x];
            }

                if (cheophai>cheotrai){
                    sherandwat[i][j]=cheophai;
                } else sherandwat[i][j]=cheotrai;
            sherandwat[i][j]=abs(sherandwat[i][j]);
        }
    }
    int I=0,J=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            if (matran[i][j]>E3*2)
                I++;
            if (matran[i][j]<-E3)
                J++;
        }
    }

    
    while (I>=10||J>=10)
    {
        if (I>=10)
        {
            I=I/10+I%10;
        }
        if (J>=10)
        {
            J=J/10+J%10;
        }
    }
    int gapnhau;
    if (abs(matran[I][J])>sherandwat[I][J])
    {
        EXP1=static_cast<int>(ceil(EXP1*0.88-0.001));
        HP1=static_cast<int>(ceil(HP1*0.9-0.001));
        EXP2=static_cast<int>(ceil(EXP2*0.88-0.001));
        HP2=static_cast<int>(ceil(HP2*0.9-0.001));
        gapnhau=matran[I][J];
    }
    else
    {
        EXP1=static_cast<int>(ceil(EXP1*1.12-0.001));
        HP1=static_cast<int>(ceil(HP1*1.1-0.001));
        EXP2=static_cast<int>(ceil(EXP2*1.12-0.001));
        HP2=static_cast<int>(ceil(HP2*1.1-0.001));
        gapnhau=sherandwat[I][J];
    }
    EXP(EXP1,EXP2); 
    HP(HP1,HP2);    
    return gapnhau;
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string matkhau(s);
    string uEmail(email);
    string se = uEmail.substr(0,uEmail.find('@'));
    if (matkhau.length()<8)
        return -1;
    if (matkhau.length()>20)
        return -2;
    if (matkhau.find(se)!=string::npos)
        return -(300+matkhau.find(se));
    for (int i=0;i<matkhau.length()-2;i++)
    {
        if (matkhau[i]==matkhau[i+1]&&matkhau[i+1]==matkhau[i+2])
            return -(400+i);
    }
    string SChars = "@#%$!";
    bool CSChar = false;
    for (char a: matkhau)
    {
        if (SChars.find(a)!=string::npos)
        {
            CSChar = true;
            break;
        }
    }
    if (!CSChar)
        return -5;
    for (char a: matkhau)
    {
        if (!isdigit(a)&&!isalpha(a)&&SChars.find(a)==string::npos)
            return matkhau.find(a);
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int soluong=0,dai=0,vitri=0;
    for (int i=0;i<num_pwds;i++)
    {
        int count=0,length=strlen(arr_pwds[i]);
        for (int j=0;j<num_pwds;j++)
        {
            if (strcmp(arr_pwds[i],arr_pwds[j])==0)
            {
                count++;
            }
        }
        if (count>soluong||(count==soluong&&length>dai))
        {
            soluong=count;
            dai=length;
            vitri=i;
        }
    }
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////