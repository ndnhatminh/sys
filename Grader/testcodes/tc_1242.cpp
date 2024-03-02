void tc_1242()
{
    std::cout << "----- Testcase 1242 -----" << std::endl;
    int E2 = 2, HP1 = 129, EXP1 = 443, M1 = 888;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}