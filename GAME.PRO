predicates
	menu
	check(integer,integer)
	startfn(integer,integer)
	inputread(integer,integer,integer)
	putread(integer,integer,integer,integer)
	checkread(integer,integer,integer,integer,integer)
	compmov(integer,integer,integer,integer,integer)
	cutno(integer,integer,integer)
	checkmov(integer,integer,integer,integer)
clauses
	menu:-
		write("How many sticks do you want to select?"),
		readint(Nstick),
		nl,
		write("Group member"),
		readint(Gno),
		nl,
		check(Nstick,Gno).
		
	check(NN,GG):-
		GG=1,
		NN=NN,
		write("Invalid Group member"),
		menu.
	check(NN,GG):-
		GG<>1,
		NN=NN,
		startfn(NN,GG).
		
	startfn(NN,GG):-
		RE=NN mod GG,
		inputread(NN,GG,RE).	
		
	inputread(NN,GG,RE):-
		nl,
		write("Player"),
		readint(No),
		checkmov(NN,GG,RE,No).
	checkmov(NN,GG,RE,No):-
		No>GG,
		nl,
		write("Invalid move"),
		inputread(NN,GG,RE).
	checkmov(NN,GG,RE,No):-
		S=NN-No,
		GG=GG,
		RE=RE,
		putread(S,GG,RE,No).
		
	putread(NN,GG,RE,No):-
		RE<>1,
		K=GG-No,
		S=RE-1+K,
		checkread(NN,GG,RE,No,S).
	putread(NN,GG,RE,No):-
		RE=1,
		K=GG-No,
		compmov(NN,GG,RE,No,K).
	checkread(NN,GG,RE,No,S):-
		S>GG,
		K=S-1,
		NN=NN,
		RE=RE,
		No=No,
		checkread(NN,GG,RE,No,K).
	checkread(NN,GG,RE,No,S):-
		S<=GG,
		RE=RE,
		CR=1,
		compmov(NN,GG,CR,No,S).
	compmov(NN,GG,RE,No,S):-
		nl,
		write("Computer:",S),
		F=NN-S,
		No=No,
		RE=RE,
		cutno(F,GG,RE).	
	cutno(1,GG,RE):-
		GG=GG,
		RE=RE,
		nl,
		write("cp win").
	cutno(NN,GG,RE):-
		nl,
		write("Remain:",NN),
		inputread(NN,GG,RE).