
#include "study_in_pink1.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
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
int limit(int value, int min, int max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0|| e1>99)
    return -99;
    exp1=limit(exp1, 0, 600);
    exp2=limit(exp2, 0, 600);
    //Th1:
    if( e1 < 4 ){
    	switch (e1){
    		case 0:
    			exp2 += 29;
    			break;
    		case 1:
				exp2 += 45;
				break;
			case 2:
				exp2 += 75;
				break;
			default:
				exp2 += 149;
				break;
    	}
    	double D= e1*3 + exp1*7;
    	if( (int)D%2 )
    		exp1 = ceil(exp1 - (D/100));
		else
			exp1 = ceil(exp1 + (D/200)) ;
		exp1=limit(exp1, 0, 600);
		exp2=limit(exp2, 0, 600);	
	}
	//TH2
	else{
		int a=ceil((double)e1/4 + 19);
		int b=ceil((double)e1/9 + 21);
		int c=ceil((double)e1/16 + 17);
		if(e1<20)
			exp2+=a;
		else if(e1<50)
            exp2+=b;
        else if(e1<66)
		    exp2+=c;
		else { if(e1<80) {
			      exp2+=a;
			      if(exp2>200)
			      exp2+=b;
		     } else {
			      exp2= exp2 + a + b;
			      if(exp2>400){
			         exp2 +=c;
			         exp2=ceil((double)exp2*1.15);
			        }
		     }	    
	    }
	    exp1=limit(exp1, 0, 600);
        exp2=limit(exp2, 0, 600);
		exp1-= e1;	
	}
    exp1=limit(exp1, 0, 600);
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0|| E2>99)
       return -99;
    HP1 = limit(HP1, 0, 666);
    M1 = limit(M1, 0, 3000);
    EXP1 = limit(EXP1, 0, 600);
    double p1, p2 , p3;
    int m = (double)M1 / 2 , n=0;
    // duong so 1: 
   
    double s1 =  pow((int)round(sqrt(EXP1)), 2);
    if(EXP1 >= (int)s1)
    p1 = 1;
    else 
    p1 = ((double)EXP1/s1 + 80 )/123;
    
  // duong so 2:
    
    if(E2%2){
   // so le:   	
	while( n <= m && M1 != 0){
    if( HP1 < 200){
    	HP1 = (HP1 * 1.3 + 0.999);
    	n += 150;
	} else {
		HP1 = (HP1 * 1.1 + 0.999);
		n += 70;
	}
	HP1 = limit(HP1, 0, 666);
    if (n > m) break;
	if(EXP1 < 400)
	    n += 200;
	else
	    n += 120;
	EXP1= EXP1 * 1.13 + 0.999;
	if (n > m) break;
	if(EXP1 < 300)
	    n += 100;
	else
	    n += 120;
	EXP1 = EXP1 * 0.9 + 0.999;
 }
    M1 -= n;
    M1 = limit(M1, 0, 3000);
    HP1 = limit(HP1, 0, 666);
  }
  // so chan :
   else {
   if(M1 == 0) goto a; 
  // su kien 1:	
   if(M1 > 70 && M1 <= 150) {
           if(HP1 < 200 ) {
                  HP1 = HP1 * 1.3 + 0.999;
                  M1 = 0;
                  HP1 = limit(HP1, 0, 666);
                  goto a;
           } else {
		          HP1 = HP1 * 1.1 + 0.999;
		          M1 -= 70;
           }
   } else if(M1 >=150) {
           if(HP1< 200 ) {
    	          HP1 = HP1 * 1.3 + 0.999;
                  M1 -= 150;
	       } else {
	              HP1= HP1 * 1.1 + 0.999;
		          M1-= 70;
	       }
   } else {
           if(HP1< 200 ) {
                  HP1= HP1 * 1.3 + 0.999;
                  M1= 0;
                  HP1 = limit(HP1, 0, 666);
                  goto a;
	       } else {
		          HP1= HP1 * 1.1 + 0.999;
		          M1= 0;
                  HP1 = limit(HP1, 0, 666);
	              goto a;
           }
   }
    HP1 = limit(HP1, 0, 666);
        
// su kien 2
    if(M1>120 && M1<=200){
           if(EXP1<400){
                  M1=0;
	              EXP1= EXP1 * 1.13 + 0.999;
                  EXP1 = limit(EXP1, 0, 600);
                  goto a;
		   } else {
                  M1-= 120;
                  EXP1= EXP1 * 1.13 + 0.999;
           }
   } else if(M1>200){
	       if(EXP1<400)
                  M1-=200;
           else
	              M1-= 120;
           EXP1= EXP1 * 1.13 + 0.999;
           EXP1 = limit(EXP1, 0, 600);
   } else {
   	       EXP1= EXP1 * 1.13 + 0.999;
           M1=0;
           EXP1 = limit(EXP1, 0, 600);
           goto a;
   }
  EXP1 = limit(EXP1, 0, 600);
// su kien 3:
   if(M1>100 && M1<=120){
        	if(EXP1 < 300)
	              M1 -= 100;
	        else
                  M1 = 0;
	EXP1= EXP1 * 0.9 + 0.999 ;
   } else if(M1>120) {
   	        if(EXP1 < 300)
	              M1 -= 100;
	        else
	              M1 -= 120;
	EXP1= EXP1 * 0.9 + 0.999;
   } else {
	        M1=0;
	EXP1= EXP1 * 0.9 + 0.999;
   }
}
  EXP1 = limit(EXP1, 0, 600);
//
a:
HP1= HP1 *0.83 + 0.999;
EXP1= EXP1 * 1.17 + 0.999;
HP1 = limit(HP1, 0, 666);
EXP1 = limit(EXP1, 0, 600);

//xac xuat dduong so 2:
    double s2 =  pow((int)round(sqrt(EXP1)), 2);
    if(EXP1 >= (int)s2)
         p2 = 1;
    else 
         p2 = ((double)EXP1/s2 + 80 )/123;
//  duong so 3:
int number[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 > 9){
         int k = E2%10 + E2/10;
         if(k > 9) k = k % 10;
         p3 = number[k];
    } else
         p3 = number[E2];
         p3 /= 100;
    if((int)p1 == 1 && (int)p2 == 1 && (int)p3 == 1)
         EXP1 = EXP1 * 0.75 + 0.999;
    else {
    double p = ((p1 + p2 + p3)/3)*1.0;
    if  (p<0.5){
 	     HP1 = HP1 * 0.85 + 0.999;
 	     EXP1 = EXP1 * 1.15 + 0.999;
   } else {
         HP1 = HP1 * 0.9 + 0.999;
 	     EXP1 = EXP1 * 1.2 + 0.999;
   }
   }
   HP1 = limit(HP1, 0, 666);
   M1 = limit(M1, 0, 3000);
   EXP1 = limit(EXP1, 0, 600);
    return HP1 + EXP1 + M1;
}
// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
  if(E3<0|| E3>99)
    return -99;     
  HP1 = limit(HP1, 0, 666);
  HP2 = limit(HP2, 0, 666);
  EXP2 = limit(EXP2, 0, 600);	  
  EXP1 = limit(EXP1, 0, 600); 
  // ma tran cua xe  
  int map_taxi[10][10] ;
  for( int i = 0; i < 10; i++){
  	for( int j = 0; j < 10; j++){
  	 	 map_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);	 	 
	 }
  }
  //ma tran cua nguoi:
  int map_sw[10][10] ;
  for(int i = 0; i < 10 ; i++){
  	for( int j = 0; j < 10; j++){
  		 int max_l, max_r; 
  		 //duong cheo trai:
  		 int max_lu = map_taxi[i][j];
  		 for(int k = i + 1, l = j + 1; k < 10 && l < 10; k++, l++){
  		 	if(max_lu < map_taxi[k][l])
  		 	   max_lu = map_taxi[k][l];	
		}
         int max_ld = map_taxi[i][j];
		 for(int k = i - 1, r = j - 1; k >= 0 && r >= 0; k--, r--){
		 	if(max_ld < map_taxi[k][r])
  		 	   max_ld = map_taxi[k][r];	
		}
		 if(max_lu > max_ld){
		 	max_l = max_lu;
		} else {
			max_l = max_ld;
		}
		//duong cheo phai:
		 int max_ru = map_taxi[i][j];
  		 for(int k = i - 1, l = j + 1; k >= 0 && l < 10; k--, l++){
  		 	if(max_ru < map_taxi[k][l])
  		 	   max_ru = map_taxi[k][l];	
		}
         int max_rd = map_taxi[i][j];
		 for(int k = i + 1, r = j - 1; k < 10 && r >= 0; k++, r--){
		 	if(max_rd < map_taxi[k][r])
  		 	   max_rd = map_taxi[k][r];	
		}
		 if(max_ru > max_rd){
		 	max_r = max_ru;
		} else {
			max_r = max_rd;
		}
		//luu gia tri vao map_sw:
		 if(max_r > max_l){
		 	map_sw[i][j] = max_r;
	    } else { 
	     	map_sw[i][j] = max_l;
	    }
	 }
  }
  //tim diem gap nhau:
  //toa do i:
  int a = 0, b = 0;
  for(int i = 0; i < 10 ; i++){
  	for( int j = 0; j < 10; j++){
  		if( map_taxi[i][j] > (E3 * 2) && i > j )
  		   a+=1;
     }
  } 
  while(a > 9){
        a = a%10 + a/10;
  }  
  //toa do j:
  for(int i = 0; i < 10 ; i++){
  	for( int j = 0; j < 10; j++){
  		if( map_taxi[i][j] < ( -E3 ) && i < j )
  		   b+=1;
     }
  }
   while(b > 9){
        b = b%10 + b/10;
  }  
  if( abs(map_taxi[a][b]) > abs(map_sw[a][b])){
  	EXP1 = EXP1 * 0.88 + 0.999;
  	HP1 = HP1 * 0.9 + 0.999;
  	EXP2 = EXP2 * 0.88 + 0.999;
  	HP2 = HP2 * 0.9 + 0.999;
  } else {
  	EXP1 = EXP1 * 1.12 + 0.999;
  	HP1 = HP1 * 1.1 + 0.999;
  	EXP2 = EXP2 * 1.12 + 0.999;
  	HP2 = HP2 * 1.1 + 0.999;
  }
  // check lai:
  HP1 = limit(HP1, 0, 666);
  HP2 = limit(HP2, 0, 666);
  EXP2 = limit(EXP2, 0, 600);	  
  EXP1 = limit(EXP1, 0, 600); 
  // tra ve gia tri:
  if( abs(map_taxi[a][b]) > abs(map_sw[a][b])){
    return map_taxi[a][b];
  } else {
    return map_sw[a][b];
  }  
    return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //dua ve string:
   string sub(s);
   string mail(email);
   // dk email :
   if( mail.length() > 100) return 100;
   // thanh lap se:
   int i = mail.find("@");
   string se = mail.substr(0, i);
   // do dai cua s:
   if( sub.length() > 20 ) return -2;
   if( sub.length() < 8) return -1;
   // ba dau gach o giua phan yeu cau ham:
   //chuoi trung :
   int a = sub.find(se);   
   if( a != -1) 
   return -(300 + a);
   int b = -1, c = -1, d = -1;
   // ki tu trung lap:
   for( int i = 0; i < (sub.length() - 2 ); i++){
   	 if( sub[i] == sub[i + 1] && sub[i] == sub[i + 2]){
   	 	c = i;
   	 	break;
		} else c = -1;   
   }
   if( c!= -1) return -(400 + c);
   // kiem tra so ki tu dac biet
   for( int i = 0; i < sub.length(); i++){
   	  if(sub[i] == '@' || sub[i] == '#' || sub[i] == '%' || sub[i] == '$' || sub[i] == '!')
   	    d = i;  
   }
   if( d == -1)
   return -5;
   // ki tu dduoc phep:
   for (int i = 0; i < sub.length(); i++) {
    if (!isalnum(sub[i]) && sub[i] != '@' && sub[i] != '#' && sub[i] != '%' && sub[i] != '$' && sub[i] != '!') {
        b = i;
        break;
        }
   }
   if(b != -1) return b;
   return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // chuyen ve sting:
    string pas[num_pwds];
    for( int i = 0; i < num_pwds; i++){
    	string s(arr_pwds[i]);
    	pas[i] = s;
	}
    // chuoi chua so lan xuat hien cua tung pwds:
    int apr[num_pwds];
    for( int i = 0; i < num_pwds; i++ ){
       apr[i] = 1;	
	}
	// danh gia so lan xuât hien cua tung pws :
	for( int i = 0 ; i < num_pwds; i++){
		string test(pas[i]);
		for(int k = i + 1; k < num_pwds; k++){
			string cp(pas[k]);
			int c = cp.find(test);
			if( c == 0 && cp.length() == test.length() ) {
				apr[i] += 1;
			}
			
		}
	}
	// kiem tra nat khau xuat hien nhieu nhat:
	int max = 0;
    int max_p = apr[0];
    for(int i = 1; i < num_pwds; i++ ){
    	if( apr[i] > max_p ){
    		max = i;
    		max_p = apr[i];
		} else if( apr[i] == max_p ){
			if( pas[i].length() > pas[max].length() ){
				max = i;
				max_p = apr[i];
			} else if( pas[i].length() == pas[max].length() ){
				if( i < max ){
					max = i;
					max_p = apr[i];
				} 	    
			}			
		}   	
	}
	return max;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
