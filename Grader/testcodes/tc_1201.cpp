void tc_1201()
{
    std::cout << "----- Testcase 1201 -----" << std::endl;
    int E2 = 32, HP1 = 665, EXP1 = 599, M1 = 2999;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}