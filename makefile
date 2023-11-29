all: compiled/prog

compiled/prog: 
	 sh/cmp.sh
stable: 
	 sh/sta.sh -Werror
clean:
	 rm compiled/*.comp
