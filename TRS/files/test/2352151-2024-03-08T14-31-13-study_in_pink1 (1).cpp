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
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
void checkExp(int &exp)
{
    if ( exp>600 ) exp=600;
    if ( exp<0 ) exp=0;
}
void checkE(int &e)
{
    if( e<0 || e>99 ) e=-99;
}
void checkHP(int &HP)
{
    if( HP>666 ) HP=666;
    if ( HP<0 ) HP=0;
}
void checkM(int &M)
{
    if ( M>3000 ) M=3000;
    if ( M<0 ) M=0;
}
int firstMeet(int & exp1, int & exp2, int e1) 
{
    // TODO: Complete this function
    //Trường hợp 1
    checkExp(exp1);
    checkExp(exp2);
    checkE(e1);
    if ( e1>=0 && e1<4)
    {
        switch (e1)
        {
            case 0: exp2+=29; break;
            case 1: exp2+=45; break;
            case 2: exp2+=75; break;
            case 3: exp2+=29+45+75; break;
        }
        checkExp(exp2);
        int D=e1*3+exp1*7;
        if (D%2==0) 
        {
            exp1=ceil(exp1+(double(D)/200));
            checkExp(exp1);
        }
        else 
        {
            exp1=ceil(exp1-(double(D)/100));
            checkExp(exp1);
        }
    }
    // Trường hợp 2
    if( e1>=4 && e1<=99)
    {
        if (e1>=4 && e1<=19) exp2=exp2+ceil((double(e1)/4)+19);
        checkExp(exp2);
        if (e1>=20 && e1<=49) exp2=exp2+ceil((double(e1)/9)+21);
        checkExp(exp2);
        if (e1>=50 && e1<=65) exp2=exp2+ceil((double(e1)/16)+17);
        checkExp(exp2);
        if (e1>=66 && e1<=79) 
        {   
            exp2=exp2+ceil((double(e1)/4)+19);
            checkExp(exp2);
            if(exp2>200) 
            {
                exp2=exp2+ceil((double(e1)/9)+21);
                checkExp(exp2);
            }
        }
        if (e1>=80 && e1<=99) 
        {  
            exp2=exp2+ceil((double(e1)/4)+19);
            checkExp(exp2);
            exp2=exp2+ceil((double(e1)/9)+21);
            checkExp(exp2);
            if (exp2>400) 
            {
                exp2=exp2+ceil((double(e1)/16)+17);
                checkExp(exp2);
                exp2=ceil(exp2+0.15*double(exp2));
                checkExp(exp2);
            }
        }
        exp1-=e1;
        checkExp(exp1);
    }
if ( e1==-99 ) return -99;
return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    // TODO: Complete this function
    checkExp(EXP1);
    checkM(M1);
    checkHP(HP1);
    checkE(E2);
    if (E2==-99) return -99;
    //con đường 1
    double S1;
    double sqrtS1;
    sqrtS1=round(sqrt(EXP1));
    S1=pow(sqrtS1,2);
    double p1=1;
    if (S1>EXP1) p1=(double(EXP1/S1)+80)/123;
    //con đường 2
    if (E2%2==1)
    {
        double cost=0;
        double limit=0.5*M1;
        while ( cost<=limit )
        {
            //sự kiện 1
            if ( HP1<200 ) 
            {
                HP1=ceil(double(HP1)*130/100);
                M1-=150;
                cost+=150;
                checkHP(HP1);
            } else if ( HP1>=200 ) 
            {
                HP1=ceil(double(HP1)*110/100);
                checkHP(HP1);
                M1-=70;
                cost+=70;
            }
            if ( cost>limit ) break;
            //sự kiện 2
            if ( EXP1<400 ) 
            {
                M1-=200;
                cost+=200;
            } else if ( EXP1>=400 ) 
            {
                M1-=120;
                cost+=120;
            }
            EXP1=ceil(double(EXP1)*113/100);
            checkExp(EXP1);
            if ( cost>limit ) break;
            //sự kiện 3
            if ( EXP1<300 ) 
            {
                M1-=100;
                cost+=100;
            } else if ( EXP1>=300 ) 
            {
                M1-=120;
                cost+=120;
            }  
            EXP1=ceil(double(EXP1)*90/100);
        }
        checkM(M1);
    }

    if( E2%2==0 )
    {
        //sự kiện 1
        if ( HP1<200 && M1>0 ) 
        {
            HP1=ceil(double(HP1)*130/100);
            checkHP(HP1);
            M1-=150;
        }
        else if ( HP1>=200 && M1>0 ) 
        {
            HP1=ceil(double(HP1)*110/100);
            checkHP(HP1);
            M1-=70;
        }
        //sự kiện 2
        if ( EXP1<400 && M1>0 ) 
        {
            M1-=200;
            EXP1=ceil(double(EXP1)*113/100);
            checkExp(EXP1);
        }
        else if (EXP1>=400 && M1>0 ) 
        {
            M1-=120;
            EXP1=ceil(double(EXP1)*113/100);
            checkExp(EXP1);
        }
        //sự kiện 3
        if ( EXP1<300 && M1>0 ) 
        {
            M1-=100;
            EXP1=ceil(double(EXP1)*90/100);
            checkM(M1);
        }
        else if (EXP1>=300 && M1>0 ) 
        {
            M1-=120;
            EXP1=ceil(double(EXP1)*90/100);
            checkM(M1);
        }
        checkM(M1);
    }

    HP1=ceil(double(HP1)*83/100);
    EXP1=ceil(double(EXP1)*117/100);
    checkExp(EXP1);
    double S2;
    double sqrtS2;
    sqrtS2=round(sqrt(EXP1));
    S2=pow(sqrtS2,2);
    double p2=1;
    if (S2>EXP1) p2=(double(EXP1/S2)+80)/123;
    //con đường 3
    double P[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    int i;
    double p3;
    if( (E2/10)<1 ) p3=P[E2];
    else
    {
        int tmp;
        tmp=(E2/10)+(E2%10);
        if( tmp>=10 ) 
        {
            i=tmp%10;
            p3=P[i];
        } else p3=P[tmp];
    }
    if( p1==1 && p2 ==1 && p3==1) EXP1=ceil(double(EXP1)*75/100);
    else
    {
        double ptb;
        ptb=(p1+p2+p3)/3;
        if( ptb < 0.5 ) 
        {
            HP1=ceil(double(HP1)*85/100);
            EXP1=ceil(double(EXP1)*115/100);
            checkExp(EXP1);
        }
        if ( ptb >=0.5 )
        {
            HP1=ceil(double(HP1)*90/100);
            EXP1=ceil(double(EXP1)*120/100);
            checkExp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    checkE(E3);
    if (E3==-99) return -99;
    int tmp1=0;
    int tmp2=0;
    double p[10][10];
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            p[i][j]=((E3*j)+(i*2))*(i-j);
            if ( p[i][j]>(E3*2) ) tmp1++;
            if ( p[i][j]<(-E3) ) tmp2++;
        }
    }
    while( (tmp1/10)>=1  ) tmp1=(tmp1/10)+(tmp1%10);
    while( (tmp2/10)>=1  ) tmp2=(tmp2/10)+(tmp2%10);
    int max=p[tmp1][tmp2];
    int min=p[tmp1][tmp2];
    int pointX=tmp1;
    int pointY=tmp2;
    while( pointX<10 && pointY<10 && pointX>=0 && pointY>=0   )
    {
        if( p[pointX][pointY]>max ) max=p[pointX][pointY];
        if( p[pointX][pointY]<min ) min=p[pointX][pointY];
        pointX++;
        pointY++;
    }
    pointX=tmp1;
    pointY=tmp2;
    while( pointX<10 && pointY<10 && pointX>=0 && pointY>=0 )
    {
        if( p[pointX][pointY]>max ) max=p[pointX][pointY];
        if( p[pointX][pointY]<min ) min=p[pointX][pointY];
        pointX--;
        pointY--;
    }
    pointX=tmp1;
    pointY=tmp2;
    while( pointX<10 && pointY<10 && pointX>=0 && pointY>=0 )
    {
        if( p[pointX][pointY]>max ) max=p[pointX][pointY];
        if( p[pointX][pointY]<min ) min=p[pointX][pointY];
        pointX++;
        pointY--;
    }
    pointX=tmp1;
    pointY=tmp2;
    while( pointX<10 && pointY<10 && pointX>=0 && pointY>=0 )
    {
        if( p[pointX][pointY]>max ) max=p[pointX][pointY];
        if( p[pointX][pointY]<min ) min=p[pointX][pointY];
        pointX--;
        pointY++;
    }
    if ( abs(p[tmp1][tmp2])>abs(max) ) 
    {
        EXP1=ceil(double(EXP1)*88/100);
        EXP2=ceil(double(EXP2)*88/100);
        HP1=ceil(double(HP1)*90/100);
        HP2=ceil(double(HP2)*90/100);
    }
    else
    {
        EXP1=ceil(double(EXP1)*112/100);
        checkExp(EXP1);
        EXP2=ceil(double(EXP2)*112/100);
        checkExp(EXP2);
        HP1=ceil(double(HP1)*110/100);
        checkHP(HP1);
        HP2=ceil(double(HP2)*110/100);
        checkHP(HP2);
    }
    if ( abs(p[tmp1][tmp2])>abs(max) ) return p[tmp1][tmp2];
    else return max;
}

// Task 4
int checkPassword(const char * s, const char * email) 
{
    string se, _email(email), _pass(s);
    int tmp;
    tmp=_email.find("@");
    se=_email.substr(0,tmp);
    if( _pass.length()<8 ) return -1;
    if( _pass.length()>20 ) return -2;
    if( _pass.find(se) != string::npos ) return -(300+(_pass.find(se)));
    for (int i=2;i<=_pass.length();i++)
    {
        if ( _pass[i]==_pass[i-1] && _pass[i-1]==_pass[i-2] ) return -(400+i-2);
    }
    if ( (_pass.find("@") == string::npos) && (_pass.find("#") == string::npos) && (_pass.find("$") == string::npos) && (_pass.find("%") == string::npos) && (_pass.find("!") == string::npos)) return -5;
    for (int i=0;i<_pass.length();i++) 
    {
        if( (_pass[i]<33) ||( (_pass[i]>39) && (_pass[i]<48) ) || ( (_pass[i]>57) && (_pass[i]<64) ) || ( (_pass[i]<97) && (_pass[i]>90) ) || (_pass[i]>122) ) return i;
    }
    return -10;
}
// Task5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    //Chuyển số lần sang mảng
    string arra_pwds[num_pwds];
    for(int i=0;i<num_pwds;i++)
    {
        arra_pwds[i]=string(arr_pwds[i]);
    }
    int numOc[num_pwds];
    for (int i=0;i<num_pwds;i++ )
    {
        int tmp=0;
        for (int j=0;j<num_pwds;j++)
        {
            if ( arra_pwds[i] == arra_pwds[j] ) tmp++;
        }
        numOc[i]=tmp;
    }
    int maxNum=numOc[0];
    int fristLo;
    int maxLength=string(arra_pwds[0]).length();
    //Số lần lớn nhất
    for (int i=0;i<num_pwds;i++)
    {
        if (numOc[i]>maxNum) maxNum=numOc[i];
        if ( string(arra_pwds[i]).length() > maxLength ) maxLength=string(arra_pwds[i]).length();
    }
    //Vị trí gần nhất
    for (int i=0;i<num_pwds;i++)
    {
        if (numOc[i]==maxNum) 
        {
            fristLo=i;
            break;
        }
    }
    for (int i=0;i<num_pwds;i++ )
    {
        if ( numOc[i]==maxNum && string(arra_pwds[i]).length()==maxLength ) return i;
    }
    int maxLength1;
    for( int i=0;i<num_pwds;i++)
    {
        if ( numOc[i]==maxNum )
        {
            maxLength1=string(arra_pwds[i]).length();
            for(int j=0;j<num_pwds;j++)
            {
                if( numOc[j]==maxNum )
                {
                    if( string(arra_pwds[j]).length()>maxLength1 ) maxLength1=string(arra_pwds[j]).length();
                }
            }
            if ( string(arra_pwds[i]).length()==maxLength1 ) return i;
        }
    }
    return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////