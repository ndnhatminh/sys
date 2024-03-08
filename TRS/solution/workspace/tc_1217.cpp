void tc_1217()
{
    std::cout << "----- Testcase 1217 -----" << std::endl;
    int E2 = 72, HP1 = 138, EXP1 = 141, M1 = 43;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}