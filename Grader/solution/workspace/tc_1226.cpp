void tc_1226()
{
    std::cout << "----- Testcase 1226 -----" << std::endl;
    int E2 = 78, HP1 = 666, EXP1 = 345, M1 = 299;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}