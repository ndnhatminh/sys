void tc_1172()
{
    std::cout << "----- Testcase 1172 -----" << std::endl;
    int E2 = 18, HP1 = 221, EXP1 = 21, M1 = 1598;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}