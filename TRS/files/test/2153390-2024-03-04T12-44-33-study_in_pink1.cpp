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
int checkEXP(int& exp){
    if(exp<0)return 0;
    else if(exp>600)return 600;
    else return exp;
}
int checkHP(int& hp){
    if(hp<0)return 0;
    else if(hp>666)return 666;
    else return hp;
}
int checkMoney(int& m){
    if(m<0)return 0;
    else if(m>3000)return 3000;
    else return m;
}
int takingLocation(int& x){
    while(x>=10){
        x=x/10+x%10;
    }
    return x;
}
int traverse_left(int i,int j,int arr[10][10]){
    int temp_i=i,temp_j=j,max=-99999;
    while((temp_i>=0&&temp_j>=0)&&(temp_i<10&&temp_j<10)){
        if(arr[temp_i][temp_j]>max){
            max=arr[temp_i][temp_j];
        }
        temp_i--;
        temp_j--;
    }
    temp_i=i,temp_j=j;
    while((temp_i>=0&&temp_j>=0)&&(temp_i<10&&temp_j<10)){
        if(arr[temp_i][temp_j]>max){
            max=arr[temp_i][temp_j];
        }
        temp_i++;
        temp_j++;
    }
    return max;
}

int traverse_right(int i,int j,int arr[10][10]){
    int temp_i=i,temp_j=j,max=-99999;
    while((temp_i>=0&&temp_j>=0)&&(temp_i<10&&temp_j<10)){
        if(arr[temp_i][temp_j]>max){
            max=arr[temp_i][temp_j];
        }
        temp_i++;
        temp_j--;
    }
    temp_i=i,temp_j=j;
    while((temp_i>=0&&temp_j>=0)&&(temp_i<10&&temp_j<10)){
        if(arr[temp_i][temp_j]>max){
            max=arr[temp_i][temp_j];
        }
        temp_i++;
        temp_j--;
    }
    return max;
}    

////////////////////////////////////////////////
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    exp1=checkEXP(exp1);
    exp2=checkEXP(exp2);
    
    // TODO: Complete this function
    //E = [0,3]
    if(e1>=0&&e1<=3){
        if(e1==0)exp2+=29;
        else if(e1==1)exp2+=45;
        else if(e1==2)exp2+=75;
        else if(e1==3)exp2+=149;
        //check EXP
        exp2=checkEXP(exp2);
        int D=ceil(e1*3+exp1*7);
        if(D%2==0)exp1=ceil(double(exp1)+double(D)/200);
        else exp1=ceil(double(exp1)-double(D)/100);
        //check EXP
        exp1=checkEXP(exp1);
    }
    else if(e1>=4&&e1<=99){

        if(e1<=19)exp2=ceil(double(exp2)+double(e1)/4+19);
        else if(e1<=49)exp2=ceil(double(exp2)+double(e1)/9+21);
        else if(e1<=65)exp2=ceil(double(exp2)+double(e1)/16+17);
        else if(e1<=79){
            exp2=ceil(double(exp2)+double(e1)/4+19);
            exp2=checkEXP(exp2);
            if(exp2>200){
                exp2=ceil(double(exp2)+double(e1)/9+21);
                exp2=checkEXP(exp2);
            }
        }
        else if(e1<=99){
            exp2=ceil(double(exp2)+double(e1)/4+19);
            exp2=checkEXP(exp2);
            exp2=ceil(double(exp2)+double(e1)/9+21);
            exp2=checkEXP(exp2);
            if(exp2>400){
                exp2=ceil(double(exp2)+double(e1)/16+17);   
                exp2=checkEXP(exp2);
                exp2=ceil(double(exp2)*1.15);
                exp2=checkEXP(exp2);
                
            } 
            
        }
        exp2=checkEXP(exp2);
    
        exp1-=e1;
    }else return -99;
    exp1=checkEXP(exp1);
    exp2=checkEXP(exp2);
    return exp1 + exp2 ;
}



int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2<0||E2>99)return -99;
    int HP=HP1;
    int EXP=EXP1;
    int M=M1;
    int E=E2;
    double P1,P2,P3;
    P1=P2=P3=1;
    while(P1==P2&&P2==P3&&P3==1){
    // TODO: Complete this function
    //PATH 1
        if(EXP1<1){
            P1=double(80)/123;
        }else{
            int x=pow(floor(sqrt(EXP1)),2);
            int y=pow(ceil(sqrt(EXP1)),2);
           // cout<<x<<" "<<y<<endl;
        //Calculate P1
            int S;
            if(EXP1-x>y-EXP1) S=y;
            else  S=x;
            if(EXP1>=S)P1=1.0;
            else P1=(double(EXP1)/S+80)/123;
            
        }
     //   cout<<"P1: "<<P1<<endl;
 
    //Checking
    //PATH 2

        int money=M1;
        int paidMoney=0;
        int flag;
        if(E2%2==0)flag=1;
        else flag=0;
        while(true){
            if(M1==0)break;
            if(HP1<200){
                HP1=ceil(double(HP1)+double(HP1)*0.3);
                HP1=checkHP(HP1);
                M1-=150;
                paidMoney+=150;
                M1=checkMoney(M1);
            }else{
                HP1=ceil(double(HP1)+double(HP1)*0.1);
                HP1=checkHP(HP1);
                M1-=70;
                M1=checkMoney(M1);
                paidMoney+=70;
            }
            
            if(flag==1&&M1==0)break;
            if(flag==0&&double(paidMoney)>(money*1.0/2))break;


            if(EXP1<400){
                M1-=200;
                paidMoney+=200;

            }
            else{
                M1-=120;
                paidMoney+=120;
                } 
            M1=checkMoney(M1);
            EXP1=ceil(double(EXP1)+double(EXP1)*.13);
            EXP1=checkEXP(EXP1);
            if(flag==1&&M1==0)break;
            if(flag==0&&double(paidMoney)>(money*1.0/2))break;

            
            if(EXP1<300){
                M1-=100;
                paidMoney+=100;
            }
            else {
                M1-=120;
                paidMoney+=120;
            }
            EXP1=ceil(double(EXP1)*0.9);
            EXP1=checkEXP(EXP1);
            M1=checkMoney(M1);
            if(flag==1)break;
            if(flag&&M1==0)break;
            if(flag==0&&double(paidMoney)>(double(money)/2))break;


        }
        //after tracing the 2nd path
        HP1=ceil(double(HP1)-double(HP1)*0.17);
        HP1=checkHP(HP1);
        EXP1=ceil(double(EXP1)+double(EXP1)*0.17);
        EXP1=checkEXP(EXP1);

        if(EXP1<1){
            P2=double(80)/123;
        }else{
            int x=pow(floor(sqrt(EXP1)),2);
            int y=pow(ceil(sqrt(EXP1)),2);

        //Calculate P2
            int S;
            if(EXP1-x>y-EXP1) S=y;
            else  S=x;
            if(EXP1>=S)P2=1.0;
            else P2=(double(EXP1)/S+80)/123;
        }
        //Checkings
       // cout<<"P2: "<<P2<<endl;
        //PATH 3

        int P[10]={32,47,28,79,100,50,22,83,64,11};
        if(E2<10)P3=double(P[E2])/100;
        else{
            int t=E2/10+E2%10;
            P3=P[t%10]*1.0/100;
        }

       // cout<<P1<<" "<<P2<<" "<<P3<<endl;
            if(P1==P2&&P2==P3&&P3==1){
                HP1=HP;
                EXP1=EXP;
                M1=M;
                
                EXP=ceil(double(EXP)-double(EXP)*0.25);
                EXP=checkEXP(EXP);
                EXP1=EXP;
            //    cout<<"looping"<<endl;
            }
            else break;
        
    }
        double percent=(P1+P2+P3)/3;
        if(percent<0.5){
            HP1=ceil(double(HP1)-double(HP1)*0.15);
            HP1=checkHP(HP1);
            EXP1=ceil(double(EXP1)+double(EXP1)*0.15);
            EXP1=checkEXP(EXP1);

        }
        else{
            HP1=ceil(double(HP1)-double(HP1)*0.1);
            HP1=checkHP(HP1);
            EXP1=ceil(double(EXP1)+double(EXP1)*0.2);
            EXP1=checkEXP(EXP1);
          //  cout<<EXP1<<endl;
        }
    
    //Checking
    return HP1 + EXP1 + M1;
}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3<0||E3>99)return -99;
    int pos=0,neg=0;
    // TODO: Complete this function
    int array[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            array[i][j]=0;
 
        }
        
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            array[i][j]=((E3*j)+(i*2))*(i-j);
            if(array[i][j]>(E3*2))pos++;
            else if(array[i][j]<(0-E3))neg++;
        }
    }

    //Taking the location
    int taxi_i=takingLocation(pos);
    int taxi_j=takingLocation(neg);
 
    int max_left = traverse_left(taxi_i,taxi_j,array);
 
    int max_right = traverse_right(taxi_i,taxi_j,array);


    
    //Finding the max
    int max = (max_left>max_right)?max_left:max_right;


    //Checking
    if(max<abs(array[taxi_i][taxi_j])){
        EXP1=ceil(double(EXP1)-double(EXP1)*0.12);
        EXP1=checkEXP(EXP1);
        EXP2=ceil(double(EXP2)-double(EXP2)*0.12);
        EXP2=checkEXP(EXP2);

        HP1=ceil(double(HP1)-double(HP1)*0.1);
        HP1=checkHP(HP1);
        HP2=ceil(double(HP2)-double(HP2)*0.1);
        HP2=checkHP(HP2);
        return array[taxi_i][taxi_j];   
    }
    else{
        EXP1=ceil(double(EXP1)+double(EXP1)*0.12);
        EXP1=checkEXP(EXP1);
        EXP2=ceil(double(EXP2)+double(EXP2)*0.12);
        EXP2=checkEXP(EXP2);


        HP1=ceil(double(HP1)+double(HP1)*0.1);    
        HP1=checkHP(HP1);
        HP2=ceil(double(HP2)+double(HP2)*0.1);
        HP2=checkHP(HP2);
        return max;

    }
    return 0;
}

// Task 4
int checkingLexer(char x){
    if(x=='@'||x=='#'||x=='%'||x=='$'||x=='!')return 1;
    else if(
    x=='a'||x=='b'||x=='c'||x=='d'||x=='e'||x=='f'||x=='g'||x=='h'||x=='i'||x=='j'||x=='k'||x=='l'||x=='m'
    ||x=='n'||x=='o'||x=='p'||x=='q'||x=='r'||x=='s'||x=='t'||x=='u'||x=='v'||x=='w'||x=='x'||x=='y'||x=='z'
    ||x=='A'||x=='B'||x=='C'||x=='D'||x=='E'||x=='F'||x=='G'||x=='H'||x=='I'||x=='J'||x=='K'||x=='L'||x=='M'
    |x=='N'||x=='O'||x=='P'||x=='Q'||x=='R'||x=='S'||x=='T'||x=='U'||x=='V'||x=='W'||x=='X'||x=='Y'||x=='Z'
    ||x=='0'||x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9')
        return 2;
    else return 3;
}


int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se="";
    string s_temp=s;
    int s_len=strlen(s);
    int email_len=strlen(email);
    int char_count=0;
    for(int i=0;i<email_len;i++){
        if(email[i]!='@')se+=email[i];
        else break;
    }
    if(s_len<8)return -1;
    else if(s_len>20)return -2;
    int found = s_temp.find(se);
    if(found!=string::npos)return 0-(300+found);

    for(int i=0;i<s_len;i++){
        if(checkingLexer(s[i])==1){
        char_count++;
            if(checkingLexer(s[i+1])==1&&s[i]==s[i+1]&&s[i+2]==1&&s[i+2]==s[i])return 0-(400+i);
        }
        else if(checkingLexer(s[i])==3)return i;
        
    }
    if(char_count==0)return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string* array=new string[num_pwds];
    int* num_arr=new int[num_pwds];
    for(int i=0;i<num_pwds;i++){
        array[i]=arr_pwds[i];
        num_arr[i]=0;
       // cout<<array[i]<<" ";
    }
 /*   cout<<endl;
    for(int i=0;i<num_pwds;i++){
        cout<<num_arr[i]<<" ";
    }
    cout<<endl;*/
    for(int i=0;i<num_pwds;i++){
        if(array[i]!=""){
            for(int j=i+1;j<num_pwds;j++){
                if(array[i]==array[j]){
                    num_arr[i]++;
                    array[j]="";
                }
            }
        }
    }
  /*  for(int i =00;i<num_pwds;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<num_pwds;i++){
        cout<<num_arr[i]<<" ";
    }
    cout<<endl;*/
    int max=-1;
    int len=-999;
    int pos=-1;
    for(int i=0;i<num_pwds;i++){
        if(array[i]!=""){
            if(num_arr[i]>max){
                len=array[i].length();
                max=num_arr[i];
                pos=i;
            }
            else if(num_arr[i]==max&&array[i].length()>len){
                len=array[i].length();
                max=num_arr[i];
                pos=i;
            }
        }
    }
   // cout<<"/////////////////////////////////////////////////////////////"<<endl;
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////