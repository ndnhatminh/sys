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
void rangeHP(int n) {
    if (n<0) {  n=0;}
    if (n>666) { n=666;}
}
void rangeEXP( int n) {
    if (n<0) {  n=0;}
    if (n>600) { n=600;}
}
void rangeM(int n) {
    if (n<0) { n=0;}
    if (n>3000) { n=3000;}
}
int firstMeet(int & EXP1, int & EXP2, int E1) 
{
    // TODO: Complete this function
    int D;
    float e1 =E1;
    rangeEXP(EXP2);
    rangeEXP(EXP1);
    switch (E1)
            {
            case 0:  EXP2+=29; break;
            case 1:  EXP2+=45; break;
            case 2:  EXP2+=75; break;
            case 3:  EXP2+=149; break;
            }
    if (E1>0&& E1<=3) { 
            rangeEXP(EXP1);
            D = e1*3 + EXP1*7;
            if(D%2==0) {EXP1 += ceil(D/200);}
                else {EXP1 -= ceil(D/100);}
                    }
    rangeEXP(EXP1);
    rangeEXP(EXP2);
    if(E1>=4 && E1<=19) {EXP2+= ceil(e1/4 + 19);}
        else if (E1>=20 && E1<=49) {EXP2 += ceil(e1/9 + 21);}
        else if (E1>=50 && E1<=65) {EXP2+= ceil( e1/16 + 17);}
        else if (E1>=66 && E1<=79) 
        {   
            EXP2 += ceil(e1/4 + 19);
            if(EXP2>200) {EXP2 += ceil(e1/9 + 21);}
        }
        else if (E1>=80 && E1<=99)
        {
            EXP2+= ceil(e1/4 + 19 + e1/9 + 21);
            rangeEXP(EXP2);
            if(EXP2>400) {EXP2= ceil((EXP2 + e1/16 + 17)*1.15);}
            rangeEXP(EXP2);
        }
    rangeEXP(EXP1);
    
    if(E1>=4 && E1<=99) {
                        rangeEXP(EXP1);
                        EXP1-= E1;}
    rangeEXP(EXP1);
    return EXP1 + EXP2;
}

// Task 2
int ncp(int n) {
        float S;
        S=round(sqrt(n))*round(sqrt(n));
        return n=S;
    }
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
     //path1
    float i,P1,P2,P3;
    if (EXP1>ncp(EXP1)) {P1=100;}
        else {P1=(EXP1/ncp(EXP1) + 80)/123;}
    //path2
    int Mu = 0,Ms=round(M1/2);
    do
    {
        rangeHP(HP1);
        if(HP1<200) 
        {   
            HP1 = ceil(HP1*1.3);
            Mu += 150;
            M1-=150;
        }
            else
            {
                HP1 = ceil(HP1*1.1);
                Mu+=70;
                M1-=70;
            }
        rangeHP(HP1);
        rangeEXP(EXP1);
        if(Mu>Ms) { break;}
        if (M1<0) {break;}
        if(EXP1<400) 
        {
            M1-=200;
            EXP1 = ceil(EXP1*1.13);
            Mu+= 200;
            
        }
        else 
        {
            M1-=120;
            EXP1 = ceil(EXP1*1.13);
            Mu+=120;
        }
        if(Mu>Ms) { break;}
        if (M1<0) {break;}
        if(EXP1<300) 
        {   
            M1 -= 100;
            Mu+= 100;
        }
        else 
        {
            M1 -= 120;
            Mu+= 120;
        }
    if(Mu>Ms) {break;}
    if (M1<0) {break;}
    }
     while(E2%2==1);
    if(E2%2!=0||M1==0) {HP1=0.83*HP1;
                        EXP1+=0.17*EXP1;
                        }
    rangeM(M1);
    rangeHP(HP1);
    if(E2%2==1||M1==0)
    {
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        rangeHP(HP1);
        rangeEXP(EXP1);
    }
    if (EXP1>ncp(EXP1)) {P2=100;}
        else {P2=(EXP1/ncp(EXP1) + 80)/123;}
    //path3
    int ar[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int dau,cuoi, tong;
    if(E2>10)
    {
    dau = E2/10;
    cuoi = E2%10;
    tong = (dau + cuoi)%10;
    P3 = ar[tong];
    }
     else P3 = ar[E2];

    //TONG KET
    float tb;
    if(P1==P2&&P2==P3) EXP1 = ceil(EXP1*0.75);
    else
    {
        tb = (P1 + P2 + P3)/3;
        if(tb<50)
        {
            HP1 = ceil(HP1*0.85);
            EXP1 = ceil(EXP1*1.15);
        }
        else 
        {
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*1.2);
        }
    }
    rangeHP(HP1);
    rangeEXP(EXP1);
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    //LAP BAN DO
    int bando[10][10],i,j, high=0,low=0;
    int x,y, taxi;
     for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            bando[i][j]=((E3*j) + (i*2))*(i-j);
            if(bando[i][j]>(E3*2)) high++;
            else if(bando[i][j]<-(E3)) low++;
        }
    }
    //TINH DIEM TAXI
    x=high;
    y=low;
int tam1,tam2;
while (x>=10)
    {
        tam1=x/10;
        tam2=x%10;
        x = tam1+tam2; 
    }
while (y>=10)
    {   
        tam1=y/10;
        tam2=y%10;
        y = tam1+tam2;
    }

    taxi = bando[x][y];

    //TINH DIEM SHERLOCK
    int mcc,mcp, max_phai_duoi,max_trai_tren,max_trai_duoi,max;
    int sx=x,sy=y;
    //cheochinh
    if (sx>sy) {
              sx=sx-sy;
              sy=0;  
            }
        else if (sy>sx) {
            sy=sy-sx;  
            sx=0;
            }
        else {sx=0;
              sy=0;
            }
    mcc=bando[sx][sy];
    while (sx<9||sy<9) {
            
            if (bando[sx][sy]>mcc) {mcc=bando[sx][sy];}
            sx++;sy++;
    }
    max=mcc;
    sx=x; sy=y;
//cheo phu
while (sx>=0&&sy>=0&&sx<9&&sy<9) {
    if (bando[sx][sy]>max) { max=bando[sx][sy];}
    sx-=1; sy+=1;
}
sx=x;sy=y;
while (sx>=0&&sy>=0&&sx<9&&sy<9) {
    if (bando[sx][sy]>max) { max=bando[sx][sy];}
    sx+=1; sy-=1;
}
    //SO DIEM CA HAI
rangeEXP(EXP1); rangeEXP(EXP2);
rangeHP(HP1); rangeHP(HP1);
   if(abs(taxi)<abs(max))
         {
            HP1 = ceil(HP1*1.1);
            EXP1 = ceil(EXP1*1.12);
            HP2 = ceil(HP2*1.1);
            EXP2 = ceil(EXP2*1.12); 
            rangeEXP(EXP1); rangeEXP(EXP2);
            rangeHP(HP1); rangeHP(HP1);
            return max;
         }
    else 
        {
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*0.88);
            HP2 = ceil(HP2*0.9);
            EXP2 = ceil(EXP2*0.88); 
            return taxi;
        }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string es = email, se, special="@#%$!";
    //email
    se=es.erase(es.find("@"));

    //pass
    string strc = s;
    
        //lenghth
        if(strc.size()<8) {return -1;}
            else if(strc.size()>20) {return -2;}
        //find se

        if (strc.find(se) != string::npos) {return -(300 + strc.find(se));}
        //repeat
        for(int i = 0; i<=strc.size();i++)
        {
             if (strc[i] == strc[i+1] && strc[i+1] == strc[i+2]) return -(400 + i);
        }
        
        //special text
        bool spS= false;
        for(int s = 0;s<=4;s++)
                    {       
            if(strc.find(special[s])>=0&&strc.find(special[s]<=strc.size())) {spS=true;}
                    }
        if (spS=false) return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
string pswa[num_pwds];
for (int i=0; i<num_pwds;i++)
{
    pswa[i] = arr_pwds[i];
}
string pass;
int max = 0, count =1, pos;
for(int i = 0; i<=num_pwds;i++)
 {
    for(int k=i+1;k<=num_pwds;k++)
     {
            if(pswa[i].size()==pswa[k].size()&&pswa[k].find(pswa[i])==0) {count++;}
     }
     
    if (count>max) 
     {
        pass= pswa[i];
        max = count;
        pos = i;
     }
     else if(count == max) 
     {
        if(pswa[i].size()>pass.size()) 
        {
            pass = pswa[i];
            pos = i;
        }
     }
     count = 1;
 }

    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////