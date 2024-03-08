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
int firstMeet(int & exp1, int & exp2, int e1) 
{
    // TODO: Complete this function
    if (e1 < 0  || e1 > 99) {return -99;}
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 += 29;
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0; 
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0; 
        }
         else if(e1 == 2)
        {
            exp2 += 75;
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0; 
        }
        else if (e1 == 3)
        {
            exp2 += (29 + 45 + 75);
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0; 
        }
         int D = e1 * 3 + exp1 * 7;
         float iexp1;
         if (D % 2 == 0)
         {
            iexp1= exp1 * 1.0 + D * 1.0 / 200;
         }
         else if (D % 2 !=0)
         {
            iexp1 = (exp1 * 1.0 - D * 1.0 / 100 );
         }
         exp1=ceil(iexp1);
         if (exp1 > 600) exp1 = 600;
         else if (exp1 < 0) exp1 = 0;
    } 
    //TH2
    if (e1 >=4 && e1 <=99)
   {  
        if (e1 >= 4 && e1 <= 19)
    {
        exp2 = exp2 + ceil(e1 * 1.0 / 4 + 19);
        if (exp2 > 600) exp2 = 600;
        else if (exp2 < 0) exp2 = 0; 
    }
     else if (e1 >= 20 && e1  <= 49)
    {
        exp2 = exp2 + ceil(e1 * 1.0 / 9 + 21);
        if (exp2 > 600) exp2 = 600;
        else if (exp2 < 0) exp2 = 0; 

    }
     else if (e1 >= 50 && e1 <= 65)
    {
        exp2 = exp2 + ceil(e1 * 1.0 / 16 + 17);
        if (exp2 > 600) exp2 = 600;
        else if (exp2 < 0) exp2 = 0; 
    }
      else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = exp2 + ceil(e1 * 1.0 / 4 + 19);
        if (exp2 > 600) exp2 = 600;
        else if (exp2 < 0) exp2 = 0; 
        if (exp2 > 200) exp2 += ceil(e1 * 1.0 / 9 + 21);
    }
     else if (e1 >= 80 && e1 <= 99)
    {
        exp2 = ceil(exp2 + e1 * 1.0 / 4 + 19);
        exp2 = ceil(exp2 + e1 * 1.0 / 9 +21 );
        if (exp2 > 600) exp2 = 600;
        else if (exp2 < 0) exp2 = 0; 
        if (exp2 > 400)
        {
            exp2 = exp2 + ceil(e1 * 1.0 / 16 + 17);
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0; 
            exp2 = ceil(exp2 + 0.15 * exp2);
            if (exp2 > 600) exp2 = 600;
            else if (exp2 < 0) exp2 = 0; 
        }
    }
    exp1 -= e1; 
    }
    if (exp1 > 600) exp1 = 600;
    else if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    else if (exp2 < 0) exp2 = 0; 
    return exp1 + exp2;
}

// Task 2
// check Square_number
bool Check_SqrN(int n)
{
    int x= sqrt(n);
    return (x*x == n);
}
// Dem so chu so
int count_Num(int n)
{
    int count=0;
    while (n != 0)
    {
        n /= 10;
        count ++;
    }
    return count;
}

//-------
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    // TODO: Complete this function
    if (E2 < 0  || E2 > 99) {return -99;}
    // Con duong 1
    int A,B,S;
    A=B=EXP1;
    while (A > 0 && B< 600)
    {
        if (Check_SqrN(A))
        {
            S=A;
            break;
        }
        else if (Check_SqrN(B))
        {
            S=B;
            break;
        }
        A--;
        B++;
    }
    double P1;
    if (EXP1 >= S) P1=1.0;
    else P1 = ((EXP1 / S + 80) * 1.0 / 123);
   
    // Con duong 2
    int Money=0.5*M1;
if ( E2 % 2 !=0 )
{
       int paid_money=0; 
       while ( E2 % 2 != 0)
    {
        // TH1
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 + HP1 * 0.3);
            M1 -= 150;
            paid_money += 150;
            if(HP1 > 666) HP1 = 666;
            else if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        else 
        {
            HP1 = ceil(HP1 + HP1 * 0.1);
            M1 -= 70;
            paid_money += 70;
            if(HP1 > 666) HP1 = 666;
            else if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        if (paid_money > Money) break;

        // TH2
        if ( EXP1 < 400)
        {
            M1 -= 200;
            paid_money += 200;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        else 
        {
            M1 -= 120;
            paid_money += 120;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
    
        }
        EXP1 = ceil(EXP1 + EXP1 * 0.13);
        if(EXP1 > 600) EXP1 = 600;
        else if(EXP1 < 0) EXP1 = 0;
        if (paid_money > Money) break;

        // TH3 
        if (EXP1 < 300)
        {
            M1 -= 100;
            paid_money += 100;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        else 
        {
            M1 -= 120;
            paid_money += 120;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        EXP1 = ceil(EXP1 - EXP1 * 0.1);
        if(EXP1 > 600) EXP1 = 600;
        else if(EXP1 < 0) EXP1 = 0;
        if (paid_money > Money) break;
    } 
    HP1 = ceil(HP1 - HP1 * 0.17);
    EXP1 = ceil(EXP1 + EXP1 * 0.17);
    if(HP1 > 666) HP1 = 666;
    else if(HP1 < 0) HP1 = 0;
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;
}
    else if (E2 % 2 == 0)
    {
        // Thuc hien lan luot 3 hanh dong 1 lan
        while (E2 % 2 == 0)
        {
           // TH1
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 + HP1 * 0.3);
            M1 -= 150;
            if(HP1 > 666) HP1 = 666;
            else if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        else 
        {
            HP1 = ceil(HP1 + HP1 * 0.1);
            M1 -= 70;
            if(HP1 > 666) HP1 = 666;
            else if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        if(M1 == 0) break;


        // TH2
        if ( EXP1 < 400)
        {
            M1 -= 200;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        else 
        {
            M1 -= 120;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
    
        }
        EXP1 = ceil(EXP1 + EXP1 * 0.13);
        if(EXP1 > 600) EXP1 = 600;
        else if(EXP1 < 0) EXP1 = 0;
        if(M1 == 0) break;

        // TH3 
        if (EXP1 < 300)
        {
            M1 -= 100;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        else 
        {
            M1 -= 120;
            if(M1 > 3000) M1 = 3000;
            else if(M1 < 0) M1 = 0;
        }
        EXP1 = ceil(EXP1 - EXP1 * 0.1);
        if(EXP1 > 600) EXP1 = 600;
        else if(EXP1 < 0) EXP1 = 0;
        if(M1 == 0) break;
        break;
        }
        HP1 = ceil(HP1 - HP1*0.17);
        EXP1 = ceil(EXP1 + EXP1*0.17);
        if(HP1 > 666) HP1 = 666;
        else if(HP1 < 0) HP1 = 0;
        if(EXP1 > 600) EXP1 = 600;
        else if(EXP1 < 0) EXP1 = 0;

    }
    
    // Tinh P2
    A=B=EXP1;
    while (A > 0 && B< 600)
    {
        if (Check_SqrN(A))
        {
            S=A;
            break;
        }
        else if (Check_SqrN(B))
        {
            S=B;
            break;
        }
        A--;
        B++;
    }
    double P2;
    if (EXP1 >= S) P2=1.0;
    else P2 = ((EXP1 / S + 80) * 1.0 / 123);
    // Con duong 3
    int P[10] = {32,47,28,79,100,50,22,83,64,11};
    int i;
    int count = count_Num(E2);
    if (count==1) i=E2;
    else if (count==2)
    {
        int sum=0;
        while (E2>0)
        {
            sum += E2%10;
            E2/=10;
        }
        i= sum % 10;
    }
    double P3=P[i] * 1.0 / 100;
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(EXP1*0.75);
    else 
    {
        double P_avr= (P1+P2+P3)/3;
        if (P_avr < 0.5)
        {
            HP1= ceil(HP1 - HP1*0.15);
            EXP1= ceil(EXP1 + EXP1*0.15);
            if(HP1 > 666) HP1 = 666;
            else if(HP1 < 0) HP1 = 0;
            if(EXP1 > 600) EXP1 = 600;
            else if(EXP1 < 0) EXP1 = 0;
        }
        else if (P_avr >= 0.5)
        {
            HP1= ceil(HP1 - HP1*0.1);
            EXP1= ceil(EXP1 + EXP1*0.2);
            if(HP1 > 666) HP1 = 666;
            else if(HP1 < 0) HP1 = 0;
            if(EXP1 > 600) EXP1 = 600;
            else if(EXP1 < 0) EXP1 = 0;
        }
    }
    if(HP1 > 666) HP1 = 666;
    else if(HP1 < 0) HP1 = 0;
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;
    if(M1 > 3000) M1 = 3000;
    else if(M1 < 0) M1 = 0;
    return HP1 + EXP1 + M1;
}

// Task 3
// Tinh tong so chu so
int sumdigits( int n )
{
    int sum=0;
    while ( n>0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

// Tim i va j
int find(int n )
{
    if (n >=0 && n <= 99)
    {
        if (n <10)
        {
            return n;
        }
        else 
        {
            int sum = sumdigits(n);
            while (sum >=10)
            {
                sum = sumdigits(sum);
            }
            return sum;
        }
    }
    else
    {
        return -1;
    }
}
// Tim max duong cheo trai pahi
// Tim max cheo trai phai

    int maxVal(int matrix[10][10], int i, int j , int target )
    {
        int maxValLeft = target;
        int temp1, temp2;
        temp1 = i - 1 ; temp2 = j - 1;
        while (temp1 >= 0 && temp2 >= 0)
        {    
            if (matrix[temp1][temp2] > maxValLeft)
            maxValLeft = matrix[temp1][temp2];
        temp1--;
        temp2--;
        }
        
        temp1 = i + 1 ; temp2 = j + 1;
        while(temp1 < 10 && temp2 < 10)
        {
            if (matrix[temp1][temp2] > maxValLeft)
            maxValLeft = matrix[temp1][temp2];
        temp1++;
        temp2++;
        }
        
        int maxValRight = target;
        temp1 = i - 1; temp2 = j+1;
        while (temp1 >=0 && temp2 <10)
        {
            if (matrix[temp1][temp2] > maxValRight)
            maxValRight=matrix[temp1][temp2];
            temp1--;
            temp2++;
        }
        
        temp1 = i + 1; temp2 = j - 1;
        while (temp1 <10 && temp2 >=0)
        {
            if (matrix[temp1][temp2]>maxValRight)
            maxValRight=matrix[temp1][temp2];;
        temp1++;
        temp2--;
        } 
        int MaxVal=max(maxValLeft,maxValRight);
        return MaxVal;
    }


int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0  || E3 > 99) {return -99;}

    // Tao ma tran
    int matrix[10][10]={0};
    for (int i=0 ; i < 10 ; i++)
    {
        for (int j=0 ; j < 10 ; j++)
        {
            matrix[i][j]=((E3*j)+ (i*2))*(i-j);
        }    
    }
    int count_positive = 0 , count_neg = 0;
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            if(matrix[i][j] > (E3 * 2)) count_positive++;
            if(matrix[i][j] <(-E3)) count_neg++;
        }
    }

    // Tim diem gap
    int i = find(count_positive);
    int j = find(count_neg);
    
// Diem cua Sherlock va Waston
    int Point=maxVal(matrix , i, j , matrix[i][j]);
    
    int max;
    // So sanh diem
     int TaxiPoint=matrix[i][j];
    if (abs(TaxiPoint) > Point)
    {
        max = TaxiPoint;
        EXP1 = ceil(EXP1 - EXP1*0.12);
        EXP2 = ceil(EXP2 - EXP2*0.12);
        HP1 = ceil(HP1 - HP1*0.1);
        HP2 = ceil(HP2 - HP2*0.1);
        
    }
    else 
    {
        max = Point;
        EXP1 = ceil(EXP1 + EXP1 * 0.12);
        EXP2 = ceil(EXP2 + EXP2 * 0.12);
        HP1 = ceil(HP1 + HP1 * 0.1);
        HP2 = ceil(HP2 + HP2 * 0.1);
    }
    if(HP1 > 666) HP1 = 666;
    else if(HP1 < 0) HP1 = 0;
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;
     if(HP2 > 666) HP2 = 666;
    else if(HP2 < 0) HP2 = 0;
    if(EXP2 > 600) EXP2 = 600;
    else if(EXP2 < 0) EXP2 = 0;
   
   
    return max;
}

// Task 4
  int CheckPass(string s, string email)
    {
        int position = email.find("@"); // tìm vị trí @
        string se = email.substr(0,position); // tạo (se) là chuỗi kí tự trước @ trong email
        //Kiểm tra email có đúng 1 @
        int NumberAt=0;
        for (int i=0 ; i < email.length() ; i++ )
            {   
                char c = email[i];
                if (c=='@')
                NumberAt++;
                if (NumberAt >=2) return i;
            }
         //Kiểm tra chiều dài email
        if (  email.length() > 100 || email.length() < 1) return 0;

        
        //Kiểm tra tính hợp lệ của pass (s)
            if (s.length() > 20) 
            {
            return -2;
            } 
            else if (s.length() < 8) {
            return -1;
            }
        
        //Kiểm tra se có trong s hay ko 
        if (s.find(se) != string::npos)
        {
            int a = -(300 + s.find(se));
            return a;
        }

        //Kiểm tra mk có chữ nhiều hơn 2 ký tự liên tiếp hay không
        for (int i=0 ; i < s.length() - 1 ; i++)
            { 
                if (s[i] == s[i + 1] && s[i] == s[i + 2])
                    {
                        return -(400+i);
                    }
            }
        
        //Kiểm tra ký tự đặc biệt
        string special_chars = "@#$%!";
        bool has_special = false;
        for (char c : s) 
        {
        if (special_chars.find(c) != string::npos) 
        {
            has_special = true;
            break;
        }
        }
        if (!has_special) {
        return -5;
        }
    // check lai
       for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (!(isupper(s[i]) || islower(s[i]) || isdigit(s[i])) && c != '@' && c != '!' && c != '%' && c != '$' && c != '#') {
            return i;
        }
        }
        return -10;
    }


int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
     
    int result = CheckPass(string(s), string(email));
    return result;
}

// Task 5
struct Mangphu
    {
        int Appearance;
        int Length;
        int Position;
    };
    
int CorrectPass (string arr[], int NumOfPass)
    {
        Mangphu arr1[NumOfPass];
        int Max_Appearance = 0;
        int Max_length = 0;
        int First_position = NumOfPass; // chua xet
        string PassWord = " ";
        
        for (int i = 0; i < NumOfPass ; i++)
            {
                arr1[i].Appearance = 0;
                arr1[i].Length = arr[i].length();
                arr1[i].Position = -99;
            }
            
        for (int i = 0 ; i < NumOfPass ; i++)
            {   
                int count = 0;
                count++;
                if (arr1[i].Position=-99)
                    {  
                        arr1[i].Position = i;
                    }
                for (int k = i + 1 ; k < NumOfPass ; k++)
                    { 
                        if (arr[i] == arr[k])
                            { 
                                count ++;
                                arr1[k].Position = i;
                            }
                    }
                arr1[i].Appearance = count;
            }
        
        for (int i = 0 ; i < NumOfPass ; i++)
            { 
                if (arr1[i].Appearance > Max_Appearance || (arr1[i].Appearance == Max_Appearance && arr1[i].Length > Max_length) || (arr1[i].Appearance == Max_Appearance && arr1[i].Length > Max_length && arr1[i].Position < First_position))
                    {
                        Max_length = arr1[i].Length;
                        Max_Appearance = arr1[i].Appearance;
                        PassWord = arr[i];
                        First_position = arr1[i].Position;
                    }
            }
        return First_position;
    }
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        arr[i] = arr_pwds[i];
    }
    int Position = CorrectPass(arr, num_pwds);
    return Position;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////