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

    void check1(int & exp1, int & exp2){
        if(exp1 < 0)
            exp1 = 0;
        if(exp1 > 600)
            exp1 = 600;
        if(exp2 < 0)
            exp2 = 0;
        if(exp2 > 600)
            exp2 = 600;
    }
    // Task 1
    int firstMeet(int & exp1, int & exp2, int e1) {
        // TODO: Complete this function
        
        if(e1 < 0 || e1 > 99){
            return -99;
        }
        else{
            //4.1.1
            check1(exp1, exp2);
            if(e1 >= 0 && e1 <= 3){
                switch (e1)
                {
                    case 0:
                        exp2 += 29;
                        break;
                    case 1:
                        exp2 += 45;
                        break;
                    case 2:
                        exp2 += 75;
                        break;
                    case 3:
                        exp2 += 149;
                        break;
                } 
                int d = e1*3+exp1*7;
                if(d % 2 == 0){
                    exp1 = exp1 + ceil(d/200.0);
                }else{
                    exp1 = ceil(exp1 - d/100.0);
                }
            }
            //4.1.2
            else if(e1 >= 4 && e1 <= 99){
                if(e1 >= 4 && e1 <= 19){
                    exp2 += ceil(e1/4.0+19);
                }
                else if(e1 >= 20 && e1 <= 49){
                    exp2 += ceil(e1/9.0+21);
                }
                else if(e1 >= 50 && e1 <= 65){
                    exp2 += ceil(e1/16.0+17);
                }
                else if(e1 >= 66 && e1 <= 79){
                    exp2 += ceil(e1/4.0+19);
                    if(exp2 > 200)
                        exp2 += ceil(e1/9.0+21);
                }
                if(e1 >= 80 && e1 <= 99){
                    exp2 += ceil(e1/4.0+19) + ceil(e1/9.0+21);
                    if(exp2 > 400){
                        exp2 += ceil(e1/16.0+17);
                        exp2 += ceil(exp2 * 0.15);
                    }  
                }
                exp1 -= e1;
            }
        }
        check1(exp1, exp2);
        return exp1 + exp2;
    }

    // Task 2
    int closestPerfSqr(int n){
        int sqr = (int)sqrt(n);            //use for 1st Path
        int s1 = sqr * sqr;
        int s2 = (sqr+1)*(sqr+1);
        return (n-s1 < s2-n) ? s1 : s2;
    }
    int sum(int n){
        //use for 3rd path
        int sum = 0;
        while(n != 0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    void check2(int & HP1, int & EXP1, int & M1){
        if(HP1 > 666){
            HP1 = 666;
        }
        if(HP1 < 0){
            HP1 = 0;
        }

        if(EXP1 > 600){
            EXP1 = 600;
        }
        if(EXP1 < 0){
            EXP1 = 0;
        }

        if(M1 > 3000){
            M1 = 3000;
        }
        if(M1 < 0){
            M1 = 0;
        }
    }
    int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
        // TODO: Complete this function
        float p1, p2, p3;
        if(E2 < 0 || E2 > 99){
            return -99;
        }
        else{   
            //1st Path
            check2(HP1, EXP1, M1);
            
            int s1 = closestPerfSqr(EXP1);
            if(EXP1 >= s1){
                p1 = 100;
            }
            else{
                p1 = ((((float)EXP1/(float)s1) + 80) / 123.0) * 100.0;
            }
            //2nd Path
            float k = ceil(M1 / 2.0);
            if(E2 % 2 != 0){        //e2 le
                if(M1 == 0){
                    HP1 = ceil(HP1 * 0.830);
                    EXP1 = ceil(EXP1 * 1.170);
                }  
                else{                 
                    while(M1 >= k){          //remaining amount > half of the money at first
                        //1st event 
                        if(HP1 < 200){
                            HP1 = ceil(HP1 * 1.30 - 0.05);
                            M1 -= 150;
                        }
                        else{
                            HP1 = ceil(HP1 * 1.10 - 0.05);
                            M1 -= 70;
                        }
                        check2(HP1, EXP1, M1);
                        if(M1 < k){
                            break;
                        }
                        //2nd event
                        else{
                            if(EXP1 < 400){
                                M1 -= 200;
                                EXP1 = ceil(EXP1 * 1.130);
                            }
                            else{
                                M1 -= 120;
                                EXP1 = ceil(EXP1 * 1.13);
                            }
                            check2(HP1, EXP1, M1);
                            if(M1 < k){    
                                break;
                            }
                            ///3rd event
                            else{
                                if(EXP1 < 300){
                                    M1 -= 100;
                                    EXP1 = ceil(EXP1*0.90 - 0.05);
                                }
                                else{
                                    M1 -= 120;
                                    EXP1 = ceil(EXP1*0.90 - 0.05);
                                }
                                check2(HP1, EXP1, M1);
                            }
                        }    
                    }
                    HP1 = ceil(HP1 * 0.830);
                    EXP1 = ceil(EXP1 * 1.170);
                    check2(HP1, EXP1, M1);
                }
            }
            else{           //E2 CHAN
                if(M1 == 0){
                    HP1 = ceil(HP1 * 0.830);
                    EXP1 = ceil(EXP1 * 1.170);
                }
                else{
                //1st event 
                    if(HP1 < 200){
                        HP1 = ceil(HP1 * 1.30 - 0.05);
                        M1 -= 150;
                    }
                    else{
                        HP1 = ceil(HP1 * 1.10 - 0.05);
                        M1 -= 70;
                    }
                    check2(HP1, EXP1, M1);
                    if(M1 <= 0){//2nd event
                        HP1 = ceil(HP1 * 0.830);
                        EXP1 = ceil(EXP1 * 1.170);
                        check2(HP1, EXP1, M1);
                    }
                    else{
                        if(EXP1 < 400){
                            M1 -= 200;
                            EXP1 = ceil(EXP1 * 1.13);
                        }
                        else{
                            M1 -= 120;
                            EXP1 = ceil(EXP1 * 1.13);
                        }
                        check2(HP1, EXP1, M1);
                        // end 2nd event and start 3rd event
                        if(M1 <= 0){
                            HP1 = ceil(HP1 * 0.830);
                            EXP1 = ceil(EXP1 * 1.170);
                            check2(HP1, EXP1, M1);
                        }
                        else{
                            if(EXP1 < 300){
                                M1 -= 100;
                                EXP1 = ceil(EXP1*0.90 - 0.05);
                                HP1 = ceil(HP1 * 0.830);
                                EXP1 = ceil(EXP1 * 1.170);
                            }
                            else{
                                M1 -= 120;
                                EXP1 = ceil(EXP1*0.90 - 0.05);
                                HP1 = ceil(HP1 * 0.830);
                                EXP1 = ceil(EXP1 * 1.170);
                            }
                            check2(HP1, EXP1, M1);
                        }
                    }
                }
            }
            int s = closestPerfSqr(EXP1);
            if(EXP1 >= s){
                p2 = 100;
            }
            else{
                p2 = (((EXP1/s) + 80.0) / 123.0) * 100.0;
            }
            //3rd Path
            int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
            if(E2 < 10){
                p3 = P[E2];
            }
            else{
                p3 = P[sum(E2) % 10];    
            }
            //final check for p1, p2, p3
            if(p1 == p2 && p2 == p3 && p3 == 100){
                EXP1 = ceil(EXP1 * 0.750);
            }
            else{
                float avg = (p1 + p2 + p3) / 3.0;
                if(avg < 50.0){
                    HP1 = ceil(HP1 * 0.850);
                    EXP1 = ceil(EXP1 * 1.150);
                }
                else{
                    HP1 = ceil(HP1 * 0.90);
                    EXP1 = ceil(EXP1 * 1.20);
                }
                check2(HP1, EXP1, M1);
            }
            check2(HP1, EXP1, M1);
        }
        check2(HP1, EXP1, M1);
        return HP1 + EXP1 + M1;
    }

    // Task 3

    int sumOf1(int n){ //use in 4.3
        while(n > 9){
            n = sum(n);
        }
        return n;
    }
    int findMaxLeft(int arr[10][10], int i, int j){
        int maxLeftDiagonal = arr[i][j];

        int row = i - 1;
        int col = j - 1;

        while (row >= 0 && col >= 0) {
            maxLeftDiagonal = max(maxLeftDiagonal, arr[row][col]);
            row--;
            col--;
        }

        row = i + 1;
        col = j + 1;

        while (row < 10 && col < 10) {
            maxLeftDiagonal = max(maxLeftDiagonal, arr[row][col]);
            row++;
            col++;
        }
        return maxLeftDiagonal;
    }
    int findMaxRight(int arr[10][10], int i, int j){
        int maxRightDiagonal = arr[i][j];

        int row = i - 1;
        int col = j + 1;

        while (row >= 0 && col < 10) {
            maxRightDiagonal = max(maxRightDiagonal, arr[row][col]);
            row--;
            col++;
        }

        row = i + 1;
        col = j - 1;

        while (row < 10 && col >= 0) {
            maxRightDiagonal = max(maxRightDiagonal, arr[row][col]);
            row++;
            col--;
        }
        return maxRightDiagonal;
    }
    void check3(int & HP1, int & EXP1, int & HP2, int & EXP2){
        if(HP1 > 666){
            HP1 = 666;
        }
        if(HP1 < 0){
            HP1 = 0;
        }

        if(HP2 > 666){
            HP2 = 666;
        }
        if(HP2 < 0){
            HP2 = 0;
        }

        if(EXP1 > 600){
            EXP1 = 600;
        }
        if(EXP1 < 0){
            EXP1 = 0;
        }

        if(EXP2 > 600){
            EXP2 = 600;
        }
        if(EXP2 < 0){
            EXP2 = 0;
        }
    }
    int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
        // TODO: Complete this function
        if(E3 > 99 || E3 < 0){
            return -99;
        }
        else{
            check3(HP1, EXP1, HP2, EXP2);
            int arr[10][10];
            int c1 = 0, c2 = 0;     //meeting point(i,j)
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    arr[i][j] = (E3 * j + i * 2)* (i - j);
                }
            }
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(arr[i][j] > E3 * 2)
                        c1++;
                    if(arr[i][j] < -E3) 
                        c2++;  
                }
            }
            c1 = sumOf1(c1);
            c2 = sumOf1(c2);
            int taxiPoint = arr[c1][c2];            //maximum taxi point
            int point = max(findMaxLeft(arr, c1, c2), findMaxRight(arr, c1, c2));     //sherlock and waston point
            if(abs(taxiPoint) > abs(point)){
                EXP1 = ceil(EXP1 * 0.88 - 0.005);        //ko duoi kip
                HP1 = ceil(HP1*0.90 - 0.005);
                EXP2 = ceil(EXP2 * 0.88 - 0.005);        
                HP2 = ceil(HP2*0.90 - 0.005);
            }
            else{
                EXP1 = ceil(EXP1 * 1.12 - 0.005);                //duoi kip
                HP1 = ceil(HP1 * 1.10-0.005);
                EXP2 = ceil(EXP2 * 1.12 - 0.005);                
                HP2 = ceil(HP2 * 1.10 - 0.005);
            }
            check3(HP1, EXP1, HP2, EXP2);
            return (abs(taxiPoint) > abs(point)) ? taxiPoint : point;
        }
    }

    // Task 4
    int checkInclude(string s, string se){
        if(strstr(s.c_str(), se.c_str()) != nullptr){
            return -300 - s.find(se);       //s include se
        }
        else{
            return 1;       //s not include se
        }
    }
    bool containsSpecialCharacters(string s) {
        for (char c : s) {
            if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
                return true;  // Found a special character
            }
        }
        return false;  // No special characters found
    }
    int checkDuplicate(string s){
        for(int i = 0; i <= s.length() - 2; i++){
            if(s[i] == s[i+1] && s[i+1] == s[i+2]){
                return i;
            }
        }
        return -1;
    }
    int findFirstNonMatchingIndex(string str) {
        for (int i = 0; i < str.length(); ++i) {
            char currentChar = str[i];
            if (!(currentChar >= '0' && currentChar <= '9') &&
                !(currentChar >= 'A' && currentChar <= 'Z') &&
                !(currentChar >= 'a' && currentChar <= 'z') &&
                currentChar != '!' && currentChar != '@' &&
                currentChar != '#' && currentChar != '$' &&
                currentChar != '%') {
                return i; // Found the first non-matching character
            }
        }
        return -1; // All characters match the criteria
    }
    int checkPassword(const char *s, const char *email)
    {
        int s2 = 0;
        string se;
        string S = s;       // doi kieu cho string s
        while (s2 < strlen(email) && email[s2] != '@') {
            se += email[s2];
            s2++;
        }
        int s1 = strlen(s);
        if(!(s1 >= 8)){
            return -1;
        }
        else{
            if(!(s1 <= 20)){
                return -2;
            }
            else{
                if(checkInclude(s, se) != 1){
                    return checkInclude(s, se);
                }
                else{
                    if(checkDuplicate(s) != -1){
                        return -400 - checkDuplicate(s);
                    }
                    else{
                        if(!containsSpecialCharacters(s)){
                            return -5;
                        }
                        else{
                            if(findFirstNonMatchingIndex(s) != -1){
                                return findFirstNonMatchingIndex(s);
                            }
                        }
                    }
                }
            }
        }
        return -10;
    }


    //! Task 5
    int findCorrectPassword(const char *arr_pwds[], int num_pwds)
    {
        int maxOccurrences = 0;
        int truePasswordIndex = -1;
        int truePasswordLength = 0;

        for (int i = 0; i < num_pwds; i++) {
            int currentOccurrences = 0;
            int currentLength = strlen(arr_pwds[i]);

            // Count occurrences of the current password
            for (int j = 0; j < num_pwds; j++) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    currentOccurrences++;
                }
            }

            // Check if the current password is the new true password
            if (currentOccurrences > maxOccurrences || 
            (currentOccurrences == maxOccurrences && currentLength > truePasswordLength)) {
                maxOccurrences = currentOccurrences;
                truePasswordIndex = i;
                truePasswordLength = currentLength;
            }
        }

        return truePasswordIndex;
    }

    ////////////////////////////////////////////////
    /// END OF STUDENT'S ANSWER
    ////////////////////////////////////////////////