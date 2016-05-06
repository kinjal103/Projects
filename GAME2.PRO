predicates
	menu
	checkturn(integer,integer,integer)
	player(integer,integer)
	checkno(integer,integer,integer)
	checkwin(integer,integer)
	computer(integer,integer)
	checkwinp(integer,integer)
clauses
	menu:-
	write("Enter total sticks:"),
	readint(Nstick),
	write("Enter max limit of choosing:"),
	readint(Limit),
	write("Who's turn?"),
	readint(Turn),
	checkturn(Nstick,Limit,Turn).
	
	checkturn(NN,L,T):-
		T=0,
		player(NN,L).
	checkturn(NN,L,T):-
		T=1,
		computer(NN,L).
	checkturn(_,_,_):-
		nl,
		write("Invalid"),
		nl,
		menu.
			
	player(NN,L):-
		nl,
		write("Player:"),
		readint(No),
		checkno(NN,L,No),
		K=NN-No,
		write("Remain:",K),
		checkwinp(K,L).
		
	checkwinp(K,L):-
		K=0,
		L=L,
		write("Player Win.").
		
	checkwinp(K,L):-
		K<>0,
		computer(K,L).	
	
	checkno(NN,L,No):-
		No=0,
		nl,
		write("Invalid"),
		player(NN,L).
	checkno(NN,L,No):-
		No>L,
		nl,
		write("Invalid"),
		player(NN,L).
	checkno(_,_,_):-
		1=1.
	
	computer(NN,L):-
		K=L+1,
		S=NN mod K,
		S<>0,
		nl,
		write("Computer:",S),
		nl,
		P=NN-S,
		write("Remain:",P),
		checkwin(P,L).
	computer(NN,L):-
		K=L+1,
		S=NN mod K,
		S=0,
		nl,
		G=1,
		P=NN-G,
		write("Computer:",G),
		nl,
		write("Remain:",P),
		checkwin(P,L).
		
	checkwin(P,L):-
		P=0,
		L=L,
		nl,
		write("Computer win.").
	checkwin(P,L):-
		player(P,L).
	checkwin(_,_):-
		1=1.
	