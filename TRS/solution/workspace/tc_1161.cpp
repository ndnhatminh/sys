void tc_1161()
{
    std::cout << "----- Testcase 1161 -----" << std::endl;
    int E2 = 78, HP1 = 200, EXP1 = 300, M1 = 741;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}