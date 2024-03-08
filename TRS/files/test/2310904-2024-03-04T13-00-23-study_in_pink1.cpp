#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

float nearestCP(float N)
{   float nearest;
    if((N-std::pow((std::floor(std::sqrt(N))),2))>(std::pow((std::floor(std::sqrt(N)))+1,2)-N))nearest=pow((std::floor(std::sqrt(N)))+1,2);
    else nearest =pow((std::floor(std::sqrt(N))),2);
    return nearest;
}
//! Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) 
 {  
    int D;
    float d, exp1, exp2, e1;
    e1=(float)E1;
    exp1=(float)EXP1;
    exp2=(float)EXP2;
   if (E1 < 0 || E1 > 99) return -99;

   if(E1>=0&&E1<=3)
   { switch(E1)
       {
          case 0:
          exp2+= 29;break;
          case 1:
          exp2+= 45;break;
          case 2:
          exp2+= 75;break;
          case 3:
          exp2+= 29 + 45 + 75;break;
       }
    
    D= E1*3 + EXP1*7;
    d= (float)D;
    if(D%2==0){exp1+= d/200;}
    else      {exp1-= d/100;}
   }
 
    if(E1>=4&&E1<=99)
   {    exp1=exp1 - e1;  
        if(E1>=4&&E1<=19) exp2+= + e1/4 + 19;
        if(E1>=20&&E1<=49)exp2+= + e1/9 + 21;
        if(E1>=50&&E1<=65)exp2+= + e1/16 +17;
        if(E1>=66&&E1<=79){exp2+= + e1/4 + 19;if(exp2!=(int)exp2)exp2=(int)exp2+1;

                           if(exp2>200)exp2+= + e1/9 + 21;
                          }
        if(E1>=80&&E1<=99){exp2+= + e1/4 + 19; if(exp2!=(int)exp2)exp2=(int)exp2+1;
                           exp2+= + e1/9 + 21; if(exp2!=(int)exp2)exp2=(int)exp2+1;

                           if(exp2>400){exp2+= + e1/16 +17;
                                        if(exp2!=(int)exp2)exp2=(int)exp2+1;
                                        exp2+= + (exp2*15)/100;
                                       }
                          }  
    
   }
     
    if(exp1!=(int)exp1) EXP1= (int)exp1 +1;
    else  EXP1=(int)exp1;
    if(exp2!=(int)exp2) EXP2= (int)exp2 +1;
    else  EXP2=(int)exp2; 
    if(EXP1<0)EXP1=0;
    if(EXP2<0)EXP2=0;  
    if(EXP1>600)EXP1=600;
    if(EXP2>600)EXP2=600;
       return EXP1 + EXP2 ;
}



int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
// TODO: Complete this function
    float hp1, exp1,m1,e2, spent=0,p1,p2,p3;
    hp1=(float)HP1; exp1=(float)EXP1; m1=(float)M1;
    if (E2 > 99 || E2 < 0)return -99;
    if(EXP1>=nearestCP(EXP1))p1=1.0;
    else p1=(exp1/nearestCP(EXP1)+80)/123.0; 
    if(m1>0){
    if(E2%2!=0)
    {  
        

        while(spent<=((M1*50)/100))
        {   //SK1
            if(hp1<200){ hp1=std::ceil(hp1*13.0/10); m1-=150;spent+=150;}
            else       { hp1=std::ceil(hp1*11.0/10); m1-=70;spent+=70;}
            if(hp1>666)hp1=666;
            if(m1<0)m1=0; 
            if(spent>((M1*50)/100)){hp1=std::ceil(hp1*0.83); exp1=std::ceil(exp1*1.17);
                                    if(hp1<0)hp1=0;if(exp1>600)exp1=600;
                                    break;}
        
            //SK2
            if(exp1<400){ exp1=std::ceil(exp1*113.0/100); m1-=200;spent+=200;}
            else        { exp1=std::ceil(exp1*113.0/100); m1-=120;spent+=120;}
            if(exp1>600)exp1=600;
            if(m1<0)m1=0;
            if(spent>((M1*50)/100)){hp1=std::ceil(hp1*0.83); exp1=std::ceil(exp1*1.17);
                                    if(hp1<0)hp1=0;if(exp1>600)exp1=600;
                                    break;}
            //SK3
            if(exp1<300){exp1=std::ceil(exp1*9.0/10); m1-=100;spent+=100;}
            else        {exp1=std::ceil(exp1*9.0/10); m1-=120;spent+=120;}
            if(exp1<0)exp1=0;
            if(m1<0)m1=0;
            if(spent>((M1*50)/100)){hp1=std::ceil(hp1*0.83); exp1=std::ceil(exp1*1.17);
                                    if(hp1<0)hp1=0;if(exp1>600)exp1=600;
                                    break;}   
        }
    } 
    else { 
            if(hp1<200){ hp1=std::ceil(hp1*13.0/10); m1-=150;}
            else       { hp1=std::ceil(hp1*11.0/10); m1-=70; }
            if(hp1>666)hp1=666;
            if(m1<=0)m1=0;
            if(m1>0)
            {if(exp1<400){ exp1=std::ceil(exp1*113.0/100); m1-=200; }
             else        { exp1=std::ceil(exp1*113.0/100); m1-=120; }
             if(exp1>600)exp1=600;
             if(m1<0)m1=0;
             if(m1>0)
          
            {if(exp1<300){exp1=std::ceil(exp1*9.0/10); m1-=100; }
            else         {exp1=std::ceil(exp1*9.0/10); m1-=120; }
            if(exp1<0)exp1=0;
            if(m1<0)m1=0;
            }
            else m1=0;
            }
            else m1=0;
            hp1=std::ceil(hp1*0.83); exp1=std::ceil(exp1*1.17);
         } 
    }
    else {hp1=std::ceil(hp1*0.83); exp1=std::ceil(exp1*1.17);}
        if(hp1<0)hp1=0;if(exp1>600)exp1=600;
        EXP1= exp1;
    if(EXP1>=nearestCP(EXP1))p2=1.0;
    else p2=(exp1/nearestCP(EXP1)+80)/123.0;     
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2<10)p3=P[E2]/100.0;
    else p3=P[(int(E2/10)+(E2-(int(E2/10))*10))-int((int(E2/10)+(E2-(int(E2/10))*10))/10)*10]/100.0;
    if(p1==p2&&p2==p3&&p1==p3)exp1=std::ceil(exp1*3.0/4.0);
    else {
        if((p1+p2+p3)/3.0<0.5){hp1=std::ceil(hp1*0.85);exp1=std::ceil(exp1*23.0/20.0);}
        else {hp1=std::ceil(hp1*9.0/10);exp1=std::ceil(exp1*6.0/5.0);};
         }
    if(exp1>600)exp1=600;
    if(hp1<0)hp1=0; 
    HP1=hp1; EXP1=exp1; M1=m1;
    return HP1 + EXP1 + M1;
} 


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
    float hp1,hp2,exp1,exp2;
    hp1=(float)HP1; hp2=(float)HP2; exp1=(float)EXP1; exp2=(float)EXP2;
    if(E3<0||E3>99)return -99;
    int taxi[10][10]={0}; int score[10][10]={0};
    int bigger=0, smaller=0;
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
    {
        taxi[i][j]=((E3*j)+(i*2))*(i-j);
        if(taxi[i][j]>(E3*2))bigger++;
        if(taxi[i][j]<-E3)smaller++;
    }
    //Tim vi tri gap nhau
    int pos_i=0,pos_j=0;
    pos_i=int(bigger/10)+bigger%10;pos_i=int(pos_i/10)+pos_i%10;
    pos_j=int(smaller/10)+smaller%10;pos_j=int(pos_j/10)+pos_j%10;
    //Tim diem lon nhat 
    score[pos_i][pos_j]=taxi[pos_i][pos_j];
    for(int i=0;i<10;i++){if(pos_i-i<0||pos_j-i<0)break;
                          else score[pos_i][pos_j]=std::max(score[pos_i][pos_j], taxi[pos_i-i][pos_j-i]);}
    for(int i=0;i<10;i++){if(pos_i+i>9||pos_j-i<0)break;
                          else score[pos_i][pos_j]=std::max(score[pos_i][pos_j], taxi[pos_i+i][pos_j-i]);}
    for(int i=0;i<10;i++){if(pos_i+i>9||pos_j+i>9)break;
                          else score[pos_i][pos_j]=std::max(score[pos_i][pos_j], taxi[pos_i+i][pos_j+i]);}
    for(int i=0;i<10;i++){if(pos_i-i<0||pos_j+i>9)break;
                          else score[pos_i][pos_j]=std::max(score[pos_i][pos_j], taxi[pos_i-i][pos_j+i]);} 
    //So sanh 
    if(abs(taxi[pos_i][pos_j])>score[pos_i][pos_j]){exp1=exp1-exp1*(12.0/100); if(int(exp1)!=exp1)EXP1=exp1+1;else EXP1=exp1;
                                                    hp1=hp1-float(hp1*(10.0/100));if(int(hp1)!=float(hp1))HP1=hp1+1;else HP1=hp1;
                                                    exp2=exp2-exp2*(12.0/100); if(int(exp2)!=exp2)EXP2=exp2+1;else EXP2=exp2;
                                                    hp2=hp2-float(hp2*(10.0/100));if(int(hp2)!=float(hp2))HP2=hp2+1;else HP2=hp2;
                                                    if(EXP1<0)EXP1=0;if(EXP2<0)EXP2=0;
                                                    if(HP1<0)HP1=0;if(HP2<0)HP2=0;}
                                              else {exp1=exp1+exp1*(12.0/100); if(int(exp1)!=exp1)EXP1=exp1+1;else EXP1=exp1;
                                                    hp1=hp1+float(hp1*(10.0/100));if(int(hp1)!=float(hp1))HP1=hp1+1;else HP1=hp1;
                                                    exp2=exp2+exp2*(12.0/100); if(int(exp2)!=exp2)EXP2=exp2+1;else EXP2=exp2;
                                                    hp2=hp2+float(hp2*(10.0/100));if(int(hp2)!=float(hp2))HP2=hp2+1;else HP2=hp2;
                                                    if(EXP1>600)EXP1=600;if(EXP2>600)EXP2=600;
                                                    if(HP1>666)HP1=666;if(HP2>666)HP2=666;
                                                    }
    
    if(abs(taxi[pos_i][pos_j])>score[pos_i][pos_j])
    return taxi[pos_i][pos_j];
    else return score[pos_i][pos_j];                    
    return -1;
}

// Task 4
int checkPassword(const char * S, const char * Email)
{
    //TODO: implement task
    std::string se;
    std::string s=std::string(S);
    std::string email=std::string(Email);
    size_t pos=email.find('@');
    se=email.substr(0,pos);
    int lens,check;
    lens=s.length();
    if(lens<8)return -1;
    if(lens>20)return -2;
    if(s.find(se)!=std::string::npos) return -(300+s.find(se));
    for(int i=0;s[i]!='\0';i++){if(s[i]==s[i+1]&&s[i+1]==s[i+2]&&s[i+2]==s[i])return -(400+i);}
    if(s.find('@')==std::string::npos&&s.find('#')==std::string::npos&&s.find('%')==std::string::npos&&s.find('$')==std::string::npos&&s.find('!')==std::string::npos)
    return -5;
    for(int i=0;s[i]!='\0';i++){if((s[i] >= 'a' && s[i] <= 'z' )  
                                   ||(s[i] >= 'A' && s[i] <= 'Z')  
                                   ||(s[i] >= '0' && s[i] <= '9')
                                   ||(s[i]=='@')||(s[i]=='#')||(s[i]=='%')||(s[i]=='$')||(s[i]=='!')) check++;
                                else {check=0; return i; break;}}
    if(check >0) return -10;
    
    return -1;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //Khai bao bien tan suat lon nhat
    int max1 = 0; 
    //Khai bao bien mat khau dung
    const char* correctPassword = nullptr;
    //Khai bao vi tri tra ve cua ham 
    int chiso; 
    for (int i = 0; i < num_pwds; ++i) {
        int tansuat = 1; 
    for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) {
                tansuat++;
            }
        }
    if (tansuat > max1 || (tansuat == max1 && strlen(arr_pwds[i]) > strlen(correctPassword))) {
            max1 = tansuat; 
            correctPassword = arr_pwds[i]; 
            chiso = i; 
        }
    }

    return chiso;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////