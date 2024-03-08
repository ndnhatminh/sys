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
int check_legit(int a, string hehe)
{
   if(a < 0)
   {
     return 0;
   }
   if( hehe == "hp")
   {
      if(a > 666)
      {
        return 666;
      }
   }
   else if(hehe == "exp")
   {
    if(a > 600)
      {
        return 600;
      }
   }
   else if(hehe == "money")
   {
    if(a > 3000)
      {
        return 3000;
      }
   }
   return a;
}
int find_max(int taxi[][10], int row , int column)
{
    int right_x = row;
    int right_y = column;
    int left_x = row;
    int left_y = column;
   
    while(right_x < 9 && right_x > 0 && right_y < 9 && right_y > 0)
    {
        right_x--;
        right_y++;
    }
    while(left_x < 9 && left_x > 0 && left_y < 9 && left_y > 0)
    {
        left_x--;
        left_y--;
    }
    int max_left = taxi[left_x][left_y];
    int max_right = taxi[right_x][right_y];
    while(right_x <= 9 && right_x >= 0 && right_y <= 9 && right_y >= 0)
    {
        if(taxi[right_x][right_y] > max_right)
        {
            max_right = taxi[right_x][right_y];
        }
        right_x++;
        right_y--;
    }
     while(left_x <= 9 && left_x >= 0 && left_y <= 9 && left_y >= 0)
    {
        if(taxi[left_x][left_y] > max_left)
        {
            max_left = taxi[left_x][left_y];
        }
        left_x++;
        left_y++;
    }
    int max1 = max(max_left,max_right);
    if(max1 < 0)
    {
        max1 = abs(max1);
    }
    return max1;

}
int find_sum(int num)
{
    if(num == 100)
    {
        return 1;
    }
    string h = to_string(num);
    if(h.length() == 2)
    {
        int sum = num%10 + (num/10)%10;
        if(sum <= 9)
        {
            return sum;
        }
        else if(sum > 9)
        {
            int result = sum%10 + (sum/10)%10;
            return result;
        }
    }
    return num;
}
int myCeil(float num) {
    float eps = 1e-5f;
    float intNum = static_cast<int>(num);
    
    if (num > intNum + eps)
        return intNum + 1; 
    else
        return intNum;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //case 1
    if(e1 < 0 || e1 > 99)
    {
        return -99;
    }
    exp1 = check_legit(exp1,"exp");
    exp2 = check_legit(exp2,"exp");
    if( e1 >= 0 && e1 <= 3)
    {
        if(e1 == 0)
        {
            exp2 += 29;
        }
        else if(e1 == 1)
        {
            exp2 += 45;
        }
        else if(e1 == 2)
        {
            exp2 += 75;
        }
        else
        {
            exp2 = exp2 + 29 + 45 + 75;
        }
        exp2 = check_legit(exp2,"exp");
        int d = e1*3 + exp1*7;
        if(d%2 == 0)
        {
            exp1 = myCeil( float(exp1) + d/200.0);
            exp1 = check_legit(exp1,"exp");
        }
        else if(d%2 == 1)
        {
            exp1 = myCeil( float(exp1) - d/100.0);
            exp1 = check_legit(exp1,"exp");
        }
    }
    //case2 
    else if(e1 >= 4 && e1 <= 99)
    {
        if(e1 >= 4 && e1 <= 19)
        {
            exp2 = myCeil(exp2 + e1/4.0 + 19);
            exp2 = check_legit(exp2,"exp");
        }
        else if(e1 >= 20 && e1 <= 49)
        {
            exp2 = myCeil(exp2 + e1/9.0 + 21);
            exp2 = check_legit(exp2,"exp");
        }
        else if( e1 >= 50 && e1 <= 65)
        {
            exp2 = myCeil(exp2 + e1/16.0 + 17);
            exp2 = check_legit(exp2,"exp");
        }
        else if(e1 >= 66 && e1 <= 79)
        {
            exp2 = myCeil(exp2 + e1/4.0 + 19);
            exp2 = check_legit(exp2,"exp");
            if(exp2 > 200)
            {
                exp2 = myCeil(exp2 + e1/9.0 + 21);
                exp2 = check_legit(exp2,"exp");
            }
        }
        else if(e1 >= 80 && e1 <= 99)
        {
            exp2 = myCeil(exp2 + e1/4.0 + 19);
            exp2 = check_legit(exp2,"exp");
            exp2 = myCeil(exp2 + e1/9.0 + 21);
            exp2 = check_legit(exp2,"exp");
            if(exp2 > 400)
            {
                exp2 = myCeil(exp2 + e1/16.0 + 17);
                exp2 = check_legit(exp2,"exp");
                exp2 = myCeil(exp2 + exp2*(0.15));
                exp2 = check_legit(exp2,"exp");
            }
        }
        exp1 = exp1 - e1;
        exp1 = check_legit(exp1,"exp");
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int&  EXP1, int& M1, int E2) {
    // TODO: Complete this function
    //road1
    if(E2 < 0 || E2 > 99 )
    {
        return -99;
    }
    HP1 = check_legit(HP1,"hp");
    EXP1 = check_legit(EXP1,"exp");
    M1 = check_legit(M1,"money");
    double P1;
    int kk = round( sqrt(EXP1));
    double s = pow(kk,2);
    if(EXP1 >= s)
    {
       P1 = 1;
    }
    else if(EXP1 < s)
    {
        P1 = (EXP1/s + 80)/123.0;
    }
    //road2                                 
    if(E2%2 == 1)
    {
      int half_money = M1/2;
      int spend_money = 0;
      while(true)
      {
            if(M1 == 0)
            {
                break;
            }
            if(HP1 < 200)
            {
                HP1 = myCeil(HP1 + 0.3*HP1);
                HP1 = check_legit(HP1,"hp");
                M1-=150;
                spend_money += 150;
                M1 = check_legit(M1,"money");
            }
            else if(HP1 >= 200)
            {
                HP1 = myCeil(HP1 + 0.1*HP1);
                HP1 = check_legit(HP1,"hp");
                M1-=70;
                spend_money += 70;
                M1 = check_legit(M1,"money");
            }
            if(spend_money > half_money)
            {
                break;
            }
            if(EXP1 < 400)
            {
                M1 -= 200;
                spend_money += 200;
                M1 = check_legit(M1,"money");
               EXP1 = myCeil(EXP1 + EXP1*0.13);
               EXP1 = check_legit(EXP1, "exp");
            }
            else if(EXP1 >= 400)
            {
                M1 -= 120;
                spend_money += 120;
                M1 = check_legit(M1,"money");
                EXP1 = myCeil(EXP1 + EXP1*0.13);
                EXP1 = check_legit(EXP1, "exp");
            }
             if(spend_money > half_money)
            {
                break;
            }
            if(EXP1 < 300)
            {
                M1 -= 100;
                spend_money += 100;
                M1 = check_legit(M1,"money");
                EXP1 = myCeil(EXP1 - EXP1*0.1);
                EXP1 = check_legit(EXP1,"exp");
            }
            else if(EXP1 >= 300)
            {
                M1 -= 120;
                spend_money += 120;
                M1 = check_legit(M1,"money");
                EXP1 = myCeil(EXP1 - EXP1*0.1);
                EXP1 = check_legit(EXP1,"exp");
            }
             if(spend_money > half_money)
            {
                break;
            }
      }
      HP1 = myCeil(HP1 - HP1*0.17);
      HP1 = check_legit(HP1,"hp");
      EXP1 = myCeil(EXP1 + EXP1*0.17);
      EXP1 = check_legit(EXP1,"exp");
    }
    else if(E2 % 2 == 0)
    {
            if(HP1 < 200 && M1 > 0)
            {
                HP1 = myCeil(HP1 + 0.3*HP1);
                HP1 = check_legit(HP1,"hp");
                M1-=150;
                M1 = check_legit(M1,"money");
            }
            else if(HP1 >= 200 && M1 > 0)
            {
                HP1 = myCeil(HP1 + 0.1*HP1);
                HP1 = check_legit(HP1,"hp");
                M1-=70;
                M1 = check_legit(M1,"money");
            }
            if(EXP1 < 400 && M1 > 0)
            {
                M1 -= 200;
                M1 = check_legit(M1,"money");
               EXP1 = myCeil(EXP1 + EXP1*0.13);
               EXP1 = check_legit(EXP1, "exp");
            }
            else if(EXP1 >= 400 && M1 > 0)
            {
                M1 -= 120;
                M1 = check_legit(M1,"money");
                EXP1 = myCeil(EXP1 + EXP1*0.13);
                EXP1 = check_legit(EXP1, "exp");
            }
            if(EXP1 < 300 && M1 > 0)
            {
                M1 -= 100;
                M1 = check_legit(M1,"money");
                EXP1 = myCeil(EXP1 - EXP1*0.1);
                EXP1 = check_legit(EXP1,"exp");
            }
            else if(EXP1 >= 300 && M1 > 0)
            {
                M1 -= 120;
                M1 = check_legit(M1,"money");
                EXP1 = myCeil(EXP1 - EXP1*0.1);
                EXP1 = check_legit(EXP1,"exp");
            }
            HP1 = myCeil(HP1 - HP1*0.17);
            HP1 = check_legit(HP1,"hp");
            EXP1 = myCeil(EXP1 + EXP1*0.17);
            EXP1 = check_legit(EXP1,"exp"); 
      }
    double P2;
    int hh = round( sqrt(EXP1));
    double s2 = pow(hh,2);
    if(EXP1 >= s2)
    {
       P2 = 1;
    }
    else if(EXP1 < s2)
    {
        P2 = (EXP1/s + 80)/123.0;
    }
    //road3
    int P[] = {32,47,28,79,100,50,22,83,64,11};
    double P3;
    string h = to_string(E2);
    if(h.length() == 1)
    {
        P3 = P[E2]/100.0;
    }
    else if(h.length() == 2)
    {
        int a = E2%10;
        int b = (E2/10)%10;
        int c = (a+b)%10;
        P3 = P[c]/100.00;
    }
    if(P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = myCeil(EXP1 - EXP1*0.25);
        EXP1 = check_legit(EXP1,"exp");
    }
    else
    {
        double P_aver = (P1 + P2 + P3)/3.00;
        if(P_aver < 0.5)
        {
              HP1  = myCeil( HP1 -HP1*0.15);
               HP1 = check_legit(HP1,"hp");
              EXP1 = myCeil(EXP1 + EXP1*0.15);
              EXP1 = check_legit(EXP1,"exp");
        }
        else if(P_aver >= 0.5)
        {
            HP1  = myCeil( HP1 - HP1*0.1);
            HP1 = check_legit(HP1,"hp");
            EXP1 = myCeil(EXP1 + EXP1*0.2);
            EXP1 = check_legit(EXP1,"exp");
        }
    }
  return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99)
    {
        return -99;
    }
    HP1 = check_legit(HP1,"hp");
    HP2 = check_legit(HP2,"hp");
    EXP1 = check_legit(EXP1,"exp");
    EXP2 = check_legit(EXP2,"exp");
    int taxi[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    int count_more = 0;
    int count_less = 0;
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            taxi[i][j] = ((E3*j) + (i*2))*(i-j);
            if(taxi[i][j] > E3*2)
            {
                count_more++;
            }
            else if(taxi[i][j] < -E3)
            {
                count_less++;
            }
        }
    }
    int home[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            home[i][j] = find_max(taxi,i,j);
        }
    }
    int x = find_sum(count_more);
    int y = find_sum(count_less);
    int taxi_point = abs(taxi[x][y]);
    int home_point = home[x][y];
    if(taxi_point <= home_point)
    {
        EXP1 = myCeil(EXP1 + 0.12*EXP1);
        EXP1 = check_legit(EXP1,"exp");
        EXP2 = myCeil(EXP2 + 0.12*EXP2);
        EXP2 = check_legit(EXP2,"exp");
        HP1 = myCeil(HP1 + 0.1*HP1);
        HP1 = check_legit(HP1,"hp");
        HP2 =  myCeil(HP2 + 0.1*HP2);
        HP2 = check_legit(HP2,"hp");
        return home[x][y];
    }
    EXP1 = myCeil(EXP1- 0.12*EXP1);
    EXP1 = check_legit(EXP1,"exp");
    EXP2 = myCeil(EXP2 - 0.12*EXP2);
    EXP2 = check_legit(EXP2,"exp");
    HP1 = myCeil(HP1 - 0.1*HP1);
    HP1 = check_legit(HP1,"hp");
    HP2 = myCeil(HP2 - 0.1*HP2);
    HP2 = check_legit(HP2,"hp");
    return taxi[x][y];
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string gmail = email;
    string pass = s;
    int found = gmail.find("@");
    string se = gmail.substr(0,found);
    if(pass.length() < 8)
    {
       return -1;
    }
    if(pass.length() > 20)
    {
        return -2;
    }
    int count_same = 1;
    int count_special = 0;
    if(pass.find(se) != string::npos)
    {
        return -(300 + pass.find(se));
    }
    else
    {
        for (int i = 2; i < pass.length(); i++) {
        if (pass[i] == pass[i - 1] && pass[i] == pass[i - 2]){
            int result = -(400 + i - 2);
              return result; 
        }
        }
            
       for(int i = 0 ; i < pass.length(); i++)
      {
         if(pass[i] == '@' || pass[i] == '#' || pass[i] == '%' || pass[i] == '$' || pass[i] == '!')
         {
            count_special++;
         }
      }
      if(count_special == 0 && (pass[0] != '@' && pass[0] != '%' && pass[0] != '#' && pass[0] != '$' && pass[0] != '!' ) )
      {
        return -5;
      }
    }
    for(int i = 0; i < pass.length() ; i++)
    {
        if(!isalnum(pass[i]) && pass[i] != '@' && pass[i] != '#' && pass[i] != '%' && pass[i] != '$' && pass[i] != '!')
        {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string sample[num_pwds];
    for(int i = 0 ;i < num_pwds ; i++)
    {
        sample[i] = arr_pwds[i];
    }
    int max_count = 0;
    int index = 0;
    string result = "";
    for(int i = 0 ; i < num_pwds ; i++)
    {
        int count = 1;
        if(i == num_pwds - 1)
        {
            count =1;
        }
        else if(i != num_pwds - 1)
        {
            for(int j = i + 1; j < num_pwds; j++)
            {
                if(sample[i] == sample[j])
                {
                    count++;
                }
            }
        }
        if(count > max_count)
        {
            max_count = count;
            index = i;
            result = sample[i];
        }
        else if(count == max_count && (sample[i].length() > result.length()))
        {
           max_count = count;
           index = i;
           result = sample[i];
        }
    }
    return index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////