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

//Task 1
int setEXP(int& EXP) {
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
        EXP = 0;
    return EXP;
}

int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    setEXP(exp1);
    setEXP(exp2);
    if (e1 < 0 || e1>99) {
        return -99;
    }
    //truong hop 1
    else if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
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
            exp2 += 29 + 45 + 75;
            break;
        }
        setEXP(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + D / 200.0);
        }
        else exp1 = ceil(exp1 - D / 100.0);
        setEXP(exp1);
    }
    //truong hop 2
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19)
            exp2 = ceil(exp2 + (e1 / 4.0) + 19);
        else if (e1 >= 20 && e1 <= 49)
            exp2 = ceil(exp2 + (e1 / 9.0) + 21);
        else if (e1 >= 50 && e1 <= 65)
            exp2 = ceil(exp2 + (e1 / 16.0) + 17);
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + (e1 / 4.0) + 19);
            if (exp2 > 200)
                exp2 = ceil(exp2 + (e1 / 9.0) + 21);
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(exp2 + (e1 / 4.0) + 19);
            exp2 = ceil(exp2 + (e1 / 9.0) + 21);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (e1 / 16.0) + 17);
                exp2 = ceil(exp2 * 11.5 / 10);
            }
        }
        setEXP(exp2);
        exp1 = exp1 - e1;
        setEXP(exp1);
    }
    return exp1 + exp2;

}


//Task 2
int setHP(int& HP) {
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;
    return HP;
}
int setM1(int& M1) {
    if (M1 > 3000)
        M1 = 3000;
    else if (M1 < 0)
        M1 = 0;
    return M1;
}
int setM1left(int& M1left, int& M1) {
    M1 = M1left;
    return M1;
}

int findS(int num) {
    double sqrtNum = sqrt(num);
    int roundedSqrt = floor(sqrtNum);
    if (num - (roundedSqrt * roundedSqrt) < (roundedSqrt + 1) * (roundedSqrt + 1) - num)
        return roundedSqrt * roundedSqrt;
    else return (roundedSqrt + 1) * (roundedSqrt + 1);

}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) {
        return -99;
    }
    else if (E2 >= 0 && E2 <= 99) {
        setHP(HP1);
        setEXP(EXP1);
        setM1(M1);
        double P1 = 0, P2 = 0;
        //con duong 1
        int S = findS(EXP1);
        if (EXP1 >= S)
            P1 = 1;
        else {
            if (S != 0)
                P1 = ((EXP1 / S) + 80) / 123.0;
            else return -1;
        }

        //con duong 2
        double halfM1 = M1 * 0.5;
        int M1left = 0;
        int M1paid = 0;
        if (E2 % 2 != 0) {
            while (M1paid < halfM1) {
                //E la so le
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * (130 / 100.0));
                    M1left = M1 - 150;
                    M1paid += 150;
                }
                else if (HP1 >= 200) {
                    HP1 = ceil(HP1 * 11.0 / 10);
                    M1left = M1 - 70;
                    M1paid += 70;
                }
                setHP(HP1);

                setM1(M1left);
                setM1left(M1left, M1);
                if (M1paid > halfM1)
                    break;

                if (M1paid <= halfM1) {
                    if (EXP1 < 400) {
                        M1left = M1left - 200;
                        M1paid += 200;
                    }
                    else {
                        M1left = M1left - 120;
                        M1paid += 120;
                    }
                    EXP1 = ceil(EXP1 * 11.3 / 10);

                }
                setEXP(EXP1);
                setM1(M1left);
                setM1left(M1left, M1);
                if (M1paid > halfM1)
                    break;


                if (M1paid <= halfM1) {
                    if (EXP1 < 300) {
                        M1left = M1left - 100;
                        M1paid += 100;
                    }
                    else {
                        M1left = M1left - 120;
                        M1paid += 120;
                    }
                    EXP1 = ceil(EXP1 * (90 / 100.0));
                }

                setEXP(EXP1);
                setM1(M1left);
                setM1left(M1left, M1);

                if (M1paid > halfM1)
                    break;

            }


        }

        else {
            //E la so chan
            for (int i = 0; i < 1; ++i) {
                if (M1 == 0) break;
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * (130 / 100.0));
                    M1left = M1 - 150;
                    M1paid += 150;
                }
                else if (HP1 >= 200) {
                    HP1 = ceil(HP1 * 11.0 / 10);
                    M1left = M1 - 70;
                    M1paid += 70;
                }
                setHP(HP1);
                setM1(M1left);
                setM1left(M1left, M1);
                if (M1left == 0) {

                    break;
                }



                if (EXP1 < 400) {
                    M1left = M1left - 200;
                    M1paid += 200;
                }
                else {
                    M1left = M1left - 120;
                    M1paid += 120;
                }
                EXP1 = ceil(EXP1 * 11.3 / 10);


                setEXP(EXP1);
                setM1(M1left);
                setM1left(M1left, M1);
                if (M1left == 0) {

                    break;
                }



                if (EXP1 < 300) {
                    M1left = M1left - 100;
                    M1paid += 100;
                }
                else {
                    M1left = M1left - 120;
                    M1paid += 120;
                }
                EXP1 = ceil(EXP1 * (90 / 100.0));


                setEXP(EXP1);
                setM1(M1left);
                setM1left(M1left, M1);

                if (M1left == 0) {

                    break;
                }
            }

        }
        HP1 = ceil(HP1 * (83 / 100.0));
        setHP(HP1);
        EXP1 = ceil(EXP1 * 11.7 / 10);
        setEXP(EXP1);
        int S2 = findS(EXP1);
        if (EXP1 >= S2)
            P2 = 1;
        else {
            if (S2 != 0)
                P2 = (double)(EXP1 / S2 + 80) / 123;
            else return -1;
        }
        //con duong 3
        int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
        int sum = 0;
        int i = 0;
        if (E2 >= 0 && E2 <= 9)
            i = E2;
        else if (E2 >= 10 && E2 <= 99) {
            sum = (E2 % 10) + (E2 / 10 % 10);
            i = sum % 10;
        }
        double P3 = P[i] / 100.0;
        double p = 0;
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = ceil(EXP1 *(75 / 100.0));
            setEXP(EXP1);
            p = 1;
        }
        else {
            p = (P1 + P2 + P3) / 3.0;

        }

        if (p < 0.5) {
            HP1 = ceil(HP1 * (85 / 100.0));
            setHP(HP1);
            EXP1 = ceil(EXP1 * 11.5 / 10);
            setEXP(EXP1);
        }
        else if (p > 0.5 && p != 1) {
            HP1 = ceil(HP1 * (90 / 100.0));
            setHP(HP1);
            EXP1 = ceil(EXP1 * (120 / 100.0));
            setEXP(EXP1);
        }
    }


    return HP1 + EXP1 + M1;
}


//Task 3
int sumDigits(int number) {
    int sum = 0;


    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    if (E3 < 0 || E3>99) return -99;
    else {
        setEXP(EXP1);
        setEXP(EXP2);
        setHP(HP1);
        setHP(HP2);
        int a[10][10];
        int count1 = 0;
        int count2 = 0;
        //tao ma tran
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        for (int i = 0; i < 10; ++i) {

            for (int j = 0; j < 10; ++j) {
                if (a[i][j] > (E3 * 2))
                    count1++;
            }
        }
        for (int i = 0; i < 10; ++i) {

            for (int j = 0; j < 10; ++j) {
                if (a[i][j] < (-E3))
                    count2++;
            }
        }
        //tim toa do taxi
        int toadoI = 0;
        int toadoJ = 0;
        int sum = 0;
        if (count1 >= 0 && count1 <= 9) toadoI = count1;
        else {
            int result = count1;
            while (result >= 10) {
                result = sumDigits(result);
            }
            toadoI = result;
        }
        if (count2 >= 0 && count2 <= 9) toadoJ = count2;
        else {
            int result = count2;
            while (result >= 10) {
                result = sumDigits(result);
            }
            toadoJ = result;
        }
        int taxiPlot = a[toadoI][toadoJ];
        //tim gia tri lon nhat tren duong cheo
        int dgcheotraitren[10], dgcheotraiduoi[10], dgcheophaitren[10], dgcheophaiduoi[10];
        int max1 = taxiPlot, max2 = taxiPlot, max3 = taxiPlot, max4 = taxiPlot;
        for (int i = toadoI, j = toadoJ; i >= 0 && j >= 0; --i, --j) {
            dgcheotraitren[i] = a[i][j];
            if (dgcheotraitren[i] > max1) max1 = dgcheotraitren[i];

        }
        for (int i = toadoI, j = toadoJ; i < 10 && j < 10; ++i, ++j) {
            dgcheotraiduoi[i] = a[i][j];
            if (dgcheotraiduoi[i] > max2) max2 = dgcheotraiduoi[i];


        }
        for (int i = toadoI, j = toadoJ; i >= 0 && j < 10; --i, ++j) {
            dgcheophaitren[i] = a[i][j];
            if (dgcheophaitren[i] > max3) max3 = dgcheophaitren[i];

        }
        for (int i = toadoI, j = toadoJ; i < 10 && j >= 0; ++i, --j) {
            dgcheophaiduoi[i] = a[i][j];
            if (dgcheophaiduoi[i] > max4) max4 = dgcheophaiduoi[i];

        }
        //tim diem taxi va SH va W
        int SHandWscore = max(max1, max(max2, max(max3, max(max4, a[toadoI][toadoJ]))));
        int taxiScore = abs(taxiPlot);
        if (taxiScore > SHandWscore) {
            EXP1 = ceil(EXP1 * (88 / 100.0));
            setEXP(EXP1);
            HP1 = ceil(HP1 * (90 / 100.0));
            setHP(HP1);
            EXP2 = ceil(EXP2 * (88 / 100.0));
            setEXP(EXP2);
            HP2 = ceil(HP2 * (90 / 100.0));
            setHP(HP2);
        }
        else {
            EXP1 = ceil(EXP1 * 11.2 / 10);
            setEXP(EXP1);
            HP1 = ceil(HP1 * 11.0 / 10);
            setHP(HP1);
            EXP2 = ceil(EXP2 * 11.2 / 10);
            setEXP(EXP2);
            HP2 = ceil(HP2 * 11.0 / 10);
            setHP(HP2);
        }
        if (taxiScore > SHandWscore) {
            return taxiPlot;
        }
        else return SHandWscore;
    }
    return -1;
}

int checkPassword(const char* s, const char* email)
{
    //gan gia tri cho se
    char se[101];
    int a = 0;
    for (a = 0; a < 100 && email[a] != '\0' && email[a] != '@'; ++a) {
        se[a] = email[a];
    }
    se[a] = '\0';
    //xet nhung dieu kien vi pham
    int length = strlen(s);
    // vi pham ve do dai
    if (length < 8) {
        return -1;

    }
    else if (length > 20) {
        return -2;

    }
    // vi pham khong duoc chua se
    const char* result = strstr(s, se);
    int sei = result - s;

    if (result != nullptr) {
        return -(300 + sei);

    }
    // vi pham s khong duoc chua nhieu hon 2 ki tu lien tiep va giong nhau
    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i);
        }
    }
    // vi pham dieu kien s chua it nhat 1 ki tu dac biet
    for (int i = 0; i < length; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            break;
        else if (s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            if (i + 1 != length) continue;
            else if (i + 1 == length)
                return -5;
        }

    }
    //vi pham s chua ki tu khac ngoai chu cai thuong, in hoa, chu so va ki tu dac biet
    for (int i = 0; i < length; ++i) {
        if ((s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') && (s[i] < 'A' || s[i]>'Z') && (s[i] < 'a' || s[i]>'z') && (s[i] < '0' || s[i]>'9')) {
            return i;

        }
    }
    //s thoa het dieu kien
    return -10;


}

int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
    int maxFrequency = 0;
    int maxLength = 0;
    if (num_pwds <= 0 || arr_pwds == nullptr) return -1;

    int index = 0;
    //xet tung mat khau trong chuoi
    for (int i = 0; i < num_pwds; ++i)
    {
        const char* password = arr_pwds[i];
        //tinh tan suat xuat hien
        int frequency = 0;
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(password, arr_pwds[j]) == 0)
                frequency++;

        }
        //tinh do dai mat khau
        int length = strlen(password);
        //xet dieu kien thoa man cua mat khau dung
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            maxLength = length;
            index = i;
        }
        else if (frequency == maxFrequency && length > maxLength) {
            maxFrequency = frequency;
            maxLength = length;
            index = i;
        }
    }

    return index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////