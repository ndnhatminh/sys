void tc_1155()
{
    std::cout << "----- Testcase 1155 -----" << std::endl;
    int E2 = 4, HP1 = 666, EXP1 = 600, M1 = 3000;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}