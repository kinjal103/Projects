domains
	A,B,C,D,E,F,G = real
	X,Y,Z,M,N = real 
predicates
	choice (integer)
	check (real,real,real)
clauses	
	choice(1):-
	write("For ax^2+bx+c"),
	write("Enter a:\n"),
	readint(A),
	write("Enter b","\n"),
	readint(B),
	write("Enter c","\n"),
	readint(C),
	D=(B*B)-(4*A*C),
	write("",D,"\n"),
	
	check(A,B,D).
	
	check(A,B,D):-
		D=0,
		A<>0,
		write("Roots are Equal"),
		F=((-1)*B)/(2*A),
		write("Root is",F,"\n").
	check(A,B,D):-
		D>0,
		A<>0,
		write("Roots Are Positive & Real","\n"),
		E=sqrt(D),
		F=(((-1)*B)+E)/(2*A),
		G=(((-1)*B)-E)/(2*A),
		write("Roots Are",F,"\n"),
		write("",G,"\n").
	check(A,B,D):-
		D<0,
		A<>0,
		write("Roots Are Imaginary","\n"),
		X=((-1)*D),
		E=sqrt(X),
		Y=((-1)*(B)),
		Z=2*A,
		M=Y/Z,
		N=E/Z,
		write("Roots Are:-",M,"+",N,"i","\n"),
		write("Roots Are:-",M,"-",N,"i","\n").