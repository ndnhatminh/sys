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

float checker_hp(float hp)
{
    if (hp > 666)
        return 666;
    if (hp < 0)
        return 0; 
    return ceil(hp - 0.0001);
}

float checker_exp(float exp)
{
    if (exp > 600)
        return 600;
    if (exp < 0)
        return 0;
    return ceil(exp - 0.0001);
}
float checker_m(float m)
{
    if (m > 3000)
        return 3000;
    if (m < 0)
        return 0;
    return ceil(m - 0.0001);
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1>99 || e1<0)
        return -99;

    //change to float for further usage
    float e1_float = e1;
    float exp1_float = exp1;
    float exp2_float = exp2;



    exp1_float = checker_exp(exp1_float);
    exp1_float = checker_exp(exp1_float);
    if (e1_float < 0 || e1_float > 99) 
        return -99;
    //e1=0->3
    if ( e1_float >= 0 && e1_float <=3)
    {
        switch (e1)
        {   
            case 0:
                exp2_float +=29;
                break;
            case 1:
                exp2_float +=45;
                break;
            case 2:
                exp2_float +=75;
                break;
            case 3:
                exp2_float += (29 + 45 +75);
                break;
        }
        float D;
        D = e1_float * 3 + exp1_float * 7;
        if ((int)D % 2 == 0)
        {
            exp1_float = exp1_float + (D / 200);
            exp1_float = checker_exp(exp1_float);
        }
        else
        {
            exp1_float = exp1_float - (D/100);
            exp1_float = checker_exp(exp1_float);
        }
    }
    else
    {
        if (e1_float >= 4 && e1_float <= 19)
        {
            exp2_float += checker_exp(e1_float / 4.0 + 19);
        }
        else if (e1_float >= 20 && e1_float <= 49)
        {
            exp2_float += checker_exp(e1_float / 9.0 + 21);
        }
        else if (e1_float >= 50 && e1_float <= 65)
        {
            exp2_float += checker_exp(e1_float / 16.0 + 17);
        }
        else if (e1_float >= 66 && e1_float <= 79)
        {
            exp2_float += checker_exp(e1_float / 4.0 + 19);
            if (exp2_float > 200)
            {
                exp2_float += checker_exp(e1_float / 9.0 + 21);
            }
        }
        else
        {
            exp2_float += checker_exp(e1_float / 4.0 + 19);
            exp2_float += checker_exp(e1_float / 9.0 + 21);
            if (exp2_float > 400)
            {   
                exp2_float += checker_exp(e1_float / 16 + 17);
                exp2_float = exp2_float * 1.15;
                exp2_float = checker_exp(exp2_float);
            }
        }
        exp1_float-=e1_float;
    }
    exp1 = exp1_float;
    exp2 = exp2_float;
    return exp1_float + exp2_float;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function




float pTong = 0;
    if (E2 < 0 || E2 > 99)
        return -99;
    EXP1 = checker_exp(EXP1);
    HP1 = checker_hp(HP1);
    M1 = checker_m(M1);
    // road 1

    float p1;
    int for_S = round(sqrt(EXP1));
    int S = for_S * for_S;

    if ((S) <= EXP1)
        p1 = 1.00;
    else
        p1 = ((float)EXP1 / (S) + 80) / 123;

    // road 2
    if (E2 % 2 != 0)
    {
        float total = 0;
        float half = (float)M1 * 0.5;
        
        while (total <= half && M1 !=0)
        {
            if (HP1 < 200)
            {
                HP1 = checker_hp(HP1*1.3- 1e-9);
                M1 -= 150;
                total += 150;
            }
            else
            {
                HP1 = checker_hp(HP1*1.1 - 1e-9);
                M1 -= 70;
                total += 70;
            }
            M1 = checker_m(M1);
            if (total > half) 
                break;
            if (EXP1 < 400)
            {
                M1 -= 200;
                total += 200;              
                EXP1 = checker_exp(EXP1*1.13);
            }
            else
            {
                M1 -= 120;
                total += 120;             
                EXP1 = checker_exp(EXP1*1.13);
            }
            M1 = checker_m(M1);
            if (total > half) 
                break;            
            if (EXP1 < 300)
            {
                M1 -= 100;
                total += 100;
                EXP1 = checker_exp(EXP1*0.9);
            }
            else
            {
                M1 -= 120;
                total += 120;
                EXP1 = checker_exp(EXP1*0.9);
            }
            M1 = checker_m(M1);
        }
    }

    else
    {    
        do{
            if (M1 == 0) 
                break;
            if (HP1 < 200)
            {
                HP1 = checker_hp(HP1 * 1.3);
                M1 -= 150;
            }
            else
            {
                HP1 = checker_hp(HP1 * 1.1);
                M1 -= 70;
            }

            if (M1 == 0) break;
            if (EXP1 < 400)
            {
                M1 -= 200; 
                EXP1 = checker_exp(EXP1 * 1.13);
            }
            else
            {
                M1 -= 120; 
                EXP1 = checker_exp(EXP1 * 1.13);
            }

            if (M1 == 0) 
                break;
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = checker_exp(EXP1 * 0.9);
            }
            else if (EXP1 > 300)
            {
                M1 -= 120;              
                EXP1 = checker_exp(EXP1 * 0.9);
            }
            M1 = checker_m(M1);
            break;
        } while(true);
    }   
    HP1 = checker_hp(HP1*0.83);
    EXP1 = checker_exp(EXP1*1.17);
    float p2;
    if (S <= EXP1)
        p2 = 1.00;
    else
        p2 = (float)(EXP1 / S + 80) / 123;
    // road 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float p3 = 0;
    if (E2 < 10 && E2 >= 0)
    {
        p3 = (float)P[E2]/100;
    }
    else
    {
        p3 = (float)P[(E2 / 10 + E2 % 10)%10] / 100;
    }
    if (p1 == 1.00 && p2 == 1.00 && p3 == 1.00)
    {
        EXP1 = checker_exp(EXP1 * 0.75);
    }
    else
    {
        pTong = (p1 + p2 + p3) / 3;
        if (pTong < 0.50)
        {
            HP1 = checker_hp(HP1 * 0.85);
            EXP1 = checker_exp(EXP1 * 1.15);
        }
        else
        {
            HP1 = checker_hp(HP1 * 0.9);
            EXP1 = checker_exp(EXP1 * 1.2);
        }
    }

    return HP1 + EXP1 + M1;

}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    EXP1 = checker_exp((float)EXP1);
    EXP2 = checker_exp((float)EXP2);
    HP1 = checker_hp((float)HP1);
    HP2 = checker_hp((float)HP2);
    int Taxi_map[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Taxi_map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int Hang = 0;
    int Cot = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (Taxi_map[i][j] > E3 * 2)
                Hang++;
            if (Taxi_map[i][j] < -E3)
                Cot++;
        }
    }
    int _1st = 0;
    int _2nd = 0;
    while (Hang >= 10)
    {
        _1st = Hang / 10;
        _2nd = Hang % 10;
        Hang = _1st + _2nd;
    }
    while (Cot >= 10)
    {
        _1st = Cot / 10;
        _2nd = Cot % 10;
        Cot = _1st + _2nd;
    }   
    int x = Hang;
    int y = Cot;
    int array1[19];
    int numm = 0;
    while (x >= 0 && y >= 0)
    {
        array1[numm] = Taxi_map[x][y];
        x--;
        y--;
        numm++;
    }
    x = Hang + 1;
    y = Cot + 1;
    while (x < 10 && y < 10)
    {
        array1[numm] = Taxi_map[x][y];
        x++;
        y++;
        numm++;
    }
    x = Hang-1;
    y = Cot+1;
    while (x >= 0 && y < 10)
    {
        array1[numm] = Taxi_map[x][y];
        x--;
        y++;
        numm++;
    }
    x = Hang + 1;
    y = Cot - 1;
    while (x < 10 && y >= 0)
    {
        array1[numm] = Taxi_map[x][y];
        x++;
        y--;
        numm++;
    }
    int largest = array1[0];
    for (int i = 1; i < numm; i++)
    {
        if (largest < array1[i])
            largest = array1[i];
    }
    if (largest >= abs(Taxi_map[Hang][Cot]))
    {
        EXP1 = checker_exp((float)EXP1 * 1.12);
        EXP2 = checker_exp((float)EXP2 * 1.12);
        HP1 = checker_hp((float)HP1 * 1.1);
        HP2 = checker_hp((float)HP2 * 1.1);

    }
    else
    {
        EXP1 = checker_exp((float)EXP1 * 0.88);
        EXP2 = checker_exp((float)EXP2 * 0.88);
        HP1 = checker_hp((float)HP1 * 0.9);
        HP2 = checker_hp((float)HP2 * 0.9);
    }

    if (largest >= abs(Taxi_map[Hang][Cot]))
    {
          return largest;
    }else   return  Taxi_map[Hang][Cot];
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //compare email
    int mail_length = strlen(email); //-1 cho strlen
    string trc_mail;
    for (int a = 0; a < mail_length - 1; a++)
    {
        if (email[a] != '@')
            trc_mail += email[a];
        else
        {
            break;    
        }
    }    
    int trc_mail_length = trc_mail.size();

    int length_pass = strlen(s) - 1;
    if (length_pass > 20)
    {
        return -2;
    }
    if (length_pass < 8)
    {
        return -1;
    }

    int length_tocheck = strlen(s) - trc_mail_length - 1; //-1 cho strlen
    for (int counter1 = 0; counter1 < length_tocheck; counter1++) 
    {   
        int checker = 0;
        for (int counter2 = 0; counter2 < trc_mail_length; counter2++) 
        {
            if (trc_mail[counter2] == s[counter1 + counter2])
                checker++;
            else
                break;
        }
        if (checker == trc_mail_length)
            return -(300 + counter1);
    }

    for (int counter1 = 0; counter1 < length_pass - 2; counter1++)
    {
        if (s[counter1] == s[counter1+1] && s[counter1] == s[counter1+2])
            return -(400+counter1);
    }

    for (int counter1 = 0; counter1 < length_pass; counter1++)
    {
        if (s[counter1] == '@' || s[counter1] == '#' || s[counter1] == '%' || s[counter1] == '$' || s[counter1] == '!')
            break;
        if (counter1 == length_pass - 1)
            return -5;    
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int max_length = 50;
    struct pass_info{
        int count;
        int length;
        int position;
        char pass[max_length];

    };
    pass_info pass_array[30];
    for (int counter1 = 0; counter1 < 30; counter1++)
    {
        pass_array[counter1].count = 0;
        pass_array[counter1].length = 0;
        pass_array[counter1].position = 0;
    }

    int pass_used = 0;


    for (int counter2 = 0; counter2 < num_pwds; counter2++)
    {
        if (pass_used == 0)
        {
            pass_array[0].count = 1;
            pass_array[0].length = strlen(arr_pwds[0]);
            strcpy(pass_array[0].pass, arr_pwds[0]);
            pass_used +=1;
        }
        else
        {
            for (int counter3 = 0; counter3 < pass_used; counter3 ++)
            {
                if (strcmp(pass_array[counter3].pass, arr_pwds[counter2]) == 0)
                {   
                    pass_array[counter3].count +=1;
                    break;
                }

                if (counter3 == pass_used - 1)
                {
                    pass_array[pass_used].count = 1;
                    pass_array[pass_used].length = strlen(arr_pwds[counter2]);
                    strcpy(pass_array[pass_used].pass, arr_pwds[counter2]);
                    pass_array[pass_used].position = counter2;
                    pass_used +=1;
                }
            }
        } 
    }

    int highest_count = 0;
    int longest_pass = 0;
    int correct_pass = -1;
    for (int a = 0; a < pass_used; a++)
    {
        if (pass_array[a].count > highest_count)
        {
            highest_count = pass_array[a].count;
            longest_pass = pass_array[a].length;
            correct_pass = pass_array[a].position;
        }
        else if (pass_array[a].count == highest_count && pass_array[a].length > longest_pass)
        {   
            longest_pass = pass_array[a].length;
            correct_pass = pass_array[a].position;
        }
    }


    return correct_pass;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////