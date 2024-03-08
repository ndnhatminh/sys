void tc_1234()
{
    std::cout << "----- Testcase 1234 -----" << std::endl;
    int E2 = 12, HP1 = 34, EXP1 = 56, M1 = 78;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}