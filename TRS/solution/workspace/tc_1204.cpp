void tc_1204()
{
    std::cout << "----- Testcase 1204 -----" << std::endl;
    int E2 = 20, HP1 = 283, EXP1 = 283, M1 = 283;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}