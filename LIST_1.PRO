domains
	list = integer*
	A,B = integer
predicates
	check(list,integer)
clauses
	check([H|T],A):-
		H<>A,
		check(T,A).
	check([H|_],A):-
		H=A.
	/* Check if the element is in the list*/