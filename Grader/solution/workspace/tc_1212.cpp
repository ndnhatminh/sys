void tc_1212()
{
    std::cout << "----- Testcase 1212 -----" << std::endl;
    int E2 = 92, HP1 = 197, EXP1 = 376, M1 = 673;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}