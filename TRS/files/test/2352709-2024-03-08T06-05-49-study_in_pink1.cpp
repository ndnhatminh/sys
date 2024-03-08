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
// Kiem tra HP
void checkHP1(int &HP1) {
    HP1=min(max(0,HP1), 666);
}
void checkHP2(int &HP2) {
    HP2=min(max(0, HP2), 666);
}

// Kiem tra EXP
void checkEXP1(int &EXP1) {
    EXP1=min(max(0, EXP1), 600);
}
void checkEXP2(int &EXP2) {
    EXP2=min(max(0, EXP2), 600);
}

// Kiem tra M
void checkM1(int &M1) {
    M1=min(max(0, M1), 3000);
}
void checkM2(int &M2) {
    M2=min(max(0, M2), 3000);
}
// So chinh phuong
float SquareNumber(int &EXP1) {
    float S1 = 0.0;
    int S_smaller = floor(sqrt(EXP1));
    float i=sqrt(EXP1);
    float S_larger = pow(ceil(i), 2);
    return abs(EXP1 - S_smaller*S_smaller) <= abs(EXP1 - S_larger) ? S1=1 : S1=(EXP1 / S_larger + 80) / 123;
}
// Kiem tra 2 ki tu lien tiep giong nhau
int Checktwochar(const char * s) {
    int numcheck=1;//dong nay khac
    int num=strlen(s);
    int count=0;
    for (int i=0;i<=num-1;i++) {
        if (s[i]==s[i+1]) {
            count++;
            if (count==2) {
                numcheck=i-1;
                break;
            }
        }
        else count=0;
    }
    return numcheck;
}
// Kiem tra co ki tu dac biet khong
bool Specialchar(const char *s){
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return true;
        }
    }
    return false;
}
// Nhung TH khac
int Checkchar(const char *s) {
    for(int i = 0; s[i] != '\0'; i++){
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
                return i;
            }
    }
    return 1;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    if (E1<0||E1>99) {
        return -99;
    }
    //case1
    if (E1>=0&&E1<=3) {
         if (E1==0) {
        EXP2=EXP2+29;
        checkEXP2(EXP2);
    }
    else if (E1==1) {
        EXP2=EXP2+45;
        checkEXP2(EXP2);
    }
    else if (E1==2) {
        EXP2=EXP2+75;
        checkEXP2(EXP2);
    }
    else if (E1==3) {
        EXP2=EXP2+29+45+75;
        checkEXP2(EXP2);
    }
    int D=E1*3+EXP1*7;
    if (D%2==0) {
        EXP1=ceil(EXP1+(D*1.0/200));
        checkEXP1(EXP1);
    }
    else if (D%2!=0) {
        EXP1=ceil(EXP1-(D*1.0/100));
        checkEXP1(EXP1);
    }
    
    }
    //case2
    else if (E1>=4&&E1<=99) {
        if (E1>=4&&E1<=19) {
        EXP2=ceil(EXP2+(E1*1.0/4+19));
        checkEXP2(EXP2);
    }
    else if (E1>=20&&E1<=49) {
        EXP2=ceil(EXP2+(E1*1.0/9+21));
        checkEXP2(EXP2);
    }
    else if (E1>=50&&E1<=65) {
        EXP2=ceil(EXP2+(E1*1.0/16+17));
        checkEXP2(EXP2);
    }
    else if (E1>=66&&E1<=79) {
        EXP2=ceil(EXP2+(E1*1.0/4+19));
        checkEXP2(EXP2);
        if (EXP2>200) {
            EXP2=ceil(EXP2+(E1*1.0/9+21));
            checkEXP2(EXP2);
        }
    }
    else if (E1>=80&&E1<=99) {
        EXP2=ceil(EXP2+(E1*1.0/4+19)+ceil((E1*1.0/9+21)));
        checkEXP2(EXP2);
        if (EXP2>400) {
            EXP2=ceil((ceil(EXP2+(E1*1.0/16+17)))*(1.15));
            checkEXP2(EXP2);
        }
    }
    EXP1=EXP1-E1;
    checkEXP1(EXP1);
    }
    
    
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //Way1
    float P1=SquareNumber(EXP1);
    //Way2
    if (E2<0||E2>99) {
        return -99;
    }
    if (E2%2!=0) {  //E le
    float tempM1=M1/2;
    int halfM1=ceil(tempM1);
    while (true) {
            if (HP1<200) {
                float tempHP1=HP1*1.3; 
                HP1=ceil(tempHP1); 
                M1=M1-150;
                checkHP1(HP1); checkM1(M1); checkEXP1(EXP1);
            }
            else {
                float tempHP1=HP1*1.1;
                HP1=ceil(tempHP1); 
                M1=M1-70;
                checkHP1(HP1); checkM1(M1); checkEXP1(EXP1);
            }
            if (M1<halfM1) {break;}
            if (EXP1<400) {
                M1=M1-200; 
            }
            else {
                M1=M1-120; 
            }
            float tempEXP1=EXP1*1.13;
            EXP1=ceil(tempEXP1); 
            checkHP1(HP1); checkEXP1(EXP1); checkM1(M1);
            if (M1<halfM1) {break;}
            if (EXP1<300) {
                M1=M1-100; 
            }
            else {
                M1=M1-120; 
            }
            float temp_EXP1=EXP1*0.9;
            EXP1=ceil(temp_EXP1); 
            checkHP1(HP1); checkEXP1(EXP1); checkM1(M1);
            if (M1<halfM1) {break;}
        }
    float tempHP=HP1*0.83;
    HP1=ceil(tempHP); 
    float tempEXP=EXP1*1.17;
    EXP1=ceil(tempEXP); 
    checkEXP1(EXP1); checkHP1(HP1); checkM1(M1);
    }
    else {  //E chan
            if (HP1<200) {
                HP1=HP1*1.3+0.999;
                M1=M1-150; 
            }
            else {
                HP1=HP1*1.1+0.999;
                M1=M1-70;
            }
            checkEXP1(EXP1); checkHP1(HP1); checkM1(M1);
            if (M1>0) {
            if (EXP1<400) {
                M1=M1-200; 
            }
            else {
                M1=M1-120;
            }
            EXP1=EXP1*1.13+0.999; 
            checkEXP1(EXP1); checkHP1(HP1); checkM1(M1);
        }
            if (M1>0) {
            if (EXP1<300) {
                M1=M1-100; 
            }
            else {
                M1=M1-120; 
            }
            EXP1=EXP1*0.9+0.999; 
            checkEXP1(EXP1); checkHP1(HP1); checkM1(M1);
        }
        HP1=HP1*0.83+0.999;
        EXP1=EXP1*1.17+0.999;
        checkEXP1(EXP1); checkHP1(HP1); checkM1(M1);
    }
    float P2=SquareNumber(EXP1);
    //Way3
    int ArrayP[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int a;
    if (E2>=0&&E2<10) {
        a=E2;
    }
    else {
        int sum=(E2/10)+(E2%10);
        a=sum%10;
    }
    float P3=ArrayP[a]/100.0;
    if (P1==1&&P2==1&&P3==1) {
        EXP1=EXP1*0.75+0.999;
        checkEXP1(EXP1); checkHP1(HP1); checkM1(M1);
    }
    else {
        float P;
        P=(P1+P2+P3)/3.0;
        if (P<0.5) {
        HP1=HP1*0.85+0.999;
        EXP1=EXP1*1.15+0.999; 
        checkHP1(HP1); checkEXP1(EXP1); checkM1(M1);
    }
    else {
        HP1=HP1*0.9+0.999;
        EXP1=EXP1*1.2+0.999; 
        checkEXP1(EXP1); checkHP1(HP1); checkM1(M1);
    }
        
    }
    checkHP1(HP1); checkEXP1(EXP1); checkM1(M1);
    return HP1 + EXP1 + M1;
}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3<0||E3>99) {
        return -99;
    }
    checkHP1(HP1); checkEXP1(EXP1); checkHP2(HP2); checkEXP2(EXP2);
    int arr[10][10]; int count1=0; int count2=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            arr[i][j]=((E3*j)+(i*2))*(i-j);
            if (arr[i][j]>(E3*2)) {count1++;}
            if (arr[i][j]<(0-E3)) {count2++;}

        }
    }
    while(count1>9){  // Toa do gap nhau
        int donvi1=count1%10;
        int chuc1=count1/10;
        count1=chuc1+donvi1;
    }
    while(count2>9){
        int donvi2=count2%10;
        int chuc2=count2/10;
        count2=chuc2+donvi2;
    }
    int arr1[10][10]; int max=INT_MIN;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            int a=i-j;
            int b=i+j;
            for(int x=0; x<10; x++){
                for (int y=0; y<10; y++){
                    if (x-y==a||x+y==b){
                        if(arr[x][y]>max){
                            max=arr[x][y];
                        }
                    }
                }
            }
            if(max<0){
                max=abs(max);
            }
            arr1[i][j]=max;
            max=INT_MIN;
        }
    }
    if (abs(arr[count1][count2])<=arr1[count1][count2]) {
        EXP1=EXP1*1.12+0.999; checkEXP1(EXP1);
        EXP2=EXP2*1.12+0.999; checkEXP2(EXP2);
        HP1=HP1*1.1+0.999; checkHP1(HP1);
        HP2=HP2*1.1+0.999; checkHP2(HP2);
        return arr1[count1][count2];
    }
    else {
        EXP1=EXP1*0.88+0.999; checkEXP1(EXP1);
        EXP2=EXP2*0.88+0.999; checkEXP2(EXP2);
        HP1=HP1*0.9+0.999; checkHP1(HP1);
        HP2=HP2*0.9+0.999; checkHP2(HP2);
        return arr[count1][count2];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    const char *a=strchr(email, '@');
    int i=a-email;
    char *se=new char[i+1];
    strncpy(se, email, i);
    se[i]='\0';
    int lenS=strlen(s);
    int seCheck;
    const char * sseCheck=strstr(s,se);
    if (sseCheck==NULL) {
        seCheck=-99;
    }
    else {
        seCheck = sseCheck-s;
    } 
    int twochar=Checktwochar(s);
    bool specialchar=Specialchar(s);
    int charcheck=Checkchar(s);

    if (lenS<8) return -1;
    else if (lenS>20) return -2;
    else if (seCheck!=-99) return -(300+seCheck);
    else if (twochar!=1) return -(400+twochar);
    else if (specialchar==false) return -5;
    else if (charcheck!=1) return (charcheck); 
    else return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int len=0; int max=0; int result; int lenMax=1;
    for (int i=0; i<num_pwds; i++) {
        int count=1;
        const char *x=arr_pwds[i];
        len=strlen(x);
        for (int j=0; j<num_pwds; j++) {
            if (i!=j) {
                const char *y=arr_pwds[j];
                if(strcmp(x,y)==0) {
                    count++;                   
                }
            }
        }
        if (count>max||(count==max&&len>lenMax)){
            max=count;
            lenMax=len;
            result=i;
        }
    } 
    return result;
    }
    


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////