void tc_1182()
{
    std::cout << "----- Testcase 1182 -----" << std::endl;
    int E2 = 76, HP1 = 311, EXP1 = 48, M1 = 89;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}