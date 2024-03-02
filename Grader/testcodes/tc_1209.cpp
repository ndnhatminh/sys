void tc_1209()
{
    std::cout << "----- Testcase 1209 -----" << std::endl;
    int E2 = 56, HP1 = 33, EXP1 = 588, M1 = 937;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}