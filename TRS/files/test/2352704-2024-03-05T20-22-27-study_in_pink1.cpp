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

//CHECK
int check(int x, int lower, int upper)
{
x = (x < lower) ? lower : (x > upper ? upper : x);
return x;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
   // TODO: Complete this function
    //CASE 1
    if(e1<0||e1>99) return -99;
    exp2= check(exp2,0,600);
    exp1= check(exp1,0,600);
    int D;
    if(e1<4)
    {
       if(e1==0)
        exp2 += 29.0;
       
       else if(e1==1)
        exp2 += 45.0;
       
       else if(e1==2)
        exp2 += 75.0;
       
       else if(e1==3)
        exp2 += 149.0;
       exp2= check(exp2,0,600); 
       D=e1*3 + exp1*7;
       if(D %2==0)
       exp1 = ceil(double(exp1+D/200.0 ));
       else
       exp1 =ceil(double(exp1- D/100.0));
       exp1= check(exp1,0,600);
    }
    //CASE 2
    else if(e1>3 && e1<99)
    {
      if(4<=e1&&e1 <=19) 
       exp2 = ceil(double(exp2 +(e1/4.0 + 19.0)*1.0));  
       
      else if(20<=e1 &&e1 <=49)
       exp2 = ceil(double(exp2 +(e1/9.0 + 21.0)*1.0));
       
      else if(50<=e1&&e1 <=65)
       exp2 = ceil(double(exp2 +(e1/16.0 + 17.0)*1.0)); 
       
      else if(66<=e1 && e1 <=79)
       {
        exp2 = ceil(double( exp2+(e1/4.0 + 19)*1.0));
        if(exp2 >200)
        exp2 =  ceil(double(exp2+(e1/9.0 + 21)*1.0));
       }
       
      else if(80<=e1 && e1 <=99)
       {
        exp2 =  ceil(double(exp2+(e1/4.0 + 19)));
        exp2 =  ceil(double(exp2+(e1/9.0 + 21)));
        if(exp2 >400)
        {
        exp2 =  ceil(double(exp2+(e1/16.0 + 17)));
        exp2 = ceil(double(exp2*1.15));    
        }
       }
       exp2= check(exp2,0,600);
       exp1 = ceil(double(exp1-e1));
       exp1= check(exp1,0,600);
    }
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function

    if (E2 < 0 || E2>99)
        return -99;

    EXP1 = check(EXP1, 0, 600);
    HP1 = check(HP1, 0, 666);
    M1 = check(M1, 0, 3000);
    int x, S;
    double P1, P2, P3, P;
    //ROAD 1 
    //FIND S
    S = round(sqrt(EXP1));
    S = pow(S, 2);

    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = double(((EXP1 / S) + 80) / 123.0);

    //ROAD 2 

    //E2 IS EVEN
    if (E2 % 2 == 0)
    {
        if (M1 > 0) {


            //ACTION 1 EVEN
            if (HP1 < 200)
            {
                HP1 = ceil(double(HP1 * 1.3) - 0.00000000000006);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(double(HP1 * 1.1) - 0.00000000000006);
                M1 -= 70;
            }
            M1 = check(M1, 0, 3000);
            HP1 = check(HP1, 0, 666);
            if (M1 != 0)
            {
                //ACTION 2 EVEN
                if (EXP1 < 400)
                {
                    M1 -= 200;
                }
                else
                {
                    M1 -= 120;
                }
                EXP1 = ceil(double(EXP1 * 1.13));
                M1 = check(M1, 0, 3000);
                EXP1 = check(EXP1, 0, 600);
                if (M1 != 0)
                {
                    //ACTION 3 EVEN
                    if (EXP1 < 300)
                    {
                        M1 -= 100;
                    }
                    else
                    {
                        M1 -= 120;
                    }
                    M1 = check(M1, 0, 3000);
                    EXP1 = ceil(double(EXP1 * 0.9));
                    EXP1 = check(EXP1, 0, 600);
                }
            }
        }
    }
    //E2 IS ODD
    else
    {
        if (M1 > 0) {
            int x = 0;
            float M3 = M1 / 2.0;
            while (x <= M3)
            {
                //ACTION 1 ODD
                M1 = check(M1, 0, 3000);

                if (HP1 < 200)
                {
                    HP1 = ceil(double(HP1 * 1.3) - 0.00000000000006);
                    M1 -= 150;
                    x += 150;
                }
                else
                {
                    HP1 = ceil(double(HP1 * 1.1) - 0.00000000000006);
                    M1 -= 70;
                    x += 70;
                }
                M1 = check(M1, 0, 3000);
                HP1 = check(HP1, 0, 666);
                if (x <= M3)
                {
                    //ACTION 2 ODD
                    if (EXP1 < 400)
                    {
                        M1 -= 200;
                        x += 200;
                    }
                    else
                    {
                        M1 -= 120;
                        x += 120;
                    }
                    EXP1 = ceil(double(EXP1 * 1.13));
                    EXP1 = check(EXP1, 0, 600);
                    M1 = check(M1, 0, 3000);
                    if (x <= M3)
                    {
                        //ACTION 3 ODD
                        if (EXP1 < 300)
                        {
                            M1 -= 100;
                            x += 100;
                        }
                        else
                        {
                            M1 -= 120;
                            x += 120;
                        }

                        M1 = check(M1, 0, 3000);
                        EXP1 = ceil(double(EXP1 * 0.9));
                        EXP1 = check(EXP1, 0, 600);
                    }
                }
            }
        }
    }
    HP1 = ceil(double(HP1 * 0.83));
    EXP1 = ceil(double(EXP1 * 1.17));
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);
    //FIND S    
    S = round(sqrt(EXP1));
    S = pow(S, 2);

    if (EXP1 >= S)
        P2 = 1;
    else
        P2 = double(((EXP1 * 1.0 / S) + 80) / 123);

    //ROAD 3
    int arr[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 <= 9)
    {
        i = E2;
        P3 = 0.01 * arr[i];
    }
    else
    {
        int   a = E2 / 10; // Chữ số thứ 1
        int   b = E2 % 10; // Chữ số thứ 2
        i = (a + b) % 10;
        P3 = 0.01 * arr[i];
    }
    if (P1 == 1 && P2 == 1 && P3 == 1)
        EXP1 = ceil(double(EXP1 * 0.75));
    else
    {
        P = (P1 + P2 + P3) / 3.0;
        if (P < 0.5)
        {
            HP1 = ceil(double(HP1 * 0.85));
            EXP1 = ceil(double(EXP1 * 1.15));
        }
        else
        {
            HP1 = ceil(double(HP1 * 0.9));
            EXP1 = ceil(double(EXP1 * 1.2));
        }
    }
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);

    return HP1 + EXP1 + M1;
}


//RUNNER TASK 3
int chase(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if(E3<0 || E3>99)
    return -99;
   
    check(EXP1,0,600);
    check(HP1,0,666);
    long int taxi,lock,a,b;
    long int arr2[10][10];
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			arr2[i][j] = ((E3*j)+(i*2))*(i-j);
			if( arr2[i][j]>E3*2 )
            {
			a++;
            }
			else if( arr2[i][j]+ E3 <0)
            {
			b++;
            }
		}
	}
    while(a>9)
    {
     int   first = a / 10;
     int   second = a % 10;
     a= first + second;
    }    
    int i=a;
    while(b>9)
    {
     int   first = b / 10; 
     int   second = b % 10;  
     b= first + second;
    }  
    int j=b;
    taxi = arr2[i][j];
    i=a;j=b;
    while(i<=9 && j<=9)
    {
      if(arr2[i][j]>lock)
      {
      lock=arr2[i][j];
      }
      i++;j++;
    }
    i=a;j=b;
    while(i>=0 && j>=0)
    {
      if(arr2[i][j]>lock) 
      {
      lock=arr2[i][j];
      }
      i--;j--;
    }
    i=a;j=b;
    while(i<=9 && j<=9 && i>=0 && j>=0)
    {
      if(arr2[i][j]>lock) 
      {
      lock=arr2[i][j];
      }
      i++;j--;
    }
    i=a;j=b;
    while(i<=9 && j<=9 && i>=0 && j>=0)
    {
      if(arr2[i][j]>lock) 
      {
      lock=arr2[i][j];
      }
      i--;j++;
    }

    if(lock >=abs(taxi))
    {
        EXP1= ceil(float(EXP1*1.12));
        check(EXP1,0,600);
        HP1= ceil(float(HP1*1.1));
        check(HP1,0,666);
        EXP2= ceil(float(EXP2*1.12));
        check(EXP2,0,600);
        HP2= ceil(float(HP2*1.1));
        check(HP2,0,666);
       return lock;
    }

    else 
    {
       EXP1= ceil(float(EXP1*0.88));
       check(EXP1,0,600);
       HP1= ceil(float(HP1*0.9));
       check(HP1,0,666);
       EXP2= ceil(float(EXP2*0.88));
       check(EXP2,0,600);
       HP2= ceil(float(HP2*0.9));
       check(HP2,0,666); 
       return taxi;
    }
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    if(E3<0 || E3>99)
    return -99;

    int x= chase(HP1,EXP1,HP2,EXP2,E3);
    return x;
    return -1;
}
//CHECK MACHINE TASK 4
bool Charactercheck(char c){
    string specialchar = " @#%$!";
    return specialchar.find(c) != string::npos;
}
//RUNNER TASK 4
int checkpass( string s, string email)  
{
    size_t at_position = email.find('@');
    if(at_position == string::npos){
        return -1;
    }
    string se = email.substr(0, at_position);
    //LESS CHARACTER
    if (s.length()<8)
    {
        return -1;
    }
    //MORE CHARACTER
    if (s.length()>20){
        return -2;
    }
    //SAME AS MAIL
    if(s.find(se) != string::npos){
        


        return -(300 + s.find(se));
    
    }
    //MORE THAN 2
    for (size_t i=0; i< s.length() -2; ++i)
    {
        if(s[i] == s[i+1] && s[i]== s[i+2])
        {
            return -(400 +i);
        
        }
    }
    bool has_special_character = false;
    for (char c: s){
        if (Charactercheck(c)){
            has_special_character = true;
            break;
        }
    }
    //SPECIAL CHAR
    if (!has_special_character){
        return -5;
    }
    //OTHERS
    for (size_t i = 0; i < s.length(); ++i) {
        if (!isalnum(s[i]) && !Charactercheck(s[i])) {
            return i;
        }
    }

    
    return -10;
} 
// Task 4


int checkPassword(const char * s, const char * email) {

    int x= checkpass(s,email);
    return x;
}
//RUNNER
int Correctpass( string arr_pwds[], int num_pwds) {
    int max_length = 0;
    int max_count = 0;
    string correct_position;
    int max=0;
    int result=0;
    for (int i = 0; i < num_pwds; ++i) 
    {
        int count=0;
        for(int j=0;j< num_pwds; ++j)
        {
            if(arr_pwds[i]== arr_pwds[j])
            count++;
        }
        if(count > max)
        {
            max = count;
            correct_position= arr_pwds[i];
            result=i;
        }
        else if(count == max)
        {
             
            if(arr_pwds[i].length()>correct_position.length())
            {
            correct_position= arr_pwds[i];
            result=i;
            }
        }
        
    }

    return result;
}
// Task 5
int findCorrectPassword(const char*  arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    arr_pwds[num_pwds];
    string arr3[num_pwds];
    for (int i = 0; i < num_pwds; ++i) {
        arr3[i] = arr_pwds[i];
    }

    int result = Correctpass(arr3, num_pwds);
    return result;

}   

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////