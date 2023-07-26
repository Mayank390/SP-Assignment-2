draw_chess_brd() {
	local rows=8
	local cols=8
	black_square="\e[47m \e[0m"
	white_square="\e[40m \e[0m"

	for((m=1;m<= rows; m++)); do
		for((n=1;n<=cols;n++)); do
			if(( (m+n)%2 == 0)); then
				printf "$black_square" # black squares
			else
				printf "$white_square" #white squares
			fi
		done

		printf "\n"
	done
}
draw_chess_brd 
