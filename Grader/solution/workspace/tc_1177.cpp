void tc_1177()
{
    std::cout << "----- Testcase 1177 -----" << std::endl;
    int E2 = 24, HP1 = 211, EXP1 = 122, M1 = 513;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}