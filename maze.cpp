#include <iostream>

using namespace std;

void	ft_del(char ***maze)
{
	size_t	i = 0;

	if (maze && *maze)
	{
		while ((*maze)[i])
		{
			free((*maze)[i]);
			(*maze)[i] = NULL;
			i++;
		}
		free(*maze);
		*maze = NULL;
	}
}

char	**ft_maze(size_t n)
{
	char	**maze;
	size_t	i = 0;

	if (!(maze = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		if (!(maze[i] = (char *)malloc(sizeof(char) * (n + 1))))
		{
			ft_del(&maze);
			return (NULL);
		}
		memset(maze[i], '0', n);
		maze[i][n] = '\0';
		i++;
	}
	maze[n] = NULL;
	return (maze);
}

void	ft_prefill_maze(char ***maze, size_t n, char *path)
{
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	size_t size = 2 * (n - 1);

	while (k < size)
	{
		if (path[k] == 'S')
		{
			if (i + 1 != n && j != n)
				(*maze)[++i][j] = 'S';
		}
		if (path[k] == 'E')
		{
			if (j + 1 != n && i != n)
				(*maze)[i][++j] = 'E';
		}
		k++;
	}
}

char	*ft_path(char *s, size_t n)
{
	char	**maze;
	char	*res;
	size_t	k = 0;
	size_t	i = 0;
	size_t	j = 0;

	res = (char *)malloc(sizeof(char) * (2 * n - 1));
	res[2 * n - 1] = '\0';
	memset(res, '0', 2 * n);
	maze = ft_maze(n);
	ft_prefill_maze(&maze, n, s);
	while (i < n)
	{
		while (j < n)
		{
			if (maze[i][j] == 'E')
			{
				if (s[k + 1] != 'S')
				res[k++] = 'S';
				i++;
				j %= n;
				break ;
			}
			j++;
		}
		if (maze[i][j] == 'S')
		{
			res[k++] = 'E';
			j++;
			i %= n;
			break ;
		}
		i++;
	}
	return (res);
}

int main()
{
	size_t	t;
	size_t	n;
	char	*str;

	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		cin >> n;
		str = (char *)malloc(sizeof(char) * (2 * n - 1));
		cin >> str;
		str[2 * (n - 1)] = '\0';
		cout << "Case #" << i + 1 << ": " << ft_path(str, n) << "\n";
		//free(str);
		//str = NULL;
	}
	return 0;
}
