void tc_1297()
{
    cout << "----- Testcase 297 -----" << endl;
    int E3 = 21, HP1 = 106, EXP1 = 245, HP2 = 12, EXP2 = 476;
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2 << endl;

    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2
         << ", result: " << result
         << endl;
}