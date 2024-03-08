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

      // exp1 chi co kinh nghiem cua Sherlock
      // exp2 chi so kinh nghiem cua Watson
      // E1 chi so bieu dien su kien 1
      // ket qua tra ve so nguyen la tong Exp cua sherlock va Watson
int firstcase_meet(int &EXP1,int &EXP2 ,int E1) 
{
  int D = 0;
    switch(E1) {
      case 0: 
      EXP2 = EXP2 + 29;
      break;

    case 1: 
    EXP2 = EXP2 + 45;
    break;

    case 2: 
    EXP2 = EXP2 + 75;
    break;

    case 3: 
    EXP2 = EXP2 + 29 + 45 + 75;
    break;

    default: 
    break;
}
  
      D = E1*3 + EXP1*7;
      if(D%2==0) 
      {
          
          EXP1 = ceil(EXP1+(float)D/200);
          if(EXP1>600) EXP1 = 600;
         if(EXP1<0)  EXP1 = 0;
      }
      else 
      {
        EXP1 =  ceil((EXP1 - (float)D/100));
        if(EXP1<0) EXP1 = 0;
        if(EXP1>600) EXP1 = 600;
        
      }
      int a[2] = {EXP1,EXP2};
      for(int i=0;i<2;i++) 
      {
        if(i==0)
        {
          if(a[i]>600) EXP1 = 600;
          if(a[i]<0) EXP1 = 0;
        }
        if(i==1)
        {
          if(a[i]>600) EXP2 = 600;
          if(a[i]<0) EXP2 = 0;
        }
      }
      return EXP1 + EXP2;
      
}

int secondcase_meet(int &EXP1,int &EXP2 ,int E1) 
{
  if(EXP2>600) 
  {
    EXP2 = 600;
  }
  else 
  {
    if(EXP2<0) EXP2 = 0;
  }
  
     if(E1<=19) // case1
     {
       // update exp of Watson
      EXP2 = ceil(EXP2+(float)E1/4 + 19);
       if(EXP2>600) 
  {
    EXP2 = 600;
  }
  else 
  {
    if(EXP2<0) EXP2 = 0;
  }
      
      
     }

     if(E1>=20 && E1<=49)  // case 2  
     {
       if(EXP2>600) 
      {
    EXP2 = 600;
      }
  else 
        {
    if(EXP2<0) EXP2 = 0;
        }
      EXP2 = ceil(EXP2 + (float)E1/9 + 21);
       
     
     }

    if(E1>=50 && E1<=65)  // case3
    {
      if(EXP2>600) 
         {
    EXP2 = 600;
      }
  else 
  {
    if(EXP2<0) EXP2 = 0;
  }
      EXP2 = ceil(EXP2 + float(E1)/16 + 17);
    
    }

    if(E1>=66 && E1<=79)  // case4
    {
      if(EXP2>600) 
     {
    EXP2 = 600;
     }
  else 
     {
      if(EXP2<0) EXP2 = 0;
     }
     EXP2 = ceil(EXP2+(float)E1/4 + 19);
      if(EXP2>600) 
     {
    EXP2 = 600;
     }
  else 
     {
      if(EXP2<0) EXP2 = 0;
     }
         
      if(EXP2>200)
      {
        EXP2 = EXP2 + (E1/9) + 21;
        EXP2 = ceil(EXP2);
        if(EXP2>600) 
     {
    EXP2 = 600;
     }
  else 
     {
      if(EXP2<0) EXP2 = 0;
     }
      }
      
    }
    if(E1>=80 && E1<=99)   // case 5
       {
         if(EXP2>600) 
      {
    EXP2 = 600;
         }
  else 
      {
    if(EXP2<0) EXP2 = 0;
      }
        if(EXP2<0) EXP2 = 0;
            EXP2 = ceil(EXP2+(float)E1/4 + 19);
             if(EXP2>600) 
      {
    EXP2 = 600;
         }
  else 
      {
    if(EXP2<0) EXP2 = 0;
      }
           
            EXP2 = ceil(EXP2 + (float)E1/9 + 21);
             if(EXP2>600) 
      {
    EXP2 = 600;
         }
  else 
      {
    if(EXP2<0) EXP2 = 0;
      }
           
           if(EXP2>400)
           {
             EXP2 = ceil(EXP2 + (float)E1/16 + 17);
              if(EXP2>600) 
      {
    EXP2 = 600;
         }
  else 
      {
    if(EXP2<0) EXP2 = 0;
      }
             EXP2 = ceil(EXP2 + (float)EXP2*0.15);
              if(EXP2>600) 
      {
    EXP2 = 600;
         }
  else 
      {
    if(EXP2<0) EXP2 = 0;
      }

           }
       }
       EXP1 -= E1;
       int a[2] = {EXP1,EXP2};
      for(int i=0;i<2;i++) 
      { 
        if(i==0) {
        if(a[i]<0) EXP1 = 0;
        if(a[i]>600) EXP1 = 600;
        }
        if(i==1) 
        {
          if(a[i]<0) EXP2 = 0;
          if(a[i]>600) EXP2 = 600;
        }
      }
       return EXP1 + EXP2;
}
int firstMeet(int &EXP1,int &EXP2 ,int E1) 
{   
   int a[2] = {EXP1,EXP2};
   for(int i=0;i<2;i++) 
      {
        if(i==0) 
       {
        if(a[i]<0) EXP1 = 0;
        if(a[i]>600) EXP1 = 600;
        }
        if(i==1) 
        {
        if(a[i]<0) EXP2 = 0;
        if(a[i]>600) EXP2 = 600;
        }
      }
    if(E1>=0 && E1<=3) {
        return firstcase_meet(EXP1,EXP2,E1);
     }
     if(E1>3 && E1<=99) 
     {
        return secondcase_meet(EXP1,EXP2,E1);

     }
     return -99;
}

// bai 2 truy tim hanh ly
// start
 // HP1 chi so suc khoe cua Sherlock
 // EXP1  kinh nghiem cua Sherlock
 // M1  so tien cua sherlock
 // E2 su kien E2 
 // ket qua tra ve HP1 + EXP1 + M1
 bool checkSquareNum(int S) 
 {
     int check = 0;
  while(check*check <= S){
        if(check*check == S){
            return true;
        }
        ++check;
    }
    return false;
}
 float firstRoad(int &EXP1) 
 { 
  int S;
  int min = 601;
  if(EXP1>600) EXP1 = 600;
  if(EXP1<0) EXP1 = 0;
  
    for(int i=0;i<=600;i++)
    {  
       if(checkSquareNum(i)) 
       {    
            if(i == EXP1) continue;
            int temp = abs(EXP1 - i);
            if(temp<min) 
            {
              min = temp;
              S = i;
            }
       }
    }
   
    if(EXP1>= S) return 1;
    return ((float)EXP1/S + 80)/123;
 }
 void oddNumber (int &HP1, int & EXP1 , int &M1,int E2 )
  {
    int check = M1/2;
    int index = 0;
    while(M1>=check) 
    {
      switch(index)
      {
        case 0:
        if(HP1<200) 
        {
          HP1 = ceil((float)HP1*1.3);
           if(HP1>666) HP1 = 666;
          if(HP1<0)  HP1 = 0;
          M1 = M1 - 150;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        else
        {
          HP1 = ceil((float)HP1*1.1);
           if(HP1>666) HP1 = 666;
          if(HP1<0)  HP1 = 0;
          M1 = M1 - 70;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        index++;
        break;

        case 1:
        if(EXP1<400)
        {
          M1 = M1 - 200;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        else 
        {
          M1 = M1 - 120;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        EXP1 = ceil((float)EXP1*1.13);
        index++;
        break;
        
        case 2:
        if(EXP1<300) {
          M1 = M1 - 100;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        else 
        {
          M1 = M1 - 120;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        EXP1 = ceil( (float)EXP1*0.9 );
        
        index++;
        break;

        default:
         index = 0;
         break;
      }
    }
    HP1 = ceil( (float)HP1*0.83);
    EXP1 = ceil((float)EXP1*1.17);
    int a[2] = {HP1,EXP1};
    for(int i=0;i<2;i++)
    {
      if(i==0)
      {
        if(a[i]>666) HP1 = 666;
        if(a[i]<0) HP1 = 0; 
      }
      if(i==1) 
      {
        if(a[i]>600) EXP1 = 600;
        if(a[i]<0)  EXP1 = 0;
      } 
    }
  }
void evenNumber(int &HP1, int &EXP1, int &M1, int E2)
{ 
  int index = 0;
     while(M1>0) 
    {
      switch(index)
      {
        case 0:
        if(HP1<200) 
        {
          HP1 = ceil((float)HP1*1.3);
          if(HP1>666) HP1 = 666;
          if(HP1<0)  HP1 = 0;
          M1 = M1 - 150;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        else
        {
          HP1 = ceil((float)HP1*1.1);
          if(HP1>666) HP1 = 666;
          if(HP1<0)  HP1 = 0;
          M1 = M1 - 70;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        index++;
        break;

        case 1:
        if(EXP1<400)
        {
          M1 = M1 - 200;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        else
        {
        M1 = M1 - 120;
        if(M1<0) M1 = 0;
        if(M1>3000) M1 = 3000;
        }
         
        EXP1 = ceil((float)EXP1*1.13);
         if(EXP1>600) EXP1 = 600;
         if(EXP1<0)  EXP1 = 0;
        index++;
        break;
        
        case 2:
        if(EXP1<300) {
          M1 = M1 - 100;
          if(M1<0) M1 = 0;
        if(M1>3000) M1 = 3000;
        }
        else 
        {
          M1 = M1 - 120;
          if(M1<0) M1 = 0;
          if(M1>3000) M1 = 3000;
        }
        EXP1 = ceil( (float)EXP1*0.9 );
        if(EXP1>600) EXP1 = 600;
         if(EXP1<0)  EXP1 = 0;
        index++;
        break;

        default:
         break;
      }
      if(index > 2) break;
      
    }
    HP1 = ceil((float)HP1*0.83);
    EXP1 = ceil( (float)EXP1*1.17);
    int a[3] = {HP1,EXP1,M1};
    for(int i=0;i<2;i++)
    {
      if(i==0) 
      {
        if(a[i]>666) HP1 = 666;
        if(a[i]<0) HP1 = 0; 
      }
      if(i==1) 
      {
        if(a[i]>600) EXP1 = 600;
        if(a[i]<0)  EXP1 = 0;
      } 
      if(i==2)
      {
        if(a[i]>3000) M1 = 3000;
        if(a[i]<0) M1 = 0;
      }
    }
  }


 float secondRoad(int &HP1, int &EXP1, int &M1, int E2)
 {
    
    if(E2%2!=0)
    {
       oddNumber(HP1,EXP1,M1,E2);
    }
    else evenNumber(HP1,EXP1,M1,E2);
    return firstRoad(EXP1);
 }
 float thirdRoad(int &HP1, int &EXP1, int &M1, int E2)
 {  
    int i = 0;
    float a[10] = {32,47,28,79,100,50,22,83,64,11};
    if(E2 == E2%10) i = E2;
    else 
    {
      int sum = 0;
      int temp = E2;
      for(int index=0;index<2;index++)
      {
         sum += temp%10;
         temp = temp/10;
         
      }
      i = sum%10;
    }
    return a[i-1]/100;

 }
 int traceLuggage(int &HP1, int & EXP1 , int &M1,int E2) {
  
  
     

     float P1 = firstRoad(EXP1);
     float P2 = secondRoad(HP1,EXP1,M1,E2);
     float P3 = thirdRoad(HP1,EXP1,M1,E2);
     
     if(P1==1 && P2==1 && P3==1) EXP1 = ceil((float)EXP1*0.75);
     else 
     {
      float P = (P1+P2+P3)/3;
      if(P<0.5) 
      {
        HP1 = ceil((float)HP1*0.85);
        EXP1 = ceil((float)EXP1 * 1.15);    
      }
      if(P>=0.5) 
      {
        HP1 = ceil((float)HP1*0.9);
        EXP1 = ceil((float)EXP1 * 1.2);
      }

     }
     int a[3] = {HP1,EXP1,M1};
     for(int i=0;i<2;i++)
    {
      if(i==0) 
      {
        if(a[i]>666) HP1 = 666;
        if(a[i]<0) HP1 = 0; 
      }
      if(i==1) 
      {
        if(a[i]>600) EXP1 = 600;
        if(a[i]<0)  EXP1 = 0;
      } 
      if(i==2) 
      {
        if(a[i]>3000) M1 = 3000;
        if(a[i]<0) M1 = 0;
      }
    }
     return HP1 + EXP1 + M1;
  }
  // bai 3 chase Taxi
  // bao gom HP1 , EXP1
  // HP2 , EXP2
  // Ma Su Kien E3
  // khai bao 1 ma tran 10x10
  // gia tri cua tung vi tri la diem so ky nang cua chiec xe taxi do tai vi tri do
  // diem so cua Sherlock va Watson bang max cua cheo trai va cheo phai cua taxi di qua diem do
  // neu diem so la am lay gia tri tuyet doi
  bool checkcatchTaxi(int road[][10],pair<int,int> &cor,int &point_taxi,int &point_Sher)
  {
     point_taxi = road[cor.first][cor.second];
     point_Sher = INT_MIN;
    for (int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++) 
      {
        int temp = abs(cor.first-i);
        if(abs(j-cor.second)==temp)
        {
          if(road[i][j]>point_Sher) point_Sher = road[i][j];
        }
      }
    }
    if(abs(point_taxi)> abs(point_Sher)) return false; // khong bat duoc
    return true; // bat duoc


  }
  void findcordinate(int road[][10],int E3,pair<int,int> &cor) // find cordinate
  {
    int x = 0;
    int y = 0;
    
    for(int i=0;i<10;i++) 
    {
      for(int j=0;j<10;j++)
      {
        if(road[i][j]>(E3*2)) x++;
        if(road[i][j]<(-E3)) y++;
      }
    }
    while(x>=10 ) 
    { 
      int temp = 0;   // x = 37
                         // temp = 7;
      temp = x%10;
      x = x/10 + temp;   // x =3 
    }
    while(y>=10)
    {
      int temp = 0;
      temp = y%10;
      y = y/10 + temp; 
    }                            // tao 1 bien max co gia tri nho nhat int max = INT_MIN;
                              // (0,0) diem cua taxi la(1,8)
                              // (i,j) taxi(i1,j1)
                              // i cach thang i1 = 1-0 = 1 don vi  
                             // j cach thang j1 8 don vi 
    cor.first = x;
    cor.second = y;

  }
  int chaseTaxi(int &HP1, int &EXP1 ,int &HP2, int &EXP2, int E3)
  {
    int road[10][10];
    for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++) 
      {
        road[i][j] = (((E3*j) + (i*2))*(i-j));
        
        
      }
      
      
    }
    pair <int,int> cor;
    findcordinate(road,E3,cor);
    int point_taxi;
    int point_Sher;
    if(checkcatchTaxi(road,cor,point_taxi,point_Sher))
    {
      EXP1 = ceil((float)EXP1*1.12);
      EXP2 = ceil((float)EXP2*1.12);
      HP1 = ceil((float)HP1*1.1);
      HP2 = ceil((float)HP2*1.1);
    }
    else 
    {
      EXP1 = ceil((float)EXP1*0.88);
      EXP2 = ceil((float)EXP2*0.88);
      HP1 = ceil((float)HP1*0.9);
      HP2 = ceil((float)HP2*0.9);
    }
    int a[4] = {EXP1,EXP2,HP1,HP2};
   
    for(int i=0;i<4;i++)
    {
      if(i==0)
     {
       if(a[i]>600) EXP1 = 600;
       if(a[i]<0) EXP1 = 0;
     }
     if(i==1)
     {
      if(a[i]>600) EXP2 = 600;
      if(a[i]<0) EXP2 = 0;
     }
     if(i==2)
     {
       if(a[i]>666) HP1 = 666;
       if(a[i]<0) HP1 = 0;
     }
     if(i==3)
     {
       if(a[i]>666) HP2 = 666;
       if(a[i]<0) HP2 = 0;
     }
    }
    if(abs(point_taxi)>abs(point_Sher)) return point_taxi;
    return point_Sher;
  }
  //task 4
  // kiem tra password
  //start
int checkLegit(string se,string s)
{
   int check = 1;
   while (check<=4) {
   switch(check)
   {
    case 1: {
    
      if(s.length()<8)
      {  
        
        return -1;
      }
      if(s.length()>20)
      {
        return -2;
      }
      break;
    }

      case 2: {
      
      if(s.find(se)!=string :: npos)
      { 
        int sei = -1;
        for(int i=0;i<s.length();i++)
        {
             if(s[i] == se[0])
             {
              sei = i;
              break;
             }
        }
        return -(300+sei);
      }
      break;
      }

      case 3: {
      
      int count = 1;
      int first = -1;
      for(int i=0;i<s.length();i++)
      { 
        if(s[i]==s[i-1]) 
       { 
         first = i-1;
         count++;
       }
       else 
       {
        if(count<=2) count = 1;
        else break;
       }
       }
       if(count >2) return -(400+first-(count-2));
       break;
      }

      case 4: {
      int checkSpecial = 0;
      int firstillegal = -1;
      for (int i = 0; i < s.length(); i++) {
    if (97 <= s[i] && s[i] <= 122) {
        continue;
    }
    if (48 <= s[i] && s[i] <= 57) {
        continue;
    }
    if (65 <= s[i] && s[i] <= 90) {
        continue;
    }
    if (35 <= s[i] && s[i] <= 37 || s[i] == 33 || s[i] == 64) {
        checkSpecial += 1;
        continue;
    }
    if(firstillegal ==-1) firstillegal = i;
      }
      if(checkSpecial==0) return -5;
      if(firstillegal!=-1) return firstillegal;
      break;
      }

      default:
      break;
   }
   check++;
}

return -10;
}
 int checkPassword(const char * s, const char * email)
  {
    
    string se;
    for(int i=0;i<strlen(email);i++)
    {
      if(email[i]=='@') break;
      se.push_back(email[i]);
    }
    int result = checkLegit(se,s);
    return result;
  }
  // task 5 
  // int find
 int finalresult(const char * arr_pwds[],string result,int num_pwds)  // pind the position of result , so this is final result
  {
    int finalresult;
    for(int i=0;i<num_pwds;i++)
    {
      if(arr_pwds[i]==result) 
      {
        finalresult = i;
        break;
      }
    }
    return finalresult;
  }
  string result(int b[],int max,int num_pwds,string store[])   // fin result
  {
     string result;
     int countdigits = 0;
     for(int i=0;i<num_pwds;i++)
     {
         if(b[i]==max) 
         {   
            if(countdigits == 0) 
            {
              result = store[i];
              continue;
            }
            countdigits = store[i].length();
            if(result.length()<countdigits)  result = store[i];
         }
     }
     return result;
  }
  int countelementmax(const char * arr_pwds[],string store[],int num_pwds,int b[])  // count and find max 
  {
    
     for(int i=0;i<num_pwds;i++)
     {
      for(int j=0;j<num_pwds;j++) 
      {
        if(arr_pwds[j]==store[i]) b[i]++;
      }
     }
     
     int max = 0;
     for(int i=0;i<num_pwds;i++)
     {
      if(b[i]>max) max = b[i];  
     }
     return max;


  }
  int findCorrectPassword(const char * arr_pwds[],int num_pwds)
  {
    // declare a array that store different element
    string store[num_pwds];
    int b[num_pwds] = {0}; // create a array to count different element
    for(int i=0;i<num_pwds;i++)
    { 
      bool check = true;
      for(int j=0;j<num_pwds;j++)
      {
        if(arr_pwds[i]==store[j]) 
        {
         check = false;
         break;
        }
      }
      if(check) store[i] = arr_pwds[i];
    }
    
     int max = countelementmax(arr_pwds,store,num_pwds,b);
     
     string final = result(b,max,num_pwds,store);
     
     return finalresult(arr_pwds,final,num_pwds);
  }

      
      



  
  




