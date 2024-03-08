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
int lamtronexp (int exp)
{
    if (exp>600)
    {
        return 600;
    }
    if (exp<0)
    {
        return 0;
    }
    else
    {
        return exp;
    } 
}
int lamtronhp(int hp)
{
    if (hp>666)
    {
        return 666;
    }
    if (hp<0)
    {
        return 0;
    }
    else
    {
        return hp;
    } 
}
int lamtronm(int money)
{
    if (money>3000)
    {
        return 3000;
    }
    if (money<0)
    {
        return 0;
    }
    else
    {
        return money;
    } 
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D = e1*3 + exp1*7;
    if (e1==0)
    {
        exp2 = exp2 + 29;

        if (D%2==0) 
            {
                exp1= ceil(exp1 + D/200.0);
            }
         else
            {
                exp1= ceil(exp1 - D/100.0);
            }
                 exp1 = lamtronexp(exp1);
                exp2 = lamtronexp(exp2);
                return exp1 + exp2;
        }
    else if (e1==1)
    {
        exp2 = exp2 + 45;
        if (D%2==0)
            {
                exp1= ceil(exp1 + D/200.0);
            }
         else
            {
                exp1= ceil(exp1 - D/100.0);
            }
                 exp1 = lamtronexp(exp1);
                 exp2 = lamtronexp(exp2);
                return exp1 + exp2;
    }
    else if (e1==2)
    {
        exp2 = exp2 + 75;
        if (D%2==0)
            {
                exp1= ceil(exp1 + D/200.0);
            }
         else
            {
                exp1= ceil(exp1 - D/100.0);
            }
                exp1 = lamtronexp(exp1);
                 exp2 = lamtronexp(exp2);
                return exp1 + exp2;
    }
    else if (e1==3)
    {
        exp2 = exp2 + 29 + 45 + 75;
        if (D%2==0)
            {
                exp1= ceil(exp1 + D/200.0);
            }
         else
            {
                exp1= ceil(exp1 - D/100.0);
            }
                exp1 = lamtronexp(exp1);
                 exp2 = lamtronexp(exp2);
                return exp1 + exp2;
    }
    else if (e1>=4 && e1<=19)
    {
        exp2 = ceil(exp2 + (ceil(e1/4.0) + 19));
        exp1 = exp1 - e1;
        exp1 = lamtronexp(exp1);
        exp2 = lamtronexp(exp2);
        return exp1 + exp2;
    }
    else if (e1>=20 && e1<=49)
    {
        exp2 = ceil(exp2 + (e1/9.0) + 21);
        exp1 = exp1 - e1;
        exp1 = lamtronexp(exp1);
        exp2 = lamtronexp(exp2);
        return exp1+ exp2;
    }
    else if (e1>=50 && e1<= 65)
    {
        exp2 = ceil(exp2 + (e1/16.0 +17));
        exp1 = exp1 - e1;
        exp1 = lamtronexp(exp1);
        exp2 = lamtronexp(exp2);
        return  exp1 + exp2;
    }
    else if (e1>=66 && e1<=79)
    {
        exp2 = ceil(exp2 + (e1/4.0 + 19));
        if (exp2>200)
        {
            exp2 = exp2 + (e1/9.0 + 21);
        }
        else
        {
            exp2 = exp2;
        }
        exp1 = exp1 - e1;
        exp1 = lamtronexp(exp1);
        exp2 = lamtronexp(exp2);
        return exp1 + exp2;
    }    
    else if (e1>=80 && e1<=99)
    {
        exp2 = ceil(ceil(exp2 + (e1/4.0 + 19)) + (e1/9.0 +21));
        if (exp2 > 400)
        {
            exp2= ceil(ceil(exp2 + (e1/16.0 + 17))*1.15);
                
        }
        exp1 = lamtronexp(exp1);
        exp2 = lamtronexp(exp2);
        exp1 = exp1 - e1;
        return exp1 + exp2;
    }
       
    
    return exp1 + exp2;
    
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    
    double P1;
    double S=((int(sqrt(EXP1)+0.5))*(int(sqrt(EXP1)+0.5)));
    double P2;
    if (sqrt(EXP1)*sqrt(EXP1)== EXP1)
    {
        P1= 1;
    }
    else if (S< EXP1)
    {
        P1 = 1;
    }
    else if (S> EXP1)
    {
        P1= (((double(((EXP1/S)+80)/123.0)))*100)/100.0;
    }
    int m = M1*0.5;
    int tiendadung =0;

    if (E2%2 != 0)
    {
        while(tiendadung<m)
        {
            if(HP1<200)
            {
                HP1= ceil(HP1*1.30);
                tiendadung=tiendadung+ 150;
                M1=M1-150;

            }
            else
            {
                HP1=ceil(HP1*1.10);
                tiendadung=tiendadung+ 70;
                M1=M1-70;

            }
            if(tiendadung>m)
            goto HHH;
            if(EXP1<400)
            {
                EXP1=ceil(EXP1*1.13);
                tiendadung=tiendadung+200;
                M1=M1-200;
            }
            else
            {
                EXP1=ceil(EXP1*1.13);
                tiendadung=tiendadung +120;
                M1=M1-120;
            }
            if(tiendadung>m)
            goto HHH;
            if(EXP1<300)
            {
                EXP1=ceil(EXP1*0.9);
                tiendadung=tiendadung+100;
                M1=M1-100;
            }
            else
            {
                EXP1=ceil(EXP1*0.9);
                tiendadung=tiendadung+120;
                M1=M1-120;
            }
            if(tiendadung>m)
            goto HHH;
        }
    }

    else if (E2%2 == 0)
    {
                                

            if(HP1<200)
            {
                HP1= ceil(HP1*1.30);
                tiendadung= 150;
                M1=M1-150;
            }
            else
            {
                HP1=ceil(HP1*1.10);
                tiendadung=70;
                M1=M1-70;
            }
            if(M1<0)
            {
                goto HHH;
            }
            if(EXP1<400)
            {
                EXP1=ceil(EXP1*1.13);
                tiendadung=tiendadung+200;
                M1=M1-200;   
            }
            else
            {
                EXP1=ceil(EXP1*1.13);
                tiendadung=tiendadung +120;
                M1=M1-120;
            }
            if(M1<0)
            {
                goto HHH;
            }
            if(EXP1<300)
            {
                EXP1=ceil(EXP1*0.9);
                tiendadung=tiendadung+100;
                M1=M1-100;
            }
            else
            {   
                EXP1=ceil(EXP1*0.9);
                tiendadung=tiendadung+120;
                M1=M1-120;
                
            }

            if(M1<0)
            {
                goto HHH;
            }
    }     
                   
HHH:
    HP1=ceil(HP1*0.83);
    EXP1=ceil(EXP1*1.17);
    
double S2=((int(sqrt(EXP1)+0.5))*(int(sqrt(EXP1)+0.5)));
if (sqrt(EXP1)*sqrt(EXP1)== EXP1)
    {
        P2= 1;
    }
    else if (S2< EXP1)
    {
        P2 = 1;
    }
    else if (S2> EXP1)
    {
        P2= ((double(((EXP1/S2)+80)/123))*100)/100.0;
    }    
                   

///////////con duong 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3;
    double Ptb;
    if (E2>=0 && E2<10)
    {
        P3= P[E2]/100.0;
    }
    else if (E2>=10)
    {
        P3=P[((E2/10)+(E2%10))%10]/100.0;
    }
    
    if (P1&&P2&&P3 == 1)
    {
        EXP1= ceil(EXP1*0.75);
        return EXP1 + HP1 + M1;
    }
    else 
    {
        Ptb = (double((P1+P2+P3)/3.0)*100)/100.0;       
    }
    if (Ptb<0.5)
        {
            HP1= ceil(HP1*0.85);
            EXP1= ceil(EXP1*1.15);
        }
        else
        {
            HP1= ceil(HP1*0.90);
            EXP1= ceil(EXP1*1.20);
        }
           

        
    
    EXP1 = lamtronexp(EXP1);
    HP1 = lamtronhp(HP1);
    M1 = lamtronm(M1);    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int l=0;
    int k=0;
    
    int taximap[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            taximap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taximap[i][j] > 2*E3)
            {
                k++;
            }
            if (taximap[i][j]< -E3)
            {
                l++;
            }
        }       
    }
    int i= k/10 + k%10;
    if (i>=10)
    {
        i= i/10 + i%10;
    }
    else if (i<10)
    {
        i=i;
    }
    int j= l/10 + l%10;
    if (j>=10)
    {
        j= j/10 + j%10;
    }
    else if (j<10)
    {
        j=j;
    }
    int max= taximap[i][j];
    int a= i;
    int b= j;
    while(true)
    {
        a = a+1;
        b= b+1;
        if (a>9)
        {
            a=i;
            b=j;
            break;
        }
        if (b>9)
        {
            a=i;
            b=j;
            break;
        }
        if (taximap[a][b]>max)
        {
            max = taximap[a][b];
        }
    }
    while(true)
    {
        a = a-1;
        b= b-1;
        if (a<0)
        {
            a=i;
            b=j;
            break;
        }
        if (b<0)
        {
            a=i;
            b=j;
            break;
        }
        if (taximap[a][b]>max)
        {
            max = taximap[a][b];
        }
    }
    while(true)
    {
        a = a-1;
        b= b+1;
        if (a<0)
        {
            a=i;
            b=j;
            break;
        }
        if (b>9)
        {
            a=i;
            b=j;
            break;
        }
        if (taximap[a][b]>max)
        {
            max = taximap[a][b];
        }
    }
    while(true)
    {
        a = a+1;
        b= b-1;
        if (a>9)
        {
            a=i;
            b=j;
            break;
        }
        if (b<0)
        {
            a=i;
            b=j;
            break;
        }
        if (taximap[a][b]>max)
        {
            max = taximap[a][b];
        }
    }
    if(abs(taximap[i][j])>max)
    {
        EXP1=EXP1*0.88;
        EXP2=EXP2*0.88;
        HP1=HP1*0.9;
        HP2=HP2*0.9;
        return taximap[i][j];
    }
    else
    {
        EXP1=EXP1*1.12;
        EXP2=EXP2*1.12;
        HP1=HP1*1.10;
        HP2=HP2*1.10;
        return max; 
    }
    return taximap[i][j];
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string backuppass= s;
    size_t pass_len = backuppass.size();
    string backupemail = email;
    size_t email_len = backupemail.find('@');//do dai cua chuoi nam truoc @
    string se = backupemail.substr(0,email_len);//chuoi nam truoc @
    string character = "@#%$!";
    
    ///checkpass
    if(pass_len<8)
    {
        
        return -1;
    }
    else if(pass_len>20)
    {
       
        return -2;
    }
    
    
    if( backuppass.find(se)!= string::npos)
    {
       
        return -(300+ static_cast<int>(backuppass.find(se)));
    }
    for(size_t i=0;i<pass_len;i++)
    {
        if(backuppass[i]==backuppass[i+1]&&backuppass[i]==backuppass[i+2])
        {
           
            return -(400+static_cast<int>(backuppass.find(backuppass[i])));
        }
    }
    if (backuppass.find_first_of("@#%$!")== string::npos)
    {
        
        return -5;
    }
    
    for (size_t idx=0; idx<pass_len;idx++)
    {   
        if(!isdigit(backuppass[idx]) && !islower(backuppass[idx]) && !isupper(backuppass[idx]) && character.find(backuppass[idx]) == string::npos)
        {
           
            return static_cast<int>(backuppass.find(backuppass[idx]));
        }
        else
    {
        return -10;
    }
    }
    
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count=0;
    int max_len =0;
    int arr_pos = 0;
    for(int i =0; i<num_pwds; i++)
    {
        const string & pwd =arr_pwds[i];
        int count = 0;
        int len = pwd.length();   
        for (int j=0;j<num_pwds; j++)
        {
        if(arr_pwds[j]== pwd)
         {
            count=count +1;
         }
        }
        if (count>max_count||(count==max_count && len>max_len))
        {
        max_count=count;
        max_len=len;
        arr_pos=i;
        }
    }
    return arr_pos;
    
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////