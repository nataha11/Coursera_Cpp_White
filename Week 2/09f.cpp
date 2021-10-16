int Factorial(int x) {
    if(x < 0)
        return 1;
	int f = 1;
	for(int i = x; i > 0; i--) {
		f *= i;
	}
	return f;
}