void tc_1175()
{
    std::cout << "----- Testcase 1175 -----" << std::endl;
    int E2 = 74, HP1 = 616, EXP1 = 192, M1 = 1001;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}