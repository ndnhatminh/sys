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

int CHECK_HP(float hp)  // kiểm tra HP
{
    if (hp < 0)
    {
        hp = 0;
    }
    else if (hp > 666)
    {
        hp = 666;
    }


    return ceil(hp);
}

int CHECK_EXP(float EXP) // kiểm tra EXP
{
    if (EXP < 0)
    {
        EXP = 0;
    }
    else if (EXP > 600)
    {
        EXP = 600;
    }

    return ceil(EXP);
}

int CHECK_M(float M) // kiểm tra tiền
{
    if (M < 0)
    {
        M = 0;
    }
    else if (M > 3000)
    {
        M = 3000;
    }
    return int(ceil(M));
}
int CHECK_E(int E) // kiểm tra E
{
    if (E < 0 || E > 99)
    {
        return -99;
    }
    else
        return E;

}







// Task 1
int firstMeet(int& exp1, int& exp2, int e1)
{
   

    

    if (CHECK_E(e1) == -99)
    {
        return -99;
    }
    else
    {
        exp1 = CHECK_EXP(exp1);
        exp2 = CHECK_EXP(exp2);
        if (e1 >= 0 && e1 <= 3)
        {
            int D;
            switch (e1)
            {
            case 0:
                exp2 = CHECK_EXP(exp2 + 29);
                break;

            case 1:
                exp2 = CHECK_EXP(exp2 + 45);
                break;

            case 2:
                exp2 = CHECK_EXP(exp2 + 75);
                break;

            default:
                exp2 = CHECK_EXP(exp2 + 149);
                break;
            }
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
            {
                exp1 = CHECK_EXP(float(exp1) + (float(D) / 200.0));
            }
            else
            {
                exp1 = CHECK_EXP(float(exp1) - (float(D) / 100.0));
            }
        }
        else if (e1 >= 4 && e1 <= 99)
        {
            if (e1 <= 19) // thông tin 1
            {
                exp2 = CHECK_EXP(exp2 + float(e1) / 4.0 + 19.0);
            }
            else if (e1 <= 49) // thông tin 2
            {
                exp2 = CHECK_EXP(exp2 + float(e1) / 9.0 + 21.0);
            }
            else if (e1 <= 65) // thông tin 3
            {
                exp2 = CHECK_EXP(exp2 + float(e1) / 16.0 + 17.0);
            }
            else if (e1 <= 79) // thông tin 4
            {
                exp2 = CHECK_EXP(exp2 + float(e1) / 4.0 + 19.0);
                if (exp2 > 200)
                {
                    exp2 = CHECK_EXP(exp2 + float(e1) / 9.0 + 21.0);
                }

            }
            else // thông tin 5
            {
                exp2 = CHECK_EXP(exp2 + float(e1) / 4.0 + 19.0);
                exp2 = CHECK_EXP(exp2 + float(e1) / 9.0 + 21.0);

                if (exp2 > 400)
                {
                    exp2 = CHECK_EXP(exp2 + float(e1) / 16.0 + 17.0);
                    exp2 = CHECK_EXP(exp2 * 1.15);
                }
            }
            exp1 = CHECK_EXP(exp1 - e1);

        }

        return (exp1 + exp2);
    }


}




// hàm tìm số chính phương gần nhất
int sqnum_max(int exp)
{
    int s;
    s = round(sqrt(float(exp))) * round(sqrt(float(exp)));
    return s;
}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
   

    if (E2 >= 0 && E2 <= 99)
    {
       HP1=CHECK_HP(HP1);
       
      EXP1= CHECK_EXP(EXP1);
     
      M1= CHECK_M(M1);
        int S;
        float P1, P2, P3;
        // con đường 1 bắt đầu
        S = sqnum_max(EXP1);
        if (S <= EXP1)
        {
            P1 = 1;
        }
        else
        {
            P1 = ((float(EXP1) / float(S) + 80.0) / 123.0);
        }

        // con đường 2 bắt đầu
        if (CHECK_M(float(M1)) > 0)
        {
            int M11 = 0;
            float M111 = (float(M1) / 2.0); // Lần lượt là số tiền cần chi trả và 50% số tiền ban đầu của holmes

            if (E2 % 2 == 0)
            { // E2 chẵn 
              // sự kiện 1
                if (HP1 < 200)
                {
                    HP1 = CHECK_HP(HP1 * 1.3);
                    M1 -= 150;

                }
                else
                {
                    HP1 = CHECK_HP(HP1 * 1.1);
                    M1 -= 70;

                }

                if (M1 > 0)
                {
                    // sự kiện 2

                    if (EXP1 < 400)
                    {
                        M1 = M1 - 200; // đi xe taxi
                    }
                    else
                    {
                        M1 = M1 - 120; // đi xe ngựa
                    }

                    EXP1 = CHECK_EXP(EXP1 * 1.13);

                    if (M1 > 0)
                    {// sự kiện 3
                        if (EXP1 < 300)
                        {
                            M1 -= 100;
                        }
                        else
                        {
                            M1 -= 120;
                        }
                        EXP1 = CHECK_EXP(EXP1 * 0.9);



                    }
                }
                HP1 = CHECK_HP(HP1 * 0.83);
                EXP1 = CHECK_EXP(EXP1 * 1.17);
                M1 = CHECK_M(float(M1));
            }
            else // E2 lẻ
            {
                do
                {
                    if (HP1 < 200)
                    {
                        HP1 = CHECK_HP(HP1 * 1.3);
                        M1 -= 150;
                        M11 += 150;

                    }
                    else
                    {
                        HP1 = CHECK_HP(HP1 * 1.1);
                        M1 -= 70;
                        M11 += 70;
                    }
                    if (M11 <= M111)
                    {
                        if (EXP1 < 400)
                        {
                            M1 = M1 - 200; // đi xe taxi
                            M11 += 200;
                        }
                        else
                        {
                            M1 = M1 - 120; // đi xe ngựa
                            M11 += 120;
                        }

                        EXP1 = CHECK_EXP(EXP1 * 1.13);
                        if (M11 <= M111)
                        {
                            if (EXP1 < 300)
                            {
                                M1 -= 100;
                                M11 += 100;
                            }
                            else
                            {
                                M1 -= 120;
                                M11 += 120;
                            }
                            EXP1 = CHECK_EXP(EXP1 * 0.9);
                        }

                    }

                } while (M11 <= M111);
                CHECK_M(float(M1));
                HP1 = CHECK_HP(HP1 * 0.83);
                EXP1 = CHECK_EXP(EXP1 * 1.17);

            }

        }
        else
        {
            EXP1 = CHECK_EXP(float(EXP1 * 1.17));
            HP1 = CHECK_HP(float(HP1 * 0.83));

        }
        S = sqnum_max(EXP1);
        if (S <= EXP1)
        {
            P2 = 1;
        }
        else
        {
            P2 = ((float(EXP1) / float(S) + 80.0) / 123.0);
        }

        // bắt đầu con đường 3
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        int i = ((E2 / 10) + (E2 % 10)) % 10;

        P3 = float(P[i]) * 0.01;
        if (P1 == 1 && P2 == 1 && P3 == 1)
        {
            EXP1 = CHECK_EXP(EXP1 * 0.75);

        }
        else if ((P1 + P2 + P3) / 3 < 0.5)
        {
            HP1 = CHECK_HP(HP1 * 0.85);
            EXP1 = CHECK_EXP(EXP1 * 1.15);
        }
        else
        {
            HP1 = CHECK_HP(HP1 * 0.9);
            EXP1 = CHECK_EXP(EXP1 * 1.2);
            M1 = CHECK_M(float(M1));



        }
        HP1 = CHECK_HP(HP1);

        EXP1 = CHECK_EXP(EXP1);

        M1 = CHECK_M(M1);
        return (HP1 + M1 + EXP1);
    }
    else
    {
        return (-99);
    }

}


int maxcheo(int i, int j, int taxi[10][10]) //  hàm tính gtln của đường chéo trái và đường chéo phải
{
    int  maxcheo = taxi[i][j];
    int hang;
    int cot;

    hang = i;
    cot = j;

    while (hang <= 9 && cot <= 9)
    {

        if (taxi[hang][cot] >= maxcheo)
        {
            maxcheo = taxi[hang][cot];

        }


        hang = hang + 1;
        cot = cot + 1;
    }


    hang = i;
    cot = j;
    while (hang >= 0 && cot >= 0)
    {
        if (taxi[hang][cot] >= maxcheo)
        {
            maxcheo = taxi[hang][cot];
        }
        hang -= 1;
        cot -= 1;
    }

    hang = i;
    cot = j;
    while (hang >= 0 && cot <= 9)
    {
        if (taxi[hang][cot] >= maxcheo)
        {
            maxcheo = taxi[hang][cot];
        }
        hang = hang - 1;
        cot = cot + 1;
    }
    hang = i;
    cot = j;

    while (hang <= 9 && cot >= 0)
    {
        if (taxi[hang][cot] >= maxcheo)
        {
            maxcheo = taxi[hang][cot];
        }
        hang = hang + 1;
        cot = cot - 1;
    }
    return maxcheo;
}












// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
  
    if (CHECK_E(E3) == -99)
    {
        return -99;
    }
    else
    {
        EXP1 = CHECK_EXP(EXP1);
        EXP2 = CHECK_EXP(EXP2);
        HP1 = CHECK_HP(HP1);
        HP2 = CHECK_HP(HP2);
        {
            int taxi[10][10], diem[10][10], a, b, i = 0, j = 0, chaseTaxi;
            for (a = 0; a < 10; a++)  // tạo ma trận điểm taxi
            {
                for (b = 0; b < 10; b++)
                {
                    taxi[a][b] = ((E3 * b) + (a * 2)) * (a - b);
                    if (taxi[a][b] > (E3 * 2))
                    {
                        i += 1;
                    }
                    if (taxi[a][b] < (0 - E3))
                    {
                        j += 1;
                    }



                }
            }
            i = (i / 10 + i % 10) / 10 + (i / 10 + i % 10) % 10; // hàng giao nhau
            j = (j / 10 + j % 10) / 10 + (j / 10 + j % 10) % 10; // cột giao nhau

            for (a = 0; a < 10; a++) // ma trận điểm holmes và watson
            {
                for (b = 0; b < 10; b++)
                {
                    diem[a][b] = abs(maxcheo(a, b, taxi));
                }
            }
            if (abs(taxi[i][j]) > diem[i][j])
            {
                EXP1 = CHECK_EXP(EXP1 * 0.88);
                EXP2 = CHECK_EXP(EXP2 * 0.88);
                HP1 = CHECK_HP(HP1 * 0.9);
                HP2 = CHECK_HP(HP2 * 0.9);


                chaseTaxi = taxi[i][j];

            }
            else
            {
                EXP1 = CHECK_EXP(EXP1 * 1.12);
                EXP2 = CHECK_EXP(EXP2 * 1.12);
                HP1 = CHECK_HP(HP1 * 1.1);
                HP2 = CHECK_HP(HP2 * 1.1);
                chaseTaxi = diem[i][j];

            }

            EXP1 = CHECK_EXP(EXP1);
            EXP2 = CHECK_EXP(EXP2);
            HP1 = CHECK_HP(HP1);
            HP2 = CHECK_HP(HP2);

            return chaseTaxi;
        }
    }
}




// hàm check trùng se
int check_se(char s1[], char se[], int u, int k)
{
    int j = 0, i, sei = -1;

    if (u <= k)
    {

        for (i = 0; i < k; i++)
        {
            if (s1[i] == se[j])
            {
                j += 1;
                if (j == u)
                {
                    sei = i - u + 1;
                    break;
                }
            }
            else { j = 0; }
        }

    }
    return sei;
}
// check nhiều hơn 2 kí tự liên tiếp của s
int check_nhieuhon2kitulientiep(char s1[], int k)
{
    int sci = -1;
    for (int i = 0; i < (k - 2); i++)
    {
        if (s1[i] == s1[(i + 1)] && s1[i] == s1[(i + 2)])
        {
            sci = i;
        }
    }
    return sci;
}
// check chuỗi có chữ số chữ cái thường và chữ hoa

int check_chucaichuso(char s1[], int k)
{
    int kq = -1;
    for (int i = 0; i < k; i++)
    {
        if ((s1[i] < 0 || s1[i] >9) && (s1[i] < 'a' || s1[i]>'z') && (s1[i] < 'A' && s1[i]>'Z'))
        {
            kq = i;
            break;
        }
    }
    return kq;
}

// hàm check kí tự đặc biệt của s
int check_kitudacbiet(char s1[], int k)
{
    int kq = -5;
    for (int i = 0; i < k; i++)
    {
        if (s1[i] == '@' || s1[i] == '#' || s1[i] == '%' || s1[i] == '$' || s1[i] == '!')
        {
            kq = 1;
            break;
        }
    }
    return kq;
}




// TASK 4
int checkPassword(const char* s, const char* email)

{

    int const n = strlen(email), k = strlen(s);
        int dem = 0, kqtrave, u;
    char se[n];
    char s1[k];

    strcpy(s1, s);
    strcpy(se, email);





    u = strlen(strtok(se, "@"));
    strcpy(se, strtok(se, "@"));

    if (k < 8)
    {
        kqtrave = -1;

    }
    else if (k > 20)
    {
        kqtrave = -2;
    }
    else if (check_se(s1, se, u, k) != -1)
    {
        kqtrave = -(300 + check_se(s1, se, u, k));
    }
    else if (check_nhieuhon2kitulientiep(s1, k) != -1)
    {
        kqtrave = -(400 + check_nhieuhon2kitulientiep(s1, k));
    }
    else if (check_kitudacbiet(s1, k) == -5)
    {
        kqtrave = -5;
    }
    else if (check_chucaichuso(s1, k) != -1)

    {
        kqtrave = check_chucaichuso(s1, k);
    }
    else
    {
        kqtrave = -10;
    }


    return kqtrave;
}







// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max = 1, i, j;
    int longg = strlen(arr_pwds[0]), dem;
    int k = 0;

    for (i = 0; i < (num_pwds - 1); i++)
    {
        dem = 1;
        for (j = (i + 1); j < (num_pwds); j++)
        {
            if (arr_pwds[i] == arr_pwds[j])
            {
                dem += 1;
            }
        }

        if (dem > max)
        {
            max = dem;
            longg = strlen(arr_pwds[i]);
            k = i;
        }
        else if (max == dem && longg < strlen(arr_pwds[i]))
        {

            longg = strlen(arr_pwds[i]);
            k = i;


        }
    }




    return k;

    
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////