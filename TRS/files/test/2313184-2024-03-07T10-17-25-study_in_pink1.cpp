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
void hp1(int & HP1){
    if (HP1 >666) HP1 = 666;
    if (HP1 <0) HP1 = 0;
}
void hp2(int & HP2){
    if (HP2 >666) HP2 = 666;
    if (HP2 <0) HP2 = 0;
}
void m1(int & M1){
    if (M1 >3000) M1 = 3000;
    if (M1 <0) M1 = 0;
}
void m2(int & M2){
    if (M2 >3000) M2 = 3000;
    if (M2 <0) M2 = 0;
}
void exp1(int & EXP1){
     if (EXP1>600) EXP1 = 600;
        if (EXP1<0) EXP1 = 0;
}
void exp2(int & EXP2){
     if (EXP2 >600) EXP2 = 600;
    if (EXP2 <0) EXP2 = 0;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    exp1(EXP1);
    exp2(EXP2); 
   if (E1 >=0 && E1 <=3){
    if (E1 == 0) EXP2 = EXP2 + 29;
    if (E1 == 1) EXP2 = EXP2 + 45;
    if (E1 == 2) EXP2 = EXP2 + 75;
    if (E1 == 3) EXP2 = EXP2 + 29+ 45+ 75;
    int D = E1*3 + EXP1*7;
    if (D % 2 == 0) EXP1 = ceilf(EXP1 + D/200.0 );
    if (D % 2 == 1)EXP1 = ceilf(EXP1 - D/100.0 ) ;
    exp1(EXP1);
    exp2(EXP2);
    }
    if (E1 >=4 && E1 <=99){
    if (E1 >=4 && E1 <=19) EXP2 = ceilf(EXP2 + E1/4.00 + 19.0 ); 
    if (E1 >=20 && E1 <=49) EXP2 = ceilf(EXP2 + E1/9.0 + 21.0  );
    if (E1 >=50 && E1 <=65) EXP2 = ceilf(EXP2 + E1/16.0 + 17.0 ); 
    if (E1 >=66 && E1 <=79){
    EXP2 = ceilf(EXP2 + E1/4.0 + 19.0 );
    if (EXP2 >200)  EXP2 = ceilf(EXP2 + E1/9.0 + 21.0 );
    }   
    if (E1 >=80 && E1 <=99){
    EXP2 = ceilf(EXP2 + E1/4.0 + 19.0 + E1/9.0 + 21.0 +0.0 );
    if (EXP2 >400) { EXP2 = ceilf(EXP2 + E1/16.0 + 17.0 );
    EXP2 = ceilf(EXP2 * 1.15  );
    }
    }   
    EXP1 = EXP1-E1;
    exp1(EXP1);
    exp2(EXP2);
    }
  

    
     int exp= EXP1+EXP2;
     if (E1 <0 || E1 >99) exp=-99;
    
    return exp;
  
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
hp1(HP1);
exp1(EXP1);
m1(M1);
    int minp = 0;
int S[26];
for (int i=0;i<=25;i++){S[i]=i*i;}
int s[26];
for (int i=0;i<=25;i++){s[i]=abs(EXP1-S[i]);}
int min = s[0];
for (int i=1;i<=25;i++){
    if (s[i] < min) {min = s[i];
     minp=i; }
}
float p1;
float scp = S[minp];
if (EXP1 >= S[minp]) p1=1.00;
else p1 = (EXP1/scp + 80.0) / 123.0;
hp1(HP1);
exp1(EXP1);
m1(M1);

//road2
//E2 le
if (E2 % 2==1){
    int og=M1/2;
    
    //bat dau vong lap
    for (int h =1; h<10;h++){
         if (HP1 <200){
        HP1 = ceilf(HP1*1.3 +0.0
);hp1(HP1);
        M1= M1 -150;
    }
    else {
        HP1 = ceilf(HP1*1.1 +0.0
);hp1(HP1);
        M1= M1 -70;
    }
    if (M1 <og) break;
    else if (EXP1<400){
        M1=M1-200;
        EXP1=ceilf(EXP1*1.13 +0.0
);;m1(M1);exp1(EXP1);
    }
    else {
       M1=M1-120;
        EXP1=ceilf(EXP1*1.13 +0.0
);;m1(M1);exp1(EXP1);  
    }
    
    if (M1 <og) break;
    else if (EXP1<300){
        M1=M1-100;
        EXP1=ceilf(EXP1*0.9 +0.0
);;m1(M1);exp1(EXP1);
    }
    else {
       M1=M1-120;
        EXP1=ceilf(EXP1*0.9 +0.0
); ;m1(M1);exp1(EXP1); 
    }
    
     if (M1 <og) break;
     else continue;
    }
    HP1 = ceilf(HP1*0.83 +0.0);
    EXP1=ceilf(EXP1*1.17 +0.0);
}
//E2 chan
else if (E2 % 2==0){
    for (int h =1; h<2;h++){
         if (HP1 <200){
        HP1 = ceilf(HP1*1.3 +0.0
);hp1(HP1);
        M1= M1 -150;
    }
    else {
        HP1 = ceilf(HP1*1.1 +0.0);hp1(HP1);
        M1= M1 -70;
    }
    if (M1 <=0) {
        M1=0;
        break;
    }
    else if (EXP1<400){
        M1=M1-200;
        EXP1=ceilf(EXP1*1.13 +0.0
);;m1(M1);exp1(EXP1);
    }
    else {
       M1=M1-120;
        EXP1=ceilf(EXP1*1.13 +0.0
);  ;m1(M1);exp1(EXP1);
    }
    
    if (M1 <=0) {
        M1=0;
        break;
    }
    else  if (EXP1<300){
        M1=M1-100;
        EXP1=ceilf(EXP1*0.9 +0.0
);;m1(M1);exp1(EXP1);
    }
    else {
       M1=M1-120;
        EXP1=ceilf(EXP1*0.9 +0.0
);  ;m1(M1);exp1(EXP1);
    }
    
    }
    HP1 = ceilf(HP1*0.83 +0.0);
    EXP1=ceilf(EXP1*1.17 +0.0);
}
hp1(HP1);
exp1(EXP1);
m1(M1);
int z[26];
for (int i=0;i<=25;i++){z[i]=abs(EXP1-S[i]);}
min = z[0];
for (int i=1;i<=25;i++){
    if (z[i] < min){ min = z[i];
    minp=i; }
}
float p2;
scp = S[minp];
if (EXP1 >= S[minp]) p2=1.00;
else p2 =(EXP1/scp + 80.0) / 123.0;
hp1(HP1);
exp1(EXP1);
m1(M1);

//road3
float P[] = {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
float p3;
int a;
if (E2 >=0 && E2 <=9) a = E2;
else if (E2>=10 && E2 <=99)
a = (E2 / 10 + E2 % 10) % 10;
p3 = P[a];
hp1(HP1);
exp1(EXP1);
m1(M1);
float avg=(p1+p2+p3)/3;
if (p1==p2 && p2==p3 && p3==1.00) {EXP1=ceilf(EXP1*0.75 + 0.);
    }
else {if (avg<0.50){
     HP1 = ceilf(HP1*0.85 +0.0
);
    EXP1=ceilf(EXP1*1.15 +0.0);
}
else if (avg>=0.50){
     HP1 = ceilf(HP1*0.90 + 0.0
);
    EXP1=ceilf(EXP1*1.20 +0.0);
}
}
hp1(HP1);
exp1(EXP1);
m1(M1);
int exp=HP1 + EXP1 + M1;
 if (E2<0 || E2>99) exp=-99; 
    return exp;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
     exp1(EXP1);
        exp2(EXP2);
        hp1(HP1);
        hp2(HP2);
        if (E3<0 || E3>99) return -99;
    int taxi[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int ip = 0, jp = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (taxi[i][j] > 2 * E3){
                ip++;
            }
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (taxi[i][j] < -1 * E3){
                jp++;
            }
        }
    }
    int a1 = ip % 10;
    int a2 = ip / 10;
    int b1 = jp % 10;
    int b2 = jp / 10;
    ip = (a1 + a2) % 10 + (a1 + a2) / 10;
    jp = (b1 + b2) % 10 + (b1 + b2) / 10;
    int max = 0;
    int in, jn;
    for(in = ip, jn = jp;in < 10 && jn < 10; in++ && jn++){
        if (taxi[in][jn] > max){
            max = taxi[in][jn];
        }
      
    }
    in = ip;
    jn = jp;
     while(in >= 0 && jn >= 0){
        if (taxi[in][in] > max){
            max = taxi[in][jn];
        }
        in--;
        jn--;
    }
  
    for (in = 0; in < 10; in++){
        for (jn = 0; jn < 10; jn++){
            if (in + jn == ip + jp){
                if (taxi[in][jn] > max){
                    max = taxi[in][jn];
                }
            }
        }
    }
    if (abs(taxi[ip][jp]) > max){
        EXP1 = ceilf(EXP1 * 0.88);
        HP1 = ceilf(HP1 * 0.9);
        EXP2 = ceilf(EXP2 * 0.88);
        HP2 = ceilf(HP2 * 0.9);
        exp1(EXP1);
        exp2(EXP2);
        hp1(HP1);
        hp2(HP2);
        return taxi[ip][jp];
    }
    else{
        EXP1 += ceilf(EXP1 * 0.12);
        HP1 += ceilf(HP1 * 0.1);
        EXP2 += ceilf(EXP2 * 0.12);
        HP2 += ceilf(HP2 * 0.1);
        exp1(EXP1);
        exp2(EXP2);
        hp1(HP1);
        hp2(HP2);
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
string email1= email;
string s1= s;
char se[100];
int po;
int point = 0;

int size1= email1.length();
int size2= s1.length();


for (int i =0; i<size1; i++){
    if (email[i]== '@')  po = i;
}
for (int i =0; i<po; i++){
   se[i]=email[i];
}
string se1=se;
int sep1= email1.find(se1);
int sep2= s1.find(se1);
//check password
if (size2 <8){
    point = -1;
    return point;
}

    if (size2>20){
    point = -2;
    return point;
}
    else {
        if (sep2 < size2 && sep2 >=0){ point = -(300+sep2);
return point;}
        else{
            for (int i=0;i<size2;i++){
                if (s1[i]==s1[i+ 1] && s1[i+ 1]==s1[i+ 2 ])
                     {point = -(400+i);
                     
                    break;}
                else  for (int i=0;i<size2;i++){        
                if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!' ) {
                    point = -10;
                    
                    break;
                                    
                            }
                else 
                     point = -5;
                    
            }
             
                        
                    
               
             }   
            
            
       return point;  
    }
}

}  

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
   
 int arr[num_pwds]; 
 int max = 0;
 int c;
  int maxp;
    for (int i =0; i< num_pwds; i++) {
        c = 1; //cu bat dau vong lap moi la c quay ve 1
        for (int j=0; j< num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) { 
                c++;
            }
        }
        arr[i] = c;// gan arr[i]=c roi quay lai vong lap moi c lai bang 0
    } 
    for (int i=0; i<num_pwds;i++) {
        if (arr[i]>max) {
            max = arr[i];
            maxp = i;
        }
    }
    //ham if dung 2 dk dc, nen dung de tim mkd y het tim max 
    for (int j = 0; j < num_pwds; j++) {
        if ((arr[j] == max) && (strlen(arr_pwds[j]) > strlen(arr_pwds[maxp]))) maxp = j;
        }
     
      return maxp;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
