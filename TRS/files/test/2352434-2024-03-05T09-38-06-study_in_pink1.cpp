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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if (E1 < 0 || E1 > 99) return -99;
    if (EXP1 <0) EXP1=0;
    if (EXP1 >600) EXP1=600;
    if (EXP2 <0) EXP2=0;
    if (EXP2 >600) EXP2=600;

    if ( E1 >= 0 && E1 <= 3) {
    switch(E1) {
        case 0:
            EXP2 += 29;
            break;
        case 1: 
            EXP2 += 45;
            break;
        case 2: 
            EXP2 += 75;
            break;  
        case 3: 
            EXP2 += 29 + 45 + 75;
            break;
    }
    
    int D = E1 * 3 + EXP1 * 7;

    if (D % 2 == 0) {
        EXP1 += ceil(D / 200.0 );
    }
    else { EXP1 -= ceil( D / 100);
    }
}
    else if ( E1 >=4 && E1 <= 19 ) {
        EXP2 += ceil(E1 / 4.0 + 19); 
    }
    else if (E1 >= 20 && E1 <= 49 ){
        EXP2 += ceil(E1 / 9.0 + 21);
    }
    else if ( E1 >= 50 && E1 <= 65) {
        EXP2 += ceil( E1 / 16.0 +17);
    }
    else if ( E1 >= 66 && E1 <= 79 )
    { 
        EXP2 += ceil(E1 / 4.0 + 19);
            if (EXP2 > 200) {
                EXP2 += ceil(E1 / 9.0 + 21); 
            } 
    }
    else if ( E1 >= 80 && E1 <= 99 )
    { 
        EXP2 += ceil(E1 / 4.0 + 19);
        EXP2 += ceil(E1 / 9.0 + 21); 
            if ( EXP2 > 400 ) {
                 EXP2 += ceil( E1 / 16.0 +17);
                 EXP2 = ceil( EXP2 * 1.15);
            }
    }

    if (E1 >= 4 && E1 <= 99)
    { EXP1 -= E1; } 
    
    EXP1 = max(0, min(EXP1, 600));
    EXP2 = max(0, min(EXP2, 600));

    return EXP1 + EXP2;

}

// Task 2


void checkStatusTask2(int&HP1, int&M1, int&EXP1){
    if (HP1 <0) HP1=0;
    if (HP1 >666) HP1=666;
    if (EXP1 <0) EXP1=0;
    if (EXP1 >600) EXP1=600;
    if (M1>3000) M1=3000;
    if (M1<0) M1=0;



}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0 ||E2>99) return -99;
    if (EXP1 <0) EXP1=0;
    if (EXP1 >600) EXP1=600;
    if (HP1 <0) HP1=0;
    if (HP1 >666) HP1=666;
    //Road 1
    int x = round(sqrt(EXP1));
    int S= x * x;
    double P1;
    if (EXP1 >= S) P1 = 1.0;
    else P1 = double(( EXP1 /S  + 80.0 )/ 123.0);
    //Road 2
    
    double Standard= M1*0.5; 
    checkStatusTask2(HP1,M1,EXP1);
    if (E2 % 2 != 0) {
        int moneySpent = 0;
        while (true){
            if (HP1 < 200) {
                HP1 = ceil(double( HP1 ) + 0.3*double(HP1));
                M1 -= 150;
                moneySpent += 150;
                checkStatusTask2(HP1, M1, EXP1);
                if (moneySpent > Standard) break;
        }
            else {
                HP1 = ceil(double(HP1) + 0.1*double(HP1));  
                M1 -= 70;
                moneySpent += 70;
                checkStatusTask2(HP1,M1,EXP1);
                if (moneySpent>Standard) break;
        }
            if (EXP1<400)  {
                M1 -= 200;
                moneySpent += 200;
                checkStatusTask2(HP1,M1,EXP1);
                EXP1 = ceil(double(EXP1*1.13));
                if (moneySpent > Standard) break;
            }
            else {
                M1 -= 120;
                moneySpent +=120;
                checkStatusTask2(HP1,M1,EXP1);
                EXP1 = ceil(double(EXP1*1.13));
                if (moneySpent > Standard) break;
            }
            
            if (EXP1 < 300) {
                M1 -= 100;
                moneySpent += 100;
                checkStatusTask2(HP1,M1,EXP1);
                EXP1 = ceil(double(EXP1*0.9));
                if (moneySpent > Standard) break;
            }
            else {
                M1 -= 120;
                moneySpent += 120;
                checkStatusTask2(HP1,M1,EXP1);
                EXP1 = ceil(double(EXP1*0.9));
                if (moneySpent > Standard) break;
            }            
            }
        HP1 = ceil(double(HP1*0.83));
        EXP1 = ceil (double(EXP1*1.17));
        checkStatusTask2(HP1,M1,EXP1);
    }    
      if (E2 % 2 == 0) {  
        while(true){
        if (HP1<200) {
                HP1 = ceil(double(HP1)+ 0.3*double(HP1));
                M1 -= 150; 
        }
        else {
                HP1 = ceil(double(HP1)+ 0.1*double(HP1));  
                M1 -= 70;  
        }
        checkStatusTask2(HP1,M1,EXP1);
        if (M1 == 0) break;
        if (EXP1 < 400)  {
                M1 -= 200;
                EXP1 = ceil(double(EXP1*1.13));
            }
        else {
                M1 -= 120;
                EXP1 = ceil(double(EXP1*1.13));
            }  
        checkStatusTask2(HP1,M1,EXP1);
        if (M1 == 0) break;
        if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = ceil(double(EXP1*0.9));
            }
        else {
                M1 -= 120;
                EXP1 = ceil(double(EXP1*0.9));
            }   
        checkStatusTask2(HP1,M1,EXP1);
        if (M1 ==0 ) break;
        break;
        }
    HP1 = ceil(double(HP1 * 0.83));
    EXP1 = ceil (double(EXP1 * 1.17));
    }
    checkStatusTask2(HP1,M1,EXP1);
    int y = round(sqrt(EXP1));
    int S2 = y * y;
    double P2;
    if (EXP1 >= S2) P2=1.0;
    else P2= double(( EXP1 / S2 + 80.0 ) / 123.0);
    //Road 3
    double i;
    double arrP[10]={0.32,0.47,0.28,0.79,1.0,0.5,0.22,0.83,0.64,0.11};
    if (E2 >= 0 && E2 < 10) i=arrP[E2];
    if (E2 >= 11 && E2 <= 99) {
        E2 = (E2 % 10 + E2 / 10);
        E2 = E2 % 10;
        i = arrP[E2];
    }
    if (P1 == 1.0 && P2 == 1.0 && i == 1.0) {
        EXP1 = ceil(double (EXP1*0.75));
        checkStatusTask2(HP1,M1,EXP1);
    }
    else {
        double ave = ( P1 + P2 + i) / 3;
        if (ave < 0.5) {
            HP1=ceil(double(HP1 * 0.85));
            EXP1=ceil(double(EXP1 * 1.15));
            checkStatusTask2(HP1,M1,EXP1);
        }
        else {
            HP1=ceil(double(HP1 * 0.9));
            EXP1=ceil(double(EXP1 * 1.2));
            checkStatusTask2(HP1,M1,EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
void checkStatusTask3(int& HP1, int& EXP1, int& HP2, int& EXP2)
{
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (HP2 < 0) HP2 = 0;  
    if (HP2 > 666) HP2 = 666;
    if (EXP2 < 0) EXP2 = 0;  
    if (EXP2 > 600) EXP2 = 600;
}

int SumOf2digits(int num) {
    while (num >= 10) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}


int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3<0 ||E3>99) return -99;
    
    
    
    int taxiMatrix [10][10] = {0};
    int SherWatMatrix [10][10] = {0};
   //Generate taxi map    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    
    
    //Find the meeting location
     int Ppos = 0, Npos = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (taxiMatrix[i][j] > E3*2) {
                Ppos++;
            }
            if (taxiMatrix[i][j] < -(E3)) {
                Npos++;
            }
        }
    }
    //Find position of meeting point
    int pos1 = SumOf2digits(Ppos);
    int pos2 = SumOf2digits(Npos);

    //Score of the taxi 
    int taxiScore = taxiMatrix[pos1][pos2];
    
    // calculating Sherlock and Watson score
    for (int i = 0; i < 10; ++i) 
        for (int j = 0; j < 10; ++j) {
            int maxNum =0;
                for (int x = i, y = j; (x >= 0) && (y >= 0); x--, y--) {
                maxNum = max(maxNum, taxiMatrix[x][y]);
            }
            for (int x = i, y = j; (x <= 9) && (y <= 9); x++, y++) {
                maxNum = max(maxNum, taxiMatrix[x][y]);
            }
            for (int x = i, y = j; (x >= 0) && (y <= 9); x--, y++) {
                maxNum = max(maxNum, taxiMatrix[x][y]);
            }
            for (int x = i, y = j; (x <= 9 && y >= 0); x++, y--) {
                maxNum = max(maxNum, taxiMatrix[x][y]);
            }                  
            
            
            SherWatMatrix [i][j] = maxNum;
                
            }

    
    int SherWatScore = SherWatMatrix[pos1][pos2]; 
    
    if (abs(taxiScore) > SherWatScore)
{
    checkStatusTask3(HP1, EXP1, HP2, EXP2);
    EXP1 = static_cast<int>(ceil(EXP1 - double(EXP1) * 0.12));
    EXP2 = static_cast<int>(ceil(EXP2 - double(EXP2) * 0.12));
    HP1 = static_cast<int>(ceil(HP1 - double(HP1) * 0.1));
    HP2 = static_cast<int>(ceil(HP2 - double(HP2) * 0.1));
    checkStatusTask3(HP1, EXP1, HP2, EXP2);
}
else
{
    checkStatusTask3(HP1, EXP1, HP2, EXP2);
    EXP1 = static_cast<int>(ceil(EXP1 + double(EXP1) * 0.12));
    EXP2 = static_cast<int>(ceil(EXP2 + double(EXP2) * 0.12));
    HP1 = static_cast<int>(ceil(HP1 + double(HP1) * 0.1));
    HP2 = static_cast<int>(ceil(HP2 + double(HP2) * 0.1));
    checkStatusTask3(HP1, EXP1, HP2, EXP2);
}
    return (abs(taxiScore) > SherWatScore) ? taxiScore : SherWatScore;
    return -1;

}


// Task 4


    

int checkPassword(const char *s, const char *email) {
//Determine se
char se[101];
int seIndex = 0;
for (int i = 0; i < strlen(email); ++i) 
{
    if (email[i] == '@')
    {
        break;
    }
    se[seIndex++] = email[i];
}
se[seIndex] = '\0';

//check the validity of password

if (strlen(s) < 8)
    {
        return -1;
    }
else if (strlen(s) > 20 )
    {
        return -2;  
    }
else if (strstr(s, se) != NULL) {
    return -(300 + (strstr(s, se) - s));
}    

for (int i = 0; i < strlen(s); ++i)
        {
            if ( s[i] == s[i+1] && s[i+1] == s[i+2])
            {
                return -(400 + i);
            }
        }  
   

if (strpbrk(s, "@#%$!") == NULL) {
        return -5;  // Does not contain special characters
    }


for (int i = 0; i < strlen(s); ++i)
    {
        char currentChar = s[i];
        if (currentChar < 'a' && currentChar >'z')
        {
            return i;
        }
        else if (currentChar < 'A' && currentChar > 'Z') 
        {
            return i;
        }
        else if (currentChar < '0' && currentChar > '9' )
        {
            return i;
        }
        else if (currentChar == '^')
        {
            return i;
        }
    }

    return -10;
}


// Task 5

int mostAppearance(const char **arr, int n)   
{
    int maxCount = 0;
    const char *mostAppPwd;
    int firstOccur;
    for (int i = 0; i < n; ++i)
    {
        int count = 0;
            for ( int j = 0; j < n; ++j)
            {
                if (arr[i] == arr[j])
                count ++;
            }
    if (maxCount < count)   
        maxCount = count;
        mostAppPwd = arr[i];
        firstOccur = i;
    }
    return firstOccur;
}



int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    
    int maxFreq = 0;
    int maxLen = 0;
    int correctPass = -1;

    for (int i = 0; i < num_pwds; i++) {
        const char *currentPass = arr_pwds[i];

        // Initialize or update frequency and length of the current password
        int frequency = 1;
        int length = strlen(currentPass);

        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(currentPass, arr_pwds[j]) == 0) {
                frequency++;
                length = (int)strlen(arr_pwds[j]); // Update length if a longer occurrence is found
            }
        }

        // Check if the current password is more frequent or has longer length
        if (frequency > maxFreq || (frequency == maxFreq && length > maxLen)) {
            maxFreq = frequency;
            maxLen = length;
            correctPass = i;
        }
    }

    return correctPass;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
