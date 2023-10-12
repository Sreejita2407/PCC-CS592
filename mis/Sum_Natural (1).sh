# Write a shell script to find the summation of N natural numbers, where the values of N natural numbers are passed as command line arguments.

echo ""
if [ $# -eq 0 ]; then
	echo "No arguments provided. Please provide some numbers as command line arguments."
	exit i
fi

sum=0

# Looping through the command line arguments and calculating the sum
for num in "$@"; do
	# Checking if the arguments given are positive numbers or not
	if ! [[ "$num" =~ ^[0-9]+$ ]]; then
		echo "Error: '$num' is not a valid positive integer."
		exit 1
	fi

	sum=$((sum+num))
done

echo "The sum of the numbers entered as the command line arguments are: $sum"
echo ""
