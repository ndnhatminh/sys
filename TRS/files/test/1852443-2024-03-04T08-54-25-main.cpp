/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2023
 * Author: Vu Van Tien
 * Date: 02.02.2023
 */

// The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"

using namespace std;

void sa_tc_01()
{
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3))
    {
        return;
    }

    // // Task 1

    // cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    // int result = firstMeet(EXP1, EXP2, E1);
    // cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << ", Result: " << result << endl;

    // Task 2

    cout << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", E2: " << E2 << endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    cout << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", E2: " << E2 << ", Result: " << result << endl;

    // Task 3
    // cout << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", HP2: " << HP2 << ", EXP2: " << EXP2 << ", E3: " << E3 << endl;
    // int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    // cout << "Result: " << result << endl;
    // cout << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", HP2: " << HP2 << ", EXP2: " << EXP2 << ", E3: " << E3 << endl;

    // Task 4

    // const char *password = "012345Pink#Pink";
    // const char *victimEmail = "@gmail.com";
    // int result = checkPassword(password, victimEmail);
    // cout << "Result: " << result;

    //  Task 5 Khai báo một mảng mật khẩu và số lượng mật khẩu

    // const char *arr_pwds[] = {"pink@123"};
    // int num_pwds = 1;
    // // Gọi hàm findCorrectPassword để tìm vị trí của mật khẩu đúng
    // int position = findCorrectPassword(arr_pwds, num_pwds);
    // cout << "Result: " << position;
}

int main(int argc, const char *argv[])
{
    sa_tc_01();

    return 0;
}