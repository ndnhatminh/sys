void tc_1223()
{
    std::cout << "----- Testcase 1223 -----" << std::endl;
    int E2 = 34, HP1 = 278, EXP1 = 537, M1 = 2167;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}