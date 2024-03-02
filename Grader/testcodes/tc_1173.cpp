void tc_1173()
{
    std::cout << "----- Testcase 1173 -----" << std::endl;
    int E2 = 86, HP1 = 199, EXP1 = 299, M1 = 674;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}