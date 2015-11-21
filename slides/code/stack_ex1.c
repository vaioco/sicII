

int function_B(int a, int b)
{
	int x, y;
	x = a * a;
	y = b * b;
	return (x + y);
}

int function_A(int p, int q)
{
	int c;
	c = function_B(p,q);
	return c;
}

int main(int argc, char** argv, char** envp)
{
	int ret;
	ret = function_A(1,2);
	return ret;
}
