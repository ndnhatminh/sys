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
int checkHP(float HP){
    if (HP>666)
       HP=666;
    else{
        if (HP<0)
           HP=0;
        else HP=HP;
    }
    return HP;
}
int checkEXP(float EXP){
    if (EXP>600)
       EXP=600;
    else{
        if (EXP<0)
           EXP=0;
        else EXP=EXP;
    }
    return EXP;
}
int checkM(float M){
    if (M>3000)
       M=3000;
    else{
        if (M<0)
           M=0;
        else M=M;
    }
    return M;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1<0||e1>99)
       return -99;
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    if (e1<4){
       if (e1 == 0){
          exp2 += 29;
          exp2 = checkEXP(exp2);
       }
       if (e1 == 1){
          exp2 += 45;
          exp2 = checkEXP(exp2);
       }
       if (e1 == 2){
          exp2 += 75;
          exp2 = checkEXP(exp2);
       }
       if (e1 == 3){
          exp2 += (29 + 45 + 75);
          exp2 = checkEXP(exp2);
       }
       int D = e1*3 + exp1*7;
       if (D%2==0){
          exp1=ceil(exp1+(double)D/200);
          exp1 = checkEXP(exp1);
       }
       else{
          exp1 = ceil(exp1-(double)D/100);
          exp1 = checkEXP(exp1);
       }
    }
    if(3<e1&&e1<100){
       if (4<=e1 && e1<=19){
          exp2 += ceil((double)e1/4+19);
          exp2 = checkEXP(exp2);
       }
       if (20<=e1 && e1 <=49){
          exp2 += ceil((double)e1/9+21);
          exp2 = checkEXP(exp2);
       }
       if (50<=e1 && e1 <=65){
          exp2 += ceil((double)e1/16+17);
          exp2 = checkEXP(exp2);
       }
       if (66<=e1 && e1 <=79){
          exp2 += ceil((double)e1/4+19);
          exp2 = checkEXP(exp2);
          if (exp2>200){
             exp2 += ceil((double)e1/9+21);
             exp2 = checkEXP(exp2);
          }
       }
       if (80<=e1 && e1 <=99){
          exp2 += ceil((double)e1/4+19);
          exp2 = checkEXP(exp2);
          exp2 += ceil((double)e1/9+21);
          exp2 = checkEXP(exp2);
          if (exp2>400){
             exp2 += ceil((double)e1/16+17);
             exp2 = checkEXP(exp2);
             exp2 = ceil((double)exp2*1.15);
            exp2 = checkEXP(exp2);
          }

          
       }
    exp1 -= e1;
    exp1 = checkEXP(exp1);
     }
     return exp1 + exp2;

}
    
   
// Task 2
int ClosestPerfectSquare(int x){
    int i = 2;
    int num;
    while (1){
        i+=1;
        if (pow(i,2)>x)
           break;
    }
    i -= 1;
    if ((x-pow(i,2))<(pow(i+1,2)-x))
       num = pow(i,2);
    else num = pow(i+1,2);
    return num;
}
class MultiValue{
public:
    float HP1;
    float EXP1;
    float M1;
};
MultiValue street_2(int HP, int M_ini, int EXP, int E2){
     int M_then = M_ini;
     int paid = 0;
     while (1){
     if(HP<200){
        HP=ceil((double)HP*1.3);
        HP = checkHP(HP);
        M_then-=150;
        M_then = checkM(M_then);
        paid += 150;
     }
     else{
        HP=ceil((double)HP*1.1);
        HP = checkHP(HP);
        M_then-=70;
        M_then = checkM(M_then);
        paid += 70;
     }
     if((paid>(M_ini/2)&&(E2%2==1))||((E2%2==0)&&(M_then<=0))){
        HP=ceil((double)HP*0.83);
        HP = checkHP(HP);
        EXP=ceil((double)EXP*1.17);
        EXP = checkEXP(EXP);
        break;
     }
        if(EXP<400){
          M_then-=200;
          M_then = checkM(M_then);
          paid += 200;
        }
        else {
            M_then-=120;
            M_then = checkM(M_then);
            paid += 120;
        }
        EXP=ceil((double)EXP*1.13);
        EXP = checkEXP(EXP);
        if((paid>(M_ini/2)&&(E2%2==1))||((E2%2==0)&&(M_then<=0))){
          HP=ceil((double)HP*0.83);
          HP = checkHP(HP);
          EXP=ceil((double)EXP*1.17);
          EXP = checkEXP(EXP);
          break;
        }
          if (EXP<300){
             M_then-=100;
             M_then = checkM(M_then);
             paid += 100;
          }
          else {
              M_then-=120;
              M_then = checkM(M_then);
              paid += 120;
          }
          EXP=ceil((double)EXP*0.9);
          if((paid>(M_ini/2)&&(E2%2==1))||((E2%2==1)&&(M_then<=0))){
             HP=ceil((double)HP*0.83);
             HP = checkHP(HP);
             EXP=ceil((double)EXP*1.17);
             EXP = checkEXP(EXP);
             break;
        }
        }
    MultiValue multivalue;
    multivalue.HP1=HP;
    multivalue.EXP1=EXP;
    multivalue.M1=M_then;
    return multivalue;
}
int Find_i(int E2){
    int digit1 = E2%10;
    int digit2 = E2/10;
    int sum = digit1+digit2;
    int i = sum%10;
    return i;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0 ||E2>99)
       return -99;
    int S1 = ClosestPerfectSquare(EXP1);
     float P1;
     if (EXP1>=S1)
        P1 = 1;
     else P1=(EXP1/S1+80)/123;
     MultiValue multivalue = street_2(HP1, M1, EXP1, E2);
     HP1= multivalue.HP1;
     EXP1=multivalue.EXP1;
     M1=multivalue.M1;
     int S2 = ClosestPerfectSquare(EXP1);
     float P2;
     if (EXP1>=S2)
        P2 = 1;
     else P2=(EXP1/S2+80)/123;
     int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
     float P3;
     int i;
     if(E2<10){
       i = E2;
       P3=ceil(P[i]/100);
     }
     else{
       i = Find_i(E2);
       P3=P[i];
     }
     if (P1==1&&P2==1&&P3==1){
       EXP1=ceil((double)EXP1*0.75);
       EXP1 = checkEXP(EXP1);
     }
     else{
         float P = (P1+P2+P3)/3;
         if (P<0.5){
            HP1=ceil((double)HP1*0.85);
            HP1 = checkHP(HP1);
            EXP1=ceil((double)EXP1*1.15);
            EXP1 = checkEXP(EXP1);
         }
         else{
            HP1=ceil((double)HP1*0.9);
            HP1 = checkHP(HP1);
            EXP1=ceil((double)EXP1*1.20);
            EXP1 = checkEXP(EXP1);
         }
     }
    return HP1 + EXP1 + M1;
}

// Task 3
int sum_digit(int x){
    int digit1 = x%10;
    int digit2 = x/10;
    int sum = digit1+digit2;
    return sum;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int taxi[10][10];
    int count_i=0;
    int count_j=0;
    int taxi_score;
    int result;
    for (int i =0;i<10;i++){
        for (int j =0;j<10;j++){
            taxi_score = ((E3*j) + (i*2))*(i-j);
            taxi[i][j]=taxi_score;
            if(taxi_score>(E3*2)){
               count_i++;
               if (count_i<10)
                 count_i=count_i;
               else count_i=sum_digit(count_i);
            }
            if(taxi_score<-E3){
               count_j++;
               if (count_j<10)
                 count_j=count_j;
               else count_j=sum_digit(count_j);
            }
        }
    }
    taxi_score=taxi[count_i][count_j];
    int SandW_score=taxi[count_i][count_j];
    int i_position = count_i;
    int j_position = count_j;
    while(i_position>=0&&j_position>=0){
        i_position--;
        j_position--;
        if(taxi[i_position][j_position]>SandW_score)
          SandW_score=taxi[i_position][j_position];
    }
    i_position = count_i;
    j_position = count_j;
    while(i_position<=9&&j_position<=9){
        i_position++;
        j_position++;
        if(taxi[i_position][j_position]>SandW_score)
          SandW_score=taxi[i_position][j_position];
    }
    i_position = count_i;
    j_position = count_j;
    while(i_position>=0&&j_position<=9){
        i_position--;
        j_position++;
        if(taxi[i_position][j_position]>SandW_score)
          SandW_score=taxi[i_position][j_position];
    }
    i_position = count_i;
    j_position = count_j;
    while(i_position<=9&&j_position>=0){
        i_position++;
        j_position--;
        if(taxi[i_position][j_position]>SandW_score)
          SandW_score=taxi[i_position][j_position];
    }
    int abs_taxi_score;
    if (taxi_score<0)
       abs_taxi_score=abs(taxi_score);
    if(abs_taxi_score>SandW_score){
        EXP1=ceil((double)EXP1*0.88);
        EXP2=ceil((double)EXP2*0.88);
        HP1=ceil((double)HP1*0.9);
        HP2=ceil((double)HP2*0.9);
        result = taxi_score;
    }
    else{
        EXP1=ceil((double)EXP1*1.12);
        EXP2=ceil((double)EXP2*1.12);
        HP1=ceil((double)HP1*1.1);
        HP2=ceil((double)HP2*1.1);
        result = SandW_score;
    }
    return result;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    string str = s;
    string eml = email;
    int i = eml.find("@");
    string se = eml.substr(0,i);
    int result;
    int sci = 0;
    if (str.length()<8)
       result = -1;
    else{
        if (str.length()>20)
           result = -2;
        else {
            if (str.find(se)>=0)
                result =  -(300+str.find(se));
            else{
                while (sci<str.length()){
                    if (str.substr(sci,1)==str.substr(sci+1,1)){
                       result = -(400+sci);
                       break;
                    }
                    if (str.substr(sci,1)=="@"||str.substr(sci,1)=="#"||str.substr(sci,1)=="%"||str.substr(sci,1)=="$"||str.substr(sci,1)=="!"){
                        result = -10;
                        break;
                    }
                    else result = -5;
                    sci+=1;
                }
            }
        }
    }
    return result;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string array_pwds[30];
    string correct_pwds;
    int count_lim =0;
    int len_lim=0;
    int result;
    for (int i = 0; i<num_pwds; i++){
        string pwds = arr_pwds[i];
        int count =0;
        for (int j = 0;j<num_pwds;j++){
            if (pwds == arr_pwds[j])
               count++;
        }
        if (count>count_lim||count==count_lim&&pwds.length()>len_lim){
            correct_pwds = pwds;
            count_lim = count;
            len_lim=pwds.length();
        }
    }
    for (int pos = 0;pos<num_pwds;pos++){
        if (arr_pwds[pos]==correct_pwds){
           result = pos;
           break;
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
