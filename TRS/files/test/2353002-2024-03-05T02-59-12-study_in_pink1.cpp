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
int testhp(int a){
	if (a>666){
		a=666;
	
	}
	if ((a<0)){
		a=0;
		
	}
return a;
}

int testexp(int &a){
		if (a>600){
		a=600;
		
	}
	if ((a<0)){
		a=0;
		
	}
return a;
}

int testM(int a){
	
		if (a>3000){
		a=3000;
	
	}
	if ((a<0)){
		a=0;
	
	}
return a;
}

int hamth1(int c,int d){
    if (c < 0) {
        return -99;
    } 

    else if ((c==1)){
    d=d+45;
	  
	}
	else if((c==2)){
	d=d+75;	
	
	}
	else if ((c==3)){
	d=d+29+45+75;

	}
	else if (c==0){
	
	d=d+29;
}
	
	return d; 
} 


int hamth2(int c,double d){
	if ((c<4)||(c>99)){
	return -99;
	}
    else if((4<=c)&&(c<=19)) {
    d=ceil(d+(c/4)+19);
    if (c%4!=0){//Da chinh sua ham nay
    	d=d+1;
	}
    
	}
	else if((20<=c)&&(c<=49)){
	d=ceil(d+(c/9+21));
	if (c%9!=0){//Da chinh sua ham nay
		d=d+1;
	}

	}	
	else if ((50<=c)&&(c<=65)){//Da chinh sua ham nay
	d=ceil(d+(c/16)+17);
	if (c%16!=0){
		d=d+1;
	}
	}
	else if ((66<=c)&&(c<=79)){// Da chinh sua ham nay
	 d=ceil(d+(c/4)+19);
	 if (c%4!=0){
	 	d=d+1;
	 }
	 if (d>200){
	 d=ceil(d+(c/9)+21);
	 if (c%9!=0){
	 	d=d+1;
	 }
	 }
	  
	}
	else if ((80<=c)&&(c<=99)){//Da chinh sua ham nay
	 d=ceil(d+(c/4)+19);
	 if (c%4!=0){
	 	d=d+1;
	 }
	 d=ceil(d+(c/9)+21);
	 if (c%9!=0){
	 	d=d+1;
	 }	
	 if (d>400){
	 d=ceil(d+(c/16)+17);
	 if (c%16!=0){
	 	d=d+1;
	 }
	 d=ceil(d+1.15*d);
	 }
	}
	return d;
} 

double checksquarenumber(int a){

   double b,c ;//chinh sua o day
	b = sqrt(a);
	c=b+1; 

	double  d,e ;
	d= b*b;
	e=c*c;
	if (abs(d-a)<abs(e-a)){
	
	return d;}
	else 
	return e;
}

void checkhpe2(int &HP1, int &EXP1, int &M1, bool &helpedHomeless) {
   
    if (HP1 < 200) {
        HP1 = ceil(1.3 * HP1); 
        M1 = M1-150; 
    } else {
        HP1 = ceil(1.1 * HP1); 
        M1 = M1-70; 
    }

   
    
    if (EXP1 < 400) {
       
        M1 = M1-200;
        EXP1=ceil(1.13*EXP1);
    } else {
        EXP1=ceil(1.13*EXP1);
        M1 = M1-120;
    }

    
    //EXP1 = ceil(1.13*EXP1);

    
    if (!helpedHomeless) {
        if (EXP1 < 300) {
            M1 =M1- 100; 
            EXP1 = ceil(0.9*EXP1); 
        } else {
            M1 =M1- 120;
            EXP1 = ceil(0.9*EXP1); 
        }
        helpedHomeless = true; 
    }
}

double ratioofeachpart(int i,int k){
	double l;//chinh sua o day
	if (i >= k){
       l=1;	
	}
	else 
	   l=((i/k)+80)/123;
	//cout<<l<<endl; 
	return l;
}

int ratioofi (int m){
    int n = m / 10;  //39/10=3
    int o = m - n*10 ;// 39-30=9
    int r=n+o;//3+9=12
    if (r>=10){
       return r-10;//chinh sua ham nay
    	
	}
	else
	return r;
}

int checkallP(double s,double t,double u,int v){// Ham nay kiem tra hp
    double  x; // Da chinh sua o day 
   
	x = (s+t+u)/3;
	if (x==1){
		v=ceil(0.75*v);
	}
	else if(x<0.5){
	   v=ceil(0.85*v);
	//   w=1.15*w;
	}
	else if(x>=0.5){
	  v=ceil(0.9*v);
	//  cout<<v<<" ";
	//  w=1.2*w;
	}
	return v;
}

int checkallPpart2(double s,double t,double u, int w){// Ham nay them vao kiem tra exp
    double x;// chinh sua o day
	x = (s+t+u)/3;
	if (x==1){
		//v=0.75*v;
	}
	else if(x<0.5){
	  // v=0.85*v;
	   w=ceil(1.15*w);
	}
	else if(x>=0.5){
	 // v=0.9*v;
	  w=ceil(1.2*w);
	}
	return w;
}

int sumof2numbers(int c){
	int e = c / 10 ;//37/10=3
	int f = c - e*10 ;//37-30=7
	int g = e + f ;//3+7=10
    if (g>=10){
       int h = g / 10 ;//10/10=1
	   int i = g - h*10 ;//10-10=0
	   int k = h+i ;//1+0=1
	   return k;
	}
	else// chinh sua ham nay
	
return g;
}
void checkingpassword (string str) {

char same = str[0];
    
    for (size_t i = 1; i < str.length(); ++i) {
        if (str[i] == same) {
            cout<< -(400+i)  << endl;
            break;
        }
        same = str[i];
    }
    
	
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
     int D;
     if (e1>3){
    exp2=hamth2( e1,exp2);//Da chinh sua ham nay
 exp1=exp1-e1;
 exp1=ceil(exp1);
 exp1=testexp(exp1);
 exp2=testexp(exp2);
return exp1+exp2;
 }

else
 exp2=hamth1(e1,exp2);
  D=3*e1+7*exp1;

  if (D % 2 == 0){
  	exp1 = ceil(exp1 - (D/200));
  }
  else
    exp1 = ceil(exp1 - (D/100));
exp1= testexp(exp1);
exp2=testexp(exp2);

 
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double S,S1;//chinh sua o day
    double P1,P2,P3;
    int i;
    bool helphomeless=false ;
    double halfofM1=0.5*M1;
	double P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};//chinh sua o day
	//Part 1 of Task 2			
	S=checksquarenumber(EXP1);

	P1=ratioofeachpart(EXP1,S);
	//cout<<P1<<endl;
    
//Part 2 of Task 2   
 

    
    //bool helpedHomeless = false;

    if (E2 % 2 != 0) { 
        while ((M1 >halfofM1) ){
            
            checkhpe2(HP1, EXP1, M1, helphomeless);//Da chinh ham nay
             
           
      //      if (M1 < halfofM1) {
      //          cont = false;
      //      }
        }
       
        HP1 = ceil(0.83*HP1); 
        //cout<<HP1<<endl;
        EXP1 = ceil(1.17*EXP1); 
        
    } else { 
       
        checkhpe2(HP1, EXP1, M1, helphomeless);
         if (M1<=0){
         	M1=0;
		 }
       
        HP1 = ceil(0.83*HP1); 
        EXP1 = ceil(1.17*EXP1); 
    }
    S1=checksquarenumber(EXP1);
    P2=ratioofeachpart(EXP1,S1); //Da chinh sua ham nay
    //cout<<P2<<endl;
 //Part 3 of Task 2
 
    if(E2 >= 10 && E2 <= 99) {
        i = ratioofi(E2);
       P3 = P[i]/100;
      
       
	
    } else if(E2 >= 0 && E2 <= 9) {
       i = E2;
       P3= P[i]/100;
      
    } 
 //cout<<P3<<endl;
EXP1=checkallPpart2(P1,P2,P3,EXP1);

EXP1=testexp(EXP1);

HP1=checkallP(P1,P2,P3,HP1);
HP1=testhp(HP1);
M1=testM(M1);	
//return HP1;
//return EXP1;
//return M1;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int counta=0;
	int countb=0;
	int x,y;
	int e,d;
	int arr[10][10]={};
	for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        if (arr[i][j]<-E3) {
          countb=countb+1;    // da chinh sua 2 bo dem counta va count b
		  
		}
		if (arr[i][j]>2*E3){
		  counta=counta+1;
		  
		}
            
        }
    }
  // cout<<counta<<endl;
  // cout<<countb<<endl;	
    x= sumof2numbers (counta);
  // cout<<x<<endl;
    y = sumof2numbers (countb);
   // cout<<y<<endl;
    
   // for (int i = 0; i < 10; i++) {
   //     for (int j = 0; j < 10; j++) {      //Da chinh sua o day
   //         cout << arr[i][j] << "\t";
   //     }
   //     cout << endl;
   // }
    
    e=arr[x][y];
    
    d=arr[y+1][x-1];
    
    if (abs(e)>d){
       EXP1=ceil(0.88*EXP1);
	   testexp(EXP1);
	   EXP2=ceil(0.88*EXP2);
	   testexp(EXP2);
	   HP1=ceil(0.9*HP1);
	   testhp(HP1);
	   HP2=ceil(0.9*HP2);
	   testhp(HP2);	
	   return e;
	}
	else 
	   EXP1=ceil(1.12*EXP1);
	   testexp(EXP1);
	   EXP2=ceil(1.12*EXP2);
	   testexp(EXP2);
	   HP1=ceil(1.1*HP1);
	   testhp(HP1);
	   HP2=ceil(1.1*HP2);	
	   testhp(HP2);
	   return d;
	//else
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
int a=strlen(s);
char se[100]; 
int b = strlen(email);

   
    int i;
    for (i = 0; i < b; i++) {
        se[i] = email[i];
        if (email[i] == '@') {
            break;
        }
    }
    se[i] = '\0'; 
int pos = string(s).find(se);
	if (a<8){
		return-1;
	//	break;
	}
	if (a>20){
		return-2;
	//	break;
	}
for ( int i=1; i<a; i++){   
	if ((s[i]==se[i])&&(i==a)){
   	return-10;
   	break;}

	if (pos != std::string::npos) {
	
	return-(300+pos);
	break;
}	   
    checkingpassword(s);
    	
		break;
	
	if ((s[i]!= '%')||(s[i]!='@')||(s[i]!='$')||(s[i]!='!')||(s[i]!='#')){
		return-5;
		break;
	}
	 
   	
   
	
	

}    

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
   // Da chinh sua o day  
	 arr_pwds[num_pwds];
	string usually; 
    int biggest = 0; 
    int firstplace = 0; 
    int longest = strlen(arr_pwds[0]); 
    for (int i = 0; i < num_pwds; i++) {
        int count = 1;                                                                                                
        for (int j = i + 1; j < num_pwds; j++) {                                                                   
		    if (strcmp(arr_pwds[j] , arr_pwds[i])==0) {                                                                       
                count=count+1;                                                                                    
            }                                                                                                       
        }
        if ((count > biggest )|| ((count == biggest )&& (strlen(arr_pwds[i]) > longest))) {
            usually = arr_pwds[i];
            biggest = count;
            firstplace = i;
            longest = strlen(arr_pwds[i]);
        }
    }

    
    return firstplace  ;

	  	

	
    return -1;
}





////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
