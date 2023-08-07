
echo ""
bubble_sort() {
	local arr=("$@")
	local n=${#arr[@]}

	for ((i = 0; i < n - 1; i++ )); do
		for ((j = 0; j < n - i - 1; j++ )); do
			if ((arr[j] > arr[j + 1] )); then
				local temp=${arr[j]}
				arr[j]=${arr[j + 1]}
				arr[j + 1]=$temp
			fi
		done
	done

	echo "${arr[@]}"
}
# Checking if there are no arguments passed
if [ $# -eq 0 ]; then
	echo "No arguments provided. Please pass the array of integers as arguments."
	exit 1
fi

# Converting command line arguments to an array

input_array=("$@")

#Sorting the array

sorted_array=$(bubble_sort "${input_array[@]}")

echo "The array after sorting is: $sorted_array"
echo ""
