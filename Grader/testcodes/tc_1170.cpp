void tc_1170()
{
    std::cout << "----- Testcase 1170 -----" << std::endl;
    int E2 = 8, HP1 = 141, EXP1 = 8, M1 = 2111;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}