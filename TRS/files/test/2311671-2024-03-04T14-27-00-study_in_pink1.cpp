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
void limit_exp(int &exp)
{
    exp = max(min(exp, 600), 0);
}
void limit_money(int &m)
{
    m = max(min(m, 3000), 0);
}
void limit_hp(int &hp)
{
    hp = max(min(hp, 666), 0);
}


// Task 1
// test theo file pdf
int case1(int & exp1, int & exp2, int e1)
{
    switch (e1)
    {
    case 0:
        exp2 += 29;
        limit_exp(exp2);
        break;
    case 1:
        exp2 += 45;
        limit_exp(exp2);
        break;
    case 2:
        exp2 += 75;
        limit_exp(exp2);
        break;
    case 3:
        exp2 = exp2 + 29 + 45 + 75;
        limit_exp(exp2);
        break;
    }
    int D = e1 * 3 + exp1 * 7;
    if (!(D & 1))
        exp1 = exp1 + ceil(D/200.0);
    else
        exp1 = exp1 - floor(D/100);
    limit_exp(exp1);
    return exp1 + exp2;
}
int subcase2_1(int e1)
{
    return ceil(e1 / 4.0) + 19;
}
int subcase2_2(int e1)
{
    return ceil(e1 / 9.0) + 21;
}
int subcase2_3(int e1)
{
    return ceil(e1 / 16.0) + 17;
}
int case2(int &exp1, int & exp2, int e1)
{
    if (e1 > 3 && e1 < 20)
    {
        exp2 += subcase2_1(e1);
        exp1 -= e1;
        limit_exp(exp2);
        limit_exp(exp1);
    }   

    if (e1 >= 20 && e1 < 50)
    {   
        exp2 += subcase2_2(e1);
        exp1 -= e1;
        limit_exp(exp2);
        limit_exp(exp1);
    }
    if (e1 >= 50 && e1 <= 65)
    {
        exp2 += subcase2_3(e1);
        exp1 -= e1;
        limit_exp(exp2);
        limit_exp(exp1);
    }
    if (e1 > 65 && e1 < 80)
    {
        exp2 += subcase2_1(e1);
        limit_exp(exp2);
        if (exp2 > 200)
            exp2 += subcase2_2(e1);
        exp1 -= e1;
        limit_exp(exp2);
        limit_exp(exp1);
    }
    if (e1 >= 80 && e1 < 100)
    {
        exp2 += subcase2_1(e1);
        exp2 += subcase2_2(e1);
        limit_exp(exp2);
        if (exp2 > 400)
        {
            exp2 += subcase2_3(e1);
            exp2 += ceil(exp2 * 15 / 100.0);
            limit_exp(exp2);
        }   
        exp1 -= e1;
        limit_exp(exp1);
    }
    return exp1 + exp2;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1 < 0 || e1 > 99)
        return -99;
    limit_exp(exp1);
    limit_exp(exp2);
    if (e1 >= 0 && e1 <= 3)
        return case1(exp1, exp2, e1);
    else if (e1 > 3 && e1 < 100)
        return case2(exp1, exp2, e1);
    else 
        return -99;
}





// Task 2
//test theo file pdf
void road1(int & EXP1, double & P1)
{
    int unsquared_1 = floor(sqrt(EXP1));
    int unsquared_2 = unsquared_1 + 1;
    unsquared_1 *= unsquared_1;
    unsquared_2 *= unsquared_2;
    if ( abs(EXP1 - unsquared_1) <= abs(EXP1 - unsquared_2))
        P1 = 100;
    else
        P1 = ceil((((double)EXP1 / unsquared_2) + 80) * 100 / 123);
    //cout <<"P1:    "<< P1<< endl;//
}

void action1(int & HP1, int & M1)
{
    if (HP1 < 200)
    {
        HP1 = HP1 + ceil(HP1 * 30 / 100.0);
        M1 -= 150;
        limit_hp(HP1);
        limit_money(M1);
    }
    else
    {
        HP1 = HP1 + ceil(HP1 * 10 / 100.0);
        M1 -= 70;
        limit_hp(HP1);
        limit_money(M1);
    }
    //cout << "hp  " <<HP1 << endl;//
}
void action2(int & EXP1, int & M1)
{
    if (EXP1 < 400)
    {
        M1 -= 200;
        limit_money(M1);
    }
    else
    {
        M1 -= 120;
       
        limit_exp(EXP1);
        limit_money(M1);
    }
    EXP1 = EXP1 + ceil(EXP1 * 13 / 100.0);
     //cout << EXP1 << endl;//
}
void action3(int & EXP1, int & M1)
{
    if (EXP1 < 300)
        M1 -= 100;
    else
        M1 -= 120;
    EXP1 -= floor(EXP1 * 10 / 100);
    //cout << EXP1 << endl;//
    limit_money(M1);
    limit_exp(EXP1);
}

int road2(int & HP1, int & EXP1, int & M1, int E2, double & P2) 
{
    
    if (!(E2 & 1))
    {
       if (M1 == 0)
    {
        HP1 -= floor(HP1 * 17 / 100);
        EXP1 = EXP1 + ceil(EXP1 * 17 / 100.0);
        limit_hp(HP1);
        limit_exp(EXP1);
          //  cout << EXP1 << endl;//
        //cout <<"hp   " <<HP1 << endl; //
        road1(EXP1, P2);
        return 0;
    }
        
        action1(HP1, M1);
        if (M1 == 0)
        {
            HP1 -= floor(HP1 * 17 / 100);
            EXP1 = EXP1 + ceil(EXP1 * 17 / 100.0);
            limit_hp(HP1);
            limit_exp(EXP1);
            //cout << EXP1 << endl;//
            //cout <<"hp   "<< HP1 << endl; //
            road1(EXP1, P2);
            return 0;
        }
        action2(EXP1, M1);
        if (M1 == 0)
        {
            HP1 -= floor(HP1 * 17 / 100);
            EXP1 = EXP1 + ceil(EXP1 * 17 / 100.0);
            limit_hp(HP1);
            limit_exp(EXP1);
            //cout << EXP1 << endl;//
            //cout<<"hp   " << HP1 << endl; //
            road1(EXP1, P2);
            return 0;
        }
        action3(EXP1, M1);
        if (M1 == 0)
        {
            HP1 -= floor(HP1 * 17 / 100);
            EXP1 = EXP1 + ceil(EXP1 * 17 / 100.0);
            limit_hp(HP1);
            limit_exp(EXP1);
            //cout << EXP1 << endl;//
            //cout <<"hp   " <<HP1 << endl; //
            road1(EXP1, P2);
            return 0;
        }
        HP1 -= floor(HP1 * 17 / 100);
        EXP1 = EXP1 + ceil(EXP1 * 17 / 100.0);
       //cout << EXP1 << endl;//
        //cout <<"hp   "<< HP1 << endl; //
        road1(EXP1, P2);
        return 0;
    }
    else
    {
        int money_max = M1/2;
        while (true)
        {
            if (M1 == 0)
                break;
            action1(HP1, M1);
            if (M1 < (money_max))
                break;
            action2(EXP1, M1);
            if (M1 < (money_max))
                break;
            action3(EXP1, M1);
            if (M1 < (money_max))
                break;
        }
        HP1 -= floor(HP1 * 17 / 100);
        EXP1 = EXP1 + ceil(EXP1 * 17 / 100.0);
        //cout << EXP1 << endl;//
        //cout << "hp  "<<HP1 << endl; //
        road1(EXP1, P2);
        return 0;
    }
    return 0;
}
void road3(int E2, double & P3)
{
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 / 10 == 0)
        P3 = P[E2];
    else
    {
        while (E2 / 10 != 0)
        {
            int donvi = E2 % 10;
            //cout << " truoc  "<< donvi<< endl;//
            E2 = floor(E2 / 10.0);
            //cout << " truoc  "<< E2<< endl;//
            E2 = donvi + E2;
        }
        //cout << "E2: "<<E2 <<endl;
        P3 = P[E2];
    }
    //cout << "P3:  "<< P3<< endl;//
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99)
        return -99;
    double P1 = 0, P2 = 0, P3 = 0;
    limit_hp(HP1);
    limit_exp(EXP1);
    limit_money(M1);
    road1(EXP1, P1);
    road2(HP1, EXP1, M1, E2, P2);
    road3(E2, P3);
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        //EXP1 -= floor(EXP1 * 25 / 100);
        //return HP1 + EXP1 + M1;
    } 
    double P_total = (P1 + P2 + P3) / 3;
    if (P_total < 50)
    {
        HP1 -= floor(HP1 * 15 / 100);
        EXP1 = EXP1 + ceil(EXP1 * 15 / 100.0);
        limit_hp(HP1);
        limit_exp(EXP1);
    }
    else
    {
        HP1 -= floor(HP1 * 10 / 100);
        EXP1 = EXP1 + ceil(EXP1 * 20 / 100.0);
        limit_hp(HP1);
        limit_exp(EXP1);
    }
    
    return HP1 + EXP1 + M1;
}



// Task 3

// test theo file pdf
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;
    limit_hp(HP1);  limit_exp(EXP1);
    limit_hp(HP2);  limit_exp(EXP2);
    int taxi_map[10][10] = {};                      // set up the matrix
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            taxi_map[i][j] = (i - j) * ((E3 * j)+ (i * 2));
    
    
    int pos = 0;                                    //find the cross point
    int neg = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (taxi_map[i][j] > (E3 * 2))
                pos ++;
            else if (taxi_map[i][j] < (-E3))
                neg ++;
    while(pos / 10 != 0)
    {
        int i = pos % 10;
        pos /= 10;
        pos += i;
    }
    while(neg / 10 != 0)
    {
        int i = neg % 10;
        neg /= 10;
        neg += i;
    }


    int point_Sher = taxi_map[pos][neg];            // find the sherlock point
    int point_taxi = taxi_map[pos][neg];
    for (int i = pos, j = neg ; i < 10 && j < 10; i++, j ++)
        point_Sher = max(taxi_map[i][j], point_Sher);
    for (int i = pos, j = neg ; i < 10 && j >= 0; i++, j --)
        point_Sher = max(taxi_map[i][j], point_Sher);
    for (int i = pos, j = neg ; i >= 0 && j < 10; i--, j ++)
        point_Sher = max(taxi_map[i][j], point_Sher);
    for (int i = pos, j = neg ; i >= 0 && j >= 0; i--, j --)
        point_Sher = max(taxi_map[i][j], point_Sher);
    
    if (abs(point_Sher) > abs(point_taxi))          // return the result with the condition
    {
        EXP1 = EXP1 + ceil(EXP1 * 12 / 100.0);
        HP1 = HP1 + ceil(HP1 * 10 /100.0);
        EXP2 = EXP2 + ceil(EXP2 * 12 / 100.0);
        HP2 = HP2 + ceil(HP2 * 10 / 100.0);
        limit_hp(HP1);  limit_exp(EXP1);
        limit_hp(HP2);  limit_exp(EXP2);
        return point_Sher;
    }    
    else
    {   
        EXP1 = EXP1 - floor(EXP1 * 12 / 100);
        HP1 = HP1 - floor(HP1 * 10 /100);
        EXP2 = EXP2 - floor(EXP2 * 12 / 100);
        HP2 = HP2 - floor(HP2 * 10 / 100);
        limit_hp(HP1);  limit_exp(EXP1);
        limit_hp(HP2);  limit_exp(EXP2);
        return point_taxi;
    }
}



// Task 4
int checkPassword(const char * s, const char * email) {// one remaining case
    size_t Size_s = strlen(s);
    
    if (Size_s < 8)//longer
        return -1;
    if (Size_s > 20)//shorter
        return -2;
        
    string se = "";
    for (int i = 0; email[i] != '@'; i ++)
        se += (email[i]);
    size_t Size_se = se.length();
    for (int i = 0; i < Size_s - Size_se; i++) //se_contained();
    {   
        int j;
        for (j = 0; j < Size_se; j++)
            if (s[i + j] != se[j])
                break;
        if (j == Size_se)
            return (- (300 + i));
    }


    for (int i = 0; i < Size_s - 2; i++) //common_sub();
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return (- (400 + i));    
    

    int count = 33;//non_special();
    bool special = 0;
    do
    {
        bool var = 0;
        for (int i = 0; i < Size_s; i++)
            if (s[i] == count)
            {
                special = 1;
                var = 1;
            }
        if (var == 1)
            break;
        if (count == 33)
        {
            count += 2;
            continue;
        }   
        count ++;
        
    }while (count <= 38);
    if (special == 0)
        return -5;
    

    for (int  i = 0; i < strlen(s); i++)
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!' || (isalnum(s[i])))
            continue;
        else 
            return i;
    //non_valid()___ contain other undeclared character


    return -10;
    //approriate();
}



// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string max_count_pass;
    int max_count = 0;
    //count which max
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = 0; j < num_pwds; j++)
            if (arr_pwds[i] == arr_pwds[j])
                count ++;
        if (count > max_count || (count == max_count && strlen(arr_pwds[i]) > max_count_pass.length())) {
            max_count = count;
            max_count_pass = arr_pwds[i];
        }
    }

    // find first pos
    for (int i = 0; i < num_pwds; i++) 
        if (arr_pwds[i] == max_count_pass)
            return i;
    
    // Not found
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////