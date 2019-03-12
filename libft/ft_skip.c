char	*ft_skip(char *str,int(*f)(int n))
{
	while (*str)
	{
		if (!f(*str))
			return (str);
		str++;
	}
	return (str);
}
