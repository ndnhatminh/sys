void tc_1206()
{
    std::cout << "----- Testcase 1206 -----" << std::endl;
    int E2 = 22, HP1 = 510, EXP1 = 290, M1 = 333;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}