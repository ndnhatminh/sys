void tc_1195()
{
    std::cout << "----- Testcase 1195 -----" << std::endl;
    int E2 = 38, HP1 = 133, EXP1 = 344, M1 = 499;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}