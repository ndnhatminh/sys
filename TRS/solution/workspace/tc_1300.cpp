void tc_1300()
{
    cout << "----- Testcase 300 -----" << endl;
    int E3 = 53, HP1 = 488, EXP1 = 376, HP2 = 128, EXP2 = 387;
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2 << endl;

    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2
         << ", result: " << result
         << endl;
}