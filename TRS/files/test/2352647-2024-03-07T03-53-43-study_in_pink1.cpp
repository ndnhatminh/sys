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

// Task 1
void checkmain_task1(int & exp1, int & exp2, int e1)
{
    if (e1 > 99) {
        e1 = 99;
    } else if (e1 < 0) {
        e1 = 0;
    }
    if (exp1 > 600) {
        exp1 = 600;
    } else if (exp1 < 0) {
        exp1 = 0;
    }
    if (exp2 > 600) {
        exp2 = 600;
    } else if (exp2 < 0) {
        exp2 = 0;
    }
    
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    
    if (e1 >= 0 && e1 <= 99)
    {
        checkmain_task1(exp1,exp2,e1);
        //case 1
        if (e1 <= 3)
        {
            switch (e1)
            {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += 149;
                break;
            default:
                break;
            }

            int D = e1*3 + exp1*7;
            if (D % 2 == 0) 
            {
                exp1 = ceil(double(exp1) + double(D)/200);
                checkmain_task1(exp1,exp2,e1);
            }
            else exp1 = ceil(double(exp1) - double(D)/100);
            checkmain_task1(exp1,exp2,e1);
        }

        // case 2
        if(e1 >=4 && e1 <=99)
        {
        if (e1 >= 4 && e1 <= 19) 
        {
            exp2 = ceil(exp2 + (double(e1)/4) + 19);
            checkmain_task1(exp1,exp2,e1);
        }
        else if (e1 >=20 && e1 <= 49) 
        {
            exp2 = ceil(exp2 + (double(e1)/9) + 21);
            checkmain_task1(exp1,exp2,e1);
        }
        else if (e1 >= 50 && e1 <= 65) 
        {
            exp2 = ceil(exp2 + (double(e1)/16) + 17);
            checkmain_task1(exp1,exp2,e1);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (double(e1)/4) + 19);
            checkmain_task1(exp1,exp2,e1);
            if (exp2 >200) 
            {
                exp2 = ceil(exp2 + (double(e1)/9) + 21);
                checkmain_task1(exp1,exp2,e1);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
           exp2 = ceil(exp2 + (double(e1)/4) + 19);
           checkmain_task1(exp1,exp2,e1);
            exp2 = ceil(exp2 + (double(e1)/9) + 21);
            checkmain_task1(exp1,exp2,e1);
            if (exp2 > 400) 
            {
               exp2 = ceil(exp2 + (double(e1)/16) + 17);
               checkmain_task1(exp1,exp2,e1);
                exp2 = ceil((exp2) + exp2*0.15);
                checkmain_task1(exp1,exp2,e1);
            }
        }
        exp1 -= e1;
        checkmain_task1(exp1,exp2,e1);
        }
        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
void checkmain_task2(int & HP1, int & EXP1, int & M1, int E2)
{
    if (HP1 > 666) {
        HP1 = 666;
    } else if (HP1 < 0) {
        HP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    } else if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (M1 > 3000) {
        M1 = 3000;
    } else if (M1 < 0) {
        M1 = 0;
    } 
}

void event1(int & HP1, int & EXP1, int & M1, int E2) {
    if (HP1 < 200) {
        HP1 = ceil(HP1 + (HP1)*0.3);
        M1 -= 150;
        checkmain_task2(HP1, EXP1, M1, E2);
    } else {
        HP1 = ceil(HP1 + (HP1)*0.1);
        M1 -= 70;
        checkmain_task2(HP1, EXP1, M1, E2);
    }
}
void event2(int & HP1, int & EXP1, int & M1, int E2) {
     if (EXP1 < 400) {
        M1 -= 200;         
    } else {
        M1 -= 120; 
    }
    EXP1 = ceil(EXP1 + (EXP1)*0.13);
    checkmain_task2(HP1, EXP1, M1, E2); 
}
void event3(int & HP1, int & EXP1, int & M1, int E2) {
    if (EXP1 < 300) {
        M1 -= 100;
        checkmain_task2(HP1, EXP1, M1, E2);
    } else {
        M1 -= 120;
        checkmain_task2(HP1, EXP1, M1, E2);
    }
    EXP1 = ceil(EXP1 - (EXP1)*0.1); 
    checkmain_task2(HP1, EXP1, M1, E2);
   
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if (E2 >=0 && E2 <=99)
    {
        checkmain_task2(HP1, EXP1, M1, E2);
        //road 1
        //finding nearest square num to exp1
        int squareRoot = static_cast<int>(round(sqrt(EXP1)));
        int S = squareRoot * squareRoot;

        double P1;
        if (EXP1 >= S) P1 = 1.0;
        else P1 = ((double(EXP1) / double(S)) +80)/123;

        //road 2
        int M1_init = M1;
        if (M1!= 0)
        {
        if (E2 % 2 != 0)
        {
            while (1)
            {
                event1(HP1, EXP1, M1, E2);
                if (M1_init - M1 > M1_init*0.5) break;
                event2(HP1, EXP1, M1, E2);
                if (M1_init - M1 > M1_init*0.5) break;
                event3(HP1, EXP1, M1, E2);
                if (M1_init - M1 > M1_init*0.5) break;
            }   
        }
        else 
        {
            for (int i = 0; i < 1 ; i++)
            {
                event1(HP1, EXP1, M1, E2);
                if (M1 <=0 ) break;
                event2(HP1, EXP1, M1, E2);
                if (M1 <=0 ) break;
                event3(HP1, EXP1, M1, E2);
                if (M1 <=0 ) break;
            }   
        }
        }
        
        HP1 = ceil(HP1 - (HP1)*0.17); 
        EXP1 = ceil(EXP1 + (EXP1)*0.17);
        checkmain_task2(HP1, EXP1, M1, E2);

        int squareRoot2 = static_cast<int>(round(sqrt(EXP1)));
        int S2 = squareRoot2 * squareRoot2;

        double P2;
        if (EXP1 >= S2) P2 = 1.0;
        else P2 = ((double(EXP1) / double(S2)) +80)/123;
    
        //road 3
        int arr[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        double P3;
        if (E2 < 10) P3 = double(arr[E2])/100;
        else 
        {
            int a = E2 / 10, b= E2 % 10;
            int S = a+b;

            P3 = double(arr[S % 10])/100;
        }
        //final dealing
        if (P1 + P2 + P3 == 3.0) 
        {
            EXP1 = ceil(EXP1 - (EXP1)*0.25);
            checkmain_task2(HP1, EXP1, M1, E2);
        }
        else
        {
            double avg = (P1 + P2 + P3)/ 3;
            
            if (avg < 0.5)
            {
                HP1 = ceil(HP1 - (HP1)*0.15);
                EXP1 = ceil(EXP1 + (EXP1)*0.15);
                checkmain_task2(HP1, EXP1, M1, E2);
            }
            else
            {
                HP1 = ceil(HP1 - (HP1)*0.1);
                EXP1 = ceil(EXP1 + (EXP1)*0.2);
                checkmain_task2(HP1, EXP1, M1, E2);
            }
        }
        
        checkmain_task2(HP1, EXP1, M1, E2);

        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
void checkmain_task3(int & HP1, int & EXP1, int & HP2, int & EXP2)
{
    if (HP1 > 666) {
        HP1 = 666;
    } else if (HP1 < 0) {
        HP1 = 0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    } else if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (HP2 > 666) {
        HP2 = 666;
    } else if (HP2 < 0) {
        HP2 = 0;
    }
    if (EXP2 > 600) {
        EXP2 = 600;
    } else if (EXP2 < 0) {
        EXP2 = 0;
    }
}
void upleft(int & i_temp, int & j_temp)
{
    i_temp -= 1;
    j_temp -= 1;
}
void downleft(int & i_temp, int & j_temp)
{
    i_temp += 1;
    j_temp -= 1;
}
void upright(int & i_temp, int & j_temp)
{
    i_temp -= 1;
    j_temp += 1;
}
void downright(int & i_temp, int & j_temp)
{
    i_temp += 1;
    j_temp += 1;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
   
    if (E3 >=0 && E3 <= 99)
    {//creating matrix
     checkmain_task3(HP1, EXP1, HP2, EXP2);
        int path_taxi[10][10];
        for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) path_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);

        int i_loc= 0, j_loc = 0;
        int sher_score = path_taxi[0][0];

        for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
            if (path_taxi[i][j] > E3 *2) i_loc++;
            if (path_taxi[i][j] < -E3) j_loc++;
        }
        
        while (i_loc >= 10) 
            i_loc = (i_loc / 10) + (i_loc % 10);
        while (j_loc >= 10) 
            j_loc = (j_loc / 10) + (j_loc % 10);
        
        int ta_score = path_taxi[i_loc][j_loc];

        // Calculate Sherlock's score 
        int i_temp = i_loc, j_temp = j_loc;
        
        // Down Left
        while (i_temp < 9 && j_temp > 0) {
            downleft(i_temp, j_temp);
            if (path_taxi[i_temp][j_temp] > sher_score) 
                sher_score = path_taxi[i_temp][j_temp];
        }

        // Down Right
        i_temp = i_loc;
        j_temp = j_loc;
        while (i_temp < 9 && j_temp < 9) {
            downright(i_temp, j_temp);
            if (path_taxi[i_temp][j_temp] > sher_score) 
                sher_score = path_taxi[i_temp][j_temp];
        }

        // Up Left
        i_temp = i_loc;
        j_temp = j_loc;
        while (i_temp > 0 && j_temp > 0) {
            upleft(i_temp, j_temp);
            if (path_taxi[i_temp][j_temp] > sher_score) 
                sher_score = path_taxi[i_temp][j_temp];
        }

        // Up Right
        i_temp = i_loc;
        j_temp = j_loc;
        while (i_temp > 0 && j_temp < 9) {
            upright(i_temp, j_temp);
            if (path_taxi[i_temp][j_temp] > sher_score) 
                sher_score = path_taxi[i_temp][j_temp];
        }

        if (sher_score <= path_taxi[i_loc][j_loc]) sher_score = path_taxi[i_loc][j_loc];

            
        if (sher_score >= abs(ta_score)) 
        {
            EXP1 = ceil(EXP1 + EXP1*0.12);
            EXP2 = ceil((EXP2) + EXP2*0.12);
            HP1 = ceil((HP1) + HP1* 0.1);
            HP2 = ceil((HP2)+ HP2*0.1);
            checkmain_task3(HP1, EXP1, HP2, EXP2);
            return sher_score;
        }
        else
        {
            EXP1 = ceil(EXP1 - EXP1*0.12);
            EXP2 = ceil((EXP2) - EXP2*0.12);
            HP1 = ceil((HP1) - HP1* 0.1);
            HP2 = ceil((HP2) - HP2*0.1); 
            checkmain_task3(HP1, EXP1, HP2, EXP2); 
            return ta_score;
        }
    }
    else return -99;
}

// Task 4
bool checkSpec(char c) {
    if(c == '@' || c == '#' || c == '%' || c == '$' || c == '!') return true;
    else return false;
}

int checkPassword(const char * s, const char * email) {

    //check lenght
    
    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }
    
    //forming se & check the index
    string se;
    for (int i = 0; i < strlen(email); i++) 
    {
        if (email[i]!= '@') se += email[i];
        else break;
    }
    if (se == "") return -300;
    const char * se_re = se.c_str();
    const char * find = strstr(s, se_re);
    
    int sei;
    if (find != nullptr) 
    {
        sei = find - s; 
    }

    //check se in s
    if (find != nullptr) {
        return -(300 + sei);
    }

    //check all other stuffs
    char initchar = '\0';
    int count = 1;
    int count_spec = 0;
    unsigned long len = strlen(s);
   for (unsigned long i = 0; i < len; ++i) {
        char currentchar = s[i];
        if (currentchar == initchar) {
            count++;
            if (count > 2) {
                return -(400 + i - 2);
            }
        } else {
            count = 1;
        }
        
        initchar = currentchar;
    }
    bool checkminspec = false;
    for (int j = 0; j < strlen(s); ++j) 
    {
        
        if (checkSpec(s[j]) == true)
        {
            checkminspec = true;
        }
    }
    if (!checkminspec) return -5;

    for (int j = 0; j < strlen(s); ++j) {
         if (checkSpec(s[j]) == true && isalnum(s[j]) == false) continue;
            else if (checkSpec(s[j]) == false && isalnum(s[j]) == false) return j;
    }
    //correct return
    return -10;
    
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    int count[num_pwds];
    memset(count, 0, num_pwds);
    for (int i = 0; i < (num_pwds); i++) 
    {
        if (count[i] == -100) continue;
        count[i] = 1;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
            count[i]++;
            count[j] = -100; //avoiding duplicate counting;
            }
        }
    }

    //find max
    int max_ele = count[0];
    for (int i = 0; i < num_pwds - 1; i++) 
    {
        if (max_ele < count[i + 1]) max_ele = count[i + 1];
    }
    
    //check the same max
    int count_max = 0;
    int index_of_max[num_pwds]; 
    
    for (int i = 0; i < num_pwds; i++) 
    {
        if (count[i] == max_ele) 
        {
            index_of_max[count_max++] = i;
        }
    }

    string max_len_pass = arr_pwds[index_of_max[0]];
    for (int i = 1; i < count_max; i++) {
        if (max_len_pass.length() < strlen(arr_pwds[index_of_max[i]])) {
            max_len_pass = arr_pwds[index_of_max[i]];
        }
    }
    for (int i = 0; i < count_max; i++) {
        if (max_len_pass == arr_pwds[index_of_max[i]]) {
            return index_of_max[i]; 
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////