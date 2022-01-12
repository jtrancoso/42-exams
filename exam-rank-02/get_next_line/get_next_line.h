/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:59:51 by juanrodr          #+#    #+#             */
/*   Updated: 2020/11/30 12:17:51 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef GET_NEXT_LINE_H
 # define GET_NEXT_LINE_H

 # include <unistd.h>
 # include <stdlib.h>
 # include <stdio.h>

int get_next_line(char **line);
int ft_strlen(char *str);
char *ft_strchr(char *str, int c);
char *ft_strdup(char *str);
char *ft_strjoin(char *s1, char *s2);
 
 #endif