{
	求多个数的最大公约数

	@file   gcd.pas
	@author yjf_victor
	@date   2014-11-01
}
program GreatestCommonDivisor(Input, Output);

{
  求两个数的最大公约数
  
  @param[in] n 第一个数
  @param[in] m 第二个数
  @return 最大公约数
}
function gcd(n, m: Integer) : Integer;
var r: Integer;
begin
	repeat
		r := m Mod n;
		m := n;
		n := r;
	until r = 0;
	gcd := m;
end;

{
	主过程
}
var i, n, current_gcd, current_number: Integer;
begin
	read(n);
	read(current_gcd);
	for i := 2 to n do
	begin
		read(current_number);
		current_gcd := gcd(current_gcd, current_number);
	end;
	writeln(current_gcd);
end.