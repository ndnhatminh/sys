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

void checkLimit(int& x, int upperLim, int lowerLim){
    x = min(x, upperLim);  //min(): return smaller value
    x = max(x, lowerLim);  //max(): return bigger value
}

// Task 1 (finished)
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkLimit(exp1,600,0);
    checkLimit(exp2,600,0);
    if(e1>=0 && e1 <= 3){
        int d;
        d = (3*e1 + exp1*7);
        switch(e1){
            case 0:
                exp2 +=29;
                checkLimit(exp2, 600, 0);
                break;
            case 1:
                exp2 += 45;
                checkLimit(exp2, 600, 0);
                break;
            case 2:
                exp2 += 75;
                checkLimit(exp2, 600, 0);
                break;
            case 3:
                exp2 += 149;
                checkLimit(exp2, 600, 0);
                break;
        }
        if(d%2==0) exp1 = (double)exp1 + (double)d/200 + 0.9999;
        else exp1 = (double)exp1 - (double)d/100 + 0.9999;

        checkLimit(exp1, 600, 0);
    }
    else if(e1 >=4 && e1 <= 19){
        exp2 = (double)exp2 + (double)e1/4 + 19 + 0.9999;
        checkLimit(exp2, 600, 0);

        exp1 -= e1;
        checkLimit(exp1, 600, 0);
    }
    else if(e1 >= 20 && e1 <=49){
        exp2 = (double)exp2 + (double)e1/9 + 21 + 0.9999;
        checkLimit(exp2, 600, 0);
        exp1 -= e1;
        checkLimit(exp1, 600, 0);
    }
    else if(e1 >=50 && e1 <= 65){
        exp2 = (double)exp2 + (double)e1/16 + 17 + 0.9999;
        checkLimit(exp2, 600, 0);

        exp1 -= e1;
        checkLimit(exp1, 600, 0);
    }
    else if(e1 >= 66 && e1 <= 79){
        exp2 = (double)exp2 + (double)e1/4 + 19 + 0.9999;
        checkLimit(exp2, 600, 0);

        if(exp2 > 200){
            exp2 = (double)exp2 + (double)e1/9 + 21 + 0.9999;
            checkLimit(exp2, 600, 0);
        }

        exp1 -= e1;
        checkLimit(exp1, 600, 0);
    }
    else if(e1 >= 80 && e1 <= 99){
        exp2 = (double)exp2 + (double)e1/4 + 19 + 0.9999;
        exp2 = (double)exp2 + (double)e1/9 + 21 + 0.9999;
        checkLimit(exp2, 600, 0);

        if(exp2 > 400){
            exp2 = (double)exp2 + (double)e1/16 + 17 + 0.9999;
            exp2 = exp2 * 1.15 + 0.9999;
            checkLimit(exp2, 600, 0);
        }

        exp1 -= e1;
        checkLimit(exp1, 600, 0);
    }
    else{
        return -99;
    }
    return exp1 + exp2;
}

// Task 2 (finished)
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;
    checkLimit(HP1,666,0);
    checkLimit(EXP1,600,0);
    checkLimit(M1,3000,0);
    //Road 1
    int x = sqrt(EXP1);
    double p1;
    if((x*x) == EXP1) p1 = 100;
    else{
        int biggerS = (x+1)*(x+1), smallerS = x*x;
        int diff1 = biggerS - EXP1;
        int diff2 = EXP1 - smallerS;
        if(diff1 > diff2){ //nearest square is smaller
            p1 = 100;
        }
        else{
            int s = (x+1)*(x+1);
            p1 = (double)(((double)(EXP1/s) + 80)/123)*100;
        }
    }

    //Road 2
    double mo = M1/2, paid = 0;
    if(E2 % 2 == 1){
        while(true){
            //Event 1
            if(HP1<200){
                HP1 = HP1*1.3 + 0.9999;
                checkLimit(HP1,666,0);
                M1 -= 150;
                paid += 150;
                checkLimit(M1,3000,0);
            }
            else{
                HP1 = HP1*1.1 + 0.9999;
                checkLimit(HP1,666,0);
                M1 -= 70;
                paid += 70;
                checkLimit(M1,3000,0);
            }
            if(paid > mo) break;

            //Event 2
            if(EXP1<400){
                M1-=200;
                paid += 200;
                checkLimit(M1,3000,0);
            }
            else{
                M1-=120;
                paid+=120;
                checkLimit(M1,3000,0);
            }
            EXP1 = EXP1*1.13 + 0.9999;
            checkLimit(EXP1,600,0);
            if(paid > mo) break;

            //Event 3
            if(EXP1 < 300){
                M1 -= 100;
                paid +=100;
                checkLimit(M1,3000,0);
            }
            else{
                M1 -=120;
                paid+=120;
                checkLimit(M1,3000,0);
            }
            EXP1 = EXP1*0.9 + 0.9999;
            checkLimit(EXP1,600,0);
            if(paid > mo) break;
        }
    }
    else{
        //Event 1
        if(M1 > 0){
            if(HP1<200){
                HP1 = HP1*1.3 + 0.9999;
                checkLimit(HP1,666,0);
                M1 -= 150;
                checkLimit(M1,3000,0);
            }
            else{
                HP1 = HP1*1.1 + 0.9999;
                checkLimit(HP1,666,0);
                M1 -= 70;
                checkLimit(M1,3000,0);
            }

            if(M1 > 0){
                //Event 2
                if(EXP1<400){
                    M1-=200;
                    checkLimit(M1,3000,0);
                }
                else{
                    M1-=120;
                    checkLimit(M1,3000,0);
                }
                EXP1 = EXP1*1.13 + 0.9999;
                checkLimit(EXP1,600,0);

                if(M1 > 0){
                    //Event 3
                    if(EXP1 < 300){
                        M1 -= 100;
                        checkLimit(M1,3000,0);
                    }
                    else{
                        M1 -=120;
                        checkLimit(M1,3000,0);
                    }
                    EXP1 = EXP1*0.9 + 0.9999;
                    checkLimit(EXP1,600,0);
                }
            }
        }
    }
    HP1 = HP1*0.83 + 0.9999;
    checkLimit(HP1,666,0);
    EXP1 = EXP1*1.17 + 0.9999;
    checkLimit(EXP1,600,0);

    x = sqrt(EXP1);
    double p2;
    if((x*x) == EXP1) p2 = 100;
    else{
        int biggerS = (x+1)*(x+1), smallerS = x*x;
        int diff1 = biggerS - EXP1;
        int diff2 = EXP1 - smallerS;
        if(diff1 > diff2){ //nearest square is smaller
            p2 = 100;
        }
        else{
            int s = (x+1)*(x+1);
            p2 = (double)(((double)(EXP1/s) + 80)/123)*100;
        }
    }

    //Road 3
    int ap[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int p3;
    if(E2>=0 && E2<=9){
        p3 = ap[E2];
    }
    else if(E2 >= 10 && E2 <= 99){
        int i = (E2/10 + E2%10)%10;
        p3 = ap[i];
    }

    int p;
    if(p1 == 100 && p2 == 100 && p3 == 100){
        EXP1 = EXP1*0.75 + 0.9999;
        checkLimit(EXP1,600,0);
    }
    else{
        p = (p1+p2+p3)/3;
        if(p<50){
            HP1 = HP1*0.85 + 0.9999;
            checkLimit(HP1,666,0);
            EXP1 = EXP1*1.15 + 0.9999;
            checkLimit(EXP1,600,0);
        }
        else{
            HP1 = HP1*0.90 + 0.9999;
            checkLimit(HP1,666,0);
            EXP1 = EXP1*1.20 + 0.9999;
            checkLimit(EXP1,600,0);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3 (finished)
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;
    checkLimit(HP1,666,0);
    checkLimit(HP2,666,0);
    checkLimit(EXP1,600,0);
    checkLimit(EXP2,600,0);

    int matrix[10][10];
    int iCnt = 0, jCnt = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            matrix[i][j] = ((E3*j) + (i*2)) * (i-j);
            if(matrix[i][j] > (E3*2)) ++iCnt;
            if(matrix[i][j] < (-E3)) ++jCnt;
        }
    }

    int row, col;
    if(iCnt >= 0 && iCnt <= 9) row = iCnt;
    else{
        row = iCnt/10 + (iCnt%10);
        if(row>=10){
            row = row/10 + (row%10);
        }
    }
    if(jCnt >= 0 && jCnt <= 9) col = jCnt;
    else{
        col = jCnt/10 + (jCnt%10);
        if(col>=10){
            col = col/10 + (col%10);
        }
    }

    int score, maxLeft = INT_MIN, maxRight = INT_MIN;
    //find largest value on left-hand diagonal
    if(row-col>=0){
        int startingRow = row-col, startingCol = 0;
        while(startingRow < 10){
            maxLeft = max(maxLeft, matrix[startingRow++][startingCol++]);
        }
    }
    else{
        int startingRow = 0, startingCol = col-row;
        while(startingCol < 10){
            maxLeft = max(maxLeft, matrix[startingRow++][startingCol++]);
        }
    }

    //find largest value on right-hand diagonal
    if(!(row == 0 && col == 0) && !(row == 9 && col == 9)){
        if(row+col < 10){
            int startingRow = row+col, startingCol = 0;
            while(startingRow >= 0){
                maxRight = max(maxRight, matrix[startingRow--][startingCol++]);
            }
        }
        else{
            int startingRow = 9, startingCol = (row+col)%9;
            cout << startingRow << " " << startingCol << '\n';
            while(startingCol < 10){
                maxRight = max(maxRight, matrix[startingRow--][startingCol++]);
            }
        }
    }

    score = abs(max(maxLeft,maxRight)); //score of Holmes and Watson
    if(abs(matrix[row][col]) > score){
        EXP1 = EXP1*0.88 + 0.9999;
        checkLimit(EXP1,600,0);
        EXP2 = EXP2*0.88 + 0.9999;
        checkLimit(EXP2,600,0);
        HP1 = HP1*0.9 + 0.9999;
        checkLimit(HP1,666,0);
        HP2 = HP2*0.9 + 0.9999;
        checkLimit(HP2,666,0);
        return matrix[row][col];
    }
    else{
        EXP1 = EXP1*1.12 + 0.9999;
        checkLimit(EXP1,600,0);
        EXP2 = EXP2*1.12 + 0.9999;
        checkLimit(EXP2,600,0);
        HP1 = HP1*1.1 + 0.9999;
        checkLimit(HP1,666,0);
        HP2 = HP2*1.1 + 0.9999;
        checkLimit(HP2,666,0);
        return score;
    }
}

// Task 4 (Finished)
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S = s;
    string Email = email;

    //check for string size
    if(S.size() < 8) return -1;
    if(S.size() > 20) return -2;

    //check for existence of se
    string se = "";
    for(int i = 0; i < Email.size(); ++i){
        if(Email[i] == '@') break;
        se += Email[i];
    }
    
    auto found = S.find(se); //"auto" automatically find a suitable type for found
    //S.find(se) searchs for existence of string se in S and returns position of first occurrence of se if found
    if (found != string::npos){  //if se is found in S
        int num = found;
        return -(300 + num);
    }

    //check for consecutive similar chars
    for(int i = 0; i < S.size() - 2; ++i){
        if(S[i] == S[i+1] && S[i] == S[i+2]) return -(400+i);
    }

    //check for special chars
    bool existSpecial = false;
    for(int i = 0; i < S.size(); ++i){
        if( S[i] == '@' || S[i] == '#' || S[i] == '%' || S[i] == '$' || S[i] == '!'){
            existSpecial = true;
            break;
        }
    }
    if(!existSpecial) return -5;

    //check for invalid chars
    for(int i = 0; i < S.size(); ++i){
        if(!(isalnum(S[i]) || S[i] == '@' || S[i] == '#' || 
            S[i] == '%' || S[i] == '$' || S[i] == '!'))
        {
            return i;
        }
    }
    return -10;
}

// Task 5 (Finished)
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string password[num_pwds];
    for(int i = 0; i < num_pwds; ++i){
        password[i] = arr_pwds[i];
    }
    int maxFreq = 0, maxLength, res = 0;
    for (int i = 0; i < num_pwds; i++) {
        int count = 1, length = password[i].size();
        for (int j = i + 1; j < num_pwds; j++) {
            if (password[j] == password[i]) ++count;
        }
        if(count == maxFreq){
            if(length > maxLength){
                res = i;
                maxLength = length;
            }
        }
        if (count > maxFreq) {
            res = i;
            maxFreq = count;
            maxLength = length;
        }
    }
    return res;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////