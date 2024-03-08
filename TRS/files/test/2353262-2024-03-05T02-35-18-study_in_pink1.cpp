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

// REMEMBER CONDITION

void condition(int & in, int con)
{
    if ( in < 0)
    in = 0;
    else {
        switch(con)
        {
            case 1: 
            if (in > 666)
            in = 666;
            break;
            case 2:
            if (in > 600)
            in = 600;
            break;
            case 3:
            if (in > 3000);
            in = 3000;
            break;
            default:
            break; 
        }
    }
}


void conTask2(int& HP1, int& EXP1, int& M1)
{
    HP1 = min(max(0, HP1), 666);
    EXP1 = min(max(0, EXP1), 600);
    M1 = min(max(0, M1), 3000);
}
void conTask3(int& HP1, int& HP2, int& EXP1, int& EXP2)
{
    HP1 = min(max(0, HP1), 666);
    HP2 = min(max(0, HP2), 666);
    EXP1 = min(max(0, EXP1), 600);
    EXP2 = min(max(0, EXP2), 600);
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
if (e1 >= 0 && e1 < 4)
    {
        
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
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
             exp1 =  ceil(exp1 + D / 200.0); // Phần làm khác
            
        }
        else
        {
            exp1 = ceil(exp1 - D / 100); // Phần làm khác
           
        }
        
        condition(exp1,2); // check condition
        condition(exp2,2);
    }

        else if ( e1 >= 4 && e1 <= 99)
        {
            
           if (e1 >= 4 && e1 <= 19)
        
        {
            exp2 = ceil(exp2 + (e1 / 4.0) + 19);
            
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(exp2 + (e1 / 9.0) + 21);
           
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + (e1 / 16.0) + 17);
            
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (e1 / 4.0) + 19);
            
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + (e1 / 9.0) + 21);
                
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(exp2 + (e1 / 4.0) + 19);
            
            exp2 = ceil(exp2 + (e1 / 9.0) + 21);
           
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + (e1 / 16.0) + 17);
                
                exp2 = ceil(exp2 * 1.15);
            
            }
        }
        exp2 = ceil(exp2);
        exp1 = exp1 - e1;
        }
    else
        return -99;
 //  condition

condition(exp1,2); // check condition 
        condition(exp2,2);

    
    return exp1 + exp2;
}

// Task 2
float road1P(int &EXP1 )
{   int a;
    int i=0; 
    float P1;
    while (i*i<EXP1)
    {
        i++;
    }
    if(abs((i)*(i)-EXP1) > abs((i-1)*(i-1)-EXP1))
    {
        a = (i-1)*(i-1);
        }
    else 
    {
        a=(i)*(i);
        }

    if(EXP1 >= a)
        {
        P1=1;
        }
    else 
    {   double S = (i)*(i);
        P1 = (EXP1/S + 80.0)/123.0;
    }
     return P1;    
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
        int sum = num1 + num2;
        i = sum % 10;
    }
    return i;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
// TODO: Complete this function
    // int money = M1;
    float S1 = road1P(EXP1); // Street 01
    // Street 02
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    if (E2 % 2 != 0) // E2 là số lẻ
    {
       
       float con_money = (M1 / 2);
       while ( true)
    {
        // TH1
        if (HP1 < 200)
        {
           float HP0 = (HP1 * 1.3);
            HP1 = ceil(HP0);
            M1 = M1 - 150;
            conTask2(HP1, EXP1, M1);
    
        }
        else 
        {
           float HP0 = (HP1 * 1.1);
            HP1 = ceil(HP0);
            M1 = M1 - 70;
             conTask2(HP1, EXP1, M1);
        }
        if (M1 < con_money)
        {
         break;
        }

        // TH2
        if ( EXP1 < 400)
        {
            M1 = M1 - 200;
        }
        else 
        {
            M1 = M1 - 120;
        }
        float EXP0 = (EXP1 * 1.13);
        EXP1 = ceil(EXP0);
        conTask2(HP1, EXP1, M1);
        if (M1 < con_money) {
        break;
        }
        // TH3 
        if (EXP1 < 300)
        {
            M1 = M1 - 100;
            conTask2(HP1, EXP1, M1);
        }
        else 
        {
            M1 = M1 - 120;
           conTask2(HP1, EXP1, M1);
        }
        float EX= (EXP1 * 0.9);
        EXP1 = ceil(EX);
        conTask2(HP1, EXP1, M1);
        if (M1 < con_money){
        break;
        }
    } 
   float HP0 = (HP1 * 0.83);
    HP1 = ceil(HP0);
   float EXP0 = (EXP1 * 1.17);
        EXP1 = ceil(EXP0);
    conTask2(HP1, EXP1, M1);
}
   
    else if (E2 % 2 == 0)
    {
        // Thuc hien lan luot 3 hanh dong 1 lan
        
        
           // TH1
        if (HP1 < 200)
        {
           float  HP0 = (HP1 + HP1 * 0.3);
             HP1 = ceil(HP0);
            M1 = M1 - 150;
          conTask2(HP1, EXP1, M1);
        }
        else 
        {
            float HP0 = (HP1 + HP1 * 0.1);
             HP1 = ceil(HP0);
            M1 = M1 - 70;
            conTask2(HP1, EXP1, M1);
        }
        if (M1 > 0)
        {
        // TH2
        if ( EXP1 < 400)
        {
            M1 = M1 - 200;
           conTask2(HP1, EXP1, M1);
        }
        else 
        {
            M1 = M1 - 120;
                conTask2(HP1, EXP1, M1);
    
        }
        float   EXP0 = (EXP1 * 1.13);
        EXP1 = ceil(EXP0);
        conTask2(HP1, EXP1, M1);
        }
        if(M1 > 0)
         {

        // TH3 
        if (EXP1 < 300)
        {
           M1 = M1 - 100;
            
           conTask2(HP1, EXP1, M1);
        }
        else 
        {
            M1 = M1 - 120;
            
            conTask2(HP1, EXP1, M1);
        }
       float EXP0 = (EXP1 * 0.9);
        EXP1 = ceil(EXP0);
       conTask2(HP1, EXP1, M1);
         }
        
        
       float HP0 = (HP1 * 0.83);
        HP1 = ceil(HP0);
   float   EXP0 = (EXP1 * 1.17);
        EXP1 = ceil(EXP0);
    conTask2(HP1, EXP1, M1);

    }
    
    float S2 = road1P(EXP1);
    
    // street 3



    // tìm giá trị index

    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = index(E2);
    
    float S3 = P[i] / 100.0;
    
    if (S1 == 1 && S2 == 1 && S3 == 1)
    {
         EXP1 = ceil(EXP1 * 0.75);

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
int twoToone(int &num) // hàm tính số 2 chữ số về 1 chữ số
{
    int i = 0;
    if (num < 0)
    {
        i = num;
    }
    if (num >= 0)
    {
        int num0 = num % 10;
        int num1 = (num - num0) / 10;
        int r = num0 + num1;
        if (r < 10)
        {
            i = r;
        }
        else
        {
            i = twoToone(r);
        }
    }
    return i;
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    conTask3(HP1, HP2, EXP1, EXP2);
    int matrixTaxi[10][10];
    int locationrow = 0, locationcolumn = 0;
    for (int i = 0; i < 10; i++) // tạo 1 mảng cho đường đi của taxi
    {
    for (int j = 0; j < 10; j++)
     {
     matrixTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
      if (matrixTaxi[i][j] > E3 * 2)
            {
                locationrow ++;
            }
            if (matrixTaxi[i][j] < -E3)
            {
                locationcolumn++;
            }
        }
    }
    locationrow = twoToone(locationrow);
    locationcolumn = twoToone(locationcolumn);
    int matrixDetec[10][10];
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
                        if (matrixTaxi[i][j] > pointDet)
                        {
                            pointDet = matrixTaxi[i][j];
                        }
                    }
                }
            }
            if (pointDet < 0)
            {
                pointDet = abs(pointDet);
            }
            matrixDetec[i][j] = pointDet;
            pointDet = INT_MIN;
        }
    }
    if ( (matrixDetec[locationrow][locationcolumn]) >= (abs(matrixTaxi[locationrow][locationcolumn]) ) )
    {
        float HP0 = HP1 * 1.1;
        HP1 = ceil(HP0);
        float EXP0 = EXP1 * 1.12;
        EXP1 = ceil(EXP0);
        float HP00 = HP2 * 1.1;
        HP2 = ceil(HP00);
        float EXP00 = EXP2 * 1.12;
        EXP2 = ceil(EXP00);
        conTask3(HP1, HP2, EXP1, EXP2);
        return matrixDetec[locationrow][locationcolumn];
    }
    else
    {
        float HP0 = HP1 * 0.9;
        HP1 = ceil(HP0);
        float EXP0 = EXP1 * 0.88;
        EXP1 = ceil(EXP0);
        float HP00 = HP2 * 0.9;
        HP2 = ceil(HP00);
        float EXP00 = EXP2 * 0.88;
        EXP2 = ceil(EXP00);
        conTask3(HP1, HP2, EXP1, EXP2);
    }
    return matrixTaxi[locationrow][locationcolumn];
}
// Task 4
int countC(const char *string)
{
    int charN = 0;
    while (*string != '\0')
    {
        
        string ++;
        charN ++;
    }
    return charN ;
}
int checkAdjacent(const char*c) // kiểm tra có phải 2 ký tự liền kề không
{   int num0 = -1;
    int num1 = countC(c);
    int t = 0;
    for (int i = 0; i < num1; i++)
    {
        if(c[i] == c[i+1])
        {
          t ++;
          if(t == 2)
          {
            num0 = i- 1 ;
             break;
          }
        }
        else t = 0;
            
    }
   return num0;
}
int checkC(const char *t) {
    for (int i = 0; t[i] != '\0'; i++) {
        if (!((t[i] >= '0' && t[i] <= '9') || (t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z') ||
              (t[i] == '@' || t[i] == '#' || t[i] == '%' || t[i] == '$' || t[i] == '!')
              )) {
            return i;
        }
    }
    return -1;
}
bool specialChar(const char *t) // kiểm tra ký tự đặc biệt
{
    for (int i = 0; t[i] != '\0'; i++)
     {
         if ((t[i] == '@' || t[i] == '#'|| t[i] == '%'|| t[i] == '$'|| t[i] == '!')){
                return 1;
         }
     }
      return 0;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    const char *p = strchr(email, '@');
    int l = p - email;
    char *se = new char[l + 1]; // Tạo một mảng đủ lớn cho chuỗi se
    strncpy(se, email, l);
    se[l] = '\0'; // end Null

    int countPassword = countC(s);
    int p_se_pass;
    const char *pp_se_pass = strstr(s, se);
    if (pp_se_pass == NULL)
        p_se_pass = -99;
    else
        p_se_pass = pp_se_pass - s;

    int checkSamePass = checkAdjacent(s);
    bool spc = specialChar(s);
    int cc = checkC(s);

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

    return -99;
}




// Task 5
int cCharacter(const char *c)
{
    int cEmail = 0;
    while (*c != '\0')
    {
        c = c + 1 ;
        cEmail = cEmail + 1;
        
    } 
    return cEmail;
    }
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
int timeappear = -1;
  int vitripass; 
 int length=-1,lengthtimeappear=-1;
   
 for (int i = 0; i < num_pwds; i++) 
    {
    int count = 1;
    const char *password = arr_pwds[i];
        length = cCharacter(password);
        int j = 0;
        for (int j = 0; j < num_pwds; j++) 
        { 
            if (i != j) {                                  
                const char *another = arr_pwds[j];
                if (strcmp(another, password) == 0)          // 2 vi tri ke nhau ma no khong giong nhau 
                {      
                    count++;                 
                }
            }
        }
       
      
        if (count > timeappear || count == timeappear && length > lengthtimeappear) 
        {
            timeappear = count;
            vitripass = i;
            lengthtimeappear = length;
        }  
    }
    return vitripass;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////