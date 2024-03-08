#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int checkValue(int n, int min, int max){
    if (n<min){
        n = min;
    }
    else if (n>max){
        n = max;
    }
    return n;
}
int roundup(float n){
    int temp;
    temp = n;
    if(n - temp >0){ return temp +1;}
    else return temp;
}

int minEXP =0, minHp = 0, minM = 0, maxEXP = 600, maxHp = 666, maxM = 3000;
float temp_HP1, temp_HP2, temp_EXP1, temp_EXP2;
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //check input
    if (e1 < 0 || e1>99) return -99;
    exp1 = checkValue(exp1, minEXP, maxEXP);
    exp2 = checkValue(exp2, minEXP, maxEXP);


    //Indentify case 1 or 2
    bool case1;
    if (e1>=0 && e1<=3){
        case1 = true;
    }
    else case1 = false; 

    //case 1
    if (case1){
        switch(e1)
        {
        case 0:
            {
                exp2 += 29;
                 break;
             }
        case 1:
            {
                exp2 += 45;
                 break;
             }
        case 2: 
            {
                exp2 += 75;
                break;
            }
        case 3:
            {
                exp2 += 149;
                break;
            }
        }
    //calculate EXP1
        int D;
        D = e1*3 + exp1*7;
        if (D%2==0){
            temp_EXP1 = exp1 + float (D)/200;
        }
        else temp_EXP1 = exp1 - float(D)/100;
        exp1 = roundup(temp_EXP1);
        exp1 = checkValue(exp1, minEXP, maxEXP);
        exp2 = checkValue(exp2, minEXP, maxEXP);
    }
    //case 2
    else{
        if (e1<=19){
            temp_EXP2 = exp2 + float(e1)/4 + 19;
        }
        else if (e1<=49){
            temp_EXP2 = exp2 + float(e1)/9 + 21;
        }
        else if (e1<=65){
            temp_EXP2 = exp2 + float(e1)/16 + 17;
        }
        else if (e1<=79){
            temp_EXP2 = exp2 + float(e1)/4 + 19;
            exp2 = roundup(temp_EXP2);
            exp2 = checkValue(exp2, minEXP, maxEXP);
            temp_EXP2 = exp2;
            if (temp_EXP2 - 200 >0){temp_EXP2 = temp_EXP2 + float(e1)/9 + 21;}
        }
        else if (e1<=99){
            temp_EXP2 = exp2 + float(e1)/4 + 19;
            exp2 = roundup(temp_EXP2);
            exp2 = checkValue(exp2, minEXP, maxEXP);
            temp_EXP2 = exp2;
            temp_EXP2 = temp_EXP2 + float(e1)/9 + 21;
            exp2 = roundup(temp_EXP2);
            exp2 = checkValue(exp2, minEXP, maxEXP);
            temp_EXP2 = exp2;
            if (temp_EXP2 - 400 >0){
                temp_EXP2 = temp_EXP2 + float(e1)/16 + 17;
                exp2 = roundup(temp_EXP2);
                exp2 = checkValue(exp2, minEXP, maxEXP);
                temp_EXP2 = exp2 + float(exp2)*0.15;
            }
        
        }

        //calculate EXP1
        exp1 -= e1;
        //round up and check
        exp2 = roundup(temp_EXP2);
        exp1 = checkValue(exp1, minEXP, maxEXP);
        exp2 = checkValue(exp2, minEXP, maxEXP);

    }
    return exp1 + exp2;
}

// Task 2

void event1(int & HP1, int & M1){
    temp_HP1 = HP1;
    if (HP1 <200){
        temp_HP1 = temp_HP1*1.3;
        M1 -= 150;
    }
    else{
        temp_HP1 =  temp_HP1*1.1;
        M1 -= 70;
    }
    HP1 = roundup(temp_HP1);
    HP1 = checkValue(HP1, minHp, maxHp);
    M1 = checkValue(M1, minM, maxM);
}
void event2(int & EXP1, int & M1){
    temp_EXP1 = EXP1;
    if (EXP1 <400){M1-=200;}
    else M1 -=120;
    temp_EXP1 = temp_EXP1*1.13;
    EXP1 = roundup(temp_EXP1);
    EXP1 = checkValue(EXP1, minEXP, maxEXP);
    M1 = checkValue(M1, minM, maxM);
}

void event3( int & EXP1, int & M1){
    temp_EXP1 = EXP1;
    if (EXP1 < 300){M1 -= 100;}
    else M1 -= 120;
    temp_EXP1 = temp_EXP1*0.9;
    EXP1 = roundup(temp_EXP1);
    EXP1 = checkValue(EXP1, minEXP, maxEXP);
    M1 = checkValue(M1, minM, maxM);
}
int nearstsquare(int n){
     //find nearstsquare
        int i ;
        i = sqrt(n);
        int sq1 = i*i;
        int sq2 = (i+1)*(i+1);
        if ((sq2-n)>(n-sq1)){return sq1;}
        else return sq2;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float P1, P2, P3;
    // check value
    if (E2 < 0 || E2>99) return -99;
    HP1 = checkValue(HP1, minHp, maxHp);
    EXP1 = checkValue(EXP1, minEXP, maxEXP);
    M1 = checkValue(M1, minM, maxM);
    /////////road 1
   
    //calculate P1
        int S1 = nearstsquare(EXP1);
        if (EXP1 >= S1){P1=1;}
        else P1 = (float(EXP1)/float(S1) + 80)/123;
    /////////road 2
        float limit_budget = float(M1)*0.5;
        if (E2%2 != 0){
            while (M1>0){
                event1(HP1, M1);
                if (M1 < limit_budget) break;
                event2(EXP1, M1);
                if (M1 < limit_budget) break;
                event3(EXP1, M1);
                if (M1 < limit_budget) break;
            }
        }
        else{
            if(M1>0){
                event1(HP1, M1);
                if(M1>0){
                    event2(EXP1, M1);
                    if(M1>0){
                        event3(EXP1, M1);
                    }
                }
            }
            
        }
            temp_HP1 = HP1;
            temp_EXP1 = EXP1;
            temp_HP1 = temp_HP1*0.83;
            temp_EXP1 = temp_EXP1*1.17;
            HP1 = roundup(temp_HP1);
            EXP1 = roundup(temp_EXP1);
            HP1 = checkValue(HP1, minHp, maxHp);
            EXP1 = checkValue(EXP1, minEXP, maxEXP);
        //calculate P2
        int S2 = nearstsquare(EXP1);
        if (EXP1 >= S2){P2=1;}
        else P2 = (float(EXP1)/float(S2) + 80)/123;
        ///////////road 3
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        /////count digit of E2
        if (E2/10 < 1){
            i = E2;
        } else {
            int digit1 = E2/10;
            int digit2 = E2%10;
            i = (digit1 + digit2)%10;
        }
        // calculate P3
        P3 = float(P[i])/100;
        // final calculations
        if (P1 == 1 && P2==1 && P3 ==1){
            temp_EXP1 = EXP1;
            temp_EXP1 = temp_EXP1*0.75;
            EXP1 = roundup(temp_EXP1);
            EXP1 = checkValue(EXP1, minEXP, maxEXP);
        }
        else{
            float P;
            temp_HP1 = HP1;
            temp_EXP1 = EXP1;
            P = (P1+P2+P3)/3;
            if (P -0.5<0){
                temp_HP1 = temp_HP1*0.85;
                temp_EXP1 =temp_EXP1*1.15;
            }
            else{
                temp_HP1 = temp_HP1*0.9;
                temp_EXP1 = temp_EXP1*1.2;
            }
            EXP1 = roundup(temp_EXP1);
            HP1 = roundup(temp_HP1);
            EXP1 = checkValue(EXP1, minEXP, maxEXP);
            HP1 = checkValue(HP1, minHp, maxHp);

        }

    return HP1 + EXP1 + M1;
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // check value
    if (E3 < 0 || E3>99) return -99;
    HP1 = checkValue(HP1, minHp, maxHp);
    HP2 = checkValue(HP2, minHp, maxHp);
    EXP1 = checkValue(EXP1, minEXP, maxEXP);
    EXP2 = checkValue(EXP2, minEXP, maxEXP);
    //taxi matrix 
  int taxiMatrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiMatrix[i][j] = ((E3*j)+(i*2)) * (i - j); 
        }
    }
    //define meeting point 
    int meeting_i=0, meeting_j=0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxiMatrix[i][j]<(-E3)){
                meeting_j++;
            }
            else if(taxiMatrix[i][j]>(2*E3)){
                meeting_i++;
            }
        }
    }
    while (meeting_i/10 >= 1){
            int num1 = meeting_i/10;
            int num2 = meeting_i%10;
            meeting_i = (num1 + num2);
        }
    while (meeting_j/10 >= 1){
            int num1 = meeting_j/10;
            int num2 = meeting_j%10;
            meeting_j = (num1 + num2);
        }
    int taxiScore = taxiMatrix[meeting_i][meeting_j];
   
    // find Sherlock and Watson score
    int Max=0, Max1=0, Max2=0, Max3=0, Max4=0;
         //max of diagonals
            //RightUp
            int a =meeting_i-1, b=meeting_j+1;
            while (a>0&&b<10){
                 Max1 = max(taxiMatrix[a][b], taxiMatrix[a+1][b-1]);
                b++; a--;
                if (a ==0 || b==9){
                    Max1 = max(taxiMatrix[a][b], taxiMatrix[a+1][b-1]);
                    break;
                }
            }
            //RightDown
            a =meeting_i+1, b=meeting_j-1;
            while (b>0&&a<10){
                Max2 = max(taxiMatrix[a][b], taxiMatrix[a-1][b+1]);
                b--; a++;
                if (a ==9 || b==0){
                    Max2 = max(taxiMatrix[a][b], taxiMatrix[a-1][b+1]);
                    break;
                }
            }
            //LeftUp
            a =meeting_i-1, b=meeting_j-1;
            while (b>0&&a>0){
                Max3 = max(taxiMatrix[a][b], taxiMatrix[a+1][b+1]);
                b--; a--;
                if (a ==0 || b==0){
                    Max3 = max(taxiMatrix[a][b], taxiMatrix[a+1][b+1]);
                    break;
                }
            }
            //LeftDown
            a =meeting_i+1, b=meeting_j+1;
            while (a<10&&b<10){
                Max4 = max(taxiMatrix[a][b], taxiMatrix[a-1][b-1]);
                b++; a++;
                if (a ==9 || b==9){
                    Max4 = max(taxiMatrix[a][b], taxiMatrix[a-1][b-1]);
                    break;
                }
            }
            Max = Max1;
            if (Max2 > Max){Max = Max2;}
            if (Max3 > Max){Max = Max3;}
            if (Max4 > Max){Max = Max4;}
        
    
    int SherlockandWatsonScore;
    if (Max < 0){SherlockandWatsonScore = abs(Max);}
    else SherlockandWatsonScore = Max;


    //compare scores
    int rt;
    if (SherlockandWatsonScore < abs(taxiScore)){
        rt = taxiScore;
        temp_EXP1 = float(EXP1) - float(EXP1)*0.12;
        temp_HP1 = float(HP1) - float(HP1)*0.1;
        temp_EXP2 = float(EXP2) - float(EXP2)*0.12;
        temp_HP2 = float(HP2) - float(HP2)*0.1;
        
    } else {
        rt = SherlockandWatsonScore;
        temp_EXP1 = float(EXP1) + float(EXP1)*0.12;
        temp_HP1 = float(HP1) + float(HP1)*0.1;
        temp_EXP2 = float(EXP2) + float(EXP2)*0.12;
        temp_HP2 = float(HP2) + float(HP2)*0.1;
    }
        EXP1 = roundup(temp_EXP1);
        EXP2 = roundup(temp_EXP2);
        HP1 = roundup(temp_HP1);
        HP2 = roundup(temp_HP2);
        EXP1 = checkValue(EXP1, minEXP, maxEXP);
        EXP2 = checkValue(EXP2, minEXP, maxEXP);
        HP1 = checkValue(HP1, minHp, maxHp);
        HP2 = checkValue(HP2, minHp, maxHp);

    return rt;
}



// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int rt;
    ///////conditions
    //limit length
    if (strlen(s)<8){return -1;}
    else if(strlen(s)>20){return -2;}
    //contain se or not
    int seIndex, sei;
    for (int i=0;i<strlen(email); i++){
        if (email[i]=='@'){
            seIndex = i;
        }
    }
    char se[seIndex];
    se[seIndex] = '\0';
    strncpy(se, email, seIndex);
    char* hasSe = strstr(const_cast<char*>(s), se);
    if (hasSe != nullptr){
        sei = hasSe-s;
        return -(300+sei);
    }
    //more than 2 same keys or not
    int sci; bool samekey = false;
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (s[i] == s[i + 1]) {
            if (i + 2 < strlen(s) && s[i] == s[i + 2]) {
                sci=i; samekey = true; break;
            }
        }
    }
    if (samekey) {return -(400+sci);}

    //has special char or not
    bool hasSpecialChar = false;
    for (int i=0; i<strlen(s);i++){
           if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5;

    //remaining cases
    for (int i = 0; i< strlen(s); i++) {
        char c = s[i];
   
        if (!((c >= '0' && c <= '9') ||          
              (c >= 'a' && c <= 'z') ||     
              (c >= 'A' && c <= 'Z') ||        
              c == '@' || c == '#' ||            
              c == '%' || c == '$' ||
              c == '!')) {
            return i; 
        }
    }


    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    // Create values about count and length
    int max_count = 0;
    int max_length = 0;
    int correct_password = 0;

    // loop for searching the correct password
    for (int i = 0; i < num_pwds; ++i) {
        // check the length of password
        int length = strlen(arr_pwds[i]);

        // count the times password appeares
        int count = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++count;
            }
        }

        // find the correct password
        if ((count > max_count) || (count == max_count && length > max_length)) {
            max_count = count;
            max_length = length;
            correct_password = i;
        }
    }


    return correct_password;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////