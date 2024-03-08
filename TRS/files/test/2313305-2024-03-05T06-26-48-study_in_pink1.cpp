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
    // DO NOT MODIFY THIS FUNCTION
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

void checkEXP(int& exp);
void checkHP(int& hp);
void checkM(int& m);
void checkEXP(int& exp)
{
    exp=(exp<0) ? 0 : (exp>600) ? 600 : exp;
}
void checkHP(int& hp)
{
    hp=(hp<0) ? 0 : (hp>666) ? 666 : hp;
}
void checkM(int& m)
{
    m=(m<0) ? 0 : (m>3000) ? 3000 : m;
}
int round_up(float x);
// Task 1
int firstMeet(int& exp1, int& exp2, const int e1) {
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99) return -99;
    float e1test = e1, exp2test = exp2, exp1test = exp1;
    if(0 <= e1 && e1 <= 3)
    {
        switch(e1)
        {
            case 0: exp2 += 29; break;
            case 1: exp2 += 45; break;
            case 2: exp2 += 75; break;
            case 3: exp2 += 29 + 45 + 75; break;
        }
        int d = e1 * 3 + exp1test * 7;
        if(d % 2 == 0) exp1 = round_up(exp1test + d / 200.0);
        else exp1 = round_up(exp1test - d / 100.0);
    }
    else if(4 <= e1 && e1 <= 99)
    {
        int case1;
        case1 = (40 <= e1 && e1 <= 49) ? 2 : (60 <= e1 && e1 <= 65) ? 3 : (e1 / 20 + 1);
        switch(case1)
        {
            case 1: exp2test += (e1test / 4 + 19); break;
            case 2: exp2test += (e1test / 9 + 21); break;
            case 3: exp2test += (e1test / 16 + 17); break;
            case 4: exp2test += (e1test / 4 + 19);
                    if(exp2 > 200)
                    {
                        exp2 = round_up(exp2test);
                        checkEXP(exp2);
                        exp2test = exp2;
                        exp2test += e1test / 9 + 21;
                    }
                    break;
            case 5: exp2test += (e1test / 4 + 19);
                    exp2 = round_up(exp2test);
                    checkEXP(exp2);
                    exp2test = exp2;
                    exp2test += (e1test / 9 + 21);
                    if(exp2test > 400)
                    {
                        exp2 = round_up(exp2test);
                        checkEXP(exp2);
                        exp2test = exp2;
                        exp2test += e1test / 16 + 17;
                        exp2 = round_up(exp2test);
                        checkEXP(exp2);
                        exp2test = exp2;
                        exp2test *= 1.15;
                    }
                    break;
        }
        exp1 -= e1; exp2 = round_up(exp2test);
    }
    checkEXP(exp1); checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
bool checksquare(int s)
{
    for(int i=2; i<=sqrt(s); i++)
        if(i*i==s) return true;
    return false;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0||E2>99) return -99;
    float p1, p2, p3;
    /* ********** path 1 *********** */
    float S1=EXP1, S2=EXP1, S;
    float HP1test=HP1, EXP1test=EXP1; int M1test=M1;
    while(!checksquare(S1)) S1--; while(!checksquare(S2)) S2++;
    if(abs(S2-EXP1)<=abs(S1-EXP1)) S=S2;
    else S=S1;
    if(EXP1>S) p1=1; else p1=(EXP1test/S+80)/123;
    /* ********** path 2 *********** */
    if(E2%2!=0)
        while(M1test>M1/2)
        {
            HP1=round_up(HP1test); checkHP(HP1); HP1test=HP1;
            if(HP1test<200)
            {   HP1test*=1.3; M1test-=150;  }
            else
            {   HP1test*=1.1; M1test-=70;   }
            if(M1test<=M1/2) break;
            if(EXP1test<400) M1test-=200;
            else M1test-=120;
            EXP1test*=1.13;
            EXP1=round_up(EXP1test);
            EXP1test=EXP1;
            checkEXP(EXP1);
            if(M1test<=M1/2) break;
            if(EXP1test<300) M1test-=100;
            else M1test-=120;
            EXP1test*=0.9; EXP1test=round_up(EXP1test);
        }
    else
    {
            if(M1test>=0)
            {
                if(HP1test<200)
                {   HP1test*=1.3; M1test-=150;  }
                else
                {   HP1test*=1.1; M1test-=70;   }
            }

            if(M1test>=0)
            {
                if(EXP1test<400) M1test-=200;
                else M1test-=120;
                EXP1test*=1.13;
                EXP1=round_up(EXP1test);
                checkEXP(EXP1);
                EXP1test=EXP1;
            }
            if(M1test>=0)
            {
                if(EXP1test<300) M1test-=100;
                else M1test-=120;
                EXP1test*=0.9; EXP1test=round_up(EXP1test);
            }
    }
    HP1=round_up(HP1test); checkHP(HP1); HP1test=HP1;
    EXP1=round_up(EXP1test); EXP1test=EXP1; checkEXP(EXP1);
    HP1test*=0.83; EXP1test*=1.17;
    HP1=round_up(HP1test); EXP1=round_up(EXP1test); M1=M1test;
    checkEXP(EXP1); checkHP(HP1); checkM(M1);
    HP1test=HP1; EXP1test=EXP1;
    S1=EXP1; S2=EXP1;
    while(!checksquare(S1)) S1--; while(!checksquare(S2)) S2++;
    if(abs(S2-EXP1)<=abs(S1-EXP1)) S=S2;
    else S=S1;
    if(EXP1>S) p2=1; else p2=(EXP1test/S+80)/123;
    /* ********** path 3 *********** */
    float pa[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2<10) p3=pa[E2]/100;
    else p3=pa[(E2%10+(E2-E2%10)/10)%10]/100;
    float p=(p1+p2+p3)/3;
    if(p==1) EXP1test*=0.75;
    else if(p<0.5) { EXP1test*=1.15; HP1test*=0.85; }
    else { EXP1test*=1.2; HP1test*=0.9; }
    HP1=round_up(HP1test); EXP1=round_up(EXP1test);
    checkEXP(EXP1); checkHP(HP1);
    return HP1+EXP1+M1;
}

// Task 3
int round_up(float x)
{
    if(round(x)==x) return x;
    else return ceil(x);
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99) return -99;
    int MapT[10][10], MapSW[10][10];
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            MapT[i][j]=(E3*j+i*2)*(i-j);
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            int Max=-1e9, Maxtest=-1e9;
            for(int ii=1; ii<10; ii++)
            {
                if(i-ii<0||j-ii<0) break;
                if(Max<MapT[i-ii][j-ii]) Max=MapT[i-ii][j-ii];  //cheo trai duoi
            }
            for(int ii=1; ii<10; ii++)
            {
                if(i-ii<0||j+ii>9) break;
                if(Max<MapT[i-ii][j+ii]) Max=MapT[i-ii][j+ii];  //cheo trai tren
            }
            for(int ii=1; ii<10; ii++)
            {
                if(i+ii>9||j+ii>9) break;
                if(Max<MapT[i+ii][j+ii]) Max=MapT[i+ii][j+ii];  //cheo phai tren
            }
            for(int ii=1; ii<10; ii++)
            {
                if(i+ii>9||j-ii<0) break;
                if(Max<MapT[i+ii][j-ii]) Max=MapT[i+ii][j-ii];  //cheo phai duoi
            }
            if(Max!=Maxtest) MapSW[i][j]=abs(Max);
            else MapSW[i][j]=0;
        }
    int I=0, J=0;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            if(MapT[i][j]>E3*2) I++;
            if(MapT[i][j]<-E3) J++;
        }
    while(I>=10||J>=10)
    {
        if(I>=10) I=I%10+I/10;
        if(J>=10) J=J%10+J/10;
    }
    float EXP1test=EXP1, EXP2test=EXP2, HP1test=HP1, HP2test=HP2;
    if(abs(MapT[I][J])>MapSW[I][J])
    {
        EXP1=round_up(EXP1test*0.88); EXP2=round_up(EXP2test*0.88);
        HP1=round_up(HP1test*0.9); HP2=round_up(HP2test*0.9);
        checkEXP(EXP1); checkHP(HP1); checkEXP(EXP2); checkHP(HP2);
        return MapT[I][J];
    }
    else
    {
        EXP1=round_up(EXP1test*1.12); EXP2=round_up(EXP2test*1.12);
        HP1=round_up(HP1test*1.1); HP2=round_up(HP2test*1.1);
        checkEXP(EXP1); checkHP(HP1); checkEXP(EXP2); checkHP(HP2);
        return MapSW[I][J];
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char * se; int Cemail=0, Cs=0;
    for(int i=0; i<strlen(email); i++)
        if(email[i]=='@') Cemail++;
    if(Cemail>1||strlen(email)>100) return -99;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            se = new char[i + 1]; // Allocate memory for se
            strncpy(se, email, i); // Copy the substring before '@' to se
            break;
        }
    }
    if(strlen(s)<8) return -1;
    if(strlen(s)>20) return -2;
    if(strcmp(s,se))
    {
        for (int i = 0; i<=strlen(s)-strlen(se); i++)
        {
            int j=0;
            while(s[i+j]==se[j]) j++;
            if (j == strlen(se)) return -(300+i);
        }
    }
    for(int i=0; i<strlen(s); i++)
        if(s[i]==s[i+1]&&s[i+1]==s[i+2]) return -(400+i);
    for(int i=0; i<strlen(s); i++)
    {
        switch(s[i])
        {
            case '@': Cs++; break;
            case '#': Cs++; break;
            case '%': Cs++; break;
            case '$': Cs++; break;
            case '!': Cs++; break;
        }
    }
    if(Cs==0) return -5;
    delete[] se;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int pos, cnt=0; string longerPwd;
    for(int i=0; i<num_pwds; i++)
    {
        int cntTest=0;
        for(int j=i+1; j<num_pwds; j++)
            if(arr_pwds[i]==arr_pwds[j]) cntTest++;
        if(cnt<cntTest)
        {
            cnt=cntTest;
            pos=i;
            longerPwd=arr_pwds[i];
        }
        else if(cnt==cntTest)
            if(strlen(arr_pwds[i])>longerPwd.size())
        {
            pos=i;
            longerPwd=arr_pwds[i];
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////