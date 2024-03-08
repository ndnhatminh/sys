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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 > 99 || e1 < 0) return -99;
    
    if (exp1 > 600) exp1 = 600;
    if (exp2 > 600) exp2 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 < 0) exp2 = 0;
    
    if (e1 == 0) exp2 += 29;
    else if (e1 == 1) exp2 += 45;
    else if (e1 == 2) exp2 += 75;
    else if (e1 == 3) exp2 += 29 + 45 + 75;
    else if (e1 >= 4 && e1 <= 19) exp2 += ceil(e1 / 4.0) + 19;
    else if (e1 >= 20 && e1 <= 49) exp2 += ceil(e1 / 9.0) + 21;
    else if (e1 >= 50 && e1 <= 65) exp2 += ceil(e1 / 16.0) + 17;
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 += ceil(e1 / 4.0) + 19;
        exp2 = (exp2 < 0) ? 0 : exp2;
        exp2 = (exp2 <= 600) ? exp2 : 600;
        if (exp2 > 200) exp2 += ceil(e1 / 9.0) + 21;
    }
    else
    {
        exp2 += ceil(e1 / 4.0) + ceil(e1 / 9.0) + 40;
        exp2 = (exp2 < 0) ? 0 : exp2;
        exp2 = (exp2 <= 600) ? exp2 : 600;
        if (exp2 > 400)
        {
            exp2 += ceil(e1 / 16.0) + 17;
            exp2 += ceil(exp2 * 0.15);
        } 
    }
    if (e1 <= 3)
    {
        int d = e1 * 3 + exp1 * 7;
        if (d & 1) exp1 = ceil(exp1 - d / 100.0);
        else exp1 = ceil(exp1 + d / 200.0);
    }
    else exp1 -= e1;
    
    exp1 = (exp1 < 0) ? 0 : exp1;
    exp1 = (exp1 <= 600) ? exp1 : 600;

    exp2 = (exp2 < 0) ? 0 : exp2;
    exp2 = (exp2 <= 600) ? exp2 : 600;
    return exp1 + exp2;
}

// Used for converting number in street 3 - task 2
int calc(int n)
{
    int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return res % 10;
}

// Used for checking nearest square in task 2
int check(int n)
{
    int tmp = sqrt(n);
    int s1 = tmp * tmp;
    int s2 = (tmp + 1) * (tmp + 1);
    if (s1 == n || n - s1 < s2 - n) return 0;
    return s2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
    double p1, p2, p3;

    // Street 1
    if (!check(EXP1)) p1 = 1;
    else 
    {
        p1 = (EXP1 / check(EXP1) + 80) / 123.0;

    }
    
    // Street 2
    double cost = M1 / 2.0;
    if (M1 == 0)
    {
        HP1 = ceil(HP1 - HP1 * 0.17);
        if (HP1 > 666) HP1 = 666;
        EXP1 += ceil(EXP1 * 0.17);
        if (EXP1 > 600) EXP1 = 600; 
    }
    else
    {
        if (E2 & 1)
    {
        while (M1 >= cost)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 + HP1 * 0.3);
                if (HP1 > 666) HP1 = 666;
                M1 -= 150;
                if (M1 <= 0) M1 = 0;
            }
            else
            {
                HP1 = ceil(HP1 + HP1 * 0.1);
                if (HP1 > 666) HP1 = 666;
                M1 -= 70;
                if (M1 <= 0) M1 = 0;
            }
            
            if (M1 < cost) break;

            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            if (M1 <= 0) M1 = 0;
            EXP1 = ceil(EXP1 + EXP1 * 0.13);
            if (EXP1 > 600) EXP1 = 600;
            
            if (M1 < cost) break;

            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            if (M1 <= 0) M1 = 0;
            EXP1 = ceil(EXP1 - EXP1 * 0.1);

        }
        HP1 = ceil(HP1 - HP1 * 0.17);
        if (HP1 > 666) HP1 = 666;
        EXP1 = ceil(EXP1 + EXP1 * 0.17);
        if (EXP1 > 600) EXP1 = 600;
    }
    else
    {
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 + HP1 * 0.3);
            if (HP1 > 666) HP1 = 666;
            M1 -= 150;
            if (M1 <= 0) M1 = 0;
        }
        else
        {
            HP1 = ceil(HP1 + HP1 * 0.1);
            if (HP1 > 666) HP1 = 666;
            M1 -= 70;
            if (M1 <= 0) M1 = 0;
        }
        if (M1 > 0)
        {
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            if (M1 <= 0) M1 = 0;
            EXP1 = ceil(EXP1 + EXP1 * 0.13);
            if (EXP1 > 600) EXP1 = 600;
                
            if (M1 > 0)
            {
                if (EXP1 < 300) M1 -= 100;
                else M1 -= 120;
                if (M1 <= 0) M1 = 0;
                EXP1 = ceil(EXP1 - EXP1 * 0.1);
            }    
        }
        HP1 = ceil(HP1 - HP1 * 0.17);
        if (HP1 > 666) HP1 = 666;
        EXP1 += ceil(EXP1 * 0.17);
        if (EXP1 > 600) EXP1 = 600; 
    }
    }
    

    if (!check(EXP1)) p2 = 1;
    else 
    {
        p2 = (EXP1 / check(EXP1)  + 80) / 123.0;
    }

    // Street 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) p3 = P[E2] / 100.0;
    else p3 = P[calc(E2)] / 100.0;

    if (p1 + p2 + p3 == 3) EXP1 = ceil(EXP1 - EXP1 * 0.25);
    else 
    {
        double res = (p1 + p2 + p3) / 3.0;
        if (res < 0.5) 
        {
            HP1 = ceil(HP1 - HP1 * 0.15);
            EXP1 += ceil(EXP1 * 0.15);
            if (EXP1 > 600) EXP1 = 600;
        }
        else
        {
            HP1 = ceil(HP1 - HP1 * 0.1);
            EXP1 += ceil(EXP1 * 0.2);
            if (EXP1 > 600) EXP1 = 600;
        }
    }
    
    return HP1 + EXP1 + M1;
}

int convert(int n)
{
    return (n % 9 == 0) ? 9 : (n % 9);
}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int a[10][10];
    int cnt1 = 0, cnt2 = 0, point = -1e9;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = (E3 * j +  i * 2) * (i - j);
            if (a[i][j] > E3 * 2) ++cnt1;
            else if (a[i][j] < -E3) ++cnt2;
        }
    }
    if (cnt1 > 9) cnt1 = convert(cnt1);
    if (cnt2 > 9) cnt2 = convert(cnt2);
    int tmp1 = cnt1, tmp2 = cnt2;
    
    while (tmp1 >= 0 && tmp2 >= 0)
    {
        point = max(point, a[tmp1--][tmp2--]);
    }
    
    tmp1 = cnt1, tmp2 = cnt2;
    while (tmp1 < 10 && tmp2 < 10)
    {
        point = max(point, a[tmp1++][tmp2++]);
    }
    
    tmp1 = cnt1, tmp2 = cnt2;
    while (tmp1 >= 0 && tmp2 < 10)
    {
        point = max(point, a[tmp1--][tmp2++]);
    }

    tmp1 = cnt1, tmp2 = cnt2;
    while (tmp1 < 10 && tmp2 >= 0)
    {
        point = max(point, a[tmp1++][tmp2--]);
    }
    if (abs(a[cnt1][cnt2]) > abs(point))
    {
        EXP1 = ceil(EXP1 - 0.12 * EXP1);
        EXP2 = ceil(EXP2 - 0.12 * EXP2);
        HP1 = ceil(HP1 - 0.1 * HP1);
        HP2 = ceil(HP2 - 0.1 * HP2);
        return a[cnt1][cnt2];
    }
    else
    {
        EXP1 += ceil(0.12 * EXP1);
        if (EXP1 > 600) EXP1 = 600;
        EXP2 += ceil(0.12 * EXP2);
        if (EXP2 > 600) EXP2 =600;
        HP1 += ceil(0.1 * HP1);
        if (HP1 > 666) HP1 = 666;
        HP2 += ceil(0.1 * HP2);
        if (HP2 > 666) HP2 = 666;
        return abs(point);
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int len = strlen(email);
    int len_pass = strlen(s);
    
    if (len_pass < 8) return -1; // nho kich thuoc toi thieu
    if (len_pass > 20) return -2; // lon hon kich thuoc toi da
    
    string email_str = email, pass_str = s;
    string se = "";
    
    for (int i = 0; i < len; i++)
    {
        if (email_str[i] != '@') se += email_str[i];
        else break;
    }
    size_t check = pass_str.find(se);
    if (check < len_pass && check != string::npos) return -(300 + check); // chua string se

    bool check_sym = 0;
    for (int i = 2; i < len_pass; i++)
    {
        if (pass_str[i] == '@'|| pass_str[i] == '#' || pass_str[i] == '%' || pass_str[i] == '$' || pass_str[i] == '!') check_sym = 1; // check ky tu dac biet
        if (pass_str[i] == pass_str[i - 1] && pass_str[i] == pass_str[i - 2]) return -(400 + i - 2); // check ki tu lien tiep

    }
    if (pass_str[0] == '@'|| pass_str[0] == '#' || pass_str[0] == '%' || pass_str[0] == '$' || pass_str[0] == '!') check_sym = 1;
    if (pass_str[1] == '@'|| pass_str[1] == '#' || pass_str[1] == '%' || pass_str[1] == '$' || pass_str[1] == '!') check_sym = 1;
    
    if (!check_sym) return -5; // khong chua ki tu dac biet
    for (int i = 0; i < len_pass; i++)
    {
        if (pass_str[i] < 48 || (pass_str[i] > 57 && pass_str[i] < 65) || (pass_str[i] > 90 && pass_str[i] < 97) || pass_str[i] > 122)
        {
            if (pass_str[i] != '@'&& pass_str[i] != '#' && pass_str[i] != '%' && pass_str[i] != '$' && pass_str[i] != '!') return i;
        }
    }
    return -10;
}
int count(const char * arr_pwds[], int num_pwds, string s)
{
    int res = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (arr_pwds[i] == s) ++res;
    }   
    return res;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_freq = 0, max_len = 0, res = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        int cur_len = strlen(arr_pwds[i]);
        int cur_freq = count(arr_pwds, num_pwds, arr_pwds[i]);
        if (cur_freq > max_freq || (cur_freq == max_freq && cur_len > max_len))
        {
            max_freq = cur_freq;
            max_len = cur_len;
            res = i;
        }
    }
    return res;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////