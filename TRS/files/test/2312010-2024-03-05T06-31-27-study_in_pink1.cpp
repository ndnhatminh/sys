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
void check(int& value,char type)
{
  if (value < 0) value = 0;
  else
  {
  switch (type)
  {
    case 'h': if (value>666) value = 666;
    break;
    case 'e': if(value>600) value =600;
    break;
    case 'm': if (value >3000) value =3000;
    
  }
  }
}
// Task 1
    
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1<0 || e1>99) return -99;
    else 
    {
        //Test input
        check(exp1,'e');
        check(exp2,'e');
        if (e1<=3) 
        {
            switch (e1)
            {
                case 0: exp2+=29;
                break;
                case 1: exp2+=45;
                break;
                case 2: exp2+=75;
                break;
                case 3: exp2= exp2+29+45+75;
            }
            int D = e1 * 3 + exp1 * 7;
            if(D%2) exp1=ceil(float(exp1-D/100.0));
            else exp1=ceil(float(exp1+D/200.0));
        }
        else 
        {
            if(e1<=19) exp2 = ceil (float (exp2+e1/4.0+19));
            else if (e1<=49) exp2 = ceil (float (exp2+e1/9.0+21));
            else if (e1<=65) exp2 = ceil (float (exp2+e1/16.0+17));
            else if (e1<=79)
            {
                exp2 = ceil (float (exp2+e1/4.0+19));
                if (exp2>200) exp2 = ceil (float (exp2+e1/9.0+21));
            }
            else 
            {
                exp2 = ceil (float (exp2+e1/4.0+19));
                exp2 = ceil (float (exp2+e1/9.0+21));
                if (exp2>400) 
                 {
                    exp2 = ceil (float (exp2+e1/16.0+17));
                    exp2 = ceil (float (exp2*1.15));
                }
            }
            exp1-=e1;
        }
    check(exp1,'e');
    check(exp2,'e');
    return exp1 + exp2;
    }
}
//Find P
double findP(int EXP1)
{
 
    if(EXP1==0) return 1;
    else 
    {
        if (EXP1 != ((int (sqrt(EXP1)))*int (sqrt(EXP1))))
            {
                if (((EXP1-(int(sqrt(EXP1)))*(int(sqrt(EXP1))))-((int(sqrt(EXP1))+1)*(int(sqrt(EXP1))+ 1)-EXP1))>0)
                return ((EXP1/((int(sqrt(EXP1)))*(int(sqrt(EXP1))))+80.0)/123.0);
                else return 1;
            }
        else return 1;
    }
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if (E2<0 || E2>99) return -99;
else
{

    // Test input
    check (EXP1,'e');
    check (HP1, 'h');
    check (M1, 'm');
    
    // Road 1
    double P1=findP(EXP1);
    //Road 2
    if (E2%2)
    {
        float temp=M1/2.0;
    
        while (1)
            {
                //1
                if ( HP1 < 200 ) 
                {
                    HP1 = ceil(float(HP1*1.3));
                    M1-=150;
                }
                else 
                {
                    HP1 = ceil(float(HP1*1.1));
                    M1 -=70;
                }
                check(HP1,'h');
                check(M1,'m');

                if(M1<temp) break;

                //2
                if (EXP1 < 400) M1-=200;
                else M1-=120;
                EXP1= ceil(float(EXP1*1.13));
                check(EXP1,'h');
                check(M1,'m');
                
                if (M1<temp) break;

                //3
                if (EXP1<300) M1-=100;
                else M1-=120;
                EXP1 = ceil(float(EXP1*0.9));
                check(M1,'m');
                if(M1<temp) break;
        }
        HP1= (1-0.17) * HP1 +0.9999;
        EXP1=(1+0.17) * EXP1 +0.9999;
        check(EXP1,'e');
    }
    else
    {
        //1
        if(M1>0)
        {
            if ( HP1 < 200 ) 
            {
                HP1 = ceil(float(HP1*1.3));
                M1-=150;
            }
            else 
            {
                HP1 = ceil(float(HP1*1.1));
                M1 -=70;
            }
            check(HP1,'h');
            check(M1,'m');
        

            //2
            if(M1>0)
            {
                if (EXP1 < 400) M1-=200;
                else M1-=120;
                EXP1= ceil(float(EXP1*1.13));
                check(EXP1,'e');
                check(M1,'m');

                //3
                if(M1>0)
                {
                    if (EXP1<300) M1-=100;
                    else M1-=120;
                    EXP1 = ceil(float(EXP1*0.9));
                    check(EXP1,'e');
                    check(M1,'m');
                }
            }
        }
        HP1= (1-0.17) * HP1 +0.9999;
        EXP1=(1+0.17) * EXP1 +0.9999;
        check(EXP1,'e');
    }
     //FIND P2
    double P2=findP(EXP1);

    //Road 03
    double P3[10]={32,47,28,79,100,50,22,83,64,11};
    if(E2>10) E2 = (E2/10+E2%10)%10;
    if (P1==1 && P2==1 && P3[E2]/100==1) EXP1=ceil(float(EXP1*0.75));
    else 
    {
        if ((P1+P2+(P3[E2])/100)/3 < 0.5)
        {
            HP1= ceil(float(0.85*HP1));
            EXP1=ceil(float(1.15*EXP1));
           
        }
        else
        {
           HP1= ceil(float(0.9*HP1));
           EXP1=ceil(float(1.2*EXP1)); 
        }
      check(EXP1,'e');

    }
    return HP1 + EXP1 + M1;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    if(E3<0 || E3>99) return -99;
    {
        check (EXP1,'e');
        check (HP1, 'h');
        check (EXP2,'e');
        check (HP2, 'h');
        
        int map[10][10];
        int x=0,y=0,i,j; 
        for (i=0;i<10;i++)
        {
            for(j=0; j<10;j++)
            {
                map[i][j] =  ((E3 * j) + (i * 2)) * (i - j) ;
                if(map[i][j]>(E3*2)) x++;
                if(map[i][j]<(-E3))  y++;
                
            }
        }
        while(x>=10) x= x/10 + x%10;
        while(y>=10) y= y/10 + y%10;
        int grade=map[x][y];
        //FIND WATSON AND SHERLOCK'S GRADE
        for(i=x,j=y;i>=0&&j>=0;i--,j--)
        {
            if (map[i][j]>grade) grade = map[i][j];
        }
        for(i=x,j=y;i<10&&j<10;i++,j++)
        {
            if (map[i][j]>grade) grade = map[i][j];
        }
        for(i=x,j=y;i<10&&j>=0;i++,j--)
        {
            if (map[i][j]>grade) grade = map[i][j];
        }
        for(i=x,j=y;i>=0&&j<10;i--,j++)
        {
            if (map[i][j]>grade) grade = map[i][j];
        }
        grade=abs(grade);
        //COMPARE WATSON AND SHERLOCK'S GRADE AND THE TAXI'S GRADE
            if(abs(map[x][y])<=grade)
            {   EXP1=ceil(float(EXP1*1.12));
                EXP2=ceil(float(EXP2*1.12));
                HP1=ceil(float(HP1*1.1));
                HP2=ceil(float(HP2*1.1));
                check(EXP1,'e');
                check(EXP2,'e');
                check(HP1,'h');
                check(HP2,'h');
            }
            else{
                grade=map[x][y];
                EXP1=ceil(float(EXP1*0.88));
                EXP2=ceil(float(EXP2*0.88));
                HP1=ceil(float(HP1*0.9));
                HP2=ceil(float(HP2*0.9));
            }
      
        return grade;
    }
}

// TASK 4

//check if Unallowed characters appear in the password
int UnallowedChars(string s)
{
    int pos;
    for(pos=0;pos<s.length();pos++)
    {
        if(!((s[pos]>='0' && s[pos]<='9')||(s[pos]>='@' && s[pos]<='Z')||(s[pos]>='a' &&s[pos]<='z')||(s[pos]>='#'&&s[pos]<='%')||(s[pos]=='!'))) 
        return pos;
    }
    return -1;
    
}

//check if the password contains more than 2 consecutive and identical characters
int CandIChars(string s)
{
    int pos=0;
    for(pos=0; pos<s.length()-2;pos++)
    {
        if(s[pos]==s[pos+1] && s[pos]==s[pos+2])
        {
            return pos;
        }
    }
   return -1;

}
//check if there is no special character in the password
bool SpeChar(string s)
{
    for (int i=0;i<s.length();i++)
    {
        if(s[i] =='#' || s[i] =='%'||s[i] =='!'||s[i]=='@'||s[i]=='$') return 0;
    }
    return 1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pw=s,se=email;
    se.erase (se.find("@"));
    if (pw.length()<8) return -1;
        else if (pw.length()>20) return -2;
            else if (pw.find(se)< pw.length()) return -( 300 + pw.find(se) );
                else if (CandIChars(pw)>=0) return -(400+CandIChars(pw));
                    else if (SpeChar(pw)) return -5;
                        else if(UnallowedChars(pw)>=0) return UnallowedChars(pw);
                            else return -10;
    
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int num_Occur[100]={0};
    // Determine the maximum number of occurrances of an element in the array arr_pwds[]
    int maxOccur=0, maxLength=0;
    for (int i=0; i<num_pwds;i++)
    {
        for (int j=0;j<num_pwds;j++)
        {
            if (strcmp(arr_pwds[j],arr_pwds[i])==0) num_Occur[i]++;
        }
       
        if(num_Occur[i]>maxOccur) maxOccur=num_Occur[i];
    }
    //Determine the element that meets the requirements
    for(int i=0;i<num_pwds;i++)
    {
        if(num_Occur[i]==maxOccur)
        {
            if(strlen(arr_pwds[i])>maxLength) maxLength= strlen(arr_pwds[i]);
        }
    }

    for(int i=0;i<num_pwds;i++)
    {
        if((num_Occur[i]==maxOccur) && strlen(arr_pwds[i])==maxLength ) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////