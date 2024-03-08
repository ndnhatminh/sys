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

void check_mission1(int& exp1, int& exp2)
{
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
}

void check_mission2(int& hp1, int& exp1, int& m1)
{
    if (hp1 < 0) hp1 = 0;
    if (hp1 > 666) hp1 = 666;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (m1 < 0) m1 = 0;
    if (m1 > 3000) m1 = 3000;
}

void check_mission3(int& hp1, int& exp1, int& hp2, int& exp2)
{
    if (hp1 < 0) hp1 = 0;
    if (hp1 > 666) hp1 = 666;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;

    if (hp2 < 0) hp2 = 0;
    if (hp2 > 666) hp2 = 666;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function      
    check_mission1(exp1, exp2);

    /* TRUONG HOP 1 */
    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0: exp2 += 29;
            break;
        case 1: exp2 += 45;
            break;
        case 2: exp2 += 75;
            break;
        default: exp2 += 29 + 45 + 75;
            break;
        }

        int d = e1 * 3 + exp1 * 7;

        if (d % 2 == 0)
        {
            exp1 = ceil(exp1 + (float)d / 200);  /* Always round up, not round off */
        }
        else
        {
            exp1 = ceil(exp1 - (float)d / 100);
        }

        check_mission1(exp1, exp2);
        return exp1 + exp2;
    }

    /* TRUONG HOP 2 */
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(exp2 + (float)e1 / 9 + 21);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + (float)e1 / 16 + 17);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19);
            check_mission1(exp1, exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + (float)e1 / 9 + 21);
            }
        }
        else
        {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19);
            check_mission1(exp1, exp2);
            exp2 = ceil(exp2 + (float)e1 / 9 + 21);     /* Round up first, check later, then compare with if () */
            check_mission1(exp1, exp2);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + (float)e1 / 16 + 17);
                check_mission1(exp1, exp2);
                exp2 = ceil(exp2 * 1.15);
            }
        }

        exp1 = exp1 - e1;
        check_mission1(exp1, exp2);
        return exp1 + exp2;
    }

    else
    {
        return -99;
    }
}



// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
        int s;
        float p1, p2, p3;
        check_mission2(HP1, EXP1, M1);

        if (E2 < 0 || E2 > 99)
        {
            return -99;
        }
        else
        {
            /** ROUTE 1 **/
            /* Find nearest prime */
            int rt_up = ceil(sqrt(EXP1));
            int rt_down = floor(sqrt(EXP1));

            if (abs(rt_up * rt_up - EXP1) <= abs(rt_down * rt_down - EXP1))
            {
                s = rt_up * rt_up;
            }
            else
            {
                s = rt_down * rt_down;
            }

            /* Compare EXP1 to s */
            if (EXP1 >= s)
            {
                p1 = 1;
            }
            else p1 = ((float)EXP1 / s + 80) / 123;
            
            /** ROUTE 2 **/
            int m1_route2 = M1;

            /* Check if M1=0 -> walk */
            if (M1 == 0)
            {
                HP1 = ceil(HP1 * 0.83);
                EXP1 = ceil(EXP1 * 1.17);
                check_mission2(HP1, EXP1, M1);
            }

            else
            {
                if (E2 % 2 != 0)
                {
                    Event_1:
                    if (HP1 < 200)
                    {
                        HP1 = ceil(HP1 * 1.3);
                        M1 -= 150;
                    }
                    else
                    {
                        HP1 = ceil(HP1 * 1.1);
                        M1 -= 70;
                    }
                    check_mission2(HP1, EXP1, M1);

                    /* Check if >50% -> walk */
                    if ((m1_route2 - M1) > (m1_route2 * 0.5))
                    {
                        HP1 = ceil(HP1 * 0.83);
                        EXP1 = ceil(EXP1 * 1.17);
                        check_mission2(HP1, EXP1, M1);
                    }
                    /* Else -> Event 2 */
                    else
                    {
                        if (EXP1 < 400)
                        {
                            M1 -= 200;
                        }
                        else M1 -= 120;

                        EXP1 = ceil(EXP1 * 1.13);
                        check_mission2(HP1, EXP1, M1);

                        /* Check if >50% -> walk */
                        if ((m1_route2 - M1) > (m1_route2 * 0.5))
                        {
                            HP1 = ceil(HP1 * 0.83);
                            EXP1 = ceil(EXP1 * 1.17);
                            check_mission2(HP1, EXP1, M1);
                        }
                        /* Else -> Event 3 */
                        else
                        {
                            if (EXP1 < 300)
                            {
                                M1 -= 100;
                            }
                            else M1 -= 120;

                            EXP1 = ceil(EXP1 * 0.9);
                            check_mission2(HP1, EXP1, M1);

                            /* Check if >50% -> walk */
                            if ((m1_route2 - M1) > (m1_route2 * 0.5))
                            {
                                HP1 = ceil(HP1 * 0.83);
                                EXP1 = ceil(EXP1 * 1.17);
                                check_mission2(HP1, EXP1, M1);
                            }

                            /* Else -> Event 1 */
                            else goto Event_1;
                        }
                    }
                }

                else /* E2 % 2 == 0 */
                {
                    /* Event 1 */
                    if (HP1 < 200)
                    {
                        HP1 = ceil(HP1 * 1.3);
                        M1 -= 150;
                    }
                    else
                    {
                        HP1 = ceil(HP1 * 1.1);
                        M1 -= 70;
                    }

                    check_mission2(HP1, EXP1, M1);

                    /* Check if M1=0 -> walk */
                    if (M1 == 0)
                    {
                        HP1 = ceil(HP1 * 0.83);
                        EXP1 = ceil(EXP1 * 1.17);
                        check_mission2(HP1, EXP1, M1);
                    }

                    /* Else -> Event 2 */
                    else
                    {
                        if (EXP1 < 400)
                        {
                            M1 -= 200;
                        }
                        else M1 -= 120;

                        EXP1 = ceil(EXP1 * 1.13);
                        check_mission2(HP1, EXP1, M1);

                        /* Check if M1=0 -> walk */
                        if (M1 == 0)
                        {
                            HP1 = ceil(HP1 * 0.83);
                            EXP1 = ceil(EXP1 * 1.17);
                            check_mission2(HP1, EXP1, M1);
                        }

                        /* Else -> Event 3 */
                        else
                        {
                            if (EXP1 < 300)
                            {
                                M1 -= 100;
                            }
                            else M1 -= 120;

                            EXP1 = ceil(EXP1 * 0.9);
                            check_mission2(HP1, EXP1, M1);

                            /* Walk */
                            HP1 = ceil(HP1 * 0.83);
                            EXP1 = ceil(EXP1 * 1.17);
                            check_mission2(HP1, EXP1, M1);
                        }
                    }
                }
            }

            /* Find p2, same as Route 1 */
            rt_up = ceil(sqrt(EXP1));
            rt_down = floor(sqrt(EXP1));

            if (abs(rt_up * rt_up - EXP1) <= abs(rt_down * rt_down - EXP1))
            {
                s = rt_up * rt_up;
            }
            else
            {
                s = rt_down * rt_down;
            }

            if (EXP1 >= s)
            {
                p2 = 1;
            }
            else p2 = ((float)EXP1 / s + 80) / 123;
            
            /** ROUTE 3 **/
            int i = 0;
            int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

            if (E2 >= 0 && E2 < 10)
            {
                i = E2;
            }
            else
            {
                int sum_digit = (E2 / 10) + (E2 % 10);
                i = sum_digit % 10;
            }

            p3 = (float)P[i] / 100;
            
            /** REVIEW ALL ROUTES **/
            if (p1 == 1 && p2 == 1 && p3 == 1)
            {
                EXP1 = ceil(EXP1 * 0.75);
            }
            else
            {
                float pos = (p1 + p2 + p3) / 3;
                if (pos < 0.5)
                {
                    HP1 = ceil(HP1 * 0.85);
                    EXP1 = ceil(EXP1 * 1.15);
                }
                else
                {
                    HP1 = ceil(HP1 * 0.9);
                    EXP1 = ceil(EXP1 * 1.2);
                }
            }

            check_mission2(HP1, EXP1, M1);
            return HP1 + EXP1 + M1;
        }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    check_mission3(HP1, EXP1, HP2, EXP2);

    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }

    else
    {
        /** Initialize matrix **/
        int taxi_pt[10][10] = { 0 };

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                taxi_pt[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        /** Find the intersection point **/
        int x_meet = 0, y_meet = 0;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (taxi_pt[i][j] > (E3 * 2))
                {
                    x_meet++;
                }

                if (taxi_pt[i][j] < -E3)
                {
                    y_meet++;
                }
            }
        }

        do
        {
            x_meet = (x_meet / 10) + (x_meet % 10);
        } while (x_meet > 9);

        do
        {
            y_meet = (y_meet / 10) + (y_meet % 10);
        } while (y_meet > 9);

        /** Find Sherlock&Watson point **/
        int sherwat_pt = taxi_pt[x_meet][y_meet];

        /* Consider the left diagonal (dg cheo) */
        for (int i = x_meet, j = y_meet; i < 10 && j < 10; i++, j++)
        {
            sherwat_pt = max(sherwat_pt, taxi_pt[i][j]);
        }

        for (int i = x_meet, j = y_meet; i >= 0 && j >= 0; i--, j--)
        {
            sherwat_pt = max(sherwat_pt, taxi_pt[i][j]);
        }

        /* Consider the right diagonal (dg cheo) */
        for (int i = x_meet, j = y_meet; i < 10 && j >= 0; i++, j--)
        {
            sherwat_pt = max(sherwat_pt, taxi_pt[i][j]);
        }

        for (int i = x_meet, j = y_meet; i >= 0 && j < 10; i--, j++)
        {
            sherwat_pt = max(sherwat_pt, taxi_pt[i][j]);
        }

        /** Can catch up with taxi or not? **/
        if (abs(taxi_pt[x_meet][y_meet]) > abs(sherwat_pt))    //no
        {
            EXP1 = ceil(EXP1 * 0.88);
            EXP2 = ceil(EXP2 * 0.88);
            HP1 = ceil(HP1 * 0.9);
            HP2 = ceil(HP2 * 0.9);
            check_mission3(HP1, EXP1, HP2, EXP2);
            return taxi_pt[x_meet][y_meet];
        }

        else    //yes
        {
            EXP1 = ceil(EXP1 * 1.12);
            EXP2 = ceil(EXP2 * 1.12);
            HP1 = ceil(HP1 * 1.1);
            HP2 = ceil(HP2 * 1.1);
            check_mission3(HP1, EXP1, HP2, EXP2);
            return sherwat_pt;
        }
    }
    
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = "";
    string mail_str = email;
    string s_str = s;
    if (mail_str.find('@') != string::npos)
    {
        se = mail_str.substr(0, mail_str.find('@'));
    }

    /* Too short, too long */
    if (s_str.length() < 8) return -1;
    else if (s_str.length() > 20) return -2;

    /* s contains se in email */
    else if (s_str.find(se) != string::npos)
    {
        int sei = s_str.find(se);
        return -(300 + sei);
    }

    /* Duplication >2 */
    else
    {
        for (int i = 0; i < s_str.length(); i++)
        {
            if ((s_str[i] == s_str[i + 1]) && (s_str[i] == s_str[i + 2]))
            {
                return -(400 + i);
            }

        }
    }

    /* Not contain special char */
    string spec_char = "!@#$%";
    bool found = false;

    for (char c : spec_char)
    {
        if (s_str.find(c) != string::npos)
        {
            found = true;
            break;
        }
    }

    if (found == false) return -5;

    /* Remain cases */
    string invalid_char = "`~^&*()-_=+[{]}\\|;:'\",<.>/?";
    for (char c : invalid_char)
    {
        if (s_str.find(c) != string::npos)
        {
            return s_str.find(c);
            break;
        }
    }

    /* Valid password */
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    string arr_pwd[30];
    int count[30] = {};      // array contains counts of each pwds

    for (int i = 0; i < num_pwds; i++) 
    {
        arr_pwd[i] = arr_pwds[i];
    }

    /* Find counts of each pwds and put them in array */
    for (int i = 0; i < (num_pwds - 1); i++)
    {
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (arr_pwd[i] == arr_pwd[j])
            {
                count[i]++;
            }
        }
    }

    /* Find max count */
    int max_idx = 0;
    int max_cnt = 0;

    for (int i = 0; i < num_pwds; i++)
    {
        if (count[i] > max_cnt)
        {
            max_cnt = count[i];
            max_idx = i;
        }
    }

    /* Find pwds with same max count */
    int equal_idx[30] = {};   //array contains idx of pwds with same max counts
    int num_equal = 0;
    int j = 0;

    for (int i = 0; i < num_pwds; i++)
    {
        if (count[i] == max_cnt)
        {
            equal_idx[j] = i;
            num_equal++;
            j++;
        }
    }

    /* Find longest pwds */
    int max_len = 0;

    for (int j = 0; j < num_equal; j++)
    {
        if ((arr_pwd[equal_idx[j]].size()) > max_len)
        {
            max_len = arr_pwd[equal_idx[j]].size();
            max_idx = equal_idx[j];
        }
    }

    return max_idx;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////