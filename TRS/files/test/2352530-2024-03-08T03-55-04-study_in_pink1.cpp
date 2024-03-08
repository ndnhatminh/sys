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
////////////////////////////////////////////////////////////////////////
int ktra_hp(int hp){
    if(hp<0 ){
        hp =0;
    }
    if(hp > 666){
        hp = 666;
    }
    return hp;
}
int ktra_exp(int exp){
    if(exp <0){
        exp = 0;
    }
   if(exp > 600){
        exp = 600;
    }
    return exp;
}
int ktra_m(int m){
    if(m > 3000){m=3000;}
   if(m<0){m=0;}
    return m;
}


// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1)
{
    //TODO: implement task
   EXP1 = ktra_exp(EXP1);
    EXP2 = ktra_exp(EXP2);
     if(E1 < 0 || E1 > 99)
     {return -99;}
    if(E1 >= 0 && E1 <=3 )
    {
       switch (E1)
       {
       case 0:
        EXP2 = EXP2+29;
       
        break;
       case 1:
        EXP2 = EXP2+45;
        
        break;
        case 2:
        EXP2= EXP2+75;
        break;
       case 3:
        EXP2 = EXP2+29+45+75;
        
        break;
       }
         float result = EXP1;
    int d = E1 * 3 + EXP1 * 7;
     switch (d % 2){
        case 0:
            result = EXP1 + d/200.0;
            EXP1 = ktra_exp(EXP1);
            break;
        case 1:
            result = EXP1 - d/100.0;
            EXP1 = ktra_exp(EXP1);
            break;
    }
   EXP1 = ceil(result);EXP1 = ktra_exp(EXP1);
    } 
    ////////////////////////////TH2//////////////////
       else if(E1<=99){
    if (E1 >= 4 && E1 <= 19) {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));
    } else if (E1 <= 49) {
        EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0));
    } else if (E1 <= 65) {
       EXP2 = ceil((EXP2 + (E1 / 16.0 + 17.0)) );
    } else if (E1 <= 79) {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));
        if (EXP2 > 200) {
            EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0));
        }
    } else if (E1 <= 99) {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19.0));
        EXP2 = ceil(EXP2 + (E1 / 9.0 + 21.0));
    

    EXP2 = ktra_exp(EXP2);

    if (EXP2 > 400) {
        EXP2= ceil((EXP2 + (E1 / 16.0 + 17.0)));
        EXP2 = ktra_exp(EXP2);
        EXP2 = ceil(EXP2 * 1.15);
    }}
     

   
    EXP1 = ceil( EXP1 - E1);
    
} EXP1=ktra_exp(EXP1);
EXP2 = ktra_exp(EXP2);
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
     /*===================================ROAD 1=====================================*/
     EXP1 = ktra_exp(EXP1);
     HP1 = ktra_hp(HP1);
     M1 = ktra_m(M1);
     if(E2 < 0 || E2 > 99)
     {cout << -99;
     return -99;}
     //////////////
    float p1;
    int s = 0;
    for (int i = 0; i <= 25; i++) {
        s = i * i;
        if (s >= EXP1) 
         break; 
    }

    if (abs(pow(sqrt(s) - 1, 2) - EXP1) < abs(pow(sqrt(s), 2) - EXP1) || s == EXP1) {
        p1 = 1.0;
    } else {
        p1 = (float(EXP1) / float(s) + 80.0) / 123.0;
    }
    /*=====================================ROAD 2============================================*/
   float hfmn = M1 *0.5;
   int M=0;
    float p2;
             if(E2%2 != 0)
    {   for(int i = 0; i < 100 ; i++){
        if(M1==0) break;
        if(HP1<200)
                   {HP1= ceil( HP1*0.3 + HP1);
                    M += 150;
                    M1 -= 150;}
        else{
                HP1 = ceil( HP1*0.1 + HP1);
                M += 70; M1-=70;
                }
                HP1 = ktra_hp(HP1);
                if(M > hfmn)
        {
                break;
        }
        if(EXP1 >= 400 )
                {
                M += 120; M1-=120;
                EXP1 = ceil( EXP1*0.13+EXP1);
                }
        else {M += 200; M1-=200;
                EXP1 = ceil( EXP1 * 0.13 + EXP1);}
                EXP1 = ktra_exp(EXP1);
                if(M > hfmn)
        {
                break;
        }
        if(EXP1 < 300)
                {
                        M+=100; M1-= 100;
                        EXP1 = ceil(EXP1 - EXP1*0.1);
                }
        else { M+=120;M1-=120; EXP1 = ceil(EXP1 - EXP1*0.1);}
        EXP1 = ktra_exp(EXP1);
        if(M> hfmn )
        {
                break;
        }

    }
       HP1=  ceil( HP1 - HP1*0.17); HP1 = ktra_hp(HP1);
        EXP1 = ceil( EXP1 + EXP1* 0.17); EXP1 = ktra_exp(EXP1);

    }
            else
    { //E chan  
		do
		{
			
			if (HP1 < 200)//1
			{
				HP1 = ceil(HP1*13.0/10);
				M1 -= 150;
			}
			else 
			{
				HP1 = ceil(HP1*11.0/10);
				M1 -= 70; 
			}
			HP1 = ktra_hp(HP1);
			if ( M1 <= 0 ) break;
		
			
			if (EXP1 < 400)//2
			{
				M1 -= 200;
			}
			else 
			{
				M1 -= 120;
			}
			EXP1 = ceil(EXP1*113.0/100); EXP1 = ktra_exp(EXP1);
			if ( M1 <= 0 ) break;
			
		
			if (EXP1 < 300)//3
			{
				M1 -= 100;
			}
			else 
			{
				M1 -= 120;
			}
			EXP1 = ceil(EXP1*9.0/10); 
			if ( M1 <= 0 ) break;
		
		}
		while(0); 
         HP1=  ceil( HP1*83.0/100);
        EXP1 = ceil( EXP1*117.0/100); 
    EXP1 = ktra_exp(EXP1);
    HP1 = ktra_hp(HP1);
    }
    for (int i = 0; i <= 25; i++) {
        s = i * i;
        if (s >= EXP1) 
         break; 
    }

    if (abs(pow(sqrt(s) - 1, 2) - EXP1) < abs(pow(sqrt(s), 2) - EXP1) || s == EXP1) {
        p2 = 1.0;
    } else {
        p2 = (float(EXP1) / float(s) + 80.0) / 123.0;
    }
    /*======================ROAD 3==========================================*/
     int i = 0;
    int p3[]=  {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
   int tong = 0;
    
    if(E2 <10){
        i = E2;
    }
    else{
        tong = tong + E2 % 10;
        E2 /= 10;
        tong = tong + E2;
        i = tong % 10;   }
    double p = p3[i] *0.01;
    double T = (p1 + p2 + p)/3.0;
        if (p1 == 1 && p2 ==1 && p == 1)
    {
        EXP1 = ceil(EXP1*75.0/100);
    }   else{
            if(T < 0.5){
                HP1 = ceil(HP1 *85.0/100);
                EXP1= ceil(EXP1 *115.0/100);
            }
            else{
                HP1 = ceil(HP1 *0.9);
                EXP1 = ceil(EXP1 *1.2);
            }
    }
     EXP1 = ktra_exp(EXP1);
     HP1 = ktra_hp(HP1);
     M1 = ktra_m(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
     EXP1 = ktra_exp(EXP1);
    HP1 = ktra_hp(HP1);
    EXP2 = ktra_exp(EXP2);
    HP2 = ktra_hp(HP2);
    if ( E3 > 99 || E3 < 0){
        cout << "-99";
        return -99;}
    int arrTaxi[10][10]={};
    int bd1 = 0;
    int bd2 = 0;
     for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            arrTaxi[i][j] = (i - j) * ((E3 * j)+ (i * 2));
     }
     }
      for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(arrTaxi[i][j]>(E3*2)) 
                {bd1 ++;}
            if(arrTaxi[i][j]<(-E3))
            {bd2 ++;}
     }
     }
     while(bd1/10 != 0)
     {int x=bd1%10;
     bd1/=10;
     bd1 = bd1 + x;}
    while(bd2/10 != 0)
     {int y=bd2%10;
     bd2/=10;
     bd2 = bd2 + y;}
int point_taxi = arrTaxi[bd1][bd2];
int point_sherlock = arrTaxi[bd1][bd2];
for(int a=0; a < 10 ; a++){
    if( bd1+a>9 || bd2+a>9){break;}
    if(arrTaxi[bd1+a][bd2+a]>point_sherlock)
    {point_sherlock = arrTaxi[bd1+a][bd2+a];}
}
for(int b=0; b < 10 ; b++){
    if( bd1-b<0 || bd2-b<0){break;}
    if(arrTaxi[bd1-b][bd2-b]>point_sherlock)
    {point_sherlock = arrTaxi[bd1-b][bd2-b];}
}
for(int c=0; c < 10 ; c++){
    if( bd1+c>9 || bd2-c<0){break;}
    if(arrTaxi[bd1+c][bd2-c]>point_sherlock)
    {point_sherlock = arrTaxi[bd1+c][bd2-c];}
}
for(int d=0; d < 10 ; d++){
    if( bd1-d<0 || bd2+d>9){break;}
    if(arrTaxi[bd1-d][bd2+d]>point_sherlock)
    {point_sherlock = arrTaxi[bd1-d][bd2+d];}
}
if (abs(point_sherlock) >= abs(point_taxi))
      {EXP1 = ceil(EXP1*112.0/100); EXP1 = ktra_exp(EXP1);
        HP1=ceil(HP1*11.0/10); HP1 = ktra_hp(HP1);
        EXP2 = ceil(EXP2*112.0/100);EXP2 = ktra_exp(EXP2);
        HP2=ceil(HP2*11.0/10); HP2 = ktra_hp(HP2);
        return point_sherlock;}
else{EXP1 = ceil(EXP1*88.0/100);EXP1 = ktra_exp(EXP1);
        HP1=ceil(HP1*9.0/10);HP1 = ktra_hp(HP1);
        EXP2 = ceil(EXP2*88.0/100);EXP2 = ktra_exp(EXP2);
        HP2=ceil(HP2*9.0/10);HP2 = ktra_hp(HP2);
        return point_taxi;}
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    //TODO: implement task
    
    ///////////////////////////////////////tim SE/////////////////////////////////////////////////////
    string email_1 = email;
    int a = email_1.find('@');
    int b = email_1.length() - a;
    string se = email_1.erase(a,b);
 
    ///////////////////////////////////////tim yeu cau/////////////////////////////////////////
    string s1 = s;
    if (s1.length() < 8) return -1;
	if ( s1.length() > 20) return -2;
    bool contains_se = (s1.find(se) != string::npos);
if (contains_se) {
    return -(300+s1.find(se));
} else {
   
}
for (int i = 0; i < s1.length() - 2; i++)
	{
		if (s1[i] == s1[i + 1] && s1[i] == s1[i + 2]) return -(400 + i);
	}
int specialchar = 0;
for (int i = 0; i < s1.length() ; i++)
	{
		
		if (s1[i] == '@' ||  s1[i] == '#' || s1[i] == '%' || s1[i] == '$' || s1[i] == '!' ) 
        specialchar+=1;
		
	}
	if (specialchar == 0 ) 
    {return -5;}
int j = 0;
while (j < s1.length()) {
    int a = s1[j];
    if (!((a >= 48 && a <= 57) || a == 33 || a == 35 || a == 37 || a == 36 || (a >= 64 && a <= 90) || (a >= 97 && a <= 122))) {
        return j;
    }
    j++;
}
return -10;
return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    int tansuat = 0;
    int dainhat=0;
    string matkhaudung = (" ");
    for(int i = 0; i < num_pwds; i++){
    int dodai = strlen(arr_pwds[i]);
    int dem=0;
       for(int j = 0; j < num_pwds; j++){
           if( i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0){
               dem++;
           }
       }
       if(tansuat < dem || dem == tansuat && dodai > dainhat){
           tansuat = dem;
           dainhat = dodai;
           matkhaudung = arr_pwds[i];
       }
    }
    for(int i = 0; i < num_pwds; i++){
        if(arr_pwds[i]==matkhaudung){
            return i; 
        }
    }
    
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////