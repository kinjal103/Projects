domains
	list=integer*
predicates
	insertpos(list,integer,integer,list)
clauses
/* Insert At Any Position	*/
	insertpos([H|T],P,E,[H|Y]):-
		P>0,
		C=P-1,
		insertpos(T,C,E,Y).
	insertpos(A,0,E,[E|A]).
	
/* Insert at Specific Position	*/