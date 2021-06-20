#ifndef FT_STRINGS_H
# define FT_STRINGS_H

int		ft_is_in_str(char c, char *str);
int		ft_word_count(char *str, char *sep);
int		ft_strlen_sep(char *str, char *sep);
char	*ft_strdlup(char *str, int n);
char	**ft_split(char *str, char *sep);

#endif
