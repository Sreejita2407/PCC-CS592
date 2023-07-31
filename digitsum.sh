echo ""
read -p"Enter a no.: " num
echo ""
temp=0
rem=0
n=$num
if [[ "$num" =~ ^[0-9]+$ || "$num" =~ ^[-][0-9]+$  ]]; then 
        if [ $num -lt 0 ]; then
                num=$((num * -1))
        fi
        while [ $num -gt 0 ] 
        do
		rem=$((num % 10))
                temp=$((temp + rem))
                num=$((num / 10))
        done
        echo "Sum of digits of $n is = $temp"
else
	echo "INVALID!!!"
fi
echo ""
echo ""
