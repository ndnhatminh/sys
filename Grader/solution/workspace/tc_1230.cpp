void tc_1230()
{
    std::cout << "----- Testcase 1230 -----" << std::endl;
    int E2 = 24, HP1 = 420, EXP1 = 240, M1 = 2112;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}