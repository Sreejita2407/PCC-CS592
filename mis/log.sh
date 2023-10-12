 #shell script to compute the common logarithm of an int N where the value of N must be taken as command line argument
 
 if [ $# -ne 1 ]; then
 	echo "Usage: $0 <integer>"
 	exit 1
 fi
 
 integer_value=$1
 log_result=$( echo "scale=2; l($integer_value)/l(10)" | bc -l)

 echo " common log of $integer_value is $log_result"
 
 
 
 
