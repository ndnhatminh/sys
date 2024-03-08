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

int upRound(double a)
{
    if (abs(a - int(a))<=10e-10) return int(a);
    else return (int(a) + 1);

}

void expCheck(int & exp)
{
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
}
void hpCheck(int& hp)
{
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
}
void mCheck(int& m)
{
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    expCheck(exp1);
    expCheck(exp2);
    if ((e1 < 0) || (e1 > 99)) return -99;
    // TODO: Complete this function
    //Truong hop 1
    if ((e1 >= 0) && (e1 <= 3))
    {
        switch (e1) {
            case 0: 
            {
                exp2 += 29;
                expCheck(exp2);
                break; 
            }
            case 1:
            {
                exp2 += 45;
                expCheck(exp2);
                break;
            }
            case 2:
            {
                exp2 += 75;
                expCheck(exp2);
                break;
            }
            case 3:
            {
                exp2 += 29;
                expCheck(exp2);
                exp2 += 45;
                expCheck(exp2);
                exp2 += 75;
                expCheck(exp2);
                break;
            }
        
        default:
            break;
        }
        int D = e1*3 + exp1*7;
        if (D % 2 == 0) exp1 += upRound(double(D) / 200);
        else exp1 = upRound(exp1- (double(D) / 100));
        expCheck(exp1);
    }
    //Truong hop 2
    if ((e1 >= 4) && (e1 <= 99))
    {
        if (e1 <= 19) exp2 += (upRound(double(e1) / 4) + 19);
        else if (e1 <= 49) exp2 += (upRound(double(e1) / 9) + 21);
        else if (e1 <= 65) exp2 += (upRound(double(e1) / 16) + 17);
        else if (e1 <= 79)
        {
            exp2 += (upRound(double(e1) / 4) + 19);
            expCheck(exp2);
            if (exp2 > 200) {
                exp2 += (upRound(double(e1) / 9) + 21);
                expCheck(exp2);
            }
        }
        else
        {
            exp2 += (upRound(double(e1) / 4) + 19);
            expCheck(exp2);
            exp2 += (upRound(double(e1) / 9) + 21);
            expCheck(exp2);
            if (exp2 > 400) {
                exp2 += (upRound(double(e1) / 16) + 17);
                expCheck(exp2);
                exp2 = upRound(double(exp2) * 115/100);
                expCheck(exp2);
            }
        }
        expCheck(exp2);
        exp1 -= e1;
        expCheck(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int nSquare(int a)
{
    int b = sqrt(a);
    if (abs(b * b - a) > abs((b + 1) * (b + 1) - a)) return (b + 1)*(b+1);
    else return b * b;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    hpCheck(HP1);
    expCheck(EXP1);
    mCheck(M1);
    if (E2 < 0 || E2>99) return -99;
    //Con duong 1
    int S1 = nSquare(EXP1);
    double P1;
    if (EXP1 >= S1) P1 = 1;
    else P1 = (double(EXP1) / double(S1) + 80) / 123;
    //Con duong 2
    int startM = M1;
    if (M1 != 0)
    {
        do
        {
            //Doi bung
            if (HP1 < 200)
            {
                HP1 = upRound(double(HP1) * 1.3);
                hpCheck(HP1);
                M1 = M1 - 150;
                mCheck(M1);
            }
            else
            {
                HP1 = upRound(double(HP1) * 1.1);
                hpCheck(HP1);
                M1 = M1 - 70;
                mCheck(M1);
            }
            //Break Check
            if (E2 % 2 == 0)
            {
                if (M1 == 0)
                {
                    break;
                }
            }
            else
            {
                if ((startM - M1) > 0.5 * double(startM))
                {
                    break;
                }
            }
            //Di xe
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                mCheck(M1);
            }
            else
            {
                M1 = M1 - 120;
                mCheck(M1);
            }
            EXP1 = upRound(double(EXP1) * 1.13);
            expCheck(EXP1);
            //Break Check
            if (E2 % 2 == 0)
            {
                if (M1 == 0)
                {
                    break;
                }
            }
            else
            {
                if ((startM - M1) > 0.5 * double(startM))
                {
                    break;
                }
            }
            //An xin
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                mCheck(M1);
            }
            else
            {
                M1 = M1 - 120;
                mCheck(M1);
            }
            EXP1 = upRound(double(EXP1) * 0.9);
            expCheck(EXP1);
            //Break Check
            if (E2 % 2 != 0)
            {
                if ((startM - M1) > 0.5 * double(startM))
                {
                    break;
                }
            }
        } while (E2 % 2 != 0);
    }
    HP1 = upRound(double(HP1) * 0.83);
    hpCheck(HP1);
    EXP1 = upRound(double(EXP1) * 1.17);
    expCheck(EXP1);
    int S2 = nSquare(EXP1);
    double P2;
    if (EXP1 >= S2) P2 = 1;
    else P2 = (double(EXP1) / double(S2) + 80) / 123;
    //Con duong 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10)i = E2;
    else i = ((E2 / 10) + (E2 % 10)) % 10;
    double P3 = double(P[i]) / 100;
    //Het duong
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = upRound(double(EXP1) * 0.75);
        expCheck(EXP1);
    }
    else
    {
        double lastP = (P1 + P2 + P3) / 3;

        if (lastP < 0.5)
        {
            HP1 = upRound(double(HP1) * 0.85);
            hpCheck(HP1);
            EXP1 = upRound(double(EXP1) * 1.15);
            expCheck(EXP1);
        }
        else
        {

            HP1 = upRound(double(HP1) * 0.9);
            hpCheck(HP1);
            EXP1 = upRound(double(EXP1) * 1.2);
            expCheck(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    expCheck(EXP1);
    expCheck(EXP2);
    hpCheck(HP1);
    hpCheck(HP2);
    if ((E3 < 0) || (E3 > 99)) return -99;
    int iMeet = 0, jMeet = 0;
    //Taxi Matrix
    int taxiM[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxiM[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxiM[i][j] > (E3 * 2)) iMeet++;
            if (taxiM[i][j] < -E3) jMeet++;
        }

    }
    //Sherlock Matrix
    int sherlockM[10][10];
    for (int jX = 0; jX < 10; jX++)
    {
        for (int iX = 0; iX < 10; iX++)
        {
            int max = taxiM[iX][jX];
            //Xet lan luot cac duong cheo
            int i = iX, j = jX;
            //Duong cheo trai
            //Ben phai X
            while (i - 1 >= 0 && j - 1 >= 0)
            {
                i--;
                j--;
                if (max < taxiM[i][j]) max = taxiM[i][j];
            }
            //Ben phai X
            i = iX;
            j = jX;
            while (i + 1 < 10 && j + 1 < 10)
            {
                i++;
                j++;
                if (max < taxiM[i][j]) max = taxiM[i][j];
            }
            //Duong cheo phai
            //Ben trai X
            i = iX;
            j = jX;
            while (i + 1 < 10 && j - 1 >= 0)
            {
                i++;
                j--;
                if (max < taxiM[i][j]) max = taxiM[i][j];
            }
            //Ben phai X
            i = iX;
            j = jX;
            while (i - 1 >= 0 && j + 1 < 10)
            {
                i--;
                j++;
                if (max < taxiM[i][j]) max = taxiM[i][j];
            }
            sherlockM[iX][jX] = abs(max);

        }
    }
    //Gap nhau
    
    while (iMeet >=10) iMeet = (iMeet / 10) + (iMeet % 10);
    while (jMeet >=10) jMeet = (jMeet / 10) + (jMeet % 10);
    if (sherlockM[iMeet][jMeet] >= abs(taxiM[iMeet][jMeet]))
    {
        HP1 = upRound(double(HP1) * 1.1); 
        hpCheck(HP1);
        HP2 = upRound(double(HP2) * 1.1);
        hpCheck(HP2);
        EXP1 = upRound(double(EXP1) * 1.12);
        expCheck(EXP1);
        EXP2 = upRound(double(EXP2) * 1.12);
        expCheck(EXP2);
        return sherlockM[iMeet][jMeet];
    }
    else
    {
        HP1 = upRound(double(HP1) * 0.9);
        hpCheck(HP1);
        HP2 = upRound(double(HP2) * 0.9);
        hpCheck(HP2);
        EXP1 = upRound(double(EXP1) * 0.88);
        expCheck(EXP1);
        EXP2 = upRound(double(EXP2) * 0.88);
        expCheck(EXP2);
        return taxiM[iMeet][jMeet];
    }
    
}

// Task 4
bool inCharList(char a)
{
    char b[67] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' ,
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '@', '#', '%', '$', '!' };
    for (int i = 0; i < 67; i++)
    {
        if (a == b[i]) return true;
    }
    return false;
}
bool inSpeCharList(char a)
{
    char b[5] = { '@', '#', '%', '$', '!' };
    for (int i = 0; i < 5; i++)
    {
        if (a == b[i]) return true;
    }
    return false;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    string password(s);
    if (password.size() < 8) return -1;
    else if (password.size() > 20) return -2;
    //Tim chuoi se
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            se = string(email, i);
            break;
        }
    }
    //xet loi se
    size_t sei = password.find(se);
    if (sei != string::npos)
    {
        return -(300 + int(sei));
    }
    //xet loi trung 3 ki tu
    for (int i = 2; i < password.size(); i++)
    {
        if (password[i] == password[i - 1] && password[i] == password[i - 2]) return -(400 + (i - 2));
    }
    //xet ki tu dac biet
    bool speChar = 0;
    for (int i = 0; i < password.size(); i++)
    {
        if (inSpeCharList(password[i]))
        {
            speChar = 1;
            break;
        }
    }
    if (speChar == 0) return -5;
    //xet ki tu hop le
    for (int i = 0; i < password.size(); i++)
    {
        if (!(inCharList(password[i]))) return i;
    }
    //Hop le
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    //chuyen arr_pwds thanh dang string cpp;
    string cppArr_Pass[100];
    for (int i = 0; i < num_pwds; i++)
    {
        cppArr_Pass[i] = string(arr_pwds[i]);
    }
    string passList[30];
    int passTimes[30];
    int num_passtimes=0;
    //Phan tich mang mat khau
    for (int i = 0; i < num_pwds; i++)
    {
        bool inPassList=0;
        //Lap danh sach mat khau
        for (int j = 0; j < num_passtimes; j++)
        {
            if (cppArr_Pass[i] == passList[j])
            {
                passTimes[j]++;
                inPassList = 1;
            }
        }
        if (inPassList == 0)
        {
            passList[num_passtimes] = cppArr_Pass[i];
            passTimes[num_passtimes] = 1;
            num_passtimes++;
        }
    }
    
    //Tim so lan xuat hien nhieu nhat
    int maxTimes = passTimes[0];
    for (int i = 0; i < num_passtimes;i++)
    {
        if (maxTimes < passTimes[i]) maxTimes = passTimes[i];
    }
    //Tim mat khau xuat hien nhieu nhat
    string maxPassList[30];
    int numMaxPassList=0;
    for (int i = 0; i < num_passtimes; i++)
    {
        if (maxTimes == passTimes[i])
        {
            maxPassList[numMaxPassList] = passList[i];
            numMaxPassList++;
        }
    }
    //Tim mat khau dai nhat
    int lenMax = maxPassList[0].size();
    string correctPass = maxPassList[0];
    for (int i = 0; i < numMaxPassList; i++)
    {
        if (lenMax < maxPassList[i].size())
        {
            lenMax = maxPassList[i].size();
        }
    }
    for (int i = 0; i < numMaxPassList; i++)
    {
        if (lenMax == maxPassList[i].size())
        {
            correctPass = maxPassList[i];
            break;
        }
    }
    //Xac dinh vi tri trong arr_pwds
    
    int i;
    for (i = 0; i < num_pwds; i++)
    {
        if (correctPass == cppArr_Pass[i]) break;
    }
    return i;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////