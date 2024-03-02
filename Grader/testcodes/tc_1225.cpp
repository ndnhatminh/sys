void tc_1225()
{
    std::cout << "----- Testcase 1225 -----" << std::endl;
    int E2 = 82, HP1 = 1, EXP1 = 11, M1 = 111;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}