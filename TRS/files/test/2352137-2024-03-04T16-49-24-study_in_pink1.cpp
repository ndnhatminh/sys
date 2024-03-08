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
) 
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) 
    {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
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
int expup(int exp) //update value of exp
{
    if (exp > 600) return 600; 
    if (exp < 0) return 0;
    return exp; 
}

int mup(int m) //update value of m
{
    if (m > 3000) return 3000; 
    if (m < 0) return 0;
    return m;
}

int hpup(int hp) //update value of hp
{
    if (hp > 666) return 666;
    if (hp < 0) return 0;
    return hp;
}
int cheese(char c)
    {
        if (((c == '!') || (c == '@') || (c == '#') || (c == '$') || (c == '%'))  ||  ((c >= '0') && (c <= '9'))  ||  ((c >= 'A') && (c <= 'Z'))  ||  ((c >= 'a') && (c <= 'z')))
            return 0;
        return 1;
    }

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) 
{
    // TODO: Complete this function
    if ((e1 > 99) or (e1 < 0)) return -99;//control value of e1

    else
    {
        exp1 = expup(exp1);//update value of exp1
        exp2 = expup(exp2);//update value of exp2
        if (e1 < 4)//
        {
            if (e1 == 3) exp2 += (29 + 45 +75);
            else if (e1 == 2) exp2 += 75;
                else if (e1 == 1) exp2 += 45;
                    else exp2 += 29;

            exp2 = expup(exp2);//update value of exp2

            int d = e1 * 3 + exp1 * 7;
            if (d % 2)//when d odd
            {
                exp1 -= d/100;

                exp1 = expup(exp1);//update value of exp1
            }
            else// when d even
            {
                exp1 += d/200;
                if (d % 200) exp1++;

                exp1 = expup(exp1);//update value of exp1
            }
        }
        else
        {
            if (e1 < 20)
            {
                exp2 += e1/4 + 19;
                if (e1 % 4) exp2++; 

                exp2 = expup(exp2);//update value of exp2
            }
            else if (e1 < 50)
                {
                    exp2 += e1/9 + 21;
                    if (e1 % 9) exp2++;

                    exp2 = expup(exp2);//update value of exp2
                }
                else if (e1 < 66)
                    {
                        exp2 += e1/16 + 17;
                        if (e1 % 16) exp2++;

                        exp2 = expup(exp2);//update value of exp2
                    }
                    else if (e1 < 80)
                        {
                            exp2 += e1/4 + 19;
                            if (e1 % 4) exp2++;

                            exp2 = expup(exp2);//update value of exp2

                            if (exp2 > 200)
                            {
                                exp2 += e1/9 + 21;
                                if (e1 % 9) exp2++;

                                exp2 = expup(exp2);//update value of exp2
                            }                       
                        }
                        else
                        {
                            exp2 += e1/4 + 19;
                            if (e1 % 4) exp2++;

                            exp2 = expup(exp2);//update value of exp2
                    
                            exp2 += e1/9 + 21;
                            if (e1 % 9) exp2++;

                            exp2 = expup(exp2);//update value of exp2

                            if (exp2 > 400)
                            {
                                exp2 += e1/16 + 17;
                                if (e1 % 16) exp2++;

                                exp2 = expup(exp2);//update value of exp2

                                exp2 = exp2 + ceil(exp2*0.15 - 1e-10);

                                exp2 = expup(exp2);//update value of exp2
                            }
                        }
            exp1 -= e1;
            exp1 = expup(exp1);//update value of exp1
        }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    // TODO: Complete this function
    if ((E2 > 99) or (E2 < 0)) return -99;//control value e2

    EXP1 = expup(EXP1);//update value of exp1
    HP1 = hpup(HP1);//update value of hp1
    M1 = mup(M1);//update value of m1

    int S = round((double)sqrt(EXP1));//calculate p1 
    double P1;
    if ((EXP1 - S*S) >= 0) P1 = 1.0;
    else P1 = ((double)(EXP1/(S*S))+80)/123;

    double d = (double)(M1/2);
    double spent = 0;
    if ((E2%2) && (M1))//when e2 odd
    {
        while (spent <= M1)
        {
            if (HP1 < 200) 
            {
                HP1 = HP1 + ceil(HP1 * 0.3);
                HP1 = hpup(HP1);//update value of hp1

                M1 -= 150;
                M1 = mup(M1);//update value of m1
                spent +=150;
            }
            else 
            {
                HP1 = HP1 + ceil(HP1 * 0.1);
                HP1 = hpup(HP1);//update value of hp1
                //cout << HP1 << endl;
                M1 -= 70;
                M1 = mup(M1);//update value of m1
                spent += 70;
            }
            
            if (spent > M1) break;

            if (EXP1 < 400) 
            {
                EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
                EXP1 = expup(EXP1);//update value of exp1

                M1 -= 200;
                M1 = mup(M1);//update value of m1
                spent += 200;
            }
            else 
            {
                EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
                EXP1 = expup(EXP1);//update value of exp1

                M1 -= 120;
                M1 = mup(M1);//update value of m1
                spent += 120;
            }

            if (spent > M1) break;

            if (EXP1 < 300) 
            {
                EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
                EXP1 = expup(EXP1);//update value of exp1

                M1 = M1 - 100;
                M1 = mup(M1);//update value of m1
                spent += 100;
            }
            else 
            {
                EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
                EXP1 = expup(EXP1);//update value of exp1

                M1 = M1 - 120;
                M1 = mup(M1);//update value of m1
                spent += 120;
            }
            
        }
    }
    else
    {
        if (M1 != 0)
        {
            if (HP1 < 200) 
            {
                HP1 = HP1 + ceil(HP1 * 0.3);
                HP1 = hpup(HP1);////update value of hp1

                M1 -= 150;
                M1 = mup(M1);//update value of m1
            }
            else 
            {
                HP1 = HP1 + ceil(HP1 * 0.1);
                HP1 = hpup(HP1);////update value of hp1

                M1 -= 70;
                M1 = mup(M1);//update value of m1
            }
        }
        
        if (M1 != 0) 
        {
            if (EXP1 < 400) 
            {
                M1 -= 200;
                M1 = mup(M1);//update value of m1

                EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
                EXP1 = expup(EXP1);//update value of exp1
            }
            else 
            {
                M1 -= 120;
                M1 = mup(M1);//update value of m1

                EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
                EXP1 = expup(EXP1);//update value of exp1
            }
        }
        
        if (M1 != 0)
        {
            if (EXP1 < 300) 
            {
                M1 -= 100;
                M1 = mup(M1);//update value of m1

                EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
                EXP1 = expup(EXP1);//update value of exp1
            }
            else 
            {
                M1 -= 120;
                M1 = mup(M1);//update value of m1

                EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
                EXP1 = expup(EXP1);//update value of exp1
            }
        }
    }
    EXP1 = ceil(round(EXP1 * 1.17 * 100) / 100);
    EXP1 = expup(EXP1);//update value of exp1

    HP1 = ceil(HP1 * 0.83);
    HP1 = hpup(HP1);////update value of hp1

    S = round((double)sqrt(EXP1));//calculate P2
    double P2;
    if ((EXP1 - S*S) >= 0) P2 = 1.0;
    else P2 = ((double)(EXP1/(S*S))+80)/123;

    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};//create const array p

    double P3;//calculate p3
    if (E2<10) P3 = P[E2]/100;
    else P3 = P[(E2%10 + E2/10)%10]/100;

    if ((P1 == 1.0) && (P2 == 1.0) && (P3 == 1.0))//minus 25% exp1
    {
        EXP1 = ceil(round(EXP1 * 0.75 * 100) / 100);
        EXP1 = expup(EXP1);//update value of exp1
    }
    else if (((P1 + P2 + P3)/3) < 0.5)
        {
            HP1 = ceil(round(HP1 * 0.85 * 100) / 100);
            HP1 = hpup(HP1);//update value of hp1

            EXP1 = ceil(round(EXP1 * 1.15 * 100) / 100);
            EXP1 = expup(EXP1);//update value of exp1
        }
        else
        {
            HP1 = ceil(HP1*0.9);
            HP1 = hpup(HP1);//update value of hp1

            EXP1 = ceil(round(EXP1 * 1.2 * 100) / 100);
            EXP1 = expup(EXP1);//update value of exp1
        }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    if ((E3 > 99) or (E3 < 0)) return -99;

    EXP1 = expup(EXP1);//update value of exp1
    HP1 = hpup(HP1);//update value of hp1

    EXP2 = expup(EXP2);//update value of exp2
    HP2 = hpup(HP2);//update value of hp2

    int diem[100][100];
    int i = 0, j = 0;

    for (int a = 0; a < 10; a++)//update 0 value for diem
        for (int b = 0; b < 10; b++) diem[a][b] = 0;

    for (int a = 0; a < 10; a++)//find value of diem
        for (int b = 0; b < 10; b++)
        {
            diem[a][b] = ((E3 * b) + (a * 2)) * (a - b);
            if (diem[a][b] > (E3 * 2)) i++;
            if (diem[a][b] < (0-E3)) j++;
        }

    while(i > 9) i = (i/10) + (i%10);//find i
    while(j > 9) j = (j/10) + (j%10);//find j

    int score = diem[i][j];//score of Sherlock and Watson

    for (int a = 0; a < 10; a++)//find score of Sherlock and Watson - SAI CMNR - VD 4.6
        for (int b = 0; b < 10; b++) if ((a - b) == (i - j) || ((a + b) == (i + j)))            
            {
                if (diem[a][b] > score) score = diem[a][b];
            }

    if (abs(diem[i][j]) > score)//cannot catch up the taxi
    {
        EXP1 = ceil((EXP1 * 0.88) - 1e-10);
        EXP1 = expup(EXP1);//update value of exp1

        EXP2 = ceil((EXP2 * 0.88) - 1e-10);
        EXP2 = expup(EXP2);//update value of exp2

        HP1 = ceil((HP1 * 0.9) - 1e-10);
        HP1 = hpup(HP1);//update value of hp1

        HP2 = ceil((HP2 * 0.9) - 1e-10);
        HP2 = expup(HP2);//update value of hp2

        return diem[i][j];
    }
    else//can catch up the taxi
    {
        EXP1 = EXP1 + ceil(EXP1 * 0.12 - 1e-10);
        EXP1 = expup(EXP1);//update value of exp1

        EXP2 = EXP2 + ceil(EXP2 * 0.12 - 1e-10);
        EXP2 = expup(EXP2);//update value of exp2

        HP1 = HP1 + ceil(HP1 * 0.1 - 1e-10);
        HP1 = hpup(HP1);//update value of hp1

        HP2 = HP2 + ceil(HP2 * 0.1 - 1e-10);
        HP2 = hpup(HP2);//update value of hp2

        return score;
    }
    //return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) 
{
    // TODO: Complete this function
    string pw = s; //string pwds
    string mail = email;
    
    if (pw.length() < 8) return -1; //too short

    if (pw.length() > 20) return -2; //too long

    string se = mail.substr(0, mail.find('@'));
    if ((int)pw.find(se) != -1) return -(300 + pw.find(se));

    for (int i = 0; i <= pw.length() - 3; i++)//alike
        if (pw[i] == pw[i + 1] && pw[i + 2] == pw[i + 1]) return -(400 + i);

    if (((int)pw.find('!') == -1) && ((int)pw.find('@') == -1) && ((int)pw.find('#') == -1) && ((int)pw.find('$') == -1) && ((int)pw.find('%') == -1))
        return -5;//none special char

    for (int i = 0; i < pw.length(); i++)
        if (cheese(pw[i])) return i;
    
    return -10;//correct

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    // TODO: Complete this function
    string check[100];//arr pwds

    int count[100];//count of each pwds
    int length[100];//length of pwds
    int max_count = 0;//max count
    int max_length = 0;//max length of max count

    for (int i = 0; i < 50; i++) 
    {
        count[i] = 0;//times of appearance
        length[i] = 0;//length of pwds
    }

    for (int i = 0; i < num_pwds; i++)//convert arr char into string
    {
        const char * pwds = arr_pwds[i];
        check[i] = pwds;
    }

    for (int i = 0; i < num_pwds; i++) 
        if (check[i] != " ")//find the max_count & pwds length
        {
            string trial = check[i];
            for (int j = 0; j < num_pwds; j++) if ((check[j] != " ") && (trial == check[j]))
            {   
                count[i]++;
                length[i] = trial.length();
                check[j] = " ";
                if (count[i] > max_count) max_count = count[i];
            }
        }
        

    int arr_length[100];//length of max count
    for (int i = 0; i < 50; i++) arr_length[i] = 0;

    for(int i = 0; i < num_pwds; i++)
        if (count[i] == max_count) 
        {
            arr_length[i] = length[i];
            if (arr_length[i] > max_length) max_length = arr_length[i];
        }
        
    for (int i = 0; i < num_pwds; i++) 
        if (arr_length[i] == max_length) return i;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////