void tc_1315()
{
    cout << "----- Testcase 315 -----" << endl;
    int E3 = 0, HP1 = 255, EXP1 = 69, HP2 = 267, EXP2 = 494;
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2 << endl;

    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2
         << ", result: " << result
         << endl;
}