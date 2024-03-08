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
int checkexp (int &x)
{
    if ( x > 600) x = 600;
    else if ( x < 0) x = 0;
    return x;
}
int checkhp (int &x)
{
    if ( x > 666) x = 666;
    else if ( x < 0) x = 0;
    return x;
}
int checkM (int &x)
{
    if ( x > 3000 ) x =3000;
    else if (x < 0) x =0;
    return x;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

    if ( e1 >= 0 && e1 <= 3)
    {
        checkexp(exp2);
        checkexp(exp1);
        switch (e1) 
        {
            case 0 : exp2 += 29;
            break;
            case 1: exp2 += 45; 
            break; 
            case 2: exp2 += 75; 
            break; 
            case 3: exp2 += 149; 
            break; 
            default : return -99;
        }
    
    int D = e1*3 + exp1*7;
        if (D%2 == 0)
        {  
        exp1 += ceil((D) /200.0);
        }
        else 
        {
        exp1 -= (D /100);  
        }
        checkexp(exp2);
        checkexp(exp1);
        return exp1 + exp2;
    }
    else if ( e1 >= 4 && e1 <= 99)
    { 
        checkexp(exp2);
        checkexp(exp1);
        if (e1 >= 4 && e1 <= 19) exp2 +=ceil((e1)/4.0) +19;
        else if (e1 >= 20 && e1 <= 49) exp2 +=ceil((e1)/9.0) + 21;
        else if (e1 >= 50 && e1 <= 65) exp2 +=ceil((e1)/16.0) + 17;
        else if (e1 >= 66 && e1<= 79) {
            exp2 = (exp2 + 19) + ceil((e1)/4.0);
            if (exp2 > 200) exp2 += ceil((e1)/9.0) + 21;
            }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil((e1)/4.0) +19;
            exp2 += ceil((e1)/9.0) + 21;
            if (exp2 > 400)
            {
                exp2 += ceil((e1)/16.0) + 17;
                exp2 += ceil((exp2) * 0.15 );
            } 
            }
        checkexp(exp2);
        exp1 -= e1;
        checkexp(exp1);
        return exp1 + exp2;
    }
    else return -99;
}
 
// Task 2
int chinhphuong (int x)
{
    int y = round(sqrt(x));
    y = y*y;
    return y;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {


    if (E2 < 0 || E2 > 99 ) return -99;  
    double P1,P2,P3;
    checkexp(EXP1); 
    checkhp(HP1);
    checkM(M1);

 

// Road 01
    int S = chinhphuong(EXP1);
    if (EXP1 >= S) P1 = 1.0; 
    else P1 = ((static_cast<double> (EXP1) / S) + 80) / 123; 

// Road 02  
   const double d = M1 * 0.5;
   if(E2 >= 0 && E2 <= 99 && E2 % 2 != 0) 
   { 
        while ( d <= M1 && d > 0 && M1 > 0)
        {       
            if(HP1 < 200) 
            {
                HP1 = ceil(HP1 + (HP1* 0.3));
                M1 -=150;
            }
            else
            {
                HP1 = ceil(HP1 + (HP1* 0.1));
                M1 -= 70;
            }  

            checkhp(HP1);
            checkM(M1);

            if( d > M1 ) break;

            if (EXP1 < 400) M1 -= 200; 
            else  M1 -= 120;

            
            EXP1 = ceil(EXP1 + (EXP1 * 0.13));
            checkexp(EXP1);
            checkM(M1);

            if( d > M1 ) break;

            if (EXP1 < 300) M1-=100;
            else M1 -= 120;

            EXP1 = ceil(EXP1 - (EXP1 * 0.1));

            checkexp(EXP1);
            checkM(M1);
            
            if( d > M1 ) break;
        }
    HP1 = ceil(HP1 - (HP1 * 0.17));
    EXP1 = ceil(EXP1 + (EXP1 * 0.17));
    }
    else if ( E2 >= 0 && E2 <= 99 && E2 % 2 == 0)
    {
   
        for (int i = 0; i < 1; i++)
        {
            if (M1 == 0 ) break;
               if(HP1 < 200) 
            {
                HP1 = ceil(HP1 + (HP1* 0.3));
                M1 -=150;
            }
            else if(HP1 >= 200)
            {
                HP1 = ceil(HP1 + (HP1* 0.1));
                M1 -= 70;
            }  
            checkhp(HP1);
            checkM(M1);

            if (M1 == 0) break;

            if (EXP1 < 400) M1 -= 200; 
            else  M1 -= 120;

            checkM(M1);

            EXP1 = ceil(EXP1 + (EXP1 * 0.13));
            checkexp(EXP1);

            if (M1 == 0)  break;

            if (EXP1 < 300) M1-=100;
            else M1 -= 120;

            checkM(M1);

            EXP1 = ceil(EXP1 - (EXP1 * 0.1));
            checkexp(EXP1);

            if (M1 == 0) break;
        }
    HP1 = ceil(HP1 - (HP1 * 0.17));
    EXP1 = ceil(EXP1 + (EXP1 * 0.17));
    }
    checkexp(EXP1);
    checkhp(HP1);

    int S2 = chinhphuong(EXP1);
    if (EXP1 >= S2) P2 = 1.0; 
    else P2 = ((static_cast<double> (EXP1) / S2) + 80) / 123; 

//Road 03
int arrayP[10] ={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int n;
if ( E2 >= 0 && E2 <= 9)
    {
        P3 = (arrayP[E2] / 100.0);
    }
else
    {
        n = (E2 / 10) + (E2%10);
        if ( n >=0 && n <= 9) P3 = (arrayP[n] / 100.0);
        else P3 = (arrayP[n%10] / 100.0);
    }
    
 
double avP = (P1 + P2 + P3) / 3.0;
if ( P1 == 1.0 && P2 ==1.0 && P3 == 1.0) {
    EXP1 = ceil(EXP1 -(EXP1 * 0.25));
    checkexp(EXP1);
}
else 
{
    if (avP < 0.5 )
    {
        HP1 = ceil(HP1 - (HP1 * 0.15));
        EXP1 = ceil(EXP1 + (EXP1 * 0.15));
    }
    else if (avP >= 0.5)
    {
        HP1 = ceil(HP1 - (HP1 * 0.1));
        EXP1 = ceil(EXP1 + (EXP1 * 0.2));
    }
    checkexp(EXP1);
    checkhp(HP1);
}




   return HP1 + EXP1 + M1;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    if ((E3 > 99) or (E3 < 0)) return -99;

    EXP1 = checkexp(EXP1);//update value of exp1
    HP1 = checkhp(HP1);//update value of hp1

    EXP2 = checkexp(EXP2);//update value of exp2
    HP2 = checkhp(HP2);//update value of hp2

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
        EXP1 = checkexp(EXP1);//update value of exp1

        EXP2 = ceil((EXP2 * 0.88) - 1e-10);
        EXP2 = checkexp(EXP2);//update value of exp2

        HP1 = ceil((HP1 * 0.9) - 1e-10);
        HP1 = checkhp(HP1);//update value of hp1

        HP2 = ceil((HP2 * 0.9) - 1e-10);
        HP2 = checkhp(HP2);//update value of hp2

        return diem[i][j];
    }
    else//can catch up the taxi
    {
        EXP1 = EXP1 + ceil(EXP1 * 0.12 - 1e-10);
        EXP1 = checkexp(EXP1);//update value of exp1

        EXP2 = EXP2 + ceil(EXP2 * 0.12 - 1e-10);
        EXP2 = checkexp(EXP2);//update value of exp2

        HP1 = HP1 + ceil(HP1 * 0.1 - 1e-10);
        HP1 = checkhp(HP1);//update value of hp1

        HP2 = HP2 + ceil(HP2 * 0.1 - 1e-10);
        HP2 = checkhp(HP2);//update value of hp2

        return score;
    }
    //return -1;
}
    


//Task 4
int checkPassword(const char * s, const char * email) {
string pass = s;
string mail = email;
int dodai = pass.size();
int position = mail.find("@");
string se = mail.substr(0, position);

if ( dodai < 8) return -1;
if (dodai > 20) return -2;
if (pass.find(se) != string::npos) return -(300 + pass.find(se));
for (int j = 0; j < dodai - 2; j++ )
    {
        if (pass.at(j) == pass.at(j+ 1) && pass.at(j + 1) == pass.at(j + 2)) 
            {
                return -(400 + j);
            }
    }
for (int i = 0; i < dodai ; i ++) {
        int q = pass.at(i);
        if (q == 36 || q == 35 || q == 37 || q == 33 || q == 64) break;
        if ( i == (dodai -1)) return -5;
}

for (int i = 0; i < dodai ; i ++) {
    int t = pass.at(i);
        if (t == 34 || (t >= 0 && t <= 32 )|| (t >= 38 && t <= 47 )|| (t >= 58 && t <= 63) || (t >= 91 && t <= 96) || (t>= 123  && t<= 127)) {
            return i;
        }
}
return -10;
 }

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int countmax = 0;
    int lengthmax = 0;
    const char *passhiennhieunhat = nullptr;

    for (int i = 0; i < num_pwds; ++i) {
        int count = 0;
        int length = strlen(arr_pwds[i]);

        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > countmax || (count == countmax && length > lengthmax)) {
            passhiennhieunhat = arr_pwds[i];
            countmax = count;
            lengthmax = length;
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu xuất hiện nhiều nhất trong mảng
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], passhiennhieunhat) == 0) {
            return i;
        }
    }
    return 0;
}
// ////////////////////////////////////////////////
// /// END OF STUDENT'S ANSWER
// ////////////////////////////////////////////////