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

//Check value
int checkvalue(int value, int Minval, int Maxval){
    if (value > Maxval) {
        return Maxval;
    }
    else if (value < Minval){
        return Minval;
    } 
    else return value;
}

//Nearest perfect square
int nearestperfectsquare(int n) {
    int sqrtn = sqrt(n);
    int lower = sqrtn * sqrtn;
    int upper = (sqrtn + 1) * (sqrtn + 1);
    if (abs(n - lower) <= abs(upper - n))
        return lower;
    else
        return upper;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    //0-3
    if (e1 >= 0 && e1 <= 3){
        
        exp1 = checkvalue(exp1, 0, 600);
        exp2 = checkvalue(exp2, 0, 600);

        if (e1 == 0){
            exp2 += 29;
            exp2 = checkvalue(exp2, 0, 600);
        }
        else if (e1 == 1){
            exp2 += 45;
            exp2 = checkvalue(exp2, 0, 600);
        }       
        else if (e1 == 2){
            exp2 += 75;
            exp2 = checkvalue(exp2, 0, 600); 
        }
        else if (e1 == 3){
            exp2 += (29 + 45 + 75);
            exp2 = checkvalue(exp2, 0, 600);
        }

        int D=(exp1*7 + e1*3);        
        if (D%2==0){
            exp1= ceil(exp1 + (D/200.0));
            exp1 = checkvalue(exp1, 0, 600);
        } else {
            exp1= ceil(exp1 - (D/100.0));
            exp1 = checkvalue(exp1, 0, 600);
        }    
    } 
    
    //4-99
    if (e1 >= 4 && e1 <= 99){
        
        exp1 = checkvalue(exp1, 0, 600);
        exp2 = checkvalue(exp2, 0, 600);

        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            exp2 = checkvalue(exp2, 0, 600);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2 + (e1 / 9.0 + 21)); 
            exp2 = checkvalue(exp2, 0, 600);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2 + (e1 / 16.0 + 17)); 
            exp2 = checkvalue(exp2, 0, 600);
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            exp2 = checkvalue(exp2, 0, 600);
            if (exp2 > 200)
                exp2 = ceil(exp2 + (e1 / 9.0 + 21)); 
                exp2 = checkvalue(exp2, 0, 600);
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            exp2 = checkvalue(exp2, 0, 600);
            exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            exp2 = checkvalue(exp2, 0, 600);
            if (exp2 > 400){
                exp2 = ceil(exp2 + (e1 / 16.0 + 17)); 
                exp2 = checkvalue(exp2, 0, 600);
                exp2 = ceil(exp2 * 1.15);
                exp2 = checkvalue(exp2, 0, 600);
            }
        }

        exp1-=e1;
        exp1 = checkvalue(exp1, 0, 600);
    }
    
    else if (e1 < 0 || e1 > 99){
        return -99;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if (E2 > 99 || E2 < 0){
        return -99;
    } else {

    //Road1        
    int S1 = nearestperfectsquare(EXP1); 
    double P1,P2,P3;
    if (EXP1 >= S1) {
        P1 = 1.0;
    } else {
        P1 = (EXP1/S1 + 80)/123.0; }

    //Road2
    //E2 odd
    if (E2%2 != 0){
        int moneyhalf = (0.5 * M1);
        int total_money_spent=0;
        while (true) {
        if (HP1 < 200) {
            HP1 = ceil(HP1*13.0/10 );
            HP1 = checkvalue(HP1, 0, 666);
            M1 -= 150;
            M1 = checkvalue(M1, 0, 3000);
            total_money_spent += 150; 
        } else {
            HP1 = ceil(HP1*11.0/10 ); 
            HP1 = checkvalue(HP1, 0, 666);
            M1 -= 70; M1 = checkvalue(M1, 0, 3000);
            total_money_spent += 70; 
        } if (total_money_spent > moneyhalf) break;

        if (EXP1 < 400) {
            total_money_spent += 200; 
            EXP1 = ceil(EXP1*113.0/100 ); 
            EXP1 = checkvalue(EXP1, 0, 600);
            M1 -= 200; M1 = checkvalue(M1, 0, 3000);
        } else {
            M1 -= 120; M1 = checkvalue(M1, 0, 3000);
            total_money_spent += 120; 
            EXP1 = ceil(EXP1*113.0/100 );  
            EXP1 = checkvalue(EXP1, 0, 600);
        } if (total_money_spent > moneyhalf) break;

        if (EXP1 < 300) {
            total_money_spent += 100; 
            M1 -= 100; M1 = checkvalue(M1, 0, 3000);
            EXP1 = ceil(EXP1*9.0/10 );  
            EXP1 = checkvalue(EXP1, 0, 600);
        } else {
            total_money_spent += 120; 
            M1 -= 120; M1 = checkvalue(M1, 0, 3000);
            EXP1 = ceil(EXP1*9.0/10 );  
            EXP1 = checkvalue(EXP1, 0, 600);
        } if (total_money_spent > moneyhalf) break;
        }
        HP1 = ceil(83.0/100 * HP1);
        HP1 = checkvalue(HP1, 0, 666);
        EXP1 = ceil (EXP1*117.0/100);
        EXP1 = checkvalue(EXP1, 0, 600);

        int S2 = nearestperfectsquare(EXP1); 
        if (EXP1 >= S2) {
            P2 = 1.0;
        } else {
            P2 = (EXP1 /S2 + 80)/123.0; }
    }
    
    //E2 even
    else if (E2%2 ==0){
        int i;
        for (i = 0; i < 1; i++){
        if (HP1 < 200) {
            HP1 = ceil(HP1*13.0/10);
            HP1 = checkvalue(HP1, 0, 666);
            M1 -= 150; M1 = checkvalue(M1, 0, 3000);
        } else {
            HP1 = ceil(HP1*11.0/10 ); 
            HP1 = checkvalue(HP1, 0, 666);
            M1 -= 70; M1 = checkvalue(M1, 0, 3000);
        } if (M1 <= 0) break;

        if (EXP1 < 400) {
            EXP1 = ceil(EXP1*11.3/10 ); 
            EXP1 = checkvalue(EXP1, 0, 600);
            M1 -= 200; M1 = checkvalue(M1, 0, 3000);
        } else {
            M1 -= 120; M1 = checkvalue(M1, 0, 3000);
            EXP1 = ceil(EXP1*11.3/10 );  
            EXP1 = checkvalue(EXP1, 0, 600);
        } if (M1 <= 0) break;

        if (EXP1 < 300) { 
            M1 -= 100; M1 = checkvalue(M1, 0, 3000);
            EXP1 = ceil(EXP1*9.0/10 );  
            EXP1 = checkvalue(EXP1, 0, 600);
        } else {
            M1 -= 120; M1 = checkvalue(M1, 0, 3000);
            EXP1 = ceil(EXP1*9.0/10 );  
            EXP1 = checkvalue(EXP1, 0, 600);
        } if (M1 <= 0) break;
        }
        HP1 = ceil(HP1*8.3/10);
        HP1 = checkvalue(HP1, 0, 666);
        EXP1 = ceil (EXP1*11.7/10 );
        EXP1 = checkvalue(EXP1, 0, 600);

        int S2 = nearestperfectsquare(EXP1); 
        if (EXP1 >= S2) {
            P2 = 1.0;
        } else {
            P2 = (EXP1 /S2 + 80)/123.0; }
    }

    //Road3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int index;
    if (E2 < 10) {
        index = E2;
    } else {
        index = (E2 % 10) + (E2 / 10);
    }
    index %= 10;
    P3 = P[index] / 100.0;
    
    //P of 3 road
    double aveP = (P1 + P2 + P3)/3;
    if (aveP==1){
        EXP1 = ceil (EXP1*7.5/10 );
        EXP1 = checkvalue(EXP1, 0, 600);
    } else if (aveP < 0.5){
        EXP1 = ceil (EXP1*11.5/10 );
        EXP1 = checkvalue(EXP1, 0, 600);
        HP1 = ceil (HP1*8.5/10 );
        HP1 = checkvalue(HP1, 0, 666);
    } else {
        EXP1 = ceil (EXP1*12.0/10 );
        EXP1 = checkvalue(EXP1, 0, 600);
        HP1 = ceil (HP1*9.0/10 ); 
        HP1 = checkvalue(HP1, 0, 666);
    }
    return HP1 + EXP1 + M1;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0){
        return -99;
    } else {

    //taxitab
    int taxi[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    //meetpoint
    int posi = 0, posj = 0;
    int big = 0, small = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] > E3 * 2) {
                big++;
            }
            if (taxi[i][j] < -E3) {
                small++;
            }
        }
    }
    int temp = big;
    while (temp >= 10) {
        temp = temp % 10 + temp / 10;
        }
    posi = temp;

    temp = small;
    while (temp >= 10) {
        temp = temp % 10 + temp / 10;
        }
    posj = temp;

    //sherlockpoint
    int sherlockpoint=taxi[posi][posj];
    for (int i = posi-1, j = posj-1; i >= 0 && j >= 0; i--, j--) {
        if (sherlockpoint<taxi[i][j])
        sherlockpoint=taxi[i][j];
    }
    
    for (int i = posi+1, j = posj-1; i < 10 && j >= 0; i++, j--) {
        if (sherlockpoint<taxi[i][j])
        sherlockpoint=taxi[i][j];
    }

    for (int i = posi+1, j = posj+1; i < 10 && j < 0; i++, j++) {
        if (sherlockpoint<taxi[i][j])
        sherlockpoint=taxi[i][j];
    }
    
    for (int i = posi-1, j = posj+1; i >= 0 && j < 10; i--, j++) {
        if (sherlockpoint<taxi[i][j])
        sherlockpoint=taxi[i][j];
    }
    
    //compare
    bool compare = (abs(taxi[posi][posj]) <= sherlockpoint);
    if (compare) {
        HP1 = ceil(HP1*11.0/10 );
        HP2 = ceil(HP2*11.0/10 );
        EXP1 = ceil(EXP1*112.0/100 );
        EXP2 = ceil(EXP2*112.0/100 );
        HP1 = checkvalue(HP1, 0, 666);
        HP2 = checkvalue(HP2, 0, 666);
        EXP1 = checkvalue(EXP1, 0, 600);
        EXP2 = checkvalue(EXP2, 0, 600);

    } else {
        sherlockpoint= taxi[posi][posj];
        HP1 = ceil(HP1*9.0/10 );
        HP2 = ceil(HP2*9.0/10 );
        EXP1 = ceil(EXP1*88.0/100 );
        EXP2 = ceil(EXP2*88.0/100 );
        HP1 = checkvalue(HP1, 0, 666);
        HP2 = checkvalue(HP2, 0, 666);
        EXP1 = checkvalue(EXP1, 0, 600);
        EXP2 = checkvalue(EXP2, 0, 600);
    }
    return sherlockpoint;

    return -1;
}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    string pw(s);
    string mail(email);
    
    //se
    int pos = mail.find('@');
    string se = mail.substr(0, pos);
    
    //checklength
    int len = pw.length();
    if (len < 8)
        return -1;
    if (len > 20)
        return -2;
    
    //findse
    int found = pw.find(se);
    const int notfound = -1;
    if (found != notfound)
        return -(300 + found);
    
    //aaa
    for (int i = 0; i < len - 2; ++i) {
        if (pw[i] == pw[i + 1] && pw[i] == pw[i + 2])
            return -(400 + i);
    }
    
    //specialchar
    bool nospecialchar = true;
    for (size_t i = 0; i < pw.length(); ++i) {
        char c = pw[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') 
        nospecialchar = false; 
    }
    if (nospecialchar)
        return -5;
    
    //wrongchar
    for (int i = 0; i < len; ++i) {
        char c = pw[i];
        if (!(isalnum(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!' || c == '_'))
            return i;
    }
    return -10;

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    int length;
    int t_max;
    int pos;
    
	//check mang
    for (int i=0;i<num_pwds;i++){
        int t=0;
        //dem so lan 
        for (int j=0;j<num_pwds;j++){
            int a=strcmp(arr_pwds[j],arr_pwds[i]);
            if (a==0) t+=1;
        }//pw hop le
        if (t>t_max){
            t_max=t;
            length=string(arr_pwds[i]).length();
            pos=i;
        }else if(t==t_max){
            if (string(arr_pwds[i]).length()>length){
                length=string(arr_pwds[i]).length();
                pos=i;
            }
        }
    }
    return pos;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
