
function Sum(s:seq<int>):int
ensures s==[] ==> Sum(s) == 0
ensures s!=[] ==> Sum(s) == s[0] + Sum(s[1..])

method feb2014(v:array<int>,m:int) returns(suma:int,p:int)
requires v!=null
requires v.Length >0
requires 0<m<=v.Length
ensures 0<=p<v.Length-m+1
ensures suma==Sum(v[p..p+m])
ensures forall i:: 0<=i<v.Length-m ==> Sum(v[i..i+m])<=suma
	
{
	var i:=0;
	var sumaParcial :=0;
	suma :=0;
	p:=0;

	while(i < m)
	invariant 0<=i<=m
	invariant sumaParcial == Sum(v[..i])
	decreases m-i
	{ sumaParcial := sumaParcial + v[i];
	 i := i + 1;
	}

	while(i<v.Length-m)
	invariant 0<=i<v.Length-m+1
	invariant sumaParcial == Sum(v[i..i+m])
	invariant suma==Sum(v[p..p+m])
	decreases v.Length-m-i
	{
	sumaParcial := sumaParcial+v[i]+v[i+m];
	if(sumaParcial>suma){
		suma := sumaParcial;
		p :=i+1;
		}
	i:=i+1;
	}





}
