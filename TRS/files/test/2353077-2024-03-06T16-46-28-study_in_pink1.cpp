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

//Check HP
int hp(int &hp) {
    if (hp>666) return 666;
    else if (hp<0) return 0;
    else return hp;
}

//Check EXP
int exp(int &exp) {
    if (exp>600) return 600;
    else if (exp<0) return 0;
    else return exp;
}

//Check M
int m(int &m) {
    if (m>3000) return 3000;
    else if (m<0) return 0;
    else return m;
}

//Find nearest perfect square
int NPS(int exp) {
    int x=sqrt(exp);
    if(sqrt(exp)-x==0) {
        return exp;
    }
    else {
        int dif_a=exp-x*x;
        int dif_b=(x+1)*(x+1)-exp;
        if (dif_a<dif_b) return x*x;
        else return (x+1)*(x+1);
    }
}

//Ceiling the percentage
float p(float p) {
    p=ceil(-1e-9+p*100);
    return p/100;
}

// 2digit-number to 1digit-number (meet point)
int one_digit_point (int num) {
    if ((num>=0)&&(num<=9)) {
        return num;
    }
    else {
        int temp_num = ((num/10)+(num%10));
        return one_digit_point (temp_num);
    }
}

// Maximum value on both left-right diagonal
int max_diag (int a, int b, int ar[][10]) {

    int max=ar[a][b];
    // Decrease complexity of algorithm with if else

    if(a>=b) {
        //Check MAX on RIGHT diagonal
        int b_r0=((a+b)>=9)*(a+b-9);
        int b_r=((a+b)<9)*(a+b)+((a+b)>=9)*9;
        for (; b_r0<=b_r; b_r0++) {
            if (ar[(a+b)-b_r0][b_r0]>max) {
                max=ar[(a+b)-b_r0][b_r0];
            }
        }

        //Check MAX on LEFT diagonal
        int b_l0=(a<b)*(a-b);
        int b_l=(a>=b)*(9-(a-b))+(a<b)*9;
        for (; b_l0<=b_l; b_l0++) {
            if (ar[b_l0+(a-b)][b_l0]>max) {
                max=ar[b_l0+(a-b)][b_l0];
            }
        }       
        return max;
    }
    else {
        //Check MAX on RIGHT diagonal (all elements on left diagonal are negative numbers)
        int b_r0=((a+b)>=9)*(a+b-9);
        int b_r=((a+b)<9)*(a+b)+((a+b)>=9)*9;
        for (; b_r0<=b_r; b_r0++) {
            if (ar[(a+b)-b_r0][b_r0]>max) {
                max=ar[(a+b)-b_r0][b_r0];
            }
        }
        return max;
    }
}
//Check if array contains more than 2 consecutive and identical characters
int consecutive_char(string con_str) {
    for (int i = 0; i < (con_str.length()-2); i++)
    {
        if(con_str[i]==con_str[i+1]) {
            if (con_str[i+1]==con_str[i+2]) {
                return i;
            }
            else {
                i++;
                continue;
            }
        }
    }
    return -1;
    
}

//Check for valid character 
int invalid_char(string spec_x) {
    for (int i = 0; i < spec_x.length(); i++) {
        int asci_x = spec_x[i];
        //Lowercaseletter: 97-122
        if (!((asci_x>=97)&&(asci_x<=122))) {
            //Uppercase: 65-90
            if (!((asci_x>=65)&&(asci_x<=90))) {
                //Number: 48-57
                if (!((asci_x>=48)&&(asci_x<=57))) {
                    //Special characters: @ # % $ !
                    if (((asci_x>=35)&&(asci_x<=37))||(asci_x==33)||(asci_x==64)) {
                        continue;
                    }
                    else return i;           
                } 
                else continue;
            }
            else continue;
        }
        else continue;
    }
    return -1;
}

//Check for special character 
bool special_char(string spec_x) {
    //Special characters
    char spec_1='@';
    char spec_2='#';
    char spec_3='%';
    char spec_4='$';
    char spec_5='!';
    for (int i = 0; i < spec_x.length(); i++)
    {
        if (spec_x[i]==spec_1) {
            return 1;
        }
        else if (spec_x[i]==spec_2) {
            return 1;
        }
        else if (spec_x[i]==spec_3) {
            return 1;
        }
        else if (spec_x[i]==spec_4) {
            return 1;
        }
        else if (spec_x[i]==spec_5) {
            return 1;
        }
    }
    return 0;
    
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    //Check all the components
    if ((e1<0)||(e1>99)) return -99;
    exp2=exp(exp2);
    exp1=exp(exp1);
    //Case 1
    if ((e1>=0)&&(e1<=3)) {
        if(e1==0) {
            exp2=ceil(-1e-9+exp2+29);
            exp2=exp(exp2);
        }
        else if(e1==1) {
            exp2=ceil(-1e-9+exp2+45);
            exp2=exp(exp2);
        }
        else if(e1==2) {
            exp2=ceil(-1e-9+exp2+75);
            exp2=exp(exp2);
        }
        else if (e1==3) {
            exp2=ceil(-1e-9+exp2+29+45+75);
            exp2=exp(exp2);
        }
        int D=3*e1+7*exp1;

        if(D%2==0) {
            exp1=ceil(-1e-9+exp1+(float)(D)/200);
            exp1=exp(exp1);
        }
        else {
            exp1=ceil(-1e-9+exp1-(float)(D)/100);
            exp1=exp(exp1);
        }
    }

    //Case 2
    else if ((e1>=4)&&(e1<=99)) {
        if ((e1>=4)&&(e1<=19)) {
            exp2=ceil(-1e-9+exp2+(float)(e1)/4+19);
            exp2=exp(exp2);
        }
        else if ((e1>=20)&&(e1<=49)) {
            exp2=ceil(-1e-9+exp2+(float)(e1)/9+21);
            exp2=exp(exp2);
        }
        if ((e1>=50)&&(e1<=65)) {
            exp2=ceil(-1e-9+exp2+(float)(e1)/16+17);
            exp2=exp(exp2);
        }
        if ((e1>=66)&&(e1<=79)) {
            exp2=ceil(-1e-9+exp2+(float)(e1)/4+19);
            exp2=exp(exp2);
            if(exp2>200) {
            exp2=ceil(-1e-9+exp2+(float)(e1)/9+21);
            exp2=exp(exp2);
            }
        }
        if ((e1>=80)&&(e1<=99)) {
            exp2=ceil(-1e-9+exp2+(float)(e1)/4+19);
            exp2=exp(exp2);
            exp2=ceil(-1e-9+exp2+(float)(e1)/9+21);
            exp2=exp(exp2);
            if(exp2>400) {
            exp2=ceil(-1e-9+exp2+(float)(e1)/16+17);
            exp2=exp(exp2);
            exp2=ceil(-1e-9+exp2+(float)(exp2*15)/100);
            exp2=exp(exp2);
            }
        }
        exp1=ceil(-1e-9+exp1-e1);
        exp1=exp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //Check all the components
    if ((E2<0)||(E2>99)) return -99;
    float P,P1,P2,P3;
    HP1=hp(HP1);
    EXP1=exp(EXP1);
    M1=m(M1);

    //ROAD 1
    if (EXP1>=NPS(EXP1)) {
        P1=1;
    }
    else {
        P1=((float)EXP1/NPS(EXP1)+80)/123;
    }

    //ROAD 2
    float sum_m=0;
    float half_init_m=(float)M1/2;

    // If E2 is odd and >0
    if (M1>0) {
    if (E2&1) {
    while(sum_m<=half_init_m) {
        //event 1
        if(HP1<200) {
            HP1=ceil(-1e-9+(float)HP1*130/100);
            HP1=hp(HP1);
            M1=M1-150;
            M1=m(M1);
            sum_m+=150;
        }
        else {
            HP1=ceil(-1e-9+(float)HP1*110/100);
            HP1=hp(HP1);
            M1=M1-70;
            M1=m(M1);
            sum_m+=70;
        }
        if(sum_m>half_init_m) break;


        //event 2
        if(EXP1<400) {
            M1=M1-200;
            M1=m(M1);
            sum_m+=200;
        }
        else {
            M1=M1-120;
            M1=m(M1);
            sum_m+=120;
        }
        EXP1=ceil(-1e-9+(float)EXP1*113/100);
        EXP1=exp(EXP1);
        if(sum_m>half_init_m) break;


        //event 3
        if(EXP1<300) {
            M1=M1-100;
            M1=m(M1);
            sum_m+=100;
        }
        else {
            M1=M1-120;
            M1=m(M1);
            sum_m+=120;
        }
        EXP1=ceil(-1e-9+(float)EXP1*90/100);
        EXP1=exp(EXP1);
        if(sum_m>half_init_m) break;
        }
    }

    //If E2 is even
    else {
        //event 1
        if (M1>0) {
            if((HP1<200)) {
                HP1=ceil(-1e-9+(float)HP1*130/100);
                HP1=hp(HP1);
                M1=M1-150;
                M1=m(M1);
            }
            else {
                HP1=ceil(-1e-9+(float)HP1*110/100);
                HP1=hp(HP1);
                M1=M1-70;
                M1=m(M1);
            }
        }

        //event 2
        if (M1>0) {
        if(EXP1<400) {
            M1=M1-200;
            M1=m(M1);
        }
        else {
            M1=M1-120;
            M1=m(M1);
        }
        EXP1=ceil(-1e-9+(float)EXP1*113/100);
        EXP1=exp(EXP1);
        }
        //event 3
        if (M1>0) {
        if(EXP1<300) {
            M1=M1-100;
            M1=m(M1);
        }
        else {
            M1=M1-120;
            M1=m(M1);
        }
        EXP1=ceil(-1e-9+(float)EXP1*90/100);
        EXP1=exp(EXP1);
        }
    }
    }
    HP1=ceil(-1e-9+(float)HP1*83/100);
    HP1=hp(HP1);
    EXP1=ceil(-1e-9+(float)EXP1*117/100);
    EXP1=exp(EXP1);

    if (EXP1>=NPS(EXP1)) {
        P2=1;
    }
    else {
        P2=((float)EXP1/NPS(EXP1)+80)/123;
    }

    //ROAD 3
    float p_R3[10]={32,47,28,79,100,50,22,83,64,11};
    if ((E2>=0)&&(E2<=9)) {
        P3=p_R3[E2]/100;
    }
    else {
        int temp_unit = ((int)(E2/10)+(int)E2%10)%10;
        P3=p_R3[temp_unit]/100;
    }

    //Probability at the end
    if ((P1==1)&&(P2==1)&&(P3==1)) {
        EXP1=ceil(-1e-9+(float)EXP1*75/100);
        EXP1=exp(EXP1);
    }
    else {
        P=ceil(-1e-9+(P1*100+P2*100+P3*100)/3)/100;
        if (P<0.5) {
        HP1=ceil(-1e-9+(float)HP1*85/100);
        HP1=hp(HP1);
        EXP1=ceil(-1e-9+(float)EXP1*115/100);
        EXP1=exp(EXP1);
        }
        else {
        HP1=ceil(-1e-9+(float)HP1*90/100);
        HP1=hp(HP1);
        EXP1=ceil(-1e-9+(float)EXP1*120/100);
        EXP1=exp(EXP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
     //Check all the components
    if ((E3<0)||(E3>99)) return -99;
    int sum_i=0, sum_j=0;
    int i_meet,j_meet;
    HP1=hp(HP1);
    EXP1=exp(EXP1);
    HP2=hp(HP2);
    EXP2=exp(EXP2);

    // Array: Taxi's Score
    int ar_taxi [10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ar_taxi[i][j]=((E3*j+i*2)*(i-j));
            if(ar_taxi[i][j]>(2*E3)) {
                sum_i++;
            }
            if(ar_taxi[i][j]<((-1)*E3)) {
                sum_j++;
            }
        }
    }

    //Final MEET POINT
    i_meet=one_digit_point(sum_i);
    j_meet=one_digit_point(sum_j);

    // Sherlock and Watson's Score
    int max_return;
    int Sher_Wat_point=max_diag(i_meet, j_meet, ar_taxi);

    if(abs(ar_taxi[i_meet][j_meet])>Sher_Wat_point) {
        HP1=ceil(-1e-9+(float)HP1*90/100);
        HP1=hp(HP1);
        EXP1=ceil(-1e-9+(float)EXP1*88/100);
        EXP1=exp(EXP1);

        HP2=ceil(-1e-9+(float)HP2*90/100);
        HP2=hp(HP2);
        EXP2=ceil(-1e-9+(float)EXP2*88/100);
        EXP2=exp(EXP2);
        max_return=ar_taxi[i_meet][j_meet];
    } 
    else {
        HP1=ceil(-1e-9+(float)HP1*110/100);
        HP1=hp(HP1);
        EXP1=ceil(-1e-9+(float)EXP1*112/100);
        EXP1=exp(EXP1);

        HP2=ceil(-1e-9+(float)HP2*110/100);
        HP2=hp(HP2);
        EXP2=ceil(-1e-9+(float)EXP2*112/100);
        EXP2=exp(EXP2);
        max_return=Sher_Wat_point;
    }
    
    return max_return;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string str_pass = s;
    string str_mail = email;
    //Length of email and pass
    int length_mail = str_mail.length();
    int length_pass = str_pass.length();

    //Find se and @ in the email and 
    int end_se = str_mail.find("@");
    string se (str_mail, 0, end_se);

    //Check the CONDITIONS OF PASSWORD
        //minimum and maximum length
        if (length_pass<8) {
            return -1;
        }
        else if (length_pass>20) {
            return -2;
        }

        //check if s contain se
        else if(str_pass.find(se)!=(string::npos)) {
            return -(300+str_pass.find(se));
        }

        //check if s contains more than 2 consecutive and identical characters
        else if(consecutive_char(str_pass)!=-1) {
            return -(400+consecutive_char(str_pass));
        }

        //check if s has special character
        else if(!(special_char(str_pass))) {
            return -5;
        }

        //check if s has invalid character 
        else if (invalid_char(str_pass)!=(-1)){
            return invalid_char(str_pass);
        }
        else {
            return -10;
        }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string max_str;
    int max_occ=0;
    int max_position=0;
    
    for (int i=0; i<num_pwds; i++) {
        int occ=1;
        for(int j=i+1; j<num_pwds; j++) {
            if (string(arr_pwds[i])==string(arr_pwds[j])) {
                occ++;
            }
        }
        if (occ>max_occ) {
            max_occ=occ;
            max_position=i;
            max_str=string(arr_pwds[i]);
        }
        else if(occ==max_occ) {
            if (strlen(arr_pwds[i])>max_str.length()) {
            max_position=i;
            max_str=string(arr_pwds[i]);
            }
        }
    }
    return max_position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////