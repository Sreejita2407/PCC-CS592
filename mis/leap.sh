echo ""
read -p"Enter a year: " yr
echo ""
if [ $yr -le 0 ]; then
	echo "INVALID!!!"
elif [ `expr $yr % 100` -eq 0 ]; then
	if [ `expr $yr % 400` -eq 0 ]; then
		echo "$yr is a leap year."
	else
		echo "$yr is not a leap year."
	fi
else
	if [ `expr $yr % 4` -eq 0 ]; then
		echo "$yr is a leap year."
	else
		echo "$yr is not a leap year."
	fi
fi
echo ""
echo "" 
