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

//thiet lap
void resetexp(int &exp)
{  
    if (exp<0) exp=0;
    if (exp>600) exp=600;
}
  
void resethp(int &hp)
{  
    if (hp<0) hp=0;
    if (hp>666) hp=666;
}

void resetm(int &m)
{  
    if (m<0) m=0;
    if (m>3000) m=3000;
}


//lam tron len
int cceil(float a) { return ceil(a);}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1<0 ) || (e1>99)) return -99;
    resetexp(exp1); resetexp(exp2);
    if ((e1>=0)&&(e1<=3)) 
    {    
            int d=e1*3+exp1*7;
                switch (e1)
            {
            case 0: exp2+=29; resetexp(exp2); break;
            case 1: exp2+=45; resetexp(exp2); break;
            case 2: exp2+=75; resetexp(exp2); break;
            case 3: exp2+=149; resetexp(exp2); break;
            }
            if (d%2==0) {exp1=cceil((double)exp1+d/200.0); resetexp(exp1);}
            else {exp1=cceil((double)exp1-d/100.0); resetexp(exp1);}
    }
    else 
    {
        if ((e1>=4)&&(e1<=19)) 
        {
            exp2=cceil((double)exp2 + e1/4.0 + (double)19); resetexp(exp2);
        }
        else if ((e1>=20)&&(e1<=49))  
        { 
            exp2=cceil((double)exp2 + e1/9.0 + (double)21); resetexp(exp2);
        }
        else if ((e1>=50)&&(e1<=65))  
        { 
            exp2=cceil((double)exp2 + e1/16.0 + (double)17); resetexp(exp2);
        }
        else if ((e1>=66)&&(e1<=79)) 
        { 
            exp2=cceil((double)exp2 + e1/4.0 + (double)19); resetexp(exp2);
            if (exp2>200) 
            {
                exp2=cceil((double)exp2 + e1/9.0 + (double)21); 
                resetexp(exp2);
            } 
        }
        else 
        {
            exp2=cceil((double)exp2 + e1/4.0 + (double)19); resetexp(exp2);
            exp2=cceil((double)exp2 + e1/9.0 + (double)21); resetexp(exp2);
            if (exp2>400) 
            {
                exp2=cceil((double)exp2 + e1/16.0 + (double)17); resetexp(exp2);
                exp2=cceil((double)exp2*1.15); resetexp(exp2);

            }
        }

        exp1-=e1; resetexp(exp1);
    };

    
    return exp1 + exp2;
}



double tinh (int EXP1)
{
    double p;
    int s=round(sqrt(EXP1)) * round(sqrt(EXP1));
    if (EXP1>=s) p=1;
    else p=(80.0 + (double)EXP1/s)/123;
    return p;

}







// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2<0 ) || (E2>99)) return -99;
    resetexp(EXP1); resethp(HP1); resetm(M1);



    const double a=M1/2;
    int sum=0;
    double p1,p2,p3;
    

    //con duong 1
    p1=tinh(EXP1); 
    
    

    // con duong 2
    if ((E2%2)==1)
    {
         while (1)
         {
            if(M1==0) break;
                if (HP1<200) 
                {
                    HP1=cceil(1.3*(double)HP1); resethp(HP1); 
                    M1-=150; resetm(M1);
                    sum+=150;
                    if (sum>a) break;
                }
                else 
                {
                    HP1=cceil(1.1*(double)HP1);   resethp(HP1); 
                    M1-=70;  resetm(M1);
                    sum+=70;  
                    if (sum>a) break;
                }
                
                


                if (EXP1<400) 
                {
                    M1-=200; resetm(M1);
                    sum+=200;  
                    EXP1=cceil((double)EXP1*1.13); resetexp(EXP1);
                    if (sum>a) break;
                }
                else 
                {
                    M1-=120;  resetm(M1);
                    sum+=120;  
                    EXP1=cceil((double)EXP1*1.13); resetexp(EXP1);
                    if (sum>a) break;
                } 
                
                


                if (EXP1<300) 
                {
                    M1-=100; resetm(M1);
                    sum+=100;  
                    EXP1=cceil(0.9*(double)EXP1);  resetexp(EXP1);
                    if (sum>a) break;
                }
                else 
                {
                    M1-=120; resetm(M1);
                    sum+=120;  
                    EXP1=cceil(0.9*(double)EXP1);  resetexp(EXP1);
                    if (sum>a) break;
                }
                
                
         }     
         
        EXP1=cceil((double)EXP1*1.17);
        HP1=cceil((double)HP1*0.83); 
        resethp(HP1); resetexp(EXP1);
        
    }

     
    else 
    {
        
        for (int i=0; i<1;i++)
        {
            if(M1==0) break;
                if (HP1<200) 
            {
                HP1=cceil(1.3*(double)HP1);  resethp(HP1);
                M1-=150;  
                if (M1<=0) { M1=0; break;}
            }
            else 
            {
                HP1=cceil(1.1*(double)HP1);   resethp(HP1);
                M1-=70;  
                if (M1<=0) { M1=0; break;}
            }
             


            if (EXP1<400) 
            {
                M1-=200;  
                EXP1=cceil((double)EXP1*1.13); resetexp(EXP1);
                if (M1<=0) { M1=0; break;}
            }
            else 
            {
                M1-=120;  
                EXP1=cceil((double)EXP1*1.13); resetexp(EXP1);
                if (M1<=0) { M1=0; break;}
            } 
            


            if (EXP1<300) 
            {
                M1-=100; 
                EXP1=cceil((double)EXP1*0.9); resetexp(EXP1);
                if (M1<=0) { M1=0; break;}
            }
            else 
            {
                M1-=120; 
                EXP1=cceil((double)EXP1*0.9); resetexp(EXP1);
                if (M1<=0) { M1=0; break;}
            }
            
            
        }
        EXP1=cceil((double)EXP1*1.17);
        HP1=cceil((double)HP1*0.83); 
        resethp(HP1); resetexp(EXP1);
        

    }
    
    p2=tinh(EXP1);










    //con duong 3
    double p[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    if (E2/10==0) p3=p[E2];
    else 
    {
        int x=E2/10+E2%10;
        p3=p[x%10]; 
    } 
    

    //tong ket
    if ((p1==1)&&(p2==1)&&(p3==1)) 
    {
        EXP1=cceil((double)EXP1*0.75);
    }
    else 
    {
        if (((p1+p2+p3)/3.0)<0.5) 
        {
            HP1=cceil(0.85*(double)HP1);  
            EXP1=cceil((double)EXP1*1.15);
        }
        else 
        {
            HP1=cceil(0.9*(double)HP1);  
            EXP1=cceil((double)EXP1*1.2);
        }
    }
    resetexp(EXP1); resethp(HP1);

 

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    
    if ((E3<0 ) || (E3>99)) return -99;
    resetexp(EXP1);
    resetexp(EXP2);
    resethp(HP1);
    resethp(HP2);
    int dem1=0,dem2=0;
    int a[10][10];
    for (int i=0;i<10;i++)
    {
        for (int j=0; j<10;j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j) ;
            if (a[i][j]>E3*2) dem1++;
            if (a[i][j]<-E3) dem2++;
        }
        
    }

    if (dem1>9) dem1=dem1/10+dem1%10;
    if (dem1>9) dem1=dem1/10+dem1%10;


    if (dem2>9) dem2=dem2/10+dem2%10;
    if (dem2>9) dem2=dem2/10+dem2%10;

    int max=a[dem1][dem2];


    for (int i=0;i<10;i++)
    {
        if (a[dem1+i][dem2-i]>max) max=a[dem1+i][dem2-i];
        
        if (((dem2-i)==0)|| ((dem1+i)==9)) break;
    }

    

    for (int i=0;i<10;i++)
    {
        if (a[dem1-i][dem2+i]>max) max=a[dem1-i][dem2+i];
        
        if (((dem1-i)==0)|| ((dem2+i)==9)) break;
    }


    for (int i=0;i<10;i++)
    {
        if (a[dem1+i][dem2+i]>max) max=a[dem1+i][dem2+i];
        
        if (((dem2+i)==9)|| ((dem1+i)==9)) break;
    }

    for (int i=0;i<10;i++)
    {
        if (a[dem1-i][dem2-i]>max) max=a[dem1-i][dem2-i];
        
        if (((dem2-i)==0)|| ((dem1-i)==0)) break;
    }

    if (abs(a[dem1][dem2])>max) 
    {
        EXP1=cceil(0.88*(double)EXP1);   HP1=cceil(0.9*(double)HP1);
        EXP2=cceil(0.88*(double)EXP2);   HP2=cceil(0.9*(double)HP2);
    }
    else
    {
        EXP1=cceil(1.12*(double)EXP1);   HP1=cceil(1.1*(double)HP1);
        EXP2=cceil(1.12*(double)EXP2);   HP2=cceil(1.1*(double)HP2);
    }
    resetexp(EXP1);
    resetexp(EXP2);
    resethp(HP1);
    resethp(HP2);

    if (abs(a[dem1][dem2])>max) return a[dem1][dem2];
    else return max;
    
    




    
    




    // TODO: Complete this function
    
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // do dai 8 20
    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;

    //kiem tra chua chuoi se khong
    char se[100];
    int dem=0;
    bool x;
    int sci=0;
    if (email[0]==64) return -300;
    for (int i=0; i<strlen(email);i++)
    {
        if (email[i]==64) break;
        else {se[i]=email[i]; dem++; }
        
    }
    
    for (int i=0; i<strlen(s);i++)
    {
        
        if (s[i]==se[0])
        {
            x=true;
            for (int j=0;j<dem;j++)
            {
                
                if (s[i+j]==se[j]) continue;
                else {x=false; break;}
                
            }
            if (x==true) {sci=i; return -(300+sci);} 

        } 
    }
    

    // kiem tra 3 ki tu lien tiep 
    for (int i=0;i<strlen(s);i++)
    {
        if ((s[i]==s[i+1]) && (s[i+1]==s[i+2])) return -(400+i);
    } 
    
    
    // chua it nhat 1 ki tu dac biet
    bool kiemtra=false;
    for (int i=0;i<strlen(s);i++)
    {
        if ( (s[i] == 33) || (s[i] == 35) || (s[i] == 36) || (s[i] == 37) || (s[i] == 64) ) kiemtra=true;
    }
    if (kiemtra==false) return -5;

    // kiem chu ki tu ngoai
    for (int i=0;i<strlen(s);i++)
    {
        if (   ((s[i] >57) && (s[i] <64)) ||
            ((s[i] > 90 ) && (s[i] < 97)) ||
            s[i]>122 ||
            ( (s[i]<48) && (s[i] != 33 ) && (s[i] != 35) && (s[i] != 36) && (s[i] != 37) )   )
        {
            return i;
        }
    }



    return -10;
}    

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    int arr[num_pwds];
    for (int j=0; j<num_pwds; j++) {arr[j]=1;}

    for (int i=0; i<num_pwds; i++)
    {

        for (int j=0; j<num_pwds; j++)
        {
            if (i==j) continue;
            if (strcmp(arr_pwds[i],arr_pwds[j])==0) arr[i]++;   
        }

    }  
    for (int i=0; i<num_pwds; i++)
    {
         for (int k=i-1; k>=0;k--)
        {
            if (strcmp(arr_pwds[i],arr_pwds[k])==0) {arr[i]=0;}
        }
            
    }

    

    int max=0,dem=0;
    for (int i=0; i<num_pwds; i++)
    {
        if (max<arr[i]) {max=arr[i]; }
    } 


    for (int i=0; i<num_pwds; i++)
    {

        if (arr[i]==max)
        {
            
            dem=i;
                for (int j=i+1;j<num_pwds;j++)
            {
                if ((strlen(arr_pwds[j])>strlen(arr_pwds[dem])) && (arr[j]==max)) dem=j;
            }
            break;

        }
         
    }
    

return dem;

    
}