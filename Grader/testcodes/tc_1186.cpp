void tc_1186()
{
    std::cout << "----- Testcase 1186 -----" << std::endl;
    int E2 = 22, HP1 = 322, EXP1 = 181, M1 = 2232;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}