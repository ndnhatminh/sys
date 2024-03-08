void tc_1237()
{
    std::cout << "----- Testcase 1237 -----" << std::endl;
    int E2 = 28, HP1 = 468, EXP1 = 593, M1 = 123;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}