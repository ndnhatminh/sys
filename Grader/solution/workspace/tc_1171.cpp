void tc_1171()
{
    std::cout << "----- Testcase 1171 -----" << std::endl;
    int E2 = 74, HP1 = 358, EXP1 = 48, M1 = 222;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}