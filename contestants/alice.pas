unit alice;

{ this module can be used for testing your solution }

interface

function get_n: longint;
{ initialize the game,
 returns n - the upper bound on the number
 that Alice has in mind }

function is_divisible_by(m : longint) : boolean;
{ question whether m divides Alice's number }
{ input: m > 0 }

procedure guess(k : longint);
{ attempts to guess Alice's number;
 should be called only once }

implementation

var l, n, questions_number: longint;

function get_n: longint;
begin
   if n = 0 then begin
      write('Input n - the upper bound on the number Alice has to choose: ');
      readln(n);
      if n <= 0 then begin
	 writeln('ERROR: n nonpositive');
	 halt(1);
      end;
      write('Input Alice''s secret number: ');
      readln(l);
      if (l <= 0) or (l > n) then begin
	 writeln('ERROR: Alice''s number out of bounds');
	 halt(1);
      end;
      questions_number := 0;
   end;
   writeln('get_n() = ', n);
   get_n := n;
end;

function is_divisible_by(m : longint) : boolean;
begin
   write('is_divisible_by(', m, ') ');
   if n = 0 then begin
      writeln('ERROR: Function `is_divisible_by'' was called before function `get_n''');
      halt(1);
   end;
   if m <= 0 then begin
      writeln('ERROR: Function `is_divisible_by'' was called with negative m');
      halt(1);
   end;
   if m > n then begin
      writeln('ERROR: Function `is_divisible_by'' was called with m > n');
      halt(1);
   end;
   inc(questions_number);
   is_divisible_by := l mod m = 0;
   writeln('= ', is_divisible_by);
end;

procedure guess(k : longint);
begin
   write('guess(', k, ')');

   if n = 0 then begin
      writeln(' ERROR: Procedure `guess'' was called before function `get_n''');
      halt(1);
   end;

   writeln;
   writeln('Alice''s secret number is ', l);

   if k <> l then begin
      writeln('FAIL: Alice''s secret number is missed after asking ',
	      questions_number, ' questions');
      halt(1);
   end;

   writeln('SUCCESS: Alice''s secret number guessed successively after asking ',
	   questions_number, ' questions');
   halt;
end;	

begin
   n := 0;
end.
