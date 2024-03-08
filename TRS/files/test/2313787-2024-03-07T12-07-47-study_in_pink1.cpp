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
        cout << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//functions to modify HP, EXP and M so its value stay in a specific range
void checkHP (int & hp)
{
    if (hp<0)
    hp=0;
    else if (hp>666)
    hp=666;
}
void checkEXP (int & exp)
{
    if (exp<0)
    exp=0;
    else if (exp>600)
    exp=600;
}
void checkM (int &m)
{
    if (m<0)
    m=0;
    else if (m>3000)
    m=3000;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkEXP(exp1);
    checkEXP(exp2);
    
    if (e1<0 || e1>99) return -99;
    else if (e1 >= 0 && e1 <= 3)
    {
    switch (e1)
    {
        case 0:
            exp2 += 29;
            break;

        case 1:
            exp2 += 45;
            break;

        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += (29+45+75);
            break;
         
    }
    checkEXP(exp2);
    int D = 3*e1 + 7*exp1;
    float a = D/200.0;
    float b = D/100.0;
    switch (D%2)
    {
        case 0:
        exp1 =ceil((float)exp1 + a);
        checkEXP(exp1);
        break;

        case 1:
        exp1 =ceil((float)exp1 - b);
        checkEXP(exp1);
        break;
    }
    }
    else 
    {
       if (e1>=4 && e1<=19)
       {
        exp2 = ceil((float)exp2 +(e1/4.0 + 19));
        checkEXP(exp2);
        }       

        else if (e1>=20 && e1<=49)
        {
            exp2 = ceil((float)exp2 +e1/9.0 + 21);
            checkEXP(exp2);
        }

        else if (e1>=50 && e1<=65)
        {
            exp2 = ceil((float)exp2 + e1/16.0 + 17);
            checkEXP(exp2);
        }

        else if (e1>=66 && e1<=79){
            exp2 = ceil((float)exp2 + e1/4.0 + 19);
           
            checkEXP(exp2);
            if (exp2>200){
            exp2 = ceil((float)exp2 + e1/9.0 + 21);
            checkEXP(exp2);
            
            }
            }
        else if (e1>=80 && e1<=99){
            exp2 = ceil((float)exp2 + e1/4.0 + 19);
            exp2 = ceil((float)exp2 + e1/9.0 + 21);
            checkEXP(exp2);
            if (exp2>400){
                exp2 = ceil((float)exp2 + e1/16.0 + 17);
                exp2 = ceil((float)exp2 * 115.0/100.0);
                checkEXP(exp2);

            
        }
        }
        exp1 -=e1;
        checkEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);
    if (E2 < 0 || E2 > 99)
    return -99;
     
     float P1, P2, P3;

    // Road 1 start here
    int S = round(sqrt(EXP1));
    S *= S;
    if (EXP1>=S){
        P1 = 1;
    }
    else P1 = ((float)EXP1/S + 80.0)/123.0;
    
    // Road 2 start here

    // IF E2 is even
    if (E2%2==0){
        while(1){
          // EVENT 1
           if (HP1<200){
            HP1 = ceil((float)HP1*130.0/100.0);
            M1 -= 150;
            checkHP(HP1);
            checkM(M1);
           }
           else {
            HP1 = ceil((float)HP1*110.0/100.0);
            M1 -= 70;
            checkHP(HP1);
            checkM(M1);
           }
           if (M1 == 0)
           break;
           
           // EVENT 2
           if (EXP1<400)
           M1 -= 200;
           else M1 -= 120;
           checkM(M1);
           EXP1 = ceil((float)EXP1 * 113.0/100.0);
           checkEXP(EXP1);
           if (M1 == 0)
           break;

           // EVENT 3
           if (EXP1 < 300)
           M1 -=100;
           else M1 -= 120;
           checkM(M1);
           EXP1 = ceil((float)EXP1 * 90.0/100.0);
           checkEXP(EXP1);
           if (M1==0)
           break;

           break;
        }
        HP1 = ceil((float)HP1 * 83.0 /100.0);
        EXP1 = ceil((float)EXP1 * 117.0/100.0);
        checkHP(HP1);
        checkEXP(EXP1);

        
}
        //IF E2 is odd
       else {
        float Paidmoney = 0;
        float MaxPaid = M1 * 0.5;
        while(1){
          // EVENT 1
           if (HP1<200){
            HP1 = ceil((float)HP1*130.0/100.0);
            M1 -= 150;
            Paidmoney += 150;
            checkHP(HP1);
            checkM(M1);
           }
           else {
            HP1 = ceil((float)HP1*110.0/100.0);
            M1 -= 70;
            Paidmoney += 70;
            checkHP(HP1);
            checkM(M1);
           }
           if (Paidmoney > MaxPaid)
           break;
           
           // EVENT 2
           if (EXP1<400)
           {M1 -= 200;
           Paidmoney += 200;}
           else { 
            M1 -= 120;
            Paidmoney += 120;
            }

           checkM(M1);
           EXP1 = ceil((float)EXP1 * 113.0/100.0);
           checkEXP(EXP1);
           if (Paidmoney > MaxPaid)
           break;

           // EVENT 3
           if (EXP1 < 300){
           M1 -=100;
           Paidmoney += 100;}
           else {
            M1 -= 120;
            Paidmoney += 120;
            }
           checkM(M1);
           EXP1 = ceil((float)EXP1 * 90.0/100.0);
           checkEXP(EXP1);
           if (Paidmoney > MaxPaid)
           break;
           
}
            HP1 = ceil((float)HP1 * 83.0/100.0);
           EXP1 = ceil((float)EXP1 * 117.0/100.0);
           checkHP(HP1);
           checkEXP(EXP1);
           }

           int S2 = round(sqrt(EXP1));
        S2 *= S2;
        if (EXP1 >= S2)
        P2 = 1;
        else P2 = ((float)EXP1/S2 + 80.0)/123.0;



    // Road 3 start here
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2>=0 && E2<=9)
    P3= P[E2]/100.0;
    else {
        int sum= E2/10 + E2%10;
        int i = sum%10;
        P3=P[i];
    }
    // Final Result of the Mission 2
    float finalP = (P1+P2+P3)/3.0;
    if (finalP == 1){
        EXP1 = ceil((float)EXP1 * 75.0/100.0);
        checkEXP(EXP1);
    }
    else if (finalP < 0.5){
        HP1 = ceil((float)HP1 * 85.0/100.0);
        checkHP(HP1);
        EXP1 = ceil((float)EXP1 * 115.0/100.0);
        checkEXP(EXP1);
    }
    else {
        HP1 = ceil((float)HP1 * 90.0/100.0);
        checkHP(HP1);
        EXP1 = ceil((float)EXP1 * 120.0/100.0);
        checkEXP(EXP1);
    }


    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    
    if (E3 < 0 || E3 > 99)
    return -99;
    // Creating the map with Taxi's score calculation
    int Taxi [10][10]={0};
    for (int i = 0; i < 10; ++i){
        for (int j = 0; j<10; ++j){
            Taxi[i][j] = ((E3 * j)+(i*2))*(i-j);
        }
    }
    // Finding the meeting point
    int Count_i = 0, Count_j = 0;
     for (int i = 0; i < 10; ++i){
        for (int j = 0; j<10; ++j){
            if (Taxi[i][j] > (2*E3))
            Count_i += 1;
            if (Taxi[i][j] < (-E3))
            Count_j += 1;
            }
            }
    while(Count_i > 9 ){
        Count_i = Count_i/10 + Count_i%10; 
    }
    int i_Meet = Count_i;

    while(Count_j > 9 ){
        Count_j = Count_j/10 + Count_j%10; 
    }
    int j_Meet = Count_j;

    // Score of Sherlock and Watson at the meeting point
    int SW_Score = Taxi [i_Meet][j_Meet];
    int x = i_Meet, y = j_Meet;
    
        //Left diagonal 
    while ((x>=0 && x <= 9) && (y>=0 && y<=9)){
        if (SW_Score < Taxi[x][y])
        SW_Score = Taxi [x][y];
        x += 1;
        y += 1;
    }
    x= i_Meet;
    y= j_Meet;
    while ((x>=0 && x <= 9) && (y>=0 && y<=9)){
        if (SW_Score < Taxi[x][y])
        SW_Score = Taxi [x][y];
        x -= 1;
        y -= 1;
    }
    x= i_Meet;
    y= j_Meet;
        //Right diagonal
while ((x>=0 && x <= 9) && (y>=0 && y<=9)){
        if (SW_Score < Taxi[x][y])
        SW_Score = Taxi [x][y];
        x -= 1;
        y += 1;
    }
    x= i_Meet;
    y= j_Meet;
    while ((x>=0 && x <= 9) && (y>=0 && y<=9)){
        if (SW_Score < Taxi[x][y])
        SW_Score = Taxi [x][y];
        x += 1;
        y -= 1;
    }
    x= i_Meet;
    y= j_Meet;
    if (SW_Score<0)
    SW_Score = abs(SW_Score);

    // Final result
    int Result_3 = 0;
    if (SW_Score > abs(Taxi[i_Meet][j_Meet])){
        EXP1 = ceil((float)EXP1 * 112.0/100.0);
        EXP2 = ceil((float)EXP2 * 112.0/100.0);
        checkEXP(EXP1);
        checkEXP(EXP2);
        HP1 = ceil((float)HP1 * 110.0/100.0);
        HP2 = ceil((float)HP2 * 110.0/100.0);
        checkHP(HP1);
        checkHP(HP2);
        Result_3 = SW_Score;
    }
    else {
        EXP1 = ceil((float)EXP1 * 88.0/100.0);
        EXP2 = ceil((float)EXP2 * 88.0/100.0);
        checkEXP(EXP1);
        checkEXP(EXP2);
        HP1 = ceil((float)HP1 * 90.0/100.0);
        HP2 = ceil((float)HP2 * 90.0/100.0);
        checkHP(HP1);
        checkHP(HP2);
        Result_3 = Taxi[i_Meet][j_Meet];

    }

    return Result_3;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // Convert the inputs to strings
    string pass = s;
    string mail = email;
    string se;

    // Findding se
    int email_name_pos = mail.find("@");
    se = mail.substr(0,email_name_pos);

    // Checking if the password has more than 2 consecutive and identical characters  or not
    bool error_consecutive = 0;
    int error1_pos;
    for (int i = 0; i<pass.length(); ++i){
        if (pass[i]==pass[i+1] && pass[i+1] ==pass[i+2]){
            error_consecutive = 1;
            error1_pos = pass[i];
            break;
        }
    }
    // Checking if the password contains any invalid characters or not
    bool error_invalid = 0;
    int error2_pos;
    for (int i = 0; i < pass.length(); ++i){
        if ((pass[i] == '@') || (pass[i] == '#') || (pass[i] == '%') || (pass[i] == '$') || (pass[i] == '!') || (pass[i]>='0'&& pass[i] <='9') || (pass[i]>='a' && pass[i] <='z') || (pass[i]>='A' && pass[i] <='Z'))
        error_invalid = 0;
        else {
            error_invalid = 1;
            error2_pos = pass[i];
        }
    }

    //Checking if the password is valid
    if (pass.length() < 8) return -1;
     else if (pass.length() > 20) return -2;
     else if(pass.find(se) != -1) return (-300-pass.find(se));
     else if (error_consecutive == 1) return -(400+error1_pos);
     else if (error_invalid == 1) return (error2_pos);
        //Checking if password contain any special characters
    else if ((pass.find("@") == -1) && (pass.find("$") == -1) && (pass.find("%") == -1) && (pass.find("!") == -1) && (pass.find("#") == -1)) return -5;
    else return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int count[100];
    for (int i=0; i<100; i++)
    count[i] = 1;
    double repeat_index1 [100];
    string arr_pass [num_pwds];
    for (int i =0; i<num_pwds; ++i){
        arr_pass[i] = arr_pwds[i];
    }
   
    
    // Finding how many times each distinct password appears
    for (int i = 0; i < num_pwds; ++i){
        if(strcmp( arr_pwds[i], "0") == 0){
                
                continue;
         }
        for (int j = i+1;j < num_pwds; ++j){
            if( arr_pwds[i] == arr_pwds[j]){
                count[i]++;
                
                if (count[i] == 2){
                    repeat_index1[i] = i;
                }
                arr_pwds[j] = "0";
            }
        }
    }
    
    // Record the passwords that appeared the most and its position in the password array
    int MostTimes = 1;
    int Result5;
    int correct = 1;
    for (int i = 0; i< num_pwds; ++i){
        if (count[i] > MostTimes){
            MostTimes = count[i];
           
            Result5 = repeat_index1[i];
        }
        else if (count[i] ==  MostTimes){
            correct++;

        }
    }
    
   
    // If there are multiple passwords which all have the same most times appeared, find the longest among them
  
    for (int i = 0; i<num_pwds; ++i){
        if (count[i] != MostTimes)
        continue;
        for (int j = i+1; j < num_pwds; ++j){
            if (count[j] != MostTimes)
            continue;
            else if (arr_pass[i].length() >= arr_pass[j].length()){
            Result5 = repeat_index1[i];
            }
            else {
                Result5 = repeat_index1[j];
                
            }
         

    }
    
    }
    return Result5;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

