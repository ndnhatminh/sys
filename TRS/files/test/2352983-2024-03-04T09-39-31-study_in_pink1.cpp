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
//////////////////////////////////////////////////////////////////////////
//Make sure that HP,EXP, M is rounded up immediately.
void reset_total(int &HP, int&EXP, int&M)
{
  //Reset value
  if(HP>666)
   HP=666;
  else if(HP<0)
   HP=0;  

  if(EXP>600)
   EXP=600;
  else if(EXP<0)
   EXP=0;  

  if(M>3000)
   M=3000;
  else if (M<0)
   M=0;
  
  return;
}

void reset_HP(int &HP)
{
  if(HP>666)
   HP=666;
  else if(HP<0)
   HP=0;

  return; 
}

void reset_EXP(int &EXP)
{
  if(EXP>600)
   EXP=600;
  else if(EXP<0)
   EXP=0; 

  return;
}

void reset_M(int &M)
{
  if(M>3000)
   M=3000;
  else if (M<0)
   M=0;
}

bool overspend(int spend, int money)
{
  if(spend>money)
   return true;
  else
   return false;
}

void calculate_exp1(int &e1, int &exp1)
{
   int d=e1*3 + exp1*7;
    if(d%2==0)
     exp1=exp1 + double(d)/200+0.99999; //Fix like this
    else
     exp1=exp1 - double(d)/100+0.99999;
}

void calculate2_exp1(int &e1, int &exp1)
{
    exp1=exp1-e1;
}

// Function to check if a number is a perfect square
bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return n == root * root;
}

// Function to find the nearest perfect square of a number
int nearestPerfectSquare(int num) {
    if (num <= 0) // Handling non-positive numbers
        return 0;

    int lower = num - 1;
    int higher = num + 1;

    while (true) {
        if (isPerfectSquare(lower))
            return lower;
        else if (isPerfectSquare(higher))
            return higher;

        lower--;
        higher++;
    }

    // Unreachable code, but added to suppress compiler warning
    return 0;
}


int largerNum(int arr[10][10], int num)
{
  int count=0;
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
     if(arr[i][j]>num)
      count++;
  }
  return count;
}

int smallerNum(int arr[10][10], int num)
{
  int count=0;
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
     if(arr[i][j]<num)
      count++;
  }
  return count;
}

int max_left_diagional(int arr[10][10], int x,int y)
{
  int r=x;
  int c=y;
  int max=arr[r][c];

  while(r>=0 && c>=0)
  {   
    //cout<<arr[r][c]<<" ";
    if(arr[r][c]>max)
     max=arr[r][c];

    r--;
    c--; 
  }
  //cout<<"\n";
  r=x;
  c=y;

  while(r<10 && c<10)
  {    
    //cout<<arr[r][c]<<" ";
    if(arr[r][c]>max)
     max=arr[r][c];

    r++;
    c++;      
  }
  //cout<<"\n";  
  return max;
}

int max_right_diagonal(int arr[10][10], int x,int y)
{
  int r=x;
  int c=y;
  int max=arr[x][y];

  while(r>=0 && c<10)
  {
    if(arr[r][c]>max)
     max=arr[r][c];

    r--;
    c++; 
  }
  
  r=x;
  c=y;

  while(r<10 && c>=0)
  {
    if(arr[r][c]>max)
     max=arr[r][c];

    r++;
    c--;  
  }
  return max;
}

bool check_subString(string original, string subset)
{
  int length=original.length();
  int length_2=subset.length();
  int pos=0;
  
  if( subset.length()==0)
   return true;
   
  for(int i=0;i<length;i++)
  {
    if(original[i]==subset[pos])
      {
        if((length-i-1)<length_2-1)
         return false;
        else
        {
           //cout<<i<<" "<<length_2-1<<"\n";
           for(int j=i;j<=i+length_2-1;j++) 
           {
               if(original[j]!=subset[pos])
                 break;
               else
                pos++;
           }  
           //cout<<pos<<"\n";      
           if(pos==length_2)
            return true;  
           else
            pos=0;           
        }
      }    
  }
  return false;
}

int check_pos_subString(string original, string subset)
{
  int length=original.length();
  int length_2=subset.length();
  int pos=0;
  
  if(subset.length()==0)
   return 0;

  for(int i=0;i<length;i++)
  {
    if(original[i]==subset[pos])
      {
        if((length-i-1)<length_2-1)
         return false;
        else
        {
           //cout<<i<<" "<<length_2-1<<"\n";
           for(int j=i;j<=i+length_2-1;j++) 
           {
               if(original[j]!=subset[pos])
                 break;
               else
                pos++;
           }  
           //cout<<pos<<"\n";      
           if(pos==length_2)
            return i;
           else
            pos=0;           
        }
      }    
  }
  return -1;//Not possible code
}

bool check_repeatedString(string original)
{
  int length=original.length();
  for(int i=0;i<length;i++)
  {
    if(original[i+1]==original[i] && original[i]==original[i-1]) //String has at least 3 characters
     return true;
  }
  return false;
}

int check_pos_repeatedString(string original)
{
  int length=original.length();
  for(int i=0;i<length;i++)
  {
    if(original[i+1]==original[i] && original[i]==original[i-1])
     return i-1;
  }
  return -1;
}

bool check_specialString(string original)
{
  int length=original.length();
  for(int i=0;i<length;i++) 
  {
     if(original[i]=='@')
      return true;
     else if(original[i]=='#')
      return true;
     else if(original[i]=='%')
      return true;
     else if(original[i]=='$')
      return true;
     else if(original[i]=='!')
      return true;
  }
  return false;
}

bool check_validString(string original)
{
  int length=original.length();
  for(int i=0;i<length;i++)
  {
    if((int)original[i]>=97 && (int)original[i]<=122)
     continue;
    else if((int)original[i]>=65 && (int)original[i]<=90)
     continue;
    else if((int)original[i]>=48 && (int)original[i]<=57)
     continue;
    else if((int)original[i]== 64 || (int)original[i]==35 || (int)original[i]==37 || (int)original[i]==36 || (int)original[i]==33)
     continue;
    else
     return false;
  }
  return true;
}

int check_pos_validString(string original)
{
  int length=original.length();
  for(int i=0;i<length;i++)
   {
    if((int)original[i]>=97 && (int)original[i]<=122)
     continue;
    else if((int)original[i]>=65 && (int)original[i]<=90)
     continue;
    else if((int)original[i]>=48 && (int)original[i]<=57)
     continue;
    else if((int)original[i]== 64 || (int)original[i]==35 || (int)original[i]==37 || (int)original[i]==36 || (int)original[i]==33)
     continue;
    else
     return i;   
   }
   return -1;   
}

int repeatedPass(string arr[], int length, string pass)
{
  int count=0;
  for(int i=0;i<length;i++)
  {
    if(pass==arr[i])
      count++;     
  }
  return count;
}

void sort2Darr_max(int arr[][3],int col,int length) //Used for sorting frequency
{
  for(int i=0;i<length;i++)
  {
    for(int j=i+1;j<length;j++)
     {
       if(arr[i][col]<arr[j][col])
        {
          swap(arr[i][0],arr[j][0]);
          swap(arr[i][1],arr[j][1]);
          swap(arr[i][2],arr[j][2]);
        }
     }
  }
  return;
}

void sort2Darr_max_2(int arr[][3],int col,int length) //Used for sorting length
{
  int pos;
  for(int i=0;i<length;i++)
  {
    if(arr[i+1][0]!=arr[i][0])
     {
       pos=i;
       break;
     }
  }
  
  for(int i=0;i<=pos;i++) //Sort length elements
  {
    for(int j=i+1;j<=pos;j++)
    {
      if(arr[i][col]<arr[j][col])
        {
          swap(arr[i][0],arr[j][0]);
          swap(arr[i][1],arr[j][1]);
          swap(arr[i][2],arr[j][2]);
        }
    }
  }
  return;
}

void sort2Darr_min_3(int arr[][3],int col,int length) //Sort index
{
  int pos;
  int pos_2;
  for(int i=0;i<length;i++)
  {
    if(arr[i+1][0]!=arr[i][0])
     {
       pos=i;
       break;
     }
  }
   
   for(int i=0;i<length;i++)
   {
     if(arr[i+1][1]!=arr[i][1])
     {
       pos_2=i;
       break;
     }
   }

   pos=min(pos,pos_2);
   for(int i=0;i<=pos;i++)
   {
     for(int j=i+1;j<=pos;j++)
     {
        if(arr[i][col]>arr[j][col])
        {
          swap(arr[i][0],arr[j][0]);
          swap(arr[i][1],arr[j][1]);
          swap(arr[i][2],arr[j][2]);
        }
     }
   } 
  return;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

     if(!(e1>=0 && e1<=99)) //Stop code
      return -99;

    // TODO: Complete this function
    //EXP1: Sherlock
    //EXP2: Watson
    reset_EXP(exp1);
    reset_EXP(exp2);

    if (e1==0){
        exp2+=29;
        calculate_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);

    if (e1==1)
    {
        exp2+=45;
        calculate_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);

    if (e1==2)
    {
        exp2+=75;
        calculate_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);

    if (e1==3)
    {
        exp2+=29;
        exp2+=45;
        exp2+=75;   
        calculate_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);

    if (e1>=4 && e1<=19)
    {
      exp2=exp2+double(e1)/4+19+0.99999;
      calculate2_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);

    if (e1>=20 && e1<=49)
    {
      //cout<<"entered"<<"\n";
      exp2=exp2+double(e1)/9+21+0.99999;
      calculate2_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);

    if (e1>=50 && e1<=65)
    {
      exp2=exp2+double(e1)/16+17 +0.99999;
      calculate2_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);
    //cout<<"The value of EXP2 is: "<<exp2<<"\n";

    if (e1>=66 && e1<=79)
    {
      exp2=exp2+double(e1)/4+19+0.99999;
      if(exp2>200)
       exp2=exp2+double(e1)/9+21+0.99999;
       calculate2_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);

    if (e1>=80 && e1<=99)
    {
      exp2=exp2+double(e1)/4+19+0.99999;
      exp2=exp2+double(e1)/9+21+0.99999;

      if(exp2>400) 
      {
        exp2=exp2+double(e1)/16+17+0.99999;
        exp2=exp2+double(exp2)/100*15+0.99999;
      }
      calculate2_exp1(e1,exp1);
    }
    reset_EXP(exp1);
    reset_EXP(exp2);    

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int left=EXP1;
    int right=EXP1;
    double P1,P2,P3;
    int arr[10]={32,47,28,79,100,50,22,83,64,11};
    bool check_1,check_2;
    int money=M1/2;
    int spend=0;        
    int S=nearestPerfectSquare(EXP1);
    
    if(!(E2>=0 && E2<=99)) //Stop code
      return -99;

  //Calculate P1
    if(EXP1>=S)
     P1=1;
    else
     P1=double(double(EXP1)/S+80)/123;
    //cout<<"Money is: "<<money<<"\n";

    if(E2%2!=0)
    {
      while(spend<=money)
      {
        if(HP1<200)
        {
         HP1=double(HP1+double(0.3*HP1))+0.9999;
         spend+=150;
         M1-=150;
        }
        else
        {
           HP1=double(HP1+double(0.1*HP1))+0.9999;
           spend+=70;
           M1-=70;
        }
        //cout<<"HP1 is "<<HP1<<"\n";
        //cout<<"Spend money is: "<<spend<<"\n";
        //cout<<"EXP1 is "<<EXP1<<"\n";
        reset_total(HP1,EXP1,M1);
        
        if(overspend(spend,money)==true)
         break;
        

        if(EXP1<400)
        {
          spend+=200; //Choose to take a taxi
          M1-=200;    
        }
        else
        {
          spend+=120; //Choose to go by horse
          M1-=120; 
        }
        

        reset_total(HP1,EXP1,M1);
        EXP1=double(EXP1+double(double(EXP1*13)/100))+0.9999;
        reset_total(HP1,EXP1,M1);

        if(overspend(spend,money)==true)
         break;
        //cout<<"HP1 2 is "<<HP1<<"\n";
        //cout<<"Spend money 2 is: "<<spend<<"\n";
        //cout<<"EXP1 2 is "<<EXP1<<"\n";        

        if(EXP1>300)
        {
            spend+=120;
            M1-=120;                     
        }
        else
        {
            spend+=100;
            M1-=100;
        }        

        reset_total(HP1,EXP1,M1);
        EXP1=double(EXP1-double(0.1*EXP1))+0.9999;        
        reset_total(HP1,EXP1,M1);

        if(overspend(spend,money)==true)
         break;
        //cout<<"HP1 3 is "<<HP1<<"\n";
        //cout<<"Spend money 3 is: "<<spend<<"\n";
        //cout<<"EXP1 3 is "<<EXP1<<"\n";        
      }
      //cout<<"Total spend money: "<<spend<<"\n";
    }
    else
    {
      if(M1>=0)
      {
        if(HP1<200)
        {
         HP1=double(HP1+double(0.3*HP1))+0.9999;
         spend+=150;
         M1-=150;        
        }
        else
        {
           HP1=double(HP1+double(0.1*HP1))+0.9999;
           spend+=70;
           M1-=70;           
        }
        reset_HP(HP1);
        reset_EXP(EXP1);
      }       

      if(M1>=0)
      {
        if(EXP1<400)
        {
          spend+=200; //Choose to take a taxi
          M1-=200;    
        }
        else
        {
          spend+=120; //Choose to go by horse
          M1-=120; 
        }
        reset_HP(HP1);
        reset_EXP(EXP1);

        EXP1=EXP1+double(double(EXP1*13)/100)+0.9999;

        reset_HP(HP1);
        reset_EXP(EXP1);
      }
       
      if(M1>=0)
      {
        if(EXP1>300)
        {
            spend+=120;
            M1-=120;                     
        }
        else
        {
            spend+=100;
            M1-=100;
        }
        reset_HP(HP1);
        reset_EXP(EXP1);

        EXP1=double(EXP1-double(0.1*EXP1))+0.9999;
        
        reset_HP(HP1);
        reset_EXP(EXP1);
      }        
    }
    reset_total(HP1,EXP1,M1);
    HP1=double(HP1*0.83)+0.9999;
    EXP1=double(EXP1*1.17)+0.9999;
    reset_total(HP1,EXP1,M1);
    //cout<<"HP1 value after road 2: "<<HP1<<"\n";
    //cout<<"EXP1 value after road 2: "<<EXP1<<"\n";

    S=nearestPerfectSquare(EXP1);
    if(EXP1>=S)
     P2=1;
    else
     P2=double(double(EXP1)/S+80)/123;
    
    //cout<<"The value of HP1, EXP1, P2: ";
    //cout<<HP1<<" "<<EXP1<<" "<<P2<<"\n";

    if(E2<10)
      P3=arr[E2];
    else
    {
      int sum=0;
      sum+=int(E2)%10;
      //cout<<"The sum is: "<<sum<<"\n";
      
      sum+=(int(E2)/10)%10;
      E2*10;
      
      //cout<<"The sum is: "<<sum<<"\n";
      if(sum<10)
       P3=arr[sum];
      else      
       P3=arr[sum%10];      
    } 
    P3=P3/100;

    if(P1==1 && P2==1 && P3==1)
    {
      EXP1=double(double(EXP1)*0.75)+0.9999;
      reset_total(HP1,EXP1,M1);
    }
    else
    {
      reset_total(HP1,EXP1,M1);
      double average_probs;

       average_probs=(P1+P2+P3)/3;
    //cout<<"P1 P2 P3 are: "<<P1<<" "<<P2<<" "<<P3<<"\n";
    //out<<"Final probability is: "<<average_probs<<"\n";
    //cout<<"HP1 EXP1 M1 are: "<<HP1<<" "<<EXP1<<" "<<M1<<"\n";

      if(average_probs<0.5)
     {
      HP1=double(double(HP1)*0.85)+0.9999;
      EXP1=double(double(EXP1)*1.15)+0.9999;
     }
     else
     {
      HP1=double(double(HP1)*0.9)+0.9999;
      EXP1=double(double(EXP1)*1.2)+0.9999;
     }
     reset_total(HP1,EXP1,M1);
     //cout<<"HP1 EXP1 M1 are: "<<HP1<<" "<<EXP1<<" "<<M1<<"\n";
    }
      
    
    return HP1 + EXP1 + M1;
} 


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(!(E3>=0 && E3<=99)) //Stop code
      return -99;
    
    int arr[10][10];
    int pos_r;
    int pos_c;
    int sum=0;
    int taxi;
    int score;
    //int diagonal_1,diagonal_2;

    for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
       arr[i][j]=(((E3*j)+(i*2))*(i-j));
    }
    
    pos_r=largerNum(arr,E3*2);
    pos_c=smallerNum(arr,-E3);
    //cout<<"Pos r, pos c initial: "<<pos_r<<" "<<pos_c<<"\n";

    if(pos_r>=10)
    {
      while(pos_r>=10)
      {
        sum=pos_r%10 +(pos_r/10)%10;
      
        if(sum<10)
          {
            pos_r=sum;
            break;
          }
        else
         pos_r=sum;                  
      }     
    }
    
    sum=0;
    if(pos_c>=10)
    {
      while(pos_c>=10)
      {
        sum=pos_c%10 +(pos_c/10)%10;
      
        if(sum<10)
          {
            pos_c=sum;
            break;
          }
        else
         pos_c=sum; 
      }
    }
   // cout<<"Pos r, pos c after: "<<pos_r<<" "<<pos_c<<"\n";

    taxi=arr[pos_r][pos_c];
    score=max(max_left_diagional(arr,pos_r,pos_c),max_right_diagonal(arr,pos_r,pos_c));
    
    //cout<<max_left_diagional(arr,pos_r,pos_c)<<" ";
    //cout<<max_right_diagonal(arr,pos_r,pos_c);
    

    if(abs(taxi)>abs(score))
     {
       EXP1=EXP1-double(EXP1*0.12)+0.9999;
       EXP2=EXP2-double(EXP2*0.12)+0.9999;

       HP1=HP1-double(HP1*0.1)+0.9999;
       HP2=HP2-double(HP2*0.1)+0.9999;
     }
     else
     {
       EXP1=EXP1+double(EXP1*0.12)+0.9999;
       EXP2=EXP2+double(EXP2*0.12)+0.9999;

       HP1=HP1+double(HP1*0.1)+0.9999;
       HP2=HP2+double(HP2*0.1)+0.9999; 
     }
    reset_HP(HP1);
    reset_HP(HP2);
    reset_EXP(EXP1);
    reset_EXP(EXP2);

    if(abs(taxi)>score)
     return taxi;
    else
     return score;
    
    //cout<<"entered";
    return -1; //Never reach this code
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // TODO: Complete this function
    string se;
    int length_2=strlen(email);
    for(int i=0;i<length_2;i++)
    {
      if(email[i]=='@')
       {
         for(int j=0;j<i;j++)
          se+=email[j];
       }       
    }    

    int length=strlen(s);
    if(!(length>=8 && length<=20))
     {
       if(length<8)
        return -1;
       else if(length>20)
        return -2;        
     }
    
    //cout<<se.length();
    if(check_subString(s,se)==true)
     return -(300+check_pos_subString(s,se));
    
      
    
    
    if(check_repeatedString(s)==true)    
     return -(400+check_pos_repeatedString(s)); 
     

    if(check_specialString(s)==false)
     return -5;

    if(check_validString(s)==false)
     return check_pos_validString(s);

    return -10; //Valid password


    return -99; //Backup option  
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    string pass[num_pwds]; //Convert const char* to string
    int arr[num_pwds][3];
    //First col: Frequency
    //Second col: length
    //Third col: Index
     for(int i=0;i<num_pwds;i++)
      pass[i]=arr_pwds[i];

    for(int i=0;i<num_pwds;i++)
    {
      arr[i][0]=repeatedPass(pass,num_pwds,pass[i]);
      arr[i][1]=pass[i].length();
      arr[i][2]=i;
    }
    
    sort2Darr_max(arr,0,num_pwds); //Sort frequency
    sort2Darr_max_2(arr,1,num_pwds); //Sort length
    sort2Darr_min_3(arr,2,num_pwds); //Sort index
    
    //for(int i=0;i<num_pwds;i++)
    //cout<<arr[i][0] <<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<"\n";

    return arr[0][2];

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

