#include "study_in_pink1.h"

bool
readFile (const string & filename,
		  int &HP1,
		  int &HP2,
		  int &EXP1, int &EXP2, int &M1, int &M2, int &E1, int &E2, int &E3)
{
  // This function is used to read the input file,
  // DO NOT MODIFY THIS FUNTION
  ifstream ifs (filename);
  if (ifs.is_open ())
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
    void Control_HP (int &hp1)
    {
    if (hp1 > 666)
        hp1 = 666;
    if (hp1 < 0)
        hp1 = 0;
    }

    void Control_EXP (int &exp1)
    {
    if (exp1 > 600)
        exp1 = 600;
    if (exp1 < 0)
        exp1 = 0;
    }
    void Control_Money (int &M)
    {
    if (M > 3000)
        M = 3000;
    if (M < 0)
        M = 0;
    }
    bool valid_event( int &e1)
    {
        if (e1<0||e1>99) return false;
        else return true;
    }
    int find_nearest_perfect_square( int &exp1)
    {
        float sqrt_exp1 = round(sqrt(exp1));
        int need_to_find = sqrt_exp1;
        return need_to_find*need_to_find;
        
    }
    int convert_to_1_digit(int &number){
        while (number > 9){
            number = (number / 10 + number % 10);
        }

        return number;
    }
    int check_email(string email) {
    int at_count = 0; 
    if (email.length() > 100)
        return email.length();
    for (int i = 0; i < email.length(); i++) { 
        if (email[i] == '@') { 
            at_count++; 
            if (at_count != 1)  
                return i; 
        }
    }
    return 1; 
}

bool check_Character(char c) {
    if ((c >= '0' && c <= '9') || 
        (c >= 'A' && c <= 'Z') || 
        (c >= 'a' && c <= 'z') || 
        c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
        return true;
    }
    return false;
}
// Task 1
int firstMeet (int &exp1, int &exp2, int e1)
{
  // TODO: Complete this function
    if (!valid_event(e1)) return -99;
    Control_EXP(exp1);
    Control_EXP(exp2);
    //case 1    
    if (e1<=3){
    // watson's exp
        switch (e1){
            case 0:
            exp2 += 29;
            break;
            case 1:
            exp2 += 45;
            break;
            case 2:
            exp2 +=75;
            break;
            case 3:
            exp2 += 29 + 45 + 75;
            break;
            default:
            break;
                
        }
        Control_EXP(exp2);
    // holme's exp
    int D = 3 * e1 + 7 * exp1;
    if (D & 1) exp1 = ceil((float)exp1 - (float)D/100);
    else       exp1 = ceil((float)exp1 + (float)D/200);    
        Control_EXP(exp1);
    }
    
    //case 2
    else if (e1 >= 4){
        // watson's exp
        //inf 1
        if (4 <= e1 && e1 <=19)  
        exp2 += ceil((float)e1 / 4 + 19);
        //inf 2
        else if (20 <= e1 && e1 <=49)
        exp2 += ceil((float)e1 / 9 +21);
        //inf 3
        else if (50 <= e1 && e1 <= 65) 
        exp2 += ceil((float)e1 / 16 + 17);
        //inf 4
        else if (66 <= e1 && e1 <= 79){
           exp2 += ceil((float)e1/4 + 19);
           Control_EXP(exp2);
           if (exp2 > 200)
           exp2 += ceil((float)e1/9 +21);
        }
        //inf 5
        else if (80 <= e1 && e1 <= 99){
            exp2 += ceil((float)e1/4 + 19);
            Control_EXP(exp2);
            exp2 += ceil((float)e1/9 +21);
            Control_EXP(exp2);
            if (exp2 > 400) {
            exp2 += ceil((double)e1 / 16.00 + 17);
            Control_EXP(exp2);
            exp2 = ceil(exp2 * 1.15);
            }
        } 
        Control_EXP(exp2);
        // holme's exp
        exp1 -= e1;
        Control_EXP(exp1);
    }   
    return exp1 + exp2;
}
// Task 2
int traceLuggage (int &HP1, int &EXP1, int &M1, int E2)
{   
  // TODO: Complete this function   
  if (!valid_event(E2))
        return -99;
    Control_EXP(EXP1);
    Control_HP(HP1);
    Control_Money(M1);

    // Road 01
    float P1;
    int S = find_nearest_perfect_square(EXP1);
    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = (float(EXP1) / S + 80) / 123;

    // Road 02
    float P2;
    int payment = 0;
    int initial = M1;
    do {
        if (M1 <= 0)
        break;
        // Event 1
        if (HP1 < 200) {
            HP1 = ceil(HP1 + (float)HP1 * 0.3);
            Control_HP(HP1);
            M1 -= 150;
            payment += 150;
        } else {
            HP1 = ceil(HP1 + (float)HP1 * 0.1);
            Control_HP(HP1);
            M1 -= 70;
            payment += 70;
        }
        Control_EXP(EXP1);
        Control_Money(M1);
        Control_HP(HP1);
        if ((E2 % 2 == 0 && M1 == 0) || (E2 % 2 != 0 && payment > 0.5 * initial))
            break;

        // Event 2: 
        if (EXP1 < 400) {
            M1 -= 200;
            payment += 200;
        } else {
            M1 -= 120;
            payment += 120;
        }
        EXP1 = ceil(EXP1 + (float)EXP1 * 0.13);
        Control_EXP(EXP1);
        Control_Money(M1);
        Control_HP(HP1);
        
        if ((E2 % 2 == 0 && M1 == 0) || (E2 % 2 != 0 && payment > 0.5 * initial))
            break;

        // Event 3: 
        if (EXP1 < 300) {
            M1 -= 100;
            payment += 100;
        } else {
            M1 -= 120;
            payment += 120;
        }
        EXP1 = ceil(EXP1 - (float)EXP1 * 0.1);
        Control_EXP(EXP1);
        Control_Money(M1);
        Control_HP(HP1);
        
        if ((E2 % 2 == 0 && M1 == 0) || (E2 % 2 != 0 && payment > 0.5 * initial))
            break;

        if (E2 % 2 == 0)
        break;

    } while (E2 <= 99 && E2 >= 0);

    // Apply final adjustments
    HP1 = ceil(HP1 - (float)HP1 * 0.17);
    EXP1 = ceil(EXP1 + (float)EXP1 * 0.17);
    Control_EXP(EXP1);
    Control_HP(HP1);
    S = find_nearest_perfect_square(EXP1);
    if (EXP1 >= S)
        P2 = 1;
    else
        P2 = ((float)EXP1 / S + 80) / 123;

    // Road 03
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    float P;
    P3 = arr[(E2 / 10 + E2 % 10) % 10]/100.0;
    if (P1 == P2 && P2 == P3 && P3 == 1.0)
        EXP1 = ceil(EXP1 - (float)EXP1 * 0.25);
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1 = ceil(HP1 - (float)HP1 * 0.15);
            EXP1 = ceil(EXP1 + (float)EXP1 * 0.15);
        } else {
            HP1 = ceil(HP1 - (float)HP1 * 0.1);
            EXP1 = ceil(EXP1 + (float)EXP1 * 0.2);
        }
    }
    Control_Money(M1);
    Control_EXP(EXP1);
    Control_HP(HP1);
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    if (!valid_event(E3))
        return -99;
    Control_EXP(EXP1);
    Control_EXP(EXP2);
    Control_HP(HP1);
    Control_HP(HP2);
    int taxi_score[10][10];
    int number_greater = 0, number_smaller = 0;
    for (int i = 0; i < 10 ; i++)
        for (int j = 0; j < 10; j++) {
            taxi_score[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi_score[i][j] > (E3 * 2))
                number_greater++;
            else if (taxi_score[i][j] < -E3)
                number_smaller++;
        }
    int x = convert_to_1_digit(number_greater);
    int y = convert_to_1_digit(number_smaller);
    int max_diagonal = 0;
    int det_score;
    
    for (int dx = -1; dx <= 1; dx += 2) {
    for (int dy = -1; dy <= 1; dy += 2) {
        for (int i = x, j = y; i >= 0 && i < 10 && j >= 0 && j < 10; i += dx, j += dy) {
            if (taxi_score[i][j] > max_diagonal)
                max_diagonal = taxi_score[i][j];
        }
    }
}
        det_score = abs(max_diagonal);
    if (det_score >= abs(taxi_score[x][y])) {
        EXP1 = ceil(EXP1 + (float)EXP1 * 0.120);
        EXP2 = ceil(EXP2 + (float)EXP2 * 0.120);
        HP1 = ceil(HP1 + (float)HP1 * 0.10);
        HP2 = ceil(HP2 + (float)HP2 * 0.10);
        Control_HP(HP1);
        Control_HP(HP2);
        Control_EXP(EXP1);
        Control_EXP(EXP2);
        return abs(det_score);
    } else {
        EXP1 = ceil(EXP1 - (float)EXP1 * 0.12);
        HP1 = ceil(HP1 - (float)HP1 * 0.10);
        EXP2 = ceil(EXP2 - (float)EXP2 * 0.12);
        HP2 = ceil(HP2 - (float)HP2 * 0.10);
        Control_HP(HP1);
        Control_HP(HP2);
        Control_EXP(EXP1);
        Control_EXP(EXP2);
        return taxi_score[x][y];
    }
}


// Task 4


int checkPassword(const char *s, const char *email)
{
    string se;
    string copy_email = email;
    int email_error = check_email(email);
    if (email_error != 1)
        return email_error; 

    int at_position = copy_email.find('@');
    se = copy_email.substr(0, at_position);
    string copy_password = s;
    int count_special = 0;
    char character;

    if (copy_password.length() < 8)
        return -1; 

    if (copy_password.length() > 20)
        return -2;
    
    if (strstr(s, se.c_str()) != nullptr) {
    const string& s_copy = s;
    size_t position = s_copy.find(se);
    return -(300 + static_cast<int>(position));
}
    for (int i = 0; i < copy_password.length() - 2; i++) {
        if (copy_password[i] == copy_password[i + 1] && copy_password[i + 1] == copy_password[i + 2])
            return -(400 + i); 
    }

    for (int i = 0; i < copy_password.length(); i++) {
        character = copy_password[i];
        if (!check_Character(character))
            return i; 
        if ((character == '@') || (character == '#') || (character == '%') || (character == '$') || (character == '!'))
            count_special++;
    }

    if (count_special == 0)
        return -5; 

    return -10; 
}
// Task 5
int findCorrectPassword (const char *arr_pwds[], int num_pwds)
{

    int max_duplicate = 0;
    int max_length = 0;
    int required_position = 0; 
    
    for (int i = 0; i < num_pwds; i++) {
        int length = strlen(arr_pwds[i]);
        
         int duplicate = 0;
       
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                duplicate++;
            }
        }

       
        if (duplicate > max_duplicate) {
            max_length = length;
            required_position = i;
            max_duplicate = duplicate;
        }
        if (duplicate == max_duplicate) {
            if (length > max_length) {
                max_length = length;
                required_position = i;
            }
        }
    }
    return required_position;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

