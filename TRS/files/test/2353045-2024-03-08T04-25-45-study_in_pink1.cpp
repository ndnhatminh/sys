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
// Case 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if((e1<0)||(e1>99))
    {
        return -99;
    }
    bool case1;
    if (exp1 >= 600) {
        exp1 = 600;
    }
    else if (exp1 <= 0) {
        exp1 = 0;
    }
    if (exp2 >= 600) {
        exp2 = 600;
    }
    else if (exp2 <= 0) {
        exp2 = 0;
    }
    while (true) {

        

        if (e1 >= 0 && e1 <= 3) 
        {
            if (e1 == 0) {
                exp2 += 29;
                
            }
            else if (e1 == 1) {
                exp2 += 45;
                
            }
            else if (e1 == 2) {
                exp2 += 75;
                
            }
            else if (e1 == 3) {
                exp2 += (75 + 45 + 29);
            
            }
            float D = e1 * 3 + exp1 * 7;
            if ((int(D) % 2) == 0) 
            {
                exp1= exp1 + ceil((float(D) / 200)-0.0000000001);
            }
            else if ((int(D) % 2) == 1) 
            {
                exp1= exp1- ceil((float(D) / 100)-00000000001);
            }      
            break;
        }
        else if ((e1>=4)&&(e1<=99))
        {
            if ((e1>=4)&&(e1<=19))
            {
                exp2=ceil(exp2+(float)(e1)/4 + 19);
            }
            else if ((e1>=20)&&(e1<=49))
            {
                exp2=ceil(exp2+(float)(e1)/9 + 21);

            }
            else if ((e1>=50)&&(e1<=65))
            {
                exp2=ceil(exp2+(float)(e1)/16 + 17);

            }
            else if ((e1>=66)&&(e1<=79))
            {
                exp2=ceil(exp2+ceil((float)(e1)/4 + 19));
                if (exp2>200){
                exp2=ceil(exp2+ceil((float)(e1)/9 + 21));
                }

            }
            else if ((e1>=80)&&(e1<=99))
            {
                exp2=ceil(exp2+(float(e1)/4 + 19));
             
                exp2=ceil(exp2+(float(e1)/9 + 21));
                exp2=ceil(exp2);
                if(exp2>400){
                    exp2=ceil(exp2+((float(e1)/16) + 17));
                    
                    exp2=exp2+ceil(float(exp2)/100*15);
                    
               
                }

            

            }
        exp1=exp1-e1;
        break;
            
        }
    }
    
    if (exp1 >= 600) {
    exp1 = 600;
    }
    else if (exp1 <= 0) {
        exp1 = 0;
    }
    if (exp2 >= 600) {
        exp2 = 600;
    }
    else if (exp2 <= 0) {
        exp2 = 0;
    }

    
    



    
    return exp1 + exp2;
}

// con duong 1
bool isPerfectSquare(int num)
{
    int sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}

int nearestPerfectSquare(int a)
{
    int low = a;
    int up = a;
    while (!isPerfectSquare(up))
        ++up;
    while (!isPerfectSquare(low))
        --low;
    if ((a - low) <= (up - a))
        return low;
    else
        return up;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;

    // stage 1
    double s = nearestPerfectSquare(EXP1);
    double p1;
    if (s > EXP1)
        p1 = (EXP1/s + 80)/ 123;
    else
        p1 = 1;
        
    // con duong 2
    int target = M1/2;
    int m2 = 0;
    if (E2 % 2 != 0) {
        while (true) {
            if (M1 == 0) break;
            {
            if (HP1 < 200) {
                HP1 = ceil(float(1.3 * HP1));
                M1 -= 150;
                m2 += 150;
            } 
            else {
                HP1 = ceil(float(1.1 * HP1));
                M1 -= 70;
                m2 += 70;
            }
        }

            if (EXP1 > 600) EXP1 = 600;
            if (HP1 > 666) HP1 = 666;
            if (m2 > target) break;

            {
            if (EXP1 < 400) {
                M1 -= 200;
                m2 += 200;
            }
            else {
                M1 -= 120;
                m2 += 120;
            }
            EXP1 = ceil(float(1.13 * EXP1));
}
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 > 666) HP1 = 666;
            if (m2 > target) break;

                    {
            if (EXP1 < 300) {
                M1 -= 100;
                m2 += 100;
            }
            else {
                M1 -= 120;
                m2 += 120;
            }
    EXP1 = ceil(float(0.9 * EXP1));
}
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 > 666) HP1 = 666;
            if (m2 > target) break;
        }
    }
    else {
        while (true) {
            if (M1 == 0) break;
            {
            if (HP1 < 200) {
                HP1 = ceil(float(1.3 * HP1));
                M1 -= 150;
                m2 += 150;
            } 
            else {
                HP1 = ceil(float(1.1 * HP1));
                M1 -= 70;
                m2 += 70;
            }
}

            if (EXP1 > 600) EXP1 = 600;
            if (HP1 > 666) HP1 = 666;
            if (M1 <= 0) break;

            {
            if (EXP1 < 400) {
                M1 -= 200;
                m2 += 200;
            }
            else {
                M1 -= 120;
                m2 += 120;
            }
            EXP1 = ceil(float(1.13 * EXP1));
            }
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 > 666) HP1 = 666;
            if (M1 <= 0) break;

            {
            if (EXP1 < 300) {
                M1 -= 100;
                m2 += 100;
            }
            else {
                M1 -= 120;
                m2 += 120;
            }
            EXP1 = ceil(float(0.9 * EXP1));
            }
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 > 666) HP1 = 666;
            break;
        }
    }
    if (M1 < 0) M1 = 0;
    HP1 = ceil(float(0.83 * HP1));
    EXP1 = ceil(float(1.17 * EXP1));
    if (EXP1 > 600) EXP1 = 600;
    if (HP1 > 666) HP1 = 666;

    s = nearestPerfectSquare(EXP1);
    double p2;
    if (s > EXP1)
        p2 = (EXP1/s + 80)/ 123;
    else
        p2 = 1;
    
    // con duong 3
    double P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10)
        i = E2;
    else
        i = (E2%10 + E2/10)%10;
    double p3 = P[i]/100;
    if (p1 == 1 && p2 == 1 && p3 == 1) 
        EXP1 = ceil(float(0.75 * EXP1));
    else {
        double avg = (p1 + p2 + p3)/3;
        if (avg < 0.5) {
            HP1 = ceil(float(0.85 * HP1));
            EXP1 = ceil(float(1.15 * EXP1));
        }
        else {
            HP1 = ceil(float(0.90 * HP1));
            EXP1 = ceil(float(1.2 * EXP1));
        }
    }
    if (EXP1 > 600) EXP1 = 600;
    if (HP1 > 666) HP1 = 666;

    return HP1 + EXP1 + M1;
}
// Task 3
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    if (E3<0 || E3>99) return -99;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    int a[10][10] = {};
    int row=0, column=0;
    // Taxi Point
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            a[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    // Meet Location
    for (int i = 0; i< 10; i++) {
        for (int j=0; j<10; j++) {
            if (a[i][j] > E3*2) {
                row++;
            }
            if (a[i][j] < (-E3)) {
                column++;
            }
        }
    }
    while (row>9) {
        row = row/10 + row%10;
    }
    while (column>9) {
        column = column/10 + column%10;
    }
    // Sherlock and Watson Point
    int max=0;
    int i=row, m=row, j=column, n=column;
    while (i>=0 && j>=0) {
        if (a[i][j]>max) {
            max = a[i][j];
        }
        i--;
        j--;
    }
    i = row + 1, j = column + 1;
    while (i<10 && j<10) {
        if (a[i][j]>max) {
            max = a[i][j];
        }
        i++;
        j++;
    }
    while (m<10 && n>=0) {
        if (a[m][n]>max) {
            max = a[m][n];
        }
        m++;
        n--;
    }
    m = row - 1, n = column + 1;
    while (m>=0 && n<10) {
        if (a[m][n]>max) {
            max = a[m][n];
        }
        m--;
        n++;
    }
    // Final
    if (abs(max)>=abs(a[row][column])) 
    {
        EXP1 = ceil((EXP1*1.12)-0.00000000001);
        EXP2 = ceil((EXP2*1.12)-0.00000000001);
        HP1 = ceil((HP1*1.1)-0.00000000001);
        HP2 = ceil((HP2*1.1)-0.00000000001);
    if (E3<0 || E3>99) return -99;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
        return max;
    } 
    else 
    {
        EXP1 = ceil((EXP1*0.88)-0.00000000001);
        EXP2 = ceil((EXP2*0.88)-0.00000000001);
        HP1 = ceil((HP1*0.9)-0.00000000001);
        HP2 = ceil((HP2*0.9)-0.00000000001);
        if (E3<0 || E3>99) return -99;
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        if (HP2 > 666) HP2 = 666;
        if (HP2 < 0) HP2 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
        if (EXP2 < 0) EXP2 = 0;
        return a[row][column];
    }
    return -1;
    }

// Task 4

   int checkPassword(const char* s, const char* email)
{
    string se(email, strchr(email, '@') - email);
    bool Available;
    Available=true;
    string password(s);
    int count=0;
    int a =0;
    
        if (strlen(s) < 8)
            return -1;
        if (strlen(s) > 20)
            return -2;
           

            
        if (password.find(se) != string::npos){
        return -(300 + password.find(se));
        }

        for (int i = 0; i < strlen(s) - 2; i++)
        {
            if ((s[i] == s[i + 1]) && s[i] == s[i + 2])
            {
                return -(400 + i);
             
               
            }
        }
        for (int i = 0; i < strlen(s); i++)
        {
            if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return i;
            }
        }
           
        
                string specialChars = "@#%$!";   
                for (int i = 0; i < strlen(s); i++)
                    for(int j=0;j<specialChars.length();j++)
                    {
                        if (password[i] == specialChars[j])
                        {
                            count+=1;
                        }

                    }
                    if(count==0) 
                    {
                        return -5;
                    }                    
    
            

        
                
    
        return -10;
}

        


// Task 5

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int pos_ans = 0;
    int count_ans = 0;
    for (int i = 0; i < num_pwds; ++i) {
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i],arr_pwds[j]) == 0) {
                count += 1;
                if (count > count_ans || (count == count_ans && strlen(arr_pwds[i]) > strlen(arr_pwds[pos_ans]))) {
                    pos_ans = i;
                    count_ans = count;
                }
            }
        }
    }
    return pos_ans;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////