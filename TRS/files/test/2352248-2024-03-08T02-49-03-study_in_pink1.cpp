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
int checkthevalue(int value, int max)
{
    if (value <0)
    {
        return 0;
    } else if( value > max)
    {
        return max;
    } else 
    {
        return value;
    }
}
void setthelimit(int & hp, int & exp, int & m)
{
    hp = checkthevalue(hp, 666);
    exp = checkthevalue(exp, 600);
    m = checkthevalue(m, 3000);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

   int hp = 666;
    int m = 3000;
    setthelimit(hp, exp1, m);
    setthelimit(hp, exp2, m);
   
    if ( e1 >= 0 && e1 <=3 )
    {
    setthelimit(hp, exp1, m);
    setthelimit(hp, exp2, m);
        if( e1 == 0){ 
            exp2 += 29;
        } else if(e1 == 1)
        {
            exp2 += 45;
        }else if(e1 == 2)
        {
            exp2 += 75;
        } else if(e1 == 3)
        {
            exp2 += 75+29+45;
        }
    
    int D = e1 * 3 + exp1 * 7;
    if (D%2==0)
    {
        exp1 = ceil(exp1+(D*1.0/200));
    } else 
    {
        exp1 = ceil(exp1-(D*1.0/100));
    }
    setthelimit(hp, exp1, m);
    setthelimit(hp, exp2, m);
    }

    if (e1 >= 4 && e1 <= 99)
    {
    setthelimit(hp, exp1, m);
    setthelimit(hp, exp2, m);
    if ( e1 >= 4 && e1 <= 19)
    {
        exp2+= ceil(e1*1.0/4 + 19);
         setthelimit(hp, exp2, m);
    } else if (e1 >= 20 && e1 <= 49 )
    {
         exp2+= ceil(e1*1.0/9 + 21);
          setthelimit(hp, exp2, m);
    } else if (e1 >= 50 && e1 <= 65)
    {
        exp2+= ceil(e1*1.0/16 + 17);
         setthelimit(hp, exp2, m);
    } else if (e1 >= 66 && e1 <= 79)
    {
        exp2+= ceil(e1*1.0/4 + 19);
         setthelimit(hp, exp2, m);
        if( exp2 > 200)
        {
            exp2+= ceil(e1*1.0/9 + 21);
             setthelimit(hp, exp2, m);
        }
    } else if (e1 >= 80 && e1 <= 99)
    {
         exp2+= ceil(e1*1.0/4 + 19);
          setthelimit(hp, exp2, m);
          exp2+= ceil(e1*1.0/9 + 21);
           setthelimit(hp, exp2, m);
          if( exp2 > 400)
          {
            exp2+= ceil(e1*1.0/16 + 17);
             setthelimit(hp, exp2, m);
          exp2 = ceil((exp2 + 0.15*exp2)*1.0);
           setthelimit(hp, exp2, m);
          }
    }
     exp1 = exp1 - e1;
     setthelimit(hp, exp1, m);
    } else if(  e1 < 0 || e1 > 99) {
    return -99;
    }
    return exp1 + exp2;
}

int closestsquarenumber(int value)
{
    int closestsquare;
    int number = (sqrt(value));
    if (abs(value - number*number) < abs((number + 1)*(number + 1) - value))
    {
    closestsquare = (number + 1)*(number + 1);
    } else {
        closestsquare =  number*number;
    }
    return closestsquare;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
   setthelimit(HP1, EXP1, M1);

    if(E2 < 0 || E2 > 99)
    {
        return -99;
    } 
    
    int S = closestsquarenumber(EXP1);
    double P1;
    if(EXP1 >= S)
    {
        P1 = 100.0;
    } else 
    {
        P1 = ((EXP1*1.0/S + 80) / 123.0)*100.0;
    }

    int total_money_spent = 0;
    double half_of_money = 0.5*M1;
    if (E2 % 2 != 0)
    {
        while (true)
        {
            if( HP1 < 200)
            {
                HP1 = ceil( (1.0*HP1) * 1.3 );
                M1 = M1 - 150;
               total_money_spent += 150;
                setthelimit(HP1, EXP1, M1);
            } else 
            {
                HP1 = ceil( (HP1*1.0) * 1.1 );
                 M1 = M1 - 70;
                total_money_spent += 70;
                setthelimit(HP1, EXP1, M1);
            } 
            
            if( total_money_spent > half_of_money)
            {
                break;
            }

            if (EXP1 < 400)
            {
                EXP1 = ceil( (EXP1 * 1.0) * 1.13 );
                M1 = M1 - 200;
                total_money_spent += 200;
                setthelimit(HP1, EXP1, M1);
            } else 
            {
                EXP1 = ceil( (EXP1 * 1.0) * 1.13 );
                M1 = M1 - 120;
                total_money_spent += 120;
                setthelimit(HP1, EXP1, M1);
            }
            
            if( total_money_spent > half_of_money)
            {
                break;
            }

            if( EXP1 < 300)
            {
            M1 = M1 - 100;
            EXP1 = ceil(( EXP1 * 1.0) - 0.1*(EXP1*1.0));
            setthelimit(HP1, EXP1, M1);
            } else 
            {
            M1 = M1 - 120;
            EXP1 = ceil(( EXP1 * 1.0) - 0.1*(EXP1*1.0));
            setthelimit(HP1, EXP1, M1);
            }

            if( total_money_spent > half_of_money)
            {
                break;
            } 
        }
        HP1 = ceil((HP1 * 1.0) - 0.17*(HP1 * 1.0));
        EXP1 = ceil(( EXP1 * 1.0) + 0.17*(EXP1*1.0));
        setthelimit(HP1, EXP1, M1);
    }
    
    if( E2 % 2 == 0)
    {
        for( int i = 0; i<1; i++)
        {

            if( HP1 < 200)
            {
                HP1 = ceil( (1.0*HP1) * 1.3 );
                M1 = M1 - 150;
               total_money_spent += 150;
                setthelimit(HP1, EXP1, M1);
            } else 
            {
                HP1 = ceil( (HP1*1.0) * 1.1 );
                 M1 = M1 - 70;
                total_money_spent += 70;
                setthelimit(HP1, EXP1, M1);
            } 
            
            if( M1 <= 0)
            {
                break;
            }

            if (EXP1 < 400)
            {
                EXP1 = ceil( (EXP1 * 1.0) * 1.13 );
                M1 = M1 - 200;
                total_money_spent += 200;
                setthelimit(HP1, EXP1, M1);
            } else 
            {
                EXP1 = ceil( (EXP1 * 1.0) * 1.13 );
                M1 = M1 - 120;
                total_money_spent += 120;
                setthelimit(HP1, EXP1, M1);
            }
            
            if( M1 <= 0)
            {
                break;
            }

            if( EXP1 < 300)
            {
            M1 = M1 - 100;
            EXP1 = ceil(( EXP1 * 1.0) - 0.1*(EXP1*1.0));
            setthelimit(HP1, EXP1, M1);
            } else 
            {
            M1 = M1 - 120;
            EXP1 = ceil(( EXP1 * 1.0) - 0.1*(EXP1*1.0));
            setthelimit(HP1, EXP1, M1);
            }

            if( M1 <= 0)
            {
                break;
            }
        }
         HP1 = ceil((HP1 * 1.0) - 0.17*(HP1 * 1.0));
            EXP1 = ceil(( EXP1 * 1.0) + 0.17*(EXP1*1.0));
             setthelimit(HP1, EXP1, M1);
    }

    int S2 = closestsquarenumber(EXP1);
    double P2;
    if(EXP1 >= S2)
    {
        P2 = 100.0;
    } else 
    {
        P2 = ((EXP1*1.0/S + 80) / 123.0)*100.0;
    }
 
    int double[10] = { 32.0, 47.0, 28.0, 79.0, 100.0, 50.0, 22.0, 83.0, 64.0, 11.0 };
    double P3, totalP;
        if (E2 >= 0 && E2 <= 9)
        {
           int i = E2;
           P3 = arr[i];
        } else if (E2 >= 10 && E2 <= 99)
        {
            int sum = (E2 / 10) + (E2 % 10);
            int number = sum % 10;
            int i = number;
            P3 = arr[number];
        }
    
    if( P1 == 100.0 && P2 == 100.0 && P3 == 100.0)
    {
        EXP1 = ceil(( EXP1 * 1.0) - 0.25*(EXP1*1.0));
        setthelimit(HP1, EXP1, M1);
    } else 
    {
        totalP = (P1 + P2 + P3) / 3;
    }
    if ( totalP < 50)
    {
         HP1 = ceil((HP1 * 1.0) - 0.15*(HP1 * 1.0));
         EXP1 = ceil(( EXP1 * 1.0) + 0.15*(EXP1*1.0));
         setthelimit(HP1, EXP1, M1);
    } else 
    {
        HP1 = ceil((HP1 * 1.0) - 0.1*(HP1 * 1.0));
        EXP1 = ceil(( EXP1 * 1.0) + 0.2*(EXP1*1.0));
        setthelimit(HP1, EXP1, M1);
    }
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
   int M1 = 3000;
    int M2 = 3000;
     setthelimit(HP1, EXP1, M1);
     setthelimit(HP2, EXP2, M2);

int taxi_point[10][10] = {0};
int bigger = 0; 
int smaller = 0;
    for(int i=0; i<10; i++) {
        for (int j=0; j<10; j++)
        {
        taxi_point[i][j] = ((E3 * j) + (i * 2)) * (i-j);
        if (taxi_point[i][j] > 2*E3 )
        {
            bigger++;
        }
        if(taxi_point[i][j] < E3*(-1))
        {
            smaller++;
        }
        }
    }
    int pos_i; int pos_j;
    int i; int j;
    
       while(bigger >= 10 || smaller >=10)
       {
        i = (bigger/10)+(bigger%10);
        bigger = i;
        j = (smaller/10) + (smaller%10);
        smaller = j;
       if( i < 10)
       {
        pos_i = i;
       }
       if( j < 10)
       {
        pos_j = j;
       }
       }

    
    int sherlock_point = taxi_point[pos_i][pos_j];
    for(int i = pos_i - 1; i>=0 ; i--)
    {
        for(int j = pos_j -1; j>=0; j--)
        {
            if (i >= 0 && i < 10 && j >= 0 && j < 10) 
            {
        sherlock_point = max(sherlock_point, taxi_point[i][j]);
            } else 
            {
        break;  
        }
        }
    for(int i = pos_i + 1; i < 10; i++)
    {
        for (int j = pos_j - 1; j >= 0; j--)
        {
            if (i >= 0 && i < 10 && j >= 0 && j < 10) 
            {
        sherlock_point = max(sherlock_point, taxi_point[i][j]);
            } else 
            {
        break;  
        }
    }
    }
    for (int i = pos_i + 1; i < 10; i++)
    {
        for (int j = pos_j + 1; j < 10; j++)
        {
            if (i >= 0 && i < 10 && j >= 0 && j < 10) 
            {
        sherlock_point = max(sherlock_point, taxi_point[i][j]);
            } else 
            {
        break;  
        }
        }
    }
    for (int i = pos_i - 1; i>=0 ; i--)
    {
        for (int j = pos_j + 1; j < 10; j++)
        {
            if (i >= 0 && i < 10 && j >= 0 && j < 10) 
            {
        sherlock_point = max(sherlock_point, taxi_point[i][j]);
            } else 
            {
        break;  
        }
        }
    }
    }
    int bigger_point;
    if(abs(taxi_point[pos_i][pos_j]) <= sherlock_point)
    {
        EXP1 = (EXP1 + 0.12*EXP1)*1.0;
        HP1  = (HP1 + 0.1*HP1)*1.0;
         setthelimit(HP1, EXP1, M1);
         EXP2 = (EXP2 + 0.12*EXP2)*1.0;
         HP2  = (HP2 + 0.1*HP2)*1.0;
          setthelimit(HP2, EXP2, M1);
        bigger_point = sherlock_point;
    } 
    if (abs(taxi_point[pos_i][pos_j]) > sherlock_point)
    {
        EXP1 = (EXP1 - 0.12*EXP1)*1.0;
        HP1  = (HP1 - 0.1*HP1)*1.0;
         setthelimit(HP1, EXP1, M1);
         EXP2 = ceil((EXP2 - 0.12*EXP2)*1.0);
         HP2  = ceil((HP2 - 0.1*HP2)*1.0);
          setthelimit(HP2, EXP2, M1);
        bigger_point = taxi_point[pos_i][pos_j];
    }
    return bigger_point;
}
string getthese(const char * str, int index, int length)
{
    string newstr(str);
    if(index < 0 || index > newstr.length())
    {
        return "Invalid.";
    } else 
    {
        return newstr.substr(index, length);
    }
}
bool checkpassword(string &s)
{
    for(int i=0; i < s.length(); i++)
    {
    if (!(isdigit(s[i]) || islower(s[i]) || isupper(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
    {
        return false;
    } 
    }
        return true;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    string new_s(s);
    string newemail(email);
    int position = newemail.find('@');
    for (int i=0; i < newemail.length(); i++)
    {
        if (position != string::npos)
    {
        se = getthese(email,0,position);
    }
    }
    if (new_s.length() < 8)
    {
        return -1;
    } else if (new_s.length() > 20)
    {
        return -2;
    } 
    size_t found = new_s.find(se);
        if (found != string::npos) 
        {
            return -(300 + found);
        } 
    for (int i=0 ; i < new_s.length(); i++ )
    {
    if (new_s[i] == new_s[i+1] && new_s[i] == new_s[i+2])
    {
        return (-400 + i);
    }
    }
    bool has_se = false;
    for(int i=0; i < new_s.length(); i++)
    {
        if(new_s[i] = '@' && new_s[i] != '#' &&  new_s[i] != '%' &&  new_s[i] != '$' &&  new_s[i] != '!')
        {
        has_se = true;
        }
    }
    if(!has_se)
    {
        return -5;
    }
    for(int i=0; i < new_s.length(); i++)
    {
    if(checkpassword(new_s))
    {
        return i;
        break;
    }
    return -10;
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int position = 0;
    int maxfrequency = -1;
    int maxlength = 0;

    for (int i = 0; i < num_pwds; i++) {
        int frequency = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) {
                frequency += 1;
            }
        }
        if (frequency > maxfrequency) {
            maxfrequency = frequency;
            maxlength = strlen(arr_pwds[i]);
            position = i;
        } else if (frequency == maxfrequency) {
            int tempLength = strlen(arr_pwds[i]);
            if (tempLength > maxlength) {
                maxlength = tempLength;
                position = i;
            }
        }
    }
    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////