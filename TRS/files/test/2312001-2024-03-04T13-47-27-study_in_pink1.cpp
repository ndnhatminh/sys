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
//Declare Student's Function
int Roundup(float a);
void Valid(int &a,string b);
bool Between(int x,int a, int b) {return ((x>=a)&&(x<=b));}
int FindS(int EXP1);
int reduceE2(int E2);
int reduceE3(int E3);
int Countchar (const char *s,char x);
bool Testslonger(const char *s);
bool Testsshorter(const char *s);
bool Testsci (const char *s,int &sci);
bool TestSpecialChar(const char *s);
bool SEappearinS (char *se,const char*s,int &SEposition);
bool CharTest0to9(char x );
bool CharTestAtoZ(char x );
bool CharTestatoz(char x );
bool SCTest(char x);
bool ValidChar (const char *s, int &i);

// Task 1 ------------------------------------------------------------
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if((e1<=3)&&(e1>=0)) { //Truong hop 1 
        switch (e1)
            {
                case 0:exp2+=29;break;
                case 1:exp2+=45;break;
                case 2:exp2+=75; break;
                case 3:exp2=exp2+29+45+75; break;
                default: break;
            }
        // Checking lan 1 de tinh D////////////////////
        Valid(exp1,"EXP1");
        Valid(exp2,"EXP2");
        ///////////////////////////////////////////////
    int D = 3*e1+7*exp1;
    if ((D % 2)==0) exp1=Roundup((float)(exp1+((float)(D))/200)); else 
        {exp1=Roundup((float)(exp1-((float) D)/100));}
        //Check lan 2/////////////////////////////////
        Valid(exp1,"EXP1");
        Valid(exp2,"EXP2");
        //////////////////////////////////////////////
    return exp1 + exp2;
    }   else if ((e1>=4)&&(e1<=99)){// Truong hop 2
        int th1=Roundup(((float)(e1))/4+19);
        int th2=Roundup(((float)(e1))/9+21);
        int th3=Roundup(((float)(e1))/16+17);
        bool tt1=0;
        bool tt2=0;
        bool tt3=0;
        //******************* Yeu cau **************************
            if (Between(e1,4,19)) {exp2+=th1;tt1=1;} //Giai thich t1
            else if (Between(e1,20,49)) {exp2+=th2;tt2=1;} //Giai thich t2
            else if (Between(e1,50,65)) {exp2+=th3; tt3=1;} //Giai thich t3
            else if (Between(e1,66,79)) {
                exp2+=th1;tt1=1; //Giai thich thong tin 1
                if (exp2>200) {exp2+=th2;tt2=1;} // Giai thich thong tin 2
                }
            else {
                 exp2+=th1;tt1=1; //Giai thich thong tin 1
                 exp2+=th2;tt2=1; //Giai thich thong tin 2
                 if (exp2>400) {exp2+=th3; tt3=1;} //Giai thich thong tin 3 
            }
        //********************************************************
        if ((tt1)&&(tt2)&&(tt3)) exp2=Roundup((float)(exp2*1.15));
        exp1-=e1;
        //***************Check**********************************
        Valid(exp1,"EXP1"); Valid(exp2,"EXP2");
        //*******************************************************
        return exp1 + exp2;
    } else {return -99;}            
}
//-----------------------------------------------------------------------

// Task 2----------------------------------------------------------------
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (Between(E2,0,99))   {
//****************Check********************************
Valid(EXP1,"EXP1"); Valid(HP1,"HP1"); Valid(M1,"M1");
//*****************************************************
//Con duong 1////////////////////////////////////////////////////////
    float P1;
    int S=FindS(EXP1);
        if (EXP1>=S) P1=1 ; else P1=((EXP1+0.00)/S+80)/123;
//Con duong 2 ///////////////////////////////////////////////////////
    int InitialMoney=M1;
    int Needtopay=0;
    bool E2le=0; if ((E2 % 2) == 1 ) E2le=1; 

while (1)
{
    //Kiemtradutien?********************************************
    if (E2le) if (Needtopay > 0.5*InitialMoney) break;
    //***********************************************************  
    //Cua Hang ven duong
    if (HP1<200) {
        Needtopay+=150;/*Tien -150*/
        HP1=Roundup((float)(HP1)*1.3); /*HP1 +30%*/
        }
    else {
        Needtopay+=70; /*Tien -70*/
        HP1=Roundup((float)(HP1)*1.1); /*+10%HP1*/
        
    }
    if (!(E2le)) if (InitialMoney < Needtopay) break; //Chan nhung ko du tien
    //Kiemtradutien?********************************************
    if (E2le) if (Needtopay > 0.5*InitialMoney) break;
    //***********************************************************  
//Xe ngua hoac taxi
    if (EXP1<400) Needtopay+=200; else Needtopay+=120;
    EXP1=Roundup((float)(EXP1)*1.13); /*EXP1 +13%*/
    if (!(E2le)) if (InitialMoney < Needtopay) break; //Chan nhung ko du tien
    //Kiemtradutien?********************************************
    if (E2le) if (Needtopay > 0.5*InitialMoney) break;
    //***********************************************************  
//Gap vo gia cu
    if (EXP1<300) Needtopay+=100; else  Needtopay+=120;
    EXP1=Roundup((float)(EXP1)*0.9); /*EXP1 -10%*/

    //***************E2 chan thoat vong lap***********************
    if (!(E2le)) break;
}
// Kiem toan con duong 2:
    EXP1=Roundup((float)(EXP1)*1.17); /*EXP1 +17%*/
    HP1=Roundup((float)(HP1)*0.83); /*HP1 -17%*/
    M1-=Needtopay;
//****************Check********************************
Valid(EXP1,"EXP1"); Valid(HP1,"HP1"); Valid(M1,"M1");
//*****************************************************
//TinhxacsuatP2
float P2;
    S=FindS(EXP1);
    if (EXP1>=S) P2=1 ; else P2=((EXP1+0.00)/S+80)/123;
//Conduong3//////////////////////////////////////////////////////////
float P2mau[] ={32,47,28,79,100,50,22,83,64,11};
float P3=(P2mau[reduceE2(E2)]/100);
    if ((abs(P1-1)<10e-6) && (abs(P2-1)<10e-6) && (abs(P3-1)<10e-6))
        EXP1=Roundup((float)(EXP1)*0.75); // EXP1 -25%
    else {
            float Ptb=((P1+P2+P3)/3); // Gia tri P trung binh
            if (Ptb<0.5)
            {
            HP1=Roundup((float)(HP1)*0.85); // EXP1 -15%
            EXP1=Roundup((float)(EXP1)*1.15); // EXP1 +15%   
            }
            else {
            HP1=Roundup((float)(HP1)*0.9); // EXP1 -15%
            EXP1=Roundup((float)(EXP1)*1.2); // EXP1 +15%   
            }            
    } 
//****************Check********************************
Valid(EXP1,"EXP1"); Valid(HP1,"HP1"); Valid(M1,"M1");
//*****************************************************
return HP1 + EXP1 + M1;
}  else return -99; 
}
//------------------------------------------------------------------------

// Task 3-----------------------------------------------------------------
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (Between(E3,0,99)) {
        int Taximap[10][10];
    //Khai bao cac phan tu =0
        for (int i=0;i<10;i++) for(int j=0;j<10;j++) {Taximap[i][j]=0;}
    //DiemsocuaTaxi
        for (int i=0;i<10;i++) for(int j=0;j<10;j++) {
            Taximap[i][j] = ((E3*j)+(i*2))*(i-j);}
    //Dem phan tu mang lon hon 2*E3
    int Count1=0,Count2=0;
    for (int i=0;i<10;i++) for (int j=0;j<10;j++) {
        if ((Taximap[i][j]) > (2*E3)) Count1+=1; 
    }
    //Dem phan tu diem nho hon -E3
    for (int i=0;i<10;i++) for (int j=0;j<10;j++) {
        if ((Taximap[i][j]) < (-E3)) Count2+=1; 
    }
    //Vi tri i, Vi tri j.
    int positioni=reduceE3(Count1),positionj=reduceE3(Count2);
    //Max duong cheo
    int i1=positioni;int j1=positionj;
    int MaxD=Taximap[i1][j1];
        while((Between(i1,0,9))&&(Between(j1,0,9))) {
            if (MaxD < Taximap[i1][j1]) MaxD=Taximap[i1][j1];
            i1++;j1++;
        }
    i1=positioni;j1=positionj;
        while((Between(i1,0,9))&&(Between(j1,0,9))) {
            if (MaxD < Taximap[i1][j1]) MaxD=Taximap[i1][j1];
            i1--;j1--;
        }
    i1=positioni;j1=positionj;
        while((Between(i1,0,9))&&(Between(j1,0,9))) {
            if (MaxD < Taximap[i1][j1]) MaxD=Taximap[i1][j1];
            i1++;j1--;
    }
    i1=positioni;j1=positionj;
        while((Between(i1,0,9))&&(Between(j1,0,9))) {
            if (MaxD < Taximap[i1][j1]) MaxD=Taximap[i1][j1];
            i1--;j1++;
    }
    //****************Check****************************************************
    Valid(EXP1,"EXP1"); Valid(HP1,"HP1"); Valid(EXP2,"EXP2");Valid(HP2,"HP2");
    //*************************************************************************
    //Diem so Taxi va Diem so SherlockWatson
    int Taxipoint=Taximap[positioni][positionj];
    int SWpoint=abs(MaxD);
    if (abs(Taxipoint)>SWpoint) {
        EXP1=Roundup((float)(EXP1)*0.88); // EXP1 -12%
        EXP2=Roundup((float)(EXP2)*0.88); // EXP1 -12%
        HP1=Roundup((float)(HP1)*0.9); // HP1 -10%
        HP2=Roundup((float)(HP2)*0.9); // HP2 -10%
        return Taxipoint;       
    }   else {
        EXP1=Roundup((float)(EXP1)*1.12); // EXP1 +12%
        EXP2=Roundup((float)(EXP2)*1.12); // EXP1 +12%
        HP1=Roundup((float)(HP1)*1.1); // HP1 +10%
        HP2=Roundup((float)(HP2)*1.1); // HP2 +10%
            //****************Check****************************************************
            Valid(EXP1,"EXP1"); Valid(HP1,"HP1"); Valid(EXP2,"EXP2");Valid(HP2,"HP2");
            //*************************************************************************
        return SWpoint;
    }
    } else return -99;
}
//-----------------------------------------------------------------------------------------

// Task 4---------------------------------------------------------------------------
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //Khoi tao se:
    char se[100]; char *seaddress=se;
    int CH=Countchar(email,'@');
    for(int i=0;i <= CH-1;i++) {
        se[i]=*(email+i);
    };
    se[CH]='\0';
    // Ket qua tra ve:
    int IVCposition;
    int SEposition;
    int sci;
    if (Testsshorter(s)) return -1; //Ngan hon 8 ki tu
        else if (Testslonger(s)) return -2; //Dai hon 20 ki tu
            else if (SEappearinS(seaddress,s,SEposition)) return -(300+SEposition);//s co chua se
                else if(Testsci(s,sci)) return  -(400+sci); //Chua nhieu hon 2 ki tu giong nhau
                    else if(!(TestSpecialChar(s))) return -5; //
                        else if(ValidChar(s,IVCposition)) return -10;
                            else return IVCposition;
}
//---------------------------------------------------------------------------------------

// Task 5--------------------------------------------------------------------------------
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int CPosition=0;
    int Count=0;
    int MaxCount=0;
    for (int i=0;i<=num_pwds-1;i++) {
        for (int j=num_pwds-1;j>i;j--) {
            if (arr_pwds[i]==arr_pwds[j]) Count++; //Dem so luong trong mang 
        }
        Count++;
            if (Count<MaxCount) Count=0;
                else if (Count>MaxCount) {CPosition=i; MaxCount=Count;Count=0;} //Tim mat khau co so luong lon hon
                    //Neu bang nhau thi so sanh do dai
                    else if (Countchar(arr_pwds[i],'\0')>Countchar(arr_pwds[i-1],'\0')) {CPosition=i;Count=0;}
    }
    return CPosition;
}
//---------------------------------------------------------------------------------------------

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
// Student's Function:

void Valid(int &a, string b) {
    if ((b =="HP1")||(b=="HP2")) {
        if(a>666) a=666; else if(a<0) a=0; }
    else if ((b=="EXP1")||(b=="EXP2")) {
        if(a>600) a=600; else if (a<0) a=0;}
    else if ((b=="M1")||(b=="M2")) {
        if(a>3000) a=3000;else if (a<0) a=0;}  
}

int Roundup(float a) {
    if ((a-((int)(a)))<10e-6) return (int) (a);
    else return ((int)(a))+1;}

int FindS(int EXP1) {
    double S=sqrt(EXP1);
    int S1=round(S); int S2=Roundup(S);
    if ((abs(S-S1))<(abs(S-S2))) return S1*S1; else return S2*S2;
}

int reduceE2(int E2) {
    if (E2 <= 9) return E2;
        else {
            E2=round(E2/10)+(E2 % 10);
            return (E2 % 10 );}
};

int reduceE3(int E3) {
    if (E3<=9) return E3;
        else E3=round(E3/10)+(E3 % 10);
        return reduceE3(E3);
};

int Countchar (const char *s,char x) {
    int count=0;
    while ((*(s+count) != x )&&(count <=100)) {
        count +=1;
    }
    return count; //Tra ve vi tri ki tu ko chua x
}

bool Testslonger(const char *s) {
    if (Countchar(s,'\0')>20) return true; else return false;
}

bool Testsshorter(const char *s){
     if (Countchar(s,'\0')<8) return true; else return false;
}

bool Testsci (const char *s,int &sci){
    sci=0;
    while ((*(s+sci) != *(s+sci+1))&&(*(s+sci+1)!='\0')) {
        sci+=1;
    }
    if (*(s+sci+1)=='\0') return false; else return true; //Tra ve dung so thu tu (khong tinh \0)
}

bool TestSpecialChar(const char *s) {
    int i=0;
    bool TSC=0;
    while (*(s+i)!='\0'){
        if ((*(s+i)=='@')||(*(s+i)=='#')||(*(s+i)=='%')||(*(s+i)=='$')||(*(s+i)=='!'))
        {
            TSC=1; break;
        }
        i+=1;
    }
    return TSC;
}

bool SEappearinS (char *se,const char*s,int &SEposition){
    if (Countchar(se,'\0')>Countchar(s,'\0')) return 0;
        else {
            int si=0,sei=0;
            while (*(s+si)!='\0'){
                if (*(se+sei) == *(s+si)){
                    sei+=1;
                    if (sei==1) SEposition=si;
                    if (*(se+sei) != *(s+si+1)) {sei=0;SEposition=0;} }
                if (*(se+sei+1)=='\0') {break;}
                si+=1;
            }
                if (sei==0) return false; else return true;
            }
}

bool CharTest0to9(char x ) {
    if ((x>='0')&&(x<='9')) return true; else return false;
}

bool CharTestAtoZ(char x ) {
    if ((x>='A')&&(x<='Z')) return true; else return false;
}

bool CharTestatoz(char x ) {
    if ((x>='a')&&(x<='z')) return true; else return false;
}

bool SCTest(char x) {
    if ((x=='@')||(x=='#')||(x=='%')||(x=='$')||(x=='!')) return true; else return false;
}

bool ValidChar (const char *s, int &i) {
    i=0;
    bool VC=1;
    while (*(s+i)!='\0') {
        if (!((CharTest0to9(*(s+i)))||(CharTestAtoZ(*(s+i)))||(CharTestatoz(*(s+i)))||(SCTest(*(s+i)))))
        {VC=0;break;}
        i+=1;
    }
    return VC;
}