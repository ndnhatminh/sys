void tc_1211()
{
    std::cout << "----- Testcase 1211 -----" << std::endl;
    int E2 = 68, HP1 = 630, EXP1 = 117, M1 = 273;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}