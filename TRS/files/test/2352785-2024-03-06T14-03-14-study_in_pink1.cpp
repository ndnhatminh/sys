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
double round_num(double &num){
    int num_temp = round(num);
    if((float)num<=num_temp) { num=num_temp; }
    else num = num_temp + 1;
    return num;
}
int conditionHP(double hp) {
    round_num(hp);
    if (hp > 666) return 666;
    else if (hp < 0) return 0;
    else {
        return hp;
    }
}
int conditionEXP(double exp) {
    round_num(exp);
    if (exp > 600) return 600;
    else if (exp < 0) return 0;
    else {
        return exp;
    }
}
int conditionMoney(double m) {
    round_num(m);
    if (m > 3000) return 3000;
    else if (m < 0) return 0;
    else {
        return m;
    }
}
int conditionEventCode(double e) {
    round_num(e);
    if (e > 99 || e < 0) return -999;
    else {
        return e;
    }
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    double EXP1a, EXP2a, E1a;
    EXP1a = (double)EXP1;
    EXP2a = (double)EXP2;
    E1a = (double)E1;

    EXP1a = conditionEXP(EXP1a);
    EXP2a = conditionEXP(EXP2a);
    E1a = conditionEventCode(E1a);

    //MISSION 1: THE FIRST ENCOUNTER
    //mission 1 (case 1)
    int D = 3 * E1a + EXP1a * 7;
    int Da = (double)D;
    if (E1a < 0 || E1a > 99) return -99;
    else { if (E1a >= 0 && E1a <= 3) {
        if (E1a == 0) {
            EXP2a += 29;
            EXP2a = conditionEXP(EXP2a);
        }
        if (E1a == 1) {
            EXP2a += 45;
            EXP2a = conditionEXP(EXP2a);
        }
        if (E1a == 2) {
            EXP2a += 75;
            EXP2a = conditionEXP(EXP2a);
        }
        if (E1a == 3) {
            EXP2a += 149;
            EXP2a = conditionEXP(EXP2a);
        }
        if (D % 2 == 0) {
            EXP1a += (Da / 200);
            EXP1a = conditionEXP(EXP1a);
        }
        else {
            EXP1a -= (Da / 100);
            EXP1a = conditionEXP(EXP1a);
        }
    }
    //mission 1 (case 2)
    if (E1a >= 4 && E1a <= 99) {
        if (E1a <= 19) {
            EXP2a += (E1a / 4 + 19);
            EXP2a = conditionEXP(EXP2a);
        }
        if (E1a >= 20 && E1a <= 49) {
            EXP2a += (E1a / 9 + 21);
            EXP2a = conditionEXP(EXP2a);
        }
        if (E1a >= 50 && E1a <= 65) {
            EXP2a += (E1a / 16 + 17);
            EXP2a = conditionEXP(EXP2a);
        }
        if (E1a >= 66 && E1a <= 79) {
            EXP2a += (E1a / 4 + 19);
            EXP2a = conditionEXP(EXP2a);
            if (EXP2a > 200) {
                EXP2a += (E1a / 9 + 21);
                EXP2a = conditionEXP(EXP2a);
            }
        }
        if (E1a >= 80 && E1a <= 99) {
            EXP2a += (E1a / 4 + 19);
            EXP2a = conditionEXP(EXP2a);
            EXP2a += (E1a / 9 + 21);
            EXP2a = conditionEXP(EXP2a);
            if (EXP2a > 400) {
                EXP2a += (E1a / 16 + 17);
                EXP2a = conditionEXP(EXP2a);
                EXP2a = EXP2a * 1.15;
                EXP2a = conditionEXP(EXP2a);
            }
        }
        EXP1a -= E1a;
        EXP1a = conditionEXP(EXP1a);
    }
    }
    //cout << EXP1 << " " << EXP2 << endl;(to check value of EXP1 and EXP2 in Mission 1)

    EXP1 = (int)EXP1a;
    EXP2 = (int)EXP2a;
    E1 = (int)E1a;

    return EXP1 + EXP2;
}


//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
int nearestsquare(double t1) {
	int t2 = sqrt(t1);
	if (pow(t2, 2) == t1) return pow(t2, 2);
	else {
		if ((t1 - pow(t2, 2)) < (pow((t2 + 1), 2) - t1)) return (pow(t2, 2));
		else return pow(t2 + 1, 2);
	}
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double HP1a, EXP1a, M1a, E2a;
    HP1a = (double)HP1;
    EXP1a = (double)EXP1;
    M1a = (double)M1;
    E2a = (double)E2;

    HP1a = conditionHP(HP1a);
    EXP1a = conditionEXP(EXP1a);
    M1a = conditionMoney(M1a);
    E2a = conditionEventCode(E2a);
    
    //MISSION 2: TRACING THE LUGGAGE
//S is the nearest square of EXP1 -> solve
//Road 1
    double S = nearestsquare(EXP1a), P1, P2, P3, Pfinal;
    if (EXP1a >= S) P1 = 1;
    else P1 = (EXP1a / S + 80) / 123;
    //Road 2
    //Create MoneyPaid and M1temp (when start Mission 2) to calculate easily
    int mpaid = 0;
    float M1temp = M1a;
    if(E2a<0 || E2a>99) return -99;
    else { if ((int)E2a % 2 == 1) {
        do {
        if(mpaid<=(0.5*M1temp)){
            if (HP1a < 200) {
                HP1a = HP1a * 1.3;
                HP1a = conditionHP(HP1a);
                M1a -= 150;
                M1a = conditionMoney(M1a);
                mpaid += 150;
            }
            else {
                HP1a = HP1a * 1.1;
                HP1a = conditionHP(HP1a);
                M1a -= 70;
                M1a = conditionMoney(M1a);
                mpaid += 70;
            }
        } else break;
        if(mpaid<=(0.5*M1temp)){
            if (EXP1a < 400) {
                M1a -= 200;
                M1a = conditionMoney(M1a);
                mpaid += 200;
            }
            else {
                M1a -= 120;
                M1a = conditionMoney(M1a);
                mpaid += 120;
            }
            EXP1a = EXP1a * 1.13;
            EXP1a = conditionEXP(EXP1a);
        } else break;
        if(mpaid<=(0.5*M1temp)){
            if (EXP1a < 300) {
                M1a -= 100;
                M1a = conditionMoney(M1a);
                mpaid += 100;
            }
            else {
                M1a -= 120;
                M1a = conditionMoney(M1a);
                mpaid += 120; 
            }
                EXP1a = EXP1a * 0.9;
                EXP1a = conditionEXP(EXP1a);
            
        } else break;    
        } while (mpaid <= (0.5 * M1temp));
    
        HP1a=HP1a*0.83;
        HP1a=conditionHP(HP1a);
        EXP1a*=1.17;
        EXP1a=conditionEXP(EXP1a);
    }
    //if E2a is even 
    else {
        if (M1a<0) M1=0;
        else {
        if(M1a>0){
        if (HP1a < 200) {
            HP1a = HP1a * 1.3;
            HP1a = conditionHP(HP1a);
            M1a -= 150;
            M1a = conditionMoney(M1a);
            mpaid += 150;
        } 
        else {
            HP1a = HP1a * 1.1;
            HP1a = conditionHP(HP1a);
            M1a -= 70;
            M1a = conditionMoney(M1a);
            mpaid += 70;
        }
        if(M1a<=0) M1a=0;
        } 
        if(M1a>0){
        if (EXP1a < 400) {
            M1a -= 200;
            M1a = conditionMoney(M1a);
            mpaid += 200;
        }
        else {
            M1a -= 120;
            M1a = conditionMoney(M1a);
            mpaid += 120;
        }
        EXP1a = EXP1a * 1.13;
        EXP1a = conditionEXP(EXP1a);
        if(M1a<=0) M1a=0;
        } 
        if(M1a>0){
        if (EXP1a < 300) {
            M1a -= 100;
            M1a = conditionMoney(M1a);
            mpaid += 100;
        }
        else {
            M1a -= 120;
            M1a = conditionMoney(M1a);
            mpaid += 120;
        }
            EXP1a = EXP1a * 0.9;
            EXP1a = conditionEXP(EXP1a);
        if(M1a<=0) M1a=0;
        } 
        HP1a=HP1a*0.83;
        HP1a=conditionHP(HP1a);
        EXP1a*=1.17;
        EXP1a=conditionEXP(EXP1a);
    }
    }

    S = nearestsquare(EXP1a);
    if (EXP1a >= S) P2 = 1;
    else P2 = (EXP1a / S + 80) / 123;
    //Road 3
    int P3temp[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if ((int)E2a < 10) {
        P3 = ((double)P3temp[(int)E2a]/100);
    }
    //2 digits
    else {
        int e1 = E2a / 10;
        int e2 = E2a - e1 * 10;
        int sum_e1e2 = e1 + e2;
        if (sum_e1e2 < 10) P3 = ((double)P3temp[sum_e1e2]/100);
        else {
            int sum_e1e2_temp1 = sum_e1e2 / 10;
            int sum_e1e2_temp2 = sum_e1e2 - sum_e1e2_temp1 * 10;
            P3 = ((double)P3temp[sum_e1e2_temp2]/100);
        }
    }
    //check p1 p2 p3

    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1a = EXP1a * 0.75;
        EXP1a = conditionEXP(EXP1a);
    }
    else {
        Pfinal = (P1 + P2 + P3) / 3;
    }
    if (Pfinal < 0.5) {
        HP1a = HP1a * 0.85;
        HP1a = conditionHP(HP1a);
        EXP1a = EXP1a * 1.15;
        EXP1a = conditionEXP(EXP1a);
    }
    else {
        HP1a = HP1a * 0.9;
        HP1a = conditionHP(HP1a);
        EXP1a = EXP1a * 1.2;
        EXP1a = conditionEXP(EXP1a);
    }
    }
    HP1 = (int)HP1a;
    EXP1 = (int)EXP1a;
    M1 = (int)M1a;
    E2 = (int)E2a;
    return HP1 + EXP1 + M1;
}



int leftdiagonal(int arr[10][10], int i, int j) {
    int r = i, c = j;
    int maxvalue = 0;
    while (r >= 0 && c >= 0) {
        maxvalue = max(arr[r][c], maxvalue);
        r--;
        c--;
    }
    r = i + 1;
    c = j + 1;
    while (r < 10 && c < 10) {
        maxvalue = max(arr[r][c], maxvalue);
        r++;
        c++;
    }
    return maxvalue;
}
int rightdiagonal(int arr[10][10], int i, int j) {
    int r = i, c = j;
    int maxvalue = 0;
    while (r >= 0 && c < 10) {
        maxvalue = max(arr[r][c], maxvalue);
        r--;
        c++;
    }
    r = i + 1;
    c = j - 1;
    while (r < 10 && c >= 0) {
        maxvalue = max(arr[r][c], maxvalue);
        r++;
        c--;
    }
    return maxvalue;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    double HP1a, HP2a, EXP1a, EXP2a, E3a;
    HP1a = (double)HP1;
    HP2a = (double)HP2;
    EXP1a = (double)EXP1;
    EXP2a = (double)EXP2;
    E3a = (double)E3;

    HP1a = conditionHP(HP1a);
    HP2a = conditionHP(HP2a);
    EXP1a = conditionEXP(EXP1a);
    EXP2a = conditionEXP(EXP2a);
    E3a = conditionEventCode(E3a);
    
    if(E3<0 || E3>99) return -99;
    else{
    int taximatrix[10][10];
    int i1 = 0, j1 = 0; //(i1,j1): where they meet
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taximatrix[i][j] = (((E3a * j) + (i * 2)) * (i - j));
            if (taximatrix[i][j] > E3a * 2) i1++;
            if (taximatrix[i][j] < -E3a) j1++;
        }
    }
    //Matrix for Sherlock and Watson
    int SWmatrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            SWmatrix[i][j] = max(leftdiagonal(taximatrix, i, j), rightdiagonal(taximatrix, i, j));
        }
    }

    //Point they meet
    //Check if they are 2 digits
    int i1temp1, i1temp2, j1temp1, j1temp2;
    do {
        i1temp1 = i1 / 10;
        i1temp2 = i1 - i1temp1 * 10;
        i1 = i1temp1 + i1temp2;
    } while (i1 >= 10 && i1 < 100);

    do {
        j1temp1 = j1 / 10;
        j1temp2 = j1 - j1temp1 * 10;
        j1 = j1temp1 + j1temp2;
    } while (j1 >= 10 && j1 < 100);
    //Check if they catched the taxi or not
    if (abs(taximatrix[i1][j1]) > SWmatrix[i1][j1]) {
        EXP1a = EXP1a * 0.88;
        EXP1a = conditionEXP(EXP1a);
        EXP2a = EXP2a * 0.88;
        EXP2a = conditionEXP(EXP2a);
        HP1a = HP1a * 0.9;
        HP1a = conditionHP(HP1a);
        HP2a = HP2a * 0.9;
        HP2a = conditionHP(HP2a);
    }
    else {
        EXP1a = EXP1a * 1.12;
        EXP1a = conditionEXP(EXP1a);
        EXP2a = EXP2a * 1.12;
        EXP2a = conditionEXP(EXP2a);
        HP1a = HP1a * 1.1;
        HP1a = conditionHP(HP1a);
        HP2a = HP2a * 1.1;
        HP2a = conditionHP(HP2a);
    }
    HP1 = (int)HP1a;
    HP2 = (int)HP2a;
    EXP1 = (int)EXP1a;
    EXP2 = (int)EXP2a;
    E3 = (int)E3a;
    //cout<<i1<<" "<<j1;
    if (abs(taximatrix[i1][j1]) > SWmatrix[i1][j1]) {
        return taximatrix[i1][j1];
    }
    else return SWmatrix[i1][j1];
    }

    return -1;
}

// Task 4
bool other_special(char a){
    if( (a>='0' && a<='9') || ((a>='A' && a<='Z') || (a>='a' && a<='z')) || (a=='@' || a=='#' || a=='$' || a=='!' || a=='%') ){
        return false;
    } else return true;
}

bool have_other_special(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (other_special(s[i])) {
            return true;
            break;
        }
        else continue;
    }
    return false;
}
bool find_place_other_special(string s, int &place) {
    for (int i = 0; i < s.length(); i++) {
        if (have_other_special(string(1, s[i]))) {
            place = i;
            return true;
            break;
        }
        else continue;
    } 
    return false;
}
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    // tao 2 bien sa, emaila voi kieu du lieu string de thay the char 
    string sa, emaila;
    sa = (string)s;
    emaila = (string)email;

    //Make se -> phan nam truoc @ trong emiala
    size_t placeforse = emaila.find('@');
    string se = emaila.substr(0, placeforse);
    int place = 0;
    // If s has a length shorter than the minimum length, return-1
    if (sa.length() < 8) return -1;
    // If s has a length longer than the maximum length, return-2
    else if (sa.length() > 20) return -2;
    // If s contains se->return-(300+<sei>),<sei> is the first occurrence of se
    else for (int i = 0; i < sa.length(); i++) {
        if (sa[i] == se[0]) {
            string sa_temp(sa, i, se.length());
            if (sa_temp == se) {
                int sei = i;
                return -(300 + sei);
                break;
            }
        }
        else continue;
    }
    /* If s contains more than 2 consecutive characters, then return-(400+<sci>), where
 <sci> is the first position of the first string containing more than 2 consecutive
 characters */
    for (int j = 0; j < sa.length(); j++) {
        if (sa[j] == sa[j + 1] && sa[j] == sa[j + 2]) {
            return -(400 + j);
            break;
        }
        else continue;
    }
    /* If s does not contain special characters, return -5 */
    for (int i = 0; i < sa.length(); i++) {
        if (sa[i] == '@' || sa[i] == '#' || sa[i] == '%' || sa[i] == '$' || sa[i] == '!') {
            break;
        }
        else {
            if (i < (sa.length() - 1)) continue;
            else if (i == (sa.length() - 1)) {
                return -5;
                break;
            }
        }
    }
        // The remaining cases return the position of the first character in violation
    if (find_place_other_special(sa, place))
        return place;
    else
        return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr_pwds_a[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        arr_pwds_a[i] = (string)arr_pwds[i];
    }
    //khoi tao mot array cua integer 2-dimension: trong do bao gom count length, va co che cong diem de lay
    int arr[3][num_pwds];
    for (int i=0; i<num_pwds; i++){
        arr[0][i] = arr_pwds_a[i].length();
        arr[1][i] = 1;
        arr[2][i] = (num_pwds-i);
        }
    for(int i=0; i<num_pwds; i++){
        for(int j=i+1; j<num_pwds; j++){
            if(arr_pwds_a[i]==arr_pwds_a[j]){
                arr[1][i]++;
            }
        }
    }
    for(int i=0; i<num_pwds; i++){
        arr[2][i] += arr[1][i]*10000;
    }
    
    int max_length = 0;
/*    for (int i=0; i<num_pwds; i++){
        max_length = max(max_length, arr[0][i]);
    } */
    for(int i=0; i<num_pwds; i++){
        arr[2][i] += arr[0][i]*100;
    }
    
    int max_point = 0;
    for (int i=0; i<num_pwds; i++){
        max_point=max(arr[2][i], max_point);
    }
    for (int i=0; i<num_pwds; i++){
        int index;
        if (arr[2][i]==max_point){
            index=i;
            return index;
            break;
        } else continue;
    }
    
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////