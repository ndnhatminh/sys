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

float validexp1(float exp1)
{
    if (exp1 > 600)
        exp1 = 600;
    else if (exp1 < 0)
        exp1 = 0;
    return exp1;
}

float validexp2(float exp2)
{
    if (exp2 > 600)
        exp2 = 600;
    else if (exp2 < 0)
        exp2 = 0;
    return exp2;
}

float validm1(float m1){
    if(m1 > 3000){
        m1 = 3000;
    }
    else if(m1 < 0){
        m1 = 0;
    }
    return m1;
}

float validhp(float hp){
    if(hp>666){
        hp=666;
    }
    else if(hp < 0){
        hp = 0;
    }
    return hp;
}

float transport(float exp1, float m1){
    if(m1 > 0){
        if(exp1 < 400){
            m1 = m1 - 200;
        }
        else{
            m1 = m1 - 120;
        }
    }
    return m1;
}

float homeless(float exp1, float m1){
    if(m1 > 0){
        if(exp1 < 300){
            m1 = m1 - 100;
        }
        else{
            m1 = m1 - 120;
        }
    }
    return m1;
}

float percentcal(float exp1){
    float squareroot = (sqrt(exp1));
    squareroot = round(squareroot);
    float S = pow(squareroot,2);
    float P;
    if(exp1>=S){
        P = 1;
    }
    else if(exp1<S){
        P = ((exp1 / S) + 80) / 123;
    }
    return P;
}


int findmax(int taximatrix[10][10], int i, int j) {
    int maxbotr = taximatrix[i][j];
    int maxbotl = taximatrix[i][j];
    int maxtopr = taximatrix[i][j];
    int maxtopl = taximatrix[i][j];
    //maxbotr
    if(i < 9 && j < 9){
        for(int a = (i+1), b = (j+1); (a <= 9) && (b <= 9); a++, b++){
            if(taximatrix[a][b]>maxbotr){
                maxbotr = taximatrix[a][b];
            }
        }
    }
    //maxbotl
    if(i < 9 && j > 0){
        for(int a = (i+1), b = (j-1); (a <= 9) && (b >= 0); a++, b--){
            if(taximatrix[a][b]>maxbotl){
                maxbotl = taximatrix[a][b];
            }
        }
    }
    //maxtopr
    if(i > 0 && j < 9){
        for(int a = (i-1), b = (j+1); (a >= 0) && (b <= 9); a--, b++){
            if(taximatrix[a][b]>maxtopr){
                maxtopr = taximatrix[a][b];
            }
        }
    }
    //maxtopl
    if(i > 0 && j > 0){
        for(int a = (i-1), b = (j-1); (a >= 0) && (b >= 0); a--, b--){
            if(taximatrix[a][b]>maxtopl){
                maxtopl = taximatrix[a][b];
            }
        }
    }
    // realmax
    int realmax = maxbotr;
    int comparearr[4] = { maxtopr, maxtopl, maxbotr, maxbotl };
    for (int z = 0; z < 4; z++) {
        if (comparearr[z] > realmax) {
            realmax = comparearr[z];
        }
    }
    return realmax;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    float EXP1 = exp1;
    float EXP2 = exp2;
    EXP1 = validexp1(EXP1);
    EXP2 = validexp2(EXP2);
    float E1 = e1;
    if (0 <= E1 && E1 <= 3) {
        if (E1 == 0) {
            EXP2 = EXP2 + 29;
            EXP2 = ceil(validexp2(EXP2));
        }
        else if (E1 == 1) {
            EXP2 = EXP2 + 45;
            EXP2 = ceil(validexp2(EXP2));
        }
        else if(E1 == 2){
            EXP2 = EXP2 + 75;
            EXP2 = ceil(validexp2(EXP2));
        }
        else{
            EXP2 = EXP2 + 75 + 45 + 29;
            EXP2 = ceil(validexp2(EXP2));
        }
        int D = 3 * E1 + EXP1 * 7;
        if (D % 2 == 0){
            EXP1 = EXP1 + (D / 200.00);
            EXP1 = ceil(validexp1(EXP1));
        }
        else{
            EXP1 = EXP1 - (D / 100.00);
            EXP1 = ceil(validexp1(EXP1));
        }



    }
    else if (4 <= E1 && E1 <= 99) {
        if (4 <= E1 && E1 <= 19) {
            EXP2 = EXP2 + ((E1 / 4) + 19);
            EXP2 = ceil(validexp2(EXP2));
        }
        else if (20 <= E1 && E1 <= 49) {
            EXP2 = EXP2 + ((E1 / 9) + 21);
            EXP2 = ceil(validexp2(EXP2));
        }
        else if (50 <= E1 && E1 <= 65) {
            EXP2 = EXP2 + ((E1 / 16) + 17);
            EXP2 = ceil(validexp2(EXP2));
        }
        else if (66 <= E1 && E1 <= 79) {
            EXP2 = EXP2 + ((E1 / 4) + 19);
            EXP2 = ceil(validexp2(EXP2));
            if (EXP2 > 200) {
                EXP2 = EXP2 + ((E1 / 9) + 21);
                EXP2 = ceil(validexp2(EXP2));
            }
        }
        else if (80 <= E1 && E1 <= 99){
            EXP2 = EXP2 + ((E1 / 4.00) + 19);
            EXP2 = ceil(validexp2(EXP2));
            EXP2 = EXP2 + ((E1 / 9.00) + 21);
            EXP2 = ceil(validexp2(EXP2));
            if (EXP2 > 400){
                EXP2 = EXP2 + ((E1 / 16.00) + 17);
                EXP2 = ceil(validexp2(EXP2));
                EXP2 = (1.15) * EXP2;
                EXP2 = ceil(validexp2(EXP2));
            }
        }

        EXP1 = EXP1 - E1;
        EXP1 = ceil(validexp1(EXP1));
    }
    else if(E1<0){
        return -99;
    }
    else if(E1>99){
        return -99;
    }
    exp1 = EXP1;
    exp2 = EXP2;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    float hp1 = HP1;
    float exp1 = EXP1;
    float m1 = M1;
    hp1 = validhp(hp1);
    exp1 = validexp1(exp1);
    m1 = validm1(m1);
    float P1;
    float P2;
    float Pi;
    float avgP;
    if(0<=E3&&E3<=99){
        //Route 1
        P1 = percentcal(exp1);
        //Route 2
        if(E3%2==0){
            //Buy food
            if(m1 > 0){
                if(hp1<200){
                    hp1 = (1.3)*hp1;
                    hp1 = ceil(validhp(hp1));
                    m1 = m1 - 150;
                    m1 = validm1(m1);
                }
                else{
                    hp1 = (1.1)*hp1;
                    hp1 = ceil(validhp(hp1));
                    m1 = m1 - 70;
                    m1 = validm1(m1);
                }
            }
            //Transport
            if(m1 > 0){
                m1 = transport(exp1,m1);
                m1 = validm1(m1);
                exp1 = (1.13)*exp1;
                exp1 = ceil(validexp1(exp1));
            }
            //Help homeless
            if(m1 > 0){
                m1 = homeless(exp1,m1);
                m1 = validm1(m1);
                exp1 = (0.9)*exp1;
                exp1 = ceil(validexp1(exp1));
            }
            exp1 = (1.17)*exp1;
            exp1 = ceil(validexp1(exp1));
            hp1 = (0.83)*hp1;
            hp1 = ceil(validhp(hp1));
        }
        else if(E3%2 != 0){
            float inithalf = m1/2;
            while(true){
                if(m1<inithalf){
                    m1 = m1;
                }
                else if(m1>=inithalf){
                    if(m1>=inithalf){
                        //Buy food
                        if(m1>0){
                            if(hp1<200){
                                hp1 = (1.3)*hp1;
                                hp1 = ceil(validhp(hp1));
                                m1 = m1 - 150;
                                m1 = validm1(m1);
                            }
                            else{
                                hp1 = (1.1)*hp1;
                                hp1 = ceil(validhp(hp1));
                                m1 = m1 - 70;
                                m1 = validm1(m1);
                            }
                        }
                    }
                    //Transport
                    if(m1>=inithalf){
                        if(m1>0){
                            m1 = transport(exp1,m1);
                            m1 = validm1(m1);
                            exp1 = (1.13)*exp1;
                            exp1 = ceil(validexp1(exp1));
                        }
                    }
                    //Help homeless
                    if(m1>=inithalf){
                        if(m1>0){
                            m1 = homeless(exp1,m1);
                            m1 = validm1(m1);
                            exp1 = (0.9)*exp1;
                            exp1 = ceil(validexp1(exp1));
                        }
                    }
                    continue;
                }
                break;
            }
            exp1 = (1.17)*exp1;
            exp1 = ceil(validexp1(exp1));
            hp1 = (0.83)*hp1;
            hp1 = ceil(validhp(hp1));
        }
        P2 = percentcal(exp1);
        //Route 3
        float chancearr[10]{32,47,28,79,100,50,22,83,64,11};
        if(0<=E3&&E3<=9){
            Pi = chancearr[E3];
        }
        else if(10<=E3&&E3<=99){
            int leftnum = E3/10;
            int rightnum = E3%10;
            int final = leftnum + rightnum;
            if(0<=final&&final<10){
                Pi = chancearr[final];
            }
            else if(10<=final&&final<=99){
                final = final%10;
                Pi = chancearr[final];
            }
        }
        Pi = Pi/100;
        //Final
        if(P1 == 1 && P2 == 1 && Pi == 1){
            exp1 = (0.75)*exp1;
            exp1 = ceil(validexp1(exp1));
        }
        else{
            avgP = (P1 + P2 + Pi)/3;
            if(avgP<0.5){
                hp1 = (0.85)*hp1;
                hp1 = ceil(validhp(hp1));
                exp1 = (1.15)*exp1;
                exp1 = ceil(validexp1(exp1));
            }
            else if(avgP>0.5){
                hp1 = (0.9)*hp1;
                hp1 = ceil(validhp(hp1));
                exp1 = (1.2)*exp1;
                exp1 = ceil(validexp1(exp1));
            }
        }
    }
    else{
        return -99;
    }
    HP1 = hp1;
    EXP1 = exp1;
    M1 = m1;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    HP1 = validhp(HP1);
    EXP1 = validexp1(EXP1);
    HP2 = validhp(HP2);
    EXP2 = validexp2(EXP2);
    float hp1 = HP1;
    float exp1 = EXP1;
    float hp2 = HP2;
    float exp2 = EXP2;
    int realreturn;
    if(0<=E3&&E3<=99){
        int taximatrix[10][10]{};
        int movematrix[10][10]{};
        int i,j;
        for(i=0;i<=9;i++){
            for(j=0;j<=9;j++){   
                taximatrix[i][j] = (((E3*j)+(i*2))*(i-j));
            }
        }
        for(j=0;j<=9;j++){
            for(i=0;i<=9;i++){
                movematrix[i][j] = findmax(taximatrix,i,j);
                movematrix[i][j] = abs(movematrix[i][j]);
            }
        }
        //Find i, j
        int doubleE = E3*2;
        int negE = E3*(-1);
        int posnum = 0;
        int negnum = 0;
        for(i = 0; i <= 9; i++){
            for(j = 0; j <= 9; j++){
                if(taximatrix[i][j]>doubleE){
                    posnum++;
                }
            }
        }
        for(i = 0; i <= 9; i++){
            for(j = 0; j <= 9; j++){
                if(taximatrix[i][j]<negE){
                    negnum++;
                }
            }
        }
        //Configuring i position
        while(true){
            if(0<=posnum&&posnum<10){
                i = posnum;
            }
            else if(10<=posnum&&posnum<=99){
                int ileftnum = posnum/10;
                int irightnum = posnum%10;
                posnum = ileftnum + irightnum;
                continue;
            }
            break;
        }
        //Configuring j position
        while(true){
            if(0<=negnum&&negnum<10){
                j = negnum;
            }
            else if(10<=negnum&&negnum<=99){
                int jleftnum = negnum/10;
                int jrightnum = negnum%10;
                negnum = jleftnum + jrightnum;
                continue;
            }
            break;
        }
        //Update the stat
        int taximeetpos = abs(taximatrix[i][j]);
        int detectpos = movematrix[i][j];
        if(detectpos>=taximeetpos){
            exp1 = (1.12)*exp1;
            exp1 = ceil(validexp1(exp1));
            hp1 = (1.1)*hp1;
            hp1 = ceil(validhp(hp1));
            exp2 = (1.12)*exp2;
            exp2 = ceil(validexp2(exp2));
            hp2 = (1.1)*hp2;
            hp2 = ceil(validhp(hp2));
            realreturn = detectpos;
        }
        else{
            exp1 = (0.88)*exp1;
            exp1 = ceil(validexp1(exp1));
            hp1 = (0.9)*hp1;
            hp1 = ceil(validhp(hp1));
            exp2 = (0.88)*exp2;
            exp2 = ceil(validexp2(exp2));
            hp2 = (0.9)*hp2;
            hp2 = ceil(validhp(hp2));
            realreturn = taximatrix[i][j];
        }
    }
    else{
        return -99;
    }
    EXP1 = exp1;
    EXP2 = exp2;
    HP1 = hp1;
    HP2 = hp2;
    return realreturn;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string emailstr = email;
    string password = s;
    string se = emailstr.substr(0, emailstr.find("@"));

    // Check email length
    if (!(emailstr.length() <= 100 && emailstr.length() > 0)) {
        return -99;
    }
    // Check if email contains '@' symbol
    else if (emailstr.find("@") == string::npos) {
        return -99;
    }
    // Check password length
    else if (!(password.length() <= 20 && password.length() >= 8)) {
        if (password.length() < 8) {
            return -1;
        }
        else if (password.length() > 20) {
            return -2;
        }
    }
    else {
        if (password.find(se) != string::npos) {
            int sei = password.find(se);
            return (300 + sei) * (-1);   // Duplicate Words
        }
        else {
            bool duplicatechar = true;
            for (size_t i = 0; i < (password.length() - 2); i++) {
                if ((password[i] == password[i + 1]) && (password[i] == password[i + 2])) {
                    int sci = i;
                    duplicatechar = false;
                    return (400 + sci) * (-1);  //DUplicate Chars
                    break;
                }
            }
            // Special chars
            if (duplicatechar) {
                if (password.find("@") == string::npos && password.find("#") == string::npos && password.find("%") == string::npos && password.find("$") == string::npos && password.find("!") == string::npos) {
                    return -5;
                }
                else {
                    for (size_t a = 0; a < password.length(); a++) {
                        int asciivalue = static_cast<int>(password[a]);
                        if (!((48 <= asciivalue && asciivalue <= 57) || (64 <= asciivalue && asciivalue <= 90) || (97 <= asciivalue && asciivalue <= 122) || (35 <= asciivalue && asciivalue <= 37) || (asciivalue == 33))) {
                            return a;
                            break;
                        }
                    }
                }
            }
        }
    }
    return -10; // Valid Pass
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int finalposition = 0;
    int newcount = 0;
    
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int z = 0; z < num_pwds; z++) {
            if (z != i && strcmp(arr_pwds[i], arr_pwds[z]) == 0)
                count++;
        }
        if (count > newcount || (count == newcount && strlen(arr_pwds[i]) > strlen(arr_pwds[finalposition]))) {
            newcount = count;
            finalposition = i;
        }
    }
    return finalposition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////