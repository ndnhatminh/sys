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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
    if (e1 < 0 || e1 > 99) return -99;
    else if ((e1<=3) && (e1>=0)){
        if (e1==0){
            exp2=exp2+29;
        }
        else if (e1==1){
            exp2=exp2+45;
        }
        else if (e1==2){
            exp2=exp2+75;
        }
        else{
            exp2=exp2+29+45+75;
        }
        D=e1*3+exp1*7;
        if (D%2!=0){
            exp1=ceil(exp1-((double)D/100));
        }
        else if (D%2==0){
            exp1=ceil(exp1+((double)D/200));
        }
        if((exp1>=600)){
            exp1=600;
        }
        if ((exp2>=600)){
            exp2=600;
        }
    }   
    else if ((e1<=99) && (e1>=4)){
        if ((e1<=19) && (e1>=4)){
            exp2=ceil(exp2+((double)e1/4)+19); 
        }
        else if ((e1<=49) && (e1>=20)){
            exp2=ceil(exp2+((double)e1/9)+21);
        }
        else if ((e1<=65) && (e1>=50)){
            exp2=ceil(exp2+((double)e1/16)+17);
        }
        else if ((e1<=79) && (e1>=66)){
            exp2=ceil(exp2+((double)e1/4)+19);
            if (exp2>200){
                exp2=ceil(exp2+((double)e1/9)+21);
            }
        }
         else if ((e1<=99) && (e1>=80)){
            exp2=ceil(exp2+((double)e1/4)+19);
            exp2=ceil(exp2+((double)e1/9)+21);
            if (exp2>400){
                exp2=ceil(exp2+((double)e1/16)+17);
                exp2=ceil(exp2*((double)115/100));
            }

        }
        if (exp1>e1){
            exp1=exp1-e1;
        }
        else if (exp1<e1){
            exp1=0;
        }
        if((exp1>=600)){
            exp1=600;  
        }
        if ((exp2>=600)){
            exp2=600;
        }
    }    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0)
        return -99;
    int Sochinhphuong;
    int CanbachaiEXP1;
    int T;
    int F;
    double P1; 
    double P2;
    double G=(double)M1*10.0/20;
    //P1
    CanbachaiEXP1=floor((double)sqrt(EXP1));
    F=EXP1-(CanbachaiEXP1*CanbachaiEXP1);
    T=((CanbachaiEXP1+1)*(CanbachaiEXP1+1))-EXP1;
    if (F<T){
        Sochinhphuong=CanbachaiEXP1*CanbachaiEXP1;
    }
    else if (F>T){
        Sochinhphuong=(CanbachaiEXP1+1)*(CanbachaiEXP1+1);
    }
    if (EXP1>=Sochinhphuong){
        P1=100;
    }
    else if (EXP1<Sochinhphuong){
        P1=(((double)EXP1/Sochinhphuong+80.0)/123)*100.0;
    }
    //Path 2
    //odd
    if (E2%2!=0){
        while(M1>=G){
            //event 1
            if (M1<G || M1==0){
                break;
            }
            if (HP1<200){
                HP1=ceil((double)HP1*130.0/100);
                M1=M1-150;
            }
            else if (HP1>=200){
                HP1=ceil((double)HP1*110.0/100);
                M1=M1-70;
            }
            if (M1>3000){
                M1=3000;
            }
            if (M1<0){
                M1=0;
            }
            if (HP1>666){
                HP1=666;
            }
            if (HP1<0){
                HP1=0;
            }
            if (M1<G|| M1==0){
                break;
            }

            //event 2
            if (EXP1<400){
                M1=M1-200;
                EXP1=ceil((double)EXP1*113.0/100);
            }
            else if ((EXP1>=400)){
                M1=M1-120;
                EXP1=ceil((double)EXP1*113.0/100);
            }
            if (M1>3000){
                M1=3000;
            }
            else if (M1<0){
                M1=0;
            }
            if (EXP1>600){
                EXP1=600;
            }
            else if (EXP1<0){
                EXP1=0;
            }
            if (M1<G|| M1==0)
                break;
            

            //event 3
            if(M1>G){
                if (EXP1>=300){
                    M1=M1-120;
                }
                else if (EXP1<300){
                    M1=M1-100;
                }
                EXP1=ceil((double)EXP1*90.0/100);
            }    
            if (M1>3000){
                M1=3000;
            }
            if (M1<0){
                M1=0;
            }
            
            if (EXP1>600){
                EXP1=600;
            }
            if (EXP1<0){
                EXP1=0;
            }
            if (M1<G || M1==0)
                break;
        }
     
        
        HP1=ceil((double)HP1*(83.0/100.0));
        if (HP1>666){
            HP1=666;
        }
        if (HP1<0){
            HP1=0;       
        }    

        EXP1=ceil((double)EXP1*(117.0/100));
        if (EXP1>600){
            EXP1=600;
        }
        if (EXP1<0){
            EXP1=0;       
        }
    }    
    //even
    else if(E2%2==0){
        //event 1
        if (M1>0){
            if (HP1<200){
            HP1=ceil((double)HP1*13.0/10);
            M1=M1-150;
            }
            else{
            HP1=ceil((double)HP1*11.0/10);
            M1=M1-70;
            }
        }
        if (M1>3000){
            M1=3000;
        }
        if (M1<0){
            M1=0;
        }
        if (HP1>666){
            HP1=666;
        }
        else if (HP1<0){
            HP1=0;
        }
        

        //event 2  
        if (M1>0){

            if (EXP1<400 ){
                M1=M1-200;
            
            }
            else if (EXP1>=400 && M1>0){
                M1=M1-120;
            
            }
            EXP1=ceil((double)EXP1*113.0/100);
        }    
            
        if (M1>3000){
            M1=3000;
        }
        else if (M1<0){
            M1=0;
        }
        if (EXP1>600){
            EXP1=600;
        }
        else if (EXP1<0){
            EXP1=0;
        }

        //event 3
        if (M1>0){
            if (EXP1<300){
                M1=M1-100;
            }  
            else{
                M1=M1-120;
            }
            EXP1=ceil((double)EXP1*9.0/10);
        }    
        if (M1>3000){
            M1=3000;
        }
        else if (M1<0){
            M1=0;
        }
            
        if (EXP1>600){
            EXP1=600;
        }
        if (EXP1<0){
            EXP1=0;       
        }
        //walk
        HP1=ceil((double)HP1*(83.0/100));
        if (HP1>666){
            HP1=666;
        }
        else if (HP1<0){
            HP1=0;
        }
        EXP1=ceil((double)EXP1*(117.0/100));
        if (EXP1>600){
            EXP1=600;
        }
        if (EXP1<0){
            EXP1=0;       
        }
    }
        // P2
    CanbachaiEXP1=floor((double)sqrt(EXP1));
    F=EXP1-(CanbachaiEXP1*CanbachaiEXP1);
    T=((CanbachaiEXP1+1)*(CanbachaiEXP1+1))-EXP1;    
    if (F<T){
        Sochinhphuong=CanbachaiEXP1*CanbachaiEXP1;
    }
    else if (F>T){
        Sochinhphuong=((CanbachaiEXP1+1)*(CanbachaiEXP1+1));
    }
    if (EXP1>=Sochinhphuong){
        P2=100;
    }
    else if (EXP1<Sochinhphuong){
        P2=(((double)EXP1/Sochinhphuong+80.0)/123)*100.0;
    }
    //path 3
    int P3;
    int P[]= {32,47,28,79,100,50,22,83,64,11};
    int i;
    if (E2<10){
        i=E2;
        P3=P[i];
    }
    else if (E2>=10){
        i=(E2%10+(E2/10))%10;
        P3=P[i];
    }
    //final
    if ((P1==100)&&(P2==100)&&(P3==100)){
        EXP1=ceil((double)EXP1*(75.0/100));
    }
    else{
        float C;
        C=ceil((double)(P1+P2+P3)*1.0/3);
        if (C<50){
            HP1=ceil((double)HP1*(85.0/100));
            EXP1=ceil((double)EXP1*(115.0/100));
        }
        else if (C>=50){
            HP1=ceil((double)HP1*(90.0/100));
            EXP1=ceil((double)EXP1*(120.0/100));
        }
    }    
    if (EXP1>600){
        EXP1=600;
    }
    if (EXP1<0){
        EXP1=0;       
    }
    if (HP1>666){
        HP1=666;
    }
    else if (HP1<0){
        HP1=0;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0)
        return -99;
    int matrix[10][10];
    int bigger=0;
    int smaller=0;
    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            matrix[i][j]=((E3*j)+(i*2))*(i-j);
            if (matrix[i][j]>2*E3){
                bigger=bigger+1;
            }
            else if(matrix[i][j]<-E3){
                smaller=smaller+1;
            }
        }
    }
    int i;
    int j;
    i=((bigger%10)+(bigger/10));
    j=((smaller%10)+(smaller/10));
    if(i<10){
        i=i;
    }
    else if (i>=10){
        i=(i%10)+(i/10);
    }
    if(j<10){
        i=i;
    }
    else if (j>=10){
        j=(j%10)+(j/10);
    }
    int taxiPoint=matrix[i][j];
    int max=matrix[i][j];
    
    //point sherlock
    int k=i;
    int y=j;
    while(k>0 && y>0){
        if(matrix[k][y]>max){
            max=matrix[k][y];
        }
        k--;
        y--;
    }
    k=i;
    y=j;
    while(k>0 && y<10){
        if(matrix[k][y]>max){
            max=matrix[k][y];
        }
        k--;
        y++;
    }
    k=i;
    y=j;
    while(k<10 && y<10){
        if(matrix[k][y]>max){
            max=matrix[k][y];
        }
        k++;
        y++;
    }
    k=i;
    y=j;
    while(k<10 && y>0){
        if(matrix[k][y]>max){
            max=matrix[k][y];
        }
        k++;
        y--;
    }
    int sherlockPoint = max;
    if (abs(taxiPoint)>sherlockPoint){
        sherlockPoint=taxiPoint;
        EXP1=ceil((double)EXP1*88.0/100);
        HP1=ceil((double)HP1*90.0/100);
        EXP2=ceil((double)EXP2*88.0/100);
        HP2=ceil((double)HP2*90.0/100);
    }
    else{
        sherlockPoint=max;
        EXP1=ceil((double)EXP1*112.0/100);
        HP1=ceil((double)HP1*110.0/100);
        EXP2=ceil((double)EXP2*112.0/100);
        HP2=ceil((double)HP2*110.0/100);
    }
    if (HP1>666){
        HP1=666;
    }
    else if (HP1<0){
        HP1=0;
    }
    if (HP2>666){
        HP2=666;
    }
    else if (HP2<0){
        HP2=0;
    }
    if (EXP1>600){
        EXP1=600;
    }
    else if (EXP1<0){
        EXP1=0;
    }
    if (EXP2>600){
        EXP2=600;
    }
    else if (EXP2<0){
        EXP2=0;
    }


    return sherlockPoint;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string e(email);
    string se;
    int index = 0;
    char character;
    while ((character = e[index++]) != '@') {
        se = se + character;
    }
    if (strlen(s)<8){
        return -1;
    }
    if (strlen(s)>20){
        return -2;
    }
    string pass(s);
    size_t f = pass.find(se);
    int g=f;
    if (f != string::npos) {
        return -300 - g;
    }
    int longs = pass.length();
    for (size_t i = 0; i < longs - 2; i++){
        if (pass[i] == pass[i+1] && pass[i+1] == pass[i+2]){
            return -400 - i;
        }
    }
    string specialcharacter("@%$!#");
    bool special = 0;
    for (char character : pass) {
        if (specialcharacter.find(character) != string::npos) {
            special = 1;
            break;
        }
    }
    if (special==0){
        return -5;
    }
    for (int i = 0; i < longs; i++) {
        if (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!' && isalnum(s[i])==0) {
            return i;
        }
    }
    return -10;
    
}



// Task 5
int sosanh(const char* a, const char* b) {
    int k = 0;
    do {
        if (a[k] != b[k]) {
            return 0;
        }
        k=k+1;
    } while (a[k] != '\0' && b[k] != '\0');

return a[k] == '\0' && b[k] == '\0';
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count = 0; 
    int dodai = 0;
    int vitri = 0;

    int i = 0;
    while (i < num_pwds) {
        const char* matkhau = arr_pwds[i];
        int matkhaulen = strlen(matkhau);

        int kiemtra = 0;
        int j = 0;
        while (j < i) {
            if (sosanh(arr_pwds[j], matkhau)) {
                kiemtra = 1;
                break;
            }
            j++;
        }

        int countpass = 0;
        j = i;
        while (j < num_pwds) {
            if (sosanh(arr_pwds[j], matkhau)) {
                countpass = countpass + 1;
            }
            j++;
        }

        if (countpass > count || (countpass == count && matkhaulen > dodai)) {
            count = countpass;
            dodai = matkhaulen;
            vitri = i;
        }
        i++;
    }
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////