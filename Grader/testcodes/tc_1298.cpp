void tc_1298()
{
    cout << "----- Testcase 298 -----" << endl;
    int E3 = 36, HP1 = 569, EXP1 = 148, HP2 = 127, EXP2 = 480;
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2 << endl;

    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1
         << ", HP2: " << HP2 << ", EXP2: " << EXP2
         << ", result: " << result
         << endl;
}