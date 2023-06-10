#include <unistd.h>
#include <stdio.h>
#include <string.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i = 0;
	size_t	j = 0;
	while (s[i])
	{
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

int main()
{
	size_t i = 0;
	size_t m = 0;
	m = ft_strcspn("Hello world", "ppppppppppppppppppppppppppoH");
	i = strcspn("Hello world", "ppppppppppppppppppppppppppoH");
	printf ("%zu\n", m);
	printf ("%zu\n", i);
	return (0);
}
