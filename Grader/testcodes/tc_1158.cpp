void tc_1158()
{
    std::cout << "----- Testcase 1158 -----" << std::endl;
    int E2 = 72, HP1 = 541, EXP1 = 125, M1 = 2345;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}