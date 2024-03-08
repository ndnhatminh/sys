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
int checkHP(int HP){
    if (HP > 666) {
        HP = 666;
    } else if (HP < 0) {
        HP = 0;
    }
    return HP;
}

int checkEXP(int EXP){
    if (EXP > 600) {
        EXP = 600;
    } else if (EXP < 0) {
        EXP = 0;
    }
    return EXP;
}

int checkM(int M){
    if (M > 3000) {
        M = 3000;
    } else if (M < 0) {
        M = 0;
    }
    return M;
}

int checkE(int E){
    if (E < 0 || E > 99) {
        return -99;  
    } 
    return E;
}
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int & exp1, int & exp2, int E1) {
    // TODO: Complete this function
    E1=checkE(E1);
    exp1=checkEXP(exp1);
    exp2=checkEXP(exp2);
    float EXP1a= (float)exp1;
    float EXP2a=(float)exp2;
    if ((E1>=0)&&(E1<=3)){
         if(E1==0){
            EXP2a= EXP2a+29;
            EXP2a=checkEXP((int)EXP2a);
        }else if(E1==1){
            EXP2a= EXP2a+45;
            EXP2a=checkEXP((int)EXP2a);
        }else if(E1==2){
            EXP2a= EXP2a+75;
            EXP2a=checkEXP((int)EXP2a);
        }else{
            EXP2a= EXP2a+29+45+75;
            EXP2a=checkEXP((int)EXP2a);
        }
        int D= E1*3+EXP1a*7;
        if((D%2)==0){
            EXP1a= ceil(EXP1a+ D/200.0);
            EXP1a= checkEXP((int)EXP1a);
        }else{
            EXP1a=ceil(EXP1a-D/100.0);
            EXP1a= checkEXP((int)EXP1a);
        }   
    }else{
        if((E1>=4)&&(E1<=19)){
            EXP2a=ceil(EXP2a +E1/4.0+19);
            EXP2a=checkEXP((int)EXP2a);
        }else if((E1>=20)&&(E1<=49)){
            EXP2a=ceil(EXP2a+ E1/9.0+21);
            EXP2a=checkEXP((int)EXP2a);
        }else if((E1>=50)&&(E1<=65)){ 
            EXP2a=ceil(EXP2a + E1/16.0+17);
            EXP2a=checkEXP((int)EXP2a);
        }else if((E1>=66)&&(E1<=79)){
            EXP2a= ceil(EXP2a+ E1/4.0+19);
            EXP2a=checkEXP((int)EXP2a);
            if(EXP2a>200){
                EXP2a=ceil(EXP2a+ E1/9.0+21);
                EXP2a=checkEXP((int)EXP2a);
            }else{
                EXP2a=EXP2a;
            }
        }else{
            EXP2a=ceil(EXP2a+ E1/4.0+19);
            EXP2a=checkEXP((int)EXP2a);
            EXP2a=ceil(EXP2a+ E1/9.0+21);
            EXP2a=checkEXP((int)EXP2a);
            if(EXP2a>400){
                EXP2a=ceil(EXP2a+E1/16.0+17);
                EXP2a=checkEXP((int)EXP2a);
                EXP2a=ceil(EXP2a*1.15);
                EXP2a=checkEXP((int)EXP2a);
            }else{
                EXP2a=EXP2a;
            }
        }EXP1a=EXP1a-E1;
    }
    exp1 =(int)EXP1a;
    exp2 =(int)EXP2a;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    E2=checkE(E2);
    M1=checkM(M1);
    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);
    float HP1b=(float)HP1;
    float EXP1b=(float)EXP1;
    // way 1
    float s1=sqrt(EXP1b);
    int s=(int)s1;
    float p1;
    if(s1<=(s+0.5)){p1=100;
    }else{
        p1=((EXP1b/((s+1)*(s+1)))+80.0)*100.0/123.0;
    }
    // way 2
int m1l=0;
int m1a=M1;
    if((E2%2)==1){
        while(m1l<(0.5*m1a)){
     // eat
    if(m1l<(0.5*m1a)){if(HP1b<200){
        HP1b=ceil(1.3*HP1b);
        HP1b=checkHP((int)HP1b);
        M1=M1-150;
        m1l=m1l+150;
    }else{
        HP1b=ceil(1.1*HP1b);
        HP1b=checkHP((int)HP1b);
        M1=M1-70;
        m1l=m1l+70;
    }}else{;}

    //move
    if(m1l<(0.5*m1a)){if(EXP1b<400){
        M1=M1-200;
        m1l=m1l+200;
    }else{
        M1=M1-120;
        m1l=m1l+120;
    }
    EXP1b= ceil(EXP1b * 1.13);
    EXP1b=checkEXP((int)EXP1b);
    }else{;}

    // meet
    if(m1l<(0.5*m1a)){if(EXP1b<300){
        M1= M1-100;
        m1l=m1l+100;
    }else{
        M1=M1-120;
        m1l=m1l+120;
    }
    EXP1b=ceil(EXP1b*0.9);}else{;}
        }
            HP1b=ceil(HP1b*0.83);
            HP1b=checkHP((int)HP1b);
            EXP1b=ceil(EXP1b*1.17);
            EXP1b=checkEXP((int)EXP1b);
    }else{
        if(M1>0){if(HP1<200){
        HP1b=ceil(1.3*HP1b);
        HP1b=checkHP((int)HP1b);
        M1=M1-150;
    }else{
        HP1b=ceil(1.1*HP1b);
        HP1b=checkHP((int)HP1b);
        M1=M1-70;
    }}else{;}
        if(M1>0){
            if(EXP1b<400){
        M1=M1-200;
    }else{
        M1=M1-120;
    }
    EXP1b=ceil(EXP1b*1.13);
    EXP1b=checkEXP((int)EXP1b);
        }else{;}
        if(M1>0){
            if(EXP1b<300){
        M1= M1-100;
    }else{
        M1=M1-120;
    }
    EXP1b=ceil(EXP1*0.9);
    EXP1b=checkEXP((int)EXP1b);
        }else{;}
            HP1b=ceil(HP1b*0.83);
            HP1b=checkHP((int)HP1b);
            EXP1b=ceil(EXP1b*1.17);
            EXP1b=checkEXP((int)EXP1b);
    }

    float s2=sqrt(EXP1b);
    int sp=(int)s2;
    float p2;
    if(s2<=(sp+0.5)){p2=100;
    }else{
        p2=((EXP1b/((sp+1)*(sp+1)))+80.0)*100.0/123.0;}

    //way 3
    int sx[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float i;
    float E2b=(float)E2;
    if(E2b<10){i=E2b;}else if(E2b==10){i=1;}else{
        i=ceil(E2b/10.0)-1+((int)E2b%10);
        if(i<10){i=i;}else{
            i=(int)i%10;
        }
    }
    int i1=(int)i;
    int p3=sx[i1];
    if((p1==100)&&(p2==100)&&(p3==100)){
        EXP1b=ceil(EXP1b*0.75);
        EXP1b=checkEXP((int)EXP1b);
    }else{
        float p=(p1+p2+p3)/3;
        if(p>=50){
            HP1b=ceil(HP1b*0.9);
            HP1b=checkHP((int)HP1b);
            EXP1b=ceil(EXP1b*1.2);
            EXP1b=checkEXP((int)EXP1b);
        }else{
            HP1b=ceil(HP1b*0.85);
            HP1b=checkHP((int)HP1b);
            EXP1b=ceil(EXP1b*1.15);
            EXP1b=checkEXP((int)EXP1b);
        }
    }

    HP1=(int)HP1b;
    EXP1=(int)EXP1b;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    E3=checkE(E3);
    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);
    HP2=checkHP(HP2);
    EXP2=checkEXP(EXP2);
    float i1=0;
    float j1=0;
    int matran[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            matran[i][j]=((E3*j)+(i*2))*(i-j);
            if(matran[i][j]>(E3*2)){
                i1= i1+1.0;
            }else if(matran[i][j]<(E3*(-1))){
                j1=j1+1.0;
            }else{;}
        }
    }
    float i2=ceil(i1/10.0)-1+((int)i1%10);
    float i3;
    if(i2>10){
        i3=ceil(i2/10.0)-1+((int)i2%10);
    }else{
        if(i2==10){i3=1;}else{
        i3=i2;
    }}

    float j2=ceil(j1/10.0)-1+((int)j1%10);
    float j3;
    if(j2>10){
        j3=ceil(j2/10.0)-1+((int)j2%10);
    }else{
        if(j2==10){j3=1;}else{
        j3=j2;
    }}
    int i3a=(int)i3;
    int j3a=(int)j3;

    int txp=matran[i3a][j3a];//taxi point
    int cpoint=0;
    for(int ia1=i3a, ja1=j3a; (ia1>=0)&&(ja1>=0)&&(ia1<10)&&(ja1<10); ia1++, ja1--){
        if(cpoint>matran[ia1][ja1]){
            // not do
        }else{
            cpoint=matran[ia1][ja1];
        }
    }
    for(int ia1=i3a, ja1=j3a; (ia1>=0)&&(ja1>=0)&&(ia1<10)&&(ja1<10); ia1--, ja1++){
        if(cpoint>matran[ia1][ja1]){
            // not do
        }else{
            cpoint=matran[ia1][ja1];
        }
    }
    for(int ia1=i3a, ja1=j3a; (ia1>=0)&&(ja1>=0)&&(ia1<10)&&(ja1<10); ia1++, ja1++){
        if(cpoint>matran[ia1][ja1]){
            // not do
        }else{
            cpoint=matran[ia1][ja1];
        }
    }
    for(int ia1=i3a, ja1=j3a; (ia1>=0)&&(ja1>=0)&&(ia1<10)&&(ja1<10); ia1--, ja1--){
        if(cpoint>matran[ia1][ja1]){
            // not do
        }else{
            cpoint=matran[ia1][ja1];
        }
    }
    
    float EXP1c=(float)EXP1;
    float EXP2c=(float)EXP2;
    float HP1c=(float)HP1;
    float HP2c=(float)HP2;
    if(abs(txp)>cpoint){
        EXP1c=ceil(EXP1c*0.88);
        EXP2c=ceil(EXP2c*0.88);
        HP1c=ceil(HP1c*0.9);
        HP2c=ceil(HP2c*0.9);
    EXP1=(int)EXP1c;
    EXP2=(int)EXP2c;
    HP1=(int)HP1c;
    HP2=(int)HP2c;
        return txp;
    }else{
        EXP1c=ceil(EXP1c*1.12);
        EXP1c=checkEXP((int)EXP1c);
        EXP2c=ceil(EXP2c*1.12);
        EXP2c=checkEXP((int)EXP2c);
        HP1c=ceil(HP1c*1.1);
        HP1c=checkHP((int)HP1c);
        HP2c=ceil(HP2c*1.1);
        HP2c=checkHP((int)HP2c);
    EXP1=(int)EXP1c;
    EXP2=(int)EXP2c;
    HP1=(int)HP1c;
    HP2=(int)HP2c;
        return cpoint;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char *sei = strchr(email, '@');
    size_t seiindex = sei - email;
    char *se = new char[seiindex + 1];
    strncpy(se, email, seiindex);
    se[seiindex] = '\0';
    // kiem tra chuoi se
    const char *found = strstr(s, se);
    if (found != NULL) {
        return -(300 + (found-s) );
    }
    // do dai chuoi
    if (strlen(s) < 8) {
        return -1; 
    }else if (strlen(s) > 20){
        return -2; 
    }
   // lien tiep
   for (size_t i = 0; i < strlen(s) - 2; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) {
            return -(400 + i + 1);
        }
    }
    //khong co ki tu dac biet
    bool specialchar = false;
    for (size_t i = 0; i < strlen(s); ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            specialchar = true;
            break;
        }
    }
    if (!specialchar) {
        return -5; 
    }
    // mat khau hop le
    for (size_t i = 0; i < strlen(s); ++i) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') ||
              s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return -99;
        }
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int maxpwds = 30;  
    string pwdscount[maxpwds][2];

    int count = 0;
    for (int i = 0; i < num_pwds; i++) {
        bool check = false;
        for (int j = 0; j < count; j++) {
            if (pwdscount[j][0] == arr_pwds[i]) {
                int count1 = stoi(pwdscount[j][1]) + 1;
                pwdscount[j][1] = to_string(count1);
                check = true;
                break;
            }
        }
        if(!check) {
            pwdscount[count][0] = arr_pwds[i];
            pwdscount[count][1] = "1";
            count++;
        }else{;}
    }
    int max_count = 0;
    int max_length = 0;
    int correctpwds = 0;

    for (int i = 0; i < count; i++) {
        int maxpoint = stoi(pwdscount[i][1]);
        if (maxpoint > max_count || (maxpoint == max_count && pwdscount[i][0].length() > max_length)) {
            max_count = maxpoint;
            max_length = pwdscount[i][0].length();
            correctpwds = i;
        }
    }
    return correctpwds;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////