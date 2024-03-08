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
int firstMeet(int & EXP1, int & EXP2, int E1) {

    if (E1 < 0 || E1 > 99) return -99;
    if(E1>=0 && E1<=3){
    if (E1 == 0) {
        EXP2 = EXP2 + 29;
        if(EXP2<0){
            EXP2=0;
        }
        else if(EXP2>600){
            EXP2=600;
        }
    } else if (E1 == 1) {
        EXP2 = EXP2 + 45;
         if(EXP2<0){
            EXP2=0;
        }
        else if(EXP2>600){
            EXP2=600;
        }
    } else if (E1 == 2) {
        EXP2 = EXP2 + 75;
         if(EXP2<0){
            EXP2=0;
        }
        else if(EXP2>600){
            EXP2=600;
        }
    } else if (E1 == 3) {
        EXP2 = EXP2 + 29 + 45 + 75;
         if(EXP2<0){
            EXP2=0;
        }
        else if(EXP2>600){
            EXP2=600;
        }
    }
    
    int D = E1 * 3 + EXP1 * 7;
    if (D % 2 != 0) {
         EXP1 = ceil(EXP1 - (D / 100.0));
         if(EXP1<0){
                EXP1=0;
            }
            else if(EXP1>600){
                EXP1=600;
            }
    } 
    else {
         EXP1 = ceil(EXP1 + (D / 200.0));
        if(EXP1<0){
                EXP1=0;
            }
            else if(EXP1>600){
                EXP1=600;
            }
    }
    }
    else if(E1>=4 && E1<=99){
        if(E1>=4 && E1<=19){
            EXP2=ceil(EXP2+(E1/4.0 + 19));
            if(EXP2<0){
                EXP2=0;
            }
            else if(EXP2>600){
                EXP2=600;
            }
            EXP1=EXP1 - E1;
            if(EXP1<0){
                EXP1=0;
            }
            else if(EXP1>600){
                EXP1=600;
            }
        }
        else if(E1>=20 && E1<=49){
            EXP2=ceil(EXP2+(E1/9.0 + 21));
              if(EXP2<0){
                EXP2=0;
            }
            else if(EXP2>600){
                EXP2=600;
            }
            EXP1=EXP1 - E1;
            if(EXP1<0){
                EXP1=0;
            }
            else if(EXP1>600){
                EXP1=600;
            }
        }
        else if(E1>=50 && E1<=65){
            EXP2=ceil(EXP2+(E1/16.0 + 17));
            if(EXP2<0){
                EXP2=0;
            }
            else if(EXP2>600){
                EXP2=600;
            }
            EXP1=EXP1- E1;
            if(EXP1<0){
                EXP1=0;
            }
            else if(EXP1>600){
                EXP1=600;
            }
        }
        else if(E1>=66 && E1<=79){
            EXP2=ceil(EXP2+(E1/4.0 + 19));
            if(EXP2>200){
                EXP2=ceil(EXP2+(E1/9.0 + 21));
                if(EXP2<0){
                EXP2=0;
            }
            else if(EXP2>600){
                EXP2=600;
            }
            }
            EXP1=EXP1-E1;
            if(EXP1<0){
                EXP1=0;
            }
            else if(EXP1>600){
                EXP1=600;
            }
        }
        else if(E1>=80 && E1<=99){
            EXP2=ceil(EXP2+(E1/4.0 + 19));
            EXP2=ceil(EXP2+(E1/9.0 + 21));
            if(EXP2>400){
                EXP2=ceil(EXP2+(E1/16.0 + 17));
                EXP2= ceil(EXP2 + EXP2*0.15);
                if(EXP2<0){
                EXP2=0;
            }
                else if(EXP2>600){
                EXP2=600;
            }
            }
            EXP1=EXP1-E1;
            if(EXP1<0){
                EXP1=0;
            }
            else if(EXP1>600){
                EXP1=600;
            }
        }
        
    }
  
    return EXP1 + EXP2;
}

// Task2
float nearestsquarenumber(int &EXP1) {
    float num = floor(sqrt(EXP1));
    if (EXP1 - (num * num) < ((num + 1) * (num + 1)) - EXP1) {
        num = num * num;
    }
    else {
        num = (num + 1) * (num + 1);
    }
    return num;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 > 99 || E2 < 0)
        return -99;

    float S = nearestsquarenumber(EXP1);
    float P1;
    if (EXP1 >= S) {
        P1 = 1;
    }
    else {
        P1 = ((EXP1 / S) + 80.0) / 123.0;
        P1 = round(P1 * 100) / 100;
    }

    float half_of_initial_money = round(M1 * 0.5);
    int total_of_paid_money = 0;
    int food_and_drink_money = 0;
    int drink_money = 0;
    int taxi_money = 0;
    int horse_money = 0;
    int help_homeless_person = 0;
    int ask_homeless_person_to_give_direction = 0;

    if (E2 % 2 != 0) {
        while (M1>0) {
            if (HP1 < 200) {
                food_and_drink_money = 150;
                HP1 = ceil(HP1 + 0.3 * HP1);  
                 if (HP1 > 666) {
                 HP1 = 666;
                 }
                 else if (HP1 < 0) {
                HP1 = 0;
                 }
                M1 = M1 - food_and_drink_money;
                if(M1<0){
                    M1=0;
                }
                else if(M1>3000){
                    M1=3000;
                }
                total_of_paid_money += food_and_drink_money;
                if (total_of_paid_money > half_of_initial_money) {
                    break;
                }
            }
            else if (HP1 >= 200) {
                drink_money = 70;
                HP1 = ceil(HP1 + 0.1 * HP1); 
                 if (HP1 > 666) {
                 HP1 = 666;
                 }
                 else if (HP1 < 0) {
                HP1 = 0;
                 }
                M1 = M1 - drink_money; 
                if(M1<0){
                    M1=0;
                }
                else if(M1>3000){
                    M1=3000;
                }
                total_of_paid_money += drink_money; 
                if (total_of_paid_money > half_of_initial_money) { 
                    break;
                }
            }

            if (EXP1 < 400) {
                taxi_money = 200;
                M1 = M1 - taxi_money; 
                if(M1<0){
                    M1=0;
                }
                else if(M1>3000){
                    M1=3000;
                }
                EXP1 = ceil(EXP1 + 0.13 * EXP1); 
                if(EXP1<0){
                    EXP1=0;
                }
                else if(EXP1>600){
                    EXP1=600;
                }
                total_of_paid_money += taxi_money; 
                if (total_of_paid_money > half_of_initial_money) {
                    break;
                }
            }
            else if (EXP1 >= 400) {
                horse_money = 120;
                M1 = M1 - horse_money;
                if(M1<0){
                    M1=0;
                }
                else if(M1>3000){
                    M1=3000;
                }
                total_of_paid_money += horse_money;
                EXP1 = ceil(EXP1 + 0.13 * EXP1);
                 if(EXP1<0){
                    EXP1=0;
                }
                else if(EXP1>600){
                    EXP1=600;
                }
                if (total_of_paid_money > half_of_initial_money) {
                    break;
                }
            }

            if (EXP1 < 300) {
                help_homeless_person = 100;
                M1 = M1 - help_homeless_person; 
                if(M1<0){
                    M1=0;
                }
                else if(M1>3000){
                    M1=3000;
                }
                total_of_paid_money += help_homeless_person;
                EXP1 = ceil(EXP1 - 0.1 * EXP1);
                 if(EXP1<0){
                    EXP1=0;
                }
                else if(EXP1>600){
                    EXP1=600;
                }
                if (total_of_paid_money > half_of_initial_money) {
                    break;
                }
            }
            else if (EXP1 >= 300) {
                ask_homeless_person_to_give_direction = 120;
                M1 = M1 - ask_homeless_person_to_give_direction; 
                if(M1<0){
                    M1=0;
                }
                else if(M1>3000){
                    M1=3000;
                }
                total_of_paid_money += ask_homeless_person_to_give_direction; 
                EXP1 = ceil(EXP1 - 0.1 * EXP1); 
                 if(EXP1<0){
                    EXP1=0;
                }
                else if(EXP1>600){
                    EXP1=600;
                }
                if (total_of_paid_money > half_of_initial_money) { 
                    break;
                }
            }
        }
    }
    else if (E2 % 2 == 0 || E2==0) {
        while (M1>0) {
            if (HP1 < 200) {
                food_and_drink_money = 150;
                HP1 = ceil(HP1 + 0.3 * HP1);
                if (HP1 > 666) {
                HP1 = 666;
                 }
                else if (HP1 < 0) {
                HP1 = 0;
                 }
                M1 = M1 - food_and_drink_money;
                if (M1 >3000) {
                    M1=3000;
                }
                else if(M1<=0){
                    M1=0;
                    break;
                }
            }
            else if (HP1 >= 200) {
                drink_money = 70;
                HP1 = ceil(HP1 + 0.1 * HP1);
                 if (HP1 > 666) {
                 HP1 = 666;
                 }
                 else if (HP1 < 0) {
                 HP1 = 0;
                 }
                M1 = M1 - drink_money;
              if (M1 >3000) {
                    M1=3000;
                }
                else if(M1<=0){
                    M1=0;
                    break;
                }
            }

            if (EXP1 < 400) {
                taxi_money = 200;
                 EXP1 = ceil(EXP1 + 0.13 * EXP1);
                 if(EXP1<0){
                    EXP1=0;
                }
                else if(EXP1>600){
                    EXP1=600;
                }
                M1 = M1 - taxi_money;
               if (M1 >3000) {
                    M1=3000;
                }
                else if(M1<=0){
                    M1=0;
                    break;
                }
            }
            else if (EXP1 >= 400) {
                horse_money = 120;
                 EXP1 = ceil(EXP1 + 0.13 * EXP1);
                 if(EXP1<0){
                    EXP1=0;
                }
                else if(EXP1>600){
                    EXP1=600;
                }
                M1 = M1 - horse_money;
                if (M1 >3000) {
                    M1=3000;
                }
                else if(M1<=0){
                    M1=0;
                    break;
                }
            }

            if (EXP1 < 300) {
                help_homeless_person = 100;
                EXP1 = ceil(EXP1 - 0.1 * EXP1);
                if(EXP1<0){
                    EXP1=0;
                }
                else if(EXP1>600){
                    EXP1=600;
                }
                M1 = M1 - help_homeless_person;
                if (M1 >3000) {
                    M1=3000;
                }
                else if(M1<=0){
                    M1=0;
                }
            }
            else if (EXP1 >= 300) {
                ask_homeless_person_to_give_direction = 120;
                 EXP1 = ceil(EXP1 - 0.1 * EXP1);
                  if(EXP1<0){
                    EXP1=0;
                }
                else if(EXP1>600){
                    EXP1=600;
                }
                M1 = M1 - ask_homeless_person_to_give_direction;
               if (M1 >3000) {
                    M1=3000;
                }
                else if(M1<=0){
                    M1=0;
                }
               
            }
            break;
        }
    }

    HP1 = ceil(HP1 - 0.17 * HP1);
     if (HP1 > 666) {
        HP1 = 666;
        }
     else if (HP1 < 0) {
        HP1 = 0;
        }
    EXP1 = ceil(EXP1 + 0.17 * EXP1);
       if(EXP1<0){
        EXP1=0;
        }
        else if(EXP1>600){
         EXP1=600;
        }
    float S2 = nearestsquarenumber(EXP1);
    float P2;
    if (EXP1 >= S2) {
        P2 = 1.0;
    }
    else {
        P2 = ((EXP1 / S2) + 80.0) / 123.0;
        P2 = round(P2 * 100) / 100;
    }

    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int sum = E2 / 10 + E2 % 10;
    int result = sum % 10;
    double P3 = arr[result]/100.0;
    float average_P = (P1 + P2 + P3) / 3;
    int sum_P = P1 + P2 + P3;
    if (sum_P == 3 || average_P==1) {
        EXP1 = ceil(EXP1 - 0.25 * EXP1);
    }
    else if (sum_P!= 3 || average_P==1) {
        if (average_P < 0.5) {
            HP1 = ceil(HP1 - 0.15 * HP1);
            if (HP1 > 666) {
                HP1 = 666;
            }
            else if (HP1 < 0) {
                HP1 = 0;
            }
            EXP1 = ceil(EXP1 + 0.15 * EXP1);
            if (EXP1 > 600) {
                EXP1 = 600;
            }
            else if (EXP1 < 0) {
                EXP1 = 0;
            }
        }
        else if (average_P >= 0.5) {
            HP1 = ceil(HP1 - 0.1 * HP1);
            if (HP1 > 666) {
                HP1 = 666;
            }
            else if (HP1 < 0) {
                HP1 = 0;
            }
            EXP1 = ceil(EXP1 + 0.2 * EXP1);
            if (EXP1 > 600) {
                EXP1 = 600;
            }
            else if (EXP1 < 0) {
                EXP1 = 0;
            }
        }
       
    }

    return HP1 + EXP1 + M1;
}




// Task 3
int calculate_total_of_two_digits(int number){
    int sum=0;
    do{
        sum=0;
         do{
            sum=sum+(number%10);
            number =number/10;
         }while(number>0);
        number =sum;
    }while(number>=10);
    return sum;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{  
    if (E3 > 99 || E3 < 0)
        return -99;
   int arr[10][10];
   int big_number=0;
   int small_number=0;
   for(int i=0; i<10; i++) {
       for(int j=0;j<10;j++){
        arr[i][j]=((E3 * j) + (i * 2)) * (i - j);
        if (arr[i][j] > E3 * 2) { 
                big_number++;
            } else if (arr[i][j] < -E3) { 
                small_number++;
            }
        }
        
    }
    
    int Position_I =calculate_total_of_two_digits(big_number);
    int Position_J =calculate_total_of_two_digits(small_number);
    int TaxiPoint=arr[Position_I][Position_J];
    int SherlockPoint=arr[Position_I][Position_J];
    for (int i = Position_I, j = Position_J; i >= 0 && j >= 0; i--, j--) {
    if (i < 0 || j < 0) break; 
    if (arr[i][j] > SherlockPoint) {
        SherlockPoint = arr[i][j];
    }
}


for (int i = Position_I, j = Position_J; i < 10 && j >= 0; i++, j--) {
    if (i >= 10 || j < 0) break; 
    if (arr[i][j] > SherlockPoint) {
        SherlockPoint = arr[i][j];
     
    }
}


for (int i = Position_I, j = Position_J; i < 10 && j < 10; i++, j++) {
    if (i >= 10 || j >= 10) break; 
    if (arr[i][j] > SherlockPoint) {
        SherlockPoint = arr[i][j];
        
    }
}


for (int i = Position_I, j = Position_J; i >= 0 && j < 10; i--, j++) {
    if (i < 0 || j >= 10) break; 
    if (arr[i][j] > SherlockPoint) {
        SherlockPoint = arr[i][j];
        
    }
}


if(abs(TaxiPoint)>abs(SherlockPoint)){
       EXP1=ceil(EXP1-0.12*EXP1);
       if(EXP1<0){
        EXP1=0;
       }
       else if(EXP1>600){
        EXP1=600;
       }
       HP1=ceil(HP1-0.1*HP1);
       if(HP1<0){
        HP1=0;
       }
       else if(HP1>666){
        HP1=666;
       }
       EXP2=ceil(EXP2-0.12*EXP2);
       if(EXP2<0){
        EXP2=0;
       }
       else if(EXP2>600){
        EXP2=600;
       }
       HP2=ceil(HP2-0.1*HP2);
        if(HP2<0){
        HP2=0;
       }
       else if(HP2>666){
        HP2=666;
       }
   return TaxiPoint;
}
else if(abs(TaxiPoint)<=abs(SherlockPoint)){
        EXP1=ceil(EXP1+0.12*EXP1);
        if(EXP1<0){
        EXP1=0;
        }
        else if(EXP1>600){
        EXP1=600;
        }
        HP1=ceil(HP1 + 0.1*HP1);
        if(HP1<0){
        HP1=0;
        }
        else if(HP1>666){
        HP1=666;
        }
        EXP2=ceil(EXP2+0.12*EXP2);
         if(EXP2<0){
        EXP2=0;
        }
        else if(EXP2>600){
        EXP2=600;
        }
        HP2=ceil(HP2+0.1*HP2);
        if(HP2<0){
        HP2=0;
        }
       else if(HP2>666){
        HP2=666;
        }
    return abs(SherlockPoint);
}
else if(TaxiPoint==SherlockPoint){
return TaxiPoint;
}
return 0;
}
// Task 4
int checkPassword(const char *s , const char *email) {   
    const char *at_position = strchr(email, '@');
    if (at_position == nullptr)
        return -1; 

    int se_length = at_position - email;
    char se[101]; 
    strncpy(se, email, se_length);
    se[se_length] = '\0'; 

    
    int password_length = strlen(s);
    if (password_length < 8)
        return -1; 
    if (password_length > 20)
        return -2; 

    int sei=strstr(s, se) - s;
    if (strstr(s, se) != nullptr)
        return -(300 + sei); 

    
    for (int i = 0; i < password_length - 1; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        return -(400 + i); 
    }

    bool has_special_character = false;
    for (int i = 0; i < password_length; ++i) {
    if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            has_special_character = true;
            break;
       }
    }  
    if (!has_special_character)
    return -5; 

   
    for (int i = 0; i < password_length; ++i) {
    if (!(isdigit(s[i]) || islower(s[i]) || isupper(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i; 
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int the_maximum_of_the_frequency = 0;
    int the_maximum_of_the_length = 0;
    int position_of_the_password = -1;
    int i=0;
     while(i<num_pwds) {
        int the_frequency = 0;
        int the_length = strlen(arr_pwds[i]);
        int j =0;
    
        while(j<num_pwds) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                the_frequency++;
            }
            j++;
        }

        if (the_frequency > the_maximum_of_the_frequency || (the_frequency == the_maximum_of_the_frequency && the_length > the_maximum_of_the_length)) {
            the_maximum_of_the_frequency = the_frequency;
            the_maximum_of_the_length = the_length;
            position_of_the_password = i;
        }
        i++;
    }

    return position_of_the_password;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////