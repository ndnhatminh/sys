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
    if(e1 <0 || e1>99){
        return -99;
    }
    if(exp1<0){
        exp1= 0;    
    }
    if(exp1>600){
        exp1= 600;    
    }
    if(exp2<0){
        exp2= 0;    
    }
    if(exp2>600){
        exp2= 600;    
    }
    //Kiem tra dau vao
    if(e1 == 0||e1==1||e1==2||e1==3){
    if(e1 == 0){
        exp2 += 29;
        if(exp2>600){
        exp2= 600;    
    }
    }
    if(e1 == 1){
        exp2 += 45;
        if(exp2>600){
        exp2= 600;    
    }
    }
    if(e1 == 2){
        exp2 += 75;
        if(exp2>600){
        exp2= 600;    
    }
    }
    if(e1 ==3){
        exp2 += 29+45+75;
        if(exp2>600){
        exp2= 600;    
    }
    }
    //
    int D = e1*3+exp1*7;
    if(D%2 == 0){
        exp1 = ceil(exp1 + float(D/200));
        if(exp1>600){
        exp1= 600;    
    }
    }
    else{
        exp1 = ceil(exp1 - float(D/100));
        if(exp1>600){
        exp1= 600;    
    }
    if(exp1<0){
        exp1= 0;    
    }
    }
    }
    //
    if(e1>=4 && e1<=19){
        exp2 = ceil(exp2 + (float)e1*0.25 +19);
        exp1 -= e1;
        if(exp1>600){
        exp1= 600;    
    }
    if(exp1<0){
        exp1= 0;    
    }
    if(exp2>600){
        exp2 = 600;
    }
    }
    if(e1>=20 && e1<=49){
        exp2 = ceil(exp2 + (float)e1/9 +21);
        exp1 -= e1;
         if(exp1>600){
        exp1= 600;    
    }
    if(exp1<0){
        exp1= 0;    
    }
    if(exp2>600){
        exp2 = 600;
    }
    }
    if(e1>=50 && e1<=65){
        exp2 = ceil(exp2 + (float)e1/16 +17);
        exp1 -= e1;
         if(exp1>600){
        exp1= 600;    
    }
    if(exp1<0){
        exp1= 0;    
    }
    if(exp2>600){
        exp2 = 600;
    }
    }
    //
    if(e1>=66 && e1<=79){
        exp2 = ceil(exp2 + (float)e1/4 +19);
    if(exp2>600){
        exp2 = 600;
    }
        if(exp2>200){
            exp2 = ceil(exp2 + (float)e1/9 + 21);      
    if(exp2>600){
        exp2 = 600;
    }
        }
        exp1 -= e1;
         if(exp1>600){
        exp1= 600;    
    }
    if(exp1<0){
        exp1= 0;      
    }
    }
    //
    if(e1>=80 && e1<=99){
        exp2 = ceil(exp2 + (float)e1/4 +19);      
    if(exp2>600){
        exp2 = 600;
    }
        exp2 = ceil(exp2 + (float)e1/9 +21);     
    if(exp2>600){
        exp2 = 600;
    }
        if(exp2 >400){
            exp2 = ceil(exp2 + (float)e1/16 + 17);     
    if(exp2>600){
        exp2 = 600;
    }
            exp2 = ceil(exp2+float((exp2*15)/100));
    if(exp2>600){
        exp2 = 600;
    }
    }
        exp1 -= e1;
    if(exp1<0){
        exp1= 0;    
    }
    }
    

    
    return exp1 + exp2;
}

// Task 2
//1. Ham tinh so chinh phuong gan nhat
int scp(int number) {
    if (number < 0) {
        return -1; 
    }

    int lowerRoot = static_cast<int>(std::sqrt(number));
    int upperRoot = lowerRoot + 1;

    int lowerSquare = lowerRoot * lowerRoot;
    int upperSquare = upperRoot * upperRoot;

    if (std::abs(number - lowerSquare) <= std::abs(number - upperSquare)) {
        return lowerSquare;
    } else {
        return upperSquare;
    }
}
//Ham tinh P1
double tinhP1(int &EXP1){
    int S= scp(EXP1);
    if(EXP1>=S){
       return 100; 
    }
    else{
        return ((EXP1 / static_cast<double>(S) + 80) / 123)*100;
    }
}
//Ham tinh P3
double tinhP3(int & E2){
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        if (E2 < 10) {
            return P[E2];
        } else {
            return P[(E2%10+E2/10)%10];
        }
    }

//Ham mo ta con duong 2
//1. Ham mo ta hanh dong mua thuc an va nuoc duong
void hd1(int &HP1, int &M1, int & tiensd){
    if(HP1<200){
        HP1 = ceil(HP1 + float(30*HP1)/100);
        M1-=150;
        tiensd +=150;
        if(HP1>666){
            HP1=666;
        }
        if(M1<0){
            M1=0;
        }
    }
        else{
            HP1 = ceil(HP1 + float(10*HP1)/100);  
            M1-=70;
             tiensd +=70;
        if(HP1>666){
            HP1=666;
        }
        if(M1<0){
            M1=0;
        }
        }
    
}
//2. Ham mo ta hanh dong di taxi hoac xe ngua
void hd2(int& EXP1, int& M1, int & tiensd){
    if(EXP1<400){
        EXP1= ceil(EXP1 + float(0.13*EXP1));
        M1-= 200;
        tiensd +=200;
        if(EXP1>600){
            EXP1 =600;
        }
        if(M1,0){
            M1=0;
        }
    }
    else{
        EXP1= ceil(EXP1 + float(0.13*EXP1));
        M1-= 120;
        tiensd +=120;
        if(EXP1>600){
            EXP1 =600;
        }
        if(M1<0){
            M1=0;
        }
    }
    
}
//Ham mo ta hanh dong hoi nguoi vgc
void hd3(int& EXP1, int& M1, int & tiensd){
    if(EXP1<300){
        M1-=100;
        tiensd +=100;
        if(M1<0){
            M1=0;
        }
    }
    else{
        M1-=120;
        tiensd +=120;
        if(M1<0){
            M1=0;
        }
    }
    EXP1 = ceil(EXP1 - float((10*EXP1)/100));
    if(EXP1<0){
       EXP1 = 0; 
    }
}
//Ham mo ta con duong 2
void cd2(int & HP1, int & EXP1, int & M1, int &E2){
    int tiensd= 0;
    int M=M1;
    int tienbd= M/2;
    if(E2%2==1){
       while(tiensd<=tienbd){
             hd1(HP1,M1, tiensd);
            
             
             if(tiensd > tienbd) break;
             hd2(EXP1,M1, tiensd);

             
             
             if(tiensd > tienbd) break;
             hd3(EXP1,M1, tiensd);

             
             
             if(tiensd > tienbd) break;
       }
       HP1 = ceil(HP1-float((HP1*17)/100));
       EXP1 = ceil(EXP1 +float(EXP1*0.17));
       if(HP1<0){
           HP1=0;
       }
       if(EXP1>600){
           EXP1 =600;
       }
    }
    else{
        while(1>0){
        hd1(HP1,M1, tiensd);
        if( M1==0){
            HP1 = ceil(HP1-float((HP1*17)/100));
            EXP1 = ceil(EXP1 +float((EXP1*17)/100));
            if(HP1<0){
               HP1=0;
            }
            if(EXP1>600){
               EXP1 =600;
            }
            break;
        }
        hd2(EXP1,M1, tiensd);
        if( M1==0){
            HP1 = ceil(HP1-float((HP1*17)/100));
            EXP1 = ceil(EXP1 +float((EXP1*17)/100));
            if(HP1<0){
               HP1=0;
            }
            if(EXP1>600){
               EXP1 =600;
            }
            break;
        }
        hd3(EXP1,M1, tiensd);
        if( M1==0){
            HP1 = ceil(HP1-float((HP1*17)/100));
            EXP1 = ceil(EXP1 +float((EXP1*17)/100));
            if(HP1<0){
               HP1=0;
            }
            if(EXP1>600){
               EXP1 =600;
            }
            break;
        }
        break;
    }
    }
}
// Ham tinh P2
double tinhP2(int &EXP1){
    int S= scp(EXP1);
    if(EXP1>=S){
       return 100; 
    }
    else{
        return ((EXP1 / static_cast<double>(S) + 80) / 123)*100;
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 <0 || E2>99){
        return -99;
    }
    if(EXP1 >600){
        EXP1 = 600;
    }
    if(EXP1 < 0){
        EXP1 = 0;
    }
    if(HP1>666){
        HP1 = 666;
    }
    if(HP1<0){
        HP1 =0;
    }
    if(M1>3000){
        M1=3000;
    }
    if(M1<0){
        M1=0;
    }
    double P1 = tinhP1(EXP1);
    cd2( HP1, EXP1,  M1, E2);
    double P2 = tinhP2(EXP1);
    double P3 = tinhP3(E2);
    if(P1==P2 && P1==P3 && P1==100){
        EXP1 = ceil(EXP1 - float((EXP1*25)/100));
    }
    double P = (P1+P2+P3)/3;
    if(P <50){
       HP1 = ceil(HP1 - float((HP1*15)/100));
       EXP1 = ceil(EXP1+float((EXP1*15)/100));
       if(HP1<0){
            HP1=0;
        }
        if(EXP1>600){
            EXP1 =600;
        }
    }
    else{
        HP1 = ceil(HP1 - float((HP1*10)/100));
        EXP1 = ceil(EXP1+float((EXP1*20)/100));
       if(HP1<0){
            HP1=0;
        }
        if(EXP1>600){
            EXP1 =600;
        }
    }

 return HP1 + EXP1 + M1;

}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //KT input
    if(HP1>666){
        HP1=666;
    }
    if(HP1<0){
        HP1 =0;
    }
    if(EXP1<0){
        EXP1=0;
    }
    if(EXP1 >600){
        EXP1= 600;
    }
     if(HP2>666){
        HP1=666;
    }
    if(HP2<0){
        HP1 =0;
    }
    if(EXP2<0){
        EXP1=0;
    }
    if(EXP2 >600){
        EXP1= 600;
    }
    if(E3>99 || E3<0){
        return -99;
    }
       
    //
    int array[10][10];
    for(int i =0; i<10; i++){
        for(int j=0 ; j<10; j++){
            array[i][j]= ((E3*j)+(2*i))*(i-j);
        }
    }
    //
    int ig=0;
    int jg=0;
    for(int i =0; i<10; i++){
        for(int j=0 ; j<10; j++){
            if(array[i][j]>(E3*2)){
                ig+=1;
            }
        }
    }
    for(int i =0; i<10; i++){
        for(int j=0 ; j<10; j++){
            if(array[i][j]<(E3*(-1))){
                jg+=1;
            }
        }
    }
    do{
        ig = ((ig%10)+(ig/10));
    }while(ig >=10);

    do{
        jg = ((jg%10)+(jg/10));
    }while(jg >=10);
    
    int is,js;
    //KT cheo trai
    for(int i =0; (ig-i)>=0 || (jg-i)>=0; i++){
        if(array[ig-1][jg-1]>array[ig][jg]){
            is = ig -i;
            js = jg -i;
        }
    }
    for(int i =0; (ig+i)<10|| (jg+i)<10; i++){
        if(array[ig+1][jg+1]>array[ig][jg]){
            is = ig +i;
            js = jg +i;
        }
    }
    //KT cheo phai
    for(int i =0; (ig+i)<10|| (jg-i)>=0; i++){
        if(array[ig+1][jg-1]>array[ig][jg]){
            is = ig +i;
            js = jg -i;
        }
    }
        for(int i =0; (ig-i)>=0|| (jg+i)<10; i++){
        if(array[ig-1][jg+1]>array[ig][jg]){
            is = ig -i;
            js = jg +i;
        }
    }
    //Ket thuc kiem tra
    if(abs(array[ig][jg])>abs(array[is][js])){
        EXP1 = ceil(EXP1 - float((12*EXP1)/100));
        HP1 = ceil(HP1 -float((HP1*10)/100));
        EXP2 = ceil(EXP2 - float((12*EXP2)/100));
        HP2 = ceil(HP2 -float((HP2*10)/100));
    }
    else{
        EXP1 = ceil(EXP1 + float((12*EXP1)/100));
        HP1 = ceil(HP1 +float((HP1*10)/100));
        EXP2 = ceil(EXP2 + float((12*EXP2)/100));
        HP2 = ceil(HP2 +float((HP2*10)/100));
    }

    


    return array[ig][jg];
    //return -1;
}

// Task 4
// Ham tim se

const char* before(const char* email) {
    const char* atSymbol = std::strchr(email, '@');

    if (atSymbol != nullptr) {
        std::size_t lengthBeforeAt = atSymbol - email;

        char* result = new char[lengthBeforeAt + 1];

        std::strncpy(result, email, lengthBeforeAt);
        result[lengthBeforeAt] = '\0'; 
        return result;
    } else {
        return nullptr; 
    }
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    std::size_t dodaimail = std::strlen(email);
    const char * se = before(email);
    if (std::strlen(s) < 8){
        return -1;
    }
    if (std::strlen(s) > 20){
        return -2;
    }
    if (strcspn(s, "@#$%!") == std::strlen(s)){
        return -5;
    }
    const char* sePosition = std::strstr(s, se);
    if (sePosition != nullptr){
        return -(300+(sePosition-s));
    }
    for (std::size_t i = 0; i < std::strlen(s) - 2; i++){
        if (s[i] == s[i + 1] && s[i] == s[i + 2]){
            return -(400+i);
        }
    }
    if (sePosition != nullptr && sePosition - s <= 2){
        return -(400 + (sePosition - s)); 
    }
    for (std::size_t i = 0; i < std::strlen(s) - 1; i++){
        if (s[i] == s[i+1]) {
            return i; 
        }
    }
    if (std::strlen(s) < dodaimail){
        return -(500 + std::strlen(s)); 
    }

    return -10; 
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int vt = -1;  
    int maxCount = 0;
    int maxLength = 0;

    for (int i = 0; i < num_pwds; ++i){
        const char* currentPassword = arr_pwds[i];
        int dem = 0;
        int dodai = std::strlen(currentPassword);
        for (int j = 0; j < num_pwds; ++j) {
            if (i != j && std::strcmp(arr_pwds[j], currentPassword) == 0){
                dem++;
            }
        }
        if (dem > maxCount || (dem == maxCount && dodai > maxLength)){
            maxCount = dem;
            maxLength = dodai;
            vt = i;
        }
    }
    return vt;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////