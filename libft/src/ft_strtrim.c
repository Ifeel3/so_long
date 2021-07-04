#include "libft.h"

static int	ft_findstart(char const *s1, char const *set)
{
	char const	*tmp;
	int			len;

	len = ft_strlen(s1);
	tmp = s1;
	while (len)
	{
		if (ft_strchr(set, *tmp) == NULL)
			break ;
		len--;
		tmp++;
	}
	return (tmp - s1);
}

static int	ft_findend(char const *s1, char const *set)
{
	char const	*tmp;
	int			len;

	len = ft_strlen(s1);
	tmp = s1 + len;
	while (len)
	{
		if (ft_strchr(set, *tmp) == NULL)
			break ;
		len--;
		tmp--;
	}
	return (tmp - s1 + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	start = ft_findstart(s1, set);
	len = ft_findend(s1, set) - start;
	if (len >= 1)
		new = malloc((sizeof(char) * len) + 1);
	else
	{
		new = malloc(sizeof(char));
		if (new == NULL)
			return (NULL);
		*new = 0;
		return (new);
	}
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1 + start, len + 1);
	new[len + 2] = 0;
	return (new);
}
