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

//Limit of input
int limit(int value,int lowest,int highest){
    if(value<lowest) value=lowest;
    else if(value>highest) value=highest;
return value;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99){
	  return -99;	}
  exp1 = limit (exp1, 0, 600);
  exp2 = limit (exp2, 0, 600);
  //stament1
  if(e1>=0&&e1<=3)  {
  if (e1 == 0)	{							
	  exp2 += 29;	}
  else if (e1 == 1)	{
	  exp2 += 45;	}
  else if (e1 == 2)	{
	  exp2 += 75;	}
  else if (e1 == 3)	{
	  exp2 += 29 + 45 + 75;	}
  int D = e1 * 3 + exp1 * 7;
  if (D % 2 == 0){
	  exp1 = exp1 + 0.9999+ D / 200;}
  else	{
	  exp1 = exp1 + 0.9999 -D / 100;}}
//Stament2
if(e1>=4&&e1<=19){ 
     exp2=0.9999+(exp2+e1/4.0+19);}
else if(e1>=20&&e1<=49){
     exp2=0.9999+(exp2+e1/9.0+21);}
else if(e1>=50&&e1<=65){
     exp2=0.9999+(exp2+e1/16.0+17);}
else if(e1>=66&&e1<=79){
     exp2=0.9999+(exp2+(e1/4.0+19));
        if(exp2>200){
        exp2=0.9999+(exp2+(e1/9.0+21));   }}
else if(e1>=80&&e1<=99)    {
     exp2=0.9999+(exp2+(e1/4.0+19)+(e1/9.0+21));   
         if(exp2>400)   {
     exp2=0.9999+(exp2+(e1/16.0+17));
     exp2=0.9999+(exp2*1.15);
     exp2=limit(exp2,0,600);    }}
if(e1>=4&&e1<=99) {
        exp1-=e1; }
  return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99){
	  return -99;	}
    EXP1 = limit (EXP1, 0, 600);
    HP1=limit(HP1,0,666);
    M1=limit(M1,0,3000);
    int M1s=0.9999+M1*0.5;
    int S=pow(round(sqrt(EXP1)),2); 
    int pay=0,t=0;
    float P1;
    //Street1
    if(S<=EXP1){
        P1=1.0;    }
    else {P1=(EXP1*1.0/S+80)/123.0;}
    //Street2
    do{
        if(HP1<200){
        HP1=0.9999+(HP1*1.30);
        M1-=150;
        M1=limit(M1,0,3000);
        pay+=150;
        if(pay>M1s||M1==0) break;
    }
    else{
        HP1=0.9999+(HP1*1.10);
        HP1=limit(HP1,0,666);
        M1-=70;
        M1=limit(M1,0,3000);
        pay+=70;
        if(pay>M1s||M1==0) break;
    }
    if(EXP1<400){
        M1-=200;
        M1=limit(M1,0,3000);
        pay+=200; 
        if(pay>M1s||M1==0) break;}
    else{
        M1-=120;
        M1=limit(M1,0,3000);
        pay+=120;
        
    }
    EXP1=0.9999+(EXP1*1.13);
    EXP1=limit(EXP1,0,600);
    if(pay>M1s||M1==0) break;
    if(EXP1<300)    {
        M1-=100;
        M1=limit(M1,0,3000);
        pay+=100;
        if(pay>M1s||M1==0) break;
    }
    else {
        M1-=120;
        M1=limit(M1,0,3000);
        pay+=120;
        
    }
    EXP1=0.9999+(EXP1*0.9);
    if(pay>M1s||M1==0) break;
    }
    while(E2%2!=0);
    HP1=0.9999+(HP1*0.83);
    EXP1=0.9999+(EXP1*1.17);
    EXP1 = limit (EXP1, 0, 600);
    S=pow(round(sqrt(EXP1)),2); 
    double P2;
    if(S<=EXP1){
        P2=1.0;    }
    else P2=(EXP1*1.0/S+80)/123.0;
    
   
   //Street3
  float P[10]={0.32,0.47,0.28,0.79,1.0,0.50,0.22,0.83,0.64,0.11};
    int i=0;
    if(E2/10==0){
        i=E2; }
    else if(E2/10>=1){
        i=((E2/10)+E2%10)%10;
    }
    double Pa=(P1+P2+P[i])/3.0;
    if(Pa<0.5){
        HP1=0.9999+(HP1*0.85);
        EXP1=0.9999+(EXP1*1.15);
        EXP1 = limit (EXP1, 0, 600);
    }
    else{
        HP1=0.9999+(HP1*0.90);
        EXP1=0.9999+(EXP1*1.20);
        EXP1 = limit (EXP1, 0, 600);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99){
	  return -99;	}
	 HP1=limit(HP1,0,666);
	 EXP1=limit(EXP1,0,600);
	 HP2=limit(HP2,0,666);
	 EXP2=limit(EXP2,0,600);
    int i=0,j=0;
    int arr[10][10]={};
    for(int x=0;x<=9;x++){
        for(int y=0;y<=9;y++){
            arr[x][y]=((E3*y)+(x*2))*(x-y);
            if(arr[x][y]>E3*2) i+=1;
        else if(arr[x][y]<E3*(-1)) j+=1;
             }}
    while(i/10>0||j/10>0){
    i=i/10+i%10;
    j=j/10+j%10;}
    //cheo trai
    int left[10]={};
    int l;
    for(l=0;l<=9;l++){
        if((i-l)<0||(j-l)<0) break;
        left[l]=arr[i-l][j-l];}
    for(int t=0;t<=9;t++){
        if((i+t)>9||(j+t)>9) break;
        left[l++]=arr[i+t][j+t];} 
    //cheo phai
    int right[10]={};
    int r;
    for(r=0;r<=9;r++){
        if((i-r)<0||(j+r)>9) break;
        right[r]=arr[i-r][j+r];}
    for(int t=0;t<=9;t++){
        if((i+t)>9||(j-t)<0) break;
        right[r++]=arr[i+t][j-t]; } 
    //tim GTLN
    int taxi_scores=arr[i][j];
    int max=left[0];
    for(int t=0; t<10; t++){
            if(max<left[t]) max=left[t];
        }
    for(int t=0; t<10; t++){
            if(max<right[t]) max=right[t];
        }
    //so sanh
    if(abs(taxi_scores)<max){
        EXP1=0.9999+EXP1*1.12;
        HP1=0.9999+HP1*1.1;
        EXP2=0.9999+(EXP2*1.12);
        HP2=0.9999+(HP2*1.1);
        EXP1=limit(EXP1,0,600);
        HP1=limit(HP1,0,666);
        EXP2=limit(EXP2,0,600);
        HP2=limit(HP2,0,666);
    }
    else if(abs(taxi_scores)>max){
        EXP1=0.9999+(EXP1*0.88);
        HP1=0.9999+(HP1*0.9);
        EXP2=0.9999+(EXP2*0.88);
        HP2=0.9999+(HP2*0.9);
    }
    return arr[i][j];
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se;
    int size=strlen(s);
    int sci=-1,sei=-1,site=-1,sp=-1;
    //cut_email
for(int i=0;i<strlen(email);i++){
    if(email[i]=='@') break;
    se=se+email[i];
}
//check
bool checkA;
for(int i=0;i<size; i++){
    if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'));
    else if((s[i]=='!')||(s[i]=='@')||(s[i]=='#')||(s[i]=='$')||(s[i]=='%'));
    else{
        site=i;
        break;}
    }
    if(site!=-1) checkA=1;
    else checkA=0;
    
bool checkS;
string test="";
for(int i=0;i<size; i++){
    if(se==test) break;
    if(se[0]==s[i]){
        int n=i;
        sei=i;
    for(int t=0; t<se.length();t++){
        test=test+s[n];
        if(se[t]!=s[n++]){ 
            sei=-1;
            break;}
        }   }   }
        
        if(sei==-1) checkS=0;
        else checkS=1;  
bool checkR;
for(int i=0; i<size; i++){
    if(s[i]==s[i+1]){
        sci=i; }}
    if(sci==-1) checkR=0;
    else checkR=1;
bool checkSP;
for(int i=0;i<size; i++){
    if((s[i]=='!')||(s[i]=='@')||(s[i]=='#')||(s[i]=='$')||(s[i]=='%'))
        sp=i;
        break;}
    if(sp==-1) checkSP=0;
    else checkSP=1;

//return
    if(size<8) return -1;
    if(size>20) return-2;
    if(checkS==1) return -(300+sei);
    if(checkR==1) return -(400+sci);
    if(checkSP==1)return -5;
    if(checkA==1) return site;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
   int place=0;
   int maxcount=0;
    int maxsize=0;
    int counting[30]={};
    int size_pwds[30]={};
for(int i=0; i<num_pwds;i++){
     int count=0;
    const char * arr_count=arr_pwds[i];
    for(int t=0; t<num_pwds;t++){
    if(strcmp(arr_count,arr_pwds[t])==0){
        count+=1;
        counting[i]=count;
        size_pwds[i]=strlen(arr_count);
        if(maxcount<=count){
        maxcount=count;}
        if(maxsize<strlen(arr_count)){
            maxsize=strlen(arr_count);
    }
}}  }
    int size=0;
    for(int t=0; t<30;t++){
        if(maxcount==counting[t]){
            if(size<size_pwds[t]){
                size=size_pwds[t];
                place=t;}
            }}
        return place;
    }
            

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////