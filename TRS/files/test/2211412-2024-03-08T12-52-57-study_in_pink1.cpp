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
int up_round(double n)
{
    if (n == (int)n) return (int)n;
    else return (int)n + 1;
}
int check_variable(int n, int i)
{
    if (i == 0) 
    {
        if (n > 666) return 666;
        if (n < 0) return 0;
    }
    else if (i == 1)
    {
        if (n > 600) return 600;
        if (n < 0) return 0;
    }
    else if (i == 2)
    {
        if (n > 3000) return 600;
        if (n < 0) return 0;
    }
    return n;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) 
{
    if (e1 >= 0 && e1 <= 99)
    {
        if (e1 <= 3)
        {
            if (e1 == 0) exp2 += 29;
            else if (e1 == 1) exp2 += 45;
            else if (e1 == 2) exp2 += 75;
            else if (e1 == 3) exp2 += 29 + 45 + 75;

            int d = e1*3 + exp1*7;
            if (d%2 == 0) exp1 += up_round((double)d/200);
            else exp1 -= (int)d/100; 
        }
        else
        {
        if (e1 <= 19) exp2 += up_round((double)e1/4 + 19);
        else if (e1 <= 49) exp2 += up_round((double)e1/9 + 21);
        else if (e1 <= 65) exp2 += up_round((double)e1/16 + 17);
        else if (e1 <= 79)
        {
            exp2 += up_round((double)e1/4 + 19);
            if (exp2 > 200) exp2 += up_round((double)e1/9 + 21);
        }
        else if (e1 <= 99)
        {
            exp2 += up_round((double)e1/4 + 19);
            exp2 += up_round((double)e1/9 + 21);
            if (exp2 > 400) 
            {
                exp2 += up_round((double)e1/16 + 17);
                exp2 += up_round((double)exp2*15/100);
            }
        }
        exp1 -= e1;
        }
        
        exp1 = check_variable(exp1 , 1);
        exp2 = check_variable(exp2 , 1);

    }
    else return -99;
    // TODO: Complete this function
    
    return exp1 + exp2;
}

// Task 2
int near_sqare(int n)
{
    int x1 = (int)sqrt(n);
    int x2 = up_round((double)sqrt(n));
    if (abs(n - x1*x1) >= abs(n - x2*x2)) return x2*x2;
    else return x1*x1;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    //Đường 1
    if (E2 <= 0 && E2 >= 99) return -99;
    double P1;
    int S = near_sqare(EXP1);
    if (EXP1 >= S) P1 = 100.0;
    else P1 = ((double)EXP1/S + 80)/123*100;


    //Đường 2
    int M = M1;
    int m = 0;
    do
    {
        if (M1 <= 0) break;

        if (HP1 < 200) 
        {
            HP1+=up_round((double)HP1*30/100);
            M1-=150;
            m += 150;
        }
        else 
        {
            HP1+=up_round((double)HP1*10/100);
            M1-=70;
            m += 70;
        }
        HP1 = check_variable(HP1, 0);
        M1 =check_variable(M1,2);
        if (M1 <= 0 || 2*m > M) break;

        if (EXP1 < 400) 
        {
            M1-=200;
            m += 200;
            EXP1+=up_round((double)EXP1*13/100);
        }
        else 
        {
            M1-=120;
            m += 120;
            EXP1+=up_round((double)EXP1*13/100);
        }
        EXP1=check_variable(EXP1, 1);
        M1=check_variable(M1,2);
        if (M1 <= 0 || 2*m > M) break;

        if (EXP1 < 300) 
        {
            M1-=100;
            m += 100;
        }
        else 
        {
            M1-=120;
            m += 120;
            EXP1-=(int)(EXP1*10/100);
        }
        EXP1=check_variable(EXP1, 1);
        M1=check_variable(M1,2);
        if (M1 <= 0 || 2*m > M) break;
    } 
    while (E2%2 != 0);
    
    HP1-=(int)(HP1*17/100);
    EXP1+=up_round((double)EXP1*17/100);
    EXP1=check_variable(EXP1, 1);
    HP1=check_variable(HP1, 0);

    double P2;
    S = near_sqare(EXP1);
    if (EXP1 >= S) P2 = 100.0;
    else P2 = ((double)EXP1/S + 80)/123*100;

    int Pi[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) i = E2;
    else i = (E2/10 + E2%10)%10;
    double P3 = Pi[i]*1.0;

    if (P1 == 100.0 && P2 == 100.0 && P3 == 100.0) EXP1 -= (int)(EXP1*25/100);
    double P =(P1+P2+P3)/3;
    if (P<50.0) 
    {
        HP1 -= (int)HP1*15/100;
        EXP1 += up_round((double)EXP1*15/100);
    }
    else
    {
        HP1 -= (int)HP1*10/100;
        EXP1 += up_round((double)EXP1*20/100);
    }

    HP1=check_variable(HP1, 0);
    EXP1=check_variable(EXP1, 1);
    M1=check_variable(M1, 2);

    // TODO: Complete this function
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    if (E3 <= 0 && E3 >= 99) return -99;
    int P = E3*2;
    int N = -E3;
    int x = 0;
    int y = 0;

    int road[10][10];
    for (int i = 0;i < 10;i++)
    {
        for (int j = 0;j<10;j++)
        {
            road[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (road[i][j] > P) x++;
            if (road[i][j] < N) y++;
        }
    }
    while (x/10 != 0 || y/10 != 0)
    {
        x = x/10 + x%10;
        y = y/10 + y%10;
    }

    int max = road[x][y];
    int i = x;
    int j = y;
    while (i > 0 && j > 0) 
    {
        i--;
        j--;
    }
    while (i < 10 && j < 10) 
    {
        if (road[i][j] > max) max = road[i][j];
        i++;
        j++;
    }

    // Duyệt qua các phần tử trên đường chéo phụ
    i = x, j= y;
    while (i < 10 && j >= 0) 
    {
        if (road[i][j] > max) max = road[i][j];
        i++;
        j--;
    }

    if (abs(road[x][y]) > max) 
    {
        EXP1-=(int)(EXP1*12/100);
        EXP1=check_variable(EXP1, 1);
        HP1-=(int)(HP1*10/100);
        HP1=check_variable(HP1, 0);
        EXP2-=(int)(EXP2*12/100);
        EXP2=check_variable(EXP2,1);
        HP2-=(int)(HP2*10/100);
        HP2=check_variable(HP2,0);
        return road[x][y];
    }
    else
    {
        EXP1+=up_round(EXP1*12/100);
        EXP1=check_variable(EXP1, 1);
        HP1+=up_round(HP1*10/100);
        HP1=check_variable(HP1, 0);
        EXP2+=up_round(EXP2*12/100);
        EXP2=check_variable(EXP2,1);
        HP2+=up_round(HP2*10/100);
        HP2=check_variable(HP2,0);
        return max;
        
    }
}

// Task 4
int checkPassword(const char * s, const char * email) 
{
    
    // Lấy phần địa chỉ email trước ký tự '@'
    char se[101];
    int i = 0;
    while (email[i] != '@' && email[i] != '\0') 
    {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0'; // Kết thúc chuỗi
    int length = strlen(s);

    bool hasSpecialChar = false;
    int consecutiveCount = 1;

    // Kiểm tra độ dài mật khẩu
    if (length < 8) return -1;
    if (length > 20) return -2;

    // Kiểm tra chuỗi se có trong mật khẩu không
    if (strstr(s, se) != NULL) 
    {
        return -(300 + (strstr(s, se) - s));
    }

    // Kiểm tra các điều kiện khác
    for (i = 0; i < length; i++) 
    {
        // Kiểm tra ký tự liên tiếp giống nhau
        if (i > 0 && s[i] == s[i - 1]) 
        {
            consecutiveCount++;
            if (consecutiveCount > 2) 
            {
                return -(400 + i);
            }
        } 
        else 
        {
            consecutiveCount = 1;
        }
        // Kiểm tra ký tự đặc biệt
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') 
        {
            hasSpecialChar = true;
        } 
        else if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))) 
        {
            // Nếu ký tự không phải là chữ số, chữ cái hoặc ký tự đặc biệt
            return i + 1;
        }

        
    }
    // Kiểm tra ký tự đặc biệt
    if (!hasSpecialChar) return -5;

    // Nếu mật khẩu hợp lệ
    return -10;
    // TODO: Complete this function
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    int index = 0;    

    // Khởi tạo mảng count với giá trị 0
    int count[num_pwds];
    for (int i = 0; i < num_pwds; i++) 
    {
        count[i] = 0;
    }
    // Đếm số lần xuất hiện của mỗi chuỗi
    for (int i = 0; i < num_pwds; i++) 
    {
        for (int j = 0; j < num_pwds; j++) 
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
            {
                count[i]++;
            }
        }
    }
    
    for (int i = 1; i < num_pwds; i++) 
    {
        if (count[i]>count[index]) 
        {
            index = i;
        }
        else if (count[i] == count[index])
        {
            if(strlen(arr_pwds[i])>strlen(arr_pwds[index]) )
            {
                index = i;
            }
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
/////////////////////////////////////////////////