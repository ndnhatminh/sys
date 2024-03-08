void tc_1213()
{
    std::cout << "----- Testcase 1213 -----" << std::endl;
    int E2 = 12, HP1 = 342, EXP1 = 243, M1 = 432;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}