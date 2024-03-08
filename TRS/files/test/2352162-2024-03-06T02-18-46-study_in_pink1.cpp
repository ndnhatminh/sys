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

//CHECK THE INPUT VALUES
void checkTask1(int & a, int & b) {
        if (a > 600)
        {
            a = 600;
        }
        if (a <0)
        {
            a = 0;
        }
        if (b > 600)
        {
            b = 600;
        }
        if (b < 0)
        {
            b = 0;
        }
    return;
}

int firstMeet(int & EXP1, int & EXP2, int E1) {

    if (E1 < 0 || E1 > 99) return -99;

    //CASE 1
    //CHECK THE EVENT CODE E1 AND ADD WATSON'S EXP
    if (E1 >= 0 && E1 <= 3)
    {
        if (E1 == 0) 
        {
            EXP2 += 29;
        }

        if (E1 == 1)
        {
            EXP2 += 45;
        }

        if (E1 == 2)
        {
            EXP2 += 75;
        }

        if (E1 == 3)
        {
            EXP2 += 149;
        }

    //ADD EXP1 DEPENDING ON SHERLOCK'S DECISION
    int D = (E1 * 3) + (EXP1 * 7);
    if((D % 2) == 0)
    {
        EXP1 = ceil(EXP1 + (D) / 200.0f);
    }
    else EXP1 = ceil(EXP1 - (D) / 100.0f);
    checkTask1(EXP1, EXP2);
    }

    //CASE 2
    if (E1 >= 4 && E1 <= 99)
    {
        //INFOR 1
        if (E1 >= 4 && E1 <=19 )
        {
            EXP2 += ceil(double(E1) / 4 + 19);
        }
        //INFOR 2
        else if (E1 >= 20 && E1 <= 49)
        {
            EXP2 += ceil(double(E1) / 9 + 21);
        }   
        //INFOR 3
        else if (E1 >= 50 && E1 <= 65)
        {
            EXP2 += ceil(double(E1) / 16 + 17);
        }
        //INFOR 4
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 += ceil(double(E1) / 4 + 19);
            checkTask1(EXP1, EXP2);
            if (EXP2 > 200)
            {
                EXP2 += ceil(double(E1) / 9 + 21);
            }
        }
        //INFOR 5
        else if (E1 >= 80 && E1 <= 99)
            {
                EXP2 += ceil(double(E1) / 4 + 19);
                EXP2 += ceil(double(E1) / 9 + 21);
                checkTask1(EXP1, EXP2);
                if (EXP2 > 400)
                {
                    EXP2 += ceil(double(E1) / 16 + 17);
                    EXP2 = ceil(double(EXP2) * 1.15);
                }
            }
        EXP1 = EXP1 - E1;
    }
    checkTask1(EXP1, EXP2);

    return EXP1 + EXP2;
}

// Task 2

//FIND THE NEAREST PERFECT SQUARE TO SHERLOCK'S EXP
int checkPerfectSquare(int num) {
    int sqrt_num = sqrt(num);
    int lowerPS = (sqrt_num + 0) * (sqrt_num + 0);
    int higherPS = (sqrt_num + 1) * (sqrt_num + 1);
    if (abs(num - lowerPS) < abs(num - higherPS)) {
        return lowerPS;
    } else {
        return higherPS;
    }
}

//CHECK THE INPUTS OF TASK 2
void checkTask2(int & a, int & b, int & c) {
    if (a > 666)
    {
        a = 666;
    }
    if (a < 0)
    {
        a = 0;
    }
    if (b > 600)
    {
        b = 600;
    }
    if (b < 0)
    {
        b = 0;
    }
    if (c > 3000)
    {
        c = 3000;
    }
    if (c < 0)
    {
        c = 0;
    }
    return;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    if (E2 < 0 || E2 > 99) return -99;
    checkTask2(HP1, EXP1, M1);
    int S1 = checkPerfectSquare(EXP1);

    //ROAD 01
    double P1;
    if (EXP1 >= S1)
    {
        P1 = 100;
    }
    else P1 = ((double (EXP1 / S1) + 80) / 123) * 100;
    
    //ROAD 02
    double moneyMark = M1 * 0.5;
    int paidMoney = 0;

    //E2 IS AN ODD NUMBER
    if ((E2%2) != 0)
    {
        while (0==0)
        {    
        //EVENT 01
        if (HP1 < 200)
        {
            HP1 = ceil(double(HP1) * 130.0 / 100.0);
            paidMoney += 150;
            M1 -= 150;
        }
        else 
        {
            HP1 = ceil(double(HP1) * 110.0 / 100.0);
            paidMoney += 70;
            M1 -= 70;
        }
        checkTask2(HP1, EXP1, M1);
        if (paidMoney > moneyMark)
        {
            break;        
        }
        
        //EVENT 02
        if (EXP1 < 400)
        {
            paidMoney += 200 ;
            M1 -= 200;
        }
        else
        {
            M1 -= 120;
            paidMoney += 120;   
        }
        EXP1 = ceil(double(EXP1) * 113.0 / 100.0);
        checkTask2(HP1, EXP1, M1);
        if (paidMoney > moneyMark)
        {
            break;        
        }

        //EVENT 03
        if (EXP1 < 300)
        {
            paidMoney += 100;
            M1 -= 100;
        }
        else
        {
            M1 -= 120;
            paidMoney += 120;
        }
        EXP1 = ceil(double(EXP1) * 90.0 / 100.0);
        checkTask2(HP1, EXP1, M1);
        if (paidMoney > moneyMark)
        {
            break;        
        }
    }
    HP1 = ceil(double(HP1) * 83.0 / 100.0);
    EXP1 = ceil(double(EXP1) * 117.0 / 100.0);
    checkTask2(HP1, EXP1, M1);
    }

    //E2 IS AN EVEN NUMBER
    else
    {
        //EVENT 01
        if (M1 > 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(double(HP1) * 130.0 / 100.0);
                M1 -= 150;
            }
            else 
            {
                HP1 = ceil(double(HP1) * 110.0 / 100.0);
                M1 -= 70;
            }
            checkTask2(HP1, EXP1, M1);
        }

        //EVENT 02
        if(M1 > 0)
        {
            if (EXP1 < 400)
            {
                M1 -= 200;
            }
            else
            {
                M1 -= 120;
                paidMoney += 120;   
            }
            EXP1 = ceil(double(EXP1)* 113.0 / 100.0);
            checkTask2(HP1, EXP1, M1);
        }

        //EVENT 03
        if(M1 > 0)
        {
            if (EXP1 < 300)
            {
                M1 -= 100;
            }
            else
            {
                M1 -= 120;
            }
            EXP1 = ceil(double(EXP1) * 90.0 / 100.0);
            checkTask2(HP1, EXP1, M1);
        }
        HP1 = ceil(double(HP1) * 83.0 / 100.0);
        EXP1 = ceil(double(EXP1) * 117.0 / 100.0);
        checkTask2(HP1, EXP1, M1);
    }

    int S2 = checkPerfectSquare(EXP1);
    double P2;
    if (EXP1 >= S2)
    {
        P2 = 100;
    }
    else P2 = ((double (EXP1 / S2) + 80) / 123) * 100;

    //ROAD 03
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 >=0 && E2 <10)
    {
        i = E2;
    }
    else
    {
        i = ((E2 / 10) + (E2 % 10)) % 10;
    }
    int P3 = P[i];

    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(double(EXP1) * 75.0 / 100.0);
    }
    else
    {
        double totalP = (P1 + P2 + P3) / 3;  
        if (totalP < 50)
        {
            HP1 = ceil(double(HP1) * 85.0 / 100.0);
            EXP1 = ceil(double(EXP1) * 115.0 / 100.0);
        }
        else if (totalP >= 50)
        {
            HP1 = ceil(double(HP1) * 90.0 / 100.0);
            EXP1 = ceil(double(EXP1) * 120.0 / 100.0);
        }
    }
    checkTask2(HP1, EXP1, M1);

    return HP1 + EXP1 + M1;
}



// Task 3

//CHECK THE INPUTS OF TASK 3
void checkTask3(int & a, int & b, int & c, int & d) {
    if (a > 666)
    {
        a = 666;
    }
    if (a < 0)
    {
        a = 0;
    }
    if (b > 600)
    {
        b = 600;
    }
    if (b < 0)
    {
        b = 0;
    }
    if (c > 666)
    {
        c = 666;
    }
    if (c < 0)
    {
        c = 0;
    }
    if (d > 600)
    {
        d = 600;
    }
    if (d < 0)
    {
        d = 0;
    }
    return;
}

//CALCULATE THE SUM OF TWO DIGITS
int sum(int & num) {
    if (num < 10) 
    {
        return num;
    }

    int sum = (num / 10) + (num % 10);

    return sum;  
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    if (E3 < 0 || E3 > 99) return -99;
    checkTask3(HP1, EXP1, HP2, EXP2);

    //INITIALIZE THE 10X10 ARRAY
    int greater = 0;
    int smaller = 0;

    int arr[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > (E3 * 2))
            {
                greater += 1;
            }
            if (arr[i][j] < ((-1) * E3))
            {
                smaller += 1;
            }               
        }
    }

    //FIND THE MEETING LOCATION AND TAXI'S POINT
    int meetingI = sum(greater);
    int meetingJ = sum(smaller);
    meetingI = sum(meetingI);
    meetingJ = sum(meetingJ);

    int taxiPoint = arr[meetingI][meetingJ];
 
    //FIND SHERLOCK AND WATSON'S POINTS
    int a = 0;
    int SherlockPoint = 0;
    int left = meetingJ - meetingI;
    int right = meetingJ + meetingI;
    int SherlockPoint_left = 0;
    int SherlockPoint_right = 0;
    int SherlockPoint_left_max = 0;
    int SherlockPoint_right_max = 0;

    //DIAGONAL LEFT
    for (a, left; a < 10; a++, left++)
    {
        if (left < 0 || left > 9)
        {
            continue;
        }
        
            SherlockPoint_left = arr[a][left];
            if (SherlockPoint_left > SherlockPoint_left_max)
            {
                SherlockPoint_left_max = SherlockPoint_left;
            }
    }
  
    a = 0;

    //DIAGONAL RIGHT
    for (a, right; a < 10; a++, right--)
    {
        if (right < 0 || right > 9)
        {
            continue;
        }
            SherlockPoint_right = arr[a][right];
            if (SherlockPoint_right > SherlockPoint_right_max)
            {
                SherlockPoint_right_max = SherlockPoint_right;
            }
    }

    //COMPARE THE MAXIMUM VALUES BETWEEN TWO DIAGONALS
    if (SherlockPoint_left_max > SherlockPoint_right_max)
    {
        SherlockPoint = SherlockPoint_left_max;
    }
    else SherlockPoint = SherlockPoint_right_max;

    SherlockPoint = abs(SherlockPoint);
    
    //IF THEY CAN CATCH THE TAXI OR NOT
    if (abs(taxiPoint) > SherlockPoint)
    {
        EXP1 = ceil(double(EXP1) * 88.0 / 100.0);
        HP1 = ceil(double(HP1) * 90.0 / 100.0);
        EXP2 = ceil(double(EXP2) * 88.0 / 100.0);
        HP2 = ceil(double(HP2) * 90.0 / 100.0);
        checkTask3(HP1, EXP1, HP2, EXP2);
        return taxiPoint;
    }
    else 
    {
        EXP1 = ceil(double(EXP1) * 112.0 / 100.0);
        HP1 = ceil(double(HP1) * 110.0 / 100.0);
        EXP2 = ceil(double(EXP2) * 112.0 / 100.0);
        HP2 = ceil(double(HP2) * 110.0 / 100.0);
        checkTask3(HP1, EXP1, HP2, EXP2);
        return SherlockPoint;
    }   
}

// Task 4
int checkPassword(const char * s, const char * email) { 

    //FIND THE STRING OF CHARACTERS BEFORE '@' IN THE VICTIM'S EMAIL
    int end = 0;
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            end = i;
            break;
        }
    }
    char se[101];
    strncpy(se, email, end);
    se[end] = '\0'; 
    
    //FIND THE LENGTH OF THE PASSWORD
    int passLength = strlen(s);

    //CONDTIONS FOR A VALID PASSWORD REQUIREMENT AND THE RETURN RESULTS

    //MINIMUM LENGTH
    if (passLength < 8)
    {
        return -1;
    }

    //MAXIMUM LENGTH
    if (passLength > 20)
    {
        return -2;
    } 

    //IF THE PASSWORD CONTAINS THE STRING BEFORE '@' IN THE EMAIL
    const char* sei = strstr(s, se);
    if (sei != NULL)
    {
        return -(300 + (sei - s));
    }
    
    //IF THE PASSWORD CONTAINS MORE THAN 2 CONSECUTIVE AND IDENTICAL CHARACTERS
    int sci = 0;
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2]))
        {
            sci = i;
            return -(400 + sci);
        }      
    }
    
    //IF THE PASSWORD DOES NOT CONTAIN SPECIAL CHARACTER
    bool specialChar = false;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!'))
        {
            specialChar = true;
        }
    }
    if (specialChar != true)
    {
        return -5;
    }    
    
    //IF THE PASSWORD CONTAINS VALID CHARACTERS
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!((isdigit(s[i])) || (islower(s[i])) || (isupper(s[i])) || (s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!')))
        {
            return i;
        }       
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {

  

int address = 0;
int freq = 0;
int max_freq = 0;   
int length = 0;
int max_length = 0;

int i = -2;
int j = -2;

for (i = 0; i < num_pwds; i++)
{
    for (j = 0; j < num_pwds; j++)
    {
        length = strlen(arr_pwds[i]);
        if (strcmp(arr_pwds[i],arr_pwds[j]) == 0)
        {
            freq += 1;
        }
    }
    if (freq > max_freq)
    {
        max_freq = freq;
        max_length = length;
        address = i;
            
    }
    if (freq == max_freq)
    {
        if (length > max_length)
        {
            
            max_length = length;
            address = i;
        }

    }   
    freq = 0;
}
    return address;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////