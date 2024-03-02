void tc_1239()
{
    std::cout << "----- Testcase 1239 -----" << std::endl;
    int E2 = 68, HP1 = 144, EXP1 = 0, M1 = 119;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}