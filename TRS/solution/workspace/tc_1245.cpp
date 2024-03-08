void tc_1245()
{
    std::cout << "----- Testcase 1245 -----" << std::endl;
    int E2 = 54, HP1 = 349, EXP1 = 517, M1 = 777;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}