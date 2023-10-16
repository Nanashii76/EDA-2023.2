unsigned long long int fibonacci(int n) {

    static unsigned long long mem[80 + 1] = { [0] = 1, [1] = 1, [2] = 1};

    if (!mem[n])
        mem[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return mem[n];
}