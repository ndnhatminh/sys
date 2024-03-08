void tc_1191()
{
    std::cout << "----- Testcase 1191 -----" << std::endl;
    int E2 = 40, HP1 = 144, EXP1 = 168, M1 = 2298;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}