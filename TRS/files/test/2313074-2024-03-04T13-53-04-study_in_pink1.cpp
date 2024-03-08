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

//check đem từ file header sang
int nearestS_EXP1(int &a){
   return a= pow(round(sqrt(a)), 2);
}


// Task 1
void firstmeet_case1(int & exp1, int & exp2, int e1){
     switch (e1)
    {
    case 0/* constant-expression */:
        exp2 = exp2 + 29;/* code */
        break;
    case 1: 
        exp2 = exp2 + 45;
        break;
    case 2:
        exp2 = exp2 + 75;
        break;
    case 3:
        exp2 = exp2 + 149;
        break;
    default:
    break;
    }
    int D;
    D = e1*3+ exp1*7;
    if ((D % 2) == 0) exp1 = ceilf(exp1 + (D/200.0));
    else exp1 = ceilf (exp1 - (D/100));
}
void firstmeet_case2(int & exp1, int & exp2, int e1){
        if     (4<=e1 && e1<=19)     exp2= ceilf(exp2+ (e1/4.0+ 19));
        else if(20<=e1 && e1<=49)    exp2= ceilf(exp2+ (e1/9.0+21));
        else if(50<=e1 && e1<=65)    exp2=ceilf(exp2 +(e1/16.0+17));
        else if(66<=e1 && e1<=79)    {
            exp2= ceilf(exp2+ (e1/4.0+ 19));
            if (exp2>200) exp2= ceilf(exp2+ (e1/9.0+21));
            else ;
            //exp2=ceil(exp2 +(e1/16.0+17));
        }
        else if(80<=e1 && e1<=99)    {
            exp2= ceilf(exp2 + (e1/4.0+ 19) );
            exp2= ceilf(exp2 + (e1/9.0+ 21));
                if (exp2>400) {
                    exp2=ceilf(exp2 +(e1/16.0+17));
                    exp2 = ceilf(exp2*1.15); 
                }
                else ;
            }
        exp1 = exp1 - e1;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    handleEXP(exp1, exp2);
    if ((e1<0) || (e1>99)) return -99;
    // TODO: Complete this function
    if ((0<=e1) && (e1<=3)) firstmeet_case1(exp1, exp2, e1);
    else if (3<e1 && e1<100) firstmeet_case2(exp1, exp2, e1);
    handleEXP(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
double trace1(int& exp1){
    int S= exp1; double P1;
    nearestS_EXP1(S);
    if (exp1 >=S) P1=100;
    else P1=(((exp1*1.0/S)+80)/123)*100;
    return P1;
}

double trace2(int & HP1, int & EXP1, int & M1, int E2){
    double M_start= M1;
    if ((E2%2)==1){
        while (M1 >(M_start*0.5)){
            //event1
            if (HP1<200) {
                HP1=ceilf(HP1*1.3);
                M1= M1-150;
                handleMoney_case(M1);
                handleHP_case(HP1);
            }
            else {
                HP1=ceilf(HP1*1.1);
                M1= M1-70;
                handleMoney_case(M1);
                handleHP_case(HP1);
            }
            if (M1< M_start*0.5) break;
            //event2
            if (EXP1<400){
                M1= M1-200;
                handleMoney_case(M1);
            }
            else{
                M1= M1-120;
                handleMoney_case(M1);
            }
            EXP1=ceilf(EXP1*1.13);
            if (M1< M_start*0.5) break;
            //event3
            if (EXP1<300){
                M1 = M1-100;
                handleMoney_case(M1);
            }
            else{
                M1 = M1 - 120;
                handleMoney_case(M1);
            }
            EXP1= ceilf(EXP1*0.9);
            if(M1<M_start*0.5) break;
            }
            HP1= ceilf(HP1*0.83);
            EXP1= ceilf(EXP1*1.17);
            handleEXP_case(EXP1);
            handleHP_case(HP1);
        }
        else{
            for (int i =1; i<2; ++i){
            //event1
            if (HP1<200) {
                HP1=ceilf(HP1*1.3);
                M1= M1-150;
                handleMoney_case(M1);
                handleHP_case(HP1);
            }
            else {
                HP1=ceilf(HP1*1.1);
                M1= M1-70;
                handleMoney_case(M1);
                handleHP_case(HP1);
            }
            if (M1==0) break;
            //event2
            if (EXP1<400){
                M1= M1-200;
                handleMoney_case(M1);
            }
            else{
                M1= M1-120;
                handleMoney_case(M1);
            }
            EXP1=ceilf(EXP1*1.13);
            if (M1==0) break;
            //event3
            if (EXP1<300){
                M1 = M1-100;
                handleMoney_case(M1);
            }
            else{
                M1 = M1 - 120;
                handleMoney_case(M1);
            }
            EXP1= ceilf(EXP1*0.9);
            if(M1==0) break;
            }
            HP1= ceilf(HP1*0.83);
            EXP1= ceilf(EXP1*1.17);
            handleEXP_case(EXP1);
            handleHP_case(HP1);
        }
    int S2=EXP1; double P2;
    nearestS_EXP1(S2);
    if (EXP1 >=S2) P2=100;
    else P2=(((EXP1*1.0/S2)+80)/123)*100;
    return P2;
    }
double trace3(int E2){
    double P3;
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2<10) P3= P[E2];
    else if(9<E2 && E2<100) {
        int sum= E2/10 + E2 %10;
        P3= P[sum%10];
    }
    return P3;
}    

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    handleEXP_case(EXP1);
    handleHP_case(HP1);
    handleMoney_case(M1);
    if ((E2<0) || (E2>99)) return -99;
    // TODO: Complete this function
    double P1=trace1(EXP1);
    double P2=trace2(HP1, EXP1, M1, E2);
    double P3=trace3(E2);
    double P =(P1+P2+P3)/3;
    if (P==100) EXP1 =ceilf(EXP1*0.75);
    else {
        if(P<50) {
            HP1=ceilf(HP1*0.85);
            EXP1=ceilf(EXP1*1.15);
        }
        else{
            HP1=ceilf(HP1*0.9);
            EXP1=ceilf(EXP1*1.2);
        }
    }
    handleEXP_case(EXP1);
    handleHP_case(HP1);
    handleMoney_case(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    handleEXP(EXP1, EXP2);
    handleHP(HP1, HP2);
    if ((E3<0) || (E3>99)) return -99;

    int matrixtaxi[10][10] = {{0}};
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                matrixtaxi[i][j]= ((E3*j)+(2*i))*(i-j);
              
            }
         
        }
    int matrixSvW[10][10] = {{0}};
        for(int a=0; a<10; a++){
            for(int b=0; b<10; b++){
                int c=a, d =b;
                int max=matrixtaxi[a][b];
                while((c<10)&& (d<10)){
                    if (c==9||d==9) break;
                    if(matrixtaxi[c+1][d+1]>max) max=matrixtaxi[c+1][d+1];
                    ++c; ++d;
                }
                 c=a, d=b;
                while((0<=c)&&(0<=d)){
                    if (c==0||d==0) break; 
                    if(matrixtaxi[c-1][d-1]>max) max=matrixtaxi[c-1][d-1];
                    --c;--d;
                }
                 c=a, d=b;
                 while (c<10 && d>=0){
                    if (c==9||d==0) break;
                    if(matrixtaxi[c+1][d-1]>max) max=matrixtaxi[c+1][d-1];
                    ++c;--d;
                 }
                 c=a, d=b;
                 while (c>=0 && d<10){
                     if (c==0||d==9) break;
                     if(matrixtaxi[c-1][d+1]>max) max=matrixtaxi[c-1][d+1];
                    --c;++d;
                 }
                matrixSvW[a][b]= max;
               
            }
            
        }    
            int e=0, f=0;
    for(int i=0; i<10;i++){
        for(int j=0; j<10; j++){
            if(matrixtaxi[i][j] > (E3*2)) e=e+1;
            if(matrixtaxi[i][j] <(-E3)) f= f+1;
        }
    }
   
    if(9<e<100) e= (e%10)+ e/10;
    if(9<e<100) e= (e%10)+ e/10;
    if(9<f<100) f= (f%10)+ f/10;
    if(9<f<100) f= (f%10)+ f/10;
    
    if (abs(matrixtaxi[e][f])>abs(matrixSvW[e][f])) {
        EXP1=ceilf(EXP1*0.88);
        EXP2=ceilf(EXP2*0.88);
        HP1=ceilf(HP1*0.9);
        HP2=ceilf(HP2*0.9);
    }
    else {
        EXP1=ceilf(EXP1*1.12);
        EXP2=ceilf(EXP2*1.12);
        HP1=ceilf(HP1*1.1);
        HP2=ceilf(HP2*1.1);
    } 
    handleEXP(EXP1, EXP2);
    handleHP(HP1, HP2);       
    if (abs(matrixtaxi[e][f])>abs(matrixSvW[e][f])) return matrixtaxi[e][f];
    else return matrixSvW[e][f];
}

// Task 4
void strncpy_custom(char* destination, const char* source, int size) {
    for (int i = 0; i < size && source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    // Đảm bảo kết thúc chuỗi đích
    destination[size] = '\0';
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int passlength= strlen(s);
    if (passlength<8) return -1;
    else if (passlength>20) return -2;
    const char* se_final= strstr(email, "@");
    int size = (se_final - email);
    char se[100];
    strncpy_custom(se,email, size);
    ///
    const char* se_1= strstr(s, se);
    if (se_1 != NULL) return (-(300+ (se_1 - s)));
    ///
    for (int i = 0; i < passlength - 2; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2])
            return -(400 + i);
    }
    ///
    bool specialcharCheck= false;
    for (int i = 0; i<passlength;++i){
        if(s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%' || s[i]=='!') specialcharCheck=true;
    }
    if (!specialcharCheck) return -5;
    /////
    for (int i = 0; i<passlength;i++){
        if(isalnum(s[i])){}
        else {
            if(s[i]!='@' && s[i]!='#' && s[i]!='$' && s[i]!='%' && s[i]!='!') return i;
        }
        } 

    return (-10);
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int **arr= new int*[2];
     for (int i = 0; i < 2; ++i) {
        arr[i] = new int[num_pwds];
        // Khởi tạo tất cả các phần tử của mảng là 0
        std::memset(arr[i], 0, sizeof(int) * num_pwds);
    }

    for (int i=0; i<num_pwds; i++){
        for(int a=0; a< num_pwds; a++){
            if (arr_pwds[i] == arr_pwds[a]) ++arr[0][i];    
        }
    arr[1][i]=strlen(arr_pwds[i]);
    }
    ////findMAX
    int max1= arr[0][0];
    int max2= arr[1][0];
    for(int i=1; i<num_pwds; i++){
        if (arr[0][i]>max1) max1 = arr[0][i];
    }
    ///
    for(int i=0; i<num_pwds; i++){
        if ((arr[0][i] == max1) && (arr[1][i]>max2)) max2= arr[1][i];
    }
    ///
    int e;
    for(int i=0; i<num_pwds;i++){
        if ((arr[0][i]== max1)&&(arr[1][i]==max2)) {
            e = i;
            break;
        }
    } 
    for (int i = 0; i < 2; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return e;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////