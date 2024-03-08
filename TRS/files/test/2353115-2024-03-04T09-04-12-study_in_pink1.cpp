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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
       if (exp1 <=0) exp1=0; //check 
    else if (exp1>600) exp1=600;
    if (exp2 <0) exp2=0;
    else if (exp2>=600) exp2=600;//check xong
    if (e1 >= 0 && e1 <= 3) { //truong hop 1 task 1
        if (e1 == 0) {
            exp2 += 29;
        }
        else if (e1 == 1) {
            exp2 += 45;
        }
        else if (e1 == 2) {
            exp2 += 75;
        }
        else if (e1 == 3) {
            exp2 += 149;
        }                    
         D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + ((D*1.0)/ 200));
        }
        else if (D%2 !=0){ exp1= ceil(exp1-((D*1.0) / 100));}
    }
        else if (e1>=4 && e1<=99){
            if(e1>=4 && e1<=19){
                exp2= ceil(exp2 +(e1/4.0) +19);
            }
            else if(e1>=20 && e1<=49){
                exp2= ceil(exp2 +(e1/9.0) +21);
            } 
             else if(e1>=50 && e1<=65){
                exp2= ceil(exp2 + (e1/16.0) +17);
            } 
             else if(e1>=66 && e1<=79){
                 exp2=ceil( exp2 + (e1/4.0) +19); //gt tt 1
                if (exp2>200){
                exp2= ceil(exp2+ (e1/9.0) + 21);} //tt gt thong tin 2
            }
             else if(e1>=80 && e1<=99){
                exp2= ceil(exp2 +(e1/4.0)+ 19);
                exp2= ceil(exp2 +(e1/9.0)+ 21);
                if (exp2 >400){
                exp2= ceil (exp2 +(e1/16.0)+17);
                exp2= ceil(1.15*exp2);}
            }
                
            exp1= exp1-e1; } //ket thuc th2
            else if (e1<0 || e1 >99){ //th3
                return -99;
            }
    if (exp1 <=0) exp1=0;
    else if (exp1>=600) exp1=600;
    if (exp2 <0) exp2=0;
    else if (exp2>600) exp2=600;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int TT,TBD,S;
    double P1,P2;
    // TODO: Complete this function
    if (E2>=0 && E2<=99 ){  //check dau vao HP1,EXP1,M1
    if (M1>0){
    if (EXP1 <=0) {EXP1=0;}
    else if (EXP1>=600) EXP1=600;
    if (M1>3000) M1=3000;
    if (HP1<0) HP1=0;
    else if (HP1>666) HP1=666;
  S=pow(round(sqrt(EXP1)),2);
  
  TT=0;
  TBD=round(M1/2.0);
  if (EXP1 >=S){ P1=1;
  }
  else if (EXP1<S) {
      P1=(EXP1*1.0/S +80)/123;// xong con duong 1
     }
  while(E2 %2 !=0){          // con duong 02, e2 le
    if (HP1<200){           //HP1<200
                    
      if(TT> TBD){
          HP1=ceil(83.0*HP1/100);
          EXP1=ceil(117.0* EXP1/100);
          if (EXP1 <=0) {EXP1=0;}
          else if (EXP1>=600) EXP1=600;
          if (HP1<0) HP1=0;
          else if (HP1>666) HP1=666;
        
          break;}
      else {HP1=ceil(130.0*HP1/100);
          if (HP1<0) HP1=0;
          else if (HP1>666) HP1=666;
          TT=TT+150; 
          M1 -=150;
           if (M1>3000) M1=3000;
    else if (M1<0) M1=0;}
      }
    else if (HP1 >=200)  {            //HP1 >=200
          if(TT> TBD){
          HP1=ceil(83.0*HP1/100);
          EXP1=ceil(117.0* EXP1/100);
          if (HP1<0) HP1=0;
          else if (HP1>666) HP1=666;
          if (EXP1 <=0) {EXP1=0;}
          else if (EXP1>=600) EXP1=600;
         
          break;}
    else {
         HP1=ceil(HP1*11.0/10);
          if (HP1<0) HP1=0;
          else if (HP1>666) HP1=666;
           TT=TT+70; 
          M1 -=70;}
    }                     // xong su kien 1
   
    if (EXP1<400){       // bd su kien 2
      if(TT> TBD){
          EXP1=ceil(117.0*EXP1/100);
          HP1=ceil(83.0*HP1/100);
          
          if (EXP1 <=0) {EXP1=0;}
          else if (EXP1>=600) EXP1=600;
          if (HP1<0) HP1=0;
          else if (HP1>666) HP1=666;
        
          break;
        }
      else if(TT <= TBD) { 
            TT=TT+200; 
           M1 -=200;
           EXP1=ceil(113.0*EXP1/100);
           if (EXP1 <=0) {EXP1=0;}
           else if (EXP1>=600) EXP1=600;
        }
    }
     else if (EXP1 >=400) { //sai 
    if(TT> TBD){
          HP1=ceil(83.0*HP1/100);
          EXP1=ceil(117.0* EXP1/100);
          if (EXP1 <=0) {EXP1=0;}
          else if (EXP1>=600) EXP1=600;
          if (HP1<0) HP1=0;
          else if (HP1>666) HP1=666;
         
          break;
        }
     else if (TT<=TBD){ 
           TT=TT+120; 
           M1 =M1-120;
           EXP1=ceil(113.0*EXP1/100);
           if (EXP1 <=0) {EXP1=0;}
           else if (EXP1>=600) EXP1=600;
        } 
    }                 // xong su kien 2
    
    if (EXP1<300) {   //bd su kien 3
     
     if(TT> TBD){
          HP1=ceil(83.0*HP1/100);
          EXP1=ceil(117.0* EXP1/100);
          if (EXP1 <=0) {EXP1=0;}
      else if (EXP1>=600) EXP1=600;
        
          break;
        }
        else if (TT<=TBD){ 
           TT=TT+ 100;
           M1 -=100;
           EXP1=ceil(90.0*EXP1/100);
           if (EXP1 <=0) {EXP1=0;}
           else if (EXP1>=600) EXP1=600;
        }  
    } 
    else if (EXP1>=300) {
      
        if(TT> TBD){
          HP1=ceil(83.0*HP1/100);
          EXP1=ceil(117.0* EXP1/100);
          if (EXP1 <=0) {EXP1=0;}
          else if (EXP1>=600) EXP1=600;
          if (HP1<0) HP1=0;
          else if (HP1>666) HP1=666;
         
          break;
        }
        else if (TT<=TBD) {
           TT=TT+ 120;
           M1 -=120;
           EXP1=ceil(90.0*EXP1/100);
        }   
    }
   
                        // xong su kien 3, e2 le
  }
  if (E2 %2 ==0){                               // con duong 02, e2 chan
      if (HP1<200 &&M1>0 ){                 // bd su kien 1
          HP1=ceil(130.0*HP1/100);
          if (HP1<0) HP1=0;
         else if (HP1>666) HP1=666;
          M1 -=150;
      }
        else if (HP1>=200 && M1>0) {
      HP1=ceil(11.0*HP1/10);
      if (HP1<0) HP1=0;
      else if (HP1>666) HP1=666;
      M1 -=70;}
                           // xong su kien 1
   
    if (EXP1<400 && M1>0){       // bd su kien 2
           M1=M1-200;
          
           EXP1=ceil(113.0*EXP1/100);
           if (EXP1 <=0) {EXP1=0;}
    else if (EXP1>=600) EXP1=600;
        
    }
    else if (EXP1>=400 &&M1>0) { 
           M1 -=120;
           
           EXP1=ceil(113.0*EXP1/100);
           if (EXP1 <=0) {EXP1=0;}
    else if (EXP1>=600) EXP1=600;
        }                  // xong su kien 2
   
    if (EXP1<300 && M1>0) {   // bd su kien 3
           M1 -=100;
           EXP1=ceil(90.0*EXP1/100);
           
    } 
    else if (EXP1>=300&& M1>0) { 
           M1 -=120;
           EXP1=ceil(90.0*EXP1/100);
          
        } 
      EXP1=ceil(117.0*EXP1/100);
      HP1=ceil(83.0*HP1/100);
    }                          // xong su kien 3,e2 chan

   
    
     if (EXP1 <=0) EXP1=0;
    else if (EXP1>=600) EXP1=600;
    else if (EXP1>600) EXP1=600;
    if (M1>3000) M1=3000;
    else if (M1<0) M1=0;
     if (HP1<0) HP1=0;
    else if (HP1>666) HP1=666;}     // check lai dau ra hp1,exp1,m1
   else if (M1<=0){
     EXP1=ceil(117.0*EXP1/100);
      HP1=ceil(83.0*HP1/100);
   }
   S=pow(round(sqrt(EXP1)),2);
  if (EXP1 >=S){ P2=1;
  }
      else if (EXP1<S) {
      P2=(EXP1*1.0/S +80)/123;} // Xong con duong 02
   
   int i;
   double P3,P;                   // con duong 3
   if (E2>=0 && E2<=9 ){
       i=E2;
   }
   else if (E2>=10 && E2<=99){
     i=i = (E2%10 + E2/10) %10;
       }
    if (i==0) P3=32.0/100; //sua trong vsc 
    else if (i==1) P3=47.0/100;
    else if (i==2) P3=28.0/100;
    else if (i==3) P3=79.0/100;
    else if (i==4) P3=1;
    else if (i==5) P3=50.0/100;
    else if (i==6) P3=22.0/100;
    else if (i==7) P3=83.0/100;
    else if (i==8) P3=64.0/100;
    else if (i==9) P3=11.0/100;
   
     P=(P1+P2+P3)*1.0/3;
      
  if (P1==1 && P3==1 && P2==1){
    EXP1= ceil(75.0*EXP1/100);
  }
    else {
     
      if (P<0.5) {
          HP1=ceil(85.0*HP1/100);
          EXP1=ceil(115.0 * EXP1/100);
      }
      else {
          HP1=ceil(90.0*HP1/100);
          EXP1=ceil(120.0*EXP1/100);
      }
    }
       
       if (EXP1 <=0) EXP1=0;
    else if (EXP1>=600) EXP1=600;
    if (M1>3000) M1=3000;
    else if (M1<0) M1=0;
     if (HP1<0) HP1=0;
    else if (HP1>666) HP1=666;  // check lai dau ra hp1,exp1,m1
    
    }

// TODO: Complete this function
    else if (E2 > 99 || E2 < 0)
       return -99;
       return HP1 +EXP1+ M1;
}
         
    
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if (E3>=0 && E3<=99){
     if (EXP1 <=0) EXP1=0;
    else if (EXP1>=600) EXP1=600;
    if (EXP2 <=0) EXP2=0;
    else if (EXP2>=600) EXP2=600;
     if (HP1<0) HP1=0;
    else if (HP1>666) HP1=666; 
     if (HP2<0) HP1=0;
    else if (HP2>666) HP2=666;   
int a[10][10];
int c=0,d=0; // c la so gia tri lon hon 2e3, d la so gia tri be hon e3, c=posI, d=posJ
for (int i=0;i<=9;i++){
    for (int j=0;j<=9;j++){
        a[i][j]=(((E3*j)+(i*2))*(i-j));
        if (a[i][j]>2.0*E3)
            c+=1;
        
        else if (a[i][j]<-E3)
        d+=1; 

    }
}
   //tim vi tri gap nhau 
if (c>=10 && c<=99){
    c= c/10+c%10;
    if (c>=10 && c<=99){
    c=c/10+c%10;
}
}
if (d>=10 && d<=99){
    d= d/10+d%10;
    if (d>=10 && d<=99){
    d=d/10+d%10;
     }
}

for (int i=0;i<9; i++){       //i va j giam 
        if ((c-i)<0||(d-i)<0) break;
       else if (a[c-i][d-i]>a[c][d]) a[c][d]=a[c-i][d-i];
    
}     
for (int i=0;i<=9; i++){            // i tang, j giam
        if ((c+i)>9||(d-i)<0) break;
        else if (a[c+i][d-i]>a[c][d]) a[c][d]=a[c+i][d-i];
    
}
for (int i=0;i<=9; i++){          // i giam, j tang 
        if ((c-i)<0||(d+i)>9) break;
        if (a[c-i][d+i]>a[c][d]) a[c][d]=a[c-i][d+i];
    
}
for (int i=0;i<=9; i++){            // i va j deu tang
        if ((c+i)>9||(d+i)>9) break;
        else if (a[c+i][d+i]>a[c][d]) a[c][d]=a[c+i][d+i];
    
}
  // gap nhau tai 1 vi tri, so sanh
    int s=abs(a[c][d]); // diem sherlock
int taxi=((E3*d+c*2)*(c-d));  //diem taxi
if (abs(taxi)<=s){
    EXP1=ceil(112.0*EXP1/100);
    EXP2=ceil(112.0*EXP2/100);
    HP1=ceil(110.0*HP1/100);
    HP2=ceil(110.0*HP2/100);
     if (EXP1 <=0) EXP1=0;
    else if (EXP1>=600) EXP1=600;
    if (EXP2 <=0) EXP2=0;
    else if (EXP2>=600) EXP2=600;
     if (HP1<0) HP1=0;
    else if (HP1>666) HP1=666; 
     if (HP2<0) HP1=0;
    else if (HP2>666) HP2=666;   
    return s;
}
else if (abs(taxi)>s) { 
    EXP1=ceil(88.0*EXP1/100);
    EXP2=ceil(88.0*EXP2/100);
    HP1=ceil(90.0*HP1/100);
    HP2=ceil(90.0*HP2/100);
    return taxi;
   }
             // check lai dau ra hp1,exp1,m1
      
}
else if (E3<0 || E3>99){
    return -99;
}
    
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{ // TODO: Complete this function
  // bat dau tim chuoi se
    char subStr = '@';
    const char *xd = strchr(email, subStr);
    size_t size = xd - email;
    char se[size + 1];
    strncpy(se, email, size);
    se[size] = '\0';       // Đảm bảo kết thúc chuỗi
    size_t sd = strlen(s); // do dai cua s
    size_t sed = strlen(se);
    // xu li yeu cau de bai
    if (strlen(s) < 8)
        return -1; // do dai chuoi
    else if (strlen(s) > 20)
        return -2;
    // do dai cua se
    //<<" sed: "<<sed <<" s: "<<s<<endl;
    if (sed == 0)
        return -300; // check if s chua se
    else if (sed != 0)
    {
        const char *p = strstr(s, se);
        if (p != nullptr)
            return -(300 + p - s);
    } // xong nv 3 check s chua se

    for (size_t i = 0; i < strlen(s) - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);
    }
    bool a = true; // khong chua ki tu dac biet
    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            a = false;
        }
    }
    if (a == true)
        return -5; // xong ko chua kt db tra ve -5
    bool b = true;
    int e = 0;
    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
            return i;
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
  // bien dem tuan suat
 int ts=0,pos=-1;
  //pos la vi tri dau tien xuat hien mk dung
 int dainhat=0;
 for(int i=0;i<num_pwds;i++){
   int dem=0;
   int dodai=strlen(arr_pwds[i]);
       for(int j=0;j<num_pwds;j++){
          if (strcmp(arr_pwds[i],arr_pwds[j])==0){  //ktra cac chuoi phia sau co trung khong
            dem ++;
            }
 }
         if (dem>ts){
            ts=dem;
            dainhat=dodai;
            pos=i;
         }
         else if (dem==ts && dodai>dainhat){
            ts=dem;
            dainhat=dodai;
            pos=i; 
         }
}
 
      return pos;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////