void tc_1192()
{
    std::cout << "----- Testcase 1192 -----" << std::endl;
    int E2 = 94, HP1 = 484, EXP1 = 373, M1 = 2492;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}