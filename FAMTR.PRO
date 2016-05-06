domains 
	A,B,C,D,E = symbol

predicates 
	male(symbol)
	female(symbol)
	parents(symbol,symbol,symbol)

	father()
	mother()
	grandfather()
	grandmother()
	son()
	daughter()
	brother()
	sister()
	cousins()
	siblings()

clauses 

	male("Rooshin").
	male("Vighnesh").
	male("Hitesh").
	male("Minesh").
	male("Bhagwat").
	male("Ruchik").
	male("Ishan").
	male("Somabhai").
	male("Hitendra").
	male("Dharmendra").
	male("Kanjibhai").
	male("Varun").
	female("Stuti").
	female("Kruti").
	female("Darshna").
	female("Kusumben").
	female("Dahiben").
	female("Rutva").
	female("Daxa").
	female("Minaxi").
	female("Christina").
	parents("Kanjibhai","Kusumben","Dharmendra").
	parents("Kanjibhai","Kusumben","Hitendra").
	parents("Kanjibhai","Kusumben","Daxa").
	parents("Somabhai","Dahiben","Minesh").
	parents("Somabhai","Dahiben","Hitesh").
	parents("Somabhai","Dahiben","Bhagwat").
	parents("Hitendra","Darshna","Stuti").
	parents("Hitendra","Darshna","Kruti").
	parents("Dharmendra","Christina","Varun").
	parents("Minesh","Rutva","Ishan").
	parents("Hitesh","Daxa","Rooshin").
	parents("Hitesh","Daxa","Vighnesh").
	parents("Bhagwat","Minaxi","Ruchik").
		

	father() :-
		write("Name of Father:-"),nl,
		readln(A),
		write("Name of Child:-"),nl,
		readln(B),
		male(A),
		parents(A,_,B).

	mother() :-
		write("Name of Mother:-"),nl,
		readln(A),
		write("Name of Child:-"),nl,
		readln(B),
		female(A),
		parents(_,A,B).
		
	grandfather() :-
		write("Name of Grandfather:-"),nl,
		readln(A),
		write("Name of Child:-"),nl,
		readln(B),
		male(A),
		parents(C,_,B),
		parents(A,_,C).
	
	grandmother() :-
		write("Name of Grandmother:-"),nl,
		readln(A),
		write("Name of Child:-"),
		readln(B),
		female(A),
		parents(C,_,B),
		parents(_,A,C).
		
	brother() :-
		write("Name of Brother:-"),nl,
		readln(A),
		write("Name of the other person"),nl,
		readln(B),
		male(A),
		parents(C,_,A),
		parents(C,_,B).

	sister() :-
		write("Name of Sister:-"),nl,
		readln(A),
		write("Name of the other person:-"),nl,
		readln(B),
		female(A),
		parents(C,_,A),
		parents(C,_,B).

	son() :-
		write("Name of Son:-"),nl,
		readln(A),
		write("Name of father:-"),nl,
		readln(B),
		write("Name of Mother"),nl,
		readln(C),
		parents(B,C,A),
		male(A).

	daughter() :-
		write("Name of Daughter:-"),nl,
		readln(A),
		write("Name of father:-"),nl,
		readln(B),
		write("Name of Mother:-"),nl,
		readln(C),
		parents(B,C,A),
		female(A).
		
	cousins() :-
		write("Name of 1st Person"),nl,
		readln(A),
		write("Name of 2nd Person"),nl,
		readln(B),
		parents(C,_,A),
		parents(D,_,B),
		parents(E,_,C),
		parents(E,_,D),
		C<>D.

	siblings() :-
		write("Name of 1st Person"),nl,
		readln(A),
		write("Name of 2nd Person"),nl,
		readln(B),
		parents(C,_,A),
		parents(D,_,B),
		C=D.