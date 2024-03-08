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
        int &E3
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
    } else {
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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    int* a = new int; // intentional memory leak to test sanitizer
    double exp1=EXP1;
    double exp2=EXP2;
    double e1=E1;
    	if(E1==0){
    		exp2+=29;
			if(exp2>600){
				exp2=600;
			}
				
    		int D=E1 * 3 + exp1 * 7;
    		double d=D;
    		if(D%2==0){
    			exp1+=d/200;
    			exp1=ceil(exp1);
				if(exp1>600){
					exp1=600;
				}	
			}
			else{
			    
				exp1-=d/100;
				exp1=ceil(exp1);
				if(exp1<0){
					exp1=0;
				}
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
    
	}
		if(E1==1){
			exp2+=45;
			if(exp2>600){
				exp2=600;
			}
		
		int D=E1 * 3 + exp1 * 7;
    		double d=D;
    		if(D%2==0){
    			exp1+=d/200;
    			exp1=ceil(exp1);
				if(exp1>600){
					exp1=600;
				}	
			}
			else{
			    
				exp1-=d/100;
				exp1=ceil(exp1);
				if(exp1<0){
					exp1=0;
				}
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
	}
		if(E1==2){
			exp2+=75;
			if(exp2>600){
				exp2=600;
			}
			
			int D=E1 * 3 + exp1 * 7;
    		double d=D;
    		if(D%2==0){
    			exp1+=d/200;
    			exp1=ceil(exp1);
				if(exp1>600){
					exp1=600;
				}	
			}
			else{
			    
				exp1-=d/100;
				exp1=ceil(exp1);
				if(exp1<0){
					exp1=0;
				}
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
	}
		if(E1==3){
			exp2+=149;
			if(exp2>600){
				exp2=600;
			}
			
			int D=E1 * 3 + exp1 * 7;
    		double d=D;
    		if(D%2==0){
    			exp1+=d/200;
    			exp1=ceil(exp1);
				if(exp1>600){
					exp1=600;
				}	
			}
			else{
			    
				exp1-=d/100;
				exp1=ceil(exp1);
				if(exp1<0){
					exp1=0;
				}
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
	}
		if(E1>=4 && E1<=19){
			exp2= exp2+e1/4+19;
			exp2= ceil(exp2);
			if(exp2>600){
				exp2=600;	
			}
			exp1-=E1;
			if(exp1<0){
				exp1=0;	
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
		}
		if(E1>=20 && E1<=49){
			exp2= exp2+e1/9+21;
			exp2= ceil(exp2);
			if(exp2>600){
				exp2=600;	
			}
			exp1-=E1;
			if(exp1<0){
				exp1=0;	
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
		}
		if(E1>=50 && E1<=65){
			exp2= exp2+e1/16+17;
			exp2= ceil(exp2);
			if(exp2>600){
				exp2=600;	
			}
			exp1-=E1;
			if(exp1<0){
				exp1=0;	
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
		}
		if(E1>=66 && E1<=79){
			exp2= exp2+(e1/9+21)+(e1/4+19);
			exp2= ceil(exp2);
			if(exp2>600){
				exp2=600;	
			}
			exp1-=E1;
			if(exp1<0){
				exp1=0;	
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
		}
		if(E1>=80 && E1<=99){
			exp2= 1.15*(exp2+(e1/9+21)+(e1/4+19)+(e1/16+17));
			exp2= ceil(exp2);
			if(exp2>600){
				exp2=600;	
			}
			exp1-=E1;
			if(exp1<0){
				exp1=0;
			}
			delete a;
			EXP1=exp1;
			EXP2=exp2;
			return exp1+exp2;
		}
		if(E1>99||E1<0){
			delete a;
			return -99;	
		}
		
		
    return 0;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double exp1=EXP1;
	double hp1=HP1;
	double m1=M1;
	int i=0;
	int S;
	double P1;
	//road 1
if(E2<0||E2>99){
		return -99;
}
else{
	while(i*i<=exp1){
		i+=1;
		if(i*i>exp1){
	        i-=1;
	        break;
	    }
	}
	if(exp1-(i*i)<((i+1)*(i+1)-exp1)){
		S=i*i;
		P1=1;	
	}
	else{
		S=(i+1)*(i+1);
		P1=(((exp1/S)+80)/123);
	}
	
	//road 2
	int spend=0;
	int m0;
	m0=m1/2;
	//buy food or drink
do{
	if(hp1<200){
		hp1=1.3*hp1;
		hp1=ceil(hp1);
		if(hp1>666){
			hp1=666;
		}
		m1-=150;
		spend+=150;
		if(m1<0){
			m1=0;
		}
	}
	else{
		hp1=1.1*hp1;
		hp1=ceil(hp1);
		if(hp1>666){
			hp1=666;
		}
		m1-=70;
		spend+=70;
		if(m1<0){
			m1=0;
		}
	}
	//compare
	if(spend>m0){
		hp1*=0.83;
		hp1=ceil(hp1);
		exp1*=1.17;
		exp1=ceil(exp1);
		if(exp1>600){
			exp1=600;
		}
		break;
	}
	//choose taxi or horse
	if(exp1<400){
		m1-=200;
		spend+=200;
		if(m1<0){
			m1=0;
		}
	}
	else{
		m1-=120;
		spend+=120;
		if(m1<0){
			m1=0;
		}
	}
	exp1=1.13*exp1;
	exp1=ceil(exp1);
	if(exp1>600){
		exp1=600;
	}
	if(spend>m0){
		hp1*=0.83;
		hp1=ceil(hp1);
		exp1*=1.17;
		exp1=ceil(exp1);
		if(exp1>600){
			exp1=600;
		}
		break;
	}
	//homeless help
	if(exp1<300){
		m1-=100;
		spend+=100;
		if(m1<0){
			m1=0;
		}
		exp1=0.9*exp1;
		exp1=ceil(exp1);
		if(exp1<0){
		exp1=0;
		}
	}
	else{
		m1-=120;
		spend+=120;
		if(m1<0){
			m1=0;
		}
		exp1*=0.9;
		exp1=ceil(exp1);
	}
	//compare spend and m0
	if(spend>m0){
		hp1*=0.83;
		hp1=ceil(hp1);
		exp1*=1.17;
		exp1=ceil(exp1);
		if(exp1>600){
			exp1=600;
		}
		break;
	}
	else;
}while(E2%2!=0);
	double P2;
	int S1;//so chinh phuong thu 2 cua P2
	if(E2!=0){
		while(i*i<=exp1){
			i+=1;
			if(i*i>exp1){
	        i-=1;
	        break;
	    }
	}
	if(exp1-(i*i)<((i+1)*(i+1)-exp1)){
		S1=i*i;
		P2=1;	
	}
	else{
		S1=(i+1)*(i+1);
		P2=(((exp1/S1)+80)/123);
	}
		}
	//road 3
	double P3,P;
	int a1,a2;//chu so 1 va 2 cua E2
	int a3,a4;//sau khi cong a1 va a2 ma ra 2 chu so
	const int arraysize= 10;
	double array[arraysize]={0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
	if(E2>=0 && E2<=9){
		P3=array[E2];
	}else if(E2>9 && E2<=99){
		a2=E2%10;
		a1=(E2-a2)/10;
		if(a1+a2>=0 && a1+a2<10){
			P3=array[a1+a2];
		}
		else{
			a3=(a1+a2)%10;
			a4=(a1+a2-a3)/10;
			P3=array[a3+a4];	
		}
	}
	//compare P1,P2,P3
	if(P1==1 && P2==1 && P3==1){
		exp1*=0.75;
		exp1=ceil(exp1);
	}
	else{
		P=(P1+P2+P3)/3;
		if(P<0.5){
			hp1*=0.85;
			hp1=ceil(hp1);
			exp1*=1.15;
			exp1=ceil(exp1);
			if(exp1>600){
				exp1=600;
			}
		}
		else{
			hp1*=0.9;
			hp1=ceil(hp1);
			exp1*=1.2;
			exp1=ceil(exp1);
			if(exp1>600){
				exp1=600;
			}
		}	
	}
	HP1=hp1;
	EXP1=exp1;
	M1=m1;
	return hp1+exp1+m1;
}
	
    return 0;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    double exp1=EXP1;
	double hp1=HP1;
	double exp2=EXP2;
	double hp2=HP2;
	double e3=E3;
	if(e3<0||e3>99){
	    return -99;
	}
	else{
    // Kh?i t?o ma tr?n 10x10 v?i giá tr? m?i ph?n t? là 0
    const int rows = 10;
    const int cols = 10;

    int matrix[rows][cols];

    // Gán giá tr? 0 cho m?i ph?n t? trong ma tr?n
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (((E3*j)+(i*2))*(i-j));
        }
    }

    int countbig=0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(matrix[i][j]>(E3*2)){
                countbig++;
            }
        }
    }
    int countsmall=0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(matrix[i][j]<(E3*(-1))){
                countsmall++;
            }
        }
    }
    //(a;b) là di?m g?p
    int a,b;
    int c,d;
    int e,f;// 2 ch? s?
    if(countbig>=0 && countbig<10){
        a=countbig;
    }
    else{
        d=countbig%10;
        c=(countbig-d)/10;
        if(c+d>=0 && c+d<=9){
            a=c+d;
        }
        else{
            f=(c+d)%10;
            e=(c+d-f)/10;
            a=e+f;
        }
    }
    if(countsmall>=0 && countsmall<10){
        b=countsmall;
    }
    else{
        d=countsmall%10;
        c=(countsmall-d)/10;
        if(c+d>=0 && c+d<=9){
            b=c+d;
        }
        else{
            f=(c+d)%10;
            e=(c+d-f)/10;
            b=e+f;
    }
    
    }
    
    double maxDiag=matrix[a][b];//tim max trong duong cheo cua 2 nguoi
    int i=a-1;// vong lap
    int j=b-1;
    //catch or not catch
    while(i>=0 && j>=0){
        if(maxDiag<matrix[i][j]){
            maxDiag=matrix[i][j];
        }
        i--;
        j--;
    }
    i=a-1;// gan lai
    j=b+1;
    while(i>=0 && j<=9){
        if(maxDiag<matrix[i][j]){
            maxDiag=matrix[i][j];
        }
        i--;
        j++;
    }
    i=a+1;// gan lai
    j=b-1;
    while(i<=9 && j>=0){
        if(maxDiag<matrix[i][j]){
            maxDiag=matrix[i][j];
        }
        i++;
        j--;
    }
    i=a+1;// gan lai
    j=b+1;
    while(i<=9 && j<=9){
        if(maxDiag<matrix[i][j]){
            maxDiag=matrix[i][j];
        }
        i++;
        j++;
    }
    
    //tim max cua taxi
    double maxtaxi;
    maxtaxi=matrix[a][b];
    int v=maxtaxi;//gia tri dau cua maxtaxi
    if(maxtaxi<0){
        maxtaxi*=-1;
    }
   
    if(maxtaxi>maxDiag){
       exp1=0.87999*exp1;
       exp1=ceil(exp1);
       exp2=0.87999*exp2;
       exp2=ceil(exp2);
       hp1=0.8999*hp1;
       hp1=ceil(hp1);
       hp2=0.8999*hp2;
       hp2=ceil(hp2);
    }
    else{
       exp1=1.11999*exp1;
       exp1=ceil(exp1);
       if(exp1>600){
            exp1=600;   
       }
       exp2=1.11999*exp2;
       exp2=ceil(exp2);
       if(exp2>600){
            exp2=600;   
       }
       hp1=1.0999*hp1;
       hp1=ceil(hp1);
       if(hp1>666){
            hp1=666;   
       }
       hp2=1.0999*hp2;
       hp2=ceil(hp2);
       if(hp2>666){
            hp2=666;   
       }
    }
    
    HP1=hp1;
	HP2=hp2;
	EXP1=exp1;
	EXP2=exp2;
    if(maxtaxi>maxDiag){
        return v;
    }
    else{
        return maxDiag;
    }
	}
	return 0;
}

// Task 4
//kiem tra ki tu dac biet
//kiem tra ki tu dac biet
bool checkpecial(const char* s){
        for(int i=0; i<strlen(s);i++){
            if(s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%'){
                return true;
            }
        }
        return false;
}
//kiem tra so lan lap lien tiep
bool check(const char *s, int &n ){
    for(int i=0;i<strlen(s)-2;i++){
        if(s[i]==s[i+1]){
            if(s[i+1]==s[i+2]){
               n=i;
               return true;
            }
        }
    }
    return false;
}
int checkPassword(const char * s, const char * email) {
	int n=0;//n luu vi tri trung
    const char* p=strchr(email,'@');// vi tri @
    int length=p-email;// do dai ki tu truoc @ va vi tri xuat hien cua @
    //cap phat bo nho cho se
    char* se=new char[length+1];//tinh them null
    strncpy(se,email,length);
    se[length]='\0';
    if(strlen(s)<8){
        return -1;
    }else if(strlen(s)>20){
        return -2;
    }else if(strstr(s,se)!=nullptr){
        const char* repetiton=strstr(s,se);//neu trung tra ve dia chi cua s luu trong con tro repetiton
        return -(300+(repetiton-s));
    }else if(check(s,n)){
        return -(400+n);
    }else if(!checkpecial(s)){
        return -5;
    }else{
        return -10;
    }
    delete[] se;
    return 0;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int count=0;// dem so lan lap cua 1 chuoi
    
    int loop[num_pwds];
   for(int i=0;i<num_pwds;i++){
        for(int j=0;j<num_pwds;j++){
           if(arr_pwds[i]==arr_pwds[j]){
               count++;
           }
           if(j==num_pwds-1){
               loop[i]=count;
           }
        }
        count=0;
    }
    
    int loopmax[num_pwds];//mang chua vi tri so lap nhieu nhat
    int max=loop[0];//so lan lap nhieu nhat
    for(int i=1;i<num_pwds;i++){
        if(max<loop[i]){
            max=loop[i];
    }
    }
    
    //tao mang loopmax
    for(int i=0;i<num_pwds;i++){
        if(max>loop[i]){
            loopmax[i]=0;
        }
        else{
            loopmax[i]=max;
        }
    }
    
    //in output
    int a;//vi tri xuat hien dau tien cua chuoi lap nhieu nhat
    
    //tim vi tri xuat hien dau tien cua chuoi lap nhieu nhat
    for(int i=0;i<num_pwds;i++){
        if(max==loopmax[i]){
            a=i;
            break;
        }
    }
    int l=a;
    const char* g=arr_pwds[a];//dung de thay the chuoi thoa dieu kien tam thoi
    for(int i=a;i<num_pwds;i++){
        if(arr_pwds[a]!=arr_pwds[i]){
          
            if(max==loopmax[i]){
            const char* h=arr_pwds[i];
            if(strlen(g)<strlen(h)){
                g=arr_pwds[i];
                l=i;
                break;
            }
        }
    }     
    }
    return l;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
