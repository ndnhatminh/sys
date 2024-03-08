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
    // DO NOT MODIFY THIS FUNCTION
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
int checkExp(int x){
    if(x < 0) return 0;
    else if(x > 600) return 600;
    else return x;
}
int checkHP(int x ){
    if (x<0) return 0;
    else if(x>666) return 666;
    else return x;
}
int checkMoney(int x){
    if (x<0) return 0;
    else if (x>3000) return 3000;
    else return x;
}


int firstMeet(int & exp1, int & exp2, int e1) {

    if ((e1 < 0) || (e1 > 99) )
        return -99;
    else {
        exp1 = checkExp(exp1);
        exp2 = checkExp(exp2);
        int D;
        if ((e1 >= 0) && (e1 <= 3)) {
            if (e1 == 0) {
                exp2 = exp2 + 29;
                exp2 = checkExp(exp2);
            } else if (e1 == 1) {
                exp2 = exp2 + 45;
                exp2 = checkExp(exp2);
            } else if (e1 == 2) {
                exp2 = exp2 + 75;
                exp2 = checkExp(exp2);
            } else if (e1 == 3) {
                exp2 = exp2 + 149;
                exp2 = checkExp(exp2);
            }
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1 = ceil(exp1 + float(D) / 200.00);
                exp1 = checkExp(exp1);
            }
            else exp1 = ceil(exp1 - float(D) / 100.00);
            exp1 = checkExp(exp1);

        } else if ((e1 >= 4) && (e1 <= 99)) {
            if (e1 <= 19) {
                exp2 = ceil(exp2 + ((double) e1 / 4.00 + 19));
                exp2 = checkExp(exp2);
            } else if (e1 <= 49) {
                exp2 = ceil((double) exp2 + ((double) e1 / 9 + 21));
                exp2 = checkExp(exp2);
            } else if (e1 <= 65) {
                exp2 = ceil(exp2 + ((double) e1 / 16.00 + 17));
                exp2 = checkExp(exp2);
            } else if (e1 <= 79) {
                exp2 = ceil(exp2 + ((double) e1 / 4.00 + 19));
                exp2 = checkExp(exp2);
                if (exp2 > 200) {
                    exp2 = ceil(exp2 + ((double) e1 / 9.00 + 21));
                    exp2 = checkExp(exp2);
                }

            } else if (e1 <= 99) {
                exp2 = ceil(exp2 + ((double) e1 / 4.00 + 19));
                exp2 = checkExp(exp2);
                exp2 = ceil(exp2 + ((double) e1 / 9.00 + 21));
                exp2 = checkExp(exp2);
                if (exp2 > 400) {
                    exp2 = ceil(exp2 + ((double) e1 / 16.00 + 17));
                    exp2 = checkExp(exp2);
                    exp2 = ceil(1.15 * exp2);
                    exp2 = checkExp(exp2);
                }
            }
            exp1 = exp1 - e1;
            exp1 = checkExp(exp1);
        }
        return exp1 + exp2;
    }
}

// Task 2
int squarenumber(int x){

    int i,sqr1,sqr2,sqr3,sqr,j,a;
    j = x;
    i = 0;
    sqr1 = 0;
    sqr2 = 0;
    while (i <= x) {
        a = sqrt(i);
        if (i == a*a) sqr1 = i;
        i++;
    }

    while(sqr2 == 0){
        sqr3 = sqrt(j);
        if (j == sqr3*sqr3) sqr2 = j ;
        j++;
    }

    if (abs(x - sqr1) > abs(x - sqr2)) sqr = sqr2;
    else sqr = sqr1;
    return sqr;
}


int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if ((E2 < 0) || (E2 > 99) )
        return -99;
    else {

        HP1 = checkHP(HP1);
        EXP1 = checkExp(EXP1);
        M1 = checkMoney(M1);
        double p1, p2, p3,p;
        int s, money, i,a,b,c;
        //First road
        i = 0;
        s = squarenumber(EXP1);
        if (EXP1 >= s) p1 = 100;
        else p1 = ((EXP1 / s + 80) / 123.00)*100.00;
        //Second road
        money = M1;
        if (E2 % 2 != 0) {
            while (E2 % 2 != 0) {
                if (M1 == 0) {
                    HP1 = HP1 * 0.83+0.999;
                    HP1 = checkHP(HP1);
                    EXP1 = EXP1 * 1.17+0.999;
                    EXP1 = checkExp(EXP1);
                    break;
                }
                if (HP1 < 200) {
                    HP1 = HP1 * 1.3+0.999;
                    HP1 = checkHP(HP1);
                    M1 = M1 - 150;
                    M1 = checkMoney(M1);
                    if (M1 <0.5 * money) {
                        HP1 = HP1 * 0.83+0.999;
                        HP1 = checkHP(HP1);
                        EXP1 = EXP1 * 1.17+0.999;
                        EXP1 = checkExp(EXP1);
                        break;
                }

                } else if (HP1 >= 200) {
                    HP1 = HP1 * 1.1+0.999;
                    HP1 = checkHP(HP1);
                    M1 = M1 - 70;
                    M1 = checkMoney(M1);
                    if (M1 < 0.5 * money) {
                        HP1 = HP1 * 0.83+0.999;
                        HP1 = checkHP(HP1);
                        EXP1 = EXP1 * 1.17+0.999;
                        EXP1 = checkExp(EXP1);
                        break;
                    }
                }

                if (EXP1 < 400) M1 = M1 - 200;
                else M1 = M1 - 120;
                M1 = checkMoney(M1);
                EXP1 = EXP1 * 1.13+0.999;
                EXP1 = checkExp(EXP1);
                if (M1 < 0.5 * money) {
                    HP1 = HP1 * 0.83+0.999;
                    HP1 = checkHP(HP1);
                    EXP1 = EXP1 * 1.17+0.999;
                    EXP1 = checkExp(EXP1);
                    break;
                }




                if (EXP1 < 300) M1 = M1 - 100;
                else M1 = M1 - 120;
                M1 = checkMoney(M1);
                EXP1 = EXP1 * 0.9+0.999;
                EXP1 = checkExp(EXP1);
                if (M1 < 0.5 * money) {
                    HP1 = HP1 * 0.83+0.999;
                    HP1 = checkHP(HP1);
                    EXP1 = EXP1 * 1.17+0.999;
                    EXP1 = checkExp(EXP1);
                    break;
                }

            }
        } else {
            while (i == 0)
            {
                if (M1 == 0 ) break;
                if (HP1 < 200) {
                    HP1 = HP1 * 1.3+0.999;
                    HP1 = checkHP(HP1);
                    M1 = M1 - 150;
                    if (M1 <= 0) break;
                }

                else if (HP1 >= 200) {
                    HP1 = HP1 * 1.1+0.999;
                    HP1 = checkHP(HP1);
                    M1 = M1 - 70;
                    if (M1 <= 0) break;
                }

                if (EXP1 < 400) M1 = M1 - 200;
                else M1 = M1 - 120;
                EXP1 = EXP1 * 1.13+0.999;
                EXP1 = checkExp(EXP1);
                if (M1 <= 0) break;



                if (EXP1 < 300) M1 = M1 - 100;
                else M1 = M1 - 120;
                EXP1 = EXP1 * 0.9+0.999;
                EXP1 = checkExp(EXP1);
                if (M1 <= 0) break;

                i++;
            }
            M1 = checkMoney(M1);
            HP1 = HP1 * 0.83+0.999;
            HP1 = checkHP(HP1);
            EXP1 = EXP1 * 1.17+0.999;
            EXP1 = checkExp(EXP1);
        }
        s = squarenumber(EXP1);
        if (EXP1 >= s) p2 = 100;
        else p2 = ((EXP1 / s + 80) / 123.00)*100.00;
        //Third road
        int P[10] = {32, 47, 28, 79, 100, 50 ,22, 83, 64, 11};
        if (E2 < 10) p3 = P[E2];
        else {
            b = E2 % 10;
            E2 = E2 / 10;
            a = E2;
            c = a + b ;
            if (c>=10) p3 = P[c%10];
            else p3 = P[c];
        }

        if ((p1 == 100) && (p2 == 100) && (p3 == 100) ){
            EXP1 = 0.75*EXP1+0.999;
            EXP1 = checkExp(EXP1);
            return HP1 + EXP1 + M1;
        }

        else p = (p1 + p2 + p3) / 3.00;

        if (p < 50) {
            HP1 = 0.85*HP1+0.999;
            HP1 = checkHP(HP1);
            EXP1 = 1.15*EXP1+0.999;
            EXP1 = checkExp(EXP1);
        }
        else {
            HP1 = HP1*0.9+0.999;
            HP1 = checkHP(HP1);
            EXP1 = EXP1*1.2+0.999;
            EXP1 = checkExp(EXP1);
        }
    }





    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if ((E3 <0 ) || (E3 > 99)) return -99;
    else{
    int a[10][10], b1[10][10], b2[10][10], b[10][10];

    int max1,c,d,e,f,j;
    int g,h,k,m,n,z,count1,count2, temp1,temp2;
    c= 0;
    d = 0;
    e = 0;
    count1 = 0;
    count2 = 0;
    HP1 = checkHP(HP1);
    EXP1 = checkExp(EXP1);
    HP2 = checkHP(HP2);
    EXP2 = checkExp(EXP2);
    for (int i = 0; i < 10; i++){
        for (int i1 = 0; i1 < 10; i1++)
            a[i1][i] = ((E3 * i) + (i1 * 2)) * (i1 - i);
    }
    for (int i = 0; i < 10; i++){
        for (int i1 = 0; i1 < 10; i1++){
            if (a[i][i1] > E3*2) count1++;
            if (a[i][i1] < -1* E3) count2++;
        }
    }
    while (count1 >= 10){
        temp1 = count1 % 10;
        temp2 = count1 / 10;
        count1 = temp1 + temp2;
    }
    while (count2 >= 10){
        temp1 = count2 % 10;
        temp2 = count2 / 10;
        count2 = temp1 + temp2;
    }
    for (int i = 0; i < 10; i++) {
        c=i;
        max1 = a[i][d];
        while(c+1<10){
            if (a[c+1][d+1] > max1) max1 = a[c+1][d+1];
            c++;
            d++;
        }

        f = 0;
        j = e;
        while(j<10){

            b1[j][f] = max1;
            f++;
            j++;
        }
        d = 0;
        e++;
    }



    g = 0;
    h = 0;
    k = 0;
    for (int i = 0; i < 10; i++) {
        g=i;
        max1 = a[k][i];
        while(g+1<10){
            if (a[k+1][g+1] > max1) max1 = a[k+1][g+1];
            g++;
            k++;
        }

        m = 0;
        n = h;
        while(n<10){
            b1[m][n] = max1;
            m++;
            n++;
        }
        k = 0;
        h++;
    }
    int c1,d1,e1,f1,j1;
    int g1,h1,k1,m1,n1;
    c1= 0;
    d1 = 9;
    e1 = 0;
    for (int i = 0; i < 10; i++) {
        c1=i;
        max1 = a[i][d1];
        while(c1+1<10) {
            if (a[c1+1][d1-1] > max1) max1 = a[c1+1][d1-1];
            c1++;
            d1--;
        }

        f1 = 9;
        j1 = e1;
        while(j1<10){
            b2[j1][f1] = max1;
            f1--;
            j1++;
        }
        d1 = 9;
        e1++;
    }
    
    h1 = 8;
    k1 = 0;
    for (int i = 8; i >= 0; i--) {
        g1=i;
        max1 = a[k1][i];
        while(g1-1>=0){
            if (a[k1+1][g1-1] > max1) max1 = a[k1+1][g1-1];
            g1--;
            k1++;
        }

        m1 = h1;
        n1 = 0;
        while(m1>=0){
            b2[n1][m1] = max1;
            m1--;
            n1++;
        }
        k1 = 0;
        h1--;
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++)
            if (b1[i][j] > b2[i][j]) b[i][j] = b1[i][j];
            else b[i][j] = b2[i][j];

    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (b[i][j]<0) b[i][j] = abs(b[i][j]);

        }
    }
    if (abs(a[count1][count2]) <= b[count1][count2]){
        HP1 = (HP1 *1.1)+0.999;
        HP1 = checkHP(HP1);
        HP2 = (HP2 *1.1)+0.999;
        HP2 = checkHP(HP2);
        EXP1 = EXP1 * 1.12+0.999;
        EXP1 = checkExp(EXP1);
        EXP2 = EXP2 * 1.12+0.999;
        EXP2 = checkExp(EXP2);
        return b[count1][count2];
    }
    else {
        HP1 = HP1*0.9+0.999;
        HP1 = checkHP(HP1);
        HP2 = HP2*0.9+0.999;
        HP2 = checkHP(HP2);
        EXP1 = EXP1* 0.88+0.999;
        EXP1 = checkExp(EXP1);
        EXP2 = EXP2* 0.88+0.999;
        EXP2 = checkExp(EXP2);
        return a[count1][count2];
    }

}}
// Task 4
int checkPassword(const char * s, const char * email) {
    string s1,email1,se;
    int count1,count2,n,sci,m;
    s1 = s;
    email1 = email;
    sci = -1;
    count1 = 0;

    m=-1;
    if (s1.length() < 8) return -1;
    else if(s1.length() > 20) return -2;
    if (email1.length() == 1) return -300;
    for (int i = 0; i < email1.length(); i++){
        m++;
        if (email1[i] =='@')
            break;

    }

        for (int i = 0; i < s1.length(); i++) {
             count2 = 1;
            for (int j = 0; j < m; j++) {
            if (s1[i + j] != email1[j]) {
                count2 = 0;
                break;
            }
        }

        if (count2 == 1) {
            sci = i;
            break;
        }
    }

    if (sci >=0 ) {
        return -(300 + sci);
    }

    for (int i = 0;i < s1.length();i++){
        if ((s1[i] == s1[i+1]) &&(s1[i]==s1[i+2]) )
            return -(400 + i);
        }

    for (int i = 0; i <s1.length();i++){
        if ((s1[i] == '@') || (s1[i] == '#') || (s1[i] == '%') || (s1[i] == '$') || (s1[i] == '!'))
            count1++;
    }
    if (count1 == 0) return -5;


    for (int i = 0; i < s1.length(); i++) {
        n = int(s1[i]);
        if ((n <48) || (n>57) && (n < 64) || (n>90) && (n<97) || (n >122)){
            if ((n != 36) && (n!=35) && (n != 37) && (n != 33))
                return i;
        }

    }
    return -10;
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max,b,count;
    string arr[num_pwds];
    string a;
    max = 0;
    for (int i = 0;i<num_pwds;i++){
        arr[i] = arr_pwds[i];
    }
    for (int i = 0;i<num_pwds;i++){
        count = 0;
        for (int j = 0; j < num_pwds;j++){
            if (arr[j] == arr[i]) count++;

            if (max < count){
                max = count;
                a = arr[i];
                b = i;
            }

            else if (max == count){
                if (a.length() < arr[i].length()){
                    a = arr_pwds[i];
                    b = i;
                }
            }
        }
    }
    return b;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////