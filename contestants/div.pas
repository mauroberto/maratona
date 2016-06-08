{
  Sample solution using alice library.
  This solution is incorrect.
  It is provided only to demonstrate the library usage.
}

uses alice;

var k, m, n : longint;

begin
   n := get_n;
   k := 0;
   while k = 0 { condition - k is unknown } do
   begin
      m := 2; { find somehow m }
      if is_divisible_by(m) then
	 k := 2 { do some action; k is divisible by m }
      else
	 k := 1 { do some action; k is not divisible by m }
   end;
   { here k shlould be Alice's secret number }
   guess(k);
end.
