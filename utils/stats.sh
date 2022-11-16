# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stats.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 00:28:52 by vvaucoul          #+#    #+#              #
#    Updated: 2022/11/17 00:31:09 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

files="$(find . -name "*.ld") $(find . -name "*.mk") $(find . -name "Makefile") $(find . -name "*.c") $(find . -name "*.s") $(find . -name "*.h")"
files_no=`echo $files | wc -w`
lines=`sed -n '$=' $(find . -name "*.ld") $(find . -name "*.mk") $(find . -name "Makefile") $(find . -name "*.c") $(find . -name "*.s") $(find . -name "*.h")`
lines_noc=`cat $(find . -name "*.ld") $(find . -name "*.mk") $(find . -name "Makefile") $(find . -name "*.c") $(find . -name "*.s") $(find . -name "*.h") | sed '/^\s*[*\/].*$/d' | wc -l`
lines_noe=`cat $(find . -name "*.ld") $(find . -name "*.mk") $(find . -name "Makefile") $(find . -name "*.c") $(find . -name "*.s") $(find . -name "*.h") | sed '/^\s*[*\/].*$/d' | sed '/^$/d' | wc -l`
lines_avg=$((lines / files_no))

echo "Total number of files ....................... $files_no"
echo "Total number of lines ....................... $lines"
echo "Total number of lines (no comments) ......... $lines_noc"
echo "Total number of lines (no comments/empty) ... $lines_noe"
echo "Average number of lines per file ............ $lines_avg"