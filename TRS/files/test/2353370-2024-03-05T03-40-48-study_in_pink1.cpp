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
void limitEXP(int exp1, int exp2){
    if(exp1>600) exp1=600;
    if(exp2>600) exp2=600;
    if(exp1<0) exp1=0;
    if(exp2<0) exp2=0;
}
void limitHP(int hp1, int hp2){
    if(hp1>600) hp1=600;
    if(hp2>600) hp2=600;
    if(hp1<0) hp1=0;
    if(hp2<0) hp2=0;
}
void limitM(int m1, int m2){
    if(m1>3000) m1=3000;
    if(m2>3000) m2=3000;
    if(m1<0) m1=0;
    if(m2<0) m2=0;
}
// Task 1

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0 || e1>99) {
     return -99;
 }
    if(exp1>600) exp1=600;
    if(exp2>600) exp2=600;
    if(exp1<0) exp1=0;
    if(exp2<0) exp2=0;
    
     switch(e1) {
        case 0:
        exp2+=29;
        break;
        case 1:
        exp2+=45;
        break;
        case 2:
        exp2+=75;
        break;
        case 3:
        exp2+=29+45+75;
        break;
     }
     if (e1 >= 0 && e1 <= 3) 
     {
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1*1.0 + ((D*1.0) / 200));
        else if (D % 2 != 0) exp1 = ceil(exp1 - ((D*1.0) / 100));
    }

    if (e1 >= 4 && e1 <= 99)
 {
     if (e1 >= 4 && e1 <= 19)
     {
         exp2 = ceil(exp2*1.0 + (e1*1.0 / 4) + 19);
         exp1 = exp1 - e1;
     }
     else if (e1 >= 20 && e1 <= 49) {
         exp2 = ceil(exp2*1.0 + (e1*1.0 / 9) + 21);
         exp1 = exp1 - e1;
     }
     else if (e1 >= 50 && e1 <= 65) {
         exp2 = ceil(exp2*1.0 + (e1*1.0 / 16 + 17));
         exp1 = exp1 - e1;
     }
     else if (e1 >= 66 && e1 <= 79) 
     {
         exp2 = ceil(exp2*1.0 + (e1*1.0 / 4 + 19));
         if (exp2 > 200) exp2 = ceil(exp2*1.0 + (e1*1.0 / 9 + 21));
         exp1 = exp1 - e1;
     }
     else if (e1 >= 80 && e1 <= 99) {
         exp2 = ceil(exp2*1.0 + (e1*1.0 / 4 + 19));
         exp2 = ceil(exp2*1.0 + (e1*1.0 / 9) + 21);
         if (exp2 > 400) {
             exp2 = ceil(exp2*1.0 + (e1*1.0 / 16 + 17));
             exp2 = ceil(exp2 * 1.15);
         }
         if (exp2 > 600) exp2 = 600;
         exp1 = exp1 - e1;
     }
 }
 if(exp1>600) exp1=600;
    if(exp2>600) exp2=600;
    if(exp1<0) exp1=0;
    if(exp2<0) exp2=0;
 
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99) {return -99;}
    if(EXP1>600) EXP1=600;
    if(EXP1<0) EXP1=0;
    if(HP1>666) HP1=666;
    if(HP1<0) HP1=0;
    if(M1>3000) M1=3000;
    if(M1<0) M1=0;
    
    //Road 1
    int S1;
    double P, P1;
    int a1 = sqrt(EXP1);
    int b1 = a1*a1;
    int c1 = (a1+1)*(a1+1);
    if(abs(EXP1-b1) < abs(EXP1-c1)) S1 = b1;
    else S1 = c1;
    if(EXP1 >= S1) P1 = 100;
    else P1 = ((EXP1*1.0/S1 +80)/123.0)*100;
    
    //Road 2
    float H = (0.5*M1);
    int temp=0;
    if(E2 % 2 == 0 && M1>0) {
        if( HP1<200){
            HP1=ceil(HP1*130.0/100);
            M1=M1-150;
        }
        else{
            HP1=ceil(HP1*110.0/100);
            M1=M1-70;
        }
        if(M1>0){
            if(EXP1<400) M1=M1-200; 
            else M1=M1-120;
            EXP1=ceil(EXP1*113.0/100);
        
        if(M1>0){
            if(EXP1<300) M1=M1-100;
            else M1=M1-120;
            EXP1=ceil(EXP1*90.0/100);
        }}
        if(M1<0) M1=0;
    }
    if(E2 % 2 != 0 && M1>0) {
        while(temp<=H){
        if(HP1<200){
            HP1=ceil(HP1*130.0/100);
            M1=M1-150;   
            temp+=150;         
        }
        else {
            HP1=ceil(HP1*110.0/100);
            M1=M1-70;
            temp+=70;
        }
        if(temp>H) break;
        if(EXP1<400){
            M1=M1-200;
            temp+=200;
        }
        else {
            M1=M1-120;
            temp+=120;
        }
        EXP1=ceil(EXP1*113.0/100);
        if(temp>H) break;
        if (EXP1<300) {
            M1=M1-100;
            temp+=100;
        }
        else {
            M1=M1-120;
            temp+=120;
        }
        EXP1=ceil(EXP1*90.0/100);
        if(temp>H) {break;}
        }
}
    HP1=ceil(HP1*83.0/100);
    EXP1=ceil(EXP1*117.0/100);
    int S2;
    double P2;
    int a2 = sqrt(EXP1);
    int b2 = a2*a2;
    int c2 = (a2+1)*(a2+1);
    if(abs(EXP1-b2) < abs(EXP1-c2)) S2 = b2;
    else S2 = c2;
    if(EXP1 >= S2) {P2 = 100;}
    else P2 = ((EXP1/S2 +80)/123.0)*100;

    //Road 3
    int arrayP[10]={32,47,28,79,100,50,22,83,64,11};
    int P3;
    if(E2>=0 && E2<10){
        P3=arrayP[E2];
    }
    if(E2>=10) 
    {
        int sum=(E2%10)+(E2/10);
        int i=sum %10;
        P3=arrayP[i];
    }
    
    //Conclusion
    if(P1==100 && P2==100 && P3==100)
    {
        EXP1=ceil(EXP1*75.0/100);
    }
    else if (P1!=100 || P2!=100 || P3!=100)
    {
        P = (P1+P2+P3)/3.0;
        if(P<50){
        HP1=ceil(HP1*85.0/100);
        EXP1=ceil(EXP1*115.0/100);
        }
        else if(P>=50){
            HP1=ceil(HP1*90.0/100);
            EXP1=ceil(EXP1*120.0/100);
        }
    }
    if(EXP1>600) EXP1=600;
    if(EXP1<0) EXP1=0;
    if(HP1>666) HP1=666;
    if(HP1<0) HP1=0;
    if(M1>3000) M1=3000;
    if(M1<0) M1=0;
    return HP1 + EXP1 + M1;
    }
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 ||E3>99) return -99;
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666;
    if (HP2<0) HP2=0;
    if (HP2>666) HP2=666;
    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
    if (EXP2<0) EXP2=0;
    if (EXP2>600) EXP2=600;

    int matrix[10][10];
    int pos=0, neg=0;
    int A, sumpos, sumneg;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            matrix[i][j]=((E3*j+(i*2))*(i-j));
        }
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(matrix[i][j] > (E3*2)) pos+=1;
            else if(matrix[i][j] < (-E3)) neg+=1;
        }
    }
    sumpos=pos;
    sumneg=neg;
    while(sumpos >= 10) {
        int sum = 0;
        
        while(sumpos > 0) {
            sum += sumpos % 10; 
            sumpos /= 10;
        }
        sumpos = sum;
    }    
    
    while(sumneg >= 10) {
        int sum = 0;
    
        while(sumneg > 0) {
            sum += sumneg % 10; 
            sumneg /= 10; 
        }
        
        sumneg = sum; 
    }

    A=matrix[sumpos][sumneg];
    int max=A;
    while(sumpos>=0 && sumneg<9){
        sumpos--;
        sumneg++;
        if(matrix[sumpos][sumneg] > max) max=matrix[sumpos][sumneg];
    }
    while(sumpos<9 && sumneg>=0){
        sumpos++;
        sumneg--;
        if(matrix[sumpos][sumneg] > max) max=matrix[sumpos][sumneg];
    }
    while(sumpos>=0 && sumneg>=0){
        sumpos--;
        sumneg--;
        if(matrix[sumpos][sumneg] > max) max=matrix[sumpos][sumneg];
    }
    while(sumpos<9 && sumneg<9){
        sumpos++;
        sumneg++;
        if(matrix[sumpos][sumneg] > max) max=matrix[sumpos][sumneg];
    }
    if(abs(A) > max) {
        EXP1=ceil(EXP1*88.0/100);
        HP1=ceil(HP1*90.0/100);
        EXP2=ceil(EXP2*88.0/100);
        HP2=ceil(HP2*90.0/100);
    }
    else
    {
        EXP1=ceil(EXP1*112.0/100);
        HP1=ceil(HP1*110.0/100);
        EXP2=ceil(EXP2*112.0/100);
        HP2=ceil(HP2*110.0/100);
    }
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666;
    if (HP2<0) HP2=0;
    if (HP2>666) HP2=666;
    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
    if (EXP2<0) EXP2=0;
    if (EXP2>600) EXP2=600;
    return A;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string Email = email;
    string S=s;
    string se = Email.substr(0, Email.find("@"));
    int size= strlen(s);
    int sei;
    sei=S.find(se);
    if(size<8) return -1;
    else if(size>20) return -2;
    else if(sei != std::string::npos) return -(300+sei);
    for(int i=0; i<size; i++)
    {
        if(S[i]=S[i+1]=S[i+2]) return -(400+i);
    }
    string A[5] ={"@","#","%","&","!"};
    for(int i=0; i<5; i++)
    {
        if(S.find(A[i]) != std::string::npos) return -5;
    }

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    // TODO: Complete this function
    int maxfreq = 0;
    int maxlen = 0;
    int result = -1;

    for (int i = 0; i < num_pwds; ++i) {
        int freq = 0;
        int len = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) {
                freq++;
            }
        }
        if (freq > maxfreq || (freq == maxfreq && len > maxlen)) {
            maxfreq = freq;
            maxlen = len;
            result = i;
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////