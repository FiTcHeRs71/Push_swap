

#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"

bool	check_arg_is_digit(char *str)
{
	size_t	i;
	long long	number;
	int			sign;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	if (!str[i])
	{
		return (false);
	}
	while (str[i])
	{
		if(!ft_isdigit(str[i]))
		{
			return (false);
		}
		number = (number * 10) + (str[i] - '0');
		if ((sign == 1 && number > INT_MAX) || (sign == -1 && number < INT_MIN))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	check_duplicate_numbers(t_build *data, int *numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if ( numbers[i] == numbers [j])
			{
				free (numbers);
				ft_error(data);
			}
			j++;
		}
		i++;
	}
}