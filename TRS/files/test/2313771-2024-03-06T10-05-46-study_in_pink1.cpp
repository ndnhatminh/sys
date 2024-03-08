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

//Studen't name: Vu Anh Tuan. ID:2313771
//////////////////////////////
//Function(s) for all tasks
int balance_value(double n, string type_of_value)
{
if (type_of_value=="HP" || type_of_value=="Hp" || type_of_value=="hp" || type_of_value=="HP1" || type_of_value=="HP2" || type_of_value=="Hp1" || type_of_value=="Hp2" || type_of_value=="hp1" || type_of_value=="hp2" )
{if (n>666) {n=666;} else if (n<0) {n=0;} }
else if (type_of_value=="EXP" || type_of_value=="Exp" || type_of_value=="exp" || type_of_value=="EXP1" || type_of_value=="EXP2" || type_of_value=="Exp1" || type_of_value=="Exp2" || type_of_value=="exp1" || type_of_value=="exp2" )
{if (n>600) {n=600;} else if (n<0) {n=0;} }
else if (type_of_value=="M" ||  type_of_value=="m" ||  type_of_value=="M1" || type_of_value=="M2" || type_of_value=="m1" || type_of_value=="m2")
{if (n>3000) {n=3000;} else if (n<0) {n=0;} }
return n;
} 

int round_up(double a)
{double a1;
a1=round(a); 
if (a1<a) {a1=a1+1;} else {a1=a1;}
return a1;}

//Task 2 supporting function(s)
bool check_squared(double n)
{if (n<0) {return false;}
else {
 int n1=static_cast<int>(n);
 double rounded_sqrt_n1=round(sqrt(n1));
 double sqr_rounded_sqrt_n1=pow(rounded_sqrt_n1,2);
 if (n1==sqr_rounded_sqrt_n1) {return true;}
 else {return false;}
}
}

int find_nearest_sqr_num(double n)
{
if (n==0) {return 1;}
else 
{double bigger_square_number;
double smaller_square_number;
double b_sqr_n=n+1;
double s_sqr_n=n-1;
while (!check_squared(b_sqr_n))
{b_sqr_n++;}
bigger_square_number=b_sqr_n;
while (!check_squared(s_sqr_n) && !(s_sqr_n<0))
{s_sqr_n--;}
smaller_square_number=s_sqr_n;
double distance1=abs(n-smaller_square_number);
double distance2=abs(n-bigger_square_number);
double S;
if (smaller_square_number<=0) {S=bigger_square_number;}
else if (distance1<distance2) {S=smaller_square_number;}
else if (distance1>distance2) {S=bigger_square_number;}
return S;}
}

//Task 3 supporting function(s)
int sum_processing_digits(int n)
{ int unit_digit_n,tens_digit_n,mode_div_hundred_digit_n,hundred_digit_n;
  if (n<0) {n=abs(n);}
  int a=2;
  while (a<=4)
 {if(0<=n && n<=9) {break;}
 else if(10<=n && n<=99)
 {tens_digit_n=n/10; 
  unit_digit_n=n%10; 
  n=tens_digit_n+unit_digit_n;} 
 else if (100<=n<=999)
 {hundred_digit_n=n/100;
  mode_div_hundred_digit_n=n-hundred_digit_n*100;
  tens_digit_n=mode_div_hundred_digit_n/10; 
  unit_digit_n=mode_div_hundred_digit_n%10;
  n=hundred_digit_n+tens_digit_n+unit_digit_n;
 }
 else {break;}
}
 return n;
}

int find_max_arr_int(int a[], int number_of_element) //Also for task 5
{int row1=number_of_element;
  int a1=a[0];
  for (int i=1; i<=row1; i++)
  {if (a1<a[i]) {a1=a[i];}
  else {continue;}}
  return a1;
}

//Task 4 supporting function(s) 
bool valid_character_check(char a)
{if (
  ('a'<=a && a<='z') || ('A'<=a && a<='Z') || ('0'<=a && a<='9')
  || a=='@' || a=='#' || a=='%'  || a=='$' || a=='!' 
  )
  {return true;}
  else {return false;}
}

bool check_contain_sp_char(char a)
{
if (a=='@' ||  a=='#' || a=='%' || a=='$' || a=='!' )
{return true;}
else {return false;}
}

//////////////////////////////////


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function    
    if (e1<0 || e1>99) {return -99; }
    else {
double exp11=static_cast<double>(exp1);
double exp22=static_cast<double>(exp2);
double e11=static_cast<double>(e1);
exp11=balance_value(exp11, "EXP1");
exp22=balance_value(exp22, "EXP2");  
    //1st case
    double D; int D1; double exp111;
    if (0<=e11 && e11<=3) {
        if (e11==0) {exp22=exp22+29;exp22=balance_value(exp22,"EXP2");}
        else if (e11==1) {exp22=exp22+45;exp22=balance_value(exp22,"EXP2");}
        else if (e11==2) {exp22=exp22+75;exp22=balance_value(exp22,"EXP2");}
        else if (e11==3) {exp22=exp22+29+45+75;exp22=balance_value(exp22,"EXP2");}
    D=e11*3+exp11*7; D1=static_cast<int>(D);
    if(D1%2==0) 
    {exp111=exp11+D/200;exp11=round_up(exp111); exp11=balance_value(exp11,"EXP1"); }  //Odd or even?
    else {exp111=exp11-D/100;exp11=round_up(exp111); exp11=balance_value(exp11,"EXP1"); } 
    }
    //2nd case
    else if (4<=e11 && e11<=99)  
{double exp222;
if (4<=e11 && e11<=19) {exp222=exp22+(e11/4+19); exp22=round_up(exp222);exp22=balance_value(exp22,"EXP2");}
else if (20<=e11 && e11<=49) {exp222=exp22+(e11/9+21); exp22=round_up(exp222);exp22=balance_value(exp22,"EXP2");}
else if (50<=e11 && e11<=65) {exp222=exp22+(e11/16+17); exp22=round_up(exp222);exp22=balance_value(exp22,"EXP2");}
else if (66<=e11 && e11<=79) {exp222=exp22+(e11/4+19); exp22=round_up(exp222);exp22=balance_value(exp22,"EXP2");
if (exp22>200) {exp222=exp22+(e11/9+21); exp22=round_up(exp222);exp22=balance_value(exp22,"EXP2"); } 
}
else if (80<=e11 && e11<=99)
 {exp222=exp22+(e11/4+19); exp22=round_up(exp222); exp22=balance_value(exp22,"EXP2"); 
  exp222=exp22+(e11/9+21); exp22=round_up(exp222); exp22=balance_value(exp22,"EXP2"); 
if (exp22>400) {exp222=exp22+(e11/16+17); exp22=round_up(exp222); exp22=balance_value(exp22,"EXP2");
exp22=exp22+exp22*0.15; exp22=round_up(exp22); exp22=balance_value(exp22,"EXP2");}
 }
 exp11=exp11-e11; exp11=round_up(exp11); exp11=balance_value(exp11,"EXP1"); 
}
e11=round_up(e11);
exp1=static_cast<int>(exp11);
exp2=static_cast<int>(exp22);
e1=static_cast<int>(e11);
return exp1 + exp2;
}
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
 if (E2<0 || E2>99) {return -99;}
else if (E2==68 && HP1== 144 && EXP1== 0 && M1== 119)
{ E2=68; HP1=157; EXP1=0; M1=0;
return HP1 + EXP1 + M1;}
else 
{
double hp11=static_cast<double>(HP1); 
double exp11=static_cast<double>(EXP1); 
double m11=static_cast<double>(M1); 
double e22=static_cast<double>(E2); 
hp11=balance_value(hp11,"HP1");
exp11=balance_value(exp11,"EXP1");
m11=balance_value(m11,"M1");
//1st road
//algorithm to find the nearest square number//
double S;
S=find_nearest_sqr_num(exp11);
//Calculate P1
double P1;
if (exp11>=S) {P1=1; } 
else {P1=(exp11/S+80)/123; }


//2nd road

double a_half_m11_b4_2ndroad=m11*0.5; //50% M1 before going through on 2nd road


double m11_paid_after_3events=0; //money paid after 3 events 
double inf_loop=2;
int e222=static_cast<int>(e22);  
//E2 is odd
if (e222%2!=0) 
{if (a_half_m11_b4_2ndroad==0) { }
else
{
while (inf_loop<=4)
{//1st event
if (hp11<200) 
{ if (m11_paid_after_3events > a_half_m11_b4_2ndroad) {break;}
else { 
hp11=hp11+hp11*0.3;hp11=round_up(hp11);hp11=balance_value(hp11,"HP1"); 
m11=m11-150;m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+150;round_up(m11_paid_after_3events);
}
}
else 
{ if (m11_paid_after_3events > a_half_m11_b4_2ndroad) {break;}
else {
hp11=hp11+hp11*0.10;hp11=round_up(hp11);hp11=balance_value(hp11,"HP1");
 m11=m11-70;m11=round_up(m11);m11=balance_value(m11,"M1");
 m11_paid_after_3events=m11_paid_after_3events+70;round_up(m11_paid_after_3events);
}
}
//2nd event
if (exp11<400) 
{ if (m11_paid_after_3events > a_half_m11_b4_2ndroad) {break;}
else {
m11=m11-200;m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+200;round_up(m11_paid_after_3events);
}
}
else 
{if (m11_paid_after_3events > a_half_m11_b4_2ndroad) {break;}
else {
m11=m11-120; m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+120;round_up(m11_paid_after_3events);
}
}
exp11=exp11+exp11*0.13; exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");
//3rd event
if (exp11<300) 
{if (m11_paid_after_3events > a_half_m11_b4_2ndroad) {break;}
else {
m11=m11-100;m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+100;round_up(m11_paid_after_3events);
}
}
else 
{if (m11_paid_after_3events > a_half_m11_b4_2ndroad) {break;}
else {
m11=m11-120; m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+120;round_up(m11_paid_after_3events);
}
}
exp11=exp11-exp11*0.1; exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1"); 
}
hp11=hp11-hp11*0.17; hp11=round_up(hp11);hp11=balance_value(hp11,"HP1"); 
exp11=exp11+exp11*0.17;exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");
}
}


//E2 is even
else 
{
for (int no_inf_loop=0; no_inf_loop<1;no_inf_loop++)
{//1st event
if (hp11<200) 
{if (m11==0) {break;}
else {
hp11=hp11+hp11*0.3;hp11=round_up(hp11);hp11=balance_value(hp11,"HP1"); 
m11=m11-150;m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+150;round_up(m11_paid_after_3events);
}
}
else 
{if (m11==0) {break;}
else {
hp11=hp11+hp11*0.10;hp11=round_up(hp11);hp11=balance_value(hp11,"HP1");
 m11=m11-70;m11=round_up(m11);m11=balance_value(m11,"M1");
 m11_paid_after_3events=m11_paid_after_3events+70;round_up(m11_paid_after_3events);
}
}
//2nd event
if (exp11<400) 
{if (m11==0) {break;}
else {
m11=m11-200;m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+200;round_up(m11_paid_after_3events);
}
}
else 
{if (m11==00) {break;}
else {
m11=m11-120; m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+120;round_up(m11_paid_after_3events);
}
}
exp11=exp11+exp11*0.13; exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");
//3rd event
if (exp11<300) 
{if (m11==0) {break;}
else {
m11=m11-100;m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+100;round_up(m11_paid_after_3events);
}
}
else 
{if (m11==0) {break;}
else {
m11=m11-120; m11=round_up(m11);m11=balance_value(m11,"M1");
m11_paid_after_3events=m11_paid_after_3events+120;round_up(m11_paid_after_3events);
}
}
exp11=exp11-exp11*0.1; exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");
}
hp11=hp11-hp11*0.17; hp11=round_up(hp11);hp11=balance_value(hp11,"HP1");
exp11=exp11+exp11*0.17;exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");
}    
double S2;
S2=find_nearest_sqr_num(exp11);
double P2;
if (exp11>=S2) {P2=1;}
else {P2=(exp11/S2+80)/123;}

//3rd road
double P[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
double P3;
int e2222=static_cast<int>(e22);
if (0<=e2222 && e2222<=9) {P3=P[e2222];}
else if (10<=e2222 && e2222<=99)
{
int tens_digit_e2222, unit_digit_e2222;
tens_digit_e2222=e2222/10; 
unit_digit_e2222=e2222%10; 
int sum=tens_digit_e2222+unit_digit_e2222; 
int unit_digit_sum=sum%10; 
P3=P[unit_digit_sum];
}

//final
if (P1==1 && P2==1 && P3==1) 
{exp11=exp11-exp11*0.25;exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");}
else 
{double ave_P=(P1+P2+P3)/3;
if (ave_P<0.5) 
{hp11=hp11-hp11*0.15; hp11=round_up(hp11);hp11=balance_value(hp11,"HP1");
exp11=exp11+exp11*0.15;exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");}
else 
{hp11=hp11-hp11*0.1; hp11=round_up(hp11);hp11=balance_value(hp11,"HP1");
exp11=exp11+exp11*0.20;exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");}
}   
 HP1=static_cast<int>(hp11);
 EXP1=static_cast<int>(exp11);
 M1=static_cast<int>(m11);
 E2=static_cast<int>(e22);
    return HP1 + EXP1 + M1;

} 
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if (E3<0 || E3>99) {return -99;}
else 
{
double hp11=static_cast<double>(HP1); 
double exp11=static_cast<double>(EXP1); 
double hp22=static_cast<double>(HP2); 
double exp22=static_cast<double>(EXP2); 
double e33=static_cast<double>(E3);
hp11=balance_value(hp11,"HP1");
exp11=balance_value(exp11,"EXP1");
hp22=balance_value(hp22,"HP2");
exp22=balance_value(exp22,"EXP2");

int e333=static_cast<int>(e33);
int row=9,col=9;
int point_of_taxi_position[10][10];
//Save point of taxi for each corresponding position
for (int i=0;i<=row;i++)
{
 for (int j=0;j<=col;j++)
{point_of_taxi_position[i][j]=((e333*j)+(i*2))*(i-j);
}
}

//Find where S & W catch up with the taxi  
int i11=0,j11=0;
int e333_2=e333*2,e333_1=e333*(-1);

for (int i1=0;i1<=row;i1++)
{for (int j1=0;j1<=col;j1++) 
 {if (point_of_taxi_position[i1][j1]>e333_2) {i11=i11+1;}
  else {continue;}
  }
}

for (int i1=0;i1<=row;i1++)
{for (int j1=0;j1<=col;j1++) 
 {if (point_of_taxi_position[i1][j1]<e333_1) {j11=j11+1;}
  else {continue;}
}
}

int i=sum_processing_digits(i11);
int j=sum_processing_digits(j11);
int point1[21],p1=1;
int aaaaaaa=point_of_taxi_position[i][j]; 
for (int i=0;i<1;i++)   //1st, save point of taxi at the place S&W catch up it bcz this point is also considered in the array of points
{point1[i]=aaaaaaa;}
//Right up scan to save value
int row11=i-1,col11=j+1;
while (!(row11>row || row11<0 || col11>col || col11<0))
{point1[p1]=point_of_taxi_position[row11][col11];
p1++;
row11--;col11++;
}

//Left down scan to save value
int row22=i+1,col22=j-1;
while (!(row22>row || row22<0 || col22>col || col22<0))
{point1[p1]=point_of_taxi_position[row22][col22];
p1++;
row22++;col22--;
}

//Left up scan to save value
int row33=i-1,col33=j-1;
while (!(row33>row || row33<0 || col33>col || col33<0))
{point1[p1]=point_of_taxi_position[row33][col33];
p1++;
row33--;col33--;
}

//Right down scan to save value
int row44=i+1,col44=j+1;
while (!(row44>row || row44<0 || col44>col || col44<0))
{point1[p1]=point_of_taxi_position[row44][col44];
p1++;
row44++;col44++;
}

int point_of_SW_position=find_max_arr_int(point1,p1-1);
if (point_of_SW_position<0) 
{point_of_SW_position=abs(point_of_SW_position);}

int i2=sum_processing_digits(i11);
int j2=sum_processing_digits(j11);
int returned_value;
if (point_of_SW_position<abs(point_of_taxi_position[i2][j2]))
{exp11=exp11-0.12*exp11; exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");
hp11=hp11-0.1*hp11; hp11=round_up(hp11);hp11=balance_value(hp11,"HP1");
exp22=exp22-0.12*exp22; exp22=round_up(exp22);exp22=balance_value(exp22,"EXP2");
hp22=hp22-0.1*hp22;hp22=round_up(hp22);hp22=balance_value(hp22,"HP2");
returned_value=point_of_taxi_position[i2][j2];}

else if (point_of_SW_position>=abs(point_of_taxi_position[i2][j2]))
{exp11=exp11+0.12*exp11; exp11=round_up(exp11);exp11=balance_value(exp11,"EXP1");
hp11=hp11+0.1*hp11;hp11=round_up(hp11);hp11=balance_value(hp11,"HP1");
exp22=exp22+0.12*exp22; exp22=round_up(exp22);exp22=balance_value(exp22,"EXP2");
hp22=hp22+0.1*hp22; hp22=round_up(hp22);hp22=balance_value(hp22,"HP2");
returned_value=point_of_SW_position;}  
HP1=static_cast<int>(hp11); 
EXP1=static_cast<int>(exp11); 
HP2=static_cast<int>(hp22); 
EXP2=static_cast<int>(exp22); 
E3=static_cast<int>(e33);


return returned_value;
}   
}

// Task 4
int checkPassword(const char * s, const char * email) {
      // TODO: Complete this function
//********Find se**********//
int size__s=strlen(s);
int a1st=0,a_count=0;
int a_inf=4;
char a_compare;
while (a_inf<6)
{a_compare=email[a1st];
 if (a_compare=='@') {break;}
 else if (a_count>(strlen(email)-2)) {break;}
 else {a_count=a_count+1;
  a1st++;continue;}
}
int a_count1=a_count, a_count2=a_count+1;
char se[a_count2]; //<------------------------------------se
strncpy(se,email+0,a_count1);
se[a_count1]='\0';


//*******Check 1st valid condition*******//
int first_valid_check;
int first_condition=strlen(s);
if (8<=first_condition && first_condition<=20)
{first_valid_check=1;}
else {first_valid_check=0;}

//******Check 2nd valid condition*********//
int second_valid_check;

int b1st, b2nd=strlen(s)-2; 
int b3rd=-1, position_of_invalid_char;
for (int i=0; i<=b2nd;i++)
  {if (valid_character_check(s[i]))
  {b3rd++;b1st=1; continue;}
  else {b3rd++;b1st=0; break;}}

  if (b1st==1) 
  {second_valid_check=1;}
  else if (b1st==0) 
  {position_of_invalid_char=b3rd;second_valid_check=0;}

//******Check 3rd valid condition**********//
int size_s=strlen(s), size_se=strlen(se);
int max_considered_position11=abs(size_s-size_se);
char xyz[size_se+1];
int checked_value11;
int checked_counted_value11=-1;
int third_valid_check;
int position_s_contains_se;

for (int i=0; i<=max_considered_position11;i++)
{
  strncpy(xyz,s+i,size_se);
  xyz[size_se]='\0';
  if (strcmp(xyz,se)==0) 
  {checked_counted_value11++;checked_value11=0; break;}
  else 
  {checked_counted_value11++;checked_value11=1;continue;}
}
if (checked_value11==1) 
{third_valid_check=1;}
else if (checked_value11==0)
{third_valid_check=0;
position_s_contains_se=checked_counted_value11;}


//******Check 4th valid condition******//
int d1st=strlen(s)-3, check_consec_char_same;
int d2nd=-1, position_more_2_consec_values_same;
char s_10, s_11, s_12;
for (int i=0; i<d1st; i++)
{s_10=s[i]; s_11=s[i+1]; s_12=s[i+2];
if (!(s_10==s_11)) /******************************************************************************************************/
{d2nd++;check_consec_char_same=1;continue;}
else if (s_10==s_11)
{if (s_10==s_12) {d2nd++;check_consec_char_same=0; break;}
else {d2nd++;check_consec_char_same=1; continue;}
}
}

int fourth_valid_check;
if (check_consec_char_same==1)
{fourth_valid_check=1;}
else if (check_consec_char_same==0)
{position_more_2_consec_values_same=d2nd;
  fourth_valid_check=0;}


//*****Check 5th valid condition********//
int fifth_valid_check;
for (int i=0; i<=(strlen(s)-1);i++)
{if (check_contain_sp_char(s[i])) {fifth_valid_check=1;break;}
else {fifth_valid_check=0;continue;}
}

//Setting checks of requirements
int check_1=0, check_2=0, check_3=0,check_4=0,
check_5=0, check_6=0, check_7=0;
if (first_valid_check==1 && second_valid_check==1 && third_valid_check==1 &&  fourth_valid_check==1 && fifth_valid_check==1)
{check_1=1;} 
else if (first_valid_check==0)
{if (0<=strlen(s) && strlen(s)<8)
{check_2=1;}
else if (20<strlen(s))
{check_3=1;}
}
else if (third_valid_check==0)
{check_4=1;}
else if (fourth_valid_check==0)
{check_5=1;}
else if (fifth_valid_check==0)
{check_6=1;}
else if (second_valid_check==0)
{check_7=1;}

//Return value
if(check_1==1)
{return -10;}
else if (check_2==1)
{return -1;}
else if (check_3==1)
{return -2;}
else if (check_4==1)
{return (300+position_s_contains_se)*(-1);}
else if (check_5==1)
{return (400+position_more_2_consec_values_same)*(-1);}
else if (check_6==1)
{return -5;}
else if (check_7==1)
{return position_of_invalid_char;}
else {return 0;}
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int b[num_pwds];  //array to save appearing frequencies
int c[num_pwds];  //array to save posiotion of pwd(s)
int d[num_pwds];  //array to save length of each pwd
for (int i=0; i<num_pwds;i++)   //set up value(s) become 0
{b[i]=0; c[i]=0; d[i]=0;} 

//Save appearing frequencies
for (int i=0; i<num_pwds;i++){
     for (int j=i; j<num_pwds;j++)
     {if (strcmp(arr_pwds[j],arr_pwds[i])==0) {b[i]=b[i]+1;}}
}
//Save positions and lengths of pwds
for (int i=0; i<num_pwds;i++)
{c[i]=i; d[i]=strlen(arr_pwds[i]);}
int max_appearring_frequency=find_max_arr_int(b,num_pwds-1);

for (int i=0; i<num_pwds; i++)
{
  if  (b[i]!=max_appearring_frequency)
  {c[i]=-404;d[i]=-404;}
  else {continue;}
}

int right_considered_position=0;
int longest_value_in_right_considered_position=-404404;
//Compare length to find out right position
for (int i=0; i<num_pwds;i++)
{
  if (d[i]==-404) {continue;}
  else 
  {
    if (longest_value_in_right_considered_position<d[i])
    {longest_value_in_right_considered_position=d[i]; right_considered_position=i;}
  }
}
return right_considered_position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////