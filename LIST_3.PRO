domains
	l1 = integer*
	l2 = integer*
	X = integer
predicates
	r1(l1)
	r2(l1,l2)
clauses	
	r1(X):-
		r2(X,[]).
	r2([H|T],Y):-
		r2(T,[H|Y]).
	r2(_,Y):-
		write(Y),nl.
	/* Reverse The List*/