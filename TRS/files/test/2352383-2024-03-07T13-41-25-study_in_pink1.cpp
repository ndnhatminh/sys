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

int check(double val, double minVal, double maxVal) {
    return max(minVal, min(val, maxVal));
    //check val co nam trong khoang hay ko
}
void addExp(int &exp, double delta){
    float temp=exp;
    temp+=delta;
    temp=ceil(temp);
    exp=temp;
    exp=check(exp,0,600);
}
void addHp(int &hp, double delta){
    float temp= hp;
    temp+=delta;
    temp=ceil(temp);
    hp=temp;
    hp=check(hp,0,666);
}
void addM(int &m, double delta){
    float temp=m;
    temp+=delta;
    temp=ceil(temp);
    m=temp;
    m=check(m,0,3000);
}
int decision(int e1, int exp1) {
    int D = e1 * 3 + exp1 * 7;
    if (D % 2 == 0) {
     addExp(exp1 , D/200.0); return exp1 ;
    } else {
     addExp(exp1 , - D/100.0); return exp1 ;
    }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
 if (e1 < 0 || e1 > 99){return -99;}
    if (e1==0){addExp(exp2 , 29); exp1=decision(e1,exp1);} //truong hop 0
     else if(e1==1){addExp(exp2 , 45); exp1=decision(e1,exp1);} //truong hop 1
     else if(e1==2){addExp(exp2 , 75); exp1=decision(e1,exp1);} //truong hop 2
     else if(e1==3){addExp(exp2 , 149);exp1=decision(e1,exp1);} //truong hop 3
     else if(e1<=19 && e1 >=4){addExp(exp2 , e1/4.0 + 19);addExp(exp1 , -e1);} //truong hop 2.1
     else if(e1<=49 && e1 >=20){addExp(exp2 , e1/9.0 + 21);addExp(exp1 , -e1);} //truong hop 2.2
     else if(e1<=65 && e1 >=50){addExp(exp2 , e1/16.0 + 17);addExp(exp1 , -e1);} //truong hop 2.3
     else if(e1<=79 && e1 >=66){addExp(exp2 , e1/4.0 + 19); 
          if(exp2 > 200){addExp(exp2 , e1/9 + 21);} //check > 200
              addExp(exp1 , -e1);}  //truong hop 2.4
     else if(e1<=99 && e1 >=80){addExp(exp2 , e1/4.0 +e1/9.0 + 40); 
          if(exp2 > 400){addExp(exp2 , 17 + e1/16.0);exp2=ceil(exp2 * 115 /100);exp2=check(exp2,0,600);} //check > 400
              addExp(exp1 , -e1);}  //truong hop 2.5
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99){return -99;}
    double P1,P2,P3;
    double s;
    int payM=floor((50.0/100.0)*M1);
    //Quang duong 1
    double maxSquare=ceil(sqrt(EXP1))*ceil(sqrt(EXP1));
    double minSquare=floor(sqrt(EXP1))*floor(sqrt(EXP1));
    if(maxSquare - EXP1 > EXP1 - minSquare ){ s=minSquare; }
       else s=maxSquare;//check so chinh phuong nao gan nhat
    if(EXP1>=s){P1=1;}//exp1 >=s
      else {P1=(double)(EXP1/s +80)/123;};//exp1 < s
    
    //QUang duong 2
   
    if(E2 % 2 == 1){
     while(payM>0){
        if(HP1<200){
            addHp( HP1, HP1*(30.0/100.0));
             addM(M1 , -150);
              payM=payM-150;if(payM<0) break;} 
                 else {
            addHp( HP1, HP1*(10.0/100.0));
             addM(M1 , -70);
              payM=payM-70;if(payM<0) break;
            }; 
            
             
    //truong hop 1
        if(EXP1<400){
            addM(M1 , -200);
              addExp(EXP1,13.0/100.0 * EXP1);
                payM-=200;if(payM<0) break;}
                 else {
            addM(M1 , -120) ;
              addExp(EXP1,13.0/100.0 * EXP1);
                payM-=120;if(payM<0) break;};
              
    //truong hop 2
        if(EXP1<300){;
            addM ( M1 ,-100) ; 
              addExp(EXP1, -10.0/100.0 * EXP1);
                payM-=100;if(payM<0) break;}
                 else{
            addM( M1 , -120) ; 
              addExp(EXP1 , -10.0/100.0 * EXP1 );
                payM-=120;if(payM<0) break;};
                   
    //truong hop 3
      }
    }
    //E2 la so le
    
    else{
     do{
         if(HP1<200){addHp( HP1, HP1*(30.0/100.0));addM(M1 , -150);payM-=150;if(payM<0) break;} 
            else {addHp( HP1, HP1*(10.0/100.0));addM(M1 , -70);payM-=70;if(payM<0) break;}; 
    //truong hop 1
        if(EXP1<400){addM(M1 , -200);addExp(EXP1,13.0/100.0 * EXP1);payM-=200;if(payM<0) break;}
            else {addM(M1 , -120) ; addExp(EXP1,13.0/100.0 * EXP1);payM-=120;if(payM<0) break;};
    //truong hop 2
        if(EXP1<300){addM(M1 , -100) ; addExp(EXP1, -10.0/100.0 * EXP1);payM-=100;if(payM<0) break;}
            else{addM(M1 , -120) ; addExp(EXP1 , -10.0/100.0 * EXP1 );payM-=120;if(payM<0) break;}
    //truong hop 3
    break;
    }while(payM>0);
    //E2 la so chan
    
       
    }

     addHp(HP1,-(17.0/100.0)*HP1); 
        addExp(EXP1 , (17.0/100.0)*EXP1);
                //HP1 sẽ giảm 17%, đồng thời EXP1 tăng 17%
    
        maxSquare=ceil(sqrt(EXP1))*ceil(sqrt(EXP1));
        minSquare=floor(sqrt(EXP1))*floor(sqrt(EXP1));
    if(maxSquare - EXP1 > EXP1 - minSquare ){ s=minSquare; }
       else s=maxSquare;//check so chinh phuong nao gan nhat
    if(EXP1>=s){P2=1;}//exp1 >=s
      else {P2=(double)(EXP1/s +80)/123;};//exp1 < s
      
           //Tinh P2
    
    //Quang duong 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if(E2 >= 10){i=(E2%10 + E2/10)%10;}
     else{i=E2%10;}
    P3=P[i]/100.0;
    
    //check
    if(P1==1 && P2==1 && P3==1){addExp(EXP1,-(25.0/100.0)*EXP1 );}
    
    else{
        double P=(P1+P2+P3)/3.0;

        if (P < 50.0/100.0){addHp(HP1 , -(15.0/100.0)*HP1);addExp(EXP1 , (15.0/100.0)*EXP1);}
         else{addHp(HP1 , -(10.0/100.0)*HP1);addExp(EXP1 , (20.0/100.0)*EXP1);}
    }
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int duong=0;
    int am=0;
    int array[10][10];
    for(int i=0;i<10;i++){
        for(int j=0 ; j<10 ;j++){
            array[i][j]=((E3 * j) + (i * 2)) * (i - j) ;
            
        } //khai bao mang 2 chieu
    }
   for(int i=0;i<10;i++){
        for(int j=0 ; j<10 ;j++){
           if(array[i][j]>E3*2){duong++;} 
           else if(array[i][j]<-E3){am++;};
        }
    }
    
    if (duong/10 > 0){duong=(duong/10+duong%10)/10+(duong/10+duong%10)%10;}
    else{duong=duong%10;}
     if (am/10 > 0){am=(am/10+am%10)%10+(am/10+am%10)/10;}
    else{am=am%10;}
    
    int taxi = array[duong][am];
    int taxiAbs= abs(taxi);

    int max=0;
    int x=duong;
    int y=am;
    for(int a=0;a<10;a++){
        if(array[x][y]>max){max=array[x][y];}
        if(x==9)break;
        if(y==9)break;
        x++;
        y++;   
    }//huong 1

     x=duong;
     y=am;
     for(int a=0;a<10;a++){
        if(array[x][y]>max){max=array[x][y];}
        if(x==0)break;
        if(y==0)break;
        x--;
        y--;   
    } //huong 2

     x=duong;
     y=am;
    for(int a=0;a<10;a++){
        if(array[x][y]>max){max=array[x][y];}
        if(x==9)break;
        if(y==0)break;
        x++;
        y--;   
    } //huong 3

     x=duong;
     y=am;
    for(int a=0;a<10;a++){
        if(array[x][y]>max){max=array[x][y];}
        if(x==0)break;
        if(y==9)break;
        x--;
        y++;   
    } //huong 4
    int Sherlock=max;
    if(max<0){max=abs(max);}
    //tach 2 bien,bien goc va bien lay tri tuyet doi
    if(taxiAbs>max){addExp(EXP1,-(12.0/100.0)*EXP1);addHp(HP1,-(10.0/100.0)*HP1);addExp(EXP2,-(12.0/100.0)*EXP2);addHp(HP2,-(10.0/100.0)*HP2);}
    else{addExp(EXP1,(12.0/100.0)*EXP1);addHp(HP1,(10.0/100.0)*HP1);addExp(EXP2,(12.0/100.0)*EXP2);addHp(HP2,(10.0/100.0)*HP2);}
    //cap nhat thong so
     
    if(taxiAbs>max){return taxi; }
    else{return Sherlock;}
//tra ve gia tri goc   
}
 

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int counts = 0;
    while (s[counts] != '\0'){
        counts ++;
    }
    int counte = 0;
    while (s[counte] != '\0'){
        counte ++;
    }
    bool check = false;
    if(counts < 8){
        return -1;
    }
    if(counts > 20){
        return -2;
    }
    string mk = s;
    string se = "";
    for(int i = 0; i < counte; i++){
        if(email[i] == '@'){
            break;
        }
        se.push_back(email[i]);
    }
    if(mk.find(se) == string::npos){
        check = false;
    }
    else return -(300 + mk.find(se));
    for(int i = 0; i < counts; i++){
        if(mk[i] == mk[i + 1] && mk[i + 1] == mk[i + 2]){
            return -(400 + i);  
        }
    }
    for(int i = 0; i < counts; i++){
        if(mk[i] !='@' && mk[i] != '#' && mk[i] != '%' && mk[i] != '$' && mk[i] != '!'){
            check = true;
        }
        else check = false;
    }
    if(check == true) return -5;
    else{
        for(int i = 0; i < mk.size(); i++){
            if(isalnum(mk[i]) == false)return i;
            else return -10;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int index = 0;
    int max_count = 0;
    int count = 0;
    int max_length = 0;
    int length;
    for(int i = 0; i < num_pwds; i++){
        count = 0;
        for(int j = 0; j < num_pwds; j++){
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                count++;
            }
        }
        length = strlen(arr_pwds[i]);
        if(count > max_count){
            max_count = count;
            max_length = strlen(arr_pwds[i]);
            index = i;
        }
        else if(count == max_count){
            if(length > max_length){
                max_count = count;
                max_length = length;
                index = i;
            }
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
//////////////////////////////////////////////// 