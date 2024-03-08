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

int firstMeet(int & exp1, int & exp2, int e1)
{
    if(e1 < 0 || e1 > 99) return -99;
    if(e1 >= 0 && e1 <= 3)
    {
        if(e1 == 0) exp2 += 29;
        else if(e1 == 1) exp2 += 45;
        else if(e1 == 2) exp2 += 75;
        else if(e1 == 3) exp2 += (29 + 45 + 75);
        //thiet lap lai 600 neu no vuot qua
        if(exp2 > 600) exp2 = 600;
        //so nguyen quyet dinh
        int D = e1*3 + exp1*7;
        //D chan
        if(D % 2 == 0) exp1 = ceil(exp1 + D*1.0/200);
        else exp1 = ceil(exp1 - D*1.0/100);
        //check exp1
        if(exp1 > 600) exp1 = 600;
        if(exp1 < 0) exp1 = 0;
    }
    else if(e1 >= 4 && e1 <= 99)
    {
        if(e1 >= 4 && e1 <= 19) exp2 = ceil(exp2 + e1*1.0/4 + 19);
        else if(e1 >= 20 && e1 <= 49) exp2 = ceil(exp2 + e1*1.0/9 + 21);
        else if(e1 >= 50 && e1 <= 65) exp2 = ceil(exp2 + e1*1.0/16 + 17);
        else if(e1 >= 66 && e1 <= 79)
        {
            exp2 =  ceil(exp2 + e1*1.0/4 + 19);
            if(exp2 > 200)
            {
                exp2 = ceil(exp2 + e1*1.0/9 + 21) ;
            }
        }
        else if(e1 >= 80 && e1 <= 99)
        {
            exp2 =  ceil(exp2 + e1*1.0/4 + 19);
            exp2 =  ceil(exp2 + e1*1.0/9 + 21);
            if(exp2 > 400)
            {
                exp2 = ceil(exp2 + e1*1.0/16 + 17);
                exp2 = ceil(exp2*115.0/100) ;
            }


        }
        exp1 -= e1;

        if(exp2 > 600) exp2 = 600;
        if(exp1 < 0) exp1 = 0;
    }
     else return -99;
     return exp1 + exp2;

}


void dopath2_1(int & HP1, int & EXP1, int & M1)
{
    if(HP1 < 200)
    {
        HP1 = ceil(HP1*130.0/100) ;
        M1 -= 150;
    }
    else
    {
        HP1 = ceil(HP1*110.0/100) ;
        M1 -= 70;
    }
    if(M1 < 0) M1 = 0;
    if(HP1 > 666) HP1 = 666;
    return;
}

void dopath2_2(int & HP1, int & EXP1, int & M1)
{
    if(EXP1 < 400) M1 -= 200;
    else M1 -= 120;
    EXP1 = ceil(EXP1*113.0/100);
    if(EXP1 > 600) EXP1 = 600;
    if(M1 < 0) M1 = 0;
    return;
}
void dopath2_3(int & HP1, int & EXP1, int & M1)
{
    if(EXP1 < 300) M1 -= 100;
    else M1 -= 120;
    EXP1 = ceil(EXP1*(90.0/100));
    if(EXP1 < 0) EXP1 = 0;
    if(M1 < 0) M1 = 0;
    return;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    if(E2 < 0 || E2 > 99) return -99;
    //con duong 1
    int a1 = 1 ; int a2 = 4; int i = 3;
    while(a2 <= EXP1)
    {
        a1 += i; a2 = a2 +  (i+2); i += 2;
    }
    int S = -1;
    if(abs(a1- EXP1) < abs(a2 - EXP1) ) S = a1;
    else S = a2;
    double P1 = -1;

    if(EXP1 >= S) P1 = 1.0;
    else P1 = (EXP1/S + 80)/123;

    //con duong 2
    if(E2 % 2 == 1)
    {
        int M1_ori = M1;
        while(true)
        {

            //dopath1

            dopath2_1(HP1, EXP1, M1);
            if(M1 < M1_ori/2) break;
            //dopath2
            dopath2_2(HP1, EXP1, M1);
            if(M1 < M1_ori/2) break;
            //dopath3
            dopath2_3(HP1, EXP1, M1);
            if(M1 < M1_ori/2) break;
        }
        HP1 = ceil(HP1*83.0/100) ;
        EXP1 = ceil(EXP1*117.0/100);
        if(HP1 < 0) HP1 = 0;
        if(EXP1 > 600) EXP1 = 600;

    }
    else
    {
        dopath2_1(HP1, EXP1, M1);
        if(M1 > 0)
        {
             dopath2_2(HP1, EXP1, M1);
             if(M1 > 0) dopath2_3(HP1, EXP1, M1);
        }
        HP1 = ceil(HP1*83.0/100) ;
        EXP1 = ceil(EXP1*117.0/100);
        if(HP1 < 0) HP1 = 0;
        if(EXP1 > 600) EXP1 = 600;
    }
     a1 = 1 ; a2 = 4; i = 3;
    while(a2 <= EXP1)
    {
        a1 += i; a2 += (i+2); i += 2;
    }
    S = -1;
    if(abs(a1- EXP1) < abs(a2 - EXP1) ) S = a1;
    else S = a2;
    double P2 = -1;

    if(EXP1 >= S) P2 = 1.0;
    else P2 = (EXP1/S + 80)/123;


    //con duong 3
    //thuc hien task 3

    //tinh P3
    double P_arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = -1;
    if(E2 < 10) P3 = P_arr[E2];
    else
    {
        int i = 0;
        i += (E2%10); E2 /= 10;
        i += (E2%10);
        i = i % 10;
        P3 = P_arr[i];
    }


    //tinh phan tram
    if(P1 == 1.0 && P2 == 1.0 && P3 == 100) EXP1 = ceil(EXP1*75.0/100);
    else
    {
        double P = (P1 + P2 + P3)/3;
        if(P < 0.5 )
        {
            HP1 = ceil(HP1*85.0/100);
            EXP1 = ceil(EXP1*115.0/100);
            if(EXP1 > 600) EXP1 = 600;
        }
        else
        {
            HP1 = ceil(HP1*90.0/100);
            if(HP1 < 0) HP1 = 0;
            EXP1 = ceil(EXP1*120.0/100);
            if(EXP1 > 600) EXP1 = 600;
        }
    }

    return HP1 + EXP1 + M1;
}
int scorepoint(int& E3, int& i, int& j)
{
    return ((E3*j)+(i*2))*(i-j);
}

int findgreatest(int matrix[10][10], int& i_a, int& j_a)
{
    int result = matrix[i_a][j_a];
    for(int i = i_a-1; i >= 0 ; i--)
    {
        for(int j = j_a-1; j >= 0; j--)
        {
            if(result < matrix[i][j]) result = matrix[i][j];
        }
    }
    for(int i = i_a + 1; i < 10; i++)
    {
        for(int j = j_a + 1; j < 10; j++)
        {
            if(result < matrix[i][j]) result = matrix[i][j];
        }
    }
    for(int i = i_a - 1; i >= 0; i--)
    {
        for(int j = j_a + 1 ; j < 10; j++ )
        {
            if(result < matrix[i][j]) result = matrix[i][j];
        }
    }
    for(int i = i_a + 1; i < 10; i++)
    {
        for(int j = j_a -1; j >= 0; j--)
        {
            if(result < matrix[i][j]) result = matrix[i][j];
        }
    }
    return result;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if(E3 < 0 || E3 > 99) return -99;
    int matrix[10][10];
    //E3_2
    int E3_2 = E3*2;
    //toa do gap nhau
    int i_meet = 0; int j_meet =0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            matrix[i][j] = scorepoint(E3, i, j);
            if(matrix[i][j] > E3_2) i_meet++;
            if(matrix[i][j] < -E3) j_meet++;
        }
    }
    while(i_meet >= 10)
    {
        int i_copy = i_meet;
        i_meet = 0;
        i_meet += (i_copy % 10);
        i_copy /= 10;
        i_meet += (i_copy%10);
    }
    while(j_meet >= 10)
    {
         int j_copy = j_meet;
        j_meet = 0;
        j_meet += (j_copy % 10);
        j_copy /= 10;
        j_meet += (j_copy%10);
    }
    int score_sherwas = findgreatest(matrix, i_meet, j_meet);
    //khong duoi kip
    if(abs(matrix[i_meet][j_meet]) > score_sherwas)
    {
        EXP1 = ceil(EXP1*88.0/100);
        EXP2 = ceil(EXP2*88.0/100);
        if(EXP1 < 0) EXP1 = 0;
        if(EXP2 < 0) EXP2 = 0;
        HP1 = ceil(HP1*9.0/10);
        HP2 = ceil(HP2*9.0/10);
        if(HP1 < 0) HP1 = 0;
        if(HP2 < 0) HP2 = 0;
        return matrix[i_meet][j_meet];
    }
    else
    {
        EXP1 = ceil(EXP1*112.0/100);
        EXP2 = ceil(EXP2*112.0/100);
        if(EXP1 > 600) EXP1 = 600;
        if(EXP2 > 600) EXP2 = 600;
        HP1 = ceil(HP1*110.0/100);
        HP2 = ceil(HP2*110.0/100);
        if(HP1 > 666) HP1 = 666;
        if(HP2 > 666) HP2 = 666;
        return score_sherwas;
    }
}

int checktripleconsecutivechars(string& str)
{
    for(int i = 0; i < (int)str.length() - 2; i++)
    {
        if(str[i] == str[i + 1] && str[i] == str[i + 2])
        {
            return i;
        }
    }
    return -1;
}

bool check_kytudacbiet(string& str)
{
    const string kytudacbiet = "@#%$!";

    for(char c : str)
    {
        if(kytudacbiet.find(c) != string::npos) return true;
    }
    return false;
}



// Task 4
int checkPassword(const char * s, const char * email)
{
    string mail = email;
    string s_str = s;
    if((int)s_str.length() < 8) return -1;
    if((int)s_str.length() > 20) return -2;
    int pos_acong = 0;
    while(email[pos_acong] != '@') pos_acong++;
    //tim ky tu email
    string se(email, pos_acong);
    int pos_se = s_str.find(se);
    if(pos_se != string::npos) return -(300 + pos_se);
    int pos_triple = checktripleconsecutivechars(s_str);
    //ba ky tu lien tiep
    if(pos_triple != -1) return -(400 + pos_triple);
    //kiem tra co ky tu dac biet khong
    if(check_kytudacbiet(s_str) == false) return -5;
    //check xem co vi pham yeu cau ky tu khong
    const string kytudacbiet = "@#%$!";
    for(int i = 0 ; i < (int)s_str.length(); i++)
    {
        if(kytudacbiet.find(s_str[i]) != string::npos) continue;
        if((s_str[i] < '0') || (s_str[i] < 'A' && s_str[i] > '9') || (s_str[i] > 'Z' && s_str[i] < 'a') || (s_str[i] > 'z') ) return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    int max_count = 0;
    size_t max_length = 0;
    int index_of_max = -1;

    for(int i = 0; i < num_pwds; i++)
    {
        int count = 0;
        size_t length = strlen(arr_pwds[i]);

        for(int j = i+1 ; j < num_pwds; j++)
        {
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) count++;
        }
        if((count > max_count) || (count == max_count && length > max_length))
        {
            max_count = count;
            max_length = length;
            index_of_max = i;
        }
    }

    return index_of_max;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
