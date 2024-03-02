void tc_1224()
{
    std::cout << "----- Testcase 1224 -----" << std::endl;
    int E2 = 58, HP1 = 291, EXP1 = 300, M1 = 2345;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}