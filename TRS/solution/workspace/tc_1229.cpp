void tc_1229()
{
    std::cout << "----- Testcase 1229 -----" << std::endl;
    int E2 = 74, HP1 = 128, EXP1 = 477, M1 = 289;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}