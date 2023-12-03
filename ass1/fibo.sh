echo ""
read -p"Enter the no. of terms: " num
echo ""
a=0
b=1
if [ $num -le 0 ]; then
	echo "INVALID!!!"
else
	echo "The fibonacci series for $num terms is: "
	for((i=0; i<num; i++)){
		echo -n "$a "
		n=$((a+b))
		a=$b
		b=$n
	}
	echo ""
	echo ""
fi
