void tc_1174()
{
    std::cout << "----- Testcase 1174 -----" << std::endl;
    int E2 = 68, HP1 = 259, EXP1 = 79, M1 = 184;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}