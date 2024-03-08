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
int EXPlimit(int &a) { return a=min(max(0, a), 600); }
int HPlimit(int &a) { return a=min(max(0, a), 666); }
int Mlimit(int &a) { return a=min(max(0, a), 3000); }
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
   if (E1 < 0 || E1 > 99) return -99;
EXPlimit(EXP1);
EXPlimit(EXP2);

if (E1>=0 &&  E1<= 3) {
switch (E1)
        {
        case 0: { EXP2 += 29; break; }
        case 1: { EXP2 += 45; break; }
        case 2: { EXP2 += 75; break; }
        case 3: { EXP2 += 29 + 45 + 75; break;} 
        //default: EXP2 += (29 + 45 + 75);
        }
        int D = E1 * 3.0 + EXP1 * 7.0;
        if (D % 2 == 0) EXP1 = ceil(EXP1 + (D / 200.0));
        else EXP1 = ceil(EXP1 - (D / 100.0));
        EXPlimit(EXP1);
}
 else if (E1>=4 && E1<=99)
   {
      if(E1>=4 && E1<=19) EXP2 += ceil(E1/4.0 + 19.0 );
      else if (E1>=20 && E1<=49) EXP2 += ceil(E1/9.0 + 21.0 );
      else if(E1>=50 && E1<=65) EXP2+= ceil(E1/16.0 + 17.0);
      else if (E1>=66 && E1<=79) 
      {
        EXP2 += ceil( E1/4.0 + 19.0);
        if(EXP2>200) EXP2 += (ceil( E1/9.0) + 21.0);
      }
      else if (E1>=80 && E1<=99)
      {
        EXP2 += ceil(E1/4.0 + 19.0 + E1/9.0 + 21.0 );
        if(EXP2>400) EXP2 += ceil((EXP2 + E1/16.0 + 17.0)*(15.0 / 100.0));
      };
    if(EXP2>600) EXP2 = 600;
    EXP1 -= E1;

   }

    return EXP1 + EXP2;
}



// Task 2
int TimCP(int a)
{
    float sq = round(sqrt(a));
    return sq * sq;
}
    // TODO: Complete this function
float P;
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
//CON ĐƯỜNG 1
  int S = 0;
  S = TimCP(EXP1);
  EXPlimit(EXP1);
  if(EXP1>=S) P=100;
    else P=(((float)(EXP1/S) + 80)/123)*100;
//CON ĐƯỜNG 2
  int ra = 0, m1 = M1;
    float P2;
    do  
    {
        if(HP1<200) 
        {
        	HP1 = ceil(HP1+ HP1*0.3);
            M1 -= 150;
            ra += 150;
            if((m1*0.5)<=ra) {break;};
		}
		else
		{
			HP1 = ceil(HP1 + HP1 * 0.1);
			M1 -= 70;
			ra += 70;
            if((m1*0.5)<=ra) {break;};
		}
		if(EXP1<400) 
        {
            M1 -= 200;
            ra += 200;
            if((m1*0.5)<=ra) {break;};
        }
        else 
        {
            M1 -= 120;
            ra += 120;
            if((m1*0.5)<=ra) {break;};
        }
        EXP1 = ceil(EXP1+ EXP1 *0.13);
        
        if(EXP1<300) 
        {   
            M1 -= 100;
            ra += 100;
            if((m1*0.5)<=ra) {break;};
        }
        else 
        {
            M1 -= 120;
            ra += 120;
            if((m1*0.5)<=ra) {break;};
        }
    }
    while(E2%2==1&&((m1*0.5)>=ra));
           
		if(E2%2==1||M1==0)
    {
        HP1 = ceil(HP1 - (HP1 * 0.17));
        EXP1 = ceil(EXP1 + (EXP1 * 0.17));
        HPlimit(HP1);
        EXPlimit(EXP1);
    }
//GIỐNG CON ĐƯỜNG 1 
S = 0;
    EXPlimit(EXP1);
    S = TimCP(EXP1);
    if (EXP1 >= S) P2 = 100;
    else P2 = ((float)(EXP1/S +80)/123)*100;

//CON ĐƯỜNG 3
  int ar[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int digit1,digit2,sum;
        float P3;
    if (E2 >9)
    {
    digit1 = E2%10;
    digit2 = E2/10;
    sum = (digit1 + digit2)%10;
    P3 = ar[sum];
    }
     else P3 = ar[E2];

    //TONG KET
    float PAvg;
    if(P==P2&&P2==P3) 
    EXP1 = ceil(EXP1 - (EXP1 * 0.25));
    else
    {
        PAvg = (P + P2 + P3)/3;
        if(PAvg<50)
        {
            HP1 = ceil(HP1 - (HP1 * 0.15));
            EXP1 = ceil(EXP1 + (EXP1 * 0.15));
        }
        else 
        {
             HP1 = ceil(HP1 - (HP1 * 0.1));
            EXP1 = ceil(EXP1 + (EXP1 * 0.2));
        }
    }
    EXPlimit(EXP1); HPlimit(HP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
        // TẠO MAP
    int map[10][10]= {0};
    int numD = 0;
    int numA = 0;
    int sherlock_watson;
    int taxi;

    // Nhập giá trị vào mảng
     int i = 0;
    while (i < 10) {
    int j = 0;
    while (j < 10) {
        map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        j++;
    }
    i++;
}

// Đếm số giá trị lớn hơn E3*2 và nhỏ hơn -E3
    i = 0;
    while (i < 10) {
    int j = 0;
    while (j < 10) {
        if (map[i][j] > (E3 * 2)) numD += 1;
        else if (map[i][j] < (-1 * E3)) numA += 1;
        j++;
    }
    i++;
}

    
     // TINH DIEM SHERLOCK
     int k = 0;
    while (numD > 0 || k > 9) {
    if (numD == 0) {
        numD = k;
        k = 0;
    }
    k += numD % 10;
    numD /= 10;
}

     int l = 0;
    while (numA > 0 || l > 9) {
    if (numA == 0) {
        numA = l;
        l = 0;
    }
    l += numA % 10;
    numA /= 10;
}

  taxi = map[k][l];
// Tính đường chéo từ trái sang và từ phải sang
    int maxLeftDiagonal = 0;
    int maxRightDiagonal =0;
i = k;
int j = l;
while (i < 10 && j < 10) {
    maxLeftDiagonal = max(maxLeftDiagonal, map[i][j]);
    i++;
    j++;
}

i = k;
j = l;
while (i >= 0 && j >= 0) {
    maxLeftDiagonal = max(maxLeftDiagonal, map[i][j]);
    i--;
    j--;
}

i = k;
j = l;
while (i < 10 && j >= 0) {
    maxRightDiagonal = max(maxRightDiagonal, map[i][j]);
    i++;
    j--;
}

i = k;
j = l;
while (i >= 0 && j < 10) {
    maxRightDiagonal = max(maxRightDiagonal, map[i][j]);
    i--;
    j++;
}

sherlock_watson = max(maxLeftDiagonal, maxRightDiagonal);


    // SO DIEM CA HAI
    if (abs(taxi) < sherlock_watson) {
        HP1 = ceil(HP1 * 1.1);
        EXP1 = ceil(EXP1 * 1.12);
        HP2 = ceil(HP2 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);
        EXPlimit(EXP1);
        HPlimit(HP1) ;
        HPlimit(HP2);
        EXPlimit(EXP2);

        return sherlock_watson ;
    } else {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        EXPlimit(EXP1);
        HPlimit(HP1) ;
        HPlimit(HP2);
        EXPlimit(EXP2);

        return taxi;
        
    }
    return -1;
}   

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //PASS
    //EMAIL    
     string mail(email);
    string pass(s);
    int pos = mail.find('@');
    string se = mail.substr(0, pos);  
    //ĐỘ DÀI
    int length = pass.size();
    if (length < 8)
        return -1;
    
    if (length > 20) 
        return -2;
        
    //SE
     int findse = pass.find(se);
     if (pass.find(se) != string::npos) return -(300 + findse);
     
    //LẶP LẠI
    for (int i = 0; i < length - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i+1]) 
        {
            return -(400 + i);
        }
    }
    //KÍ TỰ ĐẶC BIỆT
       int len = pass.length();
      string special="@#%$!";
        for(int s = 0;s<=len;s++)
        {
            if (pass[s] == '@' || pass[s] == '#' || pass[s] == '%' || pass[s] == '$' || pass[s] == '!')  break;
            else return -5;
        }

    for (int s = 0; s <= len; s++) {
        if ((pass[s] < 'A' || pass[s] > 'Z') &&
            (pass[s] < 'a' || pass[s] > 'z') &&
            (pass[s] < '0' || pass[s] > '9')) {
                if (pass[s] != '@' && pass[s] != '#' && pass[s] != '%' && pass[s] != '$' && pass[s] != '!') return s;
        }
    }
    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr[num_pwds];
    int p = 0;
    while (p<num_pwds)
{
    arr[p] = arr_pwds[p];
    p++;
}
//Đếm số lần xuất hiện của mật khẩu
int max = 0;
int dedu;
string correct; 
    for (int i = 0; i < num_pwds; i++) 
    {
        int m = 0;
        for (int j = 0; j < num_pwds; j++) 
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
            {
                m += 1;
            }
        }
                if(m>max) 
                {
                    max = m;
                    correct = arr[i];
                    dedu = i;
                }
                else if (m==max)
                {
                    if (arr[dedu].size()<arr[i].size()) 
                    {
                     max = m;
                    correct = arr[i];
                    dedu = i;
                    }
                }
    }
        
    
    return dedu;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////