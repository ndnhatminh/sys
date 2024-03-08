void tc_1169()
{
    std::cout << "----- Testcase 1169 -----" << std::endl;
    int E2 = 98, HP1 = 567, EXP1 = 123, M1 = 1234;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}