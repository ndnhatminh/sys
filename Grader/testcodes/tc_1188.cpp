void tc_1188()
{
    std::cout << "----- Testcase 1188 -----" << std::endl;
    int E2 = 72, HP1 = 629, EXP1 = 57, M1 = 1023;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}