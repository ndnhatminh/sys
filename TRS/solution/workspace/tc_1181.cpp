void tc_1181()
{
    std::cout << "----- Testcase 1181 -----" << std::endl;
    int E2 = 28, HP1 = 377, EXP1 = 88, M1 = 651;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}