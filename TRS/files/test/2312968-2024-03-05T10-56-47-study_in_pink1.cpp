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

// // Task 1
// int firstMeet(int &exp1, int &exp2, int e1)
// // TODO: Complete this function
// {
//     if (0 <= e1 && e1 <= 99) // lưu ý 2: đảm bảo E inRange
//     {
//         // Trường hợp 1
//         switch (e1)
//         {
//         case 0:
//             exp2 += 29;
//             break;

//         case 1:
//             exp2 += 45;
//             break;

//         case 2:
//             exp2 += 75;
//             break;

//         case 3:
//             exp2 = exp2 + 29 + 45 + 75;
//             break;
//         }
//         if (e1 <= 3)
//         {
//             int D = e1 * 3 + exp1 * 7;
//             if (D % 2) // KHÔNG PHẢI D mod 2 !!!
//             {
//                 exp1 = 0.999 + (exp1 - (1.0 * D / 100));
//             }
//             else
//             {
//                 exp1 = 0.999 + (exp1 + (1.0 * D / 200));
//             }
//             exp1 = EXP_inRange(exp1);
//             exp2 = EXP_inRange(exp2);
//             return exp1 + exp2;
//         }
//         // end Trường hợp 1

//         // Trường hợp 2
//         if (4 <= e1 && e1 <= 19)
//         {
//             exp2 += 0.999 + (1.0 * e1 / 4 + 19);
//         }
//         else if (20 <= e1 && e1 <= 49)
//         {
//             exp2 += 0.999 + (1.0 * e1 / 9 + 21);
//         }
//         else if (50 <= e1 && e1 <= 65)
//         {
//             exp2 += 0.999 + (1.0 * e1 / 16 + 17);
//         }
//         else if (66 <= e1 && e1 <= 79)
//         {
//             exp2 += 0.999 + (1.0 * e1 / 4 + 19);
//             if (exp2 > 200)
//             {
//                 exp2 += 0.999 + (1.0 * e1 / 9 + 21);
//             }
//         }
//         else if (80 <= e1 && e1 <= 99)
//         {
//             exp2 += 0.999 + (1.0 * e1 / 4 + 19);
//             exp2 += 0.999 + (1.0 * e1 / 9 + 21);
//             if (exp2 > 400)
//             {
//                 exp2 += 0.999 + (1.0 * e1 / 16 + 17);
//                 exp2 = 0.999 + (exp2 * 1.15);
//                 // printf("exp2 103: %d\n", exp2); //debug
//             }
//         }
//         exp1 -= e1;
//         exp1 = EXP_inRange(exp1);
//         exp2 = EXP_inRange(exp2);
//         return exp1 + exp2;
//         // end Trường hợp 2
//     }
//     else
//     {
//         return -99;
//     }
// }
// // end Task 1, đã test 300 testcases và chạy đúng 100%-------------------------------------------------------------------

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (0 <= E2 && E2 <= 99) // lưu ý 2: đảm bảo E inRange
    {
        // Con đường 1:
        double P1 = computeP_route1(EXP1);
        // end con đường 1
        //  Con đường 2:
        if (E2 % 2 == 0) // Nếu E2 chẵn
        {
            if (M1 > 0)
            {
                // dấu chấm 1
                if (HP1 < 200)
                {
                    HP1 = 0.999 + (HP1 * (1 + 30.0 / 100));
                    M1 -= 150;
                    HP1 = HP_inRange(HP1);
                    M1 = M_inRange(M1);
                }
                else if (HP1 >= 200)
                {
                    HP1 = 0.999 + (HP1 * (1 + 10.0 / 100));
                    M1 -= 70;
                    HP1 = HP_inRange(HP1);
                    M1 = M_inRange(M1);
                }
                // cout << "M1 dau cham 1 : " << M1 << endl; //debug
            }
            if (M1 > 0)
            {
                // dấu chấm 2
                if (EXP1 < 400)
                {
                    M1 -= 200; // đi taxi
                    EXP1 = 0.999 + (EXP1 * (1 + 13.0 / 100));
                    M1 = M_inRange(M1);
                    EXP1 = EXP_inRange(EXP1);
                }
                else if (EXP1 >= 400)
                {
                    M1 -= 120; // đi ngựa
                    EXP1 = 0.999 + (EXP1 * (1 + 13.0 / 100));
                    M1 = M_inRange(M1);
                    EXP1 = EXP_inRange(EXP1);
                }
                // cout << "M1 dau cham 2 : " << M1 << endl; //debug
            }
            if (M1 > 0)
            {
                // dấu chấm 3
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 = 0.999 + (EXP1 * (1 - 10.0 / 100));
                    M1 = M_inRange(M1);
                    EXP1 = EXP_inRange(EXP1);
                }
                else if (EXP1 >= 300)
                {
                    M1 -= 120;
                    EXP1 = 0.999 + (EXP1 * (1 - 10.0 / 100));
                    M1 = M_inRange(M1);
                    EXP1 = EXP_inRange(EXP1);
                }
                // cout << "M1 dau cham 3 : " << M1 << endl; //debug
            }
            // sau khi đi bộ thì hp giảm 17% còn exp tăng 17%
            HP1 = 0.999 + (HP1 * (1 - 17.0 / 100));
            EXP1 = 0.999 + (EXP1 * (1 + 17.0 / 100));
            HP1 = HP_inRange(HP1);
            EXP1 = EXP_inRange(EXP1);
        }
        else // nếu E2 lẻ
        {
            int halfOffirstM1 = M1 / 2;
            // cout << "Mot nua M1 la: (445 expected): " << halfOffirstM1 << endl; //debug
            int fee = 0;
            int e2Oddcount1 = 0, e2Oddcount2 = 0, e2Oddcount3 = 0;
            while (e2Oddcount1 == e2Oddcount2 && e2Oddcount2 == e2Oddcount3)
            {
                // dấu chấm 1
                if (HP1 < 200)
                {
                    if (fee <= halfOffirstM1)
                    {
                        fee += 150;
                        ++e2Oddcount1;
                        HP1 = 0.999 + (HP1 * (1 + 30.0 / 100));
                        M1 -= 150;
                        HP1 = HP_inRange(HP1);
                        M1 = M_inRange(M1);
                    }
                }
                else if (HP1 >= 200)
                {

                    if (fee <= halfOffirstM1)
                    {
                        fee += 70;
                        ++e2Oddcount1;
                        HP1 = 0.999 + (HP1 * (1 + 10.0 / 100));
                        // cout << "HP1: " << HP1 << endl; // debug
                        M1 -= 70;
                        HP1 = HP_inRange(HP1);
                        M1 = M_inRange(M1);
                    }
                }
                if (e2Oddcount1 > e2Oddcount2)
                {
                    // dấu chấm 2
                    if (EXP1 < 400)
                    {

                        if (fee <= halfOffirstM1)
                        {
                            fee += 200;
                            ++e2Oddcount2;
                            M1 -= 200; // đi taxi
                            EXP1 = 0.999 + (EXP1 * (1 + 13.0 / 100));
                            M1 = M_inRange(M1);
                            EXP1 = EXP_inRange(EXP1);
                        }
                    }
                    else if (EXP1 >= 400)
                    {

                        if (fee <= halfOffirstM1)
                        {
                            fee += 120;
                            // cout << "EXP1 (expected twice): " << EXP1 << endl; //debug
                            ++e2Oddcount2;
                            M1 -= 120; // đi ngựa
                            EXP1 = 0.999 + (EXP1 * (1 + 13.0 / 100));
                            M1 = M_inRange(M1);
                            EXP1 = EXP_inRange(EXP1);
                            // cout << "EXP1 (expected twice too): " << EXP1 << endl; //debug
                        }
                    }
                }

                if (e2Oddcount2 > e2Oddcount3)
                {
                    // dấu chấm 3
                    if (EXP1 < 300)
                    {

                        if (fee <= halfOffirstM1)
                        {
                            fee += 100;
                            // cout << "EXP1 dot 3: " << EXP1 << endl; //debug
                            ++e2Oddcount3;
                            M1 -= 100;
                            EXP1 = 0.999 + (EXP1 * (1 - 10.0 / 100));
                            M1 = M_inRange(M1);
                            EXP1 = EXP_inRange(EXP1);
                            // cout << "EXP1 dot 3 sau: " << EXP1 << endl; //debug
                        }
                    }
                    else if (EXP1 >= 300)
                    {

                        if (fee <= halfOffirstM1)
                        {
                            fee += 120;
                            // cout << "EXP1 dot 3: " << EXP1 << endl; //debug
                            ++e2Oddcount3;
                            M1 -= 120;
                            EXP1 = 0.999 + (EXP1 * (1 - 10.0 / 100));
                            M1 = M_inRange(M1);
                            EXP1 = EXP_inRange(EXP1);
                            // cout << "EXP1 dot 3 sau: " << EXP1 << endl; //debug
                        }
                    }
                }
                else
                {
                    ++e2Oddcount3;
                }
                // cout << "EXP1 lan 1: " << EXP1 << endl;
                // cout << "HP1 lan 1: " << HP1 << endl;
                // cout << "count1 = " << e2Oddcount1 << endl;
                // cout << "count2 = " << e2Oddcount2 << endl;
                // cout << "count3 = " << e2Oddcount3 << endl; // debug
            }
            // sau khi đi bộ thì hp giảm 17% còn exp tăng 17%
            HP1 = 0.999 + (HP1 * (1 - 17.0 / 100));
            EXP1 = 0.999 + (EXP1 * (1 + 17.0 / 100));
            HP1 = HP_inRange(HP1);
            EXP1 = EXP_inRange(EXP1);
        }
        double P2 = computeP_route1(EXP1);
        // end con đường 2
        // Con đường 3
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        if (E2 < 10)
        {
            i = E2;
        }
        else
        {
            i = floor(E2 / 10) + (E2 % 10);
            i = i % 10;
        }
        double P3 = P[i] / 100.0;
        // end con đường 3

        // Sau khi đi 3 con đường
        if (P1 == P2 && P2 == P3 && P3 == 100.0 / 100)
        {
            EXP1 = 0.999 + (EXP1 * (1 - 25.0 / 100));
        }
        else
        {
            if (((P1 + P2 + P3) / 3) < 50.0 / 100)
            {
                HP1 = 0.999 + (HP1 * (1 - 15.0 / 100));
                EXP1 = 0.999 + (EXP1 * (1 + 15.0 / 100));
            }
            else
            {
                HP1 = 0.999 + (HP1 * (1 - 10.0 / 100));
                EXP1 = 0.999 + (EXP1 * (1 + 20.0 / 100));
            }
        }
        // end sau khi đi 3 con đường

        HP1 = HP_inRange(HP1);
        EXP1 = EXP_inRange(EXP1);
        M1 = M_inRange(M1);
        return HP1 + EXP1 + M1;
    }
    else
        return -99;
}

int findNearestSquare(int n)
{
    int sqrtN = sqrt(n);
    int lowerSquare = sqrtN * sqrtN;
    int upperSquare = (sqrtN + 1) * (sqrtN + 1);
    if ((n - lowerSquare) <= (upperSquare - n))
    {
        // cout << lowerSquare << endl; //debug
        return lowerSquare;
    }
    else
    {
        // cout << upperSquare << endl; //debug
        return upperSquare;
    }
}

double computeP_route1(int &EXP)
{
    int S = findNearestSquare(EXP);
    double P;
    if (EXP >= S)
    {
        P = 100.0 / 100;
    }
    else
    {
        P = (1.0 * EXP / S + 80) / 123; // đã đúng, đây là phiên bản cũ bị sai: P = 0.0 * (1.0 * (EXP / S) + 80) / 123;
        // cout << P << endl; // debug
    }

    return P;
}
// end Task 2, đã test 300 testcases và chạy đúng 100%-------------------------------------------------------------------

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (0 <= E3 && E3 <= 99) // lưu ý 2: đảm bảo E3 inRange
    {
        // khai báo và khởi trị hai ma trận vuông cấp 10 chứa điểm của taxi, của thám tử
        int taxiPoint[10][10];
        int detectivePoint[10][10];
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                taxiPoint[i][j] = 0;
                detectivePoint[i][j] = 0;
            }
        }

        int iMeet = 0;
        int jMeet = 0;

        // tính và lưu điểm của taxi
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                taxiPoint[i][j] = ((E3 * j) + (i * 2)) * (i - j);

                // đếm i, j gặp nhau (chưa xử lí)
                if (taxiPoint[i][j] > (E3 * 2))
                {
                    ++iMeet;
                }
                if (taxiPoint[i][j] < (-E3))
                {
                    ++jMeet;
                }
                // cout << taxiPoint[i][j] << setw(4); // debug
            }
            // cout << endl; // debug
        }
        // cout << endl; // debug
        // sau khi có ma trận điểm taxi, tính và lưu điểm của 2 chàng thám tử Sherlock và Watson
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                // chéo trái
                int iLeft = i;
                int jLeft = j;
                while (iLeft != 10 && jLeft != 10) // xuống
                {
                    if (detectivePoint[i][j] < (taxiPoint[iLeft][jLeft]))
                    {
                        detectivePoint[i][j] = abs(taxiPoint[iLeft][jLeft]); // đúng
                    }
                    ++iLeft;
                    ++jLeft;
                }
                // cout << "iLeft: " << iLeft << endl;
                // cout << "jLeft: " << jLeft << endl; // debug
                iLeft = i;
                jLeft = j;
                while (iLeft != -1 && jLeft != -1) // lên
                {
                    if (detectivePoint[i][j] < (taxiPoint[iLeft][jLeft]))
                    {
                        detectivePoint[i][j] = abs(taxiPoint[iLeft][jLeft]); // đúng
                    }
                    --iLeft;
                    --jLeft;
                }
                // cout << "iLeft: " << iLeft << endl;
                // cout << "jLeft: " << jLeft << endl; // debug
                // chéo phải
                int iRight = i;
                int jRight = j;
                while (iRight != 10 && jRight != -1) // xuống
                {
                    if (detectivePoint[i][j] < (taxiPoint[iRight][jRight]))
                    {
                        detectivePoint[i][j] = abs(taxiPoint[iRight][jRight]); // đúng
                    }
                    ++iRight;
                    --jRight;
                }
                // cout << "iLeft: " << iLeft << endl;
                // cout << "jLeft: " << jLeft << endl;  // debug
                iRight = i;
                jRight = j;
                while (iRight != -1 && jRight != 10) // lên
                {
                    if (detectivePoint[i][j] < (taxiPoint[iRight][jRight]))
                    {
                        detectivePoint[i][j] = abs(taxiPoint[iRight][jRight]); // đúng
                    }
                    --iRight;
                    ++jRight;
                }
            }
            // xử lí max chéo trái chéo phải tại điểm (i, j)
        }
        // // debug
        // for (int i = 0; i < 10; ++i)
        // {
        //     for (int j = 0; j < 10; ++j)
        //     {
        //         cout << taxiPoint[i][j] << setw(4);
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 0; i < 10; ++i)
        // {
        //     for (int j = 0; j < 10; ++j)
        //     {
        //         cout << detectivePoint[i][j] << setw(4);
        //     }
        //     cout << endl;
        // }
        // //end debug
        // xử lí i, j sau khi đếm
        if (iMeet > 9)
        {
            iMeet = (floor(iMeet / 10.0) + (iMeet % 10));
            if (iMeet > 9)
            {
                iMeet = (floor(iMeet / 10.0) + (iMeet % 10));
                iMeet = iMeet % 10;
            }
        }
        if (jMeet > 9)
        {
            jMeet = (floor(jMeet / 10.0) + (jMeet % 10));
            if (jMeet > 9)
            {
                jMeet = (floor(jMeet / 10.0) + (jMeet % 10));
                jMeet = jMeet % 10;
            }
        }
        // So sánh điểm tại (i,j) gặp, sau đó cập nhật EXP, HP (1 và 2), đồng thời trả về kết quả
        if (abs(taxiPoint[iMeet][jMeet]) <= (detectivePoint[iMeet][jMeet]))
        {
            EXP1 = 0.999 + (EXP1 * (1 + 12.0 / 100));
            HP1 = 0.999 + (HP1 * (1 + 10.0 / 100));
            EXP2 = 0.999 + (EXP2 * (1 + 12.0 / 100));
            HP2 = 0.999 + (HP2 * (1 + 10.0 / 100));
            EXP1 = EXP_inRange(EXP1);
            HP1 = HP_inRange(HP1);
            EXP2 = EXP_inRange(EXP2);
            HP2 = HP_inRange(HP2);
            // cout << "iMeet: " << iMeet << endl;
            // cout << "jMeet: " << jMeet << endl;
            // cout << "taxiPoint[iMeet][jMeet] = taxiPoint[" << iMeet << "][" << jMeet << "] = " << taxiPoint[iMeet][jMeet] << endl;
            // cout << "detectivePoint[iMeet][jMeet] = detectivePoint[" << iMeet << "][" << jMeet << "] = " << detectivePoint[iMeet][jMeet] << endl; // debug
            return detectivePoint[iMeet][jMeet];
        }
        else if (abs(taxiPoint[iMeet][jMeet]) > (detectivePoint[iMeet][jMeet]))
        {
            EXP1 = 0.999 + (EXP1 * (1 - 12.0 / 100));
            HP1 = 0.999 + (HP1 * (1 - 10.0 / 100));
            EXP2 = 0.999 + (EXP2 * (1 - 12.0 / 100));
            HP2 = 0.999 + (HP2 * (1 - 10.0 / 100));
            EXP1 = EXP_inRange(EXP1);
            HP1 = HP_inRange(HP1);
            EXP2 = EXP_inRange(EXP2);
            HP2 = HP_inRange(HP2);
            // cout << "iMeet: " << iMeet << endl;
            // cout << "jMeet: " << jMeet << endl;
            // cout << "taxiPoint[iMeet][jMeet] = taxiPoint[" << iMeet << "][" << jMeet << "] = " << taxiPoint[iMeet][jMeet] << endl;
            // cout << "detectivePoint[iMeet][jMeet] = detectivePoint[" << iMeet << "][" << jMeet << "] = " << detectivePoint[iMeet][jMeet] << endl; // debug
            return taxiPoint[iMeet][jMeet];
        }
        return -1;
    }
    return -99;
}
// end Task 3, đã test 300 testcases và chạy đúng 100%-------------------------------------------------------------------

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    // check tính hợp lệ của email (khỏi cần)
    const char *original_email = email;
    const char *original_s = s;
    int return_value;
    // tìm se
    string se;
    while (*email != '\0' && *email != '@') // đã trả email
    {
        se += *email;
        ++email;
    }
    email = original_email; // trả lại sau khi dùng ạ

    // tính hợp lệ của s
    bool check1 = 0, check2 = 0, check3 = 0, check4 = 0, check5 = 0, check6 = 1, check7 = 0;
    string special_char = {'@', '#', '%', '$', '!'};
    // các ký tự hợp lệ thuộc: 33 | 35 -> 37| 48 -> 57 | 64 -> 90 | 97 -> 122|

    // check7
    while (*s != '\0') // đã trả email
    {
        if ((int(*s) != 33 &&
             (35 > int(*s) || int(*s) > 37) &&
             (48 > int(*s) || int(*s) > 57) &&
             (64 > int(*s) || int(*s) > 90) &&
             (97 > int(*s) || int(*s) > 122)))
        {
            check7 = 1;
            return_value = (s - original_s);
            // cout << "email: " << email << endl;               // debug
            // cout << "original: " << original_email << endl;   // debug
            // cout << "return_val7 = " << return_value << endl; // debug
            break;
        }
        ++s;
    }
    s = original_s;
    // end check7

    // check6
    while (*s != '\0') // đã trả email
    {
        if (int(*s) == 33 ||   // chấm tham !
            (int(*s) == 35) || // thăng #
            (int(*s) == 36) || // đô la $
            (int(*s) == 37) || // phần trăm %
            (int(*s) == 64))   // a còng @ a móc
        {
            check6 = 0;
            break;
        }
        ++s;
    }
    if (check6)
    {
        return_value = -5;
    }
    s = original_s;
    // end check6

    // check 5
    for (int i = 0; s[i + 1] != '\0'; ++i)
    {
        if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2]))
        {
            check5 = 1;
            int sci = i;
            // cout << "sci = " << sci; // debug
            return_value = -(400 + sci);
            break;
        }
    }
    //  end check5

    // check4
    const char *se_cstring = se.c_str(); // ép kiểu, tại vì ở trên dùng se là một string :D, giờ cần dùng nó dưới dạng một const char*
    const char *check4_pointer = strstr(s, se_cstring);
    if (check4_pointer != NULL)
    {
        check4 = 1;
        int sei = check4_pointer - s;
        return_value = -(300 + sei);
    }
    // end check4

    // check3
    if (strlen(s) > 20)
    {
        check3 = 1;
        return_value = -2;
    }
    // end check3

    // check2
    if (strlen(s) < 8)
    {
        check2 = 1;
        return_value = -1;
    }
    // end check2

    // check1
    if (check7 == 0 &&
        check6 == 0 &&
        check5 == 0 &&
        check4 == 0 &&
        check3 == 0 &&
        check2 == 0)
    {
        check1 = 1;
        return_value = -10;
    }
    // end check1

    if (check1)
    {
        return return_value;
    }
    if (check2)
    {
        return return_value;
    }
    if (check3)
    {
        return return_value;
    }
    if (check4)
    {
        return return_value;
    }
    if (check5)
    {
        return return_value;
    }
    if (check6)
    {
        return return_value;
    }
    if (check7)
    {
        return return_value;
    }

    // return vị_trí_đầu_tiên_vi_phạm; // 7th, vd kí tự lạ: '\', '[', ... done
    // return -5;                      // 6th ko có ký tự đặc biệt done
    // return -(400 + sci);            // 5th done
    // return -(300 + sei);            // 4th done
    // return -2;                      // 3rd strlen(s) > 20 done
    // return -1;                      // 2nd strlen(s) < 8 done
    // return -10;                     // 1st hợp lệ done

    return -99;
}
// end Task 4, đã test 300 testcases và chạy đúng 100%-------------------------------------------------------------------

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    string type_pwds[30];
    int type_count[30] = {0};

    int type_index = 0; // vị trí của loại mật khẩu trong mảng type_pwds

    // Lập ma trận chứa các loại mk khác nhau, và 1 ma trận khác chứa số lần xuất hiện
    for (int i = 0; i < num_pwds; ++i)
    {
        bool found = false;
        // Kiểm tra mật khẩu hiện tại có trong type_pwds hay chưa
        for (int j = 0; j < type_index; ++j)
        {
            if (type_pwds[j] == arr_pwds[i])
            {
                type_count[j]++;
                found = true;
                break;
            }
        }

        // ********************** khúc này QUAN TRỌNG: Nếu chưa, thêm nó vào type_pwds và tính 1 lần xuất hiện, chuyển vị trí sang ô kế tiếp
        if (!found)
        {
            type_pwds[type_index] = arr_pwds[i];
            type_count[type_index] = 1;
            type_index++;
        }
    }

    // Tìm các mật khẩu có số lần xuất hiện nhiều nhất
    int max_count = 0;
    for (int i = 0; i < type_index; ++i) //lúc nay2 type_index là vị trí cuối cùng có mk trong type_pwds
    {
        if (type_count[i] > max_count)
        {
            max_count = type_count[i];
        }
    }

    // Tìm mật khẩu có độ dài lớn nhất trong số chúng
    string max_length_pwd = "";
    int max_length_index = -1; // Vị trí đầu tiên của max_length_pwd trong arr_pwds, khởi tạo -1 để dễ debug 
    for (int i = 0; i < type_index; ++i)
    {   
        // dành cho mỗi TH i
        if (type_count[i] == max_count && type_pwds[i].length() > max_length_pwd.length())
        {
            max_length_pwd = type_pwds[i];
            // Tìm vị trí đầu tiên của max_length_pwd trong arr_pwds
            for (int j = 0; j < num_pwds; ++j)
            {
                if (max_length_pwd == arr_pwds[j])
                {
                    max_length_index = j;
                    break; // thoát ra, tăng i lên rồi lặp lại
                }
            }
        }
    }
    return max_length_index;
}
// end Task 5, đã test 300 testcases và chạy đúng 100%-------------------------------------------------------------------

// Hàm set HP về [0, 666]
int HP_inRange(int &HP)
{
    if (HP < 0)
    {
        HP = 0;
    }
    if (HP > 666)
    {
        HP = 666;
    }
    return HP;
}

// Hàm set EXP về [0, 600]
int EXP_inRange(int &EXP)
{
    if (EXP < 0)
    {
        EXP = 0;
    }
    if (EXP > 600)
    {
        EXP = 600;
    }
    return EXP;
}

// Hàm set M về [0, 3000]
int M_inRange(int &M)
{
    if (M < 0)
    {
        M = 0;
    }
    if (M > 3000)
    {
        M = 3000;
    }
    return M;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////