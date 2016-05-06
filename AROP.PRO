domains
	A,B,C = integer 
	Z = real 
predicates
	choice(integer)
	check(integer,integer,integer)
clauses	
	choice(1):-
	write("Enter First Number:\n"),
	readint(A),
	write("Enter Second Number","\n"),
	readint(B),
	write("Enter Choice No.:","\n"),
	write("1.Add."),
	write("2.Sub."),
	write("3.Mul"),
	write("4.Div\n"),
	readint(C),
	check(A,B,C).
	
	check(A,B,C):-
		C=1,		
		Z=A+B,
		write("",Z,"\n").
	check(A,B,C):-
		C=2,
		Z=A-B,
		write("",Z,"\n").
	check(A,B,C):-
		C=3,
		Z=A*B,
		write("",Z,"\n").
	check(A,B,C):-
		C=4,
		B<>0,
		Z=A/B,
		write("",Z,"\n").