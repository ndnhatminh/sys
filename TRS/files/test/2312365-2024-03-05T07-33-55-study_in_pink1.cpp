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

// Ham kiem tra EXP
void checkExp(int &a){
    if(a>600)a=600;
    else if(a<0)a=0;
}  
// Ham kiem tra tien
void checkMoney(int &a){
    if(a>3000)a=300;
    else if(a<0)a=0;
}  

//Ham kiem tra HP
void checkHP(int &a){
    if(a>666)a=666;
    else if(a<0)a=0;
}  

//Ham tim xac suat dua tren so chinh phuong gan nhat
float findP(int a){
    int b=sqrt(a);
    if(a-b*b<(b+1)*(b+1)-a){
        return 1;
    }
   else {
    	int S=(b+1)*(b+1);
    	return(float(float(a/S)+80)/123.00);
	}
}

//Ham tim chi so gia tri xac suat
int findIndex(int a){
    int index=0;
    if(a/10==0)index=a;
    else{
    //ep kieu float cho a/10, tu do a/10 nhan gia tri min la 0.1 
    while((float)a/10>=0.1){
        index+=a%10;
        a/=10;
    }
    index=index%10;
    }
    return index;
}

//Ham tim toa do xu li toa do gap nhau(task 3)
int sumDigits(int a) {
    int sum = 0;
    while (a>0||sum>9) {
        if(a==0) {
            a=sum;
            sum=0;
        }
        sum+=a%10;
        a/=10;
    }
    return sum;
}


//Ham kiem tra ki tu dac biet
int checkSpecialchar(const char a[]){
	int count =0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='@'||a[i]=='#'||a[i]=='%'||a[i]=='$'||a[i]=='!'){
			count++;
		}
	}
	return count;
}

//Ham kiem tra ki tu vi pham
int checkWeirdchar(const char a[]){
    int i ;
    for( i=0;i<strlen(a);i++){
        if(a[i]=='!'||(a[i]>='#'&&a[i]<='%')||(a[i]>='0'&&a[i]<='9')||(a[i]>='@'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))continue;
        else return i;
    }
   return -1;
}

//Ham kiem tra ki tu lien tiep
int checkContinuousChar(const char a[]){
	int i;
	for( i=0;i<strlen(a)-2;i++){
		if(a[i]==a[i+1]&&a[i+1]==a[i+2])break;
	}
    if(i==0)return 0;
	else if(i<strlen(a)-2)return i;
	else return -1;
}




// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    checkExp(exp1);
    checkExp(exp2);
    if(e1>=0&&e1<=99){
      if(e1>=0&&e1<=3){
      if(e1==0)exp2+=29;
      else if(e1==1)exp2+=45;
      else if(e1==2)exp2+=75;
      else if(e1==3)exp2+=149;
      int D=e1*3 + exp1*7 ;
      if(D%2==0){
        exp1=ceil(float(exp1+(float)D/200.00));
      }
      else if(D%2!=0){
        exp1=ceil(float(exp1-(float)D/100.00));
      }
   }
   else if(e1>=4&&e1<=99){
    exp1-=e1;
      if(e1>=4&&e1<=19){
         exp2+=(ceil((float)e1/4.00)+19);
      }
      else if(e1<=49){
         exp2+=(ceil((float)e1/9.00)+21);
      }
      else if(e1<=65){
         exp2+=(ceil((float)e1/16.00)+17);
      }
      else if(e1<=79){
         exp2+=(ceil((float)e1/4.00)+19);
         if (exp2>200) exp2+=(ceil((float)e1/9.00)+21);
      }
      else if(e1<=99){
         exp2+=(ceil((float)e1/4.00)+19);
         exp2+=(ceil((float)e1/9.00)+21);
         if(exp2>400) {
             exp2+=(ceil((float)e1/16.00)+17);
             exp2=ceil(float(exp2*115.00/100));
         }
      }
   }
    
    checkExp(exp1);
    checkExp(exp2);
    return exp1 + exp2;
    }
    else return -99;
  

}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2){
    if(E2>=0&&E2<=99){
    checkMoney(M1);
    checkHP(HP1);
    checkExp(EXP1);
    float P1=findP(EXP1);
    int M;
    int Half=M1/2;
    if(E2%2!=0){
        if(M1>0){
        while(M<=Half){
            if(HP1<200){
                HP1=ceil(HP1*13.0/10);
                checkHP(HP1);
                M+=150;
            }
            else if(HP1>=200){
                HP1=ceil(HP1*11.0/10);
                checkHP(HP1);
                M+=70;
            }
            if(M>Half)break;
            if(EXP1<400){ 
                M+=200;
                EXP1=ceil(EXP1*113.00/100);
                checkExp(EXP1);
            }
            else if(EXP1>=400){
                M+=120;
                EXP1=ceil(EXP1*113.00/100);
                checkExp(EXP1);
            }
             if(M>Half)break;
            if(EXP1<300){ 
                EXP1=ceil(EXP1*9.0/10);
                M+=100;
                }
            else if(EXP1>300 )
            {
               M+=120;
               EXP1=ceil(EXP1*9.0/10);
            }
    
        }
        M1-=M;
        checkMoney(M1);
        }
        else if(M1==0){
            checkExp(EXP1);
            checkHP(HP1);
        }
    }
    else if(E2%2==0){
        if(M1>0){
        if( HP1<200 ){
            HP1=ceil(HP1*13.0/10);
            M1-=150;
            }  
        else if(HP1>=200){
                HP1=ceil(HP1*11.0/10);
                checkHP(HP1);
                M1-=70;
        }
        checkMoney(M1);    
       if(M1){
            if(EXP1<400) M1-=200;
            else if(EXP1>=400)M1-=120;
            EXP1=ceil(EXP1*113.00/100);
       }
        checkMoney(M1);
        if(M1){
            if(EXP1<300) M1-=100;
            else if(EXP1>300 )M1-=120;
            EXP1=ceil((EXP1*9.0/10));
        }
         checkMoney(M1);   
        }
        else if(M1==0){
            checkExp(EXP1);
            checkHP(HP1);
        }
        
    }
    HP1=ceil(HP1*83.00/100);
    EXP1=ceil(EXP1*117.00/100);
    checkExp(EXP1);
    float P2=findP(EXP1);
    float P[10]={0.32,0.47,0.28,0.79,1.00,0.50,0.22,0.83,0.64,0.11};
    int i=findIndex(E2);
    float P3=P[i];
    float PT=(P1+P2+P3)/3.00;
    if(PT==1){
        EXP1=ceil(EXP1*75.00/100);
    }
    else if(PT<=0.50){
         HP1=ceil(HP1*85.00/100);
         EXP1=ceil(EXP1*115.00/100);
    }
    else{
        HP1=ceil(HP1*9.00/10);
        EXP1=ceil(EXP1*12.00/10);
    }
   checkExp(EXP1);
   return EXP1+M1+HP1;

}
else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
   if(E3>=0&&E3<=99){
    int taxiScore[10][10];
    int PosVal=0, NegVal=0; 
    //Khoi tao cac gia tri cua mang taxiScore=0 de tranh gia tri rac
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) taxiScore[i][j]=0;
             }
   //Tinh gia tri cho cac phan tu cua mang taxiScore
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
             taxiScore[i][j]=((E3*j)+(i*2))*(i-j);
             if(taxiScore[i][j]>0){
                if(taxiScore[i][j]>E3*2)PosVal++;   //dem so phan tu lon hon E3*2
             }
             else{
                if(taxiScore[i][j]<-E3)NegVal++;   //dem so phan tu nho hon -E3
             }
        }
        }
    
    const int X=sumDigits(PosVal);
    const int Y=sumDigits(NegVal);
    int max0=taxiScore[X][Y];
    int max1=taxiScore[X][Y];
    int max2=taxiScore[X][Y];

    // Quan sat ma tran, neu diem gap nhau mang gia tri am thi ta chi can duyet theo chieu X tang, Y giam
    if(taxiScore[X][Y]<0){
       int count =0;
       for(int k=X+1;k<10;k++){
       count++;
       if(taxiScore[k][Y-count]>=max0)max0=taxiScore[k][Y-count];	
       if(Y-count==0)break;
		} 
	   if(max0>=(-taxiScore[X][Y])){
         EXP1=ceil(EXP1*112.00/100);
         HP1=ceil(HP1*110.00/100);
         EXP2=ceil(EXP2*112.00/100);
         HP2=ceil(HP2*110.00/100);
         checkExp(EXP1);
         checkHP(HP1);
         checkExp(EXP2);
         checkHP(HP2);

        return max0;
        }
       else{ 
         EXP1=ceil(EXP1*88.00/100);
         HP1=ceil(HP1*90.00/100);
         EXP2=ceil(EXP2*88.00/100);
         HP2=ceil(HP2*90.00/100);
         checkExp(EXP1);
         checkHP(HP1);
         checkExp(EXP2);
         checkHP(HP2);

         return taxiScore[X][Y];
         }
		  }
    
    /*Neu diem cua taxi tai diem gap nhau >0 thi ta chi can duyet 2 duong cheo theo huong X tang Y tang va huong X tang Y giam */
    else if(taxiScore[X][Y]>=0){ 
        
        //doi voi truong hop gap nhau tai taxiScore[9][9]
        if(X==9&&Y==9){
            EXP1=ceil(EXP1*112.00/100);
            HP1=ceil(HP1*110.00/100);
            EXP2=ceil(EXP2*112.00/100);
            HP2=ceil(HP2*110.00/100);
            checkExp(EXP1);
            checkHP(HP1);
            checkExp(EXP2);
            checkHP(HP2);
            return 0;
        }
        else{
          int count1 =0;
          for(int i=X;i<10;i++){
          	count1++;
          	if(taxiScore[i+1][Y+count1]>=max1)max1=taxiScore[i+1][Y+count1];
          
		  }
		  int count2=0;
		  for(int j=X;j<10;j++){
		  	count2++;
		  	if(taxiScore[j+1][Y-count2]>=max2)max2=taxiScore[j+1][Y-count2];
		  	if(Y-count2==0)break;
		  }
           max0=max(max1,max2);
           if(max0>=(-taxiScore[X][Y])){
            EXP1=ceil(EXP1*112.00/100);
            HP1=ceil(HP1*110.00/100);
            EXP2=ceil(EXP2*112.00/100);
            HP2=ceil(HP2*110.00/100);
            checkExp(EXP1);
            checkHP(HP1);
            checkExp(EXP2);
            checkHP(HP2);
        
            return max0;
            }
           else { 
            EXP1=ceil(EXP1*88.00/100);
            HP1=ceil(HP1*90.00/100);
            EXP2=ceil(EXP2*88.00/100);
            HP2=ceil(HP2*90.00/100);
            checkExp(EXP1);
            checkHP(HP1);
            checkExp(EXP2);
            checkHP(HP2);
            return taxiScore[X][Y];
            }
   }  
     }
       }
    else return -99;
    return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    //Kiem tra do dai chuoi s
    if(strlen(s)<8)return -1;
    else if(strlen(s)>20)return -2;
    
    //kiem tra chuoi se co la chuoi con cua s hay khong
    char se[101];
	int count =0;
    if(email[0]=='@')
    {
        return -300;
    }
    else if(email[0]!='@'){
	for(int i=0;i<strlen(email);i++){
        
		if(email[i]!='@')count++;
        else break;
			}
    strncpy(se,email+0,count);
    se[count] = '\0'; // them diem dung de ham strstr tra ve dung ket qua
    const char* result=strstr(s,se);
    if(result!=nullptr){
        return -300-(result-s);   //lay con tro dia chi cua se tru con tro dia chi cua s 
        
        } 
    }
    
    //Kiem tra 3 ki tu lien tiep 
    int Continous=checkContinuousChar(s);
    if(Continous!=-1)return -400 - Continous;
    
    //Kiem tra ki tu dac biet
	int SpecialChar=checkSpecialchar(s);
    if(SpecialChar==0)return -5;
	
    //Kiem tra ki tu vi pham
    int WeirdChar=checkWeirdchar(s);
    if(WeirdChar!=-1)return WeirdChar;
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    
    int maxCount = 0;
    int maxLength = 0;
    int correctPasswordIndex = 0;

    for (int i=0;i<num_pwds;i++) {
        int count=0;
        int length=strlen(arr_pwds[i]);

        //duyet tu arr_pwds[j] toi arr_pwds[num_pwds-1], neu bang thi tang bien count 
        for (int j=0;j<num_pwds;j++) {
            if(strcmp(arr_pwds[j],arr_pwds[i])==0)count++;   
        }

        //Tien hanh so sanh, uu tien bien count, neu count=maxCount thi kem them dieu kien ve length
        if (count > maxCount||(count==maxCount&&length>maxLength)) {
            maxCount=count;                
            maxLength=length;
            correctPasswordIndex=i;   
        }
    }

    return correctPasswordIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////