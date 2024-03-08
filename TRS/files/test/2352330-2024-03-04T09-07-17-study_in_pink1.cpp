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
void modifyHp(int &hp, float amount){
    amount = ceil(amount);
    hp += amount;
    if(hp>666){
        hp = 666;
    }
    if(hp<0){
        hp = 0;
    }
}
void modifyExp(int &exp, float amount){
    amount = std::ceil(amount);
    exp += amount;
    if(exp>600){
        exp = 600;
    }
    if(exp<0){
        exp = 0;
    }
}
void modifyM(int &m, float amount){
    amount = std::ceil(amount);
    m += amount;
    if(m>3000){
        m = 3000;
    }
    if(m<0){
        m=0;
    }
}
int NearestPerfectSquare(int S){
    double sqrt_S = std::sqrt(S);
    int rounded_sqrt_S = std::round(sqrt_S);
    return rounded_sqrt_S*rounded_sqrt_S;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int E1) {
    if(E1<0||E1>99){
        return -99;
    }
    modifyExp(exp1,0);
    modifyExp(exp2,0);
    
    // TODO: Complete this function
    if(E1 == 0){
        modifyExp(exp2,29);
    }
    else if(E1 == 1){
        modifyExp(exp2,45);
    }
    else if(E1 == 2){
        modifyExp(exp2,75);
    }
    else if(E1 == 3){
        modifyExp(exp2, 149);
    }
    else if (E1 >=4 && E1 <= 19){
        float add_value= float(E1)/4 + 19;
        modifyExp(exp2,add_value);
    }
    else if (E1 >=20 && E1 <=49){
        float add_value= float(E1)/9 + 21;
        modifyExp(exp2,add_value);
    }
    else if (E1 >= 50 && E1 <= 65){
        float add_value= float(E1)/16 + 17;
        modifyExp(exp2,add_value);
    }
    else if (E1 >=66 && E1 <=79){
        float add_value = float(E1)/4 + 19;
        modifyExp(exp2,add_value);
        if(exp2>200) {
            add_value = float(E1)/9 + 21;
            modifyExp(exp2,add_value);
        }
    }
    else if (E1 >=80 && E1 <=99){
        float add_value=float(E1)/4 + 19;
        modifyExp(exp2,add_value);
        add_value= float(E1)/9 + 21;
        modifyExp(exp2,add_value);
        if(exp2>400) {
            add_value= float(E1)/16 + 17;
            modifyExp(exp2,add_value);
            add_value= float(exp2)*0.15;
            modifyExp(exp2,add_value);
        }
    }
    if(E1 >=0 && E1<=3){
        int D = E1*3 + exp1*7;
        float add_value;
        if(D%2==0) add_value = float(D)/200;
        else add_value = -float(D)/100;
        modifyExp(exp1, add_value);

    }
    if(E1>=4 && E1<=99){
        modifyExp(exp1,-E1);
    }
    
    return exp1 + exp2;
}

// Task 2

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2<0||E2>99){
        return -99;
    }
    modifyHp(HP1,0);
    modifyExp(EXP1,0);
    modifyM(M1,0);
    // TODO: Complete this function
    int initialM1 = M1;
    int paidM=0;
    float P1,P2,P3;
    int S1,S2;
    //Road 1
    S1 = NearestPerfectSquare(EXP1);
    if(EXP1 >= S1){
        P1 = 1;
    }
    else P1 = (float(EXP1)/S1+80)/123;
    
    //Road 2
    if(E2%2 !=0 ){
        while(paidM<=float(initialM1)/2&&M1!=0){
            //1
            if(HP1<200){
                
                modifyHp(HP1,float(HP1)*0.30);
                
                modifyM(M1,-150);
                paidM +=150;
            }
            else{
                modifyHp(HP1,float(HP1)*0.1);    
                 
                modifyM(M1,-70);
                paidM +=70;
                
            }
            if(paidM>float(initialM1)/2) break;

            //2
            if(EXP1<400){
                modifyM(M1,-200);
                paidM +=200;
            }
            else {
                modifyM(M1,-120);
                paidM +=120;
            }
            modifyExp(EXP1,float(EXP1)*0.13);
            if(paidM>float(initialM1)/2) break;

            //3
            if(EXP1<300){
                modifyM(M1,-100);
                paidM +=100;
            }
            else{
                modifyM(M1,-120);
                paidM +=120;
            }
            modifyExp(EXP1,-float(EXP1)*0.1);
        }
        float add_value = -float(HP1)*17/100;
        modifyHp(HP1,add_value);
        add_value = float(EXP1*17)/100;
        modifyExp(EXP1,add_value);
    }
    else{
        //1
        if(HP1<200 &&M1!=0){
            modifyHp(HP1,float(HP1)*0.30);
            modifyM(M1,-150);
        }
        else if(M1!=0){
            modifyHp(HP1,float(HP1)*0.1);
            modifyM(M1,-70);
        }
        
        //2
        if(EXP1<400&& M1!=0){
            modifyM(M1,-200);
            modifyExp(EXP1,float(EXP1)*0.13);
        }
        else if(M1!=0){
            modifyM(M1,-120);
            modifyExp(EXP1,float(EXP1)*0.13);
        }
        

        //3
        if(EXP1<300&&M1!=0){
            modifyM(M1,-100);
            modifyExp(EXP1,-float(EXP1)*0.1);
        }
        else if(M1!=0){
            modifyM(M1,-120);
            modifyExp(EXP1,-float(EXP1)*0.1);
        }
        

        float add_value = -float(HP1)*17/100;
        modifyHp(HP1,add_value);
        add_value = float(EXP1*17)/100;
        modifyExp(EXP1,add_value);
        
    }

    S2 = NearestPerfectSquare(EXP1);
    
    if(EXP1 >= S2){
        P2 = 1;
    }
    else P2 = (float(EXP1)/S2+80)/123;
    
    
    //Road 3
    int array_P3[11] = {32,47,28,79,100,50,22,83,64,11};
    int i;
    if(E2<10){
        i=E2;
    }
    else{
        i= E2%10 + E2/10;
    }
    P3 = float(array_P3[i%10])/100;
    float average_P = std::ceil((P1+P2+P3)/3*100)/100;
    if(average_P == 1){
        modifyExp(EXP1,-float(EXP1)*0.25);
    }
    else if(average_P<0.5){
        modifyExp(EXP1,float(EXP1)*0.15);
        modifyHp(HP1,-float(HP1)*0.15);
    }
    else if(average_P>=0.5){
        modifyExp(EXP1,float(EXP1)*0.2);
        modifyHp(HP1,-float(HP1)*0.1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3<0||E3>99){
        return -99;
    }
    modifyExp(EXP1,0);
    modifyHp(HP1,0);
    modifyExp(EXP2,0);
    modifyHp(HP2,0);
    
    // TODO: Complete this function
    int grade_matrix[10][10];
    int taxiGrade;
    int SW_Grade=-999999; //Sherlock and Watson's Grade
    int count_i=0, count_j=0;
    for(int i=0;i<10;i++){
        for(int j=0; j<10;j++){
            grade_matrix[i][j]= (E3*j+i*2)*(i-j);
            if(grade_matrix[i][j]>(E3*2)&&grade_matrix[i][j]>=0){
                count_i++;
            }
            if(grade_matrix[i][j]<-E3&&grade_matrix[i][j]<0){
                count_j++;
            }
        }
    }
    while(count_i>=10){
        count_i = (count_i%10) + (count_i/10);
    }
    while(count_j>=10){
        count_j = (count_j%10) + (count_j/10);
    }
    taxiGrade = grade_matrix[count_i][count_j];
    for(int i=0;i<10;i++){
        for(int j=0; j<10;j++){
            if(abs(i-count_i)==abs(j-count_j)){
                if(SW_Grade<grade_matrix[i][j]){
                    SW_Grade = grade_matrix[i][j];
                }
            }
        }
    }
    if(abs(taxiGrade)>SW_Grade){
        modifyExp(EXP1,-float(EXP1)*0.12);
        modifyExp(EXP2,-float(EXP2)*0.12);
        modifyHp(HP1,-float(HP1)*0.1);
        modifyHp(HP2,-float(HP2)*0.1);
        return taxiGrade;
    }
    else{
        modifyExp(EXP1,float(EXP1)*0.12);
        modifyExp(EXP2,float(EXP2)*0.12);
        modifyHp(HP1,float(HP1)*0.1);
        modifyHp(HP2,float(HP2)*0.1);
        return SW_Grade;
    }

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char *at_position = strchr(email,'@');
    string s_string(s);
    string email_string(email);
    string email_substring = email_string.substr(0,at_position - email);
    int repeated_error_pos;
    bool isRepeated = false;
    int contain_se_error_pos;
    bool isContainSpecialCharacter = false;
    int isContainFalseSpecialCharacter = -1;
    const char *s_substring = strstr(s,email_substring.c_str());
    if(s_string.length()<8){
        return -1;
    }
    else if(s_string.length()>20){
        return -2;
    }
    else{
        for(int i=0;i<s_string.length();i++){
            if(i<s_string.length()-2)
                if(s[i]==s[i+1]&&s[i]==s[i+2]){
                    repeated_error_pos = i;
                    isRepeated = true;
                    break;
                }
            if(!(isalnum(s[i])||s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!')&&isContainFalseSpecialCharacter==-1){
                isContainFalseSpecialCharacter = i;
            }
            if(s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
                isContainSpecialCharacter=true;
            }
        }
        
        if(s_substring!= nullptr){
            contain_se_error_pos = s_substring-s;
            return -(300+contain_se_error_pos);
        }

        if(isRepeated){
            return -(400+repeated_error_pos);
        }
       
        
        if(!isContainSpecialCharacter){
            return -5;
        }
        if(isContainFalseSpecialCharacter!=-1){
            return isContainFalseSpecialCharacter;
        }
        
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    pair<int,int> max = pair<int,int>(-1000,-1);
    for (int i = 0; i < num_pwds; i++) {
        
        bool isDistinct = true;

        for (int j = 0; j < i; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct) {
            int count_num = 1; 
            for (int k = i + 1; k < num_pwds; k++) {
                string str1(arr_pwds[i]);
                string str2(arr_pwds[k]);
                if (str1 == str2) {
                    count_num++;
                }
            }
            if(count_num > max.first){
                max.first = count_num;
                max.second = i;
            }
            else if(count_num==max.first){
                if(strlen(arr_pwds[i])>strlen(arr_pwds[max.second])){
                    max.second = i;
                }
            }
            
        }
    }
    
    return max.second;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////