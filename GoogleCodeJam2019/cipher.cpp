#include <assert.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<size_t>	sieve(size_t n)
{
	vector<size_t> v;
	bool primes[n + 1];
	
	memset(primes, true, sizeof(primes));
	for (size_t p = 2; p * p <= n; ++p)
	{
		if (primes[p])
		{
			for (size_t i = p * p; i <= n; i += p)
				primes[i] = false;
		}
	}
	for (size_t p = 3; p <= n; ++p)
		if (primes[p])
			v.push_back(p);
	return (v);
}

set<size_t>	determine_primes(vector<size_t> v, vector<size_t> primes, size_t v_size)
{
	set<size_t> s;
	size_t		fl = 0;

	for (size_t i = 0; i < v_size; ++i)
	{
		for (size_t j = 0; j < primes.size(); ++j)
		{
			if (fl == 2)
				break ;
			if (v[i] % primes[j] == 0)
			{
				s.insert(primes[j]);
				fl++;
			}
		}
		fl = 0;
	}
	return (s);
}

map<size_t, char>	alphabet(set<size_t> s)
{
	map<size_t, char> map;
	char	ch = 'A';

	for (auto i : s)
	{
		map.insert(make_pair(i, ch));
		ch++;
	}
	return (map);
}

string	decipher(map<size_t, char> m, set<size_t> s, vector<size_t> v, size_t v_size)
{
	char		tmp;
	string		res;

	for (size_t i = 0; i < v_size; ++i)
	{
		for (auto j : s)
		{
			if (i == 0 && v[i] % j == 0)
			{
				res.push_back(m[j]);
				tmp = m[j];
			}
			if (v[i] % j == 0)
			{
			   if (tmp != m[j])
				{
					res.push_back(m[j]);
					tmp = m[j];
					break ;
				}
			}
		}
	}
	return (res);
}

int main()
{
	size_t	t;
	size_t	n;
	size_t	l;
	
	cin >> t >> n >> l;
	vector<size_t> v(l, 0);
	for (size_t i = 0; i < l; i++) {
		cin >> v[i];
	}
	vector<size_t> primes = sieve(n);
	for (auto i : prime)
		cout << i << "\n";
	set<size_t> s = determine_primes(v, primes, l);
	cout << "\n\n";
	for (auto i : s)
		cout << i << "\n";
	map<size_t, char> m = alphabet(s);
	string res = decipher(m, s, v, l);
	cout << res << "\n";
	//assert(res == "CJQUIZKNOWBEVYOFDPFLUXALGORITHMS");
	assert(res == "SUBDERMATOGLYPHICFJKNQVWXZ");
	return 0;
}
