void tc_1236()
{
    std::cout << "----- Testcase 1236 -----" << std::endl;
    int E2 = 30, HP1 = 190, EXP1 = 468, M1 = 2698;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}