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
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if(e1>=0 && e1<=99){
        if(exp1<0) exp1=0;
        else if(exp1>600) exp1=600;
        
        if(exp2<0) exp2=0;
        else if(exp2>600) exp2=600;
    if(e1<=3){
        int d;
        if(e1 == 0) {
            exp2+= 29;
            d= e1*3 + exp1*7;
            }
        else if (e1 == 1) {
            exp2+= 45;
            d= e1*3 + exp1*7;
            }
        else if (e1== 2) {
            exp2+= 75;
            d= e1*3 + exp1*7;
            }
        else if (e1==3) {
            exp2= exp2 + 29 + 45 + 75;
            d= e1*3 + exp1*7;
            }     
        if(d%2==0) exp1=ceil(exp1+float(d)/200);
        else exp1=ceil(exp1- float(d)/100);
    }
    if(e1>=4 && e1<=99){

        if(e1>=4 && e1<=19){
            exp2= ceil(exp2+float(e1)/4 + 19);
        }
     else if(e1>=20 && e1<=49){
            exp2= ceil(exp2+float(e1)/9 +21);
        }
     else if(e1>=50 && e1 <=65){
            exp2=ceil(exp2+ float(e1)/16 + 17);
        }
     else if(e1>=66 && e1<=79){
            exp2=ceil(exp2+float(e1)/4 + 19);
            if(exp2>200) exp2=ceil(exp2+(float(e1)/9 + 21));
        }
     else if(e1>=80 && e1<=99){
            exp2=ceil(exp2+ float(e1)/4 + 19);
            exp2= ceil(exp2+float(e1)/9 +21);
            if(exp2 > 400) {
                exp2= ceil(exp2+ float(e1)/16 + 17);
                exp2= ceil(exp2+(exp2*0.15));
            }   
        
     }
    exp1-= e1;
    }
    if(exp1<0) exp1=0;
    else if(exp1>600) exp1=600;
        
    if(exp2<0) exp2=0;
    else if(exp2>600) exp2=600;    

    
    return exp1 + exp2;}
    
    else return -99;
}


//task2
int findSquareNumber(int a){
if(a==0) return 0;
else {
  int i=a-1;
  while(i<a){
        int n = sqrt(i);
        if (n*n == i) {          
            break;}
        i-=1;
    }
  int d1=a-i;

  int j=a+1;
  while(j>a){
        int n = sqrt(j);
        if (n*n == j) {            
            break;}
        j+=1;
    }
  int d2=j-a;
  if(d1>d2) return j;
  else return i;
}
}

int moneyCheck(int &a){
  if(a<0){
    a=0;
  } else if(a>3000) a= 3000;
  return a;
} 
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2>=0 && E2<=99){
    //street1
    if(EXP1>600) EXP1=600;
    else if(EXP1<0) EXP1=0;
    if(HP1>666) HP1=666;
    else if(HP1<0) HP1=0;

    int s;
    s=findSquareNumber(EXP1);
    
    float p1;
    if(EXP1>= s){
         p1=1;
    } else p1=(float(EXP1)/float(s) +80)/123.0;
    //street2
    float p2;
    if(E2 %2==0){
        if(HP1<200){
            HP1=ceil(HP1+0.3*HP1);
            if(HP1>666) HP1=666;
            else if(HP1<0) HP1=0;//30
            M1-=150;
            M1=moneyCheck(M1);
        }
        else if(HP1>=200){
            HP1=ceil(HP1+0.1*HP1);
            if(HP1>666) HP1=666;
            else if(HP1<0) HP1=0;
            M1-=70;
            M1=moneyCheck(M1);
        }
        if(EXP1>600) EXP1=600;
        else if(EXP1<0) EXP1=0;
        if(HP1>666) HP1=666;
        else if(HP1<0) HP1=0;
        if(M1>0){
            if(EXP1<400){
                M1-=200;
                M1=moneyCheck(M1);
                EXP1=ceil(EXP1+0.13*EXP1);
                if(EXP1>600) EXP1=600;
                else if(EXP1<0) EXP1=0;
            }
            else if(EXP1>=400){
                M1-=120;
                M1=moneyCheck(M1);
                EXP1=ceil(EXP1+0.13*EXP1);
                if(EXP1>600) EXP1=600;
                else if(EXP1<0) EXP1=0;//424
            }
            if(EXP1>600) EXP1=600;
            else if(EXP1<0) EXP1=0;
            if(HP1>666) HP1=666;
            else if(HP1<0) HP1=0;
            
                if(M1>0){
                    if(EXP1 <300){
                        M1-=100;
                        M1=moneyCheck(M1);
                        }
                    else if (EXP1 >=300){
                        M1-=120;   
                        M1=moneyCheck(M1);      
                        }
                    EXP1=ceil(EXP1-0.1*EXP1);
                    if(EXP1>600) EXP1=600;
                    else if(EXP1<0) EXP1=0;
                    }
                    if(EXP1>600) EXP1=600;
                    else if(EXP1<0) EXP1=0;
                    if(HP1>666) HP1=666;
                    else if(HP1<0) HP1=0;
                
        }
        
                HP1= ceil(HP1-0.17*HP1);
                EXP1= ceil(EXP1+0.17*EXP1);
                if(EXP1>600) EXP1=600;
                else if(EXP1<0) EXP1=0;
                if(HP1>666) HP1=666;
                else if(HP1<0) HP1=0;
                
    }
    
    if(E2%2!=0){
        float b;
        b=(0.5*M1);
        int q=0;
        while(q<=b){
            if(HP1<200){
                HP1=ceil(HP1+0.3*HP1);
                if(HP1>666) HP1=666;
                else if(HP1<0) HP1=0;
                M1-=150;
                q+=150;
            }   
            else if(HP1>=200){
                HP1=ceil(HP1+0.1*HP1);//301
                if(HP1>666) HP1=666;
                else if(HP1<0) HP1=0;
                M1-=70;
                q+=70;
            }//q70
            if(EXP1>600) EXP1=600;
            else if(EXP1<0) EXP1=0;
            if(HP1>666) HP1=666;
            else if(HP1<0) HP1=0;

            if(q<=b){
                if(EXP1<400){
                    M1-=200;
                    q+=200;
                }
                else if(EXP1>=400){
                    M1-=120;
                    q+=120;
                }
            EXP1=ceil(EXP1+0.13*EXP1);//551
            if(EXP1>600) EXP1=600;//p=190
            else if(EXP1<0) EXP1=0;
                if(q<=b){
                    if(EXP1 <300){
                        M1-=100;
                        q+=100;
                    }
                    else if (EXP1 >=300){
                        M1-=120;   
                        q+=120;
                    }
                EXP1=ceil(EXP1-0.1*EXP1);
                if(EXP1>600) EXP1=600;
                else if(EXP1<0) EXP1=0;
                } else break;
            } else break;        
        }

        HP1= ceil(HP1-0.17*HP1);//2
        EXP1= ceil(EXP1+0.17*EXP1);//0
        if(EXP1>600) EXP1=600;
        else if(EXP1<0) EXP1=0;
        if(HP1>666) HP1=666;
        else if(HP1<0) HP1=0;
    }
        int x;
        x=findSquareNumber(EXP1);
        
         if(EXP1>= x){
         p2=1;} 
         else p2=(float(EXP1)/float(x) +80)/123.0;

    
    //street3
    
    float arr[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    int g;
    if(E2/10==0)  g=E2;
    else if(E2/10!=0){
            g=(E2%10)+(E2/10);
        }
    
    float p3;
    p3= arr[g%10];
    
    
    if(p1==1 &&p2==1 &&p3==1){
        EXP1=ceil(EXP1-EXP1*0.25);
        if(EXP1>600) EXP1=600;
        else if(EXP1<0) EXP1=0;
    }
    else {
      float avr;
      avr=(p1+p2+p3)/3.0;
      if(avr<0.5){
            HP1=ceil(HP1-0.15*HP1);
            EXP1=ceil(EXP1+0.15*EXP1);
            if(HP1>666) HP1=666;
            else if(HP1<0) HP1=0;
            if(EXP1>600) EXP1=600;
            else if(EXP1<0) EXP1=0;
        }
    else if(avr>=0.5){
            HP1=ceil(HP1-0.1*HP1);
            EXP1=ceil(EXP1+0.2*EXP1);
            if(HP1>666) HP1=666;
            else if(HP1<0) HP1=0;
            if(EXP1>600) EXP1=600;
            else if(EXP1<0) EXP1=0;
        }
    }

    if(HP1<0) HP1=0;
    else if(HP1>666) HP1=666;
    if(EXP1<0) EXP1=0;
    else if(EXP1>600) EXP1=600;
    if(M1<0) M1=0;
    else if(M1>3000) M1=3000;
    
    return HP1 + EXP1 + M1;
}
    else return -99;
}

//task3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if(E3>=0 && E3<=99){
  int **arr;
arr=new int*[10];

for(int i=0;i<10;i++){
    arr[i]= new int[10];
    for(int j=0;j<10;j++){
        arr[i][j]=((E3*j)+(i*2))*(i-j);
    }
}

int n=0;
int m=0;
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        if(arr[i][j]> (E3*2)){
            n+=1;
        }
        else if(arr[i][j]<(-E3)){
            m+=1;
        }
        }
}

    while(n/10!=0){
        n=(n%10)+(n/10);
    }
    while(m/10!=0){
        m=(m%10)+(m/10);
    }
    
    int pointTaxi;
    pointTaxi=arr[n][m];
   
    int max1;
    max1=arr[n][m];
    int a,b;
    a=n;
    b=m;
    while(m>=0){
        if(m==0){ max1=arr[n][m];
                  break;}
        else if(n==9) {
                  max1=arr[n][m];
                  break;}
        else if(max1<arr[n+1][m-1]){
            max1=arr[n+1][m-1];
        }
        m--;
        n++;
        if(n==9) break;
        else if (m==0) break; 
        }
    while(m>=0){
        if(m==9) break;
       else if(n==0) break;
        else if(max1<arr[n-1][m+1]){
            max1=arr[n-1][m+1];
        }
        n--;
        m++;
        if(n==0) break;
        else if(m==9) break; 
        }
    
    int max2;

    max2=arr[a][b];
    
    while(b>=0){
        if(b==0){ max2=arr[a][b];
                  break;}
        else if(a==9) {
                  max2=arr[a][b];
                  break;}
        else if(max2<arr[a+1][b+1]){
            max2=arr[a+1][b+1];
        }
        a++;
        b++;
        if(a==9) break;
        else if (b==9) break; 
        }

    while(b>=0){
        if(b==0) break;
        else if(a==9) break;
        else if(max2<arr[a-1][b-1]){
            max2=arr[a-1][b-1];
        }
        a--;
        b--;
        if(a==0) break;
        else if(b==0) break; 
        }

    int pointSW;
    if(max1>=max2) pointSW=max1;
    else pointSW=max2; 

    int finalPoint;
    if(abs(pointTaxi)>pointSW){
        EXP1=ceil(EXP1-0.12*EXP1);
        EXP2=ceil(EXP2-0.12*EXP2);
        HP1=ceil(HP1-0.1*HP1);
        HP2=ceil(HP2-0.1*HP2);
        finalPoint=pointTaxi;
    }
    else {
        EXP1=ceil(EXP1+0.12*EXP1);
        EXP2=ceil(EXP2+0.12*EXP2);
        HP1=ceil(HP1+0.1*HP1);
        HP2=ceil(HP2+0.1*HP2);
        finalPoint=pointSW;
    }

if(HP1<0) HP1=0;
else if(HP1>666) HP1=600;
if(HP2<0) HP2=0;
else if(HP2>666) HP2=600;

if(EXP1<0) EXP1=0;
else if(EXP1>600) EXP1=600;
if(EXP2<0) EXP2=0;
else if(EXP2>600) EXP2=600;

   return finalPoint;}
   else return -99;
}


// Task 4
bool findSpecialCharacter(string s){
  if(s[s.find("@")]==64 ||s[s.find("#")]==35||s[s.find("%")]==37||s[s.find("$")]==36||s[s.find("!")]==33 ) 
     return 1;
  else return 0;
}
int checkPassword(const char * s, const char * email) {
    string s_1=s;
    string email_1=email;
  
  string result;
  bool temp=false;
  
  string se;
  se= email_1.substr(0,email_1.find("@"));
  
  
  for (int i=s_1.length(); i>=1; i--){
        for (int j=0; j < s_1.length() - i + 1; j++ ){
            string temp_1= s_1.substr(j, i);
            if (se.find(temp_1) != -1) {              
                result = temp_1;
                temp = true;
                break;
            }
        }
        if (temp) break;
    }    
    

  int a;
  bool test;
  test=false;
  for(int i=0;i<s_1.length();i++){
    
    if(s_1[i]>=1 && s_1[i]<=47){
        if((s_1[i]!=35 && s_1[i]!=36 && s_1[i]!=37 && s_1[i]!=33))
                            {test= true;
                              a=i;
                              break;}
        }
    else if(s_1[i]>=58 && s_1[i]<=63 ) {test= true;
                              a=i;
                              break;}
    else if(s_1[i]>=91 && s_1[i]<=96) {test= true;
                              a=i;
                              break;}
    else if(s_1[i]>=123 && s_1[i]<=255) {test= true;
                              a=i;
                              break;}
  }
  
  
                                  
  int g=0;
  int index;
  for(int i=0;i<s_1.length()-1;i++){
    if(s_1[i]==s_1[i+1]){
        g+=1;
        if(s_1[i+1]==s_1[i+2]){ 
            g+=1; 
            index=i; 
            break;}
        else g=0;
  }
  }
  
    int x;
  if(s_1.length()>=8 && s_1.length()<=20){
    if(result!=se){
      if(g<=1){
        if(findSpecialCharacter(s_1)) {
          if(test) x= a;
          else x= -10;
        }
        else x= -5;
      }
      else x= -(400+index);
    }
    else x= -(300+int(s_1.find(se)));
  }
  else if(s_1.length()<8) x=-1;
  else if(s_1.length()>20) x= -2;


  return x;
}

// Task 5
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    string arr[100];

for(int i=0;i<num_pwds;i++){
    string a=arr_pwds[i];
    arr[i]=a;
}

int g=1;
int z=0;
int index=0;
for(int i=0;i<num_pwds;i++){
    for(int j=num_pwds-1;j>=i+1;j--){
        if(arr[i]==arr[j]){
            g=g+1;
        }          
    }
   
    if(g==z){
        if(arr[i].length()>arr[index].length())
        {
            index=i;
        }
    } 
    if(g>z) {
        z=g;
        index=i;
    }
    
    
    g=1;
}
return index;

}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////