    #include "study_in_pink1.h"

    bool readFile(
        const string &filename,
        int &HP1,
        int &HP2,
        int &EXP1,
        int &EXP2,
        int &M1,
        int &M2,
        int &E1,
        int &E2,
        int &E3)
    {
        // This function is used to read the input file,
        // DO NOT MODIFY THIS FUNTION
        ifstream ifs(filename);
        if (ifs.is_open())
        {
            ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
            return true;
        }
        else
        {
            cerr << "The file is not found" << endl;
            return false;
        }
    }

    ////////////////////////////////////////////////////////////////////////
    /// STUDENT'S ANSWER BEGINS HERE
    /// Complete the following functions
    /// DO NOT modify any parameters in the functions.
    ////////////////////////////////////////////////////////////////////////

    // Check value
    int ExpCheck(int exp)
    {
        if (exp >= 600)
        {
            return 600;
        }
        else if (exp <= 0)
        {
            return 0;
        }
        else
        {
            return exp;
        }
    }
    int HpCheck(int hp)
    {
        if (hp >= 666)
        {
            return 666;
        }
        else if (hp <= 0)
        {
            return 0;
        }
        else
        {
            return hp;
        }
    }
    int MoneyCheck(int m){
        if(m<0){
            return 0;
        }else if(m>3000){
            return 3000;
        }else{
            return m;
        }
    }
    // Task 1
    int firstMeet(int &EXP1, int &EXP2, int e1)
    {
        // TODO: Complete this function
        float exp1 = EXP1;
        float exp2 = EXP2;
        exp1 = ExpCheck(exp1);
        exp2 = ExpCheck(exp2);

        if (e1 <= 3 && e1 >= 0)
        {
            if (e1 == 0)
            {
                exp2 += 29;
            }
            else if (e1 == 1)
            {
                exp2 += 45;
            }
            else if (e1 == 2)
            {
                exp2 += 75;
            }
            else if (e1 == 3)
            {
                exp2 += (29 + 45 + 75);
            }
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 1)
            {
                exp1 = ceil(round((exp1 - (D * 1.0 / 100)) * 10000.0) / 10000.0);
            }
            else
            {
                exp1 = ceil(round((exp1 + (D * 1.0 / 200)) * 10000.0) / 10000.0);
            }

            //
        }
        else if (e1 <= 99 && e1 >= 4)
        {
            if (e1 <= 19)
            {
                exp2 = ceil(round((exp2 + (e1 * 1.0 / 4) + 19) * 10000.0) / 10000.0);
            }
            else if (e1 <= 49)
            {
                exp2 = ceil(round((exp2 + (e1 * 1.0 / 9) + 21) * 10000.0) / 10000.0);
            }
            else if (e1 <= 65)
            {
                exp2 = ceil(round((exp2 + (e1 * 1.0 / 16) + 17) * 10000.0) / 10000.0);
            }
            else if (e1 <= 79)
            {
                exp2 = ceil(round((exp2 + (e1 * 1.0 / 4) + 19) * 10000.0) / 10000.0);
                if (exp2 > 200)
                {
                    exp2 = ceil(round((exp2 + (e1 * 1.0 / 9) + 21) * 10000.0) / 10000.0);
                }
            }
            else
            {
                exp2 = ceil(round((exp2 + (e1 * 1.0 / 4) + 19) * 10000.0) / 10000.0) + ceil(round(((e1 * 1.0 / 9) + 21) * 10000.0) / 10000.0);
                if (exp2 > 400)
                {
                    exp2 = ceil(round((exp2 + (e1 * 1.0 / 16) + 17) * 10000.0) / 10000.0);
                    exp2 = ceil(round(exp2 * 1.15 * 10000.0 / 1.0) / 10000.0);
                }
            }
            exp1 -= e1;
        }
        else
        {
            return -99;
        }
        exp1 = ExpCheck(exp1);
        exp2 = ExpCheck(exp2);
        EXP1 = exp1;
        EXP2 = exp2;
        return exp1 + exp2;
    }

    // Task 2
    int traceLuggage(int &HP1, int &EXP1, int &m1, int e2)
    {
        // TODO: Complete this function
        float hp1 = HP1;
        float exp1 = EXP1;
        if(e2>99||e2<0){
            return -99;
        }
        exp1 = ExpCheck(exp1);
        hp1 = HpCheck(hp1);
        m1 = MoneyCheck(m1);
        // Way1
        int a = sqrt(exp1);
        int s = 0;
        int b = a + 1;
        if (b * b - exp1 > exp1 - a * a)
        {
            s = a * a;
        }
        else if(b * b - exp1 <= exp1 - a * a)
        {
            s = b * b;
        }
        float p1 = 0;
        if (exp1 >= s)
        {
            p1 = 100;
        }
        else
        {
            p1 = ((exp1 * 1.0 / s + 80) / 123)*100;
        }
        // Way2
        if (e2 % 2 == 1)
        {
            float m01 = m1 * 1.0 / 2;
            while (1)
            {
                if (m1 <= 0)
                {
                    m1 = 0;
                    break;
                }
                if (hp1 < 200) // event 1
                {
                    hp1 = ceil(round(hp1 * 1.3 * 10000.0) / 10000.0);
                    hp1 = HpCheck(hp1);
                    m1 -= 150;
                    m1 = MoneyCheck(m1);
                }
                else if (hp1 >= 200)
                {
                    hp1 = ceil(round(hp1 * 1.1 * 10000.0) / 10000.0);
                    hp1 = HpCheck(hp1);
                    m1 -= 70;
                    m1 = MoneyCheck(m1);
                }
                if (m1 < m01 || m1 <= 0)
                {
                    break;
                }
                if (exp1 < 400) // event 2
                {
                    m1 -= 200;
                    m1 = MoneyCheck(m1);
                    exp1 = ceil(round(exp1 * 1.13 * 10000.0) / 10000.0);
                    exp1 = ExpCheck(exp1);
                }
                else if (exp1 >= 400)
                {
                    m1 -= 120;
                    m1 = MoneyCheck(m1);
                    exp1 = ceil(round(exp1 * 1.13 * 10000.0) / 10000.0);
                    exp1 = ExpCheck(exp1);
                }
                if (m1 < m01 || m1 <= 0)
                {
                    break;
                }
                if (exp1 < 300) // event 3
                {
                    m1 -= 100;
                    m1 = MoneyCheck(m1);
                    exp1 = ceil(round(exp1 * 0.9 * 10000.0) / 10000.0);
                    exp1 = ExpCheck(exp1);
                }
                else if (exp1 >= 300)
                {
                    m1 -= 120;
                    m1 = MoneyCheck(m1);
                    exp1 = ceil(round(exp1 * 0.9 * 10000.0) / 10000.0);
                    exp1 = ExpCheck(exp1);
                }
                if (m1 < m01 || m1 <= 0)
                {
                    break;
                }
            }
            hp1 = ceil(round(hp1 * 0.83 * 10000.0) / 10000.0);
            hp1 = HpCheck(hp1);
            exp1 = ceil(round(exp1 * 1.17 * 10000.0) / 10000.0);
            exp1 = ExpCheck(exp1);
        }
        else
        {
            int n = 1;
            while (n)
            {
                if (m1 <= 0)
                {
                    m1 = 0;
                    break;
                }
                if (hp1 < 200) // event 1
                {
                    hp1 = ceil(round(hp1 * 1.3 * 10000.0) / 10000.0);
                    hp1 = HpCheck(hp1);
                    m1 -= 150;
                    m1 = MoneyCheck(m1);
                }
                else if (hp1 >= 200)
                {
                    hp1 = ceil(round(hp1 * 1.1 * 10000.0) / 10000.0);
                    hp1 = HpCheck(hp1);
                    m1 -= 70;
                    m1 = MoneyCheck(m1);
                }
                if (m1 <= 0)
                {
                    m1 = 0;
                    break;
                }
                if (exp1 < 400) // event 2
                {
                    m1 -= 200;
                    m1 = MoneyCheck(m1);
                    exp1 = ceil(round(exp1 * 1.13 * 10000.0) / 10000.0);
                    exp1 = ExpCheck(exp1);
                }
                else if (exp1 >= 400)
                {
                    m1 -= 120;
                    m1 = MoneyCheck(m1);
                    exp1 = ceil(round(exp1 * 1.13 * 10000.0) / 10000.0);
                    exp1 = ExpCheck(exp1);
                }
                if (m1 <= 0)
                {
                    m1 = 0;
                    break;
                }
                if (exp1 < 300) // event 3
                {
                    m1 -= 100;
                    m1 = MoneyCheck(m1);
                    exp1 = ceil(round(exp1 * 0.9 * 10000.0) / 10000.0);
                    exp1 = ExpCheck(exp1);
                }
                else if (exp1 >= 300)
                {
                    m1 -= 120;
                    m1 = MoneyCheck(m1);
                    exp1 = ceil(round(exp1 * 0.9 * 10000.0) / 10000.0);
                    exp1 = ExpCheck(exp1);
                }
                n -= 1;
            }
            hp1 = ceil(round(hp1 * 0.83 * 10000.0) / 10000.0);
            hp1 = HpCheck(hp1);
            exp1 = ceil(round(exp1 * 1.17 * 10000.0) / 10000.0);
            exp1 = ExpCheck(exp1);
        }
        int a2 = sqrt(exp1);
        int s2 = 0;
        int b2 = a2 + 1;
        if (b2 * b2 - exp1 > exp1 - a2 * a2)
        {
            s2 = a2 * a2;
        }
        else if(b2 * b2 - exp1 <= exp1 - a2 * a2)
        {
            s2 = b2 * b2;
        }
        float p2 = 0;
        if (exp1 >= s2)
        {
            p2 = 100;
        }
        else
        {
            p2 = ((exp1 * 1.0 / s2 + 80) / 123)*100;
        }
        // Way3
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int n = 0, a3 = 0, a4 = 0;
        float p3 = 0;
        if ((e2 * 1.0 / 10) < 1)
        {
            n = e2;
            p3 = P[n];
        }
        else if (e2 * 1.0 / 10 >= 1)
        {
            a3 = e2 / 10;
            a4 = e2 % 10;
            n=(a3+a4)%10;
            p3 = P[n];
        }
        else
        {
            p3 = P[1];
        }
        if (p1 == p2 && p2 == p3 && p3 == 100)
        {
            exp1 = ceil(round(exp1 * 0.75 * 10000.0) / 10000.0);
            exp1 = ExpCheck(exp1);
        }
        else
        {
            double ptb = (p1 + p2 + p3)*1.0/ 3;
            if (ptb >= 50)
            {
                exp1 = ceil(round(exp1 * 1.2 * 10000.0) / 10000.0);
                exp1 = ExpCheck(exp1);
                hp1 = ceil(round(hp1 * 0.9 * 10000.0) / 10000.0);
                hp1 = HpCheck(hp1);
            }
            else
            {
                exp1 = ceil(round(exp1 * 1.15 * 10000.0) / 10000.0);
                exp1 = ExpCheck(exp1);
                hp1 = ceil(round(hp1 * 0.85 * 10000.0) / 10000.0);
                hp1 = HpCheck(hp1);
            }
        }
        HP1 = hp1;
        EXP1 = exp1;
        return hp1 + exp1 + m1;
    }

    // Task 3
    int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int e3)
    {
        // TODO: Complete this function
        if(e3<0 || e3>99){
            return -99;
        }
        float exp1 = EXP1;
        exp1 = ExpCheck(exp1);
        float exp2 = EXP2;
        exp2 = ExpCheck(exp2);
        float hp1 = HP1;
        hp1 = HpCheck(hp1);
        float hp2 = HP2;
        hp2 = HpCheck(hp2);
        int X[10][10] = {};
        int c1, c2; // c1  bằng số giá trị điểm của taxi lớn hơn E3 ∗ 2
                    // c2  bằng số giá trị điểm của taxi nhỏ hơn -E3
        c1 = 0;
        c2 = 0;
        int PointReturn = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                X[i][j] = ((e3 * j) + (i * 2)) * (i - j);
                if (X[i][j] > e3 * 2)
                {
                    c1 += 1;
                }
                else if (X[i][j] < (-e3))
                {
                    c2 += 1;
                }
            }
        }
        int a3=0,a4=0;
        if (c1 > 10)
        {
            a3=c1/10;
            a4=c1%10;
            while(a3+a4>10){
                int temp=a3;
                a3=(a3+a4)/10;
                a4=(a4+temp)%10;
            }
            c1=a3+a4;
        }
        else if (c1 == 10)
        {
            c1 = 1;
        }
        int a32=0,a42=0;
        if (c2 > 10)
        {
            a32=c2/10;
            a42=c2%10;
            while(a32+a42>10){
                int temp=a32;
                a32=(a32+a42)/10;
                a42=(a42+temp)%10;
            }
            c2=a32+a42;
        }
        else if (c2 == 10)
        {
            c2 = 1;
        }
        int taxipoint = X[c1][c2];
        int c01 = c1;
        int c02 = c2;
        int c11 = c1;
        int c12 = c2;
        while (c01 != 0 && c02 != 9)
        {
            c01 -= 1;
            c02 += 1;
        }
        int max1 = 0;
        while (c02 != -1 && c01 != 10)
        {
            if (X[c01][c02] > max1)
            {
                max1 = X[c01][c02];
            }
            c01 += 1;
            c02 -= 1;
        }
        while (c11 != 0 && c02 != 0)
        {
            c11 -= 1;
            c12 -= 1;
        }
        int max2 = 0;
        while (c12 != 9 && c11 != 9)
        {
            if (X[c11][c12] > max2)
            {
                max2 = X[c11][c12];
            }
            c11 += 1;
            c12 += 1;
        }
        int sherpoint = 0;
        if (max1 >= max2)
        {
            sherpoint = max1;
        }
        else
        {
            sherpoint = max2;
        }
        if (abs(taxipoint) <= abs(sherpoint))
        {
            exp1 = ceil(round(exp1 * 1.12 * 10000.0) / 10000.0);
            exp1 = ExpCheck(exp1);
            hp1 = ceil(round(hp1 * 1.1 * 10000.0) / 10000.0);
            hp1 = HpCheck(hp1);
            exp2 = ceil(round(exp2 * 1.12 * 10000.0) / 10000.0);
            exp2 = ExpCheck(exp2);
            hp2 = ceil(round(hp2 * 1.1 * 10000.0) / 10000.0);
            hp2 = HpCheck(hp2);
            PointReturn = sherpoint;
        }
        else if (abs(taxipoint) > abs(sherpoint))
        {
            exp1 = ceil(round(exp1 * 0.88 * 10000.0) / 10000.0);
            exp1 = ExpCheck(exp1);
            hp1 = ceil(round(hp1 * 0.9 * 10000.0) / 10000.0);
            hp1 = HpCheck(hp1);
            exp2 = ceil(round(exp2 * 0.88 * 10000.0) / 10000.0);
            exp2 = ExpCheck(exp2);
            hp2 = ceil(round(hp2 * 0.9 * 10000.0) / 10000.0);
            hp2 = HpCheck(hp2);
            PointReturn = taxipoint;
        }
        HP1 = hp1;
        EXP1 = exp1;
        EXP2 = exp2;
        HP2 = hp2;
        return PointReturn;
    }

    // Task 4
    int checkPassword(const char *s, const char *email)
    {
        // TODO: Complete this function
        int s_length = 0;
        while (s[s_length] != '\0')
        {
            s_length++;
        }
        // tìm ra chuỗi se
        char se[90] = {};
        int se_length = 0;
        for (int n = 0; n < 90; n++)
        {
            if (email[n] != '@')
            {
                se[n] = email[n];
                se_length++;
            }
            else if (email[n] == '@')
            {
                se[se_length] = '\0';
                break;
            }
        }
        char kitudacbiet[6] = "!@#$%";
        char tongkitu[68] = "abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%1234567890";
        // check do dai
        int checkdodai = 0;
        if (s_length < 8)
        {
            checkdodai = 1;
            return -1;
        }
        if (s_length > 20)
        {
            checkdodai = 1;
            return -2;
        }
        // check kí tự hợp lệ
        int kituhople = 0;
        int firstwrong1 = -1;
        for (int i = 0; i < s_length; i++)
        {
            for (int j = 0; j < sizeof(tongkitu) - 1; j++)
            {
                if (s[i] != tongkitu[j])
                {
                    kituhople += 1;
                }
            }
            if (kituhople == 67)
            {
                if (firstwrong1 == -1)
                {
                    firstwrong1 = i;
                    return firstwrong1;
                }
            }
            kituhople = 0;
        }
        // check ki tu dac biet
        int checkkitudacbiet = 0;
        for (int i = 0; i < s_length; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (s[i] == kitudacbiet[j])
                {
                    checkkitudacbiet += 1;
                    continue;
                }
            }
        }
        if (checkkitudacbiet < 1)
        {
            return -5;
        }
        // check s có chứa nhiều hơn 2 ký tự liên tiếp
        int lientiep = 0;
        for (int i = 0; i <= s_length - 2; i++)
        {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
            {
                lientiep = 1;
                return -(400 + i);
            }
        }
        // check s có chứa se hay không
        int firstse = 0, sizese = 0;
        for (int i = 0; i < s_length; i++)
        {
            if (s[i] == se[0])
            {
                int b = 0;
                int c = i + se_length;
                for (int a = i; a < c; a++)
                {
                    if (s[a] == se[b])
                    {
                        sizese += 1;
                        b++;
                    }
                    else if (s[a] != se[b] && b > 0)
                    {
                        b = 0;
                    }
                }
                if (sizese == se_length)
                {
                    firstse = i;
                    return -(300 + i);
                }
                else
                {
                    sizese = 0;
                }
            }
        }
        // check coi có hợp lệ hay không
        if (checkdodai == 0 && checkkitudacbiet >= 1 && firstwrong1 == -1 && lientiep == 0 && firstse == 0)
        {
            return -10;
        }
        return -99;
    }
    // Task 5
    int findCorrectPassword(const char *arr_pwds[], int num_pwds)
    {
        // TODO: Complete this function
        int numappear[31] = {}; // mảng số lần xuất hiện
        int addappear[31] = {}; // mảng vị trí xuất hiện của mật khẩu có số lần xuất hiện nhiều nhất
        int stt = 0;
        // tìm số lần xuất hiện của từng mật khẩu
        for (int i = 0; i < num_pwds; i++)
        {
            for (int j = 0; j < num_pwds; j++)
            {
                if (arr_pwds[i] == arr_pwds[j])
                {
                    numappear[i] += 1;
                }
            }
        }
        // tìm mật khẩu có số lần xuất hiện nhiều nhất
        int count = 0;
        for (int i = 0; i < num_pwds; i++)
        {
            for (int j = 0; j < num_pwds; j++)
            {
                if (numappear[i] >= numappear[j])
                {
                    count += 1;
                }
            }
            if (count == num_pwds)
            {
                addappear[stt] = i;
                stt += 1;
            }
            count = 0;
        }
        int count2 = 0;
        // tìm mật khẩu dài nhất sau khi lọc
        for (int i = 0; i < stt; i++)
        {
            for (int j = 0; j < stt; j++)
            {
                if (strlen(arr_pwds[addappear[i]]) >= strlen(arr_pwds[addappear[j]]))
                {
                    count2 += 1;
                }
            }
            if (count2 == stt)
            {
                return addappear[i];
            }
            count2 = 0;
        }

        return -1;
    }

    ////////////////////////////////////////////////
    /// END OF STUDENT'S ANSWER
    ////////////////////////////////////////////////