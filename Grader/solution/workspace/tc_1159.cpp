void tc_1159()
{
    std::cout << "----- Testcase 1159 -----" << std::endl;
    int E2 = 16, HP1 = 256, EXP1 = 512, M1 = 2048;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}