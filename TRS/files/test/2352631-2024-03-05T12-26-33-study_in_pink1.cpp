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

void condition(int & exp1, int & exp2, int e1) {
     //EXP1
            if (exp1 > 600)
            {exp1 = 600;}
            else if (exp1 < 0)
            {exp1 = 0;}
            //EXP2
            else if (exp2 > 600)
            {exp2 = 600;}
            else if (exp2 < 0)
            {exp2 = 0;}
            
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
     if (e1 < 0 || e1 > 99){
        return -99;
    }
    else{
    condition(exp1, exp2, e1);
    // TODO: Complete this function
             if (e1 < 0 || e1 > 99){
        return -99;
    }
    }
        if (e1 >= 0 && e1 <= 3) {
             condition(exp1, exp2, e1);
            switch (e1) {
                case 0:
                condition(exp1, exp2, e1);
                    exp2 += 29;
                    condition(exp1, exp2, e1);
                    break;
                case 1:
                condition(exp1, exp2, e1);
                    exp2 += 45;
                    condition(exp1, exp2, e1);
                    break;
                case 2:
                condition(exp1, exp2, e1);
                    exp2 += 75;
                    condition(exp1, exp2, e1);
                    break;
                case 3:
                condition(exp1, exp2, e1);
                    exp2 += 29 + 45 + 75;
                    condition(exp1, exp2, e1);
                    break;
            }
            // Calculating D
            int D = e1 * 3 + exp1 * 7;

            // Checking if D is even or odd
            if (D % 2 == 0) {
                double exp12;
                exp12 = exp1 + D / 200.0;
                exp1 = ceil(exp12);
            } else {
                double exp12;
                exp12 = exp1 - D / 100.0;
                exp1 = ceil(exp12);
            }
        }
        // case 2 e1 values 4 to 99
         if (e1 >= 4 && e1 <= 99) {
            condition(exp1, exp2, e1);
            double exp21;
            switch (e1) {
                    
                case 4 ... 19: //info 1
                condition(exp1, exp2, e1);
                    exp21 = exp2 + (e1 / 4.0 + 19.0);
                    exp2 = ceil(exp21);
                    break;
                    
                case 20 ... 49: //info 2
                condition(exp1, exp2, e1);
                    exp21 = exp2 + (e1 / 9.0 + 21.0);
                    exp2 = ceil(exp21);
                    break;
                    
                case 50 ... 65: //info 3
                condition(exp1, exp2, e1);
                    exp21 = exp2 + (e1 / 16.0 + 17.0);
                    exp2 = ceil(exp21);
                    break;
                    
                case 66 ... 79: //info 4
                    //exp 2 after info 1
                    condition(exp1, exp2, e1);
                    exp21 = exp2 + (e1 / 4.0 + 19.0);
                    exp2 = ceil(exp21);
                    if (exp21 > 200)
                    {
                        exp21 = exp2 + (e1 / 9.0 + 21.0);
                        exp2 = ceil(exp21);
                    }
                    break;
                    
               case 80 ... 99: //info 5
                    //exp2 after info 1 and 2
                    condition(exp1, exp2, e1);
                    exp21 = exp2 + (e1 / 4.0 + 19.0);
                    exp21 = ceil(exp21);
                    exp21 = exp21 + (e1 / 9.0 + 21.0);
                    exp2 = ceil(exp21);
                    if (exp2 > 400) {
                        exp21 = exp2 + (e1/ 16.0 + 17.0);
                        exp21 = ceil(exp21);
                        //exp2 after info 1 2 3
                        exp21 = 1.15 * exp21;
                        exp2 = ceil(exp21);
                    }
                    
                    break;
            }
            // Rounding exp2
            exp2 = ceil(exp2);
           
          // Subtracting e1 from exp1
            exp1 -= e1;
            condition(exp1, exp2, e1);
        }
             condition(exp1, exp2, e1);
        return exp1 + exp2;
      
      
}

void condition2(int & HP1, int & EXP1, int & E2, int & M1 ) {
            //HP1
            if (HP1 > 666)
            {HP1 = 666;}
            else if (HP1 < 0)
            {HP1 = 0;}
            //HP1
            else if (EXP1 > 600)
            {EXP1 = 600;}
            else if (EXP1 < 0)
            {EXP1 = 0;}
            //M1
            if (M1 < 0)
            {M1 = 0;}
            else if (M1 > 3000)
            {M1 = 3000;}
            
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //CONDITIONS
    //E2
    
    if(E2 < 0 || E2 > 99)
        {
        return -99;
        }
    else
    {
    
    condition2(HP1, EXP1, E2, M1);

    // TODO: Complete this function
    //ROAD 1
    //find nearest perfect square
    double root_of_exp = sqrt(EXP1);

    int nearest_int = round(root_of_exp);

    int S = nearest_int * nearest_int;

    //find P1
    double P1;
    if (EXP1 >= S) {
        P1 = 100.0;
    }
    else {
        P1 = ((EXP1 / S + 80.0 )/123.0) * 100;
    }
    
    //ROAD 2
    //⋆𐙚₊˚⊹♡‧₊˚✩ ₊˚⊹♡𝄞✮⋆˙.𖥔 ݁ ˖ᡣ𐭩
    //E2 is odd
     if (E2 % 2 == 1){
        int M = M1 * 0.5;
        int spent = 0;
        double HP12;
        double EXP12;
        do {
            ///////////////////////////// 1st event
            if (HP1 < 200){
                  condition2(HP1, EXP1, E2, M1);
                HP12 = HP1 * 1.3;
                HP1 = ceil(HP12);
                M1 -= 150;spent += 150;
                
            }
            else
            {
                  condition2(HP1, EXP1, E2, M1);
                HP12 = HP1 * 1.1;
                HP1 = ceil(HP12);
                M1 -= 70;
                spent += 70;
                
            }
            // Check if spent exceeds M and break out of the loop if true
            if (spent > M) {
                break;
            }
            
            //////////////////////////// 2nd event
            if (EXP1 < 400){
                  condition2(HP1, EXP1, E2, M1);
                M1 -= 200;
                EXP12 = EXP1 * 1.13;
                EXP1 = ceil(EXP12);
                spent += 200;
            }
            else {
                  condition2(HP1, EXP1, E2, M1);
                M1 -= 120;
                EXP12 = EXP1 * 1.13;
                EXP1 = ceil(EXP12);
                spent += 120;
            }
            // Check if spent exceeds M and break out of the loop if true
            if (spent > M) {
                break;
            }
            ///////////////////////////// 3rd event
            if (EXP1 < 300){
                  condition2(HP1, EXP1, E2, M1);
                M1 -= 100;
                spent += 100;
            }
            else {
                  condition2(HP1, EXP1, E2, M1);
                M1 -= 120;
                spent += 120;
            }
            
            EXP12 = EXP1 * 0.9;
            EXP1 = ceil(EXP12);
            
            
            // Check if spent exceeds M and break out of the loop if true
            if (spent > M) {
                break;
            }
            
            
        }
        while (spent <= M);
        
        //after spent > M
        EXP12 = EXP1 * 1.17;
        HP12 = HP1 * 0.83;
        HP1 = ceil(HP12);
        EXP1 = ceil(EXP12);

    }
//‧₊˚✩ ₊˚⊹♡𝄞✮⋆˙.𖥔 ݁ ˖ᡣ𐭩‧₊˚✩ ₊˚⊹♡𝄞✮⋆˙.𖥔 ݁ ˖ᡣ𐭩
     //E2 is even
    else {
        int spent = 0;
        double HP12;
        double EXP12;
        // one round of events
        ///////////////////////////// 1st event
        if (HP1 < 200)
        {
            HP12 = HP1 * 1.3;
            spent += 150;
            HP1 = ceil(HP12);
            M1 -= 150;
        }
        else
        {
            HP12 = HP1 * 1.1;
            spent += 70;
            HP1 = ceil(HP12);
            M1 -= 70;
            
        }
        //////////////////////////// 2nd event
        if (EXP1 < 400)
        {
            spent += 200;
            EXP12 = EXP1 * 1.13;
            EXP1 = ceil(EXP12);
            M1 -= 200;
        }
        else
        {
            spent += 120;
            EXP12 = EXP1 * 1.13;
            EXP1 = ceil(EXP12);
            M1 -= 120;
        }
        
        ///////////////////////////// 3rd event
        if (EXP1 < 300)
        {
            spent += 100;
            M1 -= 100;
        }
        
        else
        {
            spent += 120;
            M1 -= 120;
        }
        EXP12 = EXP1 * 0.9;
        EXP1 = ceil(EXP12);
        //M1 is not enough
        while (M1 <= 0)
        {
            M1 = 0;
            break;
        }
        
        //after spent > M
        EXP12 = EXP1 * 1.17;
        HP12 = HP1 * 0.83;
        HP1 = ceil(HP12);
        EXP1 = ceil(EXP12);
        
    }
    //find P2
    double P2;
    if (EXP1 >= S) {
        P2 = 100.0;
    }
    else {
        P2 = ((EXP1 / S + 80) / 123) * 100;
    }
    
    //ROAD 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if(E2 < 10)
    {
        i = E2;
    }
    else
    {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    }
    
    //find P3
    double P3;
    P3 = P[i];

    //find P average
    double P_avg;
    P_avg = (P1 + P2 + P3) / 3;

    
    if ( P_avg == 100 )
    {
        EXP1 = EXP1 * 1.75;
    }
    else if(P_avg < 50)
    {
        HP1 = HP1 * 0.85;
        EXP1 = EXP1 * 1.15;
    }
    else
    {
        double HP12;
        double EXP12;
        HP12 = HP1 * 0.9;
        HP1 = ceil(HP12);
        EXP12 = EXP1 * 1.2;
        EXP1 = ceil(EXP12);
    }
    P_avg = ceil(P_avg);
    condition2(HP1, EXP1, E2, M1);
    return HP1 + EXP1 + M1;
    }
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //taxi score
    const int rows = 10;
    const int cols = 10;
    int taxi[rows][cols] = {0};
    int i = 0, j = 0 ;
    
    
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    
    //meeting point
    int right = 0;
    int down = 0;
    
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (taxi[i][j] > (E3 * 2))
            {
                right++;
            }
            else if (taxi[i][j] < (-E3))
            {
                down++;
            }
        }
    }
    while (right >= 10)
    {
        right = (right % 10) + (right / 10);
    }
    while (down >= 10)
    {
        down = (down % 10) + (down / 10);
    }
    
    //we have to meet somewhere
    int where_we_met = taxi[right][down];
    
    //Sherlock and Watson score
    int a, b;
    int largest = taxi[right][down];
    int left, gone;
    
    for (int a = 0; a < 10; ++a)
    {
        for (int b = 0; b < 10; ++b)
        {
            for (int k = 1; k < 10; k++)
            {
                if (right - a == k && down - b == k)
                {
                    left = taxi[a][b];
                    if (largest < left)
                    {
                        largest = left;
                    }
                }
                if (right + k == a && down + k == b)
                {
                    left = taxi[a][b];
                    if (largest < left)
                    {
                        largest = left;
                    }
                }
                if (right - k == a && down + k == b)
                {
                    gone = taxi[a][b];
                    if (largest < gone)
                    {
                        largest = gone;
                    }
                }
                if (right + k == a && down - k == b)
                {
                    gone = taxi[a][b];
                    if (largest < gone)
                    {
                        largest = gone;
                    }
                }
            }
        }
    }
    
    //find largest
    
    //chasing
    int where_we_meet_again = abs(where_we_met);
    int i_love_u;
    if( where_we_meet_again <= largest) //they got 'em
    {
        EXP1 = EXP1 * 1.12;
        EXP2 = EXP2 * 1.12;
        HP1 = HP1 * 1.1;
        HP2 = HP2 * 1.1;
        i_love_u = largest;
    }
    else //they missed 'em
    {
        EXP1 = EXP1 * 0.88;
        EXP2 = EXP2 * 0.88;
        HP1 = HP1 * 0.9;
        HP2 = HP2 * 0.9;
        i_love_u = where_we_met;
    }
    
    //CONDITIONS
    //EXP1
    if (EXP1 > 600)
    {EXP1 = 600;}
    else if (EXP1 < 0)
    {EXP1 = 0;}
    //HP1
    if (HP1 > 666)
    {HP1 = 666;}
    else if (HP1 < 0)
    {HP1 = 0;}
    //EXP2
    if (EXP2 > 600)
    {EXP2 = 600;}
    else if (EXP2 < 0)
    {EXP2 = 0;}
    //HP2
    if (HP2 > 666)
    {HP2 = 666;}
    else if (HP2 < 0)
    {HP2 = 0;}
    //E3
    int E3_range (E3);
    {
        while (E3 < 0 || E3 > 99)
        {
            return -99;
            break;
        }
    }
      return i_love_u;
         }
//.・。.・゜✭・.・✫・゜・。.

      
    // Task 4
 
    int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
        char box[strlen(email) + 1];
        //put email into the box
        strcpy(box, email);

        //find length
        //passlength < 8
        int passlong = strlen(s);
        if (passlong < 8)
            {
            return -1;
            }
        //passlength > 20
        if (passlong > 20)
            {
            return -2;
            }

        //Check se
        char* se;
        se = strtok(box, "@"); //take-out
        const char* where = strstr(s, se);
        if (where)
            {
            int sei = where - s;
            return -(300 + sei);
            }

        //Find special characters
        const char* gilberrish = "@#%$!";
        const char* specialty = strpbrk(s, gilberrish);
        if (specialty == nullptr)
            {
            return -5;
            }

        //Find the same character
        for (int sci = 0; sci < passlong - 2; ++sci)
            {
            if (s[sci] == s[sci + 1] && s[sci] == s[sci + 2])
            {
                return -(400 + sci);
            }
        }
        //Password that passes
        return -10;
    }


    // Task 5
    int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxl = 0;
    int maxa = 0;
    int pass = -1;
    int times_appear;
                
    //times that a password appear
    for (int i = 0; i < num_pwds; i++)
    {
    times_appear = 0;
    for (int j = 0; j < num_pwds; j++)
    {
    if (arr_pwds[i] == arr_pwds[j])
        {
        times_appear++;
        }
    }
    //find first place
    int length = strlen(arr_pwds[i]);
    if (times_appear > maxa || (times_appear == maxa && length > maxl))
        {
        maxa = times_appear;
        maxl = length;
        pass = i;
        }
    }
    return pass;
    }



        
      
         ////////////////////////////////////////////////
         /// END OF STUDENT'S ANSWER
         ////////////////////////////////////////////////
        
