void tc_1243()
{
    std::cout << "----- Testcase 1243 -----" << std::endl;
    int E2 = 98, HP1 = 89, EXP1 = 98, M1 = 89;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}