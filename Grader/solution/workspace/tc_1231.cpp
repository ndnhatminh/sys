void tc_1231()
{
    std::cout << "----- Testcase 1231 -----" << std::endl;
    int E2 = 38, HP1 = 623, EXP1 = 345, M1 = 982;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}