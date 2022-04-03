#include <iostream>
#include <vector>

using namespace std;

vector<char>	ft_path(vector<char> in, size_t n)
{
	vector<char>	res;
	size_t			count_x = 0;
	size_t			count_y = 0;
	size_t			i = 0;

	while (i < 2 * (n - 1))
	{
		if (in[i] == 'S')
		{
			if (count_x < n)
			{
				res.push_back('E');
				count_x++;
			}
		}
		else if (in[i] == 'E')
		{
			if (count_y < n)
			{
				res.push_back('S');
				count_y++;
			}
		}
		if (i > 1)
		{
			if (in[i - 1] == res[i - 1] && in[i] == res[i])
			{
				cout << "op\n";
				if (res[i] == 'E')
				{
					if (count_y < n)
					{
						res[i] = 'S';
					}
					else
						res.pop_back();
				}
				else if (res[i] == 'S')
				{
					if (count_x < n)
					{
						res[i] = 'E';
					}
					else
						res.pop_back();
				}
			}
		}
		i++;
	}
	return (res);
}

int main()
{
	size_t			t;
	size_t			n;
	string			input;

	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		cin >> n;
		cin >> input;
		vector<char> in(input.begin(), input.end());
		vector<char> out = ft_path(in, n);
		string res(out.begin(), out.end());
		cout << "Case #" << i + 1 << ": " << res << "\n";
	}
	return 0;
}
