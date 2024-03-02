void tc_1222()
{
    std::cout << "----- Testcase 1222 -----" << std::endl;
    int E2 = 94, HP1 = 449, EXP1 = 494, M1 = 944;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}