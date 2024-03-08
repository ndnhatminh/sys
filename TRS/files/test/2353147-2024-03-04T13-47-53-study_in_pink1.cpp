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

// Task 1
// CHECK THE CONDITION OF THE INPUTS IN TASK1,2,3
void adjust_Values(int &exp1, int &exp2, int &hp1, int &hp2, int &m) 
{
    if(exp1 <0) 
    {
        exp1 = 0;
    }
    if (exp2 <0)
    {
        exp2 = 0;
    }
    if (exp1 >600)
    {
        exp1 = 600;
    }
    if (exp2 >600)
    {
        exp2 = 600;
    }
    if (hp1 < 0){
        hp1 = 0;
    }
    if (hp1 >666){
        hp1 = 666;
    }
    if (hp2 < 0){
        hp1 = 0;
    }
    if (hp2 > 666){
        hp1 = 666;
    }
    if (m < 0){
        m = 0;
    }
    if(m>3000){
        m = 3000;
    }
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    //checkinput
    int HP1, HP2, M1 = 0;
    adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    if (E1 < 0 || E1 > 99) return -99;
    //declare variable
    int D;
    
    if(E1 >=0 && E1 <=3) //Case1
    {
        switch(E1)
        {
            case 0 :
            EXP2 += 29;
            break;
            case 1 :
            EXP2 += 45;
            break;
            case 2 :
            EXP2 += 75;
            break;
            case 3 :
            EXP2 += 149;
            break;
        }
        D = (E1*3) + (EXP1*7);
        if ((D%2) == 0)
        {
            EXP1 = ceil(double(EXP1) + double(D)/200);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
        }
        else 
        {
            EXP1 = ceil(double(EXP1) - double(D)/100);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
        }
    }
    else if(E1 >=4 && E1<=99) //Case 2
    {
        if(E1 >=4 && E1<=19)
        {
            EXP2 = ceil(EXP2 + double(E1)/4 + 19);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
        }
        if(E1 >=20 && E1<=49)
        {
            EXP2 = ceil(EXP2 + double(E1)/9 + 21);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
        }
        if(E1 >=50 && E1<=65)
        {
            EXP2 = ceil(EXP2 + double(E1)/16 + 17);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
        }
        if(E1 >=66 && E1<=79)
        {
            EXP2 = ceil(EXP2 + double(E1)/4 + 19);
            if (EXP2>200)
            {
                EXP2 = ceil(EXP2 + double(E1)/9 + 21);
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
            }
        }
        if(E1 >=80 && E1<=99)
        {
            EXP2 = ceil(EXP2 + double(E1)/4 + 19);
            EXP2 = ceil(EXP2 + double(E1)/9 + 21);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
            if(EXP2>400)
            {
                EXP2 = ceil(EXP2 + double(E1)/16 + 17);
                EXP2 = ceil(EXP2 + double(EXP2)*0.15);
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
            }
        }
        EXP1 -= E1;
    }
    adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    return EXP1 + EXP2;
}

// Task2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2){
    //check input
    int EXP2, HP2 = 0;
    adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    if (E2 > 99 || E2 < 0) return -99;
    //declare variables
    const int half_M1 = ceil(M1*0.5); //variable used if E2 is odd
    double P1= 0, P2 = 0, P3 = 0; //Success rate in 3 different road.
    int S1 = 0, S2 = 0; //the nearest square number of EXP1 in 3 different road;
    int M2_1_1 = 150, M2_1_2 = 70, M2_2_1 = 200, M2_2_2 = 120, M2_3_1 = 100, M2_3_2 = 120;//the money Sherlock spend in each event
    int total_money_spend = 0; //total money spend after a event in road 2

    //ROAD 1 - evaluate the road 1 success rate
    int D = 0;
    D = floor(sqrt(EXP1)); 
    if ((EXP1 - pow(D,2)) > (pow((D+1),2) - EXP1)){ //find the the nearest square number for road 1
        S1 = (D+1)*(D+1);
    }
    else S1 = D*D;

    if (EXP1 >= S1){
        P1 = 100;
    }
    else P1 = (((double(EXP1)/S1)+80)/123)*100;

    //ROAD 2 - evaluate the road 2 success rate due to 3 events
    adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    if ((E2%2) != 0) //odd number case
    {
        for(int k = 1; k > 0; k++)
        {
            if(M1 <=0)
            {
                break;
            }
        //Event 1
            if(HP1 < 200){
                HP1 = ceil(HP1 + double(HP1)*30.0/100);
                M1 = ceil(M1 - M2_1_1);
                total_money_spend += M2_1_1;
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);;
                if (total_money_spend > half_M1) break;
            }
            else {
                HP1 = ceil(HP1 + double(HP1)*10.0/100);
                M1 = ceil(M1 - M2_1_2);
                total_money_spend += M2_1_2;
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                if (total_money_spend > half_M1) break;
            }
        //Event 2
            if (EXP1 < 400){
                M1 = ceil(M1 - M2_2_1);
                EXP1 = ceil(EXP1 + double(EXP1)*13.0/100);
                total_money_spend += M2_2_1;
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                if (total_money_spend > half_M1) break;
            }
            else {
                M1 = ceil(M1 - M2_2_2);
                EXP1 = ceil(EXP1 + double(EXP1)*13.0/100);
                total_money_spend += M2_2_2;
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                if (total_money_spend > half_M1) break;
            }
        //Event 3 
            if (EXP1 < 300){
                M1 = ceil(M1 - M2_3_1);
                EXP1 = ceil(EXP1 - double(EXP1)*10.0/100);
                total_money_spend += M2_3_1;
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                if (total_money_spend > half_M1) break;
            }
            else {
                M1 = ceil(M1 - M2_3_2);
                EXP1 = ceil(EXP1 - double(EXP1)*10.0/100);
                total_money_spend += M2_3_2;
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                if (total_money_spend > half_M1) break;
            }
        }
        HP1 = ceil(HP1 - double(HP1)*17.0/100);
        EXP1 = ceil(EXP1 + double(EXP1)*17.0/100);
        adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    }
    else { //even number case
        //Event 1
            if(HP1 < 200){
                if(M1>0){
                HP1 = ceil(HP1 + double(HP1)*30.0/100);
                M1 = ceil(M1 - M2_1_1);
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                }
            }
            else {
                if(M1>0){
                HP1 = ceil(HP1 + double(HP1)*10.0/100);
                M1 = ceil(M1 - M2_1_2);
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                }
            }
        //Event 2
            if (EXP1 < 400){
                if(M1>0){
                M1 = ceil(M1 - M2_2_1);
                EXP1 = ceil(EXP1 + double(EXP1)*13.0/100);
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                }
            }
            else {
                if(M1>0){
                M1 = ceil(M1 - M2_2_2);
                EXP1 = ceil(EXP1 + double(EXP1)*13.0/100);
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                }
            }
        //Event 3 
            if (EXP1 < 300){
                if(M1>0){
                M1 = ceil(M1 - M2_3_1);
                EXP1 = ceil(EXP1 - double(EXP1)*10.0/100);
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                }
            }
            else {
                if(M1>0){
                M1 = ceil(M1 - M2_3_2);
                EXP1 = ceil(EXP1 - double(EXP1)*10.0/100);
                adjust_Values(EXP1, EXP2, HP1, HP2, M1);
                }
            }
            HP1 = ceil(HP1 - double(HP1)*17.0/100);
            EXP1 = ceil(EXP1 + double(EXP1)*17.0/100);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    }
    
    // find the the nearest square number for road 2
    double E = floor(sqrt(EXP1));
    if ((EXP1 - pow(E,2)) > (pow((E+1),2) - EXP1)){ 
        S2 = (E+1)*(E+1);
    }
    else S2 = E*E;
    // evaluate the road 2 success rate
    if (EXP1 >= S2){
        P2 = 100;
    }
    else P2 = (((double(EXP1)/S2)+80)/123)*100;
    adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    
    //ROAD 3  evaluate the road 3 success rate
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; //an array contains 10 probable values
    int i = 0; //index value of the probability
    if (E2 < 10)
    {
        i = E2; 
        P3 = P[i];
    }
    else {
        i = int(E2)/10 + E2%10;
        if(i<10){
            P3 = P[i];
        }
        else P3 = P[(i%10)];
    }
    
    // END FOR TASK2 
    if( P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(EXP1 - double(EXP1)*25.0/100);
        adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    }
    else {
        double avg_P = double(P1 + P2 + P3)/3;
        if(avg_P<50)
        {
            EXP1 = ceil(EXP1 + double(EXP1)*15.0/100);
            HP1 = ceil(HP1 - double(HP1)*15.0/100);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
        }
        else 
        {
            EXP1 = ceil(EXP1 + double(EXP1)*20.0/100);
            HP1 = ceil(HP1  - double(HP1)*10.0/100);
            adjust_Values(EXP1, EXP2, HP1, HP2, M1);
        }
    }
    adjust_Values(EXP1, EXP2, HP1, HP2, M1);
    return EXP1 + HP1 + M1;
}


// Task 3

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    //check input
    int M = 0;
    adjust_Values(EXP1, EXP2, HP1, HP2, M);
    if (E3 > 99 || E3 < 0) return -99;
    //declare variables
    int map_chasing[10][10];
    int sherlock_score[10][10];
    int count_pos = 0;
    int count_neg = 0;
    int i = 0;
    int j = 0;
    int left_diagonal_dir = 0;
    int right_diagonal_dir = 0;
    //Evaluate taxi's score
    for (int a = 0; a < 10; a++){
        for (int b = 0; b <10; b++)
        {
            map_chasing[a][b] = ((E3*b)+(a*2))*(a-b);
            if(map_chasing[a][b] > (E3*2) ){
                count_pos += 1;
            }
            if(map_chasing[a][b] < (-E3)){
                count_neg += 1;
            }
        }
    }
    //finding the dimensions of i and j at the meeting point
    if(count_pos < 10)
    {
        i = count_pos;
    }
    else {
        i = count_pos/10 + count_pos%10;
    }
    if(i >= 10)
    {
        i = i/10 + i%10;
    }
    if(count_neg < 10)
    {
        j = count_neg;
    }
    else {
        j = count_neg/10 + count_neg%10;
    }
    if(j >= 10)
    {
        j = j/10 + j%10;
    }
    //finding the max value for the left diagonal directions
    for(int m = 0; (i-m)>=0 && (j-m)>=0; m++) //the max value for the left diagonal directions above the meeting points
    {
        if(map_chasing[i-m][j-m]>left_diagonal_dir)
        {
            left_diagonal_dir=map_chasing[i-m][j-m];
        }
    }
    for(int m = 0; (i+m)<=9 && (j+m)<=9; m++)//the max value for the left diagonal directions beneath the meeting points
    {
        if(map_chasing[i+m][j+m]>left_diagonal_dir)
        {
            left_diagonal_dir=map_chasing[i+m][j+m];
        }
    }
    //finding the max value for the right diagonal directions
    for(int m = 0; (i+m)<=9 && (j-m)>=0; m++)//the max value for the right diagonal directions above the meeting points
    {
        if(map_chasing[i+m][j-m]>right_diagonal_dir)
        {
            right_diagonal_dir=map_chasing[i+m][j-m];
        }
    }
    for(int m = 0; (i-m)>=0 && (j+m)<=9; m++)//the max value for the right diagonal directions beneath the meeting points
    {
        if(map_chasing[i-m][j+m]>right_diagonal_dir)
        {
            right_diagonal_dir=map_chasing[i-m][j+m];
        }
    }
    //compare the left and right value for final Sherlock score
    if(left_diagonal_dir>right_diagonal_dir){
        sherlock_score[i][j]=left_diagonal_dir;
    }
    else sherlock_score[i][j] =right_diagonal_dir;
    int s = abs(sherlock_score[i][j]);
    int m = abs(map_chasing[i][j]);
    if (m > s)
    {
        HP1 = ceil(HP1 - double(HP1)*0.1);
        EXP1 = ceil(EXP1 - double(EXP1)*0.12);
        HP2 = ceil(HP2 - double(HP2)*0.1);
        EXP2 = ceil(EXP2 - double(EXP2)*0.12);
        adjust_Values(EXP1, EXP2, HP1, HP2, M);
        return map_chasing[i][j];
    }
    else {
        HP1 = ceil(HP1 + double(HP1)*0.1);
        EXP1 = ceil(EXP1 + double(EXP1)*0.12);
        HP2 = ceil(HP2 + double(HP2)*0.1);
        EXP2 = ceil(EXP2 + double(EXP2)*0.12);
        adjust_Values(EXP1, EXP2, HP1, HP2, M);
        return s;
    }
}
// Task 4

int checkPassword(const char *s, const char *email)
{
    char se[101];
    int position = 0;//position of string before '@' in email
    for (int i = 0; email[i]!='@';i++ ){
        se[position++] = email[i];
    }
    se[position] = '\0';

    //checking password
    //condition for the length
    int len =strlen(s);
    if ( len < 8 )
    {
        return -1;
    }
    if ( len > 20 )
    {
        return -2;
    }

    //condition for the same words of se in s
    const char* find_se =  strstr(s,se); //this string will contain the first position of the string se in s 
    if (find_se){
        return -(300 + (find_se - s));
    }

    //condition for more than 2 consecutive and identical characters.
    for (int sci = 0; sci < (len- 2) ; sci++){
        if ((s[sci] == s[sci+1] && s[sci] == s[sci+2])){
            return -(400 + sci);
            break;
        }
    }

    // check the string if it does not 5 special characters
    int special_count = 0;
    for (int i = 0; i <= strlen(s); i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' ||s[i] == '!'){
            special_count ++ ;
        }
    }
    if (special_count == 0){
    return -5;
    }

    //check the rest of invalid condition including the string s_con does not have number, lowercase letter, uppercase number or 5 of special characters
    bool check_invalid_character;
    int position_invalid_character = 0 ; 
    for (int i = 0; i < len; ++i){
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '@') || (s[i] == '#' )|| (s[i] == '%') || (s[i] == '$') || (s[i] == '!'))
        {
        check_invalid_character = true;
        } else {
            check_invalid_character = false;
            position_invalid_character = i;
            break;
        }
        
    }
    if(!check_invalid_character){
            return position_invalid_character;
        }
    return -10;
   
}
// Task 5

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    //declare variables
    int position_correctpass = -1;
    int frequency = 0;
    int max_frequency=0; 
    int length_max = 0;
    int length_i = 0; 
    
    for(int i = 0; i < num_pwds; i++){
        for (int k = 0; k <num_pwds; k++) 
        {
            if (strcmp(arr_pwds[i], arr_pwds[k]) == 0) //Evaluate the frequency of [i] password
            {
                frequency++;
            }
            
        }
        //finding the correct passwords
        length_i = strlen(arr_pwds[i]);
        if (frequency > max_frequency)
            {
                max_frequency = frequency;
                position_correctpass = i;
                length_max = length_i;
            }
        if (frequency == max_frequency)
            {
                if(length_i > length_max){
                    max_frequency = frequency;
                    position_correctpass = i;
                    length_max = strlen(arr_pwds[i]);
                }
            }
        frequency = 0; //Reset the frequency for the new loop
    }
    return position_correctpass;
}
void tc_1320()
{
cout << "----- Testcase 320 -----" << endl;
int E3 = 93, HP1 = 506, EXP1 = 86, HP2 = 243, EXP2 = 467;
cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
<< ", HP2: " << HP2 << ", EXP2: " << EXP2 << endl;

int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
<< ", HP2: " << HP2 << ", EXP2: " << EXP2
<< ", result: " << result
<< endl;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////