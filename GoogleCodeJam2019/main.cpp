#include <iostream>

using namespace std;

size_t	ft_a(size_t n)
{
	size_t	a = n;
	size_t	count = 1;

	while (n > 0)
	{
		if (n % 10 == 4)
		{
			if (count == 1)
				a = a - (a % 10) / 2;
			else
				a = a - a / count % 10 / 2 * count;
		}
		count *= 10;
		n /= 10;
	}
	return a;
}

int main()
{
	size_t t;
	size_t *arr;
	size_t a = 0;

	cin >> t;
	arr = new size_t [t];
	for (size_t i = 0; i < t; i++)
		cin >> arr[i];
	for (size_t i = 0; i < t; i++)
	{
		a = ft_a(arr[i]);
		cout << "Case #" << i + 1 << ": " << a << " " << arr[i] - a << "\n";
	}
	delete [] arr;
	arr = NULL;
	return 0;
}
