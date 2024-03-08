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
int check_task1(int & exp1, int & exp2){
	if(exp2>600){
		exp2=600;
	}
	if(exp1>600){
		exp1=600;
	}
	if(exp1<0){
		exp1=0;
	}
	if(exp2<0){
		exp2=0;
	}
	return exp1+exp2;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

	//điều kiện của e1
    if(e1>=0&&e1<=99){
    	check_task1(exp1, exp2);
    	if(e1<4){ //TH1
    		if(e1==0){
				exp2=exp2+29;
			}
			else if(e1==1){
				exp2=exp2+45;
			}
			else if(e1==2){
				exp2=exp2+75;
			}
			else if(e1==3){
				exp2=exp2+29+45+75;
			}
			int D=e1*3+exp1*7;
			if(D%2==1){
				exp1=ceil(exp1-D*1.0/100);
			}
			else exp1=ceil(exp1+D*1.0/200);
		}
		else{ //TH2
			if(e1>=4&&e1<20){
				exp2=ceil(exp2+e1*1.0/4+19); //thông tin 1
			}
			else if(e1>=20&&e1<50){
				exp2=ceil(exp2+e1*1.0/9+21); //thông tin 2
			}
			else if(e1>=50&&e1<66){
				exp2=ceil(exp2+e1*1.0/16+17); //thông tin 3
			}
			else if(e1>=66&&e1<80){
				exp2=ceil(exp2+e1*1.0/4+19);
				check_task1(exp1, exp2);				
				if(exp2>200){
					exp2=ceil(exp2+e1*1.0/9+21);
					check_task1(exp1, exp2);
				}
			}
			else if(e1>=80&&e1<100){
				exp2=ceil(exp2+e1*1.0/4+19);
				check_task1(exp1, exp2);
				exp2=ceil(exp2+e1*1.0/9+21);
				check_task1(exp1, exp2);
				if(exp2>400){
					exp2=ceil(exp2+e1*1.0/16+17);
					exp2=ceil(exp2*115.0/100);
					check_task1(exp1, exp2);
				}
			}
			exp1=exp1-e1;
		}
	check_task1(exp1, exp2);	
	return exp1 + exp2;
	}
	else return -99;
}
	
int check_task2(int & HP1, int & EXP1, int & M1){
	if(HP1>666){
		HP1=666;
	}
	if(EXP1>600){
		EXP1=600;
	}
	if(M1>3000){
		M1=3000;
	}
	if(HP1<0){
		HP1=0;
	}
	if(EXP1<0){
		EXP1=0;
	}
	if(M1<0){
		M1=0;
	}
	return HP1+EXP1+M1;
}
/// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2>=0&&E2<=99){
	    double P, P1, P2, P3;
	    double sqrt_EXP1;
		int S;
		check_task2(HP1, EXP1, M1);
		
		//con đường 1
		sqrt_EXP1=sqrt(EXP1);
		if((EXP1-pow(floor(sqrt_EXP1), 2))>(pow(floor(sqrt_EXP1)+1, 2)-EXP1)){
			S=pow(floor(sqrt_EXP1)+1, 2);
		}
		else S=pow(floor(sqrt_EXP1), 2);
		if(EXP1>=S){
			P1=1.0;
		}
		else P1=(EXP1*1.0/S+80)/123;
		
		//con đường 2
		double first_M1=M1/2;
		if(E2%2==1){ //e2 lẻ
			while(M1>=first_M1){
				//mua đồ
				if(HP1<200){
					HP1=ceil(HP1*13.0/10);
					M1=M1-150;
					check_task2(HP1, EXP1, M1);
				}
				else {
					HP1=ceil(HP1*11.0/10);
					M1=M1-70;
					check_task2(HP1, EXP1, M1);				
				}
				if(M1>=first_M1){ //thuê xe di chuyển
					if(EXP1<400){
						M1=M1-200;
					} 
					else M1=M1-120;
					EXP1=ceil(EXP1*113.0/100);
					check_task2(HP1, EXP1, M1);					
					if(M1>=first_M1){ //cho tiền người vô gia cư
						if(EXP1<300){
							M1=M1-100;
						}
					else M1=M1-120;
					EXP1=ceil(EXP1*9.0/10);
					check_task2(HP1, EXP1, M1);
					}
				}
			}
		}
		else { //e2 chẵn 
			if(M1>0){
				//mua đồ
				if(HP1<200){
				HP1=ceil(HP1*13.0/10);
				M1=M1-150;
				check_task2(HP1, EXP1, M1);
				}
				else{
				HP1=ceil(HP1*11.0/10);
				M1=M1-70;
				check_task2(HP1, EXP1, M1);
				}
				if(M1>0){
					//thuê xe di chuyển
					if(EXP1<400){
						M1=M1-200;
					} 
					else M1=M1-120;
					EXP1=ceil(EXP1*113.0/100);
					check_task2(HP1, EXP1, M1);
					if(M1>0){ //cho tiền người vô gia cư
						if(EXP1<300){
							M1=M1-100;
						}
						else M1=M1-120;
						EXP1=ceil(EXP1*9.0/10);
						check_task2(HP1, EXP1, M1);
					}
				}
			}
		}
		HP1=ceil(HP1*83.0/100);
		EXP1=ceil(EXP1*117.0/100);
		check_task2(HP1, EXP1, M1);
				
		sqrt_EXP1=sqrt(EXP1);
		if((EXP1-pow(floor(sqrt_EXP1), 2))>(pow(floor(sqrt_EXP1)+1, 2)-EXP1)){
			S=pow(floor(sqrt_EXP1)+1, 2);
		}
		else S=pow(floor(sqrt_EXP1), 2);
		if(EXP1>=S){
			P2=1.0;
		}
		else P2=(EXP1*1.00/S+80)/123;
		
		//con đường 3
		int xacsuat[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
		P3=xacsuat[(E2%10+E2/10)%10]*1.0/100;
		
		//kết thúc NV
		P=(P1+P2+P3)/3;
		if(P==1.0){
			EXP1=ceil(EXP1*75.0/100);
		}
		else {
			if(P<0.5){
				HP1=ceil(HP1*85.0/100);
				EXP1=ceil(EXP1*115.0/100);
			}
			else {
				HP1=ceil(HP1*9.0/10);
				EXP1=ceil(EXP1*12.0/10);
			}
		}
		check_task2(HP1, EXP1, E2);
	    return HP1 + EXP1 + M1;
	}
    else return -99;
}

int check_task3(int & HP1, int & EXP1, int & HP2, int & EXP2){
	if(HP1>666){
		HP1=666;
	}
	if(EXP1>600){
		EXP1=600;
	}
	if(HP2>666){
		HP2=666;
	}
	if(EXP2>600){
		EXP2=600;
	}
	if(HP1<0){
		HP1=0;
	}
	if(EXP1<0){
		EXP1=0;
	}
	if(HP2<0){
		HP2=0;
	}
	if(EXP2<0){
		EXP2=0;
	}
	return HP1+EXP1+HP2+EXP2;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3>=0&&E3<=99){
	    //giá trị điểm taxi đi qua
		int taxi[10][10];
	    int i, j, i_meet=0, j_meet=0;
	    for(i=0; i<10; i++){
	    	for(j=0; j<10; j++){
	    		taxi[i][j]= (E3*j+(i*2))*(i-j);
	    		if(taxi[i][j]>E3*2){
	    			i_meet=i_meet+1;
				}
				if(taxi[i][j]<-E3){
					j_meet=j_meet+1;
				}
			}
		}
		
		//tìm ô gặp nhau
		while(i_meet>9){
			i_meet=i_meet%10+(i_meet-i_meet%10)/10;
		}
		while(j_meet>9){
			j_meet=j_meet%10+(j_meet-j_meet%10)/10;
		}
		int meet=taxi[i_meet][j_meet];
		
		
		//giá trị điểm của Sherlock
		int max=meet;
		i=i_meet;
		j=j_meet;
		while(i>=1&&j>=1){
			if(taxi[i-1][j-1]>max){
				max=taxi[i-1][j-1];
			}
			i--;
			j--;
		}
		
		i=i_meet;
		j=j_meet;
		while(i<=8&&j<=8){
			if(taxi[i+1][j+1]>max){
				max=taxi[i+1][j+1];
			}
			i++;
			j++;
		}
	
		i=i_meet;
		j=j_meet;
		while(i>=1&&j<=8){
			if(taxi[i-1][j+1]>max){
				max=taxi[i-1][j+1];
			}
			i--;
			j++;
		}
		
		i=i_meet;
		j=j_meet;
		while(i<=8&&j>=1){
			if(taxi[i+1][j-1]>max){
				max=taxi[i+1][j-1];
			}
			i++;
			j--;
		}
		
		//kết thúc 
		int trave;
		if(abs(meet)>abs(max)){
			EXP1=ceil(EXP1*88.0/100);
			EXP2=ceil(EXP2*88.0/100);
			HP1=ceil(HP1*9.0/10);
			HP2=ceil(HP2*9.0/10);
			trave=meet;
		}
		else{
			EXP1=ceil(EXP1*112.0/100);
			EXP2=ceil(EXP2*112.0/100);
			HP1=ceil(HP1*11.0/10);
			HP2=ceil(HP2*11.0/10);
			trave=max;
		}
		check_task3(HP1, EXP1, HP2, EXP2);
	    return trave;
	}
	else return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int re=-10;	
	int i;
	int j;
	int x=0;
	char spec_kitu[]={'@', '#', '%', '$', '!'};
	int val;
	
	//kí tự hợp lệ
		for(i=strlen(s)-1;i>=0;i--){
			val=s[i];
			if(val !='!'&& val != '@'&& val !='$'){
				if(val !='#'&&val !='%'){
					if(val<'0'||val>'9'){
						if(val<'A'||val>'Z'){
							if(val<'a'||val>'z'){
								re=i;
							}
						}
					}
				}
			}
		}
	
	//kí tự đặc biệt
	for(i=0; i<strlen(s); i++){
		for(j=0; j<strlen(spec_kitu); j++){
			if(s[i]==spec_kitu[j]){
				x=x+1;
			}
		}
	}
	if(x==0){
		re=-5;
	}
	
	//liên tiếp giống nhau
	if(strlen(s)>2){
	    for(i=0; i< strlen(s)-2; i++){
	    	if(s[i]==s[i+1]&&s[i]==s[i+2]){
	    		re=-(400+i);
	    		break;
			}
		}
	}
	
	//không chứa chuỗi se
	int kitu_se;
	for(i=0; i<=strlen(email); i++){
		if(email[i]=='@'){
			kitu_se=i;	
		}
	}
	char se[100];
	string str_email(email);
	string str_s(s);
	size_t length_se;
	length_se=str_email.copy(se,kitu_se);
	se[length_se]= '\0'; //tìm chuỗi se

	size_t posi=str_s.find(se);
	if(posi<=strlen(s)){
		re=-(300+posi);
	}

	//< 8 kí tự và > 20 kí tự
	if(strlen(s)<8){
		re=-1;
	}
	if(strlen(s)>20){
		re=-2;
	}
    return re;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int re=0, max_f=0, max_size=0;
    //so sánh tần số
	for(int i=0;i<num_pwds;i++){
		int f=0;
	 	string c=arr_pwds[i];
	 	for(int j=0;j<num_pwds;j++){
			if(c.compare(arr_pwds[j])==0){
				f++;
			}
		}
		if(f>=max_f){
			max_f=f;
		}
	}
	
	//so sánh độ dài
	for(int i=0;i<num_pwds;i++){
		int f=0;
	 	string c=arr_pwds[i];
	 	for(int j=0;j<num_pwds;j++){
			if(c.compare(arr_pwds[j])==0){
				f++;
			}
		}
		if(f==max_f){
			if(c.size()>max_size){
				max_size=c.size();
				re=i;
			}
		}
	}
    return re;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////