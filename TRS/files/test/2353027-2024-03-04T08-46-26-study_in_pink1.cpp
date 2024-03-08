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


int interval(int a, int start, int end){
    a = (a < start) ? start : (a > end) ? end : a;
    return a;
}
float findNearestPerfectSquare(float num) {
  float lowerSquare = floor(sqrt(num)) * floor(sqrt(num));
  float upperSquare = ceil(sqrt(num)) * ceil(sqrt(num));
  float S;
  if (num - lowerSquare <= upperSquare - num) {
    S = lowerSquare; //EXP1>=S
    return 1.0000;
  } else {
    S = upperSquare;
    return (num/S +80)/123;
  }
}
int findMaxDiagonal(int matrix[10][10], int a, int b){
    int n=10;
    int maxVal = INT_MIN;
    for (int i = a, j = b; i < n && j >= 0; i++, j--) {
        if (matrix[i][j] > maxVal) {
            maxVal = matrix[i][j];
        }
    }
    for (int i = a, j = b; i < n && j < n; i++, j++) {
        if (matrix[i][j] > maxVal) {
            maxVal = matrix[i][j];
        }
    } return abs(maxVal);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1){
    //check information
    int start=0, end=600;
    exp1=interval(exp1, start, end);
    exp2=interval(exp2, start, end);
    if (e1<0||e1>99) return -99;

    //declare variables
    float exp1_float=exp1, exp2_float=exp2; //convert to float to calculate
    float info1_2_1 = e1 * 1.0000 / 4 + 19, info1_2_2 = e1 * 1.0000 / 9 + 21, info1_2_3 = e1 * 1.0000 / 16 + 17;
    //case1
    if (e1<=3){
        switch (e1){
            case 0:
            {
                exp2+=29;
                break;
            }
            case 1:
            {
                exp2+=45;
                break;
            }
            case 2:
            {
                exp2+=75;
                break;
            }
            case 3:
            {
                exp2=exp2+29+45+75;
                break;
            }
        }
        int D=e1*3 + exp1*7;
        if (D%2==0) exp1_float=ceil(exp1_float + D*1.0000/200);
        else exp1_float=ceil(exp1_float - D*1.0000/100);  //round up 
        exp1=exp1_float; 
    }
    //case2 
    else {
        if (e1>=4&&e1<=19) exp2_float=ceil(exp2_float+info1_2_1);
        else if (e1>=20&&e1<=49) exp2_float=ceil(exp2_float+info1_2_2);
        else if (e1>=50&&e1<=65) exp2_float=ceil(exp2_float+info1_2_3);
        else if (e1>=66&&e1<=79) {
            exp2_float=ceil(exp2_float + info1_2_1);
            exp2=exp2_float;
            exp2=interval(exp2, start, end); //check again
            exp2_float=exp2; //convert to float to calculate
            if (exp2_float>200) exp2_float=ceil(exp2_float+info1_2_2);
        }
        else {
            exp2_float=ceil(exp2_float + info1_2_1);
            exp2=exp2_float;
            exp2=interval(exp2, start, end); 
            exp2_float=exp2;
            exp2_float=ceil(exp2_float + info1_2_2);
            exp2=exp2_float;
            exp2=interval(exp2, start, end); //check again
            exp2_float=exp2; //convert to float to calculate
            if (exp2_float>400) {
            exp2_float=ceil(exp2_float+info1_2_3);
            exp2=exp2_float;
            exp2=interval(exp2, start, end); //check again
            exp2_float=exp2; 
            exp2_float=ceil(exp2_float*1.1500);
            }
        }
    exp1 -= e1;
    exp2=exp2_float; //convert to int
    }

    exp1=interval(exp1, start, end);
    exp2=interval(exp2, start, end);   //check results
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //check information
    EXP1=interval(EXP1, 0, 600);
    HP1=interval(HP1, 0, 666);
    M1=interval(M1, 0, 3000);
    if (E2<0||E2>99) return -99;
    //variables
    float P1, P2, P3, P4;
    float HP1_float=HP1, EXP1_float=EXP1;
    int PaidM1=0, halfM1=0.5*M1;
    //road1
    P1 = findNearestPerfectSquare(EXP1_float);

    //road2
    if (E2 % 2 != 0) { // E2 is odd
        while (PaidM1 <= halfM1) {
        if (HP1_float < 200){
            HP1_float = 1.3*HP1_float;
            HP1_float=ceil(HP1_float);
            M1-=150;
            PaidM1+=150;
            M1=interval(M1, 0, 3000); //check interval
            HP1=HP1_float;
            HP1=interval(HP1, 0, 666); //check interval
            HP1_float=HP1; //reconvert to float to calculate
            if (PaidM1 > halfM1) break;
        } else {
            HP1_float = 1.1*HP1_float;
            HP1_float=ceil(HP1_float);
            M1-=70;   
            PaidM1+=70;
            M1=interval(M1, 0, 3000); //check interval
            HP1=HP1_float;
            HP1=interval(HP1, 0, 666); //check interval
            HP1_float=HP1; //reconvert to float to calculate
            if (PaidM1 > halfM1) break;
        }
        if (EXP1_float<400){
            M1-=200;
            PaidM1+=200;
            M1=interval(M1, 0, 3000); //check interval
            EXP1_float=ceil(EXP1_float*1.13);
            EXP1=EXP1_float;
            EXP1=interval(EXP1, 0, 600); //check interval
            EXP1_float=EXP1; //reconvert to float to calculate
            if (PaidM1 > halfM1) break;
        } else{
            M1-=120;
            PaidM1+=120;
            M1=interval(M1, 0, 3000); //check interval
            EXP1_float=ceil(EXP1_float*1.13);
            EXP1=EXP1_float;
            EXP1=interval(EXP1, 0, 600); //check interval
            EXP1_float=EXP1; //reconvert to float to calculate
            if (PaidM1 > halfM1) break;
        }
        if (EXP1_float<300){
            M1-=100;
            PaidM1+=100;
            M1=interval(M1, 0, 3000); //check interval
            EXP1_float=ceil(EXP1_float*0.9);
            if (PaidM1 > halfM1) break;
        } else {
            M1-=120;
            PaidM1+=120;
            M1=interval(M1, 0, 3000); //check interval
            EXP1_float=ceil(EXP1_float*0.9);
            if (PaidM1 > halfM1) break;
            }
        } //end of while
        
        } else { //E2 is even
        while (M1 > 0) {
            if (HP1_float < 200){
            HP1_float = 1.3*HP1_float;
            HP1_float=ceil(HP1_float);
            M1-=150;
            PaidM1+=150;
            M1=interval(M1, 0, 3000); //check interval
            HP1=HP1_float;
            HP1=interval(HP1, 0, 666); //check interval
            HP1_float=HP1; //reconvert to float to calculate
            if (M1 == 0) break;
        } else {
            HP1_float = 1.1*HP1_float;
            HP1_float=ceil(HP1_float);
            M1-=70;   
            PaidM1+=70;
            M1=interval(M1, 0, 3000); //check interval
            HP1=HP1_float;
            HP1=interval(HP1, 0, 666); //check interval
            HP1_float=HP1; //reconvert to float to calculate
            if (M1 == 0) break;
        }
        if (EXP1_float<400){
            M1-=200;
            PaidM1+=200;
            M1=interval(M1, 0, 3000); //check interval
            EXP1_float=ceil(EXP1_float*1.13);
            EXP1=EXP1_float;
            EXP1=interval(EXP1, 0, 600); //check interval
            EXP1_float=EXP1; //reconvert to float to calculate
            if (M1 == 0) break;
        } else{
            M1-=120;
            PaidM1+=120;
            M1=interval(M1, 0, 3000); //check interval
            EXP1_float=ceil(EXP1_float*1.13);
            EXP1=EXP1_float;
            EXP1=interval(EXP1, 0, 600); //check interval
            EXP1_float=EXP1; //reconvert to float to calculate
            if (M1 == 0) break;
        }
        if (EXP1_float<300){
            M1-=100;
            PaidM1+=100;
            M1=interval(M1, 0, 3000); //check interval
            EXP1_float=ceil(EXP1_float*0.9);
            break;
        } else {
            M1-=120;
            PaidM1+=120;
            M1=interval(M1, 0, 3000); //check interval
            EXP1_float=ceil(EXP1_float*0.9);
            break;
            }
        } //end of while & converted HP1 to int

        } //end of "E2 is even"
    HP1_float=ceil(HP1_float*0.83);
    EXP1_float=ceil(EXP1_float*1.17);
    EXP1=EXP1_float;
    EXP1=interval(EXP1, 0, 600); //check interval
    //dont need to check HP1 because of 0.83
    EXP1_float=EXP1;
    P2 = findNearestPerfectSquare(EXP1_float);

    //road3
    float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) {
        P3 = P[E2]/100;
    } else {
    int a,b;
        a = E2/10;
        b = E2%10;
        P3 = P[(a+b)%10]/100;
    }
    if (P1 == 1.0000 && P2 == 1.0000 & P3 == 1.0000) {
        EXP1_float=ceil(EXP1_float*0.75);
    } else {
        P4 = (P1 + P2 + P3)/3;
        if (P4 < 0.5) {
            EXP1_float=ceil(EXP1_float*1.15);
            HP1_float=ceil(HP1_float*0.85);
        }
        else {
            EXP1_float=ceil(EXP1_float*1.2);
            HP1_float=ceil(HP1_float*0.9);
        }
    }
    //check results
    EXP1=EXP1_float;
    HP1=HP1_float;
    EXP1=interval(EXP1, 0, 600); 
    HP1=interval(HP1, 0, 666);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //check information
    HP1=interval(HP1, 0, 666);
    EXP1=interval(EXP1, 0, 600);
    HP2=interval(HP2, 0, 666);
    EXP2=interval(EXP2, 0, 600);
    if (E3<0||E3>99) return -99;
    //variables
    float HP1_float=HP1, EXP1_float=EXP1, HP2_float=HP2, EXP2_float=EXP2;
    int matrix[10][10], a=0, b=0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
        matrix[i][j] = ((E3*j)+(i*2))*(i-j); 
        if (matrix[i][j] > E3*2) a+=1;
        else if (matrix[i][j]<-E3) b+=1;
        }
    }
    while (a>=10){
        a=a/10+a%10;
    }
    while (b>=10){
        b=b/10+b%10;
    }
    int maxVal = findMaxDiagonal(matrix, a, b); //S&W score
    int biggerVal = (abs(matrix[a][b]) > maxVal) ? abs(matrix[a][b]) : maxVal;
    if (biggerVal==-matrix[a][b]&&matrix[a][b]!=-maxVal){ //exclude the case SWscore=-taxiscore
        biggerVal=matrix[a][b];
    }
    if (abs(matrix[a][b])>maxVal){
        EXP1_float=ceil(EXP1_float*0.88);
        HP1_float=ceil(HP1_float*0.9);
        EXP2_float=ceil(EXP2_float*0.88);
        HP2_float=ceil(HP2_float*0.9);
    } else {
        EXP1_float=EXP1_float*1.12;
        EXP1_float=ceil(EXP1_float);
        HP1_float=HP1_float*1.1;
        HP1_float=ceil(HP1_float);
        EXP2_float=EXP2_float*1.12;
        EXP2_float=ceil(EXP2_float);
        HP2_float=HP2_float*1.1;
        HP2_float=ceil(HP2_float);
    }
    //check results
    HP1=HP1_float;
    EXP1=EXP1_float;
    HP2=HP2_float;
    EXP2=EXP2_float;
    HP1=interval(HP1, 0, 666);
    EXP1=interval(EXP1, 0, 600);
    HP2=interval(HP2, 0, 666);
    EXP2=interval(EXP2, 0, 600);
    return biggerVal;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string emailstr = email, sstr = s, se;
    string special = "@#%$!";
    int a=emailstr.find('@');
    se=emailstr.substr(0,a);
    if (strlen(s)<8) return -1;
     else if (strlen(s)>20) return -2;
     else if (sstr.find(se)!=string::npos) return -(300+sstr.find(se));
     for (int i=0; i<strlen(s)-2; i++){
        if (s[i]==s[i+1] and s[i] == s[i+2]) return -(400+i);
     }
    if (sstr.find("@")==string::npos && sstr.find("#")==string::npos && sstr.find("%")==string::npos && sstr.find("$")==string::npos && sstr.find("!")==string::npos) return -5;
    for (int i=0, n=sstr.size(); i<n; i++){
        if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && special.find(s[i]) == string::npos) {
            return i;  //invalid character position
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string passwords[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        passwords[i] = string(arr_pwds[i]); //convert char to string
    }
    int freq[num_pwds]={0};
    for (int i=0; i<num_pwds; i++){
        freq[i]++; //initialize freq of each string to 1
        for (int j=i+1; j<num_pwds; j++){
            if (passwords[i]==passwords[j]){
                freq[i]++; //Increment frequency if the same string is found

            }
        }
    }
    int maxfreq=0, maxlength=0;
    for (int i=0; i<num_pwds; i++){
        maxfreq=(freq[i]>maxfreq)?freq[i]:maxfreq; 
    }
    string highestFrequencyStrings[num_pwds], longestStrings[num_pwds], correctpassword;
    int k=0;
    for (int i=0; i<num_pwds; i++){ //store the strings with highest frequency
        if (freq[i]==maxfreq){
            highestFrequencyStrings[k++]=passwords[i];
        }
    }
    int n=sizeof(highestFrequencyStrings)/sizeof(highestFrequencyStrings[0]);
    int position=0;
    if (n==1) {
        for (int i=0; i<num_pwds; i++){
            if (passwords[i]==highestFrequencyStrings[0]){
                position=i;
                break;
                } //the only highest frequency string     
            return i;   
        }
        
    } 
    int length[n]={0};
    for (int i=0; i<n; i++){
        length[i]=highestFrequencyStrings[i].length();
        if (length[i]>maxlength){
            maxlength=length[i];
            correctpassword=highestFrequencyStrings[i];
        }
    }
    for (int i=0; i<num_pwds; i++){
        if (passwords[i]==correctpassword){
            position=i;
            break;
        }
    }
    return position;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////