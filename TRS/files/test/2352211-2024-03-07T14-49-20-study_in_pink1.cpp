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
int firstMeet(int & exp1, int & exp2, int e1) {
   //gioi han e1
    if(e1>99)
    {
        e1=-99;
    }
    else if(e1<0)
    {
        e1=-99;
    }                    
    //
    //gioi han xp
    if(exp1<0)
    {
        exp1=0;
    }
    else if(exp1>600)
    {
        exp1=600;
    }
    if(exp2<0)
    {
        exp2=0;
    }
    else if(exp2>600)
    {
        exp2=600;
    }
    //
    double exp1a;
    exp1a=exp1;
    double exp2a;
    exp2a=exp2;
    double e1a;
    e1a=e1;
    //1 den 3.........................................................
    if(e1>=0&&e1<=3)
    {
    if(e1==0)
    {
        exp2=exp2+29;
    }
    else if(e1==1)
    {
        exp2=exp2+45;
    }
    else if(e1==2)
    {
        exp2=exp2+75;
    }
    else if(e1==3)
    {
        exp2=exp2+(29+45+75);
    }
    int D;
    double D1;    
    D = e1*3+exp1*7;
    D1 = D;
    int kiemtraD;
    kiemtraD=D%2;
    if (kiemtraD==0)
    {
        exp1a=exp1+(D1/200);
        exp1=ceil(exp1a);
    }
    else if(kiemtraD==1)
    {
        exp1a=exp1-(D1/100);
        exp1=ceil(exp1a);
    }
    
    }
    //4 den 99.............................................................
    e1a=e1;
    if(e1>=4&&e1<=99)
    {
    if(e1>=4 && e1<=19)
    {
       exp2a=exp2+(e1a/4)+19;
       exp2=ceil(exp2a);
    }
    else if(e1>=20 && e1<=49)
    {
       exp2a=exp2+(e1a/9)+21;
       exp2=ceil(exp2a);
    }
    else if(e1>=50 && e1<=65)
    {
        exp2a=exp2+(e1a/16)+17;
        exp2=ceil(exp2a);
    }
    else if(e1>=66 && e1<=79)
    {
       exp2a=exp2+(e1a/4)+19;
       exp2=ceil(exp2a);
       if(exp2>200)
       {
        exp2a=exp2+(e1a/9)+21;
        exp2=ceil(exp2a);
       }
    }
    else if(e1>=80 && e1<=99)
    {
       exp2a=exp2+(e1a/4)+19;
       exp2=ceil(exp2a);
       exp2a=exp2+(e1a/9)+21;
       exp2=ceil(exp2a);
       if(exp2>400)
       {
        exp2a=exp2+(e1a/16)+17;
        exp2=ceil(exp2a);
        exp2a=exp2+((exp2a*15)/100);
        exp2=ceil(exp2a);
       }
       
    }
    //gioi han xp
    if(exp1<0)
    {
        exp1=0;
    }
    else if(exp1>600)
    {
        exp1=600;
    }
    if(exp2<0)
    {
        exp2=0;
    }
    else if(exp2>600)
    {
        exp2=600;
    }
    exp1=exp1-e1;
    
    }
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
//gioi han hp,xp,m,e
 //gioi han hp
 if (HP1 > 666)
 {
     HP1 = 666;
 }
 else if (HP1 < 0)
 {
     HP1 = 0;
 }
 //gioi han xp;
 if (EXP1 < 0)
 {
     EXP1 = 0;
 }
 else if (EXP1 > 600)
 {
     EXP1 = 600;
 }
 //gioi han m
 if (M1 > 3000)
 {
     M1 = 3000;
 }
 else if (M1 < 0)
 {
     M1 = 0;
 }
 //gioi han e2
 if (E2 < 0 || E2>99)
 {
     E2 = -99;
 }
 //tao cac tham so doi chieu
 double exp1a;
 exp1a = EXP1;
 double HP1a;
 HP1a = HP1;
 //Way 1
 float canb2exp1;
 double S;
 canb2exp1 = sqrt(EXP1);
 canb2exp1 = round(canb2exp1);
 S = pow(canb2exp1, 2);
 double P1;
 if (EXP1 >= S)
 {
     P1 = 1;
 }
 else
 {
     P1 = ((exp1a / S) + 80) / 123;
 }
 //way 2
 //sk1
 int nammuoim1 = (M1 * 50) / 100;
 if (E2 % 2 == 0)
 {
     if (M1 > 0)
     {
         //sk1
         if (HP1 < 200)
         {
             HP1 = ceil(HP1 * 1.3);
             M1 = M1 - 150;
         }
         else if (HP1 >= 200)
         {
             HP1 = ceil(HP1 * 1.1);
             M1 = M1 - 70;
         }
         if (HP1 > 666)
         {
             HP1 = 666;
         }
         else if (HP1 < 0)
         {
             HP1 = 0;
         }
         //gioi han xp;
         if (EXP1 < 0)
         {
             EXP1 = 0;
         }
         else if (EXP1 > 600)
         {
             EXP1 = 600;
         }
         //gioi han m
         if (M1 > 3000)
         {
             M1 = 3000;
         }
         else if (M1 < 0)
         {
             M1 = 0;
         }
         if (M1 > 0)
         {
             //sk2
             if (EXP1 < 400)
             {
                 M1 = M1 - 200;
                 EXP1 = ceil(EXP1 * 1.13);
             }
             else if (EXP1 >= 400)
             {
                 M1 = M1 - 120;
                 EXP1 = ceil(EXP1 * 1.13);
             }
         }
         if (HP1 > 666)
         {
             HP1 = 666;
         }
         else if (HP1 < 0)
         {
             HP1 = 0;
         }
         //gioi han xp;
         if (EXP1 < 0)
         {
             EXP1 = 0;
         }
         else if (EXP1 > 600)
         {
             EXP1 = 600;
         }
         //gioi han m
         if (M1 > 3000)
         {
             M1 = 3000;
         }
         else if (M1 < 0)
         {
             M1 = 0;
         }
         if (M1 > 0)
         {
             //sk3
             if (EXP1 < 300)
             {
                 M1 = M1 - 100;
                 EXP1 = ceil(EXP1 * 0.9);
             }
             else if (EXP1 >= 300)
             {
                 M1 = M1 - 120;
                 EXP1 = ceil(EXP1 * 0.9);
             }

         }

     }
 }
 if (HP1 > 666)
 {
     HP1 = 666;
 }
 else if (HP1 < 0)
 {
     HP1 = 0;
 }
 //gioi han xp;
 if (EXP1 < 0)
 {
     EXP1 = 0;
 }
 else if (EXP1 > 600)
 {
     EXP1 = 600;
 }
 //gioi han m
 if (M1 > 3000)
 {
     M1 = 3000;
 }
 else if (M1 < 0)
 {
     M1 = 0;
 }
 if (E2 % 2 == 1)
 {
     while (M1 > 0 && M1 > nammuoim1)
     {
         if (M1 > 0 && M1 > nammuoim1)
         {


             //sk1
             if (HP1 < 200)
             {
                 HP1 = ceil(HP1 * 1.3);
                 

                 M1 = M1 - 150;
             }
             else if (HP1 >= 200)
             {
                 HP1 = ceil(HP1 * 1.1);
                 M1 = M1 - 70;
             }
         }
         if (HP1 > 666)
         {
             HP1 = 666;
         }
         else if (HP1 < 0)
         {
             HP1 = 0;
         }
         //gioi han xp;
         if (EXP1 < 0)
         {
             EXP1 = 0;
         }
         else if (EXP1 > 600)
         {
             EXP1 = 600;
         }
         //gioi han m
         if (M1 > 3000)
         {
             M1 = 3000;
         }
         else if (M1 < 0)
         {
             M1 = 0;
         }
         if (M1 > 0 && M1 > nammuoim1)
         {
             //sk2
             if (EXP1 < 400)
             {
                 M1 = M1 - 200;
                 EXP1 = ceil(EXP1 * 1.13);
             }
             else if (EXP1 >= 400)
             {
                 M1 = M1 - 120;
                 EXP1 = ceil(EXP1 * 1.13);
             }
         }
         if (HP1 > 666)
         {
             HP1 = 666;
         }
         else if (HP1 < 0)
         {
             HP1 = 0;
         }
         //gioi han xp;
         if (EXP1 < 0)
         {
             EXP1 = 0;
         }
         else if (EXP1 > 600)
         {
             EXP1 = 600;
         }
         //gioi han m
         if (M1 > 3000)
         {
             M1 = 3000;
         }
         else if (M1 < 0)
         {
             M1 = 0;
         }
         if (M1 > 0 && M1 > nammuoim1)
         {
             //sk3
             if (EXP1 < 300)
             {
                 M1 = M1 - 100;
                 EXP1 = ceil(EXP1 * 0.9);
             }
             else if (EXP1 >= 300)
             {
                 M1 = M1 - 120;
                 EXP1 = ceil(EXP1 * 0.9);
             }

         }
         if (HP1 > 666)
         {
             HP1 = 666;
         }
         else if (HP1 < 0)
         {
             HP1 = 0;
         }
         //gioi han xp;
         if (EXP1 < 0)
         {
             EXP1 = 0;
         }
         else if (EXP1 > 600)
         {
             EXP1 = 600;
         }
         //gioi han m
         if (M1 > 3000)
         {
             M1 = 3000;
         }
         else if (M1 < 0)
         {
             M1 = 0;
         }

     }
 }        
 HP1 = ceil(HP1 * 0.83);
 
 EXP1 = ceil(EXP1 * 1.17);
 double P2;
 canb2exp1 = sqrt(EXP1);
 canb2exp1 = round(canb2exp1);
 int S2 = pow(canb2exp1, 2);
 if (EXP1 < S2)
 {
     P2 = ((EXP1 / S2) + 80) / 123;
 }
 if (EXP1 >= S2)
 {
     P2 = 1;
 }
 //way 3
 double Pi[10] = { 32,47,28,79,100,50,22,83,64,11 };
 int i;
 int sum = floor(E2 / 10) + E2 % 10;
 if (E2 < 10)
 {
     i = E2 % 10;
 }
 else if (E2 > 10)
 {
     i = sum % 10;
 }
 double P3 = Pi[i]/ 100;
 double tongP = (P1 + P2 + P3)/3;
 
 if (tongP < 0.5)
 {
     HP1 = ceil(HP1 * 0.85);
     
     EXP1 = ceil(EXP1 * 1.15);
 }
 else if (tongP >= 0.5)
 {
     HP1 = ceil(HP1 * 0.9);

     EXP1 = ceil(EXP1 * 1.2);
 }
 //
 if (HP1 > 666)
 {
     HP1 = 666;
 }
 else if (HP1 < 0)
 {
     HP1 = 0;
 }
 //gioi han xp;
 if (EXP1 < 0)
 {
     EXP1 = 0;
 }
 else if (EXP1 > 600)
 {
     EXP1 = 600;
 }
 //gioi han m
 if (M1 > 3000)
 {
     M1 = 3000;
 }
 else if (M1 < 0)
 {
     M1 = 0;
 }
 //gioi han e2
 if (E2 < 0 || E2>99)
 {
     E2 = -99;
 }









 //
    //
    return HP1 + EXP1 + M1;
}
  
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
}

// Task 4
// ham kytudacbiet
bool kytudacbiet(char c) 
{
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}
int checkPassword(const char * s, const char * email) 
{

    int seLength = 0;
    while (email[seLength] != '@') {
        seLength++;
    }
    char se[seLength + 1];
    for (int i = 0; i < seLength; ++i) {
        se[i] = email[i];
    }
    se[seLength] = '\0';

   
    int passwordLength = 0;
    while (s[passwordLength] != '\0') {
        passwordLength++;
    }
    if (passwordLength < 8) {
        return -1;
    }
    if (passwordLength > 20) {
        return -2;
    }

   
    bool kiemtrakytudacbiet = false;
    for (int i = 0; i < passwordLength; ++i) {
        if (kytudacbiet(s[i])) {
            kiemtrakytudacbiet = true;
            break;
        }
    }
    if (!kiemtrakytudacbiet) {
        return -5;
    }

    
    const char* foundSe = nullptr;
    for (int i = 0; i <= passwordLength - seLength; ++i) {
        bool match = true;
        for (int j = 0; j < seLength; ++j) {
            if (s[i + j] != se[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            foundSe = &s[i];
            break;
        }
    }
    if (foundSe != nullptr) {
        return -(300 + (foundSe - s));
    }

   
    for (int i = 0; i < passwordLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i);
        }
    }

    
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    
 const char* password = nullptr;
    int maxCount = 0;
    int vitrimkdung = -1;

    
    for (int i = 0; i < num_pwds; ++i) {
        int count = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++count;
            }
        }
        if (count > maxCount || (count == maxCount && strlen(arr_pwds[i]) > strlen(password))) {
            maxCount = count;
            password = arr_pwds[i];
            vitrimkdung = i;
        }
    }

    return vitrimkdung;
}
    


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////