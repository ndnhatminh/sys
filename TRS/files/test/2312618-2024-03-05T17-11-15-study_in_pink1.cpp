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
int HP_check(int HP){
    if(HP>=666){HP=666;}
    else if(HP<=0){HP=0;}
    return HP;
}
int EXP_check(int EXP){
    if(EXP>=600){EXP=600;}
    else if(EXP<=0){EXP=0;}
    return EXP;
}
int M_check(int M){
    if(M>=3000){M=3000;}
	else if(M<=0){M=0;}
    return M;
}


// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function 
        if(E1<0 || E1>99){return -99;}
        float EXP1_test,EXP2_test,E1_test=E1;
        int D;
        EXP2_test=EXP_check(EXP2);
        EXP1_test=EXP_check(EXP1);
	//case 1
	   switch(E1){
	    	case 0: EXP2_test+=29; 
                    D=E1*3+EXP1*7;
                    if(D%2==0){
                        EXP1_test+=D/200.0;
                        EXP1_test= ceil(EXP1_test);} 
                    else{
                        EXP1_test-=D/100.0;
                        EXP1_test=ceil(EXP1_test);}
                    break;
	    	case 1: EXP2_test+=45; 
                    D=E1*3+EXP1*7;
                    if(D%2==0){
                        EXP1_test+=D/200.0;
                        EXP1_test= ceil(EXP1_test);} 
                    else{
                        EXP1_test-=D/100;
                        EXP1_test=ceil(EXP1_test);}
                    break;
	    	case 2: EXP2_test+=75; 
                    D=E1*3+EXP1*7;
                    if(D%2==0){
                        EXP1_test+=D/200.0;
                        EXP1_test= ceil(EXP1_test);} 
                    else{
                        EXP1_test-=D/100.0;
                        EXP1_test=ceil(EXP1_test);}
                    break;
	    	case 3: EXP2_test+=29+45+75; 
                    D=E1*3+EXP1*7;
                    if(D%2==0){
                        EXP1_test+=D/200.0;
                        EXP1_test= ceil(EXP1_test);} 
                    else{
                        EXP1_test-=D/100.0;
                        EXP1_test=ceil(EXP1_test);}
                        break;
	    }
	   

    //case 2
    if(E1>=4 && E1<=19){EXP2_test += E1_test/4+19;EXP2_test=ceil(EXP2_test);EXP1_test-=E1;}
    if(E1>=20 && E1<=49){EXP2_test += E1_test/9+21;EXP2_test=ceil(EXP2_test);EXP1_test-=E1;}
    if(E1>=50 && E1<=65){EXP2_test += E1_test/16+17;EXP2_test=ceil(EXP2_test);EXP1_test-=E1;}
    if(E1>=66 && E1<=79){
        EXP2_test += E1_test/4+19;
        EXP2_test = ceil(EXP2_test);
        if(EXP2_test>200){EXP2_test+=E1_test/9+21;EXP2_test = ceil(EXP2_test);}
        EXP1_test-=E1;}
    if(E1>=80 && E1<=99){
        EXP2_test+=E1_test/4+19;EXP2_test = ceil(EXP2_test);
        EXP2_test+=E1_test/9+21;EXP2_test = ceil(EXP2_test);
        if(EXP2_test>400){EXP2_test+=E1_test/16+17;EXP2_test = ceil(EXP2_test);
        EXP2_test = EXP2_test*1.15;EXP2_test = ceil(EXP2_test);}
        EXP1_test-=E1;}

    EXP1_test=EXP_check(EXP1_test);
    EXP2_test=EXP_check(EXP2_test);
    EXP2=ceil(EXP2_test);
    EXP1=ceil(EXP1_test);
     
    return EXP1+EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2){
    // TODO: Complete this function

    if(E2<0 || E2>99){return -99;}

    float P1,P2,P3;
    float EXP1_test,EXP2_test,HP1_test,M1_test,halfM1=0.0;
    float tiencanchi=0.0,sochinhphuong1=0.0,sochinhphuong2=0.0,S1=0.0,S2=0.0;
    HP1_test=HP1;
    HP1_test=HP_check(HP1);
    EXP1_test=EXP1;
    EXP1_test=EXP_check(EXP1);
    M1_test=M_check(M1);
    halfM1=M_check(M1)/2.0;
    //way 1
    for(int i=2; i<=100 ;i+=1){
        sochinhphuong1=i*i;
        sochinhphuong2=(i-1)*(i-1);
        float A=abs(sochinhphuong1-EXP1_test);
        float B=abs(sochinhphuong2-EXP1_test);
        if(sochinhphuong1>=EXP1_test){
            if(A>B){S1=sochinhphuong2;}
            else {S1=sochinhphuong1;}
            break;}
        }
        if(S1<=EXP1_test){P1=1;}
        else {P1=((EXP1_test/S1)+80.0)/123.0;}
    //way2
    if(E2%2==0){
        //su kien 1
        if(M1_test!=0){
            if(HP1_test<200){
                M1_test-=150;
                M1_test=M_check(M1_test);
                HP1_test=1.3*HP1_test;
                HP1_test=ceil(HP1_test);
                HP1_test=HP_check(HP1_test);}
            else{
                HP1_test=1.1*HP1_test;
                M1_test-=70;
                M1_test=M_check(M1_test);
                HP1_test=ceil(HP1_test);
                HP1_test=HP_check(HP1_test);}
        //su kien 2
            if(M1_test!=0){
                M1_test=EXP1_test<400?M1_test-=200:M1_test-=120;
                M1_test=M_check(M1_test);
                EXP1_test=1.13*EXP1_test;
                EXP1_test=ceil(EXP1_test);
                EXP1_test=EXP_check(EXP1_test);
        // su kien 3
                if(M1_test!=0){
                    M1_test=EXP1_test<300?M1_test-100:M1_test-=120;
                    M1_test=M_check(M1_test);
                    EXP1_test=0.9*EXP1_test;
                    EXP1_test=ceil(EXP1_test);
                    EXP1_test=EXP_check(EXP1_test);
                    HP1_test=0.83*HP1_test;
                    HP1_test=ceil(HP1_test);
                    HP1_test=HP_check(HP1_test);
                    EXP1_test=1.17*EXP1_test;
                    EXP1_test=ceil(EXP1_test);
                    EXP1_test=EXP_check(EXP1_test);}
                else{
                    HP1_test=0.83*HP1_test;
                    HP1_test=ceil(HP1_test);
                    HP1_test=HP_check(HP1_test);
                    EXP1_test=1.17*EXP1_test;
                    EXP1_test=ceil(EXP1_test);
                    EXP1_test=EXP_check(EXP1_test);
                }}
            else{
                HP1_test=0.83*HP1_test;
                HP1_test=ceil(HP1_test);
                HP1_test=HP_check(HP1_test);
                EXP1_test=1.17*EXP1_test;
                EXP1_test=ceil(EXP1_test);
                EXP1_test=EXP_check(EXP1_test);}}
        else{
            HP1_test=0.83*HP1_test;
            HP1_test=ceil(HP1_test);
            HP1_test=HP_check(HP1_test);
            EXP1_test=1.17*EXP1_test;
            EXP1_test=ceil(EXP1_test);
            EXP1_test=EXP_check(EXP1_test);}}
    else {
        if (M1_test==0){
            HP1_test *= 0.83; 
            HP1_test = ceil(HP1_test);
            HP1_test=HP_check(HP1_test);
            EXP1_test *= 1.17; 
            EXP1_test = ceil(EXP1_test);
            EXP1_test=EXP_check(EXP1_test);}

        while(tiencanchi<= halfM1){
            //su kien 1
            if(HP1_test<200){
                M1_test-=150;
                M1_test=M_check(M1_test);
                tiencanchi+=150;
                HP1_test=1.3*HP1_test;
                HP1_test=ceil(HP1_test);
                HP1_test=HP_check(HP1_test);}
            else{
                M1_test-=70;
                M1_test=M_check(M1_test);
                tiencanchi+=70;
                HP1_test=1.1*HP1_test;
                HP1_test=ceil(HP1_test);
                HP1_test=HP_check(HP1_test);}

            if(tiencanchi>halfM1){
                HP1_test=0.83*HP1_test;
                HP1_test=ceil(HP1_test);
                HP1_test=HP_check(HP1_test);
                EXP1_test=1.17*EXP1_test;
                EXP1_test=ceil(EXP1_test);
                EXP1_test=EXP_check(EXP1_test);
                break;}
            //su kien 2
            if(EXP1_test<400){
                M1_test-=200;
                M1_test=M_check(M1_test);
                tiencanchi+=200;
                EXP1_test=1.13*EXP1_test;
                EXP1_test=ceil(EXP1_test);
                EXP1_test=EXP_check(EXP1_test);}
            else{
                M1_test-=120;
                M1_test=M_check(M1_test);
                tiencanchi+=120;
                EXP1_test=1.13*EXP1_test;
                EXP1_test=ceil(EXP1_test);
                EXP1_test=EXP_check(EXP1_test);}

            if(tiencanchi>halfM1){
                HP1_test=0.83*HP1_test;
                HP1_test=ceil(HP1_test);
                HP1_test=HP_check(HP1_test);
                EXP1_test=1.17*EXP1_test;
                EXP1_test=ceil(EXP1_test);
                EXP1_test=EXP_check(EXP1_test);
                break;}

            //su kien 3

            if(EXP1_test<300){
                M1_test-=100;
                M1_test=M_check(M1_test);
                tiencanchi+=100;
                EXP1_test=0.9*EXP1_test;
                EXP1_test=ceil(EXP1_test);}
            else {
                M1_test-=120;
                M1_test=M_check(M1_test);
                tiencanchi+=120;
                EXP1_test=0.9*EXP1_test;
                EXP1_test=ceil(EXP1_test);}

            if(tiencanchi>halfM1){
                HP1_test=0.83*HP1_test;
                HP1_test=ceil(HP1_test);
                HP1_test=HP_check(HP1_test);
                EXP1_test=1.17*EXP1_test;
                EXP1_test=ceil(EXP1_test);
                EXP1_test=EXP_check(EXP1_test);
                break;}}
        }
        

        for(int a=2; a<=100 ;a+=1){
        float sochinhphuong3=a*a;
        float sochinhphuong4=(a-1)*(a-1);
        float A=abs(sochinhphuong3-EXP1_test);
        float B=abs(sochinhphuong4-EXP1_test);
        if(sochinhphuong3>=EXP1_test){
            if(A>B){S2=sochinhphuong4;}
            else {S2=sochinhphuong3;}
            break;}
        }
        if(S2<=EXP1_test){P2=1;}
        else {P2=((EXP1_test/S2)+80.0)/123.0;}
        

    //way 3
    float Pi[10]={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    int i;
    float Ptb;
    if(E2<10){i=E2;}
    if(E2>=10){i=(E2/10+E2%10)%10;}
    P3=Pi[i];
    if(P1==P2 && P2==P3 && P1==1){
        EXP1_test=EXP1_test*0.75;
        EXP1_test=ceil(EXP1_test);}
   else{
        Ptb=(P1+P2+P3)/3.0;
        if(Ptb<0.5){
            HP1_test=HP1_test*0.75;
            HP1_test=ceil(HP1_test);
            EXP1_test=EXP1_test*1.15;
            EXP1_test=ceil(EXP1_test);}
        else {
            HP1_test=HP1_test*0.9;
            HP1_test=ceil(HP1_test);
            EXP1_test=EXP1_test*1.2;
            EXP1_test=ceil(EXP1_test);}}
    HP1=HP_check(HP1_test);
    EXP1=EXP_check(EXP1_test);
    M1=M_check(M1_test);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
    // TODO: Complete this function
    if(E3<0 || E3>99){return -99;}
    long long int trave, i = 0, j = 0;
    float HP1_test,HP2_test,EXP1_test,EXP2_test;
    HP1_test=HP_check(HP1);
    HP2_test=HP_check(HP2);
    EXP1_test=EXP_check(EXP1);
    EXP2_test=EXP_check(EXP2);
   
    int matran[10][10];
    int matran1[10][10];
    for(int z=0;z<10;z++){
        for(int k=0;k<10;k++){
            matran[z][k]=((E3*k)+(z*2))*(z-k);
            if(matran[z][k]>(E3*2)){
                i+=1;             
            }
            if(matran[z][k]<(-E3)){
                j+=1;
            }
        }
    }
    while(i>9){
        i=i/10+i%10;
    }
    while(j>9){
        j=j/10+j%10;
    }
    int l=abs(matran[i][j]);
    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            int max=matran[x][y];
            for(int k=0;k<10;k++){
                if(x+k<10&& y+k<10){
                    max=(max<matran[x+k][y+k])?matran[x+k][y+k]:max;
                }
            for(int k=0;k<10;k++){
                if(x+k<10 && j-k>=0){
                    max=(max<matran[x+k][y-k])?matran[x+k][y-k]:max;
                }            }
                if(x-k>0 && y-k>0){
                     max=(max<matran[x-k][y-k])?matran[x-k][y-k]:max;
                }
            }
            matran1[x][y]=abs(max);
        }}
    if(l>matran1[i][j]){
        trave=matran[i][j];
        EXP1_test=0.88*EXP1_test;
        EXP1_test=ceil(EXP1_test);
        EXP1_test=EXP_check(EXP1_test);

        EXP2_test=0.88*EXP2_test;
        EXP2_test=ceil(EXP2_test);
        EXP2_test=EXP_check(EXP2_test);

        HP1_test=0.9*HP1_test;
        HP1_test=ceil(HP1_test);
        HP1_test=HP_check(HP1_test);

        HP2_test=0.9*HP2_test;
        HP2_test=ceil(HP2_test);
        HP2_test=HP_check(HP2_test);   
    }
    else{
        trave=matran1[i][j];
        EXP1_test=1.12*EXP1_test;
        EXP1_test=ceil(EXP1_test);
        EXP1_test=EXP_check(EXP1_test);

        EXP2_test=1.12*EXP2_test;
        EXP2_test=ceil(EXP2_test);
        EXP2_test=EXP_check(EXP2_test);

        HP1_test=1.1*HP1_test;
        HP1_test=ceil(HP1_test);
        HP1_test=HP_check(HP1_test);

        HP2_test=1.1*HP2_test;
        HP2_test=ceil(HP2_test);
        HP2_test=HP_check(HP2_test);
    }
    EXP1=EXP1_test;
    EXP2=EXP2_test;
    HP2=HP2_test;
	HP1=HP1_test;
    return trave;
}

// Task 4
int checkPassword(const string & s, const string & email){
    // TODO: Complete this function
    size_t a=email.find('@');
    string se=email.substr(0,a);
    int KytuS=s.length();

    if(KytuS<8)return -1;
    if(KytuS>20)return -2;

    if(s.find(se)!= string :: npos){
        return -(300+s.find(se));
    }
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1])return -(400+i-1);
    }
    for(char e : s){
        if(e != '@' && e !='#' && e !='!' && e !='$')return -5;
    }
   return -10;
     
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
     // TODO: Complete this function
    int maxc = 0;
    int maxlength = 0;
    int ans = -1;
    for (int i = 0; i < num_pwds; ++i) {
        const string pwd = arr_pwds[i];
        int len = pwd.length();
        
        int count = 0;
        
        for (int j = 0; j < num_pwds; ++j) {
            if (arr_pwds[j] == pwd) {
                ++count;
            }
        }
        if (count > maxc || (count == maxc && len > maxlength)) {
            maxc = count;
            maxlength = len;
            ans = i;
        }
    }
    return ans;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
