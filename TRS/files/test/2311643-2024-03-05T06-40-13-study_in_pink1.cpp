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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    //Check in:
    if(exp1 > 600) exp1 = 600;
    else if(exp1 < 0) exp1 = 0;
   
    if(exp2 > 600) exp2 = 600;
    else if(exp2 < 0) exp2 = 0;

    if(e1 > 99 || e1 < 0) return -99;
    
    // Truong hop 1:
    if( e1>-1 && e1<4 ){
        int D;
    if(e1 == 0) exp2+=29;
    else if (e1 == 1) exp2+=45;
    else if (e1 == 2) exp2+=75;
    else if (e1 == 3) exp2+=149;
        D = e1*3 + exp1*7;
        if(D % 2 == 0){
            exp1 = exp1 + ceil(D/200.0);
        } 
        else {
            exp1 = exp1 - D/100 ;
        }
    }

    // Truong hop 2:
    if( e1 >=4 && e1 <=99){
        //1
        if(e1 >= 4 && e1 <= 19) {
            exp2 = exp2 + ceil(e1/4.0) + 19;
            
        }
        //2
        if(e1 >= 20 && e1 <= 49){
            exp2 = exp2 + ceil(e1/9.0) + 21;
            
        }
        //3
        if(e1 >= 50 && e1 <= 65){
            exp2 = exp2 + ceil(e1/16.0) + 17;
            
        }
        //4
        if(e1>=66 && e1 <=79){
            exp2 = exp2 + ceil(e1/4.0) + 19;
            
            if(exp2 > 200){
                exp2 = exp2 + ceil(e1/9.0) + 21;
                
            }
        }
        //5
        if(e1 >=80 && e1 <=99){
            exp2 = exp2 + ceil(e1/4.0) + 19;
            
            exp2 = exp2 + ceil(e1/9.0) + 21;
            

            if(exp2>400){
                exp2 = exp2 + ceil(e1/16.0) + 17;
                exp2 = exp2 + ceil(exp2*15/100.0);
            }

            
            
        }
        exp1 = exp1 - e1;
    }
    
    //Check out:
    if(exp1 > 600) exp1 = 600;
    else if(exp1 < 0) exp1 = 0;
   
    if(exp2 > 600) exp2 = 600;
    else if(exp2 < 0) exp2 = 0;

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    //Check in:
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;

    if(HP1 > 666) HP1 = 666;
    else if(HP1 < 0) HP1 = 0;

    if(M1 > 3000) M1 = 3000;
    else if(M1 < 0) M1 = 0;

    if(E2 > 99 || E2 < 0) return -99;

    //Con duong 1:
    float con, P1, P2, P3;
    int S;
    con = EXP1;
    con = sqrt(con);
    con = round(con);
    S = con*con;
   
    if(EXP1 >= S) P1 = 1;
    else{
        P1 = (float(EXP1)/S +80.0)/123.0;
        
        
    } 
    
    //Con duong 2:
    int mautien;
    
    mautien = M1*50/100;

    if(E2 % 2 !=0){
        int tiendachi = 0;
        while(true){
        
    //An uong:
    if(HP1 < 200){
        HP1 = HP1 + ceil(HP1*30/100.0);
       
        M1 = M1 - 150;
        tiendachi+=150;
        if(tiendachi > mautien) break;
        }
    
    else{
        HP1 = HP1 + ceil(HP1*10/100.0);
      
        M1 = M1 - 70;
        tiendachi+=70;
        if(tiendachi > mautien) break;
        }
    

    // Di xe:
    if(EXP1 < 400){
        M1 = M1 - 200;
        tiendachi+=200;
    }
    else{
        M1 = M1 - 120;
        tiendachi+=120;
    }
    EXP1 = EXP1 + ceil(EXP1*13/100.0);
   
    if(tiendachi > mautien) break;
   
    //Nguoi vo gia cu:
    if(EXP1 < 300){
        M1 = M1 - 100;
        tiendachi+=100;
    }
    else{
        M1 = M1 - 120;
        tiendachi+=120;
    }
    
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;

    EXP1 = EXP1 - EXP1*10/100;
    if(tiendachi > mautien) break;
    }
    }
   
    //E2 chan
    else{
    for(int i = 0; i < 1; i++){
        //An uong:
    if(HP1 < 200){
        HP1 = HP1 + ceil(HP1*30/100.0);
       
        M1 = M1 - 150;
        }
       
    else{
        HP1 = HP1 + ceil(HP1*10/100.0);
       
        M1 = M1 - 70;
        }
        if(M1 <= 0){
        M1 = 0;
        break;
    }

    // Di xe:
    if(EXP1 < 400){
        M1 = M1 - 200;
    }
    else{
        M1 = M1 - 120;
        
    }

    EXP1 = EXP1 + ceil(EXP1*13/100.0);
    

    if(M1 <= 0){
        M1 = 0;
        break;
    }
    //Nguoi vo gia cu:
    if(EXP1 < 300){
        M1 = M1 - 100;
        
    }
    else{
        M1 = M1 - 120;
        
    }
    
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;

    EXP1 = EXP1 - EXP1*10/100;
    if(M1 <= 0){
        M1 = 0;
        break;
    }
    }
    }

    //Check HP1, EXp1:
    if(HP1 > 666) HP1 = 666;
    else if(HP1 < 0) HP1 = 0;

    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;

    HP1 = HP1 - HP1*17/100;
    EXP1 = EXP1 + ceil(EXP1*17/100.0);

    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;
    
    con = EXP1;
    con = sqrt(con);
    con = round(con);
    S = con*con;
    if(EXP1 >= S) P2 = 1;
    else{
        P2 = (float(EXP1)/S +80.0)/123.0;
        
        
    } 

    
    //Con duong 3:
    float P[10]={0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int gan;
    gan = E2%10 + E2/10;
    gan = gan%10;
    P3 = P[gan];
    
    //Chot:
    if(P1 == 1 && P2 == 1 && P3 == 1){
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;

        EXP1 = EXP1 - EXP1*25/100;
    }
    else{
        float chot = (P1+P2+P3)/3;
       
        if(chot < 0.5){
            
            HP1 = HP1 - HP1*15/100;
            EXP1 = EXP1 + ceil(EXP1*15/100.0);
           
        }
        else{
            HP1 = HP1 - HP1*10/100;
            EXP1 = EXP1 + ceil(EXP1*20/100.0);
        }
    }
    
    //Check out:
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;

    if(HP1 > 666) HP1 = 666;
    else if(HP1 < 0) HP1 = 0;

    if(M1 > 3000) M1 = 3000;
    else if(M1 < 0) M1 = 0;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    //Check in:
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;

    if(HP1 > 666) HP1 = 666;
    else if(HP1 < 0) HP1 = 0;

    if(EXP2 > 600) EXP2 = 600;
    else if(EXP2 < 0) EXP2 = 0;

    if(HP2 > 666) HP2 = 666;
    else if(HP2 < 0) HP2 = 0;

    if(E3 > 99 || E3 < 0) return -99;

    //Ma tran:
    int taxi[10][10];
    for(int i = 0; i <10; i++){
        for(int j = 0; j <10; j++){
            taxi[i][j]= ((E3*j)+(i*2))*(i-j);
        }
    }

    //Vi tri cuoi:
    int a = 0, b = 0;
    for(int i = 0; i <10; i++){
        for(int j = 0; j < 10; j++){
            if(taxi[i][j] > E3*2) a++;
            if(taxi[i][j] < -E3) b++;
        }
    }
    a = a%10 + a/10;
    a = a%10 + a/10;
    b = b%10 + b/10;
    b = b%10 + b/10;
    
    //Tinh diem:
    int diem, m ,n;
    m = a;
    n = b;
    diem = taxi[a][b];
    while(m < 9 && n < 9){
        m++;
        n++;
        if(diem < taxi[m][n]) diem = taxi[m][n];
    }

    m=a; n=b;
    while(m > 0 && n < 9){
        m--;
        n++;
        if(diem < taxi[m][n]) diem = taxi[m][n];
    }

    m =a; n=b;
    while(m > 0 && n > 0){
        m--;
        n--;
        if(diem < taxi[m][n]) diem = taxi[m][n];
    }

    m =a; n=b;
    while(m < 9 && n > 0){
        m++;
        n--;
        if(diem < taxi[m][n]) diem = taxi[m][n];
    }

    if(abs(taxi[a][b]) > abs(diem) ){
        EXP1 = ceil(EXP1*0.88);
        EXP2 = ceil(EXP2*0.88);
        HP1 = ceil(HP1*0.9);
        HP2 = ceil(HP2*0.9);
        
    }
    else{
        EXP1 = ceil(EXP1*112/100.0);
        EXP2 = ceil(EXP2*112/100.0);
        HP1 = ceil(HP1*110/100.0);
        HP2 = ceil(HP2*110/100.0);
    }

    //Check out:
    if(EXP1 > 600) EXP1 = 600;
    else if(EXP1 < 0) EXP1 = 0;

    if(HP1 > 666) HP1 = 666;
    else if(HP1 < 0) HP1 = 0;

    if(EXP2 > 600) EXP2 = 600;
    else if(EXP2 < 0) EXP2 = 0;

    if(HP2 > 666) HP2 = 666;
    else if(HP2 < 0) HP2 = 0;

    //Xuat ket qua:
     if(abs(taxi[a][b]) > abs(diem) ){
        return taxi[a][b];
     }
     else return diem;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    //Lay do dai:
    int lengths = 0;
    while(s[lengths] != '\0') lengths++;

    int lengthemail = 0;
    while(email[lengthemail] != '\0') lengthemail++;
    
    //Check do dai:
    if(lengths < 8) return -1;
    if(lengths > 20) return -2;

    

    //Check se:
    int dodaise;
    string se;
    for(int i = 0; i < lengthemail; i++){
        if(email[i] == '@'){
            dodaise = i;
            break;
        }
    }
    for(int i = 0; i < dodaise; i++){
        se+=email[i];
    }

    if (dodaise ==0) return -300;

    if (dodaise <= lengths){
    for(int i = 0; i < lengths; i++){
        if(s[i] == se[0]){
            string draft;
            for(int j = i; j < dodaise + i; j++){
                draft+=s[j];
            }
            
            if(draft == se){
                return -(300+i);
            }
        }
    }
    }
    //Check ky tu lien tiep:
    
    for(int i = 0; i < lengths; i++){
        if(s[i] == s[i+1] && s[i]== s[i+2]){
            return -(400+i);
        }
    }

    //Check ky tu dac biet:
    int special = 0;
    for(int i = 0; i < lengths; i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!' ) special++;
    }
    if(special == 0) return -5;

    //Check ky tu phu hop:
    int vitrisai = 20;
    for(int i = 0; i < lengths; i++){
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i]>='a' && s[i] <='z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!' || (s[i] >='0' && s[i] <='9'))){
            return  i;
        }
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char*  arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int dodaipwds;
	string pwdsgoc = arr_pwds[0];
	int vitripwds = 0;
	int mostappear = 0;

	int lengthpwds = 0;
	while(arr_pwds[0][lengthpwds] != '\0') lengthpwds++;

	dodaipwds = lengthpwds;
    
	for(int i = 0; i < num_pwds; i++){
		int count = 0;
		string khoa;
        khoa = arr_pwds[i];
		for(int j = i + 1; j < num_pwds; j++){
            string minh;
            minh = arr_pwds[j];
            
			if(khoa == minh) count++;
		}

        
		if(count > mostappear){
			mostappear = count;

            int lengthpwds = 0;
			while(arr_pwds[i][lengthpwds] != '\0') lengthpwds++;
            dodaipwds = lengthpwds;
            
			pwdsgoc = arr_pwds[i];
			vitripwds = i;
        
		}
		else if(count == mostappear){
			
            int lengthpwds = 0;
			while(arr_pwds[i][lengthpwds] != '\0') lengthpwds++;
	
			if(lengthpwds > dodaipwds){
				dodaipwds = lengthpwds;
				pwdsgoc = arr_pwds[i];
				vitripwds = i;
			}
		}
       
	}
 
    return vitripwds;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////