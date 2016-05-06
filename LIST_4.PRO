domains
	list = integer*
	X = integer
predicates
	check(list,integer,integer)
clauses
	check([H|T],Y,Z):-
		H<>Y,
		C=Z+1,
		check(T,Y,C).
	check([H|_],Y,C):-
		H=Y,
		X=C+1,
		write(X),nl.
/* Unknown Practical*/