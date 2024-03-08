void tc_1187()
{
    std::cout << "----- Testcase 1187 -----" << std::endl;
    int E2 = 68, HP1 = 499, EXP1 = 99, M1 = 1199;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}