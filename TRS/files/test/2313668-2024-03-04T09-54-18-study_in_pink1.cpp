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
void check_hp(int &hp){
    if(hp>666){
        hp=666;
    }
    if(hp<0){
        hp=0;
    }
    
}
int check_int(int exp1){
	int ans1=round(sqrt(exp1));
	return ans1*ans1;
}
void check_exp(int &exp){
    if(exp>600){
        exp=600;
    }
    if(exp<0){
        exp=0;
    }
    
}

void check_m(int &m){
    if(m>3000){
        m=3000;
    }if(m<0){
        m=0;
    }
    
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0||e1>99){
        return -99;
    }
    if(e1<=3&&e1>=0){
		if(e1==0){
			exp2+=29;
		}else if(e1==1){
			exp2+=45;
		}else if(e1==2){
			exp2+=75;
		}else{
			exp2+=149;
		}
        check_exp(exp2);
		int d=e1*3+exp1*7;
		if(d%2==0){
            double a=(float)d/200;
			exp1=ceil(exp1+a);
		}else{
            float b=(float)d/100;
			exp1=ceil(exp1-b);
		}
        check_exp(exp1);
	}if(e1<=99&&e1>=4){
		if(e1>=4&&e1<=19){
			exp2+=ceil((float) e1/4+19);
		}else if(e1>=20&&e1<=49){
			exp2+=ceil((float) e1/9+21);
		}else if(e1>=50&&e1<=65){
			exp2+=ceil((float) e1/16+17);
		}else if(e1>=66&&e1<=79){
			exp2+=ceil((float) e1/4+19);
            check_exp(exp2);
			if(exp2>200){
				exp2+=ceil((float) e1/9+21);
			}
            check_exp(exp2);
		}else {
			exp2+=ceil((float) e1/4+19);
            check_exp(exp2);
            exp2+=ceil((float) e1/9+21);
            check_exp(exp2);
			if(exp2>400){
				exp2+=ceil((float) e1/16+17);
                check_exp(exp2);
				exp2=ceil((float) 1.15*exp2);
                check_exp(exp2);
			}
		}
        check_exp(exp2);
		exp1-=e1;
        check_exp(exp1);	
	}
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int S=check_int(EXP1);
	int startM=M1; 
	float p1;
    if(E2<0||E2>99){
        return -99;
    }
    else {    
    //Con duong 1
        if(EXP1>=S){
            p1=1;
        }else{
            float kq=EXP1/S;
            p1=(kq+80)/123.0;
        }
        //Con duong 2
    int t=1;
        float a=0.5*startM;
        if(E2%2!=0){
            while(1){
                if(HP1<200){
                    float hp1=HP1*1.3;
                    HP1=ceil(hp1);
                    M1-=150;
                }
                else{
                    float hp1=HP1*1.1;
                    HP1=ceil(hp1);
                    M1-=70;
                }
                check_hp(HP1);
                if(startM-M1-a>0){
                    check_m(M1);
                    break;}
                if(EXP1<400){
                    M1-=200;
                }else{
                    M1-=120;
                }   
                EXP1=ceil(EXP1*1.13);
               
                if(startM-M1-a>0){check_m(M1);break;}
                if(EXP1<300){
                    M1-=100;
                }else{
                    M1-=120;
                }
                EXP1=ceil(EXP1*0.9);
                if(startM-M1-a>0){check_m(M1);break;}
            }
        }else{
            while(t--){            
            if(HP1<200){
                float hp1=HP1*1.3;
                HP1=ceil(hp1);
                M1-=150;
            }
            else{
                float hp1=HP1*1.1;
                HP1=ceil(hp1);
                M1-=70;
            }
            check_hp(HP1);
            if(M1<0){
                check_m(M1);
                break;
            }
            if(EXP1<400){
                M1-=200;
            }else{
                M1-=120;
            }
            EXP1=ceil(EXP1*1.13);
            if(M1<0){
                check_m(M1);
                break;
            }
            if(EXP1<300){
                M1-=100;
            }else{
                M1-=120;
            }
            check_m(M1);
            EXP1=ceil(EXP1*0.9);
        }
    }
    EXP1=ceil(EXP1*1.17);
    HP1=ceil(HP1*0.83);
    check_hp(HP1);    
    check_exp(EXP1);
        int S2=check_int(EXP1);
        float p2;
        if(EXP1>=S2){
            p2=1;
        }else{
            float kq1=EXP1/S;
            p2=(kq1+80)/123.0;
        }
        //Con duong 3
        float p3;
        float arr[10]={0.32,0.47,0.28,0.79,1,0.50,0.22,0.83,0.64,0.11};
        if(E2<10){
            p3=arr[E2];
        }else{
            int kq=E2%10+E2/10;
            p3=arr[kq%10];
        }
        //Tinh xac suat
        if(p1==1.0&&p2==1.0&&p3==1.0){
                EXP1=ceil(EXP1*0.75);
                check_exp(EXP1);
        }else{
            float avg=(p1+p2+p3)/3;
            if(avg<0.5){
                HP1=ceil((float)HP1*0.85);
                check_hp(HP1);
                EXP1=ceil((float)EXP1*1.15);
                check_exp(EXP1);
            }else{
                HP1=ceil((float)HP1*0.9);
                check_hp(HP1);
                EXP1=ceil((float)EXP1*1.2);
                check_exp(EXP1);
            }
        }
        return HP1+EXP1+M1;
    }
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int count_i=0;
    int count_j=0;
    int arr[10][10];
    if(E3<0||E3>99){
        return -99;
    }else{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            arr[i][j]=((E3*j)+i*2)*(i-j);
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]>(E3*2)){
                count_i++;
            }
            if(arr[i][j]<-(E3)){
                count_j++;
            }
        }
    }
    while(count_i>=10){
        count_i=count_i/10+count_i%10;
    }
    while(count_j>=10){
        count_j=count_j/10+count_j%10;
    }
    int maxValue=arr[count_i][count_j];
    int point=maxValue;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(abs(count_i-i)==abs(count_j-j)){
                if(arr[i][j]>maxValue){
                    maxValue=arr[i][j];
                }
            }
        }
    }
    int check1=abs(maxValue);
    int check=abs(point);
    if(check>maxValue){
        float exp1=EXP1*0.88;
        float exp2=EXP2*0.88;
        float hp2=HP2*0.9;
        float hp1=HP1*0.9;
        EXP1=ceil(exp1);
        check_exp(EXP1);
        EXP2=ceil(exp2);
        check_exp(EXP2);
        HP1=ceil(hp1);
        check_hp(HP1);
        HP2=ceil(hp2);
        check_hp(HP2);
        return point;
    }else{
        float exp1=EXP1*1.12;
        float exp2=EXP2*1.12;
        float hp2=HP2*1.1;
        float hp1=HP1*1.1;
        EXP1=ceil(exp1);
        check_exp(EXP1);
        EXP2=ceil(exp2);
        check_exp(EXP2);
        HP1=ceil(hp1);
        check_hp(HP1);
        HP2=ceil(hp2); 
        check_hp(HP2);
        return maxValue;  
    }
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S1=s;
    string S2=email;
    bool check=true;
    string se;
    int length=S1.size();
    for(int i=0;i<S2.size();i++){
        if(email[i]=='@'){
            break;
        }else{
            se+=email[i];
        }
    }
    int count=0;
    if(length>=8&&length<=20){
            int pos=S1.find(se);
            if(pos!=-1){
                return -(300+pos);
            }else{
                for(int i=0;i<S1.size()-1;i++){
                    if(s[i]==s[i+1]&&s[i+1]==s[i+2]){
                        return -(400+i);
                        break;
                    }else{
                        continue;
                    }
                }
                for(int j=0;j<S1.size();j++){
                    if((s[j]>37||s[j]<35)&&(s[j]!=64&&s[j]!=33)){
                        count++;
                    }
                }
                if(count!=length){
                    check=true;
                }else{
                    check=false;
                }
                if(check){
                    for(int i=0;i<S1.size();i++){
                        if((s[i]>=48&&s[i]<=57)||(s[i]>=64&&s[i]<=90)||(s[i]>=97&&s[i]<=122)||s[i]==33||(s[i]>=35&&s[i]<=37)){
                            continue;
                        }else{
                            return i;
                            break;
                        }
                    }
                }else{
                    return -5;
                }
            }
        return -10;
    }else{
        if(length<8){
            return -1;
        }else{
            return -2;
        }
    }
}
// Task 5
int findCorrectPassword( const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int check_arr[num_pwds];
    for(int i=0;i<num_pwds;i++){
        check_arr[i]=0;
    }
    for(int i=0;i<num_pwds;i++){
        int count=1;
        for(int j=i+1;j<num_pwds;j++){
            if(strcmp(arr_pwds[i],arr_pwds[j])==0){
                count++;
            }
        }
        check_arr[i]=count;
    }
    int max=0;int max_pos=0;
    for(int i=0;i<num_pwds;i++){
        if(check_arr[i]>max){
            max=check_arr[i];
            max_pos=i;
        }else if(max==check_arr[i]){
            if(strlen(arr_pwds[i])>strlen(arr_pwds[max_pos])){
                max_pos=i;
            }
        }
    }
    for(int i=0;i<num_pwds;i++){
        if(strcmp(arr_pwds[max_pos],arr_pwds[i])==0){
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////