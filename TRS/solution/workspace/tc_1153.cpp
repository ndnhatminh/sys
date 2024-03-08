void tc_1153()
{
    std::cout << "----- Testcase 1153 -----" << std::endl;
    int E2 = 64, HP1 = 128, EXP1 = 2, M1 = 256;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}