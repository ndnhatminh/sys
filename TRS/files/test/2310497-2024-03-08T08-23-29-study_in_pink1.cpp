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

//xác suất p1, p2, p3.
int p1,p2,p3;
//tính tổng 2 chữ số
void digitsum(int & i){
    int a =i/10;
    int b = i%10;
    i=a+b;     
}

int check(int n, int firstpoint, int lastpoint) {
n = (n < firstpoint) ? firstpoint : (n > lastpoint) ? lastpoint : n;
return n;
}
//tìm số chính phương gần nhất
int square(int & exp1, int & s){
    for (int i=0; i<25;i++){
        if (i*i>=exp1){
            if ((i*i-exp1)>(exp1-(i-1)*(i-1))){
                s=(i-1)*(i-1);
                
            }
            else {
                s=i*i;
                
            }
            break;
        }
    }
    return s;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int firstpoint = 0, lastpoint = 600;
//Complete this function to gain point on task 1
//=========check the input=============
if (e1 < 0 || e1 > 99) {
    return -99;
}
else 
{
    int count=0;
    exp1 = check(exp1, firstpoint, lastpoint);
    exp2 = check(exp2, firstpoint, lastpoint);
    if(e1==0){
        exp2=ceil(exp2+29);
        exp2 = check(exp2, firstpoint, lastpoint);
        int d=3*e1+exp1*7;
        if (d%2==0){
            exp1=ceil(exp1+(float)d/200);
            exp1 = check(exp1, firstpoint, lastpoint);
        } else exp1=ceil(exp1-(float)d/100);
    }
    else if (e1==1){
        exp2+=45;
        exp2 = check(exp2, firstpoint, lastpoint);
        int d=3*e1+exp1*7;
        if (d%2==0){
            exp1=ceil(exp1+(float)d/200);
            exp1 = check(exp1, firstpoint, lastpoint);
        } else exp1=ceil(exp1-(float)d/100);
    }
    else if (e1==2){
        exp2+=75;
        exp2 = check(exp2, firstpoint, lastpoint);
        int d=3*e1+exp1*7;
        if (d%2==0){
            exp1=ceil(exp1+(float)d/200);
            exp1 = check(exp1, firstpoint, lastpoint);
    } else exp1=ceil(exp1-(float)d/100);
    } else if (e1==3){
        exp2=exp2+29+45+75;
        exp2 = check(exp2, firstpoint, lastpoint);
        int d=3*e1+exp1*7;
        if (d%2==0){
            exp1=ceil(exp1+(float)d/200);
             exp1 = check(exp1, firstpoint, lastpoint);
        } else exp1=ceil(exp1-(float)d/100);
    }
    exp1 = check(exp1, firstpoint, lastpoint);
    exp2 = check(exp2, firstpoint, lastpoint);
    if (e1>=4 && e1<=19){
        exp2=ceil(exp2+((float)e1/4+19));
        count+=1;
        exp2 = check(exp2, firstpoint, lastpoint);
        exp1=exp1-e1;
        exp1 = check(exp1, firstpoint, lastpoint);
    }
    else if ( e1>=20 && e1<=49){
        exp2=ceil(exp2+((float)e1/9+21));
        count+=1;
        exp2 = check(exp2, firstpoint, lastpoint);
        exp1=exp1-e1;
        exp1 = check(exp1, firstpoint, lastpoint);
    } else if (e1>=50 && e1<=65){
        exp2=ceil(exp2+((float)e1/16+17));
        count+=1;
        exp2 = check(exp2, firstpoint, lastpoint);
        exp1=exp1-e1;
        exp1 = check(exp1, firstpoint, lastpoint);
    } else if (e1>=66 && e1<=79){
        exp2=ceil(exp2+((float)e1/4+19));
        exp2 = check(exp2, firstpoint, lastpoint);
        if (exp2>200){
            exp2=ceil(exp2+((float)e1/9+21));
            exp2 = check(exp2, firstpoint, lastpoint);
        }
        exp1=exp1-e1;
        exp1 = check(exp1, firstpoint, lastpoint);
    } else if (e1>=80 && e1<=99){
        exp2=ceil(exp2+((float)e1/4+19));
        exp2=ceil(exp2+((float)e1/9+21));
        exp1 = exp1-e1;
        exp1 = check(exp1, firstpoint, lastpoint);
        exp2 = check(exp2, firstpoint, lastpoint);
        if (exp2>400){
            count=3;
             exp2=ceil(exp2+((float)e1/16+17));
             exp2 = check(exp2, firstpoint, lastpoint);
        }
        
    }
    if (count==3){
        exp2=ceil(exp2*1.15);
        exp2 = check(exp2, firstpoint, lastpoint);
    }
    return exp1 + exp2;
}
}

// Task 2
//trên con đường 2 sự kiện 1
void  road2ev1(int & HP1, int & EXP1, int & M1, int E2 ){
    if (HP1<200){
        HP1=(1.3*HP1)+0.999;
        M1=M1-150;
        
    }
    else {
        HP1=(1.1*HP1)+0.999;
        M1=M1-70;
    }  
}
//road 2 sự kiện 2
void road2ev2(int & HP1, int & EXP1, int & M1, int E2 ){
    if(EXP1<400){
        M1=M1-200;
    }
    else M1=M1-120;
    EXP1=(EXP1*1.13)+0.999;
}

//road 2 sự kiện 3
void  road2ev3(int & HP1, int & EXP1, int & M1, int E2 ){
    if (EXP1<300){
        M1=M1-100;
    }
    else {
        M1=M1-120;
    }
    EXP1=(0.9*EXP1)+0.999;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //CON ĐƯỜNG 1
    if (E2 < 0 || E2 > 99) {
        return -99;
    } else {
    int A[10]={32,47,28,79,100,50,22,83,64,11};
    int p1, p2, p3;
    int s1=0,s2=0,s3=0;
    int firstpointE = 0, lastpointE = 600;
    int firstpointH = 0, lastpointH = 666;
    int firstpointM = 0, lastpointM = 3000; 
    EXP1 = check(EXP1, firstpointE, lastpointE);
    M1 = check(M1, firstpointM, lastpointM);
    HP1 = check(HP1, firstpointH, lastpointH);
    int Money=M1;
    square(EXP1,s1);
    if (EXP1>=s1){
        p1=100;
    }
    else p1=(float)((float)(EXP1/s1)+80)/123*100.0+0.999;
    //CON ĐƯỜNG 2
    // road2(HP1, EXP1, M1, E2);
    
    switch (E2%2)
    {
    case 1:
        while(1){
            if (M1<=(0.5*Money)){
                break;
            } 
            road2ev1(HP1,  EXP1, M1,  E2 );
            EXP1 = check(EXP1, firstpointE, lastpointE);
            M1 = check(M1, firstpointM, lastpointM);
            HP1 = check(HP1, firstpointH, lastpointH);        
            if (M1<=(0.5*Money)){
                break;
            } 
            road2ev2(HP1,  EXP1, M1,  E2 );
            EXP1 = check(EXP1, firstpointE, lastpointE);
            M1 = check(M1, firstpointM, lastpointM);
            HP1 = check(HP1, firstpointH, lastpointH); 
            if (M1<=(0.5*Money)){
                break;
            }     
            road2ev3(HP1,  EXP1, M1,  E2 );
            EXP1 = check(EXP1, firstpointE, lastpointE);
            M1 = check(M1, firstpointM, lastpointM);
            HP1 = check(HP1, firstpointH, lastpointH);
            if (M1<=(0.5*Money)){
                break;
            }  
        }
       
    }
     M1 = check(M1, firstpointM, lastpointM);
    switch (E2%2)
    {
    case 0:
        if (M1==0){
            break;
        } 
        road2ev1(HP1,  EXP1, M1,  E2 );
        if (M1==0){
            
            break;
        } 
        EXP1 = check(EXP1, firstpointE, lastpointE);
        M1 = check(M1, firstpointM, lastpointM);
        HP1 = check(HP1, firstpointH, lastpointH);   
        if (M1==0){
            M1=0;
            break;
        }  
        road2ev2(HP1,  EXP1, M1,  E2 );
        EXP1 = check(EXP1, firstpointE, lastpointE);
        M1 = check(M1, firstpointM, lastpointM);
        HP1 = check(HP1, firstpointH, lastpointH);
        if (M1==0){
            M1=0;
            break;
        } 
        road2ev3(HP1,  EXP1, M1,  E2 );
        EXP1 = check(EXP1, firstpointE, lastpointE);
        M1 = check(M1, firstpointM, lastpointM);
        HP1 = check(HP1, firstpointH, lastpointH);
        if (M1==0){
            M1=0;
            break;
        } 
    }
    EXP1=(EXP1*1.17)+0.999;
    HP1=(HP1*0.83)+0.999;
    EXP1 = check(EXP1, firstpointE, lastpointE);
    HP1 = check(HP1, firstpointH, lastpointH);
    square(EXP1,s2);
    if (EXP1>=s2){
        p2=100;
    }
    else p2=(float)((float)(EXP1/s2)+80)/123*100.0+0.999;
    //CON ĐƯỜNG 3
    s3=E2;
    if (E2>9){
        digitsum(s3);
        s3= s3%10;
    } else {
        s3=E2;
    }
    p3=A[s3];
    if (p1==p2 && p2==p3 && p3==p1 && p3==100){
        EXP1=(0.75*EXP1)+0.999;
        EXP1 = check(EXP1, firstpointE, lastpointE);
        
    }
    else {
        int p=((p1+p2+p3)/3.0)+0.999;
        if (p<50){
            HP1=(HP1*0.85)+0.999;
            EXP1=(1.15*EXP1)+0.999;
            EXP1 = check(EXP1, firstpointE, lastpointE);
            HP1 = check(HP1, firstpointH, lastpointH);
        }
        else {
            HP1=(0.9*HP1)+0.999;
            EXP1=(1.2*EXP1)+0.999;
            EXP1 = check(EXP1, firstpointE, lastpointE);
            HP1 = check(HP1, firstpointH, lastpointH);
        }
    }
    return HP1 + EXP1 + M1;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 ||E3>99){
        return -99;
    } else {
    int firstpointE = 0, lastpointE = 600;
    int firstpointH = 0, lastpointH = 666;
    int firstpointM = 0, lastpointM = 3000; 
    EXP1 = check(EXP1, firstpointE, lastpointE);
    HP1 = check(HP1, firstpointH, lastpointH);
    EXP2 = check(EXP2, firstpointE, lastpointE);
    HP2 = check(HP2, firstpointH, lastpointH);
    int a=0,b=0;
    int A[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            A[i][j]=(((E3*j)+(i*2))*(i-j));
            if (A[i][j] >(E3*2)){
                a+=1;
            }
            if (A[i][j]<(-E3)){
                b+=1;
            }
        }
    }
    while (a>9){
        digitsum(a);
    }
    while (b>9){
        digitsum(b);
    }
    int taxi=A[a][b];
    int max=A[a][b];
    for (int m=-9; m<10;m++){
        if(a-m<10 && a-m>=0 && b+m<10 &&b+m>=0){
            if (A[a-m][b+m]>max){
                max = A[a-m][b+m];
            }
        } 
        
    }
    for (int n=-9; n<10;n++){
        if(a+n<10 &&  a+n>=0  && b-n>=0 &&b-n<10){
            if (A[a+n][b-n]>max){
                max=A[a+n][b-n];
            }
        }
    }
    int i;
    if (abs(taxi)>abs(max)){
        EXP1=0.88*EXP1+0.999;
        HP1=0.9*HP1+0.999;
        EXP2=0.88*EXP2+0.999;
        HP2=0.9*HP2+0.999;
        EXP1 = check(EXP1, firstpointE, lastpointE);
        HP1 = check(HP1, firstpointH, lastpointH);
        EXP2 = check(EXP2, firstpointE, lastpointE);
        HP2 = check(HP2, firstpointH, lastpointH);
        return taxi;
    } else {
        EXP1=1.12*EXP1+0.999;
        HP1=1.1*HP1+0.999;
        EXP2=1.12*EXP2+0.999;
        HP2=1.1*HP2+0.999;
        EXP1 = check(EXP1, firstpointE, lastpointE);
        HP1 = check(HP1, firstpointH, lastpointH);
        EXP2 = check(EXP2, firstpointE, lastpointE);
        HP2 = check(HP2, firstpointH, lastpointH);
        return max;
    }
    return i;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s1(s);
    string email1(email);
    int length = email1.length();
    int lengths = s1.length();
    int count=0;
    int dk=0;
    int pos1 = email1.find('@');
    string se = email1.substr(0, pos1);
    size_t pos= s1.find(se);
    if (lengths<8){
        //dk=dk-1;
        return -1;    
    }
    else if (lengths>20){
        //dk=dk-2;
        return -2;      
    }
    else if (pos != string::npos ){
        //dk=dk-(300+pos);
        return -(300+pos);       
    } else 
    if (pos == string::npos){
        for (int i=0; i< lengths; i++ ){
            if (s1[i]==s1[i+1]&&s1[i+1]==s1[i+2]){
                //dk=dk-(400+i);
                return -(400+i);                
            } 
        if (s1[i]==64 || s1[i]==35 || s1[i]==37 || s1[i]==36 || s1[i]==33){
            count+=1;
        } else if ((s[i]>=33&&s[i]<=47) || (s[i]>=58 &&s[i]<=64) || (s[i]>=91 &&s[i]<=96)|| (s[i]>=123 && s[i]<=126)){
            return  i;
            
        }
    }
    if (count==0){       
        dk=dk-5;
        return -5;
    }
    }
    return -10;   
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int freq[30] = {0};
    int length[30] = {0};
    string arr_pwd[num_pwds];
    for (int i=0; i<num_pwds; i++){
        arr_pwd[i]=arr_pwds[i];
    }
    // Duyệt qua mảng và cập nhật bảng băm
    for (int i = 0; i < num_pwds; ++i) {
        int len = arr_pwd[i].length();
        int idx = -1;
        for (int j = 0; j < 30; ++j) {
            if (arr_pwd[i] == arr_pwd[j]) {
                idx = j;
                break;
            }
        }
        if (idx != -1) {
            freq[idx]++;
            length[idx] = len;
        }
    }

    // Tìm mật khẩu đúng
    int max_freq = 0;
    int max_len = 0;
    int correct_idx = -1;

    for (int i = 0; i < 30; ++i) {
        if (freq[i] > max_freq || (freq[i] == max_freq && length[i] > max_len)) {
            max_freq = freq[i];
            max_len = length[i];
            correct_idx = i;
        }
    }

    return correct_idx;
}





////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////