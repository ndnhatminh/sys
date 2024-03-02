void tc_1317()
{
    cout << "----- Testcase 317 -----" << endl;
    int E3 = 69, HP1 = 626, EXP1 = 461, HP2 = 664, EXP2 = 315;
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2 << endl;

    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2
         << ", result: " << result
         << endl;
}