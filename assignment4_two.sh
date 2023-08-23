#!/bin/bash
if [ "$#" -ne 1 ]
then
	echo "Usage: $0 <file_name>"
	exit 1
fi

file_name="$1"
if [ ! -f "$file_name" ]
then
	echo "File $file_name not found."
	exit 1
fi

awk -F "~" 'BEGIN { max_total = 0 ; max_name = ""}
    NR>1
 
    {
	total = $3 +$4 + $5; 
	if(total > max_total)
	{
		max_total=total;max_name = $2
	}
    }

 
	END {
		print "Student with highest total marks is :",max_name;
            }' "$file_name"

subject_to_average="SUB1"
awk -F "~" -v subject="$subject_to_average" 'BEGIN {sum=0;count=0} NR>1 {sum+=$3;count++;}
	   END {
		if(count > 0){average = sum / count;printf "Average marks for %s: %.2f\n",subject,average;}
		else{
		  printf "No data found for",subject;
		}
	}' "$file_name"
awk -F "~" 'BEGIN {max_marks=0}
	   NR>1{
		for(i=3;i<=5;i++){
			if($i > max_marks) {
			  max_marks=$i; 
			  max_names=$2;
			}else if ($i == max_marks){
			  max_names = max_names " , " $2;
			}
		}
	  }
          END{
		print"Students with the highest marks in any subject is:",max_names;
	}' "$file_name"

