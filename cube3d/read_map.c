#include "cub3d.h"

t_list		*ft_check_options(int fd, t_all *all, t_list *list)
{
	int lines;
	char *line;

    while ((lines = get_next_line(fd, &line)) > 0)
	{
        ft_lstadd_back(&list, ft_lstnew(line));
		ft_line_parsing_one(all, list);
        list = list->next;
		if (list->content[0] == '1' || list->content[0] == '0')
			return (list);
	}
    ft_lstadd_back(&list, ft_lstnew(line));
    list = list->next;
	free(line);
	return (list);
}

void		ft_check_map(int fd, t_list *list)
{
	int lines;
	char *line;

	while ((lines = get_next_line(fd, &line)) > 0)
	{
        ft_lstadd_back(&list, ft_lstnew(line));
		list = list->next;
    }
    if (lines == 0)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
        list = list->next;
	}
	ft_lstadd_back(&list, ft_lstnew(line));
    list = list->next;
}