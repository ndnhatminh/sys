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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
     // TODO: Complete this function
      if(e1 < 0 || e1 > 99)
     return -99;
    exp1 = exp1 < 0 ? 0 : exp1;
    exp2 = exp2 < 0 ? 0 : exp2;
    exp1 = exp1 > 600 ? 600 : exp1;
    exp2 = exp2 > 600 ? 600 : exp2;
    if(e1 >=0 && e1 <=3)
    {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 +=45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 = exp2 + 29 + 45 + 75;
            break;
        }
        int D = e1*3 + exp1*7;
        if(D % 2 == 0)
        {
            exp1 += ceil(static_cast<double>(D)/200);
        }
        else{
            exp1 = ceil(exp1 - (static_cast<double>(D)/100));
        }
        exp1 = exp1 > 600 ? 600 : exp1;
        exp1 = exp1 < 0 ? 0 : exp1;
        exp2 = exp2 > 600 ? 600 : exp2;
    }
    else if(e1 >= 4 && e1 <= 99)
    {
        double temp1 = e1;
        if(e1 <= 19)
        {
            exp2 += ceil(temp1/4.0+19);
        }
        else if(e1 <= 49)
        {
            exp2 += ceil(temp1/9.0 + 21);
        }
        else if(e1 <= 65)
        {
            exp2 += ceil(temp1/16.0 + 17);
        }
        else if(e1 <= 79)
        {
            exp2 += ceil(temp1/4.0 + 19);
            if(exp2 > 200)
                exp2 += ceil(temp1/9.0+21);
        }
        else
        {
            exp2 = exp2 + ceil(temp1/4.0 + 19) + ceil(temp1/9.0 + 21);
            if (exp2 > 400){
                exp2 += ceil(temp1/16.0 + 17);
                exp2 = ceil(static_cast<double>(exp2)*115/100);
        }
    }
    exp2 = exp2 > 600 ? 600 : exp2;
    exp1 -= e1;
    exp1 = exp1 < 0 ? 0 : exp1;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
     // TODO: Complete this function
    //START PATH 1
     if(E3 < 0 || E3 > 99)
     return -99;
     HP1 = HP1 < 0 ? 0 : HP1;
    HP1 = HP1 > 666 ? 666 : HP1;
    EXP1 = EXP1 > 600 ? 600 : EXP1;
    EXP1 = EXP1 < 0 ? 0 : EXP1;
    M1 = M1 > 3000 ? 3000 : M1;
    M1 = M1 < 0 ? 0 : M1;
    double nearest_square_number1 = pow(round(sqrt(EXP1)),2);
    double P1;
    if(EXP1 >= nearest_square_number1){
        P1 = 100.0;
    }
    else
        P1 = ((static_cast<double>(EXP1)/nearest_square_number1)+80)/123*100;
    //END PATH 1
    //START PATH 2

    if(E3 % 2 == 1 && M1 != 0)
    {
        int payed_money = 0;
        double limited_money = (static_cast<double>(M1)/2);
        while(true){
        if(payed_money > limited_money)
        break;
        if(HP1 < 200)
        {
            HP1 = ceil(static_cast<double>(HP1)*130/100);
            M1 -= 150;
            payed_money +=150; 
        }
        else
        {
            HP1 = ceil(static_cast<double>(HP1)*110/100);
            M1 -= 70;
            payed_money += 70;
        }
        if(HP1 > 666)
            HP1 = 666;
        if(M1 < 0)
            M1 = 0;
        if(payed_money > limited_money)
        break;
        if(EXP1 < 400){
            M1 -= 200;
            payed_money +=200;
        } 
        else{
            M1 -= 120;
            payed_money +=120;
        } 
        if(M1 < 0)
            M1 = 0;
        EXP1 = ceil(static_cast<double>(EXP1)*113/100);
        if(EXP1 > 600)
            EXP1 = 600;
        if(payed_money > limited_money)
        break;
        if(EXP1 < 300)
        {
            M1 -= 100;
            payed_money += 100;
        }
        else
        {
            M1 -= 120;
            payed_money += 120;
        }
        EXP1 = ceil(static_cast<double>(EXP1)*90/100);
        if(M1 < 0)
            M1 =0;
        }
    }
    else
    {
        int i =1;
        while(i--){
        if(M1 <=0)
        {
            M1 = 0;
            break;
        }
        if(HP1 < 200)
        {
            HP1 = ceil(static_cast<double>(HP1)*130/100);
            M1 -= 150;
        }
        else
        {
            HP1 = ceil(static_cast<double>(HP1)*110/100);
            M1 -= 70;
        }
          if(HP1 > 666)
            HP1 = 666;
          if(M1 <=0)
        {
            M1 = 0;
            break;
        }
        if(EXP1 < 400){
            M1 -= 200;
        } 
        else{
            M1 -= 120;
        } 
         EXP1 = ceil(static_cast<double>(EXP1)*113/100);
          if(M1 <=0)
        {
            M1 = 0;
            break;
        }
        if(EXP1 > 600)
            EXP1 = 600;
        if(EXP1 < 300)
        {
            M1 -= 100;
        }
        else
        {
            M1 -= 120;
        }
           EXP1 = ceil(static_cast<double>(EXP1)*90/100);
        if(M1 <=0)
        {
            M1 = 0;
            break;
        }
        }
    }
    HP1 = ceil(static_cast<double>(HP1)*83/100);
    EXP1 = ceil(static_cast<double>(EXP1)*117/100);
    if(EXP1 > 600)
        EXP1 = 600;
    double nearest_square_number2 = pow(round(sqrt(EXP1)),2);
    double P2;
    if(EXP1 >= nearest_square_number2){
        P2 = 100.0;
    }
    else
        P2 = ((static_cast<double>(EXP1)/nearest_square_number2)+80)/123*100;
    //END PATH 2
    //START PATH 3
    double P[10]={32,47,28,79,100,50,22,83,64,11};
    double P3;
    if(E3 < 10 && E3 >= 0)
        P3 = P[E3];
    else if(E3>=10 && E3<=99)
    {
        int hang_chuc = E3/10;
        int hang_donvi = E3 % 10;
        int sum_donvi = (hang_chuc + hang_donvi)%10;
        P3 = P[sum_donvi]; 
    }
    if(P1 == 100.0 && P2 == 100.0 && P3 == 100.0)
    {
        EXP1 = ceil(static_cast<double>(EXP1)*75/100);
    }
    else
    {
        int aver_probabilty = ceil(static_cast<double>(P1 + P2 + P3) / 3);
        if(aver_probabilty < 50)
        {
            HP1 = ceil(static_cast<double>(HP1)*85/100);
            EXP1 = ceil(static_cast<double>(EXP1)*115/100);
        } 
        else
        {
            HP1 = ceil(static_cast<double>(HP1)*90/100);
            EXP1 = ceil(static_cast<double>(EXP1)*120/100);
        }
        if(EXP1 > 600)
            EXP1 = 600;

    }
    return HP1 + EXP1 + M1;
}

// Task 3
int add_num(int num)
{
    while(num >= 10)
    {
        int hang_donvi = num%10;
        int hang_chuc = num/10;
        num = hang_chuc+hang_donvi;
    }
    return num;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3 < 0 || E3 > 99)
     return -99;
    HP1 = HP1 < 0 ? 0 : HP1;
    HP1 = HP1 > 666 ? 666 : HP1;
    EXP1 = EXP1 > 600 ? 600 : EXP1;
    EXP1 = EXP1 < 0 ? 0 : EXP1;
    HP2 = HP2 < 0 ? 0 : HP2;
    HP2 = HP2 > 666 ? 666 : HP2;
    EXP2 = EXP2 > 600 ? 600 : EXP2;
    EXP2 = EXP2 < 0 ? 0 : EXP2;
    // TODO: Complete this function
    int matrix[10][10];
    int c = E3 * 2;
    int d = -E3;
    int a = 0;
    int b = 0;
    for(int i =0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3*j)+(i*2))*(i-j);
            if(matrix[i][j] > c)
                a++;
            else if(matrix[i][j] < d)
                b++;
        }
    }
    a = add_num(a);
    b = add_num(b);
    int point_taxi = matrix[a][b];
    int max_num = point_taxi;
    //right of top
    int temp_row = a;
    int temp_col = b;
    while(temp_row > 0 && temp_col < 9)
    {
        temp_row--;
        temp_col++;
        if(max_num < matrix[temp_row][temp_col])
            max_num = matrix[temp_row][temp_col];
    }
    //left of top
    temp_row = a;
    temp_col = b;
    while(temp_row > 0 && temp_col > 0)
    {
        temp_row--;
        temp_col--;
        if(max_num < matrix[temp_row][temp_col])
            max_num = matrix[temp_row][temp_col];
    }
    //right of bottom
    temp_row = a;
    temp_col = b;
    while(temp_row < 9 && temp_col < 9)
    {
        temp_row++;
        temp_col++;
        if(max_num < matrix[temp_row][temp_col])
            max_num = matrix[temp_row][temp_col];
    }
    //left of bottom
    temp_row = a;
    temp_col = b;
    while(temp_row < 9 && temp_col > 0)
    {
        temp_row++;
        temp_col--;
        if(max_num < matrix[temp_row][temp_col])
            max_num = matrix[temp_row][temp_col];
    }
    max_num = abs(max_num);
    if(abs(point_taxi) > max_num)
    {
        EXP1 = ceil(static_cast<double>(EXP1)*88/100);
        EXP2 = ceil(static_cast<double>(EXP2)*88/100);
        HP1 = ceil(static_cast<double>(HP1)*90/100);
        HP2 = ceil(static_cast<double>(HP2)*90/100);
        EXP1 = EXP1 > 600 ? 600 : EXP1;
        EXP2 = EXP2 > 600 ? 600 : EXP2;
        HP1 = HP1 > 666 ? 666 : HP1;
        HP2 = HP2 > 666 ? 666 : HP2;
        return point_taxi;
    }
    else
    {
        EXP1 = ceil(static_cast<double>(EXP1)*112/100);
        EXP2 = ceil(static_cast<double>(EXP2)*112/100);
        HP1 = ceil(static_cast<double>(HP1)*110/100);
        HP2 = ceil(static_cast<double>(HP2)*110/100);
        EXP1 = EXP1 > 600 ? 600 : EXP1;
        EXP2 = EXP2 > 600 ? 600 : EXP2;
        HP1 = HP1 > 666 ? 666 : HP1;
        HP2 = HP2 > 666 ? 666 : HP2;
        return max_num;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
     // TODO: Complete this function
    //check length
    int password_length = strlen(s);
    if(password_length < 8)
        return -1;
    else if(password_length > 20)
        return -2;
    //check se
    string se="";
    for(int i = 0;email[i] != '@'; i++)
    {
        se += email[i];
    }
    string str_password="";
    for(int i = 0;i < password_length; i++)
    {
        str_password += s[i];
    }
    size_t pos = str_password.find(se);
    if(pos != string::npos)
    {
        return -(300+pos);
    }
    //check continously, similarly
    for(int i = 0; i < password_length-2; i++)
    {
        if(s[i] == s[i+1] && s[i+1] == s[i+2])
        {
            return -(400+i);
        }
    }
    //check special character
    bool find_special = false;
    string special_char = "@#%$!";
    for(char c : special_char)
    {
        if(str_password.find(c) != string::npos)
            find_special = true;
    }
    if(!find_special)
        return -5;
    //the other case
    for(int i =0; i < password_length; i++)
    {
        if(!isalpha(s[i]) && !isalnum(s[i]))
        {
            if(special_char.find(s[i])==string::npos)
            return i;
        }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max_freq = 0;
    int max_len = 0;
    int max_index = 0;
    int freq[200] = {0};

    for (int i = 0; i < num_pwds; ++i) {
        freq[i] = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++freq[i];
            }
        }

        if (freq[i] > max_freq || (freq[i] == max_freq && strlen(arr_pwds[i]) > max_len)) {
            max_freq = freq[i];
            max_len = strlen(arr_pwds[i]);
            max_index = i;
        }
    }

    return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////