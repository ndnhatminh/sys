void tc_1180()
{
    std::cout << "----- Testcase 1180 -----" << std::endl;
    int E2 = 88, HP1 = 190, EXP1 = 250, M1 = 456;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}