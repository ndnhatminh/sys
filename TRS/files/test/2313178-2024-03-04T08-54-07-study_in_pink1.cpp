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
void condition(int &HP1, int &HP2, int &EXP1, int &EXP2, int &M1, int &M2, int &E1, int &E2, int &E3) // condition all
{
    HP1 = min(max(0, HP1), 666);
    HP2 = min(max(0, HP2), 666);
    EXP1 = min(max(0, EXP1), 600);
    EXP2 = min(max(0, EXP2), 600);
    M1 = min(max(0, M1), 3000);
    M2 = min(max(0, M2), 3000);
}
void conTask1(int &EXP1, int &EXP2) {
    EXP1 = min(max(0, EXP1), 600);
    EXP2 = min(max(0, EXP2), 600);
}
void conTask2(int &HP1, int &EXP1, int &M1)
{
    HP1 = min(max(0, HP1), 666);
    EXP1 = min(max(0, EXP1), 600);
    M1 = min(max(0, M1), 3000);
}
void conTask3(int &HP1, int &HP2, int &EXP1, int &EXP2)
{
    HP1 = min(max(0, HP1), 666);
    HP2 = min(max(0, HP2), 666);
    EXP1 = min(max(0, EXP1), 600);
    EXP2 = min(max(0, EXP2), 600);
}
float squareNumNearEXP1(int &EXP1)
{
    float P1 = 0.0;
    int nearLower = floor(sqrt(EXP1)); // làm tròn xuống
    float i = sqrt(EXP1);
    float nearHigher = pow(ceil(i), 2);                                                                                // làm tròn lên
    return abs(EXP1 - nearLower * nearLower) <= abs(EXP1 - nearHigher) ? P1 = 1 : P1 = (EXP1 / nearHigher + 80) / 123; // toán tử 3 ngôi
}
int index(int &E2) // tìm giá trị index
{
    int i = 0;
    if (E2 < 10)
    {
        i = E2;
    }
    else
    {
        int num1 = E2 % 10;
        int num2 = (E2 - num1) / 10;
        int tmpI = num1 + num2;
        i = tmpI % 10;
    }
    return i;
}
int singleNum(int &num) // hàm tính số 2 chữ số về 1 chữ số
{
    int i = 0;
    if (num < 0)
    {
        i = num;
    }
    else
    {
        int num0 = num % 10;
        int num2 = (num - num0) / 10;
        int r0 = num0 + num2;
        if (r0 < 10)
        {
            i = r0;
        }
        else
        {
            i = singleNum(r0);
        }
    }
    return i;
}
int countChar(const char *string)
{
    int charNum = 0;
    while (*string != '\0')
    {
        charNum++;
        string++;
    }
    return charNum;
}
int checkSameCharOver2(const char*s)
{   int num0 =-1;
    int num1=countChar(s);
    int temp=0;
    for (int i=0 ;i < num1; i++)
    {
        if(s[i]==s[i+1])
        {
          temp++;
          if(temp == 2)
          {
            num0 = i-1 ;
             break;
          }
        }
        else temp = 0;
            
    }
   return num0;
}
int checkChar(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            return i;
        }
    }
    return -1;
}
bool specialChar(const char *s){
    for (int i = 0; s[i] != '\0'; i++) {
         if ((s[i] == '@' || s[i] == '#'|| s[i] == '%'|| s[i] == '$'|| s[i] == '!')){
                return true;
         }
     }
      return false;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    exp1 = min(max(exp1, 0), 600); // check condition
    exp2 = min(max(exp2, 0), 600);
    // case 1
    if (e1 >= 0 && e1 < 4)
    {
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            float newExp1 = exp1 + D / 200.0;
            exp1 = ceil(newExp1);
        }
        else
        {
            int newExp1 = exp1 - D / 100;
            exp1 = ceil(newExp1);
        }
        switch (e1)
        {
        case 0:
            exp2 = exp2 + 29;
            break;
        case 1:
            exp2 = exp2 + 45;
            break;
        case 2:
            exp2 = exp2 + 75;
            break;
        case 3:
            exp2 = exp2 + 45 + 29 + 75;
            break;
        }
        exp1 = min(max(exp1, 0), 600); // check condition
        exp2 = min(max(exp2, 0), 600);
    }
    else if (e1 >= 4 && e1 <= 99) // case 2
    {
        float newExp1 = 0.0;
        float newExp2 = 0.0;
        if (e1 >= 4 && e1 <= 19)
        {
            newExp2 = exp2 + (e1 / 4.0) + 19;
            newExp2 = ceil(newExp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            newExp2 = exp2 + (e1 / 9.0) + 21;
            newExp2 = ceil(newExp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            newExp2 = exp2 + (e1 / 16.0) + 17;
            newExp2 = ceil(newExp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            newExp2 = exp2 + (e1 / 4.0) + 19;
            newExp2 = ceil(newExp2);
            if (newExp2 > 200)
            {
                newExp2 = newExp2 + (e1 / 9.0) + 21;
                exp2 = ceil(newExp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            newExp2 = exp2 + (e1 / 4.0) + 19;
            exp2 = ceil(newExp2);
            newExp2 = exp2 + (e1 / 9.0) + 21;
            newExp2 = ceil(newExp2);
            if (newExp2 > 400)
            {
                newExp2 = newExp2 + (e1 / 16.0) + 17;
                exp2 = ceil(newExp2);
                newExp2 = exp2 * 1.15;
                exp2 = ceil(newExp2);
            }
        }
        exp2 = ceil(newExp2);
        exp1 = exp1 - e1;
    }
    else
        return -99;
    conTask1(exp1,exp2); //  condition
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    // int money = M1;

    float S1 = squareNumNearEXP1(EXP1); // Street 01
    // Street 02
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    if (E2 % 2 != 0) // E2 là số lẻ
    {
        float tempM = M1 / 2;
        int tempM1 = ceil(tempM);
        while (true)
        {
            if (HP1 < 200)
            {
                float newHP1 = HP1 * 1.3;
                HP1 = ceil(newHP1);
                M1 = M1 - 150;
                conTask2(HP1, EXP1, M1);
            }
            else
            {
                float newHP1 = HP1 * 1.1;
                HP1 = ceil(newHP1);
                M1 = M1 - 70;
                conTask2(HP1, EXP1, M1);
            }
            // int newM1Sec = EXP1 < 400 ? M1 = M1 - 200 : M1 = M1 - 120;
            // M1 = newM1Sec;
            if (M1 < tempM1)
            {
                break;
            }
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
            }
            else
            {
                M1 = M1 - 120;
            }
            float iExp1 = EXP1 * 1.13;
            EXP1 = ceil(iExp1);
            conTask2(HP1, EXP1, M1);
            if (M1 < tempM1)
            {
                break;
            }
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
            }
            else
            {
                M1 = M1 - 120;
            }
            float newEXP1 = EXP1 * 0.9;
            EXP1 = ceil(newEXP1);
            conTask2(HP1, EXP1, M1);
            if (M1 < tempM1)
            {
                break;
            }
        }
        float newHP = HP1 * 0.83;
        HP1 = ceil(newHP);
        float newEx = EXP1 * 1.17;
        EXP1 = ceil(newEx);
        conTask2(HP1, EXP1, M1);
    }
    else // E2 is Even
    {
        if (HP1 < 200)
        {
            float newHP1 = HP1 * 1.3;
            HP1 = ceil(newHP1);
            M1 = M1 - 150;
            conTask2(HP1, EXP1, M1);
        }
        else
        {
            float newHP1 = HP1 * 1.1;
            HP1 = ceil(newHP1);
            M1 = M1 - 70;
            conTask2(HP1, EXP1, M1);
        }
        if (M1 > 0)
        {
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
            }
            else
            {
                M1 = M1 - 120;
            }
            float newExp = EXP1 * 1.13;
            EXP1 = ceil(newExp);
            conTask2(HP1, EXP1, M1);
        }
        if (M1 > 0)
        {
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
            }
            else
            {
                M1 = M1 - 120;
            }
            float newExp = EXP1 * 0.9;
            EXP1 = ceil(newExp);
            conTask2(HP1, EXP1, M1);
        }
        float newHP = HP1 * 0.83;
        HP1 = ceil(newHP);
        float newEx = EXP1 * 1.17;
        EXP1 = ceil(newEx);
        conTask2(HP1, EXP1, M1);
    }
    float S2 = squareNumNearEXP1(EXP1);
    // street 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = index(E2);
    float S3 = P[i] / 100.0;
    if (S1 == 1 && S2 == 1 && S3 == 1)
    {
        float newExp = EXP1 * 0.75;
        EXP1 = ceil(newExp);
        conTask2(HP1, EXP1, M1);
    }
    else
    {
        float avrP = (S1 + S2 + S3) / 3.0;
        if (avrP < 0.5)
        {
            float newExp = EXP1 * 1.15;
            EXP1 = ceil(newExp);
            float newHP1 = HP1 * 0.85;
            HP1 = ceil(newHP1);
            conTask2(HP1, EXP1, M1);
        }
        else
        {
            float newHP1 = HP1 * 0.9;
            HP1 = ceil(newHP1);
            float newExp = EXP1 * 1.2;
            EXP1 = ceil(newExp);
            conTask2(HP1, EXP1, M1);
        }
    }
    conTask2(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    conTask3(HP1, HP2, EXP1, EXP2);
    int arrayTaxi[10][10];
    int locationI = 0, locationJ = 0;
    for (int i = 0; i < 10; i++) // tạo 1 mảng cho đường đi của taxi
    {
        for (int j = 0; j < 10; j++)
        {
            arrayTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arrayTaxi[i][j] > E3 * 2)
            {
                locationI++;
            }
            if (arrayTaxi[i][j] < -E3)
            {
                locationJ++;
            }
        }
    }
    locationI = singleNum(locationI);
    locationJ = singleNum(locationJ);
    int arrayDetective[10][10];
    int pointDet = INT_MIN;
    for (int i = 0; i < 10; i++) // điểm của detective
    {
        for (int j = 0; j < 10; j++)
        {
            int a = i - j;
            int b = i + j;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (i - j == a || i + j == b)
                    {
                        if (arrayTaxi[i][j] > pointDet)
                        {
                            pointDet = arrayTaxi[i][j];
                        }
                    }
                }
            }
            if (pointDet < 0)
            {
                pointDet = abs(pointDet);
            }
            arrayDetective[i][j] = pointDet;
            pointDet = INT_MIN;
        }
    }
    if (abs(arrayTaxi[locationI][locationJ]) <= arrayDetective[locationI][locationJ])
    {
        float newHP1 = HP1 * (1.1);
        HP1 = ceil(newHP1);
        float newEXP1 = EXP1 * 1.12;
        EXP1 = ceil(newEXP1);
        float newHP2 = HP2 * (1.1);
        HP2 = ceil(newHP2);
        float newEXP2 = EXP2 * 1.12;
        EXP2 = ceil(newEXP2);
        conTask3(HP1, HP2, EXP1, EXP2);
        return arrayDetective[locationI][locationJ];
    }
    else
    {
        float newHP1 = HP1 * (0.9);
        HP1 = ceil(newHP1);
        float newEXP1 = EXP1 * 0.88;
        EXP1 = ceil(newEXP1);
        float newHP2 = HP2 * (0.9);
        HP2 = ceil(newHP2);
        float newEXP2 = EXP2 * 0.88;
        EXP2 = ceil(newEXP2);
        conTask3(HP1, HP2, EXP1, EXP2);
    }
    return arrayTaxi[locationI][locationJ];
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    const char *p = strchr(email, '@');
    int l = p - email;
    char *se = new char[l + 1]; // Tạo một mảng đủ lớn cho chuỗi se
    strncpy(se, email, l);
    se[l] = '\0'; // end Null

    int countPassword = countChar(s);
    int p_se_pass;
    const char *pp_se_pass = strstr(s, se);
    if (pp_se_pass == NULL)
        p_se_pass = -99;
    else
        p_se_pass = pp_se_pass - s;

    int checkSamePass = checkSameCharOver2(s);
    bool spc = specialChar(s);
    int cc = checkChar(s);

    if (countPassword < 8)
        return -1;
    else if (countPassword > 20)
        return -2;
    else if (p_se_pass != -99)
        return (-300 - p_se_pass);
    else if (checkSamePass != -1)
        return (-400 - checkSamePass);
    else if (spc == false)
        return -5;
    else if (cc != -1)
        return (cc);
    else
 return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
int max = -1; int passLocation; int length=-1,lengthMax=-1;
    for (int i = 0; i < num_pwds; i++) 
    {
        int count = 1;               
        const char *originalPass = arr_pwds[i];
        length = countChar(originalPass);
        for (int j = 0; j < num_pwds; j++) 
        {
            if (i != j) {                                  // sure nó kh trùng
                const char *anotherPass = arr_pwds[j];
                if (strcmp(anotherPass, originalPass) == 0)          // so sánh 
                {      
                    count++;                 
                }
            }
        }
       
      
        if (count > max || count == max && length > lengthMax) 
        {
            max = count;
            passLocation=i;
            lengthMax = length;
        }  
    }
    return passLocation;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////