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
int limit(int value, int lim){
    if(value < 0)
        value = 0;
    else if(value > lim)
        value = lim;
    return value;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0 || e1>99)
        return -99;
    else{
        exp1 = limit(exp1,600);
        exp2 = limit(exp2,600);
        int d;
        if(e1>=0 && e1<=3){
            if(e1 == 0)
                exp2 += 29;
            else if(e1 == 1)
                exp2 += 45;
            else if(e1 == 2)
                exp2 += 75;
            else
                exp2 += (29+45+75);
            d = 3*e1 + 7*exp1;
            if(d%2 == 0)
                exp1 += ceil(d*1.0/200);
            else
                exp1 -= d/100;
        }
        else if(e1 <= 99){
            if(e1 <= 19){
                exp2 += ceil(e1*1.0/4 + 19);
            }
            else if(e1 <= 49)
                exp2 += ceil(e1*1.0/9 + 21);
            else if(e1 <= 65)
                exp2 += ceil(e1*1.0/16 + 17);
            else if(e1 <= 79){
                exp2 += ceil(e1*1.0/4 + 19);
                if(exp2 > 200)
                    exp2 += ceil(e1*1.0/9 + 21);
            }
            else{
                exp2 += ceil(e1*1.0/4 + 19);
                exp2 += ceil(e1*1.0/9 + 21);

                if(exp2 > 400){
                    exp2 += ceil(e1*1.0/16 + 17);
                    exp2 += ceil(15*exp2*1.0/100);
                }
            }
            exp1 -= e1;
        }
    }
    exp1 = limit(exp1,600);
    exp2 = limit(exp2,600);
    return exp1 + exp2;
}

// Task 2
double probability(int EXP1){
    int i;
    double p,s;
    i = sqrt(EXP1);
    if(EXP1 - i*i < (i+1)*(i+1) - EXP1)
        s = i*i;
    else
        s = (i+1)*(i+1);
    if(EXP1 >= s){
        p=1;
    }
    else
        p = (double) (EXP1/s + 80)/123;
    return p;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99){
        return -99;
    }
    else{
        HP1 = limit(HP1, 666);
        EXP1 = limit(EXP1, 600);
        M1 = limit(M1,3000);
        int m = M1;
        int times;
        double value;
        double p1, p2, p3, prob;
        //Road 1
        p1 = probability(EXP1);
        //Road 2
        if(E2 % 2 == 1){
            value = M1*0.5;
            times = 15;
        }
        else{
            value = 0;
            times = 3;
        }
        for(int e = 1;e<=times && M1>value;e++){
            //An uong
            if(e%3 == 1){
                if(HP1 < 200){
                    M1 -= 150;
                    HP1 += ceil(0.3*HP1);
                }
                else{
                    M1 -= 70;
                    HP1 += ceil(0.1*HP1);
                    }
            }
            //Phuong tien di chuyen
            else if(e%3==2){
                if(EXP1 < 400){
                    M1 -= 200;
                }
                else{
                    M1 -= 120;
                }
                    
                EXP1 += ceil(0.13*EXP1);
            }

            //Nguoi vo gia cu
            else{
                if(EXP1 < 300){
                    M1 -= 100;
                }
                else
                    M1 -= 120;
                    
                EXP1 -= 0.1*EXP1;
            }
        }
        HP1 -= 17*HP1/100;
        EXP1 += ceil(0.17*EXP1);
        HP1 = limit(HP1, 666);
        EXP1 = limit(EXP1, 600);
        M1 = limit(M1,3000);
        p2 = probability(EXP1);

        //Road 3
        int p[] = {32,47,28,79,100,50,22,83,64,11};
        int i;
        int temp = E2, sum = 0;
        if(E2/10 >= 1)
            i = E2;
        else{
            for(int e = 1;e<=2;e++){
                sum += temp % 10;
                temp /= 10;
            }
            i = sum % 10;
        }
        p3 = p[i]/100;
        if(p1 == 1 && p2 == 1 && p3 == 1){
            EXP1 -= EXP1*0.25;
        }
        else{
            prob = (p1 + p2 + p3)/3;
            cout<<prob<<endl;
            if(prob < 0.5){
                HP1 -= HP1*0.15;
                EXP1 += ceil(EXP1*0.15);
            }
            else{
                HP1 -= HP1*10/100;
                EXP1 += ceil(EXP1*0.2);
            }
        }
        HP1 = limit(HP1, 666);
        EXP1 = limit(EXP1, 600);
        M1 = limit(M1, 3000);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
    // TODO: Complete this function
    if(E3<0 || E3>99)
        return -99;
    else{
        HP1 = limit(HP1, 666);
        EXP1 = limit(EXP1, 600);
        HP2 = limit(HP2,666);
        EXP2 = limit(EXP2, 600);
        int i, j, countI = 0, countJ = 0, iMeet = 0, jMeet = 0;
        int index, ul, ur, dl, dr;
        int taxi[10][10],SW;
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                taxi[i][j]=((E3*j) + (i*2))*(i-j);
                if(taxi[i][j] > E3*2)
                    countI++;
                if(taxi[i][j] < -E3)
                    countJ++;
            }
        }
        for(index=1; index <= 3; index++){
            iMeet += countI%10;
            countI /= 10;
            jMeet += countJ%10;
            countJ /= 10;
        }
        if(iMeet/10 >= 1){
                iMeet = iMeet%10 + iMeet/10%10;
        }
        if(jMeet/10 >= 1){
            jMeet = jMeet%10 + jMeet/10%10;
        }
        ul = ur = dl = dr = taxi[iMeet][jMeet];
        for(index = 1; iMeet - index >=0 && jMeet - index >=0; index++){
            ul =  max(ul, taxi[iMeet - index][jMeet - index]);
        }
        for(index = 1; iMeet - index >= 0 && jMeet + index<= 9 ; index++){
            ur =  max(ur, taxi[iMeet - index][jMeet + index]);
        }
        for(index = 1; iMeet + index <= 9 && jMeet - index >= 0 ; index++){
            dl =  max(dl, taxi[iMeet + index][jMeet - index]);
        }
        for(index = 1; iMeet + index <=9 && jMeet + index <= 9; index++){
            dr =  max(dr, taxi[iMeet + index][jMeet + index]);
        }
        SW = max(ul,ur);
        SW = max(SW, dl);
        SW = max(SW, dr);
        if(abs(taxi[iMeet][jMeet]) > abs(SW)){
            EXP1 -= 12*EXP1/100;
            EXP2 -= 12*EXP2/100;
            HP1 -= 10*HP1/100;
            HP2 -= 10*HP2/100;
            return taxi[iMeet][jMeet];
        }

        else{
        EXP1 += ceil((double) 12*EXP1/100);
        EXP2 += ceil((double) 12*EXP2/100);
        HP1 += ceil((double) 10*HP1/100);
        HP2 += ceil((double) 10*HP2/100);
        }
        HP1 = limit(HP1, 666);
        EXP1 = limit(EXP1, 600);
        HP2 = limit(HP2,666);
        EXP2 = limit(EXP2, 600);
        return SW;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int i,j, count;
    if(strlen(s) < 8)
        return -1;
    else if(strlen(s)>20)
        return -2;
    else{
        char *se = new char;
        for(i = 0;i<strlen(email);i++){
            if(email[i] == '@'){
                break;
            }
            else
                se[i] = email[i];
        }
        for(i=0;i<strlen(s);i++){
            if(s[i] == se[0]){
                count = 0;
                for(j = 1; j<strlen(se);j++){
                    if(s[i + j] == se[j])
                        count++;
                }
                if(count==strlen(se)-1)
                return -(300+i);
            }
        }
        count = 0;
        for(i=0;i<strlen(s);i++){
            if(s[i]==s[i+1]){
                return -(400+i);
            }
            if(s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%')
                count++;
        }
        if(count == 0)
            return -5;
        for(i = 0;i<strlen(s);i++){
            if(s[i] == 34||s[i] < 33 || (s[i] > 37 && s[i] < 48)||(s[i]>57&&s[i]<64)||(s[i]>90 && s[i]<97)||s[i] > 122)
                return i;
        }
        return -10;
    }


}





// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int i,j;
    int largest, longest = 0;
    string word;
    int f[num_pwds];
    for(i=0;i<num_pwds;i++){
        f[i] = 0;
    }
    for(i=0;i<num_pwds;i++){
        word = arr_pwds[i];
        for(j=0;j<num_pwds;j++){
            if(arr_pwds[j]==word){
                f[i]++;
            }
        }
    }
    for(i = 0;i<num_pwds-1;i++){
        largest = max(f[i],f[i+1]);
    }
    for(i=0;i<num_pwds;i++){
        if(f[i] == largest){
            if(strlen(arr_pwds[i])>longest){
                longest = strlen(arr_pwds[i]);
            }
        }
    }
    for(i=0;i<num_pwds;i++){
        if(strlen(arr_pwds[i]) == longest && f[i]==largest)
            break;
    }
    return i;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////