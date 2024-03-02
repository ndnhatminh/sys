void tc_1179()
{
    std::cout << "----- Testcase 1179 -----" << std::endl;
    int E2 = 2, HP1 = 647, EXP1 = 13, M1 = 47;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}