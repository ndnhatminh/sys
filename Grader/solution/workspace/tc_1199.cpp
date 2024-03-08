void tc_1199()
{
    std::cout << "----- Testcase 1199 -----" << std::endl;
    int E2 = 66, HP1 = 222, EXP1 = 444, M1 = 1111;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}