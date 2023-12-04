/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:25:11 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 15:04:15 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	
	### static void	free_ptr(char **ptr)
		utility for freeing a pointer and setting it to NULL
	
	### static char	*extract_line(char **buffer_copy)
		1. searches for newline or end of string, iterates i
		2. copies buffer_copy to temporary variable
		3. outputs to line variable, using substr,  up to i + 1
		4. updates the static buffer_copy to index i + 1
		5. frees temp_buffer_copy for use in next function call
		6. returns line

	### static int	*red_fille(int fd, char **buffer, char **buffer_copy)
		1. searches for \n if none then bites_red = the output of read function
		on buffer up to BUFFER_SIZE
		2. checks if error with reading of file
		3. terminates buffer string at BUFFER_SIZE
		4. buffer_copy is copied to temp value
		5. buffer_copy is updated with ft_strjoin of temp value and buffer
		6. temp value is freed
		7. returns number of bytes read

	### static char	*get_line(int fd, char **buffer, char **buffer_copy)
		1. searches for \n in buffer_copy, if found, calls extract_line 
		and returns its value, which will be the line up to and including \n
		2. if no \n, read file and returns bytes read into bites_red variable
		3. if bytes read is none, or file read is in error 
		(while buffer_copy is empty) frees static buffer_copy and returns NULL
		4. repeats search for \n in new version of buffer_copy, if \n,
		calls extract line
		5. if no \n, and buffer_copy is not empty,
		function will return buffer_copy
		6. if buffer_copy is empty, function returns NULL.

	### char	*get_next_line(int fd)
		1. check for invalid file descriptor or invalid BUFFER_SIZE
		2. allocate memory for buffer variable - BUFFER_SIZE + 1
		3. if no buffer_copy, assign an empty value to the index fd.
		4. output is assigned the return value of function call get_line
		5. buffer is freed
		6. output is returned
*/

#include "../includes/libft.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*extract_line(char **buffer_copy)
{
	char	*line;
	int		i;
	char	*temp_buffer_copy;

	i = 0;
	while ((*buffer_copy) && (*buffer_copy)[i] != '\n')
		i++;
	temp_buffer_copy = *buffer_copy;
	line = ft_substr(temp_buffer_copy, 0, i + 1);
	*buffer_copy = ft_strdup(&(*buffer_copy)[i + 1]);
	free_ptr(&temp_buffer_copy);
	return (line);
}

static int	red_fille(int fd, char **buffer, char **buffer_copy)
{
	int		bites_red;
	char	*temp_buffer_copy;

	bites_red = 1;
	while (!ft_strchr(*buffer_copy, '\n') && bites_red > 0)
	{
		bites_red = read(fd, *buffer, BUFFER_SIZE);
		if (bites_red == -1)
			return (bites_red);
		(*buffer)[bites_red] = '\0';
		temp_buffer_copy = *buffer_copy;
		*buffer_copy = ft_strjoin(temp_buffer_copy, *buffer);
		free_ptr(&temp_buffer_copy);
	}
	return (bites_red);
}

static char	*get_line(int fd, char **buffer, char **buffer_copy)
{
	int		bites_red;
	char	*temp_buffer_copy;

	if (ft_strchr(*buffer_copy, '\n'))
		return (extract_line(buffer_copy));
	bites_red = red_fille(fd, buffer, buffer_copy);
	if ((bites_red == 0 || bites_red == -1) && !**buffer_copy)
	{
		free_ptr(buffer_copy);
		return (NULL);
	}
	if (ft_strchr(*buffer_copy, '\n'))
		return (extract_line(buffer_copy));
	if (!ft_strchr(*buffer_copy, '\n') && (**buffer_copy))
	{
		temp_buffer_copy = ft_strdup(*buffer_copy);
		free_ptr(buffer_copy);
		return (temp_buffer_copy);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer_copy[OPEN_MAX + 1];
	char		*output;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!buffer_copy[fd])
		buffer_copy[fd] = ft_strdup("");
	output = get_line(fd, &buffer, &buffer_copy[fd]);
	free_ptr(&buffer);
	return (output);
}
