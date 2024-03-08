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

/// Update cac chi so
int updateHP(int HP, int value){
    HP = HP + value;
    return (HP<=0) ? 0 : (HP>=666) ? 666 : HP; 
}

int updateEXP(int EXP, int value) {
    EXP = EXP + value;
    return (EXP<=0) ? 0 : (EXP>=600) ? 600 : EXP;
}

int updateMon(int M, int value) {
    M = M + value;
    return (M<=0) ? 0 : (M>=3000) ? 3000 : M;
}
/// end Update


//// TASK 2  
// Xac dinh xac xuat P 
float FindP(int EXP1) {
    int SCP1 = EXP1, SCP2 = EXP1, i1=0, i2=0;
    while(SCP1>=1)
    {
        if(SCP1 == (sqrt(SCP1)*sqrt(SCP1)))
            break;
        SCP1--;
        i1++;
    }
    while(SCP2>=1) {
        if(SCP2 == (sqrt(SCP2)*sqrt(SCP2)))
            break;
        SCP2++;
        i2++;
    }
    if(i1>i2 || EXP1==0) {
        float X = (float(EXP1)/float(SCP2) + 80.0)/123.0 ;
        return X;
    }
    return 1.0;
}
// end xac dinh P

// tuyen duong 2
float P_in_road2(int &HP1, int &EXP1, int &M1, int E2 ){
    int Money_initail = M1;
    int valueHP(0), valueMon(0), valueEXP(0);
    do {
        // SK1
        if( (M1*2<Money_initail && E2%2==1) || M1==0) break;
        if(HP1<200) {
            valueHP  = ceil(float(HP1)/10.0*3.0);
            valueMon = -150;
        }
        else {  
            valueHP  = ceil(float(HP1)/10.0); 
            valueMon = -70;
        }
        HP1= updateHP (HP1, valueHP);
        M1 = updateMon(M1, valueMon);

        //SK2
        if( (M1*2<Money_initail && E2%2==1) || M1==0) break;
        if(EXP1<400) valueMon = -200;
        else         valueMon = -120;
        valueEXP = ceil(float(EXP1)/100.0*13.0);
        EXP1 = updateEXP(EXP1, valueEXP);
        M1   = updateMon(M1, valueMon);

        //SK3
        if( (M1*2<Money_initail && E2%2==1) || M1==0) break;
        if(EXP1<300) valueMon = -100;
        else         valueMon = -120;
        valueEXP = EXP1/10*(-1);
        EXP1 = updateEXP(EXP1, valueEXP);
        M1   = updateMon(M1, valueMon); 

    }while(E2%2==1);

    valueHP = HP1*17/100*(-1);
    HP1  = updateHP(HP1, valueHP);
    valueEXP = ceil(float(EXP1)/100.0*17.0);
    EXP1 = updateEXP(EXP1, valueEXP);

    return FindP(EXP1);
}
// end duong 2

// tuyen duong 3
float P_in_road3(int E2) {
    if(E2>=10 && E2<=99)    
        E2 = E2%10 + (E2/10)%10;
    E2 = E2%10;
    float P[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    return P[E2];    
}
// end duong 3
//// END TASK 2


//// TASK 3
int FindMax_in_Diagonal(int arr[][10], int X, int Y){
    int i(0), j(0), valueMax(0);
    if(X>=Y)        /// Đg chéo chính có i-j = const a 
        i = X-Y;
    else     
        j = Y-X;
    while(i<10 && j<10)
    {
        if(valueMax < arr[i][j]) valueMax = arr[i][j];
        i++; j++;
    }  

    if(X+Y<=9) {    /// Đg chéo phụ có i+j = const b
        i = X + Y; 
        j = 0;
    }
    else {
        i = 9;
        j = X + Y - 9;
    }
    while(i >= 0 && j <= 9)
    {
        if(valueMax < arr[i][j]) valueMax = arr[i][j];
        i--;
        j++;
    }

    return valueMax;
}
//// END TASK 3


//// TASK 4
string find_Se_inEmail(const char * email){
    string Se="";
    for(int i=0; i<(int)strlen(email); i++)
    {   
        if(email[i]=='@') break;
        Se = Se + email[i];
    }    
    return Se;
}

bool check_char(char ch, bool &specail_ch)
{
    if(ch>='a' && ch<='z') return true;
    if(ch>='A' && ch<='Z') return true;
    if(ch>='0' && ch<='9') return true;
    if(ch=='@' || ch=='#' || ch=='%' || ch=='$' || ch=='!')
    {
        specail_ch = 1;
        return true;
    }
    return false; 
}
//// END TASK 4


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0 || e1>99) return -99;
    if(e1>=0 && e1<=3)
    {
        int valueEXP = 0;
        switch (e1)
        {
        case 0:
            valueEXP = 29;  break;
        case 1: 
            valueEXP = 45;  break;
        case 2: 
            valueEXP = 75;  break;
        default:
            valueEXP = 29 + 45 + 75;
            break;
        }
        exp2 = updateEXP(exp2, valueEXP);

        int D = e1*3 + exp1*7;
        if(D%2==0)
            D = D/200 + int(D%200 != 0);
        else {
            D = D/100;
            D = -1 * D;
        }
        exp1 = updateEXP(exp1, D);
    }
    else if(e1>=4 && e1<=99)
    {
        int valueEXP = 0;
        if(e1<=19) 
            valueEXP = e1/4 + 19 + int(e1%4 != 0); 
            
        else if(e1<=49)
            valueEXP = e1/9 + 21 + int(e1%9 != 0);

        else if(e1<=65)
            valueEXP = e1/16 + 17 + int(e1%16 !=0);
        
        else if(e1<=79) {
            valueEXP = e1/4 + 19 + int(e1%4 != 0); 
            int exp2_tmp = updateEXP(exp2, valueEXP);

            if(exp2_tmp>200) { /// can dung exp2 sau khi qua sk1,2  
                exp2 = updateEXP(exp2, valueEXP);
                valueEXP = e1/9 + 21 + int(e1%9 != 0); 
            }   
        }  
        else {
            valueEXP = e1/4 + 19 + int(e1%4 != 0) 
                      +e1/9 + 21 + int(e1%9 != 0); 
            int exp2_tmp = updateEXP(exp2, valueEXP);

            if(exp2_tmp>400) { /// can dung exp2 sau khi qua sk1,2
                exp2 = updateEXP(exp2, valueEXP);

                valueEXP = e1/16 + 17 + int(e1%16 !=0); 
                exp2 = updateEXP(exp2, valueEXP);

                float tmpExp2 = float(exp2)/100*15;
                valueEXP = ceil(tmpExp2);
            }   
        }

        exp2 = updateEXP(exp2, valueEXP);
        exp1 = updateEXP(exp1, (-1*e1));
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99) return -99;
    int valueHP(0), valueEXP(0);
    
    float P1 = FindP(EXP1);
    float P2 = P_in_road2(HP1, EXP1, M1, E2);
    float P3 = P_in_road3(E2);

    float PTB = (P1+P2+P3)/3.0;
    if(PTB>=1) 
        valueEXP = EXP1/4*(-1);
    else if(PTB<0.5) {
        valueEXP = ceil(float(EXP1)/20.0*3.0);
        valueHP  = HP1*3/20*(-1);
    }
    else {
        valueEXP = ceil(float(EXP1)/5.0);
        valueHP  = HP1/10*(-1);
    }
    EXP1 = updateEXP(EXP1, valueEXP);
    HP1  = updateHP (HP1, valueHP); 
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99) return -99;

    int Map[10][10], Result(0), X(0), Y(0);
    for(int i=0; i<10;i++)
        for(int j=0; j<10; j++)
            Map[i][j] = 0;

    for(int i=0; i<10;i++)
        for(int j=0; j<10; j++)
        {
            Map[i][j] = (E3*j + i*2) * (i-j);
            if(Map[i][j] > (E3*2)) X++;
            if(Map[i][j] < (-1*E3)) Y++;
        }
    while(X>=10) 
        X = X%10 + (X/10)%10;
    while(Y>=10)
        Y = Y%10 + (Y/10)%10;
    int point_of_S_W = FindMax_in_Diagonal(Map, X, Y);
    if(abs(point_of_S_W) >= abs(Map[X][Y])) {
        Result = point_of_S_W;
        EXP1 = updateEXP(EXP1, ceil(float(EXP1)/100.0*12.0));
        EXP2 = updateEXP(EXP2, ceil(float(EXP2)/100.0*12.0));
        HP1  = updateHP (HP1 , ceil(float(HP1)/10.0));
        HP2  = updateHP (HP2 , ceil(float(HP2)/10.0));
    }
    else {
        Result = Map[X][Y];
        EXP1 = updateEXP(EXP1, EXP1*12/100*(-1));
        EXP2 = updateEXP(EXP2, EXP2*12/100*(-1));
        HP1  = updateHP (HP1,  HP1/10*(-1));
        HP2  = updateHP (HP2,  HP2/10*(-1));
    }
    return Result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if(strlen(s)<8)  return -1;
    if(strlen(s)>20) return -2;

    string Se = find_Se_inEmail(email);
    bool specail_ch = 0;
    if(Se.size()==0) return -300;
    for(int i = 0; i <= int(strlen(s) - Se.size()); i++){
        if(Se[0]==s[i])
        {
            for(int j=0; j< (int)Se.size(); j++)
            {   
                if(Se[j] != s[i+j]) break;
                if(j == (int)Se.size()-1) return -1*(300+i);
            }
        }
    }

    for(int i = 0; i<(int)strlen(s); i++){
        if(i<(int)strlen(s)-2 && s[i]==s[i+1] && s[i]==s[i+2])
            return -1*(400+i);
        
    }
    int vitri = -1;
    for(int i = 0; i<(int)strlen(s); i++){
        if(!check_char(s[i], specail_ch)  && vitri==-1)
            vitri = i;
    }
    if(!specail_ch) return -5;
    else if(vitri!=-1) return vitri;
    return -10;
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int size_arr(0);
    Pass arr[30];

    for(int i=0; i<num_pwds; i++)
    {
        bool happen = 0;
        for(int j = 0; j<size_arr; j++)
        {
            if(arr[j].cmpPass(arr_pwds[i]))     /// if pass giong nhau thi arr[j].count++ va so sanh voi Max
            {
                happen = 1; 
                break;
            }
        }
        if(happen==0){
            arr[size_arr++] = {arr_pwds[i], 1, i};
        }
    }
    int index_max(0);
    for(int i=1; i<size_arr; i++)
    {
        if(arr[index_max].count < arr[i].count)
            index_max = i;
        else if(arr[index_max].count == arr[i].count)
            if(arr[index_max].size_Pass() < arr[i].size_Pass())
                index_max = i;
    }
    
    return arr[index_max].index_first;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////