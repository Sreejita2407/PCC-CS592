echo ""
read -p"Enter a number: " n
fact=1
echo ""
if [ $n -lt 0 ]; then
	echo "INVALID!!!"
elif [ $n -eq 1 ]; then
	echo $fact	
else
	for((i=1; i<=n; i++)){
		fact=$((fact*i))
	}
	echo "The factorial of $n is = $fact"
fi
echo ""
