void tc_1197()
{
    std::cout << "----- Testcase 1197 -----" << std::endl;
    int E2 = 14, HP1 = 591, EXP1 = 239, M1 = 2828;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}