#Aleeza Iftikhar
#Email: aiftikhar2@student.gsu.edu
#Program: Count no. of statements, followed by words and letters in each statement.

readFrom="myexamfile.txt"

total_no_statments=$(tr '\n' ' ' < $readFrom | tr '\.' '\n' | wc -l)

echo "Total number of statments found: $total_no_statments"

echo Statment_no$'\t' no_of_words$'\t' no_of_letters

i=1

while ((i<=$total_no_statments)); do #go through each statement
#replace newline with space and replace . with newline
no_of_words=$(tr '\n' ' ' < $readFrom | tr '\.' '\n' | sed -n "$i p" | wc -w) #print words
no_of_letters=$(tr '\n' ' ' < $readFrom | tr '\.' '\n' | sed -n "$i p" | wc -m) #print letters
echo $i $'\t' $'\t' $no_of_words $'\t' $'\t' $no_of_letters
i=`expr $i + 1` #i++
done
