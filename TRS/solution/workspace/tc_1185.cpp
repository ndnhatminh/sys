void tc_1185()
{
    std::cout << "----- Testcase 1185 -----" << std::endl;
    int E2 = 18, HP1 = 81, EXP1 = 599, M1 = 995;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}